/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedbootUtils.C $               */
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
/**
 * @file trustedbootUtils.C
 *
 * @brief Trusted boot utility functions
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <spi/tpmddif.H>
#include <secureboot/trustedbootif.H>
#include <spi/tpmddreasoncodes.H>
#include <secureboot/trustedboot_reasoncodes.H>
#include "trustedbootUtils.H"
#include "trustedbootCmds.H"
#include "trustedboot.H"
#include "trustedTypes.H"
#include <secureboot/service.H>
#include <spidd.H>
#include <p10_scom_proc_d.H>
#include <errl/errludlogregister.H>
#include <errl/errludattribute.H>
#include <errl/errludstring.H>
#include <kernel/bltohbdatamgr.H>
#include <bootloader/bootloaderif.H>
#include <bootloader/hbblreasoncodes.H>
#include <stdio.h>
#include <initservice/mboxRegs.H>

namespace TRUSTEDBOOT
{

errlHndl_t tpmTransmit(TpmTarget * io_target,
                       uint8_t* io_buffer,
                       size_t i_cmdSize,
                       size_t i_bufsize,
                       tpm_locality_t i_locality)
{
    errlHndl_t err = NULL;

    do
    {
        TRACDCOMP( g_trac_trustedboot,
               ">>TPM OP TRANSMIT : BufLen %d : %016llx, cmdSize = %d",
               static_cast<int>(i_bufsize),
               *(reinterpret_cast<uint64_t*>(io_buffer)),
               static_cast<int>(i_cmdSize) );

        // Send to the TPM
        err = deviceRead(io_target,
                         io_buffer,
                         i_bufsize,
                         DEVICE_TPM_ADDRESS(TPMDD::TPM_OP_TRANSMIT,
                                            i_cmdSize,
                                            i_locality));
        TRACDCOMP( g_trac_trustedboot,
              "<<TPM OP TRANSMIT : BufLen %d : %016llx, cmdSize = %d DONE, rc=0x%X",
               static_cast<int>(i_bufsize),
               *(reinterpret_cast<uint64_t*>(io_buffer)),
               static_cast<int>(i_cmdSize),
               ERRL_GETRC_SAFE(err) );
        if (NULL != err)
        {
            break;
        }

    } while ( 0 );

    return err;
}

errlHndl_t tpmCreateErrorLog(
    const uint8_t  i_modId,
    const uint16_t i_reasonCode,
    const uint64_t i_user1,
    const uint64_t i_user2,
    const bool     i_addSwCallout)
{
    errlHndl_t pError =
        new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            i_modId,
            i_reasonCode,
            i_user1,
            i_user2,
            i_addSwCallout);

    pError->collectTrace(SECURE_COMP_NAME);
    pError->collectTrace(TRBOOT_COMP_NAME);

    return pError;
}

void addTpmFFDC(TpmTarget* i_pTpm,
                errlHndl_t& io_errl)
{
    do {
    if(nullptr == io_errl)
    {
        TRACFCOMP(g_trac_trustedboot, "addTpmFFDC: nullptr was passed for io_errl. Will not add TPM FFDC.");
        break;
    }

    // Add security regs
    SECUREBOOT::addSecurityRegistersToErrlog(io_errl);
    TARGETING::Target* l_proc = getImmediateParentByAffinity(i_pTpm);
    // Add SPI status regs
    SPI::addSpiStatusRegsToErrl(l_proc, SPI_ENGINE_TPM, io_errl);
    // Mbox Scratch 11 contains the SBE TPM RC
    ERRORLOG::ErrlUserDetailsLogRegister l_scratchReg(l_proc);
    l_scratchReg.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch11_t::REG_ADDR));
    // Mbox Scratch 14 provides additional FFDC when possible
    l_scratchReg.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch14_t::REG_ADDR));
    l_scratchReg.addToLog(io_errl);
    // Add freq control reg that will help determine the PAU freq used
    ERRORLOG::ErrlUserDetailsLogRegister l_pauFreqReg(l_proc);
    l_pauFreqReg.addData(DEVICE_SCOM_ADDRESS(scomt::proc::TP_TPCHIP_TPC_DPLL_CNTL_PAU_REGS_FREQ));
    l_pauFreqReg.addToLog(io_errl);
    // Include ATTR_BOOT_PAU_DPLL_BYPASS
    ERRORLOG::ErrlUserDetailsAttribute(l_proc, TARGETING::ATTR_BOOT_PAU_DPLL_BYPASS).addToLog(io_errl);

    ERRORLOG::ErrlUserDetailsStringSet l_tdpSourceString;

    TARGETING::Target* l_primaryProc = nullptr;
    errlHndl_t l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_primaryProc);
    if(l_errl)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"addTpmFFDC: Could not get primary proc. Stopping FFDC collection.");
        errlCommit(l_errl, SECURE_COMP_ID);
        break;
    }

    // Get HBBL/SBE - related FFDC if it's the primary proc
    if(l_proc == l_primaryProc)
    {
        // If the TDP bit is set in HBBL->HB comm area, then the issue happened
        // in HBBL; else - in SBE.
        if(g_BlToHbDataManager.getTdpSource() == Bootloader::TDP_BIT_SET_HBBL)
        {
            l_tdpSourceString.add("TDP Bit Source", "TDP bit was set by HBBL");
        }
        else if(g_BlToHbDataManager.getTdpSource() == Bootloader::TDP_BIT_SET_SBE)
        {
            l_tdpSourceString.add("TDP Bit Source", "TDP bit was set by SBE");
        }
        else if(l_proc->getAttr<TARGETING::ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM>())
        {
            l_tdpSourceString.add("TDP Bit Source", "TDP bit was set by Hostboot");
        }
        else
        {
            l_tdpSourceString.add("TDP Bit Source", "Unset/Unknown");
        }
        l_tdpSourceString.addToLog(io_errl);

        // Add some RC-specific FFDC from the bootloader
        if(g_BlToHbDataManager.getVersion() >= Bootloader::BLTOHB_TPM_FFDC)
        {
            ERRORLOG::ErrlUserDetailsStringSet l_hbblTpmRcString;
            char l_hbblRcString[10]; // Actual RC is smaller than 10 chars
            snprintf(l_hbblRcString, 10, "0x%x", g_BlToHbDataManager.getTpmRc());
            l_hbblTpmRcString.add("HBBL TPM RC", l_hbblRcString);
            l_hbblTpmRcString.addToLog(io_errl);

            // If there was an XSCOM error, deconfig the proc
            if(g_BlToHbDataManager.getTpmRc() == Bootloader::RC_XSCOM_OP_FAILED ||
               g_BlToHbDataManager.getTpmRc() == Bootloader::RC_XSCOM_OP_TIMEOUT)
            {
                io_errl->addHwCallout(l_proc,
                                      HWAS::SRCI_PRIORITY_HIGH,
                                      HWAS::DECONFIG,
                                      HWAS::GARD_NULL);
            }
        }
    }
    // Bootloader didn't run for the backup proc, so we can only tell if the TDP
    // bit was set by SBE
    else
    {
        l_errl = checkTdpBit(i_pTpm);
        if(l_errl)
        {
            // TDP bit is set by the SBE. Discard the error
            delete l_errl;
            l_errl = nullptr;
            l_tdpSourceString.add("TDP Bit Source", "TDP bit was set by SBE");
        }
        else if(l_proc->getAttr<TARGETING::ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM>())
        {
            l_tdpSourceString.add("TDP Bit Source", "TDP bit was set by Hostboot");
        }
        else
        {
            l_tdpSourceString.add("TDP Bit Source", "Unset/Unknown");
        }
        l_tdpSourceString.addToLog(io_errl);
    }

    } while(0);
}

} // end TRUSTEDBOOT
