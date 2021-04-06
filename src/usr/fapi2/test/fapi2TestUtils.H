/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2TestUtils.H $                         */
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
/// @file fapi2TestUtils.H
///
/// @brief FAPI2 utility functions
///
/// Note that platform code must provide the implementation.
///

#ifndef FAPI2TESTUTILS_H_
#define FAPI2TESTUTILS_H_

#define EQ_PER_PROC          8
#define FC_PER_EQ            2
#define CORE_PER_FC          2
#define MI_PER_PROC          4
#define MC_PER_PROC          4
#define MI_PER_MC            1
#define MCC_PER_MI           2
#define OMI_PER_MCC          2
#define OMIC_PER_MC          2
#define OCMB_PER_OMI         1
#define MEM_PORT_PER_OCMB    1
#define OMIC_PER_PAUC        2
#define IOHS_PER_PAUC        2
#define IOLINK_PER_IOHS      2

#define SIMULATED_GOOD_CORES 4

// non-core and non-cache chiplet ids
#define START_PERV_CHIPLET_NUM        0x02
// MC (0, 1, ... => 0x0C, 0x0D, ...)
#define START_MC_CHIPLET_NUM          0x0C
// MI (0, 1, ... => 0x0C, 0x0D, ...)
#define START_MI_CHIPLET_NUM          0x0C
// OMI (0-3, 4-7, ... => 0x0C, 0x0D, ...)
#define START_OMI_CHIPLET_NUM         0x0C
// OMIC (0-1, 2-3, ... => 0x0C, 0x0D, ...)
#define START_OMIC_CHIPLET_NUM        0x0C
// MCC (0-1, 2-3, ... => 0x0C, 0x0D, ...)
#define START_MCC_CHIPLET_NUM         0x0C
// IOHS (0, 1, ... => 0x18, 0x19, ...)
#define START_IOHS_CHIPLET_NUM        0x18
// PAU (0-1, 2-3, ... => 0x10, 0x11, ...)
#define START_PAU_CHIPLET_NUM         0x10
// PAUC (0, 1, ... => 0x10, 0x11, ...)
#define START_PAUC_CHIPLET_NUM        0x10
// PEC (0, 1 => 0x08, 0x09)
#define START_PEC_0_CHIPLET_NUM       0x08
#define START_PEC_1_CHIPLET_NUM       0x09

// All Cache Chiplets
#define START_EQ_CHIPLET_NUM      0x20

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
    MY_FC,
    MY_CORE,
    MY_PEC,
    MY_PHB,
    MY_PERV,
    MY_MC,
    MY_MI,
    MY_OMI,
    MY_OMIC0,
    MY_OMIC1,
    MY_MCC,
    MY_OCMB,
    MY_MEM_PORT,
    MY_IOHS,
    MY_IOLINK,
    MY_PAU,
    MY_PAUC,
    NUM_TARGETS
};

// Use the following macro to generate a list of TARGETING targets for each FAPI2_TEST_TARGET_ID
// you can then use the generated TARGETING targets by using targeting_targets[FAPI2_TEST_TARGET_ID] .
// In addition you will be able to use the fapi2 version of the targets by using the fapi2_<target>Target.
// You can see how the fapi2 targets are instantiated below.
//
// NOTE: This is expected to be called inside a do-while(0) wrapper
// variables created : numTests, numFails, generationSuccess, l_proc, l_chipList, targeting_targets,
//                     fapi2_procTarget, fapi2_eqTarget, fapi2_fcTarget, fapi2_coreTarget, fapi2_pecTarget,
//                     fapi2_phbTarget, fapi2_pervTarget, fapi2_mcsTarget, fapi2_mcTarget, fapi2_miTarget,
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
    TS_FAIL(#TEST_FUNCTION_NAME" Fail: could not find any proc, skipping tests");                            \
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
        FAPI_ERR(#TEST_FUNCTION_NAME":: targeting_targets[%d] is null", x);                                  \
        generationSuccess = false;                                                                           \
    }                                                                                                        \
}                                                                                                            \
numTests++;                                                                                                  \
if(!generationSuccess)                                                                                       \
{                                                                                                            \
    numFails++;                                                                                              \
    TS_FAIL(#TEST_FUNCTION_NAME" Fail : failed to correctly generate targets");                              \
}                                                                                                            \
/* Common Targets  */                                                                                        \
fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>  fapi2_procTarget(targeting_targets[MY_PROC]);                   \
fapi2::Target<fapi2::TARGET_TYPE_EQ>         fapi2_eqTarget(targeting_targets[MY_EQ]);                       \
fapi2::Target<fapi2::TARGET_TYPE_FC>         fapi2_fcTarget(targeting_targets[MY_FC]);                       \
fapi2::Target<fapi2::TARGET_TYPE_CORE>       fapi2_coreTarget(targeting_targets[MY_CORE]);                   \
fapi2::Target<fapi2::TARGET_TYPE_PEC>        fapi2_pecTarget(targeting_targets[MY_PEC]);                     \
fapi2::Target<fapi2::TARGET_TYPE_PHB>        fapi2_phbTarget(targeting_targets[MY_PHB]);                     \
fapi2::Target<fapi2::TARGET_TYPE_PERV>       fapi2_pervTarget(targeting_targets[MY_PERV]);                   \
fapi2::Target<fapi2::TARGET_TYPE_MC>         fapi2_mcTarget(targeting_targets[MY_MC]);                       \
fapi2::Target<fapi2::TARGET_TYPE_MI>         fapi2_miTarget(targeting_targets[MY_MI]);                       \
fapi2::Target<fapi2::TARGET_TYPE_OMI>        fapi2_omiTarget(targeting_targets[MY_OMI]);                     \
fapi2::Target<fapi2::TARGET_TYPE_OMIC>       fapi2_omic0Target(targeting_targets[MY_OMIC0]);                 \
fapi2::Target<fapi2::TARGET_TYPE_OMIC>       fapi2_omic1Target(targeting_targets[MY_OMIC1]);                 \
fapi2::Target<fapi2::TARGET_TYPE_MCC>        fapi2_mccTarget(targeting_targets[MY_MCC]);                     \
fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>  fapi2_ocmbTarget(targeting_targets[MY_OCMB]);                   \
fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>   fapi2_memportTarget(targeting_targets[MY_MEM_PORT]);            \
fapi2::Target<fapi2::TARGET_TYPE_IOHS>       fapi2_iohsTarget(targeting_targets[MY_IOHS]);                   \
fapi2::Target<fapi2::TARGET_TYPE_IOLINK>     fapi2_iolinkTarget(targeting_targets[MY_IOLINK]);               \
fapi2::Target<fapi2::TARGET_TYPE_PAU>        fapi2_pauTarget(targeting_targets[MY_PAU]);                     \
fapi2::Target<fapi2::TARGET_TYPE_PAUC>       fapi2_paucTarget(targeting_targets[MY_PAUC]);



/**
 *  @brief Number of children of given type that applicable pervasive has
 */
enum PERVASIVE_CHILDREN {
    PERV_EQ_CHILDREN           = 1,
    PERV_CORE_CHILDREN         = 4,
    PERV_PEC_CHILDREN          = 1,
    PERV_PEC_PHB_CHILDREN      = 3,
    PERV_MC_CHILDREN           = 1,
    PERV_MI_CHILDREN           = 1,
    PERV_MCC_CHILDREN          = 2,
    PERV_OMI_CHILDREN          = 4,
    PERV_OMIC_CHILDREN         = 2,
    PERV_PAU_LOW_CHILDREN      = 1,
    PERV_PAU_HIGH_CHILDREN     = 2,
    PERV_IOHS_CHILDREN         = 1,
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
    EQ_LOW            = 0x20,
    EQ_HIGH           = 0x20 + 8,
    CORE_LOW          = 0x20,
    CORE_HIGH         = 0x20 + 8,
    MC_LOW            = 0xC,
    MC_HIGH           = 0xF,
    PEC_LOW           = 0x8,
    PEC_HIGH          = 0x9,
    PAUC_LOW          = 0x10,
    PAUC_MID          = 0x11,
    PAUC_HIGH         = 0x13,
    IOHS_LOW          = 0x18,
    IOHS_HIGH         = 0x21,
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
template< TargetType K, MulticastType M = MULTICAST_OR,
        typename V = plat_target_handle_t >
inline V getPervasiveParent(V i_pTarget)
{
    Target<K, M, V> fapi2_target(i_pTarget);
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
