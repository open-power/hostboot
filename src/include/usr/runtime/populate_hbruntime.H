/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/populate_hbruntime.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include <hdat/hdat.H>
#include <vector>
#include <utility>

namespace RUNTIME
{

/**
 *  @brief Get the next Reserved HB memory range and set all member variables
 *         of struct. Additionally trace out relevant parts of the struct
 * @param[in] i_type, HDAT Range type
 * @param[in] i_rangeId, HDAT Range ID [Frequently node ID, see hdatMsVpdRhbAddrRange_t]
 * @param[in] i_startAddr, Range Starting Address
 * @param[in] i_size, Size of address space to reserve
 * @param[in] i_label, Label String Ptr
 * @param[in] i_permission, HDAT permission type [default read/write]
 *
 * @return errlHndl_t, nullptr on success; otherwise errlog
 */
errlHndl_t setNextHbRsvMemEntry(const HDAT::hdatMsVpdRhbAddrRangeType i_type,
                                const uint16_t i_rangeId,
                                const uint64_t i_startAddr,
                                const uint64_t i_size,
                                const char* i_label,
                                const HDAT::hdatRhbPermType i_permission =
                                                            HDAT::RHB_READ_WRITE
                                );

/**
 *  @brief Map physical address to virtual
 *  @param[in]  i_addr Physical address
 *  @param[in]  i_size Size of block to be mapped, in bytes.
 *  @param[out] o_addr Virtual address
 *  @return Error handle if error
 */
errlHndl_t mapPhysAddr(uint64_t i_addr, size_t i_size, uint64_t& o_addr);

/**
 *  @brief Unmap virtual address block
 *  @param[in]  i_addr Virtual address
 *  @return Error handle if error
 */
errlHndl_t unmapVirtAddr(uint64_t i_addr);

/**
 *  @brief Pre verify Pnor sections and load into HB reserved memory
 *
 *  @param[in] i_sec - pnor section to pre-verify and load
 *  @param[in] i_secHdrExpected - Indicates if pnor section is expected to have
 *                                a secure header.
 *                              e.g. RINGOVD currently never has a secure header
 *
 *  @return Error handle if error
 */
errlHndl_t hbResvLoadSecureSection (const PNOR::SectionId i_sec,
                                    const bool i_secHdrExpected);

} // End of Namespace