#include "4_queue.h"
#include <iostream>

QUEUE::QUEUE(int m):max(m), elems(new int[m + 1 ]){
	head = 0;
	tail = 0;
}

QUEUE::QUEUE(const QUEUE& s):max(s.max), elems(new int[s.max + 1]){
	head = s.head;
	tail = s.tail;
	int i=head;
	
	while(i!=tail){
		elems[i] = (s.elems)[i];
		i = (i+1)%(max+1);
	}
}

QUEUE::operator int() const {
	return (tail-head+max+1)%(max+1);
}

QUEUE& QUEUE::operator<<(int e){
	int tmp;
	tmp = (tail+1)%(max+1);
	if(tmp == head){
		std::cout<<"queue is full"<<std::endl;
		return *this;
	}else{
		elems[tail] = e;
		tail = tmp;
		return *this;
	}
}

QUEUE& QUEUE::operator>>(int &e){
	if(head == tail){
		std::cout<<"queue is empty"<<std::endl;
		return *this;
	}else{
		e = elems[head];
		head = (head+1)%(max+1);
		return *this;
	}
}

QUEUE& QUEUE::operator=(const QUEUE &s){
	int i;
	
	if(this == &s)
	  return *this;

	*(int *)&max = s.max;
	head = s.head;
	tail = s.tail;

	delete[] elems;
	*(int **)&elems = new int[s.max+1];
	i = head;
	while(i!=tail){
		elems[i] = (s.elems)[i];
		i = (i+1)%(max+1);
	}

	return *this;
}

void QUEUE::print() const{
	int i=head;

	while(i!=tail){
		std::cout<<"index:"<<i<<" "<<elems[i]<<std::endl;
		i = (i+1)%(max+1);
	}
}

QUEUE::~QUEUE(){
	*(int *)&max = 0;
	head = 0;
	tail = 0;

	delete[] elems;
}
