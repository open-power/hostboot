/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfEnums.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

    #ifndef __PRD_RULE_COMPILE

    #include <errl/errlmanager.H> // Must be included before including
                                  // hwasCallout.H, otherwise the compile will
                                  // fail.
    #include <hwas/common/hwasCallout.H>

    // FIXME: remove these mapping once the enums are made common
    #define EPUB_PRC_ALL_PROCS      HWAS::EPUB_PRC_ALL_PROCS
    #define EPUB_PRC_SP_CODE        HWAS::EPUB_PRC_SP_CODE
    #define EPUB_PRC_PHYP_CODE      HWAS::EPUB_PRC_PHYP_CODE
    #define EPUB_PRC_LVL_SUPP       HWAS::EPUB_PRC_LVL_SUPP
    #define EPUB_PRC_MEMBUS_ERROR   HWAS::EPUB_PRC_MEMBUS_ERROR
    #define EPUB_PRC_PROC_XYZ_BUS   HWAS::EPUB_PRC_PROC_XYZ_BUS
    #define EPUB_PRC_PROC_AB_BUS    HWAS::EPUB_PRC_PROC_AB_BUS
    #define EPUB_PRC_MEMORY_UE      0x4F

    // FIXME: remove these mapping once the enums are made common
    #define SRCI_PRIORITY_HIGH  HWAS::SRCI_PRIORITY_HIGH
    #define SRCI_PRIORITY_MED   HWAS::SRCI_PRIORITY_MED
    #define SRCI_PRIORITY_MEDA  HWAS::SRCI_PRIORITY_MEDA
    #define SRCI_PRIORITY_MEDB  HWAS::SRCI_PRIORITY_MEDB
    #define SRCI_PRIORITY_MEDC  HWAS::SRCI_PRIORITY_MEDC
    #define SRCI_PRIORITY_LOW   HWAS::SRCI_PRIORITY_LOW

    #endif

    // FIXME: Currently hostboot errl does not support these enums. Stubbing
    //        them out for now.

    enum
    {
        #ifdef __PRD_RULE_COMPILE
        //FIXME: these enum values have to match with
        //what are defined in include/usr/hwas/common/hwasCallout.H
        EPUB_PRC_SP_CODE      = 0x04,
        EPUB_PRC_PHYP_CODE    = 0x05,
        EPUB_PRC_ALL_PROCS    = 0x08,
        EPUB_PRC_LVL_SUPP     = 0x10,
        EPUB_PRC_PROC_AB_BUS  = 0x30,
        EPUB_PRC_PROC_XYZ_BUS = 0x31,
        EPUB_PRC_MEMBUS_ERROR = 0x34,
        EPUB_PRC_MEMORY_UE    = 0x4F,

        SRCI_PRIORITY_LOW   = 1,
        SRCI_PRIORITY_MEDC  = 2,
        SRCI_PRIORITY_MEDB  = 3,
        SRCI_PRIORITY_MEDA  = 4,
        SRCI_PRIORITY_MED   = 5,
        SRCI_PRIORITY_HIGH  = 6,
        #endif

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

#else // if not __HOSTBOOT_MODULE

    #include <epub_service_codes.H> // for EPUB_PRC_*
    #include <srci.H>               // for SRCI_PRIORITY_*

#endif // __HOSTBOOT_MODULE

#endif /* __prdfEnums_H */

