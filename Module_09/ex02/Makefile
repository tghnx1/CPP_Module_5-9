NAME    = PmergeMe

SRC     = main.cpp \
		  PmergeMe.cpp

OBJ     = $(SRC:.cpp=.o)
CXX     = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp .hpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
