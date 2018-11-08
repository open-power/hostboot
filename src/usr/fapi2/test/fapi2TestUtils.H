/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2TestUtils.H $                         */
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
/// @file fapi2TestUtils.H
///
/// @brief FAPI2 utility functions
///
/// Note that platform code must provide the implementation.
///

#ifndef FAPI2TESTUTILS_H_
#define FAPI2TESTUTILS_H_

#define EQ_PER_PROC          6
#define EX_PER_EQ            2
#define CORE_PER_EX          2
#define MCS_PER_PROC         4
#define MI_PER_PROC          4
#define MCA_PER_MCS          2
#define DMI_PER_MI           2
#define MCBIST_PER_PROC      2
#define MC_PER_PROC          2
#define MCS_PER_MCBIST       2
#define MI_PER_MC            2
#define PERV_PER_PROC        43
#define XBUS_PER_PROC        1
#define OBUS_PER_PROC        2
#define MCC_PER_MI           2
#define OMI_PER_MCC          2
#define OMIC_PER_MC          3
#define OCMB_PER_OMI         1
#define MEM_PORT_PER_OCMB    1

// Note that OMIC can either have 2 or 3 child OMI
// targets. There are 3 OMIC targets per MC, OMIC0
// and OMIC1 have 3 children, OMIC2 has 2 children
#define MAX_OMI_PER_OMIC     3

#define SIMULATED_GOOD_CORES 4

// non-core and non-cache chiplet ids
#define START_PERV_CHIPLET_NUM        0x01
// CAPI Unit(0,1 => 0x02, 0x04)
#define START_CAPP_CHIPLET_NUM        0x02
// OBUS BRICK ({0-2}, {9,11} => 0x09, 0xC)
#define START_OBUS_BRICK_CHIPLET_NUM  0x09
// XBUS (0, 1 => 0x6)
#define START_XBUS_CHIPLET_NUM        0x06
// MCBIST (0, 1 => 0x07, 0x08)
#define START_MCBIST_CHIPLET_NUM      0x07
// MC (0, 1 => 0x07)
#define START_MC_CHIPLET_NUM          0x07
// MI (0, 1 => 0x07)
#define START_MI_CHIPLET_NUM          0x07
// DMI (0, 3 => 0x07, 0x08)
#define START_DMI_CHIPLET_NUM         0x07
// OMI (0, 16 => 0x07, 0x08)
#define START_OMI_CHIPLET_NUM         0x07
// OMIC (0, 5 => 0x07, 0x08)
#define START_OMIC_CHIPLET_NUM        0x07
// MCC (0, 8 => 0x07, 0x08)
#define START_MCC_CHIPLET_NUM         0x07
// OBUS (0, 3 => 0x09, 0x0C)
#define START_OBUS_CHIPLET_NUM        0x09
// PEC (0, 1, 2 => 0x0D, 0x0E, 0x0F)
#define START_PEC_0_CHIPLET_NUM       0x0D
#define START_PEC_1_CHIPLET_NUM       0x0E
#define START_PEC_2_CHIPLET_NUM       0x0F

// All Cache Chiplets
#define START_EQ_CHIPLET_NUM      0x10

// All Core Chiplets
#define START_CORE_CHIPLET_NUM    0x20

#include <fapi2.H>

namespace fapi2
{

//Used by generateTargets to get a list of all platform target
// types that directly relate to fapi2 target types
// NOTE: KEEP THIS IN SAME ORDER AS testTargetInfoList ARRAY BELOW
enum FAPI2_TEST_TARGET_ID {
    MY_PROC,
    MY_EQ,
    MY_EX,
    MY_CORE,
    MY_MCS,
    MY_MCA,
    MY_MCBIST,
    MY_PEC,
    MY_PHB,
    MY_XBUS,
    MY_OBUS,
    MY_OBUS_BRICK,
    MY_PPE,
    MY_PERV,
    MY_CAPP,
    MY_SBE,
    MY_MC,
    MY_MI,
    MY_DMI,
    MY_OMI,
    MY_OMIC,
    MY_MCC,
    MY_OCMB,
    MY_MEM_PORT,
    NUM_TARGETS
};

// Use the following macro to generate a list of TARGETING targets for each FAPI2_TEST_TARGET_ID
// you can then use the generated TARGETING targets by using targeting_targets[FAPI2_TEST_TARGET_ID] .
// In addition you will be able to use the fapi2 version of the targets by using the fapi2_<target>Target.
// You can see how the fapi2 targets are instantiated below.
//
// NOTE: This is expected to be called inside a do-while(0) wrapper
// variables created : numTests, numFails, generationSuccess, l_proc, l_chipList, targeting_targets,
//                     fapi2_procTarget, fapi2_eqTarget, fapi2_exTarget, fapi2_coreTarget, fapi2_pecTarget,
//                     fapi2_phbTarget, fapi2_xbusTarget, fapi2_obusTarget, fapi2_oBrickTarget, fapi2_ppeTarget,
//                     fapi2_pervTarget, fapi2_sbeTarget, fapi2_cappTarget, fapi2_mcsTarget, fapi2_mcaTarget,
//                     fapi2_mcbistTarget, fapi2_mcTarget, fapi2_miTarget, fapi2_dmiTarget, fapi2_omiTarget,
//                     fapi2_omicTarget, fapi2_mccTarget
// Keep in the same order as FAPI2_TEST_TARGET_ID for ease of read
#define GENERATE_TEST_TARGETS(TEST_FUNCTION_NAME)                                                            \
int generationSuccess = true;                                                                                \
TARGETING::Target * l_proc = nullptr;                                                                        \
TARGETING::TargetHandleList l_chipList;                                                                      \
numTests++;                                                                                                  \
/* Get a list of all of the proc chips */                                                                    \
TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);                                             \
if(l_chipList.size())                                                                                        \
{                                                                                                            \
    l_proc = l_chipList[0];                                                                                  \
}                                                                                                            \
else                                                                                                         \
{                                                                                                            \
    TS_FAIL("TEST_FUNCTION_NAME Fail: could not find any proc, skipping tests");                             \
    numFails++;                                                                                              \
    break;                                                                                                   \
}                                                                                                            \
TARGETING::Target* targeting_targets[fapi2::NUM_TARGETS];                                                    \
/* Call helper function to generate a bunch of TARGETING targets to use to test  */                          \
generateTargets(l_proc, targeting_targets);                                                                  \
for( uint64_t x = 0; x < NUM_TARGETS; x++ )                                                                  \
{                                                                                                            \
    /*Skip tests where the HW unit to test isn't valid for the proc type */                                  \
    if (!isHwValid(l_proc, x))                                                                               \
    {                                                                                                        \
        continue;                                                                                            \
    }                                                                                                        \
    else if(targeting_targets[x] == nullptr)                                                                 \
    {                                                                                                        \
        FAPI_ERR("TEST_FUNCTION_NAME:: targeting_targets[%d] is null", x);                                   \
        generationSuccess = false;                                                                           \
    }                                                                                                        \
}                                                                                                            \
numTests++;                                                                                                  \
if(!generationSuccess)                                                                                       \
{                                                                                                            \
    numFails++;                                                                                              \
    TS_FAIL("TEST_FUNCTION_NAME Fail : failed to correctly generate targets");                               \
}                                                                                                            \
/* Common Targets  */                                                                                        \
fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>  fapi2_procTarget(targeting_targets[MY_PROC]);                   \
fapi2::Target<fapi2::TARGET_TYPE_EQ>         fapi2_eqTarget(targeting_targets[MY_EQ]);                       \
fapi2::Target<fapi2::TARGET_TYPE_EX>         fapi2_exTarget(targeting_targets[MY_EX]);                       \
fapi2::Target<fapi2::TARGET_TYPE_CORE>       fapi2_coreTarget(targeting_targets[MY_CORE]);                   \
fapi2::Target<fapi2::TARGET_TYPE_PEC>        fapi2_pecTarget(targeting_targets[MY_PEC]);                     \
fapi2::Target<fapi2::TARGET_TYPE_PHB>        fapi2_phbTarget(targeting_targets[MY_PHB]);                     \
fapi2::Target<fapi2::TARGET_TYPE_XBUS>       fapi2_xbusTarget(targeting_targets[MY_XBUS]);                   \
fapi2::Target<fapi2::TARGET_TYPE_OBUS>       fapi2_obusTarget(targeting_targets[MY_OBUS]);                   \
fapi2::Target<fapi2::TARGET_TYPE_OBUS_BRICK> fapi2_oBrickTarget(targeting_targets[MY_OBUS_BRICK]);           \
fapi2::Target<fapi2::TARGET_TYPE_PPE>        fapi2_ppeTarget(targeting_targets[MY_PPE]);                     \
fapi2::Target<fapi2::TARGET_TYPE_PERV>       fapi2_pervTarget(targeting_targets[MY_PERV]);                   \
fapi2::Target<fapi2::TARGET_TYPE_SBE>        fapi2_sbeTarget(targeting_targets[MY_SBE]);                     \
fapi2::Target<fapi2::TARGET_TYPE_CAPP>       fapi2_cappTarget(targeting_targets[MY_CAPP]);                   \
/* Model Specific Targets */                                                                                 \
fapi2::Target<fapi2::TARGET_TYPE_MCS>        fapi2_mcsTarget(targeting_targets[MY_MCS]);       /* Nimbus */  \
fapi2::Target<fapi2::TARGET_TYPE_MCA>        fapi2_mcaTarget(targeting_targets[MY_MCA]);       /* Nimbus */  \
fapi2::Target<fapi2::TARGET_TYPE_MCBIST>     fapi2_mcbistTarget(targeting_targets[MY_MCBIST]); /* Nimbus */  \
fapi2::Target<fapi2::TARGET_TYPE_MC>         fapi2_mcTarget(targeting_targets[MY_MC]);   /* Cumulus / Axone*/\
fapi2::Target<fapi2::TARGET_TYPE_MI>         fapi2_miTarget(targeting_targets[MY_MI]);   /* Cumulus / Axone*/\
fapi2::Target<fapi2::TARGET_TYPE_DMI>        fapi2_dmiTarget(targeting_targets[MY_DMI]); /* Cumulus */       \
fapi2::Target<fapi2::TARGET_TYPE_OMI>        fapi2_omiTarget(targeting_targets[MY_OMI]);          /* Axone */\
fapi2::Target<fapi2::TARGET_TYPE_OMIC>       fapi2_omicTarget(targeting_targets[MY_OMIC]);        /* Axone */\
fapi2::Target<fapi2::TARGET_TYPE_MCC>        fapi2_mccTarget(targeting_targets[MY_MCC]);          /* Axone */\
fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>  fapi2_ocmbTarget(targeting_targets[MY_OCMB]);        /* Axone */\
fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>   fapi2_memportTarget(targeting_targets[MY_MEM_PORT]); /* Axone */


/**
 *  @brief Number of children of given type that applicable pervasive has
 */
enum PERVASIVE_CHILDREN {
    PERV_EQ_CHILDREN           = 1,
    PERV_CORE_CHILDREN         = 1,
    PERV_XBUS_NIMBUS_CHILDREN  = 2,
    PERV_XBUS_CUMULUS_CHILDREN = 3,
    PERV_OBUS_CHILDREN         = 1,
    PERV_CAPP_NIMBUS_CHILDREN  = 1,
    PERV_CAPP_CUMULUS_CHILDREN = 2,
    PERV_OBUS_BRICK_CHILDREN   = 3,
    PERV_MCBIST_CHILDREN       = 1,
    PERV_MCS_CHILDREN          = 2,
    PERV_MCA_CHILDREN          = 4,
    PERV_PEC_CHILDREN          = 1,
    PERV_PEC0_PHB_CHILDREN     = 1,
    PERV_PEC1_PHB_CHILDREN     = 2,
    PERV_PEC2_PHB_CHILDREN     = 3,
    PERV_MC_CHILDREN           = 1,
    PERV_MI_CHILDREN           = 2,
    PERV_DMI_CHILDREN          = 4,
    PERV_OCC_CHILDREN          = 4,
    PERV_MCC_CHILDREN          = 4,
    PERV_OMI_CHILDREN          = 8,
    PERV_OMIC_CHILDREN         = 3,
};

/**
 *  @brief Unit ranges for pervasive function
 *
 *  @par Detailed Description:
 *      Maps pervasive target with chip unit X to one or more unit types.  For
 *      example, a pervasive chip unit of 18 maps to EQ type because
 *      EQ_LOW <= X <= EQ_HIGH .
 */
enum PERVASIVE_RANGE {
    EQ_LOW            = 16,
    EQ_HIGH           = 21,
    CORE_LOW          = 32,
    CORE_HIGH         = 55,
    XBUS_RANGE        = 6,
    OBUS_LOW          = 9,
    OBUS_HIGH         = 12,
    CAPP0_RANGE       = 2,
    CAPP1_RANGE       = 4,
    MC_LOW            = 7,
    MC_HIGH           = 8,
    PEC_LOW           = 13,
    PEC_MID           = 14,
    PEC_HIGH          = 15,
};

///
/// @brief Generates a list of platform targets of all differnt types.
///        This comes in handy when testing out fapi2 target interfaces
/// @param[in] i_pMasterProcChip Pointer to master proc chip
/// @param[out] o_targetList     List of platform targets that gets generated
///                              by this function
///
void generateTargets(TARGETING::Target* i_pMasterProcChip,
                                    TARGETING::Target* o_targetList[]);

/**
*  @brief Helper to get the parent pervasive of the given target
*
*  @tparam K Input target's FAPI2 type
*  @tparam V Platform target handle type
*
*  @param[in] i_pTarget Targeting target
*
*  @return Platform target handle giving the pervasive of the input target
*  @retval NULL No parent found
*  @retval !NULL Parent found, equal to the retval
 */
template< TargetType K, typename V = plat_target_handle_t >
inline V getPervasiveParent(V i_pTarget)
{
    Target<K,V> fapi2_target(i_pTarget);
    return static_cast<V>(
        fapi2_target.template getParent<TARGET_TYPE_PERV>());
}

/**
 * @brief Helper to determine if hw unit is valid for given
 *      proc type
 *
 * @param[in] i_procChip Proc chip to check type of
 * @param[in] i_hwType   Hw unit type to compare with proc
 *
 * @return True if hw unit is valid for proc type, false otherwise
 */
bool isHwValid(TARGETING::Target* i_procChip, uint8_t i_hwType);

} // End namespace fapi2
#endif
