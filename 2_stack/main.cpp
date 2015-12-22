#include "stack_2.h"
#include <stdio.h>

using namespace std;

void menu(){
	cout<<"\t   实验二"<<endl;
	cout<<"\t1 init by m"<<endl;
	cout<<"\t2 init by STACK"<<endl;
	cout<<"\t3 size     4 howMany"<<endl;
	cout<<"\t5 getelem  6 push"<<endl;
	cout<<"\t7 pop      8 assign"<<endl;
	cout<<"\t9 print    0 quit"<<endl;
	cout<<"请输入选项"<<endl;
}

int test(STACK *p){
	if(p == NULL){
		cout<<"没有初始化"<<endl;
		return 0;
	}else
	  return 1;
}

int stack(){
	int choice=-1;
	int m;
	STACK s(5);
	STACK *p = NULL;
	for(m=0; m<5; m++)
	  s.push(m+1);

	while(choice){
		menu();
		cin>>choice;
		switch(choice){
			case 1:
				if(p == 0){
					cout<<"input the m ";
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
				  cout<<"howMany: "<<p->howMany()<<endl;
				break;
			case 5:
				if(test(p)){
					cout<<"input the number you want get :";
					cin>>m;
					cout<<" "<<p->getElem(m);
				}
				break;
			case 6:
				if(test(p)){
					cout<<"input the number you want to push"<<endl;
					cin>>m;
					p->push(m);
				}
				break;
			case 7:
				if(test(p)){
					m = -1;
					p->pop(m);
					cout<<"the pop is: "<<m;
				}
				break;
			case 8:
				if(test(p)){
					cout<<"assign (use default stack 1,2,3,4,5)"<<endl;
					p->assign(s);
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
		getchar(); getchar();
	}
	if(p != 0)
	  delete p;
}

int main(){
	stack();
	return 0;
}
