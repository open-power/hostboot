/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemScrubUtils.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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

/** @file  prdfMemScrubUtils.H
 *  @brief Define the functionality necessary to start initial background scrub
 */

#ifndef __prdfMemScrubUtils_H
#define __prdfMemScrubUtils_H

#include <iipconst.h>
#include <iipServiceDataCollector.h>
#include <iipSystem.h>

namespace PRDF
{

/** Simple container to keep track of the number of time a scrub command has
 *  been resumed. */
class ScrubResumeCounter
{
  public:
    void reset()      { iv_count = 0;                      }
    void inc()        { if ( 255 != iv_count ) iv_count++; }
    bool atTh() const { return 16 <= iv_count;             }
  private:
    uint8_t iv_count = 0;
};

/**
 * @brief  Clears the command complete and WAT workaround attentions.
 * @param  i_chip OCMB.
 * @return Non-SUCCESS on SCOM failures, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t clearCmdCompleteAttn( ExtensibleChip * i_chip );

/**
 * @brief  Clears the maintenance ECC counters.
 * @param  i_chip OCMB.
 * @return Non-SUCCESS on SCOM failures, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t clearEccCounters( ExtensibleChip * i_chip );

/**
 * @brief  Clears the maintenance ECC FIRs.
 * @param  i_chip OCMB.
 * @return Non-SUCCESS on SCOM failures, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t clearEccFirs( ExtensibleChip * i_chip );

/**
 * @brief  Wrapper function that calls clearEccCounters(), clearEccFirs() and
 *         clearCmdCompleteAttn().
 * @param  i_chip OCMB.
 * @return Non-SUCCESS on SCOM failures, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t prepareNextCmd( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[prepareNextCmd] "

    uint32_t o_rc = SUCCESS;

    do
    {
        o_rc = clearEccCounters<T>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearEccCounters<T>(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        o_rc = clearEccFirs<T>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearEccFirs<T>(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        o_rc = clearCmdCompleteAttn<T>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearCmdCompleteAttn<T>(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

/** @brief Contains all supported ECC attentions. Each enum is used in a mask,
 *         so the value of each enum must be unique and disjoint. */
enum MaintEccAttns
{
    MAINT_NO_ERROR      = 0,    ///< No ECC errors found

    MAINT_MPE           = 0x8000, ///< Chip mark placed
    MAINT_SCE           = 0x4000, ///< CE on symbol mark
    MAINT_MCE           = 0x2000, ///< CE on chip mark
    MAINT_UE            = 0x1000, ///< UE
    MAINT_HARD_NCE_ETE  = 0x0800, ///< Hard NCE threshold exceeed
    MAINT_SOFT_NCE_ETE  = 0x0400, ///< Soft NCE threshold exceeed
    MAINT_INT_NCE_ETE   = 0x0200, ///< Intermittent NCE threshold exceeed
    MAINT_RCE_ETE       = 0x0100, ///< Retry CE threshold exceeed

    MAINT_IUE           = 0x0080, ///< Intermittent UE
    MAINT_IMPE          = 0x0040, ///< Intermittent chip mark

    // Maintenance CEs
    MAINT_NCE           = 0x0020, ///< CE
    MAINT_TCE           = 0x0010, ///< CE on two symbols

    MAINT_SUE           = 0x0008, ///< Maint SUE
};

/**
 * @brief  Checks for all currently active maintenance attentions.
 * @param  i_chip     OCMB.
 * @param  o_eccAttns Mask of all currently active maintenance attentions. See
 *                    enum MaintEccAttns for values.
 * @return Non-SUCCESS on SCOM failures, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t checkEccFirs( ExtensibleChip * i_chip, uint32_t & o_eccAttns );

/**
 * @param  i_chip              OCMB.
 * @param  i_rangeType         See enum AddrRangeType.
 * @param  o_stoppedOnLastAddr True, if the current maintenance command stopped
 *                             on the last address of the given rank range.
 *                             False, otherwise.
 * @param  i_rowRepair         This is a special case during VCM procedures when
 *                             row repair is enabled. It is intended to be used
 *                             to determine if the MCE happened on the last
 *                             row of the address range. When true, only the
 *                             rank and the row addresses are compared.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t didCmdStopOnLastAddr( ExtensibleChip * i_chip,
                               AddrRangeType i_rangeType,
                               bool & o_stoppedOnLastAddr,
                               bool i_rowRepair = false );

} //end namespace PRDF

#endif // __prdfMemScrubUtils_H
