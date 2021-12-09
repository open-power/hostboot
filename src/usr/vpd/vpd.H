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
 * @brief This function is used to query the attribute code to get the VPD
 *      Location value for the target provided.
 *
 * @param[out] o_vpdLocation - The value of the VPD Location attribute.
 *
 * @param[in] i_target - The target to query.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *      Error log.
 */
errlHndl_t getVpdLocation ( int64_t & o_vpdLocation,
                            TARGETING::Target * i_target );


/**
 * @brief This function will query the PNOR RP to get the offset of the
 *      section requested.  It will then set global variables to save this
 *      value away for later use.  This function only needs to be called once.
 *
 * @param[in] i_pnorInfo - Structure of common PNOR information needed to
 *      query for the sections address.
 *
 * @param[in] i_instance -Reserved memory instance (Hostboot Runtime only).
 *
 * @param[in/out] io_cachedAddr - This parameter is a gloval variable in the
 *      calling code.  It is the address that is obtained from the PNOR
 *      RP.
 *
 * @param[in] i_mutex - The Mutex from the calling code.  It is locked when
 *      the globals are modified.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *      Error log.
*/
errlHndl_t getPnorAddr ( pnorInformation & i_pnorInfo,
#ifdef __HOSTBOOT_RUNTIME
                         uint8_t i_instance,
#endif
                         uint64_t &io_cachedAddr,
                         mutex_t * i_mutex );

/**
 * @brief This function will read the PNOR at the correct offset and number of
 *      bytes for the keyword requested.
 *
 * @param[in] i_byteAddr - The offset to access in the PNOR.
 *
 * @param[in] i_numBytes - Number of bytes to read.
 *
 * @param[out] o_data - The data buffer that the read data will be placed
 *      into.
 *
 * @param[in] i_target - The chip target to access the data for.
 *
 * @param[in] i_pnorInfo - Information about the PNOR section that we need to
 *      know to make the request.
 *
 * @param[in/out] io_cachedAddr - The address offset to the data chunk in
 *      PNOR.
 *
 * @param[in] i_mutex - The mutex to lock/unlock while setting io_isAddrCached
 *      and io_cachedAddr.  It is assumed that those parameters are global
 *      variables in the code where they reside.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t readPNOR ( uint64_t i_byteAddr,
                      size_t i_numBytes,
                      void * o_data,
                      TARGETING::Target * i_target,
                      pnorInformation & i_pnorInfo,
                      uint64_t &io_cachedAddr,
                      mutex_t* i_mutex );

/**
 * @brief This function will write the PNOR at the correct offset and number
 *      of bytes for the keyword requested.
 *
 * @param[in] i_byteAddr - The offset to access in the PNOR.
 *
 * @param[in] i_numBytes - The number of bytes to write.
 *
 * @param[in] i_data - The data buffer of the data to be written.
 *
 * @param[in] i_target - The chip target to access the data for.
 *
 * @param[in] i_pnorInfo - Information about the PNOR section that we need to
 *      know to make the request.
 *
 * @param[in/out] io_cachedAddr - The address offset to the data chunk in
 *      PNOR.
 *
 * @param[in] i_mutex - The mutex to lock/unlock while setting io_isAddrCached
 *      and io_cachedAddr.  It is assumed that those parameters are global
 *      variables in the code where they reside.
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t writePNOR ( uint64_t i_byteAddr,
                       size_t i_numBytes,
                       void * i_data,
                       TARGETING::Target * i_target,
                       pnorInformation & i_pnorInfo,
                       uint64_t &io_cachedAddr,
                       mutex_t* i_mutex );

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
 * @brief This function determines the VPD source (PNOR/SEEPROM)
 *      from configuration and target state information
 *
 * @param[in] i_target - Target device.
 *
 * @param[in] i_rwPnorEnabled - Config value specifying
 *      whether PNOR reads/writes are enabled for this VPD type
 *
 * @param[in] i_rwHwEnabled - Config value specifying
 *      whether SEEPROM reads/writes are enabled for this VPD type
 *
 * @param[in] i_location - The requested VPD source location
 *      (PNOR/SEEPROM) from the caller
 *
 * @param[out] o_source - The resolved VPD source to be accessed
 *
 * @return bool - True if bad config detected otherwise False
 */
bool resolveVpdSource( TARGETING::Target * i_target,
                       bool i_rwPnorEnabled,
                       bool i_rwHwEnabled,
                       vpdCmdTarget i_vpdCmdTarget,
                       vpdCmdTarget& o_vpdSource );

/**
 * @brief This function sets the correct record/keyword combinations
 *        for the part and serial numbers.
 * @param[in] i_target - target to get the data for
 * @param[in] i_type - type of target (PROC/DIMM/NODE/etc)
 * @param[in/out] io_record - record for target
 * @param[in/out] io_keywordPN - the part number keyword
 * @param[in/out] io_keywordSN - the serial number keyword
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *                error log.
 */
errlHndl_t getPnAndSnRecordAndKeywords( TARGETING::Target * i_target,
                                        TARGETING::TYPE i_type,
                                        vpdRecord & io_record,
                                        vpdKeyword & io_keywordPN,
                                        vpdKeyword & io_keywordSN );

/**
 * @brief This function sets the correct record/keyword combinations
 *        for the ccin.
 * @param[in] i_target - target to get the data for
 * @param[in] i_type - type of target (PROC/DIMM/NODE/etc)
 * @param[in/out] io_record - record for target
 * @param[in/out] io_keywordCC - the CCIN keyword
 *
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to the
 *                error log.
 */
errlHndl_t getCcinRecordAndKeywords( TARGETING::Target * i_target,
                                     TARGETING::TYPE i_type,
                                     vpdRecord & io_record,
                                     vpdKeyword & io_keywordCC );

/**
 * Define useful constants for VPD code
 */

// default invalid value for ATTR_VPD_REC_NUM
constexpr TARGETING::ATTR_VPD_REC_NUM_type INVALID__ATTR_VPD_REC_NUM = 0xFFFF;

}; //end VPD namespace
#endif
