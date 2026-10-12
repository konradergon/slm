// program flow:
//
// (1) count
// (2) model
// (3) print
//
// for each pos in text:
//   map[text.substr(i,k)]++
//   map1[text.substr(1,k+1)]++ // should serve for each 'w' during gen
//
// pick initial w from map
// pick c from map1
// remove first, append c
// repeat
//
// print
//
// use class Counter & class Idiot

#include "counter.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string readf(const string& name) {
  ifstream f(name);
  stringstream ss;
  ss << f.rdbuf();
  return ss.str();
}

int main(int argc, char* argv[]) {
  Counter c(readf(argv[1]), 2);
  for (string p : c.pieces())
    cout << p << '\n';
  for (int c : c.counts())
    cout << c << '\n';
}
