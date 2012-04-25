//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errludparserfactoryerrl.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef ERRL_UDPARSERFACTORYERRL_H
#define ERRL_UDPARSERFACTORYERRL_H

#ifdef PARSER

/**
 *  @file errludparserfactoryerrl.H
 *
 *  Defines the errlUserDetailsParserFactoryErrl.H class
*/
#include <errl/errludstring.H>
#include <errl/errludtarget.H>
#include <errl/errludbacktrace.H>
#include <errludattribute.H>
#include <errl/errludparserfactory.H>

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
        registerParser<ErrlUserDetailsParserString>(HBERRL_UDT_STRING);
        registerParser<ErrlUserDetailsParserTarget>(HBERRL_UDT_TARGET);
        registerParser<ErrlUserDetailsParserBackTrace>(HBERRL_UDT_BACKTRACE);
        registerParser<ErrlUserDetailsParserAttribute>(HBERRL_UDT_ATTRIBUTE);
    }

private:

    // Disabled
    ErrlUserDetailsParserFactoryErrl(const ErrlUserDetailsParserFactoryErrl &);
    ErrlUserDetailsParserFactoryErrl & operator=(
        const ErrlUserDetailsParserFactoryErrl &);
};

}

#endif
#endif

