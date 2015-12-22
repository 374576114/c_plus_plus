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
	QUEUE qm(m);//申请两个队列,分别放男士跟女生
	QUEUE qw(n);

	for(int i=0; i<m; i++)//将舞者进行编号,从1开始编起
	  qm<<i+1;
	for(int i=0; i<n; i++)
	  qw<<i+1;

	while(1){
		cout<<"please input the m & f"<<endl;//输入想要一起跳舞的编号,且都是素数
		cin>>pm>>pf;
		if(pm<=m && pf<=n)//如果输入编号正确,则重新输入
		  break;
		cout<<"input error"<<endl;
	}

	while(1){
		i++;//舞曲增加
		qm>>m;//男士出队列
		qw>>n;//女士出队列
		if(m == pm && n == pf){//判断是不是想要一起跳舞的
			cout<<"\t *******"<<endl;
			cout<<"\t 第 "<<i<<" 支"<<endl;
			cout<<"\t *******"<<endl;
			break;
		}
		if(m == 1 && n == 1 && i>1){//舞伴又重新回到初始状态,说明输入有误,
			cout<<"\t************************"<<endl;//不会找到匹配
			cout<<"\t输入数据有误,没法找到匹配"<<endl;
			cout<<"\t************************"<<endl;
			break;
		}
		qm<<m;//男士继续回队列尾
		qw<<n;//女士也回队列尾部
	}

	cout<<"--------------"<<endl;
	return 0;
}


