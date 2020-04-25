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
    int len;
    double total, largest, smallest;
    len = s1.length() + s2.length();
    total = s1.sum() + s2.sum();
    if(s1.maximum() >= s2.maximum()){
      largest = s1.maximum();
    } else {
      largest = s2.maximum();
    }
    if(s1.minimum() <= s2.minimum()){
      smallest = s1.minimum();
    } else {
      smallest = s2.minimum();
    }
    statistician s(len, total, largest, smallest);
    return s;
  }

  statistician operator *(double scale, const statistician& s){
    int len;
    double total, largest, smallest;
    len = s.length();
    total = s.sum() * scale;
    largest = s.maximum() * scale;
    smallest = s.minimum() * scale;
    statistician c(len, total, largest, smallest);
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
