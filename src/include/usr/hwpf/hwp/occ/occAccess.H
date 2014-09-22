/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/occ/occAccess.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef OCCACCESS_H_
#define OCCACCESS_H_

#include <config.h>
#include <errl/errlentry.H>
#include <targeting/common/commontargeting.H>
#include <fapi.H>

#ifdef CONFIG_HTMGT
namespace HBOCC
{

    /**
     * @brief Read OCC SRAM
     *
     * @param[in]     i_pTarget   PROC or OCC target pointer
     * @param[in]     i_addr      OCI Address to be used for the operation
     * @param[in,out] io_dataBuf  Reference to data buffer
     * @return errlHndl_t   Error log if operation failed
     */
    errlHndl_t readSRAM(const TARGETING::Target*i_pTarget,
                             const uint32_t i_addr,
                             ecmdDataBufferBase & io_dataBuf);

    /**
     * @brief Write OCC SRAM
     *
     * @param[in]     i_pTarget   PROC or OCC target pointer
     * @param[in]     i_addr      OCI Address to be used for the operation
     * @param[in]     i_dataBuf   Reference to data buffer
     * @return errlHndl_t   Error log if operation failed
     */
    errlHndl_t writeSRAM(const TARGETING::Target*i_pTarget,
                              const uint32_t i_addr,
                              ecmdDataBufferBase & io_dataBuf);

    /**
     * @brief Write OCC Circular Buffer
     *
     * @param[in]     i_pTarget   PROC or OCC target pointer
     * @param[in]     i_dataBuf   Reference to data buffer
     * @return errlHndl_t   Error log if operation failed
     */
    errlHndl_t writeCircularBuffer(const TARGETING::Target*i_pTarget,
                              ecmdDataBufferBase & i_dataBuf);

} //end OCC namespace
#endif // CONFIG_HTMGT

#endif
