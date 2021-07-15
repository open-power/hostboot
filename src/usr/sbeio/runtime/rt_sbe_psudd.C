/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/rt_sbe_psudd.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
 * @file rt_sbe_psudd.C
 * @brief SBE PSU device driver for Hostboot Runtime
 */

#include <trace/interface.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/common/target.H>
#include <errl/errlreasoncodes.H>
#include <sbeio/sbeioreasoncodes.H>
#include <sbeio/sbe_ffdc_package_parser.H>
#include <sbeio/sbe_psudd.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <sbeio/sbeioif.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <p10_extract_sbe_rc.H>
#include <errl/errludlogregister.H>
#include <sbeio/sbe_retry_handler.H>
#include <errl/errludprintk.H>
#include <sbe/sbeif.H>
#include <runtime/interface.h>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"psudd: " printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"psudd: " printf_string,##args)
#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio,"psudd: " printf_string,##args)


using namespace ERRORLOG;

namespace SBEIO
{
sbeAllocationHandle_t sbeMalloc(const size_t i_bytes)
{
    // Make sure we didn't exceed our reserved space
    if( i_bytes > SbePsu::MAX_HBRT_PSU_OP_SIZE_BYTES )
    {
        SBE_TRACF("sbeMalloc> Requested size exceeds allocated space (%d > %d)",
                  i_bytes, SbePsu::MAX_HBRT_PSU_OP_SIZE_BYTES);
        assert(false,"sbeMalloc> Requested size exceeds allocated space");
    }

    // Get a pointer to our reserved memory range
    void* l_psuMemoryVirt = nullptr;
    auto l_psuMemoryPhys = UTIL::assertGetToplevelTarget()->
      getAttr<ATTR_SBE_HBRT_PSU_PHYS_ADDR>();
    if( l_psuMemoryPhys == 0 )
    {
        // This should never happen because we already check this in the
        //  constructor
        SBE_TRACF("sbeMalloc> ATTR_SBE_HBRT_PSU_PHYS_ADDR is not set");
    }
    else
    {
        l_psuMemoryVirt = g_hostInterfaces->map_phys_mem(
                                    l_psuMemoryPhys,
                                    SbePsu::MAX_HBRT_PSU_OP_SIZE_BYTES);
    }

    // Return a handle so we can free() the buffer later
    return {
        l_psuMemoryVirt,
        reinterpret_cast<uint64_t>(l_psuMemoryVirt),
        l_psuMemoryVirt,
        l_psuMemoryPhys
    };
}

sbeAllocationHandle_t sbeMalloc(const size_t i_bytes, void*& o_allocation)
{
    sbeAllocationHandle_t l_hndl = sbeMalloc(i_bytes);
    o_allocation = reinterpret_cast<void*>(l_hndl.dataPtr);
    return l_hndl;
}

void sbeFree(sbeAllocationHandle_t& i_handle)
{
    // Since the adjunct has a limited number of mappings, we
    //  will unmap our range when we're done using it.
    if( i_handle.bufPtr )
    {
        int rc = g_hostInterfaces->unmap_phys_mem(i_handle.bufPtr);
        if( rc )
        {
            SBE_TRACF("sbeFree> Error from unmap_phys_mem : rc=%d, ignoring",
                      rc);
        }
    }
    else
    {
        SBE_TRACF("sbeFree> Attempt to free an empty buffer, ignoring");
    }
    i_handle.bufPtr = nullptr;
    i_handle.aligned = 0;
    i_handle.physAddr = 0;
}


/**
 * @brief  Constructor
 **/
SbePsu::SbePsu()
    :
    iv_earlyErrorOccurred(false),
    iv_psuResponse(nullptr),
    iv_responseReady(false),
    iv_shutdownInProgress(false)
{
    SBE_TRACF("SbePsu::SbePsu() Runtime Constructor");
    errlHndl_t l_errl = nullptr;

    //@fixme-hardcoding to known value since we have attribute ordering issue
    UTIL::assertGetToplevelTarget()->
      setAttr<ATTR_SBE_HBRT_PSU_PHYS_ADDR>(0xE76D0000);


    // Get a pointer to our reserved memory range
    auto l_physAddr = UTIL::assertGetToplevelTarget()->
      getAttr<ATTR_SBE_HBRT_PSU_PHYS_ADDR>();
    if( l_physAddr == 0 )
    {
        /*@
         * @errortype
         * @moduleid     SBEIO_RT_PSU
         * @reasoncode   SBEIO_NO_RUNTIME_BUFFER
         * @userdata1    <unused>
         * @userdata2    <unused>
         * @devdesc      No reserved memory reserved for runtime SBE PSU
         *               operations (ATTR_SBE_HBRT_PSU_PHYS_ADDR==0).
         * @custdesc     Firmware error
         */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               SBEIO_RT_PSU,
                               SBEIO_NO_RUNTIME_BUFFER,
                               0,
                               0,
                               ErrlEntry::ADD_SW_CALLOUT);
        saveEarlyError( l_errl->eid(), nullptr );
        errlCommit(l_errl, SBEIO_COMP_ID);
    }
}

/**
 * @brief  Destructor
 **/
SbePsu::~SbePsu()
{
    commonDestructor();
}

void* SbePsu::allocatePage( size_t i_pageCount )
{
    return malloc(i_pageCount*PAGESIZE);
}

void SbePsu::freePage(void*  i_page)
{
    free(i_page);
}

/**
 * @brief allocates buffer and sets ffdc address for the proc
 */

errlHndl_t SbePsu::allocateFFDCBuffer(TARGETING::Target * i_target)
{
    errlHndl_t l_errl = nullptr;

    uint32_t l_huid = TARGETING::get_huid(i_target);

    // Only setup our pointer once
    if(iv_ffdcPackageBuffer.find(i_target) == iv_ffdcPackageBuffer.end())
    {
        uint64_t l_instance = i_target->getAttr<ATTR_HBRT_HYP_ID>();

        // Buffers should have been allocated by IPL code
        uint64_t l_sbeFfdcAddr = g_hostInterfaces->get_reserved_mem(
                                           HBRT_RSVD_MEM__SBE_FFDC,
                                           l_instance);

        i_target->setAttr<TARGETING::ATTR_SBE_FFDC_ADDR>(l_sbeFfdcAddr);

        if(l_sbeFfdcAddr == 0)
        {
            SBE_TRACF(ERR_MRK"HBRT_RSVD_MEM__SBE_FFDC reserved memory not configured for %d (%.8X)", l_instance, l_huid);
        }
        else
        {
            iv_ffdcPackageBuffer.insert(std::pair<TARGETING::Target *, void *>
                          (i_target, reinterpret_cast<void*>(l_sbeFfdcAddr)));
            SBE_TRACF("Using FFDC buffer %p for proc huid=0x%08lx", l_sbeFfdcAddr, l_huid);
        }
    }

    return l_errl;
}

} //end of namespace SBEIO
