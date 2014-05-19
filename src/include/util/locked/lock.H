/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/locked/lock.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
