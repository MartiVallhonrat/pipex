# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 11:30:49 by mvallhon          #+#    #+#              #
#    Updated: 2024/03/13 18:04:37 by mvallhon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

GCC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

LIBFT = libs/libft
GETLINE = libs/get_next_line

SRCS_FILES = main.c \
			 ft_strcmpl.c \
			 throw_error.c \
			 do_pipex.c \
			 split_path.c \
			 ft_strlcpy_path.c \
			 exec.c \

HEAD = pipex.h
MAKE = Makefile

SRCS_DIR = srcs/
OBJS_DIR = objs/


OBJS_FILES = $(SRCS_FILES:.c=.o)
DEPS_FILES = $(SRCS_FILES:.c=.d)

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))
DEPS = $(addprefix $(OBJS_DIR), $(DEPS_FILES))

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p objs
	$(GCC) $(CFLAGS) -c -MMD $< -o $@

make_libs: $(OBJS) $(HEAD) $(MAKE)
	@make -C $(LIBFT)
	@make -C $(GETLINE)

$(NAME): $(OBJS) $(HEAD) $(MAKE) make_libs
	$(GCC) $(CFLAGS) $(OBJS) $(GETLINE)/getline.a $(LIBFT)/libft.a -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJS_DIR)
	@make clean -C $(LIBFT)
	@make clean -C $(GETLINE)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a
	$(RM) $(GETLINE)/getline.a

re: fclean all

-include $(DEPS)

.PHONY: clean fclean re all
