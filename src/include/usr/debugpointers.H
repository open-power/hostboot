/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/debugpointers.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
constexpr uint16_t MAX_ENTRIES = 20;

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
constexpr uint64_t HEAPMANAGER               = 0x484541504d475220; //'HEAPMGR '
constexpr uint64_t HEAPMANAGERLARGEPAGECOUNT = 0x484541504d4c5043; //'HEAPMLPC'
constexpr uint64_t HEAPMANAGERLARGEPAGEMAX   = 0x484541504d4c504d; //'HEAPMLPM'
constexpr uint64_t HEAPMANAGERSMALLPAGECOUNT = 0x484541504d535043; //'HEAPMSPC'
constexpr uint64_t HEAPMANAGERCOALESCECOUNT  = 0x484541504d434e54; //'HEAPMCNT'
constexpr uint64_t HEAPMANAGERFREEBYTES      = 0x4845415042595445; //'HEAPBYTE'
constexpr uint64_t HEAPMANAGERFREECHUNKS     = 0x4845415043484e4b; //'HEAPCHNK'
constexpr uint64_t PAGEMANAGER               = 0x504147454d475220; //'PAGEMGR '
constexpr uint64_t PAGEMANAGERCOALESCECOUNT  = 0x504147454d434e54; //'PAGEMCNT'
constexpr uint64_t PAGEMANAGERLOWPAGECOUNT   = 0x504147454d4c5043; //'PAGEMLPC'
constexpr uint64_t PAGEMANAGERALLOCCOUNT     = 0x504147454d414343; //'PAGEMACC'
constexpr uint64_t SEGMENTMANAGER            = 0x53474d4e544d4752; //'SGMNTMGR'
constexpr uint64_t BLOCKREADONLYEVICT        = 0x424c4f434b524f45; //'BLOCKROE'
constexpr uint64_t BLOCKREADWRITEEVICT       = 0x424c4f434b525745; //'BLOCKRWE'
constexpr uint64_t HUGEBLOCKALLOCATED        = 0x48554745564D4D20; //'HUGEVMM '
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
