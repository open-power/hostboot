#ifndef __UTIL_LOCKFREE_STACK_H
#define __UTIL_LOCKFREE_STACK_H

#include <stddef.h>

namespace Util
{
    namespace Lockfree
    {
	template <typename _T>
	class Stack
	{
	    public:
		Stack() : head(NULL) {};
		
		_T* pop();
		void push(_T*);

	    private:
		_T* head;
	};

	template <typename _T>
	_T* Stack<_T>::pop()
	{
	    _T * h = head;
	    if (NULL == h) return h;
	    if (!__sync_bool_compare_and_swap(&head,
					      h,
					      h->next))
		return pop();
	    return h;
	}

	template <typename _T>
	void Stack<_T>::push(_T* p)
	{
	    p->next = head;
	    if (!__sync_bool_compare_and_swap(&head,
					      p->next,
					      p))
		push(p);
	}
    }
}

#endif
