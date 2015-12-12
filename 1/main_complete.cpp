#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

using namespace std;

struct STACK{
	int *elems;//�����ڴ����ڴ�Ŷ�ջ��Ԫ��
	int max;//ջ�ܴ�ŵ�������
	int pos; //ջʵ������Ԫ�ظ�����ջΪ��ʱΪ0
};

void initSTACK(STACK * const p, int m){//initial the stack point to the p, max is m
	p->elems = (int *)malloc((m+1) * sizeof(m));
	if(p->elems == NULL){
		cout<< "û���㹻�ڴ�"<<endl;
		exit(1);
	}
	p->max = m;
	p->pos = 0;
}

void initSTACK(STACK *const p, const STACK &s){//initial p by s
	int n, i;
	n = s.pos;//s stack position
	
	p->elems = (int *)malloc((s.max+1) * sizeof(int));
	p->max = s.max;
	
	if(p->elems == NULL){
		cout<< "û���㹻�ڴ�"<<endl;
		exit(1);
	}
	if(n == 0){// sΪ��
		p->pos = 0;
	}else{
		for(i=0; i<n; i++){
			(p->elems)[i] = (s.elems)[i];
		}
		p->pos = s.pos;
	}
}

int size(const STACK* p ){// return the size of stack p
		if(p)
			return p->max;
		else
			return -1;	//stack do not initial
}

int homMany(const STACK* const p){//return the top of stack p
		if(p)
			return p->pos;
		else	//stack do not initial
			return -1;
}

int getelem(const STACK* const p, int x){ //get the x postion of stack element
	if(p == NULL)
		return  -1;
	if(x-1 > p->pos)
		return  -2;
	return (p->elems)[x-1];
}

STACK* const push(STACK* const p, int e){ // push e into stack p
		if(p == NULL){
			cout << "û�г�ʼ��"<<endl;
			return p;
		}
		if(p->pos == p->max){
			cout<< "ջ�Ѿ�����"<<endl;
			return p;
		}
		(p->elems)[p->pos] = e;
		p->pos += 1;
		return p;
}

STACK* const pop(STACK* const p, int &e){
		if(p == NULL){
			cout << "û�г�ʼ��"<<endl;
			return p;
		}
		if(p->pos == 0){
			cout<< "ջΪ��"<<endl;
			return p;
		}
		e = (p->elems)[p->pos-1];
		p->pos -= 1;
		return p;
}

void print(const STACK* const p){
	int i;
	if(p == NULL){
		cout<< "ջδ��ʼ��"<<endl;
	}else if(p->pos == 0){
		cout << "ջΪ��" <<endl;
	}else{
		for(i=p->pos; i>0; i--){
			cout<<i<<" Ԫ��Ϊ��"<<(p->elems)[i-1]<<endl;
		}
	}
}

void destorySTACK(STACK* const p){
	if(p == NULL){
		cout<< "ջ�Ѿ�����";
	}
	else{
		free(p->elems);
                p->max = 0;
                p->pos = 0;
	}
}
STACK* const assign(STACK* const p, const STACK &s){
        if(p == NULL){
                initSTACK(p, s);
        }else{
                destorySTACK(p);
                initSTACK(p, s);
        }
        return p;
}
int main(){
        int i, j;
        STACK s, p;
        initSTACK(&s, 5);
        initSTACK(&p, 10);
        for(i=0; i<5; i++)
                push(&s, i);
        for(j=0; j<10; j++)
                push(&p, j);

        print(&s);
        cout<<endl;
        print(&p);

        assign(&s, p);
        print(&s);
        return 0;
}
