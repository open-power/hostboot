/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemDbUtils.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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

#ifndef prdfMemDbUtils_H
#define prdfMemDbUtils_H

#include <prdfCenMbaDataBundle.H>
#include <prdfP9McaDataBundle.H>

namespace PRDF
{

namespace MemDbUtils
{

//##############################################################################
//                                 Generic wrappers
//##############################################################################

/**
 * @brief  Generic wrapper to add an entry to the UE table.
 * @param  i_chip MCA or MBA.
 * @param  i_type UE table entry type.
 * @param  i_addr UE address.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
void addUeTableEntry( ExtensibleChip * i_chip, UE_TABLE::Type i_type,
                      const MemAddr & i_addr );

template<> inline
void addUeTableEntry<TARGETING::TYPE_MCA>( ExtensibleChip * i_chip,
                                           UE_TABLE::Type i_type,
                                           const MemAddr & i_addr )
{
    getMcaDataBundle(i_chip)->iv_ueTable.addEntry( i_type, i_addr );
}

template<> inline
void addUeTableEntry<TARGETING::TYPE_MBA>( ExtensibleChip * i_chip,
                                           UE_TABLE::Type i_type,
                                           const MemAddr & i_addr )
{
    getMbaDataBundle(i_chip)->iv_ueTable.addEntry( i_type, i_addr );
}

//##############################################################################
//                         Hostboot IPL/Runtime wrappers
//##############################################################################

#ifdef __HOSTBOOT_MODULE

/**
 * @brief  Generic wrapper to push a TdEntry to the Targeted Diagnostics queue.
 * @param  i_chip  MCA or MBA.
 * @param  i_entry The new TdEntry.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
void pushToQueue( ExtensibleChip * i_chip, TdEntry * i_entry );

template<> inline
void pushToQueue<TARGETING::TYPE_MCA>( ExtensibleChip * i_chip,
                                       TdEntry * i_entry )
{
    getMcaDataBundle(i_chip)->getTdCtlr()->pushToQueue( i_entry );
}

template<> inline
void pushToQueue<TARGETING::TYPE_MBA>( ExtensibleChip * i_chip,
                                       TdEntry * i_entry )
{
    getMbaDataBundle(i_chip)->getTdCtlr()->pushToQueue( i_entry );
}

#endif // Hostboot IPL/Runtime

//##############################################################################
//                          Hostboot IPL only wrappers
//##############################################################################

#if defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)

/**
 * @brief  Generic wrapper to get a pointer to the MemIplCeStats object from the
 *         data bundle of the given chip.
 * @param  i_chip MCA or MBA.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
MemIplCeStats<T> * getIplCeStats( ExtensibleChip * i_chip );

template<> inline
MemIplCeStats<TARGETING::TYPE_MCA> * getIplCeStats( ExtensibleChip * i_chip )
{
    return getMcaDataBundle(i_chip)->getIplCeStats();
}

template<> inline
MemIplCeStats<TARGETING::TYPE_MBA> * getIplCeStats( ExtensibleChip * i_chip )
{
    return getMbaDataBundle(i_chip)->getIplCeStats();
}

#endif // Hostboot IPL only

//##############################################################################
//                          Hostboot Runtime only wrappers
//##############################################################################

#if defined(__HOSTBOOT_MODULE) && defined(__HOSTBOOT_RUNTIME)

/**
 * @brief  Generic wrapper to tell the TD controller to process the next event
 *         in the TD queue.
 * @param  i_chip  MCA or MBA.
 * @param  io_sc   The step code data struct.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t handleTdEvent( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc );

template<> inline
uint32_t handleTdEvent<TARGETING::TYPE_MCA>( ExtensibleChip * i_chip,
                                             STEP_CODE_DATA_STRUCT & io_sc )
{
    return getMcaDataBundle(i_chip)->getTdCtlr()->handleTdEvent( io_sc );
}

template<> inline
uint32_t handleTdEvent<TARGETING::TYPE_MBA>( ExtensibleChip * i_chip,
                                             STEP_CODE_DATA_STRUCT & io_sc )
{
    return getMbaDataBundle(i_chip)->getTdCtlr()->handleTdEvent( io_sc );
}

/**
 * @brief Generic wrapper to tell the TD controller to ban TPS on a rank.
 * @param i_chip  MCA or MBA.
 * @param i_rank  The target slave rank.
 */
template<TARGETING::TYPE T>
void banTps( ExtensibleChip * i_chip, const MemRank & i_rank );

template<> inline
void banTps<TARGETING::TYPE_MCA>( ExtensibleChip * i_chip,
                                  const MemRank & i_rank )
{
    getMcaDataBundle(i_chip)->getTdCtlr()->banTps( i_chip, i_rank );
}

template<> inline
void banTps<TARGETING::TYPE_MBA>( ExtensibleChip * i_chip,
                                  const MemRank & i_rank )
{
    getMbaDataBundle(i_chip)->getTdCtlr()->banTps( i_chip, i_rank );
}

#endif // Hostboot Runtime only

} // end namespace MemDbUtils

} // end namespace PRDF

#endif // prdfMemDbUtils_H
