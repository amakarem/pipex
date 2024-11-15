/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:50:54 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/10 21:09:04 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	index;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	index = dstlen;
	while (src[i] != '\0' && index < (dstsize - 1))
	{
		dst[index] = src[i];
		i++;
		index++;
	}
	dst[index] = '\0';
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	return (srclen + dstlen);
}
