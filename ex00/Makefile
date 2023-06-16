CC = c++ -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp BitcoinExchange.cpp
NAME = btc

all: $(NAME)

$(NAME):
	$(CC) -g $(CFILES) BitcoinExchange.hpp -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean flcean re