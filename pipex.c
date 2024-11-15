/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:47:33 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/15 21:02:17 by aelaaser         ###   ########.fr       */
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





int	main(int argc, char **argv, char **envp)
{
	//int		fd[2];
	//pid_t	pid;

	if (argc != 5)
		return (exit_f(1));

    char *args[] = {"/bin/ls", argv[3], NULL};  // Arguments to the 'ls' command

    // Call execve() to run 'ls -l'
    if (execve("/bin/ls", args, envp) == -1) {
        perror("execve");  // Print error if execve fails
        return 1;
    }


	// if (execve("/bin/ls", "-l", argv) == -1)
	// {
    //     perror("execve");  // Print error if execve fails
    //     return 1;
    // }

    return (0);
}
