/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaAddress.H $   */
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

#ifndef PRDF_CEN_MBA_ADDRESS_H
#define PRDF_CEN_MBA_ADDRESS_H
#include <prdf_types.h>

/** @file  prdfCenMbaAddress.H
 *  @brief General utilities to read, modify, and write the memory controller's
 *         address registers (MCMACA, MCMEA, MCRADR, MCRADRSDUE). Also includes
 *         the CenMbaRank class.
 */

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

namespace PRDF
{
// FIXME :  via RTC 65231
// Needs to revisit this file
// There will be changes specific to P8 Addressing scheme
// Currently This file has just skeleton code
//------------------------------------------------------------------------------
//  Class CenMbaRank
//------------------------------------------------------------------------------

/**
 * @brief Container for a memory rank.
 */
class CenMbaRank
{
  public: // constructor

    /**
     * @brief Default constructor
     */
    CenMbaRank() {};

    /**
     * @brief  convert internal data structure to rank number
     * @return rank number
     */
    uint8_t toUint8() const;
};

/**
 * @brief Simple container for a memory address.
 */
class CenMbaAddr
{
  public:

    /** Starting with P7 DD2.0 each memory read error (MCRADR, MCRADRSDUE), or
     *  maintenance command stopped by an error (MCMACA) will have a tag to
     *  identify which type of error occured. */
    enum AttnType
    {
        UNKNOWN,      ///< Unknown attention (default for DD1.0)
        CE,          ///< CE
        READ_INT_UE,  ///< Read-intermittent UE
        UE_WITH_CM,   ///< Fast decoder UE fixed by a chip mark
        SLOW_DEC_UE,  ///< Slow decoder UE
        MIRROR_SD_UE, ///< Mirrored slow decoder UE
    };

    /** @brief Default constructor. */
    CenMbaAddr() {};

    /**
     * @return rank class reference
     */
    const CenMbaRank& getRank() const { return iv_rank; };

  private:
    CenMbaRank iv_rank;          ///< See class CenMbaRank
};

} //namespace PRDF
#endif /* PRDF_CEN_MBA_ADDRESS_H */

