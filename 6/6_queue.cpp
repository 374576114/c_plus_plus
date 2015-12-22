#include "6_queue.h"
#include <iostream>

QUEUE::QUEUE(int m):STACK(m), s2(m) {}//由于是继承,需要先初始化基类,在初始化本类
QUEUE::QUEUE(const QUEUE& s): STACK(s), s2(s.s2){}//中的元素

QUEUE::operator int() const{//用本类的s2存放队列元素,
	return int(s2);			//用基类的栈做缓冲
}

QUEUE& QUEUE::operator<<(int e){//由于用s2存放队列元素,那么进队列
	int n = int(s2);			//就直接用压栈

	if(n == STACK::size() ){
		std::cout<<"FULL"<<std::endl;
		return *this;
	}
	s2<<e;
	return *this;
}

QUEUE& QUEUE::operator>>(int &e){
	int i;
	int n = int(s2);
	int tmp;
	
	if(n == 0){//队列空
		std::cout<<"EMPTY\n"<<std::endl;
		return *this;
	}
//用本类的s2存放队列元素,用基类的栈来做缓冲,完成出队列操作
//思路按实验五的
	for(i=0; i<n; i++){
		s2>>tmp;//将s2中所有元素出栈并压入基类栈中
		STACK::operator<<(tmp);
	}

	STACK::operator>>(e);//取出基类栈顶元素,即是队列首元素

	for(i=0; i<n-1; i++){//将基类栈中剩余的元素都出栈并压入s2中
		STACK::operator>>(tmp);
		s2<<tmp;
	}

	return *this;
}

QUEUE& QUEUE::operator=(const QUEUE& s){//将两个栈都完成赋值操作
	STACK::operator=(s);	
	s2 = s.s2;
	return *this;
}

void QUEUE::print() const {//由于是将元素存在s2中,直接调用栈的print即可
	s2.print();
}

QUEUE::~QUEUE(){//由于没用动态申请内存,只有局部变量,则不需要进行delete操作
	std::cout<<"destructor"<<std::endl;//由于基类的析构函数有virtual修饰
}						//则基类能够先执行相应的析构函数,然后在调用本类的
						//析构函数
