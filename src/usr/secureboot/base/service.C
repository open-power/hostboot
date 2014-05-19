/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/service.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#include <secureboot/service.H>
#include <stdint.h>
#include <sys/mm.h>
#include <util/singleton.H>
#include <secureboot/secure_reasoncodes.H>

#include "settings.H"
#include "header.H"
#include "purge.H"

namespace SECUREBOOT
{
    void* initializeBase(void* unused)
    {
        errlHndl_t l_errl = NULL;

        do
        {
            // Load original secureboot header.
            if (enabled())
            {
                Singleton<Header>::instance().loadBaseHeader();
            }

            // Blind-purge lower portion of cache.
            l_errl = issueBlindPurge();
            if (l_errl)
            {
                break;
            }

            // Extend memory footprint into lower portion of cache.
            //   This can only fail is someone has already called to extend
            //   to post-secureboot state.  Major coding bug, so just assert.
            assert(0 == mm_extend(MM_EXTEND_POST_SECUREBOOT));


            // Initialize the Secure ROM
            l_errl = initializeSecureROM();
            if (l_errl)
            {
                break;
            }


        } while(0);

        return l_errl;
    }

    bool enabled()
    {
        return Singleton<Settings>::instance().getEnabled();
    }
}
