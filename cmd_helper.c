/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:11:27 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/30 20:12:58 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**optmize_cmd(char **cmd)
{
	int	size;
	int	x;

	size = ft_arr_size(cmd);
	x = 2;
	if (size > 2)
	{
		while (size > 2)
		{
			cmd[1] = ft_strjoin(cmd[1], " ");
			cmd[1] = ft_strjoin(cmd[1], cmd[x]);
			free(cmd[x]);
			cmd[x] = NULL;
			x++;
			size--;
		}
		x = 0;
		while (cmd[1][x])
		{
			if (cmd[1][x] == 39)
				cmd[1][x] = ' ';
			x++;
		}
	}
	return (cmd);
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
