#include "counter.h"

using namespace std;

// initialize map
// "slide window" through text and increment map for each window
Counter::Counter(const string& text, int n) {
  for (int i=0; i+n <= text.size(); i++)
    counts[text.substr(i,n)]++;
}
