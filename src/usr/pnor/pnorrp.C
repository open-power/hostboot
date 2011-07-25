#include "pnorrp.H"
#include <sys/rp.h>
#include <pnor/pnor_reasoncodes.H>
#include <initservice/taskargs.H> 
#include <sys/msg.h>
#include <kernel/block.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/targetservice.H>
#include <devicefw/userif.H>
#include <limits.h>
#include <string.h>

// Trace definition
trace_desc_t* g_trac_pnor = NULL;
TRAC_INIT(&g_trac_pnor, "PNOR", 4096);

const char* cv_EYECATCHER[] = {
    "TOC",    /**< PNOR_TOC           : Table of Contents */
    "GLOBAL", /**< PNOR_GLOBAL_DATA   : Global Data */
    "SBE",    /**< PNOR_SBE_IPL       : Self-Boot Enginer IPL image */
    "HBB",    /**< PNOR_HB_BASE_CODE  : Hostboot Base Image */
    "HBD",    /**< PNOR_HB_DATA       : Hostboot Data */
    "XXX",    /**< PNOR_HB_ERRLOGS    : Hostboot Error log Repository */
    "HBI",    /**< PNOR_HB_EXT_CODE   : Hostboot Extended Image */
    "HBR",    /**< PNOR_HB_RUNTIME    : Hostboot Runtime Image */
    "OPAL",   /**< PNOR_PAYLOAD       : HAL/OPAL */
    "PFWL",   /**< PNOR_PFW_LITE_CODE : PFW-lite */
    "OCC",    /**< PNOR_OCC_CODE      : OCC Code Image */
    "PART",   /**< PNOR_KVM_PART_INFO : KVM Partition Information */    
    "XXX",    /**< PNOR_CODE_UPDATE   : Code Update Overhead */
    "XXX",    /**< NUM_SECTIONS       : Used as invalid entry */
};


/**
 * @brief   set up _start() task entry procedure for PNOR daemon
 */
TASK_ENTRY_MACRO( PnorRP::init );


/********************
 Public Methods
 ********************/

/**
 * @brief  Return the size and address of a given section of PNOR data
 */
void PNOR::getSectionInfo( PNOR::SectionId i_section,
                           PNOR::SideSelect i_side,
                           PNOR::SectionInfo_t& o_info )
{
    Singleton<PnorRP>::instance().getSectionInfo(i_section,i_side,o_info);
}


/**
 * STATIC
 * @brief Static Initializer
 */
void PnorRP::init( void* i_taskArgs )
{
    TRACFCOMP(g_trac_pnor, "PnorRP::init> " );
    INITSERVICE::TaskArgs::TaskArgs* args = (INITSERVICE::TaskArgs::TaskArgs*)i_taskArgs;
    uint64_t rc = 0;
    if( Singleton<PnorRP>::instance().didStartupFail(rc) )
    {
        args->postReturnCode(rc);
    }
}


/********************
 Helper Methods
 ********************/

/**
 * @brief  Static function wrapper to pass into task_create
 */
void wait_for_message( void* unused )
{
    Singleton<PnorRP>::instance().waitForMessage();
}


/********************
 Private/Protected Methods
 ********************/

/**
 * @brief  Constructor
 */
PnorRP::PnorRP()
: iv_msgQ(NULL)
,iv_block(NULL)
{
    // setup everything in a separate function
    initDaemon();
}

/**
 * @brief  Destructor
 */
PnorRP::~PnorRP()
{
    // delete the message queue we created
    msg_q_destroy( iv_msgQ );

    //@fixme - do we need to delete the Block we allocated?
    //delete iv_block;
}

/**
 * @brief Initialize the daemon
 */
void PnorRP::initDaemon()
{
    // read the TOC in the PNOR to compute the sections
    readTOC();

    // create a message queue
    iv_msgQ = msg_q_create();

    // create a Block, passing in the message queue
    //@fixme  iv_block = new Block( 0, 0 ); 

    // start task to wait on the queue
    task_create( wait_for_message, NULL );
}


/**
 * @brief  Return the size and address of a given section of PNOR data
 */
void PnorRP::getSectionInfo( PNOR::SectionId i_section,
                             PNOR::SideSelect i_side,
                             PNOR::SectionInfo_t& o_info )
{
    // cheat for now


    //@todo - when we get a real PNOR image
    
}



/**
 * @brief Read the TOC and store section information
 */
void PnorRP::readTOC()
{
    // Zero out my table
    for( PNOR::SectionId id = PNOR::FIRST_SECTION;
         id < PNOR::NUM_SECTIONS;
         id = (PNOR::SectionId) (id + 1) )
    {
        iv_TOC[id].id = id;
        iv_TOC[id].name = cv_EYECATCHER[PNOR::INVALID_SECTION];
        iv_TOC[id].vaddr = 0;
        iv_TOC[id].size = 0;
        iv_TOC[id].eccProtected = false;
    }

    // Add a special entry for error paths
    iv_TOC[PNOR::INVALID_SECTION].id = PNOR::INVALID_SECTION;
    iv_TOC[PNOR::INVALID_SECTION].name = cv_EYECATCHER[PNOR::INVALID_SECTION];
    iv_TOC[PNOR::INVALID_SECTION].vaddr = 0;
    iv_TOC[PNOR::INVALID_SECTION].size = 0;
    iv_TOC[PNOR::INVALID_SECTION].eccProtected = false;

    //@todo - load flash layout 

    //@todo - read TOC if we haven't yet
}



/**
 * @brief  Message receiver
 */
void PnorRP::waitForMessage()
{
    msg_t* message = NULL;
    uint8_t* user_addr = NULL;
    uint8_t* eff_addr = NULL;
    uint64_t dev_offset = 0;
    uint64_t chip_select = 0xF;
    bool needs_ecc = false;

    while(1)
    {
        message = msg_wait( iv_msgQ );
        if( message )
        {
            user_addr = (uint8_t*)message->data[0];
            eff_addr = (uint8_t*)message->data[1];
            computeDeviceAddr( eff_addr, dev_offset, chip_select );
            needs_ecc = iv_TOC[sectionFromAddr(eff_addr)].eccProtected;

            switch(message->type)
            {
                case( RP::READ_PAGE ):
                    readFromDevice( dev_offset, chip_select, user_addr );
                    break;
                case( RP::WRITE_PAGE ):
                    writeToDevice( dev_offset, chip_select, true, user_addr );
                    break;
                default:
                    TRACFCOMP( g_trac_pnor, "PnorRP::waitForMessage> Unrecognized message type user_addr=%p, eff_addr=%p, msgtype=%d", user_addr, eff_addr, message->type );
                    /*@
                     * @errortype
                     * @moduleid     PNOR::PNORRP_WAITFORMESSAGE
                     * @reasoncode   PNOR::INVALID_MESSAGE
                     * @userdata1    Message type
                     * @userdata2    User memory address
                     * @devdesc      PnorRP::waitForMessage> Unrecognized message type
                     */
                    errlHndl_t l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                               PNOR::PNORRP_WAITFORMESSAGE,
                                                               PNOR::INVALID_MESSAGE,
                                                               (uint64_t)message->type,
                                                               (uint64_t)user_addr);
                    errlCommit(l_err);
                    //@fixme - kill calling task?, commit log
            }
        }
    }

}


/**
 * @brief  Retrieve 1 page of data from the PNOR device
 */
void PnorRP::readFromDevice( uint64_t i_offset,
                             uint64_t i_chip,
                             void* o_dest )
{
    TARGETING::Target* pnor_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL; //@fixme

    size_t read_size = PAGESIZE;
    errlHndl_t l_err = DeviceFW::deviceRead(pnor_target, 
                                            o_dest,
                                            read_size,
                                            DEVICE_PNOR_ADDRESS(i_offset,i_chip) );
    errlCommit(l_err);
    //@fixme - commit log

}

/**
 * @brief  Write 1 page of data to the PNOR device
 */
void PnorRP::writeToDevice( uint64_t i_offset,
                            uint64_t i_chip,
                            bool i_ecc,
                            void* i_src )
{
    TARGETING::Target* pnor_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL; //@fixme

    // apply ECC to data if needed
    void* data_to_write = i_src;
    void* ecc_buffer = NULL;
    if( i_ecc )
    {
        ecc_buffer = (void*)new uint8_t[PAGESIZE];
        applyECC( i_src, ecc_buffer );
        data_to_write = ecc_buffer;
    }

    size_t write_size = PAGESIZE;
    errlHndl_t l_err = DeviceFW::deviceWrite(pnor_target, 
                                             data_to_write,
                                             write_size,
                                             DEVICE_PNOR_ADDRESS(i_offset,i_chip) );
    errlCommit(l_err);

}

/**
 * @brief  Convert a virtual address into the PNOR device address
 */
void PnorRP::computeDeviceAddr( void* i_vaddr,
                                uint64_t& o_offset,
                                uint64_t& o_chip )
{
    //@fixme
    o_offset = ((uint64_t)i_vaddr) - iv_block->getBaseAddress();
    o_chip = 0;
}


/**
 * @brief  Apply ECC algorithm to data, assumes size of 1 page
 *
 * @param[in] i_orig  Original data to write
 * @param[in] o_ecc  Data after applying ECC
 */
void PnorRP::applyECC( void* i_orig,
                       void* o_ecc )
{
    //@todo - fill this in
    memcpy( o_ecc, i_orig, PAGESIZE );
}

/**
 * @brief  Retrieve the section Id based on the virtual address
 */
PNOR::SectionId PnorRP::sectionFromAddr( void* i_addr )
{
    //@fixme - how do I do this?
    return PNOR::INVALID_SECTION;
}


