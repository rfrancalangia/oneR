/* ***************************************************************
 *  
 *  File Name : oneR.c
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-12-2017
 *  Last Modified : Wed Sep 13 00:01:18 2017
 *  Description : This will be the main file for the oneR algo       
 *                               
 * *************************************************************** */

#include "algoOneR.h"

int main(int argc, char **argv)
{
	int 	file_desc;
	int 	i;
	char	*str;
	t_list	*temp;
	i = 0;
	file_desc = 0;
	argv++;
	argc--;
	file_desc = open(argv[i], O_RDONLY);
	if (file_desc == -1)
		file_desc = 0;
	temp = get_identifier(file_desc);
	str = convert_to_string(&temp);
	printf("Here yo: %s", str);
	return (0);
}
