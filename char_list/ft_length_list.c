/* ***************************************************************
 *  
 *  File Name : ft_length_list.c
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-12-2017
 *  Last Modified : Wed Sep 13 00:01:52 2017
 *  Description :       
 *                               
 * *************************************************************** */

#include "ft_list.h"

int	ft_length_list(t_list **begin)
{
	int len;
	t_list *temp; 

	temp = *begin;
	len = 0;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
