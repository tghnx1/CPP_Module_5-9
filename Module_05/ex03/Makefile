NAME    = Fixed

SRC     = main.cpp \
		  Bureaucrat.cpp \
		  AForm.cpp \
		  ShrubberyCreationForm.cpp \
		  RobotomyRequestForm.cpp \
		  PresidentialPardonForm.cpp \
		  Intern.cpp

OBJ     = $(SRC:.cpp=.o)
CXX     = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Zombie.hpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
