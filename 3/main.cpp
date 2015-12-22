#include "3_stack.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void menu(){
	cout<<"\t实验三"<<endl;
	cout<<"\t1 init by m"<<endl;
	cout<<"\t2 init by STACK s"<<endl;
	cout<<"\t3 size   4 int()"<<endl;
	cout<<"\t5 []     6 <<(push)"<<endl;
	cout<<"\t7 >>(pop)8 ="<<endl;
	cout<<"\t9 pinrt  0 quit"<<endl; 
	cout<<"请输入选项"<<endl;
}
//检测p是否为空
int test(STACK *p){
	if(p == 0){
		cout<<"栈未初始化"<<endl;
		return 0;
	}else
	  return 1;
}

int stack(){
	STACK s(5);
	STACK *p = 0;
	int choice=-1, m=0;

	for(; m<5; m++)
		s<<(m+1);
	
	while(choice){
		menu();
		cin>>choice;

		switch(choice){
			case 1:
				if(p == 0){
					cout<<"input the m"<<endl;
					cin>>m;
					p = new STACK(m);
				}else
				  cout<<"已经初始化";
				break;
			case 2:
				if(p == 0){
					cout<<"use default stack to init"<<endl;
					cout<<"this stack has 5 elems 1,2,3,4,5"<<endl;
					p = new STACK(s);
				}else
				  cout<<"已经初始化";
				break;
			case 3:
				if(test(p))
					cout<<"size: "<<p->size()<<endl;
				break;
			case 4:
				if(test(p))
				  cout<<"numbers of elems :"<<int (*p)<<endl;
				break;
			case 5:
				if(test(p)){
					cout<<"input the index you want :"<<endl;
					cin>>m;
					cout<<"  "<<(*p)[m];
				}
				break;
			case 6:
				if(test(p)){
					cout<<"input the number you want to push"<<endl;
					cin>>m;
					(*p)<<m;
				}
				break;
			case 7:
				if(test(p)){
					m = -1;
					(*p)>>m;
					cout<<">> "<<m;
				}
				break;
			case 8:
				if(test(p)){
					cout<<" =  (use default stack 1,2,3,4,5)"<<endl;
					(*p) = s;
				}
				break;
			case 9:
				if(test(p)){
					p->print();
				}
				break;
			default:
				choice = 0;
		}
		getchar();
		getchar();
	}
	delete p;
}

int main(){
	stack();

	return 0;
}
