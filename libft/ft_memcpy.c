/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:29:28 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/10 22:48:10 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*srcptr;
	unsigned char	*dstptr;
	size_t			i;

	srcptr = (unsigned char *) src;
	dstptr = (unsigned char *) dst;
	if (dst == NULL && src == NULL)
	{
		return ((void *) dst);
	}
	i = 0;
	while (i < n)
	{
		dstptr[i] = srcptr[i];
		i++;
	}
	return ((void *) dstptr);
}
