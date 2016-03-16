/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/attn.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
#include <util/singleton.H>
#include <errl/errlmanager.H>

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

    TargetHandleList list;

    getTargetService().getAllChips(list, TYPE_PROC);

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

    return 0;
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
