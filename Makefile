all:
	g++ -march=native -Wall -w -std=c++17 src/*.cc pitascript_main.cc -o pitascript
