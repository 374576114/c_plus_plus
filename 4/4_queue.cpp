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
		i = (i+1)%(max+1); //由于是循环队列,需要注意循环
	}
}

QUEUE::operator int() const {//先把一个循环队列便扩展成两个队列,然后
	return (tail-head+max+1)%(max+1);//再求头与尾的差值,最后再进行mod
}

QUEUE& QUEUE::operator<<(int e){
	int tmp;
	tmp = (tail+1)%(max+1);//当成功入队列后,tail的指向
	if(tmp == head){//先检测当入队列一个元素时,队列是否已经满了
		std::cout<<"queue is full"<<std::endl;
		return *this;
	}else{//队列没有满,那么进行如队列操作
		elems[tail] = e;
		tail = tmp;
		return *this;
	}
}

QUEUE& QUEUE::operator>>(int &e){
	if(head == tail){//队列头尾指向同一元素,说明队列是空的
		std::cout<<"queue is empty"<<std::endl;
		e = -1;
		return *this;
	}else{//出队列操作,先取出head处值,在对head进行加一操作,并注意需要mod
		e = elems[head];
		head = (head+1)%(max+1);
		return *this;
	}
}

QUEUE& QUEUE::operator=(const QUEUE &s){
	int i;
	
	if(this == &s)//是同一队列,不操作
	  return *this;

	*(int *)&max = s.max;
	head = s.head;
	tail = s.tail;

	delete[] elems;
	*(int **)&elems = new int[s.max+1];
	i = head;
	while(i!=tail){//从头指针开始赋值,直到指针(进行加一操作)移动到尾指针
		elems[i] = (s.elems)[i];
		i = (i+1)%(max+1);//循环,mod
	}

	return *this;
}

void QUEUE::print() const{
	int i=head;

	while(i!=tail){//从头指针开始打印,直到移动到尾指针处
		std::cout<<"index:"<<i<<" "<<elems[i]<<std::endl;
		i = (i+1)%(max+1);
	}
}

QUEUE::~QUEUE(){//释放申请的内存
	std::cout<<"destructor"<<std::endl;
	*(int *)&max = 0;
	head = 0;
	tail = 0;

	delete[] elems;
}
