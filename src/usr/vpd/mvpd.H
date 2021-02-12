/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/mvpd.H $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
/* [+] Google Inc.                                                        */
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
/* File mvpdnew.H created by ADAM R. MUHLE on Tue Jan 29 2013. */

/* Change Activity: */
/* End Change Activity */

#ifndef _MVPD_H
#define _MVPD_H

#include <vpd/mvpdenums.H>

#include "ipvpd.H"

namespace MVPD
{
    // ----------------------------------------------
    // Defines
    // ----------------------------------------------
    enum
    {
        SECTION_SIZE       = 0x10000, //64KB VPD per processor
        MAX_SECTIONS       = 8,  //8 Processors in PNOR
    };

    const IpVpdFacade::recordInfo mvpdRecords[] =
    {
        // -------------------------------------------------------------------
        // NOTE: This list must remain an ordered list!  There will be a
        //      testcase that checks this.  When adding new entries to the
        //      list, be sure that the keyword in each entry (value 0)
        //      are in ascending order.
        // -------------------------------------------------------------------
        { CRP0, "CRP0" },
        { CP00, "CP00" },
        { VINI, "VINI" },
        { LRP0, "LRP0" },
        { LRP1, "LRP1" },
        { LRP2, "LRP2" },
        { LRP3, "LRP3" },
        { LRP4, "LRP4" },
        { LRP5, "LRP5" },
        { LWP0, "LWP0" },
        { LWP1, "LWP1" },
        { LWP2, "LWP2" },
        { LWP3, "LWP3" },
        { LWP4, "LWP4" },
        { LWP5, "LWP5" },
        { VRML, "VRML" },
        { VWML, "VWML" },
        { VER0, "VER0" },
        { MER0, "MER0" },
        { VMSC, "VMSC" },
        // -------------------------------------------------------------------
        // DO NOT USE!!  This is for test purposes ONLY!
        { MVPD_TEST_RECORD, "TEST" },
        // -------------------------------------------------------------------
    };

    /**
     * @brief Conversion of MVPD Keywords to corresponding character
     *        representation.
     */
    const IpVpdFacade::keywordInfo mvpdKeywords[] =
    {
        // -------------------------------------------------------------------
        // NOTE: This list must remain an ordered list!  There will be a
        //      testcase that checks this.  When adding new entries to
        //      the list, be sure that the keyword in each entry (value 0)
        //      are in ascending order.
        // -------------------------------------------------------------------
        { VD,  "VD" },
        { ED,  "ED" },
        { TE,  "TE" },
        { DD,  "DD" },
        { DN,  "DN" },
        { PG,  "PG" },
        { PK,  "PK" },
        { pdR, "#R" },
        { pdV, "#V" },
        { pdH, "#H" },
        { SB,  "SB" },
        { DR,  "DR" },
        { VZ,  "VZ" },
        { CC,  "CC" },
        { CE,  "CE" },
        { FN,  "FN" },
        { PN,  "PN" },
        { SN,  "SN" },
        { PR,  "PR" },
        { HE,  "HE" },
        { CT,  "CT" },
        { HW,  "HW" },
        { pdM, "#M" },
        { IN,  "IN" },
        { pdI, "#I" },
        { pdG, "#G" },
        { PB,  "PB" },
        { CH,  "CH" },
        { IQ,  "IQ" },
        { PM,  "PM" },
        { PZ,  "PZ" },
        { n20, "20" },
        { n21, "21" },
        { n30, "30" },
        { n31, "31" },
        { L1, "L1" },
        { L2, "L2" },
        { L3, "L3" },
        { L4, "L4" },
        { L5, "L5" },
        { L6, "L6" },
        { L7, "L7" },
        { L8, "L8" },
        { pdW, "#W" },
        { RT,  "RT" },
        { AW,  "AW" },
        { CI,  "CI" },
        { pdP, "#P" },
        { pdS, "#S" },
        { MK,  "MK" },

        // -------------------------------------------------------------------
        // DO NOT USE!!  This is for test purposes ONLY!
        { MVPD_TEST_KEYWORD, "XX" },
        // -------------------------------------------------------------------

        //Common ipvpd
        { FULL_RECORD, "FL"},
    };

} //end namespace MVPD

class MvpdFacade: public IpVpdFacade
{
  public:

    /**
     * @brief Constructor
     */
    MvpdFacade( );

    /**
     *  @brief Return the MvpdFacade singleton
     *
     *  @return MvpdFacade& Reference to the MvpdFacade singleton
     */
    static MvpdFacade& getInstance();

};

#endif /* _MVPD_H */
