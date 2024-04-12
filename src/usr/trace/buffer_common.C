/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/buffer_common.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2024                        */
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
 * @file buffer_common.C
 * @brief Methods for TRACE::Buffer (common between IPL and RUNTIME)
 */
#include <trace/buffer.H>
#include <trace/bufferpage.H>
#include <trace/entry.H>
#include <trace/compdesc.H>
#include <trace/daemonif.H>

#include <assert.h>
#include <limits.h>
#include <string.h>
#include <util/align.H>

#ifdef __HOSTBOOT_RUNTIME
#include <arch/ppc.H>
#else
#include <util/lockfree/abaptr.H>
#endif

namespace TRACE
{
    size_t Buffer::getTrace(ComponentDesc* i_comp, void* o_data, size_t i_size)
    {
        char* l_data = reinterpret_cast<char*>(o_data);
        size_t l_size = 0;
        size_t l_entries = 0;

        // If either the pointer is null or the buffer is 0, we're just trying
        // to determine the size of the buffer.
        bool determineSize = ((o_data == NULL) || (i_size == 0));

        if (determineSize)
        {
            i_size = UINT64_MAX;
        }

        trace_buf_head_t* header = NULL;

        // If we're actually extracting, add the fsp-trace buffer header.
        if(!determineSize)
        {
            if (i_size < sizeof(trace_buf_head_t))
                return 0;

            header = reinterpret_cast<trace_buf_head_t*>(&l_data[l_size]);
            memset(header, '\0', sizeof(trace_buf_head_t));

            header->ver = TRACE_BUF_VERSION;
            header->hdr_len = sizeof(trace_buf_head_t);
            header->time_flg = TRACE_TIME_REAL;
            header->endian_flg = 'B'; // Big Endian.
            memcpy(&header->comp[0], &i_comp->iv_compName, TRAC_COMP_SIZE);
        }
        l_size += sizeof(trace_buf_head_t);

#ifndef __HOSTBOOT_RUNTIME
        // Prevent daemon from changing things while we're extracting.
        _producerEnter();
#endif

        size_t l_totalSize = l_size;
        Entry* entry = i_comp->iv_first;
        size_t l_entriesToExtract = 0;

        do
        {
            if ((!entry) || (!entry->comp))
            {
                break;
            }

            // First walk the list backwards to find everything that will fit.
            while(1)
            {
                // fsp-trace buffer entries have an extra word of size at the
                // end.  That is where the sizeof(uint32_t) comes from...

                if ((l_totalSize + entry->size + sizeof(uint32_t)) <= i_size)
                {
                    l_totalSize += entry->size + sizeof(uint32_t);
                    l_entriesToExtract++;

                    if ((entry->next) &&
                        (entry->next->comp))
                    {
                        entry = entry->next;
                        continue;
                    }
                }
                else // This entry was too big to fit, so roll back one.
                {
                    entry = entry->prev;
                }
                break;
            }

            // If we didn't find anything that fit, leave.
            if (l_totalSize == l_size)
            {
                break;
            }

            // If we're just trying to find the size, we're done.
            if(determineSize)
            {
                l_size = l_totalSize;
                break;
            }

            // Now we can actually copy all the entries...
            while(entry != nullptr)
            {
                // Copy entry data.
                memcpy(&l_data[l_size], &entry->data[0],entry->size);
                l_size += entry->size;

                // Copy entry size.
                uint32_t entry_size = entry->size + sizeof(uint32_t);
                memcpy(&l_data[l_size], &entry_size, sizeof(uint32_t));
                l_size += sizeof(uint32_t);

                l_entries++;

                if (l_entries == l_entriesToExtract)
                {
                    break;
                }
                else
                {
                    entry = entry->prev;
                }
            };

        }
        while(0);

#ifndef __HOSTBOOT_RUNTIME
        // Unlock for daemon.
        _producerExit();
#endif

        // Update header.
        if (header)
        {
            header->size = l_size;
            header->next_free = l_size;
            header->te_count = l_entries;
        }

        return l_size;
    }

    ////////////////////////////////////////////////////////////////////////////
    size_t trace_bin_entry_t::getSize()
    {
        return (sizeof(trace_bin_entry_t) + head.length);
    }

    ////////////////////////////////////////////////////////////////////////////
    trace_bin_entry_t* trace_bin_entry_v2_t::getEntry()
    {
        char *l_ptr = iv_comp + strlen(iv_comp) + 1;
        return reinterpret_cast<trace_bin_entry_t*>(l_ptr);
    }

    ////////////////////////////////////////////////////////////////////////////
    void trace_buf_head_v2_t::init(size_t i_max)
    {
        memset(this,0,i_max);
        iv_max   = i_max;
        iv_ver   = TRACE_BUF_VERSION_2;
        iv_next  = iv_data;
    }

    ////////////////////////////////////////////////////////////////////////////
    size_t trace_buf_head_v2_t::getMaxDataSize()
    {
        // total size of this struct, minus the metadata, minus iv_ver
        //  This gives the total size available for trace entries
        return (iv_max -
           (sizeof(iv_max) + sizeof(iv_size) + sizeof(iv_next) + sizeof(iv_ver)));
    }

    ////////////////////////////////////////////////////////////////////////////
    size_t trace_buf_head_v2_t::getUDSize()
    {
        // if there is at least one trace in iv_data[], then add in sizeof(iv_ver)
        // else 0
        return iv_size ? (iv_size + sizeof(iv_ver)) : 0;
    }

    ////////////////////////////////////////////////////////////////////////////
    /**
     *  @brief   Calc the max size available for Entries in iv_data[], using i_max
     *  @return  size in bytes
     */
    size_t calcMaxDataSize(size_t i_max)
    {
        trace_buf_head_v2_t l_tbh;
        // i_max minus the metadata, minus iv_ver
        //  This gives the total size available for trace entries
        return (i_max -
               (sizeof(l_tbh.iv_max) +
                sizeof(l_tbh.iv_size) +
                sizeof(l_tbh.iv_next) +
                sizeof(l_tbh.iv_ver)));
    }

    ////////////////////////////////////////////////////////////////////////////
    char* trace_buf_head_v2_t::getEndPtr()
    {
        return (reinterpret_cast<char*>(this) + iv_max);
    }

    ////////////////////////////////////////////////////////////////////////////
    char* trace_buf_head_v2_t::getBufPtr()
    {
        return reinterpret_cast<char*>(&iv_ver);
    }

    ////////////////////////////////////////////////////////////////////////////
    size_t trace_bin_entry_v2_t::getSize()
    {
        // sizeof component name plus NULL plus sizeof the trace data
        return (strlen(iv_comp) + 1 +
                sizeof(trace_bin_entry_t) +
                (getEntry())->head.length);
    }

    ////////////////////////////////////////////////////////////////////////////
    size_t Buffer::getTrace(ComponentDesc    *i_comp,
                            std::list<tid_t> &i_tids,
                            void             *o_data,
                            size_t            i_max)
    {
        // sanity check input parms
        if (o_data == nullptr)
        {
            return 0;
        }
        trace_buf_head_v2_t *l_tbh = reinterpret_cast<trace_buf_head_v2_t*>(o_data);
        l_tbh->init(i_max);

        if (i_comp == nullptr)
        {
            return 0;
        }
        if (!i_max || i_max < sizeof(trace_bin_entry_t))
        {
            return 0;
        }

#ifndef __HOSTBOOT_RUNTIME
        // Prevent daemon from changing things while we're extracting.
        _producerEnter();
#endif

        std::vector<Entry*> l_vec;
        Entry              *l_entry = i_comp->iv_first;
        trace_bin_entry_t  *l_bin_entry;

        l_vec.reserve(32);

        size_t l_comp_len       = strnlen(i_comp->iv_compName, TRAC_COMP_SIZE);
        size_t l_comp_size      = l_comp_len + 1;
        size_t l_data_size      = 0;
        size_t l_max_data_size  = l_tbh->getMaxDataSize();
        size_t l_bin_entry_size = 0;

        // loop and save each matching Entry pointer (v1 trace entry) into l_vec
        while (l_entry       &&
               l_entry->size &&
               l_data_size + l_comp_size + l_entry->size <= l_max_data_size)
        {
            l_bin_entry = reinterpret_cast<trace_bin_entry_t*>(l_entry->data);

            if (i_tids.size())
            {
                if (std::find(i_tids.begin(),
                              i_tids.end(),
                              l_bin_entry->stamp.tid) == i_tids.end())
                {
                    l_entry = l_entry->next;
                    continue;
                }
            }
            // found a Trace with a matching TID
            l_data_size += l_comp_size + l_entry->size;
            l_vec.push_back(l_entry);
            l_entry = l_entry->next;
        }

        // copy each v1 Trace in l_vec as a v2 trace in o_data
        for (const auto &itr : l_vec)
        {
            if (!itr) {continue;}

            l_bin_entry      = reinterpret_cast<trace_bin_entry_t*>(itr->data);
            l_bin_entry_size = l_bin_entry->getSize();

            memcpy(l_tbh->iv_next, i_comp->iv_compName, l_comp_len);
            l_tbh->iv_size += l_comp_size;
            l_tbh->iv_next += l_comp_size;

            memcpy(l_tbh->iv_next, itr->data, l_bin_entry_size);
            l_tbh->iv_size += l_bin_entry_size;
            l_tbh->iv_next += l_bin_entry_size;
        }

#ifndef __HOSTBOOT_RUNTIME
        // Unlock for daemon.
        _producerExit();
#endif

        return l_tbh->getUDSize();
    }

    ////////////////////////////////////////////////////////////////////////////
    void trace_buf_head_v2_t::extract(std::vector<trace_bin_entry_v2_t*> &o_vec,
                                                                   size_t i_max)
    {
        if (i_max == 0 || iv_size == 0)
        {
            return;
        }

        size_t l_i_size = 0;
        size_t l_o_size = 0;
        size_t l_i_max  = iv_size;
        size_t l_o_max  = calcMaxDataSize(i_max);

        char *l_addr = reinterpret_cast<char*>(iv_data);

        trace_bin_entry_v2_t *l_entry{nullptr};
        size_t                l_entry_size{0};

        l_entry = reinterpret_cast<trace_bin_entry_v2_t*>(l_addr);
        l_entry_size = l_entry->getSize();

        // loop through iv_data, add ptrs to o_vec until a size limit is reached
        while (l_o_size + l_entry_size <= l_o_max && // output is within bounds
               l_i_size + l_entry_size <= l_i_max)   // input is within iv_data
        {
            l_addr   += l_entry_size;
            l_i_size += l_entry_size;
            l_o_size += l_entry_size;

            o_vec.push_back(l_entry);  // save the trace entry ptr

            l_entry = reinterpret_cast<trace_bin_entry_v2_t*>(l_addr);
            l_entry_size = l_entry->getSize();
        }
        return;
    }

    ////////////////////////////////////////////////////////////////////////////
    void trace_buf_head_v2_t::append(trace_buf_head_v2_t *i_tbh)
    {
        trace_bin_entry_v2_t *l_entry{nullptr};
        uint32_t              l_entry_size{0};

        // sanity check input parms
        if (!i_tbh || !iv_next) {return;}

        char  *l_i_addr = i_tbh->iv_data;
        char  *l_i_end  = i_tbh->iv_next;
        char  *l_o_end  = getEndPtr();

        l_entry = reinterpret_cast<trace_bin_entry_v2_t*>(l_i_addr);
        l_entry_size = l_entry->getSize();

        while (l_i_addr + l_entry_size <= l_i_end &&   // input  is within bounds
               iv_next  + l_entry_size <= l_o_end)     // output is within bounds
        {
            memcpy(iv_next, l_entry, l_entry_size);
            l_i_addr += l_entry_size;
            iv_size  += l_entry_size;
            iv_next  += l_entry_size;

            l_entry      = reinterpret_cast<trace_bin_entry_v2_t*>(l_i_addr);
            l_entry_size = l_entry->getSize();
        }
        return;
    }

    ////////////////////////////////////////////////////////////////////////////
    void trace_buf_head_v2_t::cleanup(std::vector<trace_bin_entry_v2_t*> &o_vec)
    {
        if (o_vec.size() == 0 || iv_size == 0)
        {
            return;
        }

        // Sort the vector by timestamp and hash
        std::sort(o_vec.begin(), o_vec.end(),
                  // Define a lambda comparator function for sorting criteria
                  [](TRACE::trace_bin_entry_v2_t *a_v2,
                     TRACE::trace_bin_entry_v2_t *b_v2)
                    {
                        // a goes before b if a's timestamp is less than b's.
                        // If they are equal then compare the hash values.
                        bool result = false;
                        TRACE::trace_bin_entry_t *a = a_v2->getEntry();
                        TRACE::trace_bin_entry_t *b = b_v2->getEntry();
                        if (a->stamp.tbh < b->stamp.tbh)
                        {
                            result = true;
                        }
                        else if ((a->stamp.tbh == b->stamp.tbh)
                              && (a->stamp.tbl < b->stamp.tbl))
                        {
                            result = true;
                        }
                        else if ((a->stamp.tbh == b->stamp.tbh)
                                && (a->stamp.tbl == b->stamp.tbl)
                                && (a->head.hash < b->head.hash))
                        {
                            result = true;
                        }
                        return result;
                    });

        // Call unique to prune the duplicate trace entries
        auto newEnd = std::unique(o_vec.begin(), o_vec.end(),
                    // Define a lambda predicate function for duplicate criteria
                [](TRACE::trace_bin_entry_v2_t *a_v2,
                   TRACE::trace_bin_entry_v2_t *b_v2)
                    {
                        // a is equivalent to b if a's timestamp is the same as
                        // b's and their hashes are the same.
                        bool result = false;
                        TRACE::trace_bin_entry_t *a = a_v2->getEntry();
                        TRACE::trace_bin_entry_t *b = b_v2->getEntry();
                        if ((a->stamp.tbh == b->stamp.tbh)
                         && (a->stamp.tbl == b->stamp.tbl)
                         && (a->head.hash == b->head.hash))
                        {
                            result = true;
                        }
                        return result;
                    });

        o_vec.resize(std::distance(o_vec.begin(), newEnd));

        return;
    }

    ////////////////////////////////////////////////////////////////////////////
    void trace_buf_head_v2_t::output(std::vector<trace_bin_entry_v2_t*> &i_vec)
    {
        size_t l_entry_size{0};
        char  *l_end = getEndPtr();

        init(iv_max);

        for (auto itr : i_vec)
        {
            if (!itr) {continue;}

            l_entry_size = itr->getSize();

            if (iv_next + l_entry_size > l_end)  // output addr is within bounds
            {
                break;
            }

            // add a trace into iv_data
            memcpy(iv_next, itr, l_entry_size);
            iv_size += l_entry_size;
            iv_next += l_entry_size;
        }

        return;
    }

}
