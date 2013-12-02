/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/kernel_reasoncodes.H $                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
#ifndef __KERNEL_REASONCODES_H
#define __KERNEL_REASONCODES_H


#include <usr/hbotcompid.H>


    enum KernelModuleId
    {
        MOD_KERNEL_INVALID   = 0x00, /**< Zero is an invalid module id */
        MOD_KERNEL_TERMINATE = 0x01, /**< terminate.C : save SRC */

    };

    enum KernelReasonCode
    {
        //NOTE: RC_ASSERT and RC_SHUTDOWN must be used in one unique
        //  locationto maintain uniqueness as they will be used
        //  without a MODULE ID.
        RC_ASSERT            = KERNEL_COMP_ID | 0x01, /**< Assert */
        RC_SHUTDOWN          = KERNEL_COMP_ID | 0x02, /**< Shutdown */
        RC_UNHANDLED_EX      = KERNEL_COMP_ID | 0x03, /**< Unhandled Except. */
    };

#endif
