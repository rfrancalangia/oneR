/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 14:34:05 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 21:15:38 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				main(int argc, char **argv)
{
	int			i;
	t_square	*globe;
	int			file_desc;

	i = 1;
	file_desc = 0;
	globe = malloc(sizeof(*globe) * 1);
	while ((i < argc) || (i == 1))
	{
		file_desc = open(argv[i], O_RDONLY);
		if (file_desc == -1)
			file_desc = 0;
		if (first_error_check(file_desc, globe) == -1)
			return (0);
		globe->map = malloc(sizeof(char **) * globe->size[1]);
		allocate_rows(globe);
		convert_to_string(globe);
		if ((globe->map = second_error_check(file_desc, globe)) == NULL)
			return (0);
		ft_printmap(globe);
		square_reset(globe);
		i++;
		if (i < argc)
			ft_putchar('\n');
	}
}

int				first_error_check(int file_desc, t_square *globe)
{
	globe->size[1] = get_first_line(file_desc, globe->indicator);
	if (globe->size[1] == -1)
		return (-1);
	globe->size[0] = count_first_line(file_desc, globe);
	if (globe->size[0] == -1)
		return (-1);
	return (1);
}

char			**second_error_check(int file_desc, t_square *globe)
{
	globe->map = (size_file(file_desc, globe));
	if (globe->map == NULL)
		return (NULL);
	globe->map = evaluate(globe);
	if (globe->map == NULL)
		return (NULL);
	return (globe->map);
}
