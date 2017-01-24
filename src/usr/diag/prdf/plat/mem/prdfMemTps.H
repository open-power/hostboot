/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTps.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

/** @file prdfMemTps.H */

#ifndef __prdfMemTps_H
#define __prdfMemTps_H

// Platform includes
#include <prdfMemTdQueue.H>

namespace PRDF
{

/** @brief Two-Phase Scrub procedure. */
template <TARGETING::TYPE T>
class TpsEvent : public TdEntry
{
  public: // functions

    /**
     * @brief Constructor
     * @param i_chip MCA or MBA.
     * @param i_rank Target rank.
     * @param i_ban  True to ban all subsequent requests for TPS on this rank.
     */
    TpsEvent<T>( ExtensibleChip * i_chip, MemRank i_rank, bool i_ban = false ) :
        TdEntry(TPS_EVENT, i_chip, i_rank)
    {}

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

};

} // end namespace PRDF

#endif // __prdfMemTps_H

