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
        static const uint64_t PURGE_REG[] = {
            EX_L2_PURGE_REGISTER,
            EX_L3_PURGE_REGISTER
        };

        static const uint64_t PURGE_VALUE[] = {
            // L2, full purge.
                0x8000000000000000,
            // L3, blind purge.
            // Bits  : Value
            // 0     : 0b1 = Initiate Purge
            // 1:4   : 0b0100 = Full Blind Purge
            // 13:15 : 0b000 = Member value (ignored for full blind purge)
            // 16:28 : 0x8000 = CGC is (512k / 128 byte line size)
            //          CGC means "Congruence Class", ie. cache row.
                0xa000800000000000
        };

        static const uint64_t PURGE_PENDING[] = {
            // L2 bit 9,10,11 - purge pending.
                0x0070000000000000,
            // L3 bit 0 - purge pending.
                0x8000000000000000
        };

        static const size_t RETRY_COUNT = 100;
        static const size_t RETRY_WAIT_NS = ONE_CTX_SWITCH_NS;

        errlHndl_t pError = NULL;

        for (size_t reg = 0;
             reg < (sizeof(PURGE_REG)/sizeof(PURGE_REG[0]));
             ++reg)
        {
            const size_t coreId = getCoreId();
            const uint64_t regAddr = PURGE_REG[reg] +
                (EX_CHILPLET_MULTIPLIER * coreId);

            uint64_t data = 0;
            size_t size = sizeof(data);

            // Read purge register to ensure no operation is pending.
            pError = deviceRead(
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                &data, size,
                DEVICE_SCOM_ADDRESS(regAddr));
            if (pError)
            {
                break;
            }

            assert(size == sizeof(data),
                   "BUG! Returned SCOM size was %d, expected %d",
                   size,sizeof(data));

            if (data & PURGE_PENDING[reg])
            {
                /*@
                 * @errortype
                 * @moduleid          SECUREBOOT::MOD_SECURE_BLINDPURGE
                 * @reasoncode        SECUREBOOT::RC_PURGEOP_PENDING
                 * @userdata1         SCOM value.
                 * @userdata2[0:31]   CPU ID (PIR) encountering failure.
                 * @userdata2[32:63]  SCOM address read.
                 * @devdesc           Attempted to purge cache while purge
                 *                    operation was pending.
                 * @custdesc          Failed to initialize boot core cache
                 */
                pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    MOD_SECURE_BLINDPURGE,
                    RC_PURGEOP_PENDING,
                    data,
                    TWO_UINT32_TO_UINT64(
                        task_getcpuid(),
                        regAddr),
                    true); // Add high priority HB callout

                // There is a small chance something is wrong with the chip
                // or the SBE image
                pError->addHwCallout(
                    TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                    HWAS::SRCI_PRIORITY_LOW,
                    HWAS::NO_DECONFIG,
                    HWAS::GARD_NULL );
                break;
            }

            // Initiate purge operation
            data = PURGE_VALUE[reg];
            pError = deviceWrite(
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                &data, size,
                DEVICE_SCOM_ADDRESS(regAddr));
            if (pError)
            {
                break;
            }

            assert(size == sizeof(data),
                   "BUG! After SCOM write, SCOM size was %d, expected %d",
                   size,sizeof(data));

            // Wait for purge to complete.
            for(size_t i = 0; i < RETRY_COUNT; ++i)
            {
                data = 0;
                pError = deviceRead(
                    TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                    &data, size,
                    DEVICE_SCOM_ADDRESS(regAddr));

                // Error or not, size should not change
                assert(size == sizeof(data),
                       "BUG! Returned SCOM size was %d, expected %d",
                       size,sizeof(data));

                if ((pError) || !(data & PURGE_PENDING[reg]))
                {
                    break;
                }

                nanosleep(0, RETRY_WAIT_NS);
            }

            if (pError)
            {
                break;
            }

            if (data & PURGE_PENDING[reg]) // Ensure purge completed.
            {
                /*@
                 * @errortype
                 * @moduleid          SECUREBOOT::MOD_SECURE_BLINDPURGE
                 * @reasoncode        SECUREBOOT::RC_PURGEOP_FAIL_COMPLETE
                 * @userdata1         SCOM value
                 * @userdata2[0:31]   CPU ID (PIR) encountering failure.
                 * @userdata2[32:63]  SCOM address read.
                 * @devdesc           Purge operation never completed.
                 * @custdesc          Failed to initialize boot core cache
                 */
                pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    MOD_SECURE_BLINDPURGE,
                    RC_PURGEOP_FAIL_COMPLETE,
                    data,
                    TWO_UINT32_TO_UINT64(
                        task_getcpuid(),
                        regAddr));

                // Most likely a hardware issue of some sort
                pError->addHwCallout(
                    TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                    HWAS::SRCI_PRIORITY_HIGH,
                    HWAS::NO_DECONFIG,
                    HWAS::GARD_NULL );

                // Could also be a code bug
                pError->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                             HWAS::SRCI_PRIORITY_MED );
                break;
            }

        }

        return pError;
    }

}
