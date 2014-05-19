/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/cvpdenums.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef __CVPDENUMS_H
#define __CVPDENUMS_H

namespace CVPD
{

    /**
     * @brief Enumeration for the CVPD Records that contain
     *       the keyword enumerations below.
     */
    enum cvpdRecord
    {
        CVPD_FIRST_RECORD   = 0x00,
        VEIR        = CVPD_FIRST_RECORD,
        VER0        = 0x01,
        MER0        = 0x02,
        VSPD        = 0x03,
        VINI        = 0x04,
        // Last Record
        CVPD_LAST_RECORD,
        CVPD_TEST_RECORD,   // Test purposes ONLY!
        CVPD_INVALID_RECORD = 0xFFFF,
    };

    /**
     * @brief Enumerations for CVPD keywords that can be
     *       accessed in the CVPD.
     */
    enum cvpdKeyword
    {
        CVPD_FIRST_KEYWORD      = 0x00,
        pdI          = CVPD_FIRST_KEYWORD,
        PF           = 0x01,
        MT           = 0x02,
        MR           = 0x03,
        pdA          = 0x04,
        EL           = 0x05,
        LM           = 0x06,
        MW           = 0x07,
        MV           = 0x08,
        AM           = 0x09,
        VZ           = 0x0a,
        pdD          = 0x0b,
        MX           = 0x0c,

        // Last Keyword
        CVPD_LAST_KEYWORD,
        CVPD_TEST_KEYWORD,  // Test purposes ONLY!
        CVPD_INVALID_KEYWORD    = 0xFFFF,
    };

};  // end CVPD

#endif
