/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:47:33 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/15 23:21:14 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



// int main()
// {

// 	int fd[2];
// 	pid_t pid;
// 	char buffer[13];

// 	if (pipe(fd) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}

// 	if (pid == 0)
// 	{
// 		close(fd[0]); // close the read end of the pipe
// 		write(fd[1], "Hello parent!", 13);
// 		close(fd[1]); // close the write end of the pipe
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		close(fd[1]); // close the write end of the pipe
// 		read(fd[0], buffer, 13);
// 		close(fd[0]); // close the read end of the pipe
// 		printf("Message from child: '%s'\n", buffer);
// 		exit(EXIT_SUCCESS);
// 	}


// 	// int fd;

// 	// pid_t pid;

// 	// pid = fork();
// 	// if (pid == -1)
// 	// {
// 	// 	perror("fork");
// 	// 	exit(EXIT_FAILURE);
// 	// }

// 	// if (pid == 0)
// 	// 	printf("This is the child process. (pid: %d)\n", getpid());
// 	// else
// 	// 	printf("This is the parent process. (pid: %d)\n", getpid());

// 	// fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
// 	// if (access("example.txt", R_OK) != -1)
// 	// 	printf("I have permission\n");
// 	// else
// 	// 	printf("I don't have permission\n");

// 	// dup2(fd, STDOUT_FILENO);
// 	// close(fd);
// 	// printf("This is printed in example.txt!%d\n", getpid());

// 	// char *args[3];

// 	// args[0] = "ls";
// 	// args[1] = "-l";
// 	// args[2] = NULL;
// 	// execve("/bin/ls", args, NULL);
// 	//printf("This line will not be executed.\n");
	
	
// 	return (0);
// }

void	exec(char *cmd, char **env)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(env[0], 2);
}

int	open_file(char *filename, int output)
{
	if (output == 0)
		return (open(filename, O_RDONLY, 0777));
	else if (output == 1)
		return (open(filename, O_WRONLY | O_CREAT, 0644));
	return (-1);
}

void	child(char **argv, int *pipefd, char **env)
{
	int		fd;

	fd = open_file(argv[2], 0);
	if (fd == -1)
		return ;
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
		return ;
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
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (!pid)
		child(argv, pipefd, envp);
	parent(argv, pipefd, envp);

    return (0);
}
