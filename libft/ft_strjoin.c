/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:05:39 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/13 16:25:57 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[len] = s1[i];
		len++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[len] = s2[i];
		len++;
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}
