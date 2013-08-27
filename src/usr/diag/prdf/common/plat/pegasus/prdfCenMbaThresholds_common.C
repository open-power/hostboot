/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaThresholds_common.C $ */
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

/** @file  prdfCenMbaThresholds_common.C
 *  @brief Utility functions used to get specific Centaur thresholds.
 */

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfMfgThresholds.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfPlatServices.H>

// Pegasus includes
#include <prdfCenMbaThresholds.H>
#include <prdfCenMemUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

int32_t getMnfgMemCeTh( ExtensibleChip * i_mbaChip, const CenRank & i_rank,
                        uint16_t & o_cePerDram, uint16_t & o_cePerHalfRank,
                        uint16_t & o_cePerDimm )
{
    #define PRDF_FUNC "[getMnfgMemCeTh] "

    int32_t o_rc = SUCCESS;

    do
    {
        // Get base threshold ( 2GB ).
        uint8_t baseTh = getMnfgCeTh();

        // A base threhold of 0 indicates there should be no thresholding.
        if ( 0 == baseTh )
        {
            o_cePerDram = o_cePerHalfRank = o_cePerDimm =
                                    MfgThresholdFileCommon::INFINITE_LIMIT_THR;
            break;
        }

        // Get DRAM size
        uint8_t size = 0;
        o_rc = MemUtils::getDramSize( i_mbaChip, size );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "MemUtils::getDramSize() failed" );
            break;
        }

        // Get number of ranks per DIMM select.
        uint8_t rankCount = getRanksPerDimm( i_mbaChip->GetChipHandle(),
                                             i_rank.getDimmSlct() );
        if ( 0 == rankCount )
        {
            PRDF_ERR( PRDF_FUNC "PlatServices::getRanksPerDimm() failed" );
            o_rc = FAIL; break;
        }

        // Get number of allowed CEs.
        uint8_t baseAllowed = baseTh - 1;

        // Calculate CEs per DRAM.
        //   The DRAM size is in MBAXCR[6:7], where 0 = 2Gb, 1 = 4Gb, 2 = 8Gb,
        //   and 3 = 16 Gb. So the allowed CEs per DRAM can be calculated with
        //   the following:
        //         perDram = base * 2^(MBAXCR[6:7]+1) * (9/16)
        //     or, perDram = (base << MBAXCR[6:7]+1)  * (9/16)
        uint32_t computeBase = (baseAllowed << (size+1)) * 9;
        o_cePerDram = (computeBase + 8) / 16;

        // Calculate CEs per DIMM.
        o_cePerDimm = ((computeBase * (2 + rankCount)) + 8) / 16;

        // Calculate CEs per half-rank.
        // Same as perDimm where rankCount is 1;
        o_cePerHalfRank = ((computeBase * (2 + 1)) + 8) / 16;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

} // end namespace PRDF

