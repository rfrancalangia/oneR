/* ***************************************************************
 *  
 *  File Name : attributes.c
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-12-2017
 *  Last Modified : Tue Sep 19 21:13:19 2017
 *  Description :       
 *                               
 * *************************************************************** */

#include "algoOneR.h"

char	*get_identifier(int file_desc)
{
	char 	buf[BUF_SIZE];
	int 	red;
	c_list 	*identifier;
	c_list 	*temp;
	char	*str;
	
	red = 0;
	temp = NULL;
	while ((red = read(file_desc, buf, BUF_SIZE)) && (*buf != ' '))
	{
		if (*buf == '@')
		{
			temp = c_create_elem(buf);
			identifier = temp;
			continue ;
		}
		if (temp != NULL)
		{
			temp->next = c_create_elem(buf);
			temp = temp->next;
		}
	}
	str = convert_to_string(&identifier);
	return(str);
}

char	*get_title(int file_desc)
{
	char buf[BUF_SIZE];
	int red;
	c_list *title;
	c_list *temp;
	char *str;

	red = 0;
	temp = NULL;
	while ((red = read(file_desc, buf, BUF_SIZE)) && (*buf != '\n'))
	{
		if ((*buf != ' ') && (temp == NULL))
		{
			temp = c_create_elem(buf);
			title = temp;
			continue ;
		}
		if (temp != NULL)
		{
			temp->next = c_create_elem(buf);
			temp = temp->next;
		}
	}
	str = convert_to_string(&title);
	return(str);
}


int	input_titles(int file_desc, s_outcome *classifiers)
{
	char *str;
	
	str = (get_identifier(file_desc));
	while (my_strcmp(str, DATA) == -1)
	{
		if (my_strcmp(str, TYPE) == 1)
		{
			classifiers->title = get_title(file_desc);
		}
		else if (my_strcmp(str, ATTRIBUTE) == 1)
		{
			//printf("Need to make the attribute class or struct\n");	
			printf("%s ", str);
			printf("%s\n", get_title(file_desc));
			//insert 
		}
		else
		{
			printf("Breaking\n");
			break ;
		}
		str = (get_identifier(file_desc));	
	}
	return (0);
}
