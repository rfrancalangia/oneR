# * ***************************************************************
# *  
# *  File Name : Makefile
# *  Created By : rfrancalangia                                     
# *  
# *  Creation Date : 09-12-2017
# *  Last Modified : Tue Sep 12 18:28:29 2017
# *  Description :       
# *                               
# * *************************************************************** *

FILES = oneR.c
INCLUDES = includes/
RUN = oneR
FLAGS = -Wall -Werror -Wextra -o

all: $(RUN)

$(RUN):
	gcc $(FLAGS) $(RUN) $(FILES);

clean:
	/bin/rm -f *.o

fclean:
	/bin/rm -f $(RUN)

re:
	fclean all
