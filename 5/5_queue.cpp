#include "5_queue.h"
#include <iostream>

QUEUE::QUEUE(int m): s1(m), s2(m){
}

QUEUE::QUEUE(const QUEUE& s): s1(s.s1), s2(s.s2){
}
QUEUE::operator int() const{
	return int(s1) + int(s2);
}

QUEUE& QUEUE::operator<<(int e){
	s1<<e;
	return *this;
}

QUEUE& QUEUE::operator>>(int &e){
	int i;
	int n = int(s1);
	int tmp = -1;

	if(n == 0){
		std::cout<<"queue is empty"<<std::endl;
		e = -1;
		return *this;
	}

	for(i=0; i<n; i++){
		s1>>tmp;
		s2<<tmp;
		//std::cout<<"loop1 "<<tmp<<std::endl;
	}

	s2>>e;

	for(i=0; i<n-1; i++){
		s2>>tmp;
		s1<<tmp;
		//std::cout<<"loop22 "<<tmp<<std::endl;
	}

	return *this;
}

QUEUE& QUEUE::operator=(const QUEUE& s){
	s1=s.s1;
	s2=s.s2;
	return *this;

}

void QUEUE::print() const{
	int n = int(s1); 

	if(n == 0){
		std::cout<<"queue is empty"<<std::endl;
		return ;
	}

	s1.print();
//	for(i=0; i<n; i++){
//		s1>>tmp;
//		s2<<tmp;
//	}
//	for(i=0; i<n; i++){
//		s2>>tmp;
//		std::cout<<"no.is " <<tmp<<std::endl;
//		s1<<tmp;
//	}

}

QUEUE::~QUEUE(){
}

