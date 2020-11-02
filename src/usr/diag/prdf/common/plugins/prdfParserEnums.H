/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfParserEnums.H $          */
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

/** @file  prdfParserEnums.H
 *  @brief Common enums used for building and parsing capture data.
 */

#ifndef __prdfParserEnums_H
#define __prdfParserEnums_H

#include <prdfMemConst.H>

namespace PRDF
{
#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN)
namespace HOSTBOOT
{
#elif defined(PRDF_FSP_ERRL_PLUGIN)
namespace FSP
{
#endif

/* This table shows direct PARENT->CHILD relationships based on the targeting
   structure for the P10 chip.
|====================================================|
| PARENT         | CHILD          | Max # per PARENT |
|====================================================|
| TYPE_SYS       | TYPE_NODE      | 8                |
|----------------------------------------------------|
| TYPE_NODE      | TYPE_PROC      | 8                |
|----------------------------------------------------|
| TYPE_PROC      | TYPE_EQ        | 8                |
| TYPE_PROC      | TYPE_PAUC      | 4                |
| TYPE_PROC      | TYPE_MC        | 4                |
| TYPE_PROC      | TYPE_NMMU      | 2                |
| TYPE_PROC      | TYPE_PEC       | 2                |
|----------------------------------------------------|
| TYPE_EQ        | TYPE_FC        | 2                |
|----------------------------------------------------|
| TYPE_PAUC      | TYPE_IOHS      | 2                |
| TYPE_PAUC      | TYPE_OMIC      | 2                |
|----------------------------------------------------|
| TYPE_MC        | TYPE_OMIC      | 2                |
| TYPE_MC        | TYPE_MI        | 1                |
|----------------------------------------------------|
| TYPE_PEC       | TYPE_PHB       | 3                |
|----------------------------------------------------|
| TYPE_FC        | TYPE_EC        | 2                |
|----------------------------------------------------|
| TYPE_IOHS      | TYPE_PAU       | 1                |
|----------------------------------------------------|
| TYPE_OMIC      | TYPE_OMI       | 2                |
|----------------------------------------------------|
| TYPE_MI        | TYPE_MCC       | 2                |
|----------------------------------------------------|
| TYPE_MCC       | TYPE_OMI       | 2                |
|----------------------------------------------------|
| TYPE_OMI       | TYPE_OCMB_CHIP | 1                |
|----------------------------------------------------|
| TYPE_OCMB_CHIP | TYPE_MEM_PORT  | 1                |
|----------------------------------------------------|
| TYPE_MEM_PORT  | TYPE_DIMM      | 2                |
|----------------------------------------------------|
|====================================================|
*/
enum PositionBounds
{
    MAX_NODE_PER_SYS    = 8,

    MAX_PROC_PER_NODE   = 8,

    MAX_EQ_PER_PROC     = 8,

    MAX_PAUC_PER_PROC   = 4,

    MAX_IOHS_PER_PAUC   = 2,
    MAX_IOHS_PER_PROC   = MAX_IOHS_PER_PAUC * MAX_PAUC_PER_PROC,

    MAX_LINK_PER_IOHS   = 2,

    MAX_PAU_PER_IOHS    = 1,
    MAX_PAU_PER_PROC    = MAX_PAU_PER_IOHS * MAX_IOHS_PER_PROC,

    MAX_NMMU_PER_PROC   = 2,

    MAX_EC_PER_EQ       = 4,
    MAX_EC_PER_PROC     = MAX_EC_PER_EQ * MAX_EQ_PER_PROC,

    MAX_PEC_PER_PROC    = 2,

    MAX_PHB_PER_PEC     = 3,
    MAX_PHB_PER_PROC    = MAX_PHB_PER_PEC * MAX_PEC_PER_PROC,

    MAX_MC_PER_PROC     = 4,

    MAX_MI_PER_MC       = 1,
    MAX_MI_PER_PROC     = MAX_MI_PER_MC * MAX_MC_PER_PROC,

    MAX_DIMM_PER_PORT   = 2,
    MAX_DIMM_PER_RANK   = 2,

    MAX_MCC_PER_MI      = 2,
    MAX_MCC_PER_MC      = MAX_MCC_PER_MI * MAX_MI_PER_MC,
    MAX_MCC_PER_PROC    = MAX_MCC_PER_MC * MAX_MC_PER_PROC,

    MAX_OMIC_PER_MC     = 2,
    MAX_OMIC_PER_PAUC   = 2,
    MAX_OMIC_PER_PROC   = MAX_OMIC_PER_MC * MAX_MC_PER_PROC,

    MAX_OMI_PER_MCC     = 2,
    MAX_OMI_PER_OMIC    = 2,
    MAX_OMI_PER_MC      = MAX_OMI_PER_MCC * MAX_MCC_PER_MC,
    MAX_OMI_PER_PROC    = MAX_OMI_PER_MC * MAX_MC_PER_PROC,

    MAX_OCMB_PER_OMI    = 1,
    MAX_OCMB_PER_MCC    = MAX_OCMB_PER_OMI * MAX_OMI_PER_MCC,

    // TODO RTC 210072 - Support multiple ports
    MAX_PORT_PER_OCMB   = 1,

    INVALID_POSITION_BOUND = 0xffffffff,
};

namespace PARSER
{
    enum
    {
        // i_parser.PrintString() has two parts: header and data. These are the
        // maximum string lengths for one line in the error log. Note that the
        // header has a hard stop of one line, however, the data can wrap onto
        // multiple lines (not sure of the line limit).
        HEADER_SIZE  = 25,
        DATA_SIZE    = 50,
    };

} // namespace PARSER

namespace UE_TABLE
{
    enum
    {
        MAX_ENTRIES = 16, ///< Maximum number of entries allow in table.
        ENTRY_SIZE  =  7, ///< Number of bytes per entry.

        MAX_SIZE = MAX_ENTRIES * ENTRY_SIZE, ///< Maximum table size.
    };

    /**
     * @brief Represents the several different types of UEs stored in the table.
     */
    enum Type
    {
        SCRUB_MPE = 1, ///< Chip mark placed by scrub
        FETCH_MPE,     ///< Chip mark placed by fetch
        SCRUB_UE,      ///< Scrub UE
        FETCH_UE,      ///< Fetch UE
    };

} // namespace UE_TABLE

namespace CE_TABLE
{
    enum
    {
        METADATA_SIZE =  8, ///< Number of bytes for the table metadata.

        MAX_ENTRIES = 32, ///< Maximum number of entries allow in table.
        ENTRY_SIZE  =  9, ///< Number of bytes per entry.

        MAX_SIZE = METADATA_SIZE + MAX_ENTRIES * ENTRY_SIZE, ///< Maximum size.
    };

} // namespace CE_TABLE

namespace DQ_BITMAP
{
    enum
    {
        BITMAP_SIZE = 10, // 80-bit bitmap
        ENTRY_SIZE  = sizeof(uint8_t)*2 + BITMAP_SIZE,
    };

} // namespace DQ_BITMAP

namespace ROW_REPAIR
{
    enum
    {
        ROW_REPAIR_SIZE = 4, // 4 byte (32 bit) repair
        ENTRY_SIZE = sizeof(uint8_t)*2 + ROW_REPAIR_SIZE,
    };
} // namespace ROW_REPAIR

namespace SLW_FFDC_DATA
{
    static const char * const title = "SLW_FFDC_DATA";

    enum
    {
        MAX_ENTRIES = 39, ///< Maximum number of entries allowed.
        ENTRY_SIZE  = 12, ///< Number of bytes per entry.

        MAX_SIZE = MAX_ENTRIES * ENTRY_SIZE, ///< Maximum table size.
    };

} // namespace SLW_FFDC_DATA

// LineDelete/ColumnRepair FFDC
namespace LD_CR_FFDC
{
    static const char * const L2TITLE = "L2_LD_COLRPR_FFDC";
    static const char * const L3TITLE = "L3_LD_COLRPR_FFDC";

    struct L2LdCrFfdc
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32_t L2LDcnt        : 4;
        uint32_t L2LDMaxAllowed : 4;
        uint32_t L2CRMaxAllowed : 4;
        uint32_t L2CRPresent    : 4;
        uint32_t L2reserved1    :16;

        uint32_t L2errMember    : 3;
        uint32_t L2errDW        : 3;
        uint32_t L2errMacro     : 2;
        uint32_t L2errBank      : 1;
        uint32_t L2errOWSelect  : 1;
        uint32_t L2errBitLine   : 4;
        uint32_t L2errIsTopSA   : 1;
        uint32_t L2errIsLeftSA  : 1;
        uint32_t L2errAddress   :10;
        uint32_t L2reserved2    : 6;

        L2LdCrFfdc():
           L2LDcnt(0), L2LDMaxAllowed(0),
           L2CRMaxAllowed(0), L2CRPresent(0), L2reserved1(0),
           L2errMember(0), L2errDW(0), L2errMacro(0),
           L2errBank(0), L2errOWSelect(0), L2errBitLine(0),
           L2errIsTopSA(0), L2errIsLeftSA(0), L2errAddress(0), L2reserved2(0)
        {}
#else
        uint32_t L2reserved1    :16;
        uint32_t L2CRPresent    : 4;
        uint32_t L2CRMaxAllowed : 4;
        uint32_t L2LDMaxAllowed : 4;
        uint32_t L2LDcnt        : 4;

        uint32_t L2reserved2    : 6;
        uint32_t L2errAddress   :10;
        uint32_t L2errIsLeftSA  : 1;
        uint32_t L2errIsTopSA   : 1;
        uint32_t L2errBitLine   : 4;
        uint32_t L2errOWSelect  : 1;
        uint32_t L2errBank      : 1;
        uint32_t L2errMacro     : 2;
        uint32_t L2errDW        : 3;
        uint32_t L2errMember    : 3;

        L2LdCrFfdc():
           L2reserved1(0), L2CRPresent(0), L2CRMaxAllowed(0),
           L2LDMaxAllowed(0), L2LDcnt(0), L2reserved2(0),
           L2errAddress(0), L2errIsLeftSA(0), L2errIsTopSA(0),
           L2errBitLine(0), L2errOWSelect(0), L2errBank(0),
           L2errMacro(0), L2errDW(0), L2errMember(0)
        {}
#endif

    };

    struct L3LdCrFfdc
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32_t L3LDcnt           : 4;
        uint32_t L3LDMaxAllowed    : 4;
        uint32_t L3CRMaxAllowed    : 4;
        uint32_t L3CRPresent       : 4;
        uint32_t L3errBank         : 3;
        uint32_t L3errDataOut      : 8;
        uint32_t L3reserved1       : 5;

        uint32_t L3errMember       : 3;
        uint32_t L3errDW           : 3;
        uint32_t L3errHshAddress   :12;
        uint32_t L3errCacheAddress :14;

        L3LdCrFfdc():
           L3LDcnt(0), L3LDMaxAllowed(0), L3CRMaxAllowed(0),
           L3CRPresent(0), L3errBank(0), L3errDataOut(0),
           L3reserved1(0), L3errMember(0), L3errDW(0),
           L3errHshAddress(0), L3errCacheAddress(0)
        {}
#else
        uint32_t L3reserved1       : 5;
        uint32_t L3errDataOut      : 8;
        uint32_t L3errBank         : 3;
        uint32_t L3CRPresent       : 4;
        uint32_t L3CRMaxAllowed    : 4;
        uint32_t L3LDMaxAllowed    : 4;
        uint32_t L3LDcnt           : 4;

        uint32_t L3errCacheAddress :14;
        uint32_t L3errHshAddress   :12;
        uint32_t L3errDW           : 3;
        uint32_t L3errMember       : 3;

        L3LdCrFfdc():
           L3reserved1(0), L3errDataOut(0), L3errBank(0), L3CRPresent(0),
           L3CRMaxAllowed(0), L3LDMaxAllowed(0), L3LDcnt(0),
           L3errCacheAddress(0), L3errHshAddress(0), L3errDW(0), L3errMember(0)
        {}
#endif

    };


} // namespace LD_CR_FFDC

namespace TD_CTLR_DATA
{
    static const char * const START = "TDCTLR_STATE_DATA_START";
    static const char * const END   = "TDCTLR_STATE_DATA_END";

    enum State
    {
        IPL = 0,
        RT  = 1,
    };

    // We don't use 0 as one of the enum values here so we can ensure our data
    // is non-zero when we add the tdCtlr state to the capture data
    enum Version
    {
        // Version 1:
        //  Header:
        //      1-bit state (IPL or RT)
        //      3-bit version (VERSION_1)
        //      3-bit current procedure master rank (0-7)
        //      3-bit current procedure slave rank (0-7)
        //      4-bit current procedure phase (see TdEntry::Phase)
        //      4-bit current procedure type (see TdEntry::TdType)
        //      4-bit number of entries in the queue (0-15)
        //  For each entry in the queue
        //      3-bit entry master rank (0-7)
        //      3-bit entry slave rank (0-7)
        //      4-bit entry type (see TdEntry::TdType)
        VERSION_1 = 1,

        // Version 2 (includes port number):
        //  Header:
        //      1-bit state (IPL or RT)
        //      3-bit version (VERSION_2)
        //      3-bit current procedure master rank (0-7)
        //      3-bit current procedure slave rank (0-7)
        //      4-bit current procedure phase (see TdEntry::Phase)
        //      4-bit current procedure type (see TdEntry::TdType)
        //      4-bit number of entries in the queue (0-15)
        //      2-bit current procedure port relative to ocmb
        //  For each entry in the queue
        //      3-bit entry master rank (0-7)
        //      3-bit entry slave rank (0-7)
        //      4-bit entry type (see TdEntry::TdType)
        //      2-bit entry port relative to ocmb
        VERSION_2  = 2,
    };

    enum BitLen
    {
        v1_HEADER = 22,
        v1_ENTRY  = 10,

        v2_HEADER = 24,
        v2_ENTRY  = 12,
    };

} // namespace TD_CTLR_DATA

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif

} // end namespace PRDF

#endif // __prdfParserEnums_H

