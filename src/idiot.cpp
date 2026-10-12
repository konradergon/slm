#include "idiot.h"

using namespace std;

Idiot::Idiot(const string& text, int k)
  : k(k), kgrams(text,k), next(text,k+1) {}
