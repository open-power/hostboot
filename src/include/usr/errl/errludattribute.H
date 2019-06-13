/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludattribute.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef ERRL_UDATTRIBUTE_H
#define ERRL_UDATTRIBUTE_H

/**
 *  Defines the classes that allow you to save attribute data to
 *   an error log.
 */

#if !defined(PARSER) && !defined(LOGPARSER)

#include <errl/errluserdetails.H>

namespace TARGETING // Forward reference
{ class Target; }

namespace ERRORLOG
{
class ErrlUserDetailsAttribute : public ErrlUserDetails {
  public:

    /**
     *  @brief Constructor to add a single attribute
     *
     *  @param i_target  Target from whom the attribute is being read
     *  @param i_attr    Attribute id/hash
     */
    ErrlUserDetailsAttribute(const TARGETING::Target * i_pTarget,
                             uint32_t i_attr);

    /**
     *  @brief Constructor to add no attributes (need to call addData)
     *
     *  @param i_target  Target from whom the attribute is being read
     */
    ErrlUserDetailsAttribute(const TARGETING::Target * i_pTarget);

    /**
     *  @brief Add an additional attribute to the log
     *
     *  @param i_attr    Attribute id/hash
     */
    void addData(uint32_t i_attr);


    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsAttribute();

  private:

    // Disabled
    ErrlUserDetailsAttribute(const ErrlUserDetailsAttribute &);
    ErrlUserDetailsAttribute & operator=(const ErrlUserDetailsAttribute &);

    // internal function
    void dumpAll();

    const TARGETING::Target * iv_pTarget;
    uint32_t iv_dataSize;
};
}
#else // if LOGPARSER defined

#include "errluserdetails.H"

// Pull in the auto-generated portion for the parser
#include <errl/errludattribute_gen.H>

#endif

#endif //ERRL_UDATTRIBUTE_H
