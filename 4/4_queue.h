#ifndef _4_QUEUE_H_
#define _4_QUEUE_H_
//试验4
class QUEUE{
	private :
		int *const elems;
		const int max;
		int head, tail;
	
	public :
		QUEUE(int m);
		QUEUE(const QUEUE& s);
		virtual operator int() const;
		virtual QUEUE& operator<<(int e) ;
		virtual QUEUE& operator>>(int &e) ;
		virtual QUEUE& operator=(const QUEUE &s);
		virtual void print() const;
		virtual ~QUEUE();
};
#endif
