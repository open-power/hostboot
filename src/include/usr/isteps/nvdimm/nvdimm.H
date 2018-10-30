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
#ifndef NVDIMM_EXT_H__
#define NVDIMM_EXT_H__

#include <targeting/common/util.H>

namespace NVDIMM
{
enum
{
    NSTD_VAL_NOPRSV      = 0x08, // memory valid, contents not preserved (genesis)
    NSTD_VAL_NOPRSV_MASK = 0xF7,
    NSTD_VAL_PRSV        = 0x04, // memory contents preserved
    NSTD_VAL_PRSV_MASK   = 0xFB,
    NSTD_ERR_NOPRSV      = 0x02, // memory failed to preserve contents
    NSTD_ERR_NOPRSV_MASK = 0xFD,
    NSTD_ERR_NOBKUP      = 0x01, // memory unable to preserve future content
    NSTD_ERR_NOBKUP_MASK = 0xFE,
    NSTD_ERR             = 0x03, // NSTD_ERR_NOPRSV+NSTD_ERR_NOBKUP
};
#ifndef __HOSTBOOT_RUNTIME
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
#endif

/**
 * @brief This function arms the trigger to enable backup in the event
 *        of power loss (DDR Reset_n goes low)
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmArmResetN(TARGETING::Target *i_nvdimm);

/**
 * @brief This function erases image on the nvdimm target
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmEraseNF(TARGETING::Target *i_nvdimm);

/**
 * @brief Check nvdimm error state
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @return bool - true if nvdimm is in any error state, false otherwise
 */
bool nvdimmInErrorState(TARGETING::Target *i_nvdimm);

/**
 * @brief Set the status flag
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_status_flag - status flag to set for each nvdimm
 *
 */
void nvdimmSetStatusFlag(TARGETING::Target *i_nvdimm, const uint8_t i_status_flag);
}

#endif  // NVDIMM_EXT_H__

