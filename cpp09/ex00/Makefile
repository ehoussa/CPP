SRCS		= main.cpp BitcoinExchange.cpp
NAME		= btc
CXX			= c++ -fsanitize=address
CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra

$(NAME) : $(SRCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean :
	@rm -f $(NAME)

re : fclean all

.PHONY: all fclean re
