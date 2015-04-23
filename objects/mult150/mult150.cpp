#include "mult150.h"

mult150::mult150(char* a, char* b): _m1(NULL), _m2(NULL){
	if (display){
		cout << "-----------------------------" << endl;
		cout << "In mult150 constructor" << endl;
	}

	_result = new char[150];
	_lena = strlen(a);
	_m1 = new int[_lena];
	for(int i=0;i<=_lena-1;i++){
		_m1[i] = a[i]-'0';
	}
	_lenb = strlen(b);
	_m2 = new int[_lenb];
	for(int i=0;i<=_lenb-1;i++){
		_m2[i] = b[i]-'0';
	}
	_multiply();
}
mult150::~mult150(){
	if (display){
		cout << "In mult150 destructor" << endl;
	}
	delete[] _m1;
	delete[] _m2;
	delete[] _result;
}
void mult150::_multiply(){
	int noOfMult = 0;
	int noOfAdd = 0;
	int resultInt[150] = {0};
	int rcounter = 1;
	int kcounter = 1;
	int carrym = 0;
	int carrya = 0;
	for(int i=_lenb-1 ; i>=0 ; i--){
		for(int j=_lena-1 ; j >=0 ; j--){
			int x = _m2[i]*_m1[j] + carrym;
			noOfMult++;
			carrym = x/10;
			int y = resultInt[150-rcounter] + (x%10) + carrya;
			noOfAdd++;
			noOfAdd++;
			carrya = y/10;
			resultInt[150-rcounter] = y%10;
			rcounter++;
		}
		resultInt[150-rcounter]+=carrym;
		resultInt[150-rcounter]+=carrya;
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
	int length = 150-dif;
	for (int i=0 ; i<=length; i++){
		_result[i]=resultInt[i+dif]+'0';
	}
	_result[length]='\0';
}
int mult150::_countZeros(const int (&a)[150]){
	int count = 0;
	for(int i=0 ; i<150 ; i++){
		if(a[i] == 0){
			count++;
		} else{
			return count;
		}
	}
	return count;
}
ostream& operator<<(ostream& o, const mult150& c){
	 o << c._result;
	 return o;
}
bool operator==(const mult150&c1, const char* c2){
	int l = strlen(c2);
	for(int i=0;i<l;i++){
		if(c1._result[i] != c2[i]){
			return false;
		}
	}
	return true;
}
/*
-------------------------------
Number of Multiplications: 2
Number of Additions: 2
95
-------------------------------
Number of Multiplications: 4
Number of Additions: 4
969
-------------------------------
Number of Multiplications: 2500
Number of Additions: 2500
1522605027922533360535618378132637429718068114961380688657908494580122963258952897654000350692006139
-------------------------------
Number of Multiplications: 3025
Number of Additions: 3025
35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516111204504060317568667
-------------------------------
Number of Multiplications: 4160
Number of Additions: 4160
114381625757888867669235779976146612010218296721242362562561842935706935245733897830597123563958705058989075147599290026879543541
Run time   is 0.000312 secs
*/
