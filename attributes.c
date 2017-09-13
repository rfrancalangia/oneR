/* ***************************************************************
 *  
 *  File Name : attributes.c
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-12-2017
 *  Last Modified : Wed Sep 13 00:01:24 2017
 *  Description :       
 *                               
 * *************************************************************** */

#include "algoOneR.h"

t_list	*get_identifier(int file_desc)
{
	char buf[BUF_SIZE];
	int red;
	t_list *identifier;
	t_list *temp;
	char holder = ' ';

	red = 0;
	temp = NULL;
	temp = ft_create_elem(&holder);
	while ((red = read(file_desc, buf, BUF_SIZE)) && (*buf != ' '))
	{
		temp->data = *buf;
		if (temp->data == '@')
		{
			identifier = temp;
		}
		temp->next = ft_create_elem(&holder);
		temp = temp->next;
	}
	return(identifier);
}
