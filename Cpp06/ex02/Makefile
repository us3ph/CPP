NAME = Identify

CXX  = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = Base.cpp main.cpp

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

push: 
	$(RM) $(NAME)
	git add .
	git commit -m "done"
	git push

.PHONY: clean fclean re all

.SECONDARY: