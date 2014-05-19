/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plugins/hwpfUdParserFactory.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef HWPFUDPARSERFACTORY_H
#define HWPFUDPARSERFACTORY_H

/**
 *  @file fapiPlatHwpUdDecode.H
 *
 *  Defines the PlatUserDetailsParserFactory class
 */
#include "errludparserfactory.H"
#include "fapiPlatUdParserHwp.H"
#include "hwpistepud.H"

namespace fapi
{

/**
 * @class Hwpf UserDetailsParserFactory
 *
 * This factory produces ErrlUserDetailsParser objects to parse the specified
 * HWPF user detail data.
 */
class HwpfUserDetailsParserFactory : public ERRORLOG::ErrlUserDetailsParserFactory
{
public:

    /**
     *  @brief Constructor
     */
    HwpfUserDetailsParserFactory()
    {
        registerParser<PlatUserDetailsParserHwpRcValue>(HWPF_UDT_HWP_RCVALUE);
        registerParser<PlatUserDetailsParserHwpFfdc>(HWPF_UDT_HWP_FFDC);
        registerParser<ISTEP_ERROR::HwpUserDetailsParserIstep>
            (HWPF_UDT_STEP_ERROR_DETAILS);
    }

private:
    // Disabled
    HwpfUserDetailsParserFactory(const HwpfUserDetailsParserFactory &);
    HwpfUserDetailsParserFactory & operator=(
        const HwpfUserDetailsParserFactory &);
};

}

#endif

