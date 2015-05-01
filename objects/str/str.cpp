#include "str.h";

str::str(char c, bool d):_myarray(nullptr), _display(d), _size(1){
	if(display()){
		cout << "in str constructor:" << endl;
	}
	_size = 1;
	_myarray = new darray<char>(false, 1);
	_myarray[0] = c;
	_myarray[1] = '\0';
}
str::str(char* c, bool d):_display(d), _size(0), _myarray(nullptr){
	if(display()){
		cout << "in str constructor:" << endl;
	}
	_size = strlen(c);
	_myarray = new darray<char>();
	for(int i=0 ; i <_size ; i++){
		_myarray[i] = c[i];
	}
	_myarray[_size+1] = '\0';
}
str::~str() {
  if (display()) {
    cout << "in str Destructor " << endl;
  }
  _release();
  _size = 0;
}
void str::_release(){

}
/*----------------------------------------------------------------
Print
-----------------------------------------------------------------*/
ostream& operator<<(ostream& o, const str& s){
	int counter = s._size;
	for (int i=0; i < counter ; i++){
		o << s._myarray[i];
	}
	return o;
}
/*----------------------------------------------------------------
Copy constructor
-----------------------------------------------------------------*/
str::str(const str& b){
  if (display()) {
    cout << "in str copy constructor " << endl;
  }
  _copy(b);
}

/*----------------------------------------------------------------
equal operator
-----------------------------------------------------------------*/
str& str::operator=(const str& rhs) {
  if (rhs.display()) {
    cout << "in  str equal operator " << endl;
  }
  if (this != &rhs) {
    _release();
    _copy(rhs);
  }
  return *this;
}

/*----------------------------------------------------------------
equal equal operator
-----------------------------------------------------------------*/
bool operator==(const str& a, const str& b){
	if(a._size != b._size) { return false;}
	int size = a._size;
	for(int i=0 ; i < size ; i++){
		if (a._myarray[i] != b._myarray[i]){
			return false;
		}
	}
	return true;
}
/*----------------------------------------------------------------
not equal operator
-----------------------------------------------------------------*/
bool operator!=(const str& a, const str& b){
	if (!(a==b)){
		return true;
	} else{
		return false;
	}
}
/*----------------------------------------------------------------
compare function
-----------------------------------------------------------------*/
int string_compare(const str& a, const str& b){
	if (a==b){
		return 0;
	} else{
		int size = (a._size > b._size) ? a._size : b._size;
		for(int i=0 ; i<size ; i++){
			if(a._myarray[i]=='\0'){return -1;}
			else if(b._myarray[i]=='\0'){return 1;}
			else if(a._myarray[i]==b._myarray[i]){continue;}
			else {return (a._myarray[i]>b._myarray[i]) ? 1 : -1;}
		}
	}
}
/*----------------------------------------------------------------
concatenation operators
-----------------------------------------------------------------*/
str operator+(const str& a, const str& b){
	str result = a;
	int bsize = b._size;
	int size = a._size;
	result._size = bsize + size;
	int newsize = result._size;
	int counter = 0;
	for(int i=size ; i<newsize ; i++){
		result._myarray[i]=b._myarray[counter];
		counter++;
	}
	result._myarray[newsize]='\0';
	return result;
}
str operator+(char* a, const str& b){
	return str(a) + b;
}
str operator+(const str& a, char* b){
	return a + str(b);
}
str operator+(const str& b, char a){
	str result = b;
	result._myarray[result._size]=a;
	result._size++;
	return result;
}
str operator+(char a, const str& b){
	str result = b + a;
	return result;
}
/*----------------------------------------------------------------
Helper: copy function
-----------------------------------------------------------------*/
void str::_copy(const str& from) {
	_size = from._size;
	_display = from._display;
	for(int i=0 ; i <=_size ; i++){
		_myarray[i] = from._myarray[i];
	}
}

/*----------------------------------------------------------------
Helper: reverse function
-----------------------------------------------------------------*/
void str::reverse(){
	char temp;
	int half = _size/2;
	for(int i=0 ; i<half ; i++){
		temp = _myarray[i];
		_myarray[i] = _myarray[_size-i-1];
		_myarray[_size-i-1] = temp;
	}
}

/*
 * OUTPUT:
 *
length of j = 3
in str constructor:
in darray constructor:
In darray equal operator
In darray Destructor
in str constructor:
in darray constructor:
In darray equal operator
In darray Destructor
jag
gaj
U
gaj
gaj
in  str equal operator
U
U
s1 == s2
s1 != s3
in str constructor:
in darray constructor:
In darray equal operator
In darray Destructor
in str constructor:
in darray constructor:
In darray equal operator
In darray Destructor
in  str equal operator
in str Destructor
s1 = U
s3 = Ua
in  str equal operator
in str Destructor
s3 = Up
in darray constructor:
In darray equal operator
In darray Destructor
in darray constructor:
In darray equal operator
In darray Destructor
In darray Destructor
In darray Destructor
s3 = abc123
in darray constructor:
In darray equal operator
In darray Destructor
In darray Destructor
in darray constructor:
In darray equal operator
In darray Destructor
In darray Destructor
Jag ++C++ Claaaas
in str Destructor
In darray Destructor
in str Destructor
In darray Destructor
In darray Destructor
In darray Destructor
*/
