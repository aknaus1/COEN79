#ifndef COEN79_SEQUENCE1_H
#define COEN79_SEQUENCE1_H

#include <iostream>

namespace coen79_lab3 {
  class sequence {
    public:
// TYPEDEF and MEMBER CONSTANTS
      typedef double value_type;
      typedef std::size_t size_type;
      static const size_type CAPACITY = 30;


// CONSTRUCTOR for the sequence class:
      //Postcondition: The sequence has been initialized as an empty sequence.
      sequence() {
        used = 0;
        current_index = 0;
      }


// MODIFICATION MEMBER FUNCTIONS for the sequence class:
      // Poscondition: The iterator is reset to position 0
      void start( );

      // Poscondition: The iterator points to the last item in the sequence
      void end( );

      // Poscondition: The iterator is reset to CAPACITY - 1, regardless of the numebr of items in the sequence;
      void last();

      // Precondtion: isitem() returns true
      // Postcondition: The iterator's value is increased by 1, unless it is alreadyat the end of the sequence
      void advance( );

      // Postcondition: The iterator's value is reduced by 1, unless it is already at the beginning of the sequence.
      void retreat();

      // Precondition: size() < CAPACITY
      // Postcondition: A new copy of entry has been inserted in the sequence
      // before the current item. If there was no current item, the new entry
      // has been inserted at the front. In either case, the new item is now the
      // current item of the sequence.
      void insert(const value_type& entry);

      // Precondition: size() < CAPACITY
      // Postcondition: A new copy of entry has been inserted in the sequence
      // after the current item. If there was no current item, the new entry
      // has been attached to the end. In either case, the new item is now the
      // current item of the sequence.
      void attach(const value_type& entry);

      // Precondtion: isitem() returns true
      // Postcondition: The current item has been removed from the sequence,
      // and the item after this (if there is one) is now the current item.
      void remove_current();

      // Precondition: size() < CAPACITY
      // Postcondition: A new copy of entry has been inserted in the sequence
      // at the front. The new item is now the current item of the sequence.
      void insert_front(const value_type& entry);

      // Precondition: size() < CAPACITY
      // Postcondition: A new copy of entry has been inserted in the sequence
      // at the back. The new item is now the current item of the sequence.
      void attach_back(const value_type& entry);

      // Precondtion: isitem() returns true
      // Postcondition: The item at the front of the sequence has been removed from the sequence,
      // and the current item points at the front of the sequence.
      void remove_front();


// CONSTANT MEMBER FUNCTIONS for the sequence class:
      // Postcondition: The return value is the number of items in the ssequence.
      size_type size() const;

      // Postcondition: A true return value indicates that there is a valid
      // "current" item that may be retrieved by activating the current
      // member function (listed below). A false return value indicates that
      // there is no valid current item.
      bool is_item( ) const;

      // Precondtion: isitem() returns true
      // Poscondition: Returns the item in the sequence at the current position of the iterator.
      value_type current() const;

      // Precondition: index < used
      // Postcondition: The item returned is the item stored at "index"
      value_type operator[](int index) const;

      // Postcondition: The value returned is the mean of the values stored in the sequence.
      double mean() const;

      // Postcondition: The value returned is the stadard deviation of the values stored in the sequence.
      double standardDeviation() const;

    private:
      value_type data[CAPACITY];
      size_type used;
      size_type current_index;
  };

// NON-MEMBER functions for the statistician class:
  // Postcondition: Adds the items of rhs to the lhs. Also returns a copy of lhs.
  sequence operator +=(const sequence& lhs, const sequence& rhs);

  // Postcondition: The sequence that is returned contains all the
  // numbers of the sequences of lsh and rhs.
  sequence operator +(const sequence& lhs, const sequence& rhs);

  // Postcondition: The value returned is the summation of the values stored in the sequence s.
  sequence::value_type summation(const sequence &s);
}

#endif
