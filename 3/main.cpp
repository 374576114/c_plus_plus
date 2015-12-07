#include "3_stack.h"
#include <iostream>

using namespace std;

int main(){
	STACK s1(10);
	
	int i;
	STACK *p;
	p = new STACK(10);
	cout<<p->size()<<endl;
	p->print();
	delete p;
	//for(i=0; i<12; i++)
	//  s1<<i;
	//s1>>i;
	//std::cout<<"  ```"<<i<<std::endl;
	//STACK s2(s1);
	//s2.print();
	//s1.print();
	//cout<<s1[13]<<endl;
	//cout<<int(s1)<<endl;
	//cout<<s1.size()<<endl;
	//s1.print();
}
