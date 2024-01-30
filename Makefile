NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	ft_strchr.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_isascii.c \
	ft_strlen.c \
	ft_bzero.c \
	ft_strncmp.c \
	ft_isalnum.c \
	ft_strnstr.c \
	ft_isalpha.c \
	ft_strrchr.c \
	ft_isdigit.c \
	ft_tolower.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_atoi.c \
	 \
	ft_calloc.c \
	ft_strdup.c \
	 \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \

OBJECTS = $(SOURCES:%.c=%.o)

BONUS = \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \

BONUS_OBJS = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	echo ""
	echo "  ##---------------------------------------------------------##"
	echo "  ##                                                         ##"
	echo "  ##        Makefile: The library has been compiled.         ##"
	echo "  ##                                                         ##"
	echo "  ##---------------------------------------------------------##"
	echo ""

clean:
	rm -f $(OBJECTS) $(BONUS_OBJS)
	echo ""
	echo "  ##---------------------------------------------------------##"
	echo "  ##                                                         ##" 
	echo "  ##  Makefile: The .o terminated files have been removed.   ##"
	echo "  ##                                                         ##"
	echo "  ##---------------------------------------------------------##"
	echo ""

fclean: clean
	rm -f $(NAME)

	echo "  ##---------------------------------------------------------##"
	echo "  ##                                                         ##"
	echo "  ##  Makefile: The library libft.a has been removed.        ##"
	echo "  ##                                                         ##"
	echo "  ##---------------------------------------------------------##"
	echo ""

re: fclean $(NAME)

bonus: $(OBJECTS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJS)
	echo ""
	echo "  ##---------------------------------------------------------##"
	echo "  ##                                                         ##"
	echo "  ##  Makefile: The library has been compiled with bonuses.  ##"
	echo "  ##                                                         ##"
	echo "  ##---------------------------------------------------------##"
	echo ""
.SILENT:
.PHONY: all clean fclean re bonus