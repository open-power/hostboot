/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_extract_sbe_rc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
//------------------------------------------------------------------------------
/// @file  p9_extract_sbe_rc.C
///
/// @brief Check for errors on the SBE, OTPROM, PIBMEM & SEEPROM
/// Level 1 :
///     1) Read the value of DBGPRO 0xE0005 & Store IAR
///     2) Identify if PPE is halted from XSR Bit0, Continue only if halted
///     3) If Halted, Check for Halt Conditions(HC) i.e XSR (1:3)
///     4) If HC is all Zero report error else Print the Halt condition reported
///     5) Print info of XSR bits 7,8,12,13,14,21,28 if TRUE
///     6) Read the value of XIRAMEDR 0xE0004 & Store IR and EDR
///     7) Check for Machine Check State(MCS) i.e XSR (29:31)
///     8) if MCS=0x4, Report error as Program Interrupt for the address stored in EDR
///         Look for IAR range and report specific memory program error
///     9) if MCS=0x1, 0x2, 0x3, Set the flag as Data Machine Check - l_data_mchk
/// Level 2 :
///     1) Based on IAR value identifying the Memory Address range
///        OTPROM (0x000C0000  to 0x000C0378)
///        PIBMEM (0xFFFE8000  to 0xFFFFFFFF)
///        SEEPROM(0x80000000  to 0x80038E18)
///     2) If IAR value is out of above address scope, report error
/// Level 3 :
///     1)   If in OTPROM address range, Collect OTPROM Status 0x00010002
///     1.1) Print info of error report bits if they are true (0,1,2,3,4,5,45,46)
///     1.2) Map the OTPROM address to the known error at that location
///     1.3) Report Error if ECC errors are detected in OTPROM
///     2)   If in PIBMEM address range, Collect PIBMEM status 0x00088005
///     2.1) Print info of error report bits in status if they are true (0,1,2,3,4,5,6,7,19,20,21,22,23,24,25,26)
///     2.2) Report Error if ECC errors are detected in PIBMEM
///     3)   If in SEEPROM address range, Collect FI2CM Mode 0x000A0006, status 0x000A0002 & MIB Info 0xE0007
///     3.1) Print info of error report bits in status if they are true (0,1,2,3,4,5,41,42,43,45,46,47,48,49,50,53)
///     3.2) Report Error if Mode reg I2C bit rate divisor (0:15) is < 0x0003
///     3.3) Report Error for FI2C errors
///     3.4) Report Error if ECC errors are detected in SEEPROM
///     3.5) Report Error if Mib Error rsp is non Zero (0x7-FI2C timeout Error, 0x4-FI2C Seeprom cfg Err, else-FI2C PIB Err)
/// Level 4 :
///     1) If Data Machine Check error is true then look for the edr data range in SEEPROM/PIBMEM/OTPROM scope
///     2) Collect the SIB Info from 0xE0006
///     3) If in OTPROM data range report error if RSP_INFO is non-Zero response (0x6-Ecc Error, 0x7-PIB timeout Error, else-Scom Err)
///     3) If in PIBMEM data range, read MEM_Info (E0007) and report error if RSP_INFO is non-Zero response (0x6-Ecc Error, else-Scom Err)
///     4) If in SEEPROM data range, report error if RSP_INFO is non-zero response (0x7-FI2C timeout Error, 0x4-FI2C Seeprom cfg Err, else-FI2C PIB Err)
///
///     DEFAULT) If non of the above errors are detected then report as UNKNOWN_ERROR
//------------------------------------------------------------------------------
// *HWP HW Owner        : Soma BhanuTej <soma.bhanu@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Sunil Kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : FSP:HB
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_extract_sbe_rc.H"

#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_perv_scom_addresses_fixes.H>
#include <p9_perv_scom_addresses_fld_fixes.H>


fapi2::ReturnCode p9_extract_sbe_rc(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
                                    P9_EXTRACT_SBE_RC::RETURN_ACTION& o_return_action, bool i_set_sdb, bool i_unsecure_mode)
{

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_data64_dbgpro;
    fapi2::buffer<uint64_t> l_data64_fi2c_status;
    fapi2::buffer<uint64_t> l_data64_mib_mem_info;
    fapi2::buffer<uint64_t> l_data64_mib_sib_info;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint32_t> l_data32_ir;
    fapi2::buffer<uint32_t> l_data32_edr;
    fapi2::buffer<uint32_t> l_data32_iar;
    bool l_ppe_halt_state = true;
    bool l_data_mchk = false;
    bool otprom_addr_range = false;
    bool pibmem_addr_range = false;
    bool seeprom_addr_range = false;
    bool otprom_data_range = false;
    bool pibmem_data_range = false;
    bool seeprom_data_range = false;
    uint32_t HC, MCS, otprom_addr, mem_error, sib_rsp_info;

    // FAPI_ASSERT condition constant
    const bool FAIL = false;
    // Address Range constants
    const uint32_t OTPROM_MIN_RANGE  = 0x000C0000;
    const uint32_t OTPROM_MAX_RANGE  = 0x000C0378;
    const uint32_t PIBMEM_MIN_RANGE  = 0xFFFE8000;
    const uint32_t PIBMEM_MAX_RANGE  = 0xFFFFFFFF;
    const uint32_t SEEPROM_MIN_RANGE = 0x80000000;
    const uint32_t SEEPROM_MAX_RANGE = 0x80038E18;

    // OTPROM Address constants as per the image on 28/Sep/2016
    // These values might change on every recomilation of OTPROM binary
    // Refs : /afs/apd/func/project/tools/cronus/p9/exe/dev/prcd_d/images/sbe_otprom.dis
    const uint32_t MAGIC_NUMBER_MISMATCH_LOCATION = 0xC0188;
    const uint32_t OTPROM_IMAGE_END_LOCATION      = 0xC016C;

    FAPI_INF("p9_extract_sbe_rc : Entering ...");

    if(i_set_sdb)
    {
        // Applying SDB setting
        FAPI_DBG("p9_extract_sbe_rc: Setting chip in SDB mode");
        FAPI_TRY(getCfamRegister(i_target_chip, PERV_SB_CS_FSI, l_data32));
        l_data32.setBit<PERV_SB_CS_SECURE_DEBUG_MODE>();
        FAPI_TRY(putCfamRegister(i_target_chip, PERV_SB_CS_FSI, l_data32));
    }

    // XSR and IAR
    FAPI_DBG("p9_extract_sbe_rc : Reading PPE_XIDBGPRO");
    FAPI_TRY(getScom(i_target_chip, PU_PPE_XIDBGPRO, l_data64_dbgpro));
    l_data64_dbgpro.extractToRight(l_data32_iar, PU_PPE_XIDBGPRO_IAR,
                                   (PU_PPE_XIDBGPRO_IAR_LEN + 2)); //To get 32 bits of address
    FAPI_DBG("p9_extract_sbe_rc : PPE_XIDBGPRO : %#018lX", l_data64_dbgpro);
    FAPI_DBG("p9_extract_sbe_rc : SBE IAR : %#08lX", l_data32_iar);

    if (l_data64_dbgpro.getBit<PU_PPE_XIDBGPRO_XSR_HS>())
    {
        FAPI_INF("p9_extract_sbe_rc : PPE is in HALT state");
        l_ppe_halt_state  = true;
    }
    else
    {
        FAPI_INF("p9_extract_sbe_rc : PPE is in RUNNING state, likely infinite loop, recommending restart");
        l_ppe_halt_state  = false;
        o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
        FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_RUNNING()
                    .set_TARGET_CHIP(i_target_chip), "SBE is in running state");
    }

    if(l_ppe_halt_state)
    {
        // ------- LEVEL 1 ------ //

        //Extract HC
        l_data32.flush<0>();
        l_data64_dbgpro.extractToRight(l_data32, PU_PPE_XIDBGPRO_XSR_HC, PU_PPE_XIDBGPRO_XSR_HC_LEN);
        HC = l_data32;

        switch(HC)
        {
            case 0x0 :
                o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_NEVER_STARTED()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Halt Condition is all Zero, SBE engine was probably never started");
                break;

            case 0x1 :
                FAPI_ERR("p9_extract_sbe_rc : XCR[CMD] written 111 to force-halt the processor.");
                break;

            case 0x2 :
                FAPI_ERR("p9_extract_sbe_rc : A second watchdog timer (WDT) event occurred while TCR[WRC]=11");
                break;

            case 0x3 :
                FAPI_ERR("p9_extract_sbe_rc : Unmaskable interrupt halt");
                break;

            case 0x4 :
                FAPI_ERR("p9_extract_sbe_rc : Debug halt");
                break;

            case 0x5 :
                FAPI_ERR("p9_extract_sbe_rc : DBCR halt");
                break;

            case 0x6 :
                FAPI_ERR("p9_extract_sbe_rc : The external halt_req input was active.");
                break;

            case 0x7 :
                FAPI_ERR("p9_extract_sbe_rc : Hardware failure");
                break;

            default :
                FAPI_ERR("p9_extract_sbe_rc : INVALID HALT CONDITION HC=0x%x", HC);
                break;
        }

        //Extract TRAP
        if(l_data64_dbgpro.getBit<PU_PPE_XIDBGPRO_XSR_TRAP>())
        {
            FAPI_DBG("p9_extract_sbe_rc : TRAP Instruction Debug Event Occured");
        }

        //Extract IAC
        if(l_data64_dbgpro.getBit<PU_PPE_XIDBGPRO_XSR_IAC>())
        {
            FAPI_DBG("p9_extract_sbe_rc : Instruction Address Compare Debug Event Occured");
        }

        //Extract DACR
        if(l_data64_dbgpro.getBit<PU_PPE_XIDBGPRO_XSR_DACR>())
        {
            FAPI_DBG("p9_extract_sbe_rc : Data Address Compare (Read) Debug Event Occured");
        }

        //Extract DACW
        if(l_data64_dbgpro.getBit<PU_PPE_XIDBGPRO_XSR_DACW>())
        {
            FAPI_DBG("p9_extract_sbe_rc : Data Address Compare (Write) Debug Event Occured");
        }

        //Extract WS
        if(l_data64_dbgpro.getBit<PU_PPE_XIDBGPRO_NULL_MSR_WE>())
        {
            FAPI_DBG("p9_extract_sbe_rc : In WAIT STATE");
        }

        //Extract EP
        if(l_data64_dbgpro.getBit<PU_PPE_XIDBGPRO_XSR_EP>())
        {
            FAPI_DBG("p9_extract_sbe_rc : Maskable Event Pending");
        }

        //Extract MFE
        if(l_data64_dbgpro.getBit<PU_PPE_XIDBGPRO_XSR_MFE>())
        {
            FAPI_ERR("p9_extract_sbe_rc : Multiple Fault Error Occured");
        }

        //Extract MCS
        l_data32.flush<0>();
        l_data64_dbgpro.extractToRight(l_data32, PU_PPE_XIDBGPRO_XSR_MCS, PU_PPE_XIDBGPRO_XSR_MCS_LEN);
        MCS = l_data32;

        // IR and EDR
        FAPI_DBG("p9_extract_sbe_rc : Reading PPE_XIRAMEDR");
        FAPI_TRY(getScom(i_target_chip, PU_PPE_XIRAMEDR, l_data64));
        l_data64.extractToRight(l_data32_ir, PU_PPE_XIRAMEDR_XIRAMGA_IR, PU_PPE_XIRAMEDR_XIRAMGA_IR_LEN);
        l_data64.extractToRight(l_data32_edr, PU_PPE_XIRAMEDR_EDR, PU_PPE_XIRAMEDR_EDR_LEN);

        if(MCS == 0x4)
        {
            if((OTPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= OTPROM_MAX_RANGE))
            {
                FAPI_DBG("p9_extract_sbe_rc : Program Interrupt occured in OTPROM memory program");
            }
            else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
            {
                FAPI_DBG("p9_extract_sbe_rc : Program Interrupt occured in PIBMEM memory program");
            }
            else if((SEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= SEEPROM_MAX_RANGE))
            {
                FAPI_DBG("p9_extract_sbe_rc : Program Interrupt occured in SEEPROM memory program");
            }
            else
            {
                FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Program Interrupt", l_data32_iar);
            }

            o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_PROGRAM_INTERRUPT()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Program interrupt promoted for Address=%08lX", l_data32_edr);
        }
        else
        {
            FAPI_DBG("p9_extract_sbe_rc : Data/Alignment/Data Machine check interrupt for Data=%08lX", l_data32_edr);

            switch (MCS)
            {
                case 0x0 :
                    FAPI_DBG("p9_extract_sbe_rc : Instruction machine check");
                    break;

                case 0x1 :
                    FAPI_DBG("p9_extract_sbe_rc : Data machine check - load");
                    l_data_mchk = true;
                    break;

                case 0x2 :
                    FAPI_DBG("p9_extract_sbe_rc : Data machine check - precise store");
                    l_data_mchk = true;
                    break;

                case 0x3 :
                    FAPI_DBG("p9_extract_sbe_rc : Data machine check - imprecise store");
                    l_data_mchk = true;
                    break;

                case 0x5 :
                    FAPI_DBG("p9_extract_sbe_rc : Instruction storage interrupt, promoted");
                    break;

                case 0x6 :
                    FAPI_DBG("p9_extract_sbe_rc : Alignment interrupt, promoted");
                    break;

                case 0x7 :
                    FAPI_DBG("p9_extract_sbe_rc : Data storage interrupt, promoted");
                    break;

                default :
                    FAPI_ERR("p9_extract_sbe_rc : INVALID Machine Check Status MCS=0x%x", MCS);
                    break;
            }
        }

        // ------- LEVEL 2 ------ //

        if((OTPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= OTPROM_MAX_RANGE))
        {
            FAPI_DBG("p9_extract_sbe_rc : IAR contains OTPROM address");
            otprom_addr_range = true;
        }
        else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
        {
            FAPI_DBG("p9_extract_sbe_rc : IAR contains PIBMEM address");
            pibmem_addr_range = true;
        }
        else if((SEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= SEEPROM_MAX_RANGE))
        {
            FAPI_DBG("p9_extract_sbe_rc : IAR contains SEEPROM address");
            seeprom_addr_range = true;
        }
        else
        {
            o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_ADDR_NOT_RECOGNIZED()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Address %08lX is out of range", l_data32_iar);
        }

        // ------- LEVEL 3 ------ //

        if(otprom_addr_range)
        {
            if(i_unsecure_mode)
            {
                FAPI_DBG("p9_extract_sbe_rc : Reading OTPROM status register");
                FAPI_TRY(getScom(i_target_chip, PU_STATUS_REGISTER, l_data64));
                FAPI_DBG("p9_extract_sbe_rc : OTPROM status : %#018lX", l_data64);

                if(l_data64.getBit<PU_STATUS_REGISTER_ADDR_NVLD>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : OTPROM::Address invalid bit set");
                }

                if(l_data64.getBit<PU_STATUS_REGISTER_WRITE_NVLD>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : OTPROM::Write invalid bit set");
                }

                if(l_data64.getBit<PU_STATUS_REGISTER_READ_NVLD>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : OTPROM::Read invalid bit set");
                }

                if(l_data64.getBit<PU_STATUS_REGISTER_INVLD_CMD_ERR>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : OTPROM::Invalid command register fields programmed bit set");
                }

                if(l_data64.getBit<PU_STATUS_REGISTER_CORR_ERR>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : OTPROM::Correctable error bit set");
                }

                if(l_data64.getBit<PU_STATUS_REGISTER_UNCORR_ERROR>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : OTPROM::Uncorrectable error bit set");
                }

                if(l_data64.getBit<PU_STATUS_REGISTER_DCOMP_ERR>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : OTPROM::Decompression Engine Error bit set");
                }

                if(l_data64.getBit<PU_STATUS_REGISTER_INVLD_PRGM_ERR>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : OTPROM::Invalid Program Operation error bit set");
                }


                //--  FAPI Asserts section for OTPROM --//
                o_return_action = P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
                FAPI_ASSERT(l_data64.getBit<PU_STATUS_REGISTER_UNCORR_ERROR>() != 1,
                            fapi2::EXTRACT_SBE_RC_OTP_ECC_ERR_INSECURE_MODE()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Uncorrectable error detected in OTPROM memory read");
            }

            // Map the OTPROM address to the known error at that location
            // the OTPROM is write-once at mfg test, so addresses should remain fixed in this code
            otprom_addr = l_data32_iar;

            if(otprom_addr == MAGIC_NUMBER_MISMATCH_LOCATION)
            {
                o_return_action = P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_MAGIC_NUMBER_MISMATCH()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:SEEPROM magic number didn't match");
            }
            else if(otprom_addr == OTPROM_IMAGE_END_LOCATION)
            {
                o_return_action = P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_BRANCH_TO_SEEPROM_FAIL()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Branch to SEEPROM didn't happen");
            }
            else
            {
                o_return_action = P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_UNEXPECTED_OTPROM_HALT()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Halted in OTPROM at address %08lX, but not at an expected halt location", otprom_addr);
            }
        }

        if(pibmem_addr_range)
        {
            FAPI_DBG("p9_extract_sbe_rc : Reading PIBMEM status register");
            FAPI_TRY(getScom(i_target_chip, PU_PIBMEM_STATUS_REG, l_data64));
            FAPI_DBG("p9_extract_sbe_rc : PIBMEM status : %#018lX", l_data64);

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_ADDR_INVALID_PIB>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Address which PIB is trying to access in PIBMEM is not valid one in PIBMEM");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_WRITE_INVALID_PIB>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Address for which PIB is trying to write is not writable");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_READ_INVALID_PIB>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Address for which PIB is trying to read is not readable");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Uncorrectable error occurred while PIB memory read");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_ECC_CORRECTED_ERROR_PIB>())
            {
                FAPI_INF("p9_extract_sbe_rc : PIBMEM::Corrected error in PIB mem read");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_WRITE_RST_INTERRUPT_PIB>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Reset occurred during write operation to PIBMEM from PIB side");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_READ_RST_INTERRUPT_PIB>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Reset occurred during read operation to PIBMEM from PIB side");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_ADDR_INVALID_FACES>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_WRITE_INVALID_FACES>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM or not writable");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_READ_INVALID_FACES>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Address which is given by Fast acesss interface, to access is not readable");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Uncorrectable error occurred while fast acess interface read");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_ECC_CORRECTED_ERROR_FACES>())
            {
                FAPI_INF("p9_extract_sbe_rc : PIBMEM::Corrected error in fast acess read operation");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_BAD_ARRAY_ADDRESS_FACES>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Wrong address accessd in indirect mode of operation from fast acess interface");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_WRITE_RST_INTERRUPT_FACES>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Reset occurred during write operation to PIBMEM from fast acess side");
            }

            if(l_data64.getBit<PU_PIBMEM_STATUS_REG_READ_RST_INTERRUPT_FACES>())
            {
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Reset occurred during read operation to PIBMEM from fast acess side");
            }

            //--  FAPI Asserts section for PIBMEM --//
            o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(l_data64.getBit<PU_PIBMEM_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB>() != 1,
                        fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_ERR_INSECURE_MODE()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Uncorrectable error occurred while PIB memory read");

            o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(l_data64.getBit<PU_PIBMEM_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES>() != 1,
                        fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_ERR_INSECURE_MODE()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Uncorrectable error occurred while fast access interface read");
        }

        if(seeprom_addr_range)
        {
            if(i_unsecure_mode)
            {
                FAPI_DBG("p9_extract_sbe_rc : Reading FI2CM mode register");
                FAPI_TRY(getScom(i_target_chip, PU_MODE_REGISTER_B, l_data64));
                FAPI_DBG("p9_extract_sbe_rc : FI2CM mode : %#018lX", l_data64);

                l_data32.flush<0>();
                l_data64.extractToRight(l_data32, 0, 16);
                uint32_t i2c_speed = l_data32;

                if(i2c_speed < 0x0003)
                {
                    o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
                    FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_FI2CM_BIT_RATE_ERR()
                                .set_TARGET_CHIP(i_target_chip),
                                "ERROR:Speed on the I2C bit rate divisor is less than min speed value (0x0003), I2C Speed read is %04lX", i2c_speed);
                }
            }

            if(i_unsecure_mode)
            {
                FAPI_DBG("p9_extract_sbe_rc : Reading FI2CM status register");
                FAPI_TRY(getScom(i_target_chip, PU_STATUS_REGISTER_B, l_data64_fi2c_status));
                FAPI_DBG("p9_extract_sbe_rc : FI2CM status : %#018lX", l_data64_fi2c_status);

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_ADDR_NVLD_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Address invalid bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_WRITE_NVLD_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Write invalid bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_READ_NVLD_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Read invalid bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_ADDR_P_ERR_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Address parity error bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_PAR_ERR_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Data parity error bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_LB_PARITY_ERROR_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Local bus parity error bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_ECC_CORRECTED_ERROR_0>())
                {
                    FAPI_INF("p9_extract_sbe_rc : FI2CM::WARN:One bit flip was there in data and been corrected");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_ECC_UNCORRECTED_ERROR_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::There are 2 bit flips in read data which cannot be corrected");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_ECC_CONFIG_ERROR_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Control register is ecc_enabled for data_length not equal to 8. OR ECC is enabled for the engine where ECC block is not instantiated");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_INVALID_COMMAND_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Invalid command bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_PARITY_ERROR_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Parity error bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_BACK_END_OVERRUN_ERROR_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Back end overrun error bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_BACK_END_ACCESS_ERROR_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Back end access error bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_ARBITRATION_LOST_ERROR_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Arbitration lost error bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_NACK_RECEIVED_ERROR_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::NACK receieved error bit set");
                }

                if(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_STOP_ERROR_0>())
                {
                    FAPI_ERR("p9_extract_sbe_rc : FI2CM::Stop error bit set");
                }

                //--  FAPI Asserts section for SEEPROM --//
                o_return_action = P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
                FAPI_ASSERT((l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_ECC_CONFIG_ERROR_0>() != 1           ||
                             l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_INVALID_COMMAND_0>() != 1        ||
                             l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_PARITY_ERROR_0>() != 1           ||
                             l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_BACK_END_OVERRUN_ERROR_0>() != 1 ||
                             l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_BACK_END_ACCESS_ERROR_0>() != 1  ||
                             l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_ARBITRATION_LOST_ERROR_0>() != 1 ||
                             l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_NACK_RECEIVED_ERROR_0>() != 1    ||
                             l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_BUS_STOP_ERROR_0>() != 1),
                            fapi2::EXTRACT_SBE_RC_FI2C_ERROR()
                            .set_TARGET_CHIP(i_target_chip),
                            "FI2C I2C Error detected");

                o_return_action = P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
                FAPI_ASSERT(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_ECC_UNCORRECTED_ERROR_0>() != 1,
                            fapi2::EXTRACT_SBE_RC_FI2C_ECC_ERR_INSECURE_MODE()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:There are 2 bit flips in read data which cannot be corrected");
            }
            else
            {
                // TODO - Read FI2CM status register by performing ramming of local register
            }
        }

        // ------- LEVEL 4 ------ //
        if(l_data_mchk)
        {
            if((OTPROM_MIN_RANGE <= l_data32_edr) && (l_data32_edr <= OTPROM_MAX_RANGE))
            {
                FAPI_DBG("p9_extract_sbe_rc : EDR contains OTPROM address");
                otprom_data_range = true;
            }
            else if((PIBMEM_MIN_RANGE <= l_data32_edr) && (l_data32_edr <= PIBMEM_MAX_RANGE))
            {
                FAPI_DBG("p9_extract_sbe_rc : EDR contains PIBMEM address");
                pibmem_data_range = true;
            }
            else if((SEEPROM_MIN_RANGE <= l_data32_edr) && (l_data32_edr <= SEEPROM_MAX_RANGE))
            {
                FAPI_DBG("p9_extract_sbe_rc : EDR contains SEEPROM address");
                seeprom_data_range = true;
            }
            else
            {
                FAPI_DBG("p9_extract_sbe_rc : EDR contains out of scope address = %08lX", l_data32_edr);
            }

            if(otprom_data_range || seeprom_data_range) // SIB Info is valid only for Otprom & Seeprom data
            {
                //-- MIB External Interface SIB Info
                FAPI_DBG("p9_extract_sbe_rc : Reading MIB SIB Info register");
                FAPI_TRY(getScom(i_target_chip, PU_MIB_XISIB, l_data64_mib_sib_info));
                FAPI_DBG("p9_extract_sbe_rc : MIB SIB Info : %#018lX", l_data64_mib_sib_info);

                l_data32.flush<0>();
                l_data64_mib_sib_info.extractToRight(l_data32, PU_MIB_XISIB_PIB_RSP_INFO, PU_MIB_XISIB_PIB_RSP_INFO_LEN);
                sib_rsp_info = l_data32;
            }

            if(otprom_data_range)
            {
                o_return_action = P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
                FAPI_ASSERT((!(sib_rsp_info == 0x6)), fapi2::EXTRACT_SBE_RC_OTP_ECC_ERR(),
                            "Parity/ECC error detected in OTPROM memory, Check if OTPROM programmed correctly by dumping content");

                o_return_action = P9_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info == 0x7)), fapi2::EXTRACT_SBE_RC_OTP_TIMEOUT()
                            .set_TARGET_CHIP(i_target_chip),
                            "PIB Timeout error detected during access to OTPROM");

                o_return_action = P9_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info != 0x0)), fapi2::EXTRACT_SBE_RC_OTP_PIB_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Scom error detected");
            }

            if(pibmem_data_range)
            {
                //-- MIB External Interface MEM Info
                FAPI_DBG("p9_extract_sbe_rc : Reading MIB MEM Info register");
                FAPI_TRY(getScom(i_target_chip, PU_MIB_XIMEM, l_data64_mib_mem_info));
                FAPI_DBG("p9_extract_sbe_rc : MIB MEM Info : %#018lX", l_data64_mib_mem_info);

                l_data32.flush<0>();
                l_data64_mib_mem_info.extractToRight(l_data32, PU_MIB_XIMEM_MEM_ERROR, PU_MIB_XIMEM_MEM_ERROR_LEN);
                mem_error = l_data32;

                o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
                FAPI_ASSERT((!(mem_error == 0x6)), fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_ERR(),
                            "ECC error detected during pibmem access, Run PIBMEM REPAIR test..");

                o_return_action = P9_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(mem_error != 0x0)), fapi2::EXTRACT_SBE_RC_PIBMEM_PIB_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Error detected during pibmem access");
            }

            if(seeprom_data_range)
            {
                o_return_action = P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
                FAPI_ASSERT((!(sib_rsp_info == 0x7)), fapi2::EXTRACT_SBE_RC_FI2C_TIMEOUT()
                            .set_TARGET_CHIP(i_target_chip),
                            "FI2C Timeout error detected");

                o_return_action = P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
                FAPI_ASSERT((!(sib_rsp_info == 0x6)), fapi2::EXTRACT_SBE_RC_FI2C_ECC_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "FI2C SEEPROM uncorrectable ECC error detected");

                o_return_action = P9_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info == 0x4)), fapi2::EXTRACT_SBE_RC_FI2C_SPRM_CFG_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "FI2C SEEPROM config error detected");

                o_return_action = P9_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info != 0x0)), fapi2::EXTRACT_SBE_RC_FI2C_PIB_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "FI2C PIB error detected");
            }
        }

        //Unknown
        FAPI_ERR("Halted due to unknown error at IAR location %08lX", l_data32_iar);
        o_return_action = P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
        FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_UNKNOWN_ERROR()
                    .set_TARGET_CHIP(i_target_chip), "SBE halted due to unknown error");
    }

    FAPI_INF("p9_extract_sbe_rc : Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
