/* ***************************************************************
 *  
 *  File Name : algoOneR.h
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-12-2017
 *  Last Modified : Tue Sep 19 21:01:13 2017
 *  Description :       
 *                               
 * *************************************************************** */

#ifndef ALGOONER_H

# define ALGOONER_H
# define BUF_SIZE 1
# define TYPE "@relation"
# define ATTRIBUTE "@attribute"
# define DATA "@data"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "char_list/c_list.h"
# include "outcome.h"

//Input
char	*get_identifier(int file_desc);
char	*get_title(int file_desc);
int		input_titles(int file_desc, s_outcome *classifiers);

//Utilities
int		my_strcmp(char *a, char *b);

#endif
