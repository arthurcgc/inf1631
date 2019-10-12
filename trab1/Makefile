build-all:
	g++ -g -o bin/e1 src/e1.cpp
	g++ -g -o bin/e2 src/e2.cpp src/e2_parser.cpp -lm -std=c++11

build-e1:
	g++ -g -o bin/e1 src/e1.cpp

build-e2:
	g++ -g -o bin/e2 src/e2.cpp src/e2_parser.cpp -lm -std=c++11

build-e3:
	g++ -g -o bin/e3 src/e3_arthurcgc.cpp src/e3_parser.cpp

e1: clean build-e1
	./bin/e1

e2: clean build-e2
	rm -rf e2_results/*
	./bin/e2

e3: clean build-e3
	rm -rf e3_results/*
	./bin/e3

all: e1 e2

clean:
	rm -rf bin/*
