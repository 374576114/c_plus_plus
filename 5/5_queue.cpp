#include "5_queue.h"
#include <iostream>

QUEUE::QUEUE(int m): s1(m), s2(m){
}

QUEUE::QUEUE(const QUEUE& s): s1(s.s1), s2(s.s2){
}
QUEUE::operator int() const{//将s1用作存储,而将s2当作缓冲
	return int(s1);			//所以只需要返回s1的大小
}

QUEUE& QUEUE::operator<<(int e){//入队列,操作同入栈一样
	int n = int(s1);
	if(n == s1.size()){
		std::cout<<"队列满了"<<std::endl;
		return *this;
	}
	s1<<e;
	return *this;
}

QUEUE& QUEUE::operator>>(int &e){
	int i;
	int n = int(s1);//栈的大小即队列的大小
	int tmp = -1;

	if(n == 0){//当栈为空时,说明队列也就是空的
		std::cout<<"queue is empty"<<std::endl;
		e = -1;
		return *this;
	}

//  对于出队列,由于队列首元素在栈的底部,在出队列时需要
//先将此元素取出,那么,将需要将栈s1中的元素都出栈然后进
//栈入到s2中,那么此时s2的出栈顺序便是队列需要的出队列顺序
//
//  所以此时将s2的栈顶元素取出即可,然后将s2中剩余的元素再
//重新压入栈s1,完成出队列操作

	for(i=0; i<n; i++){
		s1>>tmp;//将s1元素都压入到s2中
		s2<<tmp;
	}

	s2>>e;//取出s2的栈顶元素

	for(i=0; i<n-1; i++){//将s2剩余的元素压入s1中
		s2>>tmp;
		s1<<tmp;
	}

	return *this;
}

QUEUE& QUEUE::operator=(const QUEUE& s){//将s1, s2 都进行栈赋值
	s1=s.s1;
	s2=s.s2;
	return *this;

}

void QUEUE::print() const{//调用栈的打印函数即可
	int n = int(s1); 

	if(n == 0){
		std::cout<<"queue is empty"<<std::endl;
		return ;
	}

	s1.print();
}

QUEUE::~QUEUE(){//由于没有动态申请内存,则不需要用delete操作
	std::cout<<"destructor"<<std::endl;
}

