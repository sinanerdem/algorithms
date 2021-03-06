#include "../util/util.h"

class complex {
public:
	complex(int a=0, int b=0);
	~complex();
	complex(const complex& c);
	void setxy(int a, int b);
	complex& operator=(const complex& rhs);
	friend ostream& operator<<(ostream& o, const complex& c);
	friend bool operator==(const complex& c1, const complex& c2);
	friend bool operator!=(const complex& c1, const complex& c2);
private:
	void _copy(const complex& from);
	void _release();
	void _setname(int a, int b);
	int _real;
	int _imaginary;
	char* _name;
};
