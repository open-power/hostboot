/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_sbe_rc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_extract_sbe_rc.C,v 1.17 2014/03/24 20:34:44 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_extract_sbe_rc.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_extract_sbe_rc.C
// *! DESCRIPTION : Create a return code for an SBE/SLW error
// *!
// *! OWNER NAME  : Johannes Koesters       Email: koesters@de.ibm.com
// *!
// *! Overview:
// *!   - Analyze error state of SBE/SLW engine
// *!     - Examine SBE/SLW engine state to determine if a HW error occurred.
// *!       Return RC for HW error if present
// *!     - For 'halt' due to SBE/SLW code generated failure:
// *!         - Determine PC at point for failure
// *!         - Lookup PC in appropriate code space (SEEPROM/PIBMEM/OTPROM),
// *!           extract & return RC for its associated error
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_extract_sbe_rc.H>
#include <proc_reset_i2cm_bus_fence.H>
#include <p8_scom_addresses.H>


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

enum soft_error_t
{
    eNO_ERROR = 0,
    eSOFT_ERR_I2CM=1, 
    eSOFT_ERR_PNOR=2,
    eSOFT_ERR_BOTH=3
};

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// address space/alignment masks
const uint64_t SBE_ADDR_MASK               = 0x0000FFFFFFFFFFFFULL;
const uint64_t FOURBYTE_ALIGNMENT_MASK     = 0x0000000000000003ULL;
const uint64_t INTERNAL_ADDR_MASK          = 0x000000007FFFFFFFULL;
const uint64_t ADDR_TYPE_MASK              = 0x0000FFFF80000000ULL;
const uint64_t OTPROM_ADDR_TYPE            = 0x0000000100000000ULL;
const uint64_t PIBMEM_ADDR_TYPE            = 0x0000000800000000ULL;
const uint64_t SEEPROM_ADDR_TYPE           = 0x0000800C80000000ULL;
const uint32_t ALIGN_FOUR_BYTE             = 0xFFFFFFFC;

// common SCOM register offsets for SBE/SLW engines
const uint32_t STATUS_OFFSET_0x00          = 0x00000000;
const uint32_t IBUF_OFFSET_0x0D            = 0x0000000D;
const uint32_t DEBUG0_OFFSET_0x0F          = 0x0000000F;
const uint32_t DEBUG1_OFFSET_0x10          = 0x00000010;

// illegal instruction encoding for SW detected halt
const uint32_t HALT_WITH_ERROR_INSTRUCTION = (('h' << 24) | ('a' << 16) | ('l' << 8) | ('t'));


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{

//------------------------------------------------------------------------------
// subroutine:
//      reads the word at the given address in SEEPROM pointer
//
// parameters: i_target   => target of chip with failed SBE/SLW engine
//             i_pSEEPROM => pointer to a memory-mapped SEEPROM image
//             i_address  => SEEPROM address to read
//             i_engine   => type of engine that failed (SBE/SLW)
//             i_soft_err => engine soft error status, for FFDC
//             o_data     => return data
//
// returns: fapi::ReturnCode with the error, or fapi::FAPI_RC_SUCCESS
//------------------------------------------------------------------------------
fapi::ReturnCode proc_extract_sbe_rc_read_SEEPROM(const fapi::Target & i_target,
                                                  const void         * i_pSEEPROM,
                                                  const uint32_t       i_address,
                                                  const por_engine_t   i_engine,
                                                  const soft_error_t   i_soft_err,
                                                  uint32_t           & o_data)
{
    // return codes
    fapi::ReturnCode rc;

    do
    {
        if (i_pSEEPROM == NULL)
        {
            FAPI_ERR("Need to extract SEEPROM address 0x%08X, but pointer to SEEPROM image content is NULL", i_address);
            const fapi::Target & CHIP_IN_ERROR = i_target;
            const uint32_t & PC = i_address;
            if (i_engine == SBE)
            {
                const soft_error_t & SOFT_ERR_STATUS = i_soft_err;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_IMAGE_POINTER_NULL_SBE);
            }
            else
            {
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_IMAGE_POINTER_NULL_SLW);
            }
            break;
        }

        // copy the data out of the image pointer
        uint8_t * p_errorCode = (uint8_t *)i_pSEEPROM + (i_address & ALIGN_FOUR_BYTE);
        o_data =
            (p_errorCode[0] << 3*8) |
            (p_errorCode[1] << 2*8) |
            (p_errorCode[2] << 1*8) |
            (p_errorCode[3]);
    } while(0);

    return rc;
}


//------------------------------------------------------------------------------
// subroutine:
//      Returns the PC of the given engine
//
// parameters: i_target   => target of chip with failed SBE/SLW engine
//             i_engine   => type of engine that failed (SBE/SLW)
//             i_soft_err => engine soft error status, for FFDC
//             o_pc       => referenee to the uint64_t containing the PC
//
// returns: fapi::ReturnCode with the error, or fapi::FAPI_RC_SUCCESS
//------------------------------------------------------------------------------
fapi::ReturnCode proc_extract_sbe_rc_get_pc(const fapi::Target & i_target,
                                            const por_engine_t   i_engine,
                                            const soft_error_t   i_soft_err,
                                            uint64_t           & o_pc)
{
    // return codes
    fapi::ReturnCode rc;

    // data buffer to hold register values
    ecmdDataBufferBase data(64);

    do
    {
        // read PC from the Status Register
        rc = fapiGetScom(i_target, i_engine + STATUS_OFFSET_0x00, data);
        if (rc)
        {
            FAPI_ERR("Error from fapiGetScom (STATUS_REG_0x%08X)", i_engine + STATUS_OFFSET_0x00);
            break;
        }

        o_pc = (data.getDoubleWord(0) & SBE_ADDR_MASK);

        if (o_pc & FOURBYTE_ALIGNMENT_MASK)
        {
            FAPI_ERR("Address isn't 4-byte aligned");
            const fapi::Target & CHIP_IN_ERROR = i_target;
            const uint64_t & PC = o_pc;
            if (i_engine == SBE)
            {
                const soft_error_t & SOFT_ERR_STATUS = i_soft_err;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_ADDR_UNALIGNED_SBE);
            }
            else
            {
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_ADDR_UNALIGNED_SLW);
            }
            break;
        }
    } while(0);

    return rc;
}


//------------------------------------------------------------------------------
// subroutine:
//      Returns the return code indicated by the PC of the engine
//
// parameters: i_target   => target of chip with failed SBE/SLW engine
//             i_pSEEPROM => pointer to a memory-mapped SEEPROM image
//             i_engine   => type of engine that failed (SBE/SLW)
//             i_soft_err => engine soft error status, for FFDC
//
// returns: fapi::ReturnCode with the error
//          This procedure will NEVER return SUCCESS
//------------------------------------------------------------------------------
fapi::ReturnCode proc_extract_sbe_rc_from_address(const fapi::Target & i_target,
                                                  const void         * i_pSEEPROM,
                                                  const por_engine_t   i_engine,
                                                  const soft_error_t   i_soft_err)
{
    // return codes
    fapi::ReturnCode rc;

    // data buffer to hold register values
    ecmdDataBufferBase data(64);
    uint64_t address_64;

    do
    {
        // read PC
        rc = proc_extract_sbe_rc_get_pc(i_target, i_engine, i_soft_err, address_64);
        if (rc)
        {
            FAPI_ERR("Error from proc_extract_sbe_rc_get_pc");
            break;
        }

        // add 4 because address_64 is pointing at the halt instruction
        uint32_t internal_address = (uint32_t)(address_64 & INTERNAL_ADDR_MASK) + 4;
        // error code to emit
        uint32_t error_code = 0;

        if ((address_64 & ADDR_TYPE_MASK) == SEEPROM_ADDR_TYPE)
        {
            // get the error code from that location in the SEEPROM image
            FAPI_INF("Extracting the error code from address "
                     "0x%X in the SEEPROM", internal_address);

            rc = proc_extract_sbe_rc_read_SEEPROM(i_target, i_pSEEPROM, internal_address, i_engine, i_soft_err, error_code);
            if (rc)
            {
                FAPI_ERR("Error from proc_extract_sbe_rc_read_SEEPROM (address = 0x%08X)", internal_address);
                break;
            }
        }
        else if ((address_64 & ADDR_TYPE_MASK) == PIBMEM_ADDR_TYPE)
        {
            // get the error code from that location in the PIBMEM
            FAPI_INF("Extracting the error code from address "
                     "0x%X in the PIBMEM", internal_address);

            rc = fapiGetScom(i_target, PIBMEM0_0x00080000 + (internal_address >>3), data);
            if (rc)
            {
                FAPI_ERR("Error from fapiGetScom (PIBMEM address 0x%08X)", (uint32_t)PIBMEM0_0x00080000 + (internal_address >>3));
                break;
            }

            error_code = data.getWord((internal_address & 0x04)?1:0);
        }
        else
        {
            FAPI_ERR("Address (0x%012llX) isn't in a known memory address space", address_64);
            const fapi::Target & CHIP_IN_ERROR = i_target;
            const uint64_t & PC = address_64;
            if (i_engine == SBE)
            {
                const soft_error_t & SOFT_ERR_STATUS = i_soft_err;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_ADDR_NOT_RECOGNIZED_SBE);
            }
            else
            {
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_ADDR_NOT_RECOGNIZED_SLW);
            }
            break;
        }

        // look up specified error code
        FAPI_ERR("SBE got error code 0x%06X", error_code);
        const fapi::Target CHIP_IN_ERROR = i_target;
        const fapi::Target CHIP = i_target;
        FAPI_SET_SBE_ERROR(rc, error_code);
    } while(0);

    //Make sure the code doesn't return SUCCESS
    if (rc.ok())
    {
        FAPI_ERR("proc_extract_sbe_rc_from_addr tried to return SUCCESS,"
            " which should be impossible. Must be a code bug.");
        const fapi::Target & CHIP_IN_ERROR = i_target;
        const uint64_t & PC = address_64;
        if (i_engine == SBE)
        {
            const soft_error_t & SOFT_ERR_STATUS = i_soft_err;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_FROM_ADDR_CODE_BUG_SBE);
        }
        else
        {
            FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_FROM_ADDR_CODE_BUG_SLW);
        }
    }
    return rc;
}


//------------------------------------------------------------------------------
// function:
//      Return an RC indicating the SBE/SLW error
//
// parameters: i_target   => Target of chip with failed SBE/SLW
//             i_pSEEPROM => pointer to a memory-mapped SEEPROM image
//             i_engine   => The type of engine that failed (SBE/SLW)
//
// returns: fapi::ReturnCode with the error
//          This procedure will NEVER return SUCCESS
//------------------------------------------------------------------------------
fapi::ReturnCode proc_extract_sbe_rc(const fapi::Target & i_target,
                                     const void         * i_pSEEPROM,
                                     const por_engine_t   i_engine)
{
    // return codes
    fapi::ReturnCode rc;

    // data buffer to hold register values
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase pnor_eccb_status(64);
    ecmdDataBufferBase i2cm_eccb_status(64);
    ecmdDataBufferBase fsi_data(32);
    ecmdDataBufferBase sbe_data0(64);
    ecmdDataBufferBase sbe_data1(64);

    // PC value
    uint64_t pc = 0x0ULL;

    // SBE PNOR/SEEPROM soft error status
    soft_error_t soft_err = eNO_ERROR;

    // SBE attn status
    bool sbe_reported_attn = false;

    do
    {
        // check engine type
        if ((i_engine != SBE) &&
            (i_engine != SLW))
        {
            FAPI_ERR("Unknown engine type %i", i_engine);
            const fapi::Target & CHIP_IN_ERROR = i_target;
            const por_engine_t ENGINE = i_engine;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_UNKNOWN_ENGINE);
            break;
        }

        FAPI_INF("Processing %s error", ((i_engine == SBE)?("SBE"):("SLW")));

        // if analyzing SBE engine failure
        // - make sure I2C master bus fence is released before proceeding
        // - check ECCB engines (I2C/LPC) for UE/CE conditions (SLW does not use
        //   these engines, so no need to check)
        if (i_engine == SBE)
        {
            FAPI_EXEC_HWP(rc, proc_reset_i2cm_bus_fence, i_target);
            if (!rc.ok())
            {
                FAPI_ERR("Error from proc_reset_i2cm_bus_fence");
                break;
            }

            // check on FSI 1007 for any PIB Access Error
            rc = fapiGetCfamRegister(i_target, CFAM_FSI_STATUS_0x00001007, fsi_data);
            if (rc)
            {
                FAPI_ERR("Error from fapiGetCfamRegister (CFAM_FSI_STATUS_0x00001007)");
                break;
            }

            if (fsi_data.getNumBitsSet(17,3) != 0)
            {
                FAPI_ERR("Error during PIB Access");
                const fapi::Target & CHIP_IN_ERROR = i_target;
                const ecmdDataBufferBase & FSI_STATUS = fsi_data;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_PIB_ERROR_SBE);
                break;
            }

            if (fsi_data.isBitSet(30))
            {
                FAPI_ERR("SELFBOOT_ENGINE_ATTENTION - SBE reported attention to FSI2PIB status register");
                sbe_reported_attn = true;
            }

            // check on ECCB Error for I2C engine
            rc = fapiGetScom(i_target, PORE_ECCB_STATUS_REGISTER_READ_0x000C0002, i2cm_eccb_status);
            if (rc)
            {
                FAPI_ERR("Error from fapiGetScom (PORE_ECCB_STATUS_REGISTER_READ_0x000C00002)");
                break;
            }

            // check on ECCB Engine for PNOR Access	
            rc = fapiGetScom(i_target, LPC_STATUS_0x000B0002, pnor_eccb_status);
            if (rc)
            {
                FAPI_ERR("Error from fapiGetScom (LPC_STATUS_0x000B0002)");
                break;
            }

            // determine if either engine has reached threshold of > 128 CEs
            if (i2cm_eccb_status.isBitSet(57))
            {
                soft_err = eSOFT_ERR_I2CM;
            }

            if (pnor_eccb_status.isBitSet(57))
            {
                if (soft_err == eSOFT_ERR_I2CM)
                {
                    soft_err = eSOFT_ERR_BOTH;
                }
                else
                {
                    soft_err = eSOFT_ERR_PNOR;
                }
            }
        }

        // read engine PC value
        rc = proc_extract_sbe_rc_get_pc(i_target, i_engine, soft_err, pc);
        if (rc)
        {
            FAPI_ERR("Error from proc_extract_sbe_rc_get_pc");
            break;
        }

        if (i_engine == SBE)
        {
            // return error if either engine reports an unrecoverable ECC error
            if (i2cm_eccb_status.isBitClear(41,2) && i2cm_eccb_status.isBitSet(43))
            {
                FAPI_ERR("Unrecoverable ECC error on I2C Access");
                const fapi::Target & CHIP_IN_ERROR = i_target;
                const uint64_t & PC = pc;
                const ecmdDataBufferBase & ECCB_STATUS = i2cm_eccb_status;
                const soft_error_t & SOFT_ERR_STATUS = soft_err;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_UNRECOVERABLE_ECC_I2C_SBE);
                break;
            }

            if (pnor_eccb_status.isBitClear(41,2) && pnor_eccb_status.isBitSet(43))
            {
                FAPI_ERR("Unrecoverable ECC error on PNOR Access");
                const fapi::Target & CHIP_IN_ERROR = i_target;
                const uint64_t & PC = pc;
                const ecmdDataBufferBase & ECCB_STATUS = pnor_eccb_status;
                const soft_error_t & SOFT_ERR_STATUS = soft_err;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_UNRECOVERABLE_ECC_PNOR_SBE);
                break;
            }
        } // if (i_engine == SBE)


        // read Debug1 register state, check for any HW error
        rc = fapiGetScom(i_target, i_engine + DEBUG1_OFFSET_0x10, sbe_data1);
        if (rc)
        {
            FAPI_ERR("Error from fapiGetScom (DEBUG1_REG_0x%08X)", i_engine + DEBUG1_OFFSET_0x10);
            break;
        }

        if (sbe_data1.isBitSet(63))  // SBE ANYERROR
        {
            FAPI_ERR("PIBMS_DBG_LOCK - error set");

            // read Debug0 register state
            rc = fapiGetScom(i_target, i_engine + DEBUG0_OFFSET_0x0F, sbe_data0);
            if (rc)
            {
                FAPI_ERR("Error from fapiGetScom (DEBUG0_REG_0x%08X)", i_engine + DEBUG0_OFFSET_0x0F);
                break;
            }

            // print bitwise messages for error log, unique errors will be grouped/combined into callouts below
            // grouping is done per guideance provided by Andreas Koenig
            if (sbe_data1.isBitSet(48))
            {
                FAPI_ERR("OCI_DATA_READ_P_ERR - Parity error in read data from OCI");
            }
            uint8_t oci_rc = (sbe_data0.getByte(7) >> 5) & 0x7;
            if (oci_rc)
            {
                FAPI_ERR("Last return code from OCI SBE got return code %i", oci_rc);
            }
            if (sbe_data1.isBitSet(52))
            {
                FAPI_ERR("BAD_PAR - bad instruction parity");
            }
            if (sbe_data1.isBitSet(53))
            {
                FAPI_ERR("BAD_INSTRUCTION - invalid instruction");
            }
            if (sbe_data1.isBitSet(54))
            {
                FAPI_ERR("BAD_PC - PC overflow/underflow");
            }
            if (sbe_data1.isBitSet(55))
            {
                FAPI_ERR("SCAN_DATA_CRC - Scan data CRC error");
            }
            if (sbe_data1.isBitSet(56))
            {
                FAPI_ERR("PC_STACK_ERR - PC stack PUSH error or POP error");
            }
            if (sbe_data1.isBitSet(57))
            {
                FAPI_ERR("INSTR_FETCH_ERROR - Non-zero return code or read sbe_data1 parity error was received when during fetch  - phase");
            }
            if (sbe_data1.isBitSet(58))
            {
                FAPI_ERR("BAD_OPERAND - Invalid Instruction Operand");
            }
            if (sbe_data1.isBitSet(59))
            {
                FAPI_ERR("BAD_INSTRUCTION_PATH - Invalid Instruction Path (e.g. FI2C parameter miss)");
            }
            if (sbe_data1.isBitSet(60))
            {
                FAPI_ERR("BAD_START_VECTOR_TRIGGER - Invalid Start Vector triggered");
            }
            if (sbe_data1.isBitSet(61))
            {
                FAPI_ERR("FI2C_PROTOCOL_HANG - Fast I2C protocol hang detected - exceeded poll limit for FI2C engine");
            }
            if (sbe_data1.isBitSet(62))
            {
                FAPI_ERR("ROL_INVALID - rotate invalid");
            }

            if (sbe_data0.isBitSet(32))
            {
                FAPI_ERR("PIB_DATA_READ_P_ERR - Parity error in read data from PRV PIB");
            }
            uint8_t pcb_error = (sbe_data0.getByte(4) >> 4) & 0x7;
            uint32_t scom_address = sbe_data0.getWord(0);
            if (pcb_error)
            {
                FAPI_ERR("SBE got PCB error %i accessing scom address 0x%08X", pcb_error, scom_address);
            }
            if (sbe_data0.isBitSet(36))
            {
                FAPI_ERR("I2C_BAD_STATUS_0 - I2CM internal errors including parity errors");
            }
            if (sbe_data0.isBitSet(37))
            {
                FAPI_ERR("I2C_BAD_STATUS_1 - bad PIB response code error for ECCAX to I2CM communication");
            }
            if (sbe_data0.isBitSet(38))
            {
                FAPI_ERR("I2C_BAD_STATUS_2 - ECCAX internal errors (UCE or PIB master resets)");
            }
            if (sbe_data0.isBitSet(39))
            {
                FAPI_ERR("I2C_BAD_STATUS_3 - I2C bus issues (I2C bus busy, NACK, stop bit error)");
            }
            if (sbe_data0.isBitSet(40))
            {
                FAPI_ERR("GROUP_PARITY_ERROR_0 - parity error from debug or status or error mask or pc stack regs");
            }
            if (sbe_data0.isBitSet(41))
            {
                FAPI_ERR("GROUP_PARITY_ERROR_1 - parity error from control or exe trigger or exe t_mask or i2c param regs");
            }
            if (sbe_data0.isBitSet(42))
            {
                FAPI_ERR("GROUP_PARITY_ERROR_2 - parity error from perv/oci base addr or table base addr or memory reloc");
            }
            if (sbe_data0.isBitSet(43))
            {
                FAPI_ERR("GROUP_PARITY_ERROR_3 - parity error from scr0 or scr1 or scr2 or sbe_data0 scr0 reg");
            }
            if (sbe_data0.isBitSet(44))
            {
                FAPI_ERR("GROUP_PARITY_ERROR_4 - parity error from ibuf regs");
            }

            //
            // Bucketize callouts based on combination of error bits
            //

            // "Internal Error" bucket (Error Event 3)
            if ((sbe_data0.getNumBitsSet(40,5) != 0) || sbe_data1.isBitSet(55))
            {
                FAPI_ERR("Internal %s Error", ((i_engine == SBE)?("SBE"):("SLW")));
                const fapi::Target & CHIP_IN_ERROR = i_target;
                const uint64_t & PC = pc;
                const uint8_t & GROUP_PARITY_ERROR_0_4 = (sbe_data0.getByte(5) >> 3) & 0x1F;
                const bool & SCAN_DATA_CRC_ERROR = sbe_data1.isBitSet(55);
                if (i_engine == SBE)
                {
                    const soft_error_t & SOFT_ERR_STATUS = soft_err;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_INTERNAL_ERROR_SBE);
                }
                else
                {
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_INTERNAL_ERROR_SLW);
                }
                break;
            }

            // "I2C Error" bucket (Error Event 0)
            if ((sbe_data0.getNumBitsSet(36,4) != 0) || (sbe_data1.isBitSet(61)))
            {
                FAPI_ERR("%s failed I2C Master operation", ((i_engine == SBE)?("SBE"):("SLW")));
                const fapi::Target & CHIP_IN_ERROR = i_target;
                const uint64_t & PC = pc;
                const uint8_t & I2C_BAD_STATUS_0_3 = sbe_data0.getHalfWord(10);
                const bool & FI2C_HANG = sbe_data1.isBitSet(61);

                if (i_engine == SBE)
                {
                    const soft_error_t & SOFT_ERR_STATUS = soft_err;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_I2C_ERROR_SBE);
                }
                else
                {
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_I2C_ERROR_SLW);
                }
                break;
            }

            // "SCOM Error" bucket (Error Event 0), raise in presence of no instruction execution error
            if ((sbe_data0.getNumBitsSet(32,4) != 0) && (sbe_data1.getNumBitsSet(52,9) == 0) && (sbe_data1.isBitClear(62)))
            {
                FAPI_ERR("%s failed SCOM operation", ((i_engine == SBE)?("SBE"):("SLW")));
                const fapi::Target & CHIP_IN_ERROR = i_target;
                const uint64_t & PC = pc;
                const uint32_t & SCOM_ADDRESS = scom_address;
                const uint8_t & PIB_ERROR_CODE = pcb_error;
                const bool & PIB_DATA_READ_PARITY_ERROR = sbe_data0.isBitSet(32);
                if (i_engine == SBE)
                {
                    const soft_error_t & SOFT_ERR_STATUS = soft_err;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_SCOM_ERROR_SBE);
                }
                else
                {
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_SCOM_ERROR_SLW);
                }
                break;
            }

            // "OCI Error" bucket (Error Event 1)
            if ((i_engine == SLW) && (sbe_data1.getNumBitsSet(48,4) != 0))
            {
                FAPI_ERR("%s failed OCI Master operation", ((i_engine == SBE)?("SBE"):("SLW")));
                const fapi::Target & CHIP_IN_ERROR = i_target;
                const uint64_t & PC = pc;
                const uint8_t & OCI_ERROR_CODE = oci_rc;
                const bool & OCI_DATA_READ_PARITY_ERROR = sbe_data1.isBitSet(48);
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_OCI_ERROR_SLW);
                break;
            }

            // check for the execution of an invalid instruction
            // if present, check if the SBE stopped at a code detected error (instruction = 'halt')
            if (sbe_data1.isBitSet(53) || sbe_data1.isBitSet(62))
            {
                rc = fapiGetScom(i_target, i_engine + IBUF_OFFSET_0x0D, data);
                if (rc)
                {
                    // fail through to "Instruction Execution Error" bucket below
                    FAPI_ERR("Error from fapiGetScom(IBUF_REG_0x%08X)", i_engine + IBUF_OFFSET_0x0D);
                    FAPI_ERR("SBE reported an invalid instruction error, but unable to determine if it was a code-detected error or not");
                }
                else
                {
                    // lookup return code identifying halt from image, based on PC value
                    const uint32_t instruction = data.getWord(0);
                    if (instruction == HALT_WITH_ERROR_INSTRUCTION)
                    {
                        rc = proc_extract_sbe_rc_from_address(i_target, i_pSEEPROM, i_engine, soft_err);
                        break;
                    }
                }
            }

            // "Instruction Execution Error" bucket (Error Event 2)
            if ((sbe_data1.getNumBitsSet(52,9) != 0) || (sbe_data1.isBitSet(62)))
            {
                FAPI_ERR("SBE encountered instruction execution error");
                const fapi::Target & CHIP_IN_ERROR = i_target;
                const uint64_t & PC = pc;
                const bool & INSTRUCTION_PARITY_ERROR = sbe_data1.isBitSet(52);
                const bool & INVALID_INSTRUCTION_NON_ROTATE = sbe_data1.isBitSet(53);
                const bool & PC_OVERFLOW_UNDERFLOW = sbe_data1.isBitSet(54);
                // bit 55 covered by Internal Error check
                const bool & PC_STACK_ERROR = sbe_data1.isBitSet(56);
                const bool & INSTRUCTION_FETCH_ERROR = sbe_data1.isBitSet(57);
                const bool & INVALID_OPERAND = sbe_data1.isBitSet(58);
                const bool & I2C_ENGINE_MISS = sbe_data1.isBitSet(59);
                const bool & INVALID_START_VECTOR = sbe_data1.isBitSet(60);
                const bool & INVALID_INSTRUCTION_ROTATE = sbe_data1.isBitSet(62);

                if (i_engine == SBE)
                {
                    const soft_error_t & SOFT_ERR_STATUS = soft_err;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_INSTRUCTION_ERROR_SBE);
                }
                else
                {
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_INSTRUCTION_ERROR_SLW);
                }
                break;
            }
        } // SBE ANYERROR debug(63)

        // no error bits are set, check PC to check execution progress
        // check for real halt (wait 0) instruction in OTPROM
        if ((i_engine == SBE) && ((pc & ADDR_TYPE_MASK) == OTPROM_ADDR_TYPE))
        {
            // Note: OTPROM halts are actual halt instructions, which means the
            //       SBE updated the PC before the halt.
            //       Thus we have to subtract 4 to get back to the address of the halt
            uint32_t internal_address = (uint32_t)(pc & INTERNAL_ADDR_MASK) - 4;

            // map the OTPROM address to the known error at that location
            // the OTPROM is write-once at mfg test, so addresses should remain fixed in this code
            FAPI_INF("Determining the OTPROM error based on the address "
                     "0x%X", internal_address);
            const fapi::Target & CHIP_IN_ERROR = i_target;
            const uint64_t & PC = internal_address;

            switch (internal_address)
            {
                case (0x400fc): // original OTPROM version
                case (0x40118): // updated OTPROM version
                    FAPI_ERR("Chip not identified as Murano or Venice");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_BAD_CHIP_TYPE_SBE);
                    break;
                case (0x401c0):
                    FAPI_ERR("SEEPROM magic number didn't match \"XIP SEPM\"");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_SEEPROM_MAGIC_NUMBER_MISMATCH_SBE);
                    break;
                case (0x401ec):
                    FAPI_ERR("Branch to SEEPROM didn't happen");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_BRANCH_TO_SEEPROM_FAIL_SBE);
                    break;
                default:
                    FAPI_ERR("Halted in OTPROM, but not at an expected halt location");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_UNEXPECTED_OTPROM_HALT_SBE);
                    break;
            }
            break;
        }

        // check to see if engine was never started
        if (((pc & SBE_ADDR_MASK) == 0x0000800000000000ULL) ||
            ((pc & SBE_ADDR_MASK) == 0x0000000000000000ULL))
        {
            FAPI_ERR("PC is all zeros, which means %s was probably never started", ((i_engine == SBE)?("SBE"):("SLW")));
            const fapi::Target & CHIP_IN_ERROR = i_target;
            const uint64_t & PC = pc;

            if (i_engine == SBE)
            {
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_NEVER_STARTED_SBE);
                break;
            }
            else
            {
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_NEVER_STARTED_SLW);
                break;
            }
        }

        // return soft error with lowest priority
        if ((i_engine == SBE) && (soft_err != eNO_ERROR))
        {
            const fapi::Target & CHIP_IN_ERROR = i_target;
            if (soft_err == eSOFT_ERR_I2CM)
            {
                FAPI_ERR("Recoverable ECC Error on I2C Access");
                const ecmdDataBufferBase & I2C_ECCB_STATUS = i2cm_eccb_status;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_SOFT_ECC_ERROR_I2C_SBE);
                break;
            }
            else if (soft_err == eSOFT_ERR_PNOR)
            {
                FAPI_ERR("Recoverable ECC Error on PNOR Access");
                const ecmdDataBufferBase & PNOR_ECCB_STATUS = pnor_eccb_status;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_SOFT_ECC_ERROR_PNOR_SBE);
                break;
            }
            else // (soft_err == eSOFT_ERR_BOTH)
            {
                FAPI_ERR("Recoverable ECC Error on PNOR Access");
                FAPI_ERR("Recoverable ECC Error on I2C Access");
                const ecmdDataBufferBase & PNOR_ECCB_STATUS = pnor_eccb_status;
                const ecmdDataBufferBase & I2C_ECCB_STATUS = i2cm_eccb_status;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_SOFT_ECC_ERROR_I2C_AND_PNOR_SBE);
                break;
            }
        }

    } while(0);

    // if SBE, make sure that the code doesn't return FAPI_RC_SUCCESS
    // if the engine reported an attn to the FSI2PIB status register
    if (rc.ok() && (i_engine == SBE) && (sbe_reported_attn))
    {
        FAPI_ERR("SBE reported attention, but proc_extract_sbe_rc tried to return SUCCESS,"
            " which should be impossible. Must be a code bug.");
        const fapi::Target & CHIP_IN_ERROR = i_target;
        const uint64_t & PC = pc;  
        FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_CODE_BUG_SBE);
    }
    return rc;
}


} // extern "C"
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
