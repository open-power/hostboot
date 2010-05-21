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
	    _T * _head = head;
	    _T * h = (_T*) (((uint64_t)_head) & 0x00000000FFFFFFFF);
	    if (NULL == h) return h;	    
	    uint64_t token = ((uint64_t)_head) >> 32;
	    token++;
	    _T * h_next = (_T*) (((uint64_t)(h->next)) | (token << 32));
	    if (!__sync_bool_compare_and_swap(&head,
					      _head,
					      h_next))
		return pop();
	    return h;
	}

	template <typename _T>
	void Stack<_T>::push(_T* p)
	{
	    _T* _head = head;
	    p->next = (_T*) (((uint64_t)_head) & 0x00000000FFFFFFFF);
	    uint64_t token = ((uint64_t)_head) >> 32;
	    token++;

	    _T* _p = (_T*) (((uint64_t)p) | (token << 32));
	    	    
	    if (!__sync_bool_compare_and_swap(&head,
					      _head,
					      _p))
		push(p);
	}
    }
}

#endif
