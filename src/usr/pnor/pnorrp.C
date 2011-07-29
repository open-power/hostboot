#include "pnorrp.H"
#include <sys/rp.h>
#include <pnor/pnor_reasoncodes.H>
#include <initservice/taskargs.H> 
#include <sys/msg.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <targeting/targetservice.H>
#include <devicefw/userif.H>
#include <limits.h>
#include <string.h>
#include <kernel/console.H>

// Trace definition
trace_desc_t* g_trac_pnor = NULL;
TRAC_INIT(&g_trac_pnor, "PNOR", 4096); //4K

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)  

/**
 * Eyecatcher strings for PNOR TOC entries
 */
const char* cv_EYECATCHER[] = {
    "TOC",    /**< PNOR::TOC           : Table of Contents */
    "GLOBAL", /**< PNOR::GLOBAL_DATA   : Global Data */
    "SBE",    /**< PNOR::SBE_IPL       : Self-Boot Enginer IPL image */
    "HBB",    /**< PNOR::HB_BASE_CODE  : Hostboot Base Image */
    "HBD",    /**< PNOR::HB_DATA       : Hostboot Data */
    "XXX",    /**< PNOR::HB_ERRLOGS    : Hostboot Error log Repository */
    "HBI",    /**< PNOR::HB_EXT_CODE   : Hostboot Extended Image */
    "HBR",    /**< PNOR::HB_RUNTIME    : Hostboot Runtime Image */
    "OPAL",   /**< PNOR::PAYLOAD       : HAL/OPAL */
    "PFWL",   /**< PNOR::PFW_LITE_CODE : PFW-lite */
    "OCC",    /**< PNOR::OCC_CODE      : OCC Code Image */
    "PART",   /**< PNOR::KVM_PART_INFO : KVM Partition Information */    
    "XXX",    /**< PNOR::CODE_UPDATE   : Code Update Overhead */
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
errlHndl_t PNOR::getSectionInfo( PNOR::SectionId i_section,
                                 PNOR::SideSelect i_side,
                                 PNOR::SectionInfo_t& o_info )
{
    return Singleton<PnorRP>::instance().getSectionInfo(i_section,i_side,o_info);
}


/**
 * STATIC
 * @brief Static Initializer
 */
void PnorRP::init( void* i_taskArgs )
{
    TRACUCOMP(g_trac_pnor, "PnorRP::init> " );
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
    TRACUCOMP(g_trac_pnor, "wait_for_message> " );
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
,iv_startupRC(0)
{
    TRACFCOMP(g_trac_pnor, "PnorRP::PnorRP> " );

    // setup everything in a separate function
    initDaemon();

    TRACFCOMP(g_trac_pnor, "< PnorRP::PnorRP " );
}

/**
 * @brief  Destructor
 */
PnorRP::~PnorRP()
{
    TRACFCOMP(g_trac_pnor, "PnorRP::~PnorRP> " );

    // delete the message queue we created
    msg_q_destroy( iv_msgQ );

    TRACFCOMP(g_trac_pnor, "< PnorRP::~PnorRP" );
}

/**
 * @brief Initialize the daemon
 */
void PnorRP::initDaemon()
{
    TRACUCOMP(g_trac_pnor, "PnorRP::initDaemon> " );

    // read the TOC in the PNOR to compute the sections
    readTOC();

    // create a message queue
    iv_msgQ = msg_q_create();

    // create a Block, passing in the message queue
    //@todo  iv_block = new Block( 0, 0 ); 

    // start task to wait on the queue
    task_create( wait_for_message, NULL );

    TRACUCOMP(g_trac_pnor, "< PnorRP::initDaemon" );
}


/**
 * @brief  Return the size and address of a given section of PNOR data
 */
errlHndl_t PnorRP::getSectionInfo( PNOR::SectionId i_section,
                                   PNOR::SideSelect i_side,
                                   PNOR::SectionInfo_t& o_info )
{
    //TRACDCOMP(g_trac_pnor, "PnorRP::getSectionInfo> i_section=%d, i_side=%X", i_section, i_side );
    errlHndl_t errhdl = NULL;
    
    PNOR::SectionId id = i_section;

    // Zero-length means the section is invalid
    if( 0 == iv_TOC[i_side][id].size )
    {
        TRACFCOMP( g_trac_pnor, "PnorRP::getSectionInfo> Invalid Section Requested : i_section=%d, i_side=%d", i_section, i_side );
        TRACFCOMP(g_trac_pnor, "o_info={ id=%d, size=%d }", iv_TOC[i_side][i_section].id, iv_TOC[i_side][i_section].size );
        /*@
         * @errortype
         * @moduleid     PNOR::MOD_PNORRP_GETSECTIONINFO
         * @reasoncode   PNOR::RC_INVALID_SECTION
         * @userdata1    Requested Section
         * @userdata2    Requested Side
         * @devdesc      PnorRP::waitForMessage> Invalid Address for read/write
         */
        errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         PNOR::MOD_PNORRP_GETSECTIONINFO,
                                         PNOR::RC_INVALID_SECTION,
                                         TO_UINT64(i_section),
                                         TO_UINT64(i_side));

        // set the return valid to our invalid data
        id = PNOR::INVALID_SECTION;
    }

    TRACFCOMP( g_trac_pnor, "i_section=%d, i_side=%d : id=%d", i_section, i_side, iv_TOC[i_side][i_section].id );

    // copy my data into the external format
    o_info.id = iv_TOC[i_side][i_section].id;
    o_info.side = iv_TOC[i_side][i_section].side;
    o_info.name = cv_EYECATCHER[i_section];
    o_info.vaddr = iv_TOC[i_side][i_section].virtAddr;
    o_info.size = iv_TOC[i_side][i_section].size;
    o_info.eccProtected = iv_TOC[i_side][i_section].eccProtected;

    return errhdl;
}



/**
 * @brief Read the TOC and store section information
 */
void PnorRP::readTOC()
{
    TRACUCOMP(g_trac_pnor, "PnorRP::readTOC>" );

    // Zero out my table
    for( uint64_t side = 0; side < NUM_SIDES; side++ )
    {
        for( PNOR::SectionId id = PNOR::FIRST_SECTION;
             id <= PNOR::NUM_SECTIONS; //include extra entry for error paths
             id = (PNOR::SectionId) (id + 1) )
        {
            iv_TOC[side][id].id = id;
            iv_TOC[side][id].side = (PNOR::SideSelect)side;
            iv_TOC[side][id].chip = 0;
            iv_TOC[side][id].mmrdAddr = 0;
            iv_TOC[side][id].pmrwAddr = 0;
            iv_TOC[side][id].virtAddr = 0;
            iv_TOC[side][id].size = 0;
            iv_TOC[side][id].eccProtected = false;
        }
    }

    //@todo - Add in some dummy values for now

    // assume 1 chip with only 1 side for now, no sideless
    // TOC starts at offset zero in MMRD mode

    // put some random sizes in here
    iv_TOC[PNOR::SIDE_A][PNOR::TOC].size = 8 + 8 + PNOR::NUM_SECTIONS*sizeof(TOCEntry_t);
    iv_TOC[PNOR::SIDE_A][PNOR::HB_EXT_CODE].size = 500*1024; //500K
    iv_TOC[PNOR::SIDE_A][PNOR::GLOBAL_DATA].size = PAGESIZE; //4K
    iv_TOC[PNOR::SIDE_A][PNOR::HB_DATA].size = 2*PAGESIZE; //8K

    // fake PNOR will look like this:  TOC::HB_EXT_CODE:GLOBAL_DATA:HB_DATA
    // virtual addresses
    iv_TOC[PNOR::SIDE_A][PNOR::TOC].virtAddr = BASE_VADDR + 0;
    iv_TOC[PNOR::SIDE_A][PNOR::HB_EXT_CODE].virtAddr = iv_TOC[PNOR::SIDE_A][PNOR::TOC].virtAddr + iv_TOC[PNOR::SIDE_A][PNOR::TOC].size;
    iv_TOC[PNOR::SIDE_A][PNOR::GLOBAL_DATA].virtAddr = iv_TOC[PNOR::SIDE_A][PNOR::HB_EXT_CODE].virtAddr + iv_TOC[PNOR::SIDE_A][PNOR::HB_EXT_CODE].size;
    iv_TOC[PNOR::SIDE_A][PNOR::HB_DATA].virtAddr = iv_TOC[PNOR::SIDE_A][PNOR::GLOBAL_DATA].virtAddr + iv_TOC[PNOR::SIDE_A][PNOR::GLOBAL_DATA].size;
    // MMRD offsets
    iv_TOC[PNOR::SIDE_A][PNOR::TOC].mmrdAddr = 0;
    iv_TOC[PNOR::SIDE_A][PNOR::HB_EXT_CODE].mmrdAddr = iv_TOC[PNOR::SIDE_A][PNOR::TOC].mmrdAddr + iv_TOC[PNOR::SIDE_A][PNOR::TOC].size;
    iv_TOC[PNOR::SIDE_A][PNOR::GLOBAL_DATA].mmrdAddr = iv_TOC[PNOR::SIDE_A][PNOR::HB_EXT_CODE].mmrdAddr + iv_TOC[PNOR::SIDE_A][PNOR::HB_EXT_CODE].size;
    iv_TOC[PNOR::SIDE_A][PNOR::HB_DATA].mmrdAddr = iv_TOC[PNOR::SIDE_A][PNOR::GLOBAL_DATA].mmrdAddr + iv_TOC[PNOR::SIDE_A][PNOR::GLOBAL_DATA].size;
    // PMRW offsets - no ECC support yet so just equal to MMRD
    iv_TOC[PNOR::SIDE_A][PNOR::TOC].pmrwAddr = BASE_VADDR + 0;
    iv_TOC[PNOR::SIDE_A][PNOR::HB_EXT_CODE].pmrwAddr = iv_TOC[PNOR::SIDE_A][PNOR::TOC].virtAddr + iv_TOC[PNOR::SIDE_A][PNOR::TOC].size;
    iv_TOC[PNOR::SIDE_A][PNOR::GLOBAL_DATA].pmrwAddr = iv_TOC[PNOR::SIDE_A][PNOR::HB_EXT_CODE].virtAddr + iv_TOC[PNOR::SIDE_A][PNOR::HB_EXT_CODE].size;
    iv_TOC[PNOR::SIDE_A][PNOR::HB_DATA].pmrwAddr = iv_TOC[PNOR::SIDE_A][PNOR::GLOBAL_DATA].virtAddr + iv_TOC[PNOR::SIDE_A][PNOR::GLOBAL_DATA].size;

    //@todo - end fake data

    //@todo - load flash layout (how many chips)
    //@todo - read TOC on each chip/bank/whatever

    TRACUCOMP(g_trac_pnor, "< PnorRP::readTOC" );
}



/**
 * @brief  Message receiver
 */
void PnorRP::waitForMessage()
{
    TRACFCOMP(g_trac_pnor, "PnorRP::waitForMessage>" );

    errlHndl_t l_err = NULL;
    msg_t* message = NULL;
    uint8_t* user_addr = NULL;
    uint8_t* eff_addr = NULL;
    uint64_t dev_offset = 0;
    uint64_t chip_select = 0xF;
    bool needs_ecc = false;

    while(1)
    {
        TRACUCOMP(g_trac_pnor, "PnorRP::waitForMessage> waiting for message" );
        message = msg_wait( iv_msgQ );
        if( message )
        {
            user_addr = (uint8_t*)message->data[0];
            eff_addr = (uint8_t*)message->data[1];
            l_err = computeDeviceAddr( eff_addr, MMRD_MODE, dev_offset, chip_select, needs_ecc );
            //@todo - assuming MMRD mode for now
            if( l_err )
            {
                errlCommit(l_err);
                //@todo - kill calling task?, commit log

                if( !msg_is_async(message) )
                {
                    TRACUCOMP( g_trac_pnor, "sending response...\n" );
                    msg_respond( iv_msgQ, message ); //@todo - what goes in response message?
                }
                continue; // go wait for another message
            }

            //@todo - handle MMRD/PMRW mode
            //  if MMRD then needs_ecc = false

            switch(message->type)
            {
                case( RP::READ_PAGE ):
                    readFromDevice( dev_offset, chip_select, needs_ecc, user_addr );
                    break;
                case( RP::WRITE_PAGE ):
                    writeToDevice( dev_offset, chip_select, needs_ecc, user_addr );
                    break;
                default:
                    TRACFCOMP( g_trac_pnor, "PnorRP::waitForMessage> Unrecognized message type : user_addr=%p, eff_addr=%p, msgtype=%d", user_addr, eff_addr, message->type );
                    /*@
                     * @errortype
                     * @moduleid     PNOR::MOD_PNORRP_WAITFORMESSAGE
                     * @reasoncode   PNOR::RC_INVALID_MESSAGE
                     * @userdata1    Message type
                     * @userdata2    User memory address
                     * @devdesc      PnorRP::waitForMessage> Unrecognized message type
                     */
                    l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                    PNOR::MOD_PNORRP_WAITFORMESSAGE,
                                                    PNOR::RC_INVALID_MESSAGE,
                                                    TO_UINT64(message->type),
                                                    (uint64_t)user_addr);
                    errlCommit(l_err);
                    //@todo - kill calling task?, commit log
                    continue; // go wait for another message
            }

            if( !msg_is_async(message) )
            {
                TRACUCOMP( g_trac_pnor, "sending response...\n" );
                msg_respond( iv_msgQ, message ); //@todo - what goes in response message?
            }
        }
    }


    TRACFCOMP(g_trac_pnor, "< PnorRP::waitForMessage" );
}


/**
 * @brief  Retrieve 1 page of data from the PNOR device
 */
void PnorRP::readFromDevice( uint64_t i_offset,
                             uint64_t i_chip,
                             bool i_ecc,
                             void* o_dest )
{
    TRACUCOMP(g_trac_pnor, "PnorRP::readFromDevice> i_offset=0x%X, i_chip=%d", i_offset, i_chip );

    TARGETING::Target* pnor_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL; //@todo

    void* data_to_read = o_dest;
    uint8_t* ecc_buffer = NULL;
    size_t read_size = PAGESIZE;
    if( i_ecc )
    {
        ecc_buffer = new uint8_t[PAGESIZE_PLUS_ECC];
        data_to_read = ecc_buffer;
        read_size = PAGESIZE_PLUS_ECC;
    }

    errlHndl_t l_err = DeviceFW::deviceRead(pnor_target, 
                                            data_to_read,
                                            read_size,
                                            DEVICE_PNOR_ADDRESS(i_chip,i_offset) );
    if( l_err )
    {
        TRACFCOMP(g_trac_pnor, "PnorRP::readFromDevice> Error from device : RC=%X", l_err->reasonCode() );
        errlCommit(l_err);
        //@todo - anything else?
    }

    // remove the ECC data
    if( i_ecc )
    {
        l_err = stripECC( data_to_read, o_dest );
        //@todo - handle ECC error
        delete[] ecc_buffer;
    }

    TRACUCOMP(g_trac_pnor, "< PnorRP::readFromDevice" );
}

/**
 * @brief  Write 1 page of data to the PNOR device
 */
void PnorRP::writeToDevice( uint64_t i_offset,
                            uint64_t i_chip,
                            bool i_ecc,
                            void* i_src )
{
    TRACUCOMP(g_trac_pnor, "PnorRP::writeToDevice> i_offset=%X, i_chip=%d", i_offset, i_chip );

    TARGETING::Target* pnor_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL; //@todo

    // apply ECC to data if needed
    void* data_to_write = i_src;
    uint8_t* ecc_buffer = NULL;
    if( i_ecc )
    {
        ecc_buffer = new uint8_t[PAGESIZE];
        applyECC( i_src, ecc_buffer );
        data_to_write = (void*)ecc_buffer;
    }

    size_t write_size = PAGESIZE;
    errlHndl_t l_err = DeviceFW::deviceWrite(pnor_target, 
                                             data_to_write,
                                             write_size,
                                             DEVICE_PNOR_ADDRESS(i_chip,i_offset) );
    if( l_err )
    {
        TRACFCOMP(g_trac_pnor, "PnorRP::readFromDevice> Error from device : RC=%X", l_err->reasonCode() );
        errlCommit(l_err);
        //@todo - anything else?
    }

    if( ecc_buffer )
    {
        delete[] ecc_buffer;
    }

    TRACUCOMP(g_trac_pnor, "< PnorRP::writeToDevice" );
}

/**
 * @brief  Convert a virtual address into the PNOR device address
 */
errlHndl_t PnorRP::computeDeviceAddr( void* i_vaddr,
                                      ControllerMode i_mode,
                                      uint64_t& o_offset,
                                      uint64_t& o_chip,
                                      bool& o_ecc )
{
    errlHndl_t l_err = NULL;
    o_offset = 0;
    o_chip = 99;
    uint64_t l_vaddr = (uint64_t)i_vaddr;

    // make sure this is one of our addresses
    if( !((l_vaddr >= BASE_VADDR)
          && (l_vaddr < LAST_VADDR)) )
    {
        TRACFCOMP( g_trac_pnor, "PnorRP::computeDeviceAddr> Virtual Address outside known PNOR range : i_vaddr=%p", i_vaddr );
        /*@
         * @errortype
         * @moduleid     PNOR::MOD_PNORRP_WAITFORMESSAGE
         * @reasoncode   PNOR::RC_INVALID_MESSAGE
         * @userdata1    Virtual Address 
         * @userdata2    Base PNOR Address
         * @devdesc      PnorRP::computeDeviceAddr> Virtual Address outside
         *               known PNOR range
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        PNOR::MOD_PNORRP_COMPUTEDEVICEADDR,
                                        PNOR::RC_INVALID_ADDRESS,
                                        l_vaddr,
                                        BASE_VADDR);
        return l_err;
    }

    // find the matching section
    PNOR::SideSelect side = PNOR::SIDE_A;
    PNOR::SectionId id = PNOR::INVALID_SECTION;
    l_err = computeSection( l_vaddr, side, id );
    if( l_err )
    {
        return l_err;
    }

    // pull out the information we need to return from our global copy
    o_chip = iv_TOC[side][id].chip;
    o_ecc = iv_TOC[side][id].eccProtected;
    o_offset = l_vaddr - iv_TOC[side][id].virtAddr; //offset into pnor
    if( MMRD_MODE == i_mode )
    {
        o_offset += iv_TOC[side][id].mmrdAddr;
    }
    else
    {
        o_offset += iv_TOC[side][id].pmrwAddr;
    }

    TRACUCOMP( g_trac_pnor, "< PnorRP::computeDeviceAddr: o_offset=0x%X, o_chip=%d", o_offset, o_chip );
    return l_err;
}


/**
 * @brief  Apply ECC algorithm to data, assumes size of 1 page
 */
void PnorRP::applyECC( void* i_orig,
                       void* o_ecc )
{
    TRACFCOMP(g_trac_pnor, "> PnorRP::applyECC" );

    //@todo - fill this in
    memcpy( o_ecc, i_orig, PAGESIZE );

    TRACFCOMP(g_trac_pnor, "< PnorRP::applyECC" );
}

/**
 * @brief  Apply ECC algorithm to data, assumes logical size of 1 page
 */
errlHndl_t PnorRP::stripECC( void* i_orig,
                             void* o_data )
{
    TRACFCOMP(g_trac_pnor, "> PnorRP::stripECC" );

    //@todo - fill this in
    memcpy( o_data, i_orig, PAGESIZE );

    TRACFCOMP(g_trac_pnor, "< PnorRP::stripECC" );
    return NULL;
}

/**
 * @brief Static instance function for testcase only
 */
PnorRP& PnorRP::getInstance()
{
    return Singleton<PnorRP>::instance();
}

/**
 * @brief  Figure out which section a VA belongs to
 */
errlHndl_t PnorRP::computeSection( uint64_t i_vaddr,
                                   PNOR::SideSelect& o_side,
                                   PNOR::SectionId& o_id ) 
{
    errlHndl_t errhdl = NULL;

    o_id = PNOR::INVALID_SECTION;

    // first figure out which side it is on (slight performance boost)
    if( (i_vaddr >= SIDEA_VADDR)
        && (i_vaddr < (SIDEA_VADDR + SIDE_SIZE)) )
    {
        o_side = PNOR::SIDE_A;
    }
    else if( (i_vaddr >= SIDEB_VADDR)
             && (i_vaddr < (SIDEB_VADDR + SIDE_SIZE)) )
    {
        o_side = PNOR::SIDE_B;
    }
    else if( (i_vaddr >= SIDELESS_VADDR)
             && (i_vaddr < (SIDELESS_VADDR + SIDE_SIZE)) )
    {
        o_side = PNOR::SIDELESS;
    }
    else
    {
        TRACFCOMP( g_trac_pnor, "PnorRP::computeSection> Invalid virtual address : i_vaddr=%X", i_vaddr );
        /*@
         * @errortype
         * @moduleid     PNOR::MOD_PNORRP_COMPUTESECTION
         * @reasoncode   PNOR::RC_INVALID_ADDRESS
         * @userdata1    Requested Virtual Address
         * @userdata2    <unused>
         * @devdesc      PnorRP::computeSection> Invalid Address 
         */
        errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         PNOR::MOD_PNORRP_COMPUTESECTION,
                                         PNOR::RC_INVALID_ADDRESS,
                                         i_vaddr,
                                         0);
        return errhdl;
    }

    // loop through all sections to find a matching id
    for( PNOR::SectionId id = PNOR::FIRST_SECTION;
         id < PNOR::NUM_SECTIONS; 
         id = (PNOR::SectionId) (id + 1) )
    {
        if( (i_vaddr >= iv_TOC[o_side][id].virtAddr)
            && (i_vaddr < (iv_TOC[o_side][id].virtAddr + iv_TOC[o_side][id].size)) )
        {
            o_id = iv_TOC[o_side][id].id;
            break;
        }
    }

    return errhdl; 
}

