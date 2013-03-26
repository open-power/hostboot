/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/tce.C $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef __TCE_C
#define __TCE_C

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <vmmconst.h>
#include <runtime/tceif.H>
#include <sys/mmio.h>
#include <util/align.H>
#include <sys/mm.h>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <kernel/console.H>
#include "tce.H"
#include <runtime/runtime_reasoncodes.H>
#include <assert.h>

trace_desc_t* g_trac_tce = NULL;
TRAC_INIT(&g_trac_tce, "TCE", 4*KILOBYTE);


namespace TCE
{
    /*************************************************************************/
    // External Interface.
    // NAME: createTceTable Table.
    //      Responsible for initalizing the TCE entries
    //
    /*************************************************************************/
    errlHndl_t createTceTable()
    {
       return Singleton<TceMgr>::instance().createTceTable();
    };

    /************************************************************************/
    // External Interface.
    // NAME: InitTceInHdw
    //      Responsible for setting up the Processors to point to the TCE table
    //
    /************************************************************************/
    errlHndl_t initTceInHdw()
    {
       return Singleton<TceMgr>::instance().initTceInHdw();
    };

    /************************************************************************/
    //  External Interface:
    //  NAME: allocateTces
    //     Responsible for allocating TCE Entries
    //
    /************************************************************************/
    errlHndl_t allocateTces(uint64_t startingAddress, uint64_t size, uint64_t&
                            startingToken)
    {

        return Singleton<TceMgr>::instance().allocateTces(startingAddress,
                                                           size,
                                                           startingToken);
    };

    /************************************************************************/
    // External Interface:
    // NAME: deallocateTces
    //     Responsible for deallocating TCE Entries
    //
    /************************************************************************/
    errlHndl_t deallocateTces(uint64_t startingToken, uint64_t size)
    {
        return Singleton<TceMgr>::instance().deallocateTces(startingToken,
                                                             size);
    };

};

    /************************************************************************/
    //
    // NAME: TceMgr
    //      Constructor - set up Tce Table pointers
    //
    /************************************************************************/
    TceMgr::TceMgr(uint64_t i_tableAddr, uint64_t i_tableSize)
      :tceEntryInit(0)
      ,tceTableVaPtr(NULL)
      ,tceTablePhysAddr(i_tableAddr)
      ,maxTceEntries(0)
      ,tceTableSize(i_tableSize)
    {
            maxTceEntries = tceTableSize/(sizeof (uint64_t));
    };

    /**************************************************************************/
    //
    // NAME: mapTceTable
    //      Utilty to map the Tce Table
    //
    /**************************************************************************/
    errlHndl_t TceMgr::mapTceTable()
    {
        errlHndl_t errl = NULL;

        do
        {

            // check to make sure the TCE table is not larger than 32M..
            if (tceTableSize > THIRTYTWO_MB)
            {

                // TCE table size larger than 32M.. code bug likely as the real
                // TCE table is a fixed address and size.
                TRACFCOMP(g_trac_tce,"TceMgr::mapTceTable: Table size too large..cannot map.");

                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_TCE_MAP
                 * @reasoncode   RUNTIME::RC_TCE_INVALID_SIZE
                 * @userdata1    Address of the TCE Table
                 * @userdata2    Size of of the table that is too large?
                 * @devdesc      TCE Table size requested too large.
                 */
                errl = new ERRORLOG::ErrlEntry(
                                               ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               RUNTIME::MOD_TCE_MAP,
                                               RUNTIME::RC_TCE_INVALID_SIZE,
                                               tceTablePhysAddr,
                                               tceTableSize);

                break;

            }

            // Is the TCE TABLE Address page aligned?
            if (tceTablePhysAddr - ALIGN_PAGE_DOWN(tceTablePhysAddr)!=0)
            {
                // Address not page aligned
                TRACFCOMP(g_trac_tce,"TceMgr::mapTceTable: Table Addr not page aligned.");

                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_TCE_MAP
                 * @reasoncode   RUNTIME::RC_TCE_ADDR_NOT_ALIGNED
                 * @userdata1    Address of the TCE Table
                 * @userdata2    none
                 * @devdesc      TCE Table not page aligned.
                 */
                errl = new ERRORLOG::ErrlEntry(
                                               ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               RUNTIME::MOD_TCE_MAP,
                                               RUNTIME::RC_TCE_ADDR_NOT_ALIGNED,
                                               tceTablePhysAddr,
                                               0);

                break;
            }


            // If the physical address is less than the VMM size, then the
            // address we are mapping in on the heap and is already mapped.
            // NOTE:  This is needed for testing a TCE table outside of the
            // default TCE table location.
            if (tceTablePhysAddr < VMM_MEMORY_SIZE)
            {
                tceTableVaPtr = reinterpret_cast<TceEntry *>(tceTablePhysAddr);

            }
            else
            {
                // Map the Physical Tce table Pointer
                tceTableVaPtr =
                  reinterpret_cast<TceEntry *>(
                       mmio_dev_map(reinterpret_cast<void*>(tceTablePhysAddr),
                                    THIRTYTWO_MB));

                if (tceTableVaPtr == NULL)
                {
                    // Got a bad rc from dev Map
                    TRACFCOMP(g_trac_tce, "TceMgr::mapTceTable: Device map error.");

                    /*@
                     * @errortype
                     * @moduleid     RUNTIME::MOD_TCE_MAP
                     * @reasoncode   RUNTIME::RC_TCE_DEV_MAP_FAIL
                     * @userdata1    Address to be mapped
                     * @userdata2    return Code from DevMap
                     * @devdesc      Device Map Fail
                     */
                    errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    RUNTIME::MOD_TCE_MAP,
                                    RUNTIME::RC_TCE_DEV_MAP_FAIL,
                                    tceTablePhysAddr,
                                    tceTableSize);
                }
            }
        }while(0);

        return errl;
    }

    /**************************************************************************/
    //
    // NAME: createTceTable
    //      Responsible for initalizing the TCE entries
    //
    /**************************************************************************/
    errlHndl_t TceMgr::createTceTable()
    {

        errlHndl_t errl = NULL;

        TRACFCOMP(g_trac_tce,"TceMgr::creatTceTable: tceTablePhysAddr = %llx tceTableSize = %llx",tceTablePhysAddr, tceTableSize);

        do
        {
            // Map the Tce Table
            errl = mapTceTable();

            if (errl != NULL)
            {
               break;
            }

            // Zero out the TCE table space.
            memset(tceTableVaPtr, 0, tceTableSize);

            // make sure that the memset completes.
            sync();

        }while(0);

       return errl;
    };

    /**************************************************************************/
    //
    // NAME: InitTceInHdw
    //      Responsible for setting up the Processors to point to the TCE table
    //
    /**************************************************************************/
    errlHndl_t TceMgr::initTceInHdw()
    {
        errlHndl_t errl = NULL;

        TRACFCOMP(g_trac_tce,
                  "TceMgr::InitTceInHdw: tceTablePhysAddr = %llx",
                  tceTablePhysAddr);
        do
        {

            // Loop through the processors and read the PSI_BRIDGE_ADDR
            TARGETING::TargetHandleList l_cpuTargetList;
            getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

            // Map a device at the PSI_BRIDE_ADDR -
            //            <attribute><id>PSI_BRIDGE_BASE_ADDR</id>
            //            <default>0x0003FFFE80000000</default>
            uint64_t *mmio_ptr = NULL;

            // set up the registers for TCE on all procs
            for (TARGETING::TargetHandleList::const_iterator
                 l_cpuIter = l_cpuTargetList.begin();
                 l_cpuIter != l_cpuTargetList.end();
                 ++l_cpuIter)
            {
                const TARGETING::Target* l_pTarget = *l_cpuIter;
                uint64_t PsiBridgeAddr =
                  l_pTarget->getAttr<TARGETING::ATTR_PSI_BRIDGE_BASE_ADDR>();

                TRACDCOMP(g_trac_tce,"TceMgr::InitTceInHdw:Psi Bridge Addr = %llx huid = %.8X",PsiBridgeAddr, TARGETING::get_huid(l_pTarget));

                // Check if the PSI_BRIDEG_BASE_ADDR is nonzero.. (could be for
                // Tuleta)
                if (PsiBridgeAddr != 0)
                {
                    // If the PsiBridgeAddr is not page aligned. assert.
                    assert((PsiBridgeAddr - ALIGN_PAGE_DOWN(PsiBridgeAddr)) ==
                           0);

                    // Map the device for the PSI_BRIDGE_ADDR
                    mmio_ptr =
                      static_cast<uint64_t*>(
                        mm_block_map(
                          reinterpret_cast<void*>(PsiBridgeAddr),
                                                   PAGESIZE));

                    if (mmio_ptr == NULL)
                    {
                        // Got a bad rc from device Map
                        TRACFCOMP(g_trac_tce, "TceMgr::_createTceTable: Device map error.");

                        /*@
                         * @errortype
                         * @moduleid     RUNTIME::MOD_TCE_INIT_HDW
                         * @reasoncode   RUNTIME::RC_TCE_DEV_MAP_FAIL
                         * @userdata1    Address to be mapped PsiBridgeAddr
                         * @userdata2    Tce Phys Addr
                         * @devdesc      PSI Bridge device Map failed
                         */
                        errl = new ERRORLOG::ErrlEntry(
                                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         RUNTIME::MOD_TCE_INIT_HDW,
                                         RUNTIME::RC_TCE_DEV_MAP_FAIL,
                                         PsiBridgeAddr,
                                         tceTablePhysAddr);
                        break;
                    }


                    // NOTE>> WILL MAKE DEBUG WHEN DONE TESTING
                    TRACFCOMP(g_trac_tce,"TceMgr::InitTceInHdw:phys addr = %llx",tceTablePhysAddr);

                    // Put the physical TCE addr in PsiBridgeAddr + 18 this is
                    // byte offset but since we are uin64_t increment 3 double
                    // words.
                    *(mmio_ptr + 0x3) = tceTablePhysAddr;

                    eieio();

                    // NOTE>> WILL MAKE DEBUG WHEN DONE TESTING
                    TRACFCOMP(g_trac_tce,"TceMgr::InitTceInHdw:physaddr in Hardware = %llx",*(mmio_ptr + 0x3));

                    // Turn on TCE enable (MMIO offset 0x90)
                    // the mmio_ptr is uint64_t
                    *(mmio_ptr + 0x12) = 0x1;

                    // NOTE>> WILL MAKE DEBUG WHEN DONE TESTING
                    TRACFCOMP(g_trac_tce,"TceMgr::InitTceInHdw:Set MMIO offset 0x90 = %llx",*(mmio_ptr + 0x12));

                    // unmap the device..
                    uint64_t rc =
                      mm_block_unmap(reinterpret_cast<void*>(mmio_ptr));

                    if (rc != 0)
                    {
                        // Got a bad rc from device unmap
                        TRACFCOMP(g_trac_tce,
                                  "TceMgr::initTce: device unmap error.");

                        /*@
                         * @errortype
                         * @moduleid     RUNTIME::MOD_TCE_INIT_HDW
                         * @reasoncode   RUNTIME::RC_TCE_DEV_UNMAP_FAIL
                         * @userdata1    Virtual Addr
                         * @userdata2    return Code from devUnMap
                         * @devdesc      Device UnMap Failure
                         */
                        errl = new ERRORLOG::ErrlEntry(
                                       ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       RUNTIME::MOD_TCE_INIT_HDW,
                                       RUNTIME::RC_TCE_DEV_UNMAP_FAIL,
                                       reinterpret_cast<uint64_t>(mmio_ptr),
                                       rc);
                        break;
                    }

                    mmio_ptr = NULL;
                }
            }

        }while(0);

        // If succsesfull set init to 1
        if (errl == NULL)
        {
            tceEntryInit = 1;

            // Successfully initialized the TCE table and hardware.
            TRACFCOMP(g_trac_tce, "TceMgr::_initTceInHdw: TCE initialized and setup");
        }

        return errl;
    }


    /************************************************************************/
    //
    //  NAME: allocateTces
    //     Responsible for allocating TCE Entries
    //
    /************************************************************************/
    errlHndl_t TceMgr::allocateTces(uint64_t i_startingAddress,
                                       uint64_t i_size,
                                       uint64_t& o_startingToken)
    {
        errlHndl_t errl = NULL;

        TRACFCOMP(g_trac_tce,
                   "TceMgr::AllocateTce: start for addr = %llx and size = %llx",
                    i_startingAddress, i_size);

        // Default the starting Token to invalid Token.
        o_startingToken = INVALID_TOKEN_ENTRY;

        do
        {

            // Check to see if init was run.. If not then error...
            if (!tceEntryInit)
            {
                // TceInit did not run before allocate was called
                TRACFCOMP(g_trac_tce,"TceMgr::AllocateTce: ERROR-initTceInHdw has not run");

                // error out because allocate was called before INIT.. Could
                // possibly just call init here.. but need to verify exactly
                // WHEN the init can get called..

                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_TCE_ALLOCATE
                 * @reasoncode   RUNTIME::RC_TCE_INIT_NOT_RUN
                 * @userdata1    Address to start TCE
                 * @userdata2    Size of the address space tring to get TCEs
                 *               for.
                 * @devdesc      TCE Table has not been initialized yet
                 */
                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               RUNTIME::MOD_TCE_ALLOCATE,
                                               RUNTIME::RC_TCE_INIT_NOT_RUN,
                                               i_startingAddress,
                                               i_size);

                break;
            }

            // Check to see if createTceTable ran before allocate.  If not we
            // need to make sure the hardware is mapped.. If we are in
            // multi-node we would run Create on only 1 node and other node
            // could use that table to we don't need to create the table twice.
            if (tceTableVaPtr == NULL)
            {
                // createTceTable has not run
                TRACFCOMP(g_trac_tce,"TceMgr::AllocateTce: ERROR - createTceTable has not run so doing the mapping here.");

                errl = mapTceTable();

                if (errl != NULL)
                {
                    break;
                }
            }

            //if not page aligned.. expecting a page aligned address passed in
            if (i_startingAddress - ALIGN_PAGE_DOWN(i_startingAddress) != 0)
            {
                TRACFCOMP(g_trac_tce,"TceMgr::AllocateTce: ERROR-Address not page aligned");

                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_TCE_ALLOCATE
                 * @reasoncode   RUNTIME::RC_TCE_ADDR_NOT_ALIGNED
                 * @userdata1    Address to start TCE
                 * @userdata2    Size of the address space tring to get TCEs
                 *               for.
                 * @devdesc      The Physical Address for the TCE entry is not
                 *               page aligned.
                 */
                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               RUNTIME::MOD_TCE_ALLOCATE,
                                               RUNTIME::RC_TCE_ADDR_NOT_ALIGNED,
                                               i_startingAddress,
                                               i_size);

                break;
            }

            // Calculate the number of TCE entries needed
            uint32_t numTcesNeeded = ALIGN_PAGE_DOWN(i_size)/PAGESIZE;

            // If more than the number of TCE entry avail.. error out.
            if (numTcesNeeded > maxTceEntries)
            {
                TRACFCOMP(g_trac_tce,"TceMgr::AllocateTce: ERROR - Too many entries requested");

                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_TCE_ALLOCATE
                 * @reasoncode   RUNTIME::RC_TCE_INVALID_SIZE
                 * @userdata1    Address to start TCE
                 * @userdata2    Size of the address space tring to get TCEs
                 *               for.
                 * @devdesc      The size requested is too large for the table
                 */
                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               RUNTIME::MOD_TCE_ALLOCATE,
                                               RUNTIME::RC_TCE_INVALID_SIZE,
                                               i_startingAddress,
                                               i_size);
                break;
            }

            // Find a first consequetive group of TCE entries requested
            int startingIndex = 0;
            bool found = false;

            // Start at the beginning and search for the first empty entry
            for (uint32_t tceIndex = 0;
                 tceIndex < maxTceEntries;
                 tceIndex++)
            {
                if (!tceTableVaPtr[tceIndex].valid)
                {
                    uint32_t availIndex = 0;

                    // if not enough space avail.
                    if (numTcesNeeded+tceIndex > maxTceEntries)
                    {
                        break;
                    }
                    for (uint32_t IndexInRow = tceIndex;
                         IndexInRow < numTcesNeeded + tceIndex;
                         IndexInRow++)
                    {
                        // If the entry is Not valid.. then the entry is
                        // available
                        if (!tceTableVaPtr[IndexInRow].valid)
                        {
                            // Increment availIndex
                            availIndex++;
                        }
                        // found a valid entry so need to start the count over.
                        else
                        {
                            // increment past the tce entries we already checked
                            tceIndex = IndexInRow+1;

                            // reset the avail index
                            availIndex = 0;

                            break;
                        }

                        // If we found enough consecutive TCE entires
                        if (availIndex >= numTcesNeeded)
                        {
                            // set the starting index
                            startingIndex = tceIndex;
                            // mark it found
                            found = true;
                            break;
                        }
                    }
                    // break out and update the table
                    if (found)
                    {
                        break;
                    }

                    // did not find consecutive TCE entries so continue.
                }
            }


            if (found)
            {
                // Do a for loop here to loop through the number of TCE entries
                // and set the valid bits.. read address changes.. have to add
                // PAGESIZE to each address
                for (uint32_t i = startingIndex;
                              i<numTcesNeeded+startingIndex;
                              i++)
                {
                    tceTableVaPtr[i].realPageNumber = i_startingAddress +
                                                     (i*PAGESIZE);
                    tceTableVaPtr[i].valid = 1;
                    tceTableVaPtr[i].writeAccess = 1;
                    tceTableVaPtr[i].readAccess = 1;
                }

                // We are returning offset into the TCE table for the start of
                // the first TCE entry.
                o_startingToken = startingIndex * PAGESIZE;

                TRACFCOMP(g_trac_tce,"TceMgr::AllocateTce: Token = %llx for addr = %llx and size = %llx",o_startingToken, i_startingAddress, i_size);
            }
            else  // not found means not enough space for request
            {
                TRACFCOMP(g_trac_tce,"TceMgr::AllocateTce: ERROR -Not enough free entries for this request");

                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_TCE_ALLOCATE
                 * @reasoncode   RUNTIME::RC_TCE_NOT_ENOUGH_FREE_ENTRIES
                 * @userdata1    Address to start TCE
                 * @userdata2    Size of the address space trying to get TCEs
                 *               for.
                 * @devdesc      The size requested is too large.
                 */
                errl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        RUNTIME::MOD_TCE_ALLOCATE,
                                        RUNTIME::RC_TCE_NOT_ENOUGH_FREE_ENTRIES,
                                        i_startingAddress,
                                        i_size);

            }
        }while(0);

        TRACFCOMP(g_trac_tce, "TceMgr::AllocateTce: EXIT");

        return errl;
    }


    /*************************************************************************/
    //
    // NAME: deallocateTces
    //     Responsible for deallocating TCE Entries
    //
    /*************************************************************************/
    errlHndl_t TceMgr::deallocateTces(uint64_t i_startingToken,
                                          uint64_t i_size)
    {

        errlHndl_t errl = NULL;
        bool isContiguous = true;

        TRACFCOMP(g_trac_tce,"TceMgr::DeAllocateTce: START: for Token = %llx for size = %llx",i_startingToken, i_size);

        do
        {
            // Get number of TCEs needed.
            uint32_t numTcesNeeded = ALIGN_PAGE_DOWN(i_size)/PAGESIZE;
            uint32_t startingIndex = i_startingToken/PAGESIZE;

            // if the Token passed in equals the default token, or the
            // startingIndex is larger than the max number of indexes avail
            if ((i_startingToken == INVALID_TOKEN_ENTRY) ||
                (startingIndex > maxTceEntries))
            {
                // User passed in an invalid token, do not do a deallocate and
                // return
                TRACFCOMP(g_trac_tce,"TceMgr::DeallocateTce: ERROR -invalid Token = %lx, No deallocate.", i_startingToken);

                break;
            }

            if (startingIndex+numTcesNeeded > maxTceEntries)
            {
                TRACFCOMP(g_trac_tce,"TceMgr::DeallocateTce: ERROR - request goes past the end of the tce table");

                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_TCE_DEALLOCATE
                 * @reasoncode   RUNTIME::RC_TCE_INVALID_SIZE
                 * @userdata1    starting index
                 * @userdata2    number of TCEs needed for this request
                 * @devdesc      The size requested is too large for the table
                 *               space avail starting at the Token passed in.
                 */
                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               RUNTIME::MOD_TCE_DEALLOCATE,
                                               RUNTIME::RC_TCE_INVALID_SIZE,
                                               startingIndex,
                                               numTcesNeeded);

                errlCommit(errl,RUNTIME_COMP_ID);

                numTcesNeeded = numTcesNeeded -
                  ((startingIndex+numTcesNeeded)-maxTceEntries);

                TRACFCOMP(g_trac_tce,"TceMgr::DeallocateTce: ERROR - clearing from index = %d to end of table", startingIndex);

            }

            // Currently do not check for valid entries.. Just clear as
            // requested.
            uint64_t realAddress = 0;

            for (uint32_t tceIndex = startingIndex;
                 tceIndex < (startingIndex + numTcesNeeded);
                 tceIndex++)
            {
                if (tceIndex != startingIndex)
                {
                    // check that the address space is contiguous
                    if (((tceTableVaPtr[tceIndex].realPageNumber  -
                          realAddress) != PAGESIZE) &&
                        ((tceTableVaPtr[tceIndex].realPageNumber  -
                          realAddress) != 0))
                    {
                        isContiguous = false;
                    }
                }

                realAddress = tceTableVaPtr[tceIndex].realPageNumber;

                // Clear out the TCE entry to 0
                tceTableVaPtr[tceIndex].WholeTceEntry = 0;
            }

            if (!isContiguous)
            {
                // We know the range to delete is not contingous.. the Token and
                // size passed in crosses past individual allocates.  We will
                // create error log to indicate that but will clear number of
                // entries requested by caller
                TRACFCOMP(g_trac_tce,"TceMgr::DeallocateTce: ERROR - request was not contiguous TCE entries");

                /*@
                 * @errortype
                 * @moduleid     RUNTIME::MOD_TCE_DEALLOCATE
                 * @reasoncode   RUNTIME::RC_TCE_ENTRY_NOT_CONTIGUOUS
                 * @userdata1    i_startingToken
                 * @userdata2    Size of the address space trying to deallocate
                 * @devdesc      The deallocate went across TCE Allocate space.
                 */
                errl = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          RUNTIME::MOD_TCE_DEALLOCATE,
                                          RUNTIME::RC_TCE_ENTRY_NOT_CONTIGUOUS,
                                          i_startingToken,
                                          i_size);

                errlCommit(errl,RUNTIME_COMP_ID);

            }

        }while(0);

        TRACFCOMP(g_trac_tce,"TceMgr::DeAllocateTce: COMPLETE for Token = %llx for size = %llx",i_startingToken, i_size);

        return errl;
    }

    /**************************************************************************/
    //
    // NAME: ~TceMgr
    //      Destructor
    //
    /**************************************************************************/
    TceMgr::~TceMgr()
    {
        // If the If phys addr and VA table address match and If the physical
        // addr is not less than VMM memory size we need unmap
        // If it was less than VMM Memory it was already mapped outside of the
        // TCE scope and doesn't need to be unmapped here.
        if ((tceTablePhysAddr != reinterpret_cast<uint64_t>(tceTableVaPtr)) &&
           (!(tceTablePhysAddr < VMM_MEMORY_SIZE)))
        {
            if (tceTableVaPtr!= NULL)
            {
                // Unmap the tceTableVaPtr
                uint64_t rc =
                  mm_block_unmap(reinterpret_cast<void*>(tceTableVaPtr));

                if (rc != 0)
                {
                    TRACFCOMP(g_trac_tce,"TceMgr::~TceMgr: ERROR - Unmap failed rc = %d", rc);
                }
            }
        }
        else
        {

            TRACFCOMP(g_trac_tce,"TceMgr::~TceMgr: No Unmap required. testing..");
        }
    }

#endif
