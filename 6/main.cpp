#include <iostream>
#include "6_queue.h"

using namespace std;

int main(){
	int tmp = -1;
	int i;

	QUEUE q(10);
	for(i=0; i<12; i++)
	  q<<i;
//	for(i=0; i<12; i++){
//		q>>tmp;
//		cout<<"*** "<< tmp<<endl;
//	}

	//q>>tmp;
	//cout<< int(q)<<endl;
	QUEUE q1(2);
	q1<<12;
	q1<<32;
	q1.print();
	q1 = q;
	q1.print();
	return 0;
}
