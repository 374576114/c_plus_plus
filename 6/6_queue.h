#ifndef _6_QUEUE_H_
#define _6_QUEUE_H_

#include "3_stack.h"

class QUEUE: public STACK{
	private :
		STACK s2;
	public :
		QUEUE(int m);
		QUEUE(const QUEUE& s);
		operator int() const;
		QUEUE& operator<<(int e);
		QUEUE& operator>>(int &e);
		QUEUE& operator=(const QUEUE& s);
		void print() const;
		~QUEUE();
};

#endif
