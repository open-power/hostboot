/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/diag/prdf/prdfPnorFirDataReader.H $           */
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

#ifndef __prdfPnorFirDataReader_H
#define __prdfPnorFirDataReader_H

#include <diag/prdf/prdfReadPnorFirData.H>

#include <errl/errlentry.H>

namespace PRDF
{

/**
 * @brief Container class to read FIR data information from PNOR.
 */
class PnorFirDataReader
{
  public:

    /**
     * @brief  Returns reference to singleton instance of the PnorFirDataReader.
     * @return The singleton reference.
     */
    static PnorFirDataReader & getPnorFirDataReader();

    /**
     * @brief  Reads the FIR data from PNOR and stores the register data.
     * @note   This must be called at the beginning of analysis. Otherwise,
     *         there will be no data for analysis.
     * @param  o_validData True, if the FIR data is valid and ready for
     *                     analysis. False, if there is nothing to analyze.
     * @return An error log if something failed. Otherwise, NULL.
     */
    errlHndl_t readPnor( bool & o_validData );

    /**
     * @brief  Clears any FIR data information out of the PNOR.
     * @note   This must be called at the end of analysis so that analysis is
     *         not repeated on subsequent IPLs.
     * @return An error log if something failed. Otherwise, NULL.
     */
    errlHndl_t clearPnor() const;

    /**
     * @brief  Does a getScom operation based on the data stored in PNOR.
     * @param  i_trgt SCOM target.
     * @param  i_addr SCOM address.
     * @param  o_val  Returned value for this target and address.
     */
    void getScom( TARGETING::TargetHandle_t i_trgt,
                  uint64_t i_addr, uint64_t & o_val ) const;

    /**
     * @brief  Does a putScom operation based on the data stored in PNOR.
     * @param  i_trgt SCOM target.
     * @param  i_addr SCOM address.
     * @param  i_val  Value to write to this target and address.
     */
    void putScom( TARGETING::TargetHandle_t i_trgt,
                  uint64_t i_addr, uint64_t i_val );

    /**
     * @brief Adds FFDC to the given error log.
     */
    void addFfdc( errlHndl_t io_errl ) const;

    /**
     * @brief Get IPL/Runtime state indicator
     * @return True if we were in IPL state, False if we were in runtime state
     */
    bool isIplState() const;

  private:

    PnorTrgtMap     iv_trgtRegMap;  ///< Register data for each target/address.
    PnorFfdc        iv_ffdc;        ///< High level FIR data FFDC.
    PnorTrgtFfdcMap iv_trgtFfdcMap; ///< FFDC for each FIR data target.

};

typedef Singleton<PnorFirDataReader> PnorFirData;

} // end namespace PRDF

#endif // __prdfPnorFirDataReader_H

