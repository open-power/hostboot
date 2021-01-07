/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/scopedHomerMapper.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
#include <isteps/pm/scopedHomerMapper.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <targeting/targplatutil.H>
#include <runtime/interface.h>
#include <isteps/pm/pm_common_ext.H>
#include "pm_common.H"

/**
 * @file scopedHomerMapper.C
 *
 * @brief Contains the definitions of the ScopedHomerMapper members.
 */

HBPM::ScopedHomerMapper::~ScopedHomerMapper()
{
#ifdef __HOSTBOOT_RUNTIME
    if(TARGETING::is_phyp_load())
    {
        errlHndl_t l_errl = unmap();
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"ScopedHomerMapper::~ScopedHomerMapper: could not unmap HOMER!");
            errlCommit(l_errl, ISTEP_COMP_ID);
        }
    }
#endif
}

TARGETING::Target* HBPM::ScopedHomerMapper::getProc() const
{
    return iv_proc;
}

uint64_t HBPM::ScopedHomerMapper::getHomerPhysAddr() const
{
    return iv_homerPhysAddr;
}

uint64_t HBPM::ScopedHomerMapper::getHomerVirtAddr() const
{
    return iv_homerVirtAddr;
}

errlHndl_t HBPM::ScopedHomerMapper::map()
{
    errlHndl_t l_errl = nullptr;
    uint64_t l_homerPhysAddr = 0;

    do {
    if(iv_mapped)
    {
        // HOMER already mapped - nothing to do.
        break;
    }

    if(iv_proc->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>() != 0)
    {
        // Someone's already mapped the HOMER virt (may have been done
        // recursively), so we don't need to map it again here.
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
               INFO_MRK"ScopedHomerMapper::map: HOMER virt is already mapped (potentially by another instance of ScopedHomerMapper).");
        // Set the internal virt addr so that it's still fetchable via
        // getHomerVirtAddr()
        iv_homerVirtAddr = iv_proc->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>();
        break;
    }

    // PHYP is driving the locations of HOMER and OCC Common physical addresses,
    // so we need to interrogate the PHYP interface to get them.
    if(TARGETING::is_phyp_load())
    {
#ifdef __HOSTBOOT_RUNTIME
        uint64_t l_occCommonPhysAddr = 0;

        l_errl = getRuntimePMAddresses(l_homerPhysAddr, l_occCommonPhysAddr);
        if(l_errl)
        {
            break;
        }

        iv_proc->setAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>(l_homerPhysAddr);
        TARGETING::UTIL::assertGetToplevelTarget()->
        setAttr<TARGETING::ATTR_OCC_COMMON_AREA_PHYS_ADDR>(l_occCommonPhysAddr);
#else
        // During IPL-time, we rely on the attribute to tell us what HOMER
        // phys address is, even in PHYP load.
        l_homerPhysAddr = iv_proc->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();
#endif
    } // is_phyp_load
    else
    {
        l_homerPhysAddr = iv_proc->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();
    }

    void* l_homerVaddr = HBPM::convertHomerPhysToVirt(iv_proc, l_homerPhysAddr);
    if(l_homerVaddr)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  INFO_MRK"ScopedHomerMapper::map: mapped HOMER virtual address (%p) for proc HUID 0x%08x",
                  l_homerVaddr,
                  TARGETING::get_huid(iv_proc));
        iv_homerVirtAddr = reinterpret_cast<uint64_t>(l_homerVaddr);
        iv_mapped = true;
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"ScopedHomerMapper::map: Could not map HOMER for proc HUID 0x%08x",
                  TARGETING::get_huid(iv_proc));
        /*@
         * @errortype
         * @reasoncode ISTEP::RC_COULD_NOT_MAP_HOMER
         * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid   ISTEP::MOD_SCOPED_HOMER_MAPPER_MAP
         * @userdata1  The physical address of HOMER region
         * @userdata2  The HUID of the proc
         * @devdesc    Mapping of HOMER region to virtual space failed
         * @custdesc   A host failure occurred
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        ISTEP::MOD_SCOPED_HOMER_MAPPER_MAP,
                                        ISTEP::RC_COULD_NOT_MAP_HOMER,
                                        l_homerPhysAddr,
                                        TARGETING::get_huid(iv_proc),
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(ISTEP_COMP_NAME);
        iv_mapped = false;
        break;
    }

    iv_homerPhysAddr = l_homerPhysAddr;
    } while(0);

    return l_errl;
}

#ifdef __HOSTBOOT_RUNTIME
errlHndl_t HBPM::ScopedHomerMapper::getRuntimePMAddresses(uint64_t& o_homer,
                                                    uint64_t& o_occCommon) const
{
    errlHndl_t l_errl = nullptr;
    do {
    if(INITSERVICE::spBaseServicesEnabled())
    {
        // On FSP systems, these will be supplied to us.
        o_homer = iv_proc->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();
        o_occCommon = TARGETING::UTIL::assertGetToplevelTarget()->
            getAttr<TARGETING::ATTR_OCC_COMMON_AREA_PHYS_ADDR>();

        // Error if either is not set
        if(o_homer == 0 || o_occCommon == 0)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"ScopedHomerMapper::getRuntimePMAddresses: Invalid HOMER and/or OCC Common physical addresses; HOMER phys: 0x%016lx, OCC Common phys: 0x%016lx",
                      o_homer, o_occCommon);
            /*@
             * @errortype
             * @reasoncode ISTEP::RC_INVALID_PM_ADDRESS
             * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid   ISTEP::MOD_GET_RUNTIME_PM_ADDRESSES
             * @userdata1  Provided HOMER Physical address
             * @userdata2  Provided OCC Common Physical Address
             * @devdesc    HOMER and/or OCC Common physical address is zero
             * @custdesc   A host failure occurred
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            ISTEP::MOD_GET_RUNTIME_PM_ADDRESSES,
                                            ISTEP::RC_INVALID_PM_ADDRESS,
                                            o_homer,
                                            o_occCommon,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(ISTEP_COMP_NAME);
        }
        break;
    }

    if(g_hostInterfaces->get_pm_complex_addresses == nullptr)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"ScopedHomerMapper::getRuntimePMAddresses: get_pm_complex_addresses is not provided!");
        /*@
         * @errortype
         * @reasoncode ISTEP::RC_PM_COMPLEX_ADDRESSES_NOT_FOUND
         * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid   ISTEP::MOD_GET_RUNTIME_PM_ADDRESSES
         * @userdata1  The HUID of the proc
         * @devdesc    get_pm_complex_addresses interface is not provided
         * @custdesc   A host failure occurred
         */
         l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       ISTEP::MOD_GET_RUNTIME_PM_ADDRESSES,
                                       ISTEP::RC_PM_COMPLEX_ADDRESSES_NOT_FOUND,
                                       TARGETING::get_huid(iv_proc),
                                       0,
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(ISTEP_COMP_NAME);
        break;
    }

    auto l_procChipId = iv_proc->getAttr<TARGETING::ATTR_HBRT_HYP_ID>();
    int l_rc = g_hostInterfaces->get_pm_complex_addresses(l_procChipId,
                                                          o_homer,
                                                          o_occCommon);
    if(l_rc)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"ScopedHomerMapper::getRuntimePMAddresses: get_pm_complex_addresses returned RC %d",
                  l_rc);
        /*@
         * @errortype
         * @reasoncode ISTEP::RC_BAD_INTERFACE_RETURN_CODE
         * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid   ISTEP::MOD_GET_RUNTIME_PM_ADDRESSES
         * @userdata1  The return code of the PHYP interface
         * @userdata2  The HUID of the proc
         * @devdesc    The get_pm_complex_addresses returned an error rc
         * @custdesc   A host failure occurred
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         ISTEP::MOD_GET_RUNTIME_PM_ADDRESSES,
                                         ISTEP::RC_BAD_INTERFACE_RETURN_CODE,
                                         l_rc,
                                         TARGETING::get_huid(iv_proc),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(ISTEP_COMP_NAME);
        break;
    }
    } while(0);
    return l_errl;
}
#endif

errlHndl_t HBPM::ScopedHomerMapper::unmap()
{
    errlHndl_t l_errl = nullptr;
    do {
    if(iv_mapped && (iv_homerVirtAddr != 0))
    {
        void* l_pHomerVirtAddr = reinterpret_cast<void*>(iv_homerVirtAddr);
        int l_rc = HBPM_UNMAP(l_pHomerVirtAddr);
        if(l_rc)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"ScopedHomerMapper::unmap: Could not unmap HOMER for proc HUID 0x%08x",
                      TARGETING::get_huid(iv_proc));
            /*@
             * @errortype
             * @reasoncode ISTEP::RC_COULD_NOT_UNMAP_HOMER
             * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid   ISTEP::MOD_SCOPED_HOMER_MAPPER_UNMAP
             * @userdata1  The HUID of the proc
             * @devdesc    Failed to unmap HOMER from the virtual space
             * @custdesc   A host failure occurred
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           ISTEP::MOD_SCOPED_HOMER_MAPPER_UNMAP,
                                           ISTEP::RC_COULD_NOT_UNMAP_HOMER,
                                           TARGETING::get_huid(iv_proc),
                                           0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(ISTEP_COMP_NAME);
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      INFO_MRK"ScopedHomerMapper::unmap: unmapped HOMER virtual space for proc HUID 0x%08x",
                      TARGETING::get_huid(iv_proc));
        }

        // Zero out the attribute even if there was an error
        uint64_t l_zero = 0;
        iv_proc->setAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>(l_zero);
        iv_mapped = false;
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  INFO_MRK"ScopedHomerMapper::unmap: HOMER is not mapped by this instance of ScopedHomerMapper; skipping unmapping.");
    }
    } while(0);
    return l_errl;
}
