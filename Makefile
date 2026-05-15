main: main.cpp
	g++ main.cpp -o stats -g -Wall -Werror -lncurses

clean:
	rm -rf stats
