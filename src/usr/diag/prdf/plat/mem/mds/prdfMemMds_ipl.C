/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/mds/prdfMemMds_ipl.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#include <prdfMemMds_ipl.H>

// Platform includes
#include <prdfMemDbUtils.H>
#include <prdfMemMark.H>
#include <prdfMemMdsExtraSig.H>
#include <prdfMemMdsUtils.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemVcm.H>
#include <prdfParserEnums.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace MDS
{

//------------------------------------------------------------------------------

uint32_t checkMediaErrors_ipl( ExtensibleChip * i_chip,
    bool & o_errorsFound, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[checkMediaErrors_ipl] "

    uint32_t o_rc = SUCCESS;
    o_errorsFound = false;
    TargetHandle_t target = i_chip->getTrgt();
    HUID huid = i_chip->getHuid();
    OcmbDataBundle * db = getOcmbDataBundle( i_chip );

    // Note: for media errors that result in predictive callouts we'll be
    // calling out the DIMM, so get the DIMM target here.
    // First, get the address in which the command stopped.
    MemAddr addr;
    o_rc = getMemMaintAddr<TYPE_OCMB_CHIP>( i_chip, addr );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "getMemMaintAddr<TYPE_OCMB_CHIP>(0x%08x) failed",
                  i_chip->getHuid() );
        return o_rc;
    }
    // TODO RTC 210072 - Support for multiple ports per OCMB
    MemRank rank = addr.getRank();
    TargetHandle_t dimmTarget = getConnectedDimm( target, rank );

    // Update the media error log counts stored in the data bundle
    o_rc = db->iv_mediaFfdc.updateCounts( rank );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "iv_mediaFfdc.updateCounts(0x%02x) for huid 0x%08x "
                  "failed.", rank.getKey(), huid );
    }

    // Variables to store the rank information if we need it
    uint8_t prank = 0;

    // Get the active ecc attentions
    uint32_t eccAttns = 0;
    o_rc = checkEccFirs<TYPE_OCMB_CHIP>( i_chip, eccAttns );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "checkEccFirs(0x%08x) failed", huid );
        return o_rc;
    }

    // Check for a media UE (as indicated by RDFFIR maint SUE)
    if ( 0 != (eccAttns & MAINT_SUE ) )
    {
        io_sc.service_data->AddSignatureList( target, PRDFSIG_MdsMediaUe );

        // predictive callout for media UE
        io_sc.service_data->SetCallout( dimmTarget );
        io_sc.service_data->setServiceCall();

        // collect FFDC for media errors
        captureMediaFfdc( i_chip, io_sc );

        // Set flag indicating we've seen a media UE on this pattern
        db->iv_mediaUeSeen = true;

        // clear maint SUE - will be done when prepareNextCmd is called
    }
    // Check if media UEs already logged on previous sranks for this pattern
    else if ( db->iv_mediaUeSeen )
    {
        // Skip the rest of the checks for media errors
        io_sc.service_data->AddSignatureList( target, PRDFSIG_MdsMediaUeSeen );
    }
    // Check if MFG MDS 2-symbol media screening flag is enabled and media
    // error log count for any mrank is above threshold
    // TODO
    // Check if MFG mode is enabled and media error log count for any primary
    // rank is above threshold
    // TODO Eventually we will want the mfg threshold to have an attribute we
    // can adjust. For now, default to 1
    else if ( mfgMode() && db->iv_mediaFfdc.checkPrankCount(prank, 1) )
    {
        io_sc.service_data->AddSignatureList( target, PRDFSIG_MdsMediaUeRisk );

        // Predictive callout for media UE risk
        io_sc.service_data->SetCallout( dimmTarget );
        io_sc.service_data->setServiceCall();

        // collect FFDC for media errors
        captureMediaFfdc( i_chip, io_sc );
    }
    // Check if the media error log count for any primary rank is 8 or more
    else if ( db->iv_mediaFfdc.checkPrankCount(prank, 8) )
    {
        // Note: there's no need for additional verification of the chip kill
        // as the chip kill field threshold should be set high enough in
        // hardware to rule out soft errors or interface noise.

        // Check if we can classify the error as a single bad secondary rank
        uint8_t srank = 0;
        if ( db->iv_mediaFfdc.checkSrankCount( prank, srank ) )
        {
            io_sc.service_data->AddSignatureList( target,
                                                  PRDFSIG_MdsMediaBadSrank );
        }
        // Else classify as a whole bad primary rank
        else
        {
            io_sc.service_data->AddSignatureList( target,
                                                  PRDFSIG_MdsMediaBadPrank );
        }
        // Predictive callout for media UE risk
        io_sc.service_data->SetCallout( dimmTarget );
        io_sc.service_data->setServiceCall();

        // collect FFDC for media errors
        captureMediaFfdc( i_chip, io_sc );
    }
    else
    {
        // Check if there is a media chip kill
        std::map<MemRank, uint8_t> ckMap;
        o_rc = getChipKillInfo<TYPE_OCMB_CHIP>( target, ckMap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getChipKillInfo(0x%08x) failed.", huid );
            return o_rc;
        }

        if ( !ckMap.empty() )
        {
            io_sc.service_data->SetCallout( dimmTarget );

            // In mfg mode, make the log predictive
            if ( mfgMode() )
            {
                io_sc.service_data->setServiceCall();
            }

            // collect FFDC for media errors
            captureMediaFfdc( i_chip, io_sc );
        }
    }

    // Clear media error logs
    o_rc = clearMediaErrLogs( i_chip );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "clearMediaErrLogs(0x%08x) failed.", huid );
        return o_rc;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t __mdsHandleMpe(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc)
{

    #define PRDF_FUNC "[__mdsHandleMpe] "

    uint32_t o_rc = SUCCESS;
    TargetHandle_t target = i_chip->getTrgt();
    HUID huid = i_chip->getHuid();
    bool falseAlarm = false;

    io_sc.service_data->AddSignatureList( target, PRDFSIG_MdsMaintMpe );

    // This function is only defined for memdiags handling
    if ( !isInMdiaMode() )
    {
        PRDF_ERR( PRDF_FUNC "This function only supported for memory "
                  "diagnostics." );
        return o_rc;
    }

    // MDS Memory Diagnostics Verify Chip Mark (VCM)
    // If there is a non-zero MCE count as indicated by bits 0:11 of the MBSEC1
    // register we will consider any primary rank with the MPE FIR bit set
    // (RDFFIR bits 20:27) to be verified.

    // First, check the hard MCE count in MBSEC1[0:11]
    SCAN_COMM_REGISTER_CLASS * mbsec1 = i_chip->getRegister( "MBSEC1" );
    o_rc = mbsec1->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on MBSEC1: 0x%08x", huid );
        return o_rc;
    }

    uint64_t mceCount = mbsec1->GetBitFieldJustified(0, 12);

    // Trace out the MCE count
    PRDF_TRAC( PRDF_FUNC "MCE Count on 0x%08x = %d", huid, mceCount );

    if ( 0 == mceCount )
    {
        // MCE count is 0, set false alarm flag
        falseAlarm = true;

        // Add signature to indicate false alarm
        io_sc.service_data->AddSignatureList( target, PRDFSIG_MdsMdiaVcmFa );
    }
    else
    {
        // Add signature to indicate verified
        io_sc.service_data->AddSignatureList( target, PRDFSIG_MdsMdiaVcmVer );
    }

    // Now, we will need to take action on the ranks that have the MPE FIR bit
    // set, either removing the chip mark for a false alarm or calling
    // MarkStore::chipMarkCleanup to apply our appropriate RAS actions for
    // verified chip marks.
    SCAN_COMM_REGISTER_CLASS * rdffir = i_chip->getRegister( "RDFFIR" );
    o_rc = rdffir->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on RDFFIR: 0x%08x", huid );
        return o_rc;
    }

    // Loop through the 8 bits in the RDFFIR corresponding to the 8 ranks
    // where an MPE might have been placed.
    for ( uint8_t rank = 0; rank < 8; rank++ )
    {
        // Bits 20:27 of the RDFFIR report MPE on ranks 0:7 respectively
        if ( rdffir->IsBitSet(20 + rank) )
        {
            MemRank memRank = MemRank( rank );

            if ( falseAlarm )
            {
                // If DRAM repairs are disabled, make the error log predictive.
                if ( areDramRepairsDisabled() )
                {
                    io_sc.service_data->setServiceCall();
                }
                else
                {
                    // Else if we have a false alarm, remove the chip mark.
                    o_rc = MarkStore::clearChipMark<TYPE_OCMB_CHIP>( i_chip,
                                                                     memRank );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "clearChipMark(0x%08x,0x%02x) "
                                  "failed", huid, memRank.getKey() );
                    }
                }
            }
            else
            {

                // For each rank with a verified chip mark, call
                // MarkStore::chipMarkCleanup to apply the appropriate actions.
                bool dsd = false;
                o_rc = MarkStore::chipMarkCleanup<TYPE_OCMB_CHIP>( i_chip,
                    memRank, io_sc, dsd );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "chipMarkCleanup(0x%08x,0x%02x) failed",
                              huid, memRank.getKey() );
                }
            }
        }
    }

    // MCE counters will be cleared when prepareNextCmd is called as part
    // of the usual TdCtlr handling.

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t checkReadPathInterfaceErrors_ipl( ExtensibleChip * i_chip,
    bool & o_errorsFound, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[checkReadPathInterfaceErrors_ipl] "

    uint32_t o_rc = SUCCESS;
    o_errorsFound = false;
    TargetHandle_t target = i_chip->getTrgt();
    HUID huid = i_chip->getHuid();

    uint32_t eccAttns = 0;
    o_rc = checkEccFirs<TYPE_OCMB_CHIP>( i_chip, eccAttns );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "checkEccFirs(0x%08x) failed", huid );
        return o_rc;
    }

    // Check for an interface maint UE
    if ( 0 != (eccAttns & MAINT_UE) )
    {
        o_errorsFound = true;
        io_sc.service_data->AddSignatureList( target, PRDFSIG_MdsInterfaceUe );

        // Predictive callout and exit memdiags for this DIMM
        io_sc.service_data->SetCallout( target );
        io_sc.service_data->setServiceCall();

        if ( isInMdiaMode() )
        {
            // This differs slightly from our usual maintenance UE handling
            // where we do not stop memdiags for this DIMM. The difference is
            // since this is reporting a read-interface UE. For MDS, the goal
            // is to continue with the next pattern unless an interface UE
            // forces us to exit memdiags for this DIMM.
            o_rc = mdiaSendEventMsg( target, MDIA::STOP_TESTING );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(0x%08x, STOP_TESTING) "
                          "failed", huid );
            }
        }
    }
    // Check for a maint MPE
    else if ( 0 != (eccAttns & MAINT_MPE) )
    {
        o_errorsFound = true;
        o_rc = __mdsHandleMpe( i_chip, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__mdsHandleMpe(0x%08x) failed", huid );
        }
    }
    // Check if MFG CE screening flag is enabled and maint total hard CE count
    // is non-zero
    else if ( isMfgCeCheckingEnabled() &&
              (0 != (eccAttns & MAINT_HARD_NCE_ETE)) )
    {
        o_errorsFound = true;
        io_sc.service_data->AddSignatureList( target, PRDFSIG_MaintHARD_CTE );

        // Make a predictive callout
        io_sc.service_data->SetCallout( target );
        io_sc.service_data->setServiceCall();

        // Get the hard CE count and trace it out. The count is MBSEC0[24:35]
        SCAN_COMM_REGISTER_CLASS * mbsec0 = i_chip->getRegister( "MBSEC0" );
        o_rc = mbsec0->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBSEC0: 0x%08x", huid );
            return o_rc;
        }

        uint64_t hardCeCount = mbsec0->GetBitFieldJustified(24, 12);

        // Trace out the hard CE count
        PRDF_TRAC(PRDF_FUNC "Hard CE Count on 0x%08x = %d", huid, hardCeCount);

        // CE counters will be cleared when prepareNextCmd is called as part
        // of the usual TdCtlr handling.
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t checkWritePathInterfaceErrors_ipl( ExtensibleChip * i_chip,
    bool & o_errorsFound, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[checkReadPathInterfaceErrors_ipl] "

    uint32_t o_rc = SUCCESS;

    o_errorsFound = false;
    TargetHandle_t target = i_chip->getTrgt();
    HUID huid = i_chip->getHuid();

    // Flag to keep track of if we need to stop memdiags testing on this DIMM.
    bool stopMemdiags = false;

    // Get the double bit error count, poison count, and single bit error count
    // from the MDS media controller.
    uint8_t dbCount = 0;
    o_rc = getDoubleBitCount<TYPE_OCMB_CHIP>( target, dbCount );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "getDoubleBitCount<TYPE_OCMB_CHIP>(0x%08x) failed",
                  huid );
        return o_rc;
    }

    uint8_t sbCount = 0;
    o_rc = getSingleBitCount<TYPE_OCMB_CHIP>( target, sbCount );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "getSingleBitCount<TYPE_OCMB_CHIP>(0x%08x) failed",
                  huid );
        return o_rc;
    }

    uint8_t poisonCount = 0;
    o_rc = getPoisonCount<TYPE_OCMB_CHIP>( target, poisonCount );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "getPoisonCount<TYPE_OCMB_CHIP>(0x%08x) failed",
                  huid );
        return o_rc;
    }

    // Check for write-path interface errors on the media controller
    // DBE (double bit error) count > 0
    if ( dbCount > 0 )
    {
        // Double bit error means more than one bad symbol (dq) in a given ECC
        // word on write path from explorer to the media controller
        io_sc.service_data->AddSignatureList( target, PRDFSIG_MdsDbe );
        o_errorsFound = true;

        PRDF_TRAC( PRDF_FUNC "Double bit error encountered. Count = %d",
                   dbCount );

        // Predictive callout and exit memdiags for this DIMM
        io_sc.service_data->SetCallout( target );
        io_sc.service_data->setServiceCall();
        stopMemdiags = true;
    }
    // Poison count > 0
    else if ( poisonCount > 0 )
    {
        // Poison means an SUE is already in the data we sent to the media
        // controller. This should not be possible to send an SUE using the
        // write command, so this check is mainly as a precaution to catch
        // something unexpected.
        io_sc.service_data->AddSignatureList( target, PRDFSIG_MdsPoison );
        o_errorsFound = true;

        PRDF_TRAC( PRDF_FUNC "Poison error encountered. Count = %d",
                   poisonCount );

        // Predictive callout and exit memdiags for this DIMM
        io_sc.service_data->SetCallout( target );
        io_sc.service_data->setServiceCall();
        stopMemdiags = true;
    }
    // SBE (single bit error) count > 0
    else if ( sbCount > 0 )
    {
        // Means a single bad symbol (dq) in a given ECC word on the write path
        // from explorer to the media controller.
        // - Could be caused by one bad DQ, affecting multiple ECC words
        // - Could be caused by random bit flips on multiple DQs, just not
        //   lining up in a given ECC word
        io_sc.service_data->AddSignatureList( target, PRDFSIG_MdsSbe );
        o_errorsFound = true;

        PRDF_TRAC( PRDF_FUNC "Single bit error encountered. Count = %d",
                   sbCount );

        // If MNFG CE screening enabled and count > 0
        // or count == max value of 0x7F
        if ( isMfgCeCheckingEnabled() || (sbCount == 0x7f) )
        {
            // Predictive callout and exit memdiags for this DIMM
            io_sc.service_data->SetCallout( target );
            io_sc.service_data->setServiceCall();
            stopMemdiags = true;
        }
        // Else if count < max value of 0x7F
        else
        {
            // Keep the log hidden and clear the count to prevent accumulation
            // across patterns, and allow memdiags to continue for this DIMM.
            o_rc = clearSingleBitCount( i_chip );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR(PRDF_FUNC "clearSingleBitCount(0x%08x) failed", huid)
            }
        }
    }

    if ( stopMemdiags )
    {
        if ( isInMdiaMode() )
        {
            o_rc = mdiaSendEventMsg( target, MDIA::STOP_TESTING );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(0x%08x, STOP_TESTING)"
                          " failed", huid );
            }
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace MDS

} // end namespace PRDF
