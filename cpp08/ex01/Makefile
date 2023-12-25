SRCS		= main.cpp Span.cpp
NAME		= ex01
CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra

$(NAME) : $(SRCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean :
	@rm -f $(NAME)

re : fclean all

.PHONY: all fclean re
