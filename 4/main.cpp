#include "4_queue.h"
#include <iostream>

int main(){
	QUEUE q1(10);
	QUEUE q(1);
	
	int i;
	for(i=0; i<12; i++){
		q1<<i;
	}
	q1.print();

	QUEUE *p ;
	p = new QUEUE(20);
	delete p;
	//for(i=0; i<12; i++){
		//q1>>i;
	//}
	//std::cout<<int(q1)<<std::endl;
	//q = q1;
	//q.print();
	//QUEUE q2(q1);
	//q2.print();
	return 0;
}

