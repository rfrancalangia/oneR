/* ***************************************************************
 *  
 *  File Name : oneR.c
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-12-2017
 *  Last Modified : Tue Sep 19 21:01:16 2017
 *  Description : This will be the main file for the oneR algo       
 *                               
 * *************************************************************** */

#include "algoOneR.h"

int main(int argc, char **argv)
{
	int 		file_desc;
	int 		i;
	//char		*str;
	s_outcome 	*classifiers;
	
	classifiers = malloc(sizeof(*classifiers)* 1);
	i = 0;
	file_desc = 0;
	argv++;
	argc--;
	if (argc != 1)
		return (0);
	file_desc = open(argv[i], O_RDONLY);
	if (file_desc == -1)
		file_desc = 0;
	i = input_titles(file_desc, classifiers);
	printf("Here yo: %s\n", classifiers->title);
	return (0);
}
