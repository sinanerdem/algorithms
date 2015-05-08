/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: fibonacci.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "recursion.h"

/*----------------------------------------------------------------
WRITE CODE
-----------------------------------------------------------------*/
int recursion::fibonacci_iterative(unsigned n, int& num_itr){
	if(n==0) {return 0;}
	if(n==1) {return 1;}
	num_itr = 0;
	int first = 0;
	int second = 1;
	int sum = 0;
	for(int i=2 ; i<=n ; i++){
		sum = first + second;
		first = second;
		second = sum;
		num_itr++;
	}
	return sum;

}
int recursion::fibonacci_recursion(unsigned n, int& num_rec){
	if(n==0) {return 0;}
	if(n==1) {return 1;}
	num_rec++;
	return fibonacci_recursion(n-1, num_rec) + fibonacci_recursion(n-2, num_rec);
}
int recursion::fibonacci_stack(unsigned n, int& size_of_stack){
	if(n==0) {return 0;}
	if(n==1) {return 1;}
	size_of_stack=0;
	dstack<int> s(_display);
	int val1 = 0;
	int val2 = 0;
	s.push(0);
	s.push(1);
	for(int i=2 ; i<=n ; i++){
		val1 = s.top();
		s.pop();
		val2 = val1 + s.top();
		s.push(val1);
		s.push(val2);
	}
	size_of_stack = s.num_elements();
	return s.top();
}
//EOF

