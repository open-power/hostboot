/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_ppe_utils.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file  p10_ppe_utils.C
/// @brief  PPE commonly used functions
///
/// *HWP HW Owner        : Greg Still <stillgs.@us.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Prasad BG Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 3
/// *HWP Consumed by     : Hostboot, FSP
///
/// @verbatim
///
/// @endverbatim

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_ppe_utils.H>
#include <p10_hcd_common.H>
#include <p10_scom_eq.H>
#include <p10_scom_proc.H>
#include <p10_ppe_instance_defs.H>
#include <map>

const char* ppe_get_name(enum PPE_TYPES ppe_type, uint32_t ppe_instance_num)
{
    //char outstr[16];
    //sprintf(outstr, "%s%u", G_PPE_Types[ppe_type].name.c_str(), ppe_instance_num);
    //std::string retval(outstr);

    return G_PPE_Types[ppe_type].name;
}

uint64_t ppe_get_base_address(enum PPE_TYPES ppe_type, uint32_t ppe_instance_num )
{
    return G_PPE_Types[ppe_type].base_address + ppe_instance_num * G_PPE_Types[ppe_type].inst_offset;
}

const char* ppe_get_reg_name(enum PPE_REGS reg)
{
    return v_ppe_reg_names[reg];
}

uint32_t ppe_get_reg_number(enum PPE_REGS reg)
{
    uint32_t num = v_ppe_reg_number[reg];
    return num;
}

const char* ppe_get_other_reg_name(enum PPE_TYPES ppe_type, uint16_t idx)
{
    return G_PPE_Types[ppe_type].other_names[idx];
}

uint32_t ppe_get_xir_vdr_flag(enum PPE_TYPES ppe_type)
{
    return G_PPE_Types[ppe_type].xir_vdr_flag;
}

uint64_t ppe_get_xir_address(enum PPE_TYPES ppe_type, enum PPE_XIRS_IDX xir_idx, uint32_t ppe_instance_num )
{
    return G_PPE_Types[ppe_type].base_address + ppe_instance_num * G_PPE_Types[ppe_type].inst_offset +
           G_PPE_Types[ppe_type].xir_offsets[xir_idx];
}

uint64_t ppe_get_vdr_address(enum PPE_TYPES ppe_type, enum PPE_VDRS_IDX vdr_idx, uint32_t ppe_instance_num )
{
    return G_PPE_Types[ppe_type].base_address +  ppe_instance_num * G_PPE_Types[ppe_type].inst_offset +
           G_PPE_Types[ppe_type].vdr_offsets[vdr_idx];
}

uint64_t ppe_get_mib_address(enum PPE_TYPES ppe_type, enum PPE_MIB_IDX mib_idx, uint32_t ppe_instance_num )
{
    return G_PPE_Types[ppe_type].base_address +  ppe_instance_num * G_PPE_Types[ppe_type].inst_offset +
           G_PPE_Types[ppe_type].mib_offsets[mib_idx];
}

uint64_t ppe_get_other_address(enum PPE_TYPES ppe_type, uint16_t idx, uint32_t ppe_instance_num )
{
    return G_PPE_Types[ppe_type].base_address +  ppe_instance_num * G_PPE_Types[ppe_type].inst_offset +
           G_PPE_Types[ppe_type].other_offsets[idx];
}

std::map<uint16_t, uint64_t> ppe_get_mib_offsets(enum PPE_TYPES ppe_type)
{
    return G_PPE_Types[ppe_type].mib_offsets;
}

std::map<uint16_t, uint64_t> ppe_get_other_offsets(enum PPE_TYPES ppe_type)
{
    return G_PPE_Types[ppe_type].other_offsets;
}

//-----------------------------------------------------------------------------

/**
 * @brief generates a PPE instruction for some formats
 * @param[in] i_Op      Opcode
 * @param[in] i_Rts     Source or Target Register
 * @param[in] i_RA      Address Register
 * @param[in] i_d       Instruction Data Field
 * @return returns 32 bit instruction representing the PPE instruction.
 */
uint32_t ppe_get_inst( const uint16_t i_Op, const uint16_t i_Rts, const uint16_t i_Ra, const uint16_t i_d)
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
uint32_t ppe_get_inst_mtspr( const uint16_t i_Rs, const uint16_t i_Spr )
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
uint32_t ppe_get_inst_mfspr( const uint16_t i_Rt, const uint16_t i_Spr )
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
uint32_t ppe_get_inst_mfmsr( const uint16_t i_Rt )
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
uint32_t ppe_get_inst_mfcr( const uint16_t i_Rt )
{
    uint32_t mfcrdInstOpcode = 0;
    mfcrdInstOpcode = 0;
    mfcrdInstOpcode = OPCODE_31 << 26;
    mfcrdInstOpcode |= i_Rt << 21 | ( MFCR_CONST1 << 1 );

    return mfcrdInstOpcode;
}



//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num)

{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;

    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY ( getScom(i_target, t_addr, l_data64), "Error reading PPE Halt State" );

    // Halt the PPE only if it is not already halted
    if (! l_data64.getBit<PPE_XSR_HALTED_STATE>())
    {
        FAPI_INF("   Send HALT command via XCR...");
        l_data64.flush<0>().insertFromRight(PPE_XCR_HALT, PPE_XCR_CMD_START,
                                            PPE_XCR_CMD_LEN);

        t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);
        FAPI_TRY ( putScom ( i_target,
                             t_addr,
                             l_data64 ),
                   "Error in PUTSCOM in XCR to generate Halt condition" );
        FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    }

fapi_try_exit:
    return fapi2::current_err;
}
//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_force_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num)

{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;

    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY ( getScom ( i_target,
                         t_addr,
                         l_data64 ),
               "Error reading PPE Halt State" );

    // Force Halt PPE only is it is not already Halted
    if (! l_data64.getBit<PPE_XSR_HALTED_STATE>())
    {
        FAPI_INF("   Send FORCE HALT command via XCR...");
        l_data64.flush<0>().insertFromRight(PPE_XCR_FORCE_HALT, PPE_XCR_CMD_START,
                                            PPE_XCR_CMD_START);

        t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);
        FAPI_TRY(putScom(i_target, t_addr, l_data64),
                 "Error in PUTSCOM in XCR to generate Force Halt condition");

        FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    }

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------
fapi2::ReturnCode ppe_poll_halt_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num)

{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;

    // Halt state entry should be very fast on PPEs (eg nanoseconds)
    // Try only using the SCOM access time to delay.
    static const uint32_t HALT_TRIES = 10;

    uint32_t l_timeout_count = HALT_TRIES;

    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);

    do
    {
        FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
    }
    while (! l_data64.getBit<PPE_XSR_HALTED_STATE>() &&
           --l_timeout_count != 0);


    FAPI_ASSERT ( l_data64.getBit<PPE_XSR_HALTED_STATE>(),
                  fapi2::PPE_STATE_HALT_TIMEOUT_ERR()
                  .set_TARGET(i_target)
                  .set_ADDRESS(t_addr),
                  "PPE Halt Timeout" );

fapi_try_exit:
    return fapi2::current_err;
}
//-----------------------------------------------------------------------------
fapi2::ReturnCode ppe_is_halted(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    bool& o_halted)
{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;

    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(getScom ( i_target,
                       t_addr,
                       l_data64 ),
             "Failed reading XIRAMDBG register!" );

    o_halted = l_data64.getBit<PPE_XSR_HALTED_STATE>();

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------
fapi2::ReturnCode ppe_resume(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num)

{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;

    FAPI_INF("   Resume only through XCR...");
    l_data64.flush<0>().insertFromRight(PPE_XCR_RESUME, PPE_XCR_CMD_START, PPE_XCR_CMD_LEN);
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);
    FAPI_TRY(putScom(i_target, t_addr, l_data64), "Error in PUTSCOM in XCR only resume");


fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------
fapi2::ReturnCode ppe_resume_w_poll(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num)
{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;

    static const uint32_t RESUME_TRIES = 10;
    uint32_t l_timeout_count = RESUME_TRIES;

    FAPI_INF("   Clear debug status via XCR...");
    l_data64.flush<0>();
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);
    FAPI_TRY(putScom(i_target, t_addr, l_data64), "Error in PUTSCOM in XCR to clear dbg status");

    FAPI_INF("   Send RESUME command via XCR...");
    l_data64.flush<0>().insertFromRight(PPE_XCR_RESUME, PPE_XCR_CMD_START, PPE_XCR_CMD_LEN);

    FAPI_TRY(putScom(i_target, t_addr, l_data64), "Error in PUTSCOM in XCR to resume condition");

    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);

    do
    {
        FAPI_TRY(getScom(i_target, t_addr, l_data64));
        FAPI_DBG("   Poll content:  XSR: 0x%16llX", l_data64);
    }
    while((l_data64.getBit<PPE_XSR_HALTED_STATE>() != 0) && (--l_timeout_count != 0));

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------
fapi2::ReturnCode ppe_update_dbcr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    const uint64_t i_inst_op,
    const uint16_t i_immed_16,
    const uint16_t i_Rs)
{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    //Modify DBCR using read modify write
    //Move DBCR to Rs
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mfspr(i_Rs, ppe_get_reg_number(PPE_DBCR)), 0, 32);
    FAPI_DBG("getMfsprInstruction(%d, DBCR): 0x%16llX", i_Rs, l_data64 );
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));
    //Modify Rs
    l_data64.flush<0>().insertFromRight(ppe_get_inst(i_inst_op, i_Rs, i_Rs, i_immed_16), 0, 32);
    FAPI_DBG("getInstruction(Immed %X: 0x%16llX", i_immed_16, l_data64 );
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));
    //MOVE new Rs into DBCR
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mtspr(i_Rs, ppe_get_reg_number(PPE_DBCR)), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, DBCR): 0x%16llX", i_Rs, l_data64 );
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_update_dacr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    const uint64_t i_address,
    const uint16_t i_Rs)
{
    fapi2::buffer<uint32_t> temp_inst32;
    fapi2::buffer<uint64_t> temp_data64;
    uint64_t t_addr;

    temp_data64.flush<0>().insertFromRight(ppe_get_inst_mfspr(i_Rs, ppe_get_reg_number(PPE_SPRG0)), 0, 32);
    FAPI_DBG("getMfsprInstruction(%d, SPRG0): 0x%16llX", i_Rs, temp_data64 );
    temp_data64.insertFromRight(i_address, 32, 32);
    FAPI_DBG("Final Instr + SPRG0: 0x%16llX", temp_data64 );
    //write sprg0 with address and ram mfsprg0 to i_Rs
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMGA, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, temp_data64 ));

    //then mtdacr from i_Rs
    temp_data64.flush<0>().insertFromRight(ppe_get_inst_mtspr(i_Rs, ppe_get_reg_number(PPE_DACR)), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, DBCR): 0x%16llX", i_Rs, temp_data64  );
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, temp_data64));
fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_ram_read(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    const fapi2::buffer<uint64_t> i_instruction,
    fapi2::buffer<uint32_t>& o_data)
{
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_xsr;
    uint64_t t_addr;

    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));

    //Save XSR
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIDBGPRO, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_xsr), "Error in GETSCOM");

    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, i_instruction));
    FAPI_DBG("    RAMREAD i_instruction: 0X%16llX", i_instruction);
    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(fapi2::getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(o_data, 32, 32);
    FAPI_DBG("    RAMREAD o_data: 0X%16llX", o_data);

    //Restore XSR
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIDBGPRO, i_ppe_instance_num);
    FAPI_TRY(putScom(i_target, t_addr, l_xsr), "Error in PUTSCOM");

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_ram(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    const uint64_t i_instruction
)
{
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_xsr;
    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    uint64_t t_addr;

    //Save XSR
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIDBGPRO, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_xsr), "Error in GETSCOM");

    l_data64.flush<0>().insertFromRight(i_instruction, 0, 32);
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));
    FAPI_DBG("    RAMREAD i_instruction: 0X%16llX", i_instruction);
    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));

    //Restore XSR
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIDBGPRO, i_ppe_instance_num);
    FAPI_TRY(putScom(i_target, t_addr, l_xsr), "Error in PUTSCOM");

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_single_step_w_dbcr_clr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    const uint16_t i_Rs,
    uint64_t i_step_count)
{
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_dbcr_save;
    fapi2::buffer<uint32_t> l_gpr31_save;
    fapi2::buffer<uint64_t> l_sprg0_save;
    uint64_t t_addr;

    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    // Save SPRG0 i_Rs before getting dbcr
    FAPI_DBG("Save SPRG0");
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_sprg0_save, 32, 32);
    FAPI_DBG("Saved SPRG0 value : 0x%08llX", l_sprg0_save );
    FAPI_DBG("Save i_Rs");
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mtspr(i_Rs, ppe_get_reg_number(PPE_SPRG0)), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, SPRG0): 0x%16llX", ppe_get_reg_number(PPE_R31), l_data64 );
    FAPI_TRY(ppe_ram_read(i_target, i_ppe_type, i_ppe_instance_num, l_data64, l_gpr31_save));
    FAPI_DBG("Saved GPR31 value : 0x%08llX", l_gpr31_save );

    FAPI_INF("   Read and Save DBCR");
    FAPI_DBG("Move DBCR to i_Rs");
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mfspr(i_Rs, ppe_get_reg_number(PPE_DBCR)), 0, 32);
    FAPI_DBG("getMfsprInstruction(%d, DBCR): 0x%16llX", i_Rs, l_data64 );
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));

    FAPI_DBG("Move i_Rs to SPRG0 : so now SPRG0 has DBCR value");
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mtspr(i_Rs, ppe_get_reg_number(PPE_SPRG0)), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, SPRG0): 0x%16llX", i_Rs, l_data64 );
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));

    FAPI_DBG("Save SPRG0 i.e. DBCR");
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_dbcr_save, 32, 32);
    FAPI_DBG("Saved DBCR value : 0x%08llX", l_dbcr_save );

    FAPI_DBG("clear DBCR[8] IACE and DBCR[12:13] DACE");
    FAPI_TRY(ppe_update_dbcr(i_target, i_ppe_type, i_ppe_instance_num, ANDIS_CONST, 0x0F73, ppe_get_reg_number(PPE_R31)));

    //Restore i_Rs and SPRG0 before single step
    FAPI_DBG("Restore i_Rs");
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mfspr(i_Rs, ppe_get_reg_number(PPE_SPRG0)), 0, 32);
    FAPI_DBG("getMfsprInstruction(R31, SPRG0): 0x%16llX",  l_data64 );
    l_data64.insertFromRight(l_gpr31_save, 32, 32);
    FAPI_DBG("Final Instr + SPRG0: 0x%16llX", l_data64 );
    //write sprg0 with address and ram mfsprg0 to i_Rs
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMGA, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64 ));
    FAPI_DBG("Restore SPRG0");
    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(putScom(i_target, t_addr, l_sprg0_save), "Error in PUTSCOM");

    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);

    while(i_step_count != 0)
    {
        FAPI_DBG("   Send Single step command via XCR...step count = 0x%16llx", i_step_count);
        l_data64.flush<0>().insertFromRight(PPE_XCR_SINGLE_STEP, PPE_XCR_CMD_START, PPE_XCR_CMD_LEN);
        FAPI_TRY(putScom(i_target, t_addr, l_data64),
                 "Error in PUTSCOM in XCR to generate Single Step condition");
        --i_step_count;  //Decrement step count
        FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    }

    // Save SPRG0 i_Rs before getting dbcr
    FAPI_DBG("Save SPRG0");
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_sprg0_save, 32, 32);
    FAPI_DBG("Saved SPRG0 value : 0x%08llX", l_sprg0_save );
    FAPI_DBG("Save i_Rs");
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mtspr(i_Rs, ppe_get_reg_number(PPE_SPRG0)), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, SPRG0): 0x%16llX", ppe_get_reg_number(PPE_R31), l_data64 );
    FAPI_TRY(ppe_ram_read(i_target, i_ppe_type, i_ppe_instance_num, l_data64, l_gpr31_save));
    FAPI_DBG("Saved GPR31 value : 0x%08llX", l_gpr31_save );

    FAPI_INF("   Restore DBCR");
    FAPI_INF("   Write orig. DBCR into SPRG0");

    l_data64.flush<0>().insertFromRight(ppe_get_inst_mfspr(i_Rs, ppe_get_reg_number(PPE_SPRG0)), 0, 32);
    FAPI_DBG("getMfsprInstruction(%d, SPRG0): 0x%16llX", i_Rs, l_data64 );
    l_data64.insertFromRight(l_dbcr_save, 32, 32);
    FAPI_DBG("Final Instr + SPRG0: 0x%16llX", l_data64 );
    //write sprg0 with address and ram mfsprg0 to i_Rs
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMGA, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64 ));

    //then mtDBCR from i_Rs
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mtspr(i_Rs, ppe_get_reg_number(PPE_DBCR)), 0, 32);
    FAPI_DBG("getMtsprInstruction(%d, DBCR): 0x%16llX", i_Rs, l_data64  );
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));

    //Restore i_Rs and SPRG0 after dbcr updates
    FAPI_DBG("Restore i_Rs");
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mfspr(i_Rs, ppe_get_reg_number(PPE_SPRG0)), 0, 32);
    FAPI_DBG("getMfsprInstruction(R31, SPRG0): 0x%16llX",  l_data64 );
    l_data64.insertFromRight(l_gpr31_save, 32, 32);
    FAPI_DBG("Final Instr + SPRG0: 0x%16llX", l_data64 );
    //write sprg0 with address and ram mfsprg0 to i_Rs
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMGA, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64 ));
    FAPI_DBG("Restore SPRG0");
    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(putScom(i_target, t_addr, l_sprg0_save), "Error in GETSCOM");


fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode ppe_single_step(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    uint64_t i_step_count)
{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;

    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));

    while(i_step_count != 0)
    {
        FAPI_DBG("   Send Single step command via XCR...step count = 0x%16llx", i_step_count);
        l_data64.flush<0>().insertFromRight(PPE_XCR_SINGLE_STEP, PPE_XCR_CMD_START, PPE_XCR_CMD_LEN);
        t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);
        FAPI_TRY(putScom(i_target, t_addr, l_data64),
                 "Error in PUTSCOM in XCR to generate Single Step condition");
        --i_step_count;  //Decrement step count
        FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    }

fapi_try_exit:
    return fapi2::current_err;
}


//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_clear_dbg(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num)

{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;

    FAPI_INF("   Clear debug status via XCR...");
    l_data64.flush<0>();
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);
    FAPI_TRY(putScom(i_target, t_addr, l_data64), "Error in PUTSCOM in XCR to clear dbg status");

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_toggle_trh(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num)

{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;

    FAPI_INF("   Toggle TRH via XCR...");
    l_data64.flush<0>().insertFromRight(4, 1, 3);
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);
    FAPI_TRY(putScom(i_target, t_addr, l_data64), "Error in PUTSCOM in XCR to toggle TRH");

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_soft_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num)
{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;

    FAPI_INF("   Soft reset via XCR...");
    l_data64.flush<0>().insertFromRight(5, 1, 3);
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);
    FAPI_TRY(putScom(i_target, t_addr, l_data64), "Error in PUTSCOM in XCR to do soft reset");


fapi_try_exit:
    return fapi2::current_err;
}
//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_hard_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num)
{
    fapi2::buffer<uint64_t> l_data64;
    uint64_t t_addr;

    FAPI_INF("   Hard reset via XCR...");
    l_data64.flush<0>().insertFromRight(6, 1, 3);
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);
    FAPI_TRY(putScom(i_target, t_addr, l_data64), "Error in PUTSCOM in XCR to do hard reset");

fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_write_iar(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    const uint64_t i_address
)
{

    fapi2::buffer<uint64_t> temp_data64;
    uint64_t t_addr;
    temp_data64.flush<0>().insertFromRight(i_address, 32, 32);
    FAPI_DBG("IAR: 0x%16llX",  temp_data64  );
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIDBGPRO, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, temp_data64));
fapi_try_exit:
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------
#ifndef  __HOSTBOOT_MODULE
//-----------------------------------------------------------------------------

fapi2::ReturnCode ppe_save_gprs_sprs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    fapi2::buffer<uint32_t>& l_gpr0_save,
    fapi2::buffer<uint32_t>& l_gpr1_save,
    fapi2::buffer<uint32_t>& l_gpr9_save,
    fapi2::buffer<uint64_t>& l_sprg0_save)

{
    fapi2::buffer<uint64_t> l_raminstr;
    //    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data32;
    uint64_t t_addr;


    //***********************************************************
    // Backup R0 , R1 , R9 , SPRG0
    //***********************************************************


    // Save SPRG0
    FAPI_DBG("Save SPRG0");
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_sprg0_save), "Error in GETSCOM");
    l_sprg0_save.extractToRight(l_data32, 32, 32);

    FAPI_DBG("Save GPR0");
    l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(ppe_get_reg_number(PPE_R0), ppe_get_reg_number(PPE_SPRG0)), 0,
                                          32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_raminstr );

    FAPI_TRY(ppe_ram_read(i_target, i_ppe_type, i_ppe_instance_num, l_raminstr, l_gpr0_save));
    FAPI_DBG("Saved GPR0 value : 0x%08llX", l_gpr0_save );

    FAPI_DBG("Save GPR1");
    l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(ppe_get_reg_number(PPE_R1), ppe_get_reg_number(PPE_SPRG0)), 0,
                                          32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_raminstr );

    FAPI_TRY(ppe_ram_read(i_target, i_ppe_type, i_ppe_instance_num, l_raminstr, l_gpr1_save));
    FAPI_DBG("Saved GPR1 value : 0x%08llX", l_gpr1_save );

    FAPI_DBG("Save GPR9");
    l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(ppe_get_reg_number(PPE_R0), ppe_get_reg_number(PPE_SPRG0)), 0,
                                          32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_raminstr );

    FAPI_TRY(ppe_ram_read(i_target, i_ppe_type, i_ppe_instance_num, l_raminstr, l_gpr9_save));
    FAPI_DBG("Saved GPR9 value : 0x%08llX", l_gpr9_save );

fapi_try_exit:
    return fapi2::current_err;

}


fapi2::ReturnCode ppe_restore_gprs_sprs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    fapi2::buffer<uint32_t> l_gpr0_save,
    fapi2::buffer<uint32_t> l_gpr1_save,
    fapi2::buffer<uint32_t> l_gpr9_save,
    fapi2::buffer<uint64_t> l_sprg0_save)

{
    fapi2::buffer<uint64_t> l_raminstr;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data32;
    uint64_t t_addr;


    //***********************************************************
    // Restore R0 , R1 , R9 , SPRG0
    //***********************************************************


    FAPI_DBG("Restore GPR0");
    l_gpr0_save.extractToRight(l_data64, 0, 32);  // Put 32b save value into 64b buffer
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mfspr(ppe_get_reg_number(PPE_R0), ppe_get_reg_number(PPE_SPRG0)), 0,
                                        32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_data64 );
    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));

    FAPI_DBG("Restore GPR1");
    l_gpr1_save.extractToRight(l_data64, 0, 32);  // Put 32b save value into 64b buffer
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mfspr(ppe_get_reg_number(PPE_R1), ppe_get_reg_number(PPE_SPRG0)), 0,
                                        32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_data64 );
    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));

    FAPI_DBG("Restore GPR9");
    l_gpr9_save.extractToRight(l_data64, 0, 32);  // Put 32b save value into 64b buffer
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));
    l_data64.flush<0>().insertFromRight(ppe_get_inst_mfspr(ppe_get_reg_number(PPE_R9), ppe_get_reg_number(PPE_SPRG0)), 0,
                                        32);
    FAPI_DBG("getMtsprInstructionDone(%d, SPRG0): 0x%16llX", 0, l_data64 );
    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));

    FAPI_DBG("Restore SPRG0");
    FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(putScom(i_target, t_addr, l_sprg0_save), "Error in GETSCOM");
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

fapi2::ReturnCode ppe_local_reg_read(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    const uint16_t i_local_address,
    fapi2::buffer<uint64_t>& o_data)

{

    fapi2::buffer<uint64_t> l_raminstr;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data32;
    uint64_t t_addr;

    FAPI_DBG("LocalRegRead: starting\n");
    //***********************************************************
    // addis R9, 0, 0xC000     R9 = 0xC0000000
    // lvd   D0, $local_reg_addr(r9)     0xC0000120 = R1
    // mtspr R0, SPRG0
    // getscom SPRG0
    // mtspr R1, SPRGO
    // getscom SPRG0
    //***********************************************************

    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);

    // Write Register offset to R9
    l_data64.flush<0>().insertFromRight(ppe_get_inst(ADDIS_CONST, ppe_get_reg_number(PPE_R9), ppe_get_reg_number(PPE_R0),
                                        0xC000), 0, 32);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));

    // Load data from register offset i_local_address
    l_data64.flush<0>().insertFromRight(ppe_get_inst(LVD_CONST, ppe_get_reg_number(PPE_D0), ppe_get_reg_number(PPE_R9),
                                        i_local_address), 0, 32);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));

    //Move out the first 32 bits of read data from R0
    l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(ppe_get_reg_number(PPE_R0), ppe_get_reg_number(PPE_SPRG0)), 0,
                                          32);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_raminstr));
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_data64 ), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 32, 32);
    o_data.insertFromRight(l_data32, 0, 32);

    //Move out the last 32 bits of read data from R1
    l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(ppe_get_reg_number(PPE_R1), ppe_get_reg_number(PPE_SPRG0)), 0,
                                          32);
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    FAPI_TRY(fapi2::putScom(i_target, t_addr, l_raminstr));
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_data64 ), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 32, 32);
    o_data.insertFromRight(l_data32, 32, 32);

    FAPI_DBG("LocalRegRead: ending\n");

fapi_try_exit:
    return fapi2::current_err;
}
#endif
