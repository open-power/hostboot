/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_occ_control.C $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file  p9_pm_occ_control.C
/// @brief Initialize boot vector registers and control PPC405
///
// *HWP HWP Owner: Greg Still <stillgs @us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <p9_pm.H>
#include <p9_pm_occ_control.H>
#include <p9_pm_ocb_indir_setup_circular.H>
#include <p9_pm_ocb_indir_setup_linear.H>
#include <p9_pm_ocb_indir_access.H>
#include <p9_pm_utils.H>

/**
 * @brief enumerates opcodes for few instructions.
 */
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
    OCC_MEM_BOOT_PGMADDR = 0xFFF40000,
};

//-----------------------------------------------------------------------------

/**
 * @brief generates ori instruction code.
 * @param[in]   i_Rs    Source register number
 * @param[in]   i_Ra    Destination regiser number
 * @param[in]   i_data  16 bit immediate data
 * @return  returns 32 bit instruction representing ori instruction.
 */
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


//-----------------------------------------------------------------------------

/**
 * @brief generates lis (eg addis to 0) instruction code.
 * @param[in]   i_Rt    Target register number
 * @param[in]   i_data  16 bit immediate data
 * @return  returns 32 bit instruction representing lis instruction.
 */
uint32_t ppc_lis( const uint16_t i_Rt,
                  const uint16_t i_data )
{
    uint32_t lisInstOpcode = 0;
    lisInstOpcode = LIS_OPCODE << (31 - 5);
    lisInstOpcode |= i_Rt << (31 - 10);
    lisInstOpcode |= i_data;

    return lisInstOpcode;
}


//-----------------------------------------------------------------------------

/**
 * @brief generates branch absolute instruction code.
 * @param[in]   i_TargetAddr  Target address
 * @return  returns 32 bit instruction representing branch absolute instruction.
 */
uint32_t ppc_b( const uint32_t i_TargetAddr)
{
    uint32_t brInstOpcode = 0;
    brInstOpcode = BR_OPCODE << (31 - 5);
    brInstOpcode |= (i_TargetAddr & 0x03FFFFFF);

    return brInstOpcode;
}

//-----------------------------------------------------------------------------

/**
 * @brief generates branch conditional to count register instruction code.
 * @return  returns 32 bit instruction representing branch absolute instruction.
 */
uint32_t ppc_bctr( )
{
    uint32_t bctrInstOpcode = 0;
    bctrInstOpcode  = BCCTR_OPCODE << (31 - 5);
    bctrInstOpcode |= 20 << (31 - 10); // BO
    // BI = 0 taken care by bctrInstOpcode = 0
    bctrInstOpcode |= BCCTR_CONST1 << 1;

    return bctrInstOpcode;
}

//-----------------------------------------------------------------------------

/**
 * @brief generates instruction for mtspr
 * @param[in] i_Rs      source register number
 * @param[in] i_Spr represents spr where data is to be moved.
 * @return returns 32 bit instruction representing mtspr instruction.
 */
uint32_t ppc_mtspr( const uint16_t i_Rs, const uint16_t i_Spr )
{
    uint32_t mtsprInstOpcode = 0;
    mtsprInstOpcode = OPCODE_31 << (31 - 5);
    uint32_t temp = (( i_Spr & 0x03FF ) << (31 - 20));
    mtsprInstOpcode |= ( temp  & 0x0000F800 ) << 5;  // Perform swizzle
    mtsprInstOpcode |= ( temp & 0x001F0000 ) >> 5;  // Perform swizzle
    mtsprInstOpcode |= MTSPR_CONST1 << 1;

    return mtsprInstOpcode;
}


/**
 * @brief Creates and loads the OCC memory boot launcher
 * @param[in] i_target  Chip target
 * @return returns 32 bit instruction representing mtspr instruction.
 */
fapi2::ReturnCode bootMemory(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    static const uint32_t SRAM_PROGRAM_SIZE = 2;  // in double words
    uint64_t l_sram_program[SRAM_PROGRAM_SIZE];
    fapi2::buffer<uint64_t> l_data64;
    fapi2::ReturnCode l_rc;
    uint32_t l_ocb_length_act = 0;

    // Setup use OCB channel 1 for placing instruction in SRAM
    // Channel will be returned to Linear Stream, Circular upon exit
    FAPI_EXEC_HWP(l_rc, p9_pm_ocb_indir_setup_linear, i_target,
                  p9ocb::OCB_CHAN1,
                  p9ocb::OCB_TYPE_LINSTR,
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

    // mtctr (mtspr CTR, r1 )
    l_sram_program[1] = ((uint64_t)ppc_mtspr(CTR, 1) << 32);
    FAPI_DBG("ppc_mtspr: 0x%08X with spr 0x%08X",
             ppc_mtspr(CTR, 1), CTR);

    // bctr
    l_sram_program[1] |= ppc_bctr();
    FAPI_DBG("ppc_bctr: 0x%08X", ppc_bctr());

    FAPI_DBG("SRAM PGM[0]: 0x%016llX", l_sram_program[0]);
    FAPI_DBG("SRAM PGM[1]: 0x%016llX", l_sram_program[1]);

    // Write to SRAM
    FAPI_EXEC_HWP(l_rc, p9_pm_ocb_indir_access, i_target,
                  p9ocb::OCB_CHAN1,
                  p9ocb::OCB_PUT,
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

    // b OCC_SRAM_BOOT_ADDR
    l_data64.insertFromRight<0, 32>(ppc_b(OCC_SRAM_BOOT_ADDR));

    // Write to SBV3
    FAPI_TRY(fapi2::putScom(i_target, PU_SRAM_SRBV3_SCOM, l_data64),
             "SRAM Boot Vector 3");

fapi_try_exit:
    // Channel 1 returned to Linear Stream, Circular upon exit
    FAPI_EXEC_HWP(l_rc, p9_pm_ocb_indir_setup_circular, i_target,
                  p9ocb::OCB_CHAN1,
                  p9ocb::OCB_TYPE_NULL,
                  0,   // Bar
                  0,   // Length
                  p9ocb::OCB_Q_OUFLOW_NULL,
                  p9ocb::OCB_Q_ITPTYPE_NULL);
    fapi2::current_err = l_rc;

    return fapi2::current_err;
}



// -----------------------------------------------------------------------------
//  Constant Defintions
// -----------------------------------------------------------------------------

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
static const uint32_t OCB_PIB_OCR_OCR_DBG_HALT_BIT = 10;

// OCC JTAG Register Bits
static const uint32_t JTG_PIB_OJCFG_DBG_HALT_BIT = 6;

// OCC LFIR Bits
static const uint32_t OCCLFIR_PPC405_DBGSTOPACK_BIT = 31;


// -----------------------------------------------------------------------------
//   Procedure Defintion
// -----------------------------------------------------------------------------
fapi2::ReturnCode p9_pm_occ_control
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
 const p9occ_ctrl::PPC_CONTROL i_ppc405_reset_ctrl,
 const p9occ_ctrl::PPC_BOOT_CONTROL i_ppc405_boot_ctrl)
{
    FAPI_IMP("Entering p9_pm_occ_control ....");

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_firMask;
    fapi2::buffer<uint64_t> l_occfir;
    fapi2::buffer<uint64_t> l_jtagcfg;

    // Set up Boot Vector Registers in SRAM
    //    - set bv0-2 to all 0's (illegal instructions)
    //    - set bv3 to proper branch instruction

    if (i_ppc405_boot_ctrl != p9occ_ctrl::PPC405_BOOT_NULL)
    {
        FAPI_DBG("Writing to Boot Vector 0-2 Registers");
        FAPI_TRY(fapi2::putScom(i_target, PU_SRAM_SRBV0_SCOM, l_data64));
        FAPI_TRY(fapi2::putScom(i_target, PU_SRAM_SRBV1_SCOM, l_data64));
        FAPI_TRY(fapi2::putScom(i_target, PU_SRAM_SRBV2_SCOM, l_data64));



        if (i_ppc405_boot_ctrl == p9occ_ctrl::PPC405_BOOT_SRAM)
        {
            FAPI_DBG("Writing to Boot Vector 3 Register");
            l_data64.flush<0>().insertFromRight(PPC405_BRANCH_SRAM_INSTR, 0, 32);
        }
        else if (i_ppc405_boot_ctrl == p9occ_ctrl::PPC405_BOOT_MEM)
        {
            FAPI_INF("Setting up for memory boot");
            FAPI_TRY(bootMemory(i_target), , "Booting from Memory Failed");
        }
        else
        {
            l_data64.flush<0>().insertFromRight(PPC405_BRANCH_OLD_INSTR, 0, 32);
        }

        FAPI_TRY(fapi2::putScom(i_target, PU_SRAM_SRBV3_SCOM, l_data64));
    }

    // Handle the i_ppc405_reset_ctrl parameter
    switch (i_ppc405_reset_ctrl)
    {
        case p9occ_ctrl::PPC405_RESET_NULL:
            FAPI_INF("No action to be taken for PPC405");
            break;

        case p9occ_ctrl::PPC405_RESET_OFF:
            FAPI_TRY(fapi2::putScom(i_target,
                                    PU_OCB_PIB_OCR_CLEAR,
                                    ~BIT(OCB_PIB_OCR_CORE_RESET_BIT)));
            break;

        case p9occ_ctrl::PPC405_RESET_ON:
            FAPI_TRY(fapi2::putScom(i_target,
                                    PU_OCB_PIB_OCR_OR,
                                    BIT(OCB_PIB_OCR_CORE_RESET_BIT)));
            break;

        case p9occ_ctrl::PPC405_HALT_OFF:
            FAPI_TRY(fapi2::putScom(i_target,
                                    PU_JTG_PIB_OJCFG_AND,
                                    ~BIT(OCB_PIB_OCR_OCR_DBG_HALT_BIT)));
            break;

        case p9occ_ctrl::PPC405_HALT_ON:
            FAPI_TRY(fapi2::putScom(i_target,
                                    PU_JTG_PIB_OJCFG_OR,
                                    BIT(OCB_PIB_OCR_OCR_DBG_HALT_BIT)));
            break;

        case p9occ_ctrl::PPC405_RESET_SEQUENCE:

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
            FAPI_TRY(fapi2::getScom(i_target,
                                    PERV_TP_OCC_SCOM_OCCLFIRMASK,
                                    l_firMask));
            FAPI_TRY(fapi2::putScom(i_target,
                                    PERV_TP_OCC_SCOM_OCCLFIRMASK_OR,
                                    BIT(OCCLFIR_PPC405_DBGSTOPACK_BIT)));

            // Halt the 405 and verify that it is halted
            FAPI_TRY(fapi2::putScom(i_target,
                                    PU_OCB_PIB_OCR_OR,
                                    BIT(OCB_PIB_OCR_OCR_DBG_HALT_BIT)));

            FAPI_TRY(fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY));

            FAPI_TRY(fapi2::putScom(i_target,
                                    PERV_TP_OCC_SCOM_OCCLFIR_AND,
                                    ~BIT(OCCLFIR_PPC405_DBGSTOPACK_BIT)));

            FAPI_TRY(fapi2::getScom(i_target,
                                    PERV_TP_OCC_SCOM_OCCLFIR,
                                    l_occfir));

            if (!(l_occfir & BIT(OCCLFIR_PPC405_DBGSTOPACK_BIT)))
            {
                FAPI_ERR("OCC will not halt. Pressing on, hoping for the best.");
            }

            // Put 405 into reset, unhalt 405 and clear the halted FIR bit.
            FAPI_TRY(fapi2::putScom(i_target,
                                    PU_OCB_PIB_OCR_OR,
                                    BIT(OCB_PIB_OCR_CORE_RESET_BIT)));
            FAPI_TRY(fapi2::putScom(i_target,
                                    PU_OCB_PIB_OCR_CLEAR,
                                    BIT(OCB_PIB_OCR_OCR_DBG_HALT_BIT)));
            FAPI_TRY(fapi2::putScom(i_target,
                                    PERV_TP_OCC_SCOM_OCCLFIR_AND,
                                    ~BIT(OCCLFIR_PPC405_DBGSTOPACK_BIT)));
            // Restore the original FIR mask
            FAPI_TRY(fapi2::putScom(i_target,
                                    PERV_TP_OCC_SCOM_OCCLFIRMASK,
                                    l_firMask));
            break;

        case p9occ_ctrl::PPC405_START:

            // Check the JTAG Halt bit is off as the the PPC405 won't actually start
            // if this bit is on (controlled by RiscWatch)
            FAPI_TRY(fapi2::getScom(i_target, PU_JTG_PIB_OJCFG, l_jtagcfg));

            FAPI_ASSERT (!(l_jtagcfg.getBit<JTG_PIB_OJCFG_DBG_HALT_BIT>()),
                         fapi2::OCC_CONTROL_NONSTART_DUE_TO_RISCWATCH()
                         .set_JTAGCFG(l_jtagcfg),
                         "OCC will not start as the JTAG halt from RiscWatch is currently set");

            FAPI_INF("Starting the PPC405");
            // Clear the halt bit
            FAPI_TRY(fapi2::putScom(i_target,
                                    PU_OCB_PIB_OCR_CLEAR,
                                    BIT(OCB_PIB_OCR_OCR_DBG_HALT_BIT)));
            // Clear the reset bit
            FAPI_TRY(fapi2::putScom(i_target,
                                    PU_OCB_PIB_OCR_CLEAR,
                                    BIT(OCB_PIB_OCR_CORE_RESET_BIT)));

            break;

        default:
            break;
    }

fapi_try_exit:
    FAPI_IMP("Exiting p9_pm_occ_control ....");
    return fapi2::current_err;
}

