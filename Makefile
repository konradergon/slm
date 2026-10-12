CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

slm: src/main.o src/counter.o src/idiot.o
	$(CXX) $(CXXFLAGS) -o slm src/main.o src/counter.o src/idiot.o

main.o: src/main.cpp src/counter.h src/idiot.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp

counter.o: src/counter.cpp src/counter.h
	$(CXX) $(CXXFLAGS) -c src/counter.cpp

idiot.o: src/idiot.cpp src/idiot.h
	$(CXX) $(CXXFLAGS) -c src/idiot.cpp

clean:
	rm -f *.o slm
