/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 17:36:52 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 20:52:20 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		square_reset(t_square *globe)
{
	free(globe->map);
	free(globe->rows[0]);
	free(globe->rows[1]);
	globe->size[0] = 0;
	globe->size[1] = 0;
	globe->cols[0] = 0;
	globe->cols[1] = 0;
	globe->indicator[0] = ' ';
	globe->indicator[1] = ' ';
	globe->indicator[2] = ' ';
	globe->max_position[0] = 0;
	globe->max_position[1] = 0;
	globe->max_position[2] = 0;
	ft_list_clear(&globe->first_line);
}

void		convert_to_string(t_square *globe)
{
	int		i;
	char	c;

	i = 0;
	while (i < globe->size[0])
	{
		c = globe->first_line->data;
		globe->map[0][i] = c;
		globe->first_line = globe->first_line->next;
		i++;
	}
}
