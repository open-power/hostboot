/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/plugins/fsiUdParserFactory.H $                    */
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
#if !defined(_FSIUDPARSERFACTORY_H)
#define _FSIUDPARSERFACTORY_H

#include "errludparserfactory.H"
#include "errludP_fsi.H"

namespace FSI
{
    class UserDetailsParserFactory
        : public ERRORLOG::ErrlUserDetailsParserFactory
    {
        public:
            UserDetailsParserFactory()
            {
                registerParser<FSI::UdParserPresence>
                  (FSI_UDT_PRESENCE);
                registerParser<FSI::UdParserOperation>
                  (FSI_UDT_OPERATION);
            }

        private:

            UserDetailsParserFactory(const UserDetailsParserFactory &);
            UserDetailsParserFactory & operator=
                (const UserDetailsParserFactory &);
    };
};

#endif

