/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrancal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 21:26:24 by rfrancal          #+#    #+#             */
/*   Updated: 2017/08/30 20:50:47 by rfrancal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void		ft_list_clear(t_list **begin_list)
{
	if (*begin_list == NULL)
		return ;
	while ((*begin_list) && ((*begin_list)->next != '\0'))
	{
		ft_list_clear(&((*begin_list)->next));
	}
	free(*begin_list);
	*begin_list = NULL;
}
