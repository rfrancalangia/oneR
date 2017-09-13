/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:41:35 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 20:37:54 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

char			ft_list_pop_front(t_list **begin)
{
	t_list		*curr;
	char		holder;

	curr = *begin;
	if (curr == NULL)
		return ('\n');
	else if (curr->next == NULL)
	{
		holder = (curr->data);
		*begin = NULL;
		curr->next = NULL;
		free(curr);
	}
	else
	{
		holder = (curr->data);
		*begin = curr->next;
		curr->next = NULL;
		free(curr);
	}
	return (holder);
}
