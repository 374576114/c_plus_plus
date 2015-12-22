#ifndef _1_STACK_H_
#define _1_STACK_H_

#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct STACK{
	int *elems;//申请内存用于存放堆栈的元素
	int max;//栈能存放的最大个数
	int pos; //栈实际已有元素个数，栈为空时为0
};
// 1_stack.cpp
void initSTACK(STACK* const p, int m);
void initSTACK(STACK* const p, const STACK& s);
int size(const STACK* p);
int howMany(const STACK* const p);
int getelem(const STACK* const p, int x);
STACK* const push(STACK* const p, int e);
STACK* const pop(STACK* const p, int &e);
void print(const STACK* const p);
void destorySTACK(STACK* const p);
STACK* const assign(STACK* const p, const STACK &s);
// main.cpp
void menu();
#endif
