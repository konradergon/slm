CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

slm: src/main.o src/counter.o src/idiot.o
	$(CXX) $(CXXFLAGS) -o slm src/main.o src/counter.o src/idiot.o

src/main.o: src/main.cpp src/counter.h src/idiot.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $@

src/counter.o: src/counter.cpp src/counter.h
	$(CXX) $(CXXFLAGS) -c src/counter.cpp -o $@

src/idiot.o: src/idiot.cpp src/idiot.h src/counter.h
	$(CXX) $(CXXFLAGS) -c src/idiot.cpp -o $@

clean:
	rm -f src/*.o slm
