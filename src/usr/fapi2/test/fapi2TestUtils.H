/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2TestUtils.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

#define EQ_PER_PROC 6
#define EX_PER_EQ 2
#define CORE_PER_EX 2

#include <fapi2.H>

namespace fapi2
{

//Used by generateTargets to get a list of all platform target
// types that directly relate to fapi2 target types
enum{
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
    MY_NV,
    MY_PPE,
    MY_PERV,
    MY_CAPP,
    MY_SBE,
    NUM_TARGETS
};

/**
 *  @brief Number of children of given type that applicable pervasive has
 */
enum PERVASIVE_CHILDREN {
    PERV_EQ_CHILDREN       = 1,
    PERV_CORE_CHILDREN     = 1,
    PERV_XBUS_CHILDREN     = 2,
    PERV_OBUS_CHILDREN     = 1,
    PERV_CAPP_CHILDREN     = 1,
    PERV_NV_CHILDREN       = 2,
    PERV_MCBIST_CHILDREN   = 1,
    PERV_MCS_CHILDREN      = 2,
    PERV_MCA_CHILDREN      = 4,
    PERV_PEC_CHILDREN      = 1,
    PERV_PEC0_PHB_CHILDREN = 1,
    PERV_PEC1_PHB_CHILDREN = 2,
    PERV_PEC2_PHB_CHILDREN = 3,
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
    NV_RANGE          = 5,
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

} // End namespace fapi2

#endif
