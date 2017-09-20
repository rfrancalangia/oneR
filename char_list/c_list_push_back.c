/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:46:46 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 20:03:00 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_list.h"

void	c_list_push_back(c_list **begin, char *data)
{
	c_list *curr;

	if (*begin == NULL)
	{
		*begin = c_create_elem(data);
		return ;
	}
	curr = *begin;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = c_create_elem(data);
}
