/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfMemoryMru.H $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2008,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/** @file prdfMemoryMru.H */

#ifndef __prdfMemoryMru_H
#define __prdfMemoryMru_H

#include <prdfCenAddress.H>
#include <prdfMemoryMruData.H>
#include <prdfPlatServices.H>
#include <prdfCenSymbol.H>

namespace PRDF
{

/**
 * @brief This is a container object that assists with callouts and FFDC for the
 *        mainstore memory subsystem. The intent is that it can show with the
 *        smallest possible granularity what part is failing (i.e. DIMM, rank,
 *        DRAM, a single pin on a DRAM, etc.).
 */
class MemoryMru
{
  public: // Constructors

    /** @brief Default contructor. */
    MemoryMru();

    /**
     * @brief Constructor from 32-bit representation of a memory MRU.
     * @param i_memMru A 32-bit representation of a memory MRU.
     */
    explicit MemoryMru( uint32_t i_memMru );

    /**
     * @brief Constructor for single DIMM callouts.
     * @param i_mbaTarget The MBA in which the error occurred.
     * @param i_rank      The rank in which the error occurred.
     * @param i_symbol    The symbol in which the error occurred.
     */
    MemoryMru( TARGETING::TargetHandle_t i_mbaTarget, const CenRank & i_rank,
               const CenSymbol & i_symbol );

    /**
     * @brief Constructor for special callouts.
     * @param i_mbaTarget      The MBA in which error has occured
     * @param i_rank           The rank in which the error occurred.
     * @param i_specialCallout See enum MemoryMruData::Callout.
     */
    MemoryMru( TARGETING::TargetHandle_t i_mbaTarget, const CenRank & i_rank,
               MemoryMruData::Callout i_specialCallout );

  public: // functions

    /** @return The 32-bit representation of this MemoryMru. */
    uint32_t toUint32() const { return iv_memMruMeld.u; }

    /** @return A list of targets that are represented by this MemoryMru. */
    TARGETING::TargetHandleList getCalloutList() const;

  private: // instance variables

    MemoryMruData::MemMruMeld iv_memMruMeld;

    TARGETING::TargetHandle_t iv_mbaTarget; ///< Target MBA.
    CenRank iv_rank;                        ///< Target rank
    MemoryMruData::Callout iv_special;      ///< See enum MemoryMruData::Callout
    CenSymbol iv_symbol; ///< Target symbol
};

} // end namespace PRDF

#endif // __prdfMemoryMru_H

