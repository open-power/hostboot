//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/sys/interrupt.h $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __INTERRUPT_H
#define __INTERRUPT_H


extern const char* INTR_MSGQ;

/**
 * INTR constants
 */
enum
{
    ICPBAR_SCOM_ADDR = 0x020109c9,      //!< for P8, P7 = 0x02011C09
    // This BAR value agrees with simics (for now)
    ICPBAR_VAL = 0x03FBFF90,            //!< ICPBAR value bits[0:29]>>34
};

#endif
