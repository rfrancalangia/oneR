/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_create_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <rfrancal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:46:46 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 20:36:46 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_list.h"

c_list		*c_create_elem(char *data)
{
	c_list *temp;

	temp = malloc(sizeof(c_list));
	if (temp)
	{
		temp->data = *data;
		temp->next = NULL;
	}
	return (temp);
}
