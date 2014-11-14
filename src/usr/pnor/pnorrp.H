/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnorrp.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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

/**
 * PNOR Resource Provider
 */
class PnorRP
{
  public:
    /**
     * @brief Static Initializer
     * @param[in]  ref to errlHndl_t
     */
    static void init( errlHndl_t &io_rtaskRetErrl );

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
     * @brief  Get TOC offset of specified TOC on active side
     *
     * @param[in] i_toc     TOC offset desired on active side
     *
     * @return uint64_t     TOC offset
     */
    uint64_t getTocOffset(PNOR::TOCS i_toc) const;

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

    // TOC 0 and 1 offsets of both PNOR sides. The active PNOR side determined
    // by the Seeprom the SBE booted from
    std::pair<uint64_t, uint64_t> iv_activeTocOffsets;
    std::pair<uint64_t, uint64_t> iv_altTocOffsets;

    enum
    {
        BASE_VADDR = VMM_VADDR_PNOR_RP, /**< 2GB = 0x80000000*/
        TOTAL_SIZE = 64*MEGABYTE, /**< Allocate 64 MB (0x4000000)*/
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
     * Track some information related to flash wear and health
     *  indexed by physical page number inside PNOR
     */
    std::map<uint64_t,FlashStats_t> iv_stats;

    /**
     * @brief Initialize the daemon, called by constructor
     */
    void initDaemon();

    /**
     * @brief Verify both TOC's and store section information from one of the
     *        verified TOC's. Additionally set each section permissions
     *        (e.g. readOnly)
     *
     * @return Error from device
     */
    errlHndl_t readTOC();

    /**
     * @brief  Message receiver
     */
    void waitForMessage();

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

    /**
     * @brief Static instance function
     */
    static PnorRP& getInstance();
};


#endif
