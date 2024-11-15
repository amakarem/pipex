/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:34:46 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/11 19:25:25 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srcptr;
	char	*dstptr;
	size_t	i;

	srcptr = (char *) src;
	dstptr = (char *) dst;
	if (dst == NULL && src == NULL)
		return ((void *) dst);
	if (srcptr < dstptr)
	{
		while (len--)
			dstptr[len] = srcptr[len];
	}
	else
	{
		i = 0;
		while (i++ < len)
			dstptr[i - 1] = srcptr[i - 1];
	}
	return ((void *) dst);
}
