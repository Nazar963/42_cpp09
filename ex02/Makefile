CC = c++ -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp PmergeMe.cpp
NAME = PmergeMe

all: $(NAME)

$(NAME):
	$(CC) -g $(CFILES) PmergeMe.hpp -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean flcean re