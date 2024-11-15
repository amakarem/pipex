/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:23:48 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/11 18:33:20 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;

	s1ptr = (unsigned char *) s1;
	s2ptr = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1ptr[i] != (unsigned char)s2ptr[i])
		{
			return ((unsigned char)s1ptr[i] - (unsigned char)s2ptr[i]);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1ptr[i] - (unsigned char)s2ptr[i]);
	}
	return (0);
}
