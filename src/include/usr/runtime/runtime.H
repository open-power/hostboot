/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/runtime.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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

#ifndef __RUNTIME_H
#define __RUNTIME_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <targeting/common/targetservice.H>
#include <hdat/hdat.H>
#include "../../../src/usr/runtime/hdatstructs.H"
#include <vmmconst.h>
#include <sys/misc.h>
#include <arch/memorymap.H>
#include <kernel/vmmmgr.H>


namespace RUNTIME
{

    /******************************************************************************/
    // Globals/Constants
    /******************************************************************************/
    constexpr uint8_t HB_SBE_WAITING_FOR_MSG = 0x0;
    constexpr uint8_t HB_SBE_MSG_DONE = 0x1;
    constexpr uint32_t MAX_TIME_ALLOWED_MS = 10000;
    // NUMBER_OF_POSSIBLE_DRAWERS definition here should be in sync with
    // src/usr/isteps/istep18/establish_system_smp.H's definition of the same constant.
    constexpr uint8_t NUMBER_OF_POSSIBLE_DRAWERS = 8;
    constexpr uint8_t CONTINUE_WAIT_FOR_MSGS = 0x2;
    constexpr uint8_t TIME_EXPIRED=0x3;



/**
    *  enum used for sending messages within sendSBEsystemConfig
    */
    enum
    {
        HB_SBE_SYSCONFIG_TIMER_MSG =   0xA2,
    };
/**
 * @brief  Add the host data mainstore location to VMM
 *
 * @description  If running with the standard PHYP payload this function
 *    will map all supported HDAT sections into the VMM to allow access
 *    from user space.  When running in standalone (no payload) mode,
 *    some reserved memory will be mapped in for testcases.  If AVPs are
 *    enabled, no memory will be mapped and the PAYLOAD_KIND attribute
 *    will be set appropriately.
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t load_host_data( void );

/**
 * @brief Populate HB runtime data in mainstore
 *
 * @return errlHndl_t NULL on Success
 */
errlHndl_t populate_hbRuntimeData( void );

/**
 * @brief Populate node attributes in mainstore for HostServices
 *
 * @return errlHndl_t NULL on Success
 */
errlHndl_t populate_HbRsvMem( uint64_t i_nodeNum, bool i_master_node = false );

/**
 * @brief persistent read/write Attribute validity runtime check
 *
 * @description In order to ensure validity of persistent read/write
 *    attributes, perform a check of enum values and integer ranges
 *    to ensure validity, while pinning attribute memory to ensure
 *    that PNOR cannot change the attributes prior to the copy to
 *    reserve memory.
 *
 * @return errlHndl_t nullptr on Success else pointer to error log
 */
errlHndl_t persistent_rwAttrRuntimeCheck( void );

/**
 * @brief Populate HB secureboot data in mainstore
 *
 * @description  Populates the System Parameters section of HDAT with
 *     values acquired via the secureboot module from a verified source, and
 *     so, henceforth are available to the host at runtime.
 *
 * @return errlHndl_t nullptr on Success else pointer to error log
 */
errlHndl_t populate_hbSecurebootData( void );

/**
 * @brief Populate TPM Info in mainstore
 *
 * @description Populates the Secure Boot TPM Instance Info section of HDAT
 *     with trusted information acquired via secure methods, and overwrites
 *     any untrusted information that was already there.
 *
 * @return errlHndl_t nullptr on Success else pointer to error log
 */
errlHndl_t populate_hbTpmInfo( void );

/**
 * @brief Fills in Tpm Info in HDAT for node passed in to the specified HDAT
 *        instance
 *
 * @param[in]  i_instance - the instance number to use to populate the current
 *                      node's data into HDAT, as directed by the master node.
 *                      This function is typically called upon receiving a
 *                      message of type IPC_POPULATE_TPM_INFO_BY_NODE, which
 *                      provides the instance to use as an MBOX parameter. Each
 *                      node must have a unique instance number, but beyond that
 *                      there is no guaranteed direct correlation between nodes
 *                      and instances at all.
 *
 * @return errlHndl_t nullptr on success else pointer to error log
 */
errlHndl_t populate_TpmInfoByNode(const uint64_t i_instance);

/**
 * @brief Timer function for safe error handling in sendSBESystemConfig
 *
 * @description Used inside the sendSBEsystemConfig() to wait for
 *  responses from other nodes
 * @param[in]  i_msgQPtr -- Pointer to the Message Queue to wait for messages
 *
 * @return void
 */
void* sendSBEsystemConfig_timer(void* i_msgQPtr);

/**
 * @brief Waits and Collects responses from all drawers
 *
 * @description Used inside the sendSBEsystemConfig() to wait and
 * collect responses from other nodes
 * @param[in]  i_msgQPtr -- Pointer to the Message Queue to wait for messages
 * @param[in]  i_msgCount -- Number of messages to wait for
 * @param[in]  i_msgType -- Type of the message to wait for
 * @param[in, out]  i_systemFabricConfigurationMap -- to consolidate node info from all nodes
 *
 * @return void
 */
errlHndl_t collectRespFromAllDrawers( void* i_msgQPtr, uint64_t i_msgCount, uint32_t i_msgType, uint64_t& i_systemFabricConfigurationMap );

/**
 * @brief Sends the chip config down to the SBEs
 *
 * @description Determines the system wide chip information to send to
 *  the SBE so it knows which chips are present for syncing with in MPIPL.
 *  Uses IPC to communication between HB instances if multinode
 *
 * @return errlHndl_t nullptr on success else pointer to error log
 */
errlHndl_t sendSBESystemConfig();


// How many pointers/sections there are in HB runtime data
#define HBRT_NUM_PTRS        2
// Sections defined by above literal
#define HBRT_VPD_SECTION     0
#define HBRT_ATTRIB_SECTION  1

// How many pointers/sections there are in HB reserved memory data
// HOMER*8/OCC_Common/VPD/ATTR/HBRT_Image/Res/Res/Res
// should be the same as HDAT_RHB_MAX_RANGE_ENTRIES_PER_NODE in
// src/hdat/fsp/hdat.H
#define HB_RSV_MEM_NUM_PTRS  80

//Note this means the Reserved Mem sub-section is the 6th
//(0 based) of the MDT section (See HDAT spec 11.1.1)
#define MDT_MAINSTORE_ADDR_SECTION   0
#define MDT_RESERVED_HB_MEM_SECTION  5

// Defines offset into mainstore address section where HB writes the address
// of the HYP/HB comm area
// (See HDAT spec 11.1.2.1 Mainstore Address Configuration)
#define MDT_MAINSTORE_ADDR_SECTION_HYP_HB_COMM_ADDR_OFFSET 0x1C
// Defines amount of bytes set aside for HB to write the address
// of the HYP/HB communication area address space
// (See HDAT spec 11.1.2.1 Mainstore Address Configuration)
#define MDT_MAINSTORE_ADDR_SECTION_HYP_HB_COMM_ADDR_SIZE   0x8

/**
 * HDAT Sections
 */
enum SectionId
{
    FIRST_SECTION,        //< Placeholder for arrays
    HSVC_NODE_DATA = FIRST_SECTION, //< HostServices Node Attributes
    HSVC_SYSTEM_DATA,     //< HostServices System Attributes
    IPLPARMS_SYSTEM,      //< IPL Parms
    MS_DUMP_SRC_TBL,      //< MDST: Memory Dump Source Table
    MS_DUMP_DST_TBL,      //< MDDT: Memory Dump Destination Table
    MS_DUMP_RESULTS_TBL,  //< MDRT: Memory Dump Results Table
    SPIRA_S,              //< SPIRA-S
    SPIRA_H,              //< SPIRA-H
    SPIRA_L,              //< Legacy SPIRA
    NACA,                 //< NACA
    HBRT,                 //< Hostboot Runtime
    HBRT_DATA,            //< Hostboot Runtime Data
    PCRD,                 //< Processor Chip Related Data
    IPMI_DATA,            //< IPMI Sensor Mapping Data
    NODE_TPM_RELATED,     //< Node TPM Related Data
    RESERVED_MEM,         //< Hostboot's Reserved Mainstore Memory
    HRMOR_STASH,          //< Pointer to address in reserved memory
                          //  where PHYP can write HRMOR
    CPU_CTRL,             // Spira-H CPU controls area
    PROC_DUMP_AREA_TBL,   //< Processor dump area table
    LAST_SECTION = PROC_DUMP_AREA_TBL   //< Placeholder for arrays
};

/**
 * Range of SBE unsecure memory region to open
 */
enum SbeUnsecureMemoryRegions
{
    SP_HOST_UNTRUSTED_COMM_AREA_SIZE = 64*MEGABYTE,
    SP_HOST_UNTRUSTED_OPAL_TRACE_ADDR = 0x31000000,
    SP_HOST_UNTRUSTED_OPAL_TRACE_SIZE = 1*MEGABYTE,

    SP_HOST_ATTN_SIZE_LIMIT = (PHYP_ATT_AREA_SIZE),
};

/**
 * @brief  Get a pointer to the beginning of a particular section of
 *         the host data memory.
 *
 * @description  The returned pointer will not include any header hdat header
 *     information.
 *
 * @param[in] i_section  Chunk of data to find
 * @param[in] i_instance  Instance of section when there are multiple entries
 * @param[out] o_dataAddr  Physical memory address of data
 * @param[out] o_dataSize  Size of data in bytes, 0 on error, DATA_SIZE_UNKNOWN if unknown
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t get_host_data_section( SectionId i_section,
                                  uint64_t i_instance,
                                  uint64_t& o_dataAddr,
                                  size_t& o_dataSize);
const size_t DATA_SIZE_UNKNOWN = 0xFFFFFFFFFFFFFFFF;

/**
 * @brief  Clear section of host data memory one instance at a time.
 *
 * @param[in] i_section  Chunk of data to clear
 *
 * @return errlHndl_t  nullptr on success, pointer to error log on failure
 */
errlHndl_t clear_host_data_section(const RUNTIME::SectionId i_section);

/**
 * @brief Get the number of instances in a given section.
 *
 * @param[in] i_section The section for which the instance count is desired
 *
 * @param[out] o_count The number of instances in this section
 *
 * @return errlHndl_t Returns nullptr on success; otherwise errlog
 */
errlHndl_t get_instance_count( const SectionId i_section, uint64_t& o_count);

/**
 * @brief  Store the actual count of a section in local memory.
 *
 * @param[in] i_section  Chunk of data to update
 * @param[in] i_count   Actual number of entries
 *
 */
void saveActualCount( SectionId i_id,
                      uint16_t i_count );

/**
 * @brief  Write the stored actual count to SPIRA
 *
 * @param[in] i_section  Chunk of data to update
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t writeActualCount( SectionId i_id );

/**
 * @brief  Write actual architected register detail to HDAT/SPIRAH
 *
 * @param[in] i_section        Chunk of data to update
 * @param[in] threadRegSize    Architected reg data size per thread
 * @param[in] threadRegVersion Data format version
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t updateHostProcDumpActual( SectionId i_section,
                                     uint32_t threadRegSize,
                                     uint8_t threadRegVersion);

/**
 * @brief  Use relocated payload base address
 *
 * @param[in] val  'true' for post dump data collection
 */
void useRelocatedPayloadAddr(bool val);

/**
 * @brief  Retrieve and log FFDC data relevant to a given section of
 *         host data memory
 *
 * @param[in] i_section  Relevant section
 * @param[inout] io_errlog  Log to append FFDC to
 *
 * @return errlHndl_t  NULL on success
 */
void add_host_data_ffdc( SectionId i_section,
                         errlHndl_t& io_errlog );

/**
 * @brief Set the PAYLOAD_BASE attribute
 * @param[in] i_payloadAddress in MEGABYTES
 */
void setPayloadBaseAddress(uint64_t i_payloadAddress);

/**
 * @brief Clear out any cached data and rediscover the location
 *        of the HDAT memory
 */
void rediscover_hdat( void );

/**
 * @brief  Open necessary unsecure SBE windows for SP -> host communication
 *         Currently opens three windows
 *             1. CPU controls SP ATTN areas
 *             2. SP_HOST_UNTRUSTED_COMM_AREA_ADDR
 *             3. SBE FFDC
 * @param[in] i_commBase The lowest addressable location in the system,
 *            derived from the HRMOR of the master node.
 *
 * @return errlHndl_t Returns nullptr on success; otherwise errlog
 */
errlHndl_t openUntrustedSpCommArea(uint64_t i_commbase);

/**
 * @brief Locates the offset of the HDAT structure as directed by the PAYLOAD
 *
 * Walks the NACA in the PAYLOAD to find the SpiraH structure.  The SpiraH
 * structure contains the offset to the SpiraS structure which is where the
 * PAYLOAD expects the HDAT structure to be placed.
 *
 * @param[in] payloadBase_va - Virtual Address pointing to start of PAYLOAD
 * @param[out] o_hdat_offset - Offset of HDAT Location from start of PAYLOAD
 * @param[out] o_hdat_size   - Size of HDAT Location reserved by PAYLOAD
 */
void findHdatLocation(uint64_t payloadBase_va,
                      uint64_t& o_hdat_offset,
                      size_t& o_hdat_size);

/**
 * @brief Finds the Rsvd Mem Trace Buffer section and returns the address and
 *        size of the section
 *
 * @param[out] o_RsvdMemAddress - tarting address of the Rsvd Mem Trace Buffer section
 * @param[out] o_size - Size of the Rsvd Mem Trace Buffer section
 * @return errlHndl_t Returns nullptr on success; otherwise errlog
 */
errlHndl_t getRsvdMemTraceBuf(uint64_t& o_RsvdMemAddress, uint64_t& o_size);

/**
 * @brief Returns the physical address of SP ATTN area 1.
 *
 * @param[out] o_payloadTiAddr the output address of the first SP ATTN area;
 *             zero in case of an error.
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t getPayloadAttnAreaAddr(uint64_t& o_payloadTiAddr);


/**
 *  @brief Returns the HB base address relative to the current node.
 *         The address returned takes memory mirroring mode into
 *         account.
 *  @return Base address of this instance of hostboot relative to
 *          the current node.
 */
inline uint64_t getHbBaseAddr()
{
    const auto sys = TARGETING::UTIL::assertGetToplevelTarget();
    const auto mirror_base = sys->getAttr<TARGETING::ATTR_PAYLOAD_IN_MIRROR_MEM>() ?
                              sys->getAttr<TARGETING::ATTR_MIRROR_BASE_ADDRESS>() : 0;
    // ignore the node offset
    const auto hrmor_offset = cpu_spr_value(CPU_SPR_HRMOR) & ~MEMMAP::NODE_OFFSET_MASK;

    // If a non-zero mirror_base found then we need to return a
    // mirrored address. To calculate hostboot's mirrored base
    // address you take the hrmor divided in half and offset
    // by the mirrored base.
    return mirror_base ? (hrmor_offset / 2) + mirror_base : hrmor_offset;
}

/**
 *  @brief Returns the HB base address relative to the entire system.
 *         The returned address will include the node offset.
 *         The address returned takes memory mirroring mode into
 *         account.
 *  @return Base address of this instance of hostboot relative to the system.
 */
inline uint64_t getHbBaseAddrWithNodeOffset()
{
      return getHbBaseAddr() | cpu_hrmor_nodal_base();
}

/**
 *  @brief Calculates the node's proposed start address for the system's
 *         SP ATTN areas, which becomes the effective configuration if it's
 *         elected as the master.
 *
 *  @return uint64_t Absolute start address for the intended SP ATTN areas
 */
inline uint64_t calcSpAttnAreaStart()
{
    return  (getHbBaseAddrWithNodeOffset() + PHYP_ATTN_AREA_OFFSET) | VmmManager::FORCE_PHYS_ADDR;
}

/*
 * @brief Verify PAYLOAD and move PAYLOAD + HDAT to proper location
 *
 * @param[in] i_payloadAlreadyVerified Whether the payload has already
 *     been verified and measurement extended to TPM, or not.
 *
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t verifyAndMovePayload(bool i_payloadAlreadyVerified = false);

/**
 * @brief Get the Logical Memory Block (LMB) size in megabytes.
 *
 * @return uint64_t Currently configured LMB size, in megabytes
 */
inline uint64_t getLMBSizeInMB()
{
    //@TODO: RTC 142465 missing attribute ATTR_LMB_SIZE
    //@TODO RTC 245661 to get from pldm bios
    // We hardcode this to 256 right now (see hdatGetIplParmsData)
    return 256;
}

} // namespace RUNTIME

#endif
