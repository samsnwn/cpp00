NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I Contact.hpp -I PhoneBook.hpp

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
