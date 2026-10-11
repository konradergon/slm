CXX = g++
CXXFLAGS = -Wall -std=c++17 -O3

test: src/main.o src/counter.o
	$(CXX) $(CXXFLAGS) -o test src/main.o src/counter.o

main.o: src/main.cpp src/counter.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp

counter.o: src/counter.cpp src/counter.h
	$(CXX) $(CXXFLAGS) -c src/counter.cpp

clean:
	rm -f *.o test
