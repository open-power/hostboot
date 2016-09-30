/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTps_rt.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

/** @file prdfMemTps_rt.H */

#ifndef __prdfMemTps_rt_H
#define __prdfMemTps_rt_H

// Platform includes
#include <prdfMemTdQueue.H>

namespace PRDF
{

// Only implement specializations of TpsEvent.
template<TARGETING::TYPE T> class TpsEvent;

// TODO: RTC 136126 Actual implementation of this procedure will be done later.
/** @brief Two-Phase Scrub procedure for MCA (RT only). */
template <>
class TpsEvent<TARGETING::TYPE_MCA> : public TdEntry
{
  public: // functions

    /** @brief Constructor */
    TpsEvent<TARGETING::TYPE_MCA>( ExtensibleChip * i_chip, MemRank i_rank ) :
        TdEntry(TPS_EVENT, i_chip, i_rank)
    {}

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

};

// TODO: RTC 157888 Actual implementation of this procedure will be done later.
/** @brief Two-Phase Scrub procedure for MBA (RT only). */
template <>
class TpsEvent<TARGETING::TYPE_MBA> : public TdEntry
{
  public: // functions

    /** @brief Constructor */
    TpsEvent<TARGETING::TYPE_MBA>( ExtensibleChip * i_chip, MemRank i_rank ) :
        TdEntry(TPS_EVENT, i_chip, i_rank)
    {}

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

};

} // end namespace PRDF

#endif // __prdfMemTps_rt_H

