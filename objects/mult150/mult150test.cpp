/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: mult150test.cpp

On linux:
g++ mult150.cpp mult150test.cpp
valgrind a.out
==30529== All heap blocks were freed -- no leaks are possible
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test mult150 object 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "mult150.h"

/*----------------------------------------------------------------
initialization of static
-----------------------------------------------------------------*/
bool mult150::display = true;

/*----------------------------------------------------------------
test bench
-----------------------------------------------------------------*/
void test_bench() {

  mult150 t("5", "19");
  cout << t << endl;
  assert(t == "95");

  mult150 t1("51", "19");
  cout << t1 << endl;
  assert(t1 == "969");

  mult150 rsa100("37975227936943673922808872755445627854565536638199", "40094690950920881030683735292761468389214899724061");
  cout << rsa100 << endl;
  assert(rsa100 == "1522605027922533360535618378132637429718068114961380688657908494580122963258952897654000350692006139");

  mult150 rsa110("6122421090493547576937037317561418841225758554253106999", "5846418214406154678836553182979162384198610505601062333");
  cout << rsa110 << endl;
  assert(rsa110 == "35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516111204504060317568667");

  mult150 rsa129("3490529510847650949147849619903898133417764638493387843990820577", "32769132993266709549961988190834461413177642967992942539798288533");
  cout << rsa129 << endl;
  assert(rsa129 == "114381625757888867669235779976146612010218296721242362562561842935706935245733897830597123563958705058989075147599290026879543541");
}


/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  clock_t start = clock();
  test_bench();
  clock_t end = clock();
  double d = double(end - start) / CLOCKS_PER_SEC;
  cout << "Run time  " << " is " << d << " secs" << endl;
  return 0;
}


//EOF

