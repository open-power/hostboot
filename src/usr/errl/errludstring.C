/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludstring.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

}

