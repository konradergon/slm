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

#include "idiot.h"

#include <fstream>
#include <iostream>
#include <random>
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
  string text = readf(argv[1]);      // read in file text
  Idiot idt(text,2);             // initialize idiot; populate map/map1
  std::mt19937 r(random_device{}()); // seed for idiot
  cout << idt.gen(5,0.1,r) << '\n';      // print generated text
}
