/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:15:54 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/30 20:19:56 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"

void	error_exit(const char *msg);
int		ft_arr_size(char **str);
char	**optmize_cmd(char **cmd, char *argv);
void	free_arr(char **str);
void	free_exit_error(char **cmd, char *msg);
char	*find_path(char *cmd, char **envp);
#endif