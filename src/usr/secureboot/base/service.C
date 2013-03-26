/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/service.C $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

        } while(0);

        return l_errl;
    }

    bool enabled()
    {
        return Singleton<Settings>::instance().getEnabled();
    }
}
