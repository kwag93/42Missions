CXX=clang++
CXXFLAGS=-Wall -Wextra -Werror -g
OBJECTS=./test/test_map.o main.o ./test/test_vector.o
NAME=test_all

.PHONY: run all clean fclean re

all: clean run

run: fclean $(NAME)
	./test_all

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
