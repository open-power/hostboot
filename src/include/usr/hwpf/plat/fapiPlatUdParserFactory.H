//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/plat/fapiPlatUdParserFactory.H $
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
#ifndef FAPIPLATUDPARSERFACTORY_H
#define FAPIPLATUDPARSERFACTORY_H

#ifdef PARSER

/**
 *  @file fapiPlatHwpUdDecode.H
 *
 *  Defines the PlatUserDetailsParserFactory class
 */
#include <hwpf/plat/fapiPlatUdParserHwp.H>
#include <hwpf/plat/fapiPlatReasonCodes.H>
#include <errl/errludparserfactory.H>

namespace fapi
{

/**
 * @class PlatUserDetailsParserFactory
 *
 * This factory produces ErrlUserDetailsParser objects to parse the specified
 * PLAT user detail data.
*/
class PlatUserDetailsParserFactory : public ERRORLOG::ErrlUserDetailsParserFactory
{
public:

    /**
     *  @brief Constructor
     */
    PlatUserDetailsParserFactory()
    {
        registerParser<PlatUserDetailsParserHwpRcValue>(HWPF_UDT_HWP_RCVALUE);
        registerParser<PlatUserDetailsParserHwpTarget>(HWPF_UDT_HWP_TARGET);
        registerParser<PlatUserDetailsParserHwpEcmddbb>(HWPF_UDT_HWP_ECMDDBB);
        registerParser<PlatUserDetailsParserHwpData>(HWPF_UDT_HWP_DATA);
    }

private:
    // Disabled
    PlatUserDetailsParserFactory(const PlatUserDetailsParserFactory &);
    PlatUserDetailsParserFactory & operator=(
        const PlatUserDetailsParserFactory &);
};

}

#endif
#endif

