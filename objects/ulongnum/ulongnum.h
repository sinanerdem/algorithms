#include "str.h"
#include "../util/util.h"

class ulongnum{

public:
	  ulongnum(char* c=nullptr, bool d = false);
	  ulongnum(char c, bool d = false);
	  ulongnum(int c, bool d = false);
	  ~ulongnum();
	  bool display()const { return _display; }
	  void set_display(bool x) { _display = x; _corestr.set_display(x);}
	  friend ostream& operator<<(ostream& o, const ulongnum& c);
	  friend ulongnum operator*(const ulongnum& u1, const ulongnum& u2);
	  friend ulongnum operator+(const ulongnum& u1, const ulongnum& u2);
	  ulongnum(const ulongnum& b) ;
	  ulongnum& operator=(const ulongnum& rhs) ;
	  friend bool operator==(const ulongnum& a, const ulongnum& b);
	  friend bool operator!=(const ulongnum& a, const ulongnum& b);
	  int getsize(){return _size;};
	  ulongnum factorial(ulongnum n);

private:
	  bool _display;
	  str _corestr;
	  int _size;
	  void _release();
	  void _copy(const ulongnum& from) ;
};
