/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfMemoryMruData.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/** @file  prdfMemoryMruData.H
 *  @brief This is specifically designed to be included in both functional and
 *         error log parsing code (i.e. must be able to compile in PPC and
 *         x86.nfp contexts).
 */

#ifndef __prdfMemoryMruData_H
#define __prdfMemoryMruData_H

#include <stdint.h>

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

namespace MemoryMruData
{

/** Typically a MemoryMru callout is associated with a symbol (single DIMM
 *  callout), however, there are times were we cannot isolate down that far and
 *  instead need to callout a rank (pair of DIMMs) and the assoicated MBA.
 *  This enums will be used to indicate if any special callouts are needed.
 */
enum Callout
{
    // NOTE: These values will be stored in the symbol field of the uint32_t
    //       version of the MemoryMru so the values must fit within the
    //       7-bits field and not collide with a valid symbol value.
    NO_SPECIAL_CALLOUT    = 0x6f,
    FIRST_SPECIAL_CALLOUT = 0x70,

    CALLOUT_RANK = FIRST_SPECIAL_CALLOUT,
    CALLOUT_RANK_AND_MBA,
    CALLOUT_ALL_MEM,

    LAST_SPECIAL_CALLOUT = CALLOUT_ALL_MEM, // Absolute last value is 0x7f
};

union MemMruMeld
{
    uint32_t u; ///< The 32-bit version of the MemoryMru

    struct
    {
        // NOTE: The combined total of all bits in this struct must add up to
        //       32 bits.
        // NOTE: There are some unused bits that can be used for future needs
        //       such as version number or wiring type.
        // NOTE: The arrangement of bits should not change. This struct will be
        //       used for parsing the MemoryMru in the error log parser, which
        //       wil be used in multiple releases. You should be able to add a
        //       field using the unused bits depending on the usage of the
        //       field, however, if the structure changes, you must add a
        //       version field so that the error log parser know which format to
        //       used.

#ifndef ESW_SIM_COMPILE
        uint32_t valid      : 1; ///< Used to indicate nothing failed while
                                 ///< building the object (1=valid, 0=not valid)
        uint32_t procPos    : 3; ///< Proc position within node (0-7)
        uint32_t cenPos     : 3; ///< Centaur position within proc (0-7)
        uint32_t mbaPos     : 1; ///< MBA position within centaur (0-1)

        uint32_t pins       : 2; ///< Even and/or Odd symbol pins
        uint32_t nodePos    : 3; ///< Node position (0-7)
        uint32_t mrank      : 3; ///< Master rank (0-7)

        uint32_t dramSpared : 1; ///< True if symbol is on spared DRAM
        uint32_t symbol     : 7; ///< Symbol or SpecialCallout

        uint32_t eccSpared  : 1; ///< True if symbol is on ECC DRAM
        // TODO: RTC 67376 Check if width for wiring type is enough
        uint32_t wiringType : 3; ///< Wiring type
        uint32_t srankValid : 1; ///< TRUE if slave rank is valid
        uint32_t srank      : 3; ///< Slave rank (0-7)
#else
        // Need to reverse this to make the uint32_t look right in the
        // simulator.
        uint32_t srank      : 3;
        uint32_t srankValid : 1;
        uint32_t wiringType : 3;
        uint32_t eccSpared  : 1;
        uint32_t symbol     : 7;
        uint32_t dramSpared : 1;
        uint32_t mrank      : 3;
        uint32_t nodePos    : 3;
        uint32_t pins       : 2;
        uint32_t mbaPos     : 1;
        uint32_t cenPos     : 3;
        uint32_t procPos    : 3;
        uint32_t valid      : 1;
#endif

    } s; ///< A struct defining the 32-bit version of the MemoryMru
};

} // end namespace MemoryMruData
#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
} // end namespace HOSTBOOT
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
} // end namespace FSP
#endif

} // end namespace PRDF

#endif // __prdfMemoryMruData_H

