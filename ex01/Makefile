CC = c++ -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp RPN.cpp
NAME = RPN

all: $(NAME)

$(NAME):
	$(CC) -g $(CFILES) RPN.hpp -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean flcean re