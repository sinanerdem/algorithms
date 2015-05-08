/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: str.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has str class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef str_H
#define str_H

#include "../darray/darray.h"

/*----------------------------------------------------------------
Declaration of str class
-----------------------------------------------------------------*/
class str {
public:
  str(const char* s, bool d = false);
  str(const char ch = ' ', bool d = false);
  ~str();
  str(const str& s);
  str& operator=(const str& rhs);
  friend bool operator==(const str& s1, const str& s2);
  friend bool operator!=(const str& s1, const str& s2);
  friend int string_compare(const str& s1, const str& s2);
  friend ostream& operator<<(ostream& o, const str& s);
  int strlen() const;
  void reverse();
  friend  str operator+(const str& s1, const str& s2);
  char& operator[](int i); //For non constant object
  const char& operator[](int i) const; //for constant objects
  bool display() const { return _display; }
  void set_display(bool x) {
    _str.set_display(x);
    _display = x;
  }
private:
  darray<char> _str;
  bool _display;
};

#endif
//EOF

