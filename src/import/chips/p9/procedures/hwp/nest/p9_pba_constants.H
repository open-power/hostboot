/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_pba_constants.H $  */
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
/// @file p9_pba_constants.H
/// @brief Constant enums to support PBA get/putmem procedures (FAPI)
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWp Consumed by: SBE

#ifndef _P9_PBA_CONSTANTS_H_
#define _P9_PBA_CONSTANTS_H_

//---------------------------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------------------------

extern "C"
{

//----------------------------------------------------------------------------------------------
// Constant definitions
//----------------------------------------------------------------------------------------------
    enum pba_flags
    {
        // Fastmode flag
        // If this flag is set it means we will not check for errors until
        // the very last granule for the read/write
        FLAG_PBA_FASTMODE = 0x80000000ull,

        // TTYPE flag
        // PBA operation type
        // 0b000: DMA
        // 0b001: LCO_M
        // 0b010: ATOMIC
        // 0b011: CACHE_INJ
        // 0b100: CI_PR_W
        // Same as in the documentation and how they will be passed to the register
        FLAG_PBA_TTYPE    = 0x70000000ull
    };

// TTYPE shift position
    const uint64_t FLAG_PBA_TTYPE_SHIFT = 28;
    const uint64_t FLAG_PBA_TTYPE_MASK = 0b111;

// --------------------------------------------------------------------
// TODO: RTC 147511 - Remove this definition when SBE code is updated
//                    and use PBA class.
// ---------------------------------------------------------------------
//these give the bit mask for each flag
    enum p9_pba_flags
    {
        //fastmode flag, if this flag is set it means we will not check for errors until the very last granule for the read/write
        FLAG_FASTMODE = 0x80000000ull,
        //ttype flag, this is 3 bits, will be set to 0 for dma, 1, to lco_m, 2 for atomic, 3 for cache_inj, and 4 for ci_pr_w --same as in the documentation and how they will be passed to the register
        FLAG_TTYPE    = 0x70000000ull
    };

    enum p9_pba_write_ttype
    {
        DMA = 0,
        LCO = 1,
        ATOMIC = 2,
        INJ = 3,
        CI = 4
    };

    const uint64_t FLAG_TTYPE_SHIFT = 28;
// -----------------------------------------------------


} //extern "C"

#endif //_P9_PBA_CONSTANTS_H_
