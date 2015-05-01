#include "../util/util.h"
#include "../darray/darray.h"

class str{
public:
	  str(char* c=nullptr, bool d = false);
	  str(char c, bool d = false);
	  ~str();
	  bool display()const { return _display; }
	  void set_display(bool x) { _display = x; }
	  friend ostream& operator<<(ostream& o, const str& s);
	  str(const str& b) ;
	  str& operator=(const str& rhs) ;
	  friend bool operator==(const str& a, const str& b);
	  friend bool operator!=(const str& a, const str& b);
	  friend str operator+(const str& a, char* b);
	  friend str operator+(char* a, const str& b);
	  friend str operator+(const str& a, char b);
	  friend str operator+(char a, const str& b);
	  friend str operator+(const str& a, const str& b);
	  friend int string_compare(const str& a, const str& b);
	  void reverse();


private:
	  bool _display;
	  int _size;
	  darray<char> _myarray;
	  void _release();
	  void _copy(const str& from) ;
};
