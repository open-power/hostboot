/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_ringId.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef _P10_RINGID_H_
#define _P10_RINGID_H_

#ifdef WIN32
    #include "win32_stdint.h"
#else
    #include <stdint.h>
    #include <stddef.h>
#endif
#include <p10_ring_id.H>
#include <common_ringId.H>

//******************************************************************************
//
// Rules for the two ringId header files, and MVPD renewal policy
// ==============================================================
//
// p10_ring_id.H
// =============
// - The ring IDs are grouped in MVPD and EKB (HW image) rings
// - NUM_RING_IDS_MVPD and NUM_RING_IDS_EKB sums up the number of rings in each
//   group, including holes.
// - NUM_RING_IDS at the end of the enum list is the sum of the above two IDs.
// - If a ring is **removed** from the master ring table, this will result in a
//   hold in the ringID enum list at the corresponding ring. It will and must be
//   marked as "// invalid_ring" so that the tool can recognize it.
// - If a ring is **added** to the master ring table, the ring must be appended
//   to **the end** of the ring group it belongs to (unless special
//   circumstances exist - coordinate with infrastructure team).
// - To allow the MVPD group to expand without affecting the ringId sequence of
//   the EKB rings, the beginning of the EKB ring group is pushed out to
//   RINGID_START_EKB.
//
// p10_ring_properties.H
// =====================
// - RING_TABLE_VERSION_MVPD and RING_TABLE_VERSION_EKB **must** be updated to
//   the version of the processed master ring table, RING_TABLE_VERSION_DOC when
//   one of the following conditions is satisfied:
//   - Addition of a new ring.
//   - A change in a ring's scanScomAddr.
//   - A change to the ringId sequence of existing rings.
//
// MVPD renewal policy
// ===================
// - A new MVPD **should only** be produced when one of the following conditions
//   is satisfied:
//   - Addition of a new ring to the MVPD ring group.
//   - A change in an MVPD ring's scanScomAddr.
//   - A change to the MVPD group's ringId sequence.
//
// Notes
// =====
// - If a ring is removed, from say the MVPD rings, it will leave behind a
//   "hole" in the code's ringId lists. Therefore, from a code perspective,
//   that ring no longer exists and can no longer be scanned or manipulated in
//   any way. Therefore, it also cannot be referenced by the code and for that
//   reason it is safe to leave any ring content for that ring in the already
//   existing MVPD.  In other words, there's no need to have the MVPD updated
//   to remove the ring since it can do no harm.  And for this reason we
//   **do not** update the RING_TABLE_VERSION_MVPD (or _EKB) and thus we do
//   not need to update the MVPD either.
// - The ring table version that is programmed into the TOR header is the larger
//   of the MVPD and EKB ring table versions since this will carry through to
//   the customized SBE and QME ring sections which will also contain the MVPD
//   rings. This ring table version is calculated and returned by the function,
//   ringid_get_ring_table_version_hwimg().
//
//******************************************************************************


enum Chiplets
{
    PERV_TYPE,
    N0_TYPE,
    N1_TYPE,
    PCI_TYPE,
    MC_TYPE,
    PAU0_TYPE,
    PAU1_TYPE,
    PAU2_TYPE,
    PAU3_TYPE,
    AXON0_TYPE,
    AXON1_TYPE,
    AXON2_TYPE,
    AXON3_TYPE,
    AXON4_TYPE,
    AXON5_TYPE,
    AXON6_TYPE,
    AXON7_TYPE,
    EQ_TYPE,
    SBE_NUM_CHIPLETS
};

const ChipletType_t QME_NUM_CHIPLETS = 1;

#include "p10_ring_properties.H"


//
// ringid_convert_ringId_to_ringIndex()
//
// This function converts the enum ringId to the contiguous ringIndex that
// we need for looking up ring metadata in the RING_PROPERTIES list.  Since
// we have a gap between the MVPD and EKB group of rings in the main enum
// ringId list, and since we cannot have a huge gap of empty entries in
// the RING_PROPERTIES list as that would be a waste of Seeprom space, we
// convert here the ringId into the ring properties (rp) index, rpIndex.
//
static inline const RingId_t  ringid_convert_ringId_to_rpIndex( RingId_t  i_ringId )
{
    if ( i_ringId >= RINGID_START_MVPD && i_ringId <= RINGID_END_MVPD )
    {
        return  i_ringId - RINGID_START_MVPD + RING_INDEX_START_MVPD;
    }
    else if ( i_ringId >= RINGID_START_EKB  && i_ringId <= RINGID_END_EKB )
    {
        return  i_ringId - RINGID_START_EKB + RING_INDEX_START_EKB;
    }
    else
    {
        return  UNDEFINED_RING_ID;
    }
}


static inline const char* ringid_get_ring_name(RingId_t i_ringId)
{
#ifdef __PPE__
    return "";
#else

    if ( i_ringId >= RINGID_START_MVPD && i_ringId <= RINGID_END_MVPD )
    {
        return RING_PROPERTIES[i_ringId - RINGID_START_MVPD + RING_INDEX_START_MVPD].ringName;
    }
    else if ( i_ringId >= RINGID_START_EKB  && i_ringId <= RINGID_END_EKB )
    {
        return RING_PROPERTIES[i_ringId - RINGID_START_EKB + RING_INDEX_START_EKB].ringName;
    }
    else
    {
        return "INVALID RING ID";
    }

#endif
}

// Returns data structure assocated with chipletType
int ringid_get_chiplet_properties(
    ChipletType_t      i_chipletType,
    ChipletData_t**    o_chipletData);

#endif
