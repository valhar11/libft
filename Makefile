NAME = libft.a

SRC = ft_bzero.c		\
      ft_isdigit.c		\
      ft_memcpy.c		\
      ft_strlcpy.c		\
      ft_strrchr.c		\
      ft_isalnum.c		\
      ft_isprint.c		\
      ft_memmove.c		\
      ft_strlen.c		\
      ft_tolower.c		\
      ft_isalpha.c		\
      ft_memchr.c		\
      ft_strchr.c		\
      ft_strrchr.c		\
      ft_strncmp.c		\
      ft_toupper.c		\
      ft_isascii.c		\
      ft_memcmp.c		\
      ft_strlcat.c		\
      ft_strnstr.c		\
      ft_memset.c		\
      ft_strlcpy.c		\
      ft_calloc.c		\
      ft_strdup.c	 	\
      ft_strtrim.c		\
      ft_strlcpy.c		\
      ft_strchr.c		\
      ft_strnstr.c		\
      ft_substr.c 		\
      ft_strjoin.c		\
      ft_strtrim.c		\
      ft_split.c        \
      ft_itoa.c			\
      ft_strmapi.c		\
      ft_striteri.c		\
      ft_putchar_fd.c	\
      ft_putstr_fd.c	\
      ft_putendl_fd.c	\
      ft_atoi.c         \
      ft_putnbr_fd.c

BONUS_SRC =  ft_lstnew.c		\
             ft_lstadd_front.c	\
             ft_lstlast.c		\
             ft_lstadd_back.c	\
		 	 ft_lstsize.c		\
             ft_lstdelone.c		\
             ft_lstclear.c		\
             ft_lstiter.c		\
             ft_lstmap.c

SRC_GNL = get_next_line.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
GNL_OBJ = $(SRC_GNL:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(BONUS_OBJ) $(GNL_OBJ)
	ar rc $(NAME) $(OBJ) $(BONUS_OBJ) $(GNL_OBJ)
	ranlib $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ) $(GNL_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
