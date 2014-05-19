/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludstring.H $                         */
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
#ifndef ERRL_UDSTRING_H
#define ERRL_UDSTRING_H

/**
 *  @file errludstring.H
 *
 *  Defines the ErrlUserDetailsString class that adds string FFDC to an
 *  error log as user detail data
 */

#include <errl/errluserdetails.H>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsString
 *
 * Adds String FFDC to an error log as user detail data
 */
class ErrlUserDetailsString : public ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *  
     *  Captures the supplied string internally
     *  
     *  @param i_pString Pointer to string to capture as user detail data
     */
    ErrlUserDetailsString(const char * i_pString);

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsString();

private:
    // Disabled
    ErrlUserDetailsString(const ErrlUserDetailsString &);
    ErrlUserDetailsString & operator=(const ErrlUserDetailsString &);
};

}

#endif

