NAME = Interfaces

CXX  = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98  #-g -fsanitize=address

RM = rm -rf

SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp ICharacter.cpp \
	  IMateriaSource.cpp MateriaSource.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all

.SECONDARY: