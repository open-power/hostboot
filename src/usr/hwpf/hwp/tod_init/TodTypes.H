/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/TodTypes.H $                        */
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
#ifndef TODTYPES_H
#define TODTYPES_H

/**
 *  @file TodTypes.H
 *
 *  @brief The file primarily conatins definition of data strucrtures that are
 *      required to share the tod topology register data between HB and HDAT.
 *      It also define the format of data that will be saved in file
 *      for persistency of TOD configuration data.
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

namespace TOD
{

    /**
     * Enums for the TodChipHeader->flags, These values are defined as per
     * details provided by HDAT data structure details provided by HDAT
     */
    enum
    {
        TOD_NONE     = 0x00000000,
        TOD_SEC_MDMT = 0x00000001,
        TOD_PRI_MDMT = 0x00000002,
        TOD_FUNC     = 0x00000004,
        TOD_NONFUNC  = 0x00000008,
    };


    /**
     * Sub structure of TodChipData, Represents the Chip ID details required
     * by HDAT
     *
     */
    struct TodChipHeader
    {
        uint32_t chipID; //Chip ID
        uint32_t flags;  //Flags
        TodChipHeader(void) : chipID(0),flags(TOD_NONFUNC) {}
    };

    /**
     * Sub structure of TodChipData, That will contain the first 32 bits of
     * all the TOD register values, that were populated during creation of the
     * TOD topology.
     * Out of the below register ipcr and ccr  are required by HDAT. Others are
     * there for persistancy
     *
     */
    struct TodRegs
    {
        uint32_t mpcr;   //Master Path Control Register
        uint32_t pcrp0;  //Primary Configuration Register Port 0
        uint32_t pcrp1;  //Primary Configuration Register Port 1
        uint32_t scrp0;  //Secondary Configuration Register Port 0
        uint32_t scrp1;  //Secondary Configuration Register Port 1
        uint32_t spcr;   //Slave Path Control Register
        uint32_t ipcr;   //Internal Path Control Register
        uint32_t psmscr;     //Primary/Secondary Master/Slave Control Register
        uint32_t ccr; //Chip Control Register
        TodRegs(void)
            :
            mpcr(0),pcrp0(0),pcrp1(0),scrp0(0),scrp1(0),
            spcr(0),ipcr(0),psmscr(0),ccr(0)
        {}
    };

    /**
     * TOD Data for each chip that HDAT will communicate
     * to PHYP.
     */
    struct TodChipData
    {
        TodChipHeader header;
        TodRegs       regs;
        TodChipData(void) : header(), regs() {}
    };

} //end of namespace

#endif
