/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfEnums.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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

#ifndef __prdfEnums_H
#define __prdfEnums_H

/** @file prdfEnums.H */

// Don't want to include hwasCommon.H because it includes much more than we
// need, which forces us to resolve a bunch of include paths that are not
// necessary.
#include <hwas/common/hwasCallout.H>

namespace PRDF
{

/**
 * @brief  MFG threshold sync message types
 * */
enum MFG_THRES_SYNC_MSG_TYPE
{
    MFG_THRES_SYNC_FROM_FSP  = 0x1,
    MFG_TRACE_SYNC_TO_FSP    = 0x2
};

}; // end namespace PRDF

#ifdef  __HOSTBOOT_MODULE

    // FIXME: Currently hostboot errl does not support these enums. Stubbing
    //        them out for now.

    enum
    {
        // ERRL Action Flag
        ERRL_ACTION_SA = 0,
        ERRL_ACTION_REPORT,
        ERRL_ACTION_CALL_HOME,
        ERRL_ACTION_HIDDEN,
        ERRL_ACTION_DONT_TERMINATE
    };

    namespace HWSV
    {
        typedef uint32_t hwsvDiagUpdate;
        typedef uint32_t hwsvTermEnum;
        typedef uint32_t hwsvDeconfigSchedule;

        enum
        {
            // hwsvTermEnum
            HWSV_SYS_NO_TERMINATE = 0,

            // hwsvDiagUpdate
            HWSV_DIAG_NOT_NEEDED = 0,
            HWSV_DIAG_NEEDED,

            //hwsvDeconfigSchedule
            HWSV_DECONFIG_IMMEDIATE = 0,
            HWSV_DECONFIG_DEFER
        };
    };

#endif // __HOSTBOOT_MODULE

#endif /* __prdfEnums_H */

