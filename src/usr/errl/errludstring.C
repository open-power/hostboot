//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/errludstring.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
/**
 *  @file errludstring.C
 *
 *  @brief Implementation of ErrlUserDetailsString
 */
#include <errl/errludstring.H>
#include <string.h>

namespace ERRORLOG
{

//------------------------------------------------------------------------------
ErrlUserDetailsString::ErrlUserDetailsString(const char * i_pString)
{
    char * l_pBuf = reinterpret_cast<char *>(
        reallocUsrBuf(strlen(i_pString) + 1));
    strcpy(l_pBuf, i_pString);
    
    // Set up ErrlUserDetails instance variables
    iv_CompId = HBERRL_COMP_ID;
    iv_Version = 1;
    iv_SubSection = HBERRL_UDT_STRING;
}

//------------------------------------------------------------------------------
ErrlUserDetailsString::~ErrlUserDetailsString()
{

}

}

