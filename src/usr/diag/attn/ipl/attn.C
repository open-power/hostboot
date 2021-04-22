/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/attn.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/**
 * @file attn.C
 *
 * @brief HBATTN utility function definitions.
 */

#include "ipl/attnsvc.H"
#include "common/attnprd.H"
#include "common/attnops.H"
#include "common/attnlist.H"
#include "common/attntrace.H"
#include "common/attntarget.H"
#include "common/attnproc.H"
#include "common/attnmem.H"
#include "diag/attn/attnreasoncodes.H"
#include <util/singleton.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <initservice/initserviceif.H>
#include <devicefw/userif.H>

// Custom compile configs

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace Util;
using namespace ERRORLOG;

namespace ATTN
{

errlHndl_t startService()
{
    return Service::getGlobalInstance()->start();
}

errlHndl_t stopService()
{
    return Service::getGlobalInstance()->stop();
}

errlHndl_t checkForIplAttentions()
{
    errlHndl_t err = NULL;

    assert(!Service::getGlobalInstance()->running());

    TargetHandleList     list;
    uint8_t              l_useAllProcs = 0;
    TARGETING::Target   *l_MasterProcTarget = NULL;
    TARGETING::Target   *l_sys = NULL;


    // ------------------------------------------------
    // NOTE: ATTN code overrides TARGETING code for
    //       testing purposes. However for this case
    //       of getting an attribute, we can just
    //       modify the attribute for testing.
    // ------------------------------------------------

    // We have an ATTRIBUTE that indicates all procs
    // or just the master proc.
    TARGETING::targetService().getTopLevelTarget( l_sys );
    assert(l_sys != NULL);
    l_sys->tryGetAttr<ATTR_ATTN_CHK_ALL_PROCS>(l_useAllProcs);

    getTargetService().masterProcChipTargetHandle(
                                          l_MasterProcTarget);

    // Do we want to check ALL procs ?
    if (0 == l_useAllProcs)
    {
        list.push_back(l_MasterProcTarget);
    } // end if just master proc
    else
    {
        getTargetService().getAllChips(list, TYPE_PROC);
    } // end else ALL procs


    TargetHandleList::iterator tit = list.begin();

    ATTN_SLOW("checkForIplAttentions: %d chips", list.size() );
    while(tit != list.end())
    {
        err = Service::getGlobalInstance()->handleAttentions(*tit);

        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
        }

        tit = list.erase(tit);
    }

    // ====================================================================
    // PRD and HW procedures use an attribute to associate errors
    // together.  If we still see that 'active' when done checking
    // attentions, we are suppose to build an error log with a
    // matching PLID so the istep fails.  Then hopefully people
    // look at the other error log with the same PLID and not this
    // one since that is the real error.
    // ====================================================================
    // NOTE: There could be multiple PLIDs set on different targets
    //       So we may need to commit some elogs and pass back one.
    // ====================================================================

    errlHndl_t l_plidElog = nullptr;

    // Iterate all targets.
    for ( TargetIterator trgt = TARGETING::targetService().begin();
          trgt != TARGETING::targetService().end(); ++trgt )
    {
        uint32_t l_plid = 0;

        // Check for non-zero value in PLID attribute.
        if ( (*trgt)->tryGetAttr<ATTR_PRD_HWP_PLID>(l_plid) && (0 != l_plid) )
        {
            ATTN_SLOW( "ATTR_PRD_HWP_PLID found on 0x%08x with value 0x%08x",
                       get_huid(*trgt), l_plid );

            // In the case where there is more than one target with this
            // attribute, commit the previous error log.
            if ( nullptr != l_plidElog )
            {
                errlCommit( l_plidElog, ATTN_COMP_ID );
            }

            // Create a new error log and link the PLID.
            /*@
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   ATTN_CHK_IPL_ATTNS_MODULE
             * @reasoncode ATTN_SEE_HW_ERROR
             * @userdata1  HUID of target containing ATTR_PRD_HWP_PLID
             * @userdata2  Value of ATTR_PRD_HWP_PLID
             *
             * @devdesc    A hardware procedure failed with the assumption that
             *             there were active attentions. However, no attentions
             *             were found. Check the other log with matching PLID.
             *
             * @custdesc   A hardware procedure failed. Check the other log with
             *             matching PLID.
             */
            l_plidElog = new ErrlEntry( ERRL_SEV_UNRECOVERABLE,
                                        ATTN_CHK_IPL_ATTNS_MODULE,
                                        ATTN_SEE_HW_ERROR,
                                        get_huid(*trgt), l_plid );
            l_plidElog->plid(l_plid);

            // Clear the attribute.
            (*trgt)->setAttr<ATTR_PRD_HWP_PLID>( 0 );
        }
    }

    // ====================================================================

    return l_plidElog;
}

void  setTrueMask_otherProcs( const TARGETING::TargetHandleList &i_allProcs )
{
    TARGETING::TargetHandle_t   l_PrimaryProcTarget = NULL;
    bool            l_fspSystem = INITSERVICE::spBaseServicesEnabled();  // True on FSP
    uint32_t        l_huid = 0;
    errlHndl_t      l_err = NULL;
    const uint16_t  ATTN_TRUEMASK_REG = 0x100D;   // cfam address
    uint32_t        l_truemaskData = 0x60000000;  // Chkstop and SpecialAttn
    size_t          l_size = sizeof(l_truemaskData);
    uint16_t        l_fsiAddr = (ATTN_TRUEMASK_REG & 0xfe00) |
                                ((ATTN_TRUEMASK_REG & 0x01ff) * 4);


    ATTN_SLOW("setTrueMask_otherProcs - FSP %d",  l_fspSystem);

    // The FSP interrupt handling will set the TRUEMASK regs on all procs.
    // We don't want to interfere with that in hostboot or we could have issues.
    // The eBMC needs these regs set though and it seems easiest to do in hostboot.
    if ( false == l_fspSystem )
    {
        // BMC type box
        // We need to skip setting on primary proc as we don't have FSI access to it.
        // The BMC has to set the primary proc !!
        getTargetService().masterProcChipTargetHandle(l_PrimaryProcTarget);

        for (const auto & l_procTarget : i_allProcs)
        {
            if ( l_PrimaryProcTarget != l_procTarget )
            {
                // Trace which procs we are setting up
                l_huid = TARGETING::get_huid(l_procTarget);
                ATTN_SLOW( "Init TRUEMASK on Proc 0x%08X to 0x%08X",
                           l_huid, l_truemaskData );

                // Write the CFAM register on this processor
                l_err = deviceWrite( l_procTarget, &l_truemaskData, l_size,
                                     DEVICE_FSI_ADDRESS((uint64_t) l_fsiAddr) );
                if (l_err)
                {
                    ATTN_SLOW("Failed to init TRUEMASK on 0x%08X", l_huid);
                    errlCommit(l_err, ATTN_COMP_ID);
                } // if failed writing TRUEMASK reg

            } // if  NOT primary proc

        } // end for loop on all input procs

    } // end if NOT FSP

    return;
}


} // end namespace ATTN
