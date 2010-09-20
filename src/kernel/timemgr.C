#include <kernel/timemgr.H>
#include <util/singleton.H>

uint64_t TimeManager::iv_timeSlice = 0xFFFFFFFF;

void TimeManager::init()
{
    Singleton<TimeManager>::instance()._init();
}

void TimeManager::_init()
{
    /*              TB freq  /  Timeslice per Sec */
    iv_timeSlice = 512000000 / 1000;
}
