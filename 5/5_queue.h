#ifndef _5_QUEUE_H_
#define _5_QUEUE_H_

#include "3_stack.h"

class QUEUE{
	STACK s1, s2;
	
	public :
		QUEUE(int m);
		QUEUE(const QUEUE& s);
		virtual operator int () const ;
		virtual QUEUE& operator<<(int e);
		virtual QUEUE& operator>>(int &e);
		virtual QUEUE& operator=(const QUEUE &s);
		virtual void print() const;
		virtual ~QUEUE();
};


#endif
