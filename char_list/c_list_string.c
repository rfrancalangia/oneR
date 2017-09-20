/* ***************************************************************
 *  
 *  File Name : c_list_string.c
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-12-2017
 *  Last Modified : Tue Sep 19 20:23:51 2017
 *  Description : Take a char list and return a char string      
 *                               
 * *************************************************************** */

#include "c_list.h"

char		*convert_to_string(c_list **begin)
{
	int	i;
	int	len;
	char	c;
	char 	*str;
	c_list	*temp;

	temp = *begin;
	len = c_length_list(begin);
	i = 0;
	str = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		c = temp->data;
		str[i] = c;
		temp = temp->next;
		i++;
	}
	str[i] = '\0';
	return (str);
}
