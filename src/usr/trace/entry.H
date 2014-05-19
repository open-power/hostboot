/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/entry.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __TRACE_ENTRY_H
#define __TRACE_ENTRY_H

/** @file entry.H
 *
 *  Definition of both the Hostboot-unique "entry" structure and the
 *  fsp-trace common entry structures.
 */

#include <trace/interface.H>

namespace TRACE
{
    /** @struct Entry
     *
     *  @brief Maintains the data for an entry in the Hostboot trace buffers.
     *
     *  In order to allow easy traversal of component trace buffers when they
     *  are in a common buffer, this entry maintains a linked-list of entries
     *  within the same buffer.
     *
     *  Important conventions:
     *     * (comp == NULL) - Entry is "expired" and no longer valid.
     *     * (committed == 0) - Entry is still in the process of being created
     *                          by a client.
     *
     *  If we wished to reduce the size of this structure in the future, to
     *  reduce the memory impact of tracing, we could turn the pointers here
     *  into a "short pointer" which is only 32bits since all Hostboot heap
     *  addresses are under 4GB.
     */
    struct Entry
    {
        ComponentDesc* comp;    //< Component Descriptor for this Entry.
        Entry* next;            //< Linked-list 'next' ptr.
        Entry* prev;            //< Linked-list 'prev' ptr.
        volatile uint16_t committed;     //< Committed status.
        uint16_t size;          //< Size of data portion.
        char data[0];           //< Start of 'fsp-trace' style structure.
    };

    //----- Below are structures directly from FSP for fsp-trace ------//

    const uint32_t TRACE_BUF_VERSION = 0x01;    // Trace buffer version
    const uint32_t TRACE_COMP_TRACE  = 0x434F;  // Component Field Trace - "CO"
    const uint32_t TRACE_FIELDTRACE  = 0x4654;  // Field Trace - "FT"
    const uint32_t TRACE_FIELDBIN    = 0x4644;  // Binary Field Trace - "FD"
    const uint32_t TRACE_TIME_REAL   = 0;       // upper 32 = secs,
                                                // lower 32 = microsecs
    const uint32_t TRACE_BUF_CONT    = 2;       // Trace buffer is continuous
                                                // trace style.

    /*!
     * @brief Timestamp and thread id for each trace entry.
     */
    struct trace_entry_stamp_t
    {
        uint32_t tbh;        /*!< timestamp upper part */
        uint32_t tbl;        /*!< timestamp lower part */
        uint32_t tid;        /*!< process/thread id */
    };

    /*
     * @brief Structure is used by adal app. layer to fill in trace info.
     */
    struct trace_entry_head_t
    {
        uint16_t length;    /*!< size of trace entry */
        uint16_t tag;       /*!< type of entry: xTRACE xDUMP, (un)packed */
        uint32_t hash;      /*!< a value for the (format) string */
        uint32_t line;      /*!< source file line number of trace call */
    };

    /*
     * @brief Binary first writes header and time stamp.
     */
    struct trace_bin_entry_t {
        trace_entry_stamp_t stamp;
        trace_entry_head_t head;
        char data[0];
    };

    /*
     * @brief Structure is put at beginning of all trace buffers
     */
    struct trace_buf_head_t {
        unsigned char ver;         /*!< version of this struct (1)          */
        unsigned char hdr_len;     /*!< size of this struct in bytes        */
        unsigned char time_flg;    /*!< meaning of timestamp entry field    */
        unsigned char endian_flg;  /*!< flag for big ('B') or little
                                        ('L') endian */
        char comp[TRAC_COMP_SIZE]; /*!< the buffer name as specified in
                                        init call*/
        uint32_t size;             /*!< size of buffer, including this struct*/
        uint32_t times_wrap;       /*!< how often the buffer wrapped        */
        uint32_t next_free;        /*!< offset of the byte behind the latest
                                        entry*/
        uint32_t te_count;         /*!< Updated each time a trace is done   */
        uint32_t extracted;        /*!< Not currently used                  */
    };



}
#endif
