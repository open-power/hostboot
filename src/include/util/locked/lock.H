//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/util/locked/lock.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
