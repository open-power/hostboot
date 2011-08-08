
#include <trace/interface.H>
#include <initservice/taskargs.H> 


// Trace definition
trace_desc_t* g_trac_fakeext = NULL;
TRAC_INIT(&g_trac_fakeext, "FAKE_EXT", 4096); //4k


/**
 * @brief Fake EXT test function 1
 *
 * @return  void
 */
void fakeExtTest1(void* i_taskArgs )
{
    TRACFCOMP(g_trac_fakeext, "fakeExtTest1 called " );
//    INITSERVICE::TaskArgs::TaskArgs* args = (INITSERVICE::TaskArgs::TaskArgs*)i_taskArgs;

    return;
}


/**
 * @brief   set up _start() task
 */
TASK_ENTRY_MACRO( fakeExtTest1 );



/**
 * @brief Fake EXT test function 2
 *
 * @return  void
 */
void fakeExtTest2()
{
    TRACFCOMP(g_trac_fakeext, "fakeExtTest2 called " );

    return;
}

