/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_extract_sbe_rc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @brief Check for errors on the PNOR , SEEPROM
//------------------------------------------------------------------------------
// *HWP HW Owner        : Soma BhanuTej <soma.bhanu@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Sunil Kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : FSP:HB
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_extract_sbe_rc.H"

#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>

fapi2::ReturnCode p9_extract_sbe_rc(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint32_t> l_data32_ir;
    fapi2::buffer<uint32_t> l_data32_edr;
    fapi2::buffer<uint32_t> l_data32_xsr;
    fapi2::buffer<uint32_t> l_data32_iar;
    bool l_ppe_halt_state = true;
    bool otprom_addr_range = false;
    bool pibmem_addr_range = false;
    bool seeprom_addr_range = false;
    bool FAIL = false;
    uint32_t HC, MCS, otprom_addr;

    // OTPROM Address constants
    uint32_t MAGIC_NUMBER_MISMATCH_LOCATION = 0xC015C;
    uint32_t OTPROM_IMAGE_END_LOCATION = 0xC0158;

    FAPI_INF("p9_extract_sbe_rc : Entering ...");

    // XSR and IAR
    FAPI_DBG("p9_extract_sbe_rc : Reading PPE_XIDBGPRO");
    FAPI_TRY(getScom(i_target_chip, PU_PPE_XIDBGPRO, l_data64));
    l_data64.extractToRight(l_data32_xsr, 0, 32);
    l_data64.extractToRight(l_data32_iar, 32, 32);

    if (l_data32_xsr.getBit<0>())
    {
        FAPI_INF("p9_extract_sbe_rc : PPE is in HALT state");
        l_ppe_halt_state  = true;

    }
    else
    {
        FAPI_INF("p9_extract_sbe_rc : PPE is in RUNNING state");
        l_ppe_halt_state  = false;
    }


    if(l_ppe_halt_state)
    {
        // ------- LEVEL 1 ------ //

        //Extract HC
        l_data32.flush<0>();
        l_data32_xsr.extractToRight(l_data32, 1, 3);
        HC = l_data32;

        if(HC != 0x0)
        {
            switch(HC)
            {
                case 0x1 :
                    FAPI_DBG("p9_extract_sbe_rc : XCR[CMD] written 111 to force-halt the processor.");
                    break;

                case 0x2 :
                    FAPI_DBG("p9_extract_sbe_rc : A second watchdog timer (WDT) event occurred while TCR[WRC]=11");
                    break;

                case 0x3 :
                    FAPI_DBG("p9_extract_sbe_rc : Unmaskable interrupt halt");
                    break;

                case 0x4 :
                    FAPI_DBG("p9_extract_sbe_rc : Debug halt");
                    break;

                case 0x5 :
                    FAPI_DBG("p9_extract_sbe_rc : DBCR halt");
                    break;

                case 0x6 :
                    FAPI_DBG("p9_extract_sbe_rc : The external halt_req input was active.");
                    break;

                case 0x7 :
                    FAPI_DBG("p9_extract_sbe_rc : Hardware failure");
                    break;

                default :
                    FAPI_ERR("p9_extract_sbe_rc : INVALID HALT CONDITION HC=0x%x", HC);
                    break;
            }
        }
        else
        {
            FAPI_INF("p9_extract_sbe_rc : Halt condition not reported");
        }

        //Extract TRAP
        if(l_data32_xsr.getBit<7>())
        {
            FAPI_DBG("p9_extract_sbe_rc : TRAP Instruction Debug Event Occured");
        }

        //Extract IAC
        if(l_data32_xsr.getBit<8>())
        {
            FAPI_DBG("p9_extract_sbe_rc : Instruction Address Compare Debug Event Occured");
        }

        //Extract DACR
        if(l_data32_xsr.getBit<12>())
        {
            FAPI_DBG("p9_extract_sbe_rc : Data Address Compare (Read) Debug Event Occured");
        }

        //Extract DACW
        if(l_data32_xsr.getBit<13>())
        {
            FAPI_DBG("p9_extract_sbe_rc : Data Address Compare (Write) Debug Event Occured");
        }

        //Extract WS
        if(l_data32_xsr.getBit<14>())
        {
            FAPI_DBG("p9_extract_sbe_rc : In WAIT STATE");
        }

        //Extract EP
        if(l_data32_xsr.getBit<21>())
        {
            FAPI_DBG("p9_extract_sbe_rc : Maskable Event Pending");
        }

        //Extract MFE
        if(l_data32_xsr.getBit<28>())
        {
            FAPI_DBG("p9_extract_sbe_rc : Multiple Fault Error Occured");
        }

        //Extract MCS
        l_data32.flush<0>();
        l_data32_xsr.extractToRight(l_data32, 29, 3);
        MCS = l_data32;

        // IR and EDR
        FAPI_DBG("p9_extract_sbe_rc : Reading PPE_XIRAMEDR");
        FAPI_TRY(getScom(i_target_chip, PU_PPE_XIRAMEDR, l_data64));
        l_data64.extractToRight(l_data32_ir, 0, 32);
        l_data64.extractToRight(l_data32_edr, 32, 32);

        if(MCS == 0x4)
        {
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_PROGRAM_INTERRUPT(), "ERROR:Program interrupt promoted for Address=0x%08llX",
                        l_data32_edr);
        }
        else
        {
            FAPI_DBG("p9_extract_sbe_rc : Data/Alignment/Data Machine check interrupt for Data=0x%08llX", l_data32_edr);

            switch (MCS)
            {
                case 0x0 :
                    FAPI_DBG("p9_extract_sbe_rc : Instruction machine check");
                    break;

                case 0x1 :
                    FAPI_DBG("p9_extract_sbe_rc : Data machine check - load");
                    break;

                case 0x2 :
                    FAPI_DBG("p9_extract_sbe_rc : Data machine check - precise store");
                    break;

                case 0x3 :
                    FAPI_DBG("p9_extract_sbe_rc : Data machine check - imprecise store");
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

        if((0x00C00000 <= l_data32_iar) && (l_data32_iar >= 0x000C0378))
        {
            FAPI_DBG("p9_extract_sbe_rc : IAR contains OTPROM address");
            otprom_addr_range = true;
        }
        else if((0xFFE80000 <= l_data32_iar) && (l_data32_iar >= 0xFFEFFFFF))
        {
            FAPI_DBG("p9_extract_sbe_rc : IAR contains PIBMEM address");
            pibmem_addr_range = true;
        }
        else if((0x80000000 <= l_data32_iar) && (l_data32_iar >= 0x8000FFFF))
        {
            FAPI_DBG("p9_extract_sbe_rc : IAR contains SEEPROM address");
            seeprom_addr_range = true;
        }
        else
        {
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_ADDR_NOT_RECOGNIZED(), "ERROR:Address 0x%08llX is out of range", l_data32_iar);
        }

        // ------- LEVEL 3 ------ //

        if(otprom_addr_range)
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


            //--  FAPI Asserts section --//

            // map the OTPROM address to the known error at that location
            // the OTPROM is write-once at mfg test, so addresses should remain fixed in this code
            otprom_addr = l_data32_iar;

            if(otprom_addr == MAGIC_NUMBER_MISMATCH_LOCATION)
            {
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_MAGIC_NUMBER_MISMATCH(), "ERROR:SEEPROM magic number didn't match");
            }
            else if(otprom_addr > OTPROM_IMAGE_END_LOCATION)
            {
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_BRANCH_TO_SEEPROM_FAIL(), "ERROR:Branch to SEEPROM didn't happen");
            }
            else
            {
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_UNEXPECTED_OTPROM_HALT(),
                            "ERROR:Halted in OTPROM at address 0x%08llX, but not at an expected halt location", otprom_addr);
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
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Corrected error in PIB mem read");
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
                FAPI_ERR("p9_extract_sbe_rc : PIBMEM::Corrected error in fast acess read operation");
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

            //--  FAPI Asserts section --//

            FAPI_ASSERT(l_data64.getBit<PU_PIBMEM_STATUS_REG_ECC_UNCORRECTED_ERROR_PIB>() != 1,
                        fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_UNCORRECTED_ERROR_PIB(), "ERROR:Uncorrectable error occurred while PIB memory read");
            FAPI_ASSERT(l_data64.getBit<PU_PIBMEM_STATUS_REG_ECC_CORRECTED_ERROR_PIB>() != 1,
                        fapi2::EXTRACT_SBE_RC_PIBMEM_SOFT_ECC_ERROR_PIB(), "WARN:Corrected error in PIB mem read from PIB side");
            FAPI_ASSERT(l_data64.getBit<PU_PIBMEM_STATUS_REG_ECC_UNCORRECTED_ERROR_FACES>() != 1,
                        fapi2::EXTRACT_SBE_RC_PIBMEM_ECC_UNCORRECTED_ERROR_FACES(),
                        "ERROR:Uncorrectable error occurred while fast acess interface read");
            FAPI_ASSERT(l_data64.getBit<PU_PIBMEM_STATUS_REG_ECC_CORRECTED_ERROR_FACES>() != 1,
                        fapi2::EXTRACT_SBE_RC_PIBMEM_SOFT_ECC_ERROR_FACES(), "WARN:Corrected error in fast acess read operation");
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_HALT_PIBMEM(), "ERROR:Halted in PIBMEM address location 0x%08llX",
                        l_data32_iar);
        }

        if(seeprom_addr_range)
        {
            FAPI_DBG("p9_extract_sbe_rc : Reading FI2CM mode register");
            FAPI_TRY(getScom(i_target_chip, PU_MODE_REGISTER_B, l_data64));
            FAPI_DBG("p9_extract_sbe_rc : FI2CM mode : %#018lX", l_data64);

            l_data32.flush<0>();
            l_data64.extractToRight(l_data32, 0, 16);
            uint32_t i2c_speed = l_data32;

            if(i2c_speed <= 0x0003)
            {
                FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_FI2CM_BIT_RATE_ERR(),
                            "ERROR:Speed on the I2C bit rate divisor is less than min speed value (0x0003), I2C Speed read is 0x%04llX", i2c_speed);
            }

            FAPI_DBG("p9_extract_sbe_rc : Reading FI2CM status register");
            FAPI_TRY(getScom(i_target_chip, PU_STATUS_REGISTER_B, l_data64));
            FAPI_DBG("p9_extract_sbe_rc : FI2CM status : %#018lX", l_data64);

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_ADDR_NVLD_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Address invalid bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_WRITE_NVLD_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Write invalid bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_READ_NVLD_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Read invalid bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_ADDR_P_ERR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Address parity error bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_PAR_ERR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Data parity error bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_LB_PARITY_ERROR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Local bus parity error bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_ECC_CORRECTED_ERROR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::WARN:One bit flip was there in data and been corrected");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_ECC_UNCORRECTED_ERROR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::There are 2 bit flips in read data which cannot be corrected");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_ECC_CONFIG_ERROR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Control register is ecc_enabled for data_length not equal to 8. OR ECC is enabled for the engine where ECC block is not instantiated");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_INVALID_COMMAND_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Invalid command bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_PARITY_ERROR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Parity error bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_BACK_END_OVERRUN_ERROR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Back end overrun error bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_BACK_END_ACCESS_ERROR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Back end access error bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_ARBITRATION_LOST_ERROR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Arbitration lost error bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_NACK_RECEIVED_ERROR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::NACK receieved error bit set");
            }

            if(l_data64.getBit<PU_STATUS_REGISTER_B_BUS_STOP_ERROR_0>())
            {
                FAPI_ERR("p9_extract_sbe_rc : FI2CM::Stop error bit set");
            }

            //--  FAPI Asserts section --//

            FAPI_ASSERT(l_data64.getBit<PU_STATUS_REGISTER_B_ECC_UNCORRECTED_ERROR_0>() != 1,
                        fapi2::EXTRACT_SBE_RC_UNRECOVERABLE_ECC_SEEPROM(),
                        "ERROR:There are 2 bit flips in read data which cannot be corrected");
            FAPI_ASSERT(l_data64.getBit<PU_STATUS_REGISTER_B_ECC_UNCORRECTED_ERROR_0>() != 1,
                        fapi2::EXTRACT_SBE_RC_UNRECOVERABLE_ECC_SEEPROM(),
                        "ERROR:There are 2 bit flips in read data which cannot be corrected");
            FAPI_ASSERT(l_data64.getBit<PU_STATUS_REGISTER_B_ECC_CORRECTED_ERROR_0>() != 1,
                        fapi2::EXTRACT_SBE_RC_SOFT_ECC_ERROR_SEEPROM(), "WARN:One bit flip was there in data and been corrected");
            FAPI_ASSERT(FAIL, fapi2::EXTRACT_SBE_RC_HALT_SEEPROM(), "ERROR:Halted in SEEPROM address location 0x%08llX",
                        l_data32_iar);
        }
    }

    FAPI_INF("p9_extract_sbe_rc : Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
