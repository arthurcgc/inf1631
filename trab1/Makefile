build-all:
	g++ -g -o bin/e1 src/e1.cpp
	g++ -g -o bin/e2 src/e2.cpp src/e2_parser.cpp -lm -std=c++11

build-e1:
	g++ -g -o bin/e1 src/e1.cpp
e1: clean build-e1
	./bin/e1

build-e2:
	g++ -g -o bin/e2 src/e2.cpp src/e2_parser.cpp -lm -std=c++11

e2: clean build-e2
	./bin/e2

all: e1 e2

clean:
	rm -rf bin/*
	rm -rf e2_results/*
