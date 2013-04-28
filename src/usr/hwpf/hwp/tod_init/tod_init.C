/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/tod_init.C $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/**
 *  @file tod_init.C
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include "TodTrace.H"
#include "tod_init.H"
#include "TodSvc.H"

namespace   TOD
{

const char TOD_TRACE_NAME[] = "TOD";
trace_desc_t* g_trac_tod = NULL;
TRAC_INIT(&g_trac_tod, TOD_TRACE_NAME, KILOBYTE, TRACE::BUFFER_SLOW);

static bool is_spless()
{
    bool spless = true;
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    TARGETING::SpFunctions spfuncs;
    if( sys &&
        sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfuncs) &&
        spfuncs.mailboxEnabled )
    {
        spless = false;
    }

    return spless;
}

void * call_tod_setup(void *dummy)
{
    errlHndl_t l_errl;

    if (is_spless())
    {
        l_errl = TodSvc::getTheInstance().todSetup();

        if (l_errl)
        {
            TOD_ERR("todSetup() return errl handle %p", l_errl);
            errlCommit( l_errl, TOD_COMP_ID );
        }
    }

    return NULL;
}

void * call_tod_init(void *dummy)
{
    errlHndl_t l_errl;

    if (is_spless())
    {
        l_errl = TodSvc::getTheInstance().todInit();

        if (l_errl)
        {
            TOD_ERR("todInit() return errl handle %p", l_errl);
            errlCommit( l_errl, TOD_COMP_ID );
        }
    }

    return NULL;
}

};   // end namespace
