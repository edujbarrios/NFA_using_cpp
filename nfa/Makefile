.default: all

all: nfa_simulation

clean:
	rm -f nfa_simulation *.o

nfa_simulation: automaton.o main.o NFA.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^
	
%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
