NAME = getline.a

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -f

SRCS = get_next_line.c \
	   get_next_line_utils.c \

HEAD = get_next_line.h
MAKE = Makefile

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

%.o: %.c
	$(GCC) $(CFLAGS) -c -MMD -MP $<

$(NAME): $(OBJS) $(HEAD) $(MAKE)
	$(LIB) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

-include $(DEPS)

.PHONY: clean fclean re all bonus rebonus
