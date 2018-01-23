/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/common/plugins/secureUdParserFactory.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#if !defined(_SECUREUDPARSERFACTORY_H)
#define _SECUREUDPARSERFACTORY_H

#include "errludparserfactory.H"
#include "errludP_secure.H"

namespace SECUREBOOT
{
    class UserDetailsParserFactory
        : public ERRORLOG::ErrlUserDetailsParserFactory
    {
        public:
            UserDetailsParserFactory()
            {
                registerParser<SECUREBOOT::UdParserSystemHwKeyHash>
                  (SECURE_UDT_SYSTEM_HW_KEY_HASH);

                registerParser<SECUREBOOT::UdParserTargetHwKeyHash>
                  (SECURE_UDT_TARGET_HW_KEY_HASH);

                registerParser<SECUREBOOT::UdParserSecuritySettings>
                  (SECURE_UDT_SECURITY_SETTINGS);

                registerParser<SECUREBOOT::UdParserVerifyInfo>
                  (SECURE_UDT_VERIFY_INFO);
            }

        private:

            UserDetailsParserFactory(const UserDetailsParserFactory &);
            UserDetailsParserFactory & operator=
                (const UserDetailsParserFactory &);
    };
};

#endif

