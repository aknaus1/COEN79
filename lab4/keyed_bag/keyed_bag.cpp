#include <cassert>
#include <iostream>

#include "keyed_bag.h"

using namespace std;

namespace coen79_lab4 {
  // MODIFICATION MEMBER FUNCTIkONS for the keyed_bag class:
    void keyed_bag::erase() {
      for(int i = 0; i < used; i++) {
        keys[i] = '\0';
        data[i] = '\0';
      }
      used = 0;
    }
  //     Postcondition: This keyed_bag is emptied of all items and keys.

    bool keyed_bag::erase(const key_type& key) {
      for(int i = 0; i < used; i++) {
        if(keys[i] == key) {
          for(int j = i; j < used - 1; j++) {
            keys[j] = keys[j+1];
            data[j] = data[j+1];
          }
          used--;
          return true;
        }
      }
      return false;
    }
  //     Postcondition: If key was in the keyed_bag, then the key and its value have been removed;
  //     otherwise the keyed_bag is unchanged. A true return value indicates that an
  //     item was removed; false indicates that nothing was removed.

    void keyed_bag::insert(const value_type& entry, const key_type& key) {
      assert(size() < CAPACITY && !has_key(key));
      keys[used] = key;
      data[used] = entry;
      used++;
    }
  //     Precondition:  size( ) < CAPACITY, and the keyed_bag does not yet contain
  //     the given key.
  //     Postcondition: A new copy of entry has been added to the keyed_bag with
  //     the corresponding key.

    void keyed_bag::operator +=(const keyed_bag& addend) {
      assert(size() + addend.size() <= CAPACITY && !hasDuplicateKey(addend));
      for(int i = 0; i < addend.size(); i++) {
        keys[used] = addend.keys[i];
        data[used] = addend.data[i];
        used++;
      }
    }
  //     Precondition:  size( ) + addend.size( ) <= CAPACITY.
  //     The intersection of the keyed_bags' key tables is empty (i.e. the keyed_bags)
  //     share no keys.
  //     Postcondition: Each item and its key in addend has been added to this keyed_bag.


  // CONSTANT MEMBER FUNCTIONS for the keyed_bag class:
    bool keyed_bag::has_key(const key_type& key) const {
      for(int i = 0; i < used; i++) {
        if(keys[i] == key) {
          return true;
        }
      }
      return false;
    }
  //     Postcondition: The return value is whether or not the given key is in
  //     the keyed_bag's list of keys.

    keyed_bag::value_type keyed_bag::get(const key_type& key) const {
      assert(has_key(key));
      for(int i = 0; i < used; i++){
        if(keys[i] == key) {
          return data[i];
        }
      }
      return '\0';
    }
  //     Precondition: has_key returns true for the given key.
  //     Postcondtion: the data value corresponding to the given key is returned.

    keyed_bag::size_type keyed_bag::size( ) const {
      return used;
    }
  //     Postcondition: The return value is the total number of items in the keyed_bag.

    keyed_bag::size_type keyed_bag::count(const value_type& target) const {
      int count = 0;
      for(int i = 0; i < used; i++) {
        if(data[i] == target) {
          count++;
        }
      }
      return count;
    }
  //     Postcondition: The return value is number of times target is in the keyed_bag.

    bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const {
      for(int i = 0; i < used; i++) {
        if(otherBag.has_key(keys[i])) {
          return true;
        }
      }
      return false;
    }
  //     Postcondition: The return value is true if there is at least one key used by
  //                    both this bag and the "otherBag". In other words, this function
  //                    checks if there is any shared key by the two bags.


  // NONMEMBER FUNCTIONS for the keyed_bag class:
  keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2) {
    assert(b1.size() + b2.size() <= keyed_bag::CAPACITY && !b1.hasDuplicateKey(b2));
    keyed_bag result;
    result += b1;
    result += b2;
    return result;
  }
  //     Precondition:  b1.size( ) + b2.size( ) <= keyed_bag::CAPACITY.
  //                    The intersection of the keyed_bags' key tables is empty.
  //                    (i.e. The two keyed_bag's have no keys in common.)
  //     Postcondition: The keyed_bag returned is the union of b1 and b2.
}
