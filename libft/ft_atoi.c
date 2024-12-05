/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:27:59 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 05:16:45 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_return_max(int flag)
{
	if (flag == 1)
		return (2147483647);
	return (-2147483648);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		flag;

	flag = 1;
	nbr = 0;
	i = 0;
	while (str[i] != '\0' && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		flag = (flag * -1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (nbr > 214748364 || (nbr == 214748364 && (str[i] - '0') > 7))
			return (ft_return_max(flag));
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * flag);
}
