// Idiot:
//
// generate text from kgram distribution
// based on two maps; one for choosing initial w
// and the other for subsequent letters.

#pragma once
#include "counter.h"
#include <random>

class Idiot {
public:
  Idiot(const std::string&, std::size_t);
  std::string gen(std::size_t, double, std::mt19937&) const;

private:
  std::size_t k;
  Counter kgrams; // kgrams
  Counter next;   // (k+1)grams
  std::vector<std::string> alphabet;
};

