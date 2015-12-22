#include <iostream>
#include "5_queue.h"
#include <stdio.h>

using namespace std;

void menu(){
	cout<<"\t     实验五"<<endl;
	cout<<"\t1 init by m"<<endl;
	cout<<"\t2 init by QUEUE s"<<endl;
	cout<<"\t3 int()   4 <<"<<endl;
	cout<<"\t5 >>      6 ="<<endl;
	cout<<"\t7 print   0 quit"<<endl;
	cout<<"请输入选项:"<<endl;
}

int test(QUEUE *p){//对指针进行检测
	if(p == 0){
		cout<<"未初始化"<<endl;
		return 0;
	}else
	  return 1;
}

void queue(){
	int choice=-1;
	int m;
	QUEUE s(5);
	QUEUE *p = 0;
	for(m=0; m<5; m++)
	  s<<(m+1);
	
	while(choice){
		menu();
		cin>>choice;

		switch(choice){
			case 1:
				if(p == 0){
					cout<<"please input the m"<<endl;
					cin>>m;
					p = new QUEUE(m);
				}else
				  cout<<"已经初始化"<<endl;
				break;
			case 2:
				if(p == 0){
					cout<<"use the default queue to init"<<endl;
					cout<<"this queue has 5 elems 1,2,3,4,5"<<endl;
					p = new QUEUE(s);
				}else
				  cout<<"已经初始化"<<endl;
				break;
			case 3:
				if(test( p))
					cout<<"numbers of elems : "<<int (*p) <<endl;
				break;
			case 4:
				if(test(p)){
					cout<<"please input the number you want to <<"<<endl;
					cin>>m;
					(*p)<<m;
				}
				break;
			case 5:
				if(test(p)){
					m = -1;
					(*p)>>m;
					cout<<">> "<<m<<endl;
				}
				break;
			case 6:
				if(test(p)){
					cout<<" = use the default queue(1,2,3,4,5,6)"<<endl;
					(*p) = s;
				}
				break;
			case 7:
				if(test(p))
				  p->print();
				break;
			default:
				choice = 0;
		}
		getchar(); getchar();
	}
	delete p;
}

int main(){
	queue();

	return 0;
}

