#include "6_queue.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int m, n;
	int pm, pf;
	int i=0;
	cout<<"please input the number man & woman"<<endl;
	cin>>m>>n;
	QUEUE qm(m);
	QUEUE qw(n);

	for(int i=0; i<m; i++)
	  qm<<i+1;
	for(int i=0; i<n; i++)
	  qw<<i+1;

	while(1){
		cout<<"please input the m & f"<<endl;
		cin>>pm>>pf;
		if(pm<=m && pf<=n)
		  break;
		cout<<"input error"<<endl;
	}

	while(1){
		i++;
		qm>>m;
		qw>>n;
		if(m == pm && n == pf){
			cout<<" success "<<i<<endl;
			break;
		}
		qm<<m;
		qw<<n;
	}

	return 0;
}


