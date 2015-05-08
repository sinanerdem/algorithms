#include "ulongnum.h"

ulongnum::ulongnum(char* c, bool d): _display(d), _corestr(c,d){
	if(display()){
		cout << "in str constructor:" << endl;
	}
	_size = _corestr.getsize();
}
ulongnum::ulongnum(char c, bool d): _display(d), _corestr(c,d) {
	if(display()){
		cout << "in str constructor:" << endl;
	}
	_size = _corestr.getsize();
}
ulongnum::ulongnum(int c, bool d): _display(d), _corestr(d){
	if(display()){
		cout << "in str constructor:" << endl;
	}
	char mystr[100];
	sprintf(mystr, "%d", c);
	_corestr = mystr;
	_size = _corestr.getsize();
}
ulongnum::~ulongnum(){

}
/*----------------------------------------------------------------
Print
-----------------------------------------------------------------*/
ostream& operator<<(ostream& o, const ulongnum& c){
  o << c._corestr;
  return o;
}
/*----------------------------------------------------------------
Copy constructor
-----------------------------------------------------------------*/
ulongnum::ulongnum(const ulongnum& b){
  if (display()) {
    cout << "in str copy constructor " << endl;
  }
  _copy(b);
}

/*----------------------------------------------------------------
equal operator
-----------------------------------------------------------------*/
ulongnum& ulongnum::operator=(const ulongnum& rhs) {
  if (rhs.display()) {
    cout << "in  str equal operator " << endl;
  }
  if (this != &rhs) {
    _release();
    _copy(rhs);
  }
  return *this;
}
int _countZeros(const int (&a)[300]){
	int count = 0;
	for(int i=0 ; i<300 ; i++){
		if(a[i] == 0){
			count++;
		} else{
			return count;
		}
	}
	return count;
}
/*----------------------------------------------------------------
multiplication operator
-----------------------------------------------------------------*/
ulongnum operator*(const ulongnum& u1, const ulongnum& u2){
	char result[300];
	int noOfMult = 0;
	int noOfAdd = 0;
	int resultInt[300] = {0};
	int rcounter = 1;
	int kcounter = 1;
	int carrym = 0;
	int carrya = 0;
	for(int i=u2._size-1 ; i>=0 ; i--){
		for(int j=u1._size-1 ; j >=0 ; j--){
			int x = (u2._corestr[i]-'0')*(u1._corestr[j]-'0') + carrym;
			noOfMult++;
			carrym = x/10;
			int y = resultInt[300-rcounter] + (x%10) + carrya;
			noOfAdd++;
			noOfAdd++;
			carrya = y/10;
			resultInt[300-rcounter] = y%10;
			rcounter++;
		}
		resultInt[300-rcounter]+=carrym;
		resultInt[300-rcounter]+=carrya;
		noOfAdd++;
		noOfAdd++;
		carrym = 0;
		carrya = 0;
		kcounter++;
		rcounter=kcounter;
	}
	cout << "Number of Multiplications: " << noOfMult << endl;
	cout << "Number of Additions: " << noOfAdd << endl;

	int dif = _countZeros(resultInt);
	int length = 300-dif;
	for (int i=0 ; i<=length; i++){
		result[i]=resultInt[i+dif]+'0';
	}
	result[length]='\0';
	ulongnum newnum(result);
	return newnum;
}
/*----------------------------------------------------------------
addition operator
-----------------------------------------------------------------*/
ulongnum operator+(const ulongnum& u1, const ulongnum& u2){

		int size1 = u1._size;
		int size2 = u2._size;
		int dif = size1 - size2;
		if (dif>=0){
			int op[300]={0};
			int carry = 0;
			for(int i=size2-1 ; i>=0 ; i--){
				int sum = u2._corestr[i]-'0' + u1._corestr[i+dif]-'0' + carry;
				op[300+i-size2]=sum%10;
				carry = sum/10;
			}
			if(dif != 0){
				for(int i=dif-1 ; i >=0 ; i--){
					int sum = u1._corestr[i]-'0'+ carry;
					op[300+i-size1] = sum%10;
					carry = sum/10;
				}
			}
			if (carry == 1){
				op[299-size1]=1;
			}
			char result[300];
			int dif = _countZeros(op);
			int length = 300-dif;
			for (int i=0 ; i<=length; i++){
				result[i]=op[i+dif]+'0';
			}
			result[length]='\0';
			ulongnum newnum(result);
			return newnum;
		}else{
			return u2 + u1;
		}

}
/*----------------------------------------------------------------
equal equal operator
-----------------------------------------------------------------*/
bool operator==(const ulongnum& a, const ulongnum& b){
	if(a._size != b._size) { return false;}
	int size = a._size;
	for(int i=0 ; i < size ; i++){
		if (a._corestr[i] != b._corestr[i]){
			return false;
		}
	}
	return true;
}
/*----------------------------------------------------------------
not equal operator
-----------------------------------------------------------------*/
bool operator!=(const ulongnum& a, const ulongnum& b){
	if (!(a==b)){
		return true;
	} else{
		return false;
	}
}

/*----------------------------------------------------------------
factorial function
-----------------------------------------------------------------*/
ulongnum ulongnum::factorial(ulongnum n){
	ulongnum zero('0');
    if (n == zero)
       return ulongnum(1);
    return n * factorial(n +(-1));
}
/*----------------------------------------------------------------
Helper: copy function
-----------------------------------------------------------------*/
void ulongnum::_copy(const ulongnum& from) {
	_corestr = from._corestr;
}

void ulongnum::_release(){

}

