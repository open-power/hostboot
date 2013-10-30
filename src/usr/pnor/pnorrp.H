/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnorrp.H $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
#ifndef __PNOR_PNORRP_H
#define __PNOR_PNORRP_H

#include <pnor/pnorif.H>
#include <sys/msg.h>
#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <vmmconst.h>
#include <map>

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
    static void init( errlHndl_t    &io_rtaskRetErrl );

    /**
     * @brief  Return the size and address of a given section of PNOR data
     *    Called by external PNOR::getSectionInfo()
     *
     * @param[in] i_section  PNOR section
     * @param[in] i_side  Side select
     * @param[out] o_info  Location and size information
     *
     * @return errlHndl_t  Error log if request was invalid
     */
    errlHndl_t getSectionInfo( PNOR::SectionId i_section,
                               PNOR::SideSelect i_side,
                               PNOR::SectionInfo_t& o_info );

  protected:
    /**
     * @brief  Constructor
     */
    PnorRP();

    /**
     * @brief  Destructor
     */
    ~PnorRP();


  private:

    /**
     * PNOR Constants
     */
    enum
    {
        BASE_VADDR = VMM_VADDR_PNOR_RP, /**< 2GB = 0x80000000*/

        NUM_SIDES = 2,  /**< A, B */

        SIDE_SIZE = 32*MEGABYTE, /**< Allocate 32 MB (0x2000000) of VA per side */

        NUM_VADDR_BLOCKS = NUM_SIDES+1, /**< Number of VADDR blocks. */
        SIDEA_VADDR = BASE_VADDR,  /**< Base address of Side A */
        SIDEB_VADDR = SIDEA_VADDR + SIDE_SIZE,  /**< Base address of Side B */
        SIDELESS_VADDR = SIDEB_VADDR + SIDE_SIZE,  /**< Sideless data Base Addr */

        TOTAL_SIZE = SIDE_SIZE*NUM_VADDR_BLOCKS,  /**< Size of PNOR VA region */
        LAST_VADDR = BASE_VADDR + TOTAL_SIZE,  /**< End of our VA range */

        /** Real number of bytes required to read 1 logical page */
        PAGESIZE_PLUS_ECC = ((PAGESIZE * 9)/8),  // 8B data + 1B of ECC

        SUPPORTED_FFS_VERSION = 0x1,  /**< Supported FFS Version */
        FFS_TABLE_BASE_ADDR = 0x0,    /**< Currently only have FFS table */
    };

    /**
     * Internal information to deal with the sections of PNOR
     */
    struct SectionData_t {
        PNOR::SectionId id;  /**< Identifier for this section */
        PNOR::SideSelect side;  /** Side Select */
        uint64_t virtAddr;  /**< Virtual address for the start of the section */
        uint32_t flashAddr;  /**< Address in flash */
        uint32_t size;  /**< Actual size of content in bytes (not including ECC) */
        uint8_t chip;  /**< Chip Select */
        uint8_t version; /**< Version Checking */
        uint16_t integrity; /**< Data Integrity */
        uint8_t misc; /**< Misc Flags */
    } PACKED;

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
    SectionData_t iv_TOC[NUM_SIDES][PNOR::NUM_SECTIONS+1];

    /**
     * Currently selected PNOR Side
     */
    PNOR::SideSelect iv_curSide;

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
     * @brief Read the TOC and store section information
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
     * @param[out] o_fatalError  true=fatal error encountered, but no
     *                    log could be created
     *
     * @return Error from device
     */
    errlHndl_t readFromDevice( uint64_t i_offset,
                               uint64_t i_chip,
                               bool i_ecc,
                               void* o_dest,
                               bool& o_fatalError );

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
     * @param[out] o_side  Which side of the flash
     * @param[out] o_id  Which section of PNOR
     *
     * @return Error if VA is bad
     */
    errlHndl_t computeSection( uint64_t i_vaddr,
                               PNOR::SideSelect& o_side,
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

    /**
     * @brief Static instance function for testcase only
     */
    static PnorRP& getInstance();
};


#endif
