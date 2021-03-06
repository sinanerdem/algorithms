/*
 * truthtable.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: sinan
 */

#include "truthtable.h"


truthtable::truthtable(int x) {
	int y = pow(2,x);
	for (int i=0; i<y; i++){
		for (int j=x-1; j>=0; j--){
			int output = (i>>j)&1;
			cout << output;
			}
		cout << endl;
	}

}

/*
000000
000001
000010
000011
000100
000101
000110
000111
001000
001001
001010
001011
001100
001101
001110
001111
010000
010001
010010
010011
010100
010101
010110
010111
011000
011001
011010
011011
011100
011101
011110
011111
100000
100001
100010
100011
100100
100101
100110
100111
101000
101001
101010
101011
101100
101101
101110
101111
110000
110001
110010
110011
110100
110101
110110
110111
111000
111001
111010
111011
111100
111101
111110
111111
Run time for truthtable for n = 6 is 0.000299 secs
--------------
Run time for truthtable for n = 10 is 0.006416 secs
--------------
Run time for truthtable for n = 16 is 0.521954 secs
--------------
Run time for truthtable for n = 20 is 9.56927 secs
--------------
Run time for truthtable for n = 30 is 9352.544 secs
--------------
For n = 30 and higher, program cannot finish in reasonable time.
*/
