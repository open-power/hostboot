/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfEnums.H $                        */
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

#ifndef __prdfEnums_H
#define __prdfEnums_H

/** @file prdfEnums.H */

#ifdef  __HOSTBOOT_MODULE

    #ifndef __PRD_RULE_COMPILE
    #include <hwas/common/hwasCallout.H>

    // FIXME: mapping from HWSV enums to HB ones
    // eventually these HWAS will make it way to fips
    #define HOM_NO_DECONFIG     HWAS::NO_DECONFIG
    #define HOM_DECONFIG        HWAS::DECONFIG
    #define HOM_DEFER_DECONFIG  HWAS::DELAYED_DECONFIG

    // FIXME: remove these mapping once the enums are made common
    #define EPUB_PRC_ALL_PROCS      HWAS::EPUB_PRC_ALL_PROCS
    #define EPUB_PRC_SP_CODE        HWAS::EPUB_PRC_SP_CODE
    #define EPUB_PRC_PHYP_CODE      HWAS::EPUB_PRC_PHYP_CODE
    #define EPUB_PRC_LVL_SUPP       HWAS::EPUB_PRC_LVL_SUPP
    #define EPUB_PRC_MEMBUS_ERROR   HWAS::EPUB_PRC_MEMBUS_ERROR
    #define EPUB_PRC_PROC_XYZ_BUS   HWAS::EPUB_PRC_PROC_XYZ_BUS
    #define EPUB_PRC_PROC_AB_BUS    HWAS::EPUB_PRC_PROC_AB_BUS

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

        SRCI_PRIORITY_LOW   = 1,
        SRCI_PRIORITY_MEDC  = 2,
        SRCI_PRIORITY_MEDB  = 3,
        SRCI_PRIORITY_MEDA  = 4,
        SRCI_PRIORITY_MED   = 5,
        SRCI_PRIORITY_HIGH  = 6,
        #endif

        // homTermEnum
        HOM_SYS_NO_TERMINATE = 0,

        // homHCDBUpdate
        HOM_HCDB_DO_UPDATE = 0,
        HOM_HCDB_OVERRIDE,

        // homGardEnum
        HOM_NO_GARD = 0,
        HOM_DECONFIG_GARD,

        //homDeconfigSchedule
        HOM_DECONFIG_IMMEDIATE = 0,
        HOM_DECONFIG_DEFER,

        // ERRL Action Flag
        ERRL_ACTION_SA = 0,
        ERRL_ACTION_REPORT,
        ERRL_ACTION_CALL_HOME,
        ERRL_ACTION_HIDDEN,
        ERRL_ACTION_DONT_TERMINATE

    };

#else // if not __HOSTBOOT_MODULE

    #include <epub_service_codes.H> // for EPUB_PRC_*
    #include <srci.H>               // for SRCI_PRIORITY_*

#endif // __HOSTBOOT_MODULE

#endif /* __prdfEnums_H */

