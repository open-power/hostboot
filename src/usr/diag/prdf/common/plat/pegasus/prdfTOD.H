/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfTOD.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

#ifndef PRDFTOD_H
#define PRDFTOD_H

namespace PRDF
{

/** @struct PrdfTodFaultData
 *  TOD Fault isolation information from a chip.
 */
struct PrdfTodFaultData
{
    TARGETING::TargetHandle_t source_chipHandle;
    bool phyp_fault;
    bool topo_fault[2];                  // 0 is active, 1 is backup
    bool topo_fault_clock[2];
    TARGETING::TargetHandle_t topo_fault_chip[2];
};

int32_t prdfP7_TodCaptureRegisters(STEP_CODE_DATA_STRUCT & i_stepcode);
int32_t prdfP7_TodCleanUpErrors(STEP_CODE_DATA_STRUCT & i_stepcode);
int32_t prdfP7_TodCollectFaultDataSys(vector<PrdfTodFaultData> & o_faults,
                                      STEP_CODE_DATA_STRUCT & i_stepcode);
int32_t prdfP7_TodCollectFaultDataChip(ExtensibleChip * i_chip,
                                       vector<PrdfTodFaultData> & o_faults,
                                       STEP_CODE_DATA_STRUCT & i_stepcode);

} // end namespace PRDF

#endif //PRDFTOD_H
