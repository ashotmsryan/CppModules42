NAME = easyfind

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

RM = rm -f

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

bonus: $(NAME)

re: fclean all

.PHONY: all clean fclean re
