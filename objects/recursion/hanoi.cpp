/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: hanoi.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "recursion.h"

/*----------------------------------------------------------------
WRITE CODE
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
hanoi using recursion

1 -> 3
1 -> 2
3 -> 2
1 -> 3
2 -> 1
2 -> 3
1 -> 3
Number of itr = 7
-----------------------------------------------------------------*/
void recursion::_t_r(unsigned n, char s, char t, char d, int& num_rec, str& str){
  if (n) {
    ++num_rec;
    _t_r(n - 1, s, d, t, num_rec, str);
    //s->d
    str = str + s + " -> " + d + "\n";
    _t_r(n - 1, t, s, d, num_rec, str);
  }
}

void recursion::hanoi_recursion(unsigned n, int& num_rec, str& s) {
  _t_r(n, '1', '2', '3', num_rec, s);
}

/*----------------------------------------------------------------
hanoi using stack
-----------------------------------------------------------------*/
class recursion::peg{
	public:
		peg(str name): mystack(false), name(name), maxsize(0){};
		dstack<int> mystack;
		str name;
		int maxsize;
};

void recursion::hanoi_stack_r(unsigned n, peg& s, peg& t, peg& d, str& str){
	if(n>1){
		hanoi_stack_r(n-1, s, d, t, str);
	}
	d.mystack.push(s.mystack.top());
	if (d.maxsize<d.mystack.num_elements()){d.maxsize++;}
	s.mystack.pop();
	str = str + s.name + " -> " + d.name + "\n";
	if(n>1){
		hanoi_stack_r(n-1, t, s, d, str);
	}
}

void recursion::hanoi_stack(unsigned n, int& size_of_stack, str& str) {
	size_of_stack = 0;
	peg s('1');
	peg t('2');
	peg d('3');
	for(int i=1 ; i<=n ; i++){
		s.mystack.push(i);
	}
	hanoi_stack_r(n, s, t, d, str);
	size_of_stack = s.maxsize + t.maxsize + d.maxsize;
}

//EOF



