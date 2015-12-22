#ifndef _STACK2_H_
#define _STACK2_H_
#include <iostream>
// 第二次上机试验
// 用类来实现栈的基本操作
//
class STACK{
	int *const elems;
	const int max;
	int pos;
	
	public :
		STACK(int m);
		STACK(const STACK& s);
		int size() const;
		int howMany() const;
		int getElem(int x) const;
		STACK& push(int e);
		STACK& pop(int &e);
		STACK& assign(const STACK& s);
		void print() const;

		~STACK();
};

#endif 
