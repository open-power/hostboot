/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/genPstate.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#include "genPstate.H"
#include "htmgt_utility.H"
#include <htmgt/htmgt_reasoncodes.H>
#include <assert.h>

//  Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>

// occ hwp support
#include <freqVoltageSvc.H>
#include <pstates.h>

using namespace TARGETING;

namespace HTMGT
{
errlHndl_t genPstateTables()
{
    errlHndl_t err = NULL;

    TargetHandleList processors;

    getChipResources(processors,
                     TYPE_PROC,
                     UTIL_FILTER_FUNCTIONAL);

    for(TargetHandleList::const_iterator
            procItr = processors.begin();
            procItr != processors.end();
            ++procItr)
    {
        Target * procTarget = *procItr;

        TargetHandleList occs;
        getChildChiplets(occs,
                         procTarget,
                         TYPE_OCC,
                         true);

        if(occs.size() > 0)
        {
            PstateSuperStructure pstate_data;
            Target * occTarget = occs[0];
            ATTR_HUID_type huid = occTarget->getAttr<ATTR_HUID>();

            TMGT_INF("Building pstate table for huid 0x%x", huid);

            err = FREQVOLTSVC::runP8BuildPstateDataBlock( procTarget,
                                                          &pstate_data);

            if(err)
            {
                TMGT_ERR( "tmgtProcessAppGenPstateTable: Failed to"
                          " generate PSTATE data for OCC "
                          "(huid=%x).",
                          huid
                        );

                //  collectTrace is called by the calling routine (htmgt.C).
                break;

            }
            else
            {
                ATTR_PSTATE_TABLE_type * pstateData =
                    reinterpret_cast<ATTR_PSTATE_TABLE_type*>
                    (&pstate_data);

                CPPASSERT(sizeof(ATTR_PSTATE_TABLE_type) ==
                          sizeof(PstateSuperStructure));

                occTarget->setAttr<ATTR_PSTATE_TABLE>(*pstateData);
            }
        }
    }
    return err;
}
}; // end namespace
