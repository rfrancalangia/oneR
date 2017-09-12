/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <rfrancal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 11:44:01 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 21:26:24 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putchar_error(char c)
{
	write(2, &c, 1);
}

void	ft_putstr_error(char *str)
{
	while (*str)
	{
		ft_putchar_error(*str);
		str++;
	}
}

void	ft_printmap(t_square *globe)
{
	int row;

	row = 0;
	while (row < globe->size[1])
	{
		write(1, globe->map[row], globe->size[0]);
		ft_putchar('\n');
		row++;
	}
}
