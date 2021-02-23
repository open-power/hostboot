/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemConst.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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

#ifndef __prdfMemConst_H
#define __prdfMemConst_H

/** @file prdfMemConst.H */

namespace PRDF
{

enum
{
    DIMM_SLCT_PER_PORT = 2,

    MASTER_RANKS_PER_DIMM_SLCT  = 4,
    SLAVE_RANKS_PER_MASTER_RANK = 8,

    MASTER_RANKS_PER_PORT = DIMM_SLCT_PER_PORT * MASTER_RANKS_PER_DIMM_SLCT,

    SYMBOLS_PER_RANK  = 72,
    DQS_PER_DIMM      = 72,
    OCMB_DQS_PER_DIMM = 80,

    OCMB_SPARE_DQ_START = 40,

    BYTES_PER_DIMM   = 9,
    NIBBLES_PER_DIMM = 18,

    DQS_PER_BYTE     = 8,
    DQS_PER_NIBBLE   = 4,

    MEM_DIMMS_PER_RANK     = 1,

    MEM_BYTES_PER_RANK     = BYTES_PER_DIMM   * MEM_DIMMS_PER_RANK,
    MEM_NIBBLES_PER_RANK   = NIBBLES_PER_DIMM * MEM_DIMMS_PER_RANK,

    MEM_SYMBOLS_PER_BYTE   = SYMBOLS_PER_RANK / MEM_BYTES_PER_RANK,
    MEM_SYMBOLS_PER_NIBBLE = SYMBOLS_PER_RANK / MEM_NIBBLES_PER_RANK,

    MEM_DQS_PER_SYMBOL     = DQS_PER_BYTE / MEM_SYMBOLS_PER_BYTE,
};

} // end namespace PRDF

#endif // __prdfMemConst_H

