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

#include <fapi2.H>

namespace fapi2
{
// Setup some targets to use
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
    MY_NVBUS,
    MY_PPE,
    MY_PERV,
    MY_CAPP,
    MY_SBE,
    NUM_TARGETS
};


void generateTargets(TARGETING::Target* i_pMasterProcChip,
                                    TARGETING::Target* o_targetList[]);

} // End namespace fapi2

#endif
