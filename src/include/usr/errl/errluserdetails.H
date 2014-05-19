/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errluserdetails.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef ERRL_ERRLUSERDETAILS_H
#define ERRL_ERRLUSERDETAILS_H

/**
 *  @file errluserdetails.H
 *
 *  Defines the ErrlUserDetails base classes
 *
 *  Derive a class from ErrlUserDetails to create user detail data. For each
 *  class, in the component's plugins directory, derive a class from
 *  ErrlUserDetailsParser to parse user detail data
 */
#include <stdint.h>
#include <errl/errlentry.H>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetails
 *
 * This class creates user detail data. If a component creates user detail data
 * then for each different type of data it should derive a class from this.
 */
class ErrlUserDetails
{
public:

    /**
     *  @brief Constructor
     *
     *  Sets up instance variables. A derived class should set up the instance
     *  variables to reflect a specific format of user detail data
     */
    ErrlUserDetails();

    /**
     *  @brief Destructor
     *
     *  Performs any necessary cleanup
     */
    virtual ~ErrlUserDetails();

    /**
     *  @brief Adds user detail data to an error log
     *
     *  Adds the user detail data stored in the internal buffer to the error
     *  log. Subclasses should override if the detail data is not stored in the
     *  internal buffer.
     *
     *  @param  i_errl Error log handle to add detail data to.
     */
    virtual void addToLog(errlHndl_t i_errl);

protected:

    /**
     *  @brief Allocates the internal data buffer for storing detail data
     *
     *  If the internal buffer is already allocated then it is reallocated and
     *  the contents preserved (up to the lesser of the new and old sizes).
     *
     *  @param i_size Size of buffer
     *
     *  @return uint8_t* Pointer to the data buffer
     */
    uint8_t * reallocUsrBuf(const uint32_t i_size);

    /**
     *  @brief Returns the size of the internal data buffer
     *
     *  @return uint32_t Size of the internal data buffer
     */
    uint32_t getUsrBufSize() const;

    /**
     *  Protected Data: ID of component adding user details
     */
    compId_t iv_CompId;

    /**
     *  Protected Data: Version number of the user details
     */
    errlver_t iv_Version;

    /**
     *  Protected Data: Subsection number of the user details
     */
    errlsubsec_t iv_SubSection;

    /**
     *  Protected Data: true/false merge like buffers
     */
    bool      iv_merge;

private:

    // Disabled
    ErrlUserDetails(const ErrlUserDetails &);
    ErrlUserDetails & operator=(const ErrlUserDetails &);

    /**
     *  Private Data members (the internal buffer should be accessed through
     *  public member functions)
     */
    uint8_t * iv_pBuffer;       // Pointer to internal buffer
    uint32_t  iv_BufLen;        // Length of internal buffer
};

}

#endif

