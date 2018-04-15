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

#endif // Hostboot Runtime only

} // end namespace MemDbUtils

} // end namespace PRDF

#endif // prdfMemDbUtils_H
