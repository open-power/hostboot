/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/kernel_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#ifndef __KERNEL_REASONCODES_H
#define __KERNEL_REASONCODES_H


#include <usr/hbotcompid.H>

namespace KERNEL
{
    enum KernelModuleId
    {
        MOD_KERNEL_INVALID   = 0x00, /**< Zero is an invalid module id */
        MOD_KERNEL_TERMINATE = 0x01, /**< terminate.C : save SRC */
        
    };

    enum KernelReasonCode
    {
        //NOTE: RC_ASSERT and RC_SHUTDOWN must be used in one unique
        //  location to maintain uniqueness as they will be used
        //  without a MODULE ID.
        RC_ASSERT            = KERNEL_COMP_ID | 0x01, /**< Assert */
        RC_SHUTDOWN          = KERNEL_COMP_ID | 0x02, /**< Shutdown */
        RC_UNHANDLED_EX      = KERNEL_COMP_ID | 0x03, /**< Unhandled Except. */

        // Reserving this SRC (BC801B99) for use by attention handling
        //  code to log a TI in the case where Hostboot was not able
        //  to fill in the TI area or they were unable to read memory
        RC_EARLY_BOOT_FAIL   = KERNEL_COMP_ID | 0x99, /**< Failure before HB is ready */
    };
}

#endif
