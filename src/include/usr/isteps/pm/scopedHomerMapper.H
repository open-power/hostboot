/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/pm/scopedHomerMapper.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef _SCOPED_HOMER_MAPPER
#define _SCOPED_HOMER_MAPPER

#include <targeting/common/target.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>

/**
 * @file scopedHomerMapper.H
 *
 * @brief Contains the declaration of the ScopedHomerMapper class and its
 *        members. The class' function is to map the HOMER space into
 *        virtual memory for the lifetime of the ScopedHomerMapper object.
 *        When the object goes out of scope on PHYP systems, the virtual
 *        space is unmapped/released.
 */

namespace HBPM
{

/**
 * @brief ScopedHomerMapper class. The purpose of the class is to map the HOMER
 *        space into virtual memory for the duration of the ScompedHomerMapper
 *        object. On PHYP systems, the virtual memory is unmapped/released when
 *        an object of this class goes out of scope. The unmapping of memory
 *        occurs in the destructor.
 */
class ScopedHomerMapper
{
public:
    /**
     * @brief Parameterized constructor. The member iv_proc is associated with
     *        the input proc.
     *
     * @param[in] i_proc the input proc to map HOMER space for. Must not be
     *            nullptr and must be of TYPE_PROC; otherwise the constructor
     *            asserts.
     */
    ScopedHomerMapper(TARGETING::Target* i_proc) :
        iv_proc(i_proc), iv_mapped(false), iv_homerVirtAddr(0)
    {
        assert(i_proc != nullptr, "ScopedHomerMapper: i_proc is nullptr!");
        assert(i_proc->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC,
               "ScopedHomerMapper: i_proc must be of TYPE_PROC");
        iv_homerPhysAddr = i_proc->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();
    }

    /**
     * @brief Default destructor. On PHYP systems the destructor unmaps the
     *        HOMER area (if previously mapped) from the virtual space.
     */
    ~ScopedHomerMapper();

    /**
     * @brief The member function that maps the HOMER space associated with the
     *        internal proc member to virtual space. This function sets up
     *        appropriate HOMER attribute(s).
     *
     * @return nullptr on success; non-nullptr on error
     */
    errlHndl_t map();

    /**
     * @brief The member function that unmaps the HOMER space associated with
     *        the internal proc from virtual space. The appropriate HOMER
     *        attribute(s) is(are) reset to zero.
     *
     * @return nullptr on success; non-nullptr on error.
     */
    errlHndl_t unmap();

    /**
     * @brief Get the internal proc target.
     *
     * @return iv_proc.
     */
    TARGETING::Target* getProc() const;

    /**
     * @brief Get the HOMER virtual address associated with the internal proc.
     *
     * @return iv_homerVirtAddr.
     */
    uint64_t getHomerVirtAddr() const;

    /**
     * @brief Get the HOMER physical address associated with the internal proc.
     * @note The physical address may be updated by the call to map().
     *
     * @return HOMER Physical address associated with the internal proc.
     */
    uint64_t getHomerPhysAddr() const;

    // Disable copy constructor and copy assignement.
    ScopedHomerMapper(const ScopedHomerMapper& i_mapper) = delete;
    ScopedHomerMapper& operator=(const ScopedHomerMapper& i_rhs) = delete;

private:

#ifdef __HOSTBOOT_RUNTIME
    /**
     * @brief Fetch the HOMER and OCC common physical addresses. No-op in
     *        non-runtime environments.
     *
     * @param[out] o_homer the HOMER physical address.
     * @param[out] o_occCommon the OCC Common physical address.
     * @return nullptr on success; non-nullptr on error.
     */
    errlHndl_t getRuntimePMAddresses(uint64_t& o_homer,
                                     uint64_t& o_occCommon) const;
#endif

    TARGETING::Target* iv_proc; // The proc on which to operate
    bool iv_mapped;             // Whether HOMER has been mapped for this proc
    uint64_t iv_homerVirtAddr;  // The virtual address where HOMER has been
                                // mapped
    uint64_t iv_homerPhysAddr;  // The physical address of the HOMER region
};

} // end namespace HBPM
#endif //_SCOPED_HOMER_MAPPER
