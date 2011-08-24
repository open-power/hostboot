//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pnor/fakeext/fakeext.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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

