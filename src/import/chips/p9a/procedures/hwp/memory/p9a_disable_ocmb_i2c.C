/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/p9a_disable_ocmb_i2c.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
///
/// @file p9a_disable_ocmb_i2c.H
/// @brief Enable the security block for i2c access to the OCMB devices
///
//------------------------------------------------------------------------------
// *HWP HW Owner        : Santosh Balasubramanian <sbalasub@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Dan Crowell <dcrowell@us.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include "p9a_disable_ocmb_i2c.H"


///
/// @brief Enable the security block for i2c access to the OCMB devices
///
fapi2::ReturnCode p9a_disable_ocmb_i2c( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc,
                                        bool i_force )
{
    FAPI_INF("p9a_disable_ocmb_i2c : Entering ...");

    fapi2::buffer<uint64_t> l_data64;
    bool l_in_secure_mode = false;

    //Get value of SAB bit to see if chip is in secure mode
    FAPI_TRY(fapi2::getScom(i_proc, PU_SECURITY_SWITCH_REGISTER_SCOM, l_data64));

    l_in_secure_mode = l_data64.getBit<PU_SECURITY_SWITCH_REGISTER_SECURE_ACCESS>();

    if ((l_in_secure_mode == 1) || (i_force)) //Chip in Secure mode  or override with i_force parameter
    {
        //SECURITY_SWITCH_REGISTER is SET only register - hence clearing '0' before setting specific bits
        //To Avoid the issue of a read modified write
        l_data64.flush<0>();

        //13 : SECURITY_SWITCH_SECURE_OCMB_LOCK: TP Spare
        l_data64.setBit<13>();

        FAPI_TRY(fapi2::putScom(i_proc, PU_SECURITY_SWITCH_REGISTER_SCOM, l_data64));
    }
    else
    {
        FAPI_INF("Chip not in secure mode - No need to disable i2c access");
    }

    FAPI_INF("p9a_disable_ocmb_i2c : Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
