/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/ipvpdenums.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
#ifndef __IPVPDENUMS_H
#define __IPVPDENUMS_H

namespace IPVPD
{

    /**
     * @brief Enumeration for the IPVPD Records that contain
     *       the keyword enumerations below.
     */
    enum ipvpdRecord
    {
        IPVPD_FIRST_RECORD   = 0xFFF0,
        INVALID_RECORD       = IPVPD_FIRST_RECORD,

        // Last Record
        IPVPD_LAST_RECORD,
    };

    /**
     * @brief Enumerations for IPVPD keywords that can be
     *       accessed in the IPVPD.
     */
    enum ipvpdKeyword
    {
        IPVPD_FIRST_KEYWORD  = 0xFFF0,
        FULL_RECORD          = IPVPD_FIRST_KEYWORD,
        INVALID_KEYWORD      = 0xFFF1,

        // Last Keyword
        IPVPD_LAST_KEYWORD,
    };

};  // end IPVPD

#endif
