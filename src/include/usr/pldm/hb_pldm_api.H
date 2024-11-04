/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/hb_pldm_api.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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
#ifndef _HB_PLDM_API_CALLS_H
#define _HB_PLDM_API_CALLS_H
/*
*  contains wrappers for OpenBMC Libpldm Api calls that follow a new structure
*  from the original structure the Hostboot owned code is expecting.
*  API calls included are the following:
*  encode_get_bios_table_req from bios.h
*  encode_get_bios_attribute_current_value_by_handle_req,
*/

// system headers
#include <vector>
#include <sys/msg.h>
// non-pldm /include headers
#include <mctp/mctp_message_types.H>
#include <openbmc/pldm/libpldm/include/libpldm/bios_table.h>


/*****************************************************
**                WRAPPERs
*******************************************************/
int encode_get_bios_table_req(uint8_t instance_id, uint32_t transfer_handle,
                  uint8_t transfer_op_flag, uint8_t table_type,
                  struct pldm_msg *msg,size_t payload_length)
{
    return encode_get_bios_table_req(instance_id,
                                    transfer_handle,
                                    transfer_op_flag,
                                    table_type,
                                    msg);
}

int encode_get_bios_attribute_current_value_by_handle_req(
    uint8_t instance_id, uint32_t transfer_handle, uint8_t transfer_op_flag,
    uint16_t attribute_handle, struct pldm_msg *msg, size_t payload_length)
{
    return encode_get_bios_attribute_current_value_by_handle_req(instance_id,
                                                                transfer_handle,
                                                                transfer_op_flag,
                                                                attribute_handle,
                                                                msg);
}

#endif