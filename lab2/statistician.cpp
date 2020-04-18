#include <cassert>
#include <iostream>
#include "statistician.h"

using namespace std;
using namespace coen79_lab2;

namespace coen79_lab2{
  void statistician::next(double m){
    if(len == '\0'){
      len = 0;
    }
    len++;
    if(total == '\0'){
      total = 0;
    }
    total += m;
    if(largest == '\0'){
      largest = m;
    } else if (m > largest){
      largest = m;
    }
    if(smallest == '\0'){
      smallest = m;
    } else if (m < smallest){
      smallest = m;
    }
  }

  int statistician::length() const{
    if(len == '\0'){
      return 0;
    }
    return len;
  }

  double statistician::sum() const{
    if(total == '\0'){
      return 0;
    }
    return total;
  }

  double statistician::mean() const{
    return (total / len);
  }

  double statistician::minimum() const{
    return smallest;
  }

  double statistician::maximum() const{
    return largest;
  }

  void statistician::reset(){
    len = '\0';
    total = '\0';
    largest = '\0';
    smallest = '\0';
  }

  statistician operator +(const statistician& s1, const statistician& s2){
    statistician s;
    s.len = s1.len + s2.len;
    s.total = s1.total + s2.total;
    if(s1.largest >= s2.largest){
      s.largest = s1.largest;
    } else {
      s.largest = s2.largest;
    }
    if(s1.smallest <= s2.smallest){
      s.smallest = s1.smallest;
    } else {
      s.smallest = s2.smallest;
    }
    return s;
  }

  statistician operator *(double scale, const statistician& s){
    statistician c;
    c.len = s.len;
    c.total = s.total * scale;
    c.largest = s.largest * scale;
    c.smallest = s.smallest * scale;
    return c;
  }

  bool operator ==(const statistician& s1, const statistician& s2){
    return (s1.length()==s2.length() &&  //compare all attributes to ensure equal
            s1.mean()==s2.mean() &&
            s1.sum()==s2.sum() &&
            s1.maximum()==s2.maximum() &&
            s1.minimum()==s2.minimum());
  }
}

void printStatisticianInfo(statistician & s) {
    cout << "Sum: " << s.sum() << endl;
    cout << "Mean: " << s.mean() << endl;
    cout << "Smallest: " << s.minimum() << endl;
    cout << "Largest: " << s.maximum() << endl;
}

int main() {
  statistician s1, s2;
  s1.next(1.1);
  s1.next(-2.4);
  s1.next(0.8);
  s2 = s1;
  cout << "S1:" << endl;
  printStatisticianInfo(s1);
  cout << "S2:" << endl;
  printStatisticianInfo(s2);
  s1 = 2.0 * s1;
  cout << "2.0 * S1:" << endl;
  printStatisticianInfo(s1);
  s1 = s1 + s2;
  cout << "S1 + S2:" << endl;
  printStatisticianInfo(s1);
  if(s1==s2){
    cout << "S1 == S2" << endl;
  }
  s1.reset();
  cout << "S1 reset:" << endl;
  printStatisticianInfo(s1);
  s1 = s2;
  if(s1==s2){
    cout << "S1 == S2" << endl;
  }
  cout << "S2:" << endl;
  printStatisticianInfo(s2);
  return 0;
}
