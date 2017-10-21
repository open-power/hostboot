/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludstring.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
/**
 *  @file errludstring.C
 *
 *  @brief Implementation of ErrlUserDetailsString
 */
#include <errl/errludstring.H>
#include <errl/errlreasoncodes.H>
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
    iv_CompId = ERRL_COMP_ID;
    iv_Version = 1;
    iv_SubSection = ERRL_UDT_STRING;

    // override the default of false.
    iv_merge = true;
}

//------------------------------------------------------------------------------
ErrlUserDetailsString::~ErrlUserDetailsString()
{

}

// ErrlUserDetailsStringSet implementation

ErrlUserDetailsStringSet::ErrlUserDetailsStringSet()
{
    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = ERRL_UDT_STRING_SET_VER_1;
    iv_SubSection = ERRL_UDT_STRING_SET;

    // override the default of false.
    iv_merge = true;
}

void ErrlUserDetailsStringSet::add(
    const char* const i_pDescriptionString,
    const char* const i_pString)
{
    // [Object Memory Layout]
    //
    // Offset  Size  Description
    // =========================================================================
    // 0       X     Existing object contents before this call, where X=0 if
    //               this is the first add call to the object
    // X       Y     NULL terminated description string describing the string
    //               being logged, where Y=strlen(this string) + length (1) of
    //               NULL terminator.
    // X+Y     Z     NULL terminated FFDC string, where Z=strlen(this string) +
    //               length (1) of NULL terminator.

    // Absorb API errors on error path and instead substitue error string for
    // any input that is nullptr
    const char* const pDescriptionString = (i_pDescriptionString == nullptr) ?
        "BUG! Invalid description" : i_pDescriptionString;
    const char* const pString = (i_pString == nullptr) ? "BUG! Invalid string" :
        i_pString;

    const auto currentSize = static_cast<size_t>(getUsrBufSize());
    const auto descriptionSize = strlen(pDescriptionString)+1;
    const auto stringSize = strlen(pString)+1;
    const auto newSize = currentSize + descriptionSize + stringSize;
    char* const pBuf = reinterpret_cast<char*>(
        reallocUsrBuf(newSize));
    strcpy(pBuf+currentSize, pDescriptionString);
    strcpy(pBuf+currentSize+descriptionSize,pString);
}

ErrlUserDetailsStringSet::~ErrlUserDetailsStringSet()
{

}

} // End of ERRORLOG namespace


