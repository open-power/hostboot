/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/ody_extract_sbe_rc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
/// @file  ody_extract_sbe_rc.C
/// @brief Check for errors on the SPPE, OTPROM, PIBMEM & PNOR
//------------------------------------------------------------------------------
// *HWP HW Owner        : Sandeep Korrapati <sakorrap@in.ibm.com>
// *HWP HW Backup Owner : Sreekanth Reddy <skadapal@in.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : SP:HB
//------------------------------------------------------------------------------

#include <ody_extract_sbe_rc.H>
#include <ody_scom_ody.H>
#include <ody_scom_perv.H>

using namespace fapi2;
using namespace scomt::ody;
using namespace scomt::perv;

SCOMT_PERV_USE_CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS;
SCOMT_PERV_USE_CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG;
SCOMT_ODY_USE_T_TPCHIP_PIB_SPPE_SBEPM_SBEPPE_PPE_XIDBGPRO;
SCOMT_ODY_USE_T_TPCHIP_PIB_SPPE_SBEPM_SBEPPE_PPE_XIRAMDBG;
SCOMT_ODY_USE_T_TPCHIP_PIB_SPPE_SBEPM_SBEPPE_PPE_XIDBGINF;
SCOMT_ODY_USE_T_TPCHIP_PIB_SPPE_SBEPM_SBEPPE_PPE_XIRAMEDR;
SCOMT_PERV_USE_CFAM_FSI_W_OTPCTL_MAC_STATUS_REGISTER;
SCOMT_ODY_USE_T_TPCHIP_PIB_SPPE_SBEPM_MIB_XISIB;
SCOMT_ODY_USE_T_TPCHIP_PIB_SPPE_SBEPM_SBEPPE_MIB_PPE_XIMEM;
SCOMT_ODY_USE_T_TPCHIP_PIB_SPPE_SBEPRV_ACS_CTRL_COMP_PIBMEM_STATUS_REG;
SCOMT_PERV_USE_CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_13;

enum ODY_EXTRACT_SBE_RC_Private_Constants
{
    NUM_OF_LOCATION = 16,
    ADDR_REG_PIB  = 0xD0011,
    AUTO_INCR_REG = 0xD0013,
    PIBMEM_MIN_RANGE  = 0xFFF80000,
    PIBMEM_MAX_RANGE  = 0xFFFFFFFF,
    PIBMEM_ADDR_OFFSET = 0xFFF80000,
    PIBMEM_BLDR_PROG_EXCEPTION_LOCATION  = 0xFFFEE6E0,
    PIBMEM_BLDR_ALIGN_INTR_LOCATION      = 0xFFFEE6C0,
    PIBMEM_BLDR_DATA_STORE_INTR_LOCATION = 0xFFFEE660,
    PIBMEM_BLDR_INST_STORE_INTR_LOCATION = 0xFFFEE680,
    PIBMEM_RUNTIME_PROG_EXCEPTION_LOCATION  = 0xFFF800E0,
    PIBMEM_RUNTIME_ALIGN_INTR_LOCATION      = 0xFFF800C0,
    PIBMEM_RUNTIME_DATA_STORE_INTR_LOCATION = 0xFFF80060,
    PIBMEM_RUNTIME_INST_STORE_INTR_LOCATION = 0xFFF80080,
    SROM_BASE_ADDR    = 0xFFF70000,
    SROM_SIZE         = 0x10000,
    SROM_PROG_EXCEPTION_LOCATION  = 0xFFF700E0,
    SROM_ALIGN_INTR_LOCATION      = 0xFFF700C0,
    SROM_DATA_STORE_INTR_LOCATION = 0xFFF70060,
    SROM_INST_STORE_INTR_LOCATION = 0xFFF70080,
    NOR_SIDE_SIZE            = 0x00400000,
    NOR_SIDE_0_START_ADDR    = 0xFE000000,
    OTPROM_MIN_RANGE  = 0x000C0000,
    OTPROM_MAX_RANGE  = 0x000C0378,
    OTPROM_DATA_MIN_RANGE  = 0x00018000,
    OTPROM_DATA_MAX_RANGE  = 0x0001806F,
    SBE_PROGRESS_CODE_START_BIT = 28,
    SBE_PROGRESS_CODE_LENGTH = 4,
};

#define NOR_SIDE_1_START_ADDR      (NOR_SIDE_0_START_ADDR + NOR_SIDE_SIZE)
#define NOR_GOLDEN_SIDE_START_ADDR (NOR_SIDE_1_START_ADDR + NOR_SIDE_SIZE)
#define SROM_END_ADDR (SROM_BASE_ADDR + SROM_SIZE - 1)
#define NOR_END_ADDR (NOR_GOLDEN_SIDE_START_ADDR + NOR_SIDE_SIZE - 1)

ReturnCode ody_extract_sbe_rc(const Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              bool i_set_sdb,
                              bool i_use_scom)
{
    T_TPCHIP_PIB_SPPE_SBEPM_SBEPPE_PPE_XIDBGPRO_t PPE_XIDBGPRO;
    T_TPCHIP_PIB_SPPE_SBEPM_SBEPPE_PPE_XIRAMDBG_t PPE_XIRAMDBG;
    T_TPCHIP_PIB_SPPE_SBEPM_SBEPPE_PPE_XIDBGINF_t PPE_XIDBGINF;
    T_TPCHIP_PIB_SPPE_SBEPM_SBEPPE_PPE_XIRAMEDR_t PPE_XIRAMEDR;
    CFAM_FSI_W_OTPCTL_MAC_STATUS_REGISTER_t OTPCTL_MAC_STATUS_REGISTER;
    T_TPCHIP_PIB_SPPE_SBEPM_MIB_XISIB_t MIB_XISIB;
    T_TPCHIP_PIB_SPPE_SBEPM_SBEPPE_MIB_PPE_XIMEM_t MIB_PPE_XIMEM;
    T_TPCHIP_PIB_SPPE_SBEPRV_ACS_CTRL_COMP_PIBMEM_STATUS_REG_t PIBMEM_STATUS_REGISTER;
    CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_13_t SCRATCH_REGISTER_13;
    CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_t  SB_CS;
    CFAM_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_MSG_t SB_MSG;

    bool l_pibmem_saveoff;
    bool l_inst_mchk = false, l_data_mchk = false;
    bool pibmem_addr_range = false, nor_addr_range = false;
    bool otprom_data_range = false, pibmem_data_range = false, nor_data_range = false;
    uint8_t  HC, MCS, sib_rsp_info, mem_error, secure_boot_err_code;
    buffer<uint32_t> l_data32, l_data32_iar, l_data32_edr;// l_data32_edr,
    uint32_t ppe_dbg_loc;
    uint32_t l_data32_magicbyte = 0;
    uint32_t l_data32_srr0, l_data32_srr1 = 0, l_data32_isr = 0, l_data32_lr;
    uint32_t spi_clk_div, spi_clk_div_lfr, spi_config_val;
    buffer<uint64_t> l_data64 = 0;
    buffer<uint64_t> l_data64_lfr0 = 0, l_data64_lfr1 = 0, l_data64_eistr = 0, l_data64_eimr = 0, l_data64_eisr = 0;
    buffer<uint64_t> l_data64_spi0_status = 0, l_data64_spi0_config = 0, l_data64_spi0_clock_config = 0,
                     l_data64_otp_status = 0;
    buffer<uint64_t> l_data64_spi_status = 0, l_data64_spi_config = 0, l_data64_spi_clock_config = 0;
    buffer<uint64_t> l_data64_dbg[NUM_OF_LOCATION];

    FAPI_INF("Entering ...");

    if(i_use_scom) //HB calling proc over OMI interface
    {
        FAPI_INF("Reading Selfboot Message register...");
        FAPI_TRY(SB_MSG.getScom(i_target));

        FAPI_INF("Reading SCRATCH REGISTER 13");
        FAPI_TRY(SCRATCH_REGISTER_13.getScom(i_target));

        FAPI_INF("Reading Selfboot Control/Status register...");
        FAPI_TRY(SB_CS.getScom(i_target));

        if(i_set_sdb)
        {
            SB_CS.set_SECURE_DEBUG_MODE(1);
            FAPI_TRY(SB_CS.putScom(i_target));
        }
    }
    else
    {
        FAPI_INF("Reading Selfboot Message register...");
        FAPI_TRY(SB_MSG.getCfam(i_target));

        FAPI_INF("Reading SCRATCH REGISTER 13");
        FAPI_TRY(SCRATCH_REGISTER_13.getCfam(i_target));

        FAPI_INF("Reading Selfboot Control/Status register...");
        FAPI_TRY(SB_CS.getCfam(i_target));

        if(i_set_sdb)
        {
            SB_CS.set_SECURE_DEBUG_MODE(1);
            FAPI_TRY(SB_CS.putCfam(i_target));
        }
    }

    FAPI_INF("SB_MSG : %#018lX ", SB_MSG);
    FAPI_INF("SCRATCH_REGISTER_13 : %#018lX ", SCRATCH_REGISTER_13);
    FAPI_INF("SB_CS : %#018lX ", SB_CS);

    FAPI_INF("Reading PPE_XIDBGPRO to check halt state");
    FAPI_TRY(PPE_XIDBGPRO.getScom(i_target));
    l_data32_iar = PPE_XIDBGPRO.getBits<32, 32>(); //IAR 32 bits
    FAPI_INF("SPPE IAR : %#08lX", l_data32_iar);

    FAPI_ASSERT(PPE_XIDBGPRO.get_XSR_HS(), fapi2::SPPE_RUNNING()
                .set_TARGET_CHIP(i_target), "SPPE is in running state");

    FAPI_INF("Reading PPE_XIRAMDBG to get SPRG0");
    FAPI_TRY(PPE_XIRAMDBG.getScom(i_target));
    ppe_dbg_loc = PPE_XIRAMDBG.get_SPRG0();
    FAPI_INF("Data present in SPRG0 : %#08lX", ppe_dbg_loc);

    FAPI_INF("Reading PPE_XIDBGINF to get SRR0 and LR");
    FAPI_TRY(PPE_XIDBGINF.getScom(i_target));
    l_data32_srr0 = PPE_XIDBGINF.get_SRR0_SRR0();
    l_data32_lr = PPE_XIDBGINF.get_LR_LR();
    FAPI_INF(" SRR0 : %#08lX", l_data32_srr0);
    FAPI_INF(" LR   : %#08lX", l_data32_lr);

    if ((PIBMEM_MIN_RANGE <= ppe_dbg_loc) && (ppe_dbg_loc <= PIBMEM_MAX_RANGE))
    {
        FAPI_INF("SPRG0 has address with in PIBMEM range");
        uint32_t pibmem_dbg_loc = (ppe_dbg_loc - PIBMEM_ADDR_OFFSET) >> 3;

        FAPI_TRY(putScom(i_target, ADDR_REG_PIB, pibmem_dbg_loc));

        for(uint32_t i = 0; i < NUM_OF_LOCATION; i++)
        {
            FAPI_TRY(getScom(i_target, AUTO_INCR_REG, l_data64_dbg[i]));
        }

        l_data64_dbg[0].extractToRight(l_data32_magicbyte, 16, 8);

        if((l_data64_dbg[0].getBit<31>()) && (l_data32_magicbyte == 0xA5))
        {
            FAPI_INF("Valid Bit is set & MagicByte matches");
            l_pibmem_saveoff = true;

            l_data32 = 0;
            l_data64_dbg[0].extractToRight(l_data32, 0, 16);
            FAPI_INF("Structure Version : %#06lX", l_data32);

            l_data64_dbg[0].extractToRight(l_data32_srr0, 32, 32);
            l_data64_dbg[1].extractToRight(l_data32_srr1,  0, 32);
            l_data64_dbg[1].extractToRight(l_data32_isr , 32, 32);
            l_data64_dbg[2].extractToRight(l_data32_lr  , 0, 32);
            l_data64_dbg[3].extractToRight(l_data64_eimr  , 0, 64);
            l_data64_dbg[4].extractToRight(l_data64_eisr  , 0, 64);
            l_data64_dbg[5].extractToRight(l_data64_eistr  , 0, 64);
            l_data64_dbg[6].extractToRight(l_data64_lfr0  , 0, 64);
            l_data64_dbg[7].extractToRight(l_data64_lfr1  , 0, 64);
            l_data64_dbg[8].extractToRight(l_data64_otp_status, 0, 64);
            l_data64_dbg[9].extractToRight(l_data64_spi0_status, 0, 64);
            l_data64_dbg[10].extractToRight(l_data64_spi0_config, 0, 64);
            l_data64_dbg[11].extractToRight(l_data64_spi0_clock_config, 0, 64);
            FAPI_INF("SRR0  : %#010lX", l_data32_srr0);
            FAPI_INF("SRR1  : %#010lX", l_data32_srr1);
            FAPI_INF("ISR   : %#010lX", l_data32_isr);
            FAPI_INF("LR    : %#010lX", l_data32_lr);
            FAPI_INF("EIMR  : %#018lX", l_data64_eimr);
            FAPI_INF("EISR  : %#018lX", l_data64_eisr);
            FAPI_INF("EISTR : %#018lX", l_data64_eistr);
            FAPI_INF("LFR0  : %#018lX", l_data64_lfr0);
            FAPI_INF("LFR1  : %#018lX", l_data64_lfr1);
            FAPI_INF("OTP STATUS  : %#018lX", l_data64_otp_status);
            FAPI_INF("SPI STATUS  : %#018lX", l_data64_spi0_status);
            FAPI_INF("SPI CONFIG  : %#018lX", l_data64_spi0_config);
            FAPI_INF("SPI CLOCK CONFIG  : %#018lX", l_data64_spi0_clock_config);
        }

    }
    else
    {
        FAPI_INF("SPRG0 doesn't have address with in PIBMEM range");
    }

    HC = PPE_XIDBGPRO.get_XSR_HC();
    FAPI_INF("Halt condition : 0x%X", HC);

    switch(HC)
    {
        case 0x0 :
            FAPI_ERR("ERROR: Halt Condition is all Zero, SBE engine was probably never started or SBE got halted by programming XCR to halt");
            break;

        case 0x1 :
            FAPI_ERR("XCR[CMD] written 111 to force-halt the processor.");
            break;

        case 0x2 :
            FAPI_ERR("A second watchdog timer (WDT) event occurred while TCR[WRC]=11");
            break;

        case 0x3 :
            FAPI_ERR("Unmaskable interrupt halt");
            break;

        case 0x4 :
            FAPI_ERR("Debug halt");
            break;

        case 0x5 :
            FAPI_ERR("DBCR halt");
            break;

        case 0x6 :
            FAPI_ERR("The external halt_req input was active.");
            break;

        case 0x7 :
            FAPI_ERR("Hardware failure");
            break;

        default :
            FAPI_ERR("INVALID HALT CONDITION");
            break;
    }

    if(HC == 0x4 || HC == 0x5)
    {
        secure_boot_err_code = SCRATCH_REGISTER_13.getBits<20, 4>();
        FAPI_INF("Secure Boot Error Code : 0x%X", secure_boot_err_code);
        FAPI_ASSERT(secure_boot_err_code == 0x0,
                    fapi2::SECURE_BOOT_FAIL()
                    .set_TARGET_CHIP(i_target)
                    .set_ERROR_CODE(secure_boot_err_code)
                    .set_SCRATCH_REGISTER_13(SCRATCH_REGISTER_13)
                    .set_SB_MSG(SB_MSG),
                    "secure boot fail");
    }

    //Extract TRAP
    if(PPE_XIDBGPRO.get_XSR_TRAP())
    {
        FAPI_INF("TRAP Instruction Debug Event Occured");
    }

    //Extract IAC
    if(PPE_XIDBGPRO.get_XSR_IAC())
    {
        FAPI_INF("Instruction Address Compare Debug Event Occured");
    }

    //Extract DACR
    if(PPE_XIDBGPRO.get_XSR_RDAC())
    {
        FAPI_INF("Data Address Compare (Read) Debug Event Occured");
    }

    //Extract DACW
    if(PPE_XIDBGPRO.get_XSR_WDAC())
    {
        FAPI_INF("Data Address Compare (Write) Debug Event Occured");
    }

    //Extract WS
    if(PPE_XIDBGPRO.get_NULL_MSR_WE())
    {
        FAPI_INF("In WAIT STATE");
    }

    //Extract EP
    if(PPE_XIDBGPRO.get_XSR_EP())
    {
        FAPI_INF("Maskable Event Pending");
    }

    //Extract MFE
    if(PPE_XIDBGPRO.get_XSR_MFE())
    {
        FAPI_ERR("Multiple Fault Error Occured");
    }

    MCS = PPE_XIDBGPRO.get_XSR_MCS();

    FAPI_INF("Reading PPE_XIRAMEDR to get IR & EDR");
    FAPI_TRY(PPE_XIRAMEDR.getScom(i_target));
    l_data32_edr = PPE_XIRAMEDR.get_EDR();

    //Program Interrupt
    if(MCS == 0x4 ||
       ((l_data32_lr - 0x4) == PIBMEM_BLDR_PROG_EXCEPTION_LOCATION
        || (l_data32_lr - 0x4) == PIBMEM_RUNTIME_PROG_EXCEPTION_LOCATION) ||
       (l_data32_iar == SROM_PROG_EXCEPTION_LOCATION ))
    {
        if((SROM_BASE_ADDR <= l_data32_iar) && (l_data32_iar <= SROM_END_ADDR))
        {
            FAPI_ERR("Program Exception occured in SROM");
        }
        else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
        {
            FAPI_ERR("Program Interrupt occured in PIBMEM memory program");
        }
        else if((NOR_SIDE_0_START_ADDR <= l_data32_iar) && (l_data32_iar <= NOR_END_ADDR))
        {
            FAPI_ERR("Program Interrupt occured in NOR FLASH memory program");

            if((NOR_SIDE_0_START_ADDR <= l_data32_iar) && (l_data32_iar < NOR_SIDE_1_START_ADDR))
            {
                FAPI_ERR("ERROR: Program Interrupt occured in NOR SIDE 0");
            }
            else if((NOR_SIDE_1_START_ADDR <= l_data32_iar) && (l_data32_iar < NOR_GOLDEN_SIDE_START_ADDR))
            {
                FAPI_ERR("ERROR: Program Interrupt occured in NOR SIDE 1");
            }
            else if((NOR_GOLDEN_SIDE_START_ADDR <= l_data32_iar) && (l_data32_iar <= NOR_END_ADDR))
            {
                FAPI_ERR("ERROR: Program Interrupt occured in GOLDEN PARTITION");
            }
        }
        else
        {
            FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Program Interrupt", l_data32_iar);
        }

        FAPI_ASSERT(false, fapi2::PROGRAM_INTERRUPT()
                    .set_TARGET_CHIP(i_target),
                    "ERROR: Program interrupt occured for IAR=%08lX and EDR=%08lX", l_data32_iar, l_data32_edr);
    }
    // Instruction storage interrupt
    else if(MCS == 0x5 ||
            ((l_data32_lr - 0x4) == PIBMEM_BLDR_INST_STORE_INTR_LOCATION
             || (l_data32_lr - 0x4) == PIBMEM_RUNTIME_INST_STORE_INTR_LOCATION) ||
            (l_data32_iar == SROM_INST_STORE_INTR_LOCATION ))
    {
        if((SROM_BASE_ADDR <= l_data32_iar) && (l_data32_iar <= SROM_END_ADDR))
        {
            FAPI_ERR("Instruction storage interrupt occured in SROM address range");
        }
        else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
        {
            FAPI_ERR("Instruction storage interrupt occured in PIBMEM memory range");
        }
        else if((NOR_SIDE_0_START_ADDR <= l_data32_iar) && (l_data32_iar <= NOR_END_ADDR))
        {
            FAPI_ERR("Instruction storage interrupt occured in NOR FLASH memory range");
        }
        else
        {
            FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Instruction storage interrupt", l_data32_iar);
        }

        FAPI_ASSERT(false, fapi2::INST_STORE_INTR()
                    .set_TARGET_CHIP(i_target),
                    "ERROR:Instruction storage interrupt for IAR=%08lX and EDR=%08lX", l_data32_iar, l_data32_edr);
    }
    // Alignment interrupt
    else if(MCS == 0x6 ||
            ((l_data32_lr - 0x4) == PIBMEM_BLDR_ALIGN_INTR_LOCATION || (l_data32_lr - 0x4) == PIBMEM_RUNTIME_ALIGN_INTR_LOCATION) ||
            (l_data32_iar == SROM_ALIGN_INTR_LOCATION ))
    {
        if((SROM_BASE_ADDR <= l_data32_iar) && (l_data32_iar <= SROM_END_ADDR))
        {
            FAPI_ERR("Alignment interrupt occured in SROM address range");
        }
        else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
        {
            FAPI_ERR("Alignment interrupt occured in PIBMEM memory range");
        }
        else if((NOR_SIDE_0_START_ADDR <= l_data32_iar) && (l_data32_iar <= NOR_END_ADDR))
        {
            FAPI_ERR("Alignment interrupt occured in NOR FLASH memory range");
        }
        else
        {
            FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Alignment interrupt", l_data32_iar);
        }

        FAPI_ASSERT(false, fapi2::ALIGN_INTR()
                    .set_TARGET_CHIP(i_target),
                    "ERROR:Alignment interrupt for IAR=%08lX and EDR=%08lX", l_data32_iar, l_data32_edr);
    }
    // Data storage interrupt
    else if(MCS == 0x7 ||
            ((l_data32_lr - 0x4) == PIBMEM_BLDR_DATA_STORE_INTR_LOCATION
             || (l_data32_lr - 0x4) == PIBMEM_RUNTIME_DATA_STORE_INTR_LOCATION) ||
            (l_data32_iar == SROM_DATA_STORE_INTR_LOCATION ))
    {
        if((SROM_BASE_ADDR <= l_data32_iar) && (l_data32_iar <= SROM_END_ADDR))
        {
            FAPI_ERR("Data storage interrupt occured in SROM address range");
        }
        else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
        {
            FAPI_ERR("Data storage interrupt occured in PIBMEM memory range");
        }
        else if((NOR_SIDE_0_START_ADDR <= l_data32_iar) && (l_data32_iar <= NOR_END_ADDR))
        {
            FAPI_ERR("Data storage interrupt occured in NOR FLASH memory range");
        }
        else
        {
            FAPI_ERR("ERROR: IAR %08lX is out of range when MCS reported a Data storage interrupt", l_data32_iar);
        }

        FAPI_ASSERT(false, fapi2::DATA_STORE_INTR()
                    .set_TARGET_CHIP(i_target),
                    "ERROR:Data storage interrupt for IAR=%08lX ", l_data32_iar);
    }
    else
    {
        switch (MCS)
        {
            case 0x0 :
                FAPI_ERR("Instruction machine check at Address = %08lX", l_data32_iar);
                l_inst_mchk = true;
                break;

            case 0x1 :
                FAPI_ERR("Data machine check - load for EDR = %08lX", l_data32_edr);
                l_data_mchk = true;
                break;

            case 0x2 :
                FAPI_ERR("Data machine check - precise store for EDR = %08lX", l_data32_edr);
                l_data_mchk = true;
                break;

            case 0x3 :
                FAPI_ERR("Data machine check - imprecise store for EDR = %08lX", l_data32_edr);
                l_data_mchk = true;
                break;

            default :
                FAPI_ERR("INVALID Machine Check Status MCS=0x%x", MCS);
                break;
        }
    }

    if((SROM_BASE_ADDR <= l_data32_iar) && (l_data32_iar <= SROM_END_ADDR))
    {
        FAPI_INF("IAR contains SROM address");
    }
    else if((PIBMEM_MIN_RANGE <= l_data32_iar) && (l_data32_iar <= PIBMEM_MAX_RANGE))
    {
        FAPI_INF("IAR contains PIBMEM address");
        pibmem_addr_range = true;
    }
    else if((NOR_SIDE_0_START_ADDR <= l_data32_iar) && (l_data32_iar <= NOR_END_ADDR))
    {
        FAPI_INF("IAR contains NOR FLASH address");
        nor_addr_range = true;
    }
    else
    {
        FAPI_ASSERT(false, fapi2::ADDR_NOT_RECOGNIZED()
                    .set_TARGET_CHIP(i_target),
                    "ERROR:Address %08lX is out of range", l_data32_iar);
    }

    if(pibmem_addr_range && l_inst_mchk) // PIBMEM status register read is allowed in both Secure & NonSecure mode
    {
        FAPI_INF("Reading PIBMEM status register");
        FAPI_TRY(PIBMEM_STATUS_REGISTER.getScom(i_target));

        if(PIBMEM_STATUS_REGISTER.get_ADDR_INVALID_PIB())
        {
            FAPI_ERR("PIBMEM::Address which PIB is trying to access in PIBMEM is not valid one in PIBMEM");
        }

        if(PIBMEM_STATUS_REGISTER.get_WRITE_INVALID_PIB())
        {
            FAPI_ERR("PIBMEM::Address for which PIB is trying to write is not writable");
        }

        if(PIBMEM_STATUS_REGISTER.get_READ_INVALID_PIB())
        {
            FAPI_ERR("PIBMEM::Address for which PIB is trying to read is not readable");
        }

        if(PIBMEM_STATUS_REGISTER.get_ECC_UNCORRECTED_ERROR_PIB())
        {
            FAPI_ERR("PIBMEM::Uncorrectable error occurred while PIB memory read");
        }

        if(PIBMEM_STATUS_REGISTER.get_ECC_CORRECTED_ERROR_PIB())
        {
            FAPI_INF("PIBMEM::Corrected error in PIB mem read");
        }

        if(PIBMEM_STATUS_REGISTER.get_BAD_ARRAY_ADDRESS_PIB())
        {
            FAPI_ERR("PIBMEM::Wrong address accessd in indirect mode of operation from PIB side");
        }

        if(PIBMEM_STATUS_REGISTER.get_WRITE_RST_INTERRUPT_PIB())
        {
            FAPI_ERR("PIBMEM::Reset occurred during write operation to PIBMEM from PIB side");
        }

        if(PIBMEM_STATUS_REGISTER.get_READ_RST_INTERRUPT_PIB())
        {
            FAPI_ERR("PIBMEM::Reset occurred during read operation to PIBMEM from PIB side");
        }

        if(PIBMEM_STATUS_REGISTER.get_ADDR_INVALID_FACES())
        {
            FAPI_ERR("PIBMEM::Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM");
        }

        if(PIBMEM_STATUS_REGISTER.get_WRITE_INVALID_FACES())
        {
            FAPI_ERR("PIBMEM::Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM or not writable");
        }

        if(PIBMEM_STATUS_REGISTER.get_READ_INVALID_FACES())
        {
            FAPI_ERR("PIBMEM::Address which is given by Fast acesss interface, to access is not readable");
        }

        if(PIBMEM_STATUS_REGISTER.get_ECC_UNCORRECTED_ERROR_FACES())
        {
            FAPI_ERR("PIBMEM::Uncorrectable error occurred while fast acess interface read");
        }

        if(PIBMEM_STATUS_REGISTER.get_ECC_CORRECTED_ERROR_FACES())
        {
            FAPI_INF("PIBMEM::Corrected error in fast acess read operation");
        }

        if(PIBMEM_STATUS_REGISTER.get_BAD_ARRAY_ADDRESS_FACES())
        {
            FAPI_ERR("PIBMEM::Wrong address accessd in indirect mode of operation from fast acess interface");
        }

        if(PIBMEM_STATUS_REGISTER.get_WRITE_RST_INTERRUPT_FACES())
        {
            FAPI_ERR("PIBMEM::Reset occurred during write operation to PIBMEM from fast acess side");
        }

        if(PIBMEM_STATUS_REGISTER.get_READ_RST_INTERRUPT_FACES())
        {
            FAPI_ERR("PIBMEM::Reset occurred during read operation to PIBMEM from fast acess side");
        }

        //--  FAPI Asserts section for PIBMEM --//
        FAPI_ASSERT(PIBMEM_STATUS_REGISTER.get_ECC_UNCORRECTED_ERROR_PIB() != 0x1,
                    fapi2::PIBMEM_ECC_ERR()
                    .set_TARGET_CHIP(i_target)
                    .set_OCCURRENCE(1),
                    "ERROR: Uncorrectable error occurred while accessing memory via PIB side");

        FAPI_ASSERT(PIBMEM_STATUS_REGISTER.get_ECC_UNCORRECTED_ERROR_FACES() != 0x1,
                    fapi2::PIBMEM_ECC_ERR()
                    .set_TARGET_CHIP(i_target)
                    .set_OCCURRENCE(2),
                    "ERROR:Uncorrectable error occurred while accessing memory via fast access side");
    }

    if(nor_addr_range && l_inst_mchk)
    {
        if(!l_pibmem_saveoff)
        {
            FAPI_INF("Reading SPI STATUS/CONFIG registers");
            FAPI_TRY(getScom(i_target, scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG, l_data64_spi_status));
            FAPI_TRY(getScom(i_target, scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_CONFIG1, l_data64_spi_config));
            FAPI_TRY(getScom(i_target, scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_CLOCK_CONFIG, l_data64_spi_clock_config));
        }
        else
        {
            l_data64_spi0_status.extractToRight(l_data64_spi_status, 0, 64);
            l_data64_spi0_config.extractToRight(l_data64_spi_config, 0, 64);
            l_data64_spi0_clock_config.extractToRight(l_data64_spi_clock_config, 0, 64);
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_COUNTER_REG_PARITY_ERRS>())
        {
            FAPI_ERR("PNOR : counter configuration register parity error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_CLOCK_REG_PARITY_ERR>())
        {
            FAPI_ERR("PNOR : clock configuration register parity error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_SEQUENCER_REG_PARITY_ERR>())
        {
            FAPI_ERR("PNOR : sequencer configuration register parity error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_SEQUENCER_FSM_PARITY_ERR>())
        {
            FAPI_ERR("PNOR : sequencer fsm error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_SHIFTER_FSM_PARITY_ERR>())
        {
            FAPI_ERR("PNOR : shifter fsm error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_PATTERN_REG_PARITY_ERR>())
        {
            FAPI_ERR("PNOR : pattern match register parity error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_TDR_REG_PARITY_ERR>())
        {
            FAPI_ERR("PNOR : transmit data register parity error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_RDR_REG_PARITY_ERR>())
        {
            FAPI_ERR("PNOR : receive data register parity error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_CONFIG_REG1_PARITY_ERR>())
        {
            FAPI_ERR("PNOR : configuration register 1 parity error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ERROR_REG_PARITY_ERR>())
        {
            FAPI_ERR("PNOR : error register parity error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ECC_CORRECTABLE_ERR>())
        {
            FAPI_ERR("PNOR : ecc correctable error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ECC_UNCORRECTABLE_ERR>())
        {
            FAPI_ERR("PNOR : ecc uncorrectable error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_MM_ADDR_OVERLAP>())
        {
            FAPI_ERR("PNOR : memory mapped SPI address overlap");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ACCESS_VIOLATION>())
        {
            FAPI_ERR("PNOR : general access violation");
        }

        if(l_data64_spi_status.getBit < scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ACCESS_VIOLATION + 1 > ())
        {
            FAPI_ERR("PNOR : general access violation");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_PORT_MULTIPLEXER_ERR>())
        {
            FAPI_ERR("PNOR : port multiplexer error");
        }

        if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ADDR_OUT_OF_RANGE>())
        {
            FAPI_ERR("PNOR : address out of range error");
        }

        l_data32.flush<0>();
        l_data64_lfr0.extractToRight(l_data32, 0, 12);
        spi_clk_div_lfr = l_data32;

        l_data32.flush<0>();
        l_data64_spi_clock_config.extractToRight(l_data32, 0, 12);
        spi_clk_div = l_data32;

        l_data32.flush<0>();
        l_data64_spi_config.extractToRight(l_data32, 0, 5);
        spi_config_val = l_data32;

        if(spi_clk_div_lfr != spi_clk_div)
        {
            FAPI_ERR("spi clock divider value is corrupted, clock divider value in SPI is 0x%X and in lfr is 0x%X",
                     spi_clk_div, spi_clk_div_lfr);
        }

        if(spi_config_val != 0x1D)
        {
            FAPI_ERR("spi lock is lost,lock value is 0x%X", spi_config_val);
        }

        //-- MIB External Interface SIB Info
        FAPI_INF("Reading MIB SIB Info register");
        FAPI_TRY(MIB_XISIB.getScom(i_target));
        sib_rsp_info = MIB_XISIB.get_RSP_INFO();

        if(sib_rsp_info != 0x0)
        {
            FAPI_ERR("SIB Error Rsp is 0x%X", sib_rsp_info);
        }

        FAPI_ASSERT((!(spi_clk_div_lfr < 0x4)), fapi2::SPI_CLK_ERR()
                    .set_TARGET_CHIP(i_target)
                    .set_OCCURRENCE(1),
                    "SPPE LFR configured with invalid spi clock divider");

        if(l_pibmem_saveoff)
        {
            FAPI_ASSERT((!(spi_clk_div_lfr != spi_clk_div)), fapi2::SPI_CLK_ERR()
                        .set_TARGET_CHIP(i_target)
                        .set_OCCURRENCE(2),
                        "SPI CLOCK CONFIG register configured with invalid clock divider value");
        }

        FAPI_ASSERT((!(sib_rsp_info == 0x6)), fapi2::SPI_ECC_ERR()
                    .set_TARGET_CHIP(i_target)
                    .set_OCCURRENCE(1),
                    "SPI uncorrectable ECC error detected");

        FAPI_ASSERT((!(sib_rsp_info == 0x4)), fapi2::SPI_SPRM_CFG_ERR()
                    .set_TARGET_CHIP(i_target)
                    .set_OCCURRENCE(1),
                    "SPI config/addr error detected");

        FAPI_ASSERT((!(sib_rsp_info == 0x1)), fapi2::SPI_RSC_ERR()
                    .set_TARGET_CHIP(i_target)
                    .set_OCCURRENCE(1),
                    "SPI resources accessed is not available. Could be due to lock error OR port multiplexer settings");
    }

    if((OTPROM_DATA_MIN_RANGE <= l_data32_edr) && (l_data32_edr <= OTPROM_DATA_MAX_RANGE))
    {
        FAPI_INF("EDR contains OTPROM address");
        otprom_data_range = true;
    }
    else if((PIBMEM_MIN_RANGE <= l_data32_edr) && (l_data32_edr <= PIBMEM_MAX_RANGE))
    {
        FAPI_INF("EDR contains PIBMEM address");
        pibmem_data_range = true;
    }
    else if((NOR_SIDE_0_START_ADDR <= l_data32_iar) && (l_data32_iar <= NOR_END_ADDR))
    {
        FAPI_INF("EDR contains NOR FLASH address");
        nor_data_range = true;
    }
    else
    {
        FAPI_INF("EDR contains out of scope address = %08lX", l_data32_edr);
    }

    if(l_data_mchk && otprom_data_range)
    {
        FAPI_INF("Reading OTPROM status register");
        FAPI_TRY(OTPCTL_MAC_STATUS_REGISTER.getScom(i_target));

        if(OTPCTL_MAC_STATUS_REGISTER.get_REG_ADDR_NVLD())
        {
            FAPI_ERR("OTPROM::Address invalid bit set");
        }

        if(OTPCTL_MAC_STATUS_REGISTER.get_WRITE_NVLD())
        {
            FAPI_ERR("OTPROM::Write invalid bit set");
        }

        if(OTPCTL_MAC_STATUS_REGISTER.get_READ_NVLD())
        {
            FAPI_ERR("OTPROM::Read invalid bit set");
        }

        if(OTPCTL_MAC_STATUS_REGISTER.get_INVLD_CMD_ERR())
        {
            FAPI_ERR("OTPROM::Invalid command register fields programmed bit set");
        }

        if(OTPCTL_MAC_STATUS_REGISTER.get_CORR_ERR())
        {
            FAPI_ERR("OTPROM::Correctable error bit set");
        }

        if(OTPCTL_MAC_STATUS_REGISTER.get_UNCORR_ERROR())
        {
            FAPI_ERR("OTPROM::Uncorrectable error bit set");
        }

        //--  FAPI Asserts section for OTPROM --//
        FAPI_ASSERT(OTPCTL_MAC_STATUS_REGISTER.get_UNCORR_ERROR() != 0x1,
                    fapi2::OTP_UNCORR_ERR()
                    .set_TARGET_CHIP(i_target),
                    "ERROR: Uncorrectable error detected in OTPROM memory read");
    }

    if(l_data_mchk)
    {
        if(otprom_data_range || nor_data_range) // SIB Info is valid only for Otprom & Seeprom data
        {
            //-- MIB External Interface SIB Info
            FAPI_INF("Reading MIB SIB Info register");
            FAPI_TRY(MIB_XISIB.getScom(i_target));
            sib_rsp_info = MIB_XISIB.get_RSP_INFO();

            if(sib_rsp_info != 0x0)
            {
                FAPI_ERR("SIB Error Rsp is 0x%X", sib_rsp_info);
            }

        }

        if(otprom_data_range)
        {
            FAPI_ASSERT((!(sib_rsp_info == 0x6)),
                        fapi2::OTP_ECC_ERR()
                        .set_TARGET_CHIP(i_target)
                        .set_OCCURRENCE(1),
                        "Parity/ECC error detected in OTPROM memory, Check if OTPROM programmed correctly by dumping content");

            FAPI_ASSERT((!(sib_rsp_info == 0x7)), fapi2::OTP_TIMEOUT()
                        .set_TARGET_CHIP(i_target)
                        .set_OCCURRENCE(1),
                        "PIB Timeout error detected during access to OTPROM");

            FAPI_ASSERT((!(sib_rsp_info != 0x0)), fapi2::OTP_PIB_ERR()
                        .set_TARGET_CHIP(i_target)
                        .set_OCCURRENCE(1),
                        "Scom error detected");
        }

        if(pibmem_data_range) // PIBMEM status register read is allowed in both Secure & NonSecure mode
        {
            FAPI_INF("Reading PIBMEM status register");
            FAPI_TRY(PIBMEM_STATUS_REGISTER.getScom(i_target));

            if(PIBMEM_STATUS_REGISTER.get_ADDR_INVALID_PIB())
            {
                FAPI_ERR("PIBMEM::Address which PIB is trying to access in PIBMEM is not valid one in PIBMEM");
            }

            if(PIBMEM_STATUS_REGISTER.get_WRITE_INVALID_PIB())
            {
                FAPI_ERR("PIBMEM::Address for which PIB is trying to write is not writable");
            }

            if(PIBMEM_STATUS_REGISTER.get_READ_INVALID_PIB())
            {
                FAPI_ERR("PIBMEM::Address for which PIB is trying to read is not readable");
            }

            if(PIBMEM_STATUS_REGISTER.get_ECC_UNCORRECTED_ERROR_PIB())
            {
                FAPI_ERR("PIBMEM::Uncorrectable error occurred while PIB memory read");
            }

            if(PIBMEM_STATUS_REGISTER.get_ECC_CORRECTED_ERROR_PIB())
            {
                FAPI_INF("PIBMEM::Corrected error in PIB mem read");
            }

            if(PIBMEM_STATUS_REGISTER.get_BAD_ARRAY_ADDRESS_PIB())
            {
                FAPI_ERR("PIBMEM::Wrong address accessd in indirect mode of operation from PIB side");
            }

            if(PIBMEM_STATUS_REGISTER.get_WRITE_RST_INTERRUPT_PIB())
            {
                FAPI_ERR("PIBMEM::Reset occurred during write operation to PIBMEM from PIB side");
            }

            if(PIBMEM_STATUS_REGISTER.get_READ_RST_INTERRUPT_PIB())
            {
                FAPI_ERR("PIBMEM::Reset occurred during read operation to PIBMEM from PIB side");
            }

            if(PIBMEM_STATUS_REGISTER.get_ADDR_INVALID_FACES())
            {
                FAPI_ERR("PIBMEM::Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM");
            }

            if(PIBMEM_STATUS_REGISTER.get_WRITE_INVALID_FACES())
            {
                FAPI_ERR("PIBMEM::Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM or not writable");
            }

            if(PIBMEM_STATUS_REGISTER.get_READ_INVALID_FACES())
            {
                FAPI_ERR("PIBMEM::Address which is given by Fast acesss interface, to access is not readable");
            }

            if(PIBMEM_STATUS_REGISTER.get_ECC_UNCORRECTED_ERROR_FACES())
            {
                FAPI_ERR("PIBMEM::Uncorrectable error occurred while fast acess interface read");
            }

            if(PIBMEM_STATUS_REGISTER.get_ECC_CORRECTED_ERROR_FACES())
            {
                FAPI_INF("PIBMEM::Corrected error in fast acess read operation");
            }

            if(PIBMEM_STATUS_REGISTER.get_BAD_ARRAY_ADDRESS_FACES())
            {
                FAPI_ERR("PIBMEM::Wrong address accessd in indirect mode of operation from fast acess interface");
            }

            if(PIBMEM_STATUS_REGISTER.get_WRITE_RST_INTERRUPT_FACES())
            {
                FAPI_ERR("PIBMEM::Reset occurred during write operation to PIBMEM from fast acess side");
            }

            if(PIBMEM_STATUS_REGISTER.get_READ_RST_INTERRUPT_FACES())
            {
                FAPI_ERR("PIBMEM::Reset occurred during read operation to PIBMEM from fast acess side");
            }

            //--  FAPI Asserts section for PIBMEM --//
            FAPI_ASSERT(PIBMEM_STATUS_REGISTER.get_ECC_UNCORRECTED_ERROR_PIB() != 0x1,
                        fapi2::PIBMEM_ECC_ERR()
                        .set_TARGET_CHIP(i_target)
                        .set_OCCURRENCE(3),
                        "ERROR: Uncorrectable error occurred while accessing memory via PIB side");

            FAPI_ASSERT(PIBMEM_STATUS_REGISTER.get_ECC_UNCORRECTED_ERROR_FACES() != 0x1,
                        fapi2::PIBMEM_ECC_ERR()
                        .set_TARGET_CHIP(i_target)
                        .set_OCCURRENCE(4),
                        "ERROR:Uncorrectable error occurred while accessing memory via fast access side");

            //-- MIB External Interface MEM Info
            FAPI_INF("Reading MIB MEM Info register");
            FAPI_TRY(MIB_PPE_XIMEM.getScom(i_target));
            mem_error = MIB_PPE_XIMEM.get_ERROR();

            if(mem_error != 0x0)
            {
                FAPI_ERR("MIB MEM Error info is 0x%X", mem_error);
            }

            FAPI_ASSERT((!(mem_error == 0x6)),
                        fapi2::PIBMEM_ECC_ERR()
                        .set_TARGET_CHIP(i_target)
                        .set_OCCURRENCE(5),
                        "ECC error detected during pibmem access, Run PIBMEM REPAIR test..");

            FAPI_ASSERT((!(mem_error != 0x0)), fapi2::PIBMEM_PIB_ERR()
                        .set_TARGET_CHIP(i_target),
                        "Error detected during pibmem access");

        }

        if(nor_data_range)
        {
            if(!l_pibmem_saveoff)
            {
                FAPI_INF("Reading SPI STATUS/CONFIG registers");
                FAPI_TRY(getScom(i_target, scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG, l_data64_spi_status));
                FAPI_TRY(getScom(i_target, scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_CONFIG1, l_data64_spi_config));
                FAPI_TRY(getScom(i_target, scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_CLOCK_CONFIG, l_data64_spi_clock_config));
            }
            else
            {
                l_data64_spi0_status.extractToRight(l_data64_spi_status, 0, 64);
                l_data64_spi0_config.extractToRight(l_data64_spi_config, 0, 64);
                l_data64_spi0_clock_config.extractToRight(l_data64_spi_clock_config, 0, 64);
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_COUNTER_REG_PARITY_ERRS>())
            {
                FAPI_ERR("PNOR : counter configuration register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_CLOCK_REG_PARITY_ERR>())
            {
                FAPI_ERR("PNOR : clock configuration register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_SEQUENCER_REG_PARITY_ERR>())
            {
                FAPI_ERR("PNOR : sequencer configuration register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_SEQUENCER_FSM_PARITY_ERR>())
            {
                FAPI_ERR("PNOR : sequencer fsm error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_SHIFTER_FSM_PARITY_ERR>())
            {
                FAPI_ERR("PNOR : shifter fsm error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_PATTERN_REG_PARITY_ERR>())
            {
                FAPI_ERR("PNOR : pattern match register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_TDR_REG_PARITY_ERR>())
            {
                FAPI_ERR("PNOR : transmit data register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_RDR_REG_PARITY_ERR>())
            {
                FAPI_ERR("PNOR : receive data register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_CONFIG_REG1_PARITY_ERR>())
            {
                FAPI_ERR("PNOR : configuration register 1 parity error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ERROR_REG_PARITY_ERR>())
            {
                FAPI_ERR("PNOR : error register parity error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ECC_CORRECTABLE_ERR>())
            {
                FAPI_ERR("PNOR : ecc correctable error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ECC_UNCORRECTABLE_ERR>())
            {
                FAPI_ERR("PNOR : ecc uncorrectable error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_MM_ADDR_OVERLAP>())
            {
                FAPI_ERR("PNOR : memory mapped SPI address overlap");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ACCESS_VIOLATION>())
            {
                FAPI_ERR("PNOR : general access violation");
            }

            if(l_data64_spi_status.getBit < scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ACCESS_VIOLATION + 1 > ())
            {
                FAPI_ERR("PNOR : general access violation");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_PORT_MULTIPLEXER_ERR>())
            {
                FAPI_ERR("PNOR : port multiplexer error");
            }

            if(l_data64_spi_status.getBit<scomt::perv::TPCHIP_PIB_SPICTL_SPICTL0_STATUS_REG_ADDR_OUT_OF_RANGE>())
            {
                FAPI_ERR("PNOR : address out of range error");
            }

            l_data32.flush<0>();
            l_data64_lfr0.extractToRight(l_data32, 0, 12);
            spi_clk_div_lfr = l_data32;

            l_data32.flush<0>();
            l_data64_spi_clock_config.extractToRight(l_data32, 0, 12);
            spi_clk_div = l_data32;

            l_data32.flush<0>();
            l_data64_spi_config.extractToRight(l_data32, 0, 5);
            spi_config_val = l_data32;

            if(spi_clk_div_lfr != spi_clk_div)
            {
                FAPI_ERR("spi clock divider value is corrupted, clock divider value in SPI is 0x%X and in lfr is 0x%X",
                         spi_clk_div, spi_clk_div_lfr);
            }

            if(spi_config_val != 0x1D)
            {
                FAPI_ERR("spi lock is lost,lock value is 0x%X", spi_config_val);
            }

            FAPI_ASSERT((!(spi_clk_div_lfr < 0x4)), fapi2::SPI_CLK_ERR()
                        .set_TARGET_CHIP(i_target)
                        .set_OCCURRENCE(5),
                        "SPPE LFR configured with invalid spi clock divider");

            if(l_pibmem_saveoff)
            {
                FAPI_ASSERT((!(spi_clk_div_lfr != spi_clk_div)), fapi2::SPI_CLK_ERR()
                            .set_TARGET_CHIP(i_target)
                            .set_OCCURRENCE(6),
                            "SPI CLOCK CONFIG register configured with invalid clock divider value");
            }

            FAPI_ASSERT((!(sib_rsp_info == 0x6)), fapi2::SPI_ECC_ERR()
                        .set_TARGET_CHIP(i_target)
                        .set_OCCURRENCE(3),
                        "SPI uncorrectable ECC error detected");

            FAPI_ASSERT((!(sib_rsp_info == 0x4)), fapi2::SPI_SPRM_CFG_ERR()
                        .set_TARGET_CHIP(i_target)
                        .set_OCCURRENCE(3),
                        "SPI config/addr error detected");

            FAPI_ASSERT((!(sib_rsp_info == 0x1)), fapi2::SPI_RSC_ERR()
                        .set_TARGET_CHIP(i_target)
                        .set_OCCURRENCE(3),
                        "SPI resources accessed is not available. Could be due to lock error OR port multiplexer settings");
        }
    }


fapi_try_exit:
    FAPI_INF("Exiting ...");
    return fapi2::current_err;
}
