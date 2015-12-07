#include "stack_2.h"

STACK::STACK(int m):max(m), elems(new int[m+1]){
	pos = 0;
}
//elems(s.elems)
STACK::STACK(const STACK &s):max(s.max), elems(new int[s.max+1]){
    int i;
    pos = s.pos;
	for(i=0; i<pos; i++){
		elems[i] = (s.elems)[i];
	}
}

int STACK::size() const{
	return max;
}

int STACK::howMany() const{
	if(elems == 0){
		std::cout<<"stack is null"<<std::endl;
		 return -1;
	}
	else
	  return pos;
}

int STACK::getElem(int x) const{
	if(x<0 || x>=pos){
		std::cout<<"x 非法"<<std::endl;
		return -1;
	}
	else{
		return elems[x];
	}
}

STACK& STACK::push(int e){
	if(pos == max){
		std::cout<<"stack is ful"<<std::endl;
		return *this;
	}
	else{
		elems[pos] = e;
		pos += 1;
		return *this;
	}
}
//*(int **)&elems =
//*(int *)&max=
STACK& STACK::pop(int &e){
	if(pos == 0){
		std::cout<<"stack is empty"<<std::endl;
		return *this;
	}else{
		e = elems[pos-1];
		pos -= 1;
		return *this;
	}
}

STACK& STACK::assign(const STACK& s){
	int i;
	if(elems != 0){
		delete []elems;
	}
	*(int *)&max = s.max;
	pos = s.pos;
    *(int **)&elems = new int[max+1];

	for(i=0; i<pos; i++){
		elems[i] = (s.elems)[i];
	}

	return *this;
}

void STACK::print() const{
	int i;
	for(i=0; i<pos; i++){
		std::cout<<"no."<<i+1<<":  "<<elems[i]<<std::endl;
	}
}

STACK::~STACK(){
	*(int *)&max = 0;
	pos = 0;
	delete [] elems;
}
