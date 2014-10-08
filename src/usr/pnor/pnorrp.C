/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnorrp.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
#include <endian.h>
#include <util/align.H>

// Trace definition
trace_desc_t* g_trac_pnor = NULL;
TRAC_INIT(&g_trac_pnor, PNOR_COMP_NAME, 4*KILOBYTE, TRACE::BUFFER_SLOW); //2K

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

/**
 * Eyecatcher strings for PNOR TOC entries
 */
const char* cv_EYECATCHER[] = {
    "part",     /**< PNOR::TOC            : Table of Contents */
    "HBI",      /**< PNOR::HB_EXT_CODE    : Hostboot Extended Image */
    "GLOBAL",   /**< PNOR::GLOBAL_DATA    : Global Data */
    "HBB",      /**< PNOR::HB_BASE_CODE   : Hostboot Base Image */
    "SBEC",     /**< PNOR::CENTAUR_SBE    : Centaur Self-Boot Engine image */
    "SBE",      /**< PNOR::SBE_IPL        : Self-Boot Enginer IPL image */
    "WINK",     /**< PNOR::WINK           : Sleep Winkle Reference image */
    "PAYLOAD",  /**< PNOR::PAYLOAD        : HAL/OPAL */
    "HBRT",     /**< PNOR::HB_RUNTIME     : Hostboot Runtime (for Sapphire) */
    "HBD",      /**< PNOR::HB_DATA        : Hostboot Data */
    "GUARD",    /**< PNOR::GUARD_DATA     : Hostboot Data */
    "HBEL",     /**< PNOR::HB_ERRLOGS     : Hostboot Error log Repository */
    "DJVPD",    /**< PNOR::DIMM_JEDEC_VPD : Dimm JEDEC VPD */
    "MVPD",     /**< PNOR::MODULE_VPD     : Module VPD */
    "CVPD",     /**< PNOR::CENTAUR_VPD    : Centaur VPD */
    "ATTROVER", /**< PNOR::ATTR_OVER      : Attribute Override */
    "NVRAM",    /**< PNOR::NVRAM         : OPAL Storage */
    "OCC",      /**< PNOR::OCC            : OCC LID */
    "TEST",     /**< PNOR::TEST           : Test space for PNOR*/

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
                                 PNOR::SectionInfo_t& o_info )
{
    return Singleton<PnorRP>::instance().getSectionInfo(i_section,o_info);
}

namespace PNOR
{

/**
 * @brief calculates the checksum on data(ffs header/entry) and will return
 *    0 if the checksums match
 */
uint32_t pnor_ffs_checksum(void* data, size_t size)
{
    uint32_t checksum = 0;

    for (size_t i = 0; i < (size/4); i++)
    {
        checksum ^= ((uint32_t*)data)[i];
    }

    checksum = htobe32(checksum);
    return checksum;
}

};

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
         * @custdesc    A problem occurred while accessing the boot flash.
         */
        l_errl = new ERRORLOG::ErrlEntry(
                                         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                PNOR::MOD_PNORRP_DIDSTARTUPFAIL,
                                PNOR::RC_BAD_STARTUP_RC,
                                rc,
                                0,
                                true /*Add HB SW Callout*/ );

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
: iv_TOC_used(0)
,iv_msgQ(NULL)
,iv_startupRC(0)
{
    TRACFCOMP(g_trac_pnor, "PnorRP::PnorRP> " );
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
             * @custdesc    A problem occurred while accessing the boot flash.
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           PNOR::MOD_PNORRP_INITDAEMON,
                           PNOR::RC_EXTERNAL_ERROR,
                           TO_UINT64(BASE_VADDR),
                           TO_UINT64(rc),
                           true /*Add HB SW Callout*/);
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
        iv_startupRC = l_errhdl->reasonCode();
        errlCommit(l_errhdl,PNOR_COMP_ID);
    }

    // call ErrlManager function - tell him that PNOR is ready!
    ERRORLOG::ErrlManager::errlResourceReady(ERRORLOG::PNOR);

    TRACUCOMP(g_trac_pnor, "< PnorRP::initDaemon" );
}


/**
 * @brief  Return the size and address of a given section of PNOR data
 */
errlHndl_t PnorRP::getSectionInfo( PNOR::SectionId i_section,
                                   PNOR::SectionInfo_t& o_info )
{
    //TRACDCOMP(g_trac_pnor, "PnorRP::getSectionInfo> i_section=%d", i_section );
    errlHndl_t l_errhdl = NULL;
    PNOR::SectionId id = i_section;

    do
    {
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
             * @custdesc    A problem occurred while accessing the boot flash.
             */
            l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               PNOR::MOD_PNORRP_GETSECTIONINFO,
                                               PNOR::RC_STARTUP_FAIL,
                                               TO_UINT64(i_section),
                                               rc,
                                               true /*Add HB SW Callout*/);
            l_errhdl->collectTrace(PNOR_COMP_NAME);

            // set the return section to our invalid data
            id = PNOR::INVALID_SECTION;
            break;
        }

        // Zero-length means the section is invalid
        if( 0 == iv_TOC[id].size )
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::getSectionInfo> Invalid Section Requested : i_section=%d", i_section );
            TRACFCOMP(g_trac_pnor, "o_info={ id=%d, size=%d }", iv_TOC[i_section].id, iv_TOC[i_section].size );
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORRP_GETSECTIONINFO
             * @reasoncode   PNOR::RC_INVALID_SECTION
             * @userdata1    Requested Section
             * @userdata2    TOC used
             * @devdesc      PnorRP::getSectionInfo> Invalid Address for read/write
             * @custdesc    A problem occurred while accessing the boot flash.
            */
            l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               PNOR::MOD_PNORRP_GETSECTIONINFO,
                                               PNOR::RC_INVALID_SECTION,
                                               TO_UINT64(i_section),
                                               iv_TOC_used,
                                               true /*Add HB SW Callout*/);
            l_errhdl->collectTrace(PNOR_COMP_NAME);

            // set the return section to our invalid data
            id = PNOR::INVALID_SECTION;
            break;
        }
    } while(0);

    if (PNOR::INVALID_SECTION != id)
    {
        TRACDCOMP( g_trac_pnor, "PnorRP::getSectionInfo: i_section=%d, id=%d", i_section, iv_TOC[i_section].id );

        // copy my data into the external format
        o_info.id = iv_TOC[id].id;
        o_info.name = cv_EYECATCHER[id];
        o_info.vaddr = iv_TOC[id].virtAddr;
        o_info.size = iv_TOC[id].size;
        o_info.eccProtected = ((iv_TOC[id].integrity & FFS_INTEG_ECC_PROTECT)
                                != 0) ? true : false;
        o_info.sha512Version = ((iv_TOC[id].version & FFS_VERS_SHA512)
                                 != 0) ? true : false;
        o_info.sha512perEC = ((iv_TOC[id].version & FFS_VERS_SHA512_PER_EC)
                               != 0) ? true : false;
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
    uint64_t fatal_error = 0;
    bool TOC_0_failed = false;

    do{
        iv_TOC_used = 0;

        for (uint32_t cur_TOC = 0; cur_TOC < NUM_TOCS; ++cur_TOC)
        {
            TRACFCOMP(g_trac_pnor, "PnorRP::readTOC verifying TOC: %d",cur_TOC);
            uint64_t nextVAddr = BASE_VADDR;

            // Zero out my table
            for( size_t id = PNOR::FIRST_SECTION;
                 id <= PNOR::NUM_SECTIONS; //include extra entry for error paths
                 ++id )
            {
                iv_TOC[id].id = (PNOR::SectionId)id;
                //everything else should default to zero
            }

            // Read TOC information from TOC 0 and then TOC 1
            tocBuffer = new uint8_t[PAGESIZE];
            if (cur_TOC == 0)
            {
                l_errhdl = readFromDevice( TOC_0_OFFSET, 0, false,
                                           tocBuffer, fatal_error );
            }
            else if (cur_TOC == 1)
            {
                l_errhdl = readFromDevice( TOC_1_OFFSET, 0, false,
                                           tocBuffer, fatal_error );
            }

            if( l_errhdl )
            {
                TRACFCOMP(g_trac_pnor, "PnorRP::readTOC readFromDevice Failed.");
                break;
            }

            ffs_hdr* l_ffs_hdr = (ffs_hdr*) tocBuffer;

            // ffs entry check, 0 if checksums match
            if( PNOR::pnor_ffs_checksum(l_ffs_hdr, FFS_HDR_SIZE) != 0)
            {
                //@TODO - RTC:90780 - May need to handle this differently in SP-less config
                TRACFCOMP(g_trac_pnor, "PnorRP::readTOC pnor_ffs_checksum header checksums do not match.");
                if (cur_TOC == 0)
                {
                    TRACFCOMP(g_trac_pnor, "PnorRP::readTOC TOC 0 failed header checksum");
                    TOC_0_failed = true;
                    iv_TOC_used = 1;
                    continue;
                }
                else if (cur_TOC == 1 && TOC_0_failed)
                {
                    // Both TOC's failed
                    TRACFCOMP(g_trac_pnor, "PnorRP::readTOC both TOC's are corrupted");
                    INITSERVICE::doShutdown( PNOR::RC_PARTITION_TABLE_INVALID);
                }
                else
                {
                    // TOC 1 failed
                    TRACFCOMP(g_trac_pnor, "PnorRP::readTOC TOC 1 failed header checksum");
                    break;
                }
            }

            // Only check header if on first TOC or the first TOC failed
            if (cur_TOC == 0 || TOC_0_failed)
            {
                TRACFCOMP(g_trac_pnor, "PnorRP::readTOC:  FFS Block size = 0x%.8X, Partition Table Size = 0x%.8x, entry_count=%d",
                          l_ffs_hdr->block_size, l_ffs_hdr->size, l_ffs_hdr->entry_count);

                uint64_t spaceUsed = (sizeof(ffs_entry))*l_ffs_hdr->entry_count;

                /* Checking FFS Header to make sure it looks valid */
                bool header_good = true;
                if(l_ffs_hdr->magic != FFS_MAGIC)
                {
                    TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC:  Invalid magic number in FFS header: 0x%.4X",
                              l_ffs_hdr->magic);
                    header_good = false;
                }
                else if(l_ffs_hdr->version != SUPPORTED_FFS_VERSION)
                {
                    TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC:  Unsupported FFS Header version: 0x%.4X",
                              l_ffs_hdr->version);
                    header_good = false;
                }
                else if(l_ffs_hdr->entry_size != sizeof(ffs_entry))
                {
                    TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC:  Unexpected entry_size(0x%.8x) in FFS header: 0x%.4X", l_ffs_hdr->entry_size);
                    header_good = false;
                }
                else if(l_ffs_hdr->entries == NULL)
                {
                    TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC:  FFS Header pointer to entries is NULL.");
                    header_good = false;
                }
                else if(l_ffs_hdr->block_size != PAGESIZE)
                {
                    TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC:  Unsupported Block Size(0x%.4X). PNOR Blocks must be 4k",
                              l_ffs_hdr->block_size);
                    header_good = false;
                }
                else if(l_ffs_hdr->block_count == 0)
                {
                    TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC:  Unsupported BLock COunt(0x%.4X). Device cannot be zero blocks in length.",
                              l_ffs_hdr->block_count);
                    header_good = false;
                }
                //Make sure all the entries fit in specified partition table size.
                else if(spaceUsed >
                        ((l_ffs_hdr->block_size * l_ffs_hdr->size) - sizeof(ffs_hdr)))
                {
                    TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC:  FFS Entries (0x%.16X) go past end of FFS Table.",
                              spaceUsed);
                    header_good = false;
                }

                if(!header_good)
                {
                    //Shutdown if we detected a partition table issue for any reason
                    if (TOC_0_failed)
                    {
                        INITSERVICE::doShutdown( PNOR::RC_PARTITION_TABLE_INVALID);
                    }
                    else
                    {
                        TOC_0_failed = true;
                    }
                    //Try TOC1
                    continue;
                }
            }

            ffs_hb_user_t* ffsUserData = NULL;

            //Walk through all the entries in the table and parse the data.
            for(uint32_t i=0; i<l_ffs_hdr->entry_count; i++)
            {
                ffs_entry* cur_entry = (&l_ffs_hdr->entries[i]);

                TRACUCOMP(g_trac_pnor, "PnorRP::readTOC:  Entry %d, name=%s, pointer=0x%X", i, cur_entry->name, (uint64_t)cur_entry);

                uint32_t secId = PNOR::INVALID_SECTION;

                // ffs entry check, 0 if checksums match
                if( PNOR::pnor_ffs_checksum(cur_entry, FFS_ENTRY_SIZE) != 0)
                {
                    //@TODO - RTC:90780 - May need to handle this differently in SP-less config
                    TRACFCOMP(g_trac_pnor, "PnorRP::readTOC pnor_ffs_checksum entry checksums do not match.");
                    if (cur_TOC == 0)
                    {
                        TRACFCOMP(g_trac_pnor, "PnorRP::readTOC TOC 0 entry checksum failed");
                        TOC_0_failed = true;
                        iv_TOC_used = 1;
                        break;
                    }
                    else if (cur_TOC == 1 && TOC_0_failed)
                    {
                        // Both TOC's failed
                        TRACFCOMP(g_trac_pnor, "PnorRP::readTOC both TOC's are corrupted");
                        INITSERVICE::doShutdown( PNOR::RC_PARTITION_TABLE_INVALID);
                    }
                    else
                    {
                        // TOC 1 failed
                        TRACFCOMP(g_trac_pnor, "PnorRP::readTOC TOC 1 entry checksum failed");
                        break;
                    }
                }

                // Only set data if on first TOC or the first TOC failed
                if (cur_TOC == 0 || TOC_0_failed)
                {
                    //Figure out section enum
                    for(uint32_t eyeIndex=PNOR::TOC; eyeIndex < PNOR::NUM_SECTIONS; eyeIndex++)
                    {
                        if(strcmp(cv_EYECATCHER[eyeIndex], cur_entry->name) == 0)
                        {
                            secId = eyeIndex;
                            TRACUCOMP(g_trac_pnor, "PnorRP::readTOC: sectionId=%d", secId);
                            break;
                        }
                    }

                    if(secId == PNOR::INVALID_SECTION)
                    {
                        TRACFCOMP(g_trac_pnor, "PnorRP::readTOC:  Unrecognized Section name(%s), skipping", cur_entry->name);
                        continue;
                    }

                    ffsUserData = (ffs_hb_user_t*)&(cur_entry->user);

                    //size
                    iv_TOC[secId].size = ((uint64_t)cur_entry->size)*PAGESIZE;

                    //virtAddr
                    iv_TOC[secId].virtAddr = nextVAddr;
                    nextVAddr += iv_TOC[secId].size;

                    //flashAddr
                    iv_TOC[secId].flashAddr = ((uint64_t)cur_entry->base)*PAGESIZE;

                    //chipSelect
                    iv_TOC[secId].chip = ffsUserData->chip;

                    //user data
                    iv_TOC[secId].integrity = ffsUserData->dataInteg;
                    iv_TOC[secId].version = ffsUserData->verCheck;
                    iv_TOC[secId].misc = ffsUserData->miscFlags;

                    TRACFCOMP(g_trac_pnor, "PnorRp::readTOC: User Data %s", cur_entry->name);

                    if (iv_TOC[secId].integrity == FFS_INTEG_ECC_PROTECT)
                    {
                        TRACFCOMP(g_trac_pnor, "PnorRP::readTOC: ECC enabled for %s", cur_entry->name);
                        iv_TOC[secId].size = ALIGN_PAGE_DOWN((iv_TOC[secId].size * 8 ) / 9);
                    }

                    // TODO RTC:96009 handle version header w/secureboot
                    if (iv_TOC[secId].version == FFS_VERS_SHA512)
                    {
                        TRACFCOMP(g_trac_pnor, "PnorRP::readTOC: Incrementing Flash Address for SHA Header");
                        if (iv_TOC[secId].integrity == FFS_INTEG_ECC_PROTECT)
                        {
                            iv_TOC[secId].flashAddr += PAGESIZE_PLUS_ECC;
                        }
                        else
                        {
                            iv_TOC[secId].flashAddr += PAGESIZE;
                        }
                    }

                    if((iv_TOC[secId].flashAddr + iv_TOC[secId].size) > (l_ffs_hdr->block_count*PAGESIZE))
                    {
                        TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC:  Partition(%s) at base address (0x%.8x) extends past end of flash device",
                                  cur_entry->name, iv_TOC[secId].flashAddr);
                        INITSERVICE::doShutdown( PNOR::RC_PARTITION_TABLE_INVALID);
                    }
                }
            }

            //keep these traces here until PNOR is rock-solid
            for(PNOR::SectionId tmpId = PNOR::FIRST_SECTION;
                tmpId < PNOR::NUM_SECTIONS;
                tmpId = (PNOR::SectionId) (tmpId + 1) )
            {
                TRACFCOMP(g_trac_pnor, "%s:    size=0x%.8X  flash=0x%.8X  virt=0x%.16X", cv_EYECATCHER[tmpId], iv_TOC[tmpId].size, iv_TOC[tmpId].flashAddr, iv_TOC[tmpId].virtAddr );
            }
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
    uint64_t fatal_error = 0;

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
                        if( l_errhdl || ( 0 != fatal_error ) )
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
                         * @devdesc      PnorRP::waitForMessage> Unrecognized
                         *               message type
                         * @custdesc     A problem occurred while accessing
                         *               the boot flash.
                         */
                        l_errhdl = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           PNOR::MOD_PNORRP_WAITFORMESSAGE,
                                           PNOR::RC_INVALID_MESSAGE_TYPE,
                                           TO_UINT64(message->type),
                                           (uint64_t)eff_addr,
                                           true /*Add HB SW Callout*/);
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
                 * @devdesc      PnorRP::waitForMessage> Unrecognized message
                 *               type
                 * @custdesc     A problem occurred while accessing the boot
                 *               flash.
                 */
                l_errhdl = new ERRORLOG::ErrlEntry(
                                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         PNOR::MOD_PNORRP_WAITFORMESSAGE,
                                         PNOR::RC_INVALID_ASYNC_MESSAGE,
                                         TO_UINT64(message->type),
                                         (uint64_t)eff_addr,
                                         true /*Add HB SW Callout*/);
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
             *      extra_data = Specific reason code.
             */
            message->data[1] = status_rc;
            message->extra_data = reinterpret_cast<void*>(fatal_error);
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
                                   uint64_t& o_fatalError )
{
    TRACUCOMP(g_trac_pnor, "PnorRP::readFromDevice> i_offset=0x%X, i_chip=%d", i_offset, i_chip );
    errlHndl_t l_errhdl = NULL;
    uint8_t* ecc_buffer = NULL;
    o_fatalError = 0;

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
                TRACFCOMP( g_trac_pnor, "PnorRP::readFromDevice> Uncorrectable ECC error : chip=%d,offset=0x%.X", i_chip, i_offset );

                // Need to shutdown here instead of creating an error log
                //  because the bad page could be critical to the regular
                //  error handling path and cause an infinite loop.
                // Also need to spawn a separate task to do the shutdown
                //  so that the regular PNOR task can service the writes
                //  that happen during shutdown.
                o_fatalError = PNOR::RC_ECC_UE;
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
         * @custdesc    A problem occurred while accessing the boot flash.
         */
        l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        PNOR::MOD_PNORRP_COMPUTEDEVICEADDR,
                                        PNOR::RC_INVALID_ADDRESS,
                                        l_vaddr,
                                        BASE_VADDR,
                                        true /*Add HB SW Callout*/);
        l_errhdl->collectTrace(PNOR_COMP_NAME);
        return l_errhdl;
    }

    // find the matching section
    PNOR::SectionId id = PNOR::INVALID_SECTION;
    l_errhdl = computeSection( l_vaddr, id );
    if( l_errhdl )
    {
        return l_errhdl;
    }

    // pull out the information we need to return from our global copy
    o_chip = iv_TOC[id].chip;
    o_ecc = (bool)(iv_TOC[id].integrity & FFS_INTEG_ECC_PROTECT);
    o_offset = l_vaddr - iv_TOC[id].virtAddr; //offset into section

    // for ECC we need to figure out where the ECC-enhanced offset is
    //  before tacking on the offset to the section
    if( o_ecc )
    {
        o_offset = (o_offset * 9) / 8;
    }
    // add on the offset of the section itself
    o_offset += iv_TOC[id].flashAddr;

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
                                   PNOR::SectionId& o_id )
{
    errlHndl_t errhdl = NULL;

    o_id = PNOR::INVALID_SECTION;

    do {
        // loop through all sections to find a matching id
        for( PNOR::SectionId id = PNOR::FIRST_SECTION;
             id < PNOR::NUM_SECTIONS;
             id = (PNOR::SectionId) (id + 1) )
        {
            if( (i_vaddr >= iv_TOC[id].virtAddr)
                && (i_vaddr < (iv_TOC[id].virtAddr + iv_TOC[id].size)) )
            {
                o_id = iv_TOC[id].id;
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
         * @custdesc    A problem occurred while accessing the boot flash.
         */
        errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         PNOR::MOD_PNORRP_COMPUTESECTION,
                                         PNOR::RC_INVALID_ADDRESS,
                                         i_vaddr,
                                         0,
                                         true /*Add HB SW Callout*/);
        errhdl->collectTrace(PNOR_COMP_NAME);
        return errhdl;
    }

    return errhdl;
}

