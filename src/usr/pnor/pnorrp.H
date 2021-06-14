/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnorrp.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
/* [+] Google Inc.                                                        */
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
#ifndef __PNOR_PNORRP_H
#define __PNOR_PNORRP_H
#include <pnor/pnorif.H>
#include <sys/msg.h>
#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <vmmconst.h>
#include <map>
#include "pnor_common.H"
#include "ffs.h"
#include "pnor_utils.H"

#ifdef CONFIG_FILE_XFER_VIA_PLDM
#include <openbmc/pldm/oem/ibm/libpldm/file_io.h>
#endif

/**
 * PNOR Resource Provider
 */
namespace PNOR
{
    // used to register for the hostboot shutdown
    // notification messages.
    enum msg_type
    {
        MSG_NOT_USED = 0x00,
        MSG_SHUTDOWN = 0x01,
    };
};
class PnorRP
{
  public:
    /**
     * @brief Static Initializer
     * @param[in]  ref to errlHndl_t
     */
    static void init( errlHndl_t &io_rtaskRetErrl );

    /**
     * @brief Returns information about a given side of pnor
     *        (Called by an external interface PNOR::getSideInfo())
     * @param[in]  i_side PNOR side
     * @param[out] o_info side information
     *
     * @return errlHndl_t Error log if request was invalid
     */
    errlHndl_t getSideInfo (PNOR::SideId i_side, PNOR::SideInfo_t& o_info);

    /**
     * @brief  Return the size and address of a given section of PNOR data
     *    Called by external PNOR::getSectionInfo()
     *
     * @param[in] i_section  PNOR section
     * @param[out] o_info  Location and size information
     *
     * @return errlHndl_t  Error log if request was invalid
     */
    errlHndl_t getSectionInfo( PNOR::SectionId i_section,
                               PNOR::SectionInfo_t& o_info );

#ifndef __HOSTBOOT_RUNTIME
    /**
     *  @brief Returns whether requested section is available or not
     *
     *  @par Detailed Description:
     *      Returns whether requested section is available or not.  Resource
     *      provider must be functional, section ID must be valid, section must
     *      not be inhibited by secure boot, and section must exist in the PNOR
     *      to be considered available.
     *
     *  @param[in] i_section PNOR section to check for availability
     *
     *  @return boolean Whether section is available or not
     *  @retval true Section is available
     *  @retval false Section is not available
     */
    bool isSectionAvailable(PNOR::SectionId i_section);
#endif

    /**
     * @brief  Clears the specified PNOR section with all FF's (w/ good ECC)
     *
     * @param[in] i_id  PNOR section to clear
     *
     * @return Error if fails
     */
    errlHndl_t clearSection(PNOR::SectionId i_section);

    /**
     * @brief Checks and fixes correctable ECC for a given PNOR section
     *
     * @param[in] i_id  PNOR section to clear
     *
     * @return Error if fails
     */
    errlHndl_t fixECC(PNOR::SectionId i_section);

    /**
     * @brief  Get TOC offset of specified TOC and side
     *
     * @param[in] i_toc     TOC id of the TOC requested
     *
     * @return uint64_t     TOC offset
     */
    uint64_t getTocOffset(PNOR::TOCS i_toc) const;

    /**
     * @brief  Trace out which pages we loaded more than i_threshold times,
     *         then optionally clear the list.
     *
     * @param[in] i_threshold  Threshold to trace results
     * @param[in] i_clear  Set true to clear the list [default=true]
     */
    void readAndClearCounter( uint32_t i_threshold,
                              bool i_clear = true );
#ifdef CONFIG_FILE_XFER_VIA_PLDM
    /**
     * @brief Return a const ref to the iv_ipltime_lid std:array
     * @return a const ref to the iv_ipltime_lid member variable.
     */
    const std::array<uint32_t, PNOR::NUM_SECTIONS>& get_lid_ids() const
    {
        return this->iv_ipltime_lid_ids;
    }
#endif

  protected:
    /**
     * @brief  Constructor, default TOC offsets to side A
     */
    PnorRP();

    /**
     * @brief  Destructor
     */
    ~PnorRP();


  private:

    /*
     * Stores primary and backup TOCs for each side of PNOR
     */
    typedef std::pair<uint64_t, uint64_t> TocOffsets_t;
    TocOffsets_t iv_TocOffset [PNOR::NUM_SIDES];
#ifdef CONFIG_FILE_XFER_VIA_PLDM
    std::array<uint32_t, PNOR::NUM_SECTIONS> iv_ipltime_lid_ids;
#endif

    enum
    {
        BASE_VADDR = VMM_VADDR_PNOR_RP, /**< 2GB = 0x80000000*/
#ifndef CONFIG_FILE_XFER_VIA_PLDM
        TOTAL_SIZE = 64*MEGABYTE, /**< Allocate 64 MB (0x4000000)*/
#else
        TOTAL_SIZE = VMM_SIZE_RESERVED_PER_SECTION*PNOR::NUM_SECTIONS,
#endif
        LAST_VADDR = BASE_VADDR + TOTAL_SIZE,  /**< End of our VA range */
    };

    /**
     * Which TOC (0 or 1) is used after verifying both.
     */
    PNOR::TOCS iv_TOC_used;

    /**
     * Flash statistics
     */
    struct FlashStats_t {
        uint8_t numWrites;  /**< Number of writes to this page */
        uint8_t numCEs;  /**< Number of ECC corrections made */
    };

    /**
     * Stores information about all sides of PNOR
     */
    PNOR::SideInfo_t iv_side[PNOR::NUM_SIDES];

    /**
     * Cached copy of section data
     */
    PNOR::SectionData_t iv_TOC[PNOR::NUM_SECTIONS+1];

    /**
     * Pointer to the message queue where we receive messages
     */
    msg_q_t iv_msgQ;

    /**
     * Remember that we failed during initial startup
     *   This is set by startup methods to indicate to constructor that
     *   something went wrong
     */
    uint64_t iv_startupRC;

    /**
     * sent when a shutdown message is sent, used to elimnate further writes
     * to pnor during a shutdown process
     */
    bool iv_shutdown_pending;

    /**
     * Track some information related to flash wear and health
     *  indexed by physical page number inside PNOR
     */
    std::map<uint64_t,FlashStats_t> iv_stats;

    /**
     * Create a permanent buffer to handle ECC translations rather than
     *  constantly allocating new pages every time.  This is always 2 pages.
     */
    uint8_t iv_ecc_buffer[PNOR::PAGESIZE_PLUS_ECC];

    /**
     * Keep track of all page requests
     */
    std::map<uint64_t,uint32_t> iv_pageCounter;

    /**
     * @brief Initialize the daemon, called by constructor
     */
    void initDaemon();

    /**
     * @brief Determine the TOC offsets based on the HBB address
     *        System does a shutdown if any errors detected
     *
     * @param[out] o_tocSize The size of the table of content of PNOR in bytes
     *
     * @return Error from device
     */
    errlHndl_t  findTOC(size_t & o_tocSize);

    /**
     * @brief Perform mm_alloc_block operations in order to allocate
     *        virtual memory blocks that PnorRP will use and register
     *        the space to be flushed on shutdown. When using the
     *        pnor_pldmdd this function will also set permissions
     *
     * @return Contains an error, if one occurred, otherwise it will return nullptr.
     */
    errlHndl_t setupPnorVMM(void);

    /**
     * @brief determines the sides information and fills the class variable
     *          iv_side
     *
     * @param[in] i_tocSize The size of the table of content of PNOR in bytes
     *
     * @return Error
     */
    errlHndl_t setSideInfo(size_t i_tocSize);

    /**
     * @brief Verify both TOC's and store section information from one of the
     *        verified TOC's. Additionally set each section permissions
     *        (e.g. readOnly)
     *
     * @param[in] i_tocSize The size of the table of content of PNOR in bytes
     *
     *
     * @return Error from device
     */
    errlHndl_t readTOC(size_t i_tocSize);

    /**
     * @brief  Message receiver
     */
    void waitForMessage();

    /**
     * @brief Set the virtual addresses in the iv_TOC
     *
     * @return Any errors found while setting Virtual Addresses
     */
    errlHndl_t setVirtAddrs(void);

    /**
     * @brief  Retrieve 1 logical page of data from the PNOR device
     *
     * @param[in] i_offset  Offset into PNOR chip
     * @param[in] i_chip  Which PNOR chip
     * @param[in] i_ecc  true=apply ECC after reading
     * @param[out] o_dest  Buffer to copy data into
     * @param[out] o_fatalError  non-zero=fatal error encountered, but no
     *                    log could be created.  Value is the internal RC.
     *
     * @return Error from device
     */
    errlHndl_t readFromDevice( uint64_t i_offset,
                               uint64_t i_chip,
                               bool i_ecc,
                               void* o_dest,
                               uint64_t& o_fatalError );

    /**
     * @brief  Write 1 logical page of data to the PNOR device
     *
     * @param[in] i_offset  Offset into PNOR chip
     * @param[in] i_chip  Which PNOR chip
     * @param[in] i_ecc  true=apply ECC before writing
     * @param[in] i_src  Buffer to copy data from
     *
     * @return Error from device
     */
    errlHndl_t writeToDevice( uint64_t i_offset,
                              uint64_t i_chip,
                              bool i_ecc,
                              void* i_src );

    /**
     * @brief  Convert a virtual address into the PNOR device address
     *
     * @param[in] i_vaddr  Virtual address of page
     * @param[out] o_offset  Offset into PNOR chip
     * @param[out] o_chip  Which PNOR chip
     * @param[out] o_ecc  true=data is ECC-protected
     *
     * @return Error if VA is bad
     */
    errlHndl_t computeDeviceAddr( void* i_vaddr,
                                  uint64_t& o_offset,
                                  uint64_t& o_chip,
                                  bool& o_ecc );

    /**
     * @brief  Figure out which section a VA belongs to
     *
     * @param[in] i_vaddr  Virtual address of page
     * @param[out] o_id  Which section of PNOR
     *
     * @return Error if VA is bad
     */
    errlHndl_t computeSection( uint64_t i_vaddr,
                               PNOR::SectionId& o_id );

    /**
     * @brief  Figure out which section a PA belongs to
     *
     * @param[in] i_offset  Physical offset into PNOR
     *
     * @return Which section of PNOR, returns
     *         PNOR::INVALID_SECTION if not mapped
     */
     PNOR::SectionId computeSectionPhys( uint64_t i_offset );

#ifdef CONFIG_FILE_XFER_VIA_PLDM
    /**
     * @brief Request the PLDM file table from the BMC and use it to fill
     *        in information about the various PNOR sections in the iv_TOC
     *        member of PnorRP.
     *
     * @return Contains the error, if one occurred, returned from the getFileTable
     *         PLDM request. Otherwise it will return nullptr.
     */
    errlHndl_t populateTOC(void);



    /**
    * @brief Given a SectionId and a PLDM File Table, lookup the file table
    *        entry associated with that SectionId in the PLDM File Table given.
    *
    * @param[in]  i_secId SectionId we want to lookup
    * @param[in]  i_fileTable Byte vector containing the PLDM file table we got from
    *                         the BMC.
    * @return File Table Entry associated with this PNOR::SectionId
    */
    pldm_file_attr_table_entry * sectionIdFileTableLookup(const PNOR::SectionId i_secId,
                                                          const std::vector<uint8_t> & i_fileTable);
#endif

    /**
     * @brief  Returns true if the initial startup failed for some reason
     * @param[out]  Return code
     * @return  true if startup failed
     */
    bool didStartupFail( uint64_t& o_rc )
    {
        if( iv_startupRC )
        {
            //@patrick : Weak consistency bug? Will need some sort of lwsync / isync coordinating reading / setting of iv_startupRC if the daemonized task could be setting this.
            o_rc = iv_startupRC;
            return true;
        }
        return false;
    };

    // allow local helper function to call private methods
    friend void* wait_for_message( void* unused );

    // allow testcase to see inside
    friend class PnorRpTest;
    friend class PnorDdTest;
    friend class SfcIBMTest;
    friend class SfcAST2400Test;
    // allow this function to use constant(s)
    friend errlHndl_t PNOR::validateAltMaster( void );
    friend errlHndl_t PNOR::copyPnorPartitionToAlt( PNOR::SectionId i_section );

    /**
     * @brief Static instance function
     */
    static PnorRP& getInstance();
};


#endif
