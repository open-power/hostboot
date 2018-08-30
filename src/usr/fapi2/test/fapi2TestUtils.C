/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2TestUtils.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
///
/// @file fapi2TestUtils.C
///
/// @brief FAPI2 utility functions
///
/// Note that platform code must provide the implementation.
///

#include <fapi2.H>
#include "fapi2TestUtils.H"

#define RESET_EPATH_TO_MASTER \
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath); \
    assert(TARGETING::targetService().toTarget(l_epath) != nullptr, \
           "sys0node0proc0 should be valid according to system xml"); \

#define CAT(a,b) a b
#define VAL(str) #str

#define GENERATE_TARGET(PLAT_TARGET_TYPE, EPATH_STRING, TARGET_TEST_ENUM, POS) \
    l_epath.addLast(TARGETING::PLAT_TARGET_TYPE,POS); \
    assert(TARGETING::targetService().toTarget(l_epath) != nullptr, \
          CAT(#EPATH_STRING, " should be valid according to system xml")); \
    o_targetList[TARGET_TEST_ENUM] = \
        TARGETING::targetService().toTarget(l_epath);

namespace fapi2
{

void generateTargets(TARGETING::Target* i_pMasterProcChip,
                                    TARGETING::Target* o_targetList[])
{
    TARGETING::EntityPath l_epath;

    // ensure o_targetList is initialized to nullptrs
    for( uint64_t x = 0; x < NUM_TARGETS; x++ )
    {
        o_targetList[x] = nullptr;
    }

    // Start generic P9 Target
    // Use the GENERATE_TARGET macro to generate the target if the pos 0
    // unit exists in the simics test xml. This is true for most targets

    // Set up entity path for proc
    RESET_EPATH_TO_MASTER
    o_targetList[MY_PROC] = i_pMasterProcChip;

    // Setup EQ, EX, and CORE targets which are common among all P9 Chips
    GENERATE_TARGET(TYPE_EQ,sys0node0proc0eq0,MY_EQ,0)
    GENERATE_TARGET(TYPE_EX,sys0node0proc0eq0ex0,MY_EX,0)
    GENERATE_TARGET(TYPE_CORE,sys0node0proc0eq0ex0core0,MY_CORE,0)

    // Reset l_epath to master proc
    RESET_EPATH_TO_MASTER

    //Setup PECs and PHBs
    GENERATE_TARGET(TYPE_PEC,sys0node0proc0pec0,MY_PEC,0)
    GENERATE_TARGET(TYPE_PHB,sys0node0proc0pec0phb0,MY_PHB,0)

    // Reset l_epath to master proc
    RESET_EPATH_TO_MASTER

    //Setup XBUS
    GENERATE_TARGET(TYPE_XBUS,sys0node0proc0xbus1,MY_XBUS,1)

    // Reset l_epath to master proc
    RESET_EPATH_TO_MASTER

    //Setup OBUS, OBUS_BRICK
    GENERATE_TARGET(TYPE_OBUS,sys0node0proc0obus0,MY_OBUS,0)
    GENERATE_TARGET(TYPE_OBUS_BRICK,sys0node0proc0obus0obus_brick0,MY_OBUS_BRICK,0)

    // Reset l_epath to master proc
    RESET_EPATH_TO_MASTER

    //Setup PPE
    GENERATE_TARGET(TYPE_PPE,sys0node0proc0ppe0,MY_PPE,0)

    // Reset l_epath to master proc
    RESET_EPATH_TO_MASTER

    //Setup CAPP
    GENERATE_TARGET(TYPE_CAPP,sys0node0proc0capp0,MY_CAPP,0)

    // Reset l_epath to master proc
    RESET_EPATH_TO_MASTER

    //Setup SBE
    GENERATE_TARGET(TYPE_SBE,sys0node0proc0capp0,MY_SBE,0)

    // Reset l_epath to master proc
    RESET_EPATH_TO_MASTER

    //Setup PERV
    GENERATE_TARGET(TYPE_PERV,sys0node0proc0perv1,MY_PERV,1)

    // End generic P9 Target

    // Reset l_epath to master proc
    RESET_EPATH_TO_MASTER


    // Start System Specific P9 Target

    // See src/usr/targeting/common/xmltohb/simics_NIMBUS.system.xml
    if (TARGETING::MODEL_NIMBUS ==
                i_pMasterProcChip->getAttr<TARGETING::ATTR_MODEL>())
    {
        //Setup MCBIST, MCS, and MCA
        GENERATE_TARGET(TYPE_MCBIST,sys0node0proc0mcbist0,MY_MCBIST,0)
        GENERATE_TARGET(TYPE_MCS,sys0node0proc0mcbist0mcs0,MY_MCS,0)
        GENERATE_TARGET(TYPE_MCA,sys0node0proc0mcbist0mcs0mca0,MY_MCA,0)
    }
    // See src/usr/targeting/common/xmltohb/simics_CUMULUS.system.xml
    else if (TARGETING::MODEL_CUMULUS ==
                i_pMasterProcChip->getAttr<TARGETING::ATTR_MODEL>())
    {
        //Setup MC, MI, DMI
        GENERATE_TARGET(TYPE_MC,sys0node0proc0mc0,MY_MC,0)
        GENERATE_TARGET(TYPE_MI,sys0node0proc0mc0mi0,MY_MI,0)
        GENERATE_TARGET(TYPE_DMI,sys0node0proc0mc0mi0dmi0,MY_DMI,0)

    }
    // See src/usr/targeting/common/xmltohb/simics_AXONE.system.xml
    else if (TARGETING::MODEL_AXONE ==
                i_pMasterProcChip->getAttr<TARGETING::ATTR_MODEL>())
    {
        // Setup MC, MI, MCC, OMI
        GENERATE_TARGET(TYPE_MC,sys0node0proc0mc0,MY_MC,0)
        GENERATE_TARGET(TYPE_MI,sys0node0proc0mc0mi0,MY_MI,0)
        GENERATE_TARGET(TYPE_MCC,sys0node0proc0mc0mi0mcc0,MY_MCC,0)
        GENERATE_TARGET(TYPE_OMI,sys0node0proc0mc0mi0mcc0omi0,MY_OMI,0)

        // Change epath type for both TYPE_OCMB_CHIP and TYPE_MEM_PORT
        // so that targeting service will lookup the paths as type AFFINITY_PATH
        // when looking up the target
        l_epath.setType(TARGETING::EntityPath::PATH_AFFINITY);

        // Setup OCBM_CHIP and MEM_PORT
        GENERATE_TARGET(TYPE_OCMB_CHIP,sys0node0ocmb0,MY_OCMB,0)
        GENERATE_TARGET(TYPE_MEM_PORT,sys0node0ocmb0memport0,MY_MEM_PORT,0)

        // Set l_epath's type back to PATH_PHYSICAL
        l_epath.setType(TARGETING::EntityPath::PATH_PHYSICAL);

        // Remove MEM_PORT, OCMB_CHIP, OMI, MCC, MI (5 targets)
        l_epath.removeLast(); l_epath.removeLast();
        l_epath.removeLast(); l_epath.removeLast();
        l_epath.removeLast();

        // Setup OMIC
        GENERATE_TARGET(TYPE_OMIC,sys0node0proc0mc0omic0,MY_OMIC,0)
    }

    // End System Specific P9 Target
}

bool isHwValid(TARGETING::Target* i_procChip, uint8_t i_hwType)
{
    bool isValid = true;

    // Only need to check model if this is NOT a common target for p9
    if (!(i_hwType == MY_PROC || i_hwType == MY_EQ || i_hwType == MY_EX || i_hwType == MY_CORE ||
        i_hwType == MY_PEC || i_hwType == MY_PHB || i_hwType == MY_XBUS || i_hwType == MY_OBUS ||
        i_hwType == MY_OBUS_BRICK || i_hwType == MY_PPE || i_hwType == MY_PERV || i_hwType == MY_CAPP ||
        i_hwType == MY_SBE))
    {
        auto l_model = i_procChip->getAttr<TARGETING::ATTR_MODEL>();
        if (l_model == TARGETING::MODEL_CUMULUS)
        {
            if (i_hwType == MY_MCS || i_hwType == MY_MCA || i_hwType == MY_MCBIST ||
                i_hwType == MY_OMI || i_hwType == MY_OMIC || i_hwType == MY_MCC ||
                i_hwType == MY_OCMB || i_hwType == MY_MEM_PORT)
            {
                isValid = false;
            }
        }
        else if (l_model == TARGETING::MODEL_NIMBUS)
        {
            if (i_hwType == MY_MC || i_hwType == MY_MI || i_hwType == MY_DMI ||
                i_hwType == MY_OMI || i_hwType == MY_OMIC || i_hwType == MY_MCC ||
                i_hwType == MY_OCMB || i_hwType == MY_MEM_PORT)
            {
                isValid = false;
            }
        }
        else if (l_model == TARGETING::MODEL_AXONE)
        {
            if (i_hwType == MY_MCS || i_hwType == MY_MCA || i_hwType == MY_MCBIST ||
                i_hwType == MY_DMI)
            {
                isValid = false;
            }
        }
    }
    return isValid;
}

} // End namespace fapi2
