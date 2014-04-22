/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/purge.C $                             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <stdint.h>
#include <sys/task.h>
#include <sys/time.h>
#include <devicefw/userif.H>
#include <secureboot/secure_reasoncodes.H>

#include "purge.H"

namespace SECUREBOOT
{
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
            size_t coreId = (task_getcpuid() / 8) & 0xF;
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
