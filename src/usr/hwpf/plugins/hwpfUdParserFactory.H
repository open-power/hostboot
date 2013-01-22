/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plugins/hwpfUdParserFactory.H $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

