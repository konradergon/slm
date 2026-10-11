// Counter: map counts for n-length sequences in text

#pragma once
#include <map>
#include <string>

struct Counter {
public:
  Counter(const std::string&, int);

private:
  std::map<std::string, int> counts;
};
