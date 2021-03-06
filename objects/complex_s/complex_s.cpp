/*
 * truthtable.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: sinan
 */

#include "complex_s.h"


complex::complex(int a, int b) : _real(a), _imaginary(b), _name(NULL) {
	_setname(a,b);
}
complex::~complex(){
	delete[] _name;
}
complex::complex(const complex& c){
	_copy(c);
}
complex& complex::operator=(const complex& rhs){
	if(this!= &rhs){
		_release();
		_copy(rhs);
	}
	return *this;
}
void complex::_copy(const complex& from){
	int l = strlen(from._name)+1;
	_name = new char[l];
	strcpy(_name,from._name);
}
void complex::_release(){
	delete[] _name;
}
ostream& operator<<(ostream& o, const complex& c){
	 o << c._name;
	 return o;
}
bool operator==(const complex&c1, const complex&c2){
	if(c1._real == c2._real && c1._imaginary == c2._imaginary){
		return true;
	}
	return false;
}
bool operator!=(const complex&c1, const complex&c2){
	if(!(c1==c2)){
		return true;
	}
	return false;
}
void complex::_setname(int a, int b){

	//calculate the length of name
	int digitsa = 0;
	int counta = a;
	while (counta) {
		counta /= 10;
		digitsa++;
	}
	int countb = b;
	int digitsb = 0;
	while (countb) {
		countb /= 10;
		digitsb++;
	}
	int aneg = 0;
	if(a<0){
		aneg = 1;
	}
	int lengthofname = aneg+digitsa+1+1+digitsb;
	_name = new char[lengthofname+1];

	//put the characters one by one into name array
	_name[lengthofname]='\0';
	if (b<0){
		b = -b;
		_name[lengthofname-digitsb-2]= '-';
	}else{
		_name[lengthofname-digitsb-2]= '+';
	}
	for (int i=lengthofname-1; i>=lengthofname-digitsb;i--){
		_name[i]=b%10 + '0';
		b=b/10;
	}
	_name[lengthofname-digitsb-1]= 'i';
	if (a<0){
		a = -a;
		_name[0]='-';
	}
	for (int i=lengthofname-digitsb-3; i>lengthofname-digitsb-3-digitsa;i--){
		_name[i]=a%10 + '0';
		a=a/10;
	}
}
void complex::setxy(int a, int b) {
	_release();
	_setname(a,b);
	_real = a;
	_imaginary = b;
}

/*
RESULT:
------------------------
2+i3
27-i200
-20+i4
-18-i99
2+i3
c1 is equal to c2
c1 is NOT equal to c3
-200-i800
-18-i99
-------------------------
 */
