/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/runtime/rt_service.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#include "../service.H"
#include "../compdesc.H"
#include "../buffer.H"
#include "../entry.H"
#include <limits.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <util/align.H>
#include <runtime/interface.h>
#include <util/singleton.H>
#include "rt_rsvdtracebufservice.H"

namespace TRACE
{
    // Value was chosen empirically from trace lengths during the IPL.
    static const size_t DEFAULT_TRACE_LENGTH = 128;

    Service::Service()
    {
        // Only use one "fake" daemon for runtime and one valid buffer
        // BUFFER_FAST skips some blocking calls and is limited in pages
        iv_daemon = new TRACEDAEMON::Daemon();
        iv_buffers[BUFFER_SLOW] = nullptr;
        iv_buffers[BUFFER_FAST] = new Buffer(iv_daemon);

        // Force create the Reserved Trace Buffer Service object
        iv_rsvdtracebufservice = &(Singleton<RsvdTraceBufService>::instance());

        iv_compList = &(Singleton<ComponentList>::instance());
    }

    Service::~Service()
    {
        // No need to destruct the service.

        #ifndef PROFILE_CODE
        // When code coverage is active, unload all the runtime
        // modules to recover the code coverage data
        assert(0, "No need to destruct the Service");
        #endif
    }

    void Service::writeEntry(ComponentDesc* i_td,
                             trace_hash_val i_hash,
                             const char * i_fmt,
                             uint32_t i_line,
                             uint32_t i_type,
                             va_list i_args)
    {
        if (unlikely(i_type == TRACE_DEBUG))
        {
            if (!i_td->iv_debugEnabled)
            {
                return;
            }
        }

        size_t compName_len = strnlen(i_td->iv_compName,
                                      sizeof(i_td->iv_compName));

        char output[DEFAULT_TRACE_LENGTH];
        memcpy(output, i_td->iv_compName, compName_len);
        output[compName_len] = ':';
        size_t length = vsnprintf(&output[compName_len+1],
                                  DEFAULT_TRACE_LENGTH-(compName_len+1),
                                  i_fmt, i_args);

        if (unlikely((compName_len + 1 + length + 1) > DEFAULT_TRACE_LENGTH))
        {
            char* long_output = new char[compName_len + 1 + length + 1];
            memcpy(long_output, i_td->iv_compName, compName_len);
            long_output[compName_len] = ':';
            vsprintf(&long_output[compName_len+1], i_fmt, i_args);
            g_hostInterfaces->puts(long_output);
            delete[] long_output;
        }
        else
        {
            g_hostInterfaces->puts(output);
        }

        //////////////////////////////////////////////
        // Try to use buffers
        //////////////////////////////////////////////
        do
        {
            // Get the right buffer for this component.
            Buffer* l_buffer = iv_buffers[i_td->iv_bufferType];

            if (l_buffer == nullptr)
            {
                break;
            }

            // Copy the current time.
            trace_entry_stamp_t l_time;
            _createTimeStamp(&l_time);

            // Sizes for trace entry.
            uint32_t l_size = 0;
            uint32_t l_num_args = 0;

            // Maps of arguments to special types.
            uint64_t l_str_map = 0, l_char_map = 0, l_double_map = 0;

            va_list l_args;
            va_copy(l_args, i_args);

            // Parse the fmt list to determine the types/sizes of each
            // argument.
            while(NULL != (i_fmt = strchr(i_fmt, '%')))
            {
                i_fmt++; // skip %

                // skip width in front of format type
                while ((i_fmt != nullptr) && (isdigit(*i_fmt) || (*i_fmt == '-')))
                {
                    i_fmt++;
                }
                if (i_fmt == nullptr)
                    break;

                switch (*i_fmt)
                {
                    case '%':
                        break;

                    case 's': // string.
                        l_str_map |= (1 << l_num_args);
                        l_num_args++;
                        l_size += ALIGN_4(strlen(va_arg(l_args, char*)) + 1);
                        break;

                    case 'c': // character.
                        l_char_map |= (1 << l_num_args);
                        l_num_args++;
                        va_arg(l_args, uint32_t);
                        l_size += sizeof(uint32_t);
                        break;

                    case 'e': // doubles.
                    case 'f':
                    case 'g':
                        l_double_map |= (1 << l_num_args);
                        l_num_args++;
                        va_arg(l_args, double);
                        l_size += sizeof(double);
                        break;

                    default: // uint64_t-sized argument.
                        l_num_args++;
                        va_arg(l_args, uint64_t);
                        l_size += sizeof(uint64_t);
                        break;
                }
                i_fmt++;
            }

            va_end(l_args);

            // Ensure we don't have too many arguments.
            if (l_num_args > TRAC_MAX_ARGS)
            {
                // Simply reducing the number of arguments and continuing
                // causes FSP trace to crash.  See defect 864438.
                //l_num_args = TRAC_MAX_ARGS;
                break;
            }

            // Claim an entry from the buffer.
            uint32_t l_realSize = ALIGN_4(sizeof(trace_bin_entry_t) + l_size);
            Entry* l_entry = l_buffer->claimEntry(i_td, l_realSize);
            if (nullptr == l_entry)
            {
                break;
            }

            // Copy contents into the 'fsp-trace'-style structure.
            trace_bin_entry_t* l_binEntry =
                reinterpret_cast<trace_bin_entry_t*>(&l_entry->data[0]);

            l_binEntry->stamp = l_time;
            l_binEntry->head.length = l_size;
            l_binEntry->head.tag = TRACE_COMP_TRACE;
            l_binEntry->head.hash = i_hash;
            l_binEntry->head.line = i_line;

            // Copy arguments into the 'fsp-trace' entry's data section.
            char* l_dataOut = reinterpret_cast<char*>(&l_binEntry->data[0]);
            for (size_t i = 0; i < l_num_args; i++)
            {
                // String.
                if (l_str_map & (1 << i))
                {
                    char* str = va_arg(i_args, char*);
                    uint32_t strSize = strlen(str);

                    memcpy(l_dataOut, str, strSize+1);

                    l_dataOut += ALIGN_4(strSize + 1);
                }
                // Single character.
                else if (l_char_map & (1 << i))
                {
                    *(reinterpret_cast<uint32_t*>(l_dataOut)) =
                        va_arg(i_args, uint32_t);
                    l_dataOut += sizeof(uint32_t);
                }
                // Doubles.
                else if (l_double_map & (1 << i))
                {
                    *(reinterpret_cast<double*>(l_dataOut)) =
                        va_arg(i_args, double);

                    l_dataOut += sizeof(double);
                }
                // All others (as uint64_t's).
                else
                {
                    *(reinterpret_cast<uint64_t*>(l_dataOut)) =
                        va_arg(i_args, uint64_t);

                    l_dataOut += sizeof(uint64_t);
                }
            }

            // "Commit" entry to buffer.
            l_buffer->commitEntry(l_entry);

            // Copy the trace entry in to the Reserved Trace Buffer too
            iv_rsvdtracebufservice->writeEntry(i_td,
                            reinterpret_cast<char*>(&l_entry->data[0]),
                            l_realSize);

        } while(0);
    }


    void Service::writeBinEntry(ComponentDesc* i_td,
                                trace_hash_val i_hash,
                                const char * i_fmt,
                                uint32_t i_line,
                                const void* i_ptr,
                                uint32_t i_size,
                                uint32_t i_type)
    {
        if (unlikely(i_type == TRACE_DEBUG))
        {
            if (!i_td->iv_debugEnabled)
            {
                return;
            }
        }

        size_t compName_len = strnlen(i_td->iv_compName,
                                      sizeof(i_td->iv_compName));

        // Output header.
        char output[DEFAULT_TRACE_LENGTH];
        memcpy(output, i_td->iv_compName, compName_len);
        output[compName_len] = ':';
        size_t length = vsnprintf(&output[compName_len+1],
                                  DEFAULT_TRACE_LENGTH-(compName_len+1),
                                  i_fmt, NULL);

        if(unlikely((compName_len + 1 + length + 1) > DEFAULT_TRACE_LENGTH))
        {
            char* long_output = new char[compName_len + length + 1];
            memcpy(long_output, i_td->iv_compName, compName_len);
            long_output[compName_len] = ':';
            vsprintf(&long_output[compName_len+1], i_fmt, NULL);
            g_hostInterfaces->puts(long_output);
            delete[] long_output;
        }
        else
        {
            g_hostInterfaces->puts(output);
        }

        // Output binary data.
        // Format is:
        // ~[0x0000] 01234567 01234567 01234567 01234567    *012345689abcdef*
        static size_t BINARY_FORMAT_LENGTH =
            68 + sizeof(ComponentDesc::iv_compName) + 1;

        size_t pos = 0;
        while (pos < i_size)
        {
            char bin_output[BINARY_FORMAT_LENGTH];
            memcpy(bin_output, i_td->iv_compName, compName_len);
            size_t output_pos = compName_len +
                                sprintf(&bin_output[compName_len],
                                        ":~[0x%04hx]", (uint16_t) pos);

            for (int i = 0; i < 16; ++i)
            {
                if ((i % 4) == 0)
                {
                    bin_output[output_pos++] = ' ';
                }
                if ((pos + i) < i_size)
                {
                    output_pos +=
                        sprintf(&bin_output[output_pos], "%02x",
                                ((const char*)i_ptr)[pos+i]);
                }
                else
                {
                    bin_output[output_pos++] = ' ';
                    bin_output[output_pos++] = ' ';
                }
            }

            for (int i = 0; i < 4; i++)
            {
                bin_output[output_pos++] = ' ';
            }
            bin_output[output_pos++] = '*';

            for (int i = 0; i < 16; ++i)
            {
                char ch = ' ';
                if ((pos + i) < i_size)
                {
                    ch = ((const char*) i_ptr)[pos+i];
                    if (!isprint(ch))
                    {
                        ch = '.';
                    }
                }
                bin_output[output_pos++] = ch;
            }
            bin_output[output_pos++] = '*';
            bin_output[output_pos++] = '\0';

            g_hostInterfaces->puts(bin_output);

            pos += 16;
        }

        // Runtime traces
        do
        {
            // Get the right buffer for this component.
            Buffer* l_buffer = iv_buffers[i_td->iv_bufferType];
            if(l_buffer == nullptr)
            {
                break;
            }

            // Copy the current time.
            trace_entry_stamp_t l_time;
            _createTimeStamp(&l_time);

            // Claim an entry from the buffer.
            uint32_t l_realSize = ALIGN_4(sizeof(trace_bin_entry_t) + i_size);
            Entry* l_entry = l_buffer->claimEntry(i_td, l_realSize);
            if (nullptr == l_entry)
            {
                break;
            }

            // Copy contents into the 'fsp-trace'-style structure.
            trace_bin_entry_t* l_binEntry =
                reinterpret_cast<trace_bin_entry_t*>(&l_entry->data[0]);

            l_binEntry->stamp = l_time;
            l_binEntry->head.length = i_size;
            l_binEntry->head.tag = TRACE_FIELDBIN;
            l_binEntry->head.hash = i_hash;
            l_binEntry->head.line = i_line;

            // Copy bin-data into the 'fsp-trace' entry's data section.
            memcpy(&l_binEntry->data[0], i_ptr, i_size);

            // "Commit" entry to buffer.
            l_buffer->commitEntry(l_entry);

            // Copy the trace entry in to the Reserved Trace Buffer too
            iv_rsvdtracebufservice->writeEntry(i_td,
                            reinterpret_cast<char*>(&l_entry->data[0]),
                            l_realSize);

        } while(0);

    }

    size_t Service::getBuffer(ComponentDesc* i_comp,
                              void * o_data,
                              size_t i_size)
    {
        return
            iv_buffers[i_comp->iv_bufferType]->getTrace(i_comp,o_data,i_size);
    }

    void Service::flushBuffers()
    {
        // No-op in runtime.
    }

    void Service::_createTimeStamp(trace_entry_stamp_t *o_entry)
    {
        timespec_t curTime;

        clock_gettime(CLOCK_MONOTONIC, &curTime);

        o_entry->tbh = curTime.tv_sec;
        o_entry->tbl = curTime.tv_nsec;
        o_entry->tid = task_gettid();
    }

    Service* Service::getGlobalInstance()
    {
        return &(Singleton<Service>::instance());
    }
}
