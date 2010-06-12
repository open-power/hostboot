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

	template<bool _locked, typename _T>
	class LockHelper
	{
	    public:
		inline LockHelper(_T& i) : l(i) {};
		inline void lock() { l.lock(); };
		inline void unlock() { l.unlock(); };
	    private:
		_T& l;
	};

	template<typename _T>
	class LockHelper<false,_T>
	{
	    public:
		inline LockHelper(_T&i) {};
		inline void lock() {};
		inline void unlock() {};
	};
    };
};

#endif
