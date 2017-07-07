/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_memRegionMgr.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
* @file sbe_memRegionMgr.C
* @brief Opens and Closes Unsecure Memory Regions via the SBE
*/

#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <vmmconst.h>
#include <sys/misc.h>

#include "sbe_memRegionMgr.H"

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"memRegion: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"memRegion: " printf_string,##args)

namespace SBEIO
{

// External Function to Open an Unsecure Memory Region
// - see sbeioif.H for details
errlHndl_t openUnsecureMemRegion(
    const uint64_t i_start_addr,
    const uint32_t i_size,
    const bool     i_isWritable,
    TARGETING::Target* i_target)
{
    return Singleton<MemRegionMgr>::instance()
               .openUnsecureMemRegion(i_start_addr,
                                      i_size,
                                      i_isWritable,
                                      i_target);
};


// External Function to Close an Unsecure Memory Region
// - see sbeioif.H for details
errlHndl_t closeUnsecureMemRegion(
    const uint64_t i_start_addr,
    TARGETING::Target* i_target)
{
    return Singleton<MemRegionMgr>::instance()
               .closeUnsecureMemRegion(i_start_addr, i_target);
};


// External Function to Close All Unsecure Memory Regions
// - see sbeioif.H for details
errlHndl_t closeAllUnsecureMemRegions()
{
    return Singleton<MemRegionMgr>::instance()
               .closeAllUnsecureMemRegions();
};


/*****************************************************************************/
/*
 * MemRegionMgr : Constructor : Setup Instance Variables
 */
MemRegionMgr::MemRegionMgr()
{
    SBE_TRACD(ENTER_MRK"MemRegionMgr Constructor");

    // SBE opens Memory Region for HB DUMP before starting hostboot
    // so just add it directly to iv_memRegions
    regionData hb_dump_region;
    hb_dump_region.start_addr = cpu_spr_value(CPU_SPR_HRMOR);
    hb_dump_region.size = VMM_MEMORY_SIZE;
    hb_dump_region.flags = SbePsu::SBE_MEM_REGION_OPEN_READ_ONLY;
    iv_memRegions.push_back(hb_dump_region);

    SBE_TRACF("MemRegionMgr Constructor: Initial region(s):");
    printIvMemRegions();

    SBE_TRACD(EXIT_MRK"MemRegionMgr Constructor");
};

/*
 * MemRegionMgr : Destructor : Clear Instance Variables
 */
MemRegionMgr::~MemRegionMgr()
{
    // Clear Vector of Unsecure Memory Regions
    iv_memRegions.clear();
};

/**
 * MemRegionMgr::openUnsecureMemRegion
 * - see sbe_unsecureMemRegionMgr.H for details
 */
errlHndl_t MemRegionMgr::openUnsecureMemRegion(
    const uint64_t    i_start_addr,
    const uint32_t    i_size,
    const bool        i_isWritable,
    TARGETING::Target* i_target)
{

    errlHndl_t errl = nullptr;
    regionData l_region;
    bool itr_region_closed = false;
    const uint8_t input_flags = i_isWritable ?
                                  SbePsu::SBE_MEM_REGION_OPEN_READ_WRITE :
                                  SbePsu::SBE_MEM_REGION_OPEN_READ_ONLY;

    SBE_TRACF(ENTER_MRK"openUnsecureMemRegion: i_tgt=0x%X: "
              "i_start_addr=0x%.16llX, i_size=0x%.8X, i_isWritable=%d "
              "(flags=0x%.2X)",
              TARGETING::get_huid(i_target), i_start_addr, i_size,
              i_isWritable, input_flags);
    assert(i_size!=0, "openUnsecureMemRegion: i_size=0");

    do
    {
        // Handle 'Open' Request
        // -- Look for identical region
        // ---- if so, fail
        // -- Look for possible overlap with existing regions
        // ---- If overlap, close existing regions and re-open
        //      all regions as necessary
        // ---- If no overlap, open requested region

        // @TODO RTC 174970 - Add checks to not exceed 8 memory regions

        auto itr = iv_memRegions.begin();
        while (itr != iv_memRegions.end())
        {
            // reset for each loop
            itr_region_closed = false;

            // Look for Overlap: start_addr starts at or is inside
            // existing region
            if ((i_start_addr >= itr->start_addr) &&
                (i_start_addr < (itr->start_addr + itr->size)))
            {
                SBE_TRACF(INFO_MRK"openUnsecureMemRegion: Overlap Found: "
                  "Req Region Starts inside existing region. "
                  "Exist start=0x%.16lX, size=0x%.8X, flags=0x%.2X"
                  "Req start=0x%.16lX, size=0x%.8X, flags=0x%.2X",
                  itr->start_addr, itr->size, itr->flags,
                  i_start_addr, i_size, input_flags);

                // Close Existing Region
                l_region.start_addr = itr->start_addr;
                l_region.size = itr->size;
                l_region.flags = SbePsu::SBE_MEM_REGION_CLOSE;
                l_region.tgt = itr->tgt;

                errl = doUnsecureMemRegionOp(l_region);

                if (errl)
                {
                    SBE_TRACF(ERR_MRK "openUnsecureMemRegion: Close Op "
                              "Failed: err rc=0x%.4X plid=0x%.8X",
                              ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));

                    // Return error to caller ASAP
                    break;
                }
                else
                {
                    // This region will be removed from the cache list later
                    itr_region_closed = true;
                }

                // Re-Open Non-overlapping initial part of Existing Region
                l_region.start_addr = itr->start_addr;
                l_region.size = i_start_addr - itr->start_addr;
                l_region.flags = itr->flags;
                l_region.tgt = itr->tgt;

                errl = doUnsecureMemRegionOp(l_region);

                if (errl)
                {
                    SBE_TRACF(ERR_MRK "openUnsecureMemRegion: Re-Open Op "
                              "Failed: err rc=0x%.4X plid=0x%.8X",
                              ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));

                    // Return error to caller ASAP
                    break;
                }
                else
                {
                    // Add the region to the cache list
                    iv_memRegions.push_front(l_region);
                }
            }

            // Look for Overlap: end of region inside existing region
            if (((i_start_addr + i_size) > itr->start_addr) &&
                ((i_start_addr + i_size) < (itr->start_addr + itr->size)))
            {
                SBE_TRACF(INFO_MRK"openUnsecureMemRegion: Overlap Found: "
                  "Req Region Ends inside existing region. "
                  "Exist start=0x%.16lX, size=0x%.8X, flags=0x%.2X"
                  "Req start=0x%.16lX, size=0x%.8X, flags=0x%.2X",
                  itr->start_addr, itr->size, itr->flags,
                  i_start_addr, i_size, input_flags);

                // Close Existing Region - if not already closed
                if (itr_region_closed == false)
                {
                    l_region.start_addr = itr->start_addr;
                    l_region.size = itr->size;
                    l_region.flags = SbePsu::SBE_MEM_REGION_CLOSE;
                    l_region.tgt = itr->tgt;

                    errl = doUnsecureMemRegionOp(l_region);

                    if (errl)
                    {
                        SBE_TRACF(ERR_MRK "openUnsecureMemRegion: Close Op "
                                  "Failed: err rc=0x%.4X plid=0x%.8X",
                                  ERRL_GETRC_SAFE(errl),
                                  ERRL_GETPLID_SAFE(errl));

                        // Return error to caller ASAP
                        break;
                    }
                    else
                    {
                        // This region will be removed from the cache list later
                        itr_region_closed = true;
                    }
                }

                // Re-open, non-overlapping back end part of
                // Existing Region
                l_region.start_addr = i_start_addr + i_size;
                l_region.size = (itr->start_addr + itr->size) -
                                  (i_start_addr + i_size);
                l_region.flags = itr->flags;
                l_region.tgt = itr->tgt;

                errl = doUnsecureMemRegionOp(l_region);

                if (errl)
                {
                    SBE_TRACF(ERR_MRK "openUnsecureMemRegion: Re-Open Op "
                              "Failed: err rc=0x%.4X plid=0x%.8X",
                              ERRL_GETRC_SAFE(errl),
                              ERRL_GETPLID_SAFE(errl));

                    // Return error to caller ASAP
                    break;
                }
                else
                {
                    // Add the region to the cache list
                    iv_memRegions.push_front(l_region);
                }
            }

            // Look for Overlap: existing region enclosed by requested region
            else if ((i_start_addr <= itr->start_addr) &&
                     ((i_start_addr + i_size) >=
                        (itr->start_addr + itr->size)))
            {
                SBE_TRACF(INFO_MRK"openUnsecureMemRegion: Overlap Found: "
                  "Req Region encloses existing region. "
                  "Exist start=0x%.16lX, size=0x%.8X, flags=0x%.2X"
                  "Req start=0x%.16lX, size=0x%.8X, flags=0x%.2X",
                  itr->start_addr, itr->size, itr->flags,
                  i_start_addr, i_size, input_flags);

                // Close Existing Region
                if (itr_region_closed==false)
                {
                    l_region.start_addr = itr->start_addr;
                    l_region.size = itr->size;
                    l_region.flags = SbePsu::SBE_MEM_REGION_CLOSE;
                    l_region.tgt = itr->tgt;

                    errl = doUnsecureMemRegionOp(l_region);

                    if (errl)
                    {
                        SBE_TRACF(ERR_MRK "openUnsecureMemRegion: Close Op "
                                  "(enclosed) Failed: err rc=0x%.4X plid=0x%.8X",
                                  ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));

                        // Return error to caller ASAP
                        break;
                    }
                    else
                    {
                        // This region will be removed from the cache list later
                        itr_region_closed = true;
                    }
                }
            }

            // Increment Iterator
            if (itr_region_closed == true)
            {
                itr = iv_memRegions.erase(itr);
            }
            else
            {
                ++itr;
            }
        }

        // If previous error, don't open a new region
        if (errl)
        {
            break;
        }


        // Open Requested Region
        l_region.start_addr = i_start_addr;
        l_region.size = i_size;
        l_region.flags = input_flags;
        l_region.tgt = i_target;

        errl = doUnsecureMemRegionOp(l_region);
        if (errl)
        {
            SBE_TRACF(ERR_MRK "openUnsecureMemRegion: Open Call Failed: "
                      "err rc=0x%.4X plid=0x%.8X",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));

            // Return error to caller ASAP
            break;
        }
        else
        {
            // Add region to cache on success
            iv_memRegions.push_front(l_region);
        }

    }
    while (0);

    // TODO RTC 174970 remove when base support is working
    printIvMemRegions();

    SBE_TRACF(EXIT_MRK "openUnsecureMemRegion: i_tgt=0x%X: "
              "i_start_addr=0x%.16llX: err_rc=0x%.4X",
              TARGETING::get_huid(i_target), i_start_addr,
              ERRL_GETRC_SAFE(errl));

    return errl;
}

/**
 * MemRegionMgr::closeUnsecureMemRegion
 * - see sbe_unsecureMemRegionMgr.H for details
 */
errlHndl_t MemRegionMgr::closeUnsecureMemRegion(
    const uint64_t    i_start_addr,
    TARGETING::Target* i_target)
{
    errlHndl_t errl = nullptr;

    bool region_found = false;
    regionData l_region;

    SBE_TRACF(ENTER_MRK"closeUnsecureMemRegion: i_tgt=0x%X: "
              "i_start_addr=0x%.16llX",
              TARGETING::get_huid(i_target), i_start_addr);

    do
    {
        auto itr = iv_memRegions.begin();
        while (itr != iv_memRegions.end())
        {
            if (itr->start_addr == i_start_addr)
            {
                region_found = true;

                // Close Requested Region
                l_region.start_addr = itr->start_addr;
                l_region.size = itr->size;
                l_region.flags = SbePsu::SBE_MEM_REGION_CLOSE;
                l_region.tgt = itr->tgt;

                errl = doUnsecureMemRegionOp(l_region);
                if (errl)
                {
                    SBE_TRACF(ERR_MRK "closeUnsecureMemRegion: Close Op Failed:"
                              " err rc=0x%.4X plid=0x%.8X",
                              ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
                }
                else
                {
                    itr = iv_memRegions.erase(itr);
                }

                // Quit walking through regions
                break;
            }

            // Keep looking
            ++itr;
        }

        // If previous error, don't even check for "region not found" error
        if (errl)
        {
            break;
        }

        if (region_found == false)
        {
            SBE_TRACF(ERR_MRK"closeUnsecureMemRegion: Requested Region "
                      "Does Not Exist! start_addr=0x%.16llX",
                      i_start_addr);

            /*@
             * @errortype
             * @moduleid     SBEIO_MEM_REGION
             * @reasoncode   SBEIO_MEM_REGION_DOES_NOT_EXIST
             * @userdata1    Starting Address of Unsecure Memory Region
             * @userdata2    Number of Unsecure Memory Regions
             * @devdesc      Unsecure Memory Region Does Not Exist
             * @custdesc     A problem occurred during the IPL
             */
            errl = new ERRORLOG::ErrlEntry(
                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                         SBEIO_MEM_REGION,
                         SBEIO_MEM_REGION_DOES_NOT_EXIST,
                         i_start_addr,
                         iv_memRegions.size(),
                         true /*Add HB SW Callout*/ );
            break;
        }

    }
    while (0);

    SBE_TRACF(EXIT_MRK "closeUnsecureMemRegion: i_tgt: 0x%X: "
              "i_start_addr0x%.16llX: err_rc=0x%4X",
              TARGETING::get_huid(i_target), i_start_addr,
              ERRL_GETRC_SAFE(errl));

    return errl;
}

/**
 * MemRegionMgr::closeUnsecureMemRegions
 * - see sbe_unsecureMemRegionMgr.H for details
 */
errlHndl_t MemRegionMgr::closeAllUnsecureMemRegions()
{
    errlHndl_t errl = nullptr;
    errlHndl_t errl_orig = nullptr;

    regionData l_region;

    SBE_TRACF(ENTER_MRK"closeAllUnsecureMemRegions: closing %d region(s)",
              iv_memRegions.size());

    printIvMemRegions();

    do
    {
        // Close every memory region saved in vector
        auto itr = iv_memRegions.begin();
        while (itr != iv_memRegions.end())
        {
            // Close Requested Region
            l_region.start_addr = itr->start_addr;
            l_region.size = itr->size;
            l_region.flags = SbePsu::SBE_MEM_REGION_CLOSE;

            errl = doUnsecureMemRegionOp(l_region);

            if ( ( errl != nullptr) &&
                 ( errl_orig != nullptr ) )
            {
                SBE_TRACF(ERR_MRK "closeAllUnsecureMemRegions: Another Fail: "
                          "Committing new err rc=0x%.4X plid=0x%.8X with plid "
                          "of original err rc=0x%.4X plid=0x%.8X",
                          ERRL_GETRC_SAFE(errl),
                          ERRL_GETPLID_SAFE(errl),
                          ERRL_GETRC_SAFE(errl_orig),
                          ERRL_GETPLID_SAFE(errl_orig));

                // commit new error with orignal err PLID
                errl->plid(errl_orig->plid());

                errlCommit(errl, SBEIO_COMP_ID);

                // Skip region since it failed to close
                ++itr;
            }
            else if ( errl != nullptr)
            {
                SBE_TRACF(ERR_MRK "closeAllUnsecureMemRegions: Close Fail: "
                          "err rc=0x%.4X plid=0x%.8X",
                          ERRL_GETRC_SAFE(errl),
                          ERRL_GETPLID_SAFE(errl));

                // Save error and continue
                errl_orig = errl;
                errl = nullptr;

                // Skip region since it failed to close
                ++itr;
            }
            else
            {
                itr = iv_memRegions.erase(itr);
            }
        }
    }
    while (0);

    printIvMemRegions();

    SBE_TRACF(EXIT_MRK "closeAllUnsecureMemRegions: regions left = %d, "
              "err_rc=0x%.4X",
              iv_memRegions.size(),
              ERRL_GETRC_SAFE(errl_orig));

    return errl_orig;
}

/**
 * MemRegionMgr::doUnsecureMemRegionOp
 * - see sbe_unsecureMemRegionMgr.H for details
 */
errlHndl_t MemRegionMgr::doUnsecureMemRegionOp(regionData & i_region)
{
    errlHndl_t errl = nullptr;
    TARGETING::Target * l_tgt = i_region.tgt;

    // @TODO RTC 174970 - make TRACD when SBE support is tested
    SBE_TRACF(ENTER_MRK"doUnsecureMemRegionOp: tgt=0x%.8X: "
              "start_addr=0x%.16llX, size=0x%.8X, controlFlags=0x%.2X",
              TARGETING::get_huid(l_tgt), i_region.start_addr,
              i_region.size, i_region.flags);

    do
    {
        // Find master proc for target of PSU command, if necessary
        if (l_tgt == nullptr)
        {
            TARGETING::TargetService& tS = TARGETING::targetService();

            errl = tS.queryMasterProcChipTargetHandle(l_tgt);
            if (errl)
            {
                SBE_TRACF(ERR_MRK "doUnsecureMemRegionOp: Failed to get Master "
                          "Proc: err rc=0x%.4X plid=0x%.8X",
                          ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));

                break;
            }

            // Set target for future operations
            i_region.tgt = l_tgt;
        }

        SbePsu::psuCommand l_psuCommand(
            i_region.flags |
              SbePsu::SBE_MEM_REGION_RESPONSE_REQUIRED, //control flags
            SbePsu::SBE_PSU_CLASS_SECURITY_CONTROL, //command class
            SbePsu::SBE_PSU_SET_UNSECURE_MEMORY_REGION_CMD); //command

        SbePsu::psuResponse  l_psuResponse;

        // set up PSU command message
        l_psuCommand.cd6_memRegion_Size = i_region.size;
        l_psuCommand.cd6_memRegion_Start_Addr = i_region.start_addr;

// @TODO RTC 174970 - Activate code block when SBE support is tested
#if 0
        errl =  SBEIO::SbePsu::getTheInstance().performPsuChipOp(l_tgt,
                                &l_psuCommand,
                                &l_psuResponse,
                                SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                                SbePsu::SBE_MEMORY_REGION_REQ_USED_REGS,
                                SbePsu::SBE_MEMORY_REGION_RSP_USED_REGS);
#endif
        if (errl)
        {
            SBE_TRACF(ERR_MRK "doUnsecureMemRegionOp: PSU Cmd Failed: "
                      "err rc=0x%.4X plid=0x%.8X (mbxReg0=0x%.16llX)",
                      ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl),
                      l_psuCommand.mbxReg0);
            break;
        }

    }
    while (0);

    // @TODO RTC 174970 - make TRACD when SBE support is tested
    SBE_TRACF(EXIT_MRK "doUnsecureMemRegionOp: tgt=0x%.8X: "
              "start_addr=0x%.16llX, size=0x%.8X, controlFlags=0x%.2X: "
              "err_rc=0x%.4X",
              TARGETING::get_huid(l_tgt), i_region.start_addr, i_region.size,
              i_region.flags, ERRL_GETRC_SAFE(errl));

    return errl;
}

/**
 * MemRegionMgr::printIvMemRegions
 * - see sbe_unsecureMemRegionMgr.H for details
 */
void MemRegionMgr::printIvMemRegions(void) const
{
    SBE_TRACF("MemRegionMgr::printIvMemRegions: number of entries=%d",
              iv_memRegions.size());

    for ( const auto& itr : iv_memRegions )
    {
        SBE_TRACF("printIvMemRegions: tgt=0x%.8X: start_addr=0x%.16llX, "
                  "size=0x%.8X, flags=0x%.2X (%s)",
                  TARGETING::get_huid(itr.tgt), itr.start_addr,
                  itr.size, itr.flags,
                  itr.flags == SbePsu::SBE_MEM_REGION_OPEN_READ_ONLY ?
                    "Read-Only" : "Read-Write");
    }
}

} // end namespace SBEIO
