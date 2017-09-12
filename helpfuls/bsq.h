/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 16:42:30 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 21:15:41 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H

# define BSQ_H

# define BUF_SIZE 1
# define SED(x)	(x == ' ' || x == '\t' || x == '\v' || x == '\r')

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "srcs/ft_list.h"

typedef	struct	s_square
{
	char	**map;
	char	indicator[3];
	int		*rows[2];
	int		size[2];
	int		cols[2];
	int		max_position[3];
	t_list	*first_line;
}				t_square;

void			ft_putchar(char c);
void			ft_putchar_error(char c);
void			ft_putstr(char *str);
void			ft_putstr_error(char *str);
void			ft_printmap(t_square *globe);

int				failed_open(int file);
int				failed_close(int file);
int				invalid_file(void);
int				map_error(int check);
int				first_error_check(int file_desc, t_square *globe);
char			**second_error_check(int file_desc, t_square *globe);

int				get_first_line(int file, char *indicator);
char			**size_file(int file_desc, t_square *globe);
void			square_reset(t_square *globe);
int				count_first_line(int file_desc, t_square *globe);
int				allocate_rows(t_square *globe);

int				choose_val(int row, int col, t_square *globe);
int				catalog_max(int *num_array, t_square *globe, int row);
char			**evaluate(t_square *globe);
char			**input_largest(t_square *globe);
void			iterate(t_square *globe);

int				ft_atoi(char *str);
void			convert_to_string(t_square *globe);

#endif
