/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: dstack.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has dstack class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef dstack_H
#define dstack_H

#include "../util/util.h"
#include "../darray/darray.h"

/*----------------------------------------------------------------
Declaration of dstack class
-----------------------------------------------------------------*/
template <typename T>
class dstack {
public:
  dstack(bool d = false, int size = 50);
  dstack(int size, bool d) = delete;
  dstack(int size) = delete;
  ~dstack();
  int num_elements() const;
  bool isempty() const;
  bool isfull() const;
  void push(const T& b); // Stack copies b and holds. Now stack is the owner of b
  T& top(); // user can get top by alias. He can change its contents also. See explanation in implementation
  void pop(); // Remove top element from the stack. Nothing returned 

  void for_each_element_of_stack_from_top_to_bottom(void(*pf) (T& c));
  bool display()const { return _display; }
  void set_display(bool x) {
    darray<T>::set_display(x);
    _display = x;
  }
  T min();
  /* no body will copies or equal stack */
  dstack(const dstack<T>& s) = delete;
  dstack<T>& operator=(const dstack<T>& rhs) = delete;
private:
  bool _display;
  int _sp;
  darray<T> _stack;
  int _minp;
  darray<int> _minarr;
};

#include "dstack.hpp"

#endif
//EOF

