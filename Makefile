# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mlokhors <mlokhors@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/11 08:54:54 by mlokhors       #+#    #+#                 #
#    Updated: 2019/12/19 13:09:19 by mlokhors      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME_ONE := push_swap
NAME_TWO := checker 
FLAGS := -Wall -Werror -Wextra -g
CC := gcc

LIBFT_DIR:=./libft/
LIBFT_H =./libft/includes/
LIBFT_A:=$(LIBFT_DIR)/libft.a

PRT_DIR:=./ft_printf/
PRT_H:=./ft_printf/
PRT_A:=$(PRT_DIR)/libftprintf.a

HEADER:=./includes/

SRC_DIR:=./src/
OBJ_DIR=./.obj/

SRC_SH = 	sh_natoi.c \
			sh_init_stacks.c \
			sh_do_instruction.c \
			sh_is_sorted.c \
			sh_pp.c \
			sh_rr.c \
			sh_rrr.c \
			sh_ss.c \
			sh_lst_check.c \
			sh_new_elem.c \
			sh_check_stack.c \
			sh_error_only_stack.c

SRC_PS =	ps_push_swap.c \
			ps_add_instruction_and_operations.c \
			ps_brute_force.c \
			ps_brute_force_state_1.c \
			ps_brute_force_state_2.c \
			ps_brute_force_state_3.c \
			ps_brute_force_state_4.c \
			ps_brute_force_state_5.c \
			ps_error_with_list.c \
			ps_is_rev_sorted.c \
			ps_undo_instructions.c \
			ps_big_sorting.c \
			ps_calculate_distance.c \
			ps_shift_stack.c \
			ps_set_sort_stack.c \
			ps_init_functions.c \
			ps_search_for_lowest_distance.c \
			ps_search_and_do_shortest_distance.c \
			ps_excute_up_down.c \
			ps_set_target_1.c \
			ps_set_target_2.c

SRC_CH =	ch_checker.c

OBJ = $(SRC_SH:.c=.o) $(SRC_PS:.c=.o) $(SRC_CH:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ_SH = $(addprefix $(OBJ_DIR), $(SRC_SH:.c=.o))
OBJ_CH = $(addprefix $(OBJ_DIR), $(SRC_CH:.c=.o))
OBJ_PS = $(addprefix $(OBJ_DIR), $(SRC_PS:.c=.o))

SRCS = $(addprefix $(SRC_DIR), $(SRC_SH)) $(addprefix $(SRC_DIR), $(SRC_PS)) $(addprefix $(SRC_DIR), $(SRC_CH))

all: $(LIBFT_A) $(PRT_A) $(NAME_ONE) $(NAME_TWO)

$(NAME_ONE): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME_ONE) $(OBJ_PS) $(OBJ_SH) -L./$(LIBFT_DIR) -lft -L./$(PRT_DIR) -lftprintf

$(NAME_TWO): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME_TWO) $(OBJ_SH) $(OBJ_CH) -L./$(LIBFT_DIR) -lft -L./$(PRT_DIR) -lftprintf

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(FLAGS)  -I$(HEADER) -I$(LIBFT_H) -I$(PRT_H)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(PRT_A):
	$(MAKE) -C $(PRT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRT_DIR) fclean
	rm -f $(NAME_ONE)
	rm -f $(NAME_TWO)

re: fclean all