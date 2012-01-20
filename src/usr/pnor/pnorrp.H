//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pnor/pnorrp.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __PNOR_PNORRP_H
#define __PNOR_PNORRP_H

#include <pnor/pnorif.H>
#include <sys/msg.h>
#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <vmmconst.h>

/**
 * PNOR Resource Provider
 */
class PnorRP
{
  public:
    /**
     * @brief Static Initializer
     * @param[in]  Task Args pointer passed by init service
     */
    static void init( void* i_taskArgs );

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

        NUM_SIDES = 3,  /**< A, B, Sideless */

        SIDE_SIZE = 32*MEGABYTE, /**< Allocate 32 MB (0x2000000) of VA per side */

        SIDEA_VADDR = BASE_VADDR,  /**< Base address of Side A */
        SIDEB_VADDR = SIDEA_VADDR + SIDE_SIZE,  /**< Base address of Side B */
        SIDELESS_VADDR = SIDEB_VADDR + SIDE_SIZE,  /**< Base address of Sideless data */

        TOTAL_SIZE = SIDE_SIZE*NUM_SIDES,  /**< Size of PNOR VA region */
        LAST_VADDR = BASE_VADDR + TOTAL_SIZE,  /**< End of our VA range */

        /** Real number of bytes required to read 1 logical page */
        PAGESIZE_PLUS_ECC = PAGESIZE * (9/8),  // 8 bytes of data + 1 byte of ECC 
    };

    /**
     * Table of Contents entry
     *   This matches the PNOR binary layout  @todo this will change
     */
    struct TOCEntry_t
    {
        char name[8]; /**< Null terminated ascii string */
        uint64_t offset;  /**< Offset to region from zero (relative to chip) */
        uint64_t size;  /**< Size of region in bytes (with or without ECC?) */
        uint64_t size_act;  /**< Actual size of content in bytes */
        char fuse_tbd[96];  /**< Remainder is TBD depending on FUSE requirements */
        //@todo - need a chip select here I think?
    } PACKED;

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
        uint8_t eccProtected;  /**< Section is ECC protected */
    } PACKED;

    /**
     * Cached copy of section data
     */
    SectionData_t iv_TOC[NUM_SIDES][PNOR::NUM_SECTIONS+1];

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
     *
     * @return Error from device
     */
    errlHndl_t readFromDevice( uint64_t i_offset,
                               uint64_t i_chip,
                               bool i_ecc,
                               void* o_dest );

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
     * @brief  Apply ECC algorithm to data
     *
     * @param[in] i_orig  Original data to write
     * @param[in] o_ecc  Data after applying ECC
     */
    void applyECC( void* i_orig,
                   void* o_ecc );

    /**
     * @brief  Apply ECC algorithm to data, assumes size of 1 page
     *
     * @param[in] i_orig  Original data that was read
     * @param[in] o_data  Data after removing ECC
     *
     * @return Error if ECC is incorrect
     */
    errlHndl_t stripECC( void* i_orig,
                         void* o_data );

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
    friend void wait_for_message( void* unused );

    // allow testcase to see inside
    friend class PnorRpTest;

    /**
     * @brief Static instance function for testcase only
     */
    static PnorRP& getInstance();
};


#endif 
