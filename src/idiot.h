// artificial idiot:
//
// generate text from kgram distribution
// based on two maps; one for choosing initial w
// and the other for subsequent letters.

#pragma once
#include "counter.h"

class Idiot {
public:
  Idiot(const std::string& text, int k);

private:
  int k;
  Counter kgrams; // kgrams
  Counter next;   // (k+1)grams
};

