#include "6_queue.h"
#include <iostream>
// STACK::pos
QUEUE::QUEUE(int m):STACK(m), s2(m) {}
QUEUE::QUEUE(const QUEUE& s): STACK(s), s2(s.s2){}

QUEUE::operator int() const{
	//return s2.STACK::operator int();
	return int(s2);
}

QUEUE& QUEUE::operator<<(int e){
	int n = int(s2);

	if(n == STACK::size() ){
		std::cout<<"FULL"<<std::endl;
		return *this;
	}
	//s2.STACK::operator<<(e);
	s2<<e;
	return *this;
}

QUEUE& QUEUE::operator>>(int &e){
	int i;
	int n = int(s2);
	int tmp;
	
	if(n == 0){
		std::cout<<"EMPTY\n"<<std::endl;
		return *this;
	}

	for(i=0; i<n; i++){
		//s2.STACK::operator>>(tmp);
		s2>>tmp;
		STACK::operator<<(tmp);
	}

	STACK::operator>>(e);

	for(i=0; i<n-1; i++){
		STACK::operator>>(tmp);
		//s2.STACK::operator<<(tmp);
		s2<<tmp;
	}

	return *this;
}

QUEUE& QUEUE::operator=(const QUEUE& s){
	STACK::operator=(s);	
	//s2 = STACK::operator=(s.s2);
	s2 = s.s2;
	return *this;
}

void QUEUE::print() const {
	//s2.STACK::print();
	s2.print();
}

QUEUE::~QUEUE(){
}
