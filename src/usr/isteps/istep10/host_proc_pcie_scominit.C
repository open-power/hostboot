/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/host_proc_pcie_scominit.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#include <targeting/targplatutil.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <devicefw/userif.H>
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
// _deconfigPhbsBasedOnPhbActive
//******************************************************************************

void _deconfigPhbsBasedOnPhbActive(
    TARGETING::ConstTargetHandle_t const i_pecTarget,
    TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_typeStdArr& io_phbActive)
{
    uint8_t l_phbNum = 0;
    errlHndl_t l_err = nullptr;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        ENTER_MRK "_deconfigPhbsBasedOnPhbActive: Proc target HUID = 0x%08X,"
        " PHB active value = 0x%02X.", TARGETING::get_huid(i_pecTarget), io_phbActive);

    // Get pec chip's PHB units
    TARGETING::TargetHandleList l_phbList;
    (void)TARGETING::getChildChiplets(
        l_phbList, i_pecTarget, TARGETING::TYPE_PHB, false);

    // io_phbActive is a 3 x uint8 array where each array entry is 1 (Active) or 0 (inactive)
    // for (PHB0 , PHB1 , PHB2) for the given PEC the attribute is associated with
    for (auto const & l_phb : l_phbList)
    {
        // Get the PHB unit number
        l_phbNum = l_phb->getAttr<TARGETING::ATTR_CHIP_UNIT>();

        //First check if this particular PHB is indicated as active
        //via the PHB Active attribute
        if (io_phbActive[l_phbNum % io_phbActive.size()] == 0)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "PHB %d on PEC %d has been found INACTIVE. Deconfiguring PHB %d.",
                  l_phbNum, i_pecTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>(), l_phbNum);

            l_err = HWAS::theDeconfigGard().deconfigureTarget(
                 *l_phb, HWAS::DeconfigGard::DECONFIGURED_BY_PHB_DECONFIG);

            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                    "_deconfigPhbsBasedOnPhbMask: Error deconfiguring PHB "
                    "%d  on PEC %d.", l_phbNum,
                    i_pecTarget->getAttr<TARGETING::ATTR_HUID>());

                ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
            }
        }
        else
        {
            // PHB is marked active, check if it is non-functional.
            // if so, then mark it inactive in the phbActive Attribute.
            if (!l_phb->getAttr<ATTR_HWAS_STATE>().functional)
            {
                io_phbActive[l_phbNum % io_phbActive.size()] = 0;
            }
        }
    } // PHB loop

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        EXIT_MRK "_deconfigPhbsBasedOnPhbActive: io_phbActive = 0x%02X",
        io_phbActive);

    return;
}

//******************************************************************************
// _modifyPhbsBasedonNVME
//******************************************************************************

void _modifyPhbActiveBasedonNVME(
    TARGETING::ConstTargetHandle_t const i_pecTarget,
    TARGETING::ConstTargetHandle_t const i_procTarget,
    TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_typeStdArr& io_phbActive)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        ENTER_MRK "_modifyPhbsBasedonNVME: Proc target HUID = 0x%08X,"
        " PHB active value = 0x%02X.", TARGETING::get_huid(i_pecTarget), io_phbActive);

    TARGETING::Target* l_nodeTgt = TARGETING::UTIL::getCurrentNodeTarget();
    const auto i_nvmeCcin = l_nodeTgt->getAttr<ATTR_PCIE_NVME_CCIN>();
    const auto i_nvmeConfig = l_nodeTgt->getAttrAsStdArr<ATTR_PCIE_NVME_PHB_CONFIG>();

    uint8_t l_procNum = i_procTarget->getAttr<ATTR_POSITION>();
    //Get Unique PEC Number for this PEC within the NODE -- This is will be used as an entry
    // the PCIE_NVME_PHB_CONFIG to find the right bits for this particular PEC target
    uint8_t l_pecNum = (l_procNum * NUM_PECS_PER_PROC) + i_pecTarget->getAttr<ATTR_CHIP_UNIT>();

    for (auto const & l_nvmeEntry : i_nvmeConfig)
    {
        //Check if installed NVME backplane has any entries in PCIE_NVME_PHB_CONFIG
        //  so any requisite PHBs can be disabled
        if (i_nvmeCcin == l_nvmeEntry[0])
        {
            //Check if any of PHB0/PHB1/PHB2 are listed in the entry for this particular PEC
            uint64_t l_phbMask = PHB_ANY_MASK >> (l_pecNum * (io_phbActive.size() + 1));
            if (l_nvmeEntry[1] & l_phbMask)
            {
                //Isolate Specific PHBs to update the io_phbActive attribute
                uint64_t l_phb0Mask = PHB0_MASK >> (l_pecNum * (io_phbActive.size() + 1));
                uint64_t l_phb1Mask = PHB1_MASK >> (l_pecNum * (io_phbActive.size() + 1));
                uint64_t l_phb2Mask = PHB2_MASK >> (l_pecNum * (io_phbActive.size() + 1));

                if (l_nvmeEntry[1] & l_phb0Mask)
                {
                    if (io_phbActive[0])
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                  "Disabling PHB0 on PEC:0x%x due to NVME Backplane Settings",
                                  l_pecNum );
                        //Disable PHB in Active Attribute
                        io_phbActive[0] = 0;
                    }
                }
                if (l_nvmeEntry[1] & l_phb1Mask)
                {
                    if (io_phbActive[1])
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                  "Disabling PHB1 on PEC:0x%x due to NVME Backplane Settings",
                                  l_pecNum );
                        //Disable PHB in Active Attribute
                        io_phbActive[1] = 0;
                    }
                }
                if (l_nvmeEntry[1] & l_phb2Mask)
                {
                    if (io_phbActive[2])
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                  "Disabling PHB2 on PEC:0x%x due to NVME Backplane Settings",
                                  l_pecNum );
                        //Disable PHB in Active Attribute
                        io_phbActive[2] = 0;
                    }
                }
            }
            //No need to look at other entries since this entry was found
            break;
        }
    }

    return;
}

//******************************************************************************
// computeProcPcieConfigAttrs
//******************************************************************************
errlHndl_t computeProcPcieConfigAttrs(TARGETING::Target * i_pProcChipTarget)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        ENTER_MRK "computeProcPcieConfigAttrs: Proc chip target HUID = "
        "0x%08X.", TARGETING::get_huid(i_pProcChipTarget));

    errlHndl_t pError = nullptr;

    do
    {
        //Validate we are in a good state to begin
        assert((i_pProcChipTarget != nullptr),"computeProcPcieConfigs was "
            "passed in a nullptr processor target");

        const TARGETING::ATTR_CLASS_type targetClass
            = i_pProcChipTarget->getAttr<TARGETING::ATTR_CLASS>();
        const TARGETING::ATTR_TYPE_type targetType
            = i_pProcChipTarget->getAttr<TARGETING::ATTR_TYPE>();
        const bool targetPresent =
            i_pProcChipTarget->getAttr<TARGETING::ATTR_HWAS_STATE>()
                .present;

        assert(((targetClass == TARGETING::CLASS_CHIP)
           && (targetType == TARGETING::TYPE_PROC)
           && (targetPresent)),"computeProcPcieConfigs - input either not a "
            "processor chip or not present");

        // Set up vector of functional PECs under this processor
        TargetHandleList l_pecList;
        (void)TARGETING::getChildChiplets(
                             l_pecList, i_pProcChipTarget, TARGETING::TYPE_PEC);

        // Iterate over every PEC to find its "BASE" settings
        for(auto l_pec : l_pecList)
        {
            //Get Base Attribute Settings
            auto l_phb_active = l_pec->getAttrAsStdArr<ATTR_PROC_PCIE_PHB_ACTIVE_BASE>();
            auto l_phb_lane = l_pec->getAttrAsStdArr<ATTR_PROC_PCIE_LANE_REVERSAL_BASE>();

           //Modify Active Settings Based on NVME Backplane Data
           //  The deconfiguration of these possibly now inactive PHBs happens in the next
           //     step: _deconfigPhbsBasedOnPhbActive()
           _modifyPhbActiveBasedonNVME(l_pec, i_pProcChipTarget, l_phb_active);

           //Modify Active Settings based on Non-Functional Targets +
           //   Deconfigure Targets based on Inactive PHB Settings
           _deconfigPhbsBasedOnPhbActive(l_pec, l_phb_active);

           //Set Attribute so HWP has reflection of PHB configuration
           l_pec->setAttrFromStdArr<ATTR_PROC_PCIE_PHB_ACTIVE>(l_phb_active);
           l_pec->setAttrFromStdArr<ATTR_PROC_PCIE_LANE_REVERSAL>(l_phb_lane);
        }

    } while(0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        EXIT_MRK "computeProcPcieConfigAttrs: Proc chip target HUID = "
        "0x%08X.", TARGETING::get_huid(i_pProcChipTarget));

    return pError;
}


#if 0 // TODO RTC:250046 -- Delete all unused code when enabling Dynamic Bifurcation


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
    static_assert(
        (sizeof(ATTR_PEC_PCIE_HX_KEYWORD_DATA_type) >= sizeof(hxKwdData)),
        "createElogFromHxKeywordRc: sizeof(i_hxKeywordData) is less than "
        "hxKwdData size");
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
    // hold off deconfigure so hwsv will create a dummy record which
    // will persist and prevent an infinite reconfig loop
    l_pError->addHwCallout(i_pecTarget,
                           HWAS::SRCI_PRIORITY_LOW,
                           HWAS::DELAYED_DECONFIG,
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
/* FIXME RTC: 210975
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
*/

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                 "PROC %.8X PEC%d -> ATTR_PROC_PCIE_IOVALID_ENABLE: 0x%02X",
                 TARGETING::get_huid(i_procTarget),
                 l_pecTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>(),
                 l_iovalid);

        l_pecTarget->setAttr
              <TARGETING::ATTR_PROC_PCIE_IOVALID_ENABLE>(l_iovalid);
    }
}


#endif // TODO RTC:250046


};
