/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: ../complex/complex.cpp darraytest.cpp

On linux:
g++ ../complex/complex.cpp darraytest.cpp
valgrind a.out
-- All heap blocks were freed -- no leaks are possible

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test darray object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "darray.h"
#include "../complex/complex.h"

/*--------------------------------------------------------
local to this file. Change verbose = true for debugging
----------------------------------------------------------*/
static bool verbose = true;

/*----------------------------------------------------------------
array of integers
-----------------------------------------------------------------*/
static void test_array_of_integers(){
  const int N = 5;
  //darray<int> b; This will compile
  {
    /* This will not compile */
    //int x;
    //darray<int> c(x);
  }
  darray<int> a(verbose, 3);
  //darray<int> a(3, verbose); /* This will not compile in C++11 */
  for (int i = 0; i < N; i++) {
    a[i] = i * 10;
  }
  darray<int>b(a);
  for (int i = 0; i < N; i++) {
    cout << " b[" << i << "]=" << b[i];
  }
  cout << endl;
  bool equal = true;
  for (int i = 0; i < N; i++) {
    if (a[i] != b[i]) {
      equal = false;
      break;
    }
  }
  equal ? cout << " array a == b\n " : cout << " array a != b\n ";
  cout << endl;
  cout << "We have not inserted 25th element. Let us see what we get " << endl;
  cout << a[25] << endl;
}

/*----------------------------------------------------------------
array of integer pointers
-----------------------------------------------------------------*/
static void test_array_of_ptr_integers(int n){
  darray<int*> a(verbose, 3);
  //darray<int*> a1(3,verbose); /* this will not compile */
  for (int i = 0; i < n; i++) {
    a[i] = new int(i * 10);
  }
  darray<int*> b(a);
  for (int i = 0; i < n; i++) {
    cout << " b[" << i << "]=" << *(b[i]);
  }
  cout << endl;
  bool equal = true;
  for (int i = 0; i < n; i++) {
    if (*(a[i]) != *(b[i])) {
      equal = false;
      break;
    }
  }
  equal ? cout << " array a == b\n " : cout << " array a != b\n ";
  cout << "We have not inserted 25th element. Let us see what we get " << endl;
  cout << a[25] << endl;
  for (int i = 0; i < n; i++) {
    /* we allocated contents in a. So we delete it */
    delete(a[i]);
  }
  /* Why you should NOT do this */
  /*
  for (int i = 0; i < n; i++) {
  FREE(b[i]) ;
  }
  */
}

/*----------------------------------------------------------------
array of user defined type
-----------------------------------------------------------------*/
static void test_array_of_udt(){
  const int N = 5;
  darray<complex> a(verbose, 3);
  for (int i = 0; i < N; i++) {
    a[i].setxy(i, -i);
  }
  darray<complex> b(a);
  for (int i = 0; i < N; i++) {
    cout << " b[" << i << "]=" << b[i];
  }
  cout << endl;
  bool equal = true;
  for (int i = 0; i < N; i++) {
    if (a[i] != b[i]) {
      equal = false;
      break;
    }
  }
  equal ? cout << " array a == b\n " : cout << " array a != b\n ";
  cout << "We have not inserted 25th element. Let us see what we get " << endl;
  cout << a[25] << endl;
}

/*----------------------------------------------------------------
array of user defined pointer type
-----------------------------------------------------------------*/
static void test_array_of_ptr_udt(int n){
  darray<complex*> a(verbose, 3);
  for (int i = 0; i < n; i++) {
    a[i] = new complex(i, -i);
  }
  darray<complex*> b(a);
  for (int i = 0; i < n; i++) {
    cout << " b[" << i << "]=" << *(b[i]);
  }
  cout << endl;
  bool equal = true;
  for (int i = 0; i < n; i++) {
    if (*(a[i]) != *(b[i])) {
      equal = false;
      break;
    }
  }
  equal ? cout << " array a == b\n " : cout << " array a != b\n ";
  cout << "We have not inserted 25th element. Let us see what we get " << endl;
  //cout << a[25] << endl ;
  for (int i = 0; i < n; i++) {
    /* we allocated contents in a. So we delete it */
    delete(a[i]);
  }
  /* Why you should NOT do this */
  /*
  for (int i = 0; i < n; i++) {
  FREE(b[i]) ;
  }
  */
}

/*----------------------------------------------------------------
array of constant integers
-----------------------------------------------------------------*/
static void test_constant_array_of_integer(){
  static const int arr[] = { -89, -90, -78, -420, 1986, 2002 };
  int size = sizeof(arr) / sizeof(int);
  const darray<int> a(arr, size, verbose);
  int k = a[2]; //WHICH EQUAL IS CALLED ?
  //error C3892: 'a' : you cannot assign to a variable that is const
  //a[1] = a[2] ;
  for (int i = 0; i < size; ++i) {
    cout << " a[" << i << "]=" << a[i];
  }
  const darray<int>b(a);
  for (int i = 0; i < size; ++i) {
    cout << " b[" << i << "]=" << b[i];
  }
  //'a' : you cannot assign to a variable that is const
  //a[10] = 789 ;
}

/*----------------------------------------------------------------
array of constant complex
-----------------------------------------------------------------*/
static void test_constant_array_of_complex(){
  static const complex arr[] = { -89, -90, -78, -420, 1986, 2002 };
  int size = sizeof(arr) / sizeof(complex);
  const darray<complex> a(arr, size, verbose);
  complex k = a[2]; //WHICH EQUAL IS CALLED ?
  //error C3892: 'a' : you cannot assign to a variable that is const
  //a[1] = a[2] ;
  for (int i = 0; i < size; ++i) {
    cout << " a[" << i << "]=" << a[i];
  }
  const darray<complex>b(a);
  for (int i = 0; i < size; ++i) {
    cout << " b[" << i << "]=" << b[i];
  }
  //
  complex c(90, -9);
  //a[10] = c ;
}

/*----------------------------------------------------------------
problem

MORAL: DO NOT STORE ALIAS TO THE CONTAINER OBJECT
-----------------------------------------------------------------*/
static void test_problem() {
  darray<complex> vc(verbose, 3);
  vc[0] = 0;
  vc[1] = 1;
  vc[2] = 2;

  complex& c1 = vc[1];
  cout << " c1 = " << c1 << endl;

  vc[3] = 3;
  vc[4] = 4;

  cout << " c1 = " << c1 << endl; //WHAT HAAPENS HERE ?????????????
}


/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  darray<int> a;
  a[0] = 1;
  cout << a[0];
  return 0;
}

//EOF

