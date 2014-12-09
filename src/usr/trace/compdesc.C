/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/compdesc.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
#include "compdesc.H"
#include "service.H"
#include <assert.h>
#include <string.h>
#include <string_ext.h>

#include <targeting/common/commontargeting.H>

namespace TRACE
{
    ComponentDesc::ComponentDesc(const char* i_comp, uint32_t i_size,
                                 uint8_t i_bufferType) :
        iv_bufferType(i_bufferType), iv_debugEnabled(false),
        iv_maxSize(i_size), iv_curSize(0),
        iv_first(NULL), iv_last(NULL)
    {
        assert(iv_bufferType < BUFFER_COUNT);

        memset(iv_compName, '\0', sizeof(iv_compName));
        strcpy(iv_compName, i_comp); // No buffer overrun because of assert
                                     // in ComponentList::getDescriptor.
        strupr(iv_compName);

        iv_compNameLen = strlen(iv_compName) + 1;
    }

    ComponentList::ComponentList() :
        iv_components()
    {
        mutex_init(&iv_mutex);
    };

    ComponentList::~ComponentList()
    {
        mutex_destroy(&iv_mutex);
    };

    ComponentDesc* ComponentList::getDescriptor(const char* i_comp,
                                                uint32_t i_size,
                                                uint8_t i_bufferType)
    {
        ComponentDesc* l_rc = NULL;

        assert(strlen(i_comp) < ComponentDesc::COMP_SIZE);

        // Fix up the component name to be upper case.
        char l_compName[ComponentDesc::COMP_SIZE];
        memset(l_compName, '\0', sizeof(l_compName));
        strcpy(l_compName, i_comp);
        strupr(l_compName);

        mutex_lock(&iv_mutex);

        // Look for existing descriptor.
        for(List::iterator i = iv_components.begin();
            i != iv_components.end();
            ++i)
        {
            if (0 == memcmp(&i->iv_compName, l_compName, sizeof(l_compName)))
            {
                l_rc = &(*i);
                break;
            }
        }

        // Insert new descriptor if none found.
        if ((NULL == l_rc) && (i_size > 0))
        {
            iv_components.push_back(ComponentDesc(l_compName, i_size,
                                                  i_bufferType));
            l_rc = &iv_components.back();
        }

#ifndef __HOSTBOOT_RUNTIME  // TODO: RTC 79408
        // Check for special SCAN and FAPI_MFG component to
        // force enable debug trace on.
        if (l_rc && !l_rc->iv_debugEnabled)
        {
            if(0 == memcmp(l_compName, "SCAN", 5))
            {
                TARGETING::Target* sys = NULL;
                TARGETING::targetService().getTopLevelTarget(sys);

                TARGETING::HbSettings hbSettings =
                    sys->getAttr<TARGETING::ATTR_HB_SETTINGS>();

                if (hbSettings.traceScanDebug)
                {
                    l_rc->iv_debugEnabled = true;
                }
            }
            else if(0 == memcmp(l_compName, "FAPI_MFG",9))
            {
                TARGETING::Target* sys = NULL;
                TARGETING::targetService().getTopLevelTarget(sys);

                TARGETING::ATTR_MFG_TRACE_ENABLE_type l_mfgTraceEnable =
                    sys->getAttr<TARGETING::ATTR_MFG_TRACE_ENABLE>();

                if (l_mfgTraceEnable)
                {
                    l_rc->iv_debugEnabled = true;
                }
            }
        }
#endif

        mutex_unlock(&iv_mutex);
        return l_rc;
    }

};
