#include "1_stack.h"
#include <stdio.h>
using namespace std;

void menu(){
	cout<<"    欢迎使用"<<endl;
	cout<<"1 initSTACK by m:"<<endl;
	cout<<"2 initSTACK by STACK"<<endl;
	cout<<"3 size      4 howMany"<<endl;
	cout<<"5 getelem   6 push"<<endl;
	cout<<"7 pop       8 print"<<endl;
	cout<<"9 assign    0 quit"<<endl;
	cout<<"10 destorySTACK"<<endl;
	cout<<"请输入选项:"<<endl;
}

int stack(){
	int choice=-1;
	int m;
	STACK s, p;
	s.elems = NULL;
	initSTACK(&s, 5);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	
	while(choice){
		menu();
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"input the m:";
				cin>>m;
				initSTACK(&p, m);
				break;
			case 2:
				cout<<"use default stack to init"<<endl;
				cout<<"this stack has 5 elems 1,2,3,4,5"<<endl;
				initSTACK(&p, s);
				break;
			case 3:
				cout<<"size :"<<size(&p)<<endl;
				break;
			case 4:
				cout<<"howMany: "<<howMany(&p)<<endl;
				break;
			case 5:
				cout<<"input the number you want to get"<<endl;
				cin>>m;
				cout<<"  " << getelem(&p, m)<<endl;
				break;
			case 6:
				cout<<"input the number you want to push"<<endl;
				cin>>m;
				push(&p, m);
				break;
			case 7:
				m = -1;
				pop(&p, m);
				cout<<"the pop is :"<<m<<endl;
				break;
			case 8:
				cout<<"print  :" <<endl;
				print(&p);
				break;
			case 9:
				cout<<"assign"<<endl;
				assign(&p, s);
				break;
			case 10:
				cout<<"destory"<<endl;
				destorySTACK(&p);
				break;
			default:
				choice = 0;
		}
		getchar(); getchar();
	}
}

int main(){
	stack();
	return 0;
}
