/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/genPstate.C $                                   */
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
errlHndl_t genPstateTables(bool i_normalTables)
{
    errlHndl_t err = NULL;

    // pstate table attribute must be big enough to hold the pstate structure
    CPPASSERT(sizeof(ATTR_PSTATE_TABLE_type) >= sizeof(PstateSuperStructure));
    // normal and mfg pstate tables are the same size
    CPPASSERT(sizeof(ATTR_PSTATE_TABLE_type) ==
              sizeof(ATTR_PSTATE_TABLE_MFG_type));

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
            const char * tableType = i_normalTables?"normal":"mfg";
            PstateSuperStructure pstate_data;
            Target * occTarget = occs[0];
            ATTR_HUID_type huid = occTarget->getAttr<ATTR_HUID>();

            TMGT_INF("genPstateTables: Building %s pstate tables for "
                     "huid 0x%x", tableType, huid);

            err = FREQVOLTSVC::runP8BuildPstateDataBlock( procTarget,
                                                          &pstate_data);

            if(err)
            {
                TMGT_ERR( "genPstateTables: Failed to"
                          " generate PSTATE data for OCC "
                          "(huid=%x).",
                          huid
                        );

                //  collectTrace is called by the calling routine (htmgt.C).
                break;

            }
            else
            {
                TMGT_INF("genPstateTables: %s pstate tables completed for "
                         "huid 0x%x", tableType, huid);
                if (i_normalTables)
                {
                    ATTR_PSTATE_TABLE_type * pstateData =
                        reinterpret_cast<ATTR_PSTATE_TABLE_type*>
                        (&pstate_data);

                    occTarget->setAttr<ATTR_PSTATE_TABLE>(*pstateData);
                }
                else
                {
                    ATTR_PSTATE_TABLE_MFG_type * pstateData =
                        reinterpret_cast<ATTR_PSTATE_TABLE_MFG_type*>
                        (&pstate_data);

                    occTarget->setAttr<ATTR_PSTATE_TABLE_MFG>(*pstateData);
                }
            }
        }
    }
    return err;
}


bool getPstateTable(const bool      i_normalTables,
                    const uint8_t   i_proc,
                    uint16_t      & o_dataLen,
                    uint8_t       * o_dataPtr)
{
    bool copied = false;

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
        const uint8_t procInstance =
            procTarget->getAttr<TARGETING::ATTR_POSITION>();
        if (i_proc == procInstance)
        {
            const uint8_t l_occ = 0;
            TargetHandleList occs;
            getChildChiplets(occs,
                             procTarget,
                             TYPE_OCC,
                             true);
            Target * occTarget = occs[l_occ];
            ATTR_HUID_type huid = occTarget->getAttr<ATTR_HUID>();
            // Read data from attribute for specified occ
            if (i_normalTables)
            {
                TMGT_INF("Dumping PStateTable for Proc%d OCC%d (HUID 0x%08X)",
                         i_proc, l_occ, huid);
                ATTR_PSTATE_TABLE_type * pstateDataPtr =
                    reinterpret_cast<ATTR_PSTATE_TABLE_type*>(o_dataPtr);

                occTarget->tryGetAttr<ATTR_PSTATE_TABLE>(*pstateDataPtr);
                o_dataLen = sizeof(ATTR_PSTATE_TABLE_type);
                copied = true;
            }
            else
            {
                TMGT_INF("Dumping MFG PStateTable for Proc%d OCC%d"
                         " (HUID 0x%08X)", i_proc, l_occ, huid);
                ATTR_PSTATE_TABLE_MFG_type * pstateDataPtr =
                    reinterpret_cast<ATTR_PSTATE_TABLE_MFG_type*>(o_dataPtr);

                occTarget->tryGetAttr<ATTR_PSTATE_TABLE_MFG>(*pstateDataPtr);
                o_dataLen = sizeof(ATTR_PSTATE_TABLE_MFG_type);
                copied = true;
            }

            // Just dump for first OCC
            break;
        }
    }

    return copied;

} // end getPstateTable()


}; // end namespace
