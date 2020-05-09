#include <iostream>
#include <cassert>
#include <cstring>

#include "mystring.h"

using namespace std;
using namespace coen79_lab5;

namespace coen79_lab5 {
  string::string(const char str[ ]) {
    current_length = strlen(str);
    allocated = current_length + 1;
    characters = new char[allocated];
    strncpy(characters, str, allocated);
  }
  //Precondition: str is an ordinary null-terminated string.
  //Postcondition: The string contains the sequence of chars from str.

  string::string(char c) {
    current_length = 1;
    allocated = current_length + 1;
    characters = new char[allocated];
    characters[0] = c;
    characters[1] = '\0';
  }
  //Postcondition: The string contains c and then the null character.

  string::string(const string& source) {
    characters = new char[source.length()];
    strncpy(characters, source.characters, source.length());
    current_length = source.length();
    allocated = current_length + 1;
  }
  //Postcondition: The string becomes a copy of the source string.

  string::~string( ) {
    delete [] characters;
    current_length = 0;
    allocated = 0;
  }

  // MODIFICATION MEMBER FUNCTIONS
  void string::operator +=(const string& addend) {
    size_t add = addend.length();
    size_t final = current_length + add;
    allocated = final + 1;
    reserve(allocated);
    strncat(characters, addend.characters, add);
    current_length = final;
  }
  //Postcondition: addend has been catenated to the end of the string.

  void string::operator +=(const char addend[ ]) {
    size_t add = strlen(addend);
    size_t final = current_length + add;
    allocated = final + 1;
    reserve(allocated);
    strncat(characters, addend, add);
    current_length = final;
  }
  //Precondition: addend is an ordinary null-terminated string.
  //Postcondition: addend has been catenated to the end of the string.

  void string::operator +=(char addend) {
    size_t final = current_length + 1;
    allocated = final + 1;
    reserve(allocated);
    characters[current_length] = addend;
    current_length = final;
  }
  //Postcondition: The single character addend has been catenated to the
  //     end of the string.

  void string::reserve(size_t n) {
    char* newchar = new char[n];
    if(characters != NULL) {
      strncpy(newchar, characters, current_length);
      delete []characters;
    }
    characters = newchar;
  }
  //Postcondition: All functions will now work efficiently (without
  //     allocating new memory) until n characters are in the string.

  string& string::operator =(const string& source) {
    this->dlt(0, current_length);
    if(current_length != source.length()){
      allocated = source.allocated;
      reserve(allocated);
    }
    strncpy(characters, source.characters, source.length());
    current_length = source.length();
    return *this;
  }

  void string::insert(const string& source, unsigned int position) {
    assert(position <= length());
    char* temp1 = new char[current_length + source.length() + 1];
    if(position > 0) {
      strncpy(temp1, characters, position);
    }
    char* temp2 = new char[allocated - position];
    for(int i = position, j = 0; i <= current_length; i++, j++) {
      temp2[j] = characters[i];
    }
    delete[] characters;
    strncat(temp1, source.characters, source.length());
    strncat(temp1, temp2, strlen(temp2));
    characters = temp1;
    current_length += source.length();
    allocated = current_length + 1;
  }
  //Precondtion: position <= length()
  //Postcondition: The source string is inserted into this string before
  //     the character at the given index.

  void string::dlt(unsigned int position, unsigned int num) {
    assert((position + num) <= length( ));
    for(int i = position; i < length(); i++) {
      characters[i] = characters[i + num];
    }
    current_length -= num;
  }
  //Precondition: (position + num) <= length( ).
  //Postcondition: num characters are deleted from the sequence, starting
  //     at index position.

  void string::replace(char c, unsigned int position) {
    assert(position < length());
    characters[position] = c;
  }
  //Precondition: position < length()
  //Postcondtion: the character at the given position in the string is
  //     replaced with c.

  void string::replace(const string& source, unsigned int position) {
    assert((position + source.length()) <= length());
    for(int i = position, j = 0; j < source.length(); i++, j++) {
      characters[i] = source[j];
    }
  }
  //Precondition: (position + source.length()) <= length()
  //Postcondtion: the characters in this string starting at position are
  //     replaced with those in the source srting.

  // CONSTANT MEMBER FUNCTIONS
  char string::operator [ ](size_t position) const {
    assert(position < length());
    return characters[position];
  }
  //Precondition: position < length( ).
  //Postcondition: The value returned is the character at the specified
  //     position of the string. A string's positions start from 0 at the start
  //     of the sequence and go up to length( )-1 at the right end.

  int string::search(char c) const {
    for(int i = 0; i < length(); i++) {
      if(characters[i] == c) {
        return i;
      }
    }
    return -1;
  }
  //Postcondition: The location of the first occurence of the character c
  //     within this string is returned. If the string does not contain c, -1 is
  //     is returned.

  int string::search(const string& substring) const {
    char* temp = strstr(characters, substring.characters);
    if(temp != NULL){
      return *temp - *characters;
    }
    return -1;
  }
  //Postcondition: Returns the index of the start of the first instance of
  //     the given substring inside of this string. If the substring is not found,
  //     this function returns -1.

  unsigned int string::count(char c) const {
    int count = 0;
    for(int i = 0; i < length(); i++) {
      if(characters[i] == c) {
        count++;
      }
    }
    return count;
  }
  //Postcondition: The count of the occurence of the character c within this
  //     string is returned.

  // FUNCTIONS
  std::ostream& operator <<(std::ostream& outs, const string& source) {
    outs << source.characters;
    return outs;
  }
  //Postcondition: The sequence of characters in source has been written
  //     to outs. The return value is the ostream outs.

  bool operator ==(const string& s1, const string& s2) {
    return (strcmp(s1.characters, s2.characters) == 0);
  }
  bool operator !=(const string& s1, const string& s2) {
    return (strcmp(s1.characters, s2.characters) != 0);
  }
  bool operator > (const string& s1, const string& s2) {
    return (strcmp(s1.characters, s2.characters) > 0);
  }
  bool operator < (const string& s1, const string& s2) {
    return (strcmp(s1.characters, s2.characters) < 0);
  }
  bool operator >=(const string& s1, const string& s2) {
    return ((s1 > s2) || (s1 == s2));
  }
  bool operator <=(const string& s1, const string& s2) {
    return ((s1 < s2) || (s1 == s2));
  }

  // NON-MEMBER FUNCTIONS for the string class
  string operator +(const string& s1, const string& s2) {
    string s;
    s += s1;
    s += s2;
    return s;
  }
  //Postcondition: The string returned is the catenation of s1 and s2.

  string operator +(const string& s1, const char addend[ ]) {
    string s;
    s += s1;
    s += addend;
    return s;
  }

  std::istream& operator >> (std::istream& ins, string& target) {
    while(ins && isspace(ins.peek())) {
      ins.ignore();
    }
    char temp;
    target = "";
    while (ins && !isspace(ins.peek())) {
      ins >> temp;
      target += temp;
    }
    return ins;
  }
  //Postcondition: A string has been read from the istream ins, and the
  //     istream ins is then returned by the function. The reading operation
  //     skips white space (i.e., blanks, newlines, tabs) at the start of ins.
  //     Then the string is read up to the next white space or the end of the
  //     file. The white space character that terminates the string has not
  //     been read.
}
