#ifndef STATS_H
#define STATS_H
#include <iostream>

namespace coen79_lab2 {
  class statistician {
    private:
      int len; //length
      double total; //sum
      double largest; //max
      double smallest; //min

    public:
      //constructor from null
      statistician(){
        len = '\0';
        total = '\0';
        largest = '\0';
        smallest = '\0';
      }
      //constructor with known values
      statistician(int len_init, double total_init, double largest_init, double smallest_init){
        len = len_init;
        total = total_init;
        largest = largest_init;
        smallest = smallest_init;
      }
      void next(double n); //add a number to the sequence
      int length() const; //return the number of values in the sequence
      double sum() const; //return the sum of the numbers in the sequence
      double mean() const; //return the mean of the numbers in the sequence
      double minimum() const; //return the smallest number in the sequence
      double maximum() const; //return the largest number in the sequence
      void reset(); //erase the sequence
  };
  // Postcondition: The statistician that is returned contains all the
  // numbers of the sequences of s1 and s2.
  statistician operator +(const statistician& s1, const statistician& s2);
  // Postcondition: The statistician that is returned contains the same
  // numbers that s does, but each number has been multiplied by the
  // scale number.
  statistician operator *(double scale, const statistician& s);
  // Postcondition: The return value is true if s1 and s2 have the zero
  // length. Also, if the length is greater than zero, then s1 and s2 must
  // have the same length, the same mean, the same minimum,
  // the same maximum, and the same sum.
  bool operator ==(const statistician& s1, const statistician& s2);
}
#endif
