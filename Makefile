# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:59:35 by bebrandt          #+#    #+#              #
#    Updated: 2023/12/04 17:36:34 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_NAME	=	push_swap

PUSH_SRCS	=
	
PUSH_OBJ_NAME = $(PUSH_SRC_NAME:.c=.o)

PUSH_OBJ = $(addprefix $(OBJ_DIR),$(PUSH_OBJ_NAME))

CHECK_NAME	=	checker

CHECK_SRCS	=	

CHECK_OBJ_NAME = $(CHECK_SRC_NAME:.c=.o)

CHECK_OBJ = $(addprefix $(OBJ_DIR),$(CHECK_OBJ_NAME))

LIBFT_DIR		=	libft

LIBFT_NAME		=	libft.a

PRINTF_DIR		=	libftprintf

PRINTF_NAME		=	libftprintf.a

HDRS		=	-I .

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

AR			=	ar rcs

LIB			=	ranlib

RM			=	rm -f

LIB_DIR = libft/
PRINTF_DIR = printf/
SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(CHECK_NAME) $(PUSH_NAME)

$(CHECK_NAME): $(CHECK_OBJ)
	@make -C $(PRINTF_DIR) --silent
	@gcc -o $(CHECK_NAME) $(CHECK_OBJ) -L $(PRINTF_DIR) -lftprintf
	@echo "##### checker compiling finished! #####"

$(PUSH_NAME): $(PUSH_OBJ)
	@make -C $(PRINTF_DIR) --silent
	@gcc -o $(PUSH_NAME) $(PUSH_OBJ) -L $(PRINTF_DIR) -lftprintf
	@echo "##### push_swap compiling finished! #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) -o $@ -c $< $(HDRS)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@make -C $(PRINTF_DIR) clean  --silent
	@rm -f $(CHECK_OBJ) $(PUSH_OBJ)
	@echo "##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@make -C $(PRINTF_DIR) fclean  --silent
	@rm -f $(CHECK_NAME) $(PUSH_NAME)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re