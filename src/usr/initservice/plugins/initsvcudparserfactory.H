/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/plugins/initsvcudparserfactory.H $        */
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
#ifndef INITSVC_UDPARSERFACTORY_H
#define INITSVC_UDPARSERFACTORY_H

/**
 *  @file initsvcudparserfactory.H
 *
 *  Defines the InitSvcUserDetailsParserFactory.H class
 */
#include "errludparserfactory.H"
#include "initsvcudistep.H"

namespace INITSERVICE
{

/**
 * @class InitSvcUserDetailsParserFactory
 *
 * This factory produces ErrlUserDetailsParser objects to parse the specified
 * InitService user detail data.
*/
class InitSvcUserDetailsParserFactory : public ERRORLOG::ErrlUserDetailsParserFactory
{
public:

    /**
     *  @brief Constructor
     */
    InitSvcUserDetailsParserFactory()
    {
        registerParser<InitSvcUserDetailsParserIstep>(INIT_SVC_UDT_ISTEP);
    }

private:

    // Disabled
    InitSvcUserDetailsParserFactory(const InitSvcUserDetailsParserFactory &);
    InitSvcUserDetailsParserFactory & operator=(
        const InitSvcUserDetailsParserFactory &);
};

}

#endif

