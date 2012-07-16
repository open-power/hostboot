/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/scan/scan_reasoncodes.H $                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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
#ifndef __SCAN_REASONCODES_H
#define __SCAN_REASONCODES_H

#include <hbotcompid.H>

namespace SCAN
{
    enum SCANModuleId
    {
        MOD_SCANDD_INVALID   = 0x00, /**< Zero is an invalid module id */
        MOD_SCANDD_DDOP      = 0x01, /**< scandd.C : ddOp */
        MOD_SCANDD_DOSCAN    = 0x02, /**< scandd.C : ScanDD::scanDoScan */

    };

    enum SCANReasonCode
    {
        RC_INVALID_LENGTH            = SCAN_COMP_ID | 0x01,
        RC_INVALID_RING_ADDRESS      = SCAN_COMP_ID | 0x02,
        RC_INVALID_OPERATION         = SCAN_COMP_ID | 0x03,
        RC_INVALID_BUF_SIZE          = SCAN_COMP_ID | 0x04,
        RC_SCAN_LAST_BITS_FAIL       = SCAN_COMP_ID | 0x05,
        RC_SCAN_TYPE_SELECT_ERROR    = SCAN_COMP_ID | 0x06,
        RC_HEADER_WRITE_ERROR        = SCAN_COMP_ID | 0x07,
        RC_HEADER_READ_ERROR         = SCAN_COMP_ID | 0x08,
        RC_SCAN_READ_FAIL            = SCAN_COMP_ID | 0x09,
        RC_SCAN_READ_EXTRA_FAIL      = SCAN_COMP_ID | 0x0a,
        RC_SCAN_WRITE_FAIL           = SCAN_COMP_ID | 0x0b,
        RC_HEADER_DATA_MISMATCH      = SCAN_COMP_ID | 0x0c,
        RC_INVALID_DATA              = SCAN_COMP_ID | 0x0d,
    };
};

#endif
