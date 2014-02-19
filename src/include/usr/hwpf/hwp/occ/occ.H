/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/occ/occ.H $                          */
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
#ifndef OCC_H_
#define OCC_H_

#include <limits.h>
#include <errl/errlentry.H>

namespace HBOCC {

    struct occHostConfigDataArea_t
    {
        uint32_t version;
        uint32_t nestFrequency;
    };

    enum
    {
        OccHostDataVersion = 1,
        OCC_LIDID = 0x81e00430,
        OCC_IBSCOM_RANGE_IN_MB = MEGABYTE,
    };

    enum occAction_t
    {
        OCC_START,
        OCC_STOP,
    };

    /**
     * @brief Starts OCCs on all Processors in the node
     *        This is intended to be used for AVP testing.
     *
     * @return errlHndl_t  Error log if OCC load failed
     */
    errlHndl_t loadnStartAllOccs();

} //end OCC namespace

#endif
