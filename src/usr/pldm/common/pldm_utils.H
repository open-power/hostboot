/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/common/pldm_utils.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

/**
* @file pldm_utils.H
*
* @brief Header file to declare functions which will be defined
*        in pldm_utils.C. This should declare PLDM utility functions
*        we don't want to be exposed to external modules.
*/

#ifndef PLDM_UTILS_H
#define PLDM_UTILS_H

#include <openbmc/pldm/oem/ibm/libpldm/file_io.h>
#include <errl/errlentry.H>

// There is no "invalid file type" enumerator so to denote an invalid
// bootside by using PLDM_FILE_TYPE_PEL = 0 which is never going to
// be a valid bootside.
#define PLDM_BOOT_SIDE_INVALID PLDM_FILE_TYPE_PEL

namespace PLDM
{

    /**
    * @brief On first call perform a bios attribute lookup to determine
    *        the bootside and store the value in a static variable
    *         that will be referenced when making file io requests for lids.
    *
    * @param[out] o_boot_side  The side we got from the bmc bios attribute pvm_fw_boot_side
    *
    * @return errHndl_t   nullptr unless error occurs
    */
    errlHndl_t get_pldm_bootside(pldm_fileio_file_type &o_boot_side);

}
#endif
