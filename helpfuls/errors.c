/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 17:00:39 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 22:25:26 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		failed_open(int file)
{
	if (file == -1)
	{
		ft_putstr_error("Error: Open Failed\n");
		return (-1);
	}
	else
		return (1);
}

int		failed_close(int file)
{
	if (file == -1)
	{
		ft_putstr_error("Error: Close Failed\n");
		return (0);
	}
	else
		return (1);
}

int		invalid_file(void)
{
	ft_putstr_error("Error: Invalid File\n");
	return (-1);
}

int		map_error(int check)
{
	if (check == 0)
	{
		ft_putstr_error("map error\n");
		return (-1);
	}
	return (check);
}
