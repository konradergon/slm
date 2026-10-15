// slm - small language model

#include "idiot.h"

#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

constexpr char usage[] = "usage: slm [-a alpha] k file length";

template<typename T>
bool read(const string& arg, T& val) {
  istringstream is(arg);
  return is >> val && is.eof(); // anything left after read?
}
 
string readf(const string& name) {
  ifstream f(name);
  if (!f)
    throw runtime_error("cannot open file '"+name+"'");
  stringstream ss;
  ss << f.rdbuf();
  return ss.str();
}

int main(int argc, char* argv[]) try {
  vector<string> args(argv+1, argv+argc); // read in arguments
  
  double alpha {};
  if (!args.empty() && args[0] == "-a") {
    if (args.size()<2 || !read(args[1], alpha) || alpha<0) // bad or no alpha
      throw runtime_error("-a must be followed by a non-negative number");
    args.erase(args.begin(), args.begin()+2);
  }

  if (args.size() != 3)
    throw runtime_error(usage);
  if (args[0][0] == '-')
    throw runtime_error("unknown option");

  long k {};
  long len {};

  if (!read(args[0], k))
    throw runtime_error("k must be a positive integer");
  if (!read(args[2], len) || len<1)
    throw runtime_error("length must be a positive integer");
  if (len<k)
    throw runtime_error("length must be at least k");

  Idiot idt(readf(args[1]), k);
  mt19937 r(random_device{}());
  cout << idt.gen(len, alpha, r) << '\n';
 }
 catch (const exception& e) {
   cerr << "slm: " << e.what() << '\n';
   return 1;
 }
