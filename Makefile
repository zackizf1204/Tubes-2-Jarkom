all: src/main.cpp
	g++ --std=c++11 -o main main.cpp
run:
	./main
