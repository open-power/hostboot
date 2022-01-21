/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/eeprom/runtime/rt_eepromCache.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
 * @file rt_eepromCache.C
 *
 * @brief Runtime functionality of the eeprom cache driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------

#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <eeprom/eepromddreasoncodes.H>
#include <eeprom/eepromif.H>
#include <runtime/interface.h>
#include <targeting/runtime/rt_targeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/attrrp.H>
#include <trace/interface.H>
#include <util/runtime/util_rt.H>
#include <sys/internode.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

#include "../eepromCache.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_eeprom;

//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace EEPROM
{

// Any time we access either any of the global variables defined above we want
// to wrap the call in this mutex to avoid multi-threading issues
mutex_t g_eecacheMutex = MUTEX_INITIALIZER;

uint64_t g_eecachePnorVaddr[MAX_NODES_PER_SYS] = {0,0,0,0,0,0,0,0};
std::map<eepromRecordHeader, EepromEntryMetaData_t> g_cachedEeproms[MAX_NODES_PER_SYS];

// ------------------------------------------------------------------
// rtEecacheInit
// ------------------------------------------------------------------
struct rtEecacheInit
{
    rtEecacheInit()
    {
        TRACFCOMP(g_trac_eeprom, ENTER_MRK" rtEecacheInit()");
        errlHndl_t l_errl = nullptr;

        // Add cache status for the node
        TARGETING::TargetHandleList l_nodeList;
        getEncResources(l_nodeList,
                        TARGETING::TYPE_NODE,
                        TARGETING::UTIL_FILTER_ALL);
        // Find all the targets with VPD switches
        for (auto & l_node : l_nodeList)
        {
            uint64_t l_eecacheSize = 0;
            uint8_t l_instance = TARGETING::AttrRP::getNodeId(l_node);

#ifdef CONFIG_FSP_BUILD
            // On FSP platforms we use a preloaded reserved memory section
            eecacheSectionHeader* l_sectionHeader =
              reinterpret_cast<eecacheSectionHeader*>(
                  hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_VPD,
                                      l_instance, l_eecacheSize));
#else
            // On eBMC platforms we will pull the data from PNOR directly
            PNOR::SectionInfo_t l_sectionInfo;
            l_errl = PNOR::getSectionInfo(PNOR::EECACHE, l_sectionInfo);
            if(l_errl)
            {
                TRACFCOMP(g_trac_eeprom, "rtEecacheInit() Failed while looking up the EECACHE section in PNOR!!");
                l_errl->collectTrace(EEPROM_COMP_NAME);
                errlCommit (l_errl, EEPROM_COMP_ID);
                break;
            }

            eecacheSectionHeader* l_sectionHeader =
              reinterpret_cast<eecacheSectionHeader*>(l_sectionInfo.vaddr);
            l_eecacheSize = l_sectionInfo.size;
#endif


            g_eecachePnorVaddr[l_instance] = reinterpret_cast<uint64_t>(l_sectionHeader);

            // Check if reserved memory does not exist for this instance
            if ((NULL == l_sectionHeader) || (0 == l_eecacheSize))
            {
                TRACFCOMP(g_trac_eeprom,
                          "rtEecacheInit(): ERROR Could not find EECACHE section of reserved memory for Node %d, ",
                          l_instance);
                /*@
                 *   @errortype         ERRL_SEV_UNRECOVERABLE
                 *   @moduleid          EEPROM_CACHE_INIT_RT
                 *   @reasoncode        EEPROM_CACHE_NO_VPD_IN_RSV_MEM
                 *   @userdata1         Node Id
                 *   @userdata2         Unused
                 *
                 *   @devdesc   Attempted to lookup VPD in reserved memory
                 *              and failed
                 *   @custdesc  A problem occurred during the IPL of the
                 *              system.
                 */
                l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       EEPROM::EEPROM_CACHE_INIT_RT,
                                       EEPROM::EEPROM_CACHE_NO_VPD_IN_RSV_MEM,
                                       l_instance,
                                       0,
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_errl->collectTrace(EEPROM_COMP_NAME);
                errlCommit (l_errl, EEPROM_COMP_ID);
                break;

            }

            eepromRecordHeader * l_recordHeaderToCopy = nullptr;
            uint8_t l_eepromCount = 0;
            for(int8_t i = 0; i < MAX_EEPROMS_LATEST; i++)
            {
                // Keep track of current record so we can use outside for loop
                l_recordHeaderToCopy = &l_sectionHeader->recordHeaders[i];

                // If internal_offset is UNSET_INTERNAL_OFFSET_VALUE then we will assume this address not been filled
                if(l_recordHeaderToCopy->completeRecord.internal_offset != UNSET_INTERNAL_OFFSET_VALUE)
                {
                    l_eepromCount++;
                    // Will return true if already found an entry in the list
                    if(addEepromToCachedList(*l_recordHeaderToCopy,
                              reinterpret_cast<uint64_t>(l_recordHeaderToCopy),
                                             l_instance))
                    {

                        TRACFCOMP(g_trac_eeprom,
                          "rtEecacheInit(): ERROR Duplicate cache entries found in VPD reserved memory section");

                        /*@
                        * @errortype        ERRL_SEV_UNRECOVERABLE
                        * @moduleid         EEPROM_CACHE_INIT_RT
                        * @reasoncode       EEPROM_DUPLICATE_CACHE_ENTRY
                        * @userdata1[0:31]  master Huid
                        * @userdata1[32:39] port (or 0xFF)
                        * @userdata1[40:47] engine
                        * @userdata1[48:55] devAddr of eeprom slave   (or byte 0 offset_KB)
                        * @userdata1[56:63] muxSelect of eeprom slave (or byte 1 offset_KB)
                        * @userdata2[0:31]  size of eeprom
                        * @userdata2[32:63] Node Id
                        * @devdesc          Attempted to lookup VPD in reserved memory
                        *                   and failed
                        * @custdesc         A problem occurred during the IPL of the
                        *                   system.
                        */
                        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              EEPROM::EEPROM_CACHE_INIT_RT,
                                              EEPROM::EEPROM_DUPLICATE_CACHE_ENTRY,
                                              EEPROM::getEepromHeaderUserData(*l_recordHeaderToCopy),
                                              TWO_UINT32_TO_UINT64(l_recordHeaderToCopy->completeRecord.cache_copy_size,
                                                                   TO_UINT32(l_instance)),
                                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                        errlCommit (l_errl, EEPROM_COMP_ID);
                        // Something is wrong so we have committed the unrecoverable
                        // but keep processing the eeproms because we want a full picture
                        // of what we understand the eeprom cache contents to be
                        continue;
                    }
                }
            }

            TRACFCOMP(g_trac_eeprom, "Found %d cached eeproms in reserved memory for node %d",
                      l_eepromCount, l_instance);

            printCurrentCachedEepromMap();

        }
        TRACFCOMP(g_trac_eeprom, EXIT_MRK" rtEecacheInit()");
    }

};
rtEecacheInit g_rtEecacheInit;

void printCurrentCachedEepromMap(void)
{
    TRACFCOMP( g_trac_eeprom,
               "printCurrentCachedEepromMap():");

    mutex_lock(&g_eecacheMutex);
    for(int8_t i = 0; i < MAX_NODES_PER_SYS; i++)
    {
        for(std::map<eepromRecordHeader, EepromEntryMetaData_t>::iterator iter = g_cachedEeproms[i].begin();
            iter != g_cachedEeproms[i].end();
            ++iter)
        {
            if ( iter->first.completeRecord.accessType ==
                   EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
            {
                TRACSSCOMP( g_trac_eeprom,
                            "printTableOfContents(): I2CM Huid: 0x%.08X, Port: 0x%.02X,"
                            " Engine: 0x%.02X, Dev Addr: 0x%.02X,"
                            " Mux Select: 0x%.02X, Size: 0x%.08X",
                            iter->first.completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                            iter->first.completeRecord.eepromAccess.i2cAccess.port,
                            iter->first.completeRecord.eepromAccess.i2cAccess.engine,
                            iter->first.completeRecord.eepromAccess.i2cAccess.devAddr,
                            iter->first.completeRecord.eepromAccess.i2cAccess.mux_select,
                            iter->first.completeRecord.cache_copy_size);
            }
            else
            {
                TRACSSCOMP( g_trac_eeprom,
                            "printTableOfContents(): SPI Huid: 0x%.08X, Engine: 0x%.02X,"
                            " offset: 0x%.04X KB, Size: 0x%.08X",
                            iter->first.completeRecord.eepromAccess.spiAccess.spi_master_huid,
                            iter->first.completeRecord.eepromAccess.spiAccess.engine,
                            iter->first.completeRecord.eepromAccess.spiAccess.offset_KB,
                            iter->first.completeRecord.cache_copy_size);
            }

            TRACSSCOMP( g_trac_eeprom,
                        "                          "
                        "Internal Offset: 0x%.08X, Cache Valid: 0x%.02X, Master EEPROM: 0x%.02X",
                        iter->first.completeRecord.internal_offset,
                        iter->first.completeRecord.cached_copy_valid,
                        iter->first.completeRecord.master_eeprom);
        }
    }
    mutex_unlock(&g_eecacheMutex);

}

uint64_t lookupEepromCacheAddr(const eepromRecordHeader& i_eepromRecordHeader,
                               const uint8_t i_instance)
{
    uint64_t l_vaddr = 0;
    std::map<eepromRecordHeader, EepromEntryMetaData_t>::iterator l_it;

    if (MAX_NODES_PER_SYS < i_instance)
    {
        TRACFCOMP( g_trac_eeprom, "lookupEepromCacheAddr() called with instance"
                   " %d, which is greater than max cached eeproms %d",
                   i_instance, MAX_NODES_PER_SYS );
        return 0;
    }

    // Wrap lookup in mutex because reads are not thread safe
    mutex_lock(&g_eecacheMutex);
    l_it = g_cachedEeproms[i_instance].find(i_eepromRecordHeader);

    if(l_it != g_cachedEeproms[i_instance].end())
    {
        l_vaddr = l_it->second.cache_entry_address;
    }
    mutex_unlock(&g_eecacheMutex);

    return l_vaddr;
}

uint64_t lookupEepromHeaderAddr(const eepromRecordHeader& i_eepromRecordHeader,
                                const uint8_t i_instance)
{
    uint64_t l_vaddr = 0;
    std::map<eepromRecordHeader, EepromEntryMetaData_t>::iterator l_it;

    if (MAX_NODES_PER_SYS < i_instance)
    {
        TRACFCOMP( g_trac_eeprom, "lookupEepromHeaderAddr() called with instance"
                   " %d, which is greater than max cached eeproms %d",
                   i_instance, MAX_NODES_PER_SYS );
        return 0;
    }

    // Wrap lookup in mutex because reads are not thread safe
    mutex_lock(&g_eecacheMutex);
    l_it = g_cachedEeproms[i_instance].find(i_eepromRecordHeader);

    if(l_it != g_cachedEeproms[i_instance].end())
    {
        l_vaddr = l_it->second.header_entry_address;
    }
    mutex_unlock(&g_eecacheMutex);

    return l_vaddr;
}

bool addEepromToCachedList(const eepromRecordHeader & i_eepromRecordHeader,
                           const uint64_t i_recordHeaderVaddr,
                           const uint8_t i_instance)
{
    bool l_matchFound = true;

    // Map accesses are not thread safe, make sure this is always wrapped in mutex
    mutex_lock(&g_eecacheMutex);

    if(g_cachedEeproms[i_instance].find(i_eepromRecordHeader) ==
       g_cachedEeproms[i_instance].end())
    {
        g_cachedEeproms[i_instance][i_eepromRecordHeader].cache_entry_address =
              g_eecachePnorVaddr[i_instance] + i_eepromRecordHeader.completeRecord.internal_offset;

        g_cachedEeproms[i_instance][i_eepromRecordHeader].header_entry_address =
              i_recordHeaderVaddr;

        if (i_eepromRecordHeader.completeRecord.accessType ==
            EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C)
        {
            TRACSSCOMP( g_trac_eeprom,
                "addEepromToCachedList() Adding access: 0x%02X,"
                " I2CM Huid: 0x%.08X, Port: 0x%.02X,"
                " Engine: 0x%.02X, Dev Addr: 0x%.02X, Mux Select: 0x%.02X,"
                " Size: 0x%.08X to g_cachedEeproms",
                i_eepromRecordHeader.completeRecord.accessType,
                i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.port,
                i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.engine,
                i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.devAddr,
                i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.mux_select,
                i_eepromRecordHeader.completeRecord.cache_copy_size);
        }
        else
        {
            TRACSSCOMP( g_trac_eeprom,
                "addEepromToCachedList() Adding access: 0x%02X,"
                " SPI master Huid: 0x%.08X, Engine: 0x%.02X, "
                " offset_KB: 0x%.04X, Size: 0x%.08X to g_cachedEeproms",
                i_eepromRecordHeader.completeRecord.accessType,
                i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.spi_master_huid,
                i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.engine,
                i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.offset_KB,
                i_eepromRecordHeader.completeRecord.cache_copy_size);
        }
        l_matchFound = false;
    }

    mutex_unlock(&g_eecacheMutex);

    return l_matchFound;
}

} // end namespace EEPROM
