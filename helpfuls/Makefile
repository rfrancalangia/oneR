# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfrancal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/21 11:38:42 by rfrancal          #+#    #+#              #
#    Updated: 2017/08/30 21:11:44 by rfrancal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = main.c open.c ft_prints.c errors.c ft_atoi.c evaluate.c struct.c srcs/*.c 
INCLUDE = includes/
RUN = bsq 

all: $(RUN)

$(RUN):
	gcc -Wall -Werror -Wextra -o $(RUN) $(FILES); 

clean:
	/bin/rm -f *.o

fclean:
	/bin/rm -f $(RUN)

norm:
	norminette $(FILES);

re:	fclean all

