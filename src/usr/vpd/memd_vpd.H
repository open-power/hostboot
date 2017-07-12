/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/memd_vpd.H $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#ifndef __MEMD_VPD_H
#define __MEMD_VPD_H


/**
 * @file MEMD_VPD.H
 *
 * @brief Provides the interfaces for the MEMD_VPD device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <errl/errlentry.H>
#include <vpd/memd_vpdenums.H>

#include "ipvpd.H"
#include <config.h>

namespace MEMD_VPD
{

    enum
    {
        MAX_SECTIONS    = 1,
        SECTION_SIZE    = 0x6000,
    };


    /**
     * @brief Conversion of MEMD_VPD Records to corresponding character
     *        representation.
     */
    const IpVpdFacade::recordInfo MEMD_VPDRecords[] =
    {
        // -------------------------------------------------------------------
        // NOTE: This list must remain an ordered list!  There is a
        //      testcase that checks this.  When adding new entries to the
        //      list, be sure that the keyword in each entry (value 0)
        //      are in ascending order.
        // -------------------------------------------------------------------
        { MEMD, "MEMD" },

        // -------------------------------------------------------------------
        // DO NOT USE!!  This is for test purposes ONLY!
        { MEMD_VPD_TEST_RECORD, "TEST" },
        // -------------------------------------------------------------------
    };

    /**
     * @brief Conversion of MEMD_VPD Keywords to corresponding character
     *        representation.
     */
    const IpVpdFacade::keywordInfo MEMD_VPDKeywords[] =
    {
        // -------------------------------------------------------------------
        // NOTE: This list must remain an ordered list!  There is a
        //      testcase that checks this.  When adding new entries to
        //      the list, be sure that the keyword in each entry (value 0)
        //      are in ascending order.
        // -------------------------------------------------------------------
        { B3,   "B3" },
        { B4,   "B4" },
        { B7,   "B7" },
        { CC,   "CC" },
        { CE,   "CE" },
        { CT,   "CT" },
        { DR,   "DR" },
        { FC,   "FC" },
        { FN,   "FN" },
        { HE,   "HE" },
        { HW,   "HW" },
        { I2,   "I2" },
        { IN,   "IN" },
        { J0,   "J0" },
        { J1,   "J1" },
        { J2,   "J2" },
        { J3,   "J3" },
        { J4,   "J4" },
        { J5,   "J5" },
        { J6,   "J6" },
        { J7,   "J7" },
        { J8,   "J8" },
        { J9,   "J9" },
        { JA,   "JA" },
        { JB,   "JB" },
        { JC,   "JC" },
        { JD,   "JD" },
        { JE,   "JE" },
        { JF,   "JF" },
        { JG,   "JG" },
        { JH,   "JH" },
        { JI,   "JI" },
        { JJ,   "JJ" },
        { JK,   "JK" },
        { JL,   "JL" },
        { JM,   "JM" },
        { JN,   "JN" },
        { JO,   "JO" },
        { JP,   "JP" },
        { JQ,   "JQ" },
        { JR,   "JR" },
        { JS,   "JS" },
        { JT,   "JT" },
        { JU,   "JU" },
        { JV,   "JV" },
        { JW,   "JW" },
        { JX,   "JX" },
        { JY,   "JY" },
        { JZ,   "JZ" },
        { LX,   "LX" },
        { MR,   "MR" },
        { MT,   "MT" },
        { PF,   "PF" },
        { PN,   "PN" },
        { PR,   "PR" },
        { RB,   "RB" },
        { RG,   "RG" },
        { RT,   "RT" },
        { SE,   "SE" },
        { SN,   "SN" },
        { SO,   "SO" },
        { TM,   "TM" },
        { VM,   "VM" },
        { VZ,   "VZ" },
        { X0,   "X0" },
        { X1,   "X1" },
        { X2,   "X2" },
        { X3,   "X3" },
        { X4,   "X4" },
        { X5,   "X5" },
        { X6,   "X6" },
        { X7,   "X7" },
        { X8,   "X8" },
        { X9,   "X9" },
        { XA,   "XA" },
        { XB,   "XB" },
        { XC,   "XC" },
        { XD,   "XD" },
        { XE,   "XE" },
        { XF,   "XF" },
        { XG,   "XG" },
        { XH,   "XH" },
        { XI,   "XI" },
        { XJ,   "XJ" },
        { XK,   "XK" },
        { XL,   "XL" },
        { XM,   "XM" },
        { XN,   "XN" },
        { XO,   "XO" },
        { XP,   "XP" },
        { XQ,   "XQ" },
        { XR,   "XR" },
        { XS,   "XS" },
        { XT,   "XT" },
        { XU,   "XU" },
        { XV,   "XV" },
        { XW,   "XW" },
        { XX,   "XX" },
        { XY,   "XY" },
        { XZ,   "XZ" },
        { Q0,   "Q0" },
        { Q1,   "Q1" },
        { Q2,   "Q2" },
        { Q3,   "Q3" },
        { Q4,   "Q4" },
        { Q5,   "Q5" },
        { Q6,   "Q6" },
        { Q7,   "Q7" },
        { Q8,   "Q8" },
        { CK,   "CK" },

        // -------------------------------------------------------------------
        // DO NOT USE!!  This is for test purposes ONLY!
        { MEMD_VPD_TEST_KEYWORD, "ZZ" },
        // -------------------------------------------------------------------

        //Common ipvpd
        { FULL_RECORD, "FL"},
    };

}; // end MEMD_VPD namespace

class MEMD_VpdFacade: public IpVpdFacade
{
  public:

    /**
     * @brief Constructor
     */
    MEMD_VpdFacade( );


  protected:
    virtual bool recordPresent( const char * i_record,
                        uint16_t & offset,
                        TARGETING::Target * i_target,
                        VPD::vpdCmdTarget i_location );


};
#endif  // __MEMD_VPD_H
