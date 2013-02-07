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

    return 0;
}
}
