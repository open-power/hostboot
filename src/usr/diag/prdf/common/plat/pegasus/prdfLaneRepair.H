/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfLaneRepair.H $      */
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
#ifndef _PRDFLANEREPAIR_H
#define _PRDFLANEREPAIR_H

/** @file  prdfLaneRepair.H
 *  @brief Common Lane Repair code for Lane Spared, Spares Exceeded, and
 *         Too Many Bus Errors conditions.
 */

#include<iipconst.h>
#include <targeting/common/target.H>

namespace PRDF
{

class ExtensibleChip;
struct STEP_CODE_DATA_STRUCT;

namespace LaneRepair
{
    /**
     * @brief Handles a Lane Repair Event
     * @param i_chip    Chip that detected the lane repair event
     * @param i_busType Bus connection type (X,A, MEMBUF, or MCS)
     * @param i_busPos  Bus position
     * @param i_sc      The step code data struct.
     * @param i_spareDeployed  True if FIR bit indicates a spare was deployed
     * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleLaneRepairEvent (ExtensibleChip * i_chip,
                                   TARGETING::TYPE i_busType,
                                   uint32_t i_busPos,
                                   STEP_CODE_DATA_STRUCT & i_sc,
                                   bool i_spareDeployed);

    // Utility functions for secondary FIR bits

    /**
     * @brief clean up secondary FIR bits ( MBI/MCIFIR bit 10 )
     * @param i_chip    Chip that detected the lane repair event
     * @param i_busType Bus connection type (X,A, MEMBUF, or MCS)
     * @param i_busPos  Bus position
     * @note  This will only clear FIR bits if spare deploy attention is present
     *        on DMI bus. It does not check for spare deployed  attention type
     *        Calling fucntion should make ensure that.
     * @return  Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t cleanupSecondaryFirBits(  ExtensibleChip * i_chip,
                       TARGETING::TYPE i_busType,
                       uint32_t i_busPos );

    /**
     * @brief Checks if spare bit is set for DMI Bus.
     * @param i_mcsChip    MCS chip.
     * @param i_mbChip    Membuf chip.
     * @return  True if spare bit is set false otherwise.
     * @note This function will check both ends of DMI bus to check
     *       if spare deployed attention is raised on any side.
     */
    bool isSpareBitOnDMIBus( ExtensibleChip * i_mcsChip,
                             ExtensibleChip * i_mbChip );

} // end namespace LaneRepair
} // end namespace PRDF

#endif /* _PRDFLANEREPAIR_H */
