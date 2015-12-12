#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

using namespace std;

struct STACK{
	int *elems;//申请内存用于存放堆栈的元素
	int max;//栈能存放的最大个数
	int pos; //栈实际已有元素个数，栈为空时为0
};

void initSTACK(STACK * const p, int m){//initial the stack point to the p, max is m
	p->elems = (int *)malloc((m+1) * sizeof(m));
	if(p->elems == NULL){
		cout<< "没有足够内存"<<endl;
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
		cout<< "没有足够内存"<<endl;
		exit(1);
	}
	if(n == 0){// s为空
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
			cout << "没有初始化"<<endl;
			return p;
		}
		if(p->pos == p->max){
			cout<< "栈已经满了"<<endl;
			return p;
		}
		(p->elems)[p->pos] = e;
		p->pos += 1;
		return p;
}

STACK* const pop(STACK* const p, int &e){
		if(p == NULL){
			cout << "没有初始化"<<endl;
			return p;
		}
		if(p->pos == 0){
			cout<< "栈为空"<<endl;
			return p;
		}
		e = (p->elems)[p->pos-1];
		p->pos -= 1;
		return p;
}

void print(const STACK* const p){
	int i;
	if(p == NULL){
		cout<< "栈未初始化"<<endl;
	}else if(p->pos == 0){
		cout << "栈为空" <<endl;
	}else{
		for(i=p->pos; i>0; i--){
			cout<<i<<" 元素为："<<(p->elems)[i-1]<<endl;
		}
	}
}

void destorySTACK(STACK* const p){
	if(p == NULL){
		cout<< "栈已经销毁";
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
