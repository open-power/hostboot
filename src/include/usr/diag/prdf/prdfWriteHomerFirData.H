/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/prdfWriteHomerFirData.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

#include <errl/errlentry.H>

namespace PRDF
{

// enum to determine what hardware is currently initialized
enum HwInitialized_t
{
    MASTER_PROC_CORE,         //master processor and master core
    ALL_PROC_MASTER_CORE,     //all processors and master core
    ALL_PROC_MEM_MASTER_CORE, //all processors, all memory, and master core
    ALL_HARDWARE              //all processors, all memory, and all cores
};

/** @brief  Writes register lists and hardware config in the HOMER data for
 *          the OCC to capture in the event of a system checkstop.
 *  @param  i_hBuf     SRAM pointer to the beginning of the HOMER data buffer.
 *  @param  i_hBufSize Total size of the HOMER data buffer.
 *  @return An error log on failure. NULL on success.
 */
errlHndl_t writeHomerFirData( uint8_t * i_hBuf, size_t i_hBufSize,
                              const HwInitialized_t i_curHw = ALL_HARDWARE );
}; // end namespace PRDF

