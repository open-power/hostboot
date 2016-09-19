/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_image_build.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#ifndef __IO_IOO_HCODE_IMG_BUILD_H_
#define __IO_IOO_HCODE_IMG_BUILD_H_
///
/// @file   p9_io_obus_image_build.H
/// @brief  Implements HWP that builds the Hcode image in IO Obus PPE Sram.
///----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HPW Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 1
/// *HWP Consumed by      : FSP:HB
///----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <stdint.h>
#include <fapi2.H>


typedef fapi2::ReturnCode ( *p9_io_obus_image_build_FP_t )
( const fapi2::Target < fapi2::TARGET_TYPE_OBUS >,
  void* const );

extern "C"
{

    /**
    * @brief   builds a STOP image using a refrence image as input.
    * @param   i_tgt     fapi2 target for obus chip unit.
    * @param   i_pimage  points to memory mapped refrence image in PNOR.
    */
    fapi2::ReturnCode p9_io_obus_image_build(
        const fapi2::Target < fapi2::TARGET_TYPE_OBUS > i_target,
        void* const                                     i_pimage );
} // extern C
#endif //__IO_IOO_HCODE_IMG_BUILD_H_
