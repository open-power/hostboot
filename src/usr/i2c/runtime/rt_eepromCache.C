/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/runtime/rt_eepromCache.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
#include <i2c/eepromddreasoncodes.H>
#include <runtime/interface.h>
#include <runtime/rt_targeting.H>
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
std::map<eepromRecordHeader, EeepromEntryMetaData_t> g_cachedEeproms[MAX_NODES_PER_SYS];

// ------------------------------------------------------------------
// rtEecacheInit
// ------------------------------------------------------------------
struct rtEecacheInit
{
    rtEecacheInit()
    {
        errlHndl_t l_errl = nullptr;

        // Add cache status for the node
        TARGETING::TargetHandleList l_nodeList;
        getEncResources(l_nodeList,
                        TARGETING::TYPE_NODE,
                        TARGETING::UTIL_FILTER_ALL);
        // Find all the targets with VPD switches
        for (auto & l_node : l_nodeList)
        {
            uint8_t l_instance = TARGETING::AttrRP::getNodeId(l_node);
            uint64_t vpd_size = 0;
            eecacheSectionHeader* l_sectionHeader =
              reinterpret_cast<eecacheSectionHeader*>(
                  hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_VPD,
                                      l_instance, vpd_size));

            g_eecachePnorVaddr[l_instance] = reinterpret_cast<uint64_t>(l_sectionHeader);

            // Check if reserved memory does not exist for this instance
            if ((NULL == l_sectionHeader) || (0 == vpd_size))
            {
                TRACFCOMP(g_trac_eeprom,
                          "rtEecacheInit(): ERROR Could not find VPD section of reserved memory for Node %d, ",
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

                errlCommit (l_errl, EEPROM_COMP_ID);
                break;

            }

            eepromRecordHeader * l_recordHeaderToCopy = nullptr;
            uint8_t l_eepromCount = 0;
            for(int8_t i = 0; i < MAX_EEPROMS_VERSION_1; i++)
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
                        * @userdata1[0:31]   i2c_master_huid
                        * @userdata1[32:39] port on i2c master eeprom slave is on
                        * @userdata1[40:47] engine on i2c master eeprom slave is on
                        * @userdata1[48:55] devAddr of eeprom slave
                        * @userdata1[56:63] muxSelect of eeprom slave (0xFF is not valid)
                        * @userdata2[0:31]   size of eeprom
                        * @userdata2[32:63]  Node Id
                        * @devdesc          Attempted to lookup VPD in reserved memory
                        *                   and failed
                        * @custdesc         A problem occurred during the IPL of the
                        *                   system.
                        */
                        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              EEPROM::EEPROM_CACHE_INIT_RT,
                                              EEPROM::EEPROM_DUPLICATE_CACHE_ENTRY,
                                              TWO_UINT32_TO_UINT64(
                                                  l_recordHeaderToCopy->completeRecord.i2c_master_huid,
                                                  TWO_UINT16_TO_UINT32(
                                                      TWO_UINT8_TO_UINT16(
                                                          l_recordHeaderToCopy->completeRecord.port,
                                                          l_recordHeaderToCopy->completeRecord.engine),
                                                      TWO_UINT8_TO_UINT16(
                                                          l_recordHeaderToCopy->completeRecord.devAddr,
                                                          l_recordHeaderToCopy->completeRecord.mux_select))),
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
        for(std::map<eepromRecordHeader, EeepromEntryMetaData_t>::iterator iter = g_cachedEeproms[i].begin();
            iter != g_cachedEeproms[i].end();
            ++iter)
        {
            TRACSSCOMP( g_trac_eeprom,
                        "printTableOfContents(): I2CM Huid: 0x%.08X, Port: 0x%.02X,"
                        " Engine: 0x%.02X, Dev Addr: 0x%.02X,"
                        " Mux Select: 0x%.02X, Size: 0x%.08X",
                        iter->first.completeRecord.i2c_master_huid,
                        iter->first.completeRecord.port,
                        iter->first.completeRecord.engine,
                        iter->first.completeRecord.devAddr,
                        iter->first.completeRecord.mux_select,
                        iter->first.completeRecord.cache_copy_size);

            TRACSSCOMP( g_trac_eeprom,
                        "                          "
                        "Internal Offset: 0x%.08X, Cache Valid: 0x%.02X",
                        iter->first.completeRecord.internal_offset,
                        iter->first.completeRecord.cached_copy_valid);
        }
    }
    mutex_unlock(&g_eecacheMutex);

}

uint64_t lookupEepromCacheAddr(const eepromRecordHeader& i_eepromRecordHeader,
                               const uint8_t i_instance)
{
    uint64_t l_vaddr = 0;
    std::map<eepromRecordHeader, EeepromEntryMetaData_t>::iterator l_it;

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

        TRACSSCOMP( g_trac_eeprom,
                    "addEepromToCachedList() Adding I2CM Huid: 0x%.08X, Port: 0x%.02X,"
                    " Engine: 0x%.02X, Dev Addr: 0x%.02X, Mux Select: 0x%.02X,"
                    " Size: 0x%.08X to g_cachedEeproms",
                    i_eepromRecordHeader.completeRecord.i2c_master_huid,
                    i_eepromRecordHeader.completeRecord.port,
                    i_eepromRecordHeader.completeRecord.engine,
                    i_eepromRecordHeader.completeRecord.devAddr,
                    i_eepromRecordHeader.completeRecord.mux_select,
                    i_eepromRecordHeader.completeRecord.cache_copy_size);

        l_matchFound = false;
    }

    mutex_unlock(&g_eecacheMutex);

    return l_matchFound;
}

} // end namespace EEPROM
