/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/pvpd.H $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#ifndef __PVPD_H
#define __PVPD_H


/**
 * @file pvpd.H
 *
 * @brief Provides the interfaces for the PVPD device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <errl/errlentry.H>
#include <vpd/pvpdenums.H>

#include "ipvpd.H"

namespace PVPD
{

    /**
     * @brief Conversion of PVPD Records to corresponding character
     *        representation.
     */
    const IpVpdFacade::recordInfo pvpdRecords[] =
    {
        // -------------------------------------------------------------------
        // NOTE: This list must remain an ordered list!  There will be a
        //      testcase that checks this.  When adding new entries to the
        //      list, be sure that the keyword in each entry (value 0)
        //      are in ascending order.
        // -------------------------------------------------------------------
        { VINI, "VINI" },
        { VSYS, "VSYS" },
        { LXR0, "LXR0" },
        // -------------------------------------------------------------------
        // DO NOT USE!!  This is for test purposes ONLY!
        { PVPD_TEST_RECORD, "TEST" },
        // -------------------------------------------------------------------
    };

    /**
     * @brief Conversion of PVPD Keywords to corresponding character
     *        representation.
     */
    const IpVpdFacade::keywordInfo pvpdKeywords[] =
    {
        // -------------------------------------------------------------------
        // NOTE: This list must remain an ordered list!  There will be a
        //      testcase that checks this.  When adding new entries to
        //      the list, be sure that the keyword in each entry (value 0)
        //      are in ascending order.
        // -------------------------------------------------------------------
        { pdI, "#I" },
        { B3,  "B3" },
        { B4,  "B4" },
        { B7,  "B7" },
        { CC,  "CC" },
        { CE,  "CE" },
        { CT,  "CT" },
        { DR,  "DR" },
        { ET,  "ET" },
        { FN,  "FN" },
        { HE,  "HE" },
        { HW,  "HW" },
        { IN,  "IN" },
        { MM,  "MM" },
        { PF,  "PF" },
        { PN,  "PN" },
        { RT,  "RT" },
        { SN,  "SN" },
        { SS,  "SS" },
        { VD,  "VD" },
        { VN,  "VN" },
        { VP,  "VP" },
        { VS,  "VS" },
        { VZ,  "VZ" },
        { LX,  "LX" },
        { MB,  "MB" },
        { NV,  "NV" },
        { FG,  "FG" },
        { HX,  "HX" },
        { TS,  "TS" },
        { BR,  "BR" },
        { FV,  "FV" },
        { ID,  "ID" },
        { MN,  "MN" },
        { RB,  "RB" },
        { RG,  "RG" },
        { SE,  "SE" },
        { SG,  "SG" },
        { SU,  "SU" },
        { TM,  "TM" },
        { TN,  "TN" },
        { WN,  "WN" },

        // -------------------------------------------------------------------
        // DO NOT USE!!  This is for test purposes ONLY!
        { PVPD_TEST_KEYWORD, "XX" },
        // -------------------------------------------------------------------

        //Common ipvpd
        { FULL_RECORD, "FL"},
    };

}; // end PVPD namespace

class PvpdFacade: public IpVpdFacade
{
  public:

    /**
     * @brief Constructor
     */
    PvpdFacade( );

  private:

    /**
     * @brief This function returns a primary and an alternate list of records
     *       that should be copied to pnor. The Alternate list is optional.
     *
     * @param[out] o_primaryVpdRecords - Pointer to array of VPD Records to use
     *
     * @param[out] o_primaryRecSize -    Size of o_primaryVpdRecords array
     *
     * @param[out] o_altVpdRecords -     Pointer to array of VPD Records to use
     *
     * @param[out] o_altRecSize -        Size of o_altVpdRecords array
     *
     */
    void getRecordLists(
                const  recordInfo* & o_primaryVpdRecords,
                uint64_t           & o_primaryRecSize,
                const  recordInfo* & o_altVpdRecords,
                uint64_t           & o_altRecSize);

};
#endif  // __PVPD_H
