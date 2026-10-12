#include "counter.h"

using namespace std;

// initialize map
// "slide window" through text and increment map for each window
Counter::Counter(const string& text, int n) {
  for (int i=0; i+n <= text.size(); i++)
    m[text.substr(i,n)]++;
}

// get list of segments
vector<string> Counter::pieces() {
  vector<string> v;
  for (auto& [p,n] : m)
    v.push_back(p);
  return v;
}

// get list of counts for each individual segment
vector<int> Counter::counts() {
  vector<int> v;
  for (auto& [p,n] : m)
    v.push_back(n);
  return v;
}

// get specific count
int Counter::count(const string& piece) { return m[piece]; }

// get specific piece
string Counter::piece(int count) { return m[count]; }
