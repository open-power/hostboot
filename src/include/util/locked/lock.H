#ifndef __UTIL_LOCKED_LOCK_H
#define __UTIL_LOCKED_LOCK_H

namespace Util
{
    namespace Locked
    {
	class Lock
	{
	    public:
		Lock() {};
		virtual ~Lock() {};
		
		virtual void lock() = 0;
		virtual void unlock() = 0;
	};
    };
};

#endif
