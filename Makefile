# * ***************************************************************
# *  
# *  File Name : Makefile
# *  Created By : rfrancalangia                                     
# *  
# *  Creation Date : 09-12-2017
# *  Last Modified : Tue Sep 19 21:09:07 2017
# *  Description :       
# *                               
# * *************************************************************** *

FILES = oneR.c open_and_store.c utilities.c
INCLUDES = char_list/*.c
RUN = oneR
FLAGS = -Wall -Werror -Wextra -o

all: $(RUN)

$(RUN):
	gcc $(FLAGS) $(RUN) $(FILES) $(INCLUDES);

clean:
	/bin/rm -f *.o

fclean:
	/bin/rm -rf $(RUN)

re: fclean all
