NAME = Forms

CXX  = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

RM = rm -rf

SRC = Bureaucrat.cpp Form.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)
	
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all

.SECONDARY: