/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfOcmbDataBundle.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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

#ifndef __prdfOcmbDataBundle_H
#define __prdfOcmbDataBundle_H

/** @file  prdfOcmbDataBundle.H
 *  @brief Contains the data bundle for a P9 OCMB_CHIP object.
 */

// Framework includes
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfPlatServices.H>
#include <prdfMemCeTable.H>
#include <prdfMemUeTable.H>
#include <prdfOcmbAddrConfig.H>

#ifdef __HOSTBOOT_MODULE

#include <prdfMemScrubUtils.H>
#include <prdfMemTdFalseAlarm.H>
#include <prdfMemThresholds.H>
#include <prdfMemTdCtlr.H>

#ifndef __HOSTBOOT_RUNTIME
#include <prdfMemIplCeStats.H>
#endif

#endif // __HOSTBOOT_MODULE

namespace PRDF
{

/** @brief P9 OCMB data bundle. */
class OcmbDataBundle : public DataBundle
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_ocmbChip The OCMB chip.
     */
    explicit OcmbDataBundle( ExtensibleChip * i_ocmbChip ) :
        iv_chip(i_ocmbChip), iv_ceTable(i_ocmbChip), iv_ueTable(i_ocmbChip),
        iv_addrConfig(i_ocmbChip)
    {}

    /** @brief Destructor. */
    ~OcmbDataBundle()
    {
        #ifdef __HOSTBOOT_MODULE
            #ifdef __HOSTBOOT_RUNTIME
                delete iv_vcmFalseAlarmCounter;
                delete iv_tpsFalseAlarmCounter;
            #else // IPL only
                delete iv_iplCeStats;
            #endif
        delete iv_tdCtlr; iv_tdCtlr = nullptr;
        #endif // __HOSTBOOT_MODULE
    }

    // Don't allow copy or assignment.
    OcmbDataBundle( const OcmbDataBundle & ) = delete;
    const OcmbDataBundle & operator=( const OcmbDataBundle & ) = delete;

    #ifdef __HOSTBOOT_MODULE

    /** @return The Targeted Diagnostics controller. */
    MemTdCtlr<TARGETING::TYPE_OCMB_CHIP> * getTdCtlr()
    {
        if ( nullptr == iv_tdCtlr )
        {
            iv_tdCtlr = new MemTdCtlr<TARGETING::TYPE_OCMB_CHIP>{iv_chip};
        }

        return iv_tdCtlr;
    }

    /** @return The IMPE threshold counter. */
    VcmFalseAlarm * getImpeThresholdCounter()
    {
        if ( nullptr == iv_impeThresholdCounter )
        {
            iv_impeThresholdCounter = new VcmFalseAlarm(
                                           TimeBasedThreshold { getImpeTh() } );
        }

        return iv_impeThresholdCounter;
    }

    #ifdef __HOSTBOOT_RUNTIME

    /** @return The VCM false alarm counter. */
    VcmFalseAlarm * getVcmFalseAlarmCounter()
    {
        if ( nullptr == iv_vcmFalseAlarmCounter )
        {
            iv_vcmFalseAlarmCounter = new VcmFalseAlarm(
                       TimeBasedThreshold { 4, ThresholdResolution::ONE_DAY } );
        }

        return iv_vcmFalseAlarmCounter;
    }

    /** @return The TPS false alarm counter. */
    TpsFalseAlarm * getTpsFalseAlarmCounter()
    {
        if ( nullptr == iv_tpsFalseAlarmCounter )
        {
            iv_tpsFalseAlarmCounter = new TpsFalseAlarm(
                TimeBasedThreshold{ 3, ThresholdResolution::ONE_DAY } );
        }

        return iv_tpsFalseAlarmCounter;
    }

    #else // IPL only

    /** @return The IPL CE statistics object. */
    MemIplCeStats<TARGETING::TYPE_OCMB_CHIP> * getIplCeStats()
    {
        if ( nullptr == iv_iplCeStats )
        {
            iv_iplCeStats =
                new MemIplCeStats<TARGETING::TYPE_OCMB_CHIP>( iv_chip );
        }

        return iv_iplCeStats;
    }

    #endif

    #endif // __HOSTBOOT_MODULE

  private: // instance variables

    /** The OCMB chip associated with this data bundle. */
    ExtensibleChip * const iv_chip;

    #ifdef __HOSTBOOT_MODULE

    /** The Targeted Diagnostics controller. */
    MemTdCtlr<TARGETING::TYPE_OCMB_CHIP> * iv_tdCtlr = nullptr;

    /** IMPE threshold counter. */
    VcmFalseAlarm * iv_impeThresholdCounter = nullptr;

    #endif // __HOSTBOOT_MODULE

  public: // instance variables

    MemCeTable<TARGETING::TYPE_OCMB_CHIP> iv_ceTable; ///< CE table for FFDC
    MemUeTable iv_ueTable;                           ///< UE table for FFDC

    /** If there is a channel failure detected on this bus, there will be some
     *  required cleanup after analysis to mask off all further attentions from
     *  the bus. A channel failure could occur on either side of the bus and it
     *  is possible the cleanup function could be called in multiple
     *  PostAnalysis plugins depending on where the channel failure occurred.
     *  Since we only want to do one cleanup, we will use this variable to
     *  indicate if a cleanup is still required or has already been done. */
    bool iv_doChnlFailCleanup = false;

    /** If we get a channel fail on an OCMB, we cannot be sure whether we
     *  will be able to do putScoms after the fail. This would mean we
     *  won't be able to clear or mask registers. So to compensate, we will
     *  also use this flag to indicate that this OCMB has failed and should
     *  be "masked" and not analyzed to in the future. */
    bool iv_maskChnl = false;

    /** Ocmb Address Configuration */
    OcmbAddrConfig iv_addrConfig;

    #ifdef __HOSTBOOT_MODULE

    /** Threshold table for IUEs. Threshold per DIMM */
    std::map<uint8_t, TimeBasedThreshold> iv_iueTh;

    /** Bool to indicate if we've triggered a channel fail because of IUEs. */
    bool iv_iueChnlFail = false;

    #ifdef __HOSTBOOT_RUNTIME

    /** VCM false alarm counter. */
    VcmFalseAlarm * iv_vcmFalseAlarmCounter = nullptr;

    /** TPS false alarm counter. */
    TpsFalseAlarm * iv_tpsFalseAlarmCounter = nullptr;

    /** Set to true if mainline NCEs and TCEs should be permanently masked. This
     *  is checked at the end of targeted diagnostics before background
     *  scrubbing is resumed. */
    bool iv_maskMainlineNceTce = false;

    // These are used to limit the number of times a scrub command will stop
    // on a UE or CE on a rank. This is to prevent potential flooding of
    // maintenance UEs or CEs. The threshold will be 16 per rank for each.
    TimeBasedThreshold iv_ueStopCounter =
        TimeBasedThreshold( 16, ThresholdResolution::SEVEN_HOURS );
    TimeBasedThreshold iv_ceStopCounter =
        TimeBasedThreshold( 16, ThresholdResolution::SEVEN_HOURS );;

    // If we stop on a UE or a CE, we will need to store the rank that the
    // error is on so that we can clear our respective thresholds if the
    // next error we stop on is on a different rank.
    MemRank iv_ceUeRank;

    #else // IPL only

    /** MNFG IPL CE statistics. */
    MemIplCeStats<TARGETING::TYPE_OCMB_CHIP> * iv_iplCeStats = nullptr;

    #endif

    #endif // __HOSTBOOT_MODULE

};

/**
 * @brief  Wrapper function for the OcmbDataBundle.
 * @param i_ocmbChip The OCMB chip.
 * @return This MBA's data bundle.
 */
inline OcmbDataBundle * getOcmbDataBundle( ExtensibleChip * i_ocmbChip )
{
    return static_cast<OcmbDataBundle *>(i_ocmbChip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfOcmbDataBundle_H

