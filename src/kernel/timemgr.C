#include <kernel/timemgr.H>
#include <kernel/scheduler.H>
#include <util/singleton.H>

uint64_t TimeManager::iv_timebaseFreq = 0xFFFFFFFF;

void TimeManager::init()
{
    Singleton<TimeManager>::instance()._init();
}

void TimeManager::_init()
{
    iv_timebaseFreq = 512000000ULL;
}

uint64_t TimeManager::convertSecToTicks(uint64_t i_sec, uint64_t i_nsec)
{
    // This code will handle times almost up to a year without overflowing a
    // uint64.  This should be more than sufficient for our purposes.
    
    // Result = ((sec * 10^9 + nsec) * tb) / 10^9.
    uint64_t result = ((i_sec * 1000000000ULL) + i_nsec);
    result *= (iv_timebaseFreq / 1000000);
    result /= 1000;
    return result;
}

void TimeManager::delayTask(task_t* t, uint64_t i_sec, uint64_t i_nsec)
{
    Singleton<TimeManager>::instance()._delayTask(t,i_sec,i_nsec);
}

void TimeManager::_delayTask(task_t* t, uint64_t i_sec, uint64_t i_nsec)
{
    _TimeManager_Delay_t* node = new _TimeManager_Delay_t();

    node->key = this->getCurrentTimeBase() + 
		this->convertSecToTicks(i_sec, i_nsec);
    node->task = t;

    iv_taskList.insert(node);
}

void TimeManager::checkReleaseTasks(Scheduler* s)
{
    Singleton<TimeManager>::instance()._checkReleaseTasks(s);
}

void TimeManager::_checkReleaseTasks(Scheduler* s)
{
    uint64_t l_currentTime = getCurrentTimeBase();
    _TimeManager_Delay_t* node = NULL;

    while(NULL != (node = iv_taskList.remove_if(l_currentTime)))
    {
	s->addTask(node->task);
	delete node;
    }
}
