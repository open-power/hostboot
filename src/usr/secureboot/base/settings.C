/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/settings.C $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#include <errl/errlentry.H>
#include <devicefw/userif.H>

#include "settings.H"

namespace SECUREBOOT
{
    const uint64_t Settings::SECURITY_SWITCH_REGISTER = 0x00010005;
    const uint64_t
        Settings::SECURITY_SWITCH_TRUSTED_BOOT = 0x4000000000000000ull;

    void Settings::_init()
    {
        errlHndl_t l_errl = NULL;
        size_t size = sizeof(iv_regValue);

        // Read / cache security switch setting from processor.
        l_errl = deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            &iv_regValue, size,
                            DEVICE_SCOM_ADDRESS(SECURITY_SWITCH_REGISTER));

        // If this errors, we're in bad shape and shouldn't trust anything.
        assert(NULL == l_errl);
    }

    bool Settings::getEnabled()
    {
        return 0 != (iv_regValue & SECURITY_SWITCH_TRUSTED_BOOT);
    }
}
