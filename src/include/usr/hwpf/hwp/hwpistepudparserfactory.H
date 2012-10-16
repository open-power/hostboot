/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/hwpistepudparserfactory.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
#ifndef __ISTEP_UDPARSERFACTORY_H
#define __ISTEP_UDPARSERFACTORY_H

#ifdef PARSER

/**
 *  @file initsvcudparserfactory.H
 *
 *  Defines the IStepUserDetailsParserFactory.H class
*/
#include <hwpf/istepvcreasoncodes.H>
#include <errl/errludparserfactory.H>

namespace INITSERVICE
{

/**
 * @class IStepUserDetailsParserFactory
 *
 * This factory produces ErrlUserDetailsParser objects to parse the specified
 * InitService user detail data.
*/
class IStepUserDetailsParserFactory : public ERRORLOG::ErrlUserDetailsParserFactory
{
public:

    /**
     *  @brief Constructor
     */
    IStepUserDetailsParserFactory()
    {
        registerParser<IStepUserDetailsParserIstep>( ISTEP_UDT_PLID );
    }

private:

    // Disabled
    IStepUserDetailsParserFactory(const IStepUserDetailsParserFactory &);
    IStepUserDetailsParserFactory & operator=(
        const IStepUserDetailsParserFactory &);
};

}

#endif
#endif
