/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: ../complex/complex.cpp dstacktest.cpp

On linux:
g++ ../complex/complex.cpp dstacktest.cpp
valgrind a.out
-- All heap blocks were freed -- no leaks are possible

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test dstack object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "dstack.h"
#include "complex.h"

/*--------------------------------------------------------
local to this file. Change verbose = true for debugging
----------------------------------------------------------*/
static bool verbose = true;

/*----------------------------------------------------------------
Print an integer - value given
-----------------------------------------------------------------*/
static void print(int& x) {
  cout << x << " ";
}

/*----------------------------------------------------------------
Print an integer - address given
-----------------------------------------------------------------*/
static void print(int*& x) {
  print(*(x));
}

/*----------------------------------------------------------------
Print a complex - value given
-----------------------------------------------------------------*/
static void print(complex& x) {
  cout << x << " ";
}

/*----------------------------------------------------------------
Print a complex  - address given
-----------------------------------------------------------------*/
static void print(complex*& x) {
  print(*(x));
}

/*----------------------------------------------------------------
add by 2000 - value given
-----------------------------------------------------------------*/
static void add2000(int& x) {
  x = x + 2000;
}

/*----------------------------------------------------------------
add by 2000 - address given
-----------------------------------------------------------------*/
static void add2000(int*& x) {
  add2000(*(x));
}

/*----------------------------------------------------------------
add by 2000 - value given
-----------------------------------------------------------------*/
static void add2000(complex& c) {
  int x, y;
  c.getxy(x, y);
  x = x + 2000;
  y = y + 2000;
  c.setxy(x, y);
}

/*----------------------------------------------------------------
add by 2000 - address given
-----------------------------------------------------------------*/
static void add2000(complex*& x) {
  add2000(*(x));
}

/*----------------------------------------------------------------
delete integer - address given
-----------------------------------------------------------------*/
static void delete_obj(int*&  x) {
  delete(x);
}

/*----------------------------------------------------------------
delete complex - address given
-----------------------------------------------------------------*/
static void delete_obj(complex*&  x) {
  delete(x);
}


/*----------------------------------------------------------------
array of integers
-----------------------------------------------------------------*/
static void test_stack_of_integers(){
  {
    //THIS will not compile
    //int x = 8;
    //dstack<int> s(8,verbose);
  }
  dstack<int> s(verbose,3);
  cout << "Number of element in the stack is: " << s.num_elements() << endl;
  for (int i = 0; i < 8; i++) {
    s.push(1000 + i);
  }
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  s.for_each_element_of_stack_from_top_to_bottom(add2000);
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  for (int i = 0; i < 7; i++){
    int& x = s.top();
    cout << "Top element = " << x << endl;
    s.pop();
  }
  int& x = s.top();
  cout << "top element = " << x << endl;
  for (int i = 0; i < 8; i++) {
    s.push(-(8000 + i));
  }
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  int& y = s.top();
  y = 9999;
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  int z = s.top();
  z = 8888;
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
}

/*----------------------------------------------------------------
array of integer pointers
-----------------------------------------------------------------*/
static void test_stack_of_ptr_integers(){
  dstack<int*> s(verbose,3);
  cout << "Number of element in the stack is: " << s.num_elements() << endl;
  for (int i = 0; i < 8; i++) {
    s.push(new(int)(1000 + i));
  }
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  s.for_each_element_of_stack_from_top_to_bottom(add2000);
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  for (int i = 0; i < 7; i++){
    int*& x = s.top();
    cout << "top element = " << *x << endl;
    delete(x);
    s.pop();
  }
  int x = *(s.top());
  cout << "Top element = " << x << endl;
  for (int i = 0; i < 8; i++) {
    s.push(new(int)(-(8000 + i)));
  }
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  s.for_each_element_of_stack_from_top_to_bottom(delete_obj);
}

/*----------------------------------------------------------------
array of user defined type
-----------------------------------------------------------------*/
static void test_stack_of_udt(){
  dstack<complex> s(verbose,3);
  cout << "Number of element in the stack is: " << s.num_elements() << endl;
  for (int i = 0; i < 8; i++) {
    s.push(complex(1000 + i, -(1000 + i)));
  }
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  s.for_each_element_of_stack_from_top_to_bottom(add2000);
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  for (int i = 0; i < 7; i++){
    cout << "Top element = " << s.top() << endl;
    s.pop();
  }
  cout << "Top element = " << s.top() << endl;
  for (int i = 0; i < 8; i++) {
    s.push(complex(-(8000 + i), -(-(8000 + i))));
  }
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  complex& y = s.top();
  y = 9999;
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  complex z = s.top();
  z = 8888;
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
}

/*----------------------------------------------------------------
array of user defined pointer type
-----------------------------------------------------------------*/
static void test_stack_of_ptr_udt(){
  dstack<complex*> s(verbose,3);
  cout << "Number of element in the stack is: " << s.num_elements() << endl;
  for (int i = 0; i < 8; i++) {
    s.push(new(complex)(complex(1000 + i, -(1000 + i))));
  }
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  s.for_each_element_of_stack_from_top_to_bottom(add2000);
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  for (int i = 0; i < 7; i++){
    complex*& x = s.top();
    cout << "top element = " << *(x) << endl;
    delete(x);
    s.pop();
  }
  cout << "top element = " << s.top() << endl;
  for (int i = 0; i < 8; i++) {
    s.push(new(complex)((-(8000 + i), -(-(8000 + i)))));
  }
  s.for_each_element_of_stack_from_top_to_bottom(print);
  cout << endl;
  s.for_each_element_of_stack_from_top_to_bottom(delete_obj);
}
/*
 * TEST OF THE MIN PROPERTY / by SINAN ERDEM
 *
 */
static void test_min_with_int() {

	dstack<int> mystack(verbose,5);
	// cout << "min after initialization: " << mystack.min();
	// expected: assert fail;

	for (int i=5 ; i>0 ; i--){
		mystack.push(i);
	}
	cout << "min after populated with 5,4,3,2,1: " << mystack.min() << endl;
	// expected: 1
	assert(1==mystack.min());

	mystack.pop();
	cout << "min after last element (1) popped: " << mystack.min() << endl;
	// expected: 2
	assert(2==mystack.min());

	mystack.push(-50);
	cout << "min after -50 pushed: " << mystack.min() << endl;
	// expected: -50
	assert(-50==mystack.min());

	mystack.pop();
	cout << "min after last element (-50) popped: " << mystack.min() << endl;
	// expected: 2
	assert(2==mystack.min());

	mystack.for_each_element_of_stack_from_top_to_bottom(add2000);
	cout << "current stack elements: ";
	mystack.for_each_element_of_stack_from_top_to_bottom(print);
	cout << endl;
	cout << "min after add2000: " << mystack.min() << endl;
	// expected: 2002
	assert(2002==mystack.min());

	mystack.pop();
	cout << "min after last element (2002) popped: " << mystack.min() << endl;
	// expected: 2003
	assert(2003==mystack.min());
	mystack.pop();
	cout << "min after last element (2003) popped: " << mystack.min() << endl;
	// expected: 2004
	assert(2004==mystack.min());
	mystack.pop();
	cout << "min after last element (2004) popped: " << mystack.min() << endl;
	// expected: 2005
	assert(2005==mystack.min());
	mystack.pop();
	// cout << "min after last element (2005) popped: " << mystack.min() << endl;
	// expected: assert fail

}


/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  complex::set_display(verbose);
  test_stack_of_integers();
  cout << "____________________________" << endl;
  test_stack_of_ptr_integers();
  cout << "____________________________" << endl;
  test_stack_of_udt();
  cout << "____________________________" << endl;
  test_stack_of_ptr_udt();
  cout << "____________________________" << endl;
  test_min_with_int();
  cout << "____________________________" << endl;
  return 0;
}


//EOF

