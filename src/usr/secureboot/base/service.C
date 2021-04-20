/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/service.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
 * @file service.C
 *
 * @brief Provides implementations for secureboot init code and the basic
 *        secureboot functions
 */

#include <secureboot/service.H>
#include <stdint.h>
#include <sys/mm.h>
#include <util/singleton.H>
#include <secureboot/secure_reasoncodes.H>
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

#include <secureboot/settings.H>
#include "../common/securetrace.H"
#include "../common/errlud_secure.H"

// Quick change for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


using namespace ERRORLOG;
using namespace TARGETING;

namespace
{

/*
 * @brief Determines if the given target handle can be XSCOM-ed.
 *
 * @param[in]   i_pProc     The target to assess.
 *
 * @return      errlHndl_t  nullptr if the target can be XSCOM-ed. Otherwise, an error.
 */
errlHndl_t canXscomProc(const TargetHandle_t i_pProc)
{
    errlHndl_t err = nullptr;

    // Assume the op can't be done.
    bool do_op = false;

    // Need to support MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    if (i_pProc == MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {
        do_op = true;
    }
    else if (Util::isTargetingLoaded())
    {
        // Check that i_pProc isn't nullptr and is of type proc
        assert((i_pProc != nullptr) &&
               (i_pProc->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC ),
               "canXscomProc: i_pProc either nullptr or !TYPE_PROC");

        if (i_pProc->getAttr<ATTR_SCOM_SWITCHES>().useXscom)
        {
            do_op = true;
        }
    }

    // Can't XSCOM the proc, return an error.
    if (do_op != true)
    {
        // Fail since proc target is not scommable at this time
        // NOTE: the master proc is always scommable
        SB_ERR("canXscomProc: FAIL: Tgt=0x%.08X not set up to use Xscom at this time",
               TARGETING::get_huid(i_pProc));

        /*@
         * @errortype
         * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid        SECUREBOOT::MOD_CAN_XSCOM_PROC
         * @reasoncode      SECUREBOOT::RC_SECURE_BAD_TARGET
         * @userdata1       HUID of Processor Target
         * @userdata2       <unused>
         * @devdesc         Processor Parameter is not scommable
         * @custdesc        A firmware error occurred.
         */
        err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        SECUREBOOT::MOD_CAN_XSCOM_PROC,
                        SECUREBOOT::RC_SECURE_BAD_TARGET,
                        get_huid(i_pProc),
                        0,
                        ErrlEntry::ADD_SW_CALLOUT);

        err->collectTrace(SECURE_COMP_NAME);
    }

    return err;
}

/*
 * @brief   Reads a given Measurement SEEPROM register from the given SecureRegisterValues struct and returns the data.
 *          Will verify that the given target is xscommable.
 *
 * @param[in/out]  io_reg        The register to read from for the given proc.
 *
 * @return         errlHndl_t    nullptr on success. Otherwise, an error.
 */
errlHndl_t readSbeMeasurementRegister(SecureRegisterValues& io_reg)
{
    errlHndl_t err = nullptr;

    SB_DBG("readSbeMeasurementRegister: Getting Target=0x%.08X Reg=0x%.08X",
           TARGETING::get_huid(io_reg.procTgt), io_reg.addr);

    do {
        // Do the operation if we have a valid target.
        err = canXscomProc(io_reg.procTgt);
        if (err)
        {
            // Can't perform the op with this proc.
            break;
        }

        // Read the register
        io_reg.data = 0x0;
        size_t op_actual_size = sizeof(io_reg.data);
        const size_t op_expected_size = op_actual_size;

        err = deviceRead( io_reg.procTgt,
                          &(io_reg.data),
                          op_actual_size,
                          DEVICE_SCOM_ADDRESS(io_reg.addr));

        if( err )
        {
            // Something failed on the read.
            SB_ERR("readSbeMeasurementRegister: Error from scom read: "
                   "Target 0x%.8X: Register: 0x%.8X "
                   TRACE_ERR_FMT,
                   TARGETING::get_huid(io_reg.procTgt),
                   io_reg.addr,
                   TRACE_ERR_ARGS(err));

            // Don't expect any xscom errors so break and return this error
            err->collectTrace(SECURE_COMP_NAME);
            break;
        }

        if (op_actual_size != op_expected_size)
        {
            SB_ERR("readSbeMeasurementRegister: size returned from device read (%d) is not the expected size of %d",
                   op_actual_size, op_expected_size);
            /*@
             * @errortype
             * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid        SECUREBOOT::MOD_READ_SBE_MEASUREMENT_REGISTER
             * @reasoncode      SECUREBOOT::RC_DEVICE_READ_ERR
             * @userdata1       Actual size read
             * @userdata2       Expected size read
             * @devdesc         Device read did not return expected size
             * @custdesc        A firmware error occurred.
             */
            err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            SECUREBOOT::MOD_READ_SBE_MEASUREMENT_REGISTER,
                            SECUREBOOT::RC_DEVICE_READ_ERR,
                            op_actual_size,
                            op_expected_size,
                            ErrlEntry::ADD_SW_CALLOUT);

            // Don't expect any xscom errors so break and return this error
            err->collectTrace(SECURE_COMP_NAME);
            break;
        }
    } while(0);

    return err;
}

};


namespace SECUREBOOT
{

// TODO securebootp9 - Do a diff of this file with the p8 version make sure
// all the missing parts are brought in.


// Local structure and function prototypes used below

/*
 * HB specific secureboot setting which is aliased to the FAPI attribute
 * ATTR_SECURITY_MODE and customized into the SBE image.  If 0b0, requesting
 * SBE to disable proc security (via SAB bit);  Otherwise, if 0b1, requesting
 * SBE to enable proc security.
 */
uint8_t g_sbeSecurityMode = 1;


/** @brief Get All SBE Measurement Registers
 *
 *  See service.H for more details
 */
errlHndl_t getSbeMeasurementRegisters(
            std::vector<SecureRegisterValues> & o_regs,
            TARGETING::Target* i_pProc)
{
    errlHndl_t err = nullptr;
    o_regs.clear();

    SB_ENTER("getSbeMeasurementRegisters: Target=0x%.08X",
             get_huid(i_pProc));

    SecureRegisterValues l_regValue;

    do {

        l_regValue.procTgt=i_pProc;

        for ( const auto scom_reg : sbe_measurement_regs )
        {
            l_regValue.addr = scom_reg;

            err = readSbeMeasurementRegister(l_regValue);
            if (err)
            {
                break;
            }
            // push back result
            o_regs.push_back(l_regValue);

        } // end of loop on SBE Measurement Registers
        if (err)
        {
            break;
        }

    } while(0);

    SB_EXIT("getSbeMeasurementRegisters: o_regs.size()=%d "
            TRACE_ERR_FMT,
            o_regs.size(),
            TRACE_ERR_ARGS(err));

    return err;
}

/** @brief Get an SBE Measurement register
 *
 *  See service.H for more details
 */
errlHndl_t getSbeMeasurementRegister(SecureRegisterValues& io_reg)
{
    errlHndl_t err = nullptr;

    SB_ENTER("getSbeMeasurementRegister: Target=0x%.08X",
             get_huid(io_reg.procTgt));

    // The upper portion of the measurement seeprom address range
    constexpr uint32_t ADDR = 0x1001;
    // The lower four bits of any value are valid, so shift those off and check
    // the rest of the address to ensure it's in range.
    assert(ADDR == (io_reg.addr >> 4),
          "getSbeMeasurementRegister: Requested address is out of range for SBE Measurement SEEPROM");

    do {

        // Call function to read the requested reg.
        err = readSbeMeasurementRegister(io_reg);
        if (err)
        {
            break;
        }

    } while(0);

    return err;
}


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
    std::vector<SecureRegisterValues> l_sbeMeasurementRegValues;

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
                l_secRegValues.procTgt=procTgt;
                l_secRegValues.addr=static_cast<uint32_t>(ProcSecurity::SwitchRegister);
                err = getSecuritySwitch(l_secRegValues.data,
                                        l_secRegValues.procTgt);
                if( err )
                {
                    // Something failed on the read.  Commit the error
                    // here but continue
                    SB_ERR("getAllSecurityRegisters: Error from getSecuritySwitch: "
                           "(0x%X) from Target 0x%.8X: RC=0x%X, PLID=0x%X",
                           l_secRegValues.addr,
                           TARGETING::get_huid(l_secRegValues.procTgt),
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
                                ErrlEntry::ADD_SW_CALLOUT);
                addSecureUserDetailsToErrlog(err);
                err->collectTrace(SECURE_COMP_NAME);
                break;
            }

            // push back result
            l_secRegValues.procTgt=procTgt;
            l_secRegValues.addr=op_addr;
            l_secRegValues.data=scomData;
            o_regs.push_back(l_secRegValues);


            /****************************************/
            // Get SBE Measurement Registers
            /****************************************/
            // can only get these register if processor target is scommable
            // ie, the the proc chip supports xscom..
            if (procTgt->getAttr<ATTR_SCOM_SWITCHES>().useXscom)
            {
                err = getSbeMeasurementRegisters(l_sbeMeasurementRegValues, procTgt);
                if( err )
                {
                    // Something failed on the read.  Commit the error
                    // here but continue
                    SB_ERR("getAllSecurityRegisters: Error from getSbeMeasurementRegisters: "
                           "Target 0x%.8X: "
                           TRACE_ERR_FMT,
                           TARGETING::get_huid(procTgt),
                           TRACE_ERR_ARGS(err));
                    // Commit error and continue
                    errlCommit( err, SECURE_COMP_ID );
                    continue;
                }
                else
                {
                    o_regs.insert(o_regs.end(),
                                  l_sbeMeasurementRegValues.begin(),
                                  l_sbeMeasurementRegValues.end());
                }
            }
        } // end of targeting loop

    } // TargetList has some targets

    else
    {
        // Since targeting is NOT loaded or TargetList is empty only capture
        // data for MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
        l_secRegValues.procTgt=TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        l_secRegValues.addr=static_cast<uint32_t>(ProcSecurity::SwitchRegister);
        err = getSecuritySwitch(l_secRegValues.data,
                                l_secRegValues.procTgt);

        if( err )
        {
            // Something failed on the read.  Commit the error
            // here but continue
            SB_ERR("getAllSecurityRegisters: Error from getSecuritySwitch: "
                   "(0x%X) from Target 0x%.8X: RC=0x%X, PLID=0x%X",
                   l_secRegValues.addr,
                   TARGETING::get_huid(l_secRegValues.procTgt),
                   ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

            // Commit error and continue
            errlCommit( err, SECURE_COMP_ID );
            break;
        }
        o_regs.push_back(l_secRegValues);

        // Add SBE Mesasurement Registers
        Target* l_procTgt = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        err = getSbeMeasurementRegisters(l_sbeMeasurementRegValues,
                                         l_procTgt);
        if( err )
        {
            // Something failed; commit the error here but continue
            SB_ERR("getAllSecurityRegisters: Error from getSbeMeasurementRegisters: "
                   "Target 0x%.8X: "
                   TRACE_ERR_FMT,
                   TARGETING::get_huid(l_procTgt),
                   TRACE_ERR_ARGS(err));

            // Commit error and continue
            errlCommit( err, SECURE_COMP_ID );
        }
        else
        {
            o_regs.insert(o_regs.end(),
                           l_sbeMeasurementRegValues.begin(),
                           l_sbeMeasurementRegValues.end());
        }

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

        // Initialize the Secure ROM
        l_errl = initializeSecureRomManager();
        if (l_errl)
        {
            break;
        }

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
    CONSOLE::displayf(CONSOLE::DEFAULT, SECURE_COMP_NAME, "Secureboot Failure plid = 0x%08X, rc = 0x%04X\n",
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

    // Trace Settings from SBE-to-HBBL
    SB_INF("traceSecuritySettings(): SBE-to-HBBL Security Settings: "
           "secAccessBit=0x%.2X, secOverride=0x%.2X, allowAttrOverride=0%.2X, "
           "minSecureVersion=0x%.2X, measurementSeepromVersion=0x%.8X",
           g_BlToHbDataManager.getSecureAccessBit(),
           g_BlToHbDataManager.getSecurityOverride(),
           g_BlToHbDataManager.getAllowAttrOverrides(),
           g_BlToHbDataManager.getMinimumSecureVersion(),
           g_BlToHbDataManager.getMeasurementSeepromVersion());

    // Trace Security Regisgers
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

        SB_INF("traceSecuritySettings: register:.procTgt=0x%X, addr=0x%lX, data=0x%.16llX ",
               TARGETING::get_huid(l_reg.procTgt),
               l_reg.addr, l_reg.data);

        if ( l_reg.addr == static_cast<uint32_t>(ProcSecurity::SwitchRegister) )
        {
            SB_INF("procTgt=0x%X: ProcSecurity::SwitchRegister(0x%x): 0x%.16llX: "
                   "SabBit=%d, SULBit=%d, SDBBit=%d, CMFSIBit=%d",
                   TARGETING::get_huid(l_reg.procTgt), l_reg.addr, l_reg.data,
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
                   TARGETING::get_huid(l_reg.procTgt), l_reg.addr, l_reg.data,
                   l_reg.data & static_cast<uint64_t>(ProcCbsControl::SabBit)
                    ? 1 : 0,
                   l_reg.data & static_cast<uint64_t>(ProcCbsControl::JumperStateBit)
                    ? 1 : 0 );

           if (i_doConsoleTrace == true)
           {

               // Process this register for console output below
               l_pos=l_reg.procTgt->getAttr<TARGETING::ATTR_POSITION>();

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
        CONSOLE::displayf(CONSOLE::DEFAULT, "SECURE", "Security Access Bit> 0x%.8X%.8X",
                          l_SABBits>>32, l_SABBits&0xFFFFFFFF );

        CONSOLE::displayf(CONSOLE::DEFAULT, "SECURE", "Secure Mode Disable (via Jumper)> 0x%.8X%.8X",
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
            ERRORLOG::ErrlUserDetailsLogRegister l_logReg(l_reg.procTgt,
                                                      &l_reg.data,
                                                      sizeof(l_reg.data),
                                                      DEVICE_FSI_ADDRESS(l_reg.addr));
            l_logReg.addToLog(io_err);
        }
        else
        {
            ERRORLOG::ErrlUserDetailsLogRegister l_logReg(l_reg.procTgt,
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

void logPlatformSecurityConfiguration(void)
{
    SHA512_t hash = {0};
    getHwKeyHash(hash);

    /*@
     * @errortype
     * @moduleid          SECUREBOOT::MOD_SECURE_LOG_PLAT_SECURITY_CONFIG
     * @reasoncode        SECUREBOOT::RC_SECURE_LOG_PLAT_SECURITY_CONFIG
     * @userdata1         Minimum FW Secure Version
     * @userdata2[0:31]   Measurement Seeprom Version
     * @userdata2[32:63]  System HW Keys' Hash
     * @devdesc    Planar jumper configuration and other security info
     * @custdesc   Planar jumper configuration
     */
    errlHndl_t pError = new ERRORLOG::ErrlEntry(
        ERRORLOG::ERRL_SEV_INFORMATIONAL,
        SECUREBOOT::MOD_SECURE_LOG_PLAT_SECURITY_CONFIG,
        SECUREBOOT::RC_SECURE_LOG_PLAT_SECURITY_CONFIG,
        getMinimumSecureVersion(),
        TWO_UINT32_TO_UINT64(
            g_BlToHbDataManager.getMeasurementSeepromVersion(),
            sha512_to_u32(hash)));
    (void)addSecureUserDetailsToErrlog(
        pError);
    ERRORLOG::errlCommit(pError,SECURE_COMP_ID);

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
                        ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        addSecureUserDetailsToErrlog(l_errl);
        break;
    }

    g_sbeSecurityMode = i_sbeSecurityMode;

    } while(0);

    return l_errl;
}

} //namespace SECUREBOOT
