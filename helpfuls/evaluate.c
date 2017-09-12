/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 20:02:20 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 21:12:48 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		iterate(t_square *globe)
{
	int		r;
	int		c;

	r = 0;
	while (r < globe->size[1])
	{
		c = 0;
		while (c < globe->size[0])
		{
			if (globe->map[r][c] == globe->indicator[1])
				globe->rows[r % 2][c] = 0;
			else if ((c == 0) || (r == 0))
				globe->rows[r % 2][c] = 1;
			else
				globe->rows[r % 2][c] = choose_val(r, c, globe);
			c++;
		}
		catalog_max(globe->rows[r % 2], globe, r);
		r++;
	}
}

char		**evaluate(t_square *globe)
{
	int		c;

	globe->rows[0] = malloc(sizeof(int) * globe->size[0]);
	globe->rows[1] = malloc(sizeof(int) * globe->size[0]);
	c = 0;
	while (c < globe->size[0])
	{
		globe->rows[0][c] = 0;
		globe->rows[1][c] = 0;
		c++;
	}
	globe->max_position[0] = 0;
	iterate(globe);
	globe->map = input_largest(globe);
	return (globe->map);
}

int			choose_val(int row, int col, t_square *globe)
{
	int		min_adjacent;
	int		prev_line;

	prev_line = (row % 2) + 1;
	if (prev_line == 2)
		prev_line = 0;
	min_adjacent = (globe->rows[row % 2][col - 1]);
	if (min_adjacent > globe->rows[prev_line][col - 1])
		min_adjacent = globe->rows[prev_line][col - 1];
	if (min_adjacent > globe->rows[prev_line][col])
		min_adjacent = globe->rows[prev_line][col];
	return (min_adjacent + 1);
}

int			catalog_max(int *num_array, t_square *globe, int row)
{
	int		i;

	i = 0;
	while (i < globe->size[0])
	{
		if (num_array[i] > globe->max_position[0])
		{
			globe->max_position[0] = num_array[i];
			globe->max_position[1] = row;
			globe->max_position[2] = i;
		}
		i++;
	}
	return (0);
}

char		**input_largest(t_square *globe)
{
	int		row;
	int		col;

	row = globe->max_position[1] + 1 - globe->max_position[0];
	while (row <= globe->max_position[1])
	{
		col = globe->max_position[2] + 1 - globe->max_position[0];
		while (col <= globe->max_position[2])
		{
			globe->map[row][col] = globe->indicator[2];
			col++;
		}
		row++;
	}
	return (globe->map);
}
