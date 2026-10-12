// artificial idiot:
//
// generate text from kgram distribution
// based on two maps; one for choosing initial w
// and the other for subsequent letters.

#pragma once
#include "counter.h"
#include <numeric>
#include <random>

class Idiot {
public:
  Idiot(const std::string& text, int k);
  std::string gen(int len, double alpha, std::mt19937& r) const;

private:
  int k;
  Counter kgrams; // kgrams
  Counter next;   // (k+1)grams
  std::vector<std::string> alphabet;
};

