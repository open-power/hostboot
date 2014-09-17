/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfParserEnums.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

#include <prdfCenConst.H>

namespace PRDF
{
#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
{
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
namespace FSP
{
#endif

enum PositionBounds
{
    MAX_NODE_PER_SYS    = 8,

    MAX_PROC_PER_NODE   = 8,

    MAX_EX_PER_PROC     = 16,
    MAX_CORE_PER_PROC   = MAX_EX_PER_PROC,
    MAX_L2_PER_PROC     = MAX_EX_PER_PROC,
    MAX_L3_PER_PROC     = MAX_EX_PER_PROC,

    MAX_XBUS_PER_PROC   = 4,
    MAX_ABUS_PER_PROC   = 3,
    MAX_PHB_PER_PROC    = 3,

    MAX_MCS_PER_PROC    = 8,
    MAX_MEMBUF_PER_PROC = MAX_MCS_PER_PROC,

    MAX_MBA_PER_MEMBUF  = 2,
    MAX_PORT_PER_MBA    = 2,
    MAX_DIMM_PER_PORT   = 2,
    MAX_L4_PER_MEMBUF   = 1,

    MAX_PCIE_OSC_PER_NODE = 2,

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
        MAX_ENTRIES = 32, ///< Maximum number of entries allow in table.
        ENTRY_SIZE  =  9, ///< Number of bytes per entry.

        MAX_SIZE = MAX_ENTRIES * ENTRY_SIZE, ///< Maximum table size.
    };

} // namespace CE_TABLE

namespace RCE_TABLE
{
    enum
    {
        ENTRY_SIZE  =  2, ///< Number of bytes per entry.
    };

} // namespace RCE_TABLE

namespace DQ_BITMAP
{
    enum
    {
        BITMAP_SIZE = 10, // 80-bit bitmap
        ENTRY_SIZE  = sizeof(uint8_t) + PORT_SLCT_PER_MBA * BITMAP_SIZE,
    };

} // namespace DQ_BITMAP

namespace CEN_SYMBOL
{

    /** Used as a 2-bit mask to display which of the DQs on this symbol are
     *  failing. */
    enum DqMask
    {
        NO_SYMBOL_DQS   = 0x0,
        ODD_SYMBOL_DQ   = 0x1,
        EVEN_SYMBOL_DQ  = 0x2,
        BOTH_SYMBOL_DQS = EVEN_SYMBOL_DQ | ODD_SYMBOL_DQ,
    };

    /** A three bit field in memory MRU. It describes the raw card type for
     *  buffered DIMMs or the DIMM plug card type for IS DIMMs. These types are
     *  used for error log parsing which must be supported independent of the
     *  drivers (i.e. eblis tool) so enums can be added, but the values of the
     *  enums cannot be changed */
    enum WiringType
    {
        CEN_TYPE_A          = 0,
        CEN_TYPE_B          = 1,
        CEN_TYPE_D          = 2,
        CEN_TYPE_C          = 3,
        WIRING_INVALID      = 7, // An invalid card type
    };

}//namespace CEN_SYMBOL ends

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

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
} // end namespace HOSTBOOT
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
} // end namespace FSP
#endif

} // end namespace PRDF

#endif // __prdfParserEnums_H

