/* ***************************************************************
 *  
 *  File Name : algoOneR.h
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-12-2017
 *  Last Modified : Wed Sep 13 00:01:22 2017
 *  Description :       
 *                               
 * *************************************************************** */

#ifndef ALGOONER_H

# define ALGOONER_H
# define BUF_SIZE 1

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "char_list/ft_list.h"

t_list	*get_identifier(int file_desc);
#endif
