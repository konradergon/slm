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
  std::string piece(int);

private:
  std::map<std::string, int> m;
};
