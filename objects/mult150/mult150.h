#include "../util/util.h"

class mult150 {
public:
	mult150(char* a, char* b);
	~mult150();
	static bool display;
	friend ostream& operator<<(ostream& o, const mult150& c);
	friend bool operator==(const mult150&c1, const char* c2);
private:
	int* _m1;
	int* _m2;
	int _lena;
	int _lenb;
	char* _result;
	void _multiply();
	int _countZeros(const int (&a)[150]);
};
