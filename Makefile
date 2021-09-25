CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall  # flags for the compiler (use c++17 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

# runs for "make all"
main: TicTacToe.cpp

# note that lines below targets must be
# TABBED in (not spaces!)
clean:
	rm main

main: TicTacToe.cpp
	$(CXX) $(CXXFLAGS) TicTacToe.cpp -o main
