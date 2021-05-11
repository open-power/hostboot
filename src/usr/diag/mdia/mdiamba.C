/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiamba.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#include <util/misc.H> // Util::isSimicsRunning

using namespace TARGETING;

namespace MDIA
{

errlHndl_t getDiagnosticMode( const Globals & i_globals, TargetHandle_t i_trgt,
                              DiagMode & o_mode )
{
    o_mode = i_globals.getDiagMode();

    // Check the HW changed state of this target to determine if more testing
    // is required.
    if ( (ONE_PATTERN == o_mode) && isHWStateChanged(i_trgt) &&
         !Util::isSimicsRunning() )
    {
        // Run standard pattern testing.
        o_mode = FOUR_PATTERNS;
    }

    MDIA_FAST( "getDiagnosticMode i_trgt:0x%08x o_mode:0x%x",
               get_huid(i_trgt), o_mode );

    return nullptr;
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

    if ( i_globals.queryMnfgIplCeChecking() )
    {
        o_wf.push_back(ANALYZE_IPL_MNFG_CE_STATS);
    }

    o_wf.push_back(CLEAR_HW_CHANGED_STATE);
    o_wf.push_back(POST_MEMDIAGS_HWPS);

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

        if( !dimmList.empty() )
        {
            o_list.insert(o_list.begin(), dimmList.begin(), dimmList.end());
        }

        // add associated MEM_PORTs
        TargetHandleList portList;
        getChildAffinityTargets(portList,
                                i_trgt,
                                CLASS_NA,
                                TYPE_MEM_PORT);

        if( !portList.empty() )
        {
            o_list.insert(o_list.begin(), portList.begin(), portList.end());
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
        getParentOmicTargetsByState( omicList, omiList[0], CLASS_NA,
                                     TYPE_OMIC, UTIL_FILTER_FUNCTIONAL );
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

    MDIA_DBG(FUNC "i_trgt HUID: 0x%08x, size: %d",
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
        hwChangeFlag = (*target)->getAttr<ATTR_HWAS_STATE_CHANGED_FLAG>();

        if(HWAS_CHANGED_BIT_MEMDIAG & hwChangeFlag)
        {
            MDIA_FAST("isHWStateChanged: set for target: 0x%08x",
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
