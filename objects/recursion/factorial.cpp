/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: factorial.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "recursion.h"

/*----------------------------------------------------------------
Definition of routines of factorial
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
factorial using iteration
-----------------------------------------------------------------*/
long long recursion::factorial_iterative(unsigned n, int& num_mult) {
  long long a = 1;
  num_mult = 0;
  for (int j = n; j > 1; j--) {
    ++num_mult;
    a = a * j;
  }
  return a;
}


long long recursion::factorial_recursion(unsigned n, int& num_rec) {
	if (n<=1){
		return 1;
	}
	num_rec++;
	return (n * factorial_recursion(n-1, num_rec));

}

/*----------------------------------------------------------------
factorial using stack
-----------------------------------------------------------------*/
long long recursion::factorial_stack(unsigned n, int& size_of_stack) {
  size_of_stack = 0;
  dstack<long long> s(_display);
  //WRITE CODE
  if(n<=1){return 1;};

  s.push(1);

  for(int i=2 ; i<=n ; i++){
	  s.push(s.top()*i);
  }
  size_of_stack = s.num_elements();
  return s.top();
}

//EOF

