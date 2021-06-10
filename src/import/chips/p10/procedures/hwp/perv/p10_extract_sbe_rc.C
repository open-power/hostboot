/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_extract_sbe_rc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file  p10_extract_sbe_rc.C
///
/// @brief Check for errors on the SBE, OTPROM, PIBMEM & SEEPROM
/// Pre-Checking :
///     1) Validating Usecase
///     2) (In non HB mode only) Check if VDN_PGOOD is set
///     3) Reading chip ec attribute detect if chip is NDD1 or later, and update memory location values
///     4) Read the value of DBGPRO 0xE0005 & Store IAR as Current IAR
///     5) Identify if PPE is halted from XSR Bit0, if not halted report error as infinite loop
/// Level 0 :
///     1) If Halted, Read the value of RAMDBG 0xE0003 & store SPRG0
///     2) Check if SPRG0 has address within valid PIBMEM range
///     3) If in valid range, then read the PIBMEM Save-off data
///     4) If PIBMEM Saveoff data not available then Perform RAMMING SRR0, SRR1, SPI STATUS (if valid)
///     5) Update l_data32_iar to SRR0 value (if valid)
/// Level 1 :
///     1) Check for Halt Conditions(HC) i.e XSR (1:3)
///     2) If HC is all Zero report error else Print the Halt condition reported
///     3) Print info of XSR bits 7,8,12,13,14,21,28 if TRUE
///     4) Read the value of XIRAMEDR 0xE0004 & Store IR and EDR
///     5) Check for Machine Check State(MCS) i.e XSR (29:31)
///     6) if MCS=0x4 OR Link Register contains PIBMEM Program Interrupt offset OR Current IAR has OTPROM Program Interrupt offset
///         Look for IAR range and report specific memory program error
///         Reading SB_MSG register to collect SBE Code state bits(bit 30:31) & SBE booted bit (bit 0) to report error of specific boot stage
///     7) if MCS=0x5 OR Link Register contains PIBMEM Instruction storage interrupt offset OR Current IAR has OTPROM Instruction storage interrupt offset
///         Look for IAR range and report specific memory program error
///     8) if MCS=0x6 OR Link Register contains PIBMEM Alignment interrupt offset OR Current IAR has OTPROM Alignment interrupt offset
///         Look for IAR range and report specific memory program error
///     9) if MCS=0x7 OR Link Register contains PIBMEM Data storage interrupt offset OR Current IAR has OTPROM Data storage interrupt offset
///         Look for IAR range and report specific memory program error
///    10) elseif MCS=0x1, 0x2, 0x3, Set the flag as Data Machine Check - l_data_mchk
/// Level 2 :
///     1) Based on IAR value identifying the Memory Address range
///        OTPROM (0x000C0000  to 0x000C0378)
///        PIBMEM (0xFFF80000  to 0xFFFFFFFF)
///        SEEPROM(0xFF800000  to 0xFF88FFFF)
///     2) If IAR value is out of above address scope, report error
/// Level 3 :
///     1)   If in OTPROM address range, Collect OTPROM Status 0x00010002
///     1.1) Print info of error report bits if they are true (0,1,2,3,4,5,45,46)
///     1.2) Map the OTPROM address to the known error at that location
///     1.3) Report Error if ECC errors are detected in OTPROM
///     2)   If in PIBMEM address range, Collect PIBMEM status 0x0008FFF5
///     2.1) Print info of error report bits in status if they are true (0,1,2,3,4,5,6,7,19,20,21,22,23,24,25,26)
///     2.2) Report Error if ECC errors are detected in PIBMEM
///     3)   If in SEEPROM address range, Collect SPI status and SPI clock divider from SBE_LCL_LFR
///     3.1) Print info of error report bits in status if they are true
///     3.2) Report Error if SPI clock divider is < 0x0004
///     3.3) Report Error for SPI errors
///     3.4) Report Error if ECC errors are detected in SEEPROM
///     3.5) Report Error if Mib Error rsp is non Zero (0x6-ECC Error, 0x4- Seeprom cfg Err, 0x1-Resource Err)
/// Level 4 :
///     1) If Data Machine Check error is true then look for the edr data range in SEEPROM/PIBMEM/OTPROM scope
///     2) Collect the SIB Info from 0xE0006
///     3) If in OTPROM data range report error if RSP_INFO is non-Zero response (0x6-Ecc Error, 0x7-PIB timeout Error, else-Scom Err)
///     3) If in PIBMEM data range, read MEM_Info (E0007) and report error if RSP_INFO is non-Zero response (0x6-Ecc Error, else-Scom Err)
///     4) If in SEEPROM data range, report error if RSP_INFO is non-zero response (0x6-ECC Error, 0x4- Seeprom cfg Err, 0x1-Resource Err)
///
///     DEFAULT) If non of the above errors are detected then report as UNKNOWN_ERROR
//
/////////////////////////////// USE CASES ////////////////////////////////////
// (Case1) SP calling on any proc                                          //
// (Case2) HB calling on master proc (after a failed chipop or something)   //
// (Case3) HB calling on slave proc before SMP is up (initial sbe start)    //
// (Case4) HB calling on slave proc after SMP is up (chipop fail)           //
//     ------------------------------------------------------               //
//     |    HB    |   SDB    |   UseCase                    |               //
//     ------------------------------------------------------               //
//     |    0     |    1     |   SP                 (Case1)|               //
//     |    1     |    0     |   MASTER_HB           (Case2)|               //
//     |    1     |    1     |   SLAVE_HB_BEFORE_SMP (Case3)|               //
//     |    1     |    0     |   SLAVE_HB_AFTER_SMP  (Case4)|               //
//     ------------------------------------------------------               //
//////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
// *HWP HW Owner        : Sandeep Korrapati <sakorrap@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Raja Das <rajadas2@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : SP:HB
//------------------------------------------------------------------------------


//## auto_generated
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#include "p10_extract_sbe_rc.H"
#include <p10_ppe_utils.H>
#include <p10_ppe_common.H>
#include <p10_scom_proc.H>
#include <p10_scom_perv.H>


fapi2::ReturnCode p10_extract_sbe_rc(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
                                     P10_EXTRACT_SBE_RC::RETURN_ACTION& o_return_action,
                                     bool i_set_sdb,
                                     bool i_unsecure_mode)
{
    // FAPI_ASSERT condition constant
    const bool FAIL = false;
    // PIBMEM address offset constant
    const uint32_t PIBMEM_ADDR_OFFSET = 0xFFF80000;
    const uint32_t PIBMEM_SCOM_OFFSET = 0x00080000;
    const uint32_t NUM_OF_LOCATION = 16;
    // Address Range constants
    const uint32_t OTPROM_MIN_RANGE  = 0x000C0000;
    const uint32_t OTPROM_MAX_RANGE  = 0x000C0378;
    const uint32_t PIBMEM_MIN_RANGE  = 0xFFF80000;
    const uint32_t PIBMEM_MAX_RANGE  = 0xFFFFFFFF;
    //Boot SEEPROM
//    const uint32_t SEEPROM_NDD1_MIN_RANGE = 0x80000000;
//    const uint32_t SEEPROM_NDD1_MAX_RANGE = 0x80038E18;
    const uint32_t BSEEPROM_MIN_RANGE = 0xFF800000;
    const uint32_t BSEEPROM_MAX_RANGE = 0xFF87FFFF;
    const uint32_t MSEEPROM_MIN_RANGE = 0xFF880000;
    const uint32_t MSEEPROM_MAX_RANGE = 0xFF8FFFFF;
    // Interrupt Vector offsets locations
    const uint32_t OTPROM_PROG_EXCEPTION_LOCATION  = 0x000C00E0;
    const uint32_t PIBMEM_PROG_EXCEPTION_LOCATION  = 0xFFF800E0;
    const uint32_t OTPROM_INST_STORE_INTR_LOCATION = 0x000C0080;
    const uint32_t PIBMEM_INST_STORE_INTR_LOCATION = 0xFFF80080;
    const uint32_t OTPROM_ALIGN_INTR_LOCATION      = 0x000C00C0;
    const uint32_t PIBMEM_ALIGN_INTR_LOCATION      = 0xFFF800C0;
    const uint32_t OTPROM_DATA_STORE_INTR_LOCATION = 0x000C0060;
    const uint32_t PIBMEM_DATA_STORE_INTR_LOCATION = 0xFFF80060;

    // These values might change on every recomilation of OTPROM binary
    // Refs : /afs/apd/func/project/tools/cronus/p10/exe/dev/prcd_d/images/sim/sbe_otprom_DD2.dis
    const uint32_t MAGIC_NUMBER_MISMATCH_LOCATION = 0xC0340;
    const uint32_t BSEEPROM_MAGIC_NUMBER_CHECK_LOCATION_1 = 0xC01AC;
    const uint32_t BSEEPROM_MAGIC_NUMBER_CHECK_LOCATION_2 = 0xC01C8;
    const uint32_t MSEEPROM_MAGIC_NUMBER_CHECK_LOCATION = 0xC01D0;
    // const uint32_t OTPROM_IMAGE_END_LOCATION      = 0xC02c4;

    // Variables
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_data64_dbgpro;
    fapi2::buffer<uint64_t> l_data64_dbginf;
    fapi2::buffer<uint64_t> l_data64_ramdbg;
    fapi2::buffer<uint64_t> l_data64_mib_mem_info;
    fapi2::buffer<uint64_t> l_data64_mib_sib_info;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint32_t> l_data32_ir;
    fapi2::buffer<uint32_t> l_data32_edr;
    fapi2::buffer<uint32_t> l_data32_iar;
    fapi2::buffer<uint32_t> l_data32_curr_iar;
    fapi2::buffer<uint32_t> l_data32_srr0 = 0xDEADDEAD;
    fapi2::buffer<uint32_t> l_data32_srr1;
    fapi2::buffer<uint32_t> l_data32_isr;
    fapi2::buffer<uint32_t> l_data32_lr;
    fapi2::buffer<uint32_t> l_data32_magicbyte;
    fapi2::buffer<uint8_t>  l_is_ndd1 = false;
    fapi2::buffer<uint64_t> l_data64_dbg[NUM_OF_LOCATION];
    fapi2::buffer<uint32_t> l_data32_sb_cs;
    fapi2::buffer<uint64_t> l_data64_spi_status;
    fapi2::buffer<uint64_t> l_data64_spi_config;
    fapi2::buffer<uint64_t> l_data64_spi_clock_config;
    fapi2::buffer<uint64_t> l_data64_spi0_status;
    fapi2::buffer<uint64_t> l_data64_spi0_config;
    fapi2::buffer<uint64_t> l_data64_spi0_clock_config;
    fapi2::buffer<uint64_t> l_data64_spi1_status;
    fapi2::buffer<uint64_t> l_data64_spi1_config;
    fapi2::buffer<uint64_t> l_data64_spi1_clock_config;
    fapi2::buffer<uint64_t> l_data64_spi2_status;
    fapi2::buffer<uint64_t> l_data64_spi2_config;
    fapi2::buffer<uint64_t> l_data64_spi2_clock_config;
    fapi2::buffer<uint64_t> l_data64_spi3_status;
    fapi2::buffer<uint64_t> l_data64_spi3_config;
    fapi2::buffer<uint64_t> l_data64_spi3_clock_config;
    fapi2::buffer<uint64_t> l_data64_loc_lfr;
    bool l_ppe_halt_state = true;
    bool l_data_mchk = false;
    bool l_inst_mchk = false;
    bool otprom_addr_range = false;
    bool pibmem_addr_range = false;
    bool seeprom_addr_range = false;
    bool bseeprom_addr_range = false;
    bool mseeprom_addr_range = false;
    bool otprom_data_range = false;
    bool pibmem_data_range = false;
    bool seeprom_data_range = false;
    bool bseeprom_data_range = false;
    bool mseeprom_data_range = false;
    bool l_is_HB_module = false;
    bool l_pibmem_saveoff = false;
    uint32_t HC, MCS, mem_error, ppe_dbg_loc, pibmem_dbg_loc;
    uint32_t sib_rsp_info = 0;
    uint32_t spi_clk_div_lfr = 0;
    uint32_t spi_clk_div = 0;
    uint32_t spi_config_val = 0;
    uint32_t SPRG0   = 272;

    FAPI_INF("p10_extract_sbe_rc : Entering ...");

#ifdef __HOSTBOOT_MODULE
    l_is_HB_module = true;
#endif

    FAPI_INF("p10_extract_sbe_rc : Inputs \n\ti_set_sdb = %s \n\ti_unsecure_mode = %s \n\tl_is_HB_module = %s",
             btos(i_set_sdb), btos(i_unsecure_mode), btos(l_is_HB_module));

    //-- Validating Usecase
    if(!l_is_HB_module && i_set_sdb)
    {
        FAPI_INF("p10_extract_sbe_rc : UseCase = SP");
    }
    else if(l_is_HB_module && !i_set_sdb)
    {
        FAPI_INF("p10_extract_sbe_rc : UseCase = MASTER_HB or SLAVE_HB_AFTER_SMP");
    }
    else if(l_is_HB_module && i_set_sdb)
    {
        FAPI_INF("p10_extract_sbe_rc : UseCase = SLAVE_HB_BEFORE_SMP");
    }
    else if (i_unsecure_mode)
    {
        FAPI_INF("p10_extract_sbe_rc : Running on a UNSECURE mode chip");
    }
    else
    {
        FAPI_ERR("p10_extract_sbe_rc : Extract_sbe_rc is triggered in an invalid usecase.");
        fapi2::current_err = fapi2::FAPI2_RC_INVALID_PARAMETER;
        goto fapi_try_exit;
    }

#ifndef __HOSTBOOT_MODULE
    FAPI_INF("p10_extract_sbe_rc: Reading CBS Status register");
    FAPI_TRY(getCfamRegister(i_target_chip, scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI, l_data32));

    if(!(l_data32.getBit<scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD>()))
    {
        o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
        FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_POWERCHECK_FAIL() .set_TARGET_CHIP(i_target_chip), "VDN_PGOOD not set");
    }

#endif


    if(i_set_sdb)
    {
        // Applying SDB setting required in usecase 1 & 3 only
        FAPI_INF("p10_extract_sbe_rc: Setting chip in SDB mode");
        l_data32.flush<0>();
        FAPI_TRY(getCfamRegister(i_target_chip, scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI, l_data32));
        l_data32.setBit<scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE>();
        FAPI_TRY(putCfamRegister(i_target_chip, scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI, l_data32));
    }

    // XSR and IAR
    FAPI_INF("p10_extract_sbe_rc : Reading PPE_XIDBGPRO");
    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO, l_data64_dbgpro));
    l_data64_dbgpro.extractToRight(l_data32_iar, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR,
                                   (scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_IAR_LEN + 2)); //To get 32 bits of address
    FAPI_INF("p10_extract_sbe_rc : PPE_XIDBGPRO : %" PRIx64 "", l_data64_dbgpro);
    FAPI_INF("p10_extract_sbe_rc : SBE IAR : %#08lX", l_data32_iar);

    l_data32_curr_iar = l_data32_iar;

    if (l_data64_dbgpro.getBit<scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HS>())
    {
        FAPI_INF("p10_extract_sbe_rc : PPE is in HALT state and SDB is set %s", btos(i_set_sdb));
        l_ppe_halt_state  = true;
    }
    else
    {
        FAPI_INF("p10_extract_sbe_rc : PPE is in RUNNING state, likely infinite loop, recommending restart");
        l_ppe_halt_state  = false;
        o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
        FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_RUNNING()
                    .set_TARGET_CHIP(i_target_chip), "SBE is in running state");
    }

    if(l_ppe_halt_state)
    {
        // ------- LEVEL 0 ------ //
        FAPI_INF("p10_extract_sbe_rc : Reading PU_PPE_XIRAMDBG");
        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMDBG, l_data64_ramdbg));
        l_data32.flush<0>();
        l_data64_ramdbg.extractToRight(l_data32, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMDBG_PPE_XIRAMRA_SPRG0,
                                       scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMDBG_PPE_XIRAMRA_SPRG0_LEN);
        ppe_dbg_loc = l_data32;
        FAPI_INF("p10_extract_sbe_rc : Data present in SPRG0 is %#010lX" , ppe_dbg_loc);

        FAPI_INF("p10_extract_sbe_rc : Reading PU_PPE_XIDBGINF");
        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF, l_data64_dbginf));
        l_data64_dbginf.extractToRight(l_data32_srr0, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0,
                                       scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_SRR0_LEN + 2);
        l_data64_dbginf.extractToRight(l_data32_lr, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR,
                                       scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGINF_LR_LEN);

        if ((PIBMEM_MIN_RANGE <= ppe_dbg_loc) && (ppe_dbg_loc <= PIBMEM_MAX_RANGE))
        {
            FAPI_INF("p10_extract_sbe_rc : SPRG0 has address with in PIBMEM range");
            pibmem_dbg_loc = (((ppe_dbg_loc - PIBMEM_ADDR_OFFSET) >> 3) + PIBMEM_SCOM_OFFSET);

            for(uint32_t i = 0; i <= NUM_OF_LOCATION; i++)
            {
                FAPI_INF("p10_extract_sbe_rc : PIBMEM address location fetching data from:%#010lX", (pibmem_dbg_loc + i));
                l_data32.flush<0>();
                l_data32 = pibmem_dbg_loc + i;
                FAPI_TRY(getScom(i_target_chip, l_data32, l_data64_dbg[i]));
            }

            //---------------------------------------------------------------------------------------------
            // uint32_t  version:16;   // Structure versioning                              -- DBG[0]  0:15
            // uint32_t  magicbyte:8;  // Magic byte for address validation (0xA5) in SPRG0 -- DBG[0] 16:23
            // Valid Bit, if the Register below could be saved off
            // uint32_t  validbit:8;   // One bit for all the registers below               -- DBG[0] 24:31
            // Registers to be saved off locations
            // uint32_t register_SRR0;                                                      -- DBG[0] 32:63
            // uint32_t register_SRR1;                                                      -- DBG[1]  0:31
            // uint32_t register_ISR;                                                       -- DBG[1] 32:63
            // uint64_t register_SPI_STATUS;                                                -- DBG[2]  0:63
            // uint32_t register_LR;                                                        -- DBG[3]  0:31
            //---------------------------------------------------------------------------------------------
            l_data64_dbg[0].extractToRight(l_data32_magicbyte, 16, 8);

            if((l_data64_dbg[0].getBit<31>()) && (l_data32_magicbyte == 0xA5))
            {
                FAPI_INF("p10_extract_sbe_rc : Valid Bit is set & MagicByte matches");
                l_pibmem_saveoff = true;

                l_data32.flush<0>();
                l_data64_dbg[0].extractToRight(l_data32, 0, 16);
                FAPI_INF("p10_extract_sbe_rc : Structure Version : %#06lX", l_data32);

                l_data64_dbg[0].extractToRight(l_data32_srr0, 32, 32);
                l_data64_dbg[1].extractToRight(l_data32_srr1,  0, 32);
                l_data64_dbg[1].extractToRight(l_data32_isr , 32, 32);
                l_data64_dbg[2].extractToRight(l_data32_lr  , 0, 32);
                l_data64_dbg[3].extractToRight(l_data64_spi0_status, 0, 64);
                l_data64_dbg[4].extractToRight(l_data64_spi0_config, 0, 64);
                l_data64_dbg[5].extractToRight(l_data64_spi0_clock_config, 0, 64);
                l_data64_dbg[6].extractToRight(l_data64_spi1_status, 0, 64);
                l_data64_dbg[7].extractToRight(l_data64_spi1_config, 0, 64);
                l_data64_dbg[8].extractToRight(l_data64_spi1_clock_config, 0, 64);
                l_data64_dbg[9].extractToRight(l_data64_spi2_status, 0, 64);
                l_data64_dbg[10].extractToRight(l_data64_spi2_config, 0, 64);
                l_data64_dbg[11].extractToRight(l_data64_spi2_clock_config, 0, 64);
                l_data64_dbg[12].extractToRight(l_data64_spi3_status, 0, 64);
                l_data64_dbg[13].extractToRight(l_data64_spi3_config, 0, 64);
                l_data64_dbg[14].extractToRight(l_data64_spi3_clock_config, 0, 64);
                FAPI_INF("p10_extract_sbe_rc : SRR0  : %#010lX", l_data32_srr0);
                FAPI_INF("p10_extract_sbe_rc : SRR1  : %#010lX", l_data32_srr1);
                FAPI_INF("p10_extract_sbe_rc : ISR   : %#010lX", l_data32_isr);
                //FAPI_INF("p10_extract_sbe_rc : SPI status   : %" PRIx64 "", l_data64_spi_status);
                FAPI_INF("p10_extract_sbe_rc : LR    : %#010lX", l_data32_lr);
            }
            else
            {
                FAPI_INF("p10_extract_sbe_rc : Valid Bit is not set OR Magic byte not matching, So continue with limited data\n\tValid Bit = %d, Magic Byte = %#04X",
                         l_data64_dbg[0].getBit<31>(), l_data32_magicbyte);
            }
        }
        else
        {
            FAPI_INF("p10_extract_sbe_rc : SPRG0 dont have address with in PIBMEM range");
        }

        if(!l_pibmem_saveoff && (i_set_sdb || i_unsecure_mode))
        {
            //--- RAMMING  SRR1, LFR
            static const uint16_t l_addr_srr0 = 0x01A;
            static const uint16_t l_addr_srr1 = 0x01B;
            fapi2::buffer<uint64_t> l_edr_save;
            fapi2::buffer<uint32_t> l_gpr0_save;
            fapi2::buffer<uint32_t> l_gpr1_save;
            fapi2::buffer<uint32_t> l_gpr9_save;
            fapi2::buffer<uint64_t> l_sprg0_save;
            fapi2::buffer<uint64_t> l_raminstr;
            //Store
            FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR, l_edr_save));
            FAPI_TRY(backup_gprs_sprs(i_target_chip, l_gpr0_save, l_gpr1_save, l_gpr9_save, l_sprg0_save ));
            FAPI_INF("p10_extract_sbe_rc : Performing RAMMING to get SRR1");
            //@sakorrap: Ramming SRR0 is not required as it is SCOMable and collected on top
            /*
                //-- Ramming SRR0
                // SPR to R0
                l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mfspr(0, l_addr_srr0), 0, 32);
                FAPI_INF("ppe_get_inst_mfspr(R0, %5d): %" PRIx64 " ", l_addr_srr0, l_raminstr );
                FAPI_TRY(pollHaltStateDone(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR));
                FAPI_TRY(fapi2::putScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR, l_raminstr));
                // R0 to SPRG0
                l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(0, SPRG0), 0, 32);
                FAPI_INF(": ppe_getMtsprInstruction(R0, SPRG0): %" PRIx64 " " , l_raminstr );
                FAPI_TRY(RAMReadDone(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR, l_raminstr, l_data32_srr0));
            */
            //-- Ramming SRR1
            // SPR to R0
            l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mfspr(0, l_addr_srr1), 0, 32);
            FAPI_INF("ppe_get_inst_mfspr(R0, %5d): %" PRIx64 " ", l_addr_srr0, l_raminstr );
            FAPI_TRY(pollHaltStateDone(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR));
            FAPI_TRY(fapi2::putScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR, l_raminstr));
            // R0 to SPRG0
            l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(0, SPRG0), 0, 32);
            FAPI_INF(": ppe_getMtsprInstruction(R0, SPRG0): %" PRIx64 " " , l_raminstr );
            FAPI_TRY(RAMReadDone(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIXCR, l_raminstr, l_data32_srr1));
            //Reading LFR
            FAPI_TRY(LocalRegRead(i_target_chip , 0x2040 , l_data64_loc_lfr));
            //Restore
            FAPI_TRY(restore_gprs_sprs(i_target_chip , l_gpr0_save, l_gpr1_save, l_gpr9_save, l_sprg0_save ));
            FAPI_TRY(putScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR, l_edr_save));
            //FAPI_INF("p10_extract_sbe_rc : Rammed SRR0  : %#010lX", l_data32_srr0);
            FAPI_INF("p10_extract_sbe_rc : Rammed SRR1  : %#010lX", l_data32_srr1);
            FAPI_INF("p10_extract_sbe_rc : Rammed LFR  : %" PRIx64 "", l_data64_loc_lfr);
        }

        if(l_data32_srr0 != 0xDEADDEAD && l_data32_srr0 != 0x0)
        {
            FAPI_INF("p10_extract_sbe_rc : Use SRR0 as IAR");
            l_data32_iar = l_data32_srr0;
        }

        // ------- LEVEL 1 ------ //
        //Extract HC
        l_data32.flush<0>();
        l_data64_dbgpro.extractToRight(l_data32, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC,
                                       scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_HC_LEN);
        HC = l_data32;

        switch(HC)
        {
            case 0x0 :
                o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_NEVER_STARTED()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Halt Condition is all Zero, SBE engine was probably never started or SBE got halted by programming XCR to halt");
                break;

            case 0x1 :
                FAPI_ERR("p10_extract_sbe_rc : XCR[CMD] written 111 to force-halt the processor.");
                break;

            case 0x2 :
                FAPI_ERR("p10_extract_sbe_rc : A second watchdog timer (WDT) event occurred while TCR[WRC]=11");
                break;

            case 0x3 :
                FAPI_ERR("p10_extract_sbe_rc : Unmaskable interrupt halt");
                break;

            case 0x4 :
                FAPI_ERR("p10_extract_sbe_rc : Debug halt");
                break;

            case 0x5 :
                FAPI_ERR("p10_extract_sbe_rc : DBCR halt");
                break;

            case 0x6 :
                FAPI_ERR("p10_extract_sbe_rc : The external halt_req input was active.");
                break;

            case 0x7 :
                FAPI_ERR("p10_extract_sbe_rc : Hardware failure");
                break;

            default :
                FAPI_ERR("p10_extract_sbe_rc : INVALID HALT CONDITION HC=0x%x", HC);
                break;
        }

        //Extract TRAP
        if(l_data64_dbgpro.getBit<scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_TRAP>())
        {
            FAPI_INF("p10_extract_sbe_rc : TRAP Instruction Debug Event Occured");
        }

        //Extract IAC
        if(l_data64_dbgpro.getBit<scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_IAC>())
        {
            FAPI_INF("p10_extract_sbe_rc : Instruction Address Compare Debug Event Occured");
        }

        //Extract DACR
        if(l_data64_dbgpro.getBit<scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_RDAC>())
        {
            FAPI_INF("p10_extract_sbe_rc : Data Address Compare (Read) Debug Event Occured");
        }

        //Extract DACW
        if(l_data64_dbgpro.getBit<scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_WDAC>())
        {
            FAPI_INF("p10_extract_sbe_rc : Data Address Compare (Write) Debug Event Occured");
        }

        //Extract WS
        if(l_data64_dbgpro.getBit<scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_NULL_MSR_WE>())
        {
            FAPI_INF("p10_extract_sbe_rc : In WAIT STATE");
        }

        //Extract EP
        if(l_data64_dbgpro.getBit<scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_EP>())
        {
            FAPI_INF("p10_extract_sbe_rc : Maskable Event Pending");
        }

        //Extract MFE
        if(l_data64_dbgpro.getBit<scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MFE>())
        {
            FAPI_ERR("p10_extract_sbe_rc : Multiple Fault Error Occured");
        }

        //Extract MCS
        l_data32.flush<0>();
        l_data64_dbgpro.extractToRight(l_data32, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS,
                                       scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIDBGPRO_XSR_MCS_LEN);
        MCS = l_data32;

        // IR and EDR
        FAPI_INF("p10_extract_sbe_rc : Reading PPE_XIRAMEDR");
        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR, l_data64));
        l_data64.extractToRight(l_data32_ir, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR,
                                scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_GA_IR_LEN);
        l_data64.extractToRight(l_data32_edr, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR,
                                scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_PPE_XIRAMEDR_EDR_LEN);

        // Magic Number Mismatch
        if(l_data32_curr_iar == MAGIC_NUMBER_MISMATCH_LOCATION)
        {
            if((l_data32_lr == BSEEPROM_MAGIC_NUMBER_CHECK_LOCATION_1) || (l_data32_lr == BSEEPROM_MAGIC_NUMBER_CHECK_LOCATION_2))
            {
                o_return_action = P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_MAGIC_NUMBER_MISMATCH()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Boot SEEPROM magic number didn't match");
            }

            if(l_data32_lr == MSEEPROM_MAGIC_NUMBER_CHECK_LOCATION)
            {
                o_return_action = P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM;
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_MAGIC_NUMBER_MISMATCH()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Measurement SEEPROM magic number didn't match");
            }
        }
        //Program Interrupt
        else if(MCS == 0x4 ||
                (l_data32_lr - 0x4) == PIBMEM_PROG_EXCEPTION_LOCATION ||
                (l_data32_curr_iar == OTPROM_PROG_EXCEPTION_LOCATION )) //PIBMEM Saveoff can't be active when IVPR is having OTP offset
        {
            if((OTPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= OTPROM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Program Interrupt occured in OTPROM memory program");

                if(!l_is_ndd1)
                {
                    fapi2::buffer<uint8_t> l_sbe_code_state;
                    FAPI_INF("p10_extract_sbe_rc : Reading SB_MSG register to collect SBE Code state bits");

                    if(l_is_HB_module && !i_set_sdb) //HB calling Master Proc or HB calling Slave after SMP
                    {
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG, l_data64));
                        l_data64.extractToRight(l_sbe_code_state, 30, 2);
                    }
                    else
                    {
                        FAPI_TRY(getCfamRegister(i_target_chip, scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG_FSI, l_data32));
                        l_data32.extractToRight(l_sbe_code_state, 30, 2);
                    }

                    if(l_sbe_code_state == 0x1)
                    {
                        o_return_action = P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
                        FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_MAGIC_NUMBER_MISMATCH()
                                    .set_TARGET_CHIP(i_target_chip),
                                    "ERROR:Program Interrupt occured, probably MAGIC NUMBER MISMATCH");
                    }
                    else
                    {
                        FAPI_ERR("p10_extract_sbe_rc : SBE code state value = %02X is invalid", l_sbe_code_state);
                    }
                }
            }
            else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Program Interrupt occured in PIBMEM memory program");
            }
            else if((BSEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= MSEEPROM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Program Interrupt occured in SEEPROM memory program");

                fapi2::buffer<uint8_t> l_sbe_code_state;
                bool l_sbe_booted = false;
                FAPI_INF("p10_extract_sbe_rc : Reading SB_MSG register to collect SBE Code state bits");

                if(l_is_HB_module && !i_set_sdb) //HB calling Master Proc or HB calling Slave after SMP
                {
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG, l_data64));
                    l_data64.extractToRight(l_sbe_code_state, 30, 2);
                    l_sbe_booted = l_data64.getBit<0>();
                }
                else
                {
                    FAPI_TRY(getCfamRegister(i_target_chip, scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG_FSI, l_data32));
                    l_data32.extractToRight(l_sbe_code_state, 30, 2);
                    l_sbe_booted = l_data32.getBit<0>();
                }

                //if(l_sbe_code_state < 0x9)
                if((MSEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= MSEEPROM_MAX_RANGE))
                {
                    o_return_action = P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM;
                    FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_SBE_L1_LOADER_FAIL()
                                .set_TARGET_CHIP(i_target_chip),
                                "ERROR:Program Interrupt occured in Measurement SEEPROM");
                }
                else if((BSEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= BSEEPROM_MAX_RANGE))
                {
                    o_return_action = P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
                    FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_SBE_L2_LOADER_FAIL()
                                .set_TARGET_CHIP(i_target_chip),
                                "ERROR:Program Interrupt occured in Boot SEEPROM");
                }
                else if(l_sbe_code_state < 0xB)
                {
                    o_return_action = P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
                    FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_SBE_L2_LOADER_FAIL()
                                .set_TARGET_CHIP(i_target_chip),
                                "ERROR:Program Interrupt occured in Boot SEEPROM")
                }
                else if((l_sbe_code_state == 0xB) && (!l_sbe_booted))
                {
                    o_return_action = P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
                    FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_SBE_L2_LOADER_FAIL()
                                .set_TARGET_CHIP(i_target_chip),
                                "ERROR:Program Interrupt occured during pk boot")
                }
                else if(!l_sbe_booted)
                {
                    FAPI_ERR("p10_extract_sbe_rc : SBE code state value = %02X is invalid", l_sbe_code_state);
                }
            }

            else
            {
                FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Program Interrupt", l_data32_iar);
            }

            o_return_action = P10_EXTRACT_SBE_RC::REIPL_BKP_BMSEEPROM;
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_PROGRAM_INTERRUPT()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Program interrupt occured for IAR=%08lX and EDR=%08lX", l_data32_iar, l_data32_edr);
        }
        // Instruction storage interrupt
        else if(MCS == 0x5 ||
                (l_data32_lr - 0x4) == PIBMEM_INST_STORE_INTR_LOCATION ||
                (l_data32_curr_iar == OTPROM_INST_STORE_INTR_LOCATION )) //PIBMEM Saveoff can't be active when IVPR is having OTP offset
        {
            if((OTPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= OTPROM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Instruction storage interrupt occured for OTPROM memory range");
            }
            else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Instruction storage interrupt occured for PIBMEM memory range");
            }
            else if((BSEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= MSEEPROM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Instruction storage interrupt occured for SEEPROM memory range");
            }
            else
            {
                FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Instruction storage interrupt", l_data32_iar);
            }

            o_return_action = P10_EXTRACT_SBE_RC::REIPL_BKP_BMSEEPROM;
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_INST_STORE_INTR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Instruction storage interrupt for IAR=%08lX and EDR=%08lX", l_data32_iar, l_data32_edr);
        }
        // Alignment interrupt
        else if(MCS == 0x6 ||
                (l_data32_lr - 0x4) == PIBMEM_ALIGN_INTR_LOCATION ||
                (l_data32_curr_iar == OTPROM_ALIGN_INTR_LOCATION )) //PIBMEM Saveoff can't be active when IVPR is having OTP offset
        {
            if((OTPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= OTPROM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Alignment interrupt occured for OTPROM memory range");
            }
            else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Alignment interrupt occured for PIBMEM memory range");
            }
            else if((BSEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= MSEEPROM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Alignment interrupt occured for SEEPROM memory range");
            }
            else
            {
                FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Alignment interrupt", l_data32_iar);
            }

            o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_ALIGN_INTR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Alignment interrupt for IAR=%08lX and EDR=%08lX", l_data32_iar, l_data32_edr);
        }
        // Data storage interrupt
        else if(MCS == 0x7 ||
                (l_data32_lr - 0x4) == PIBMEM_DATA_STORE_INTR_LOCATION ||
                (l_data32_curr_iar == OTPROM_DATA_STORE_INTR_LOCATION )) //PIBMEM Saveoff can't be active when IVPR is having OTP offset
        {
            if((OTPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= OTPROM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Data storage interrupt occured for OTPROM memory range");
            }
            else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Data storage interrupt occured for PIBMEM memory range");
            }
            else if((BSEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= MSEEPROM_MAX_RANGE))
            {
                FAPI_ERR("p10_extract_sbe_rc : Data storage interrupt occured for SEEPROM memory range");
            }
            else
            {
                FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Data storage interrupt", l_data32_iar);
            }

            o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_DATA_STORE_INTR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Data storage interrupt for IAR=%08lX ", l_data32_iar);
        }
        else
        {
            switch (MCS)
            {
                case 0x0 :
                    FAPI_ERR("p10_extract_sbe_rc : Instruction machine check at Address = %08lX", l_data32_iar);
                    l_inst_mchk = true;
                    break;

                case 0x1 :
                    FAPI_ERR("p10_extract_sbe_rc : Data machine check - load for EDR = %08lX", l_data32_edr);
                    l_data_mchk = true;
                    break;

                case 0x2 :
                    FAPI_ERR("p10_extract_sbe_rc : Data machine check - precise store for EDR = %08lX", l_data32_edr);
                    l_data_mchk = true;
                    break;

                case 0x3 :
                    FAPI_ERR("p10_extract_sbe_rc : Data machine check - imprecise store for EDR = %08lX", l_data32_edr);
                    l_data_mchk = true;
                    break;

                default :
                    FAPI_ERR("p10_extract_sbe_rc : INVALID Machine Check Status MCS=0x%x", MCS);
                    break;
            }
        }

        // ------- LEVEL 2 ------ //

        if((OTPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= OTPROM_MAX_RANGE))
        {
            FAPI_INF("p10_extract_sbe_rc : IAR contains OTPROM address");
            otprom_addr_range = true;
        }
        else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
        {
            FAPI_INF("p10_extract_sbe_rc : IAR contains PIBMEM address");
            pibmem_addr_range = true;
        }
        else if((BSEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= MSEEPROM_MAX_RANGE))
        {
            FAPI_INF("p10_extract_sbe_rc : IAR contains SEEPROM address");
            seeprom_addr_range = true;

            if((BSEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= BSEEPROM_MAX_RANGE))
            {
                bseeprom_addr_range = true;
            }

            if((MSEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= MSEEPROM_MAX_RANGE))
            {
                mseeprom_addr_range = true;
            }
        }
        else
        {
            o_return_action = P10_EXTRACT_SBE_RC::REIPL_BKP_BMSEEPROM;
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_ADDR_NOT_RECOGNIZED()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Address %08lX is out of range", l_data32_iar);
        }

        // ------- LEVEL 3 ------ //

        if(otprom_addr_range && l_inst_mchk)
        {
            if(i_unsecure_mode)
            {
                FAPI_INF("p10_extract_sbe_rc : Reading OTPROM status register");
                FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_OTP_OTPC_M_STATUS_REGISTER, l_data64));
                FAPI_INF("p10_extract_sbe_rc : OTPROM status : %" PRIx64 "", l_data64);

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIB_OTP_OTPC_M_STATUS_REGISTER_ADDR_NVLD>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : OTPROM::Address invalid bit set");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIB_OTP_OTPC_M_STATUS_REGISTER_WRITE_NVLD>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : OTPROM::Write invalid bit set");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIB_OTP_OTPC_M_STATUS_REGISTER_READ_NVLD>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : OTPROM::Read invalid bit set");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIB_OTP_OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : OTPROM::Invalid command register fields programmed bit set");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIB_OTP_OTPC_M_STATUS_REGISTER_CORR_ERR>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : OTPROM::Correctable error bit set");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIB_OTP_OTPC_M_STATUS_REGISTER_UNCORR_ERROR>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : OTPROM::Uncorrectable error bit set");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIB_OTP_OTPC_M_STATUS_REGISTER_DCOMP_ERR>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : OTPROM::Decompression Engine Error bit set");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIB_OTP_OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : OTPROM::Invalid Program Operation error bit set");
                }


                //--  FAPI Asserts section for OTPROM --//
                o_return_action = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
                FAPI_ASSERT(l_data64.getBit<scomt::proc::TP_TPCHIP_PIB_OTP_OTPC_M_STATUS_REGISTER_UNCORR_ERROR>() != 1,
                            fapi2::EXTRACT_SBE_RC_OTP_ECC_ERR_NONSECURE_MODE()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Uncorrectable error detected in OTPROM memory read");
            }

            // Map the OTPROM address to the known error at that location
            // the OTPROM is write-once at mfg test, so addresses should remain fixed in this code

            //-- MIB External Interface SIB Info
            FAPI_INF("p10_extract_sbe_rc : Reading MIB SIB Info register");
            FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB, l_data64_mib_sib_info));
            FAPI_INF("p10_extract_sbe_rc : MIB SIB Info : %" PRIx64 "", l_data64_mib_sib_info);

            l_data32.flush<0>();
            l_data64_mib_sib_info.extractToRight(l_data32, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO,
                                                 scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO_LEN);
            sib_rsp_info = l_data32;
            o_return_action = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            FAPI_ASSERT((!(sib_rsp_info == 0x6)), fapi2::EXTRACT_SBE_RC_OTP_ECC_ERR(),
                        "Parity/ECC error detected in OTPROM memory, Check if OTPROM programmed correctly by dumping content");

            o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
            FAPI_ASSERT((!(sib_rsp_info == 0x7)), fapi2::EXTRACT_SBE_RC_OTP_TIMEOUT()
                        .set_TARGET_CHIP(i_target_chip),
                        "PIB Timeout error detected during access to OTPROM");

            o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
            FAPI_ASSERT((!(sib_rsp_info != 0x0)), fapi2::EXTRACT_SBE_RC_OTP_PIB_ERR()
                        .set_TARGET_CHIP(i_target_chip),
                        "Scom error detected");
            //When no any error detected and still halted in some OTPROM location
            o_return_action = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            FAPI_ASSERT((!(sib_rsp_info == 0x0)), fapi2::EXTRACT_SBE_RC_UNEXPECTED_OTPROM_HALT()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Halted in OTPROM at address %08lX, but not at an expected halt location", l_data32_iar);

        }

        if(pibmem_addr_range && l_inst_mchk) // PIBMEM status register read is allowed in both Secure & NonSecure mode
        {
            FAPI_INF("p10_extract_sbe_rc : Reading PIBMEM status register");
            FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG, l_data64));
            FAPI_INF("p10_extract_sbe_rc : PIBMEM status : %" PRIx64 "", l_data64);

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address which PIB is trying to access in PIBMEM is not valid one in PIBMEM");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address for which PIB is trying to write is not writable");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address for which PIB is trying to read is not readable");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Uncorrectable error occurred while PIB memory read");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB>())
            {
                FAPI_INF("p10_extract_sbe_rc : PIBMEM::Corrected error in PIB mem read");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Wrong address accessd in indirect mode of operation from PIB side");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Reset occurred during write operation to PIBMEM from PIB side");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Reset occurred during read operation to PIBMEM from PIB side");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM or not writable");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address which is given by Fast acesss interface, to access is not readable");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Uncorrectable error occurred while fast acess interface read");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES>())
            {
                FAPI_INF("p10_extract_sbe_rc : PIBMEM::Corrected error in fast acess read operation");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Wrong address accessd in indirect mode of operation from fast acess interface");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Reset occurred during write operation to PIBMEM from fast acess side");
            }

            if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES>())
            {
                FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Reset occurred during read operation to PIBMEM from fast acess side");
            }

            //--  FAPI Asserts section for PIBMEM --//
            o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(l_data64.getBit<3>() != 1,
                        fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_ERR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Uncorrectable error occurred while accessing memory via PIB side");

            o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(l_data64.getBit<22>() != 1,
                        fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_ERR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Uncorrectable error occurred while accessing memory via fast access side");
        }

        if(seeprom_addr_range && i_unsecure_mode && l_inst_mchk && !l_pibmem_saveoff)  // || !i_set_sdb))
        {
            if(bseeprom_addr_range)
            {
                if(!(l_data64_loc_lfr.getBit<12>()))
                {
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG, l_data64_spi_status));
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_CONFIG1, l_data64_spi_config));
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG, l_data64_spi_clock_config));
                }
                else
                {
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG, l_data64_spi_status));
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1, l_data64_spi_config));
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST1_CLOCK_CONFIG, l_data64_spi_clock_config));
                }
            }
            else if(mseeprom_addr_range)
            {
                if(!(l_data64_loc_lfr.getBit<13>()))
                {
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST3_STATUS_REG, l_data64_spi_status));
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1, l_data64_spi_config));
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG, l_data64_spi_clock_config));
                }
                else
                {
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG, l_data64_spi_status));
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1, l_data64_spi_config));
                    FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG, l_data64_spi_clock_config));
                }
            }
        }
        else if(l_pibmem_saveoff && l_inst_mchk)
        {
            if(bseeprom_addr_range)
            {
                if(!(l_data64_loc_lfr.getBit<12>()))
                {
                    l_data64_spi0_status.extractToRight(l_data64_spi_status, 0, 64);
                    l_data64_spi0_config.extractToRight(l_data64_spi_config, 0, 64);
                    l_data64_spi0_clock_config.extractToRight(l_data64_spi_clock_config, 0, 64);
                }
                else
                {
                    l_data64_spi1_status.extractToRight(l_data64_spi_status, 0, 64);
                    l_data64_spi1_config.extractToRight(l_data64_spi_config, 0, 64);
                    l_data64_spi1_clock_config.extractToRight(l_data64_spi_clock_config, 0, 64);
                }
            }
            else if(mseeprom_addr_range)
            {
                if(!(l_data64_loc_lfr.getBit<13>()))
                {
                    l_data64_spi3_status.extractToRight(l_data64_spi_status, 0, 64);
                    l_data64_spi3_config.extractToRight(l_data64_spi_config, 0, 64);
                    l_data64_spi3_clock_config.extractToRight(l_data64_spi_clock_config, 0, 64);
                }
                else
                {
                    l_data64_spi2_status.extractToRight(l_data64_spi_status, 0, 64);
                    l_data64_spi2_config.extractToRight(l_data64_spi_config, 0, 64);
                    l_data64_spi2_clock_config.extractToRight(l_data64_spi_clock_config, 0, 64);
                }
            }
        }

        if(seeprom_addr_range && (i_unsecure_mode || l_pibmem_saveoff) && l_inst_mchk) //!i_set_sdb))
        {
            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_32>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : counter configuration register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_33>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : clock configuration register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_34>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : sequencer configuration register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_35>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : sequencer fsm error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_36>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : shifter fsm error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_37>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : pattern match register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_38>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : transmit data register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_38>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : transmit data register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_39>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : receive data register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_40>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : configuration register 1 parity error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_42>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : error register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_43>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : ecc correctable error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_44>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : ecc uncorrectable error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_47>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : memory mapped SPI address overlap");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_48>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : general access violation");
            }

            if(l_data64_spi_status.getBit < scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_48 + 1 > ())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : general access violation");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_50>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : port multiplexer error");
            }

            if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_51>())
            {
                FAPI_ERR("p10_extract_sbe_rc : SEEPROM : address range error");
            }
        }

        if(seeprom_addr_range && (i_set_sdb || i_unsecure_mode) && l_inst_mchk)
        {
            l_data32.flush<0>();
            l_data64_loc_lfr.extractToRight(l_data32, 0, 12);
            spi_clk_div_lfr = l_data32;
            l_data32.flush<0>();
            l_data64_spi_clock_config.extractToRight(l_data32, 0, 12);
            spi_clk_div = l_data32;
            l_data32.flush<0>();
            l_data64_spi_config.extractToRight(l_data32, 0, 5);
            spi_config_val = l_data32;

            if(spi_clk_div_lfr < 0x4)
            {
                FAPI_ERR("p10_extract_sbe_rc : Invalid spi clock divider value specified 0x%X", spi_clk_div_lfr);
            }

            if(l_pibmem_saveoff || i_unsecure_mode)
            {
                if(spi_clk_div_lfr != spi_clk_div)
                {
                    FAPI_ERR("p10_extract_sbe_rc : spi clock divider value is corrupted, clock divider value in SPI is 0x%X and in lfr is 0x%X",
                             spi_clk_div, spi_clk_div_lfr);
                }

                if(spi_config_val != 0x1E)
                {
                    FAPI_ERR("p10_extract_sbe_rc : spi lock is lost,lock value is 0x%X", spi_config_val);
                }
            }

            //-- MIB External Interface SIB Info
            FAPI_INF("p10_extract_sbe_rc : Reading MIB SIB Info register");
            FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB, l_data64_mib_sib_info));
            FAPI_INF("p10_extract_sbe_rc : MIB SIB Info : %" PRIx64 "", l_data64_mib_sib_info);

            l_data32.flush<0>();
            l_data64_mib_sib_info.extractToRight(l_data32, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO,
                                                 scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO_LEN);
            sib_rsp_info = l_data32;

            if(sib_rsp_info != 0x0)
            {
                FAPI_ERR("p10_extract_sbe_rc : SIB Error Rsp is 0x%X", sib_rsp_info);
            }

            if(bseeprom_addr_range)
            {
                o_return_action = P10_EXTRACT_SBE_RC::REIPL_UPD_SPI_CLK_DIV;
                FAPI_ASSERT((!(spi_clk_div_lfr < 0x4)), fapi2::EXTRACT_SBE_RC_SPI_CLK_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "SBE LFR configured with invalid spi clock divider");

                if(l_pibmem_saveoff || i_unsecure_mode)
                {
                    o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                    FAPI_ASSERT((!(spi_clk_div_lfr != spi_clk_div)), fapi2::EXTRACT_SBE_RC_SPI_CLK_ERR()
                                .set_TARGET_CHIP(i_target_chip),
                                "Boot SEEPROM configured with invalid clock divider");
                }

                o_return_action = P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
                FAPI_ASSERT((!(sib_rsp_info == 0x6)), fapi2::EXTRACT_SBE_RC_SPI_ECC_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Boot SEEPROM uncorrectable ECC error detected");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
                FAPI_ASSERT((!(sib_rsp_info == 0x4)), fapi2::EXTRACT_SBE_RC_SPI_SPRM_CFG_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Boot SEEPROM config/addr error detected");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
                FAPI_ASSERT((!(sib_rsp_info == 0x1)), fapi2::EXTRACT_SBE_RC_SPI_RSC_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Boot SEEPROM is not available. Could be lock or port multiplexer settings");
                //TODO: Include RC for SPI parity errors captured
            }

            if(mseeprom_addr_range)
            {
                o_return_action = P10_EXTRACT_SBE_RC::REIPL_UPD_SPI_CLK_DIV;
                FAPI_ASSERT((!(spi_clk_div_lfr < 0x4)), fapi2::EXTRACT_SBE_RC_SPI_CLK_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "SBE LFR configured with invalid spi clock divider");

                if(l_pibmem_saveoff || i_unsecure_mode)
                {
                    o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                    FAPI_ASSERT((!(spi_clk_div_lfr != spi_clk_div)), fapi2::EXTRACT_SBE_RC_SPI_CLK_ERR()
                                .set_TARGET_CHIP(i_target_chip),
                                "Measurement SEEPROM configured with invalid clock divider");
                }

                o_return_action = P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM;
                FAPI_ASSERT((!(sib_rsp_info == 0x6)), fapi2::EXTRACT_SBE_RC_SPI_ECC_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Measurement SEEPROM uncorrectable ECC error detected");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info == 0x4)), fapi2::EXTRACT_SBE_RC_SPI_SPRM_CFG_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Measurement SEEPROM config/addr error detected");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info == 0x1)), fapi2::EXTRACT_SBE_RC_SPI_RSC_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Measurement SEEPROM is not available. Could be lock or port multiplexer settings ");
                //TODO: Include RC for SPI parity errors captured
            }
        }

        // ------- LEVEL 4 ------ //
        if(l_data_mchk)
        {
            if((OTPROM_MIN_RANGE <= l_data32_edr) && (l_data32_edr <= OTPROM_MAX_RANGE))
            {
                FAPI_INF("p10_extract_sbe_rc : EDR contains OTPROM address");
                otprom_data_range = true;
            }
            else if((PIBMEM_MIN_RANGE <= l_data32_edr) && (l_data32_edr <= PIBMEM_MAX_RANGE))
            {
                FAPI_INF("p10_extract_sbe_rc : EDR contains PIBMEM address");
                pibmem_data_range = true;
            }
            else if((BSEEPROM_MIN_RANGE <= l_data32_edr) && (l_data32_edr <= MSEEPROM_MAX_RANGE))
            {
                FAPI_INF("p10_extract_sbe_rc : EDR contains SEEPROM address");
                seeprom_data_range = true;

                if((BSEEPROM_MIN_RANGE <= l_data32_edr) && (l_data32_edr <= BSEEPROM_MAX_RANGE))
                {
                    bseeprom_data_range = true;
                }

                if((MSEEPROM_MIN_RANGE <= l_data32_edr) && (l_data32_edr <= MSEEPROM_MAX_RANGE))
                {
                    mseeprom_data_range = true;
                }
            }
            else
            {
                FAPI_INF("p10_extract_sbe_rc : EDR contains out of scope address = %08lX", l_data32_edr);
            }

            if(otprom_data_range || seeprom_data_range) // SIB Info is valid only for Otprom & Seeprom data
            {
                //-- MIB External Interface SIB Info
                FAPI_INF("p10_extract_sbe_rc : Reading MIB SIB Info register");
                FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB, l_data64_mib_sib_info));
                FAPI_INF("p10_extract_sbe_rc : MIB SIB Info : %" PRIx64 "", l_data64_mib_sib_info);

                l_data32.flush<0>();
                l_data64_mib_sib_info.extractToRight(l_data32, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO,
                                                     scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_MIB_XISIB_RSP_INFO_LEN);
                sib_rsp_info = l_data32;

                if(sib_rsp_info != 0x0)
                {
                    FAPI_ERR("p10_extract_sbe_rc : SIB Error Rsp is 0x%X", sib_rsp_info);
                }
            }

            if(otprom_data_range)
            {
                o_return_action = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
                FAPI_ASSERT((!(sib_rsp_info == 0x6)), fapi2::EXTRACT_SBE_RC_OTP_ECC_ERR(),
                            "Parity/ECC error detected in OTPROM memory, Check if OTPROM programmed correctly by dumping content");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info == 0x7)), fapi2::EXTRACT_SBE_RC_OTP_TIMEOUT()
                            .set_TARGET_CHIP(i_target_chip),
                            "PIB Timeout error detected during access to OTPROM");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info != 0x0)), fapi2::EXTRACT_SBE_RC_OTP_PIB_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Scom error detected");
            }

            if(pibmem_data_range && l_data_mchk) // PIBMEM status register read is allowed in both Secure & NonSecure mode
            {
                FAPI_INF("p10_extract_sbe_rc : Reading PIBMEM status register");
                FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG, l_data64));
                FAPI_INF("p10_extract_sbe_rc : PIBMEM status : %" PRIx64 "", l_data64);

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_PIB>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address which PIB is trying to access in PIBMEM is not valid one in PIBMEM");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_PIB>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address for which PIB is trying to write is not writable");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_PIB>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address for which PIB is trying to read is not readable");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Uncorrectable error occurred while PIB memory read");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_PIB>())
                {
                    FAPI_INF("p10_extract_sbe_rc : PIBMEM::Corrected error in PIB mem read");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_PIB>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Wrong address accessd in indirect mode of operation from PIB side");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_PIB>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Reset occurred during write operation to PIBMEM from PIB side");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_PIB>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Reset occurred during read operation to PIBMEM from PIB side");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ADDR_INVALID_FACES>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_INVALID_FACES>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM or not writable");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_INVALID_FACES>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Address which is given by Fast acesss interface, to access is not readable");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Uncorrectable error occurred while fast acess interface read");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_ECC_CORRECTED_ERROR_FACES>())
                {
                    FAPI_INF("p10_extract_sbe_rc : PIBMEM::Corrected error in fast acess read operation");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_BAD_ARRAY_ADDRESS_FACES>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Wrong address accessd in indirect mode of operation from fast acess interface");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_WRITE_RST_INTERRUPT_FACES>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Reset occurred during write operation to PIBMEM from fast acess side");
                }

                if(l_data64.getBit<scomt::proc::TP_TPCHIP_PIBMEM_CTRL_MAC_STATUS_REG_READ_RST_INTERRUPT_FACES>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : PIBMEM::Reset occurred during read operation to PIBMEM from fast acess side");
                }

                //--  FAPI Asserts section for PIBMEM --//
                o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
                FAPI_ASSERT(l_data64.getBit<3>() != 1,
                            fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Uncorrectable error occurred while accessing memory via PIB side");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
                FAPI_ASSERT(l_data64.getBit<22>() != 1,
                            fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Uncorrectable error occurred while accessing memory via fast access side");
            }

            if(pibmem_data_range)
            {
                //-- MIB External Interface MEM Info
                FAPI_INF("p10_extract_sbe_rc : Reading MIB MEM Info register");
                FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM, l_data64_mib_mem_info));
                FAPI_INF("p10_extract_sbe_rc : MIB MEM Info : %" PRIx64 "", l_data64_mib_mem_info);

                l_data32.flush<0>();
                l_data64_mib_mem_info.extractToRight(l_data32, scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR,
                                                     scomt::proc::TP_TPCHIP_PIB_SBE_SBEPM_SBEPPE_MIB_XIMEM_ERROR_LEN);
                mem_error = l_data32;

                if(mem_error != 0x0)
                {
                    FAPI_ERR("p10_extract_sbe_rc : MIB MEM Error info is 0x%X", mem_error);
                }

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_SBE;
                FAPI_ASSERT((!(mem_error == 0x6)), fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_ERR(),
                            "ECC error detected during pibmem access, Run PIBMEM REPAIR test..");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(mem_error != 0x0)), fapi2::EXTRACT_SBE_RC_PIBMEM_PIB_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Error detected during pibmem access");
            }

            if(seeprom_data_range && i_unsecure_mode && !l_pibmem_saveoff)  // || !i_set_sdb))
            {
                if(bseeprom_data_range)
                {
                    if(!(l_data64_loc_lfr.getBit<12>()))
                    {
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG, l_data64_spi_status));
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_CONFIG1, l_data64_spi_config));
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_CLOCK_CONFIG, l_data64_spi_clock_config));
                    }
                    else
                    {
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST1_STATUS_REG, l_data64_spi_status));
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST1_CONFIG1, l_data64_spi_config));
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST1_CLOCK_CONFIG, l_data64_spi_clock_config));
                    }
                }
                else if(mseeprom_data_range)
                {
                    if(!(l_data64_loc_lfr.getBit<13>()))
                    {
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST3_STATUS_REG, l_data64_spi_status));
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST3_CONFIG1, l_data64_spi_config));
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST3_CLOCK_CONFIG, l_data64_spi_clock_config));
                    }
                    else
                    {
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST2_STATUS_REG, l_data64_spi_status));
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST2_CONFIG1, l_data64_spi_config));
                        FAPI_TRY(getScom(i_target_chip, scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST2_CLOCK_CONFIG, l_data64_spi_clock_config));
                    }
                }
            }
            else if(l_pibmem_saveoff)
            {
                if(bseeprom_data_range)
                {
                    if(!(l_data64_loc_lfr.getBit<12>()))
                    {
                        l_data64_spi0_status.extractToRight(l_data64_spi_status, 0, 64);
                        l_data64_spi0_config.extractToRight(l_data64_spi_config, 0, 64);
                        l_data64_spi0_clock_config.extractToRight(l_data64_spi_clock_config, 0, 64);
                    }
                    else
                    {
                        l_data64_spi1_status.extractToRight(l_data64_spi_status, 0, 64);
                        l_data64_spi1_config.extractToRight(l_data64_spi_config, 0, 64);
                        l_data64_spi1_clock_config.extractToRight(l_data64_spi_clock_config, 0, 64);
                    }
                }
                else if(mseeprom_data_range)
                {
                    if(!(l_data64_loc_lfr.getBit<13>()))
                    {
                        l_data64_spi3_status.extractToRight(l_data64_spi_status, 0, 64);
                        l_data64_spi3_config.extractToRight(l_data64_spi_config, 0, 64);
                        l_data64_spi3_clock_config.extractToRight(l_data64_spi_clock_config, 0, 64);
                    }
                    else
                    {
                        l_data64_spi2_status.extractToRight(l_data64_spi_status, 0, 64);
                        l_data64_spi2_config.extractToRight(l_data64_spi_config, 0, 64);
                        l_data64_spi2_clock_config.extractToRight(l_data64_spi_clock_config, 0, 64);
                    }
                }
            }

            if(seeprom_data_range && (i_unsecure_mode || l_pibmem_saveoff)) //!i_set_sdb))
            {
                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_32>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : counter configuration register parity error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_33>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : clock configuration register parity error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_34>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : sequencer configuration register parity error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_35>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : sequencer fsm error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_36>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : shifter fsm error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_37>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : pattern match register parity error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_38>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : transmit data register parity error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_38>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : transmit data register parity error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_39>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : receive data register parity error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_40>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : configuration register 1 parity error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_42>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : error register parity error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_43>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : ecc correctable error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_44>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : ecc uncorrectable error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_47>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : memory mapped SPI address overlap");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_48>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : general access violation");
                }

                if(l_data64_spi_status.getBit < scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_48 + 1 > ())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : general access violation");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_50>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : port multiplexer error");
                }

                if(l_data64_spi_status.getBit<scomt::proc::TP_TPCHIP_PIB_SPIMC_SPIMST0_STATUS_REG_SPI_STATUS_51>())
                {
                    FAPI_ERR("p10_extract_sbe_rc : SEEPROM : address range error");
                }
            }

            if(bseeprom_data_range || mseeprom_data_range)
            {
                l_data32.flush<0>();
                l_data64_loc_lfr.extractToRight(l_data32, 0, 12);
                spi_clk_div_lfr = l_data32;
                l_data32.flush<0>();
                l_data64_spi_clock_config.extractToRight(l_data32, 0, 12);
                spi_clk_div = l_data32;
                l_data32.flush<0>();
                l_data64_spi_config.extractToRight(l_data32, 0, 5);
                spi_config_val = l_data32;

                if(spi_clk_div_lfr < 0x4)
                {
                    FAPI_ERR("p10_extract_sbe_rc : Invalid spi_clk_div specified 0x%X", spi_clk_div_lfr);
                }

                if(l_pibmem_saveoff || i_unsecure_mode)
                {
                    if(spi_clk_div_lfr != spi_clk_div)
                    {
                        FAPI_ERR("p10_extract_sbe_rc : spi clock divider value is corrupted, clock divider value in SPI is 0x%X and in lfr is 0x%X",
                                 spi_clk_div, spi_clk_div_lfr);
                    }

                    if(spi_config_val != 0x1E)
                    {
                        FAPI_ERR("p10_extract_sbe_rc : spi lock is lost,lock value is 0x%X", spi_config_val);
                    }
                }
            }

            if(bseeprom_data_range)
            {

                o_return_action = P10_EXTRACT_SBE_RC::REIPL_UPD_SPI_CLK_DIV;
                FAPI_ASSERT((!(spi_clk_div_lfr < 0x4)), fapi2::EXTRACT_SBE_RC_SPI_CLK_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "SBE LFR configured with invalid spi clock divider");

                if(l_pibmem_saveoff || i_unsecure_mode)
                {
                    o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                    FAPI_ASSERT((!(spi_clk_div_lfr != spi_clk_div)), fapi2::EXTRACT_SBE_RC_SPI_CLK_ERR()
                                .set_TARGET_CHIP(i_target_chip),
                                "Boot SEEPROM configured with invalid clock divider");
                }

                o_return_action = P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
                FAPI_ASSERT((!(sib_rsp_info == 0x6)), fapi2::EXTRACT_SBE_RC_SPI_ECC_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Boot SEEPROM uncorrectable ECC error detected");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info == 0x4)), fapi2::EXTRACT_SBE_RC_SPI_SPRM_CFG_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Boot SEEPROM config/addr error detected");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info == 0x1)), fapi2::EXTRACT_SBE_RC_SPI_RSC_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Boot SEEPROM is not available");
            }

            if(mseeprom_data_range)
            {
                o_return_action = P10_EXTRACT_SBE_RC::REIPL_UPD_SPI_CLK_DIV;
                FAPI_ASSERT((!(spi_clk_div_lfr < 0x4)), fapi2::EXTRACT_SBE_RC_SPI_CLK_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "SBE LFR configured with invalid spi clock divider");

                if(l_pibmem_saveoff || i_unsecure_mode)
                {
                    o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                    FAPI_ASSERT((!(spi_clk_div_lfr != spi_clk_div)), fapi2::EXTRACT_SBE_RC_SPI_CLK_ERR()
                                .set_TARGET_CHIP(i_target_chip),
                                "Measurement SEEPROM configured with invalid clock divider");
                }

                o_return_action = P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM;
                FAPI_ASSERT((!(sib_rsp_info == 0x6)), fapi2::EXTRACT_SBE_RC_SPI_ECC_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Measurement SEEPROM uncorrectable ECC error detected");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info == 0x4)), fapi2::EXTRACT_SBE_RC_SPI_SPRM_CFG_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Measurement SEEPROM config/addr error detected");

                o_return_action = P10_EXTRACT_SBE_RC::RESTART_CBS;
                FAPI_ASSERT((!(sib_rsp_info == 0x1)), fapi2::EXTRACT_SBE_RC_SPI_RSC_ERR()
                            .set_TARGET_CHIP(i_target_chip),
                            "Measurement SEEPROM is not available");
            }
        }

        //Unknown
        FAPI_ERR("Halted due to unknown error at IAR location %08lX", l_data32_iar);

        o_return_action = P10_EXTRACT_SBE_RC::REIPL_BKP_BMSEEPROM;
        FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_UNKNOWN_ERROR()
                    .set_TARGET_CHIP(i_target_chip), "SBE halted due to unknown error");
    }

    FAPI_INF("p10_extract_sbe_rc : Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
