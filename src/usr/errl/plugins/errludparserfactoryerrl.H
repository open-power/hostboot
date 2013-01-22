/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errludparserfactoryerrl.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
#include "errludattribute.H"
#include "errludlogregister.H"
#include "errludcallout.H"

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
        registerParser<ErrlUserDetailsParserTarget>(ERRL_UDT_TARGET);
        registerParser<ErrlUserDetailsParserBackTrace>(ERRL_UDT_BACKTRACE);
        registerParser<ErrlUserDetailsParserAttribute>(ERRL_UDT_ATTRIBUTE);
        registerParser<ErrlUserDetailsParserLogRegister>(ERRL_UDT_LOGREGISTER);
        registerParser<ErrlUserDetailsParserCallout>(ERRL_UDT_CALLOUT);
    }

private:

    // Disabled
    ErrlUserDetailsParserFactoryErrl(const ErrlUserDetailsParserFactoryErrl &);
    ErrlUserDetailsParserFactoryErrl & operator=(
        const ErrlUserDetailsParserFactoryErrl &);
};

}

#endif

