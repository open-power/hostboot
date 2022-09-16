/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/vpd.H $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#ifndef __VPD_H
#define __VPD_H

#include <pnor/pnorif.H>
#include <vpd/vpd_if.H>
#include <vpd/ipvpdenums.H>
#include <map>

namespace VPD
{

/**
 * @brief This structure is used to transfer common information needed
 *      for reading the address from the PNOR RP.
 */
struct pnorInformation
{
    uint64_t segmentSize;
    uint64_t maxSegments;
    PNOR::SectionId pnorSection;
};

/**
 * @brief VPD Message Types
 */
enum VPD_MSG_TYPE
{
    VPD_INVALID       = 0x0000,
    // UNUSED message types are OLD and should probably NOT
    // be recycled since disablement was NOT performed across
    // the stack (HWSV/HB, etc).
    //
    //VPD_WRITE_DIMM    = 0x00C1, // UNUSED < DIMM SPD
    //VPD_WRITE_PROC    = 0x00C2, // UNUSED < Processor MVPD
    // Hole in mapping
    //VPD_WRITE_NODE    = 0x00C4, // UNUSED < Planar VPD
    //VPD_WRITE_MCS     = 0x00C5, // UNUSED < Direct access memory VPD
    VPD_WRITE_CACHE   = 0x00C6, //< VPD cache write update
};

/**
 * @brief Message definition for VPD Write Request
 *
 * - data0 :
 *   - [32] targetHUID
 *   - [16] offset
 *   - [16] unused
 * - data1 :
 *   - [64] Size of binary extra data in bytes
 *
 *   VpdWriteMsg_t total size 2 x uint64_t = 16 bytes
 *
 * Reference Only for Extra Data usage
 *   Extra Data bundled in msg_t and seeded in VpdWriteMsgHBRT_t
 *   - see vpdData in VpdWriteMsgHBRT_t
 *   - extra data : Binary VPD Data
 * See msg.h for msg_t layout
 */
union VpdWriteMsg_t
{
    struct
    {
        // data[0]
        uint32_t targetHUID;
        uint16_t offset;
        uint16_t data0_unused;
        // data[1]
        uint64_t extra_payload_bytes; // payload size
          // even though this is a large number, the
          // various other code that gets this passed
          // around uses size_t so we keep this
          // as uint64_t
    } PACKED;
    uint64_t data[2]; // msg_t overlay
} PACKED;

/**
 * first = 4-character record name as a 4-byte uint
 * second = Target pointer
 */
typedef std::pair<uint32_t, TARGETING::Target*> RecordTargetPair_t;

/**
 * @brief Helper function to convert record string to uint
 * @param[in]  4-character record string
 * @param[in]  Target pointer
 * @return  Fully formed RecordTargetPair_t
 */
inline RecordTargetPair_t makeRecordTargetPair( const char* i_rec,
                                                TARGETING::Target* i_targ )
{
    uint32_t l_rec = 0;
    memcpy( &l_rec, i_rec, sizeof(l_rec) );
    return std::make_pair(l_rec,i_targ);
};


/**
 *  Indexed by RecordTargetPair_t
 *  Returns a pointer to this record within the override section
 *   if it is being used, or nullptr if not.
 */
typedef std::map<RecordTargetPair_t,uint8_t*> OverrideMap_t;



/**
 * @brief This function handles sending the mailbox message to the Fsp to
 *      notify of updates to the data.
 *
 * @param[in] i_numbytes - Number of bytes to read.
 *
 * @param[in] i_data - The data buffer that will return the data read.
 *
 * @param[in] i_target - The target to access.  The msg_t payload
 *     built and sent via MBOX will be populated with this target HUID.
 *
 * @param[in] i_type - The type of VPD being written.
 *
 * @param[in] io_record - The record/keyword.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t sendMboxWriteMsg ( size_t i_numBytes,
                              void * i_data,
                              TARGETING::Target * i_target,
                              VPD_MSG_TYPE i_type,
                              VpdWriteMsg_t& io_record );

/**
 * @brief Structure to describe the relation between a FRU property
 *        (represented by the corresponding attribute) and the
 *        record+keyword combination that stores it.
 */
struct FruPropertyLocation_t
{
    const TARGETING::ATTRIBUTE_ID name;
    vpdRecord record;
    vpdKeyword keyword;
    FruPropertyLocation_t( TARGETING::ATTRIBUTE_ID i_name ) :
      name(i_name),
    record(IPVPD::INVALID_RECORD),
    keyword(IPVPD::INVALID_KEYWORD) {};
};

/**
 * @brief This function returns the correct record/keyword combinations
 *        for the requested FRU properties..
 * @param[in] i_target - target to get the data for
 * @param[in] i_type - type of target (PROC/DIMM/NODE/etc)
 * @param[in/out] io_locs - input: List of properties to fetch,
 *                        - output: Associated records+keywords
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *                error log.
 */
errlHndl_t getFruRecordsAndKeywords( TARGETING::Target * i_target,
                                     TARGETING::TYPE i_type,
                                     std::vector<FruPropertyLocation_t>& io_locs );

/**
 * Define useful constants for VPD code
 */

// default invalid value for ATTR_VPD_REC_NUM
constexpr TARGETING::ATTR_VPD_REC_NUM_type INVALID__ATTR_VPD_REC_NUM = 0xFFFF;

}; //end VPD namespace
#endif
