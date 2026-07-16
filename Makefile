NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -I.

SRCS = $(wildcard srcs/*.c)

OBJDIR = objs
OBJS = $(SRCS:srcs/%.c=$(OBJDIR)/%.o)

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJDIR)/%.o: srcs/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re