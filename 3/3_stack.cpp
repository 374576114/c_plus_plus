#include "3_stack.h"
#include <iostream>

STACK::STACK(int m):max(m), elems(new int[m+1]){
	pos = 0;
}

STACK::STACK(const STACK&s):max(s.max), elems(new int[s.max + 1]){
	int i;
	pos = s.pos;

	for(i=0; i<pos; i++){
		elems[i] = (s.elems)[i];
	}
}

int STACK::size() const{
	return max;
}

STACK::operator int() const{
	return pos;
}

int STACK:: operator[](int x) const{
	if(x<0 || x>=pos){
		std::cout<<"error index"<<std::endl;
		return -1;
	}else{
		return elems[x];
	}
}

STACK& STACK::operator<<(int e){
	if(pos == max){
		std::cout<<"stack is full"<<std::endl;
		return *this;
	}else{
		elems[pos] = e;
		pos += 1;
		return *this;
	}
}

STACK& STACK::operator>>(int &e){
	if(pos == 0){
		std::cout<<"stack is empty"<<std::endl;
		e = -1;
		return *this;
	}else{
		pos -= 1;
		e = elems[pos];
		return *this;
	}
}

STACK& STACK::operator=(const STACK& s){
	int i;

	if(this == &s)
	  return *this;

	*(int *)&max = s.max;
	delete[] elems;
	*(int **)&elems = new int [s.max + 1];
	pos = s.pos;

	for(i=0; i<pos; i++){
		elems[i] = (s.elems)[i];
	}

	return *this;
}

void STACK::print() const{
	int i;
	for(i=0; i<pos; i++){
		std::cout<<i+1<<"  "<<elems[i]<<std::endl;
	}
}

STACK::~STACK(){
	std::cout<<"destructor"<<std::endl;
	*(int *)&max = 0;
	pos = 0;
	delete [] elems;
}

