#ifndef __PNOR_PNORRP_H
#define __PNOR_PNORRP_H

#include <pnor/pnorif.H>
#include <sys/msg.h>
#include <stdint.h>
#include <builtins.h>
class Block;

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
     * @return size_t  Offset of section in bytes
     */
    void getSectionInfo( PNOR::SectionId i_section,
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
     * Table of Contents entry
     */
    struct TOCEntry_t
    {
        char name[8]; /**< Null terminated ascii string */
        uint64_t offset;  /**< Offset to region from zero */
        uint64_t size;  /**< Size of region in bytes */
        uint64_t size_act;  /**< Actual size of content in bytes */
        char fuse_tbd[96];  /**< Remainder is TBD depending on FUSE requirements */
    };

    /**
     * Cached copy of section data
     */
    PNOR::SectionInfo_t iv_TOC[PNOR::NUM_SECTIONS+1];

    /**
     * Pointer to the message queue where we receive messages
     */
    msg_q_t iv_msgQ;

    /**
     * Remember that we failed during initial startup
     */
    uint64_t iv_startupRC;

    /**
     * Memory Block associated with my PNOR memory space
     */
    Block* iv_block;

    /**
     * @brief Initialize the daemon, called by constructor
     */
    void initDaemon();

    /**
     * @brief Read the TOC and store section information
     */
    void readTOC();

    /**
     * @brief  Message receiver
     */
    void waitForMessage();

    /**
     * @brief  Retrieve 1 page of data from the PNOR device
     *
     * @param[in] i_offset  Offset into PNOR chip
     * @param[in] i_chip  Which PNOR chip
     * @param[out] o_dest  Buffer to copy data into
     */
    void readFromDevice( uint64_t i_offset,
                         uint64_t i_chip,
                         void* o_dest );

    /**
     * @brief  Write 1 page of data to the PNOR device
     *
     * @param[in] i_offset  Offset into PNOR chip
     * @param[in] i_chip  Which PNOR chip
     * @param[in] i_ecc  true=apply ECC before writing
     * @param[in] i_src  Buffer to copy data from
     */
    void writeToDevice( uint64_t i_offset,
                        uint64_t i_chip,
                        bool i_ecc,
                        void* i_src );

    /**
     * @brief  Convert a virtual address into the PNOR device address
     *
     * @param[in] i_vaddr  Virtual address of page
     * @param[out] o_offset  Offset into PNOR chip
     * @param[out] o_chip  Which PNOR chip
     */
    void computeDeviceAddr( void* i_vaddr,
                            uint64_t& o_offset,
                            uint64_t& o_chip );

    /**
     * @brief  Apply ECC algorithm to data
     *
     * @param[in] i_orig  Original data to write
     * @param[in] o_ecc  Data after applying ECC
     */
    void applyECC( void* i_orig,
                   void* o_ecc );

    /**
     * @brief  Retrieve the section Id based on the virtual address
     *
     * @param[in] i_addr  Virtual address of page within section
     *
     * @return SectionId  Id of matching section, =INVALID_SECTION if no match
     */
    PNOR::SectionId sectionFromAddr( void* i_addr );

    /**
     * @brief  Returns true if the initial startup failed for some reason
     * @param[out]  Return code
     * @return  true if startup failed
     */
    bool didStartupFail( uint64_t& o_rc )
    {
        if( iv_startupRC )
        {
            o_rc = iv_startupRC;
            return true;
        }
        return false;
    };


    // allow local helper function to call private methods
    friend void wait_for_message( void* unused );
};


#endif 
