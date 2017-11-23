# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astrelov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 11:15:26 by astrelov          #+#    #+#              #
#    Updated: 2017/11/13 11:15:28 by astrelov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re $(NAME)

NAME=fillit

SRC= main.c validate.c mapper.c solver.c

CFLAGS= -Wall -Werror -Wextra

HEADER= -I ./includes/

LIBINCL= -L. ./includes/libft/libft.a

LIBDIR= ./includes/libft/

OBJFOLD= ./obj/

OBJ=$(addprefix $(OBJFOLD),$(patsubst %.c, %.o, $(SRC)))

all:			$(NAME)

$(NAME):		$(OBJ)
	@make -C $(LIBDIR) -f Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBINCL)
	@echo "Fillit: done"

$(OBJFOLD)%.o: 	%.c
	@mkdir -p $(OBJFOLD)
	gcc $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJFOLD)
	@make -C $(LIBDIR) -f Makefile clean
	@echo "objects removed"

fclean:			clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) -f Makefile fclean
	@echo "binary removed"

re:				fclean all
