/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludstring.H $                         */
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

    // Disable compiler provided default functions
    ErrlUserDetailsString(
        const ErrlUserDetailsString &);
    ErrlUserDetailsString & operator=(
        const ErrlUserDetailsString &);
    ErrlUserDetailsString (
        ErrlUserDetailsString&&) = delete;
    ErrlUserDetailsString& operator = (
        ErrlUserDetailsString&&) = delete;
};

/**
 * @class ErrlUserDetailsStringSet
 *
 * @brief Adds multiple, tagged FFDC strings to an error log as user details
 *     data
 */
class ErrlUserDetailsStringSet : public ErrlUserDetails
{

  public:

    /**
     *  @brief Constructor; creates the object
     */
    ErrlUserDetailsStringSet();

    /**
     *  @brief Adds a new tagged string to the object's string cache
     *
     *  @param[in] i_pDescriptionString Description of the string to add.  Must
     *      not be nullptr or function will substitute an error message.
     *  @param[in] i_pString The string to add.  Must not be nullptr or function
     *      will substitute an error message.
     */
    void add(const char* i_pDescriptionString,
             const char* i_pString);

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsStringSet();

    // Disable compiler provided default functions
    ErrlUserDetailsStringSet(
        const ErrlUserDetailsStringSet&) = delete;
    ErrlUserDetailsStringSet& operator=(
        const ErrlUserDetailsStringSet&) = delete;
    ErrlUserDetailsStringSet (
        ErrlUserDetailsStringSet&&) = delete;
    ErrlUserDetailsStringSet& operator = (
        ErrlUserDetailsStringSet&&) = delete;
};

}

#endif

