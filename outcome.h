/* ***************************************************************
 *  
 *  File Name : outcome.h
 *  Created By : rfrancalangia                                     
 *  
 *  Creation Date : 09-19-2017
 *  Last Modified : Tue Sep 19 21:00:50 2017
 *  Description : class struct header file      
 *                               
 * *************************************************************** */

#ifndef OUTCOME_H

# define OUTCOME_H

typedef struct outcome
{
	char 	*title;
	int 	num_outcomes;
	char 	**outcomes;
	int 	*outcome_counts;
	int	population;
} 		s_outcome;

#endif

