/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: num_binary_digit.cpp
-----------------------------------------------------------------*/


/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "recursion.h"

/*----------------------------------------------------------------
WRITE CODE
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
num_binary_digit using iteration
0  1
1  1
4  100
15 1111
16 10000
-----------------------------------------------------------------*/
int recursion::num_binary_digit_iterative(unsigned n, int& num_itr){
	if (n==0){return 1;}
//	int result=0;
	num_itr=0;
	while(n > 0){
//		result += n%2 * pow(10,counter);
		n=n/2;
		num_itr++;
	}
	return num_itr;
}
int recursion::num_binary_digit_recursion(unsigned n, int& num_rec){
	if (n<=1){
		return 1;
	}
	num_rec++;
	return 1 + num_binary_digit_recursion(n/2, num_rec);
}
int recursion::num_binary_digit_stack(unsigned n, int& size_of_stack){
	if (n<=1){
		return 1;
	}
	dstack<int> s(_display);
	s.push(1);
	while(n>1){
		s.push(n);
		n/=2;
	}
	size_of_stack = s.num_elements();
	return s.num_elements();
}

//EOF

