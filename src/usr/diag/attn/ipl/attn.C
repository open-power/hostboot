/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/attn.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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

// Custom compile configs
#include <config.h>

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
  #include "ipl/attnfilereg.H"
  #include <diag/prdf/prdfPnorFirDataReader.H>
#endif

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace Util;
using namespace ERRORLOG;

namespace ATTN
{

errlHndl_t startService()
{
    return Singleton<Service>::instance().start();
}

errlHndl_t stopService()
{
    return Singleton<Service>::instance().stop();
}

errlHndl_t checkForIplAttentions()
{
    errlHndl_t err = NULL;

    assert(!Singleton<Service>::instance().running());

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

    ATTN_TRACE("checkForIplAttentions: %d chips", list.size() );
    while(tit != list.end())
    {
        err = Singleton<Service>::instance().handleAttentions(*tit);

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
    ATTR_MODEL_type  l_model = l_MasterProcTarget->getAttr<ATTR_MODEL>();
    errlHndl_t       l_plidElog = NULL;
    uint32_t         l_plid  = 0;
    TARGETING::TYPE  l_memType;
    TargetHandleList l_allProcsList, l_memList;


    // Setup appropriate memory type target
    if ( MODEL_NIMBUS == l_model )
    {
        l_memType = TYPE_MCA;
    } // if NIMBUS
    else if ( MODEL_CUMULUS == l_model )
    {
        l_memType = TYPE_DMI;
    } // if CUMULUS
    else
    {
        ATTN_ERR("ChkForIplAttns Unknown PROC type - add support");
        assert(0);
    } // UNKNOWN proc type


    // This gets all PROCs whether functional or not
    getTargetService().getAllChips(l_allProcsList, TYPE_PROC, false);

    // Loop thru all PROC targets
    for ( auto  l_procTarg : l_allProcsList )
    {
        // check PROC target first for attribute
        l_procTarg->tryGetAttr<ATTR_PRD_HWP_PLID>(l_plid);

        if (0 != l_plid)
        {
            ATTN_SLOW("checkForIplAttentions PROC plid found");

            // If we had a prior ELOG, we need to commit it
            // since we will be creating another one here.
            if (NULL != l_plidElog)
            {
                errlCommit(l_plidElog, ATTN_COMP_ID);
            }

            // Build elog with same PLID value
            l_plidElog = new ErrlEntry( ERRL_SEV_UNRECOVERABLE,
                                        ATTN_CHK_IPL_ATTNS_MODULE,
                                        ATTN_SEE_HW_ERROR,
                                        l_plid, TYPE_PROC
                                      );

            // Make sure PLID matches the HW error
            l_plidElog->plid(l_plid);

            // clear attribute
            l_plid = 0;
            l_procTarg->trySetAttr<ATTR_PRD_HWP_PLID>(l_plid);
        } // non-zero PLID in attribute


        // Get the list of MEMORY related units (functional or not)
        getChildChiplets(l_memList, l_procTarg, l_memType, false);

        for ( auto  l_memTarg : l_memList )
        {
            // check PROC target first for attribute
            l_memTarg->tryGetAttr<ATTR_PRD_HWP_PLID>(l_plid);

            if (0 != l_plid)
            {
                ATTN_SLOW("checkForIplAttentions MEM plid found");

                // If we had a prior ELOG, we need to commit it
                // since we will be creating another one here.
                if (NULL != l_plidElog)
                {
                    errlCommit(l_plidElog, ATTN_COMP_ID);
                }

                // Build elog with same PLID value
                l_plidElog = new ErrlEntry( ERRL_SEV_UNRECOVERABLE,
                                            ATTN_CHK_IPL_ATTNS_MODULE,
                                            ATTN_SEE_HW_ERROR,
                                            l_plid, l_memType
                                           );

                // Make sure PLID matches the HW error
                l_plidElog->plid(l_plid);

                // clear attribute
                l_plid = 0;
                l_memTarg->trySetAttr<ATTR_PRD_HWP_PLID>(l_plid);
            } // non-zero PLID in attribute

        } // end for on mem target

    } // end for loop on PROC targets
    // ====================================================================

    return l_plidElog;
}

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS

errlHndl_t checkForCSAttentions()
{
    ATTN_SLOW("Checking for checkstop attentions");

    errlHndl_t errl = NULL;

    assert(!Singleton<Service>::instance().running());

    do
    {
        // Read register data from PNOR into memory.
        PnorFirDataReader & firData = PnorFirDataReader::getPnorFirDataReader();
        bool validData;
        errl = firData.readPnor( validData );
        if ( NULL != errl )
        {
            ATTN_ERR("PnorFirDataReader::readPnor() failed");
            break;
        }

        // Check if there was valid data in PNOR.
        if ( !validData )
        {
            // Nothing to do, exit quietly.
            ATTN_SLOW("No PNOR data found, nothing to analyze.");
            break;
        }

        // Install File scom implementation
        FileRegSvc fileRegs;
        fileRegs.installScomImpl();

        // Process the checkstop attention
        errl = Singleton<Service>::instance().processCheckstop();
        if ( NULL != errl )
        {
            firData.addFfdc( errl );
            errlCommit( errl, ATTN_COMP_ID );
        }

        // Uninstall File scom implementation.
        Singleton<ScomImpl>::instance().installScomImpl();

        // Analysis is complete. Clear the PNOR data.
        errl = firData.clearPnor();
        if ( NULL != errl )
        {
            ATTN_ERR("PnorFirDataReader::clearPnor() failed");
            break;
        }

    } while (0);

    ATTN_SLOW("checkForCSAttentions complete");

    return errl;
}

#endif // CONFIG_ENABLE_CHECKSTOP_ANALYSIS

}
