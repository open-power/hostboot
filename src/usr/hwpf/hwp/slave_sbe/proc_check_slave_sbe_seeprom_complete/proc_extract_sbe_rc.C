/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_sbe_rc.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_extract_sbe_rc.C,v 1.9 2013/11/05 22:16:08 jeshua Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_extract_sbe_rc.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_extract_sbe_rc.C
// *! DESCRIPTION : Create a return code for an SBE error
// *!
// *! OWNER NAME  : Jeshua Smith            Email: jeshua@us.ibm.com
// *!
// *! Overview:
// *!    - Check that it was a halt at magic instruction
// *!    - Get the failing PC
// *!    - If secure, look up PC in image pointer
// *!    - If not secure, look the PC up in the SBE (SEEPROM/PIBMEM/OTPROM)
// *!    - Extract the error code at that PC
// *!    - Return the RC for that error
// *!    
// *! Assumption: The SBE is stopped at a "invalid instruction" error
// *!             and the instruction was 'halt'
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_extract_sbe_rc.H>
#include <p8_scom_addresses.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
//Address masks
const uint64_t SBE_ADDR_MASK               = 0x0000FFFFFFFFFFFFull;
const uint64_t FOURBYTE_ALIGNMENT_MASK     = 0x0000000000000003ull;
const uint64_t INTERNAL_ADDR_MASK          = 0x000000007FFFFFFFull;
const uint64_t ADDR_TYPE_MASK              = 0x0000FFFF80000000ull;
const uint64_t OTPROM_ADDR_TYPE            = 0x0000000100000000ull;
const uint64_t PIBMEM_ADDR_TYPE            = 0x0000000800000000ull;
const uint64_t SEEPROM_ADDR_TYPE           = 0x0000800C80000000ull;
const uint32_t ALIGN_FOUR_BYTE             = 0xFFFFFFFC;
//Scom register offsets
const uint32_t STATUS_OFFSET_0x00          = 0x00000000;
const uint32_t IBUF_OFFSET_0x0D            = 0x0000000D;
const uint32_t DEBUG0_OFFSET_0x0F          = 0x0000000F;
const uint32_t DEBUG1_OFFSET_0x10          = 0x00000010;
//Halt types
const uint32_t HALT_WITH_ERROR_INSTRUCTION = (('h' << 24) | ('a' << 16) | ('l' << 8) | ('t'));

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{

//------------------------------------------------------------------------------
// subroutine:
//      Reads the word at the given address in SEEPROM pointer
//
// parameters: i_target   => Target of chip with failed SBE
//             i_pSEEPROM => pointer to a memory-mapped SEEPROM image
//             i_address  => The SEEPROM address to read
//             o_data     => A uint32_t to put the data into 
//
// returns: fapi::ReturnCode with the error, or fapi::FAPI_RC_SUCCESS
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_extract_sbe_rc_read_SEEPROM(const fapi::Target & i_target,
                                                      const void         * i_pSEEPROM,
                                                      const uint32_t       i_address,
                                                      uint32_t           & o_data)
    {
        // return codes
        fapi::ReturnCode rc;

        do
        {
            if (i_pSEEPROM==NULL)
            {
                FAPI_ERR("Need to extract SEEPROM address 0x%08X but pointer to SEEPROM is NULL", i_address);
                const fapi::Target & CHIP_IN_ERROR = i_target;
                const uint32_t & ADDRESS = i_address;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_IMAGE_POINTER_NULL);
            }
            else
            {
                uint8_t * p_errorCode = (uint8_t *)i_pSEEPROM + (i_address & ALIGN_FOUR_BYTE);

                //Copy the data out of the image pointer
                o_data =
                    (p_errorCode[0] << 3*8) |
                    (p_errorCode[1] << 2*8) |
                    (p_errorCode[2] << 1*8) |
                    (p_errorCode[3]);
                rc = fapi::FAPI_RC_SUCCESS;
            }
        } while(0);
        return rc;
    }

//------------------------------------------------------------------------------
// subroutine:
//      Returns the PC of the given engine
//
// parameters: i_target   => Target of chip with failed SBE
//             i_engine   => The type of engine that failed (SBE/SLW)
//             o_pc       => Referenece to the uint64_t containing the PC
//
// returns: fapi::ReturnCode with the error, or fapi::FAPI_RC_SUCCESS
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_extract_sbe_rc_get_pc(const fapi::Target & i_target,
                                                por_engine_t         i_engine,
                                                uint64_t           & o_pc)
    {
        // return codes
        fapi::ReturnCode rc;

        // data buffer to hold register values
        ecmdDataBufferBase data(64);

        do
        {
            //////////////////////////////////////////
            //Get the PC from the status register
            //////////////////////////////////////////
            rc = fapiGetScom(i_target, i_engine + STATUS_OFFSET_0x00, data);
            if (rc)
            {
                FAPI_ERR("Error reading SBE status reg (0x%08X)", i_engine + STATUS_OFFSET_0x00);
                break;
            }
            o_pc = (data.getDoubleWord(0) & SBE_ADDR_MASK);

            if (o_pc & FOURBYTE_ALIGNMENT_MASK)
            {
                FAPI_ERR("Address isn't 4-byte aligned");
                const fapi::Target & CHIP_IN_ERROR = i_target;
                uint64_t & SBE_ADDRESS = o_pc;
                if (i_engine == SBE)
                {
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
// parameters: i_target   => Target of chip with failed SBE
//             i_pSEEPROM => pointer to a memory-mapped SEEPROM image
//             i_engine   => The type of engine that failed (SBE/SLW)
//
// returns: fapi::ReturnCode with the error
//          This procedure will NEVER return SUCCESS
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_extract_sbe_rc_from_address(const fapi::Target & i_target,
                                                      const void         * i_pSEEPROM,
                                                      por_engine_t         i_engine)
    {
        // return codes
        fapi::ReturnCode rc;

        // data buffer to hold register values
        ecmdDataBufferBase data(64);
        uint64_t address_64;

        do
        {
            rc = proc_extract_sbe_rc_get_pc(i_target,i_engine,address_64);
            if (rc)
                break;

            uint32_t error_code = 0;
            //Add 4 because address_64 is pointing at the halt instruction
            uint32_t internal_address = (uint32_t)(address_64 & INTERNAL_ADDR_MASK) + 4;

            if ((address_64 & ADDR_TYPE_MASK) == SEEPROM_ADDR_TYPE)
            {
                //////////////////////////////////////////
                //Get the error code from that location in the SEEPROM
                //////////////////////////////////////////
                FAPI_DBG("Extracting the error code from address "
                         "0x%X in the SEEPROM", internal_address);

                rc = proc_extract_sbe_rc_read_SEEPROM(i_target, i_pSEEPROM, internal_address, error_code);
                if (rc)
                {
                    FAPI_ERR("Error reading SEEPROM address 0x%08X", internal_address);
                    break;
                }
            }
            else
            if ((address_64 & ADDR_TYPE_MASK) == PIBMEM_ADDR_TYPE)
            {
                //////////////////////////////////////////
                //Get the error code from that location in the PIBMEM
                //////////////////////////////////////////
                FAPI_DBG("Extracting the error code from address "
                         "0x%X in the PIBMEM", internal_address);

                rc = fapiGetScom(i_target, PIBMEM0_0x00080000 + (internal_address >>3), data);
                if (rc)
                {
                    FAPI_ERR("Error reading PIBMEM (scom address 0x%08X)", (uint32_t)PIBMEM0_0x00080000 + (internal_address >>3));
                    break;
                }
                error_code = data.getWord((internal_address & 0x04)?1:0);
            }
            else
            {
                FAPI_ERR("Address (0x%012llX) isn't in a known memory", address_64);
                const fapi::Target & CHIP_IN_ERROR = i_target;
                uint64_t & SBE_ADDRESS = address_64;
                if (i_engine == SBE)
                {
                    FAPI_SET_HWP_ERROR(rc,
                                       RC_PROC_EXTRACT_SBE_RC_ADDR_NOT_RECOGNIZED_SBE);
                }
                else
                {
                    FAPI_SET_HWP_ERROR(rc,
                                       RC_PROC_EXTRACT_SBE_RC_ADDR_NOT_RECOGNIZED_SLW);
                }
                break;
            }

            //////////////////////////////////////////
            //Look up that error code
            //////////////////////////////////////////
            FAPI_ERR("SBE got error code 0x%06X", error_code);
            const fapi::Target & CHIP_IN_ERROR = i_target;
            FAPI_SET_SBE_ERROR(rc, error_code);
        } while(0);

        //Make sure the code doesn't return SUCCESS
        if (rc.ok())
        {
            FAPI_ERR("proc_extract_sbe_rc_from_addr tried to return SUCCESS,"
                " which should be impossible. Must be a code bug.");
            const fapi::Target & CHIP_IN_ERROR = i_target;
            uint64_t & SBE_ADDRESS = address_64;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_FROM_ADDR_CODE_BUG);
        }
        return rc;
    }

//------------------------------------------------------------------------------
// function:
//      Return an RC indicating the SBE error
//
// parameters: i_target   => Target of chip with failed SBE
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

        FAPI_INF("Processing SBE error");

        do
        {
            //JDS TODO - print out the istep name based on SBE_VITAL

            if ((i_engine != SBE) &&
                (i_engine != SLW))
            {
                FAPI_ERR("Unknow engine type %i", i_engine);
                const por_engine_t ENGINE = i_engine;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_UNKNOWN_ENGINE);
                break;
            }

            //JDS TODO - split out the generic error into more granular errors?
            bool generic_hw_error = false;
            //////////////////////////////////////////
            // Check for SBE error bits
            //////////////////////////////////////////
            rc = fapiGetScom(i_target, i_engine + DEBUG1_OFFSET_0x10, data);
            if (rc)
            {
                FAPI_ERR("Error reading SBE debug1 reg (0x%08X)", i_engine + DEBUG1_OFFSET_0x10);
                break;
            }
            if (data.isBitSet(48))
            {
                FAPI_ERR("OCI_DATA_READ_P_ERR - Parity error in read data from OCI");
                generic_hw_error=true;
            }
            if (data.isBitSet(52))
            {
                FAPI_ERR("BAD_PAR - bad instruction parity");
                generic_hw_error=true;
            }
            if (data.isBitSet(53))
            {
                //////////////////////////////////////////
                //Check if the SBE stopped at a code detected error
                // (a 'halt' instruction, which is an invalid instruction)
                //////////////////////////////////////////
                rc = fapiGetScom(i_target, i_engine + IBUF_OFFSET_0x0D, data);
                if (rc)
                {
                    FAPI_ERR("SBE reported an invalid instruction error, but got a scom error reading SBE instruction buffer reg (0x%08X) to determine if it was a code-detected error or not", i_engine + IBUF_OFFSET_0x0D);
                    break;
                }

                const uint32_t instruction = data.getWord(0);
                if (instruction == HALT_WITH_ERROR_INSTRUCTION)
                {
                    rc = proc_extract_sbe_rc_from_address(i_target, i_pSEEPROM, i_engine);
                    break;
                }
                else
                {
                    FAPI_ERR("BAD_INSTRUCTION - invalid instruction");
                    generic_hw_error=true;
                }
            }
            if (data.isBitSet(54))
            {
                FAPI_ERR("BAD_PC - PC overflow/underflow");
                generic_hw_error=true;
            }
            if (data.isBitSet(55))
            {
                FAPI_ERR("SCAN_DATA_CRC - Scan data CRC error");
                generic_hw_error=true;
            }
            if (data.isBitSet(56))
            {
                FAPI_ERR("PC_STACK_ERR - PC stack PUSH error or POP error");
                generic_hw_error=true;
            }
            if (data.isBitSet(57))
            {
                FAPI_ERR("INSTR_FETCH_ERROR - Non-zero return code or read data parity error was received when during fetch  - phase");
                generic_hw_error=true;
            }
            if (data.isBitSet(58))
            {
                FAPI_ERR("BAD_OPERAND - Invalid Instruction Operand");
                generic_hw_error=true;
            }
            if (data.isBitSet(59))
            {
                FAPI_ERR("BAD_INSTRUCTION_PATH - Invalid Instruction Path (e.g. FI2C parameter miss)");
                generic_hw_error=true;
            }
            if (data.isBitSet(60))
            {
                FAPI_ERR("BAD_START_VECTOR_TRIGGER - Invalid Start Vector triggered");
                generic_hw_error=true;
            }
            if (data.isBitSet(61))
            {
                FAPI_ERR("FI2C_PROTOCOL_HANG - Fast I2C protocol hang detected - exceeded poll limit for FI2C engine");
                generic_hw_error=true;
            }
            rc = fapiGetScom(i_target, i_engine + DEBUG0_OFFSET_0x0F, data);
            if (rc)
            {
                FAPI_ERR("Error reading SBE debug0 reg (0x%08X)", i_engine + DEBUG0_OFFSET_0x0F);
                break;
            }
            uint8_t pcb_error = data.getByte(4) >> 4;
            if (pcb_error)
            {
                uint32_t scom_address = data.getWord(0);
                FAPI_ERR("SBE got PCB error %i accessing scom address 0x%08X", pcb_error, scom_address);
                generic_hw_error=true;
            }
            if (data.isBitSet(36))
            {
                FAPI_ERR("I2C_BAD_STATUS_0 - I2CM internal errors including parity errors");
                generic_hw_error=true;
            }
            if (data.isBitSet(37))
            {
                FAPI_ERR("I2C_BAD_STATUS_1 - bad PIB response code error for ECCAX to I2CM communication");
                generic_hw_error=true;
            }
            if (data.isBitSet(38))
            {
                FAPI_ERR("I2C_BAD_STATUS_2 - ECCAX internal errors (UCE or PIB master resets)");
                generic_hw_error=true;
            }
            if (data.isBitSet(39))
            {
                FAPI_ERR("I2C_BAD_STATUS_3 - I2C bus issues (I2C bus busy, NACK, stop bit error)");
                generic_hw_error=true;
            }
            if (data.isBitSet(40))
            {
                FAPI_ERR("GROUP_PARITY_ERROR_0 - parity error from debug or status or error mask or pc stack regs");
                generic_hw_error=true;
            }
            if (data.isBitSet(41))
            {
                FAPI_ERR("GROUP_PARITY_ERROR_1 - parity error from control or exe trigger or exe t_mask or i2c param regs");
                generic_hw_error=true;
            }
            if (data.isBitSet(42))
            {
                FAPI_ERR("GROUP_PARITY_ERROR_2 - parity error from perv/oci base addr or table base addr or memory reloc");
                generic_hw_error=true;
            }
            if (data.isBitSet(43))
            {
                FAPI_ERR("GROUP_PARITY_ERROR_3 - parity error from scr0 or scr1 or scr2 or data scr0 reg");
                generic_hw_error=true;
            }
            if (data.isBitSet(44))
            {
                FAPI_ERR("GROUP_PARITY_ERROR_4 - parity error from ibuf regs");
                generic_hw_error=true;
            }
            if (generic_hw_error)
            {
                const fapi::Target & CHIP_IN_ERROR = i_target;
                if(i_engine == SBE)
                {
                    FAPI_SET_HWP_ERROR(rc,RC_PROC_EXTRACT_SBE_RC_GENERIC_SBE_HW_ERROR);
                    break;
                }
                else
                {
                    FAPI_SET_HWP_ERROR(rc,RC_PROC_EXTRACT_SBE_RC_GENERIC_SLW_HW_ERROR);
                    break;
                }
            }
                    

            //No error bits are set, so perhaps it was a real halt (ie. wait 0) instruction in OTPROM
            uint64_t pc = 0;
            rc = proc_extract_sbe_rc_get_pc(i_target, i_engine, pc);
            if (rc)
                break;

            if ((pc & ADDR_TYPE_MASK) == OTPROM_ADDR_TYPE)
            {
                //Note: OTPROM halts are actual halt instructions, which means the
                // SBE updated the PC before the halt.
                // Thus we have to subtract 4 to get back to the address of the halt
                uint32_t internal_address = (uint32_t)(pc & INTERNAL_ADDR_MASK) - 4;

                //////////////////////////////////////////
                //Map the OTPROM address to the known error at that location
                //The OTPROM is write-once at mfg, so addresses should remain fixed
                //////////////////////////////////////////
                FAPI_DBG("Determining the OTPROM error based on the address "
                         "0x%X", internal_address);
                const fapi::Target & CHIP_IN_ERROR = i_target;
                switch(internal_address)
                {
                case (0x400fc): //Original OTPROM
                case (0x40118): //Updated OTPROM
                    FAPI_ERR("Chip not identified as Murano or Venice");
                    FAPI_SET_HWP_ERROR(rc,RC_PROC_EXTRACT_SBE_RC_BAD_CHIP_TYPE);
                    break;
                case (0x401c0):
                    FAPI_ERR("SEEPROM magic number didn't match \"XIP SEPM\"");
                    FAPI_SET_HWP_ERROR(rc,RC_PROC_EXTRACT_SBE_RC_SEEPROM_MAGIC_NUMBER_MISMATCH);
                    break;
                case (0x401ec):
                    FAPI_ERR("Branch to SEEPROM didn't happen");
                    FAPI_SET_HWP_ERROR(rc,RC_PROC_EXTRACT_SBE_RC_BRANCH_TO_SEEPROM_FAIL);
                    break;
                default:
                    FAPI_ERR("Halted in OTPROM, but not at an expected halt location");
                    FAPI_SET_HWP_ERROR(rc,RC_PROC_EXTRACT_SBE_RC_UNEXPECTED_OTPROM_HALT);
                    break;
                }                    
                break;
            }
            else if (((pc & SBE_ADDR_MASK) == 0x0000800000000000ull) ||
                     ((pc & SBE_ADDR_MASK) == 0x0000000000000000ull))
            {
                //PC is all zeros, which means SBE was probably never started
                FAPI_ERR("PC is all zeros, which means SBE was probably never started");
                const fapi::Target & CHIP_IN_ERROR = i_target;
                if(i_engine == SBE)
                {
                    FAPI_SET_HWP_ERROR(rc,RC_PROC_EXTRACT_SBE_RC_SBE_NEVER_STARTED);
                    break;
                }
                else
                {
                    FAPI_SET_HWP_ERROR(rc,RC_PROC_EXTRACT_SBE_RC_SLW_NEVER_STARTED);
                    break;
                }
            }

        } while(0);

        //Make sure the code doesn't return SUCCESS
        if (rc.ok())
        {
            FAPI_ERR("proc_extract_sbe_rc tried to return SUCCESS,"
                " which should be impossible. Must be a code bug.");
            const fapi::Target & CHIP_IN_ERROR = i_target;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_CODE_BUG);
        }
        return rc;
    }

} // extern "C"
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
