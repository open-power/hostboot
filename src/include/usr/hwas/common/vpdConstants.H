/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/vpdConstants.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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

#ifndef VPD_CONSTANTS_H
#define VPD_CONSTANTS_H

#include <targeting/common/commontargeting.H>

// @TODO RTC 249996 std::array isn't available pre-C++11. The reason we're
//                  keeping it in conditionally is so that the static_assert
//                  below can still be used during Hostboot compiles.
#ifdef __HOSTBOOT_MODULE
#include <array>
#endif

namespace HWAS
{

// pg_entry_t represents one entry in the partial-good vector (PGV). A 0 in a
// particular bit position means that the part is functional; a 1 means that it
// is nonfunctional. In P10 the PG VPD each row is comprised of 24 bits, so this
// has some room to grow.
typedef uint32_t pg_entry_t;

// pg_idx_t represents an index into the PG vector. Max value is 255.
typedef uint8_t pg_idx_t;

// pg_mask_t represents a mask that will be applied to a pg_entry_t.
typedef uint32_t pg_mask_t;

// NOTE: Many of the VPD_CP00_PG_X constants are used to construct an "All Good"
//       vector to compare against the PG vector of a system. Changes to
//       constants in this file should be reflected both in
//       src/usr/hwas/plugins/errludParser_pgData.H and
//       src/build/tools/ebmc/vpdConstants.py

// constants the platReadPartialGood will use for looking at the VPD data
const pg_idx_t VPD_CP00_PG_DATA_LENGTH      = 192;
// TODO RTC 208782: Update VPD_CP00_PG_HDR_LENGTH if necessary
const pg_idx_t VPD_CP00_PG_HDR_LENGTH       = 1;
const uint32_t VPD_CP00_PG_ENTRY_SIZE       = 3;
const uint32_t VPD_CP00_PG_DATA_ENTRIES     = VPD_CP00_PG_DATA_LENGTH
                                            / VPD_CP00_PG_ENTRY_SIZE;

// The pgv type holds the entirety of the PGV after it is read and unpacked from
// the VPD.
// @TODO RTC 249996 std::array isn't available pre-C++11 but needed for
//                  static_assert during Hostboot compiles.
#ifdef __HOSTBOOT_MODULE
typedef std::array<pg_entry_t, VPD_CP00_PG_DATA_ENTRIES> partialGoodVector;
#else
typedef pg_entry_t partialGoodVector[VPD_CP00_PG_DATA_ENTRIES];
#endif

// Following are ALL_GOOD, ALWAYS_GOOD, and INDEX constants for entries in the
// PGV; they are defined according to the P10 Partial Good Keyword
// documentation. Note that these are 32-bit values; they are the 24-bit values
// from the documentation right-justified and padded on the left with 1-bits (1
// indicates not-present or not-functional).
//
// The *_ALL_GOOD constants are what are found in the PGV (after 4-byte
// 1-extension) when all subcomponents of the chiplet are good.
//
// The *_ALWAYS_GOOD constants are only defined for chiplets that are themselves
// marked always-good for the entire chip. Bits in the PGV entries corresponding
// to set (1) bit positions in the *_ALWAYS_GOOD masks must be GOOD (0) or else
// the entire chip is considered nonfunctional.
//
// The *_INDEX constants are the offset in number-of-entries (whether in 3-byte
// chunks in the VPD or in 4-byte chunks post-extension) from the beginning of
// the PGV at which the given value is located.

// UNSET: vital, fsia, fsi0, fsi1, fsi0ll, fsi1ll, fsi0inv
const pg_entry_t VPD_CP00_PG_FSI_ALL_GOOD = 0xFFE03FFFu;
// SET: fsia, fsi0, fsi1, fsi0ll, fsi1ll, fsi0inv
const pg_mask_t VPD_CP00_PG_FSI_ALWAYS_GOOD_MASK = 0x000FC000u;
const pg_idx_t VPD_CP00_PG_FSI_INDEX = 0;

// UNSET: vital, perv, sbe, pib, occ, net, iopsi, dpllpau, dpllnest, pllperv
const pg_entry_t VPD_CP00_PG_PRV_ALL_GOOD = 0xFFE051FFu;
// SET: perv, sbe, pib, occ, net, iopsi, dpllpau, dpllnest, pllperv
const pg_mask_t VPD_CP00_PG_PRV_ALWAYS_GOOD_MASK = 0x000FAE00u;
const pg_idx_t VPD_CP00_PG_PRV_INDEX = 1;

// This is actually the "vital" bit but the functionality of the PERV targets
// depend on it rather than the "perv" bit.
const pg_mask_t VPD_CP00_PG_PERV_BIT = 0x00100000u;

// UNSET: vital, perv, misc, pe
const pg_entry_t VPD_CP00_PG_N0_ALL_GOOD = 0xFFE37FFFu;
// SET: perv, misc, pe
const pg_mask_t VPD_CP00_PG_N0_ALWAYS_GOOD_MASK = 0x000C8000u;
const pg_idx_t VPD_CP00_PG_N0_INDEX = 2;

// UNSET: vital, perv, fbc, pe, nmmu
const pg_entry_t VPD_CP00_PG_N1_ALL_GOOD = 0xFFE53FFFu;
// SET: perv, fbc, pe, nmmu
const pg_mask_t VPD_CP00_PG_N1_ALWAYS_GOOD_MASK = 0x000AC000u;
const pg_idx_t VPD_CP00_PG_N1_INDEX = 3;

// UNSET: vital, perv, ecl20, ecl21, ecl22, ecl23, l30, l31, l32,
//        l33, qme, clkadj, mma0, mma1, mma2, mma3
const pg_entry_t VPD_CP00_PG_EQ_ALL_GOOD = 0xFFE0001Fu;
// SET: perv, qme, clkadj
const pg_mask_t VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK = 0x00080600u;
const pg_idx_t VPD_CP00_PG_EQ_INDEX[] =
{
    // These are the indices in the PGV of each EQ entry.
    32, 33, 34, 35, 36, 37, 38, 39
};

// UNSET: vital, perv, ph5, pcs0, pcs1, pcs2, pcs3, psm0, psm1, pllpci, pma0,
//        pma1, pma2, pma3
const pg_entry_t VPD_CP00_PG_PCI_ALL_GOOD = 0xFFE00C1Fu;
// no always-good constant for PCI since it's not always-good for the chip

const pg_entry_t VPD_CP00_PG_PCI_INDEX[] =
{
    8, 9
};

// UNSET: vital, perv, pau0, tl, ioppe
const pg_entry_t VPD_CP00_PG_PAUC_SE_NE_ALL_GOOD = 0xFFE39FFFu;
// UNSET: vital, perv, pau0, pau1, tl, ioppe
const pg_entry_t VPD_CP00_PG_PAUC_SW_NW_ALL_GOOD = 0xFFE19FFFu;
// SET: perv, tl, ioppe
const pg_mask_t VPD_CP00_PG_PAUC_ALWAYS_GOOD_MASK = 0x00086000u;
const pg_idx_t VPD_CP00_PG_PAUC_INDEX[] = {
    16, 17, 18, 19
};

// UNSET: perv, ioo, pdl/odl, pllaxon
// (Note: Even though the PG documentation says that the "ndl" bit is
//        partial-good, it's actually always bad because we dropped NVLINK
//        support (and therefore NDL) on P10.)
const pg_entry_t VPD_CP00_PG_IOHS_ALL_GOOD = 0xFFE3BDFFu;

// UNSET: perv, mc_emo, dl01, dl23, ioo0, ioo1, pllmc
const pg_entry_t VPD_CP00_PG_MC_ALL_GOOD = 0xFFE21DFFu;

// The value representing an empty entry in the PGV
const uint32_t VPD_CP00_PG_RESERVED_GOOD    = 0xFFFFFFFFu;

// The two arrays below enumerate the set of all chiplets whose always-good bits
// are mandatory for baseline functionality (checked in isChipFunctional); if a
// chiplet in these arrays fails to pass the ALWAYS GOOD mask check, Hostboot
// cannot use the chip.

// The first contains the chiplet's index in the PGV of the PG data...
const pg_idx_t VPD_CP00_PG_ALWAYS_GOOD_INDEX[16] =
{
    VPD_CP00_PG_FSI_INDEX,
    VPD_CP00_PG_PRV_INDEX,
    VPD_CP00_PG_N0_INDEX,
    VPD_CP00_PG_N1_INDEX,
    VPD_CP00_PG_PAUC_INDEX[0],
    VPD_CP00_PG_PAUC_INDEX[1],
    VPD_CP00_PG_PAUC_INDEX[2],
    VPD_CP00_PG_PAUC_INDEX[3],
    VPD_CP00_PG_EQ_INDEX[0],
    VPD_CP00_PG_EQ_INDEX[1],
    VPD_CP00_PG_EQ_INDEX[2],
    VPD_CP00_PG_EQ_INDEX[3],
    VPD_CP00_PG_EQ_INDEX[4],
    VPD_CP00_PG_EQ_INDEX[5],
    VPD_CP00_PG_EQ_INDEX[6],
    VPD_CP00_PG_EQ_INDEX[7],
};

const size_t ALWAYS_GOOD_INDEX_SIZE = sizeof(VPD_CP00_PG_ALWAYS_GOOD_INDEX)
                                    / sizeof(VPD_CP00_PG_ALWAYS_GOOD_INDEX[0]);

// ...and the second contains the mask of bits which MUST be GOOD (0) for the
// part to be considered functional.
const pg_mask_t VPD_CP00_PG_ALWAYS_GOOD_MASKS[ALWAYS_GOOD_INDEX_SIZE] =
{
    VPD_CP00_PG_FSI_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_PRV_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_N0_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_N1_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_PAUC_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_PAUC_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_PAUC_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_PAUC_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK,
    VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK,
};

// This is a P10 Partial-Good Vector with every partial- and always-good bit
// unset, and every reserved bit set, used for tests.
// This is defined in this header because it is used by both hwas1test.H and by
// errludParser_pgData.H
// NOTE: Any changes to the Partial-Good Vector should be reflected in the createPGV()
// function found in src/build/tools/ebmc/vpdConstants.py
// @TODO RTC 249996 static_assert requires this to be constexpr
#ifdef __HOSTBOOT_MODULE
#define CONSTEXPR constexpr
#else
#define CONSTEXPR const
#endif
CONSTEXPR partialGoodVector pgDataAllGood =
{
    VPD_CP00_PG_FSI_ALL_GOOD,
    VPD_CP00_PG_PRV_ALL_GOOD,
    VPD_CP00_PG_N0_ALL_GOOD,
    VPD_CP00_PG_N1_ALL_GOOD,

    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,

    VPD_CP00_PG_PCI_ALL_GOOD,
    VPD_CP00_PG_PCI_ALL_GOOD,

    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,

    VPD_CP00_PG_MC_ALL_GOOD,
    VPD_CP00_PG_MC_ALL_GOOD,
    VPD_CP00_PG_MC_ALL_GOOD,
    VPD_CP00_PG_MC_ALL_GOOD,

    VPD_CP00_PG_PAUC_SE_NE_ALL_GOOD,
    VPD_CP00_PG_PAUC_SE_NE_ALL_GOOD,
    VPD_CP00_PG_PAUC_SW_NW_ALL_GOOD,
    VPD_CP00_PG_PAUC_SW_NW_ALL_GOOD,

    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,

    VPD_CP00_PG_IOHS_ALL_GOOD,
    VPD_CP00_PG_IOHS_ALL_GOOD,
    VPD_CP00_PG_IOHS_ALL_GOOD,
    VPD_CP00_PG_IOHS_ALL_GOOD,
    VPD_CP00_PG_IOHS_ALL_GOOD,
    VPD_CP00_PG_IOHS_ALL_GOOD,
    VPD_CP00_PG_IOHS_ALL_GOOD,
    VPD_CP00_PG_IOHS_ALL_GOOD,

    VPD_CP00_PG_EQ_ALL_GOOD,
    VPD_CP00_PG_EQ_ALL_GOOD,
    VPD_CP00_PG_EQ_ALL_GOOD,
    VPD_CP00_PG_EQ_ALL_GOOD,
    VPD_CP00_PG_EQ_ALL_GOOD,
    VPD_CP00_PG_EQ_ALL_GOOD,
    VPD_CP00_PG_EQ_ALL_GOOD,
    VPD_CP00_PG_EQ_ALL_GOOD,

    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
    VPD_CP00_PG_RESERVED_GOOD,
};

// There are no model-specific AG entries as yet.
const uint8_t MODEL_AG_DATA_ENTRIES = 0;

// @TODO 249996 - compiler for hb errlparser didn't support static_assert(C++11)
//                check if this is still the case.
#ifdef __HOSTBOOT_MODULE
// We need to initialize every element of our test PGV, and by default elements
// will be initialized to 0, so if the last element is 0 then we know that we
// used too few initializers. This will catch errors if the number of PGV
// entries increases in the future.
static_assert(pgDataAllGood.back() != 0,
              "pgDataAllGood has too few initializers");
#endif

// model_ag_entry represents a model-specific entry in the all-good AGV
struct model_ag_entry
{
    // The index in the AGV that this value is stored at
    uint32_t index;

    // The model-specific all-good value
    pg_entry_t value;
};

// model_ag_entries is used to hold model-specific all-good entries.
// It is used by the error log for Partial-Good issues (ErrlUdPartialGoodData)
// so that the parser can reconstruct an all-good AGV for a particular chip
// model when it prints expected vs. actual pg values.
typedef model_ag_entry model_ag_entries[MODEL_AG_DATA_ENTRIES];

// constants the platReadLx will use for looking at the VPD data
const uint32_t VPD_CRP0_LX_HDR_DATA_LENGTH       = 256;

const uint32_t VPD_CRP0_LX_FREQ_INDEP_INDEX      = 8;
const uint32_t VPD_CRP0_LX_PORT_DISABLED         = 0;

const uint8_t  VPD_CRP0_LX_MIN_X                 = 1;
const uint8_t  VPD_CRP0_LX_MAX_X                 = 8;

}

#endif // VPD_CONSTANTS_H
