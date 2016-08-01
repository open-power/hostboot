/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/coreops.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <stdint.h>
#include <sys/task.h>
#include <sys/time.h>
#include <devicefw/userif.H>
#include <secureboot/secure_reasoncodes.H>
#include <errl/errludtarget.H>
#include <secureboot/service.H>

#include "coreops.H"

// Quick change for unit testing
#define TRACUCOMP(args...)  TRACFCOMP(args)
//#define TRACUCOMP(args...)

namespace SECUREBOOT
{
    /**
     *  @brief Return core ID of running thread
     *
     *  @return size_t Running thread's core ID
     */
    inline size_t getCoreId(void)
    {
        return (task_getcpuid() / 8) & 0xF;
    }

    errlHndl_t unprotectCore(void)
    {
        TRACUCOMP(g_trac_secure,ENTER_MRK"SECUREBOOT::unprotectCore>");

        errlHndl_t pError = NULL;

        bool readFail = false;
        bool writeFail = false;
        const size_t coreId = getCoreId();
        const uint64_t regAddr = CORE_PROTECT_REG_0x10013C03
             + (EX_CHILPLET_MULTIPLIER * coreId);
        TARGETING::Target* const pMasterProc =
            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        do {

        // Disable core protect bit
        uint64_t data = 0;
        size_t size = sizeof(data);
        const size_t expSize = size;

        pError = deviceRead(
            pMasterProc,
            &data, size,
            DEVICE_SCOM_ADDRESS(regAddr));
        if(pError)
        {
            readFail = true;
            break;
        }

        assert(expSize==size,"Expected size %d returned from SCOM read "
                            "!= actual size %d",expSize,size);

        data &= ~CORE_PROTECT_TRUSTED_BOOT_EN_BIT0;
        pError = deviceWrite(
            pMasterProc,
            &data, size,
            DEVICE_SCOM_ADDRESS(regAddr));
        if(pError)
        {
            writeFail = true;
            break;
        }

        assert(expSize==size,"Expected size %s returned from SCOM write "
                            "!= actual size %d",expSize,size);

        } while(0);

        if(pError)
        {
            TRACFCOMP(g_trac_secure,ERR_MRK"Failed to read (failed? %d) or "
                "write (failed? %d) core protect register 0x%08X for core ID "
                "%d. Error Log reason code = 0x%04X, eid = 0x%08X, "
                "plid = 0x%08X",
                readFail,writeFail,regAddr,coreId,pError->reasonCode(),
                pError->eid(), pError->plid());

            ERRORLOG::ErrlUserDetailsTarget(pMasterProc).addToLog(pError);

            pError->collectTrace(SECURE_COMP_NAME);
        }

        TRACUCOMP(g_trac_secure,EXIT_MRK"SECUREBOOT::unprotectCore>");

        return pError;
    }

    errlHndl_t issueBlindPurge()
    {
        static const uint64_t PURGE_REG = 0x1001080e;

            // Bits : Value
            // 0    : 0b1 = Initiate Purge
            // 1:4  : 0b0100 = Full Blind Purge
            // 13:28 : 0x1000 = CGC is (512k / 128 byte line size)
            //          CGC means "Congruence Class", ie. cache row.
        static const uint64_t PURGE_VALUE = 0xa000800000000000;

            // Bit 0 - Purge Pending.
        static const uint64_t PURGE_PENDING = 0x8000000000000000;

        static const size_t RETRY_COUNT = 100;
        static const size_t RETRY_WAIT_NS = ONE_CTX_SWITCH_NS;

        errlHndl_t l_errl = NULL;
        do
        {
            size_t coreId = getCoreId();
            uint64_t regAddr = PURGE_REG + 0x01000000 * coreId;

            uint64_t data = 0;
            size_t size = sizeof(data);

            // Read purge register to ensure no operation is pending.
            l_errl =
                deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                           &data, size,
                           DEVICE_SCOM_ADDRESS(regAddr));
            if (l_errl)
            {
                break;
            }

            if (data & PURGE_PENDING)
            {
                /*@
                 * @errortype
                 * @moduleid    SECUREBOOT::MOD_SECURE_BLINDPURGE
                 * @reasoncode  SECUREBOOT::RC_PURGEOP_PENDING
                 * @userdata1   SCOM value.
                 * @userdata2   CPU ID (PIR) encountering failure.
                 * @devdesc     Attempted to purge cache while purge operation
                 *              was pending.
                 */
                l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MOD_SECURE_BLINDPURGE,
                                            RC_PURGEOP_PENDING,
                                            data, task_getcpuid());
                // Probably a code bug
                l_errl->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                             HWAS::SRCI_PRIORITY_HIGH );
                // But there might be something wrong with the chip
                //  or the SBE image
                l_errl->addHwCallout(
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          HWAS::SRCI_PRIORITY_LOW,
                          HWAS::NO_DECONFIG,
                          HWAS::GARD_NULL );
                break;
            }

            // Initiate purge operation
            data = PURGE_VALUE;
            l_errl =
                deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            &data, size,
                            DEVICE_SCOM_ADDRESS(regAddr));
            if (l_errl)
            {
                break;
            }

            // Wait for purge to complete.
            for(size_t i = 0; i < RETRY_COUNT; i++)
            {
                l_errl =
                    deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                               &data, size,
                               DEVICE_SCOM_ADDRESS(regAddr));

                if ((l_errl) || !(data & PURGE_PENDING))
                {
                    break;
                }

                nanosleep(0, RETRY_WAIT_NS);
            }
            if (l_errl)
            {
                break;
            }
            if (data & PURGE_PENDING) // Ensure op did complete.
            {
                /*@
                 * @errortype
                 * @moduleid    SECUREBOOT::MOD_SECURE_BLINDPURGE
                 * @reasoncode  SECUREBOOT::RC_PURGEOP_FAIL_COMPLETE
                 * @userdata1   SCOM value of Reg 0x1001080E
                 * @devdesc     Purge operation never completed.
                 */
                l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MOD_SECURE_BLINDPURGE,
                                            RC_PURGEOP_FAIL_COMPLETE,
                                            data);
                // Most likely a hardware issue of some sort
                l_errl->addHwCallout(
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          HWAS::SRCI_PRIORITY_HIGH,
                          HWAS::NO_DECONFIG,
                          HWAS::GARD_NULL );
                // Could also be a code bug
                l_errl->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                             HWAS::SRCI_PRIORITY_MED );
                break;
            }

        } while(0);

        return l_errl;
    }

}
