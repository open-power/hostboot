#ifndef __UTIL_SINGLETON_H
#define __UTIL_SINGLETON_H

template <typename _T>
class Singleton : private _T
{
    public:
	static _T& instance()
	    {
		static Singleton<_T> instance;
		return instance;
	    };

    private:
	Singleton() : _T() {};
};

#endif
