NAME = bits

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

RM = rm -f

%.o: %.cpp
	$(CC) -c $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 