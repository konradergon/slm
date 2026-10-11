#include "counter.h"

using namespace std;

// initialize map
// "slide window" through text and increment map for each window
Counter::Counter(const string& text, int n) {
  for (int i=0; i+n <= text.size(); i++)
    counts[text.substr(i,n)]++;
}

// get list of segments
vector<string> Counter::pieces() {
  vector<string> v;
  for (auto& [p,n] : counts)
    v.push_back(p);
  return v;
}

// get list of counts for each individual segment
vector<int> Counter::counts() {
  vector<int> v;
  for (auto& [p,n] : counts)
    v.push_back(n);
  return v;
}
