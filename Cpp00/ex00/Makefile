NAME = megaphone

CC  = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

RM = rm -rf


SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all

.SECONDARY:
