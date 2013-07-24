/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiamba.C $                                 */
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

errlHndl_t getMbaDiagnosticMode(
        const Globals & i_globals,
        TargetHandle_t i_mba,
        DiagMode & o_mode)
{
    o_mode = INIT_ONLY;

    if(MNFG_FLAG_BIT_MNFG_ENABLE_EXHAUSTIVE_PATTERN_TEST
            & i_globals.mfgPolicy)
    {
        o_mode = NINE_PATTERNS;
    }

    else if(MNFG_FLAG_BIT_MNFG_ENABLE_STANDARD_PATTERN_TEST
            & i_globals.mfgPolicy)
    {
        o_mode = FOUR_PATTERNS;
    }

    else if(MNFG_FLAG_BIT_MNFG_ENABLE_MINIMUM_PATTERN_TEST
            & i_globals.mfgPolicy)
    {
        o_mode = ONE_PATTERN;
    }

    // Only need to check hw changed state attributes
    // when not already set to standard or exhaustive
    if((FOUR_PATTERNS != o_mode) ||
       (NINE_PATTERNS != o_mode))
    {
        if(isHWStateChanged(i_mba))
        {
            o_mode = FOUR_PATTERNS;
        }
    }

    MDIA_FAST("getMbaDiagnosticMode: mba: %x, o_mode: 0x%x",
              get_huid(i_mba), o_mode);

    return 0;
}

errlHndl_t getMbaWorkFlow(DiagMode i_mode, WorkFlow & o_wf)
{
    // add the correct sequences for the mba based
    // on the mode

    // every mba does restore dram repairs

    o_wf.push_back(RESTORE_DRAM_REPAIRS);

    switch (i_mode) {

        case NINE_PATTERNS:

            o_wf.push_back(START_RANDOM_PATTERN);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_7);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_6);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_5);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_4);
            o_wf.push_back(START_SCRUB);

            // fall through

        case FOUR_PATTERNS:

            o_wf.push_back(START_PATTERN_3);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_2);
            o_wf.push_back(START_SCRUB);
            o_wf.push_back(START_PATTERN_1);
            o_wf.push_back(START_SCRUB);

            // fall through

        case ONE_PATTERN:

            o_wf.push_back(START_PATTERN_0);

            // fall through

        case SCRUB_ONLY:

            o_wf.push_back(START_SCRUB);
            break;

        case INIT_ONLY:

            o_wf.push_back(START_PATTERN_0);
            break;

        default:
            break;
    }

    // clear HW changed state attribute
    o_wf.push_back(CLEAR_HW_CHANGED_STATE);

    return 0;
}

/*
 *  Local helper function to return a list of Centaur
 *  DIMMs, and MCS associated with the input MBA target
 *
 *  If i_queryOnly = true (Query)
 *    - Return a list of DIMMs, Centaur, and
 *      MCS connected to this MBA
 *
 *  Else (Clear)
 *   - Return a list of DIMMs and
 *     (Centaur + MCS) if all the DIMMs behind this
 *     Centaur have hwchangedState flags cleared
 *     or about to be cleared by this MBA
 */
TargetHandleList getMemTargetsForQueryOrClear(
                    TargetHandle_t i_mba, bool i_queryOnly)
{
    #define FUNC "getMemTargetsForQueryOrClear: "
    TargetHandleList o_list;

    do
    {
        // add associated DIMMs
        TargetHandleList dimmList;
        getChildAffinityTargets(dimmList,
                                i_mba,
                                CLASS_NA,
                                TYPE_DIMM);

        if( ! dimmList.empty() )
        {
            o_list.insert(o_list.begin(), dimmList.begin(),
                          dimmList.end());
        }

        // add associated Centaur
        TargetHandleList targetList;
        getParentAffinityTargets(targetList,
                                 i_mba,
                                 CLASS_CHIP,
                                 TYPE_MEMBUF);

        if( targetList.empty() )
        {
            MDIA_FAST(FUNC"no connected centaur "
                    "for mba: %x", get_huid(i_mba));
            break;
        }

        TargetHandle_t centaur = targetList[0];

        // if query flag is not set, check to make sure
        // all of the dimms connected to this centaur
        // have cleared hw chagned state attributes
        // before adding this centaur/mcs to the list.
        // This is needed because we only clear
        // the centaur/mcs attribute when all of the
        // dimms' attributes from both mbas have cleared.
        if(false == i_queryOnly)
        {
            targetList.clear();
            getChildAffinityTargets(targetList,
                                    centaur,
                                    CLASS_NA,
                                    TYPE_DIMM);

            if( ! targetList.empty() )
            {
                TargetHandleList::iterator target;

                for(target = targetList.begin();
                    target != targetList.end(); ++target)
                {
                    // exclude dimms belong to the current mba
                    // because their attributes will be cleared
                    if(dimmList.end() !=
                             std::find(dimmList.begin(),
                                       dimmList.end(), *target))
                    {
                        continue;
                    }

                    ATTR_HWAS_STATE_CHANGED_FLAG_type hwChangeFlag;
                    hwChangeFlag =
                      (*target)->getAttr<ATTR_HWAS_STATE_CHANGED_FLAG>();

                    if(HWAS_CHANGED_BIT_MEMDIAG & hwChangeFlag)
                    {
                        MDIA_FAST(FUNC"hwChangedState is not cleared "
                                  "for dimm: %x", get_huid(*target));
                        centaur = NULL; // don't add centaur and mcs
                        break;
                    }
                }
            }
        }

        if(NULL == centaur)
        {
            break;
        }

        o_list.push_back(centaur);

        // get connected mcs target
        targetList.clear();

        getParentAffinityTargets(targetList,
                                 centaur,
                                 CLASS_UNIT,
                                 TYPE_MCS);

        if( ! targetList.empty() )
        {
            o_list.push_back(targetList[0]);
        }

    } while(0);

    MDIA_DBG(FUNC"mba: %x, size: %d",
             get_huid(i_mba), o_list.size());

    return o_list;

    #undef FUNC
}


bool isHWStateChanged(TargetHandle_t i_mba)
{
    bool hwChanged = false;
    ATTR_HWAS_STATE_CHANGED_FLAG_type hwChangeFlag;

    // Get a list of associated targets for attribute query
    TargetHandleList targetList =
        getMemTargetsForQueryOrClear(i_mba, true);

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

void clearHWStateChanged(TargetHandle_t i_mba)
{
    TargetHandleList targetList;

    // Get a list of associated targets for attribute clearing
    targetList = getMemTargetsForQueryOrClear(i_mba, false);

    for(TargetHandleList::iterator target = targetList.begin();
        target != targetList.end(); ++target)
    {
        MDIA_DBG("clearHWStateChanged: mba: %x, target: %x",
                 get_huid(i_mba), get_huid(*target));

        clear_hwas_changed_bit( *target,
                                HWAS_CHANGED_BIT_MEMDIAG);
    }
}


}
