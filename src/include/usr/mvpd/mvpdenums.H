/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mvpd/mvpdenums.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
/**
 * @file MVpdenums.H
 *
 * @brief Enums for the MVPD fields to be requested.
 *
 */
#ifndef __MVPDENUMS_H
#define __MVPDENUMS_H

namespace MVPD
{

/**
* @brief Enumeration for the MVPD Records that contain
*       the keyword enumerations below.
*/
enum mvpdRecord
{
    MVPD_FIRST_RECORD   = 0x00,
    CRP0        = MVPD_FIRST_RECORD,
    CP00        = 0x01,
    VINI        = 0x02,
    LRP0        = 0x03,
    LRP1        = 0x04,
    LRP2        = 0x05,
    LRP3        = 0x06,
    LRP4        = 0x07,
    LRP5        = 0x08,
    LRP6        = 0x09,
    LRP7        = 0x0a,
    LRP8        = 0x0b,
    LRP9        = 0x0c,
    LRPA        = 0x0d,
    LRPB        = 0x0e,
    LWP0        = 0x0f,
    LWP1        = 0x10,
    LWP2        = 0x11,
    LWP3        = 0x12,
    LWP4        = 0x13,
    LWP5        = 0x14,
    LWP6        = 0x15,
    LWP7        = 0x16,
    LWP8        = 0x17,
    LWP9        = 0x18,
    LWPA        = 0x19,
    LWPB        = 0x1a,
    VWML        = 0x1b,

    // Last Record
    MVPD_LAST_RECORD,
    MVPD_TEST_RECORD,   // Test purposes ONLY!
    MVPD_INVALID_RECORD = 0xFFFF,
};

/**
* @brief Enumerations for MVPD keywords that can be
*       accessed in the MVPD.
*/
enum mvpdKeyword
{
    MVPD_FIRST_KEYWORD      = 0x00,
    VD          = MVPD_FIRST_KEYWORD,
    ED          = 0x01,
    TE          = 0x02,
    DD          = 0x03,
    pdP         = 0x04,
    ST          = 0x05,
    DN          = 0x06,
    PG          = 0x07,
    PK          = 0x08,
    pdR         = 0x09,
    pdV         = 0x0a,
    pdH         = 0x0b,
    SB          = 0x0c,
    DR          = 0x0d,
    VZ          = 0x0e,
    CC          = 0x0f,
    CE          = 0x10,
    FN          = 0x11,
    PN          = 0x12,
    SN          = 0x13,
    PR          = 0x14,
    HE          = 0x15,
    CT          = 0x16,
    HW          = 0x17,
    pdM         = 0x18,
    IN          = 0x19,
    pd2         = 0x1a,
    pd3         = 0x1b,
    OC          = 0x1c,
    FO          = 0x1d,
    pdI         = 0x1e,
    pdG         = 0x1f,

    // Last Keyword
    MVPD_LAST_KEYWORD,
    MVPD_TEST_KEYWORD,  // Test purposes ONLY!
    INVALID_MVPD_KEYWORD    = 0xFFFF,
};

};  // end MVPD

#endif
