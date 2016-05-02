/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_ppe_state.C $       */
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
/// @file  p9_ppe_state.C
/// @brief Get PPE's internal state
///
/// *HWP HW Owner        : Ashish More <ashish.more.@in.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : SBE, Cronus
///
/// @verbatim
///
/// Procedure Summary:
///   - Dump out PPE's internal state
///
/// @endverbatim

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_ppe_state.H>
#include <p9_hcd_common.H>

/**
 * @brief Offsets from base address for XIRs.
 */
const static uint64_t PPE_XIXCR    = 0x0;
const static uint64_t PPE_XIRAMRA  = 0x1;
const static uint64_t PPE_XIRAMGA  = 0x2;
const static uint64_t PPE_XIRAMDBG = 0x3;
const static uint64_t PPE_XIRAMEDR = 0x4;
const static uint64_t PPE_XIDBGPRO = 0x5;


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
};

// Vector defining the special acceess egisters
std::vector<PPEReg_t> v_ppe_special_regs =
{
    { MSR,   "MSR"    },
    { CR,    "CR"     },
};

// Vector defining the major SPRs
// Note: SPRG0 is not include as it is saved and restored as the means for
// accessing the other SPRS
std::vector<PPEReg_t> v_ppe_major_sprs =
{
    { CTR,   "CTR"    },
    { LR,    "LR"     },
    { ISR,   "ISR"    },
    { SRR0,  "SRR0"   },
    { SRR1,  "SRR1"   },
    { TCR,   "TCR"    },
    { TSR,   "TSR"    },
};

// Vector defining the minor SPRs
std::vector<PPEReg_t> v_ppe_minor_sprs =
{
    { DACR,  "DACR"   },
    { DBCR,  "DBCR"   },
    { DEC,   "DEC"    },
    { IVPR,  "IVPR"   },
    { PIR,   "PIR"    },
    { PVR,   "PVR"    },
    { XER,   "XER"    },
};

// Vector defining the GPRs
std::vector<PPEReg_t> v_ppe_gprs =
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
    { R31,   "R31"    },
};



//-----------------------------------------------------------------------------

/**
 * @brief generates a PPE instruction for some formats
 * @param[in] i_Op      Opcode
 * @param[in] i_Rts     Source or Target Register
 * @param[in] i_RA      Address Register
 * @param[in] i_d       Instruction Data Field
 * @return returns 32 bit instruction representing the PPE instruction.
 */

uint32_t getInstruction( const uint16_t i_Op, const uint16_t i_Rts, const uint16_t i_Ra, const uint16_t i_d)
{
    uint32_t instOpcode = 0;

    instOpcode = (i_Op & 0x3F) << (31 - 5);
    instOpcode |= (i_Rts & 0x1F) << (31 - 10);
    instOpcode |= (i_Ra & 0x1F) << (31 - 15);
    instOpcode |= (i_d & 0xFFFF) << (31 - 31);

    return instOpcode;
}
//-----------------------------------------------------------------------------

/**
 * @brief generates instruction for mtspr
 * @param[in] i_Rs      source register number
 * @param[in] i_Spr represents spr where data is to be moved.
 * @return returns 32 bit instruction representing mtspr instruction.
 */
uint32_t getMtsprInstruction( const uint16_t i_Rs, const uint16_t i_Spr )
{
    uint32_t mtsprInstOpcode = 0;
    uint32_t temp = (( i_Spr & 0x03FF ) << 11);
    mtsprInstOpcode = ( temp  & 0x0000F800 ) << 5;
    mtsprInstOpcode |= ( temp & 0x001F0000 ) >> 5;
    mtsprInstOpcode |= MTSPR_BASE_OPCODE;
    mtsprInstOpcode |= ( i_Rs & 0x001F ) << 21;

    return mtsprInstOpcode;
}

//-----------------------------------------------------------------------------

/**
 * @brief generates instruction for mfspr
 * @param[in] i_Rt      target register number
 * @param[in] i_Spr represents spr where data is to sourced
 * @return returns 32 bit instruction representing mfspr instruction.
 */
uint32_t getMfsprInstruction( const uint16_t i_Rt, const uint16_t i_Spr )
{
    uint32_t mtsprInstOpcode = 0;
    uint32_t temp = (( i_Spr & 0x03FF ) << 11);
    mtsprInstOpcode = ( temp  & 0x0000F800 ) << 5;
    mtsprInstOpcode |= ( temp & 0x001F0000 ) >> 5;
    mtsprInstOpcode |= MFSPR_BASE_OPCODE;
    mtsprInstOpcode |= ( i_Rt & 0x001F ) << 21;

    return mtsprInstOpcode;
}

//-----------------------------------------------------------------------------

/**
 * @brief generates instruction for mfmsr instruction.
 * @param[in]   i_Rt     target register number
 * @return  returns 32 bit instruction representing mfmsr instruction.
 * @note    moves contents of register MSR to i_Rt register.
 */
uint32_t getMfmsrInstruction( const uint16_t i_Rt )
{
    uint32_t mfmsrdInstOpcode = 0;
    mfmsrdInstOpcode = 0;
    mfmsrdInstOpcode = OPCODE_31 << 26;
    mfmsrdInstOpcode |= i_Rt << 21 | ( MFMSRD_CONST1 << 1 );

    return mfmsrdInstOpcode;
}

//-----------------------------------------------------------------------------

/**
 * @brief generates instruction for mfcr instruction.
 * @param[in]   i_Rt     target register number
 * @return  returns 32 bit instruction representing mfcr instruction.
 * @note    moves contents of register CR to i_Rt register.
 */
uint32_t getMfcrInstruction( const uint16_t i_Rt )
{
    uint32_t mfcrdInstOpcode = 0;
    mfcrdInstOpcode = 0;
    mfcrdInstOpcode = OPCODE_31 << 26;
    mfcrdInstOpcode |= i_Rt << 21 | ( MFCR_CONST1 << 1 );

    return mfcrdInstOpcode;
}

//-----------------------------------------------------------------------------

/**
 * @brief poll for Halt state
 * @param[in]   i_Rt     target register number
 * @return  fapi2::ReturnCode
 * @note    moves contents of register MSR to i_Rt register.
 */
fapi2::ReturnCode pollHaltState(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    // Halt state entry should be very fast on PPEs (eg nanoseconds)
    // Try only using the SCOM access time to delay.
    static const uint32_t HALT_TRIES = 10;

    uint32_t l_timeout_count = HALT_TRIES;

    do
    {
        FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMDBG, l_data64), "Error in GETSCOM");
    }
    while (! l_data64.getBit<0>() &&
           --l_timeout_count != 0);


    FAPI_ASSERT(l_data64.getBit<0>(), fapi2::P9_PPE_STATE_HALT_TIMEOUT_ERR(),
                "PPE Halt Timeout");


fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------

/**
 * @brief halt the engine
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs XCR with halt bit to halt the engine.
 */
fapi2::ReturnCode halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("   Send HALT command via XCR...");
    l_data64.flush<0>().insertFromRight(p9hcd::HALT, 1, 3);

    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64), "Error in PUTSCOM in XCR to generate Halt condition");

    FAPI_TRY(pollHaltState(i_target, i_base_address));

fapi_try_exit:
    return fapi2::current_err;
}
//-----------------------------------------------------------------------------

/**
 * @brief force halt the engine
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs XCR with force halt  to force halt the engine.
 */
fapi2::ReturnCode force_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("   Send FORCE HALT command via XCR...");
    l_data64.flush<0>().insertFromRight(p9hcd::FORCE_HALT, 1, 3);

    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64),
             "Error in PUTSCOM in XCR to generate Force Halt condition");

    FAPI_TRY(pollHaltState(i_target, i_base_address));

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------

/**
 * @brief resume the halted engine
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs XCR with resume bit to resume the engine.
 */
fapi2::ReturnCode resume(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    static const uint32_t RESUME_TRIES = 10;
    uint32_t l_timeout_count = RESUME_TRIES;

    FAPI_INF("   Send RESUME command via XCR...");
    l_data64.flush<0>().insertFromRight(p9hcd::RESUME, 1, 3);

    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64), "Error in PUTSCOM in XCR to resume condition");

    do
    {
        FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64));
        FAPI_DBG("   Poll content:  XSR: 0x%16llX", l_data64);
    }
    while((l_data64.getBit<p9hcd::HALTED_STATE>() != 0) && (--l_timeout_count != 0));

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------

/**
 * @brief Perform RAM "read" operation
 * @param[in]   i_target        Chip Target
 * @param[in]   i_base_address  Base SCOM address of the PPE
 * @param[in]   i_instruction   RAM instruction to move a register
 * @param[out]  o_data          Returned data
 * @return  fapi2::ReturnCode
 */
fapi2::ReturnCode RAMRead(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const fapi2::buffer<uint64_t> i_instruction,
    fapi2::buffer<uint32_t>& o_data)
{
    fapi2::buffer<uint64_t> l_data64;
    FAPI_TRY(pollHaltState(i_target, i_base_address));
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, i_instruction));
    FAPI_DBG("    RAMREAD i_instruction: 0X%16llX", i_instruction);
    FAPI_TRY(pollHaltState(i_target, i_base_address));
    FAPI_TRY(fapi2::getScom(i_target, i_base_address + PPE_XIRAMDBG, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(o_data, 32, 32);
    FAPI_DBG("    RAMREAD o_data: 0X%16llX", o_data);

fapi_try_exit:
    return fapi2::current_err;
}


//-----------------------------------------------------------------------------

/**
 * @brief Perform PPE internal reg "read" operation
 * @param[in]   i_target        Chip Target
 * @param[in]   i_base_address  Base SCOM address of the PPE
 * @param[in]   i_mode          PPE Dump Mode
 * @param[out]  v_ppe_minor_sprs_value   Returned data
 * @param[out]  v_ppe_major_sprs_value   Returned data
 * @param[out]  v_ppe_xirs_value   Returned data
 * @param[out]  v_ppe_gprs_value   Returned data
 * @param[out]  v_ppe_special_sprs_value   Returned data
 * @return  fapi2::ReturnCode
 */
fapi2::ReturnCode
ppe_state_data(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
               const uint64_t i_base_address,
               const PPE_DUMP_MODE i_mode,
               std::vector<PPERegValue_t>& v_ppe_minor_sprs_value,
               std::vector<PPERegValue_t>& v_ppe_major_sprs_value,
               std::vector<PPERegValue_t>& v_ppe_xirs_value,
               std::vector<PPERegValue_t>& v_ppe_gprs_value,
               std::vector<PPERegValue_t>& v_ppe_special_sprs_value)
{
    fapi2::buffer<uint64_t> l_raminstr;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint32_t> l_gpr0_save;
    fapi2::buffer<uint64_t> l_sprg0_save;
    bool l_ppe_halt_state = false;
    PPERegValue_t l_regVal;
    SCOMRegValue_t l_scomregVal;

    char outstr[32];

    FAPI_INF("Base Address : 0x%08llX", i_base_address);

    //If requested make sense to halt PPE first if requested (XIR reads are not dependent on this ,
    //But XSR content can change after halt and it is better to capture XSR content after halt(if requested)
    if (i_mode == HALT)
    {
        FAPI_TRY(halt(i_target, i_base_address));

    }

    if (i_mode == FORCE_HALT)
    {
        FAPI_TRY(force_halt(i_target, i_base_address));

    }

    FAPI_INF("------   XIRs   ------");
    // XSR and IAR
    FAPI_TRY(getScom(i_target, i_base_address + PPE_XIDBGPRO, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 0, 32);
    sprintf(outstr, "XSR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.reg.number = 1;
    l_regVal.reg.name = "XSR";
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);

    l_data64.extractToRight(l_data32, 32, 32);
    sprintf(outstr, "IAR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.reg.number = 2;
    l_regVal.reg.name = "IAR";
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);

    // IR and EDR
    FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 0, 32);
    sprintf(outstr, "IR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.reg.number = 3;
    l_regVal.reg.name = "IR";
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);


    l_data64.extractToRight(l_data32, 32, 32);
    sprintf(outstr, "EDR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.reg.number = 4;
    l_regVal.reg.name = "EDR";
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);


    // Save SPRG0
    FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMDBG, l_sprg0_save), "Error in GETSCOM");
    l_sprg0_save.extractToRight(l_data32, 32, 32);
    sprintf(outstr, "SPRG0");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.reg.number = 5;
    l_regVal.reg.name = "SPRG0";
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);


    //Initially Check for halt
    FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMDBG, l_data64), "Error in GETSCOM");

    if (l_data64.getBit(0, 1))
    {
        l_ppe_halt_state  = true;

    }
    else
    {
        l_ppe_halt_state  = false;
    }

    //IF PPE is halted(by default or due to halt/force_halt swicthes) or SNAPSHOT mode , get the other internal registers
    if ((i_mode == SNAPSHOT) || l_ppe_halt_state)
    {
        //If SNAPSHOT mode and PPE is not halted do XCR halt; before ramming
        if((i_mode == SNAPSHOT) && !(l_ppe_halt_state))
        {
            FAPI_TRY(halt(i_target, i_base_address));
        }

        FAPI_DBG("Save GPR0");
        l_raminstr.flush<0>().insertFromRight(getMtsprInstruction(R0, SPRG0), 0, 32);
        FAPI_DBG("getMtsprInstruction(%d, SPRG0): 0x%16llX", 0, l_raminstr );

        FAPI_TRY(RAMRead(i_target, i_base_address, l_raminstr, l_gpr0_save));
        FAPI_DBG("Saved GPR0 value : 0x%08llX", l_gpr0_save );

        FAPI_INF("---   Major SPRs    --");

        for (auto it : v_ppe_major_sprs)
        {

            // SPR to R0
            l_raminstr.flush<0>().insertFromRight(getMfsprInstruction(0, it.number), 0, 32);
            FAPI_DBG("%-6s: getMfsprInstruction(R0, %5d): 0x%16llX", it.name.c_str(), it.number, l_raminstr );
            FAPI_TRY(pollHaltState(i_target, i_base_address));
            FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_raminstr));

            // R0 to SPRG0
            l_raminstr.flush<0>().insertFromRight(getMtsprInstruction(0, SPRG0), 0, 32);
            FAPI_DBG("%-6s: getMtsprInstruction(R0, SPRG0): 0x%16llX", it.name.c_str(), l_raminstr );

            FAPI_TRY(RAMRead(i_target, i_base_address, l_raminstr, l_data32));

            FAPI_INF("%-9s = 0x%08llX", it.name.c_str(), l_data32);

            l_regVal.reg = it;
            l_regVal.value = l_data32;
            v_ppe_major_sprs_value.push_back(l_regVal);


        }

        FAPI_INF("--- State Registers --");
        // MSR

        // MSR to R0
        l_raminstr.flush<0>().insertFromRight(getMfmsrInstruction(0), 0, 32);
        FAPI_DBG("      getMfmsrInstruction(R0): 0x%16llX", l_raminstr );
        FAPI_TRY(pollHaltState(i_target, i_base_address));
        FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_raminstr));

        // R0 to SPRG0
        l_raminstr.flush<0>().insertFromRight(getMtsprInstruction(0, SPRG0), 0, 32);
        FAPI_DBG("          : getMtsprInstruction(R0, SPRG0): 0x%16llX", l_raminstr );

        FAPI_TRY(RAMRead(i_target, i_base_address, l_raminstr, l_data32));

        sprintf(outstr, "MSR");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.reg.number = 42;
        l_regVal.reg.name = "MSR";
        l_regVal.value = l_data32;
        v_ppe_special_sprs_value.push_back(l_regVal);
        // CR

        // CR to R0
        l_raminstr.flush<0>().insertFromRight(getMfcrInstruction(0), 0, 32);
        FAPI_DBG("          getMfcrInstruction(R0): 0x%16llX", l_raminstr );
        FAPI_TRY(pollHaltState(i_target, i_base_address));
        FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_raminstr));

        // R0 to SPRG0
        l_raminstr.flush<0>().insertFromRight(getMtsprInstruction(0, SPRG0), 0, 32);
        FAPI_DBG("          : getMtsprInstruction(R0, SPRG0): 0x%16llX", l_raminstr );

        FAPI_TRY(RAMRead(i_target, i_base_address, l_raminstr, l_data32));

        sprintf(outstr, "CR");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.reg.number = 420;
        l_regVal.reg.name = "CR";
        l_regVal.value = l_data32;
        v_ppe_special_sprs_value.push_back(l_regVal);
        FAPI_INF("-------  GPRs  -------");

        for (auto it : v_ppe_gprs)
        {
            l_raminstr.flush<0>().insertFromRight(getMtsprInstruction(it.number, SPRG0), 0, 32);
            //l_raminstr.flush<0>().insertFromRight(getMtsprInstruction(0, SPRG0), 0, 32);
            FAPI_DBG("getMtsprInstruction(%d, SPRG0): 0x%16llX", it.number, l_raminstr );
            FAPI_TRY(RAMRead(i_target, i_base_address, l_raminstr, l_data32));

            sprintf(outstr, "GPR%d", it.number);

            if (it.number == 0)
            {
                FAPI_INF("%-9s = 0x%08llX", outstr, l_gpr0_save);
                l_regVal.reg = it;
                l_regVal.value = l_gpr0_save;
                v_ppe_gprs_value.push_back(l_regVal);
            }
            else
            {
                FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
                l_regVal.reg = it;
                l_regVal.value = l_data32;
                v_ppe_gprs_value.push_back(l_regVal);
            }
        }

        FAPI_INF("----- Minor SPRs -----");

        for (auto it : v_ppe_minor_sprs)
        {
            // SPR to R0
            l_raminstr.flush<0>().insertFromRight(getMfsprInstruction(0, it.number), 0, 32);
            FAPI_DBG("%-6s: getMfsprInstruction(R0, %5d): 0x%16llX", it.name.c_str(), it.number, l_raminstr );
            FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_raminstr));

            // R0 to SPRG0
            //ashish
            //l_raminstr.flush<0>().insertFromRight(getMtsprInstruction(it.number, SPRG0), 0, 32);
            l_raminstr.flush<0>().insertFromRight(getMtsprInstruction(0, SPRG0), 0, 32);

            FAPI_DBG("%-6s: getMtsprInstruction(R0, SPRG0): 0x%16llX", it.name.c_str(), l_raminstr );
            l_data32.flush<0>().insertFromRight(0XDEADBEEF, 0, 31);
            FAPI_TRY(RAMRead(i_target, i_base_address, l_raminstr, l_data32));

            FAPI_INF("%-9s = 0x%08llX", it.name.c_str(), l_data32);

            l_regVal.reg = it;
            l_regVal.value = l_data32;
            v_ppe_minor_sprs_value.push_back(l_regVal);

        }


        FAPI_DBG("Restore GPR0");
        l_gpr0_save.extractToRight(l_data64, 0, 32);  // Put 32b save value into 64b buffer
        FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMDBG, l_data64));
        l_data64.flush<0>().insertFromRight(getMfsprInstruction(R0, SPRG0), 0, 32);
        FAPI_DBG("getMtsprInstruction(%d, SPRG0): 0x%16llX", 0, l_data64 );
        FAPI_TRY(pollHaltState(i_target, i_base_address));
        FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64));


        FAPI_DBG("Restore SPRG0");
        FAPI_TRY(pollHaltState(i_target, i_base_address));
        FAPI_TRY(putScom(i_target, i_base_address + PPE_XIRAMDBG , l_sprg0_save), "Error in GETSCOM");

        //If SNAPSHOT mode and only if initially PPE was not halted then do XCR(resume)
        if ((i_mode == SNAPSHOT) && ~(l_ppe_halt_state))
        {
            FAPI_TRY(resume(i_target, i_base_address));

            FAPI_INF("------   XIRs After resume   ------");
            // XSR and IAR
            FAPI_TRY(getScom(i_target, i_base_address + PPE_XIDBGPRO, l_data64), "Error in GETSCOM");
            l_data64.extractToRight(l_data32, 0, 32);
            sprintf(outstr, "XSR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.reg.number = 1;
            l_regVal.reg.name = "XSR";
            l_regVal.value = l_data32;

            l_data64.extractToRight(l_data32, 32, 32);
            sprintf(outstr, "IAR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.reg.number = 2;
            l_regVal.reg.name = "IAR";
            l_regVal.value = l_data32;


            // IR and EDR
            FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64), "Error in GETSCOM");
            l_data64.extractToRight(l_data32, 0, 32);
            sprintf(outstr, "IR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.reg.number = 3;
            l_regVal.reg.name = "IR";
            l_regVal.value = l_data32;


            l_data64.extractToRight(l_data32, 32, 32);
            sprintf(outstr, "EDR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.reg.number = 4;
            l_regVal.reg.name = "EDR";
            l_regVal.value = l_data32;

            // Save SPRG0
            FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMDBG, l_sprg0_save), "Error in GETSCOM");
            l_sprg0_save.extractToRight(l_data32, 32, 32);
            sprintf(outstr, "SPRG0");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.reg.number = 5;
            l_regVal.reg.name = "SPRG0";
            l_regVal.value = l_data32;


        }


    }
    else
    {
        FAPI_INF("\nPPE is not Halted\n");
    }

fapi_try_exit:
    return fapi2::current_err;
}

// Hardware procedure
fapi2::ReturnCode
p9_ppe_state(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
             const uint64_t i_base_address,
             const PPE_DUMP_MODE i_mode,
             std::vector<PPERegValue_t>& v_ppe_sprs_value,
             std::vector<PPERegValue_t>& v_ppe_xirs_value,
             std::vector<PPERegValue_t>& v_ppe_gprs_value
            )
{
    std::vector<PPERegValue_t> v_ppe_minor_sprs_value;
    std::vector<PPERegValue_t> v_ppe_major_sprs_value;
    std::vector<PPERegValue_t> v_ppe_special_sprs_value;


    //Call the function to collect the data.
    ppe_state_data(i_target,
                   i_base_address,
                   i_mode,
                   v_ppe_minor_sprs_value,
                   v_ppe_major_sprs_value,
                   v_ppe_xirs_value,
                   v_ppe_gprs_value,
                   v_ppe_special_sprs_value);


    v_ppe_sprs_value.reserve(v_ppe_special_sprs_value.size() + v_ppe_major_sprs_value.size() +
                             v_ppe_minor_sprs_value.size()); // preallocate memory
    v_ppe_sprs_value.insert( v_ppe_sprs_value.end(), v_ppe_special_sprs_value.begin(), v_ppe_special_sprs_value.end() );
    v_ppe_sprs_value.insert( v_ppe_sprs_value.end(), v_ppe_major_sprs_value.begin(), v_ppe_major_sprs_value.end() );
    v_ppe_sprs_value.insert( v_ppe_sprs_value.end(), v_ppe_minor_sprs_value.begin(), v_ppe_minor_sprs_value.end() );

//fapi_try_exit:
    return fapi2::current_err;
} // Procedure
