/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/secure_reasoncodes.H $             */
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
#ifndef __SECUREBOOT_REASONCODES_H
#define __SECUREBOOT_REASONCODES_H

#include <hbotcompid.H>

namespace SECUREBOOT
{
    enum SECUREModuleId
    {
        MOD_SECURE_INVALID              = 0x00,
        MOD_SECURE_BLINDPURGE           = 0x01,
        MOD_SECURE_ROM_INIT             = 0x02,
        MOD_SECURE_ROM_VERIFY           = 0x03,
        MOD_SECURE_ROM_CLEANUP          = 0x04,
   };

    enum SECUREReasonCode
    {
        RC_PURGEOP_PENDING              = SECURE_COMP_ID | 0x01,
        RC_PURGEOP_FAIL_COMPLETE        = SECURE_COMP_ID | 0x02,
        RC_DEV_MAP_FAIL                 = SECURE_COMP_ID | 0x03,
        RC_PAGE_ALLOC_FAIL              = SECURE_COMP_ID | 0x04,
        RC_SET_PERMISSION_FAIL_EXE      = SECURE_COMP_ID | 0x05,
        RC_SET_PERMISSION_FAIL_WRITE    = SECURE_COMP_ID | 0x06,
        RC_ROM_VERIFY                   = SECURE_COMP_ID | 0x07,
    };
}

#endif
