NAME		= open
SRC			= main.cpp
C			= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror
OBJ			= $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
	@$(C) $(CPPFLAGS) $(OBJ) -o $(NAME);

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
