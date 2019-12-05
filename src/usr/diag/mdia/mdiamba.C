/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiamba.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
 * @file mdiamba.C
 * @brief mdia mba specific functions
 */

#include "mdiafwd.H"
#include "mdiaglobals.H"
#include "mdiasm.H"
#include "mdiatrace.H"
#include "targeting/common/utilFilter.H"

using namespace TARGETING;

namespace MDIA
{

errlHndl_t getDiagnosticMode(
        const Globals & i_globals,
        TargetHandle_t i_trgt,
        DiagMode & o_mode)
{
    o_mode = ONE_PATTERN;

    do
    {

        if(MNFG_FLAG_ENABLE_EXHAUSTIVE_PATTERN_TEST
           & i_globals.mfgPolicy)
        {
            o_mode = NINE_PATTERNS;
        }

        else if(MNFG_FLAG_ENABLE_STANDARD_PATTERN_TEST
                & i_globals.mfgPolicy)
        {
            o_mode = FOUR_PATTERNS;
        }

        else if(MNFG_FLAG_ENABLE_MINIMUM_PATTERN_TEST
                & i_globals.mfgPolicy)
        {
            o_mode = ONE_PATTERN;
        }

        else if(i_globals.simicsRunning)
        {
            o_mode = ONE_PATTERN;
        }

        // Only need to check hw changed state attributes
        // when not already set to exhaustive and not in simics
        if( ( NINE_PATTERNS != o_mode ) &&
            ( FOUR_PATTERNS != o_mode ) &&
            ( ! i_globals.simicsRunning ) )
        {
            if(isHWStateChanged(i_trgt))
            {
                // To reduce IPL times without broadcast mode, we will just run
                // 4 patterns instead of 9.
                o_mode = FOUR_PATTERNS;
            }
        }

    } while(0);

    MDIA_FAST("getDiagnosticMode: trgt: %x, o_mode: 0x%x, "
              "simics: %d",
              get_huid(i_trgt), o_mode, i_globals.simicsRunning);

    return 0;
}

errlHndl_t getWorkFlow(
                DiagMode i_mode,
                WorkFlow & o_wf,
                const Globals & i_globals)
{
    // add the correct sequences for the mba based
    // on the mode

    // every mba does restore dram repairs

    o_wf.push_back(RESTORE_DRAM_REPAIRS);

    switch (i_mode)
    {
        case NINE_PATTERNS:

            o_wf.push_back(START_PATTERN_7);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_6);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_5);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_4);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_3);
            o_wf.push_back(START_SCRUB);

            // fall through

        case FOUR_PATTERNS:

            o_wf.push_back(START_RANDOM_PATTERN);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_2);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_1);
            o_wf.push_back(START_SCRUB);

            // fall through

        case ONE_PATTERN:

            o_wf.push_back(START_PATTERN_0); // 0's pattern, must be last
            o_wf.push_back(START_SCRUB);

            break;

        default:
            break;
    }

    if(MNFG_FLAG_IPL_MEMORY_CE_CHECKING
            & i_globals.mfgPolicy)
    {
        o_wf.push_back(ANALYZE_IPL_MNFG_CE_STATS);
    }

    o_wf.push_back(CLEAR_HW_CHANGED_STATE);

    return 0;
}

/*
 *  Local helper function to return a list of targets associated with the input
 *  OCMB target
 *
 */
TargetHandleList getMemTargetsForQueryOrClear(TargetHandle_t i_trgt)
{
    #define FUNC "getMemTargetsForQueryOrClear: "
    TargetHandleList o_list;

    do
    {
        // add associated DIMMs
        TargetHandleList dimmList;
        getChildAffinityTargets(dimmList,
                                i_trgt,
                                CLASS_NA,
                                TYPE_DIMM);

        if( ! dimmList.empty() )
        {
            o_list.insert(o_list.begin(), dimmList.begin(), dimmList.end());
        }

        // add associated OCMB
        o_list.push_back( i_trgt );

        // add associated OMI
        TargetHandleList omiList;
        getParentAffinityTargets( omiList, i_trgt, CLASS_UNIT, TYPE_OMI );
        if ( omiList.size() == 1 )
        {
            o_list.push_back( omiList[0] );
        }
        else
        {
            MDIA_FAST( FUNC "Could not find parent OMI." );
            break;
        }

        // add associated OMIC
        TargetHandleList omicList;
        getParentAffinityTargets( omicList, omiList[0], CLASS_UNIT,
                                  TYPE_OMIC );
        if ( omicList.size() == 1 )
        {
            o_list.push_back( omicList[0] );
        }
        else
        {
            MDIA_FAST( FUNC "Could not find parent OMIC." );
            break;
        }

        // add associated MCC
        TargetHandleList mccList;
        getParentAffinityTargets( mccList, omiList[0], CLASS_UNIT,
                TYPE_MCC );
        if ( mccList.size() == 1 )
        {
            o_list.push_back( mccList[0] );
        }
        else
        {
            MDIA_FAST( FUNC "Could not find parent MCC." );
            break;
        }

        // add associated MI
        TargetHandleList miList;
        getParentAffinityTargets( miList, mccList[0], CLASS_UNIT, TYPE_MI );
        if ( miList.size() == 1 )
        {
            o_list.push_back( miList[0] );
        }
        else
        {
            MDIA_FAST( FUNC "Could not find parent MI." );
            break;
        }

        // add associated MC
        TargetHandleList mcList;
        getParentAffinityTargets( mcList, miList[0], CLASS_UNIT, TYPE_MC );
        if ( mcList.size() == 1 )
        {
            o_list.push_back( mcList[0] );
        }
        else
        {
            MDIA_FAST( FUNC "Could not find parent MC." );
            break;
        }

    } while(0);

    MDIA_DBG(FUNC "i_trgt HUID: %x, size: %d",
             get_huid(i_trgt), o_list.size());

    return o_list;

    #undef FUNC
}


bool isHWStateChanged(TargetHandle_t i_trgt)
{
    bool hwChanged = false;
    ATTR_HWAS_STATE_CHANGED_FLAG_type hwChangeFlag;

    // Get a list of associated targets for attribute query
    TargetHandleList targetList =
        getMemTargetsForQueryOrClear(i_trgt);

    for(TargetHandleList::iterator target = targetList.begin();
        target != targetList.end(); ++target )
    {
        hwChangeFlag =
            (*target)->getAttr<ATTR_HWAS_STATE_CHANGED_FLAG>();

        if(HWAS_CHANGED_BIT_MEMDIAG & hwChangeFlag)
        {
            MDIA_DBG("isHWStateChanged: set for target: %x",
                     get_huid(*target));
            hwChanged = true;
            break;
        }
    }

    return hwChanged;
}

void clearHWStateChanged(TargetHandle_t i_trgt)
{
    TargetHandleList targetList;

    // Get a list of associated targets for attribute clearing
    targetList = getMemTargetsForQueryOrClear(i_trgt);

    for(TargetHandleList::iterator target = targetList.begin();
        target != targetList.end(); ++target)
    {
        MDIA_DBG("clearHWStateChanged: mba: %x, target: %x",
                 get_huid(i_trgt), get_huid(*target));

        clear_hwas_changed_bit( *target,
                                HWAS_CHANGED_BIT_MEMDIAG);
    }
}


}
