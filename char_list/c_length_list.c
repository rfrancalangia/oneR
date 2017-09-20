/* ***************************************************************
 *  
 *  File Name : c_length_list.c
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-12-2017
 *  Last Modified : Tue Sep 19 20:28:01 2017
 *  Description :       
 *                               
 * *************************************************************** */

#include "c_list.h"

int	c_length_list(c_list **begin)
{
	int len;
	c_list *temp; 

	temp = *begin;
	len = 0;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
