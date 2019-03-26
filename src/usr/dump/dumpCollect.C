/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/dump/dumpCollect.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2019                        */
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

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

#include <sys/mmio.h>
#include "dumpCollect.H"
#include <dump/dumpreasoncodes.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <runtime/runtime.H>
#include <util/align.H>
#include <sys/mm.h>
#include <dump/dumpif.H>
#include <util/utiltce.H>
#include <isteps/mem_utils.H>

#include <sys/msg.h>                     //  message Q's
#include <mbox/mbox_queues.H>            //
#include <kernel/vmmmgr.H>

// Trace definition
trace_desc_t* g_trac_dump = NULL;
TRAC_INIT(&g_trac_dump, "DUMP", 4*KILOBYTE);

#define SBE_FFDC_SIZE 128

namespace DUMP
{


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

errlHndl_t doDumpCollect(void)
{
    TRACFCOMP(g_trac_dump, "doDumpCollect - start ");
    errlHndl_t l_err = NULL;

    // Table Sizes
    uint64_t srcTableSize = 0;
    uint64_t destTableSize = 0;
    uint64_t resultsTableSize = 0;

    // Dump table struct pointers
    dumpEntry *srcTableEntry = NULL;
    dumpEntry *destTableEntry = NULL;
    resultsEntry *resultsTableEntry = NULL;

    do
    {
        // Get the Data pointers to the locations we need from HDAT
        //     MS_DUMP_SRC_TBL, < MDST: Memory Dump Source Table
        //     MS_DUMP_DST_TBL, < MDDT: Memory Dump Destination Table
        //     MS_DUMP_RESULTS_TBL,  <MDRT:Memory Dump Results Table
        l_err = getHostDataPtrs(srcTableEntry, srcTableSize,
                                destTableEntry, destTableSize,
                                resultsTableEntry, resultsTableSize);

        if (l_err)
        {
            TRACFCOMP(g_trac_dump, "doDumpCollect: Got an error back from getHostDataPtrs");
            break;
        }

        l_err = copySrcToDest(srcTableEntry,srcTableSize,
                              destTableEntry,destTableSize,
                              resultsTableEntry,resultsTableSize);

        if (l_err)
        {
            TRACFCOMP(g_trac_dump, "doDumpCollect: Got an error back from copySrcToDest");
            break;
        }

    }while (0);

    return (l_err);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Returns the physical address corresponding to a PHYP MDST/MDRT entry
void* getPhysAddr( uint64_t i_phypAddr )
{
    uint64_t phys_addr = 0;

    // Physical Address
    if( VmmManager::FORCE_PHYS_ADDR & i_phypAddr )
    {
        // lop off the top bit so our vmm code works
        phys_addr = (i_phypAddr & ~VmmManager::FORCE_PHYS_ADDR);
    }
    // Relative to PHYP HRMOR
    else
    {
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);

        // add the hrmor/payload_base to the value in the table
        TARGETING::ATTR_PAYLOAD_BASE_type payload_base
          = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
        phys_addr = payload_base*MEGABYTE + i_phypAddr;
    }

    return reinterpret_cast<void*>(ALIGN_PAGE_DOWN(phys_addr));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t copyArchitectedRegs(void)
{
    TRACFCOMP(g_trac_dump, "copyArchitectedRegs - start ");
    errlHndl_t l_err = nullptr;
    int rc;
    // Processor dump area address and size from HDAT
    uint64_t procTableAddr = 0;
    uint64_t procTableSize = 0;
    // Pointer to architected register reserved memory
    void *pSrcAddrBase = nullptr;
    void *vMapSrcAddrBase = nullptr;
    // Pointers to Hypervisor allocated memory for register data content
    void *pDstAddrBase = nullptr;
    void *vMapDstAddrBase = nullptr;
    // Architected Reg Dump table struct pointers
    procDumpAreaEntry *procTableEntry = nullptr;

    do
    {
        // Get the PROC_DUMP_AREA_TBL address from SPIRAH
        l_err = RUNTIME::get_host_data_section(RUNTIME::PROC_DUMP_AREA_TBL,
                                               0,
                                               procTableAddr,
                                               procTableSize);
        if (l_err)
        {
            // Got an errorlog back from get_host_data_sections
            TRACFCOMP(g_trac_dump, "copyArchitectedRegs get_host_data_sections "
                                   "for PDAT failed");
            break;
        }

        // If the address or size is zero - error out
        if ((procTableAddr == 0) || (procTableSize == 0))
        {
            // Invalid address or size
            TRACFCOMP(g_trac_dump, "copyArchitectedRegs address or size invalid"
                                   " for PDAT: addr =0x%X, size =0x%X,",
                                   procTableAddr, procTableSize);
            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_ARCH_REGS
             * @reasoncode   DUMP::DUMP_PDAT_INVALID_ADDR
             * @userdata1    Table address returned
             * @userdata2    Table size returned
             * @devdesc      Invalid address and size returned from HDAT
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            DUMP_ARCH_REGS,
                                            DUMP_PDAT_INVALID_ADDR,
                                            procTableAddr,
                                            procTableSize,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Map processor dump area destination address to VA addresses
        procTableEntry = reinterpret_cast<procDumpAreaEntry *>(procTableAddr);
        pDstAddrBase = getPhysAddr(procTableEntry->dstArrayAddr);
        vMapDstAddrBase = mm_block_map(pDstAddrBase,
                                       procTableEntry->dstArraySize);

        // Map architected register reserved memory to VA addresses
        uint64_t srcAddr = ISTEP::get_top_homer_mem_addr() -
                           VMM_ARCH_REG_DATA_SIZE_ALL_PROC -
                     			   VMM_ALL_HOMER_OCC_MEMORY_SIZE;
        pSrcAddrBase = reinterpret_cast<void * const>(srcAddr);
        vMapSrcAddrBase = mm_block_map(pSrcAddrBase,
                                       VMM_ARCH_REG_DATA_SIZE_ALL_PROC);

        // Get list of functional processor chips, in MPIPL path we
        // don't expect any deconfiguration
        TARGETING::TargetHandleList procChips;
        TARGETING::getAllChips( procChips, TARGETING::TYPE_PROC, true);


        uint64_t dstTempAddr = reinterpret_cast<uint64_t>(vMapDstAddrBase);
        procTableEntry->capArraySize = 0;
        for (const auto & procChip: procChips)
        {
            uint8_t procNum = procChip->getAttr<TARGETING::ATTR_POSITION>();
            // Base addresses w.r.t PROC positions. This is static here
            // and used for reference below to calculate all other addresses
            uint64_t procSrcAddr = (reinterpret_cast<uint64_t>(vMapSrcAddrBase)+
                                    procNum * VMM_ARCH_REG_DATA_PER_PROC_SIZE);

            sbeArchRegDumpProcHdr_t *sbeProcHdr =
                       reinterpret_cast<sbeArchRegDumpProcHdr_t *>(procSrcAddr);
            uint16_t threadCount = sbeProcHdr->thread_cnt;
            uint16_t regCount = sbeProcHdr->reg_cnt;

            //Validate the structure versions used by SBE and HB for sharing the
            //data
            if( sbeProcHdr->version != REG_DUMP_SBE_HB_STRUCT_VER )
            {
                /*@
                 * @errortype
                 * @moduleid     DUMP::DUMP_ARCH_REGS
                 * @reasoncode   DUMP::DUMP_PDAT_VERSION_MISMATCH
                 * @userdata1    Structure version obtained from SBE
                 * @userdata2    Structure version supported by HB
                 * @devdesc      Mismatch between the version of structure
                 *               supported by both SBE and HB.
                 *
                 */
                l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        DUMP_ARCH_REGS,
                        DUMP_PDAT_VERSION_MISMATCH,
                        sbeProcHdr->version,
                        REG_DUMP_SBE_HB_STRUCT_VER,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                errlCommit(l_err, DUMP_COMP_ID);
                break;
            }

            //Update the data source address to point to the thread specific
            //header data obtained by SBE
            procSrcAddr = reinterpret_cast<uint64_t>(procSrcAddr +
                                               sizeof(sbeArchRegDumpProcHdr_t));

            procTableEntry->threadRegSize = sizeof(hostArchRegDataHdr)+
                                      (regCount * sizeof(hostArchRegDataEntry));
            procTableEntry->capArraySize = procTableEntry->capArraySize +
                                          (procTableEntry->threadRegSize
                                           * threadCount);
            if (procTableEntry->dstArraySize < procTableEntry->capArraySize)
            {
                /*@
                 * @errortype
                 * @moduleid     DUMP::DUMP_ARCH_REGS
                 * @reasoncode   DUMP::DUMP_PDAT_INSUFFICIENT_SPACE
                 * @userdata1    Hypervisor reserved memory size
                 * @userdata2    Memory needed to copy architected
                 *               register data
                 * @devdesc      Insufficient space to copy architected
                 *               registers
                 */
                l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        DUMP_ARCH_REGS,
                        DUMP_PDAT_INSUFFICIENT_SPACE,
                        procTableEntry->dstArraySize,
                        procTableEntry->capArraySize,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                errlCommit(l_err, DUMP_COMP_ID);
                break;
            }

            // Total Number of Threads possible in one Proc
            for(uint32_t idx = 0; idx < threadCount; idx++)
            {
                sbeArchRegDumpThreadHdr_t *sbeTdHdr =
                     reinterpret_cast<sbeArchRegDumpThreadHdr_t *>(procSrcAddr);

                hostArchRegDataHdr *hostHdr =
                     reinterpret_cast<hostArchRegDataHdr *>(dstTempAddr);

                // Fill thread header info
                hostHdr->pir = sbeTdHdr->pir;
                hostHdr->coreState = sbeTdHdr->coreState;
                hostHdr->iv_regArrayHdr.hdatOffset =
                                              sizeof(HDAT::hdatHDIFDataArray_t);
                hostHdr->iv_regArrayHdr.hdatArrayCnt = regCount;
                hostHdr->iv_regArrayHdr.hdatAllocSize =
                                              sizeof(hostArchRegDataEntry);
                hostHdr->iv_regArrayHdr.hdatActSize =
                                              sizeof(hostArchRegDataEntry);

                dstTempAddr = reinterpret_cast<uint64_t>(dstTempAddr +
                                                    sizeof(hostArchRegDataHdr));
                //Update SBE data source address to point to the register data
                //related to the current thread.
                procSrcAddr = reinterpret_cast<uint64_t>(procSrcAddr +
                                             sizeof(sbeArchRegDumpThreadHdr_t));

                //Validate the CoreState to find if the buffer has register data
                if (sbeTdHdr->coreState != 0)
                {
                    //Bump up the destination address to skip the memory
                    //required to store the register details.
                    dstTempAddr = reinterpret_cast<uint64_t>(dstTempAddr +
                                     (regCount * sizeof(hostArchRegDataEntry)));
                    continue;
                }

                // Fill register data
                for(uint8_t cnt = 0; cnt < regCount; cnt++)
                {
                    sbeArchRegDumpEntries_t *sbeRegData =
                       reinterpret_cast<sbeArchRegDumpEntries_t *>(procSrcAddr);
                    hostArchRegDataEntry *hostRegData =
                         reinterpret_cast<hostArchRegDataEntry *>(dstTempAddr);

                    hostRegData->regType = sbeRegData->regType;
                    hostRegData->regNum  = sbeRegData->regNum;
                    hostRegData->regVal  = sbeRegData->regVal;

                    dstTempAddr = reinterpret_cast<uint64_t>(dstTempAddr +
                                                  sizeof(hostArchRegDataEntry));
                    //Update the SBE data source address to point to the
                    //next register data related to the same thread.
                    procSrcAddr = reinterpret_cast<uint64_t>(procSrcAddr +
                                               sizeof(sbeArchRegDumpEntries_t));
                    if( sbeRegData->isLastReg )
                    {
                        //Skip the FFDC for now
                        if(sbeRegData->isFfdcPresent)
                        {
                            //Move the source address to skip theFFDC
                            procSrcAddr = procSrcAddr + (sizeof(uint32_t)*SBE_FFDC_SIZE);
                            //Adjust the destination address accordingly to skip
                            //the mememory required for remaining registers
                            uint32_t remaingRegCount = regCount - (cnt+1);
                            if(remaingRegCount)
                            {
                                dstTempAddr = reinterpret_cast<uint64_t>(
                                               dstTempAddr + (remaingRegCount *
                                               sizeof(hostArchRegDataEntry)));
                            }
                        }
                        break;
                    }
                }
            }
        }
        // Update Process Dump Area tuple
        procTableEntry->threadRegVersion = REG_DUMP_HDAT_STRUCT_VER;
        procTableEntry->capArrayAddr = procTableEntry->dstArrayAddr;

        // Update the PDA Table Entries to Attribute to be fetched in istep 21
        TARGETING::TargetService& targetService = TARGETING::targetService();
        TARGETING::Target* l_sys = NULL;
        targetService.getTopLevelTarget(l_sys);
        l_sys->setAttr<TARGETING::ATTR_PDA_THREAD_REG_STATE_ENTRY_FORMAT>(
                                              procTableEntry->threadRegVersion);
        l_sys->setAttr<TARGETING::ATTR_PDA_THREAD_REG_ENTRY_SIZE>(
                                                 procTableEntry->threadRegSize);
        l_sys->setAttr<TARGETING::ATTR_PDA_CAPTURED_THREAD_REG_ARRAY_ADDR>(
                                                  procTableEntry->capArrayAddr);
        l_sys->setAttr<TARGETING::ATTR_PDA_CAPTURED_THREAD_REG_ARRAY_SIZE>(
                                                  procTableEntry->capArraySize);

    } while (0);

    // Unmap destination memory
    if (vMapDstAddrBase)
    {
        rc = mm_block_unmap(vMapDstAddrBase);
        if (rc != 0)
        {
            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_ARCH_REGS
             * @reasoncode   DUMP::DUMP_PDAT_CANNOT_UNMAP_DST_ADDR
             * @userdata1    VA of Destination Array Address for PDAT
             * @userdata2    rc value from unmap
             * @devdesc      Cannot unmap the PDAT Destinatin Array Addr
             */
            l_err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  DUMP_ARCH_REGS,
                                  DUMP_PDAT_CANNOT_UNMAP_DST_ADDR,
                                  (uint64_t)vMapDstAddrBase,
                                  rc,
                                  ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            // Commit the error and continue.
            // Leave the devices unmapped?
            errlCommit(l_err, DUMP_COMP_ID);
            l_err = NULL;
        }
    }

    // Unmap source memory
    if(vMapSrcAddrBase)
    {
        rc = mm_block_unmap(vMapSrcAddrBase);
        if (rc != 0)
        {
            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_ARCH_REGS
             * @reasoncode   DUMP::DUMP_PDAT_CANNOT_UNMAP_SRC_ADDR
             * @userdata1    VA address of Source Array Address for PDAT
             * @userdata2    rc value from unmap
             * @devdesc      Cannot unmap the PDAT Source Array Address
             */
            l_err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  DUMP_ARCH_REGS,
                                  DUMP_PDAT_CANNOT_UNMAP_SRC_ADDR,
                                  (uint64_t)vMapSrcAddrBase,
                                  rc,
                                  ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            // Commit the error and continue.
            // Leave the devices unmapped?
            errlCommit(l_err, DUMP_COMP_ID);
            l_err = NULL;
        }
    }
    TRACFCOMP(g_trac_dump, "copyArchitectedRegs - end ");
    return (l_err);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

errlHndl_t copySrcToDest(dumpEntry *srcTableEntry,
                         uint64_t srcTableSize,
                         dumpEntry *destTableEntry,
                         uint64_t destTableSize,
                         resultsEntry *resultsTableEntry,
                         uint64_t resultsTableSize)
{
    TRACFCOMP(g_trac_dump, "copySrcToDest - start ");

    errlHndl_t l_err = NULL;
    int rc = 0;
    bool invalidSrcSize = false;
    bool invalidDestSize = false;
    uint32_t l_resultCount = 0x0;

    // local src table info
    uint64_t *vaSrcTableAddr = 0;
    uint64_t *vaMapSrcTableAddr = 0;
    uint64_t curSrcTableAddr = 0;

    // destination table info
    uint64_t *vaDestTableAddr = 0;
    uint64_t *vaMapDestTableAddr = 0;
    uint64_t curDestTableAddr = 0;

    // Data sizes
    uint64_t sizeToCopy = 0;
    uint64_t bytesLeftInSrc = 0;
    uint64_t bytesLeftInDest = 0;

    do
    {

        // Need to loop through all the source entries.. Copying into a
        // destination entry.  Note the src could be larger than the
        // destination size and could require multiple copies.. In addition
        // the size of the destination could be larger than 1 source entry.
        // These entries need to be packed into the destination.. so 1
        // destination entry could have multiple source entries in it.
        // After each copy need to write an entry into the results table
        // source/destination/size.

        // Figure out the num of entries in the src table
        uint64_t maxSrcEntries = srcTableSize/(sizeof (dumpEntry));

        // Figure out the num of entries in the dest table
        uint64_t maxDestEntries = destTableSize/(sizeof (dumpEntry));

        // Figure out the max result entires
        uint64_t maxResultEntries = resultsTableSize/(sizeof
                                                      (resultsEntry));

        // Index into each Dump table
        uint64_t curSourceIndex = 0;
        uint64_t curDestIndex = 0;
        uint64_t curResultIndex = 0;

        // Map in the first source and destination entries from their
        // corresponding tables.
        // NOTE: When mapping a device the address we are mapping needs to
        // be page aligned.  In addition the VA returned is page
        // aligned so we need to add the offset of the page aligned address
        // to the VA returned

        // Get the first Source address and size
        curSrcTableAddr = srcTableEntry[curSourceIndex].dataAddr;
        bytesLeftInSrc = srcTableEntry[curSourceIndex].dataSize;

        // Get the first destination address and size.
        curDestTableAddr = destTableEntry[curDestIndex].dataAddr;
        bytesLeftInDest = destTableEntry[curDestIndex].dataSize;

        // Determine the src and destination offset.
        uint64_t destOffset = curDestTableAddr
          - ALIGN_PAGE_DOWN(curDestTableAddr);
        uint64_t srcOffset = curSrcTableAddr
          - ALIGN_PAGE_DOWN(curSrcTableAddr);

        // If the data size is greater then 32GB after page alignment
        // create an error.  Current limitation on DevMap is 32GB in size.
        // Not sure yet if we will ever see a table entry > 3GB.
        if (bytesLeftInSrc + srcOffset > THIRTYTWO_GB)
        {
            invalidSrcSize = true;
            break;
        }
        else if ((bytesLeftInDest + destOffset > THIRTYTWO_GB))
        {
            invalidDestSize = true;
            break;
        }

        vaMapSrcTableAddr = (static_cast<uint64_t*>(mm_block_map(
                              getPhysAddr(curSrcTableAddr),
                              THIRTYTWO_GB)));

        vaSrcTableAddr = vaMapSrcTableAddr;

        vaMapDestTableAddr = (static_cast<uint64_t*>(mm_block_map(
                               getPhysAddr(curDestTableAddr),
                               THIRTYTWO_GB)));

        vaDestTableAddr = vaMapDestTableAddr;

        // add the offset to the src and destination VAs,
        vaSrcTableAddr += (srcOffset/(sizeof (uint64_t)));

        vaDestTableAddr += (destOffset/(sizeof (uint64_t)));

        // Current Source physical and Va address
        TRACFCOMP(g_trac_dump, "copySrcToDest SrcTableIndex = %d, srcTableAddr = %.16X, VA = %.16X",  curSourceIndex, curSrcTableAddr, vaSrcTableAddr);

        // Current Destination physical and Va address
        TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest DestTableIndex = %d, DestTableAddr = %.16X, VA = %.16X", curDestIndex, curDestTableAddr, vaDestTableAddr);

        resultsTableEntry->dataSize = 0x0;

        while(1)
        {
            // If we have copied all the bytes in the src entry
            if (bytesLeftInSrc == 0)
            {
                // unmap the previous src entry
                rc =  mm_block_unmap(
                            reinterpret_cast<void*>(vaMapSrcTableAddr));

                if (rc != 0)
                {
                    /*@
                     * @errortype
                     * @moduleid     DUMP::DUMP_COLLECT
                     * @reasoncode   DUMP::DUMP_CANNOT_UNMAP_SRC
                     * @userdata1    VA address of the MDST to unmap
                     * @userdata2    rc value from unmap
                     * @devdesc      Cannot unmap the source table section
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          DUMP_COLLECT,
                                          DUMP_CANNOT_UNMAP_SRC,
                                          (uint64_t)vaMapSrcTableAddr,
                                          rc);

                    // commit the error and continue.
                    // Leave the devices unmapped for now.
                    errlCommit(l_err,DUMP_COMP_ID);

                    l_err = NULL;

                }

                // increment to the next src entry
                curSourceIndex++;

                // if we have reach all entries
                if (curSourceIndex >= maxSrcEntries)
                {
                    TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest - through all src entries");
                    break;
                }

                curSrcTableAddr = srcTableEntry[curSourceIndex].dataAddr;
                bytesLeftInSrc = srcTableEntry[curSourceIndex].dataSize;

                // src address 0 is valid source address on OPAL sytems
                if (!TARGETING::is_sapphire_load())
                {
                    // If the current Src table Address is 0 we are done
                    if (curSrcTableAddr == 0)
                    {
                        break;
                    }
                }

                srcOffset =  curSrcTableAddr -
                  ALIGN_PAGE_DOWN(curSrcTableAddr);

                // If the data size is less then 32GB after page alignment
                if (bytesLeftInSrc + srcOffset > THIRTYTWO_GB)
                {
                    invalidSrcSize = true;
                    break;
                }

                // map the MDST entry to a device such that we can read and
                //  write from that memory address
                vaMapSrcTableAddr = (static_cast<uint64_t*>(mm_block_map(
                                      getPhysAddr(curSrcTableAddr),
                                      THIRTYTWO_GB)));

                vaSrcTableAddr = vaMapSrcTableAddr;

                vaSrcTableAddr += (srcOffset/(sizeof (uint64_t)));

                // Current Source physical and Va address
                TRACFCOMP(g_trac_dump, "copySrcToDest SrcTableIndex = %d, srcTableAddr = %.16X, VA = %.16X",  curSourceIndex, curSrcTableAddr, vaSrcTableAddr);

            }

            // If there is no more space in the destination area
            if (bytesLeftInDest == 0)
            {
                // unmap the previous dest entry
                rc =  mm_block_unmap(
                            reinterpret_cast<void*>(vaMapDestTableAddr));
                if (rc != 0)
                {
                    /*@
                     * @errortype
                     * @moduleid     DUMP::DUMP_COLLECT
                     * @reasoncode   DUMP::DUMP_CANNOT_UNMAP_DEST
                     * @userdata1    VA address of the MDDT to unmap
                     * @userdata2    rc value from unmap
                     * @devdesc      Cannot unmap the source table section
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          DUMP_COLLECT,
                                          DUMP_CANNOT_UNMAP_DEST,
                                          (uint64_t)vaMapDestTableAddr,
                                          rc);

                    // commit the error and continue.
                    //  Leave the devices unmapped?
                    errlCommit(l_err,DUMP_COMP_ID);

                    l_err = NULL;
                }

                // increment to the next dest entry
                curDestIndex++;

                // if made it through all dest entries.
                if (curDestIndex >= maxDestEntries)
                {
                    // need to check here to see if we still have SRC
                    // entries not copied.
                    if (bytesLeftInSrc != 0)
                    {
                        // Write an error because we have more src entries
                        // then destination space available.
                        TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: not enough Destination table entries");

                        /*@
                         * @errortype
                         * @moduleid     DUMP::DUMP_COLLECT
                         * @reasoncode   DUMP::DUMP_MDDT_INSUFFICIENT_ENTRIES
                         * @userdata1    Source Entires bytes left to copy
                         * @userdata2    Index into the MDST table
                         * @devdesc      MDDT table is not big enough to
                         *               hold all src entries
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              DUMP_COLLECT,
                                              DUMP_MDDT_INSUFFICIENT_ENTRIES,
                                              bytesLeftInSrc,
                                              curSourceIndex);

                        // do not commit this errorlog error as this is a
                        // real problem.

                        // TODO:  RTC: 64399
                        //  Need to add the src entries and sizes? that did
                        //  not get copied to the destination. This error
                        //  condition is such that the table entries are
                        // exceeded.
                    }

                    break;
                }

                curDestTableAddr = destTableEntry[curDestIndex].dataAddr;
                bytesLeftInDest = destTableEntry[curDestIndex].dataSize;

                //check to see if there are contiguous destination addresses
                while ((destTableEntry[curDestIndex].dataAddr +
                        destTableEntry[curDestIndex].dataSize) ==
                       destTableEntry[curDestIndex+1].dataAddr)
                {
                    curDestIndex++;
                    bytesLeftInDest +=destTableEntry[curDestIndex].dataSize;
                }

                // If the current dest addr or the size to copy are zero.
                if ((curDestTableAddr == 0) || (bytesLeftInDest == 0))
                {

                    // If there are still SRC entries to copy with no
                    // destination send an error back.
                    if (bytesLeftInSrc != 0)
                    {
                        // Write an error because we have more src entries
                        // then destination space available.
                        TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: not enough Destination table space");

                        /*@
                         * @errortype
                         * @moduleid     DUMP::DUMP_COLLECT
                         * @reasoncode   DUMP::DUMP_MDDT_INSUFFICIENT_SPACE
                         * @userdata1    Source Entires bytes left to copy
                         * @userdata2    Index into the MDST table
                         * @devdesc      MDDT table is not big enough to
                         *               hold all src entries
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              DUMP_COLLECT,
                                              DUMP_MDDT_INSUFFICIENT_SPACE,
                                              bytesLeftInSrc,
                                              curSourceIndex);

                        // do not commit this errorlog error as this is a
                        // real problem.

                        // TODO:  RTC: 64399
                        //  Need to add the src entries and sizes? that did
                        //  not get copied to the destination.  This
                        //  condition is such that we have a destination
                        //  entry that either has a zero address or zero
                        //  size.. Perhaps put the bad destination entry
                        //  there as well
                    }

                    break;
                }

                destOffset =  curDestTableAddr
                  - ALIGN_PAGE_DOWN(curDestTableAddr);

                // If the data size is less then 32GB after page alignment
                if (bytesLeftInDest + destOffset > THIRTYTWO_GB)
                {
                    invalidDestSize = true;
                    break;
                }

                // map the MDDT to a VA addresss
                vaMapDestTableAddr = (static_cast<uint64_t*>(mm_block_map(
                                       getPhysAddr(curDestTableAddr),
                                       THIRTYTWO_GB)));

                vaDestTableAddr = vaMapDestTableAddr;

                vaDestTableAddr += (destOffset/(sizeof(uint64_t)));

                // Current Destination physical and Va address
                TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest DestTableIndex = %d, DestTableAddr = %.16X, VA = %.16X", curDestIndex, curDestTableAddr, vaDestTableAddr);

            }


            // Determine how much to copy..
            sizeToCopy = std::min(bytesLeftInSrc, bytesLeftInDest);

            // Do the copy of the data from the source to the destination
            mm_tolerate_ue(1);
            memcpy( vaDestTableAddr,vaSrcTableAddr, sizeToCopy);
            mm_tolerate_ue(0);

            if (curResultIndex < maxResultEntries)
            {
                // Update the results table
                resultsTableEntry->srcAddr =
                  VmmManager::FORCE_PHYS_ADDR|curSrcTableAddr;
                resultsTableEntry->destAddr =
                  VmmManager::FORCE_PHYS_ADDR|curDestTableAddr;
                resultsTableEntry->dataSize = sizeToCopy;
                // Size field in source/destination table is of 4 bytes.
                // So result table size field will never cross 4 bytes.
                // Hence use top 2 bytes to copy data_type from source
                // table to result table (see HDAT spec for details).
                if (TARGETING::is_sapphire_load())
                {
                    uint64_t data_type = srcTableEntry[curSourceIndex].data_type;
                    resultsTableEntry->dataSize |= (data_type << 48);
                }
                resultsTableEntry++;
                l_resultCount++;
                curResultIndex++;
            }
            else
            {
                TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: not enough result table space");

                /*@
                 * @errortype
                 * @moduleid     DUMP::DUMP_COLLECT
                 * @reasoncode   DUMP::DUMP_MDRT_INSUFFICIENT_SPACE
                 * @userdata1    Index into the MDRT
                 * @userdata2    max entries allowed given space allocated
                 * @devdesc      MDRT table is not big enough to hold all
                 *               entries
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                DUMP_COLLECT,
                                                DUMP_MDRT_INSUFFICIENT_SPACE,
                                                curResultIndex,
                                                maxResultEntries);

                // commit the error and continue.
                errlCommit(l_err,DUMP_COMP_ID);

                l_err = NULL;
            }

            // decrement the amount copied from the source and destination
            bytesLeftInSrc -= sizeToCopy;
            bytesLeftInDest -= sizeToCopy;

            uint64_t addrOffset = sizeToCopy/(sizeof (uint64_t));

            // increment the current src and dest addresses in both the
            // physical and virtual addresses.
            curSrcTableAddr += sizeToCopy;
            curDestTableAddr += sizeToCopy;
            vaSrcTableAddr += addrOffset;
            vaDestTableAddr += addrOffset;
        } // end of while loop


        if (invalidSrcSize)
        {
            // Write an error because we have more src entries
            // then destination space available.
            TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: Source TableSize > 32GB");

            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_COLLECT
             * @reasoncode   DUMP::DUMP_MDST_INVALID_TABLE_SIZE
             * @userdata1    Size of Source Table Entry
             * @userdata2    Size of Page Aligned Source Table Entry
             * @devdesc      MDST table entry with page aligned is
             *               greater than 32GB
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            DUMP_COLLECT,
                                            DUMP_MDST_INVALID_TABLE_SIZE,
                                            bytesLeftInSrc,
                                            bytesLeftInSrc + srcOffset);
            break;

        }
        if (invalidDestSize)
        {
            // Write an error because we have more src entries
            // then destination space available.
            TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: Destination TableSize > 32GB");

            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_COLLECT
             * @reasoncode   DUMP::DUMP_MDDT_INVALID_TABLE_SIZE
             * @userdata1    Size of Destination Table Entry
             * @userdata2    Size of Page Aligned Destination Table Entry
             * @devdesc      MDDT table entry with page aligned is
             *               greater than 32GB
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            DUMP_COLLECT,
                                            DUMP_MDDT_INVALID_TABLE_SIZE,
                                            bytesLeftInDest,
                                            bytesLeftInDest + destOffset);

            break;
        }

        // Update the MDRT Count to Attribute to be fetched in istep 21
        TARGETING::TargetService& l_targetService = TARGETING::targetService();
        TARGETING::Target* l_sys = NULL;
        l_targetService.getTopLevelTarget(l_sys);
        l_sys->setAttr<TARGETING::ATTR_MPIPL_HB_MDRT_COUNT>(l_resultCount);

        //Update actual count in RUNTIME
        RUNTIME::saveActualCount(RUNTIME::MS_DUMP_RESULTS_TBL,
                                 l_resultCount);

        //Write actual count into memory as well
        // We know this will get whacked when FSP reloads the PHYP
        // lid, but we want it to be valid before that to allow
        // FSP code to consume the data from mainstore
        RUNTIME::writeActualCount(RUNTIME::MS_DUMP_RESULTS_TBL);
    }while(0);// end of do-while loop

    // Got an errorlog back from get_host_data_sections
    TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest - COMPLETE ");

    return l_err;
}



    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////

    errlHndl_t getHostDataPtrs(dumpEntry *&srcTableEntry,
                               uint64_t &srcTableSize,
                               dumpEntry *&destTableEntry,
                               uint64_t &destTableSize,
                               resultsEntry *&resultsTableEntry,
                               uint64_t &resultsTableSize)

    {

        errlHndl_t l_err = NULL;
        int rc = 0;
        bool l_error = false;
        uint64_t l_section = 0;
        uint64_t l_addr = 0;
        uint64_t srcTableAddr = 0;
        uint64_t destTableAddr = 0;
        uint64_t resultsTableAddr = 0;


        do
        {

            // Get the Src Table address  (MDST)
            l_err = RUNTIME::get_host_data_section(RUNTIME::MS_DUMP_SRC_TBL,
                                                   0,
                                                   srcTableAddr,
                                                   srcTableSize);


            if (l_err)
            {
                // Got an errorlog back from get_host_data_sections
                TRACFCOMP(g_trac_dump, "HBDumpGetHostData get_host_data_sections for MDST failed rc=0x%X", rc);

                break;
            }

            // If the address or size is zero - error out
            if ((srcTableSize == 0) || (srcTableAddr == 0))
            {
                // Invalid size or address
                TRACFCOMP(g_trac_dump, "HBDumpGetHostData address or size invalie for MDST: addr =0x%X, size =0x%X," , srcTableAddr, srcTableSize);

                l_section = RUNTIME::MS_DUMP_SRC_TBL;
                l_addr = srcTableAddr;
                l_error = true;
                // got back a bad address
                break;
            }

            srcTableEntry = reinterpret_cast<dumpEntry *>(srcTableAddr);

            // Get the Destination Table Address (MDDT)
            l_err = RUNTIME::get_host_data_section(RUNTIME::MS_DUMP_DST_TBL,
                                                   0,
                                                   destTableAddr,
                                                   destTableSize);


            if (l_err)
            {
                // Got an errorlog back from get_host_data_sections
                TRACFCOMP(g_trac_dump, "HBDumpGetHostData get_host_data_sections for MDDT failed rc=0x%X", rc);

                break;
            }

            // If the address or size is zero - error out
            if ((destTableSize == 0) || (destTableAddr == 0))
            {
                // Invalid size or address
                TRACFCOMP(g_trac_dump,
                          "HBDumpGetHostData address or size invalie for MDDT: addr =0x%X, size =0x%X," ,
                          destTableAddr, destTableSize);

                l_section = RUNTIME::MS_DUMP_DST_TBL;
                l_addr = destTableAddr;
                l_error = true;

                // got back a bad address
                break;
            }

            destTableEntry = reinterpret_cast<dumpEntry *>(destTableAddr);

            // Get the Results Table Address
            l_err = RUNTIME::get_host_data_section(RUNTIME::MS_DUMP_RESULTS_TBL,
                                                   0,
                                                   resultsTableAddr,
                                                   resultsTableSize);


            if (l_err)
            {
                // Got an errorlog back from get_host_data_sections
                TRACFCOMP(g_trac_dump, "HBDumpGetHostData get_host_data_sections for MDDT failed rc=0x%X", rc);

                break;
            }

            // If the address or size is zero - error out
            if ((resultsTableSize == 0) || (resultsTableAddr == 0))
            {
                // Invalid size or address
                TRACFCOMP(g_trac_dump,
                          "HBDumpGetHostData address or size invalid for MDRT: addr =0x%X, size =0x%X," ,
                          resultsTableAddr, resultsTableSize);

                l_section = RUNTIME::MS_DUMP_RESULTS_TBL;
                l_addr = resultsTableAddr;
                l_error = true;
                // got back a bad address
                break;
            }

            // Each results table entry has the Source,Destination and Size for
            // each copy that is done from source to destination
            resultsTableEntry =
              reinterpret_cast<resultsEntry *>(resultsTableAddr);

            TRACFCOMP(g_trac_dump,
                      "gethostDataPtrs SrcTableAddr = %.16x, DestTableAddr = %.16X, resultTableAddr = %.16X",
                      srcTableAddr, destTableAddr, resultsTableAddr);

        }while(0);

        if (l_error)
        {

            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_COLLECT
             * @reasoncode   DUMP::DUMP_NO_HDAT_ADDR
             * @userdata1    Address returned
             * @userdata2    Table type Requested
             * @devdesc      Invalid address and size returned from HDAT
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            DUMP_COLLECT,
                                            DUMP_NO_HDAT_ADDR,
                                            l_addr,
                                            l_section);

        }

        return (l_err);
    }


    // ------------------------------------------------------------------
    // sendMboxMsg
    // ------------------------------------------------------------------
    errlHndl_t sendMboxMsg(DUMP_MSG_TYPE i_type)

    {
        errlHndl_t l_err = NULL;
        msg_t* msg = NULL;
        TRACFCOMP( g_trac_dump,
                   ENTER_MRK"sendMboxMsg()" );

        do
        {

            //Create a mailbox message to send to FSP
            msg = msg_allocate();
            msg->type = i_type;

            // If this is not a dump start message, need to collect the
            // Results table and size as well as the results table itself.
            if (i_type != DUMP_MSG_START_MSG_TYPE)
            {
                uint64_t resultsTableAddr = 0;
                uint64_t resultsTableSize = 0;

                // Get the Results Table Address
                l_err =
                  RUNTIME::get_host_data_section(RUNTIME::MS_DUMP_RESULTS_TBL,
                                                 0,
                                                 resultsTableAddr,
                                                 resultsTableSize);


                if (l_err)
                {
                    // Got an errorlog back from get_host_data_sections
                    TRACFCOMP(g_trac_dump, "HBDumpGetHostData get_host_data_sections for MDDT failed rc=0x%X", l_err->reasonCode());
                }
                // If the address or size is zero - error out
                else if ((resultsTableSize == 0) || (resultsTableAddr == 0))
                {
                    // Invalid size or address
                    TRACFCOMP(g_trac_dump,
                              "HBDumpGetHostData address or size invalid for MDRT: addr =0x%X, size =0x%X," ,
                              resultsTableAddr, resultsTableSize);


                    // Create an errorlog and change the type to error and add
                    // the plid to the data section.

                    /*@
                     * @errortype
                     * @moduleid     DUMP::DUMP_SEND_MBOX_MSG
                     * @reasoncode   DUMP::DUMP_NO_HDAT_ADDR
                     * @userdata1    Address returned
                     * @userdata2    Table type Requested
                     * @devdesc      Invalid address and size returned from HDAT
                     */
                    l_err =
                      new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              DUMP_SEND_MBOX_MSG,
                                              DUMP_NO_HDAT_ADDR,
                                              resultsTableAddr,
                                              i_type);

                }

                // if no error then collect as expected.
                if (!l_err)
                {
                    // Physical Address of the results table
                    uint64_t l_mdrt_phys =
                      mm_virt_to_phys(
                          reinterpret_cast<void*>(resultsTableAddr));

                    // If TCEs are enabled setup TCEs in TCE Table to allow
                    // the FSP to read this memory
                    if (TCE::utilUseTcesForDmas())
                    {
                        // Align Physical addr down for TCE requirement
                        uint64_t mdrt_phys_aligned =
                                   ALIGN_PAGE_DOWN(l_mdrt_phys);

                        uint64_t offset = l_mdrt_phys - mdrt_phys_aligned;

                        TRACFCOMP( g_trac_dump,"Setup TCEs for FSP to use for "
                                   "l_mdrt_phys=0x%.16llX (virt=0x%.16llX, "
                                   "aligned_phys=0x%.16llX, offset=0x%X)",
                                   l_mdrt_phys, resultsTableAddr,
                                   mdrt_phys_aligned, offset);

                        uint32_t token = 0;
                        l_err = TCE::utilAllocateTces(mdrt_phys_aligned,
                                                      resultsTableSize+offset,
                                                      token,
                                                      false); //Read-Only

                        if (l_err)
                        {
                            // Got an errorlog back from utilAllocateTces
                            TRACFCOMP(g_trac_dump, "HBDumpGetHostData utilAllocateTces failed rc=0x%X", l_err->reasonCode());
                        }
                        else
                        {
                            // Put the token with the offset into the msg
                            msg->data[0] = token + offset;
                        }
                    }
                    else
                    {
                        msg->data[0] = l_mdrt_phys;
                    }

                    // Number of bytes in the results table
                    msg->data[1] = resultsTableSize;

                    // No extra data to worry about
                    msg->extra_data = NULL;

                }

                if (l_err)
                {
                    TRACFCOMP( g_trac_dump,
                               INFO_MRK"Got an error trying to send msg. %.8X,",
                               i_type);

                    // change the msg type to be error type
                    i_type = DUMP_MSG_ERROR_MSG_TYPE;

                    l_err->collectTrace("DUMP",1024);

                    // Put a default value into the data[0] indicating plid to in data[1]
                    msg->data[0] = 0xFFFF;

                    msg->data[1] = l_err->plid(); // plid

                    // just commit the log from failure on Read.. and
                    // send an error msg to FSP.
                    errlCommit( l_err, DUMP_COMP_ID );
                    l_err = NULL;

                }
            }


            TRACFCOMP( g_trac_dump,
                       INFO_MRK"Send msg to FSP about DUMP %.8X,",
                       i_type);

            // Send the message
            l_err = MBOX::send( MBOX::FSP_DUMP_MSGQ_ID, msg );

            // got an error.. Free the msg space allocated above.
            if( l_err )
            {
                TRACFCOMP(g_trac_dump,
                          ERR_MRK "Failed sending DUMP to FSP for %.8X",i_type);

                l_err->collectTrace("DUMP",1024);

                free( msg->extra_data );
                msg->extra_data = NULL;
                msg_free( msg );
            }
        } while( 0 );


        TRACFCOMP( g_trac_dump,
                   EXIT_MRK"sendMboxMsg()" );

        return l_err;
    }


}; // end of namespace
