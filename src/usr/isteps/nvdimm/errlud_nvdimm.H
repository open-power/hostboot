/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/errlud_nvdimm.H $                       */
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
/**
 *  @file errlud_nvdimm.H
 *
 *  @brief Defines the class that logs and parses NVDIMM data
 */
#ifndef ERRL_UD_NVDIMM_H
#define ERRL_UD_NVDIMM_H

#include <errl/errluserdetails.H>
#include "nvdimmdd.H"

namespace NVDIMM
{
/**
 * @class UdNvdimmParms
 *
 * Adds NVDIMM information to an error log as user detail data
 */
class UdNvdimmParms : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_opType       Operation Type
     *  @param i_target       Chip being detected/acted upon
     *  @param i_buflen       Length of In/Out Buffer
     *  @param i_i2cInfo      Miscellaneous Parameters
     */
    UdNvdimmParms( uint8_t i_opType,
                   TARGETING::Target * i_target,
                   uint64_t i_buflen,
                   nvdimm_addr_t &i_i2cInfo );

    /**
     *  @brief Destructor
     */
    virtual ~UdNvdimmParms();

  private:
    // Disabled
    UdNvdimmParms(UdNvdimmParms &);
    UdNvdimmParms & operator=(UdNvdimmParms &);
};

} // end NVDIMM namespace

#endif
