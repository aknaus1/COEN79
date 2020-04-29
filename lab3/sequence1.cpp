#include <cassert>
#include <iostream>
#include<cmath>

#include "sequence1.h"

using namespace std;
using namespace coen79_lab3;

namespace coen79_lab3{
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
  // Poscondition: The iterator is reset to position 0
  void sequence::start( ){
    current_index = 0;
  }

  // Poscondition: The iterator points to the last item in the sequence
  void sequence::end( ){
    current_index = used - 1;
  }

  // Poscondition: The iterator is reset to CAPACITY - 1, regardless of
  // the numebr of items in the sequence
  void sequence::last( ){
    current_index = CAPACITY - 1;
  }

  // Precondtion: isitem() returns true
  // Postcondition: The iterator's value is increased by 1, unless it is
  // already at the end of the sequence
  void sequence::advance( ){
    assert(is_item());
    if(current_index < used){
      current_index++;
    }
  }

  // Postcondition: The iterator's value is reduced by 1,
  // unless it is already at the beginning of the sequence.
  void sequence::retreat( ){
    if(current_index > 0){
      current_index--;
    }
  }

  // Precondition: size() < CAPACITY
  // Postcondition: A new copy of entry has been inserted in the sequence
  // before the current item. If there was no current item, the new entry
  // has been inserted at the front. In either case, the new item is now the
  // current item of the sequence.
  void sequence::insert(const value_type& entry){
    assert(size() < CAPACITY);
    if(used == 0){
      current_index = 0;
      data[current_index] = entry;
    } else if(!is_item()){
      data[used] = entry;
      current_index = used;
    } else{
      int i;
      for(i = used; i > current_index; i--){
        data[i] = data[i-1];
      }
      data[current_index] = entry;
    }
    used++;
  }

  // Precondition: size() < CAPACITY
  // Postcondition: A new copy of entry has been inserted in the sequence
  // after the current item. If there was no current item, the new entry
  // has been attached to the end. In either case, the new item is now the
  // current item of the sequence.
  void sequence::attach(const value_type& entry){
    assert(size() < CAPACITY);
    current_index++;
    insert(entry);
  }

  // Precondtion: isitem() returns true
  // Postcondition: The current item has been removed from the sequence,
  // and the item after this (if there is one) is now the current item.
  void sequence::remove_current(){
    assert(is_item());
    int i;
    for(i = current_index; i < used - 1; i++){
      data[i] = data[i+1];
    }
    used--;
  }

  // Precondition: size() < CAPACITY
  // Postcondition: A new copy of entry has been inserted in the sequence
  // at the front. The new item is now the current item of the sequence.
  void sequence::insert_front(const value_type& entry){
    assert(size() < CAPACITY);
    current_index = 0;
    insert(entry);
  }

  // Precondition: size() < CAPACITY
  // Postcondition: A new copy of entry has been inserted in the sequence
  // at the back. The new item is now the current item of the sequence.
  void sequence::attach_back(const value_type& entry){
    assert(size() < CAPACITY);
    current_index = used;
    data[current_index] = entry;
    used++;
  }

  // Precondtion: isitem() returns true
  // Postcondition: The item at the front of the sequence has been removed
  // from the sequence, and the current item points at the front of the sequence.
  void sequence::remove_front(){
    assert(is_item());
    current_index = 0;
    remove_current();
  }


// CONSTANT MEMBER FUNCTIONS for the sequence class:
  // Postcondition: The return value is the number of items in the ssequence.
  sequence::size_type sequence::size() const{
    return used;
  }

  // Postcondition: A true return value indicates that there is a valid
  // "current" item that may be retrieved by activating the current
  // member function (listed below). A false return value indicates that
  // there is no valid current item.
  bool sequence::is_item( ) const{
    if(current_index < used){
      return true;
    } else {
      return false;
    }
  }

  // Precondtion: isitem() returns true
  // Poscondition: Returns the item in the sequence at the current
  // position of the iterator.
  sequence::value_type sequence::current() const{
    assert(is_item());
    return data[current_index];
  }

  // Precondition: index < used
  // Postcondition: The item returned is the item stored at "index"
  sequence::value_type sequence::operator[](int index) const{
    assert(index < used);
    return data[index];
  }

  // Postcondition: The value returned is the mean of the values stored in
  // the sequence.
  double sequence::mean() const{
    int i;
    double sum = 0.0;
    for(i = 0; i < used; i++){
      sum += data[i];
    }
    return (sum / used);
  }

  // Postcondition: The value returned is the stadard deviation of the
  // values stored in the sequence.
  double sequence::standardDeviation() const{
    int i;
    double temp, std = 0.0, avg = mean();
    for(i = 0; i < used; i++){
      temp = data[i] - avg;
      std += pow(temp,2);
    }
    return sqrt(std / used);
  }


// NON-MEMBER functions for the statistician class:
  // Postcondition: Adds the items of rhs to the lhs. Also returns a copy of lhs.
  sequence operator +=(const sequence& lhs, const sequence& rhs){
    assert((lhs.size() + rhs.size()) <= sequence::CAPACITY);
    sequence s;
    int i;
    for(i = 0; i < lhs.size(); i++){
      s.insert(lhs[i]);
    }
    for(i = 0; i < rhs.size(); i++){
      s.insert(rhs[i]);
    }
    return s;
  }

  // Postcondition: The sequence that is returned contains all the
  // numbers of the sequences of lsh and rhs.
  sequence operator +(const sequence& lhs, const sequence& rhs){
    assert(lhs.size()+ rhs.size() <= sequence::CAPACITY);
    sequence s;
    s += lhs;
    s += rhs;
    return s;
  }

  // Postcondition: The value returned is the summation of the values
  // stored in the sequence s.
  sequence::value_type summation(const sequence &s){
    int i;
    double sum = 0;
    for(i = 0; i < s.size(); i++){
      sum += s[i];
    }
    return sum;
  }
}
