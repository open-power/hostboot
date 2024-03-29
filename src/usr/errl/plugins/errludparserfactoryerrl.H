/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errludparserfactoryerrl.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
#ifndef ERRL_UDPARSERFACTORYERRL_H
#define ERRL_UDPARSERFACTORYERRL_H

/**
 *  @file errludparserfactoryerrl.H
 *
 *  Defines the errlUserDetailsParserFactoryErrl.H class
*/
#include "errludparserfactory.H"
#include "errludstring.H"
#include "errludtarget.H"
#include "errludbacktrace.H"
#include "errludattributeP.H"
#include "errludlogregister.H"
#include "errludcallout.H"
#include "errludbuild.H"
#include "errludstate.H"
#include "errludwofdata.H"

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsParserFactoryErrl
 *
 * This factory produces ErrlUserDetailsParser objects to parse the specified
 * ERRL user detail data.
 */
class ErrlUserDetailsParserFactoryErrl : public ErrlUserDetailsParserFactory
{
public:

    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserFactoryErrl()
    {
        registerParser<ErrlUserDetailsParserString>(ERRL_UDT_STRING);
        registerParser<ErrlUserDetailsParserStringSet>(ERRL_UDT_STRING_SET);
        registerParser<ErrlUserDetailsParserTarget>(ERRL_UDT_TARGET);
        registerParser<ErrlUserDetailsParserBackTrace>(ERRL_UDT_BACKTRACE);
        registerParser<ErrlUserDetailsParserAttribute>(ERRL_UDT_ATTRIBUTE);
        registerParser<ErrlUserDetailsParserLogRegister>(ERRL_UDT_LOGREGISTER);
        registerParser<ErrlUserDetailsParserCallout>(ERRL_UDT_CALLOUT);
        registerParser<ErrlUserDetailsParserBuild>(ERRL_UDT_BUILD);
        registerParser<ErrlUserDetailsParserSysState>(ERRL_UDT_SYSSTATE);
        registerParser<ErrlUserDetailsParserWofData>(ERRL_UDT_WOFDATA);
   }

private:

    // Parser isn't compiled with c++11 in all environments, and therefore
    // "delete" of unused interfaces (like below) is not supported, nor are
    // functions with move semantics

    // Disable compiler provided default functions
    ErrlUserDetailsParserFactoryErrl(
        const ErrlUserDetailsParserFactoryErrl &);
    ErrlUserDetailsParserFactoryErrl & operator=(
        const ErrlUserDetailsParserFactoryErrl &);

};

}

#endif

