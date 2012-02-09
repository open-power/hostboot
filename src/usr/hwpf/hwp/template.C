//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/HWPs/template.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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

//  notes:
//  replace <@foo> with the tag string @foo
//  replace <<@foo>> with an uppercased tag string @foo

/**
 *  @file <@istepname>.C                                                // @
 *
 *  Support file for IStep:
 *      <@istepname>                                                    // @
 *
 *
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <kernel/console.H>
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <targeting/targetservice.H>
#include    <fapi.H>

//  --  prototype   includes    --
#include    "<@istepname>.H"                                            // @
#include    "<@substepname>/<@substepname>.H"                           // @

namespace   <<@istepname>>                                              // @
{
trace_desc_t *g_trac_<@istepname> = NULL;                               // @
TRAC_INIT(&g_trac_dmi<@istepname>, "<<@istepname>>", 2048 );            // @

using   namespace   TARGETING;

//
//  Wrapper function to call <@istepnum>.<@substepnum> : <@substepname>
//
void    call_<@substepname>( void *io_pArgs )                            // @
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    //  Use hwasPredicate to filter only functional chips
    HWAS::HwasPredicate             l_functionalHwas;


    TRACDCOMP( g_trac_dmi_training, "call_<@substepname> entry" );       //@


    //  figure out what targets we need

    // print trace message beginning HWP, listing out input parms
    TRACFCOMP( g_trac_dmi_training,
                            "===== Call @substepname HWP( @parm1 0x%x, ..., @parmN 0x%x ) : ",
                            @parm1,
                            ...,
                            @parmN
                    );
    //  dump @target1..N Physical path
    EntityPath l_path;
    l_path = @target1->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();
    //  ...
    //  dump    @targetN
    EntityPath l_path;
    l_path = @targetN->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   <@substepname>( ? , ?, ? );


    //  process return code.
    if ( l_fapirc == fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( g_trac_dmi_training,
                "SUCCESS :  @substepname HWP( cpu 0x%x, mcs 0x%x, mem 0x%x ) " );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( g_trac_dmi_training,
                "ERROR %d:  @substepname HWP(  ) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( g_trac_dmi_training, "<@substepname> exit" );       //@

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


};   // end namespace

