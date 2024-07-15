/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/debugpointers.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2024                        */
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
#ifndef _DEBUGPOINTERS_H
#define _DEBUGPOINTERS_H

#include <stdint.h>
#include <cstring>
#include <builtins.h>

/**
 * This file contains details on a list of pointers that can be used
 *  by our debug framework without requiring an exact build match.
 */

// Static space allocated in start.S
// This points to a dynamically allocated instance of a DebugPointers_t
extern void* debug_pointers;

namespace DEBUG
{
// Maximum number of entries
constexpr uint16_t MAX_ENTRIES = 50;

// Eyecatcher to detect levels without this support
//  = DEBUGPTR
constexpr uint64_t EYECATCHER = 0x4445425547505452;

// Only 1 version so far but allow for others
constexpr uint16_t VERSION_LATEST = 0x0001;

// A pair of pointers
struct PointerPair_t
{
    union {
        char label[8];
        uint64_t label_num; //Makes assignments and checking simpler
    };
    uint32_t size; // bytes
    uint32_t pointer; // we never use all 64-bits of a native pointer
} PACKED;

// Table of Debug Pointers
struct DebugPointers_t
{
    uint64_t eyecatcher;
    uint16_t version;
    uint16_t numEntries;
    uint32_t reserved;
    PointerPair_t pairs[MAX_ENTRIES];

    DebugPointers_t()
      : eyecatcher(EYECATCHER),
        version(VERSION_LATEST),
        numEntries(MAX_ENTRIES),
        reserved(0)
    {
        memset( pairs, 0, sizeof(pairs) );
    }
} PACKED;

/*
 * List of known debug pointers
 *   Note: Must keep debug tools in sync if these values change
 */
constexpr uint64_t PRINTK                    = 0x5052494e544b2020; //'PRINTK  '
constexpr uint64_t TRACESERVICE              = 0x5452414345535643; //'TRACESVC'
constexpr uint64_t TRACEDAEMON               = 0x5452414345444D4E; //'TRACEDMN'
constexpr uint64_t TASKMANAGER               = 0x5441534b4c495354; //'TASKLIST'
constexpr uint64_t ERRORLOGS                 = 0x4552524f524c4f47; //'ERRORLOG'
constexpr uint64_t HEAPMANAGERHUGEPAGEALLOC  = 0x484541504d485041; //'HEAPMHPA'
constexpr uint64_t HEAPMANAGERHUGEPAGECOUNT  = 0x484541504d485043; //'HEAPMHPC'
constexpr uint64_t HEAPMANAGERHUGEEPAGEMAX   = 0x484541504d48504d; //'HEAPMHPM'
constexpr uint64_t HEAPMANAGERLARGEPAGECOUNT = 0x484541504d4c5043; //'HEAPMLPC'
constexpr uint64_t HEAPMANAGERLARGEPAGEMAX   = 0x484541504d4c504d; //'HEAPMLPM'
constexpr uint64_t HEAPMANAGERSMALLPAGECOUNT = 0x484541504d535043; //'HEAPMSPC'
constexpr uint64_t HEAPMANAGERSMALLALLOCHW   = 0x484541504d534148; //'HEAPMSAH'
constexpr uint64_t HEAPMANAGERSMALLALLOC     = 0x484541504d53414C; //'HEAPMSAL'
constexpr uint64_t HEAPMANAGERSMALLUSERALLOC = 0x484541504d535541; //'HEAPMSUA'
constexpr uint64_t HEAPMANAGERSMALLCOALSTATE = 0x484541504d434e54; //'HEAPMCST'
constexpr uint64_t HEAPMANAGERSMALLCOALATMPT = 0x484541504d434e54; //'HEAPMCAT'
constexpr uint64_t HEAPMANAGERSMALLCOALCOUNT = 0x484541504d434e54; //'HEAPMCNT'
constexpr uint64_t HEAPMANAGERSMALLCOALPAGE  = 0x484541504d435047; //'HEAPMCPG'
constexpr uint64_t HEAPMANAGERSMALLFREEBUCKT = 0x484541504d464254; //'HEAPMFBT'
constexpr uint64_t HEAPMANAGERSMALLINUSEBUCKT= 0x484541504d494254; //'HEAPMIBT'
constexpr uint64_t HEAPMANAGERSMALLALLOCSIZES= 0x484541504d41535A; //'HEAPMASZ'
constexpr uint64_t HEAPMANAGERSMALLCHUNKSIZES= 0x484541504d43535A; //'HEAPMCSZ'
constexpr uint64_t PAGEMANAGERBUCKETS        = 0x504147454d424b54; //'PAGEMBKT'
constexpr uint64_t PAGEMANAGERPAGESTOTAL     = 0x504147454d584754; //'PAGEMPGT'
constexpr uint64_t PAGEMANAGERPAGESAVAIL     = 0x504147454d584741; //'PAGEMPGA'
constexpr uint64_t PAGEMANAGERRESPAGESAVAIL  = 0x504147454d525041; //'PAGEMRPA'
constexpr uint64_t PAGEMANAGERLOWPAGECOUNT   = 0x504147454d4c5043; //'PAGEMLPC'
constexpr uint64_t PAGEMANAGERCOALSTATE      = 0x504147454d435354; //'PAGEMCST'
constexpr uint64_t PAGEMANAGERCOALATTEMPTS   = 0x504147454d434154; //'PAGEMCAT'
constexpr uint64_t PAGEMANAGERCOALESCECOUNT  = 0x504147454d434e54; //'PAGEMCNT'
constexpr uint64_t PAGEMANAGERALLOCCOUNT     = 0x504147454d414343; //'PAGEMACC'
constexpr uint64_t PAGEMANAGERFREEBUCKETS    = 0x504147454d46424b; //'PAGEMFBK'
constexpr uint64_t PAGEMANAGERKERNRESAVAIL   = 0x504147454d4B5241; //'PAGEMKRA'
constexpr uint64_t KMEMTRACE                 = 0x4b4d454d54524320; //'KMEMTRC '
constexpr uint64_t KALLOCTRACE               = 0x4b414c4c54524320; //'KALLTRC '
constexpr uint64_t SEGMENTMANAGER            = 0x53474d4e544d4752; //'SGMNTMGR'
constexpr uint64_t BLOCKPAGESALLOC           = 0x424c4f434b414c4c; //'BLOCKALL'
constexpr uint64_t BLOCKPAGESALLOCPEAK       = 0x424c4f434b414c50; //'BLOCKALP'
constexpr uint64_t BLOCKPAGESALLOCCOUNT      = 0x424c4f434b414c43; //'BLOCKALC'
constexpr uint64_t BLOCKREADONLYEVICT        = 0x424c4f434b524f45; //'BLOCKROE'
constexpr uint64_t BLOCKREADWRITEEVICT       = 0x424c4f434b525745; //'BLOCKRWE'
constexpr uint64_t PLDMFRMAX                 = 0x504c444d46524d58; //'PLDMFRMX'
constexpr uint64_t PLDMOUTREQFR              = 0x504c444d4f524551; //'PLDMOREQ'
constexpr uint64_t PLDMINREQFR               = 0x504c444d49524551; //'PLDMIREQ'
constexpr uint64_t PLDMOUTRSPFR              = 0x504c444d4f525350; //'PLDMORSP'
constexpr uint64_t PLDMINRSPFR               = 0x504c444d49525350; //'PLDMIRSP'
constexpr uint64_t PLDMOUTREQNEXT            = 0x504c444d4f52514e; //'PLDMORQN'
constexpr uint64_t PLDMINREQNEXT             = 0x504c444d4952514e; //'PLDMIRQN'
constexpr uint64_t PLDMOUTRSPNEXT            = 0x504c444d4f52504e; //'PLDMORPN'
constexpr uint64_t PLDMINRSPNEXT             = 0x504c444d4952504e; //'PLDMIRPN'
// Number of values cannot exceed MAX_ENTRIES


/*
 * @brief Save off a pointer to the master list
 *
 * @param[in]  Pointer Label
 * @param[in]  Pointer Value
 */
void add_debug_pointer( uint64_t i_label,
                        void* i_ptr,
                        size_t i_size );

}; //namespace


#endif //_DEBUGPOINTERS_H
