/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2TestUtils.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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

#define GENERATE_TARGET(PLAT_TARGET_TYPE, EPATH_STRING, TARGET_TEST_ENUM, POS) \
    l_epath.addLast(TARGETING::PLAT_TARGET_TYPE,POS); \
    assert(TARGETING::targetService().toTarget(l_epath) != nullptr, \
           #EPATH_STRING " should be valid according to system xml"); \
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

    // Start generic P10 Target
    // Use the GENERATE_TARGET macro to generate the target if the pos 0
    // unit exists in the simics test xml. This is true for most targets

    // Set up entity path for proc
    RESET_EPATH_TO_MASTER
    o_targetList[MY_PROC] = i_pMasterProcChip;

    // Setup EQ, FC, and CORE targets which are common among all P10 Chips
    GENERATE_TARGET(TYPE_EQ,sys0node0proc0eq0,MY_EQ,0)
    GENERATE_TARGET(TYPE_FC,sys0node0proc0eq0fc0,MY_FC,0)
    GENERATE_TARGET(TYPE_CORE,sys0node0proc0eq0fc0core0,MY_CORE,0)

    // Reset l_epath to master proc
    RESET_EPATH_TO_MASTER

    //Setup PECs and PHBs
    GENERATE_TARGET(TYPE_PEC,sys0node0proc0pec0,MY_PEC,0)
    GENERATE_TARGET(TYPE_PHB,sys0node0proc0pec0phb0,MY_PHB,0)

    // Reset l_epath to master proc
    RESET_EPATH_TO_MASTER

    //Setup PERV
    GENERATE_TARGET(TYPE_PERV,sys0node0proc0perv1,MY_PERV,2)

    // Reset l_epath to master proc
    RESET_EPATH_TO_MASTER

    // Setup MC, MI, MCC, OMI
    GENERATE_TARGET(TYPE_MC,sys0node0proc0mc0,MY_MC,0)
    GENERATE_TARGET(TYPE_MI,sys0node0proc0mc0mi0,MY_MI,0)
    GENERATE_TARGET(TYPE_MCC,sys0node0proc0mc0mi0mcc0,MY_MCC,0)
    GENERATE_TARGET(TYPE_OMI,sys0node0proc0mc0mi0mcc0omi0,MY_OMI,0)

    // Change epath type for both TYPE_OCMB_CHIP and TYPE_MEM_PORT
    // so that targeting service will lookup the paths as type AFFINITY_PATH
    // when looking up the target
    l_epath.setType(TARGETING::EntityPath::PATH_AFFINITY);

    // Setup OCMB_CHIP and MEM_PORT
    GENERATE_TARGET(TYPE_OCMB_CHIP,sys0node0ocmb0,MY_OCMB,0)
    GENERATE_TARGET(TYPE_MEM_PORT,sys0node0ocmb0memport0,MY_MEM_PORT,0)

    // Set l_epath's type back to PATH_PHYSICAL
    l_epath.setType(TARGETING::EntityPath::PATH_PHYSICAL);

    // Remove MEM_PORT, OCMB_CHIP, OMI, MCC, MI (5 targets)
    l_epath.removeLast(); l_epath.removeLast();
    l_epath.removeLast(); l_epath.removeLast();
    l_epath.removeLast();

    // Setup OMICs
    GENERATE_TARGET(TYPE_OMIC,sys0node0proc0mc0omic0,MY_OMIC0,0)
    l_epath.removeLast();
    GENERATE_TARGET(TYPE_OMIC,sys0node0proc0mc0omic1,MY_OMIC1,1)

    // Remove OMIC, MC
    l_epath.removeLast(); l_epath.removeLast();

    // Setup PAUC
    GENERATE_TARGET(TYPE_PAUC,sys0node0proc0pauc0,MY_PAUC,0)
    // Setup IOHS
    GENERATE_TARGET(TYPE_IOHS,sys0node0proc0pauc0iohs0,MY_IOHS,0)
    // Setup IOLINK
    GENERATE_TARGET(TYPE_SMPGROUP,sys0node0proc0pauc0iohs0smpgroup0,MY_IOLINK,0)

    // Remove IOLINK
    l_epath.removeLast();
    // Remove IOHS
    l_epath.removeLast();

    // Setup PAU
    GENERATE_TARGET(TYPE_PAU,sys0node0proc0pauc0pau0,MY_PAU,0)

    // End generic P10 Target
}

bool isHwValid(TARGETING::Target* i_procChip, uint8_t i_hwType)
{
    return true;
}

} // End namespace fapi2
