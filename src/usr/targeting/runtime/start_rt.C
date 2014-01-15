/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/start_rt.C $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#include <targeting/common/commontargeting.H>
#include <targeting/common/targetservice.H>
#include <targeting/attrrp.H>

namespace TARGETING
{
    static void initTargeting() __attribute__((constructor));
    static void initTargeting()
    {
        errlHndl_t l_errl = NULL;

        AttrRP::init(l_errl);
        if (l_errl)
        {
            errlCommit(l_errl, TARG_COMP_ID);
            assert(false);
        }

        TargetService& l_targetService = targetService();
        (void)l_targetService.init();
    }
}
