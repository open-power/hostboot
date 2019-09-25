/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_disable_ocmb_i2c.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_disable_ocmb_i2c.H
/// @brief Enable the security block for i2c access to the OCMB devices if
///        security is enabled in the processor (SAB bit).
///
//------------------------------------------------------------------------------
/// *HWP HW Maintainer: Santosh Balasubramanian <sbalasub@in.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
//------------------------------------------------------------------------------

#ifndef P10_DISABLE_OCMB_I2C_H_
#define P10_DISABLE_OCMB_I2C_H_

#include <fapi2.H>


typedef fapi2::ReturnCode (*p10_disable_ocmb_i2c_FP_t) ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc,
        bool i_force );

extern "C"
{
    ///
    /// @brief Enable the security block for i2c access to the OCMB devices
    /// @param[in] i_proc  the processor target to operate on
    /// @param[in] i_force  force the block regardless of security settings
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p10_disable_ocmb_i2c( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc,
                                            bool i_force = false );

}
#endif
