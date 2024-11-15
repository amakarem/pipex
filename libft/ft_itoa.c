/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:12:07 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/16 23:13:04 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		if (n <= -2147483647)
			return (11);
		n = (n * -1);
	}
	if (n <= 9)
		return (1);
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	if (n != 0)
		i++;
	return (i);
}

static int	ft_maxnegative(int n)
{
	if (n < 0)
	{
		if (n <= -2147483647)
			n = 214748364;
		else
			n = n * -1;
	}
	return (n);
}

static char	*ft_revnbr(char *rev, int n)
{
	int		negative;
	int		i;

	negative = 0;
	i = 0;
	if (n < 0)
	{
		negative = 1;
		if (n == -2147483648)
			rev[i++] = '8';
		n = ft_maxnegative(n);
	}
	while ((n / 10) > 0)
	{
		rev[i++] = (char)(n % 10) + 48;
		n = n / 10;
	}
	if (n != 0)
		rev[i++] = (char)n + 48;
	if (negative == 1)
		rev[i++] = '-';
	rev[i++] = '\0';
	return (rev);
}

static char	*ft_revstr(char *s)
{
	char	*tmp;
	int		len;
	int		i;

	len = ft_strlen(s) - 1 ;
	tmp = malloc(sizeof(char) * (len + 2));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (len >= 0)
	{
		tmp[i] = s[len];
		len--;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*rev;

	str = malloc(sizeof(char) * (ft_nbrlen(n) + 1));
	if (str == NULL)
		return (NULL);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	rev = ft_revnbr(str, n);
	str = ft_revstr(rev);
	free(rev);
	return (str);
}
