/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemRrd.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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

/** @file prdfMemRrd.H */

#ifndef __prdfMemRrd_H
#define __prdfMemRrd_H

// Platform includes
#include <prdfMemEccAnalysis.H>
#include <prdfMemMark.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTdQueue.H>
#include <prdfMemExtraSig.H>
#include <prdfPlatServices.H>

namespace PRDF
{

  // Row repair format, per primary rank:
  // 32 bits per repair (Explorer):
  //     5 bits : DRAM position (x8: 0-9, x4: 0-19)
  //     3 bits : secondary rank (srank0-srank2)
  //     2 bits : bank group (bg1-bg0)
  //     3 bits : bank (b2-b0)
  //     18 bits: row (r17-r0)
  //     1 bit  : repair validity (0: invalid, 1: valid)
  //
  // 32 bits per repair (Odyssey):
  //     5 bits : DRAM position (x8: 0-9, x4: 0-19)
  //     3 bits : secondary rank (srank0-srank2)
  //     3 bits : bank group (bg2-bg0)
  //     2 bits : bank (b1-b0)
  //     18 bits: row (r17-r0)
  //     1 bit  : repair validity (0: invalid, 1: valid)


  /** @brief Structure for FFDC to track address data of rows */
  struct FfdcRrData
  {
      uint8_t prank;
      uint8_t srank;
      uint8_t bnkGrp;
      uint8_t bnk;
      uint32_t row;

      bool operator==( const FfdcRrData & i_data ) const
      {
          return ( this->prank == i_data.prank &&
                   this->srank == i_data.srank &&
                   this->bnkGrp == i_data.bnkGrp &&
                   this->bnk == i_data.bnk &&
                   this->row == i_data.row );
      }
  };

/** @brief Row Repair Deploy procedure. */
template<TARGETING::TYPE T>
class RrdEvent : public TdEntry
{
  public: // functions, structs

    /**
     * @brief Constructor
     * @param i_chip OCMB.
     * @param i_rank Rank reporting the chip mark.
     * @param i_mark Chip mark placed by hardware.
     * @param i_port The port reporting the chip mark.
     * @param i_deployedRr FFDC data for the deployed row repair
     */
    RrdEvent<T>( ExtensibleChip * i_chip, const MemRank & i_rank,
                 const MemMark & i_mark, const uint8_t& i_port,
                 FfdcRrData i_deployedRr ) :
        TdEntry(RRD_EVENT, i_chip, i_port, i_rank), iv_mark(i_mark),
        iv_deployedRr(i_deployedRr)
    {
        PRDF_ASSERT( nullptr != i_chip );
        PRDF_ASSERT( T == i_chip->getType() );
        PRDF_ASSERT( i_mark.isValid() );
    }

  public: // overloaded functions from parent class

    uint32_t nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

    uint32_t getKey() const
    { return MemRank(iv_rank.getMaster()).getKey(); } // Master rank only

  private: // functions

    /**
     * @brief  Does isolation for ECC attentions during each phase.
     * @param  i_eccAttns Mask of all currently active maintenance attentions.
     *                    See enum MaintEccAttns for values.
     * @param  io_sc      The step code data struct.
     * @param  o_done     True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t checkEcc( const uint32_t & i_eccAttns,
                       STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );
    /**
     * @brief  Called in the last phase of the procedure to determine if the
     *         row repair was successfully deployed.
     * @param  io_sc      The step code data struct.
     * @param  o_done     True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t verifyRowRepair( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

    /**
     * @brief  Do analysis based on the current phase.
     * @param  io_sc  The step code data struct.
     * @param  o_done True if the procedure is complete or has aborted.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t analyzePhase( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done );

    /**
     * @brief  Starts the appropriate maintenance command for each phase of the
     *         procedure.
     * @pre    iv_phase must be set appropriately before calling this function.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    template <mss::mc_type MC>
    uint32_t startCmd();

    /**
     * @brief  Starts the next phase of the procedure.
     * @param  io_sc  The step code data struct.
     * @post   iv_phase will be updated appropriately per design.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    uint32_t startNextPhase( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief Gathers all data on the deployed row repair and uninitialized
     *        rows that have been found to add to log.
     * @param  io_sc  The step code data struct.
     */
    void addFfdc(STEP_CODE_DATA_STRUCT & io_sc);

  private: // instance variables

    const MemMark iv_mark;  ///< The chip mark from hardware.

    // The following variables are used solely for FFDC
    FfdcRrData iv_deployedRr; ///< The row repair that was deployed
    std::vector<FfdcRrData> iv_uninitRows; ///< Uninitialized rows found
};

//##############################################################################
//                              Utility Functions
//##############################################################################

  /**
   * @brief  Returns the address information of a row in FfdcRrData format
   * @param  i_ocmb An OCMB target
   * @param  i_addr The address
   * @return A FfdcRrData structure with the information of the input address.
   */
FfdcRrData getRrdFfdc(TARGETING::TargetHandle_t i_ocmb, const MemAddr & i_addr);

} // end namespace PRDF

#endif // __prdfMemRrd_H
