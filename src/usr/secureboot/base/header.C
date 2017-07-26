/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/header.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#include <secureboot/header.H>
#include <sys/mm.h>
#include <sys/mmio.h>
#include <kernel/console.H>
#include <errno.h>
#include <kernel/bltohbdatamgr.H>

namespace SECUREBOOT
{
    Header& baseHeader()
    {
        return Singleton<Header>::instance();
    }

    // @TODO RTC 178520 Converge on a single method of reading the secure
    // header
    void Header::loadSecurely()
    {
        const void* const pSecureHeader = g_BlToHbDataManager.getHbbHeader();

        // Fatal code bug if called with nullptr pointer
        assert(pSecureHeader != nullptr,
            "BUG! In Header::loadSecurely(), expected valid address for base "
            "image header in secure mode, but got nullptr.");
        _set(pSecureHeader);
    }

    // @TODO RTC 178520 Converge on a single method of reading the secure
    // header
    void Header::setNonSecurely(
        const void* const i_pHeader)
    {
        // Fatal code bug if called with nullptr pointer
        assert(i_pHeader != nullptr,"BUG! In Header::setNonSecurely(), "
            "caller passed a nullptr header address.");
        _set(i_pHeader);
    }

    void Header::_set(
        const void* const i_pHeader)
    {
        // Fatal code bug if already loaded
        assert(iv_data == nullptr,"BUG! In Header::_set(), "
            "a cached header is already present.");

        // Fatal code bug if called with nullptr pointer
        assert(i_pHeader != nullptr,"BUG! In Header::_set(), "
            "caller passed a nullptr header address.");

        void* pData = malloc(PAGESIZE);
        memcpy(pData,i_pHeader,PAGE_SIZE);
        iv_data = pData;
        pData = nullptr;
    }

    void Header::getHeader(
        const void*& o_pHeader) const
    {
        // Fatal code bug if queried before loaded
        assert(iv_data!=nullptr,"BUG! In getHeader(), "
            "header is not present.");
        o_pHeader = iv_data;
    }
}
