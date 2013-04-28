/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenDqBitmap.H $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

/** @file  prdfCenDqBitmap.H */

#ifndef __prdfCenDqBitmap_H
#define __prdfCenDqBitmap_H

#include <prdfPlatServices.H>

#include <prdfCenAddress.H>
#include <prdfCenConst.H>

namespace PRDF
{

class CaptureData;

/**
 * @brief Container for DIMM's Centaur DQ bitmap.
 */
class CenDqBitmap
{
  public: // constructors

    /** @brief Default constructor */
    CenDqBitmap()
    {
        memset( iv_data, 0x00, sizeof(iv_data) );
    }

    /** @brief Constructor from components */
    CenDqBitmap( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
           const uint8_t (&i_d)[PORT_SLCT_PER_MBA][DIMM_DQ_RANK_BITMAP_SIZE] ) :
        iv_mba(i_mba), iv_rank(i_rank)
    {
        memcpy( iv_data, i_d, sizeof(iv_data) );
    }

  public: // functions

    /**
     * @brief  Queries the given port to determine if there are any bad DQs
     *         present.
     * @param  i_portSlct The target port.
     * @param  o_badDqs   TRUE if there are bad DQS present the given port,
     *                    FALSE otherwise.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t badDqs( uint8_t i_portSlct, bool & o_badDqs ) const;

    /**
     * @brief  Sets the specified Centaur DQ.
     * @param  i_dq       The target Centaur DQ.
     * @param  i_portSlct The target port.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setDq( uint8_t i_dq, uint8_t i_portSlct );

    /**
     * @brief  Sets the specified symbol.
     * @param  i_symbol The target symbol.
     * @param  i_pins   Optional 2-bit value of the symbol's pins. The default
     *                  is to set both pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setSymbol( uint8_t i_symbol, uint8_t i_pins = 0x3 );

    /**
     * @brief  Sets the specified DRAM.
     * @param  i_symbol A symbol on the target DRAM.
     * @param  i_pins   Optional 8-bit (x8 mode) or 4-bit (x4 mode) value of the
     *                  DRAM's pins. The default is to set all pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setDram( uint8_t i_symbol, uint8_t i_pins = 0xff );

    /**
     * @brief  Sets the DRAM spare on the specified port.
     * @param  i_portSlct The target port.
     * @param  i_pins     Optional 8-bit (x8 mode) or 4-bit (x4 mode) value of
     *                    the DRAM's pins. The default is to set all pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setDramSpare( uint8_t i_portSlct, uint8_t i_pins = 0xff );

    /**
     * @brief  Sets the ECC spare on the specified port (x4 mode only).
     * @param  i_portSlct The target port.
     * @param  i_pins     Optional 2-bit value of the symbol's pins. The default
     *                    is to set both pins.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t setEccSpare( uint8_t i_pins );

    /**
     * @brief  Queries for DRAM spare status.
     * @param  i_portSlct  The target port.
     * @param  o_available TRUE if the spare is available, FALSE if it is used.
     * @return Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t isDramSpareAvailable( uint8_t i_portSlct, bool & o_available );

    /**
     * @brief Adds the bitmaps for both ports to the capture data.
     * @param o_cd Capture data struct.
     */
    void getCaptureData( CaptureData & o_cd ) const;

    /** @return A reference to the data array. */
    const uint8_t (&getData()const)[PORT_SLCT_PER_MBA][DIMM_DQ_RANK_BITMAP_SIZE]
    {
        return iv_data;
    }

  private: // instance variables

    TARGETING::TargetHandle_t iv_mba; ///< Target MBA
    CenRank iv_rank;                  ///< Target rank

    /** A bitmap of all bad DQs for each port. */
    uint8_t iv_data[PORT_SLCT_PER_MBA][DIMM_DQ_RANK_BITMAP_SIZE];
};

} // end namespace PRDF

#endif // __prdfCenDqBitmap_H

