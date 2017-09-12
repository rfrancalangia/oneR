/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 15:04:05 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 21:15:34 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			get_first_line(int file, char *indicator)
{
	char	buf[BUF_SIZE];
	int		red;
	int		size;
	int		i;

	red = 0;
	size = 0;
	i = 0;
	while ((red = read(file, buf, BUF_SIZE)) && (*buf != '\n'))
	{
		if (SED(*buf))
			continue ;
		else if (*buf >= '0' && *buf <= '9')
			size = (size * 10) + (ft_atoi(buf));
		else if (*buf != '\n')
		{
			indicator[i] = *buf;
			i++;
		}
		else
			break ;
	}
	return (map_error(size));
}

int			count_first_line(int file_desc, t_square *globe)
{
	int		red;
	int		first;
	char	buf[BUF_SIZE];

	first = 0;
	while ((red = read(file_desc, buf, BUF_SIZE)))
	{
		if (*buf == '\n')
			break ;
		else if ((*buf != globe->indicator[0]) && (*buf != globe->indicator[1]))
			return (map_error(0));
		else
		{
			ft_list_push_back(&globe->first_line, buf);
			first++;
		}
	}
	return (first);
}

int			allocate_rows(t_square *globe)
{
	int		row;

	row = 0;
	while (row < globe->size[1])
	{
		globe->map[row] = malloc(sizeof(char *) * globe->size[0]);
		row++;
	}
	return (0);
}

char		**size_file(int file_desc, t_square *globe)
{
	int		red;
	char	buf[BUF_SIZE];
	int		col;
	int		row;

	col = 0;
	row = 1;
	while ((red = read(file_desc, buf, BUF_SIZE)))
	{
		if ((*buf == globe->indicator[0]) || (*buf == globe->indicator[1]))
			globe->map[row][col++] = *buf;
		else if (*buf == '\n')
		{
			if (col != globe->size[0])
			{
				map_error(0);
				return (NULL);
			}
			row++;
			col = 0;
		}
	}
	failed_close(close(file_desc));
	return (globe->map);
}
