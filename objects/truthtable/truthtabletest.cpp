
#include "truthtable.h"

int main() {
int n = 22;
clock_t start = clock();
truthtable a(n);
clock_t end = clock();
double d = double(end - start) / CLOCKS_PER_SEC;
cout << "Run time for truthtable for n = " << n << " is " << d << " secs" << endl; return 0 ;
}
