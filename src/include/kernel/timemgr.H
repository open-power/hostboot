#ifndef __KERNEL_TIMEMGR_H
#define __KERNEL_TIMEMGR_H

#include <kernel/types.h>

class TimeManager
{
    public:
	static void init();
	static uint64_t getTimeSliceCount()
	    {
		return iv_timeSlice;
	    };

    protected:
	TimeManager() {};
	~TimeManager() {};

    private:
	void _init();


	static uint64_t iv_timeSlice;
};

#endif
