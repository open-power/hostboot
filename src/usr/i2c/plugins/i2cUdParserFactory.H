/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/plugins/i2cUdParserFactory.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
#if !defined(_I2CUDPARSERFACTORY_H)
#define _I2CUDPARSERFACTORY_H

#include "errludparserfactory.H"
#include "errludP_i2c.H"

namespace I2C
{
    class UserDetailsParserFactory
        : public ERRORLOG::ErrlUserDetailsParserFactory
    {
        public:
            UserDetailsParserFactory()
            {
                registerParser<I2C::UdParserI2CParms>
                  (I2C_UDT_PARAMETERS);
            }

        private:

            UserDetailsParserFactory(const UserDetailsParserFactory &);
            UserDetailsParserFactory & operator=
                (const UserDetailsParserFactory &);
    };
};

namespace EEPROM
{
    class UserDetailsParserFactory
        : public ERRORLOG::ErrlUserDetailsParserFactory
    {
        public:
            UserDetailsParserFactory()
            {
                registerParser<EEPROM::UdParserEepromParms>
                  (EEPROM_UDT_PARAMETERS);
            }

        private:

            UserDetailsParserFactory(const UserDetailsParserFactory &);
            UserDetailsParserFactory & operator=
                (const UserDetailsParserFactory &);
    };
};

#endif

