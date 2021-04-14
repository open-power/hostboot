/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnorvalid.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
/**
 *  @file pnorvalid.C
 *
 *  @brief Implements PNOR::validateAltMaster(), which Validates
 *         the Alternative Master Processor's connection to PNOR
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <trace/interface.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludlogregister.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <attributeenums.H>
#include "ffs.h"
#include "common/ffs_hb.H"
#include "pnorrp.H"
#include <pnor/pnorif.H>
#include <pnor/pnor_reasoncodes.H>
#include <lpc/lpcif.H>
#if defined(CONFIG_PNORDD_IS_SFC)
#include "pnor_sfcdd.H"
using PnorDD = PnorSfcDD;
#elif (defined(CONFIG_PNORDD_IS_BMCMBOX) || defined(CONFIG_PNORDD_IS_IPMI))
#include "pnor_hiomapdd.H"
using PnorDD = PnorHiomapDD;
#elif CONFIG_FILE_XFER_VIA_PLDM
#include "pnor_pldmdd.H"
using PnorDD = PnorPldmDD;
#else
#error "No PNOR DD configured"
#endif

// Used for creating an Invalid TOC ("PNOR")
#define PNORVALID_FAKE_MAGIC 0x504E4F52

extern trace_desc_t* g_trac_pnor;

namespace PNOR
{

/**
 * @brief Validate the MAGIC field in the TOC
 *
 * @parm i_pnordd         PNOR Device Driver Object of Alt Master
 * @parm i_ffs_hdr        FFS Header to check
 * @parm i_toc0_offset    Offset Address of TOC
 * @parm i_attempt_write  If invalid MAGIC, rewrite TOC if true
 *                        (createEmptyTOC gets called)
 *
 * @return errlHndl_t  Error log if validation failed
 */
errlHndl_t validateMagic(PnorDD*  i_pnordd,
                         ffs_hdr* i_ffs_hdr,
                         uint64_t i_toc0_offset,
                         bool     i_attempt_write);

/**
 * @brief Create an Invalid TOC on Alt Master's PNOR
 *
 * @parm i_pnordd         PNOR Device Driver Object of Alt Master
 * @parm i_ffs_hdr        FFS Header to check
 * @parm i_toc0_offset    Offset Address of TOC
 *
 * @return errlHndl_t  Error log if validation failed
 */
errlHndl_t createInvalidTOC(PnorDD*  i_pnordd,
                          ffs_hdr* i_ffs_hdr,
                          uint64_t i_toc0_offset);

/**
 * @brief Validate the Alternative Master Processor's LPC connection to PNOR
 *
 * @return errlHndl_t  Error log if validation failed
 */

errlHndl_t validateAltMaster( void )
{
    TRACFCOMP( g_trac_pnor, ENTER_MRK"PNOR::validateAltMaster" );
    errlHndl_t l_err = NULL;

    PnorDD* pnordd = NULL;

    // When reading PNOR TOC assume a single page and no ECC
    uint8_t* tocBuffer = new uint8_t[PAGESIZE];
    size_t read_size = PAGESIZE;
    const uint64_t toc0_offset = PnorRP::getInstance().getTocOffset(TOC_0);

    do{

        // Get list of all processors
        TARGETING::TargetHandleList procList;
        TARGETING::getAllChips(procList,
                               TARGETING::TYPE_PROC,
                               true); // true: return functional targets

        if( ( 0 == procList.size() ) ||
            ( NULL == procList[0] ) )
        {
            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::validateAltMaster()> No functional processors Found! Validation skipped" );
            break;
        }

        // Loop through all processors
        for(uint32_t i=0; i<procList.size(); i++)
        {
            // Check if processor is MASTER_CANDIDATE
            TARGETING::ATTR_PROC_MASTER_TYPE_type type_enum =
                       procList[i]->getAttr<TARGETING::ATTR_PROC_MASTER_TYPE>();

            if ( type_enum != TARGETING::PROC_MASTER_TYPE_MASTER_CANDIDATE )
            {
                TRACDCOMP( g_trac_pnor, INFO_MRK"PNOR::validateAltMaster> Skipping Processor 0x%X (PROC_MASTER_TYPE=%d)",
                           TARGETING::get_huid(procList[i]), type_enum);
                continue;
            }

            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::validateAltMaster> Validating Processor 0x%X (PROC_MASTER_TYPE=%d)",
                       TARGETING::get_huid(procList[i]), type_enum);

            // Create and initialize custom PNOR DD class for this target
            if ( pnordd )
            {
                delete pnordd;
                pnordd = NULL;

                // Delete the LPC objects we already used
                l_err = LPC::create_altmaster_objects( false, NULL );
                if ( l_err )
                {
                    // Commit Error Log, but continue the test
                    TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::validateAltMaster> Could not delete LPC objects. eid=0x%X, rc=0x%X. Committing log and Continuing", l_err->eid(), l_err->reasonCode());

                    l_err->collectTrace(PNOR_COMP_NAME);

                    // if there was an error, commit here and then proceed to
                    // the next processor
                    errlCommit(l_err,PNOR_COMP_ID);
                    continue;
                }
            }

            // Create the LPC objects we're going to use
            l_err = LPC::create_altmaster_objects( true, procList[i] );
            if ( l_err )
            {
                // Commit Error Log, but continue the test
                TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::validateAltMaster> Could not create LPC objects for %.8X. eid=0x%X, rc=0x%X. Committing log and Continuing", TARGETING::get_huid(procList[i]), l_err->eid(), l_err->reasonCode());

                l_err->collectTrace(PNOR_COMP_NAME);

                // if there was an error, commit here and then proceed to
                // the next processor
                errlCommit(l_err,PNOR_COMP_ID);
                continue;
            }

            pnordd = new PnorDD(procList[i]);

            // Read Flash
            l_err = pnordd->readFlash(tocBuffer, read_size, toc0_offset);
            if ( l_err )
            {
                // Commit Error Log, but continue the test
                TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::validateAltMaster> readFlash fail for 0x%X. eid=0x%X, rc=0x%X. Committing log and Continuing",
                           TARGETING::get_huid(procList[i]), l_err->eid(),
                           l_err->reasonCode());

                l_err->addPartCallout(
                            procList[i],
                            HWAS::PNOR_PART_TYPE,
                            HWAS::SRCI_PRIORITY_LOW,
                            HWAS::NO_DECONFIG,
                            HWAS::GARD_NULL);

                l_err->collectTrace(PNOR_COMP_NAME);

                // if there was an error, commit here and then proceed to
                // the next processor
                errlCommit(l_err,PNOR_COMP_ID);
                continue;
            }

            // Set the header pointer
            ffs_hdr* l_ffs_hdr = (ffs_hdr*) tocBuffer;

            // Recursive function to check FFS/TOC Magic and possibly write
            // new TOC if necessary
            l_err = validateMagic(pnordd,
                                  l_ffs_hdr,
                                  toc0_offset,
                                  true); // true->write TOC if necessary

            if ( l_err )
            {
                // Commit Error Log, but continue the test
                TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::validateAltMaster> validateMagic fail for 0x%X. eid=0x%X, rc=0x%X. Committing log and Continuing",
                           TARGETING::get_huid(procList[i]), l_err->eid(),
                           l_err->reasonCode());

                l_err->addPartCallout(
                            procList[i],
                            HWAS::PNOR_PART_TYPE,
                            HWAS::SRCI_PRIORITY_HIGH,
                            HWAS::NO_DECONFIG,
                            HWAS::GARD_NULL);

                l_err->collectTrace(PNOR_COMP_NAME);

                // if there was an error, commit here and then proceed to
                // the next processor
                errlCommit(l_err,PNOR_COMP_ID);
                continue;
            }


            // Now check ffs entry checksum (0 if checksums match)
            if( pnor_ffs_checksum(l_ffs_hdr, FFS_HDR_SIZE) != 0)
            {
                //@TODO - RTC:90780 - May need to handle this differently in
                //                    SP-less config
                TRACFCOMP(g_trac_pnor, "PNOR::validateAltMaster> pnor_ffs_checksum header checksums do not match on target 0x%X. Create and commit error log then continue the test",
                          TARGETING::get_huid(procList[i]));

                /*@
                 * @errortype
                 * @moduleid     PNOR::MOD_PNORVALID_MAIN
                 * @reasoncode   PNOR::RC_PARTITION_TABLE_INVALID
                 * @userdata1    Master Candidate Processor Target
                 * @userdata2    <unused>
                 * @devdesc      PNOR::validateAltMaster> Fail verifying FFS
                 *               Header on Master Candidate PNOR TOC0
                 * @custdesc     Fail verifying Flash File System (FFS) Header
                 *               on Master Candidate Processor NOR flash Table
                 *               of Contents 0 (TOC)
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      PNOR::MOD_PNORVALID_MAIN,
                                      PNOR::RC_PARTITION_TABLE_INVALID,
                                      TARGETING::get_huid(procList[i]),
                                      0);

                l_err->addPartCallout(
                            procList[i],
                            HWAS::PNOR_PART_TYPE,
                            HWAS::SRCI_PRIORITY_HIGH,
                            HWAS::NO_DECONFIG,
                            HWAS::GARD_NULL);

                TRACFBIN(g_trac_pnor, "tocBuffer", tocBuffer, 0x20);

                l_err->collectTrace(PNOR_COMP_NAME);
                errlCommit(l_err,PNOR_COMP_ID);
                continue;
            }
            else
            {
                TRACFCOMP(g_trac_pnor, "PNOR::validateAltMaster> Successful validation of Alt-Master 0x%X",
                          TARGETING::get_huid(procList[i]));
            }

        } // end of processor 'for' loop


    }while(0);

    // Delete PNOR DD class and memory buffer
    if ( pnordd )
    {
        delete pnordd;
        pnordd = NULL;

        // Delete the LPC objects we used
        l_err = LPC::create_altmaster_objects( false, NULL );
        if ( l_err )
        {
            // Commit Error Log, but continue the test
            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::validateAltMaster> Could not delete LPC objects. eid=0x%X, rc=0x%X. Committing log and Continuing", l_err->eid(), l_err->reasonCode());

            l_err->collectTrace(PNOR_COMP_NAME);

            // if there was an error, commit here and then proceed to
            // the next processor
            errlCommit(l_err,PNOR_COMP_ID);
        }
    }

    if(tocBuffer != NULL)
    {
        delete[] tocBuffer;
        tocBuffer = NULL;
    }

    TRACFCOMP( g_trac_pnor, EXIT_MRK"PNOR::validateAltMaster : RC=%X", ERRL_GETRC_SAFE(l_err) );
    return l_err;
}



/**
 * @brief Validate the MAGIC field in the TOC
 */
errlHndl_t validateMagic(PnorDD*  i_pnordd,
                         ffs_hdr* i_ffs_hdr,
                         uint64_t i_toc0_offset,
                         bool     i_attempt_write)
{
    errlHndl_t l_err = NULL;

    do{

        /* Checking FFS Header MAGIC to make sure it looks valid */
        if ( ( i_ffs_hdr->magic != FFS_MAGIC ) &&
             ( i_ffs_hdr->magic != PNORVALID_FAKE_MAGIC ) )
        {
            TRACFCOMP(g_trac_pnor, "PNOR::validateMagic> Invalid magic number in FFS header: 0x%.4X",
                      i_ffs_hdr->magic);

            TRACFBIN(g_trac_pnor, "PNOR::validateMagic> i_ffs_hdr",
                     i_ffs_hdr, FFS_HDR_SIZE);

            // Check if we should attempt to write empty TOC
            if ( i_attempt_write == true )
            {
                // Write Invalid TOC with a specific 'MAGIC' marker
                l_err = createInvalidTOC(i_pnordd, i_ffs_hdr, i_toc0_offset);
                if ( l_err )
                {
                    TRACFCOMP(g_trac_pnor, "PNOR::validateMagic> createInvalidTOC returned error: eid=0x%X, rc=0x%X",
                              l_err->eid(), l_err->reasonCode());
                    break;
                }
                else
                {
                    // Writing TOC successful, so recursively call this function
                    l_err = validateMagic(i_pnordd,
                                          i_ffs_hdr,
                                          i_toc0_offset,
                                          false); // false->don't write TOC
                    if ( l_err )
                    {

                        TRACFCOMP(g_trac_pnor, "PNOR::validateMagic> After successful createEmptyTOC, validateMagic returned error: eid=0x%X, rc=0x%X",
                                  l_err->eid(), l_err->reasonCode());
                        break;
                    }
                }
            }
            else
            {

                //@TODO - RTC:90780 - May need to handle this differently in
                //                    SP-less config
                TRACFCOMP(g_trac_pnor, "PNOR::validateMagic> MAGIC number header still incorrect after writing empty TOC");

                /*@
                 * @errortype
                 * @moduleid     PNOR::MOD_PNORVALID_MAGIC
                 * @reasoncode   PNOR::RC_PARTITION_TABLE_INVALID
                 * @userdata1    Magic Number read
                 * @userdata2    <unused>
                 * @devdesc      PNOR::validateMagic> Fail verifying FFS Magic
                 *               Number in Header on Master
                 * @custdesc     Fail verifying Flash File System (FFS) Magic
                 *               Number in Header on Master
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      PNOR::MOD_PNORVALID_MAGIC,
                                      PNOR::RC_PARTITION_TABLE_INVALID,
                                      i_ffs_hdr->magic,
                                      0);

                TRACFBIN(g_trac_pnor, "i_ffs_hdr", i_ffs_hdr, FFS_HDR_SIZE);

                // HW Callout handled by caller
                break;
            }
        }

    }while(0);


    return l_err;
}

/**
 * @brief Create an Invalid TOC on Alt Master's PNOR
 */
errlHndl_t createInvalidTOC(PnorDD*  i_pnordd,
                            ffs_hdr* i_ffs_hdr,
                            uint64_t i_toc0_offset)
{
    errlHndl_t l_err = NULL;

    // When reading PNOR TOC assume a single page and no ECC
    size_t toc_size = PAGESIZE;

    do{
            // Create FFS Header of Empty TOC with Invalid MAGIC field
            ffs_hdr l_hdr;

            // Clear the struct and only set (invalid) MAGIC and checksum fields
            // - Thus HWSV will recognize this TOC needs to be updated
            memset(&(l_hdr), 0, FFS_HDR_SIZE);
            l_hdr.magic       = PNORVALID_FAKE_MAGIC;
            l_hdr.checksum    = pnor_ffs_checksum(&(l_hdr), FFS_HDR_SIZE_CSUM);

            // Re-use previously defined io_ffs_hdr memory space
            memset(i_ffs_hdr, 0, toc_size);
            memcpy(i_ffs_hdr, &(l_hdr), FFS_HDR_SIZE);

            TRACFBIN(g_trac_pnor, "PNOR::createInvalidTOC> New FFS Header",
                     i_ffs_hdr, FFS_HDR_SIZE);


            // Write TOC to PNOR
            l_err = i_pnordd->writeFlash(i_ffs_hdr, toc_size,
                                         i_toc0_offset);
            if ( l_err )
            {
                TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::createInvalidTOC> writeFlash fail: eid=0x%X, rc=0x%X",
                           l_err->eid(), l_err->reasonCode());

                TRACFBIN(g_trac_pnor, "EMPTY TOC", i_ffs_hdr, 0x20);
                break;
            }

            // Read Back TOC from PNOR (reset toc_size and i_ffs_hdr to be safe)
            toc_size = PAGESIZE;
            memset(i_ffs_hdr, 0, toc_size);
            l_err = i_pnordd->readFlash(i_ffs_hdr, toc_size,
                                        i_toc0_offset);
            if ( l_err )
            {
                TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::createInvalidTOC> readFlash fail: eid=0x%X, rc=0x%X",
                           l_err->eid(), l_err->reasonCode());

            }


    }while(0);

    return l_err;
}

}; //namespace PNOR

