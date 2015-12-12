#include <iostream>
#include "5_queue.h"
#include <stdio.h>
using namespace std;
int main(){
	QUEUE q(10);
	QUEUE qtt(2);
	int tmp;
	qtt.:
	int i;
	for(i=0; i<12; i++){
		q<<i*2;
	}
	cout<< "start"<<endl;
	q.print();
	cout<< ">> 3 operation"<<endl;
	q>>tmp;
//	cout<<" "<<tmp<<endl;
	q>>tmp;
//	cout<<" "<<tmp<<endl;
	q>>tmp;
//	cout<<" "<<tmp<<endl;
	q.print();
//	cout<<" qt"<<endl;
//	QUEUE qt(q);
//	qt.print();
//	cout<<" qtt"<<endl;
//	qtt = qt;
//	qtt.print();
	return 0;
}
