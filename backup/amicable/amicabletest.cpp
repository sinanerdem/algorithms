
#include "amicable.h"

int main() {

 const int MAX = 100000000;

 clock_t start = clock() ;

 amicable a(MAX) ;

 clock_t end = clock() ;

 cout <<"Run time for amicable " << double(end - start)/CLOCKS_PER_SEC <<

 " secs" << endl ;

}
