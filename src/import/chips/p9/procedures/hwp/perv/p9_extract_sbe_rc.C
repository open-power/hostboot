/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_extract_sbe_rc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
/// Level 0 :
///     1) Read the value of RAMDBG 0xE0003 & store SPRG0
///     2) Check if SPRG0 has address within valid PIBMEM range
///     3) If in valid range, then read the PIBMEM Save-off data
///     4) If PIBMEM Saveoff data not available then Perform RAMMING SRR0, SRR1, FI2C CNFG & STATUS (if valid)
///     5) Update l_data_iar to SRR0 value (if valid)
/// Level 1 :
///     1) Read the value of DBGPRO 0xE0005 & Store IAR
///     2) Identify if PPE is halted from XSR Bit0, Continue only if halted
///     3) If Halted, Check for Halt Conditions(HC) i.e XSR (1:3)
///     4) If HC is all Zero report error else Print the Halt condition reported
///     5) Print info of XSR bits 7,8,12,13,14,21,28 if TRUE
///     6) Read the value of XIRAMEDR 0xE0004 & Store IR and EDR
///     7) Check for Machine Check State(MCS) i.e XSR (29:31)
///     8) if MCS=0x4 OR Link Register contains Program Interrupt offset
///         Look for IAR range and report specific memory program error
///     8) if MCS=0x5 OR Link Register contains Instruction storage interrupt offset
///         Look for IAR range and report specific memory program error
///     8) if MCS=0x6 OR Link Register contains Alignment interrupt offset
///         Look for IAR range and report specific memory program error
///     8) if MCS=0x7 OR Link Register contains Data storage interrupt offset
///         Look for IAR range and report specific memory program error
///     9) elseif MCS=0x1, 0x2, 0x3, Set the flag as Data Machine Check - l_data_mchk
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
//
/////////////////////////////// USE CASES ////////////////////////////////////
// (Case1) FSP calling on any proc                                          //
// (Case2) HB calling on master proc (after a failed chipop or something)   //
// (Case3) HB calling on slave proc before SMP is up (initial sbe start)    //
// (Case4) HB calling on slave proc after SMP is up (chipop fail)           //
//     ------------------------------------------------------               //
//     |    HB    |   SDB    |   UseCase                    |               //
//     ------------------------------------------------------               //
//     |    0     |    1     |   FSP                 (Case1)|               //
//     |    1     |    0     |   MASTER_HB           (Case2)|               //
//     |    1     |    1     |   SLAVE_HB_BEFORE_SMP (Case3)|               //
//     |    1     |    0     |   SLAVE_HB_AFTER_SMP  (Case4)|               //
//     ------------------------------------------------------               //
//////////////////////////////////////////////////////////////////////////////
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
#include <p9_ppe_common.H>
#include <p9_ppe_utils.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_perv_scom_addresses_fixes.H>
#include <p9_perv_scom_addresses_fld_fixes.H>


fapi2::ReturnCode p9_extract_sbe_rc(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
                                    P9_EXTRACT_SBE_RC::RETURN_ACTION& o_return_action,
                                    bool i_set_sdb,
                                    bool i_unsecure_mode)
{
    // FAPI_ASSERT condition constant
    const bool FAIL = false;
    // PIBMEM address offset constant
    const uint32_t PIBMEM_ADDR_OFFSET = 0xFFFE8000;
    const uint32_t PIBMEM_SCOM_OFFSET = 0x00080000;
    const uint32_t NUM_OF_LOCATION = 4;
    // Address Range constants
    const uint32_t OTPROM_MIN_RANGE  = 0x000C0000;
    const uint32_t OTPROM_MAX_RANGE  = 0x000C0378;
    const uint32_t PIBMEM_MIN_RANGE  = 0xFFFE8000;
    const uint32_t PIBMEM_MAX_RANGE  = 0xFFFFFFFF;
    const uint32_t SEEPROM_NDD1_MIN_RANGE = 0x80000000;
    const uint32_t SEEPROM_NDD1_MAX_RANGE = 0x80038E18;
    const uint32_t SEEPROM_NOT_NDD1_MIN_RANGE = 0xFF800000;
    const uint32_t SEEPROM_NOT_NDD1_MAX_RANGE = 0xFF838E18;
    // Interrupt Vector offsets locations
    const uint32_t OTPROM_PROG_EXCEPTION_LOCATION  = 0x000C00E0;
    const uint32_t PIBMEM_PROG_EXCEPTION_LOCATION  = 0xFFFE80E0;
    const uint32_t OTPROM_INST_STORE_INTR_LOCATION = 0x000C0080;
    const uint32_t PIBMEM_INST_STORE_INTR_LOCATION = 0xFFFE8080;
    const uint32_t OTPROM_ALIGN_INTR_LOCATION      = 0x000C00C0;
    const uint32_t PIBMEM_ALIGN_INTR_LOCATION      = 0xFFFE80C0;
    const uint32_t OTPROM_DATA_STORE_INTR_LOCATION = 0x000C0060;
    const uint32_t PIBMEM_DATA_STORE_INTR_LOCATION = 0xFFFE8060;

    // OTPROM Address constants as per the image on 12/Jun/2017
    // These values might change on every recomilation of OTPROM binary
    // Refs : /afs/apd/func/project/tools/cronus/p9/exe/dev/prcd_d/images/sim/sbe_otprom_DD2.dis
    const uint32_t NOT_NDD1_MAGIC_NUMBER_MISMATCH_LOCATION = 0xC0170;
    const uint32_t NOT_NDD1_OTPROM_IMAGE_END_LOCATION      = 0xC016C;
    // NDD1 address locations are extracted from HW System by Joachim Fenkes
    const uint32_t NDD1_MAGIC_NUMBER_MISMATCH_LOCATION     = 0xC015C;
    const uint32_t NDD1_OTPROM_IMAGE_END_LOCATION          = 0xC0158;

    // Variables
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_data64_dbgpro;
    fapi2::buffer<uint64_t> l_data64_ramdbg;
    fapi2::buffer<uint64_t> l_data64_fi2c_status;
    fapi2::buffer<uint64_t> l_data64_loc_fi2c_status;
    fapi2::buffer<uint64_t> l_data64_loc_fi2c_cnfg;
    fapi2::buffer<uint64_t> l_data64_mib_mem_info;
    fapi2::buffer<uint64_t> l_data64_mib_sib_info;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint32_t> l_data32_ir;
    fapi2::buffer<uint32_t> l_data32_edr;
    fapi2::buffer<uint32_t> l_data32_iar;
    fapi2::buffer<uint32_t> l_data32_srr0 = 0xDEADDEAD;
    fapi2::buffer<uint32_t> l_data32_srr1;
    fapi2::buffer<uint32_t> l_data32_isr;
    fapi2::buffer<uint32_t> l_data32_lr;
    fapi2::buffer<uint32_t> l_data32_magicbyte;
    fapi2::buffer<uint8_t>  l_is_ndd1;
    fapi2::buffer<uint64_t> l_data64_dbg[NUM_OF_LOCATION];
    bool l_ppe_halt_state = true;
    bool l_data_mchk = false;
    bool otprom_addr_range = false;
    bool pibmem_addr_range = false;
    bool seeprom_addr_range = false;
    bool otprom_data_range = false;
    bool pibmem_data_range = false;
    bool seeprom_data_range = false;
    bool l_is_HB_module = false;
    bool l_pibmem_saveoff = false;
    uint32_t HC, MCS, otprom_addr, mem_error, sib_rsp_info, ppe_dbg_loc, pibmem_dbg_loc;
    uint32_t SEEPROM_MIN_RANGE;
    uint32_t SEEPROM_MAX_RANGE;
    uint32_t MAGIC_NUMBER_MISMATCH_LOCATION;
    uint32_t OTPROM_IMAGE_END_LOCATION;

    FAPI_INF("p9_extract_sbe_rc : Entering ...");

#ifdef __HOSTBOOT_MODULE
    l_is_HB_module = true;
#endif

    FAPI_INF("p9_extract_sbe_rc : Inputs \n\ti_set_sdb = %s \n\ti_unsecure_mode = %s \n\tl_is_HB_module = %s",
             btos(i_set_sdb), btos(i_unsecure_mode), btos(l_is_HB_module));

    //-- Validating Usecase
    if(!l_is_HB_module && i_set_sdb)
    {
        FAPI_INF("p9_extract_sbe_rc : UseCase = FSP");
    }
    else if(l_is_HB_module && !i_set_sdb)
    {
        FAPI_INF("p9_extract_sbe_rc : UseCase = MASTER_HB or SLAVE_HB_AFTER_SMP");
    }
    else if(l_is_HB_module && i_set_sdb)
    {
        FAPI_INF("p9_extract_sbe_rc : UseCase = SLAVE_HB_BEFORE_SMP");
    }
    else if (i_unsecure_mode)
    {
        FAPI_INF("p9_extract_sbe_rc : Running on a UNSECURE mode chip");
    }
    else
    {
        FAPI_ERR("p9_extract_sbe_rc : Extract_sbe_rc is triggered in an invalid usecase.");
        goto fapi_try_exit;
    }

    FAPI_DBG("p9_extract_sbe_rc: Reading chip ec attribute");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_EXTRACT_SBE_RC_P9NDD1_CHIPS, i_target_chip, l_is_ndd1));

    if(l_is_ndd1)
    {
        FAPI_INF("p9_extract_sbe_rc: Detected as Nimbus DD1 chip");
        MAGIC_NUMBER_MISMATCH_LOCATION = NDD1_MAGIC_NUMBER_MISMATCH_LOCATION;
        OTPROM_IMAGE_END_LOCATION = NDD1_OTPROM_IMAGE_END_LOCATION;
        SEEPROM_MIN_RANGE = SEEPROM_NDD1_MIN_RANGE;
        SEEPROM_MAX_RANGE = SEEPROM_NDD1_MAX_RANGE;
    }
    else
    {
        MAGIC_NUMBER_MISMATCH_LOCATION = NOT_NDD1_MAGIC_NUMBER_MISMATCH_LOCATION;
        OTPROM_IMAGE_END_LOCATION = NOT_NDD1_OTPROM_IMAGE_END_LOCATION;
        SEEPROM_MIN_RANGE = SEEPROM_NOT_NDD1_MIN_RANGE;
        SEEPROM_MAX_RANGE = SEEPROM_NOT_NDD1_MAX_RANGE;
    }

    if(i_set_sdb)
    {
        // Applying SDB setting required in usecase 1 & 3 only
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
        FAPI_INF("p9_extract_sbe_rc : PPE is in HALT state and SDB is set %s", btos(i_set_sdb));
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
        // ------- LEVEL 0 ------ //
        FAPI_DBG("p9_extract_sbe_rc : Reading PU_PPE_XIRAMDBG");
        FAPI_TRY(getScom(i_target_chip, PU_PPE_XIRAMDBG, l_data64_ramdbg));
        l_data32.flush<0>();
        l_data64_ramdbg.extractToRight(l_data32, PU_GPE0_PPE_XIRAMDBG_XIRAMRA_SPRG0, PU_GPE0_PPE_XIRAMDBG_XIRAMRA_SPRG0_LEN);
        ppe_dbg_loc = l_data32;
        FAPI_DBG("p9_extract_sbe_rc : Data present in SPRG0 is %#010lX" , ppe_dbg_loc);

        if ((PIBMEM_MIN_RANGE <= ppe_dbg_loc) && (ppe_dbg_loc <= PIBMEM_MAX_RANGE))
        {
            FAPI_DBG("p9_extract_sbe_rc : SPRG0 has address with in PIBMEM range");
            pibmem_dbg_loc = (((ppe_dbg_loc - PIBMEM_ADDR_OFFSET) >> 3) + PIBMEM_SCOM_OFFSET);

            for(uint32_t i = 0; i <= NUM_OF_LOCATION; i++)
            {
                FAPI_DBG("p9_extract_sbe_rc : PIBMEM address location fetching data from:%#010lX", (pibmem_dbg_loc + i));
                l_data32.flush<0>();
                l_data32 = pibmem_dbg_loc + i;
                FAPI_TRY(getScom(i_target_chip, l_data32, l_data64_dbg[i]));
            }

            //---------------------------------------------------------------------------------------------
            // uint32_t  version:16;   // Structure versioning                              -- DBG[0]  0:15
            // uint32_t  magicbyte:8;  // Magic byte for address validation (0xA5) in SPRG0 -- DBG[0] 16:23
            // Valid Bit, if the Register below could be saved off
            // uint32_t  validbit:8;   // One byte for all the registers below              -- DBG[0] 24:31
            // Registers to be saved off locations
            // uint32_t register_SRR0;                                                      -- DBG[0] 32:63
            // uint32_t register_SRR1;                                                      -- DBG[1]  0:31
            // uint32_t register_ISR;                                                       -- DBG[1] 32:63
            // uint32_t register_FI2C_CONFIG_LOWER_32BITS;                                  -- DBG[2]  0:31
            // uint32_t register_FI2C_CONFIG_UPPER_32BITS;                                  -- DBG[2] 32:63
            // uint32_t register_FI2C_STAT_LOWER_32BITS;                                    -- DBG[3]  0:31
            // uint32_t register_FI2C_STAT_UPPER_32BITS;                                    -- DBG[3] 32:63
            // uint32_t register_LR;                                                        -- DBG[4]  0:31
            //---------------------------------------------------------------------------------------------
            l_data64_dbg[0].extractToRight(l_data32_magicbyte, 16, 8);

            if((l_data64_dbg[0].getBit<31>()) && (l_data32_magicbyte == 0xA5))
            {
                FAPI_DBG("p9_extract_sbe_rc : Valid Bit is set & MagicByte matches");
                l_pibmem_saveoff = true;

                l_data32.flush<0>();
                l_data64_dbg[0].extractToRight(l_data32, 0, 16);
                FAPI_DBG("p9_extract_sbe_rc : Structure Version : %#06lX", l_data32);

                l_data64_dbg[0].extractToRight(l_data32_srr0, 32, 32);
                l_data64_dbg[1].extractToRight(l_data32_srr1,  0, 32);
                l_data64_dbg[1].extractToRight(l_data32_isr , 32, 32);
                l_data64_dbg[2].extractToRight(l_data64_loc_fi2c_cnfg, 0, 64);
                l_data64_dbg[3].extractToRight(l_data64_loc_fi2c_status, 0, 64);
                l_data64_dbg[4].extractToRight(l_data32_lr  , 0, 32);
                FAPI_INF("p9_extract_sbe_rc : SRR0  : %#010lX", l_data32_srr0);
                FAPI_INF("p9_extract_sbe_rc : SRR1  : %#010lX", l_data32_srr1);
                FAPI_INF("p9_extract_sbe_rc : ISR   : %#010lX", l_data32_isr);
                FAPI_INF("p9_extract_sbe_rc : LR    : %#010lX", l_data32_lr);
                FAPI_INF("p9_extract_sbe_rc : SBE Local FI2C Config   : %#018lX", l_data64_loc_fi2c_cnfg);
                FAPI_INF("p9_extract_sbe_rc : SBE Local FI2C Status   : %#018lX", l_data64_loc_fi2c_status);
            }
            else
            {
                FAPI_INF("p9_extract_sbe_rc : Valid Bit is not set OR Magic byte not matching, So continue with limited data\n\tValid Bit = %d, Magic Byte = %#04X",
                         l_data64_dbg[0].getBit<31>(), l_data32_magicbyte);
            }
        }
        else
        {
            FAPI_INF("p9_extract_sbe_rc : SPRG0 dont have address with in PIBMEM range");
        }

        if(!l_pibmem_saveoff && (i_set_sdb || i_unsecure_mode))
        {
            //--- RAMMING SRR0, SRR1, FI2C CNFG & STATUS
            static const uint64_t SBE_BASE_ADDRESS  = 0x000E0000;
            static const uint16_t l_addr_srr0 = 0x01A;
            static const uint16_t l_addr_srr1 = 0x01B;
            fapi2::buffer<uint64_t> l_edr_save;
            fapi2::buffer<uint32_t> l_gpr0_save;
            fapi2::buffer<uint32_t> l_gpr1_save;
            fapi2::buffer<uint32_t> l_gpr9_save;
            fapi2::buffer<uint64_t> l_sprg0_save;
            fapi2::buffer<uint64_t> l_raminstr;
            //Store
            FAPI_TRY(getScom(i_target_chip, PU_PPE_XIRAMEDR, l_edr_save));
            FAPI_TRY(backup_gprs_sprs(i_target_chip, l_gpr0_save, l_gpr1_save, l_gpr9_save, l_sprg0_save ));
            FAPI_INF("p9_extract_sbe_rc : Performing RAMMING to get SRR0 & SRR1");
            //-- Ramming SRR0
            // SPR to R0
            l_raminstr.flush<0>().insertFromRight(ppe_getMfsprInstruction(0, l_addr_srr0), 0, 32);
            FAPI_DBG("ppe_getMfsprInstruction(R0, %5d): 0x%16llX", l_addr_srr0, l_raminstr );
            FAPI_TRY(ppe_pollHaltState(i_target_chip, SBE_BASE_ADDRESS));
            FAPI_TRY(fapi2::putScom(i_target_chip, SBE_BASE_ADDRESS + PPE_XIRAMEDR, l_raminstr));
            // R0 to SPRG0
            l_raminstr.flush<0>().insertFromRight(ppe_getMtsprInstruction(0, SPRG0), 0, 32);
            FAPI_DBG(": ppe_getMtsprInstruction(R0, SPRG0): 0x%16llX" , l_raminstr );
            FAPI_TRY(ppe_RAMRead(i_target_chip, SBE_BASE_ADDRESS, l_raminstr, l_data32_srr0));
            //-- Ramming SRR1
            // SPR to R0
            l_raminstr.flush<0>().insertFromRight(ppe_getMfsprInstruction(0, l_addr_srr1), 0, 32);
            FAPI_DBG("ppe_getMfsprInstruction(R0, %5d): 0x%16llX", l_addr_srr0, l_raminstr );
            FAPI_TRY(ppe_pollHaltState(i_target_chip, SBE_BASE_ADDRESS));
            FAPI_TRY(fapi2::putScom(i_target_chip, SBE_BASE_ADDRESS + PPE_XIRAMEDR, l_raminstr));
            // R0 to SPRG0
            l_raminstr.flush<0>().insertFromRight(ppe_getMtsprInstruction(0, SPRG0), 0, 32);
            FAPI_DBG(": ppe_getMtsprInstruction(R0, SPRG0): 0x%16llX" , l_raminstr );
            FAPI_TRY(ppe_RAMRead(i_target_chip, SBE_BASE_ADDRESS, l_raminstr, l_data32_srr1));
            FAPI_INF("p9_extract_sbe_rc : Performing RAMMING to get FI2C CNFG & STAT");
            FAPI_TRY(LocalRegRead(i_target_chip , 0x800 , l_data64_loc_fi2c_cnfg));
            FAPI_TRY(LocalRegRead(i_target_chip , 0x820 , l_data64_loc_fi2c_status));
            //Restore
            FAPI_TRY(restore_gprs_sprs(i_target_chip , l_gpr0_save, l_gpr1_save, l_gpr9_save, l_sprg0_save ));
            FAPI_TRY(putScom(i_target_chip, PU_PPE_XIRAMEDR, l_edr_save));
            FAPI_INF("p9_extract_sbe_rc : Rammed SRR0  : %#010lX", l_data32_srr0);
            FAPI_INF("p9_extract_sbe_rc : Rammed SRR1  : %#010lX", l_data32_srr1);
            FAPI_INF("p9_extract_sbe_rc : Rammed SBE Local FI2C Config   : %#018lX", l_data64_loc_fi2c_cnfg);
            FAPI_INF("p9_extract_sbe_rc : Rammed SBE Local FI2C Status   : %#018lX", l_data64_loc_fi2c_status);
        }

        if(l_data32_srr0 != 0xDEADDEAD)
        {
            FAPI_INF("p9_extract_sbe_rc : Use SRR0 as IAR");
            l_data32_iar = l_data32_srr0;
        }

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

        //Program Interrupt
        if(MCS == 0x4 ||
           (l_data32_lr - 0x4) == PIBMEM_PROG_EXCEPTION_LOCATION ||
           (l_data32_lr - 0x4) == OTPROM_PROG_EXCEPTION_LOCATION )
        {
            if((OTPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= OTPROM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Program Interrupt occured in OTPROM memory program");

                if(!l_is_ndd1)
                {
                    fapi2::buffer<uint8_t> l_sbe_code_state;
                    FAPI_DBG("p9_extract_sbe_rc : Reading SB_MSG register to collect SBE Code state bits");

                    if(l_is_HB_module && !i_set_sdb) //HB calling Master Proc or HB calling Slave after SMP
                    {
                        FAPI_TRY(getScom(i_target_chip, PERV_SB_MSG_SCOM, l_data64));
                        l_data64.extractToRight(l_sbe_code_state, 30, 2);
                    }
                    else
                    {
                        FAPI_TRY(getCfamRegister(i_target_chip, PERV_SB_MSG_FSI, l_data32));
                        l_data32.extractToRight(l_sbe_code_state, 30, 2);
                    }

                    if(l_sbe_code_state == 0x1)
                    {
                        o_return_action = P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
                        FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_MAGIC_NUMBER_MISMATCH()
                                    .set_TARGET_CHIP(i_target_chip),
                                    "ERROR:Program Interrupt occured, probably MAGIC NUMBER MISMATCH");

                    }
                    else if(l_sbe_code_state == 0x2)
                    {
                        o_return_action = P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
                        FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_SBE_L1_LOADER_FAIL()
                                    .set_TARGET_CHIP(i_target_chip),
                                    "ERROR:Program Interrupt occured during base loader (l1)");

                    }
                    else if(l_sbe_code_state == 0x3)
                    {
                        o_return_action = P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
                        FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_SBE_L2_LOADER_FAIL()
                                    .set_TARGET_CHIP(i_target_chip),
                                    "ERROR:Program Interrupt occured during pk loader")
                    }
                    else
                    {
                        FAPI_ERR("p9_extract_sbe_rc : SBE code state value = %02X is invalid", l_sbe_code_state);
                    }
                }
            }
            else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Program Interrupt occured in PIBMEM memory program");
            }
            else if((SEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= SEEPROM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Program Interrupt occured in SEEPROM memory program");
            }
            else
            {
                FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Program Interrupt", l_data32_iar);
            }

            o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_PROGRAM_INTERRUPT()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Program interrupt occured for IAR=%08lX and EDR=%08lX", l_data32_iar, l_data32_edr);
        }
        // Instruction storage interrupt
        else if(MCS == 0x5 ||
                (l_data32_lr - 0x4) == PIBMEM_INST_STORE_INTR_LOCATION ||
                (l_data32_lr - 0x4) == OTPROM_INST_STORE_INTR_LOCATION )
        {
            if((OTPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= OTPROM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Instruction storage interrupt occured for OTPROM memory range");
            }
            else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Instruction storage interrupt occured for PIBMEM memory range");
            }
            else if((SEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= SEEPROM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Instruction storage interrupt occured for SEEPROM memory range");
            }
            else
            {
                FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Instruction storage interrupt", l_data32_iar);
            }

            o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_INST_STORE_INTR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Instruction storage interrupt for IAR=%08lX and EDR=%08lX", l_data32_iar, l_data32_edr);
        }
        // Alignment interrupt
        else if(MCS == 0x6 ||
                (l_data32_lr - 0x4) == PIBMEM_ALIGN_INTR_LOCATION ||
                (l_data32_lr - 0x4) == OTPROM_ALIGN_INTR_LOCATION )
        {
            if((OTPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= OTPROM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Alignment interrupt occured for OTPROM memory range");
            }
            else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Alignment interrupt occured for PIBMEM memory range");
            }
            else if((SEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= SEEPROM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Alignment interrupt occured for SEEPROM memory range");
            }
            else
            {
                FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Alignment interrupt", l_data32_iar);
            }

            o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_ALIGN_INTR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Alignment interrupt for IAR=%08lX and EDR=%08lX", l_data32_iar, l_data32_edr);
        }
        // Data storage interrupt
        else if(MCS == 0x7 ||
                (l_data32_lr - 0x4) == PIBMEM_DATA_STORE_INTR_LOCATION ||
                (l_data32_lr - 0x4) == OTPROM_DATA_STORE_INTR_LOCATION )
        {
            if((OTPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= OTPROM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Data storage interrupt occured for OTPROM memory range");
            }
            else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Data storage interrupt occured for PIBMEM memory range");
            }
            else if((SEEPROM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= SEEPROM_MAX_RANGE))
            {
                FAPI_ERR("p9_extract_sbe_rc : Data storage interrupt occured for SEEPROM memory range");
            }
            else
            {
                FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Data storage interrupt", l_data32_iar);
            }

            o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_DATA_STORE_INTR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Data storage interrupt for IAR=%08lX ", l_data32_iar);
        }
        else
        {
            switch (MCS)
            {
                case 0x0 :
                    FAPI_ERR("p9_extract_sbe_rc : Instruction machine check at Address = %08lX", l_data32_iar);
                    l_data_mchk = true;
                    break;

                case 0x1 :
                    FAPI_ERR("p9_extract_sbe_rc : Data machine check - load for EDR = %08lX", l_data32_edr);
                    l_data_mchk = true;
                    break;

                case 0x2 :
                    FAPI_ERR("p9_extract_sbe_rc : Data machine check - precise store for EDR = %08lX", l_data32_edr);
                    l_data_mchk = true;
                    break;

                case 0x3 :
                    FAPI_ERR("p9_extract_sbe_rc : Data machine check - imprecise store for EDR = %08lX", l_data32_edr);
                    l_data_mchk = true;
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
                            fapi2::EXTRACT_SBE_RC_OTP_ECC_ERR_NONSECURE_MODE()
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

        if(pibmem_addr_range) // PIBMEM status register read is allowed in both Secure & NonSecure mode
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
                        fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_ERR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Uncorrectable error occurred while accessing memory via PIB side");

            o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
            FAPI_ASSERT(l_data64.getBit<PU_PIBMEM_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES>() != 1,
                        fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_ERR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:Uncorrectable error occurred while accessing memory via fast access side");
        }

        if(seeprom_addr_range && (i_unsecure_mode || !i_set_sdb))
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
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_FI2CM_BIT_RATE_ERR_NONSECURE_MODE()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Speed on the I2C bit rate divisor is less than min speed value (0x0003), I2C Speed read is %04lX", i2c_speed);
            }

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
                        fapi2::EXTRACT_SBE_RC_FI2C_ERR_NONSECURE_MODE()
                        .set_TARGET_CHIP(i_target_chip),
                        "FI2C I2C Error detected");

            o_return_action = P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
            FAPI_ASSERT(l_data64_fi2c_status.getBit<PU_STATUS_REGISTER_B_ECC_UNCORRECTED_ERROR_0>() != 1,
                        fapi2::EXTRACT_SBE_RC_FI2C_ECC_ERR_NONSECURE_MODE()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:There are 2 bit flips in read data which cannot be corrected");
        }

        if(seeprom_addr_range && (l_pibmem_saveoff || i_set_sdb))
        {
            l_data32.flush<0>();
            l_data64_loc_fi2c_cnfg.extractToRight(l_data32, 20, 16);
            uint32_t i2c_speed = l_data32;

            if(i2c_speed < 0x0003)
            {
                o_return_action = P9_EXTRACT_SBE_RC::RESTART_SBE;
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_LOCAL_FI2C_BIT_RATE_ERROR()
                            .set_TARGET_CHIP(i_target_chip),
                            "ERROR:Speed on the I2C bit rate divisor is less than min speed value (0x0003), I2C Speed read is %04lX", i2c_speed);
            }

            // SBE Local FI2C Status register
            // PIB_response_info
            bool fi2c_cnfg_error = false;
            bool fi2c_ecc_error = false;

            l_data32.flush<0>();
            l_data64_loc_fi2c_status.extractToRight(l_data32, 0, 3);

            if(l_data32 != 0x0)
            {
                fi2c_cnfg_error = true;
                FAPI_ERR ("p9_extract_sbe_rc : FI2C_L::Response info from PIB for SBE communication is %01X", l_data32);
            }

            // I2CM_PIB_errors -- Bits 0 to 5 from the PIB_I2CM status register.
            if(l_data64_loc_fi2c_status.getBit<3>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Address invalid");
            }

            if(l_data64_loc_fi2c_status.getBit<4>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Write invalid");
            }

            if(l_data64_loc_fi2c_status.getBit<5>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Read invalid");
            }

            if(l_data64_loc_fi2c_status.getBit<6>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Address parity error");
            }

            if(l_data64_loc_fi2c_status.getBit<7>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Data parity error");
            }

            if(l_data64_loc_fi2c_status.getBit<8>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Local bus parity error");
            }

            // I2CM_ECC_errors -- Bits 41 to 43 from the PIB_I2CM status register.
            if(l_data64_loc_fi2c_status.getBit<9>())
            {
                FAPI_INF("p9_extract_sbe_rc : FI2C_L::ECC_CORRECTED_ERROR - This is a warning indicates that one bit flip was there in data and been corrected.");
            }

            if(l_data64_loc_fi2c_status.getBit<10>())
            {
                fi2c_ecc_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::ECC_UNCORRECTED_ERROR - This is the error indicating that there are 2 bit flips in read data which cannot be corrected.");
            }

            if(l_data64_loc_fi2c_status.getBit<11>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::ECC_CONFIG_ERROR - This the error indicating that control register is ecc_enabled for data_length not equal to 8. OR ECC is enabled for the engine where ECC block is not at all instantiated.");
            }

            // I2CM_I2C_errors -- Bits 45 to 50 and Bit 53 of the PIB_I2CM status register.
            if(l_data64_loc_fi2c_status.getBit<12>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Invalid command");
            }

            if(l_data64_loc_fi2c_status.getBit<13>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Parity Error");
            }

            if(l_data64_loc_fi2c_status.getBit<14>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Back end overrun error");
            }

            if(l_data64_loc_fi2c_status.getBit<15>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Back end access error");
            }

            if(l_data64_loc_fi2c_status.getBit<16>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Arbitration lost error; Probably PIB I2CM bit rate divisor is lessthan 0x0003");
            }

            if(l_data64_loc_fi2c_status.getBit<17>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - NACK receieved error");
            }

            if(l_data64_loc_fi2c_status.getBit<18>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR("p9_extract_sbe_rc : FI2C_L::BUS_STATUS - Stop error");
            }

            // Err_addr_beyond_range
            if(l_data64_loc_fi2c_status.getBit<19>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR ("p9_extract_sbe_rc : FI2C_L::This means the seeprom location addressed by PPE couldn't found.");
            }

            // Err_addr_overlap
            if(l_data64_loc_fi2c_status.getBit<20>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR ("p9_extract_sbe_rc : FI2C_L::This means the seeprom location addressed by PPE is overlapped with 2 SEEPROM configuration register.");
            }

            // PIB_ABORT
            if(l_data64_loc_fi2c_status.getBit<21>())
            {
                fi2c_cnfg_error = true;
                FAPI_ERR ("p9_extract_sbe_rc : FI2C_L::Reset from the PIB side when FI2C is busy");
            }

            // Locked_PIBM_ADDR
            l_data32.flush<0>();
            l_data64_loc_fi2c_status.extractToRight(l_data32, 32, 8);

            if(l_data32 != 0x0)
            {
                FAPI_ERR ("p9_extract_sbe_rc : FI2C_L::Locked PIBM address on PIB master when first error occured : 0x%02lX", l_data32);
            }

            // Locked_FSM_STATE
            l_data32.flush<0>();
            l_data64_loc_fi2c_status.extractToRight(l_data32, 43, 5);

            if(l_data32 != 0x0)
            {
                FAPI_ERR ("p9_extract_sbe_rc : FI2C_L::Locked FSM state when the first error occurred : 0x%02lX", l_data32);
            }

            // Locked_seeprom_address
            l_data32.flush<0>();
            l_data64_loc_fi2c_status.extractToRight(l_data32, 48, 16);

            if(l_data32 != 0x0)
            {
                FAPI_ERR ("p9_extract_sbe_rc : FI2C_L::Locked Seeprom address from PPE when first error occured : 0x%04lX", l_data32);
            }

            o_return_action = P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
            FAPI_ASSERT(!fi2c_ecc_error, fapi2::EXTRACT_SBE_RC_LOCAL_FI2C_ECC_ERR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:There is an ECC error reported in FI2C_L status register");

            o_return_action = P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
            FAPI_ASSERT(!fi2c_cnfg_error, fapi2::EXTRACT_SBE_RC_LOCAL_FI2C_STATUS_ERR()
                        .set_TARGET_CHIP(i_target_chip),
                        "ERROR:There is an error registered in local FI2C_L status register");
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

                if(sib_rsp_info != 0x0)
                {
                    FAPI_ERR("p9_extract_sbe_rc : SIB Error Rsp is 0x%X", sib_rsp_info);
                }
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
                FAPI_INF("p9_extract_sbe_rc : MIB MEM Info : %#018lX", l_data64_mib_mem_info);

                l_data32.flush<0>();
                l_data64_mib_mem_info.extractToRight(l_data32, PU_MIB_XIMEM_MEM_ERROR, PU_MIB_XIMEM_MEM_ERROR_LEN);
                mem_error = l_data32;

                if(mem_error != 0x0)
                {
                    FAPI_ERR("p9_extract_sbe_rc : MIB MEM Error info is 0x%X", mem_error);
                }

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
