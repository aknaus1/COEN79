#ifndef RAND_H
#define RAND_H
#include <iostream>

namespace coen79_lab2 {
  class rand_gen {
    private:
      int seed;
      int multiplier;
      int increment;
      int modulus;
    public:
      rand_gen(int s, int mult, int inc, int mod){ //generate random number string
        seed = s;
        multiplier = mult;
        increment = inc;
        modulus = mod;
      }
      int next(); //output next number in random number sequence;
      void set_seed(int n); //set seed used in random number generator
  };
}

#endif
