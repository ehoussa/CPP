SRCS		= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
NAME		= Bureaucrat
OBJ			= $(SRCS:.cpp=.o)
CXX			= g++ -g3
CXXFLAGS	= -fsanitize=address -std=c++98 -Wall -Werror -Wextra

$(NAME) : $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
