# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eveiled <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 12:45:23 by eveiled           #+#    #+#              #
#   Updated: 2021/11/05 16:53:31 by eveiled          ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
#
SOURSE = add_functions.c check_list_int.c find_median.c main.c\
		operations_1.c operations_2.c operations_3.c\
		small_array.c sort_new.c sort_new_1.c\
		sort_new_01.c sort_new_2.c sort_new_3.c\
#
CFLAGS		= -Wall -Werror -Wextra -I $(HEADER)
HEADER	= push_swap.h
OBJ = $(SOURSE:%.c=%.o)
CC = gcc
LIBFTDIR	= ./libft
#
.PHONY : all clean fclean re re_libft
#
all : $(NAME)
#
$(NAME) :  $(SOURSE) $(HEADER)
	@make -C $(LIBFTDIR)
	$(CC) -L./libft -lft $(CFLAGS) $(SOURSE) -o $(NAME)
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
clean :
	@rm -f $(OBJ)
	@make clean -C $(LIBFTDIR)
#
fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
#
re_libft :
	@make re -C $(LIBFTDIR)
#
re : fclean re_libft all



