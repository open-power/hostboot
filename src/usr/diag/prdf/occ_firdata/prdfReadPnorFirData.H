/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/prdfReadPnorFirData.H $         */
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

#ifndef __prdfReadPnorFirData_H
#define __prdfReadPnorFirData_H

#include <map>

#include <pnorData_common.h>
#include <prdfPlatServices.H>

namespace PRDF
{

typedef std::map<uint64_t, uint64_t> PnorRegMap;

typedef std::map<TARGETING::TargetHandle_t, PnorRegMap> PnorTrgtMap;

struct PnorFfdc
{
    uint8_t trgts; ///< Total number of target in the PNOR data.
    bool    full;  ///< True if the PNOR data was unable to capture all regs.

    PnorFfdc() : trgts(0), full(false) {}
    PnorFfdc( uint8_t t, bool f ) : trgts(t), full(f) {}
};

struct PnorTrgtFfdc
{
    uint16_t scomErrs; ///< Total number of SCOM error detected on this target

    PnorTrgtFfdc() : scomErrs(0) {}
    PnorTrgtFfdc(uint16_t s) : scomErrs(s) {}
};

typedef std::map<TARGETING::TargetHandle_t, PnorTrgtFfdc> PnorTrgtFfdcMap;

/** @brief  Read register data captured by the OCC in the event of a system
 *          checkstop.
 *  @param  o_validData True, if there the was a system checkstop and the OCC
 *                      stored valid data in the PNOR. False otherwise.
 *  @param  o_trgtMap   If the data if valid, a map containing the register
 *                      values for each target and address.
 *  @param  o_ffdc      PNOR FFDC data for debug.
 *  @param  o_trgtFfdc  PNOR target FFDC data for debug.
 *  @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
int32_t readPnorFirData( bool & o_validData, PnorTrgtMap & o_trgtMap,
                         PnorFfdc & o_ffdc, PnorTrgtFfdcMap & o_trgtFfdc );

/** @brief  Clears the OCC FIR data from the PNOR. This must be done after the
 *          checkstop analysis is complete so that analysis is not repeated on
 *          subsequent IPLs.
 *  @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
int32_t clearPnorFirData();

}; // end namespace PRDF

#endif // __prdfReadPnorFirData_H

