/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: recursion.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has recursion class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef recursion_H
#define recursion_H

#include "../util/util.h"
#include "../dstack/dstack.h"
#include "str.h"

/*----------------------------------------------------------------
Declaration of recursion class
-----------------------------------------------------------------*/
class recursion{
public:
  recursion(bool d = false) :_display(d){}
  bool display() const {
    return _display;
  }
  //ALL REQUIRED. WRITE CODE
  long long factorial_iterative(unsigned n, int& num_itr);
  long long factorial_recursion(unsigned n, int& num_rec);
  long long factorial_stack(unsigned n, int& size_of_stack);

  int num_binary_digit_iterative(unsigned n, int& num_itr);
  int num_binary_digit_recursion(unsigned n, int& num_rec);
  int num_binary_digit_stack(unsigned n, int& size_of_stack);

  int fibonacci_iterative(unsigned n, int& num_mult);
  int fibonacci_recursion(unsigned n, int& num_rec);
  int fibonacci_stack(unsigned n, int& size_of_stack);

  void hanoi_iterative(unsigned n, int& num_itr);
  void hanoi_recursion(unsigned n, int& num_rec, str& s);
  void hanoi_stack(unsigned n, int& size_of_stack, str& str);

private:
  //WHATEVER PRIVATE U NEED
  bool _display;
  class peg;

  void _t_r(unsigned n, char s, char t, char d, int& num_rec, str& str);
  void hanoi_stack_r(unsigned n, peg& s, peg& t, peg& d, str& str);
};

#endif
//EOF

