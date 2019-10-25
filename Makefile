# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nharra <nharra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 18:13:07 by nharra            #+#    #+#              #
#    Updated: 2019/10/25 17:37:59 by nharra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS = -Wall -Werror -Wextra

SRCS =\
	ft_ls.c\
	make_flag_and_args.c\
	check_sort.c\
	cmp.c\
	ls_dir.c\
	simple_print.c\
	hard_print.c\
	ls_info.c\
	print_info.c\
	get_extatr.c\
	print_filename.c\
	print_total.c\
	check_perm_denied.c\
	print_time.c\
	print_mode.c\
	print_illegal_option.c\
	erase_dirs.c\
	cmp_2.c\
	collumn_print.c\

SOURCES_DIR = src


SOURCE = $(addprefix $(SOURCES_DIR)/, $(SRCS))

OBJECTS_DIR = obj

OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(OBJS))

OBJS = $(SRCS:.c=.o)

INCLUDE_DIR = includes

INCLUDES = lem_in.h \
			list_rooms.h

NAME = ft_ls

LIBFT = $(addprefix $(LIBFT_DIR)/, libft.a)

LIBFT_DIR = libft

LIBFT_INCLUDE_DIR = libft/includes

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJECTS_DIR) $(OBJECTS)
	gcc -o $(NAME) $(OBJECTS_LIST) $(OBJECTS)  -I $(LIBFT_INCLUDE_DIR) -I $(INCLUDE_DIR) -L libft/ -lft $(FLAGS)

$(OBJECTS): | $(OBJECTS_DIR)


$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c
	gcc  -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR) -c $< -o $@ $(FLAGS)


$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR) all

fclean:
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJECTS_DIR)
	rm -rf $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJECTS_DIR)

re: fclean all

.PHONY: all, clean, fclean, re, make_lib
