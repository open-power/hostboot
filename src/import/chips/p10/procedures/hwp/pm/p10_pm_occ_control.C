/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_occ_control.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file  p10_pm_occ_control.C
/// @brief Initialize boot vector registers and control PPC405
///
/// *HWP HWP Owner      : Greg Still <stillgs @us.ibm.com>
/// *HWP FW Owner       : Prasad BG Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team           : PM
/// *HWP Level          : 3
/// *HWP Consumed by    : HS

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <p10_pm.H>
#include <p10_pm_occ_control.H>
#include <p10_pm_ocb_indir_setup_circular.H>
#include <p10_pm_ocb_indir_setup_linear.H>
#include <p10_pm_ocb_indir_access.H>
#include <p10_pm_utils.H>
#include <p10_hcd_common.H>
#include <p10_scom_proc.H>

#ifdef __HOSTBOOT_MODULE
    #include <util/misc.H>                   // Util::isSimicsRunning
#endif
// ----------------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------------
//
/// @brief enumerates opcodes for few instructions.
enum
{
    ORI_OPCODE        = 24,
    ORIS_OPCODE       = 25,
    LIS_OPCODE        = 15,
    BR_OPCODE         = 18,
    BCCTR_OPCODE      = 19,
    OPCODE_31         = 31,
    MTSPR_CONST1      = 467,
    BCCTR_CONST1      = 528,
    CTR               = 9,
    OCC_BOOT_OFFSET   = 0x40,
    OCC_SRAM_BOOT_ADDR = 0xFFF40000,
    OCC_SRAM_BOOT_ADDR2 = 0xFFF40002,
    OCC_MEM_BOOT_PGMADDR = 0xFFF40000,
};

enum PPC_BRANCH_INSTR
{
    // Branch Absolute 0xFFF40002  (boot from sram)
    PPC405_BRANCH_SRAM_INSTR = 0x4BF40002,
    // Branch Absolute 0x00000040  (boot from memory)
    PPC405_BRANCH_MEM_INSTR  = 0x48000042,
    // Branch Relative -16         (boot from sram)
    PPC405_BRANCH_OLD_INSTR  = 0x4BFFFFF0
};

enum DELAY_VALUE
{
    NS_DELAY = 1000000,// 1,000,000 ns = 1ms
    SIM_CYCLE_DELAY = 10000
};

// OCR Register Bits
static const uint32_t OCB_PIB_OCR_CORE_RESET_BIT = 0;
static const uint32_t OCB_PIB_OCR_OCR_DBG_HALT_BIT = 10;  // HW434437 this bit isn't connected

// OCC JTAG Register Bits
static const uint32_t JTG_PIB_OJCFG_DBG_HALT_BIT = 6;

// OCC LFIR Bits
static const uint32_t OCCLFIR_PPC405_DBGSTOPACK_BIT = 31;


//-----------------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------------
///
/// @brief generates ori instruction code.
/// @param[in]   i_Rs    Source register number
/// @param[in]   i_Ra    Destination regiser number
/// @param[in]   i_data  16 bit immediate data
/// @return  returns 32 bit instruction representing ori instruction.
///
uint32_t ppc_ori( const uint16_t i_Rs, const uint16_t i_Ra,
                  const uint16_t i_data )
{
    uint32_t oriInstOpcode = 0;
    oriInstOpcode = ORI_OPCODE << (31 - 5);
    oriInstOpcode |= i_Rs << (31 - 10);
    oriInstOpcode |= i_Ra << (31 - 15);
    oriInstOpcode |= i_data;

    return oriInstOpcode;
}

///
/// @brief generates lis (eg addis to 0) instruction code.
/// @param[in]   i_Rt    Target register number
/// @param[in]   i_data  16 bit immediate data
/// @return  returns 32 bit instruction representing lis instruction.
///
uint32_t ppc_lis( const uint16_t i_Rt,
                  const uint16_t i_data )
{
    uint32_t lisInstOpcode = 0;
    lisInstOpcode = LIS_OPCODE << (31 - 5);
    lisInstOpcode |= i_Rt << (31 - 10);
    lisInstOpcode |= i_data;

    return lisInstOpcode;
}

///
/// @brief generates branch absolute instruction code.
/// @param[in]   i_TargetAddr  Target address
/// @return  returns 32 bit instruction representing branch absolute instruction.
///
uint32_t ppc_b( const uint32_t i_TargetAddr)
{
    uint32_t brInstOpcode = 0;
    brInstOpcode = BR_OPCODE << (31 - 5);
    brInstOpcode |= (i_TargetAddr & 0x03FFFFFF);

    return brInstOpcode;
}

///
/// @brief generates branch conditional to count register instruction code.
/// @return  returns 32 bit instruction representing branch absolute instruction.
//
uint32_t ppc_bctr( )
{
    uint32_t bctrInstOpcode = 0;
    bctrInstOpcode  = BCCTR_OPCODE << (31 - 5);
    bctrInstOpcode |= 20 << (31 - 10); // BO
    // BI = 0 taken care by bctrInstOpcode = 0
    bctrInstOpcode |= BCCTR_CONST1 << 1;

    return bctrInstOpcode;
}

///
/// @brief generates instruction for mtspr
/// @param[in] i_Rs      source register number
/// @param[in] i_Spr represents spr where data is to be moved.
/// @return returns 32 bit instruction representing mtspr instruction.
///
uint32_t ppc_mtspr( const uint16_t i_Rs, const uint16_t i_Spr )
{
    uint32_t mtsprInstOpcode = 0;
    mtsprInstOpcode = OPCODE_31 << (31 - 5);
    mtsprInstOpcode |= i_Rs << (31 - 10);
    uint32_t temp = (( i_Spr & 0x03FF ) << (31 - 20));
    mtsprInstOpcode |= ( temp  & 0x0000F800 ) << 5;  // Perform swizzle
    mtsprInstOpcode |= ( temp & 0x001F0000 ) >> 5;  // Perform swizzle
    mtsprInstOpcode |= MTSPR_CONST1 << 1;

    return mtsprInstOpcode;
}

///
/// @brief Creates and loads the OCC memory boot launcher
/// @param[in] i_target  Chip target
/// @param[in] i_data64  32 bit instruction representing the branch
///                    instruction to the SRAM boot loader
/// @return FAPI2_RC_SUCCESS on success, else error
///
fapi2::ReturnCode bootMemory(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    fapi2::buffer<uint64_t>& i_data64)
{
    static const uint32_t SRAM_PROGRAM_SIZE = 2;  // in double words
    uint64_t l_sram_program[SRAM_PROGRAM_SIZE];
    fapi2::ReturnCode l_rc;
    uint32_t l_ocb_length_act = 0;

    // Setup use OCB channel 1 for placing instruction in SRAM
    // Channel will be returned to Linear Stream, Circular upon exit
    FAPI_EXEC_HWP(l_rc, p10_pm_ocb_indir_setup_linear, i_target,
                  ocb::OCB_CHAN1,
                  ocb::OCB_TYPE_LINSTR,
                  OCC_SRAM_BOOT_ADDR);   // Bar
    FAPI_TRY(l_rc);


    // lis r1, 0x8000
    l_sram_program[0] = ((uint64_t)ppc_lis(1, 0x8000) << 32);
    FAPI_DBG("ppc_lis: 0x%08X with data 0x%08X",
             ppc_lis(1, 0x8000), 0x8000);

    // ori r1, r1, OCC_BOOT_OFFSET
    l_sram_program[0] |= (ppc_ori(1, 1, OCC_BOOT_OFFSET));
    FAPI_DBG("ppc_ori: 0x%08X with data 0x%08X",
             ppc_ori(1, 1, OCC_BOOT_OFFSET), OCC_BOOT_OFFSET);

    // mtctr (mtspr r1, CTR )
    l_sram_program[1] = ((uint64_t)ppc_mtspr(1, CTR) << 32);
    FAPI_DBG("ppc_mtspr: 0x%08X with spr 0x%08X",
             ppc_mtspr(1, CTR), CTR);

    // bctr
    l_sram_program[1] |= ppc_bctr();
    FAPI_DBG("ppc_bctr: 0x%08X", ppc_bctr());

    FAPI_DBG("SRAM PGM[0]: 0x%016llX", l_sram_program[0]);
    FAPI_DBG("SRAM PGM[1]: 0x%016llX", l_sram_program[1]);

    // Write to SRAM
    FAPI_EXEC_HWP(l_rc, p10_pm_ocb_indir_access, i_target,
                  ocb::OCB_CHAN1,
                  ocb::OCB_PUT,
                  SRAM_PROGRAM_SIZE,
                  false,
                  0,
                  l_ocb_length_act,
                  l_sram_program);

    FAPI_ASSERT(l_ocb_length_act == SRAM_PROGRAM_SIZE,
                fapi2::OCC_CONTROL_MEM_BOOT_LENGTH_MISMATCH()
                .set_ACTLENGTH(l_ocb_length_act)
                .set_LENGTH(SRAM_PROGRAM_SIZE),
                "OCC memory boot launcher length mismatch");

    // b OCC_SRAM_BOOT_ADDR2
    i_data64.insertFromRight<0, 32>(ppc_b(OCC_SRAM_BOOT_ADDR2));

fapi_try_exit:
    // Channel 1 returned to Linear Stream, Circular upon exit
    FAPI_EXEC_HWP(l_rc, p10_pm_ocb_indir_setup_circular, i_target,
                  ocb::OCB_CHAN1,
                  ocb::OCB_TYPE_CIRC,
                  0,   // Bar
                  0,   // Length
                  ocb::OCB_Q_OUFLOW_NULL,
                  ocb::OCB_Q_ITPTYPE_NULL);
    fapi2::current_err = l_rc;

    return fapi2::current_err;
}


static const uint32_t OCC_HB_TIMEOUT_MS       = 2000;
static const uint32_t OCC_HB_TIMEOUT_MCYCLES  = 100;
static const uint32_t OCC_HB_POLLTIME_MS      = 20;
static const uint32_t OCC_HB_POLLTIME_MCYCLES = 20;
static const uint32_t TIMEOUT_COUNT = OCC_HB_TIMEOUT_MS / OCC_HB_POLLTIME_MS;
///
/// @brief Poll for OCC Heartbeat Enablement
/// @param[in] i_target  Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error
///
fapi2::ReturnCode pollOCCHearbeat(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

#ifdef __HOSTBOOT_MODULE
    using namespace scomt;
    using namespace proc;

    fapi2::buffer<uint64_t>  l_occhbr;
    uint32_t                 l_timeout_counter = TIMEOUT_COUNT;

    FAPI_DBG("OCC heartbeat polling...");

    do
    {
        FAPI_TRY(GET_TP_TPCHIP_OCC_OCI_OCB_OCCHBR(i_target, l_occhbr));
        FAPI_DBG("OCC Heartbeat Reg: 0x%016lx; Timeout: %d",
                 l_occhbr, l_timeout_counter);
        // fapi2::delay takes ns as the arg
        fapi2::delay(OCC_HB_POLLTIME_MS * 1000 * 1000, OCC_HB_POLLTIME_MCYCLES * 1000 * 1000);
    }
    while((l_occhbr.getBit<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN>() != 1) &&
          (--l_timeout_counter != 0));

    FAPI_ASSERT((l_timeout_counter &&
                 l_occhbr.getBit<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN>()),
                fapi2::OCC_START_TIMEOUT()
                .set_CHIP(i_target),
                "OCC Start via Heartbeat enable timeout");

    FAPI_INF("OCC was activated successfully!!!!");

#endif
fapi_try_exit:
    return fapi2::current_err;

}

fapi2::ReturnCode p10_pm_occ_control
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
 const occ_ctrl::PPC_CONTROL i_ppc405_reset_ctrl,
 const occ_ctrl::PPC_BOOT_CONTROL i_ppc405_boot_ctrl,
 const uint64_t i_ppc405_jump_to_main_instr)
{

    using namespace scomt;
    using namespace proc;

    FAPI_IMP("Entering p10_pm_occ_control ....");

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_firMask;
    fapi2::buffer<uint64_t> l_occfir;
    fapi2::buffer<uint64_t> l_jtagcfg;

    // Set up Boot Vector Registers in SRAM
    //    - set bv0-2 to all 0's (illegal instructions)
    //    - set bv3 to proper branch instruction

    if (i_ppc405_boot_ctrl != occ_ctrl::PPC405_BOOT_NULL)
    {
        FAPI_DBG("Writing to Boot Vector 0-2 Registers");

        PREP_TP_TPCHIP_OCC_SRAM_CTL_SRBV0(i_target);
        FAPI_TRY(PUT_TP_TPCHIP_OCC_SRAM_CTL_SRBV0(i_target, l_data64));
        PREP_TP_TPCHIP_OCC_SRAM_CTL_SRBV1(i_target);
        FAPI_TRY(PUT_TP_TPCHIP_OCC_SRAM_CTL_SRBV1(i_target, l_data64));
        PREP_TP_TPCHIP_OCC_SRAM_CTL_SRBV2(i_target);
        FAPI_TRY(PUT_TP_TPCHIP_OCC_SRAM_CTL_SRBV2(i_target, l_data64));

        if (i_ppc405_boot_ctrl == occ_ctrl::PPC405_BOOT_SRAM)
        {
            FAPI_DBG("Writing to Boot Vector 3 Register");
            l_data64.flush<0>().insertFromRight(PPC405_BRANCH_SRAM_INSTR, 0, 32);
        }
        else if (i_ppc405_boot_ctrl == occ_ctrl::PPC405_BOOT_MEM)
        {
            FAPI_INF("Setting up for memory boot");
            FAPI_TRY(bootMemory(i_target, l_data64), "Booting from Memory Failed");
        }
        else if(i_ppc405_boot_ctrl == occ_ctrl::PPC405_BOOT_WITHOUT_BL)
        {
            FAPI_DBG("Setting up for boot without bootloader");
            l_data64.flush<0>().insertFromRight(i_ppc405_jump_to_main_instr, 0, 64);
        }
        else
        {
            l_data64.flush<0>().insertFromRight(PPC405_BRANCH_OLD_INSTR, 0, 32);
        }

        PREP_TP_TPCHIP_OCC_SRAM_CTL_SRBV3(i_target);
        FAPI_TRY(PUT_TP_TPCHIP_OCC_SRAM_CTL_SRBV3(i_target, l_data64));
    }

    // Handle the i_ppc405_reset_ctrl parameter
    switch (i_ppc405_reset_ctrl)
    {
        case occ_ctrl::PPC405_RESET_NULL:
            FAPI_INF("No action to be taken for PPC405");
            break;

        case occ_ctrl::PPC405_RESET_OFF:

            PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR(i_target,
                     BIT64(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET)));
            break;

        case occ_ctrl::PPC405_RESET_ON:
            PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR(i_target,
                     BIT64(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET)));
            break;

        case occ_ctrl::PPC405_HALT_OFF:
            PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND(i_target,
                     ~BIT64(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT)));
            break;

        case occ_ctrl::PPC405_HALT_ON:
            PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR(i_target,
                     BIT64(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT)));
            break;

        case occ_ctrl::PPC405_RESET_SEQUENCE:

            /// It is unsafe in general to simply reset the 405, as this is an
            /// asynchronous reset that can leave OCI slaves in unrecoverable
            /// states.
            /// This is a "safe" reset-entry sequence that includes
            /// halting the 405 (a synchronous operation) before issuing the
            /// reset. Since this sequence halts/unhalts the 405 and modifies
            /// FIRs it is called apart from the simple PPC405_RESET_OFF
            /// that simply sets the 405 reset bit.
            ///
            /// The sequence:
            ///
            /// 1. Mask the "405 halted" FIR bit to avoid FW thinking the halt
            /// we are about to inject on the 405 is an error.
            ///
            /// 2. Halt the 405. If the 405 does not halt in 1ms we note that
            /// but press on, hoping (probably in vain) that any subsequent
            /// reset actions will clear up the issue.
            /// To check if the 405 halted we must clear the FIR and verify
            /// that the FIR is set again.
            ///
            /// 3. Put the 405 into reset.
            ///
            /// 4. Clear the halt bit.
            ///
            /// 5. Restore the original FIR mask
            /// Save the FIR mask, and mask the halted FIR

            FAPI_DBG("Performing the RESET SEQUENCE");

            FAPI_TRY(GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW(i_target, l_firMask));
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_WO_OR(i_target,
                     BIT64(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK)));

            // Halt the 405 and verify that it is halted
            PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_OR(i_target,
                     BIT64(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT)));

            FAPI_TRY(fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY));

            PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND(i_target,
                     ~BIT64(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK)));

            FAPI_TRY(GET_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_RW(i_target, l_occfir));

            if (!(l_occfir & BIT64(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK)))
            {
                FAPI_ERR("OCC will not halt. Pressing on, hoping for the best.");
            }

            // Put 405 into reset, unhalt 405 and clear the halted FIR bit.
            PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR(i_target,
                     BIT64(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET)));
            PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND(i_target,
                     ~BIT64(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT)));
            PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_AND(i_target,
                     ~BIT64(TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_PPC405_DBGSTOPACK)));

            // Restore the original FIR mask
            PREP_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_SCOM_OCCLFIRMASK_RW(i_target, l_firMask));
            break;

        case occ_ctrl::PPC405_START:

            FAPI_INF("Starting the PPC405");
            // Clear the halt bit of both JTAG and OCR
            PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR(i_target,
                     BIT64(OCB_PIB_OCR_OCR_DBG_HALT_BIT)));

            PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_WO_AND(i_target,
                     ~BIT64(TP_TPCHIP_OCC_OCI_OCB_PIB_OJCFG_DBG_HALT)));

            // Set the reset bit
            PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_OR(i_target,
                     BIT64(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET)));

            // Clear the reset bit
            PREP_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR(i_target);
            FAPI_TRY(PUT_TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_WO_CLEAR(i_target,
                     BIT64(TP_TPCHIP_OCC_OCI_OCB_PIB_OCR_CORE_RESET)));

#ifdef __HOSTBOOT_MODULE

            if (! Util::isSimicsRunning())
            {
#endif
                FAPI_TRY(pollOCCHearbeat(i_target));

#ifdef __HOSTBOOT_MODULE
            }

#endif


            break;

        default:
            break;
    }

fapi_try_exit:
    FAPI_IMP("Exiting p10_pm_occ_control ....");
    return fapi2::current_err;
}
