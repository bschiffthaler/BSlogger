default: all

all:
	$(CXX) -Wall -Wextra -o bslogger-examples src/bslogger_examples.cpp

instrumented:
	$(CXX) -Wall -Wextra -fsanitize=address -fsanitize=undefined -o bslogger-examples src/bslogger_examples.cpp
