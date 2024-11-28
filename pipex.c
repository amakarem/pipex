/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:47:33 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/28 20:32:38 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		error_exit("ft_split failed");
	path = find_path(cmd[0], env);
	if (!path)
		free_exit_error(cmd);
	if (execve(path, cmd, env) == -1)
		free_exit_error(cmd);
}

int	open_file(char *filename, int output)
{
	int	fd;

	if (output == 0)
		return (open(filename, O_RDONLY, 0777));
	else if (output == 1)
	{
		fd = open(filename, O_RDONLY, 0777);
		if (fd > 0)
		{
			close(fd);
			unlink(filename);
		}
		return (open(filename, O_WRONLY | O_CREAT, 0644));
	}
	return (-1);
}

void	child(char **argv, int *pipefd, char **env)
{
	int		fd;

	fd = open_file(argv[1], 0);
	if (fd == -1)
		error_exit("Failed to open input file");
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	exec(argv[2], env);
}

void	parent(char **argv, int *pipefd, char **env)
{
	int		fd;

	fd = open_file(argv[4], 1);
	if (fd == -1)
		error_exit("Failed to open output file");
	dup2(fd, 1);
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	exec(argv[3], env);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
		error_exit("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>");
	if (pipe(pipefd) == -1)
		error_exit("Pipe failed");
	pid = fork();
	if (pid == -1)
		error_exit("Fork failed");
	if (!pid)
		child(argv, pipefd, envp);
	waitpid(pid, NULL, 0);
	parent(argv, pipefd, envp);
	return (0);
}
