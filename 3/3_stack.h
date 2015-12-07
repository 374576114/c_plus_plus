#ifndef _3_STACK_H_
#define _3_STACK_H_
//试验三
class STACK{
	private :
		int *const elems;
		const int max;
		int pos;

	public :
		STACK(int m);
		STACK(const STACK &s);
		virtual int size() const;
		virtual operator int () const;
		virtual int operator[](int x) const;
		virtual STACK& operator<<(int e);
		virtual STACK& operator>>(int &e);
		virtual STACK& operator=(const STACK &s);
		virtual void print() const;
		virtual ~STACK();
};
#endif
