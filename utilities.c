/* ***************************************************************
 *  
 *  File Name : utilities.c
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-19-2017
 *  Last Modified : Tue Sep 19 21:00:59 2017
 *  Description : strcmp etc.     
 *                               
 * *************************************************************** */

int	my_strcmp(char *a, char *b)
{
	while (*a)
	{
		if (*a != *b)
			return (-1);
		a++;
		b++;
	}
	if (*b != '\0')
		return (-1);
	else
		return (1);
}

