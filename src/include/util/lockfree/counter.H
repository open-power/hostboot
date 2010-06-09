#ifndef __UTIL_LOCKFREE_COUNTER_H
#define __UTIL_LOCKFREE_COUNTER_H

namespace Util
{
    namespace Lockfree
    {
	template <typename _T>
	class Counter
	{
	    public:
		Counter() : value(_T()) {};

		_T next() { return __sync_fetch_and_add(&value, 1); };

	    private:
		_T value;
	};
    };
};


#endif
