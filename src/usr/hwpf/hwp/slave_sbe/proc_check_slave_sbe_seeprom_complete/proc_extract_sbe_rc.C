/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_sbe_rc.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: proc_extract_sbe_rc.C,v 1.3 2012/10/29 22:06:08 jeshua Exp $
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
// *!    - Get the failing PC
// *!    - Look the PC up in the SBE (SEEPROM/PIBMEM/OTPROM)
// *!    - Extract the error code at that PC
// *!    - Pass the error code to proc_sbe_error to create the RC
// *!    - Return the RC
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_extract_sbe_rc.H"
#include "proc_sbe_error.H"
#include "p8_scom_addresses.H"
#include "proc_read_seeprom.H"
//JDS TODO - uncomment once proc_read_pibmem and proc_read_otprom are available
// #include "proc_read_pibmem.H"
// #include "proc_read_otprom.H"

//------------------------------------------------------------------------------
// Constant definitions
// JDS TODO -confirm these address type values for OTPROM and PIBMEM
//------------------------------------------------------------------------------
const uint64_t SEEPROM_ADDR_MASK          = 0x0000FFFFFFFFFFFFull;
const uint64_t FOURBYTE_ALIGNMENT_MASK    = 0x0000000000000003ull;
const uint64_t ADDR_TYPE_MASK             = 0x0000FFFF80000000ull;
const uint64_t OTPROM_ADDR_TYPE           = 0x0000800180000000ull;
const uint64_t PIBMEM_ADDR_TYPE           = 0x0000800800000000ull;
const uint64_t SEEPROM_ADDR_TYPE          = 0x0000800C80000000ull;
const uint64_t INTERNAL_ADDR_MASK         = 0x000000007FFFFFFFull;
const uint32_t SBE_IMAGE_SELECT_BIT       = 8;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{


//------------------------------------------------------------------------------
// function:
//      Get the failing PC, and extract the RC stored at that PC
//
// parameters: i_target  => Target of chip with failed SBE
//
// returns: fapi::ReturnCode with the error
//          This procedure will NEVER return SUCCESS
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_extract_sbe_rc(const fapi::Target & i_target)
    {
        // return codes
        fapi::ReturnCode rc;

        // data buffer to hold register values
        ecmdDataBufferBase data(64);

        // Address of the error in the SBE image
        uint64_t address_64 = 0;
        uint32_t address = 0;

        FAPI_INF("Processing SBE error\n");

        do
        {
            //////////////////////////////////////////
            //Get the PC from the SBE status register
            //////////////////////////////////////////
            rc = fapiGetScom(i_target, PORE_SBE_STATUS_0x000E0000, data);
            if(rc)
            {
                FAPI_ERR("Error reading SBE status reg\n");
                break;
            }
            address_64 = data.getDoubleWord(0) & SEEPROM_ADDR_MASK;
            if(address_64 & FOURBYTE_ALIGNMENT_MASK)
            {
                FAPI_ERR("Address isn't 4-byte aligned");
                const fapi::Target & CHIP_IN_ERROR = i_target;
                uint64_t & SBE_ADDRESS = address_64;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_ADDR_UNALIGNED);
                break;
            }

            uint64_t error_code_64 = 0;
            address = (uint32_t)(address_64 & INTERNAL_ADDR_MASK);

            //Get the SEEPROM portion of the address
            if((address_64 & ADDR_TYPE_MASK) == SEEPROM_ADDR_TYPE)
            {
                //////////////////////////////////////////
                //Get the error code from that location in the SEEPROM
                //////////////////////////////////////////
                FAPI_DBG("Extracting the error code from address "
                         "0x%X in the SEEPROM", address);
            //JDS TODO - should this use a different method to read the seeprom?
                uint32_t i_start_addr = (address & 0xFFFFFFF8);
                uint32_t i_length = 8;
                //JDS TODO - figure out how to get ECC enable status
                bool i_ecc_disable = true;
                bool i_use_secondary = false;

                rc = fapiGetCfamRegister(i_target,
                                         CFAM_FSI_SBE_VITAL_0x0000281C, data);
                if(rc)
                {
                    FAPI_ERR("Error reading SBE Vital to determine SEEPROM\n");
                    break;
                }
                if( data.isBitSet( SBE_IMAGE_SELECT_BIT ) )
                {
                    i_use_secondary = true;
                }

                FAPI_PLAT_EXEC_HWP(rc, proc_read_seeprom, i_target,
                                   i_start_addr, i_length,
                                   i_ecc_disable, &error_code_64,
                                   i_use_secondary);
                if(rc)
                {
                    FAPI_ERR("Error reading SEEPROM");
                    break;
                }
                FAPI_DBG("Read 0x%016llX out of SEEPROM address 0x%08X\n", error_code_64, i_start_addr);
            }
            //JDS TODO - uncomment once proc_read_pibmem and proc_read_otprom are available
//             else
//             //Get the PIBMEM portion of the address
//             if((address_64 & ADDR_TYPE_MASK) == PIBMEM_ADDR_TYPE)
//             {
//                 //////////////////////////////////////////
//                 //Get the error code from that location in the PIBMEM
//                 //////////////////////////////////////////
//                 FAPI_DBG("Extracting the error code from address "
//                          "0x%X in the PIBMEM", address);
//             //JDS TODO - should this use a different method to read the pibmem?
//                 uint32_t i_start_addr = (address & 0xFFFFFFF8);
//                 uint32_t i_length = 8;
//                 //JDS TODO - figure out how to get ECC status
//                 bool i_ecc_disable = false;
//                 FAPI_PLAT_EXEC_HWP(rc, proc_read_pibmem, i_target,
//                                    i_start_addr, i_length,
//                                    i_ecc_disable, &error_code_64);
//                 if(rc)
//                 {
//                     FAPI_ERR("Error reading PIBMEM");
//                     break;
//                 }
//             }
//             else
//             //Get the OTPROM portion of the address
//             if((address_64 & ADDR_TYPE_MASK) == OTPROM_ADDR_TYPE)
//             {
//                 //////////////////////////////////////////
//                 //Get the error code from that location in the OTPROM
//                 //////////////////////////////////////////
//                 FAPI_DBG("Extracting the error code from address "
//                          "0x%X in the OTPROM", address);
//             //JDS TODO - should this use a different method to read the otprom?
//                 uint32_t i_start_addr = (address & 0xFFFFFFF8);
//                 uint32_t i_length = 8;
//                 //JDS TODO - figure out how to get ECC status
//                 bool i_ecc_disable = false;
//                 FAPI_PLAT_EXEC_HWP(rc, proc_read_otprom, i_target,
//                                    i_start_addr, i_length,
//                                    i_ecc_disable, &error_code_64);
//                 if(rc)
//                 {
//                     FAPI_ERR("Error reading OTPROM");
//                     break;
//                 }
//             }
            else
            {
                FAPI_ERR("Address isn't in a known memory");
                const fapi::Target & CHIP_IN_ERROR = i_target;
                uint64_t & SBE_ADDRESS = address_64;
                FAPI_SET_HWP_ERROR(rc,
                                   RC_PROC_EXTRACT_SBE_RC_ADDR_NOT_RECOGNIZED);
                break;
            }


            //Get the error code from the correct word
            uint32_t error_code = (address & 0x04ull) ?
                (uint32_t)( error_code_64 & 0x00000000FFFFFFFFull):
                (uint32_t)((error_code_64 & 0xFFFFFFFF00000000ull) >> 32);

            //////////////////////////////////////////
            //Look up that error code
            // JDS TODO - replace this with the official FAPI call
            //            once it exists
            //////////////////////////////////////////
            FAPI_PLAT_EXEC_HWP(rc, proc_sbe_error, i_target, error_code);
        } while(0);

        //Make sure the code doesn't return SUCCESS
        if( rc.ok() )
        {
            FAPI_ERR("proc_extract_sbe_rc tried to return SUCCESS,"
                " which should be impossible. Must be a code bug.");
            const fapi::Target & CHIP_IN_ERROR = i_target;
            uint64_t & SBE_ADDRESS = address_64;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_SBE_RC_CODE_BUG);
        }
        return rc;
    }

} // extern "C"
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
