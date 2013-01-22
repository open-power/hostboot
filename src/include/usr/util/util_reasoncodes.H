/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/util_reasoncodes.H $                     */
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

#ifndef __UTIL_REASONCODES_H
#define __UTIL_REASONCODES_H

#include <hbotcompid.H>

namespace Util
{
    enum ModuleId
    {
        UTIL_MOD_MEM_READ       = 0x01,       // UtilMem::Read
        UTIL_MOD_MEM_WRITE      = 0x02,       // UtilMem::Write
    };

    enum ReasonCode
    {
        UTIL_ERC_NONE           = UTIL_COMP_ID | 0x01,
        UTIL_ERC_BAD_PTR        = UTIL_COMP_ID | 0x02,
        UTIL_ERC_EOF            = UTIL_COMP_ID | 0x03,
    };
};

#endif
