/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:23:16 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/16 18:24:01 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_ar(char	**arr)
{
	int	i;

	if (arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static size_t	ft_get_keys(char const *s, char c)
{
	size_t	keys;

	if (!*s)
		return (0);
	keys = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			keys++;
		while (*s != c && *s)
			s++;
	}
	return (keys);
}

static char	**ft_set_arr(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc((ft_get_keys(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	return (arr);
}

static char	**ft_split_write(char const *s, char c, char **arr)
{
	int		key;
	size_t	w_len;

	key = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				w_len = ft_strlen(s);
			else
				w_len = ft_strchr(s, c) - s;
			arr[key] = ft_substr(s, 0, w_len);
			if (arr[key] == NULL)
				return (ft_free_ar(arr));
			key++;
			s += w_len;
		}
	}
	arr[key] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = ft_set_arr(s, c);
	if (arr == NULL)
		return (NULL);
	return (ft_split_write(s, c, arr));
}
