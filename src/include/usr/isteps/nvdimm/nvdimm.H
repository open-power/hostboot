/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/nvdimm/nvdimm.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef NVDIMM_H__
#define NVDIMM_H__

#include <targeting/common/util.H>

namespace NVDIMM
{

/**
 * @brief Entry function to NVDIMM management
 *        - Restore image from NVDIMM NAND flash to DRAM
 *        - Arms the backup trigger to ddr_reset_n once the restore
 *          is completed
 *        - Erase image
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 **/
void nvdimm_restore(TARGETING::TargetHandleList &i_nvdimmList);

}

#endif  // NVDIMM_H__

