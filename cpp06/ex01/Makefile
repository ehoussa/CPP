SRCS		= main.cpp Serializer.cpp
NAME		= cast
OBJ			= $(SRCS:.cpp=.o)
CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra

$(NAME) : $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
