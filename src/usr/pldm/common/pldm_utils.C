/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/common/pldm_utils.C $                            */
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
* @file pldm_utils.C
*
* @brief Source code for utility functions defined in pldmif.H
*/

#include <pldm/pldmif.H>
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/pldm_errl.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_trace.H>
#include "pldm_utils.H"
#include <cstring>

namespace PLDM
{

uint64_t pldmHdrToUint64(const pldm_msg& i_pldmMsg)
{
    uint64_t request_hdr_data = 0;
    const pldm_msg_hdr* const request_hdr = &i_pldmMsg.hdr;

    static_assert(sizeof(pldm_msg_hdr) <= sizeof(request_hdr_data),
                  "pldm_msg_hdr is too big for a 64-bit integer");

    memcpy(&request_hdr_data, request_hdr, sizeof(pldm_msg_hdr));
    return request_hdr_data;
}

errlHndl_t get_pldm_bootside(pldm_fileio_file_type &o_boot_side)
{
    errlHndl_t errl = nullptr;
    static pldm_fileio_file_type pldm_bootside = PLDM_BOOT_SIDE_INVALID;
    do {
    if(pldm_bootside == PLDM_BOOT_SIDE_INVALID)
    {
        std::vector<uint8_t> string_table, attr_table;
        errl = getBootside(string_table, attr_table, pldm_bootside);
        if(errl)
        {
            break;
        }
        if(!(pldm_bootside  == PLDM_FILE_TYPE_LID_PERM ||
             pldm_bootside  == PLDM_FILE_TYPE_LID_TEMP))
        {
            PLDM_ERR("checkBootside: getBootside set pldm_bootside to an invalid value");
            /*@
            * @errortype
            * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid   MOD_GET_BIOS_SIDE
            * @reasoncode RC_UNSUPPORTED_TYPE
            * @userdata1  pldm_bootside  value
            * @userdata2  unused
            * @devdesc    Unable to find a valid bootside
            * @custdesc   A host failure occurred
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_GET_BIOS_SIDE,
                                           RC_UNSUPPORTED_TYPE,
                                           pldm_bootside,
                                           0);
            addBmcErrorCallouts(errl);
        }
    }
    o_boot_side = pldm_bootside;
    } while(0);
    return errl;
}

}
