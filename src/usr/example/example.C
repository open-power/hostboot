//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/example/example.C $
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
#include <kernel/console.H>
#include <sys/sync.h>
#include <sys/vfs.h>
#include <sys/task.h>
#include <trace/interface.H>
#include <example/example.H>
#include <example/examplerc.H>
#include <errl/errlentry.H>

#if 0
//static mutex_t value = MUTEX_INITIALIZER;
trace_desc_t *g_trac_test = NULL;
TRAC_INIT(&g_trac_test, "EXAMPLE", 4096);
#endif

extern "C"
void _start(void *ptr)
{
    /**
     * @todo    fix printk to accept (NULL)
     */
    printk( "Executing Example module, arg=%s\n", ( (ptr==NULL) ? "(NULL)" : (char*)ptr ) );

    task_end();
}

uint64_t example1_function()
{
    uint64_t    l_rc = 0;

    //TRACFCOMP(g_trac_test, "Someone Called example1_function!");

    return l_rc;
}

// This example shows how to create an error log with passed-in
// defined parameters
void example2_create_errorlog_function()
{
    /*@
     * @errortype
     * @moduleid     MY_MODULE_ID_1
     * @reasoncode   MY_REASON_CODE_1
     * @userdata1    Meaning of userdata1 value
     * @userdata2    Meaning of userdata2 value
     * @devdesc      Example of creating an error log
     */
    errlHndl_t l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                        MY_MODULE_ID_1,
                        MY_REASON_CODE_1,
                        0x8000000000000001,
                        0x9000000000000003);
    delete l_err;
    l_err = NULL;
    return;
}
