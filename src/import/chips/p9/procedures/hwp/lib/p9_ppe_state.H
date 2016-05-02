/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_ppe_state.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

///
/// @file  p9_ppe_state.H
/// @brief Dump a PPE engine's state.
///
/// *HWP HW Owner        : Ashish More <ashish.more.@in.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : SBE, Cronus

#ifndef __P9_PPE_STATE_H__
#define __P9_PPE_STATE_H__
typedef struct
{
    uint16_t     number;
    std::string  name;
} PPEReg_t;

typedef struct
{
    PPEReg_t    reg;
    uint32_t    value;
} PPERegValue_t;

typedef struct
{
    PPEReg_t    reg;
    uint64_t    value;
} SCOMRegValue_t;


enum PPE_DUMP_MODE
{
    XIRS           = 0x0,
    SNAPSHOT       = 0x1,
    HALT           = 0x2,
    FORCE_HALT     = 0x3
};
enum VERBOSE_MODE
{
    NOVERBOSE        = 0x0,
    VERBOSE          = 0x1,
    VERBOSEP         = 0x2,
};

enum INT_VEC_OFFSET
{
    MCHK_VEC = 0x000  ,  // 0,
    SRST_VEC = 0x040  ,  // 64,
    DSI_VEC  =  0x060 ,  // 96,
    ISI_VEC  =  0x080 ,  // 128,
    EXT_VEC  =  0x0A0 ,  // 160,
    ALIG_VEC = 0x0C0  ,  // 192,
    PRG_VEC  =  0x0E0 ,  // 224,
    DEC_VEC  =  0x100 ,  // 256,
    FIT_VEC  =  0x120 ,  // 288,
    WDT_VEC  =  0x140 ,  // 320,
} ;
enum PPE_XIRS
{
    XIR_XSR,
    XIR_IAR,
    XIR_IR,
    XIR_EDR,
    XIR_SPRG0,
};

enum PPE_SPECIAL_ACCESS
{
    MSR,
    CR,
};
enum PPE_SPRS
{
    CTR     = 9,
    DACR    = 316,
    DBCR    = 308,
    DEC     = 22,
    IVPR    = 63,
    ISR     = 62,
    LR      = 8,
    PIR     = 286,
    PVR     = 287,
    SPRG0   = 272,
    SRR0    = 26,
    SRR1    = 27,
    TCR     = 340,
    TSR     = 336,
    XER     = 1, //336,
};


// Note: EDR is available via XIR
enum PPE_GPRS
{
    R0  = 0,
    R1  = 1,
    R2  = 2,
    R3  = 3,
    R4  = 4,
    R5  = 5,
    R6  = 6,
    R7  = 7,
    R8  = 8,
    R9  = 9,
    R10 = 10,
    R13 = 13,
    R28 = 28,
    R29 = 29,
    R30 = 30,
    R31 = 31,
};



/// @typedef p9_ppe_state_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_ppe_state_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const uint64_t, const PPE_DUMP_MODE,
    std::vector<PPERegValue_t>& v_ppe_sprs_value,
    std::vector<PPERegValue_t>& v_ppe_xirs_value,
    std::vector<PPERegValue_t>& v_ppe_gprs_value
);

extern "C"
{

/// @brief Dump the PPE state based on the based base address
/// @param [in] i_target TARGET_TYPE_PROC_CHIP
/// @param [in] i_base_address Base offset to be used for all accesses
/// @return FAPI2_RC_SUCCESS
    fapi2::ReturnCode
    p9_ppe_state(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                 const uint64_t i_base_address, const PPE_DUMP_MODE i_mode,
                 std::vector<PPERegValue_t>& v_ppe_sprs_value,
                 std::vector<PPERegValue_t>& v_ppe_xirs_value,
                 std::vector<PPERegValue_t>& v_ppe_gprs_value

                );

} // extern C

#endif  // __P9_PPE_DUMP_H__
