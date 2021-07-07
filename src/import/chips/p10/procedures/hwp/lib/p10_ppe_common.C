/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_ppe_common.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include <fapi2.H>
#include <p10_ppe_common.H>
#include <p10_hcd_common.H>

/**
 * @brief generates a PPE instruction for some formats
 * @param[in] i_Op      Opcode
 * @param[in] i_Rts     Source or Target Register
 * @param[in] i_RA      Address Register
 * @param[in] i_d       Instruction Data Field
 * @return returns 32 bit instruction representing the PPE instruction.
 */

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
    ADDIS_CONST       = 15,
    LWZ_CONST         = 32,
    STW_CONST         = 36,
    LVD_CONST         = 5,

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
    D0  = 0 ,
};





uint32_t getInstructionDone( const uint16_t i_Op, const uint16_t i_Rts, const uint16_t i_Ra, const uint16_t i_d)
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
uint32_t getMtsprInstructionDone( const uint16_t i_Rs, const uint16_t i_Spr )
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
uint32_t getMfsprInstructionDone( const uint16_t i_Rt, const uint16_t i_Spr )
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
uint32_t getMfmsrInstructionDone( const uint16_t i_Rt )
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
uint32_t getMfcrInstructionDone( const uint16_t i_Rt )
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
fapi2::ReturnCode pollHaltStateDone(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_sbe_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    // Halt state entry should be very fast on PPEs (eg nanoseconds)
    // Try only using the SCOM access time to delay.
    static const uint32_t HALT_TRIES = 10;

    uint32_t l_timeout_count = HALT_TRIES;

    do
    {
        FAPI_INF("  reading XIRAMDBG: timeout_count = %d  ...", l_timeout_count);
        FAPI_TRY(getScom(i_target, i_sbe_base_address + PPE_XIRAMDBG, l_data64), "Error in GETSCOM");
    }
    while (! l_data64.getBit<0>() &&
           --l_timeout_count != 0);

#define __READY_FOR_P10__
#ifdef __READY_FOR_P10__
    FAPI_ASSERT(l_data64.getBit<0>(),
                fapi2::P10_PPE_STATE_HALT_TIMEOUT_ERR()
                .set_TARGET(i_target)
                .set_SBE_BASE_ADDRESS(i_sbe_base_address),
                "PPE Halt Timeout");
#endif

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
fapi2::ReturnCode haltDone(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_sbe_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("   Send HALT command via XCR...");
    l_data64.flush<0>().insertFromRight(XCR_HALT, 1, 3);

    FAPI_TRY(putScom(i_target, i_sbe_base_address + PPE_XIXCR, l_data64),
             "Error in PUTSCOM in XCR to generate Halt condition");

    FAPI_TRY(pollHaltStateDone(i_target, i_sbe_base_address));

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


fapi2::ReturnCode resumeDone(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_sbe_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    static const uint32_t RESUME_TRIES = 10;
    uint32_t l_timeout_count = RESUME_TRIES;

    FAPI_INF("   Send RESUME command via XCR...");
    l_data64.flush<0>().insertFromRight(XCR_RESUME, 1, 3);

    FAPI_TRY(putScom(i_target, i_sbe_base_address + PPE_XIXCR, l_data64), "Error in PUTSCOM in XCR to resume condition");

    do
    {
        FAPI_TRY(getScom(i_target, i_sbe_base_address + PPE_XIRAMEDR, l_data64));
        FAPI_DBG("   Poll content:  XSR: 0x%16llX", l_data64);
    }
    while((l_data64.getBit<XSR_HALTED_STATE>() != 0) && (--l_timeout_count != 0));

fapi_try_exit:
    return fapi2::current_err;
}



//-----------------------------------------------------------------------------

/**
 * @brief Perform RAM "read" operation
 * @param[in]   i_target        Chip Target
 * @param[in]   i_sbe_base_address  Base SCOM address of the PPE
 * @param[in]   i_instruction   RAM instruction to move a register
 * @param[out]  o_data          Returned data
 * @return  fapi2::ReturnCode
 */
fapi2::ReturnCode RAMReadDone(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_sbe_base_address,
    const fapi2::buffer<uint64_t> i_instruction,
    fapi2::buffer<uint32_t>& o_data)

{
    fapi2::buffer<uint64_t> l_data64;
    FAPI_TRY(pollHaltStateDone(i_target, i_sbe_base_address));
    FAPI_TRY(fapi2::putScom(i_target, i_sbe_base_address + PPE_XIRAMEDR, i_instruction));
    FAPI_DBG("    RAMREAD i_instruction: 0X%16llX", i_instruction);
    FAPI_TRY(pollHaltStateDone(i_target, i_sbe_base_address));
    FAPI_TRY(fapi2::getScom(i_target, i_sbe_base_address + PPE_XIRAMDBG, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(o_data, 32, 32);
    FAPI_DBG("    RAMREAD o_data: 0X%16llX", o_data);

fapi_try_exit:
    return fapi2::current_err;
}




fapi2::ReturnCode backup_gprs_sprs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    fapi2::buffer<uint32_t>& l_gpr0_save,
    fapi2::buffer<uint32_t>& l_gpr1_save,
    fapi2::buffer<uint32_t>& l_gpr9_save,
    fapi2::buffer<uint64_t>& l_sprg0_save)

{
    fapi2::buffer<uint64_t> l_raminstr;
    //    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data32;


    //***********************************************************
    // Backup R0 , R1 , R9 , SPRG0
    //***********************************************************


    // Save SPRG0
    FAPI_DBG("Save SPRG0");
    FAPI_TRY(getScom(i_target, sbe_base_address + PPE_XIRAMDBG, l_sprg0_save), "Error in GETSCOM");
    l_sprg0_save.extractToRight(l_data32, 32, 32);

    FAPI_DBG("Save GPR0");
    l_raminstr.flush<0>().insertFromRight(getMtsprInstructionDone(R0, SPRG0), 0, 32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_raminstr );

    FAPI_TRY(RAMReadDone(i_target, sbe_base_address, l_raminstr, l_gpr0_save));
    FAPI_DBG("Saved GPR0 value : 0x%08llX", l_gpr0_save );

    FAPI_DBG("Save GPR1");
    l_raminstr.flush<0>().insertFromRight(getMtsprInstructionDone(R1, SPRG0), 0, 32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_raminstr );

    FAPI_TRY(RAMReadDone(i_target, sbe_base_address, l_raminstr, l_gpr1_save));
    FAPI_DBG("Saved GPR1 value : 0x%08llX", l_gpr1_save );

    FAPI_DBG("Save GPR9");
    l_raminstr.flush<0>().insertFromRight(getMtsprInstructionDone(R9, SPRG0), 0, 32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_raminstr );

    FAPI_TRY(RAMReadDone(i_target, sbe_base_address, l_raminstr, l_gpr9_save));
    FAPI_DBG("Saved GPR9 value : 0x%08llX", l_gpr9_save );

fapi_try_exit:
    return fapi2::current_err;

}



fapi2::ReturnCode restore_gprs_sprs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    fapi2::buffer<uint32_t> l_gpr0_save,
    fapi2::buffer<uint32_t> l_gpr1_save,
    fapi2::buffer<uint32_t> l_gpr9_save,
    fapi2::buffer<uint64_t> l_sprg0_save)

{
    fapi2::buffer<uint64_t> l_raminstr;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data32;


    //***********************************************************
    // Restore R0 , R1 , R9 , SPRG0
    //***********************************************************


    FAPI_DBG("Restore GPR0");
    l_gpr0_save.extractToRight(l_data64, 0, 32);  // Put 32b save value into 64b buffer
    FAPI_TRY(fapi2::putScom(i_target, sbe_base_address + PPE_XIRAMDBG, l_data64));
    l_data64.flush<0>().insertFromRight(getMfsprInstructionDone(R0, SPRG0), 0, 32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_data64 );
    FAPI_TRY(pollHaltStateDone(i_target, sbe_base_address));
    FAPI_TRY(fapi2::putScom(i_target, sbe_base_address + PPE_XIRAMEDR, l_data64));

    FAPI_DBG("Restore GPR1");
    l_gpr1_save.extractToRight(l_data64, 0, 32);  // Put 32b save value into 64b buffer
    FAPI_TRY(fapi2::putScom(i_target, sbe_base_address + PPE_XIRAMDBG, l_data64));
    l_data64.flush<0>().insertFromRight(getMfsprInstructionDone(R1, SPRG0), 0, 32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_data64 );
    FAPI_TRY(pollHaltStateDone(i_target, sbe_base_address));
    FAPI_TRY(fapi2::putScom(i_target, sbe_base_address + PPE_XIRAMEDR, l_data64));

    FAPI_DBG("Restore GPR9");
    l_gpr9_save.extractToRight(l_data64, 0, 32);  // Put 32b save value into 64b buffer
    FAPI_TRY(fapi2::putScom(i_target, sbe_base_address + PPE_XIRAMDBG, l_data64));
    l_data64.flush<0>().insertFromRight(getMfsprInstructionDone(R9, SPRG0), 0, 32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_data64 );
    FAPI_TRY(pollHaltStateDone(i_target, sbe_base_address));
    FAPI_TRY(fapi2::putScom(i_target, sbe_base_address + PPE_XIRAMEDR, l_data64));

    FAPI_DBG("Restore SPRG0");
    FAPI_TRY(pollHaltStateDone(i_target, sbe_base_address));
    FAPI_TRY(putScom(i_target, sbe_base_address + PPE_XIRAMDBG , l_sprg0_save), "Error in GETSCOM");
fapi_try_exit:
    return fapi2::current_err;

}

//-----------------------------------------------------------------------------

/**
 * @brief Perform RAM "read" operation
 * @param[in]   i_target        Chip Target
 * @param[in]   i_sbe_local_address  last 16 bit Local register address of the PPE
 * @param[out]  o_data          Returned 64 bit data
 * @return  fapi2::ReturnCode
 */

fapi2::ReturnCode LocalRegRead(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint16_t i_sbe_local_address,
    fapi2::buffer<uint64_t>& o_data)

{

    fapi2::buffer<uint64_t> l_raminstr;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data32;



    FAPI_DBG("LocalRegRead: starting\n");




    //***********************************************************
    // addis R9, 0, 0xC000     R9 = 0xC0000000
    // lvd   D0, $local_reg_addr(r9)     0xC0000120 = R1
    // mtspr R0, SPRG0
    // getscom SPRG0
    // mtspr R1, SPRGO
    // getscom SPRG0
    //***********************************************************

    // Write Register offset to R9
    l_data64.flush<0>().insertFromRight(getInstructionDone(ADDIS_CONST, R9, R0, 0xC000), 0, 32);
    FAPI_TRY(fapi2::putScom(i_target, sbe_base_address + PPE_XIRAMEDR, l_data64));


    // Load data from register offset i_sbe_local_address
    l_data64.flush<0>().insertFromRight(getInstructionDone(LVD_CONST, D0, R9, i_sbe_local_address), 0, 32);
    FAPI_TRY(fapi2::putScom(i_target, sbe_base_address + PPE_XIRAMEDR, l_data64));

    //Move out the first 32 bits of read data from R0
    l_raminstr.flush<0>().insertFromRight(getMtsprInstructionDone(R0, SPRG0), 0, 32);
    FAPI_TRY(fapi2::putScom(i_target, sbe_base_address + PPE_XIRAMEDR, l_raminstr));
    FAPI_TRY(getScom(i_target, sbe_base_address + PPE_XIRAMDBG, l_data64 ), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 32, 32);
    o_data.insertFromRight(l_data32, 0, 32);

    //Move out the last 32 bits of read data from R1
    l_raminstr.flush<0>().insertFromRight(getMtsprInstructionDone(R1, SPRG0), 0, 32);
    FAPI_TRY(fapi2::putScom(i_target, sbe_base_address + PPE_XIRAMEDR, l_raminstr));
    FAPI_TRY(getScom(i_target, sbe_base_address + PPE_XIRAMDBG, l_data64 ), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 32, 32);
    o_data.insertFromRight(l_data32, 32, 32);


    FAPI_DBG("LocalRegRead: ending\n");



fapi_try_exit:
    return fapi2::current_err;
}












//#endif
