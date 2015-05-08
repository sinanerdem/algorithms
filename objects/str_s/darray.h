/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: darray.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has darray class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef darray_H
#define darray_H

#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of darray class
-----------------------------------------------------------------*/
template <typename T>
class darray {
public:
  darray(bool d = false, int size = 50);
  darray(int size, bool d) = delete; //Why?
  darray(int size) = delete; //Why?
  darray(const T f[], int size, bool d = false); //For constant object.
  darray(const T f[], bool d, int size) = delete; //Why ?
  ~darray();
  darray(const darray<T>& s);
  darray<T>& operator=(const darray<T>& rhs);
  T& operator[](int i); //For non constant objects
  const T& operator[](int i) const; //for constant objects
  bool display()const { return _display; }
  void set_display(bool x) {
    _display = x;
  }

private:
  T*  _element;
  bool _display;
  int _size;
  void _copy(const darray<T>& s);
  void _release(){ delete[] _element; }
  void _grow(int i);
};

#include "darray.hpp"

#endif
//EOF

