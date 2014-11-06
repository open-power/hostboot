/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/cvpd.H $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
#ifndef __CVPD_H
#define __CVPD_H


/**
 * @file cvpd.H
 *
 * @brief Provides the interfaces for the CVPD device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <errl/errlentry.H>
#include <vpd/cvpdenums.H>

#include "ipvpd.H"
#include <config.h>

namespace CVPD
{

    enum
    {
#ifdef CONFIG_CDIMM_FORMAT_FOR_CVPD
        // 4KB x 64
        SECTION_SIZE       = 0x1000,
        MAX_SECTIONS       = 64,
#else
        // 8KB x 32
        SECTION_SIZE       = 0x2000,
        MAX_SECTIONS       = 32,
#endif
    };


    /**
     * @brief Conversion of CVPD Records to corresponding character
     *        representation.
     */
    const IpVpdFacade::recordInfo cvpdRecords[] =
    {
        // -------------------------------------------------------------------
        // NOTE: This list must remain an ordered list!  There will be a
        //      testcase that checks this.  When adding new entries to the
        //      list, be sure that the keyword in each entry (value 0)
        //      are in ascending order.
        // -------------------------------------------------------------------
        { VEIR, "VEIR" },
        { VER0, "VER0" },  //Not currently used, but keep support
        { MER0, "MER0" },
        { VSPD, "VSPD" },
        { VINI, "VINI" },
        { OPFR, "OPFR" },
        { VNDR, "VNDR" },
        { SPDX, "SPDX" },
        // -------------------------------------------------------------------
        // DO NOT USE!!  This is for test purposes ONLY!
        { CVPD_TEST_RECORD, "TEST" },
        // -------------------------------------------------------------------
    };

    /**
     * @brief Conversion of CVPD Keywords to corresponding character
     *        representation.
     */
    const IpVpdFacade::keywordInfo cvpdKeywords[] =
    {
        // -------------------------------------------------------------------
        // NOTE: This list must remain an ordered list!  There will be a
        //      testcase that checks this.  When adding new entries to
        //      the list, be sure that the keyword in each entry (value 0)
        //      are in ascending order.
        // -------------------------------------------------------------------
        { pdI, "#I" },
        { PF,  "PF" },
        { MT,  "MT" },
        { MR,  "MR" },
        { pdA, "#A" },
        { EL,  "EL" },
        { LM,  "LM" },
        { MW,  "MW" },
        { MV,  "MV" },
        { AM,  "AM" },
        { VZ,  "VZ" },
        { pdD, "#D" },
        { MX,  "MX" },
        { DW,  "DW" },
        { PN,  "PN" },
        { SN,  "SN" },
        { DR,  "DR" },
        { CE,  "CE" },
        { FN,  "FN" },
        { CC,  "CC" },
        { HE,  "HE" },
        { CT,  "CT" },
        { HW,  "HW" },
        { VD,  "VD" },
        { VN,  "VN" },
        { VP,  "VP" },
        { VS,  "VS" },
        { M0,  "M0" },
        { M1,  "M1" },
        { M2,  "M2" },
        { M3,  "M3" },
        { M4,  "M4" },
        { M5,  "M5" },
        { M6,  "M6" },
        { M7,  "M7" },
        { M8,  "M8" },
        { T1,  "T1" },
        { T2,  "T2" },
        { T4,  "T4" },
        { T5,  "T5" },
        { T6,  "T6" },
        { T8,  "T8" },
        { Q0,  "Q0" },
        { Q1,  "Q1" },
        { Q2,  "Q2" },
        { Q3,  "Q3" },
        { Q4,  "Q4" },
        { Q5,  "Q5" },
        { Q6,  "Q6" },
        { Q7,  "Q7" },
        { Q8,  "Q8" },
        { K0,  "K0" },
        { K1,  "K1" },
        { K2,  "K2" },
        { K3,  "K3" },
        { K4,  "K4" },
        { K5,  "K5" },
        { K6,  "K6" },
        { K7,  "K7" },
        { K8,  "K8" },

        // -------------------------------------------------------------------
        // DO NOT USE!!  This is for test purposes ONLY!
        { CVPD_TEST_KEYWORD, "XX" },
        // -------------------------------------------------------------------
    };

}; // end CVPD namespace

class CvpdFacade: public IpVpdFacade
{
  public:

    /**
     * @brief Constructor
     */
    CvpdFacade( );

};
#endif  // __CVPD_H
