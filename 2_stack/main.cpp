#include "stack_2.h"

using namespace std;

int main(){
	STACK s1(10);
	STACK s2(s1);
	//s2 = s1;
	int i, a;
	for(i=0; i<12; i++){
		s1.push(i);
	}
	//s1.print();
	cout<<s1.getElem(100)<<"  "<<s1.getElem(9)<<endl<<"how:"<<s1.howMany();
	s2.assign(s1);
	//s2.print();
	for(i=0; i<12; i++){
		s2.pop(a);
	}
	s2.print();
	return 0;
}

