/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/establish_system_smp/establish_system_smp.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
 *  @file establish_system_smp.C
 *
 *  Support file for IStep: establish_system_smp
 *   Establish System SMP
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1611
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>

#include    <hwpisteperror.H>

#include    <istep_mbox_msgs.H>

//  targeting support
#include    <targeting/common/commontargeting.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    "establish_system_smp.H"

//  Uncomment these files as they become available:
// #include    "host_coalesce_host/host_coalesce_host.H"

namespace   ESTABLISH_SYSTEM_SMP
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;
using   namespace   fapi;


//
//  Wrapper function to call host_coalesce_host
//
void*    call_host_coalesce_host( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_coalesce_host entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  write HUID of target
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l));

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target( TARGET_TYPE_MEMBUF_CHIP,
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, host_coalesce_host, _args_...);
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : .........." );
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : .........." );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_coalesce_host exit" );

    // end task, returning any errorlogs to IStepDisp 
    return l_errl;
}

//******************************************************************************
// host_sys_fab_iovalid_processing function
//******************************************************************************
void host_sys_fab_iovalid_processing( msg_t* io_pMsg )
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "host_sys_fab_iovalid_processing entry" );

    iovalid_msg * drawerData = NULL;

    uint16_t count = 0;

    std::vector<TARGETING::EntityPath> present_drawers;

    errlHndl_t l_errl = NULL;

    // if there is extra data, start processing it
    // else send back a msg to indicate invalid msg
    if(io_pMsg->extra_data)
    {
        drawerData = (iovalid_msg *)io_pMsg->extra_data;

        // setup a pointer to the first drawer entry in our data
        TARGETING::EntityPath * ptr = drawerData->drawers;


        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,"Master node %s "
                                                      "List size = %d bytes "
                                                      "Drawer count = %d",
                ptr->toString(), drawerData->size, drawerData->count);

        count = drawerData->count;

        // create a vector with the present drawers
        for(uint8_t i = 0; i < count; i++)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "list entry[%d] - %s", i, ptr->toString());

            present_drawers.push_back(*ptr);
            ptr++;
        }

        // $TODO RTC:63128 - exchange between present drawers to agree
        // on valid endpoints
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "$TODO RTC:63128 - hb instances exchange and agree on cfg");

        // $TODO RTC:63132 after agreement, open abuses as required
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "$TODO RTC:63132 - open the required A-busses "
                  " after agreement is reached");

        // release the storage from the message
        free(io_pMsg->extra_data);
        io_pMsg->extra_data = NULL;

        io_pMsg->data[0] = INITSERVICE::HWSVR_MSG_SUCCESS;
    }
    else
    {
        // message needs to have at least one entry
        // in the drawer list, else we will say invalid msg
        io_pMsg->data[0] = INITSERVICE::HWSVR_INVALID_MESSAGE;
    }

    io_pMsg->data[1] = 0;

    // if there is an error log add the ID to
    // data 0
    if(l_errl)
    {
        io_pMsg->data[0] = l_errl->eid();
        errlCommit(l_errl, HWPF_COMP_ID);
    }

    // response will be sent by calling routine
    // IStepDispatcher::handleMoreWorkNeededMsg()
    // which will also execute the procedure to winkle all cores

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "host_sys_fab_iovalid_processing exit" );
}

};   // end namespace
