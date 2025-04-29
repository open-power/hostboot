/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbe/errlud_sbe.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2025                             */
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
#ifndef ERRL_UD_SBE_H
#define ERRL_UD_SBE_H

/**
 *  @file errlud_sbe.H
 *
 *  Defines the classes that logs and parses SBE UD data
 */

#include <errl/errluserdetails.H>

namespace SBE {
/**
 * @class UdSBEParms
 *
 * Adds SBE information to an error log as user detail data
 */
class UdXIPSectionSizeParms : public ERRORLOG::ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *
     *  @param i_image Target of XIP sections
     */
    UdXIPSectionSizeParms(const void * i_image);

    /**
     *  @brief Destructor
     */
    virtual ~UdXIPSectionSizeParms();

private:
    // Disabled
    UdXIPSectionSizeParms(UdXIPSectionSizeParms &) = delete;
    UdXIPSectionSizeParms & operator=(UdXIPSectionSizeParms &) = delete;
};

} // end SBE namespace

#endif
