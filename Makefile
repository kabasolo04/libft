NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

AR = ar rcs

# -------------------- RULES --------------------

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo ""
	@echo "  ##---------------------------------------------------------##"
	@echo "  ##        libft: library compiled successfully             ##"
	@echo "  ##---------------------------------------------------------##"
	@echo ""

# Compile .c -> obj/.o
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo ""
	@echo "  ##---------------------------------------------------------##"
	@echo "  ##        libft: object files removed                      ##"
	@echo "  ##---------------------------------------------------------##"
	@echo ""

fclean: clean
	@rm -f $(NAME)
	@echo ""
	@echo "  ##---------------------------------------------------------##"
	@echo "  ##        libft: library removed                           ##"
	@echo "  ##---------------------------------------------------------##"
	@echo ""

re: fclean all

.PHONY: all clean fclean re
.SILENT: