#include "counter.h"

using namespace std;

// initialize map
// "slide window" through text and increment map for each window
Counter::Counter(const string& text, size_t n) {
  for (size_t i=0; i+n <= text.size(); i++)
    m[text.substr(i,n)]++;
}

// get list of segments
vector<string> Counter::pieces() const {
  vector<string> v;
  for (auto& p : m)
    v.push_back(p.first);
  return v;
}

// get list of counts for each individual segment
vector<double> Counter::counts() const {
  vector<double> v;
  for (auto& p : m)
    v.push_back(p.second);
  return v;
}

// get specific count
// m[piece] for non-occurring piece creates {piece,0} pair
// this makes counts() & pieces() inaccurate
//
// therefore we use m.find()
double Counter::count(const string& piece) const {
  auto it = m.find(piece);               // iterator for pair
  return it == m.end() ? 0 : it->second; // second is count in pair
}
