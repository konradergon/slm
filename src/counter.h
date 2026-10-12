// Counter: map counts for n-length pieces in text

#pragma once
#include <map>
#include <string>
#include <vector>

struct Counter {
public:
  Counter(const std::string&, int);
  std::vector<std::string> pieces();
  std::vector<int> counts();
  int count(const std::string&);

private:
  std::map<std::string, int> m;
};
