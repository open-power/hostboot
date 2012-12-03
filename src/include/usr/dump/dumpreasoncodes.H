/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/dump/dumpreasoncodes.H $                      */
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
#ifndef __DUMP_REASONCODES_H
#define __DUMP_REASONCODES_H

#include <hbotcompid.H>

namespace DUMP
{
    enum dumpModuleId
    {
        DUMP_COLLECT_INVALID         = 0x00,
        DUMP_COLLECT                 = 0x01,
    };

    enum dumpReasonCode
    {
        DUMP_INVALID_ADDR              = DUMP_COMP_ID | 0x01,
        DUMP_NO_HDAT_ADDR              = DUMP_COMP_ID | 0x02,
        DUMP_CANNOT_MAP                = DUMP_COMP_ID | 0x03,
        DUMP_CANNOT_UNMAP_SRC          = DUMP_COMP_ID | 0x04,
        DUMP_CANNOT_UNMAP_DEST         = DUMP_COMP_ID | 0x05,
        DUMP_CANNOT_UNMAP_RESULTS      = DUMP_COMP_ID | 0x06,
        DUMP_MDRT_INSUFFICIENT_SPACE   = DUMP_COMP_ID | 0x07,
        DUMP_MDST_INSUFFICIENT_SPACE   = DUMP_COMP_ID | 0x08,
        DUMP_MDDT_INSUFFICIENT_SPACE   = DUMP_COMP_ID | 0x09,
        DUMP_MDDT_INSUFFICIENT_ENTRIES = DUMP_COMP_ID | 0x0A,
        DUMP_MDST_INVALID_TABLE_SIZE   = DUMP_COMP_ID | 0x0B,
        DUMP_MDDT_INVALID_TABLE_SIZE   = DUMP_COMP_ID | 0x0C,
    };
};

#endif
