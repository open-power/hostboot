/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/interface.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2025                        */
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

/** @file interface.C
 *  @brief Implementation of the trace interfaces.
 *
 *  Most of the functions in this file are simply redirections to the
 *  appropriate class/instance that handles this functionality.
 */

#include <trace/interface.H>
#include <util/singleton.H>
#include <stdarg.h>
#include <limits.h>
#include <string.h>

#include <trace/compdesc.H>
#include <trace/entry.H>
#include <trace/service.H>
#include <trace/buffer.H>
#include <vector>

#include <targeting/common/commontargeting.H>

#if  __HOSTBOOT_RUNTIME
#include "runtime/rt_rsvdtracebufservice.H"
#endif

namespace TRACE
{
    TracInit::TracInit(trace_desc_t** o_td,
                       const char * i_comp,
                       const size_t i_size,
                       uint8_t i_bufferType)
    {
        initBuffer(o_td, i_comp, i_size, i_bufferType);
    }

    TracInit::~TracInit() {}



    void initBuffer(ComponentDesc** o_td,
                    const char* i_comp,
                    size_t i_size,
                    uint8_t i_bufferType)
    {

        if (i_size == 0)
        {
            i_size = KILOBYTE;
        }

#ifdef __HOSTBOOT_RUNTIME
        // Run all Runtime traces to same buffer
        i_bufferType = BUFFER_FAST;
#endif
        (*o_td) =
            Singleton<ComponentList>::instance().getDescriptor(i_comp,
                                                               i_size,
                                                               i_bufferType);
    }

    void trace_adal_write_all(ComponentDesc * io_td,
                              const traceCodeInfo* i_info,
                              const uint32_t i_line,
                              const uint32_t i_type, ...)
    {
        va_list args;
        va_start(args, i_type);

        Singleton<Service>::instance().writeEntry(io_td,
                                                  i_info->hash, i_info->format,
                                                  i_line, i_type, args);

        va_end(args);
    }

    void trace_adal_write_bin(ComponentDesc * io_td,
                              const traceCodeInfo* i_info,
                              const uint32_t i_line,
                              const void * i_ptr,
                              const uint32_t i_size,
                              const uint32_t i_type)
    {
        Singleton<Service>::instance().writeBinEntry(io_td, i_info->hash,
                                                     i_info->format, i_line,
                                                     i_ptr, i_size, i_type);
    }

    size_t getBuffer(const char * i_comp,
                       void * o_data,
                       size_t i_bufferSize )
    {
        size_t l_bufferSize(0);

        ComponentDesc* l_comp =
            Singleton<ComponentList>::instance().getDescriptor(i_comp, 0);

        if (NULL == l_comp)
        {
#if  __HOSTBOOT_RUNTIME
            // All the components will have a corresponding CompDescriptor,
            // if buffer is created. RSVD_MEM_TRACE is a speacial case without
            // a corresponding compDescriptor. Check for RSVD_MEM_TRACE, if
            // not RSVD_MEM_TRACE then return 0.
            if(strcmp( i_comp, "RSVD_MEM_TRACE") == 0)
            {
                l_bufferSize =  Singleton<RsvdTraceBufService>::
                                     instance().getBuffer(o_data,i_bufferSize);
            }
#endif
        }
        else
        {
            l_bufferSize = Singleton<Service>::instance().getBuffer(l_comp,
                                                        o_data, i_bufferSize);
        }
        return l_bufferSize;
    }

    /**
     *  @brief  Get the traces for i_comp. If i_comp is null, then get traces
     *          for all components.
     *           (local function called by getBuffer below)
     *
     *  @param[in] i_comp     Component name or NULL
     *  @param[in] i_tids     List of Thread IDs to filter
     *  @param[in] i_tbh      Buffer used to get the Traces
     *  @param[in] i_tbh_tmp  Buffer used to aggregate Traces
     */
    void getBuffer(const char          *i_comp,
                   std::list<tid_t>    &i_tids,
                   trace_buf_head_v2_t *i_tbh,
                   trace_buf_head_v2_t *i_tbh_tmp)
    {
        ComponentList                *l_compList{nullptr};
        ComponentList::List::iterator itr;
        size_t                        l_get_size(0);
        bool                          l_found = false;

        l_compList = &(Singleton<ComponentList>::instance());

        // Iterate through all the trace buffers
        bool more = l_compList->first(itr);
        while (more)
        {
            if (i_comp)
            {
                if (*itr == i_comp)
                {
                    l_found = true;
                }
                else
                {
                    more = l_compList->next(itr);
                    continue; // not a match, skip
                }
            }

            l_get_size = Singleton<Service>::instance().getBuffer(&(*itr),
                                                                  i_tids,
                                                                  i_tbh,
                                                                  i_tbh->iv_max);
            if (l_get_size)
            {
                i_tbh_tmp->append(i_tbh);
            }

            if (l_found) {break;} // we have the traces for i_comp, done

            more = l_compList->next(itr);
        }
        return;
    }

    ////////////////////////////////////////////////////////////////////////////
    size_t getBuffer(std::list<const char*> i_comps,
                     std::list<tid_t>      &i_tids,
                     void                  *o_data,
                     size_t                 i_max)
    {
        trace_buf_head_v2_t *l_tbh = reinterpret_cast<trace_buf_head_v2_t*>(o_data);

        // sanity check input parms
        if (o_data == nullptr)
        {
            return 0;
        }
        l_tbh->init(i_max);

        if (i_max < sizeof(trace_bin_entry_t))
        {
            return 0;
        }

        std::vector<trace_bin_entry_v2_t*> l_vec;
        size_t                             l_max = i_max+1024;
        char                              *l_tmp = new char[l_max];

        trace_buf_head_v2_t *l_tbh_tmp = reinterpret_cast<trace_buf_head_v2_t*>(l_tmp);

        l_tbh_tmp->init(l_max);

        if (i_comps.size())
        {
            uint32_t l_size_per_comp = i_max/i_comps.size();
            if (i_tids.size() == 0 &&
                l_size_per_comp > sizeof(trace_bin_entry_t))
            {
                // If no tids specified, divide the size between the comps
                // The init() sets the header up to use a subset of the memory
                l_tbh->init(l_size_per_comp);
            }

            // get traces only for the components in i_comps
            for (auto l_comp : i_comps)
            {
                // fill l_tbh with traces for l_comp, and append to l_tbh_tmp
                getBuffer(l_comp, i_tids, l_tbh, l_tbh_tmp);
            }
        }
        else
        {
            // fill l_tbh with traces for all components, and append to l_tbh_tmp
            char *l_comp{nullptr};
            getBuffer(l_comp, i_tids, l_tbh, l_tbh_tmp);
        }

        // create a vector of pointers to the tmp traces for cleanup
        l_tbh_tmp->extract(l_vec, l_max);

        // remove dups and sort traces in the tmp buf
        l_tbh_tmp->cleanup(l_vec);

        // copy traces into o_data
        l_tbh->init(i_max);
        l_tbh->output(l_vec);

        delete[] l_tmp;

        return l_tbh->getUDSize();
    }

    void flushBuffers()
    {
        Singleton<Service>::instance().flushBuffers();
    }

#ifndef __HOSTBOOT_RUNTIME
    void enableContinousTrace()
    {
        Singleton<Service>::instance().enableContinous();
    }

    void disableContinousTrace()
    {
        Singleton<Service>::instance().disableContinous();
    }
#endif

    bool isDebugEnabled(ComponentDesc * i_td)
    {
        return i_td->isDebugEnabled();
    }

    void enableDebug(const char* i_comp,
                     bool i_enable)
    {
        ComponentDesc* l_comp =
            Singleton<ComponentList>::instance().getDescriptor(i_comp, 0);
        l_comp->enableDebug(i_enable);
    }

    void evaluateAttributes(ComponentDesc* i_td)
    {
        // Iterate through all the trace buffers if asked
        if( i_td == nullptr )
        {
            ComponentList* l_compList = &(Singleton<ComponentList>::instance());
            ComponentList::List::iterator itr;

            bool more = l_compList->first(itr);
            while (more)
            {
                // recursive call for every trace buffer individually
                evaluateAttributes(&(*itr));

                more = l_compList->next(itr);
            }

            return;
        }

        // Now check if the component should be enabled or not
        if(0 == memcmp(i_td->iv_compName, "SCAN", 5))
        {
            TARGETING::Target* sys = NULL;
            TARGETING::targetService().getTopLevelTarget(sys);

            TARGETING::HbSettings hbSettings =
              sys->getAttr<TARGETING::ATTR_HB_SETTINGS>();

            auto traceEnable =
              sys->getAttr<TARGETING::ATTR_HB_SETTINGS_OVERRIDE>();

            i_td->iv_debugEnabled = (hbSettings.traceScanDebug
                                     || (reinterpret_cast<TARGETING::HbSettings*>
                                         (&traceEnable))->traceScanDebug);
        }
        else if(0 == memcmp(i_td->iv_compName, "FAPI_DBG", 9))
        {
            TARGETING::Target* sys = NULL;
            TARGETING::targetService().getTopLevelTarget(sys);

            TARGETING::HbSettings hbSettings =
              sys->getAttr<TARGETING::ATTR_HB_SETTINGS>();

            auto traceEnable =
              sys->getAttr<TARGETING::ATTR_HB_SETTINGS_OVERRIDE>();

            i_td->iv_debugEnabled =(hbSettings.traceFapiDebug
                                    || (reinterpret_cast<TARGETING::HbSettings*>
                                        (&traceEnable))->traceFapiDebug);
        }
        else if(0 == memcmp(i_td->iv_compName, "FAPI_MFG",9))
        {
            TARGETING::Target* sys = NULL;
            TARGETING::targetService().getTopLevelTarget(sys);

            TARGETING::ATTR_MFG_TRACE_ENABLE_type l_mfgTraceEnable =
              sys->getAttr<TARGETING::ATTR_MFG_TRACE_ENABLE>();

            i_td->iv_debugEnabled = l_mfgTraceEnable;
        }
    }
};
