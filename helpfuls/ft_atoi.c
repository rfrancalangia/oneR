/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 20:08:08 by exam              #+#    #+#             */
/*   Updated: 2017/08/28 20:36:56 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			max_int(char *str)
{
	char	*c;
	int		max_int;
	int		i;

	i = 0;
	max_int = 1;
	c = "-2147483648";
	while (str[i])
	{
		if (c[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

int			is_operand(char c)
{
	if ((c == '=') || (c == '-') || (c == '+'))
		return (1);
	return (0);
}

int			ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		num;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t'))
		i++;
	if (max_int(str) == 1)
		return (-2147483648);
	if (str[i] == '-')
		sign = -1;
	if (is_operand(str[i] == 1))
		i++;
	while (str[i])
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
			num = ((num * 10) + (str[i] - '0'));
		else if ((str[i] < '0') || (str[i] > '9'))
			return (num * sign);
		i++;
	}
	return (num * sign);
}
