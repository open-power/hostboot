/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/host_proc_pcie_scominit.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>

#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <isteps/hwpisteperror.H>
#include <errl/errludtarget.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <devicefw/userif.H>
#include <config.h>
#include "host_proc_pcie_scominit.H"
#include <hwas/common/hwas.H>
#include <hwas/common/deconfigGard.H>


namespace   ISTEP_10
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//******************************************************************************
// Local logical equality operator for matching lane configuration rows
//******************************************************************************

inline bool operator==(
    const laneConfigRow& i_lhs,
    const laneConfigRow& i_rhs)
    {
        return ( memcmp(i_lhs.laneSet,i_rhs.laneSet,
            sizeof(i_lhs.laneSet)) == 0);
    }

//******************************************************************************
// _laneMaskToLaneWidth
//******************************************************************************

LaneWidth _laneMaskToLaneWidth(const uint16_t i_laneMask)
{
    LaneWidth laneWidth = LANE_WIDTH_NC;
    if(i_laneMask == LANE_MASK_X16)
    {
        laneWidth = LANE_WIDTH_16X;
    }
    else if(   (i_laneMask == LANE_MASK_X8_GRP0)
            || (i_laneMask == LANE_MASK_X8_GRP1))
    {
        laneWidth = LANE_WIDTH_8X;
    }
    else if(   (i_laneMask == LANE_MASK_X4_GRP0)
            || (i_laneMask == LANE_MASK_X4_GRP1))
    {
        laneWidth = LANE_WIDTH_4X;
    }

    return laneWidth;
}

//******************************************************************************
// _deconfigPhbsBasedOnPhbMask
//******************************************************************************

void _deconfigPhbsBasedOnPhbMask(
    TARGETING::ConstTargetHandle_t const       i_procTarget,
    TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type& i_phbActiveMask)
{
    uint8_t phbNum = 0;
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        ENTER_MRK "_deconfigPhbsBasedOnPhbMask: Proc target HUID = "
        "0x%08X, PHB active mask = 0x%02X.", i_procTarget ?
        i_procTarget->getAttr<TARGETING::ATTR_HUID>() : 0, i_phbActiveMask);

    // PHB mask bits start at the left most bit - so we must shift the bits
    // right in order to get the correct masks. This number below should
    // always be 7.
    const size_t bitsToRightShift =
        ((sizeof(i_phbActiveMask)*BITS_PER_BYTE) - 1);

    // Get every functional PEC under the Proc
    TARGETING::TargetHandleList funcPecList;
    (void)TARGETING::getChildChiplets(
        funcPecList,i_procTarget,TARGETING::TYPE_PEC);

     for (TARGETING::TargetHandleList::const_iterator pecItr
            = funcPecList.begin(); pecItr != funcPecList.end(); ++pecItr)
    {
        TargetHandle_t l_pec = *pecItr;

        // Get pec chip's functional PHB units
        TARGETING::TargetHandleList funcPhbList;
        (void)TARGETING::getChildChiplets(
            funcPhbList,l_pec,TARGETING::TYPE_PHB);

        // i_phbActiveMask is a bitmask whose leftmost bit corresponds to
        // PHB0, followed by bits for PHB1, PHB2, PHB3, PHB4, and PBH5. The
        // remaining bits are ignored. We need to compare each PHB mask to
        // its respective PHB and deconfigure it if needed.
        for (TARGETING::TargetHandleList::const_iterator phbItr
                = funcPhbList.begin(); phbItr != funcPhbList.end(); ++phbItr)
        {
            TargetHandle_t l_phb = *phbItr;

            // Get the PHB unit number
            phbNum = l_phb->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            // Subtract the PHB unit number from the constant bitsToRightShift
            // in order to get the correct amount of bits to shift right.
            // e.g. for PHB0, the unit number is 0, bitsToRightShift-0 = 7.
            // We will shift i_phbActiveMask 7 bits right, which means we are
            // examining bit 0 of the PHB mask. If it is not set - deconfigure
            // the respective PHB
            if (!((i_phbActiveMask >> (bitsToRightShift - phbNum)) & 1))
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "PHB %d on PEC %d has been found INACTIVE. Deconfiguring "
                    "PHB %d.", phbNum,
                    l_pec->getAttr<TARGETING::ATTR_CHIP_UNIT>(), phbNum);

                l_err = HWAS::theDeconfigGard().deconfigureTarget(
                     *l_phb, HWAS::DeconfigGard::DECONFIGURED_BY_PHB_DECONFIG);

                if (l_err)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                        "_deconfigPhbsBasedOnPhbMask: Error deconfiguring PHB "
                        "%d  on PEC %d.", phbNum,
                        l_pec->getAttr<TARGETING::ATTR_HUID>());

                    ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);

                    // Try to deconfigure any other PHBs
                    delete l_err;
                    l_err = NULL;
                }
            }
        }//PHB loop
    }//PEC loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        EXIT_MRK "_deconfigPhbsBasedOnPhbMask: i_phbActiveMask = 0x%02X",
        i_phbActiveMask);

    return;
}

//******************************************************************************
// _queryIopsToBifurcateAndPhbsToDisable
//******************************************************************************

// Normally a x16 PCIE adapter is driven by one PHB in the processor.
// Some x16 adapters have two logically different devices integrated
// onto the same adapter, each acting as a x8 PCIE endpoint driven by
// its own PHB.  The ability to detect which type of PCIE adapter is
// present and dynamically reconfigure the PCIE langes / PHBs to support
// whatever is present is called 'dynamic bifurcation'.  This feature is
// not officially supported however hooks remain in place to add that
// support easily.  To enable it, define the DYNAMIC_BIFURCATION flag
// and implement the guts of the
// _queryIopsToBifurcateAndPhbsToDisable function.

#if CONFIG_SENSOR_BASED_BIFURCATION
extern errlHndl_t _queryIopsToBifurcateAndPhbsToDisable(
    TARGETING::ConstTargetHandle_t const       i_pecTarget,
    bool&                                      o_iopBifurcate,
    TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type& o_disabledPhbsMask);
#elif CONFIG_DYNAMIC_BIFURCATION
errlHndl_t _queryIopsToBifurcateAndPhbsToDisable(
    TARGETING::ConstTargetHandle_t const       i_pecTarget,
    bool&                                      o_iopBifurcate,
    TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type& o_disabledPhbsMask)
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        ENTER_MRK "_queryIopsToBifurcateAndPhbsToDisable: PEC target "
        "HUID = 0x%08X.", i_pecTarget ?
            i_pecTarget->getAttr<TARGETING::ATTR_HUID>() : 0);

    errlHndl_t pError = NULL;
    o_iopBifurcate = false;
    o_disabledPhbsMask = 0;

    do {

    // Extension point to return bifurcated IOPs and PHBs to disable.
    // Assuming no extensions are added, the function returns no IOPs to
    // bifurcate and no PHBs to disable

    // If implemented, this function should only return error on software code
    // bug.  Any other condition should result in IOPs not being bifurcated and
    // host taking care of that condition.

    } while(0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        EXIT_MRK "_queryIopsToBifurcateAndPhbsToDisable: EID = 0x%08X, "
        "PLID = 0x%08X, RC = 0x%08X.",
        ERRL_GETEID_SAFE(pError),ERRL_GETPLID_SAFE(pError),
        ERRL_GETRC_SAFE(pError));

    return pError;
}

#endif

/******************************************************************
* compareChipUnits
*
* Check if chip unit of l_t1 > l_t2
*
*******************************************************************/
bool compareChipUnits(TARGETING::Target *l_t1,
                      TARGETING::Target *l_t2)
{
    bool l_result = false;
    assert((l_t1 != NULL) && (l_t2 != NULL));

    l_result = l_t1->getAttr<TARGETING::ATTR_CHIP_UNIT>() >
               l_t2->getAttr<TARGETING::ATTR_CHIP_UNIT>();

    return l_result;
}

/******************************************************************
* setup_pcie_iovalid_enable
*
* Setup ATTR_PROC_PCIE_IOVALID_ENABLE on i_procTarget's PEC children
*
*******************************************************************/
void setup_pcie_iovalid_enable(const TARGETING::Target * i_procTarget)
{
    // Get list of PEC chiplets downstream from the given proc chip
    TARGETING::TargetHandleList l_pecList;

    getChildAffinityTargetsByState( l_pecList,
                                    i_procTarget,
                                    TARGETING::CLASS_NA,
                                    TARGETING::TYPE_PEC,
                                    TARGETING::UTIL_FILTER_ALL);

    for (auto l_pecTarget : l_pecList)
    {
        // Get list of PHB chiplets downstream from the given PEC chiplet
        TARGETING::TargetHandleList l_phbList;

        getChildAffinityTargetsByState( l_phbList,
                   const_cast<TARGETING::Target*>(l_pecTarget),
                   TARGETING::CLASS_NA,
                   TARGETING::TYPE_PHB,
                   TARGETING::UTIL_FILTER_ALL);

        // default to all invalid
        ATTR_PROC_PCIE_IOVALID_ENABLE_type l_iovalid = 0;

        // arrange phb targets from largest to smallest based on unit
        // ex.  PHB5, PHB4, PHB3
        std::sort(l_phbList.begin(),l_phbList.end(),compareChipUnits);
        for(uint32_t k = 0; k<l_phbList.size(); ++k)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PHB>
             l_fapi_phb_target(l_phbList[k]);

            if(l_fapi_phb_target.isFunctional())
            {
                TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "PHB%d functional",
                      (l_phbList[k])->getAttr<TARGETING::ATTR_CHIP_UNIT>());

                // filled in bitwise, largest PHB unit on the right to smallest
                // leftword. ex. l_iovalid = 0b00000110 : PHB3, PHB4 functional
                // PHB5 not
                l_iovalid |= (1<<k);
            }
            else
            {
                TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "PHB%d not functional",
                      (l_phbList[k])->getAttr<TARGETING::ATTR_CHIP_UNIT>());
            }
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                 "PROC %.8X PEC%d -> ATTR_PROC_PCIE_IOVALID_ENABLE: 0x%02X",
                 TARGETING::get_huid(i_procTarget),
                 l_pecTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>(),
                 l_iovalid);

        l_pecTarget->setAttr
              <TARGETING::ATTR_PROC_PCIE_IOVALID_ENABLE>(l_iovalid);
    }
}


//*****************************************************************************
// computeProcPcieConfigAttrs
//******************************************************************************
errlHndl_t computeProcPcieConfigAttrs(TARGETING::Target * i_pProcChipTarget)
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        ENTER_MRK "computeProcPcieConfigAttrs: Proc chip target HUID = "
        "0x%08X.",
        i_pProcChipTarget ?
            i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>() : 0);

    // Currently there are three PEC config tables for procs with 48 usable PCIE
    // lanes. In general, the code accumulates the current configuration of
    // the PECs from the MRW and other dynamic information(such as bifurcation)
    // then matches that config to one of the rows in the table.  Once a match
    // is discovered, the PEC config value is  pulled from the matching row and
    // set in the attributes.
    const laneConfigRow pec0_laneConfigTable[] =
        {{{LANE_WIDTH_NC,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC},
           0x00,PHB_MASK_NA,
           PHB_X16_MAC_MAP},

         {{LANE_WIDTH_16X,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC},
           0x00,PHB0_MASK,
           PHB_X16_MAC_MAP},
        };

    const laneConfigRow pec1_laneConfigTable[] =
        {{{LANE_WIDTH_NC,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC},
           0x00,PHB_MASK_NA,
           PHB_X8_X8_MAC_MAP},

         {{LANE_WIDTH_8X,
           LANE_WIDTH_NC,
           LANE_WIDTH_8X,
           LANE_WIDTH_NC},
           0x00,PHB1_MASK|PHB2_MASK,
           PHB_X8_X8_MAC_MAP},

         {{LANE_WIDTH_8X,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC},
           0x00,PHB1_MASK,
           PHB_X8_X8_MAC_MAP},

         {{LANE_WIDTH_NC,
           LANE_WIDTH_NC,
           LANE_WIDTH_8X,
           LANE_WIDTH_NC},
           0x00,PHB2_MASK,
           PHB_X8_X8_MAC_MAP},
        };

    const laneConfigRow pec2_laneConfigTable[] =
        {{{LANE_WIDTH_NC,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC},
           0x00,PHB_MASK_NA,
           PHB_X16_MAC_MAP},

         {{LANE_WIDTH_16X,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC,
           LANE_WIDTH_NC},
           0x00,PHB3_MASK,
           PHB_X16_MAC_MAP},

         {{LANE_WIDTH_8X,
           LANE_WIDTH_NC,
           LANE_WIDTH_8X,
           LANE_WIDTH_NC},
           0x10,PHB3_MASK|PHB4_MASK,
           PHB_X8_X8_MAC_MAP},

         {{LANE_WIDTH_8X,
           LANE_WIDTH_NC,
           LANE_WIDTH_4X,
           LANE_WIDTH_4X},
           0x20,PHB3_MASK|PHB4_MASK|PHB5_MASK,
           PHB_X8_X4_X4_MAC_MAP},
        };

    const laneConfigRow* pec0_end = pec0_laneConfigTable +
        (  sizeof(pec0_laneConfigTable)
         / sizeof(pec0_laneConfigTable[0]));

    const laneConfigRow* pec1_end = pec1_laneConfigTable +
        (  sizeof(pec1_laneConfigTable)
         / sizeof(pec1_laneConfigTable[0]));

    const laneConfigRow* pec2_end = pec2_laneConfigTable +
        (  sizeof(pec2_laneConfigTable)
         / sizeof(pec2_laneConfigTable[0]));

    errlHndl_t pError = NULL;
    const laneConfigRow* pLaneConfigTableBegin = NULL;
    const laneConfigRow* pLaneConfigTableEnd = NULL;
    TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type procPhbActiveMask = 0;

    do
    {
        assert((i_pProcChipTarget != NULL),"computeProcPcieConfigs was "
            "passed in a NULL processor target");

        const TARGETING::ATTR_CLASS_type targetClass
            = i_pProcChipTarget->getAttr<TARGETING::ATTR_CLASS>();
        const TARGETING::ATTR_TYPE_type targetType
            = i_pProcChipTarget->getAttr<TARGETING::ATTR_TYPE>();
        const bool targetPresent =
            i_pProcChipTarget->getAttr<TARGETING::ATTR_HWAS_STATE>()
                .present;

        assert(((targetClass == TARGETING::CLASS_CHIP)
           || (targetType == TARGETING::TYPE_PROC)
           || (targetPresent)),"computeProcPcieConfigs - input either not a "
            "processor chip or not present");

        // Set up vector of PECs under this processor
        PredicateCTM predPec(CLASS_UNIT, TYPE_PEC);
        TargetHandleList l_pecList;
        targetService().getAssociated(l_pecList,
                                      i_pProcChipTarget,
                                      TargetService::CHILD,
                                      TargetService::ALL,
                                      &predPec);

        // Even if the list is empty we still want to go to the bottom of the
        // fucntion and set PROC_PHB_ACTIVE_MASK

        // Iterate over every PEC to find its config, swap, reversal and
        // bifurcation attributes
        for(TargetHandleList::iterator l_pPecIt = l_pecList.begin();
               l_pPecIt != l_pecList.end(); ++l_pPecIt)
        {
            TargetHandle_t l_pec = *l_pPecIt;
            // Get the PEC id
            uint8_t l_pecID = l_pec->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            // Select the correct PEC config table
            if(l_pecID == 0)
            {
                pLaneConfigTableBegin = pec0_laneConfigTable;
                pLaneConfigTableEnd = pec0_end;
            }
            else if (l_pecID == 1)
            {
                pLaneConfigTableBegin = pec1_laneConfigTable;
                pLaneConfigTableEnd = pec1_end;
            }
            else if (l_pecID == 2)
            {
                pLaneConfigTableBegin = pec2_laneConfigTable;
                pLaneConfigTableEnd = pec2_end;
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    ERR_MRK "computeProcPcieConfigAttrs> "
                    "Code bug! Unsupported PEC ID attribute for "
                    "processor with HUID of 0x%08X.  Expected 0,1 or 2, but "
                    "read a value of %d. PROC_PCIE_NUM_PEC is %d.",
                    i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>(),l_pecID,
                    i_pProcChipTarget->getAttr
                        <TARGETING::ATTR_PROC_PCIE_NUM_PEC>());

                /*@
                 * @errortype
                 * @moduleid         MOD_COMPUTE_PCIE_CONFIG_ATTRS
                 * @reasoncode       RC_INVALID_ATTR_VALUE
                 * @userdata1[0:15]  Target's HUID
                 * @userdata1[16:31] PEC id number
                 * @userdata2[32:63] ATTR_PROC_PCIE_NUM_PEC attribute value
                 * @devdesc          Illegal ATTR_PROC_PCIE_NUM_PEC attribute
                 *                   read from a processor chip target.
                 * @custdesc         A problem isolated to firmware or firmware
                 *                   customization occurred during the IPL of
                 *                   the system.
                 */
                pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    MOD_COMPUTE_PCIE_CONFIG_ATTRS,
                    RC_INVALID_ATTR_VALUE,
                    TWO_UINT32_TO_UINT64(TWO_UINT16_TO_UINT32(
                        i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>(),
                        l_pecID),
                        i_pProcChipTarget->getAttr<
                            TARGETING::ATTR_PROC_PCIE_NUM_PEC>()),
                    0,
                    true);
                ERRORLOG::ErrlUserDetailsTarget(i_pProcChipTarget)
                    .addToLog(pError);
                pError->collectTrace(ISTEP_COMP_NAME);
                break;
            }

            TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type disabledPhbs = 0;

            TARGETING::ATTR_PROC_PCIE_LANE_MASK_type
              effectiveLaneMask = {0};

            TARGETING::ATTR_PEC_PCIE_IOP_REVERSAL_type
              effectiveLaneReversal = {0};

            TARGETING::ATTR_PROC_PCIE_IOP_SWAP_type
              effectiveLaneSwap = 0;

            //Only attempt to determine the lane config on FSPless systems
            //On FSP based systems it has already been determined
            if (!INITSERVICE::spBaseServicesEnabled())
            {
#if CONFIG_DYNAMIC_BIFURCATION
                // Figure out which IOPs need bifurcation, and as a
                // result, which PHBs to disable
                bool iopBifurcate = false;
                pError = _queryIopsToBifurcateAndPhbsToDisable(
                                                               l_pec,
                                                               iopBifurcate,
                                                               disabledPhbs);
                if(pError!=NULL)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              ERR_MRK "computeProcPcieConfigAttrs> "
                              "Failed in call to"
                              "_queryIopsToBifurcateAndPhbsToDisable; "
                              "Proc HUID = 0x%08X.",
                              i_pProcChipTarget->getAttr
                              <TARGETING::ATTR_HUID>());
                    break;
                }
#endif

                TARGETING::ATTR_PEC_PCIE_LANE_MASK_NON_BIFURCATED_type
                  laneMaskNonBifurcated = {0};
                assert(l_pec->tryGetAttr<
                         TARGETING::ATTR_PEC_PCIE_LANE_MASK_NON_BIFURCATED>(
                         laneMaskNonBifurcated),"Failed to get "
                         "ATTR_PEC_PCIE_LANE_MASK_NON_BIFURCATED attribute");


                memcpy(effectiveLaneMask,laneMaskNonBifurcated,
                       sizeof(effectiveLaneMask));

#if CONFIG_DYNAMIC_BIFURCATION
                // Apply any IOP bifurcation settings
                if (iopBifurcate)
                {
                    TARGETING::ATTR_PEC_PCIE_LANE_MASK_BIFURCATED_type
                      laneMaskBifurcated = {0};
                    assert(l_pec->tryGetAttr<
                           TARGETING::ATTR_PEC_PCIE_LANE_MASK_BIFURCATED>(
                           laneMaskBifurcated),"Failed to get "
                           "ATTR_PEC_PCIE_LANE_MASK_BIFURCATED attribute");

                    TARGETING::ATTR_PEC_PCIE_IOP_REVERSAL_BIFURCATED_type
                      laneReversalBifurcated = {0};
                    assert(l_pec->tryGetAttr<
                           TARGETING::ATTR_PEC_PCIE_IOP_REVERSAL_BIFURCATED>(
                           laneReversalBifurcated),"Failed to get "
                           "ATTR_PEC_PCIE_IOP_REVERSAL_BIFURCATED attribute");

                    TARGETING::ATTR_PEC_PCIE_IOP_SWAP_BIFURCATED_type
                      bifurcatedSwap = 0;
                    assert(l_pec->tryGetAttr<
                           TARGETING::ATTR_PEC_PCIE_IOP_SWAP_BIFURCATED>(
                           bifurcatedSwap),"Failed to get "
                           "ATTR_PEC_PCIE_IOP_SWAP_BIFURCATED attribute");

                    memcpy(
                           &effectiveLaneReversal[0],
                           &laneReversalBifurcated[0],
                           sizeof(effectiveLaneReversal)/1);

                    memcpy(
                           &effectiveLaneMask[0],
                           &laneMaskBifurcated[0],
                           sizeof(effectiveLaneMask)/1);

                    effectiveLaneSwap = bifurcatedSwap;

                    l_pec->setAttr<
                      TARGETING::ATTR_PROC_PCIE_IOP_SWAP>(effectiveLaneSwap);

                    l_pec->setAttr<
                      TARGETING::ATTR_PEC_PCIE_IOP_REVERSAL>(effectiveLaneReversal);
                }
#endif

                l_pec->setAttr<
                  TARGETING::ATTR_PROC_PCIE_LANE_MASK>(effectiveLaneMask);

            }
            else
            {
                assert(l_pec->tryGetAttr<
                       TARGETING::ATTR_PROC_PCIE_LANE_MASK>(effectiveLaneMask),
                       "Failed to get ATTR_PROC_PCIE_LANE_MASK attribute");

                // While we aren't using the attribute in this function, we
                // should still make sure swap and reversal are set
                assert(l_pec->tryGetAttr<
                       TARGETING::ATTR_PROC_PCIE_IOP_SWAP>(effectiveLaneSwap),
                       "Failed to get ATTR_PROC_PCIE_IOP_SWAP attribute");

                assert(l_pec->tryGetAttr<
                       TARGETING::ATTR_PEC_PCIE_IOP_REVERSAL>
                       (effectiveLaneReversal),
                       "Failed to get ATTR_PEC_PCIE_IOP_REVERSAL attribute");
            }

            TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type pecPhbActiveMask = 0;
            TARGETING::ATTR_PROC_PCIE_IOP_CONFIG_type iopConfig = 0;
            TARGETING::ATTR_PROC_PCIE_REFCLOCK_ENABLE_type refEnable = 0;
            TARGETING::ATTR_PROC_PCIE_PCS_SYSTEM_CNTL_type macCntl = 0;

            laneConfigRow effectiveConfig =
                  {{LANE_WIDTH_NC,
                   LANE_WIDTH_NC,
                   LANE_WIDTH_NC,
                   LANE_WIDTH_NC},
                    0x00,PHB_MASK_NA,
                    PHB_X16_MAC_MAP,
                   };

            // Transform effective config to match lane config table format
            for(size_t laneGroup = 0;
                laneGroup < MAX_LANE_GROUPS_PER_PEC;
                 ++laneGroup)
            {
                effectiveConfig.laneSet[laneGroup].width
                    = _laneMaskToLaneWidth(effectiveLaneMask[laneGroup]);
            }

            const laneConfigRow* laneConfigItr =
                std::find(
                    pLaneConfigTableBegin,
                    pLaneConfigTableEnd,
                    effectiveConfig);

            if(laneConfigItr != pLaneConfigTableEnd)
            {
                iopConfig = laneConfigItr->laneConfig;
                refEnable = 0x1;
                macCntl = laneConfigItr->phb_to_pcieMAC;
                pecPhbActiveMask = laneConfigItr->phbActive;

                // If we find a valid config, and the PHB_MASK is still NA
                // that means all PHB's on this PEC will be disabled. Lets
                // trace something out just so someone knows.
                if(pecPhbActiveMask == PHB_MASK_NA)
                {
                     TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Valid "
                     "configuration found for PEC 0x%08X, but no PHBs behind "
                     "it wil be functional", l_pecID);
                }

                // Disable applicable PHBs
                pecPhbActiveMask &= (~disabledPhbs);
                // Add the PEC phb mask to the overall Proc PHB mask
                procPhbActiveMask |= pecPhbActiveMask;

            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    ERR_MRK "computeProcPcieConfigAttrs> "
                    "Code bug! PEC PCIE IOP configuration not found. "
                    "Continuing with no PHBs active on PEC 0x%08X. "
                    "Lane set 0: Lane mask = 0x%04X "
                    "Lane set 1: Lane mask = 0x%04X "
                    "Lane set 2: Lane mask = 0x%04X "
                    "Lane set 3: Lane mask = 0x%04X ",
                    l_pecID,
                    effectiveLaneMask[0],
                    effectiveLaneMask[1],
                    effectiveLaneMask[2],
                    effectiveLaneMask[3]);
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "PEC chip target number 0x%08X, HUID = 0x%08X.",
                    l_pecID, l_pec->getAttr<TARGETING::ATTR_HUID>());
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Proc chip target HUID = 0x%08X.",
                    i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>());
                /*@
                 * @errortype
                 * @moduleid         MOD_COMPUTE_PCIE_CONFIG_ATTRS
                 * @reasoncode       RC_INVALID_CONFIGURATION
                 * @userdata1[0:31]  Target processor chip's HUID
                 * @userdata1[32:63] Target PEC HUID
                 * @userdata2[0:15]  PEC lane set 0 lane mask
                 * @userdata2[16:31] PEC lane set 1 lane mask
                 * @userdata2[32:47] PEC lane set 2 lane mask
                 * @userdata2[48:63] PEC lane set 3 lane mask
                 * @devdesc          No valid PCIE IOP configuration found.  All
                 *                   PHBs on this PEC will be disabled.
                 * @custdesc         A problem isolated to firmware or firmware
                 *                   customization occurred during the IPL of
                 *                   the system.
                 */
                pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    MOD_COMPUTE_PCIE_CONFIG_ATTRS,
                    RC_INVALID_CONFIGURATION,
                    TWO_UINT32_TO_UINT64(
                        i_pProcChipTarget->getAttr<TARGETING::ATTR_HUID>(),
                        l_pec->getAttr<TARGETING::ATTR_HUID>()),
                    TWO_UINT32_TO_UINT64(
                        TWO_UINT16_TO_UINT32(
                        effectiveLaneMask[0],
                        effectiveLaneMask[1]),
                        TWO_UINT16_TO_UINT32(
                        effectiveLaneMask[2],
                        effectiveLaneMask[3])),
                    true);
                ERRORLOG::ErrlUserDetailsTarget(i_pProcChipTarget)
                    .addToLog(pError);
                pError->collectTrace(ISTEP_COMP_NAME);
                errlCommit(pError, ISTEP_COMP_ID);
            }

            procPhbActiveMask |= pecPhbActiveMask;
            l_pec->setAttr<
                TARGETING::ATTR_PROC_PCIE_IOP_CONFIG>(iopConfig);
            l_pec->setAttr<
                  TARGETING::ATTR_PROC_PCIE_REFCLOCK_ENABLE>(refEnable);
            l_pec->setAttr<
                  TARGETING::ATTR_PROC_PCIE_PCS_SYSTEM_CNTL>(macCntl);

        }// PEC loop

        // Set the procPhbActiveMask
        i_pProcChipTarget->setAttr<
            TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE>(procPhbActiveMask);

        // Only deconfigure the PHB's once we have the phbActiveMask attribute
        // set up for the whole processor
        (void)_deconfigPhbsBasedOnPhbMask(
             i_pProcChipTarget,
             procPhbActiveMask);

        // setup ATTR_PROC_PCIE_IOVALID_ENABLE for this processor
        // This has to be done after the PHB's are disabled
        setup_pcie_iovalid_enable(i_pProcChipTarget);

    } while(0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        EXIT_MRK "computeProcPcieConfigAttrs: EID = 0x%08X, PLID = 0x%08X, "
        "RC = 0x%08X.",
        ERRL_GETEID_SAFE(pError),ERRL_GETPLID_SAFE(pError),
        ERRL_GETRC_SAFE(pError));

    return pError;
}

};
