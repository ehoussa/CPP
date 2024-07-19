SRC			= main.cpp
NAME		= brain
OBJ			= $(SRC:.cpp=.o)
C			= c++
CPPFLAGS	= -std=c++98 -Wall -Werror -Wextra

$(NAME) : $(OBJ)
	@$(C) $(CPPFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all