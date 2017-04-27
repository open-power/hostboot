/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utilsemipersist.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
 * @file utilsemipersist.C
 *
 * @brief   Abstraction of semi volatile pnor partition
 *
 * Used for creating and manipulating streams
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <trace/interface.H>
#include <limits.h>
#include <util/util_reasoncodes.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <pnor/pnorif.H>
#include <sys/mm.h>
#include <util/utilsemipersist.H>
#include "utilbase.H"
trace_desc_t* g_trac_persist = nullptr;
TRAC_INIT(&g_trac_persist, "UTIL_PERSIST", KILOBYTE);

using namespace ERRORLOG;

namespace Util
{

    // ----------------------------------------------
    // Globals
    // ----------------------------------------------
    mutex_t g_PersistMutex = MUTEX_INITIALIZER;

    semiPersistData_t * getHbVolatile()
    {
        errlHndl_t l_err = nullptr;
        uint64_t l_vaddr = 0x0;
        static uint64_t g_HbVolatileAddr = 0x0;

        do
        {
            if(g_HbVolatileAddr)
            {
                l_vaddr = g_HbVolatileAddr;
                break;
            }

            PNOR::SectionInfo_t l_pnorHbVolatile;
            l_err = PNOR::getSectionInfo(PNOR::HB_VOLATILE, l_pnorHbVolatile);
            if(l_err)
            {
                delete l_err;
                l_err = nullptr;
                TRACFCOMP( g_trac_persist,
                           INFO_MRK"getHbVolatile(): HB_VOLATILE section not"
                           " found, it is optional");
                break;
            }
            if(l_pnorHbVolatile.size == 0)
            {
                TRACFCOMP( g_trac_persist,
                           INFO_MRK"getHbVolatile(): HB_VOLATILE section is"
                           " empty in PNOR");
                break;
            }

            g_HbVolatileAddr = l_pnorHbVolatile.vaddr;
            l_vaddr = g_HbVolatileAddr;

        }while(0);

        return reinterpret_cast<semiPersistData_t*>(l_vaddr);
    }

    void readSemiPersistData(semiPersistData_t & o_data)
    {
        memset(&o_data, 0x0, sizeof(semiPersistData_t));

        //Lock to prevent concurrent access
        mutex_lock(&g_PersistMutex);

        auto l_data = getHbVolatile();
        if(l_data)
        {
            o_data = *l_data;
        }

        mutex_unlock(&g_PersistMutex);
    }

    void writeSemiPersistData(const semiPersistData_t i_data)
    {
        //Lock to prevent concurrent access
        mutex_lock(&g_PersistMutex);

        auto l_data = getHbVolatile();
        if(l_data)
        {
            *l_data = i_data;
            int l_rc = mm_remove_pages(FLUSH, l_data,
                                       sizeof(semiPersistData_t));
            if (l_rc)
            {
                TRACFCOMP(g_trac_persist,
                          ERR_MRK"writeSemiPersistData(): mm_remove_pages"
                          "(FLUSH,%p,%d) returned %d",l_data,
                          sizeof(semiPersistData_t),l_rc);
            }
        }
        mutex_unlock(&g_PersistMutex);
    }
};
