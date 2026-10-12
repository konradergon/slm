#include "idiot.h"

using namespace std;

Idiot::Idiot(const string& text, int k)
  : k(k), kgrams(text,k), next(text,k+1), alphabet(Counter(text,1).pieces()) {}

// pick any kgram, likely the most frequent
string pick(const vector<string>& pieces, const vector<int> counts, mt19937& r) {
  discrete_distribution<int> d(counts.begin(),counts.end()); // generate die based on count distribution
  return pieces[d(r)]; // r throws the die
}

// generate text
string Idiot::gen(int len, mt19937& r) const {
  string out = pick(kgrams.pieces(), kgrams.counts(), r); // we start with some kgram
  while (out.size() < len) {
    string w = out.substr(out.size()-k); // last k chars written
    vector<int> v;                       // counts for all w+c sequences
    for (const string& c : alphabet)
      v.push_back(next.count(w+c));
    out += pick(alphabet, v, r);         // pick next char
  }
  return out;
}
