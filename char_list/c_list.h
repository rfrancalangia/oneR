/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <rfrancal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:30:55 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 20:53:15 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H

# define FT_LIST_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	char		data;
}			c_list;

c_list			*c_create_elem(char *data);
void			c_list_push_back(c_list **begin, char *data);
void			c_list_clear(c_list **begin_list);
char			c_list_pop_front(c_list **begin);
int			c_length_list(c_list **begin);
char			*convert_to_string(c_list **begin);

#endif
