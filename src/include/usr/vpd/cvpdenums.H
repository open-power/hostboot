/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/cvpdenums.H $                             */
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
#ifndef __CVPDENUMS_H
#define __CVPDENUMS_H

namespace CVPD
{

    /**
     * @brief Enumeration for the CVPD Records that contain
     *       the keyword enumerations below.
     */
    enum cvpdRecord
    {
        CVPD_FIRST_RECORD   = 0x00,
        VEIR        = CVPD_FIRST_RECORD,
        VER0        = 0x01,
        MER0        = 0x02,
        VSPD        = 0x03,
        VINI        = 0x04,
        // Last Record
        CVPD_LAST_RECORD,
        CVPD_TEST_RECORD,   // Test purposes ONLY!
        CVPD_INVALID_RECORD = 0xFFFF,
    };

    /**
     * @brief Enumerations for CVPD keywords that can be
     *       accessed in the CVPD.
     */
    enum cvpdKeyword
    {
        CVPD_FIRST_KEYWORD      = 0x00,
        pdI          = CVPD_FIRST_KEYWORD,
        PF           = 0x01,
        MT           = 0x02,
        MR           = 0x03,
        pdA          = 0x04,
        EL           = 0x05,
        LM           = 0x06,
        MW           = 0x07,
        MV           = 0x08,
        AM           = 0x09,
        VZ           = 0x0a,
        // Last Keyword
        CVPD_LAST_KEYWORD,
        CVPD_TEST_KEYWORD,  // Test purposes ONLY!
        CVPD_INVALID_KEYWORD    = 0xFFFF,
    };

};  // end CVPD

#endif
