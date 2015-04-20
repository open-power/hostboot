/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_sbe_rc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: proc_extract_sbe_rc.C,v 830.1 2015-04-20 13:55:16 dcrowell Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/fw830/procedures/ipl/fapi/proc_extract_sbe_rc.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *|
// *! TITLE       : proc_extract_sbe_rc.C
// *! DESCRIPTION : Create return code for PORE (SBE/SLW) error
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *! BACKUP NAME : Johannes Koesters       Email: koesters@de.ibm.com
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
#include <proc_extract_pore_engine_state.H>
#include <proc_extract_pore_base_ffdc.H>
#include <proc_extract_pore_halt_ffdc.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// address space masks
const uint64_t PORE_ADDR_MASK              = 0x0000FFFFFFFFFFFFULL;
const uint64_t INTERNAL_ADDR_MASK          = 0x000000007FFFFFFFULL;
const uint64_t ADDR_TYPE_MASK              = 0x0000FFFF80000000ULL;
const uint64_t OTPROM_ADDR_TYPE            = 0x0000000100000000ULL;
const uint64_t PIBMEM_ADDR_TYPE            = 0x0000000800000000ULL;
const uint64_t SEEPROM_ADDR_TYPE           = 0x0000800C80000000ULL;
const uint64_t SLW_ADDR_TYPE               = 0x0000800080000000ULL;

// illegal instruction encoding for SW detected halt
const uint32_t PORE_HALT_WITH_ERROR_INSTRUCTION = (('h' << 24) | ('a' << 16) | ('l' << 8) | ('t'));


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{


/**
 * proc_extract_sbe_rc - HWP entry point, return RC indicating SBE/SLW error
 *
 * @param[in]   i_target - target of chip with failed SBE/SLW engine
 * @param[in]   i_poreve - pointer to PoreVe object, used to collect engine
 *                         state if non NULL
 * @param[in]   i_image  - pointer to memory-mapped PORE image
 * @param[in]   i_engine - type of engine that failed (SBE/SLW)
 *
 * @retval      fapi::ReturnCode  - The error code the SBE hit, or the error hit
 *                                  while trying to get the error code
 */
fapi::ReturnCode proc_extract_sbe_rc(const fapi::Target & i_target,
                                     void * i_poreve,
                                     const void * i_image,
                                     const por_engine_t i_engine)
{
    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;

    // common state for analysis/FFDC
    const fapi::Target & CHIP = i_target;
    por_base_state pore_state;
    // SBE specific state for analysis/FFDC
    por_sbe_base_state pore_sbe_state;

    // process arguments
    bool is_processor = (i_target.getType() == fapi::TARGET_TYPE_PROC_CHIP);
    bool is_sbe = (i_engine == SBE);
    bool is_slw = (i_engine == SLW);

    do
    {
        //
        // all engine types -- extract engine state
        //

        FAPI_INF("proc_extract_sbe_rc: Processing PORE engine for target: %s, engine type: %s, virtual: %d", 
                 i_target.toEcmdString(),
                 ((i_engine == SBE)?("SBE"):("SLW")),
                 (i_poreve == NULL)?(0):(1));

        FAPI_EXEC_HWP(rc, proc_extract_pore_engine_state,
                      i_target, i_poreve, i_engine, pore_state, pore_sbe_state);
        if (!rc.ok())
        {
            FAPI_ERR("proc_extract_sbe_rc: Error from proc_extract_pore_engine_state");
            break;
        }


        //
        // processor SBE -- return SEEPROM/PNOR UE as highest priority callouts
        //

        if (is_processor && is_sbe)
        {
            // ensure I2C master bus fence is released before proceeding
            FAPI_EXEC_HWP(rc, proc_reset_i2cm_bus_fence, i_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_extract_sbe_rc: Error from proc_reset_i2cm_bus_fence");
                break;
            }

            // return error if either ECCB engine reports an unrecoverable ECC error
            if (pore_sbe_state.i2cm_eccb_status.isBitClear(41,2) && pore_sbe_state.i2cm_eccb_status.isBitSet(43))
            {
                FAPI_ERR("proc_extract_sbe_rc: SBE encountered Unrecoverable ECC error on I2C Access");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_UNRECOVERABLE_ECC_SEEPROM);
                break;
            }

            if (pore_sbe_state.pnor_eccb_status.isBitClear(41,2) && pore_sbe_state.pnor_eccb_status.isBitSet(43))
            {
                FAPI_ERR("proc_extract_sbe_rc: SBE encountered Unrecoverable ECC error on PNOR Access");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_UNRECOVERABLE_ECC_PNOR);
                break;
            }
        }


        //
        // all engine types -- process PORE Debug0/Debug1 registers for HW detected/SW generated errors
        // 

        ecmdDataBufferBase pore_debug0_reg;
        ecmdDataBufferBase pore_debug1_reg;

        rc_ecmd |= pore_state.engine_state.extractToRight(pore_debug0_reg, 64*PORE_DEBUG0_OFFSET, 64);
        rc_ecmd |= pore_state.engine_state.extractToRight(pore_debug1_reg, 64*PORE_DEBUG1_OFFSET, 64);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_extract_sbe_rc: Error %x extracting PORE engine debug register state", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // any HW error will cause DBG_LOCK bit to be set
        if (pore_debug1_reg.isBitSet(63))
        {
            FAPI_ERR("proc_extract_sbe_rc: PIBMS_DBG_LOCK - error set");

            // print bitwise messages for error log, unique errors will be grouped/combined into callouts below
            // grouping is done per guidance provided by Andreas Koenig
            if (pore_debug1_reg.isBitSet(48))
            {
                FAPI_ERR("proc_extract_sbe_rc: ERR_DATA_READ_P_ERR - Parity error in read data from OCI");
            }
            uint8_t oci_rc = (pore_debug0_reg.getByte(7) >> 5) & 0x7;
            if (oci_rc)
            {
                FAPI_ERR("proc_extract_sbe_rc: Last return code from OCI received return code %i", oci_rc);
            }
            if (pore_debug1_reg.isBitSet(52))
            {
                FAPI_ERR("proc_extract_sbe_rc: BAD_PAR - bad instruction parity");
            }
            if (pore_debug1_reg.isBitSet(53))
            {
                FAPI_ERR("proc_extract_sbe_rc: BAD_INSTRUCTION - invalid instruction");
            }
            if (pore_debug1_reg.isBitSet(54))
            {
                FAPI_ERR("proc_extract_sbe_rc: BAD_PC - PC overflow/underflow");
            }
            if (pore_debug1_reg.isBitSet(55))
            {
                FAPI_ERR("proc_extract_sbe_rc: SCAN_DATA_CRC - Scan data CRC error");
            }
            if (pore_debug1_reg.isBitSet(56))
            {
                FAPI_ERR("proc_extract_sbe_rc: PC_STACK_ERR - PC stack PUSH error or POP error");
            }
            if (pore_debug1_reg.isBitSet(57))
            {
                FAPI_ERR("proc_extract_sbe_rc: INSTR_FETCH_ERROR - Non-zero return code or read DEBUG1 parity error was received when during fetch phase");
            }
            if (pore_debug1_reg.isBitSet(58))
            {
                FAPI_ERR("proc_extract_sbe_rc: BAD_OPERAND - Invalid Instruction Operand");
            }
            if (pore_debug1_reg.isBitSet(59))
            {
                FAPI_ERR("proc_extract_sbe_rc: BAD_INSTRUCTION_PATH - Invalid Instruction Path (e.g. FI2C parameter miss)");
            }
            if (pore_debug1_reg.isBitSet(60))
            {
                FAPI_ERR("proc_extract_sbe_rc: BAD_START_VECTOR_TRIGGER - Invalid Start Vector triggered");
            }
            if (pore_debug1_reg.isBitSet(61))
            {
                FAPI_ERR("proc_extract_sbe_rc: FI2C_PROTOCOL_HANG - Fast I2C protocol hang detected - exceeded poll limit for FI2C engine");
            }
            if (pore_debug1_reg.isBitSet(62))
            {
                FAPI_ERR("proc_extract_sbe_rc: ROL_INVALID - rotate invalid");
            }
            if (pore_debug0_reg.isBitSet(32))
            {
                FAPI_ERR("proc_extract_sbe_rc: PIB_DATA_READ_P_ERR - Parity error in read data from PRV PIB");
            }
            uint8_t pcb_error = (pore_debug0_reg.getByte(4) >> 4) & 0x7;
            uint32_t scom_address = pore_debug0_reg.getWord(0);
            if (pcb_error)
            {
                FAPI_ERR("proc_extract_sbe_rc: PORE engine got PCB error %i accessing scom address 0x%08X", pcb_error, scom_address);
            }
            if (pore_debug0_reg.isBitSet(36))
            {
                FAPI_ERR("proc_extract_sbe_rc: I2C_BAD_STATUS_0 - I2CM internal errors including parity errors");
            }
            if (pore_debug0_reg.isBitSet(37))
            {
                FAPI_ERR("proc_extract_sbe_rc: I2C_BAD_STATUS_1 - bad PIB response code error for ECCAX to I2CM communication");
            }
            if (pore_debug0_reg.isBitSet(38))
            {
                FAPI_ERR("proc_extract_sbe_rc: I2C_BAD_STATUS_2 - ECCAX internal errors (UCE or PIB master resets)");
            }
            if (pore_debug0_reg.isBitSet(39))
            {
                FAPI_ERR("proc_extract_sbe_rc: I2C_BAD_STATUS_3 - I2C bus issues (I2C bus busy, NACK, stop bit error)");
            }
            if (pore_debug0_reg.isBitSet(40))
            {
                FAPI_ERR("proc_extract_sbe_rc: GROUP_PARITY_ERROR_0 - parity error from DEBUG or STATUS or ERROR MASK or PC STACK regs");
            }
            if (pore_debug0_reg.isBitSet(41))
            {
                FAPI_ERR("proc_extract_sbe_rc: GROUP_PARITY_ERROR_1 - parity error from CONTROL or EXE TRIGGER or EXE T_MASK or I2C PARAM regs");
            }
            if (pore_debug0_reg.isBitSet(42))
            {
                FAPI_ERR("proc_extract_sbe_rc: GROUP_PARITY_ERROR_2 - parity error from PERV/OCI BASE ADDR or TABLE BASE ADDR or MEMORY RELOC regs");
            }
            if (pore_debug0_reg.isBitSet(43))
            {
                FAPI_ERR("proc_extract_sbe_rc: GROUP_PARITY_ERROR_3 - parity error from SCR0 or SCR1 or SCR2 or DEBUG0 SCR0 reg");
            }
            if (pore_debug0_reg.isBitSet(44))
            {
                FAPI_ERR("proc_extract_sbe_rc: GROUP_PARITY_ERROR_4 - parity error from IBUF regs");
            }

            //
            // Bucketize callouts based on combination of error bits
            //

            // "Internal Error" bucket (Error Event 3)
            if ((pore_debug0_reg.getNumBitsSet(40,5) != 0) || pore_debug1_reg.isBitSet(55))
            {
                FAPI_ERR("proc_extract_sbe_rc: Internal Error (Event 3)");
                const uint8_t & GROUP_PARITY_ERROR_0_4 = (pore_debug0_reg.getByte(5) >> 3) & 0x1F;
                const bool & SCAN_DATA_CRC_ERROR = pore_debug1_reg.isBitSet(55);
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_INTERNAL_ERROR);
                break;
            }

            // "I2C Error" bucket (Error Event 0)
            if ((pore_debug0_reg.getNumBitsSet(36,4) != 0) || (pore_debug1_reg.isBitSet(61)))
            {
                FAPI_ERR("proc_extract_sbe_rc: I2C Error (Event 0)");
                const uint8_t & I2C_BAD_STATUS_0_3 = (pore_debug0_reg.getByte(4) & 0x0F);
                const bool & FI2C_HANG = pore_debug1_reg.isBitSet(61);
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_I2C_ERROR);
                break;
            }

            // "SCOM Error" bucket (Error Event 0), raise only if no instruction execution error is present
            if ((pore_debug0_reg.getNumBitsSet(32,4) != 0) && (pore_debug1_reg.getNumBitsSet(52,9) == 0) && (pore_debug1_reg.isBitClear(62)))
            {
                FAPI_ERR("proc_extract_sbe_rc: SCOM operation failed (Event 0)");
                const uint32_t & SCOM_ADDRESS = scom_address;
                const uint8_t & PIB_ERROR_CODE = pcb_error;
                const bool & PIB_DATA_READ_PARITY_ERROR = pore_debug0_reg.isBitSet(32);


                if (is_sbe &&
                    (scom_address == (uint32_t) TP_GP0_OR_0x01000005) &&
                    (pore_state.vital_state.getHalfWord(1) == 0x2031))
                {
                    FAPI_INF("proc_extract_sbe_rc: Reconfig loop should be attempted");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_ENGINE_RETRY);
                }
                // SW285387
                else if (is_sbe &&
                         (scom_address == (uint32_t) PCIE_OPCG_CNTL0_0x09030002) &&
                         (pore_state.vital_state.getHalfWord(1) == 0x2100))
                {
                    FAPI_INF("proc_extract_sbe_rc: PCI OPCG SCOM failure encountered");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_PCI_CLOCK_ERROR);
                }
                else
                {
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_SCOM_ERROR);
                }
                break;
            }

            // "OCI Error" bucket (Error Event 1)
            if (is_slw && (pore_debug1_reg.getNumBitsSet(48,4) != 0))
            {
                FAPI_ERR("proc_extract_sbe_rc: OCI Master operation failed (Event 1)");
                const uint8_t & OCI_ERROR_CODE = oci_rc;
                const bool & OCI_DATA_READ_PARITY_ERROR = pore_debug1_reg.isBitSet(48);
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_OCI_ERROR);
                break;
            }

            // check for PORE code generated halt
            // code detected errors will result in the the execution of an invalid instruction -> ASCII 'halt'
            if (pore_debug1_reg.isBitSet(53) || pore_debug1_reg.isBitSet(62))
            {
                // check alignment of PC value
                if (pore_state.pc & 0x3ULL)
                {
                    FAPI_ERR("proc_extract_sbe_rc: Unexpected address alignment");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_ADDR_UNALIGNED);
                    break;
                }

                // examine first word of IBUF register
                uint32_t instruction = pore_state.engine_state.getWord(2*PORE_IBUF0_OFFSET);
                if (instruction == PORE_HALT_WITH_ERROR_INSTRUCTION)
                {
                     // halt encountered
                     // RC indicating unique exit point will be contained in next word
                     // retrieve RC from appropriate memory space
                     uint64_t rc_addr = (pore_state.pc & INTERNAL_ADDR_MASK)+4;
                     
                     if ((is_processor && 
                         (((pore_state.pc & ADDR_TYPE_MASK) == SEEPROM_ADDR_TYPE) ||
                          ((pore_state.pc & ADDR_TYPE_MASK) == SLW_ADDR_TYPE))) ||
                         (!is_processor))
                     {
                         if (i_image == NULL)
                         {
                             FAPI_ERR("proc_extract_sbe_rc: PORE image pointer is NULL");
                             FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_IMAGE_POINTER_NULL);
                             break;
                         }

                         FAPI_INF("proc_extract_sbe_rc: Extracting the error code from address 0x%llX in PORE image", rc_addr);
                         uint8_t * p_errorCode = (uint8_t *) i_image + rc_addr;
                         pore_state.rc =
                             (p_errorCode[0] << 3*8) |
                             (p_errorCode[1] << 2*8) |
                             (p_errorCode[2] << 1*8) |
                             (p_errorCode[3]);
                     }
                     else if (is_processor && ((pore_state.pc & ADDR_TYPE_MASK) == PIBMEM_ADDR_TYPE))
                     {
                         FAPI_INF("proc_extract_sbe_rc: Extracting the error code from address 0x%llX in the PIBMEM", rc_addr);
                         ecmdDataBufferBase pibmem_data(64);
                         rc = fapiGetScom(i_target, PIBMEM0_0x00080000 + (rc_addr >>3), pibmem_data);
                         if (rc)
                         {
                             FAPI_ERR("proc_extract_sbe_rc: Error from fapiGetScom (PIBMEM address 0x%08X)", (uint32_t) (PIBMEM0_0x00080000 + (rc_addr >>3)));
                             break;
                         }
                         pore_state.rc = pibmem_data.getWord((rc_addr & 0x04)?1:0);
                     }
                     else
                     {
                         FAPI_ERR("proc_extract_sbe_rc: Address (0x%012llX) isn't in a known memory address space", pore_state.pc);
                         FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_ADDR_NOT_RECOGNIZED);
                         break;
                     }

                     // invoke platform function to return XML defined RC associated with PORE state
                     FAPI_ERR("proc_extract_sbe_rc: PORE got error code 0x%06X", pore_state.rc);
                     FAPI_SET_SBE_ERROR(rc, pore_state.rc);

                     // ensure that error is generated in this code path
                     if (rc.ok())
                     {
                         FAPI_ERR("proc_extract_sbe_rc: PORE got error code 0x%06X, but this did not resolve to any return code!", pore_state.rc);
                         FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_FROM_ADDR_CODE_BUG);
                     }
                     break;
                }
            }

            // "Instruction Execution Error" bucket (Error Event 2)
            if ((pore_debug1_reg.getNumBitsSet(52,9) != 0) || (pore_debug1_reg.isBitSet(62)))
            {
                FAPI_ERR("proc_extract_sbe_rc: Instruction execution error (Event 2)");
                const bool & INSTRUCTION_PARITY_ERROR = pore_debug1_reg.isBitSet(52);
                const bool & INVALID_INSTRUCTION_NON_ROTATE = pore_debug1_reg.isBitSet(53);
                const bool & PC_OVERFLOW_UNDERFLOW = pore_debug1_reg.isBitSet(54);
                // bit 55 covered by Internal Error check
                const bool & PC_STACK_ERROR = pore_debug1_reg.isBitSet(56);
                const bool & INSTRUCTION_FETCH_ERROR = pore_debug1_reg.isBitSet(57);
                const bool & INVALID_OPERAND = pore_debug1_reg.isBitSet(58);
                const bool & I2C_ENGINE_MISS = pore_debug1_reg.isBitSet(59);
                const bool & INVALID_START_VECTOR = pore_debug1_reg.isBitSet(60);
                const bool & INVALID_INSTRUCTION_ROTATE = pore_debug1_reg.isBitSet(62);
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_INSTRUCTION_ERROR);
                break;
            }
        }


        //
        // processor SBE -- check for real halt in OTPROM
        // 

        // for processor SBE only, check for real halt (wait 0) instruction in OTPROM
        if (is_processor && is_sbe && ((pore_state.pc & ADDR_TYPE_MASK) == OTPROM_ADDR_TYPE))
        {
            // Note: OTPROM halts are actual halt instructions, which means the
            //       SBE updated the PC before the halt.
            //       Thus we have to subtract 4 to get back to the address of the halt
            uint32_t pc_m4 = (uint32_t)(pore_state.pc & INTERNAL_ADDR_MASK)-4;

            // map the OTPROM address to the known error at that location
            // the OTPROM is write-once at mfg test, so addresses should remain fixed in this code
            FAPI_INF("proc_extract_sbe_rc: Determining OTPROM error at address 0x%X", pc_m4);
            switch (pc_m4)
            {
                case (0x400fc):
                case (0x40118):
                case (0x40124):
                    FAPI_ERR("proc_extract_sbe_rc: Chip was not identified as Murano or Venice");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_BAD_CHIP_TYPE);
                    break;
                case (0x401c0):
                case (0x401cc):
                    FAPI_ERR("proc_extract_sbe_rc: SEEPROM magic number didn't match \"XIP SEPM\"");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_SEEPROM_MAGIC_NUMBER_MISMATCH);
                    break;
                case (0x401ec):
                case (0x401f8):
                    FAPI_ERR("proc_extract_sbe_rc: Branch to SEEPROM didn't happen");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_BRANCH_TO_SEEPROM_FAIL);
                    break;
                default:
                    FAPI_ERR("proc_extract_sbe_rc: Halted in OTPROM, but not at an expected halt location");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_UNEXPECTED_OTPROM_HALT);
                    break;
            }
        }


        //
        // all engine types -- validate execution progress of PC
        //

        // determine if engine was ever started
        if (((pore_state.pc & PORE_ADDR_MASK) == 0x0000800000000000ULL) ||
            ((pore_state.pc & PORE_ADDR_MASK) == 0x0000000000000000ULL))
        {
            FAPI_ERR("proc_extract_sbe_rc: PC is all zeros, which means PORE engine was probably never started");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_NEVER_STARTED);
            break;
        }


        //
        // processor SBE -- return soft error with lowest priority
        //

        if (is_processor && is_sbe && (pore_sbe_state.soft_err != eNO_ERROR))
        {
            if (pore_sbe_state.soft_err == eSOFT_ERR_I2CM)
            {
                FAPI_ERR("proc_extract_sbe_rc: SBE encountered Recoverable ECC Error on I2C Access");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_SOFT_ECC_ERROR_SEEPROM);
                break;
            }
            else if (pore_sbe_state.soft_err == eSOFT_ERR_PNOR)
            {
                FAPI_ERR("proc_extract_sbe_rc: SBE encountered Recoverable ECC Error on PNOR Access");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_SOFT_ECC_ERROR_PNOR);
                break;
            }
            else // (soft_err == eSOFT_ERR_BOTH)
            {
                FAPI_ERR("proc_extract_sbe_rc: SBE encountered Recoverable ECC Error on I2C Access");
                FAPI_ERR("proc_extract_sbe_rc: SBE encountered Recoverable ECC Error on PNOR Access");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_SOFT_ECC_ERROR_SEEPROM_AND_PNOR);
                break;
            }
        }

    } while(0);

    //
    // processor SBE -- ensure HWP doesn't return FAPI_RC_SUCCESS if the engine reported attn
    // 
    if (rc.ok() && is_processor && is_sbe && pore_sbe_state.reported_attn)
    {
        FAPI_ERR("proc_extract_sbe_rc: SBE reported attention, but proc_extract_sbe_rc tried to return SUCCESS!");
        FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_CODE_BUG);
    }

    //
    // all engine types -- append engine specific base FFDC to any non-zero return code
    // 

    if (!rc.ok())
    {
        FAPI_ADD_INFO_TO_HWP_ERROR(rc, RC_PROC_EXTRACT_PORE_BASE_FFDC);
    }

    FAPI_INF("proc_extract_sbe_rc: End");
    return rc;
}


} // extern "C"
