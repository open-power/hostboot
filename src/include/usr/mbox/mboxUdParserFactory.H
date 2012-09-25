/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/mbox/mboxUdParserFactory.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#if !defined(_MBOXUDPARSERFACTORY_H)
#define _MBOXUDPARSERFACTORY_H

#if defined(PARSER)

#include <mbox/mboxUdParser.H>
#include <mbox/mbox_reasoncodes.H>
#include <errl/errludparserfactory.H>

namespace MBOX
{
    class UserDetailsParserFactory 
        : public ERRORLOG::ErrlUserDetailsParserFactory
    {
        public:
            UserDetailsParserFactory()
            {
                registerParser<MBOX::UserDetailsParserMboxMsg>
                    (MBOX_UDT_MBOXMSG_DATA);
            }

        private:

            UserDetailsParserFactory(const UserDetailsParserFactory &);
            UserDetailsParserFactory & operator=
                (const UserDetailsParserFactory &);
    };
};

#endif
#endif
