#include <cassert>
#include <iostream>
#include "random.h"

using namespace std;
using namespace coen79_lab2;

namespace coen79_lab2{
  int rand_gen::next() {
    double n = (multiplier * seed + increment) % modulus;
    seed = n;
    return n;
  }

  void rand_gen::set_seed(int n) {
    seed = n;
    return;
  }
}
