/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:47:33 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/28 19:31:01 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *argv, char **env)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], env);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, env) == -1)
		error();
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
		error();
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
		error();
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	exec(argv[3], env);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
		return (exit_f(1));
	if (pipe(pipefd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (!pid)
		child(argv, pipefd, envp);
	waitpid(pid, NULL, 0);
	parent(argv, pipefd, envp);
	return (0);
}
