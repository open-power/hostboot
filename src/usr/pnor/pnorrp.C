/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnorrp.C $                                       */
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
#include "pnorrp.H"
#include <pnor/pnor_reasoncodes.H>
#include <initservice/taskargs.H>
#include <sys/msg.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>
#include <limits.h>
#include <string.h>
#include <sys/mm.h>
#include <errno.h>
#include <initservice/initserviceif.H>
#include "pnordd.H"
#include "ffs.h"   //Common header file with BuildingBlock.
#include "common/ffs_hb.H" //Hostboot definition of user data in ffs_entry struct.
#include <pnor/ecc.H>
#include <kernel/console.H>

// Trace definition
trace_desc_t* g_trac_pnor = NULL;
TRAC_INIT(&g_trac_pnor, PNOR_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW); //2K

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

/**
 * Eyecatcher strings for PNOR TOC entries
 */
const char* cv_EYECATCHER[] = {
    "part",   /**< PNOR::TOC           : Table of Contents */
    "HBI",    /**< PNOR::HB_EXT_CODE   : Hostboot Extended Image */
    "GLOBAL", /**< PNOR::GLOBAL_DATA   : Global Data */
    "HBB",    /**< PNOR::HB_BASE_CODE  : Hostboot Base Image */
    "SBEC",   /**< PNOR::CENTAUR_SBE   : Centaur Self-Boot Engine image */
    "SBE",    /**< PNOR::SBE_IPL       : Self-Boot Enginer IPL image */
    "WINK",   /**< PNOR::WINK          : Sleep Winkle Reference image */
    "PAYLOAD",/**< PNOR::PAYLOAD       : HAL/OPAL */
    "HBRT",   /**< PNOR::HB_RUNTIME    : Hostboot Runtime (for Sapphire) */
    "HBD",    /**< PNOR::HB_DATA       : Hostboot Data */
    "GUARD",  /**< PNOR::GUARD_DATA    : Hostboot Data */
    "HBEL",   /**< PNOR::HB_ERRLOGS    : Hostboot Error log Repository */
    "DJVPD",  /**< PNOR::DIMM_JEDEC_VPD: Dimm JEDEC VPD */
    "MVPD",   /**< PNOR::MODULE_VPD    : Module VPD */
    "CVPD",   /**< PNOR::CENTAUR_VPD   : Centaur VPD */
    "TEST",   /**< PNOR::TEST          : Test space for PNOR*/

    //Not currently used
//    "XXX",    /**< NUM_SECTIONS       : Used as invalid entry */
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
void PnorRP::init( errlHndl_t   &io_rtaskRetErrl )
{
    TRACUCOMP(g_trac_pnor, "PnorRP::init> " );
    uint64_t rc = 0;
    errlHndl_t  l_errl  =   NULL;

    if( Singleton<PnorRP>::instance().didStartupFail(rc) )
    {
        /*@
         *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
         *  @moduleid       PNOR::MOD_PNORRP_DIDSTARTUPFAIL
         *  @reasoncode     PNOR::RC_BAD_STARTUP_RC
         *  @userdata1      return code
         *  @userdata2      0
         *
         *  @devdesc        PNOR startup task returned an error.
         */
        l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                PNOR::MOD_PNORRP_DIDSTARTUPFAIL,
                                PNOR::RC_BAD_STARTUP_RC,
                                rc,
                                0   );
        l_errl->collectTrace(PNOR_COMP_NAME);
    }

    io_rtaskRetErrl=l_errl;
}


/********************
 Helper Methods
 ********************/

/**
 * @brief  Static function wrapper to pass into task_create
 */
void* wait_for_message( void* unused )
{
    TRACUCOMP(g_trac_pnor, "wait_for_message> " );
    Singleton<PnorRP>::instance().waitForMessage();
    return NULL;
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

    //Default to PNOR Side A for now.
    //TODO: Determine proper side  (RTC: 34764)
    iv_curSide = PNOR::SIDE_A;

    // setup everything in a separate function
    initDaemon();

    TRACFCOMP(g_trac_pnor, "< PnorRP::PnorRP : Startup Errors=%X ", iv_startupRC );
}

/**
 * @brief  Destructor
 */
PnorRP::~PnorRP()
{
    TRACFCOMP(g_trac_pnor, "PnorRP::~PnorRP> " );

    // delete the message queue we created
    if( iv_msgQ )
    {
        msg_q_destroy( iv_msgQ );
    }

    // should kill the task we spawned, but that isn't needed right now

    TRACFCOMP(g_trac_pnor, "< PnorRP::~PnorRP" );
}

/**
 * @brief Initialize the daemon
 */
void PnorRP::initDaemon()
{
    TRACUCOMP(g_trac_pnor, "PnorRP::initDaemon> " );
    errlHndl_t l_errhdl = NULL;

    do
    {
        // read the TOC in the PNOR to compute the sections
        l_errhdl = readTOC();
        if( l_errhdl )
        {
            break;
        }

        // create a message queue
        iv_msgQ = msg_q_create();

        // create a Block, passing in the message queue
        int rc = mm_alloc_block( iv_msgQ, (void*) BASE_VADDR, TOTAL_SIZE );
        if( rc )
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::initDaemon> Error from mm_alloc_block : rc=%d", rc );
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORRP_INITDAEMON
             * @reasoncode   PNOR::RC_EXTERNAL_ERROR
             * @userdata1    Requested Address
             * @userdata2    rc from mm_alloc_block
             * @devdesc      PnorRP::initDaemon> Error from mm_alloc_block
             */
            l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               PNOR::MOD_PNORRP_INITDAEMON,
                                               PNOR::RC_EXTERNAL_ERROR,
                                               TO_UINT64(BASE_VADDR),
                                               TO_UINT64(rc));
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            break;
        }

        //Register this memory range to be FLUSHed during a shutdown.
        INITSERVICE::registerBlock(reinterpret_cast<void*>(BASE_VADDR),
                                   TOTAL_SIZE,PNOR_PRIORITY);

        // Need to set permissions to R/W
        rc = mm_set_permission((void*) BASE_VADDR,TOTAL_SIZE,
                               WRITABLE | WRITE_TRACKED);



        // start task to wait on the queue
        task_create( wait_for_message, NULL );

    } while(0);

    if( l_errhdl )
    {
        errlCommit(l_errhdl,PNOR_COMP_ID);
        iv_startupRC = l_errhdl->reasonCode();
    }

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
    errlHndl_t l_errhdl = NULL;
    PNOR::SectionId id = i_section;
    PNOR::SideSelect side = i_side;

    do
    {
        if(side == PNOR::CURRENT_SIDE)
        {
            side = iv_curSide;
        }

        // Abort this operation if we had a startup failure
        uint64_t rc = 0;
        if( didStartupFail(rc) )
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::getSectionInfo> RP not properly initialized, failing : rc=%X", rc );
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORRP_GETSECTIONINFO
             * @reasoncode   PNOR::RC_STARTUP_FAIL
             * @userdata1    Requested Section
             * @userdata2    Startup RC
             * @devdesc      PnorRP::getSectionInfo> RP not properly initialized
             */
            l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               PNOR::MOD_PNORRP_GETSECTIONINFO,
                                               PNOR::RC_STARTUP_FAIL,
                                               TO_UINT64(i_section),
                                               rc);
            l_errhdl->collectTrace(PNOR_COMP_NAME);

            // set the return section to our invalid data
            id = PNOR::INVALID_SECTION;
            break;
        }

        // Zero-length means the section is invalid
        if( 0 == iv_TOC[side][id].size )
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::getSectionInfo> Invalid Section Requested : i_section=%d, side=%d", i_section, side );
            TRACFCOMP(g_trac_pnor, "o_info={ id=%d, size=%d }", iv_TOC[side][i_section].id, iv_TOC[side][i_section].size );
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORRP_GETSECTIONINFO
             * @reasoncode   PNOR::RC_INVALID_SECTION
             * @userdata1    Requested Section
             * @userdata2    Requested Side
             * @devdesc      PnorRP::getSectionInfo> Invalid Address for read/write
             */
            l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               PNOR::MOD_PNORRP_GETSECTIONINFO,
                                               PNOR::RC_INVALID_SECTION,
                                               TO_UINT64(i_section),
                                               TO_UINT64(side));
            l_errhdl->collectTrace(PNOR_COMP_NAME);

            // set the return section to our invalid data
            id = PNOR::INVALID_SECTION;
            break;
        }
    } while(0);

    if (PNOR::INVALID_SECTION != id)
    {
        TRACDCOMP( g_trac_pnor, "PnorRP::getSectionInfo: i_section=%d, side=%d : id=%d", i_section, side, iv_TOC[side][i_section].id );

        // copy my data into the external format
        o_info.id = iv_TOC[side][id].id;
        o_info.side = iv_TOC[side][id].side;
        o_info.name = cv_EYECATCHER[id];
        o_info.vaddr = iv_TOC[side][id].virtAddr;
        o_info.size = iv_TOC[side][id].size;
        o_info.eccProtected = (bool)(iv_TOC[side][id].integrity &
                                     FFS_INTEG_ECC_PROTECT);
    }

    return l_errhdl;
}


/**
 * @brief Read the TOC and store section information
 */
errlHndl_t PnorRP::readTOC()
{
    TRACUCOMP(g_trac_pnor, "PnorRP::readTOC>" );
    errlHndl_t l_errhdl = NULL;
    uint8_t* tocBuffer = NULL;
#define SIDELESS_VADDR_INDEX 2
    uint64_t nextVAddr[] = {SIDEA_VADDR, SIDEB_VADDR, SIDELESS_VADDR};
    bool fatal_error = false;

    do{
        // Zero out my table
        for( uint64_t side = 0; side < NUM_SIDES; side++ )
        {
            for( size_t id = PNOR::FIRST_SECTION;
                 id <= PNOR::NUM_SECTIONS; //include extra entry for error paths
                 ++id )
            {
                iv_TOC[side][id].id = (PNOR::SectionId)id;
                iv_TOC[side][id].side = (PNOR::SideSelect)side;
                //everything else should default to zero
            }
        }

        // Read TOC information
        // assume 1 chip with only 1 side for now, no sideless
        const uint32_t cur_side = PNOR::SIDE_A;

        // TOC starts at offset zero

        tocBuffer = new uint8_t[PAGESIZE];
        l_errhdl = readFromDevice( FFS_TABLE_BASE_ADDR, 0, false,
                                   tocBuffer, fatal_error );
        if( l_errhdl ) { break; }

        ffs_hdr* l_ffs_hdr = (ffs_hdr*) tocBuffer;

        //TODO: verify checksum of header  RTC: 44147

        TRACFCOMP(g_trac_pnor, "PnorRp::readTOC:  FFS Block size = 0x%.8X, Partition Table Size = 0x%.8x, entry_count=%d",
                  l_ffs_hdr->block_size, l_ffs_hdr->size, l_ffs_hdr->entry_count);

        uint64_t spaceUsed = (sizeof(ffs_entry))*l_ffs_hdr->entry_count;

        /* Checking FFS Header to make sure it looks valid */
        bool header_good = true;
        if(l_ffs_hdr->magic != FFS_MAGIC)
        {
            TRACFCOMP(g_trac_pnor, "E>PnorRp::readTOC:  Invalid magic number in FFS header: 0x%.4X",
                      l_ffs_hdr->magic);
            header_good = false;
        }
        else if(l_ffs_hdr->version != SUPPORTED_FFS_VERSION)
        {
            TRACFCOMP(g_trac_pnor, "E>PnorRp::readTOC:  Unsupported FFS Header version: 0x%.4X",
                      l_ffs_hdr->version);
            header_good = false;
        }
        else if(l_ffs_hdr->entry_size != sizeof(ffs_entry))
        {
            TRACFCOMP(g_trac_pnor, "E>PnorRp::readTOC:  Unexpected entry_size(0x%.8x) in FFS header: 0x%.4X", l_ffs_hdr->entry_size);
            header_good = false;
        }
        else if(l_ffs_hdr->entries == NULL)
        {
            TRACFCOMP(g_trac_pnor, "E>PnorRp::readTOC:  FFS Header pointer to entries is NULL.");
            header_good = false;
        }
        else if(l_ffs_hdr->block_size != PAGESIZE)
        {
            TRACFCOMP(g_trac_pnor, "E>PnorRp::readTOC:  Unsupported Block Size(0x%.4X). PNOR Blocks must be 4k",
                      l_ffs_hdr->block_size);
            header_good = false;
        }
        else if(l_ffs_hdr->block_count == 0)
        {
            TRACFCOMP(g_trac_pnor, "E>PnorRp::readTOC:  Unsupported BLock COunt(0x%.4X). Device cannot be zero blocks in length.",
                      l_ffs_hdr->block_count);
            header_good = false;
        }
        //Make sure all the entries fit in specified partition table size.
        else if(spaceUsed >
                ((l_ffs_hdr->block_size * l_ffs_hdr->size) - sizeof(ffs_hdr)))
        {
            TRACFCOMP(g_trac_pnor, "E>PnorRp::readTOC:  FFS Entries (0x%.16X) go past end of FFS Table.",
                      spaceUsed);
            crit_assert(0);
        }

        if(!header_good)
        {
            //Shutdown if we detected a partition table issue for any reason
            INITSERVICE::doShutdown( PNOR::RC_PARTITION_TABLE_INVALID);
        }

        ffs_hb_user_t* ffsUserData = NULL;

        //Walk through all the entries in the table and parse the data.
        ffs_entry* cur_entry = (l_ffs_hdr->entries);

        for(uint32_t i=0; i<l_ffs_hdr->entry_count; i++)
        {
            TRACUCOMP(g_trac_pnor, "PnorRp::readTOC:  Entry %d, name=%s, pointer=0x%X", i, cur_entry->name, (uint64_t)cur_entry);

            //TODO: verify checksum of entry   RTC: 44147

            uint32_t secId = PNOR::INVALID_SECTION;

            //Figure out section enum
            for(uint32_t eyeIndex=PNOR::TOC; eyeIndex < PNOR::NUM_SECTIONS; eyeIndex++)
            {
                if(strcmp(cv_EYECATCHER[eyeIndex], cur_entry->name) == 0)
                {
                    secId = eyeIndex;
                    TRACUCOMP(g_trac_pnor, "PnorRp::readTOC: sectionId=%d", secId);
                    break;
                }
            }

            if(secId == PNOR::INVALID_SECTION)
            {
                TRACFCOMP(g_trac_pnor, "PnorRp::readTOC:  Unrecognized Section name(%s), skipping", cur_entry->name);
                continue;
            }

            ffsUserData = (ffs_hb_user_t*)&(cur_entry->user);

            //size
            iv_TOC[cur_side][secId].size = ((uint64_t)cur_entry->size)*PAGESIZE;


            //virtAddr
            //The PNOR data is broken up into 3 blocks of Virtual Addresses, A, B, and Sideless.
            //For Sections found to be sideless, both PNOR sides will map to the same virtual address.
            //TODO RTC: 34764, remove VADDR ranges for SIDE B & SIDELESS
            iv_TOC[cur_side][secId].virtAddr = nextVAddr[cur_side];
            nextVAddr[cur_side] += iv_TOC[cur_side][secId].size;

            //flashAddr
            iv_TOC[cur_side][secId].flashAddr = ((uint64_t)cur_entry->base)*PAGESIZE;

            //chipSelect
            iv_TOC[cur_side][secId].chip = ffsUserData->chip;

            //user data
            iv_TOC[cur_side][secId].integrity = ffsUserData->dataInteg;
            iv_TOC[cur_side][secId].version = ffsUserData->verCheck;
            iv_TOC[cur_side][secId].misc = ffsUserData->miscFlags;

            TRACFCOMP(g_trac_pnor, "PnorRp::readTOC: User Data %s", cur_entry->name);
            TRACFBIN(g_trac_pnor, "PnorRp::readTOC: Bin Dump",ffsUserData, sizeof(ffs_hb_user_t) );

            if (iv_TOC[cur_side][secId].version == FFS_VERS_SHA512)
            {
                TRACFCOMP(g_trac_pnor, "PnorRp::readTOC: Incrementing Flash Address for SHA Header");
                if (iv_TOC[cur_side][secId].integrity == FFS_INTEG_ECC_PROTECT)
                {
                    iv_TOC[cur_side][secId].flashAddr += (PAGESIZE*9)/8;
                }
                else
                {
                    iv_TOC[cur_side][secId].flashAddr += PAGESIZE;
                }
            }

            if((iv_TOC[cur_side][secId].flashAddr + iv_TOC[cur_side][secId].size) > (l_ffs_hdr->block_count*PAGESIZE))
            {
                TRACFCOMP(g_trac_pnor, "E>PnorRp::readTOC:  Partition(%s) at base address (0x%.8x) extends past end of flash device",
                          cur_entry->name, iv_TOC[cur_side][secId].flashAddr);
                INITSERVICE::doShutdown( PNOR::RC_PARTITION_TABLE_INVALID);
            }

            cur_entry++;
        }

        //keep these traces here until PNOR is rock-solid
        for(PNOR::SectionId tmpId = PNOR::FIRST_SECTION;
            tmpId < PNOR::NUM_SECTIONS;
            tmpId = (PNOR::SectionId) (tmpId + 1) )
        {
            TRACFCOMP(g_trac_pnor, "%s:    size=0x%.8X  flash=0x%.8X  virt=0x%.16X", cv_EYECATCHER[tmpId], iv_TOC[PNOR::SIDE_A][tmpId].size, iv_TOC[PNOR::SIDE_A][tmpId].flashAddr, iv_TOC[PNOR::SIDE_A][tmpId].virtAddr );
        }

    }while(0);

    if(tocBuffer != NULL)
    {
        TRACUCOMP(g_trac_pnor, "Deleting tocBuffer");
        delete[] tocBuffer;
    }

    TRACUCOMP(g_trac_pnor, "< PnorRP::readTOC" );
    return l_errhdl;
}



/**
 * @brief  Message receiver
 */
void PnorRP::waitForMessage()
{
    TRACFCOMP(g_trac_pnor, "PnorRP::waitForMessage>" );

    errlHndl_t l_errhdl = NULL;
    msg_t* message = NULL;
    uint8_t* user_addr = NULL;
    uint8_t* eff_addr = NULL;
    uint64_t dev_offset = 0;
    uint64_t chip_select = 0xF;
    bool needs_ecc = false;
    int rc = 0;
    uint64_t status_rc = 0;
    bool fatal_error = false;

    while(1)
    {
        status_rc = 0;
        TRACUCOMP(g_trac_pnor, "PnorRP::waitForMessage> waiting for message" );
        message = msg_wait( iv_msgQ );
        if( message )
        {
            /*  data[0] = virtual address requested
             *  data[1] = address to place contents
             */
            eff_addr = (uint8_t*)message->data[0];
            user_addr = (uint8_t*)message->data[1];

            //figure out the real pnor offset
            l_errhdl = computeDeviceAddr( eff_addr, dev_offset, chip_select, needs_ecc );
            if( l_errhdl )
            {
                status_rc = -EFAULT; /* Bad address */
            }
            else
            {
                switch(message->type)
                {
                    case( MSG_MM_RP_READ ):
                        l_errhdl = readFromDevice( dev_offset,
                                                   chip_select,
                                                   needs_ecc,
                                                   user_addr,
                                                   fatal_error );
                        if( l_errhdl || fatal_error )
                        {
                            status_rc = -EIO; /* I/O error */
                        }
                        break;
                    case( MSG_MM_RP_WRITE ):
                        l_errhdl = writeToDevice( dev_offset, chip_select, needs_ecc, user_addr );
                        if( l_errhdl )
                        {
                            status_rc = -EIO; /* I/O error */
                        }
                        break;
                    default:
                        TRACFCOMP( g_trac_pnor, "PnorRP::waitForMessage> Unrecognized message type : user_addr=%p, eff_addr=%p, msgtype=%d", user_addr, eff_addr, message->type );
                        /*@
                         * @errortype
                         * @moduleid     PNOR::MOD_PNORRP_WAITFORMESSAGE
                         * @reasoncode   PNOR::RC_INVALID_MESSAGE_TYPE
                         * @userdata1    Message type
                         * @userdata2    Requested Virtual Address
                         * @devdesc      PnorRP::waitForMessage> Unrecognized message type
                         */
                        l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                        PNOR::MOD_PNORRP_WAITFORMESSAGE,
                                                        PNOR::RC_INVALID_MESSAGE_TYPE,
                                                        TO_UINT64(message->type),
                                                        (uint64_t)eff_addr);
                        l_errhdl->collectTrace(PNOR_COMP_NAME);
                        status_rc = -EINVAL; /* Invalid argument */
                }
            }

            if( !l_errhdl && msg_is_async(message) )
            {
                TRACFCOMP( g_trac_pnor, "PnorRP::waitForMessage> Unsupported Asynchronous Message  : user_addr=%p, eff_addr=%p, msgtype=%d", user_addr, eff_addr, message->type );
                /*@
                 * @errortype
                 * @moduleid     PNOR::MOD_PNORRP_WAITFORMESSAGE
                 * @reasoncode   PNOR::RC_INVALID_ASYNC_MESSAGE
                 * @userdata1    Message type
                 * @userdata2    Requested Virtual Address
                 * @devdesc      PnorRP::waitForMessage> Unrecognized message type
                 */
                l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                   PNOR::MOD_PNORRP_WAITFORMESSAGE,
                                                   PNOR::RC_INVALID_ASYNC_MESSAGE,
                                                   TO_UINT64(message->type),
                                                   (uint64_t)eff_addr);
                l_errhdl->collectTrace(PNOR_COMP_NAME);
                status_rc = -EINVAL; /* Invalid argument */
            }

            if( l_errhdl )
            {
                errlCommit(l_errhdl,PNOR_COMP_ID);
            }


            /*  Expected Response:
             *      data[0] = virtual address requested
             *      data[1] = rc (0 or negative errno value)
             */
            message->data[1] = status_rc;
            rc = msg_respond( iv_msgQ, message );
            if( rc )
            {
                TRACFCOMP(g_trac_pnor, "PnorRP::waitForMessage> Error from msg_respond, giving up : rc=%d", rc );
                break;
            }
        }
    }


    TRACFCOMP(g_trac_pnor, "< PnorRP::waitForMessage" );
}


/**
 * @brief  Retrieve 1 page of data from the PNOR device
 */
errlHndl_t PnorRP::readFromDevice( uint64_t i_offset,
                                   uint64_t i_chip,
                                   bool i_ecc,
                                   void* o_dest,
                                   bool& o_fatalError )
{
    TRACUCOMP(g_trac_pnor, "PnorRP::readFromDevice> i_offset=0x%X, i_chip=%d", i_offset, i_chip );
    errlHndl_t l_errhdl = NULL;
    uint8_t* ecc_buffer = NULL;
    o_fatalError = false;

    do
    {
        TARGETING::Target* pnor_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        // assume a single page
        void* data_to_read = o_dest;
        size_t read_size = PAGESIZE;

        // if we need to handle ECC we need to read more than 1 page
        if( i_ecc )
        {
            ecc_buffer = new uint8_t[PAGESIZE_PLUS_ECC]();
            data_to_read = ecc_buffer;
            read_size = PAGESIZE_PLUS_ECC;
        }

        // get the data from the PNOR DD
        l_errhdl = DeviceFW::deviceRead(pnor_target,
                                        data_to_read,
                                        read_size,
                                        DEVICE_PNOR_ADDRESS(i_chip,i_offset) );
        if( l_errhdl )
        {
            TRACFCOMP(g_trac_pnor, "PnorRP::readFromDevice> Error from device : RC=%X", l_errhdl->reasonCode() );
            break;
        }

        // remove the ECC data
        if( i_ecc )
        {
            // remove the ECC and fix the original data if it is broken
            PNOR::ECC::eccStatus ecc_stat =
              PNOR::ECC::removeECC( reinterpret_cast<uint8_t*>(data_to_read),
                                    reinterpret_cast<uint8_t*>(o_dest),
                                    PAGESIZE );

            // create an error if we couldn't correct things
            if( ecc_stat == PNOR::ECC::UNCORRECTABLE )
            {
                TRACFCOMP( g_trac_pnor, "PnorRP::readFromDevice> Uncorrectable ECC error : chip=%d, offset=0x%.X", i_chip, i_offset );

                // Need to shutdown here instead of creating an error log
                //  because the bad page could be critical to the regular
                //  error handling path and cause an infinite loop.
                // Also need to spawn a separate task to do the shutdown
                //  so that the regular PNOR task can service the writes
                //  that happen during shutdown.
                o_fatalError = true;
                INITSERVICE::doShutdown( PNOR::RC_ECC_UE, true );
            }
            // found an error so we need to fix something
            else if( ecc_stat != PNOR::ECC::CLEAN )
            {
                TRACFCOMP( g_trac_pnor, "PnorRP::readFromDevice> Correctable ECC error : chip=%d, offset=0x%.X", i_chip, i_offset );

                // need to write good data back to PNOR
                l_errhdl = DeviceFW::deviceWrite(pnor_target,
                                       data_to_read,//corrected data
                                       read_size,
                                       DEVICE_PNOR_ADDRESS(i_chip,i_offset) );
                if( l_errhdl )
                {
                    TRACFCOMP(g_trac_pnor, "PnorRP::readFromDevice> Error writing corrected data back to device : RC=%X", l_errhdl->reasonCode() );
                    // we don't need to fail here since we can correct
                    //  it the next time we read it again, instead just
                    //  commit the log here
                    errlCommit(l_errhdl,PNOR_COMP_ID);
                }

                // keep some stats here in case we want them someday
                //no need for mutex since only ever 1 thread accessing this
                iv_stats[i_offset/PAGESIZE].numCEs++;
            }
        }
    } while(0);

    if( ecc_buffer )
    {
        delete[] ecc_buffer;
    }

    TRACUCOMP(g_trac_pnor, "< PnorRP::readFromDevice" );
    return l_errhdl;
}

/**
 * @brief  Write 1 page of data to the PNOR device
 */
errlHndl_t PnorRP::writeToDevice( uint64_t i_offset,
                                  uint64_t i_chip,
                                  bool i_ecc,
                                  void* i_src )
{
    TRACUCOMP(g_trac_pnor, "PnorRP::writeToDevice> i_offset=%X, i_chip=%d", i_offset, i_chip );
    errlHndl_t l_errhdl = NULL;
    uint8_t* ecc_buffer = NULL;

    do
    {
        TARGETING::Target* pnor_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        // assume a single page to write
        void* data_to_write = i_src;
        size_t write_size = PAGESIZE;

        // apply ECC to data if needed
        if( i_ecc )
        {
            ecc_buffer = new uint8_t[PAGESIZE_PLUS_ECC];
            PNOR::ECC::injectECC( reinterpret_cast<uint8_t*>(i_src),
                                  PAGESIZE,
                                  reinterpret_cast<uint8_t*>(ecc_buffer) );
            data_to_write = reinterpret_cast<void*>(ecc_buffer);
            write_size = PAGESIZE_PLUS_ECC;
        }

        //no need for mutex since only ever a singleton object
        iv_stats[i_offset/PAGESIZE].numWrites++;

        // write the data out to the PNOR DD
        errlHndl_t l_errhdl = DeviceFW::deviceWrite( pnor_target,
                                       data_to_write,
                                       write_size,
                                       DEVICE_PNOR_ADDRESS(i_chip,i_offset) );
        if( l_errhdl )
        {
            TRACFCOMP(g_trac_pnor, "PnorRP::writeToDevice> Error from device : RC=%X", l_errhdl->reasonCode() );
            break;
        }
    } while(0);

    if( ecc_buffer )
    {
        delete[] ecc_buffer;
    }

    TRACUCOMP(g_trac_pnor, "< PnorRP::writeToDevice" );
    return l_errhdl;
}

/**
 * @brief  Convert a virtual address into the PNOR device address
 */
errlHndl_t PnorRP::computeDeviceAddr( void* i_vaddr,
                                      uint64_t& o_offset,
                                      uint64_t& o_chip,
                                      bool& o_ecc )
{
    errlHndl_t l_errhdl = NULL;
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
         * @reasoncode   PNOR::RC_INVALID_ADDRESS
         * @userdata1    Virtual Address
         * @userdata2    Base PNOR Address
         * @devdesc      PnorRP::computeDeviceAddr> Virtual Address outside
         *               known PNOR range
         */
        l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        PNOR::MOD_PNORRP_COMPUTEDEVICEADDR,
                                        PNOR::RC_INVALID_ADDRESS,
                                        l_vaddr,
                                        BASE_VADDR);
        l_errhdl->collectTrace(PNOR_COMP_NAME);
        return l_errhdl;
    }

    // find the matching section
    PNOR::SideSelect side = PNOR::SIDE_A;
    PNOR::SectionId id = PNOR::INVALID_SECTION;
    l_errhdl = computeSection( l_vaddr, side, id );
    if( l_errhdl )
    {
        return l_errhdl;
    }

    // pull out the information we need to return from our global copy
    o_chip = iv_TOC[side][id].chip;
    o_ecc = (bool)(iv_TOC[side][id].integrity & FFS_INTEG_ECC_PROTECT);
    o_offset = l_vaddr - iv_TOC[side][id].virtAddr; //offset into section

    // for ECC we need to figure out where the ECC-enhanced offset is
    //  before tacking on the offset to the section
    if( o_ecc )
    {
        o_offset = (o_offset * 9) / 8;
    }
    // add on the offset of the section itself
    o_offset += iv_TOC[side][id].flashAddr;

    TRACUCOMP( g_trac_pnor, "< PnorRP::computeDeviceAddr: i_vaddr=%X, o_offset=0x%X, o_chip=%d", l_vaddr, o_offset, o_chip );
    return l_errhdl;
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

    do {
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
            o_side = iv_curSide;
        }
        else
        {
            //break to send down error path
            break;
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

    }while(0);

    if(o_id == PNOR::INVALID_SECTION)
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
        errhdl->collectTrace(PNOR_COMP_NAME);
        return errhdl;
    }


    return errhdl;
}

