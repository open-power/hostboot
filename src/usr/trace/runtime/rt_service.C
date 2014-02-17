/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/runtime/rt_service.C $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#include "../service.H"
#include "../compdesc.H"
#include <limits.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <runtime/interface.h>

namespace TRACE
{
    // Value was chosen empirically from trace lengths during the IPL.
    static const size_t DEFAULT_TRACE_LENGTH = 128;

    Service::Service()
    {
    }

    Service::~Service()
    {
        // No need to destruct the service.
        assert(0);
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
    }

    void Service::writeBinEntry(ComponentDesc* i_td,
                                trace_hash_val i_hash,
                                const char * i_fmt,
                                uint32_t i_ine,
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

    }

    size_t Service::getBuffer(ComponentDesc* i_comp,
                              void * o_data,
                              size_t i_size)
    {
        // No way to get the buffer back in runtime.
        return 0;
    }

    void Service::flushBuffers()
    {
        // No-op in runtime.
    }

}
