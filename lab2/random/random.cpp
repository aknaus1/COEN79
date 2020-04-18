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

int main() {
  int n, s, mult, inc, mod;
  cout << "Seed: ";
  cin >> s;
  cout << "Multiplier: ";
  cin >> mult;
  cout << "Increment: ";
  cin >> inc;
  cout << "Modulus: ";
  cin >> mod;
  rand_gen g = rand_gen(s, mult, inc, mod);
  n = g.next();
  cout << n << endl;
  n = g.next();
  cout << n << endl;
  n = g.next();
  cout << n << endl;
  g.set_seed(1);
  n = g.next();
  cout << n << endl;
  n = g.next();
  cout << n << endl;
  n = g.next();
  cout << n << endl;

}
