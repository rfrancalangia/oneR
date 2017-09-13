/* ***************************************************************
 *  
 *  File Name : ft_list_string.c
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-12-2017
 *  Last Modified : Wed Sep 13 00:01:46 2017
 *  Description : Take a char list and return a char string      
 *                               
 * *************************************************************** */

#include "ft_list.h"

char		*convert_to_string(t_list **begin)
{
	int	i;
	int	len;
	char	c;
	char 	*str;
	t_list	*temp;

	temp = *begin;
	len = ft_length_list(begin);
	i = 0;
	str = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		c = temp->data;
		str[i] = c;
		temp = temp->next;
		i++;
	}
	return (str);
}
