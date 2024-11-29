/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:19:56 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/29 19:33:38 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(const char *msg)
{
	if (ft_strlen(msg) == 0)
		msg = strerror(errno);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(127);
}

int	ft_arr_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**cmd_args(char **cmd, char *argv)
{
	int	i;
	int	x;

	i = ft_arr_size(cmd) - 1;
	x = 2;
	while (i > 1)
	{
		cmd[1] = ft_strjoin(cmd[1], " ");
		cmd[1] = ft_strjoin(cmd[1], cmd[x]);
		free(cmd[x]);
		x++;
		i--;
	
	}
	// write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
	// write(STDERR_FILENO, cmd[1], ft_strlen(cmd[1]));
	// write(STDERR_FILENO, "\n", 1);
	i = ft_strlen(argv);
	return (cmd);
}

void	free_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_exit_error(char **cmd, char *msg)
{
	free_arr(cmd);
	error_exit(msg);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	if (access(cmd, F_OK) == 0)
		return (cmd);
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	free_arr(paths);
	return (0);
}
