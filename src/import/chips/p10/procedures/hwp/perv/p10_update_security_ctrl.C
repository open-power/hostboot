/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_update_security_ctrl.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
//------------------------------------------------------------------------------
/// @file  p10_update_security_ctrl.C
///
/// @brief To set SUL(Secure Update Lock) bit to lock down SAB + SBE SEEPROM and to set TDP(TPM Deconfig Protect) Bit
///     Decision to set SUL is based on if Chip is in Secure mode(SAB bit is 1)
///     Decision to set TDP is based on an attribute : ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM
///     Decision to lock Abus mailboxes is based on the input option
///     All three bits are set if SAB bit is set or if security is forced via input option
///
//------------------------------------------------------------------------------
// *HWP HW Owner        : Santosh Balasubramanian <sbalasub@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_scom_perv_8.H>
#include "p10_update_security_ctrl.H"


fapi2::ReturnCode p10_update_security_ctrl(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        const bool i_force_security,
        const bool i_lock_sec_mailboxes)
{
    FAPI_INF("p10_update_security_ctrl : Entering ...");
    FAPI_INF("p10_update_security_ctrl : i_force_security: %d; i_lock_sec_mailboxes: %d",
             i_force_security, i_lock_sec_mailboxes);

    uint8_t l_set_tdp = 0;
    fapi2::buffer<uint64_t> l_data64;
    bool l_in_secure_mode = false;

    //Attribute for setting TDP bit - TPM Deconfig Protection  0x00 = No protection, 0x01 = Set TDP bit(Bit 12)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM, i_target_chip, l_set_tdp));
    FAPI_INF("TPM Deconfig Attribute value : 0x%02x", l_set_tdp);


    //Get value of SAB bit to see if chip is in secure mode
    FAPI_TRY(fapi2::getScom(i_target_chip, scomt::perv::OTPC_M_SECURITY_SWITCH_REGISTER, l_data64));

    l_in_secure_mode = l_data64.getBit<scomt::perv::OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS>();

    if ((l_in_secure_mode == 1) || (i_force_security)) //Chip in Secure mode  or override with i_force_security parameter
    {
        //SECURITY_SWITCH_REGISTER is SET only register - hence clearing '0' before setting specific bits
        //To Avoid the issue of a read modified write
        l_data64.flush<0>();

        //Set bit 4 to set SUL
        l_data64.setBit<scomt::perv::OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK>();

        if (l_set_tdp == 1) //Check if TDP needs to be set
        {
            //Set bit 12 to set TDP
            l_data64.setBit<scomt::perv::OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT>();
        }

        //Set bit 8 to set Abus mailbox lock
        if(i_lock_sec_mailboxes)
        {
            l_data64.setBit<scomt::perv::OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK>();
        }

        FAPI_TRY(fapi2::putScom(i_target_chip, scomt::perv::OTPC_M_SECURITY_SWITCH_REGISTER, l_data64));
    }
    else
    {
        FAPI_INF("Chip not in secure mode - No need to set SUL/TDP/Abus mailbox lock bits");
    }

    FAPI_INF("p10_update_security_ctrl : Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
