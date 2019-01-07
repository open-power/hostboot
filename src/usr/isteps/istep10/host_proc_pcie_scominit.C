/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/host_proc_pcie_scominit.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
#include <map>

#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <errl/errludattribute.H>
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

// Maps the iop number to a mask which indicates which
// PHB numbers are valid for the given PEC
std::vector<uint8_t> allowablePHBsforPEC =
{
    static_cast<uint8_t>(PHB0_MASK), //PEC0
    (PHB1_MASK|PHB2_MASK),           //PEC1
    (PHB3_MASK|PHB4_MASK|PHB5_MASK)  //PEC2
};

//HX keyword data format
typedef struct {
    uint8_t lane_enabled:1; // if set to 1, then this lane is assiged
                            // to the device (phb) number defined by the
                            // next 3 bits
    uint8_t deviceId:3;     // phb number
    uint8_t reserve:4;
}LaneEntry_t;

typedef struct {
    uint8_t version;
    uint8_t laneSetCount;  // how many lane set definitions
    LaneEntry_t laneEntry[7];
}hxKeywordData;


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
    TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type& io_phbActiveMask)
{
    uint8_t l_phbNum = 0;
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        ENTER_MRK "_deconfigPhbsBasedOnPhbMask: Proc target HUID = "
        "0x%08X, PHB active mask = 0x%02X.", i_procTarget ?
        i_procTarget->getAttr<TARGETING::ATTR_HUID>() : 0, io_phbActiveMask);

    // PHB mask bits start at the left most bit - so we must shift the bits
    // right in order to get the correct masks. This number below should
    // always be 7.
    const size_t bitsToRightShift =
        (sizeof(io_phbActiveMask) * BITS_PER_BYTE) - 1;

    // Get every PEC under the Proc
    TARGETING::TargetHandleList l_pecList;
    (void)TARGETING::getChildChiplets(
        l_pecList, i_procTarget, TARGETING::TYPE_PEC, false);

    for (auto const & l_pec : l_pecList)
    {
        // Get pec chip's PHB units
        TARGETING::TargetHandleList l_phbList;
        (void)TARGETING::getChildChiplets(
            l_phbList, l_pec, TARGETING::TYPE_PHB, false);

        // io_phbActiveMask is a bitmask whose leftmost bit corresponds to
        // PHB0, followed by bits for PHB1, PHB2, PHB3, PHB4, and PBH5. The
        // remaining bits are ignored. We need to compare each PHB mask to
        // its respective PHB and deconfigure it if needed.
        for (auto const & l_phb : l_phbList)
        {
            // Get the PHB unit number
            l_phbNum = l_phb->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            // Subtract the PHB unit number from the constant bitsToRightShift
            // in order to get the correct amount of bits to shift right.
            // e.g. for PHB0, the unit number is 0, bitsToRightShift-0 = 7.
            // We will shift io_phbActiveMask 7 bits right, which means we are
            // examining bit 0 of the PHB mask. If it is not set - deconfigure
            // the respective PHB
            if (!((io_phbActiveMask >> (bitsToRightShift - l_phbNum)) & 1))
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "PHB %d on PEC %d has been found INACTIVE. Deconfiguring "
                    "PHB %d.", l_phbNum,
                    l_pec->getAttr<TARGETING::ATTR_CHIP_UNIT>(), l_phbNum);

                l_err = HWAS::theDeconfigGard().deconfigureTarget(
                     *l_phb, HWAS::DeconfigGard::DECONFIGURED_BY_PHB_DECONFIG);

                if (l_err)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                        "_deconfigPhbsBasedOnPhbMask: Error deconfiguring PHB "
                        "%d  on PEC %d.", l_phbNum,
                        l_pec->getAttr<TARGETING::ATTR_HUID>());

                    ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);

                    // Try to deconfigure any other PHBs
                    delete l_err;
                    l_err = NULL;
                }
            }
            else
            {
                // PHB is marked active, check if it is non-functional.
                // if so, then mark it inactive in the phbActiveMask.
                if (!l_phb->getAttr<ATTR_HWAS_STATE>().functional)
                {
                    io_phbActiveMask &= ~(1 >> (bitsToRightShift - l_phbNum));
                }
            }
        } // PHB loop
    } // PEC loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        EXIT_MRK "_deconfigPhbsBasedOnPhbMask: io_phbActiveMask = 0x%02X",
        io_phbActiveMask);

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

enum hxKeywordRc
{
   KEYWORD_VALID   = 0,
   VERSION_IGNORE_DATA,
   VERSION_NOT_SUPPORTED,
   TOO_MANY_LANE_SETS,
   INVALID_DEVICE_NUMBER
};

// parse the hx keyword data into a useable lane mask
hxKeywordRc getLaneMaskFromHxKeyword( ATTR_PEC_PCIE_HX_KEYWORD_DATA_type &i_kw,
                                     ATTR_PROC_PCIE_LANE_MASK_type& o_laneMask,
                                     uint8_t i_pec_num)
{
    size_t l_keywordSize =
        sizeof(ATTR_PEC_PCIE_HX_KEYWORD_DATA_type);

    hxKeywordRc l_rc = KEYWORD_VALID;

    hxKeywordData l_keyword = {0};

    memcpy (&l_keyword, i_kw, l_keywordSize);


    do
    {
        // This is the most likely case
        // Version 0 means HX Keyword is not set, so use defaults
        // Version 1 is incorrectly set on Bearpaw cards (skip using HX keyword)
        if( l_keyword.version < 2 )
        {
            l_rc = VERSION_IGNORE_DATA;
            break;
        }

        // Currently only version 2 is defined for firmware support
        if( l_keyword.version != 2 )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "HX keyword version %d is not supported yet, "
                "using default lane mask", l_keyword.version );
            l_rc = VERSION_NOT_SUPPORTED;
            break;
        }


        // Even though the HW supports x4 bifurcation on PEC2 (using 3rd lane),
        // our firmware supported HX keyword version only allows for x8 bifurcation.
        // version 1 of the HX keyword spec defines a set of lanes as x8 so
        // we need to make sure that we don't have more than 2 sets of lanes
        // defined per PEC
        if( l_keyword.laneSetCount > 2)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "HX keyword has too many lane sets (%d) defined for this PEC",
                l_keyword.laneSetCount);
            l_rc = TOO_MANY_LANE_SETS;
            break;
        }

        // get a mask to indicate which PHB numbers are supported in this PEC
        assert((i_pec_num < allowablePHBsforPEC.size()),
            "getLaneMaskFromHxKeyword: i_pec_num is over maximum");

        uint8_t validPhbMask = allowablePHBsforPEC[i_pec_num];

        uint8_t l_deviceID = 0xFF;

        for (auto x = 0; x < l_keyword.laneSetCount; ++x)
        {
            if (l_keyword.laneEntry[x].lane_enabled)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "lane set %d assigned to PHB%d",
                        x, l_keyword.laneEntry[x].deviceId);

                if (l_keyword.laneEntry[x].deviceId != l_deviceID)
                {
                    l_deviceID = l_keyword.laneEntry[x].deviceId;

                    if( x == 0 )
                    {
                        // initial setting for this new device
                        o_laneMask[0] = LANE_MASK_X8_GRP0;
                    }
                    else
                    {
                        // x8 bifurcation uses lanes 0 & 2
                        o_laneMask[2] = LANE_MASK_X8_GRP1;
                    }
                }
                else
                {
                    // two adjacent lane masks assigned to
                    // the same device id makes a x16 device
                    o_laneMask[0] = LANE_MASK_X16;
                }

                // sniff test the device id to see if its valid for this PEC
                uint8_t mask = static_cast<uint8_t>(PHB0_MASK) >> l_deviceID;

                if( (mask & validPhbMask) == 0 )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "HX keyword defined deviceId %d which "
                            "is not valid for PEC%d - using default lane mask",
                            l_keyword.laneEntry[x].deviceId, i_pec_num);

                    l_rc = INVALID_DEVICE_NUMBER;
                    break;
                }
            }
        }
    }while(0);
    return l_rc;
}

errlHndl_t createElogFromHxKeywordRc( hxKeywordRc i_rc,
        TARGETING::ConstTargetHandle_t const  i_pecTarget,
        ATTR_PEC_PCIE_HX_KEYWORD_DATA_type i_hxKeywordData )
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Failed to parse the HX keyword RC=%d for %.8X PEC target",
            static_cast<uint32_t>(i_rc), TARGETING::get_huid(i_pecTarget) );

    // fit as much of the hx keyword data into the userdata2 field
    uint64_t hxKwdData = 0;

    // make sure we don't access beyond the boundary of i_hxKeywordData
    // when copying to hxKwdData variable
    static_assert((sizeof(i_hxKeywordData) >= sizeof(hxKwdData)),
        "createElogFromHxKeywordRc: sizeof(i_hxKeywordData) is less than hxKwdData size");
    memcpy(&hxKwdData, i_hxKeywordData, sizeof(hxKwdData));

    /*@
     * @errortype
     * @moduleid         MOD_GET_LANEMASK_FROM_HX_KEYWORD
     * @reasoncode       RC_INVALID_HX_KEYWORD_DATA
     * @userdata1[0:31]  Return code value from parseHxKeyword
     * @userdata1[32:63] PEC target HUID
     * @userdata2        HX keyword data
     * @devdesc          The HX keyword data found in the
     *                   vpd is invalid. See Userdata for specific
     *                   reason.
     *
     * @custdesc         A problem isolated to firmware or firmware
     *                   customization occurred during the IPL of
     *                   the system.
     */
    errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              MOD_GET_LANEMASK_FROM_HX_KEYWORD,
                              RC_INVALID_HX_KEYWORD_DATA,
                              TWO_UINT32_TO_UINT64( i_rc,
                                TARGETING::get_huid(i_pecTarget) ),
                              hxKwdData);

    l_pError->addPartCallout(i_pecTarget,
                             HWAS::VPD_PART_TYPE,
                             HWAS::SRCI_PRIORITY_HIGH);

    l_pError->addHwCallout(i_pecTarget,
                           HWAS::SRCI_PRIORITY_LOW,
                           HWAS::DECONFIG,
                           HWAS::GARD_NULL);

    ERRORLOG::ErrlUserDetailsTarget(i_pecTarget).addToLog(l_pError);

    ERRORLOG::ErrlUserDetailsAttribute(i_pecTarget,
        ATTR_PEC_PCIE_HX_KEYWORD_DATA).addToLog(l_pError);

    l_pError->collectTrace(ISTEP_COMP_NAME);

    return l_pError;
}
/*******************************************************************
 * calculateEffectiveLaneMask
 *
 * Use the data from the HX keyword to calculate the effective lane mask
 * if the HX keyword is empty, or invalid use the default lane mask from
 * mrw.
 *****************************************************************/
errlHndl_t calculateEffectiveLaneMask(
        TARGETING::ConstTargetHandle_t const  i_pecTarget,
        TARGETING::ATTR_PROC_PCIE_LANE_MASK_type& o_effectiveLaneMask)
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            ENTER_MRK "calculateEffectiveLaneMask: PEC target "
            "HUID = 0x%08X.", i_pecTarget ?
            i_pecTarget->getAttr<TARGETING::ATTR_HUID>() : 0);

    errlHndl_t pError = nullptr;

    do {
        // the most likely case is to use the default, we will overwrite it
        // it later if we get good data from the hx keyword
        assert(i_pecTarget->tryGetAttr<
                TARGETING::ATTR_PROC_PCIE_LANE_MASK>(o_effectiveLaneMask),
                "Failed to get ATTR_PROC_PCIE_LANE_MASK attribute");

        if( !(i_pecTarget->getAttr<TARGETING::ATTR_PEC_IS_BIFURCATABLE>()) )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "PHB is not bifurcatable skip reading HX keyword");
            break;
        }

        ATTR_PEC_PCIE_HX_KEYWORD_DATA_type l_hxKeywordData  = {0};

        // grab the HX keyword from the PEC target
        assert(i_pecTarget->tryGetAttr
                    <ATTR_PEC_PCIE_HX_KEYWORD_DATA>(l_hxKeywordData),
                    "HX keyword not found for PEC target");

        TRACFBIN(ISTEPS_TRACE::g_trac_isteps_trace,
                "HX keyword data:",l_hxKeywordData,sizeof(l_hxKeywordData));

        ATTR_PROC_PCIE_LANE_MASK_type l_laneMask = {0};

        // need the PEC number to validate the keyword contents
        uint8_t pec_num = i_pecTarget->getAttr<ATTR_CHIP_UNIT>();

        // parse and validate the keyword data for this pec
        hxKeywordRc l_rc = getLaneMaskFromHxKeyword(
                                                l_hxKeywordData,
                                                l_laneMask,
                                                pec_num);

        if( l_rc == KEYWORD_VALID )
        {
            // overwrite the default mask we setup earlier
            memcpy(o_effectiveLaneMask,l_laneMask,sizeof(l_laneMask));
        }
        else if ( l_rc == VERSION_IGNORE_DATA )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "HX keyword is ignored version, using default lane mask");
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERR>>calculateEffectiveLaneMask()> "
                    "an error occurred while parsing the HX keyword, return "
                    "the error and use default lane mask");
            // create an elog from the rc here
            pError = createElogFromHxKeywordRc(l_rc,
                                               i_pecTarget,
                                               l_hxKeywordData);
        }

    } while(0);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "INF>>calculateEffectiveLaneMask()> "
            "PEC: 0x%08X",
            TARGETING::get_huid(i_pecTarget));
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "     Lane set 0: Lane mask = 0x%04X ",
            o_effectiveLaneMask[0]);
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "     Lane set 1: Lane mask = 0x%04X ",
            o_effectiveLaneMask[1]);
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "     Lane set 2: Lane mask = 0x%04X ",
            o_effectiveLaneMask[2]);
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "     Lane set 3: Lane mask = 0x%04X ",
            o_effectiveLaneMask[3]);;

    return pError;
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
    //
    // Each PEC can control up to 16 lanes:
    // - PEC0 can give 16 lanes to PHB0
    // - PEC1 can split 16 lanes between PHB1 & PHB2
    // - PEC2 can split 16 lanes between PHB3, PHB4 & PHB5
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

    errlHndl_t pError = nullptr;
    const laneConfigRow* pLaneConfigTableBegin = nullptr;
    const laneConfigRow* pLaneConfigTableEnd = nullptr;
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

        // Set up vector of functional PECs under this processor
        TargetHandleList l_pecList;
        (void)TARGETING::getChildChiplets(
                             l_pecList, i_pProcChipTarget, TARGETING::TYPE_PEC);

        // Even if the list is empty we still want to go to the bottom of the
        // function and set PROC_PHB_ACTIVE_MASK

        // Iterate over every PEC to find its config, swap, reversal and
        // bifurcation attributes
        for(auto l_pec : l_pecList)
        {
            // Get the PEC id
            uint8_t l_pecID = l_pec->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            // Select the correct PEC config table
            if      (l_pecID == 0)
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

            //Only attempt to determine the lane config on FSP-less systems
            //On FSP based systems it has already been determined
            if (!INITSERVICE::spBaseServicesEnabled())
            {
#if CONFIG_DYNAMIC_BIFURCATION
                TARGETING::ATTR_PEC_PCIE_IOP_REVERSAL_type
                    effectiveLaneReversal = {0};

                TARGETING::ATTR_PROC_PCIE_IOP_SWAP_type
                    effectiveLaneSwap = 0;


                // Figure out which IOPs need bifurcation, and as a
                // result, which PHBs to disable
                bool iopBifurcate = false;
                pError = _queryIopsToBifurcateAndPhbsToDisable(
                                                               l_pec,
                                                               iopBifurcate,
                                                               disabledPhbs);
                if(pError!=nullptr)
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
                           sizeof(effectiveLaneReversal));

                    memcpy(
                           &effectiveLaneMask[0],
                           &laneMaskBifurcated[0],
                           sizeof(effectiveLaneMask));

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
            else // FSP based
            {
                // PROC_IOP_SWAP defined/set in mrw and is the same
                // for bifurcated and non-bifurcated lane masks
                // so we just need to figure out what the lane mask
                // would be and let the existing function fill in the rest
                // of the interesting attributes.
                pError = calculateEffectiveLaneMask(l_pec,effectiveLaneMask);

                //If there was an error, commit it as unrecoverable and move on
                if (pError != nullptr)
                {
                  errlCommit(pError,ISTEP_COMP_ID);
                }
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
                     TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                     "Valid configuration found for PEC%d, but no PHBs behind "
                     "it will be functional", l_pecID);
                }
                else
                {
                     TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                     "Valid configuration found for PEC%d, "
                     "pecPhbActiveMask = 0x%x", l_pecID, pecPhbActiveMask);

                }

                // Disable applicable PHBs
                pecPhbActiveMask &= (~disabledPhbs);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    ERR_MRK "computeProcPcieConfigAttrs> "
                    "Code bug! PEC PCIE IOP configuration not found. "
                    "Continuing with no PHBs active on PEC%d. "
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

            // Add the PEC phb mask to the overall Proc PHB mask
            procPhbActiveMask |= pecPhbActiveMask;

            l_pec->setAttr<
                TARGETING::ATTR_PROC_PCIE_IOP_CONFIG>(iopConfig);
            l_pec->setAttr<
                  TARGETING::ATTR_PROC_PCIE_REFCLOCK_ENABLE>(refEnable);
            l_pec->setAttr<
                  TARGETING::ATTR_PROC_PCIE_PCS_SYSTEM_CNTL>(macCntl);
        } // PEC loop

        // Deconfigure the PHBs once we have the phbActiveMask attribute
        // set up for the whole processor.  Also, update the phbActiveMask
        // attribute to include gard'd PHBs.
        (void)_deconfigPhbsBasedOnPhbMask(
             i_pProcChipTarget,
             procPhbActiveMask);

        // Set the procPhbActiveMask
        i_pProcChipTarget->setAttr<
            TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE>(procPhbActiveMask);

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
