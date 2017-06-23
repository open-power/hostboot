/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_ppe_utils.H $       */
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
/// @file  p9_ppe_utils.H
/// @brief PPE commonly used functions
///
/// *HWP HW Owner        : Ashish More <ashish.more.@in.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 3
/// *HWP Consumed by     : Cronus, HB, FSP
#ifndef __P9_PPE_UTILS_H__
#define __P9_PPE_UTILS_H__
#include <map>
#include <fapi2.H>
typedef struct
{
    uint16_t    number;
    uint32_t    value;
} PPERegValue_t;

typedef struct
{
    uint16_t    number;
    uint64_t    value;
} SCOMRegValue_t;

/**
 * @brief enumerates opcodes for few instructions.
 */
enum
{
    OPCODE_31         = 31,
    MTSPR_CONST1      = 467,
    MTSPR_BASE_OPCODE = (OPCODE_31 << (31 - 5)) | (MTSPR_CONST1 << (31 - 30)),
    MFSPR_CONST1      = 339,
    MFSPR_BASE_OPCODE = (OPCODE_31 << (31 - 5)) | (MFSPR_CONST1 << (31 - 30)),
    MFMSRD_CONST1     = 83,
    MFCR_CONST1       = 19,
    ANDIS_CONST       = 29,
    ORIS_CONST        = 25,
};


/**
 * @brief Offsets from base address for XIRs.
 */
const static uint64_t PPE_XIXCR    = 0x0; //XCR_NONE
const static uint64_t PPE_XIRAMRA  = 0x1; //XCR_SPRG0
const static uint64_t PPE_XIRAMGA  = 0x2; //IR_SPRG0
const static uint64_t PPE_XIRAMDBG = 0x3; //XSR_SPRG0
const static uint64_t PPE_XIRAMEDR = 0x4; //IR_EDR
const static uint64_t PPE_XIDBGPRO = 0x5; //XSR_IAR

enum PPE_DUMP_MODE
{
    NONE           = 0x0,
    XIRS           = 0x4,
    SNAPSHOT       = 0x1,
    HALT           = 0x2,
    FORCE_HALT     = 0x3
};
enum VERBOSE_MODE
{
    NOVERBOSE        = 0x0,
    VERBOSE          = 0x1,
    VERBOSEP         = 0x2,
    VERBOSE1         = 0x3,

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

//enum PPE_SPECIAL_ACCESS
//{
//    MSR,
//    CR,
//};
enum PPE_SPRS
{
    CTR     = 9,
    DACR    = 316,
    DBCR    = 308,
    DEC     = 22,
    EDR     = 61,
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
    XER     = 1,
    //Some unique identification no. FOR OTHER REGS(non sprn)
    XSR     = 4200,
    IAR     = 2,
    IR      = 3,
    MSR     = 42,
    CR      = 420,

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

#ifndef  __HOSTBOOT_MODULE
typedef struct
{
    SCOMRegValue_t    reg;
    std::string  name;
} SCOMReg_t;

typedef struct
{
    PPERegValue_t     reg;
    std::string  name;
} PPEReg_t;

// Vector defining all spr acceess egisters
const std::map<uint16_t, std::string> v_ppe_sprs_num_name =
{
    { MSR,   "MSR"    },
    { CR,    "CR"     },
    { CTR,   "CTR"    },
    { LR,    "LR"     },
    { ISR,   "ISR"    },
    { SRR0,  "SRR0"   },
    { SRR1,  "SRR1"   },
    { TCR,   "TCR"    },
    { TSR,   "TSR"    },
    { DACR,  "DACR"   },
    { DBCR,  "DBCR"   },
    { DEC,   "DEC"    },
    { IVPR,  "IVPR"   },
    { PIR,   "PIR"    },
    { PVR,   "PVR"    },
    { XER,   "XER"    }
};

// Vector defining the GPRs
const std::map<uint16_t, std::string> v_ppe_gprs_num_name =
{
    { R0,    "R0"     },
    { R1,    "R1"     },
    { R2,    "R2"     },
    { R3,    "R3"     },
    { R4,    "R4"     },
    { R5,    "R5"     },
    { R6,    "R6"     },
    { R7,    "R7"     },
    { R8,    "R8"     },
    { R9,    "R9"     },
    { R10,   "R10"    },
    { R13,   "R13"    },
    { R28,   "R28"    },
    { R29,   "R29"    },
    { R30,   "R30"    },
    { R31,   "R31"    }
};
// Vector defining the other xsr regs
const std::map<uint16_t, std::string> v_ppe_xsr_num_name =
{
    { XSR,   "XSR"    },
    { IAR,   "IAR"    },
    { IR,    "IR"     },
    { EDR,   "EDR"    },
    { SPRG0, "SPRG0"  }
};

#endif //__HOSTBOOT_MODULE

///--------------------------------------------------------------------------------------
/// @brief generates a PPE instruction for some formats
/// @param[in] i_Op      Opcode
/// @param[in] i_Rts     Source or Target Register
/// @param[in] i_RA      Address Register
/// @param[in] i_d       Instruction Data Field
/// @return returns 32 bit instruction representing the PPE instruction.
///--------------------------------------------------------------------------------------
uint32_t ppe_getInstruction( const uint16_t i_Op, const uint16_t i_Rts, const uint16_t i_Ra, const uint16_t i_d );

///--------------------------------------------------------------------------------------
/// @brief generates instruction for mtspr
/// @param[in] i_Rs      source register number
/// @param[in] i_Spr represents spr where data is to be moved.
/// @return returns 32 bit instruction representing mtspr instruction.
///--------------------------------------------------------------------------------------
uint32_t ppe_getMtsprInstruction( const uint16_t i_Rs, const uint16_t i_Spr );


///--------------------------------------------------------------------------------------
/// @brief generates instruction for mfspr
/// @param[in] i_Rt      target register number
/// @param[in] i_Spr represents spr where data is to sourced
/// @return returns 32 bit instruction representing mfspr instruction.
///--------------------------------------------------------------------------------------

uint32_t ppe_getMfsprInstruction( const uint16_t i_Rt, const uint16_t i_Spr );

///--------------------------------------------------------------------------------------
/// @brief generates instruction for mfmsr instruction.
/// @param[in]   i_Rt     target register number
/// @return  returns 32 bit instruction representing mfmsr instruction.
/// @note    moves contents of register MSR to i_Rt register.
///--------------------------------------------------------------------------------------
uint32_t ppe_getMfmsrInstruction( const uint16_t i_Rt );

///--------------------------------------------------------------------------------------
/// @brief generates instruction for mfcr instruction.
/// @param[in]   i_Rt     target register number
/// @return  returns 32 bit instruction representing mfcr instruction.
/// @note    moves contents of register CR to i_Rt register.
///--------------------------------------------------------------------------------------
uint32_t ppe_getMfcrInstruction( const uint16_t i_Rt );

///--------------------------------------------------------------------------------------
/// @brief poll for Halt state
/// @param[in]  i_target fapi2 target for proc chip
/// @param[in]  i_base_address  base SCOM address of the PPE
/// @return  fapi2::ReturnCode
/// @note    moves contents of register MSR to i_Rt register.
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_pollHaltState(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address) ;

///--------------------------------------------------------------------------------------
/// @brief halt the engine
/// @param[in]  i_target fapi2 target for proc chip
/// @param[in]  i_base_address  base SCOM address of the PPE
/// @return  fapi2::ReturnCode
/// @note    programs XCR with halt bit to halt the engine.
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address );

///--------------------------------------------------------------------------------------
/// @brief force halt the engine
/// @param[in]  i_target fapi2 target for proc chip
/// @param[in]  i_base_address  base SCOM address of the PPE
/// @return  fapi2::ReturnCode
/// @note    programs XCR with force halt  to force halt the engine.
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_force_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address );

///--------------------------------------------------------------------------------------
/// @brief resume the halted engine
/// @param[in]  i_target fapi2 target for proc chip
/// @param[in]  i_base_address  base SCOM address of the PPE
/// @return  fapi2::ReturnCode
/// @note    programs XCR with resume bit to resume the engine.
///--------------------------------------------------------------------------------------
fapi2::ReturnCode ppe_resume(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address );

///--------------------------------------------------------------------------------------
/// @brief update dbcr
/// @param[in]  i_target fapi2 target for proc chip
/// @param[in]  i_base_address  base SCOM address of the PPE
/// @param[in]  i_inst_op       instruction opcode
/// @param[in]  i_immed_16      16 bit constant
/// @param[in]  i_Rs            source GPR number
/// @return  fapi2::ReturnCode
/// @note    programs mtdbcr
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_update_dbcr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const uint64_t i_inst_op,
    const uint16_t i_immed_16,
    const uint16_t i_Rs );

///--------------------------------------------------------------------------------------
/// @brief update dacr
/// @param[in]   i_target  target register number
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @param[in]   i_address       address to be updated
/// @return      fapi2::ReturnCode
/// @note        programs mtdacr
///--------------------------------------------------------------------------------------
fapi2::ReturnCode ppe_update_dacr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const uint64_t i_address,
    const uint16_t i_Rs );

///--------------------------------------------------------------------------------------
/// @brief Perform RAM "read" operation
/// @param[in]   i_target        Chip Target
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @param[in]   i_instruction   RAM instruction to move a register
/// @param[out]  o_data          Returned data
/// @return  fapi2::ReturnCode
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_RAMRead(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const fapi2::buffer<uint64_t> i_instruction,
    fapi2::buffer<uint32_t>& o_data );

///--------------------------------------------------------------------------------------
/// @brief Perform RAM "read" operation
/// @param[in]   i_target        Chip Target
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @param[in]   i_instruction   RAM instruction to move a register
/// @return  fapi2::ReturnCode
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_RAM(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const uint64_t i_instruction
);

///--------------------------------------------------------------------------------------
/// @brief single step the engine
/// @param[in]   i_target  target register number
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @param[in]   i_Rs
/// @param[in]   i_step_count
/// @return  fapi2::ReturnCode
/// @note    programs XCR with single step  tosingle step the engine.
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_single_step(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const uint16_t i_Rs,
    uint64_t i_step_count );


///--------------------------------------------------------------------------------------
/// @brief clear the dbg status engine
/// @param[in]   i_target  target register number
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @return  fapi2::ReturnCode
/// @note    programs XCR to clear dbg status.
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_clear_dbg(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address );

///--------------------------------------------------------------------------------------
/// @brief toggle TRH
/// @param[in]   i_target  target register number
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @return  fapi2::ReturnCode
/// @note    programs XCR to toggle trh.
///--------------------------------------------------------------------------------------
fapi2::ReturnCode ppe_toggle_trh(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address );

///--------------------------------------------------------------------------------------
/// @brief xcr soft reset
/// @param[in]   i_target  target register number
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @return  fapi2::ReturnCode
/// @note    programs XCR to give soft reset
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_soft_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address );

///--------------------------------------------------------------------------------------
/// @brief xcr hard reset
/// @param[in]   i_target        target register number
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @return  fapi2::ReturnCode
/// @note    programs XCR to give hard reset
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_hard_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address );

///--------------------------------------------------------------------------------------
/// @brief xcr resume only
/// @param[in]   i_target  target register number
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @return  fapi2::ReturnCode
/// @note    programs XCR to only resume
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_resume_only(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address );

///--------------------------------------------------------------------------------------
/// @brief only single step the engine
/// @param[in]   i_target  target register number
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @param[in]   i_step_count
/// @return  fapi2::ReturnCode
/// @note    programs XCR with single step no clearing DBCR
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_ss_only(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    uint64_t i_step_count );

///--------------------------------------------------------------------------------------
/// @brief populate IAR register with a given address
/// @param[in]   i_target        target register number
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @param[in]   i_address       address to be populated
/// @return  fapi2::ReturnCode
/// @note    programs XCR with single step no clearing DBCR
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_write_iar(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const uint64_t i_address );

#ifndef  __HOSTBOOT_MODULE

///--------------------------------------------------------------------------------------
/// @brief   finds name of SCOM registers and populates a vector
/// @param[in]   i_ppe_regs_value    a vector of SCOMRegValue_t
/// @param[in]   i_ppe_regs_num_name a map of reg num and respective name
/// @param[in]   i_scom_regs         a vector of SCOMReg_t
/// @return  fapi2::ReturnCode
///--------------------------------------------------------------------------------------

fapi2::ReturnCode scom_regs_populate_name(
    std::vector<SCOMRegValue_t> i_ppe_regs_value,
    const std::map<uint16_t, std::string> i_ppe_regs_num_name,
    std::vector<SCOMReg_t>& i_scom_regs );

///--------------------------------------------------------------------------------------
/// @brief       populates register names
/// @param[in]   i_ppe_regs_value
/// @param[in]   i_ppe_regs_num_name
/// @param[in]   i_ppe_regs
/// @return      fapi2::ReturnCode
///--------------------------------------------------------------------------------------

fapi2::ReturnCode ppe_regs_populate_name(
    std::vector<PPERegValue_t> i_ppe_regs_value,
    const std::map<uint16_t, std::string> i_ppe_regs_num_name,
    std::vector<PPEReg_t>& i_ppe_regs );

#endif  //__HOSTBOOT_MODULE
#endif  // __P9_PPE_UTILS_H__
