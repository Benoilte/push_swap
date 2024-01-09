# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:59:35 by bebrandt          #+#    #+#              #
#    Updated: 2024/01/09 11:40:28 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_NAME	=	push_swap

PUSH_SRCS	=	push_swap.c  fill_stack_a.c sort_small_stack.c push_swap_algo.c \
				push_swap_algo_utils.c input_validation.c operations_swap.c \
				operations_push.c operations_reverse.c operations_rotate.c \
				error.c safe_free.c count_move.c check_sorted_stack.c find_range.c \
				find_min_max.c push_swap_algo_ben.c
	
PUSH_OBJS = $(PUSH_SRCS:.c=.o)

PUSH_OBJ = $(addprefix $(OBJ_DIR),$(PUSH_OBJS))

CHECK_NAME	=	checker

CHECK_SRCS	=	checker.c fill_stack_a.c input_validation.c error.c safe_free.c \
				operations_swap.c operations_push.c operations_reverse.c operations_rotate.c \
				check_sorted_stack.c find_min_max.c

CHECK_OBJS = $(CHECK_SRCS:.c=.o)

CHECK_OBJ = $(addprefix $(OBJ_DIR),$(CHECK_OBJS))

LIBFT_DIR		=	libft

LIBFT_NAME		=	libft.a

PRINTF_DIR		=	libftprintf

PRINTF_NAME		=	libftprintf.a

HDRS		=	-I headers/.

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

AR			=	ar rcs

LIB			=	ranlib

RM			=	rm -f

LIB_DIR		=	libft/
PRINTF_DIR	=	printf/
SRC_DIR		=	srcs/
OBJ_DIR		=	objs/

RED			=	\033[0;31m
GREEN		=	\033[0;32m
NONE		=	\033[0m

all: $(PUSH_NAME)

bonus: $(CHECK_NAME)

$(CHECK_NAME): $(CHECK_OBJ)
	@make -C $(PRINTF_DIR) --silent
	@gcc -o $(CHECK_NAME) $(CHECK_OBJ) -L $(PRINTF_DIR) -lftprintf
	@echo "$(GREEN)##### checker compiling finished! #####$(NONE)"

$(PUSH_NAME): $(PUSH_OBJ)
	@make -C $(PRINTF_DIR) --silent
	@gcc -o $(PUSH_NAME) $(PUSH_OBJ) -L $(PRINTF_DIR) -lftprintf
	@echo "$(GREEN)##### push_swap compiling finished! #####$(NONE)"
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)##### Creating" [ $@ ] " #####$(NONE)"
	@gcc $(CFLAGS) -o $@ -c $< $(HDRS)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@make -C $(PRINTF_DIR) clean  --silent
	@rm -f $(CHECK_OBJ) $(PUSH_OBJ)
	@echo "$(RED)##### Removed object files #####$(NONE)"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@make -C $(PRINTF_DIR) fclean  --silent
	@rm -f $(CHECK_NAME) $(PUSH_NAME)
	@echo "$(RED)##### Removed binary files #####$(NONE)"

re: fclean all

.PHONY: all clean fclean re
