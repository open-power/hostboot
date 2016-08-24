/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_ppe_utils.C $       */
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
/// @file  p9_ppe_utils.C
/// @brief  PPE commonly used functions
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
/// @endverbatim

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_ppe_utils.H>
#include <p9_hcd_common.H>
#include <map>





//// Vector defining the special acceess egisters
//const std::map<uint16_t, std::string> v_ppe_special_num_name =
//{
//    { MSR,   "MSR"    },
//    { CR,    "CR"     }
//};
//// Vector defining the major SPRs
//// Note: SPRG0 is not include as it is saved and restored as the means for
//// accessing the other SPRS
//const std::map<uint16_t, std::string> v_ppe_major_num_name =
//{
//    { CTR,   "CTR"    },
//    { LR,    "LR"     },
//    { ISR,   "ISR"    },
//    { SRR0,  "SRR0"   },
//    { SRR1,  "SRR1"   },
//    { TCR,   "TCR"    },
//    { TSR,   "TSR"    }
//};
//// Vector defining the minor SPRs
//const std::map<uint16_t, std::string> v_ppe_minor_num_name =
//{
//    { DACR,  "DACR"   },
//    { DBCR,  "DBCR"   },
//    { DEC,   "DEC"    },
//    { IVPR,  "IVPR"   },
//    { PIR,   "PIR"    },
//    { PVR,   "PVR"    },
//    { XER,   "XER"    }
//};



//-----------------------------------------------------------------------------

/**
 * @brief generates a PPE instruction for some formats
 * @param[in] i_Op      Opcode
 * @param[in] i_Rts     Source or Target Register
 * @param[in] i_RA      Address Register
 * @param[in] i_d       Instruction Data Field
 * @return returns 32 bit instruction representing the PPE instruction.
 */

uint32_t ppe_getInstruction( const uint16_t i_Op, const uint16_t i_Rts, const uint16_t i_Ra, const uint16_t i_d)
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
uint32_t ppe_getMtsprInstruction( const uint16_t i_Rs, const uint16_t i_Spr )
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
uint32_t ppe_getMfsprInstruction( const uint16_t i_Rt, const uint16_t i_Spr )
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
uint32_t ppe_getMfmsrInstruction( const uint16_t i_Rt )
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
uint32_t ppe_getMfcrInstruction( const uint16_t i_Rt )
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
fapi2::ReturnCode ppe_pollHaltState(
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
fapi2::ReturnCode ppe_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("   Send HALT command via XCR...");
    l_data64.flush<0>().insertFromRight(p9hcd::HALT, 1, 3);

    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64), "Error in PUTSCOM in XCR to generate Halt condition");

    FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));

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
fapi2::ReturnCode ppe_force_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("   Send FORCE HALT command via XCR...");
    l_data64.flush<0>().insertFromRight(p9hcd::FORCE_HALT, 1, 3);

    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64),
             "Error in PUTSCOM in XCR to generate Force Halt condition");

    FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));

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
fapi2::ReturnCode ppe_resume(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    static const uint32_t RESUME_TRIES = 10;
    uint32_t l_timeout_count = RESUME_TRIES;
    //Before reume always clear debug status (Michael's comment)
    FAPI_INF("   Clear debug status via XCR...");
    l_data64.flush<0>();
    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64), "Error in PUTSCOM in XCR to clear dbg status");

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
 * @brief update dbcr
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs mtdbcr
 */
fapi2::ReturnCode ppe_update_dbcr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const uint64_t l_inst_op,
    const uint16_t l_immed_16,
    const uint16_t i_Rs)
{
    fapi2::buffer<uint64_t> l_data64;
    //Modify DBCR using read modify write
    //Move DBCR to Rs
    l_data64.flush<0>().insertFromRight(ppe_getMfsprInstruction(i_Rs, DBCR), 0, 32);
    FAPI_DBG("getMfsprInstruction(%d, DBCR): 0x%16llX", i_Rs, l_data64 );
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64));
    //Modify Rs
    l_data64.flush<0>().insertFromRight(ppe_getInstruction(l_inst_op, i_Rs, i_Rs, l_immed_16), 0, 32);
    FAPI_DBG("getInstruction(Immed %X: 0x%16llX", l_immed_16, l_data64 );
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64));
    //MOVE new Rs into DBCR
    l_data64.flush<0>().insertFromRight(ppe_getMtsprInstruction(i_Rs, DBCR), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, DBCR): 0x%16llX", i_Rs, l_data64 );
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64));

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief update dacr
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs mtdacr
 */
fapi2::ReturnCode ppe_update_dacr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const uint64_t l_address,
    const uint16_t i_Rs)
{
    fapi2::buffer<uint32_t> temp_inst32;
    fapi2::buffer<uint64_t> temp_data64;

    temp_data64.flush<0>().insertFromRight(ppe_getMfsprInstruction(i_Rs, SPRG0), 0, 32);
    FAPI_DBG("getMfsprInstruction(%d, SPRG0): 0x%16llX", i_Rs, temp_data64 );
    temp_data64.insertFromRight(l_address, 32, 32);
    FAPI_DBG("Final Instr + SPRG0: 0x%16llX", temp_data64 );
    //write sprg0 with address and ram mfsprg0 to i_Rs
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMGA, temp_data64 ));

    //then mtdacr from i_Rs
    temp_data64.flush<0>().insertFromRight(ppe_getMtsprInstruction(i_Rs, DACR), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, DBCR): 0x%16llX", i_Rs, temp_data64  );
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, temp_data64));
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
fapi2::ReturnCode ppe_RAMRead(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const fapi2::buffer<uint64_t> i_instruction,
    fapi2::buffer<uint32_t>& o_data)
{
    fapi2::buffer<uint64_t> l_data64;
    FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, i_instruction));
    FAPI_DBG("    RAMREAD i_instruction: 0X%16llX", i_instruction);
    FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
    FAPI_TRY(fapi2::getScom(i_target, i_base_address + PPE_XIRAMDBG, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(o_data, 32, 32);
    FAPI_DBG("    RAMREAD o_data: 0X%16llX", o_data);

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
fapi2::ReturnCode ppe_RAM(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const uint64_t i_instruction
)
{
    fapi2::buffer<uint64_t> l_data64;
    FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));


    l_data64.flush<0>().insertFromRight(i_instruction, 0, 32);
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64));
    FAPI_DBG("    RAMREAD i_instruction: 0X%16llX", i_instruction);
    FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));

fapi_try_exit:
    return fapi2::current_err;
}
//-----------------------------------------------------------------------------

/**
 * @brief single step the engine
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs XCR with single step  tosingle step the engine.
 */
fapi2::ReturnCode ppe_single_step(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const uint16_t i_Rs,
    uint64_t i_step_count)
{
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_dbcr_save;
    fapi2::buffer<uint32_t> l_gpr31_save;
    fapi2::buffer<uint64_t> l_sprg0_save;

    FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
    // Save SPRG0 i_Rs before getting dbcr
    FAPI_DBG("Save SPRG0");
    FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMDBG, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_sprg0_save, 32, 32);
    FAPI_DBG("Saved SPRG0 value : 0x%08llX", l_sprg0_save );
    FAPI_DBG("Save i_Rs");
    l_data64.flush<0>().insertFromRight(ppe_getMtsprInstruction(i_Rs, SPRG0), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, SPRG0): 0x%16llX", R31, l_data64 );
    FAPI_TRY(ppe_RAMRead(i_target, i_base_address, l_data64, l_gpr31_save));
    FAPI_DBG("Saved GPR31 value : 0x%08llX", l_gpr31_save );

    FAPI_INF("   Read and Save DBCR");
    FAPI_DBG("Move DBCR to i_Rs");
    l_data64.flush<0>().insertFromRight(ppe_getMfsprInstruction(i_Rs, DBCR), 0, 32);
    FAPI_DBG("getMfsprInstruction(%d, DBCR): 0x%16llX", i_Rs, l_data64 );
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64));

    FAPI_DBG("Move i_Rs to SPRG0 : so now SPRG0 has DBCR value");
    l_data64.flush<0>().insertFromRight(ppe_getMtsprInstruction(i_Rs, SPRG0), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, SPRG0): 0x%16llX", i_Rs, l_data64 );
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64));

    FAPI_DBG("Save SPRG0 i.e. DBCR");
    FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMDBG, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_dbcr_save, 32, 32);
    FAPI_DBG("Saved DBCR value : 0x%08llX", l_dbcr_save );

    FAPI_DBG("clear DBCR[8] IACE and DBCR[12:13] DACE");
    FAPI_TRY(ppe_update_dbcr(i_target, i_base_address, ANDIS_CONST, 0x0F73, R31));

    //Restore i_Rs and SPRG0 before single step
    FAPI_DBG("Restore i_Rs");
    l_data64.flush<0>().insertFromRight(ppe_getMfsprInstruction(i_Rs, SPRG0), 0, 32);
    FAPI_DBG("getMfsprInstruction(R31, SPRG0): 0x%16llX",  l_data64 );
    l_data64.insertFromRight(l_gpr31_save, 32, 32);
    FAPI_DBG("Final Instr + SPRG0: 0x%16llX", l_data64 );
    //write sprg0 with address and ram mfsprg0 to i_Rs
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMGA, l_data64 ));
    FAPI_DBG("Restore SPRG0");
    FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIRAMDBG , l_sprg0_save), "Error in PUTSCOM");

    while(i_step_count != 0)
    {
        FAPI_DBG("   Send Single step command via XCR...step count = 0x%16llx", i_step_count);
        l_data64.flush<0>().insertFromRight(p9hcd::SINGLE_STEP, 1, 3);
        FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64),
                 "Error in PUTSCOM in XCR to generate Single Step condition");
        --i_step_count;  //Decrement step count
        FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
    }

    // Save SPRG0 i_Rs before getting dbcr
    FAPI_DBG("Save SPRG0");
    FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMDBG, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_sprg0_save, 32, 32);
    FAPI_DBG("Saved SPRG0 value : 0x%08llX", l_sprg0_save );
    FAPI_DBG("Save i_Rs");
    l_data64.flush<0>().insertFromRight(ppe_getMtsprInstruction(i_Rs, SPRG0), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, SPRG0): 0x%16llX", R31, l_data64 );
    FAPI_TRY(ppe_RAMRead(i_target, i_base_address, l_data64, l_gpr31_save));
    FAPI_DBG("Saved GPR31 value : 0x%08llX", l_gpr31_save );

    FAPI_INF("   Restore DBCR");
    FAPI_INF("   Write orig. DBCR into SPRG0");

    l_data64.flush<0>().insertFromRight(ppe_getMfsprInstruction(i_Rs, SPRG0), 0, 32);
    FAPI_DBG("getMfsprInstruction(%d, SPRG0): 0x%16llX", i_Rs, l_data64 );
    l_data64.insertFromRight(l_dbcr_save, 32, 32);
    FAPI_DBG("Final Instr + SPRG0: 0x%16llX", l_data64 );
    //write sprg0 with address and ram mfsprg0 to i_Rs
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMGA, l_data64 ));

    //then mtDBCR from i_Rs
    l_data64.flush<0>().insertFromRight(ppe_getMtsprInstruction(i_Rs, DBCR), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, DBCR): 0x%16llX", i_Rs, l_data64  );
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64));

    //Restore i_Rs and SPRG0 after dbcr updates
    FAPI_DBG("Restore i_Rs");
    l_data64.flush<0>().insertFromRight(ppe_getMfsprInstruction(i_Rs, SPRG0), 0, 32);
    FAPI_DBG("getMfsprInstruction(R31, SPRG0): 0x%16llX",  l_data64 );
    l_data64.insertFromRight(l_gpr31_save, 32, 32);
    FAPI_DBG("Final Instr + SPRG0: 0x%16llX", l_data64 );
    //write sprg0 with address and ram mfsprg0 to i_Rs
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMGA, l_data64 ));
    FAPI_DBG("Restore SPRG0");
    FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIRAMDBG , l_sprg0_save), "Error in GETSCOM");


fapi_try_exit:
    return fapi2::current_err;
}
//-----------------------------------------------------------------------------

/**
 * @brief single step the engine
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note   output is l_ppe_regs.] which has reg name added along with value and number
 *         this will be used for printing in the wrapper
 */
fapi2::ReturnCode ppe_regs_populate_name(
    std::vector<PPERegValue_t> l_ppe_regs_value,
    const std::map<uint16_t, std::string> l_ppe_regs_num_name,
    std::vector<PPEReg_t>& l_ppe_regs)

{
    PPEReg_t l_reg;
    FAPI_INF("   populating reg names");

    if (!l_ppe_regs_value.empty())
    {
        for (auto it : l_ppe_regs_value)
        {
            auto search = l_ppe_regs_num_name.find(it.number);
            l_reg.name  = search->second;
            l_reg.reg = it;
            l_ppe_regs.push_back(l_reg);
        }
    }

    return fapi2::current_err;
}


//-----------------------------------------------------------------------------

/**
 * @brief clear the dbg status engine
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs XCR to clear dbg status.
 */
fapi2::ReturnCode ppe_clear_dbg(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("   Clear debug status via XCR...");
    l_data64.flush<0>();
    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64), "Error in PUTSCOM in XCR to clear dbg status");



fapi_try_exit:
    return fapi2::current_err;
}
//-----------------------------------------------------------------------------

/**
 * @brief toggle TRH
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs XCR to toggle trh.
 */
fapi2::ReturnCode ppe_toggle_trh(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("   Toggle TRH via XCR...");
    l_data64.flush<0>().insertFromRight(4, 1, 3);
    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64), "Error in PUTSCOM in XCR to toggle TRH");


fapi_try_exit:
    return fapi2::current_err;
}
//-----------------------------------------------------------------------------

/**
 * @brief xcr soft reset
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs XCR to give soft reset
 */
fapi2::ReturnCode ppe_soft_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("   Soft reset via XCR...");
    l_data64.flush<0>().insertFromRight(5, 1, 3);
    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64), "Error in PUTSCOM in XCR to do soft reset");


fapi_try_exit:
    return fapi2::current_err;
}
//-----------------------------------------------------------------------------

/**
 * @brief xcr hard reset
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs XCR to give hard reset
 */
fapi2::ReturnCode ppe_hard_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("   Hard reset via XCR...");
    l_data64.flush<0>().insertFromRight(6, 1, 3);
    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64), "Error in PUTSCOM in XCR to do hard reset");


fapi_try_exit:
    return fapi2::current_err;
}
//-----------------------------------------------------------------------------

/**
 * @brief xcr resume only
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs XCR to only resume
 */
fapi2::ReturnCode ppe_resume_only(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address)
{
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("   Resume only through XCR...");
    l_data64.flush<0>().insertFromRight(p9hcd::RESUME, 1, 3);
    FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64), "Error in PUTSCOM in XCR only resume");


fapi_try_exit:
    return fapi2::current_err;
}
//-----------------------------------------------------------------------------

/**
 * @brief only single step the engine
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note    programs XCR with single step no clearing DBCR
 */
fapi2::ReturnCode ppe_ss_only(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    uint64_t i_step_count)
{
    fapi2::buffer<uint64_t> l_data64;

    FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));


    while(i_step_count != 0)
    {
        FAPI_DBG("   Send Single step command via XCR...step count = 0x%16llx", i_step_count);
        l_data64.flush<0>().insertFromRight(p9hcd::SINGLE_STEP, 1, 3);
        FAPI_TRY(putScom(i_target, i_base_address + PPE_XIXCR, l_data64),
                 "Error in PUTSCOM in XCR to generate Single Step condition");
        --i_step_count;  //Decrement step count
        FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
    }


fapi_try_exit:
    return fapi2::current_err;
}
//PPE write  IAR
fapi2::ReturnCode ppe_write_iar(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_base_address,
    const uint64_t l_address
)
{

    fapi2::buffer<uint64_t> temp_data64;
    temp_data64.flush<0>().insertFromRight(l_address, 32, 32);
    FAPI_DBG("IAR: 0x%16llX",  temp_data64  );
    FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIDBGPRO, temp_data64));
fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------

/**
 * @brief single step the engine
 * @param[in]   i_target  target register number
 * @return  fapi2::ReturnCode
 * @note   output is l_scom_regs.] which has reg name added along with value and number
 *         this will be used for printing in the wrapper
 */
fapi2::ReturnCode scom_regs_populate_name(
    std::vector<SCOMRegValue_t> l_ppe_regs_value,
    const std::map<uint16_t, std::string> l_ppe_regs_num_name,
    std::vector<SCOMReg_t>& l_scom_regs)

{
    SCOMReg_t l_reg;
    FAPI_INF("   populating reg names");

    if (!l_ppe_regs_value.empty())
    {
        for (auto it : l_ppe_regs_value)
        {
            auto search = l_ppe_regs_num_name.find(it.number);
            l_reg.name  = search->second;
            l_reg.reg = it;
            l_scom_regs.push_back(l_reg);
        }
    }


    return fapi2::current_err;
}
