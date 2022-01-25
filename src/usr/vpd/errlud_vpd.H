/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/errlud_vpd.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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
#ifndef ERRL_UD_VPD_H
#define ERRL_UD_VPD_H

/**
 *  @file errlud_vpd.H
 *
 *  Defines the classes that logs and parses various VPD structures
 */

#include <errl/errluserdetails.H>
#include "ipvpd.H"

namespace VPD
{

/**
 * @class UdVpdParms
 *
 * Adds VPD parameters information to an error log as user detail data
 */
class UdVpdParms : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_target        Target being detected/acted upon
     *  @param i_buflen        Length of In/Out buffer
     *  @param i_record        Record
     *  @param i_keyword       Keyword
     *  @param read_notWrite   Read/not-Write (read=true; write=false)
     */
    UdVpdParms( TARGETING::Target * i_target,
           uint64_t i_buflen,
           uint64_t i_record,
           uint64_t i_keyword,
           bool read_notWrite  );

    /**
     *  @brief Destructor
     */
    virtual ~UdVpdParms();

  private:
    // Disabled
    UdVpdParms(UdVpdParms &);
    UdVpdParms & operator=(UdVpdParms &);
};


}

#endif
