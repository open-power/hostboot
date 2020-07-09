/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/service.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#include <secureboot/service.H>
#include <stdint.h>
#include <sys/mm.h>
#include <util/singleton.H>
#include <secureboot/secure_reasoncodes.H>
#include <config.h>
#include <devicefw/userif.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
#include <initservice/initserviceif.H>
#include <secureboot/settings.H>
#include <secureboot/header.H>
#include "purge.H"
#include <kernel/misc.H>
#include <kernel/console.H>
#include <kernel/bltohbdatamgr.H>
#include <console/consoleif.H>
#include <util/misc.H>

#include "../common/securetrace.H"
#include "../common/errlud_secure.H"

// Quick change for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


using namespace ERRORLOG;
using namespace TARGETING;

namespace SECUREBOOT
{

// TODO securebootp9 - Do a diff of this file with the p8 version make sure
// all the missing parts are brought in.


// Local structure and function prototypes used below
/**
 *  @brief Structure used to capture values of Processor Security Registers
 */
struct SecureRegisterValues
{
    TARGETING::Target * tgt;
    uint32_t addr;
    uint64_t data;
};

/*
 * HB specific secureboot setting which is aliased to the FAPI attribute
 * ATTR_SECURITY_MODE and customized into the SBE image.  If 0b0, SBE
 * will disable proc security (via SAB bit) if mailbox scratch register 3
 * bit 6 is set.  Otherwise, if 0b1, SBE will not override proc security.
 * TODO RTC 170650: When SBE image is signed in all environments, set
 *     default to 0b1 and rely on SBE signing header to configure the final
 *     value.
 */
uint8_t g_sbeSecurityMode = 1;

/**
 * @brief Retrieve values of Security Registers of the processors in the
 *        system
 *
 * @param[out] o_regs       Vector of SecureRegisterValue structs that contain
 *                          processor security register values
 *                          NOTE:  The state of the system/processors (ie, SCOM vs
 *                          FSI) determines which registers can be included
 * @param[out] i_calledByRP See the handleSecurebootFailure function's
 *                          "called by resource provider" option.
 *
 * @return errlHndl_t  nullptr on success, else pointer to error log
 */
errlHndl_t getAllSecurityRegisters(std::vector<SecureRegisterValues> & o_regs,
                                   const bool i_calledByRP = false)
{
    // Note: If you add code to this function that calls into the extended
    // image then it could cause a deadlock. Protect any such code with
    // logic that checks if i_calledByRP is false before doing so.

    SB_ENTER("getAllSecurityRegisters: isTargetingLoaded=%d calledByRP=%d",
             Util::isTargetingLoaded(), i_calledByRP);
    errlHndl_t err = nullptr;

    // Clear output vector
    o_regs.clear();

    SecureRegisterValues l_secRegValues;

    do
    {

    TARGETING::TargetHandleList procList;
    TARGETING::Target* masterProcChipTargetHandle = nullptr;

    if ( Util::isTargetingLoaded() && !i_calledByRP )
    {
        // Try to get a list of functional processors

        // Get Target Service, and the system target.
        TargetService& tS = targetService();
        TARGETING::Target* sys = nullptr;
        (void) tS.getTopLevelTarget( sys );

        assert(sys, "getAllSecurityRegisters() system target is nullptr");

        TARGETING::getAllChips(procList,
                               TARGETING::TYPE_PROC,
                               true); // true: return functional targets

        // Get the Master Proc Chip Target for comparisons later
        err = tS.queryMasterProcChipTargetHandle(masterProcChipTargetHandle);

        if (err)
        {
            SB_ERR("getAllSecurityRegisters: "
                   "queryMasterProcChipTargetHandle returned error: "
                   "RC=0x%X, PLID=0x%X",
                   ERRL_GETRC_SAFE(err),
                   ERRL_GETPLID_SAFE(err));

            // Commit error and continue
            errlCommit( err, SECURE_COMP_ID );
            masterProcChipTargetHandle = nullptr;

            // Since we can't get master proc, don't trust targeting and
            // just use MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
            procList.clear();
        }
    }

    if ( procList.size() != 0 )
    {
        // Grab data from all of the targets
        uint64_t scomData = 0x0;
        size_t   op_expected_size  = 0x0;
        size_t   op_actual_size = 0x0;
        uint64_t op_addr  = 0x0;

        for( auto procTgt : procList )
        {
            SB_DBG("getAllSecurityRegisters: procTgt=0x%X: useXscom=%d",
                   TARGETING::get_huid(procTgt), procTgt->getAttr<ATTR_SCOM_SWITCHES>().useXscom);

            /****************************************/
            // Get ProcSecurity::SwitchRegister
            /****************************************/
            // can only get register if processor target is scommable
            // If the proc chip supports xscom..
            if (procTgt->getAttr<ATTR_SCOM_SWITCHES>().useXscom)
            {
                l_secRegValues.tgt=procTgt;
                l_secRegValues.addr=static_cast<uint32_t>(ProcSecurity::SwitchRegister);
                err = getSecuritySwitch(l_secRegValues.data,
                                        l_secRegValues.tgt);
                if( err )
                {
                    // Something failed on the read.  Commit the error
                    // here but continue
                    SB_ERR("getAllSecurityRegisters: Error from getSecuritySwitch: "
                           "(0x%X) from Target 0x%.8X: RC=0x%X, PLID=0x%X",
                           l_secRegValues.addr,
                           TARGETING::get_huid(l_secRegValues.tgt),
                           ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

                    // Commit error and continue
                    errlCommit( err, SECURE_COMP_ID );
                    continue;
                }
                o_regs.push_back(l_secRegValues);
            }

            /****************************************/
            // Get ProcCbsControl::StatusRegister
            /****************************************/
            // Check to see if current target is master processor
            if ( procTgt == masterProcChipTargetHandle)
            {
                SB_DBG("getAllSecurityRegisters: procTgt=0x%X is MASTER. ",
                       TARGETING::get_huid(procTgt));

                // Read ProcCbsControl::StatusRegister via SCOM
                scomData = 0x0;
                op_actual_size = sizeof(scomData);
                op_expected_size = op_actual_size;
                op_addr = static_cast<uint64_t>(ProcCbsControl::StatusRegister);

                err = deviceRead( procTgt,
                                  &scomData,
                                  op_actual_size,
                                  DEVICE_SCOM_ADDRESS(op_addr) );
            }
            else
            {
                SB_DBG("getAllSecurityRegisters: procTgt=0x%X is NOT MASTER. ",
                       TARGETING::get_huid(procTgt));

                // Not Master, so read ProcCbsControl::StatusRegister via FSI
                scomData = 0x0;
                op_actual_size = 4; // size for FSI
                op_expected_size = op_actual_size;
                op_addr = static_cast<uint64_t>(ProcCbsControl::StatusRegisterFsi);

                err = deviceRead( procTgt,
                                  &scomData,
                                  op_actual_size,
                                  DEVICE_FSI_ADDRESS(op_addr) );
            }

            if( err )
            {
                // Something failed on the read.  Commit the error
                // here but continue
                SB_ERR("getAllSecurityRegisters: Error reading CBS Control Reg "
                       "(0x%X) from Target 0x%.8X: RC=0x%X, PLID=0x%X",
                       op_addr, TARGETING::get_huid(procTgt),
                       ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

                // Commit error and continue
                errlCommit( err, SECURE_COMP_ID );
                continue;
            }

            if (op_actual_size != op_expected_size)
            {
                SB_ERR("getAllSecurityRegisters: size returned from device write (%d) is not the expected size of %d",
                       op_actual_size, op_expected_size);
                /*@
                 * @errortype
                 * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid        SECUREBOOT::MOD_SECURE_GET_ALL_SEC_REGS
                 * @reasoncode      SECUREBOOT::RC_DEVICE_WRITE_ERR
                 * @userdata1       Actual size written
                 * @userdata2       Expected size written
                 * @devdesc         Device write did not return expected size
                 * @custdesc        Firmware Error
                 */
                err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                SECUREBOOT::MOD_SECURE_GET_ALL_SEC_REGS,
                                SECUREBOOT::RC_DEVICE_WRITE_ERR,
                                op_actual_size,
                                op_expected_size,
                                true);
                addSecureUserDetailsToErrlog(err);
                err->collectTrace(SECURE_COMP_NAME);
                break;
            }

            // push back result
            l_secRegValues.tgt=procTgt;
            l_secRegValues.addr=op_addr;
            l_secRegValues.data=scomData;
            o_regs.push_back(l_secRegValues);

        } // end of targeting loop

    } // TargetList has some targets

    else
    {
        // Since targeting is NOT loaded or TargetList is empty only capture
        // data for MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
        l_secRegValues.tgt=TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        l_secRegValues.addr=static_cast<uint32_t>(ProcSecurity::SwitchRegister);
        err = getSecuritySwitch(l_secRegValues.data,
                                l_secRegValues.tgt);

        if( err )
        {
            // Something failed on the read.  Commit the error
            // here but continue
            SB_ERR("getAllSecurityRegisters: Error from getSecuritySwitch: "
                   "(0x%X) from Target 0x%.8X: RC=0x%X, PLID=0x%X",
                   l_secRegValues.addr,
                   TARGETING::get_huid(l_secRegValues.tgt),
                   ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

            // Commit error and continue
            errlCommit( err, SECURE_COMP_ID );
            break;
        }
        o_regs.push_back(l_secRegValues);

    } // using MASTER_PROCESSOR_CHIP_TARGET_SENTINEL

    } while(0);

    SB_EXIT("getAllSecurityRegisters(): err rc=0x%X, plid=0x%X, "
            "o_regs.size()=%d",
            ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err),
            o_regs.size());

    return err;
}

void* initializeBase(void* unused)
{
    errlHndl_t l_errl = NULL;

    do
    {
        // SecureROM manager verifies if the content necessary for secureboot in
        // the BltoHbData is valid or not. So initialize before anything else.
        // Don't enable SecureRomManager in VPO
#ifndef CONFIG_P9_VPO_COMPILE

        // Initialize the Secure ROM
        l_errl = initializeSecureRomManager();
        if (l_errl)
        {
            break;
        }
#endif

        // Load original header.
        l_errl = Singleton<Header>::instance().loadHeader();
        if (l_errl)
        {
            break;
        }
    } while(0);

    return l_errl;
}

#if defined(CONFIG_SECUREBOOT) && !defined(__HOSTBOOT_RUNTIME)
bool enabled()
{
    return Singleton<Settings>::instance().getEnabled();
}
#endif

errlHndl_t getSecuritySwitch(uint64_t& o_regValue, TARGETING::Target* i_pProc)
{
    return Singleton<Settings>::instance().getSecuritySwitch(o_regValue,
                                                                       i_pProc);
}

errlHndl_t getProcCbsControlRegister(uint64_t& o_regValue,
    TARGETING::Target* i_pProc)
{
    return Singleton<Settings>::instance().getProcCbsControlRegister(o_regValue,
        i_pProc);
}

errlHndl_t getJumperState(SecureJumperState& o_state,
                                                    TARGETING::Target* i_pProc)
{
    return Singleton<Settings>::instance().getJumperState(o_state, i_pProc);
}

errlHndl_t clearSecuritySwitchBits(
    const std::vector<SECUREBOOT::ProcSecurity>& i_bits,
          TARGETING::Target* const               i_pTarget)
{
    return Singleton<Settings>::instance().clearSecuritySwitchBits(
        i_bits, i_pTarget);
}

errlHndl_t setSecuritySwitchBits(
    const std::vector<SECUREBOOT::ProcSecurity>& i_bits,
          TARGETING::Target* const               i_pTarget)
{
    return Singleton<Settings>::instance().setSecuritySwitchBits(
        i_bits, i_pTarget);
}

void handleSecurebootFailure(errlHndl_t &io_err, const bool i_waitForShutdown,
                                                 const bool i_calledByRP)
{
    TRACFCOMP( g_trac_secure, ENTER_MRK"handleSecurebootFailure()");

    assert(io_err != NULL, "Secureboot Failure has a NULL error log")

    // Secure Boot failure is a critical error
    io_err->setSev(ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM);

    // Grab errlog reason code before committing.
    uint16_t l_rc = io_err->reasonCode();

#ifdef CONFIG_CONSOLE
    CONSOLE::displayf(SECURE_COMP_NAME, "Secureboot Failure plid = 0x%08X, rc = 0x%04X\n",
                      io_err->plid(), l_rc);
#endif
    printk("Secureboot Failure plid = 0x%08X, rc = 0x%04X\n",
           io_err->plid(),l_rc);

    // Add Verification callout
    io_err->addProcedureCallout(HWAS::EPUB_PRC_FW_VERIFICATION_ERR,
                               HWAS::SRCI_PRIORITY_HIGH);

    addSecureUserDetailsToErrlog(io_err, i_calledByRP);

    io_err->collectTrace(SECURE_COMP_NAME,MAX_ERROR_TRACE_SIZE);
    io_err->collectTrace(TRBOOT_COMP_NAME,MAX_ERROR_TRACE_SIZE);

    errlCommit(io_err, SECURE_COMP_ID);

    // If background shutdown requested, flush the error logs to ensure that the
    // security error is committed to PNOR.  Otherwise, it's possible for other
    // fail paths to TI Hostboot before the shutdown completes, potentially
    // leaving the security error uncommitted.
    if(!i_waitForShutdown)
    {
        ErrlManager::callFlushErrorLogs();
    }

    // Shutdown with Secureboot error status
    INITSERVICE::doShutdown(l_rc, !i_waitForShutdown);
}

errlHndl_t traceSecuritySettings(bool i_doConsoleTrace)
{
    SB_ENTER("traceSecuritySettings(): i_doConsoleTrace=%d", i_doConsoleTrace);
    errlHndl_t err = nullptr;

    std::vector<SecureRegisterValues> registerList;
    uint64_t l_SMDBits = 0;
    uint64_t l_SABBits = 0;
    TARGETING::ATTR_POSITION_type l_pos = 0;

    do
    {

    err = getAllSecurityRegisters(registerList);

    if (err)
    {
        SB_ERR("traceSecuritySettings: getAllSecurityRegisters returned error: "
               "RC=0x%X, PLID=0x%X",
               ERRL_GETRC_SAFE(err),
               ERRL_GETPLID_SAFE(err));
        break;
    }

    for( auto l_reg : registerList )
    {
        SB_DBG("traceSecuritySettings: register: tgt=0x%X, addr=0x%lX, data=0x%.16llX ",
               TARGETING::get_huid(l_reg.tgt),
               l_reg.addr, l_reg.data);

        if ( l_reg.addr == static_cast<uint32_t>(ProcSecurity::SwitchRegister) )
        {
            SB_INF("procTgt=0x%X: ProcSecurity::SwitchRegister(0x%x): 0x%.16llX: "
                   "SabBit=%d, SULBit=%d, SDBBit=%d, CMFSIBit=%d",
                   TARGETING::get_huid(l_reg.tgt), l_reg.addr, l_reg.data,
                   l_reg.data & static_cast<uint64_t>(ProcSecurity::SabBit)
                    ? 1 : 0,
                   l_reg.data & static_cast<uint64_t>(ProcSecurity::SULBit)
                    ? 1 : 0 ,
                   l_reg.data & static_cast<uint64_t>(ProcSecurity::SDBBit)
                    ? 1 : 0 ,
                   l_reg.data & static_cast<uint64_t>(ProcSecurity::CMFSIBit)
                    ? 1 : 0 );
        }

        else if ( ( l_reg.addr == static_cast<uint32_t>(ProcCbsControl::StatusRegister) ) ||
                  ( l_reg.addr == static_cast<uint32_t>(ProcCbsControl::StatusRegisterFsi) ) )
        {
            SB_INF("procTgt=0x%X: ProcCbsControl::StatusRegister(0x%x): 0x%.16llX: "
                   "SabBit=%d, SmdBit=%d",
                   TARGETING::get_huid(l_reg.tgt), l_reg.addr, l_reg.data,
                   l_reg.data & static_cast<uint64_t>(ProcCbsControl::SabBit)
                    ? 1 : 0,
                   l_reg.data & static_cast<uint64_t>(ProcCbsControl::JumperStateBit)
                    ? 1 : 0 );

           if (i_doConsoleTrace == true)
           {

               // Process this register for console output below
               l_pos=l_reg.tgt->getAttr<TARGETING::ATTR_POSITION>();

               if (l_reg.data & static_cast<uint64_t>(ProcCbsControl::SabBit))
               {
                   l_SABBits |= (0x8000000000000000 >> l_pos);
               }
               if (l_reg.data & static_cast<uint64_t>(ProcCbsControl::JumperStateBit))
               {
                   l_SMDBits |= (0x8000000000000000 >> l_pos);
               }
           }

        }

    } // output vector loop

    if (i_doConsoleTrace == true)
    {
#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
        // Using 2 uint32_t's due to CONSOLE BUG displaying uint64_t
        CONSOLE::displayf("SECURE", "Security Access Bit> 0x%.8X%.8X",
                          l_SABBits>>32, l_SABBits&0xFFFFFFFF );

        CONSOLE::displayf("SECURE", "Secure Mode Disable (via Jumper)> 0x%.8X%.8X",
                          l_SMDBits>>32, l_SMDBits&0xFFFFFFFF );
#endif
        SB_INF("Security Access Bit> 0x%.16llX", l_SABBits);
        SB_INF("Secure Mode Disable (via Jumper)> 0x%.16llX", l_SMDBits);
    }


    } while(0);

    SB_EXIT("traceSecuritySettings(): err rc=0x%X, plid=0x%X",
            ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

    return err;
}


void addSecurityRegistersToErrlog(errlHndl_t & io_err,
                                  const bool i_calledByRP)
{
    SB_ENTER("addSecurityRegistersToErrlog(): io_err rc=0x%X, plid=0x%X",
             ERRL_GETRC_SAFE(io_err), ERRL_GETPLID_SAFE(io_err));

    errlHndl_t new_err = nullptr;


    std::vector<SecureRegisterValues> registerList;

    do
    {

    new_err = getAllSecurityRegisters(registerList, i_calledByRP);

    if (new_err)
    {
        SB_ERR("addSecurityRegistersToErrlog: getAllSecurityRegisters returned "
               "error: RC=0x%X, PLID=0x%X. Commiting this error and NOT adding "
               "data to io_err",
               ERRL_GETRC_SAFE(new_err),
               ERRL_GETPLID_SAFE(new_err));

        // Commit error and break
        errlCommit(new_err, SECURE_COMP_ID );
        break;
    }

    for( auto l_reg : registerList )
    {

        if (l_reg.addr == static_cast<uint32_t>(ProcCbsControl::StatusRegisterFsi))
        {
            ERRORLOG::ErrlUserDetailsLogRegister l_logReg(l_reg.tgt,
                                                      &l_reg.data,
                                                      sizeof(l_reg.data),
                                                      DEVICE_FSI_ADDRESS(l_reg.addr));
            l_logReg.addToLog(io_err);
        }
        else
        {
            ERRORLOG::ErrlUserDetailsLogRegister l_logReg(l_reg.tgt,
                                                      &l_reg.data,
                                                      sizeof(l_reg.data),
                                                      DEVICE_SCOM_ADDRESS(l_reg.addr));
            l_logReg.addToLog(io_err);
        }


    } // end of registerList loop

    } while(0);

    SB_EXIT("addSecurityRegistersToErrlog(): io_err rc=0x%X, plid=0x%X",
            ERRL_GETRC_SAFE(io_err), ERRL_GETPLID_SAFE(io_err));

    return;
}

void addSecureUserDetailsToErrlog(errlHndl_t & io_err,
                                   const bool i_calledByRP)
{
    // Add Security Settings
    UdSecuritySettings().addToLog(io_err);

    // Add security register values
    addSecurityRegistersToErrlog(io_err, i_calledByRP);

    // Add System HW Keys' Hash
    SHA512_t hash = {0};
    getHwKeyHash(hash);
    SB_INF_BIN("Sys HwKeyHash", &hash, sizeof(hash));
    UdSystemHwKeyHash( hash ).addToLog(io_err);

    //Note: adding UdTargetHwKeyHash left to Extended image
}

#ifndef __HOSTBOOT_RUNTIME
bool allowAttrOverrides()
{
    bool retVal = false;

    if (enabled())
    {
        if (g_BlToHbDataManager.getAllowAttrOverrides())
        {
            retVal = true;
            SB_INF("allowAttrOverrides: Allowing Attr Overrides in "
                   "Secure Mode: retVal=%d", retVal);
        }
        else
        {
            retVal = false;
            SB_INF("allowAttrOverrides: DO NOT Allow Attr Overrides in "
                   "Secure Mode: retVal=%d", retVal);
        }
    }
    else
    {
        retVal = true;
        SB_DBG("allowAttrOverrides: Allow Attr Overrides in "
                "Unsecure Mode: retVal=%d", retVal);
    }

    return retVal;
};
#endif

bool getSbeSecurityBackdoor()
{
    bool l_backdoorEnabled = false;

    if(g_BlToHbDataManager.getSecBackdoor())
    {
        l_backdoorEnabled = true;
        SB_INF("getSbeSecurityBackdoor: SBE Security Backdoor is enabled.");
    }
    else
    {
        l_backdoorEnabled = false;
        SB_INF("getSbeSecurityBackdoor: SBE Security Backdoor is disabled.");
    }
    return l_backdoorEnabled;
}

uint8_t getSbeSecurityMode()
{
    return g_sbeSecurityMode;
}

errlHndl_t setSbeSecurityMode(uint8_t i_sbeSecurityMode)
{
    errlHndl_t l_errl = nullptr;

    do {
    // Ensure a valid mode
    if (i_sbeSecurityMode != 0 && i_sbeSecurityMode != 1)
    {
        SB_ERR("SBE Security Mode can only be set to 0 or 1");

        /*@
         * @errortype
         * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid        SECUREBOOT::MOD_SECURE_SET_SBE_SECURE_MODE
         * @reasoncode      SECUREBOOT::RC_SBE_INVALID_SEC_MODE
         * @userdata1       Security mode to set
         * @userdata2       0
         * @devdesc         Invalid SBE security mode
         * @custdesc        Platform security problem detected
         */
        l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        SECUREBOOT::MOD_SECURE_SET_SBE_SECURE_MODE,
                        SECUREBOOT::RC_SBE_INVALID_SEC_MODE,
                        i_sbeSecurityMode,
                        0,
                        true);
        l_errl->collectTrace(SECURE_COMP_NAME);
        addSecureUserDetailsToErrlog(l_errl);
        break;
    }

    g_sbeSecurityMode = i_sbeSecurityMode;

    } while(0);

    return l_errl;
}

} //namespace SECUREBOOT
