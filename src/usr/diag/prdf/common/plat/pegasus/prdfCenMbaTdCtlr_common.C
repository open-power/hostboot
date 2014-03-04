/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaTdCtlr_common.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

#include <prdfCenMbaTdCtlr_common.H>

// Framework includes
#include <prdfRegisterCache.H>

// Pegasus includes
#include <prdfCalloutUtil.H>
#include <prdfCenDqBitmap.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfCenMbaThresholds.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlrCommon::initialize()
{
    #define PRDF_FUNC "[CenMbaTdCtlrCommon::initialize] "

    int32_t o_rc = SUCCESS;

    do
    {
        // Set iv_mbaTrgt
        iv_mbaTrgt = iv_mbaChip->GetChipHandle();

        // Validate iv_mbaChip.
        if ( TYPE_MBA != getTargetType(iv_mbaTrgt) )
        {
            PRDF_ERR( PRDF_FUNC"iv_mbaChip is not TYPE_MBA" );
            o_rc = FAIL; break;
        }

        // Set iv_membChip.
        CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );
        iv_membChip = mbadb->getMembChip();
        if ( NULL == iv_membChip )
        {
            PRDF_ERR( PRDF_FUNC"getMembChip() failed" );
            o_rc = FAIL; break;
        }

        // Set iv_mbaPos.
        iv_mbaPos = getTargetPosition( iv_mbaTrgt );
        if ( MAX_MBA_PER_MEMBUF <= iv_mbaPos )
        {
            PRDF_ERR( PRDF_FUNC"iv_mbaPos=%d is invalid", iv_mbaPos );
            o_rc = FAIL; break;
        }

        // Set iv_x4Dimm.
        iv_x4Dimm = isDramWidthX4(iv_mbaTrgt);

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool CenMbaTdCtlrCommon::isInTdMode()
{
    return ( (NO_OP != iv_tdState) && (MAX_TD_STATE > iv_tdState) );
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlrCommon::cleanupPrevCmd()
{
    #define PRDF_FUNC "[CenMbaTdCtlrCommon::cleanupPrevCmd] "

    int32_t o_rc = SUCCESS;

    // Clean up the current maintenance command. This must be done whenever
    // maintenance command will no longer be executed.
    if ( NULL != iv_mssCmd )
    {
        o_rc = iv_mssCmd->cleanupCmd();
        if ( SUCCESS != o_rc )
            PRDF_ERR( PRDF_FUNC"cleanupCmd() failed" );

        delete iv_mssCmd; iv_mssCmd = NULL;
    }

    // Clear the command complete attention. This must be done before starting
    // the next maintenance command.
    SCAN_COMM_REGISTER_CLASS * firand = iv_mbaChip->getRegister("MBASPA_AND");
    firand->setAllBits();

    firand->ClearBit(0); // Maintenance command complete
    firand->ClearBit(8); // Maintenance command complete (DD1.0 workaround)

    if ( SUCCESS != firand->Write() )
    {
        PRDF_ERR( PRDF_FUNC"Write() failed on MBASPA_AND" );
        o_rc = FAIL;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlrCommon::prepareNextCmd( bool i_clearStats )
{
    #define PRDF_FUNC "[CenMbaTdCtlrCommon::prepareNextCmd] "

    int32_t o_rc = SUCCESS;

    do
    {
        //----------------------------------------------------------------------
        // Clean up previous command
        //----------------------------------------------------------------------

        o_rc = cleanupPrevCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"cleanupPrevCmd() failed" );
            break;
        }

        //----------------------------------------------------------------------
        // Clear ECC counters
        //----------------------------------------------------------------------

        const char * reg_str = NULL;

        if ( i_clearStats )
        {
            reg_str = (0 == iv_mbaPos) ? "MBA0_MBSTR" : "MBA1_MBSTR";
            SCAN_COMM_REGISTER_CLASS * mbstr =
                                    iv_membChip->getRegister( reg_str );

            // MBSTR's content could be modified from cleanupCmd()
            // so we need to refresh
            o_rc = mbstr->ForceRead();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"ForceRead() failed on %s", reg_str );
                break;
            }

            mbstr->SetBit(53); // Setting this bit clears all counters.

            o_rc = mbstr->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"Write() failed on %s", reg_str );
                break;
            }

            // Hardware automatically clears bit 53, so flush this register out
            // of the register cache to avoid clearing the counters again with
            // a write from the out-of-date cached copy.
            RegDataCache & cache = RegDataCache::getCachedRegisters();
            cache.flush( iv_membChip, mbstr );
        }

        //----------------------------------------------------------------------
        // Clear ECC FIRs
        //----------------------------------------------------------------------

        reg_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_AND"
                                   : "MBA1_MBSECCFIR_AND";
        SCAN_COMM_REGISTER_CLASS * firand = iv_membChip->getRegister( reg_str );
        firand->setAllBits();

        // Clear all scrub MPE bits.
        // This will need to be done when starting a TD procedure or background
        // scrubbing. iv_rank may not be set when starting background scrubbing
        // and technically there should only be one of these MPE bits on at a
        // time so we should not have to worry about losing an attention by
        // clearing them all.
        firand->SetBitFieldJustified( 20, 8, 0 );

        // Clear scrub NCE, SCE, MCE, RCE, SUE, UE bits (36-41)
        firand->SetBitFieldJustified( 36, 6, 0 );

        o_rc = firand->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on %s", reg_str );
            break;
        }

        SCAN_COMM_REGISTER_CLASS * spaAnd =
                                iv_mbaChip->getRegister("MBASPA_AND");
        spaAnd->setAllBits();

        // Clear threshold exceeded attentions
        spaAnd->SetBitFieldJustified( 1, 4, 0 );

        o_rc = spaAnd->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on MBASPA_AND" );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlrCommon::chipMarkCleanup()
{
    #define PRDF_FUNC "[CenMbaTdCtlrCommon::chipMarkCleanup] "

    int32_t o_rc = SUCCESS;

    do
    {
        SCAN_COMM_REGISTER_CLASS * ddrPhyAndFir =
                                 iv_mbaChip->getRegister( "MBADDRPHYFIR_AND" );
        ddrPhyAndFir->setAllBits();

        ddrPhyAndFir->ClearBit(50); // Calibration Error RE 0
        ddrPhyAndFir->ClearBit(58); // Calibration Error RE 1

        o_rc = ddrPhyAndFir->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on MBADDRPHYFIR_AND" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlrCommon::checkEccErrors( uint16_t & o_eccErrorMask,
                                            STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlrCommon::checkEccErrors] "

    int32_t o_rc = SUCCESS;

    o_eccErrorMask = NO_ERROR;

    do
    {
        const char * reg_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR"
                                                : "MBA1_MBSECCFIR";
        SCAN_COMM_REGISTER_CLASS * mbsEccFir
                                        = iv_membChip->getRegister( reg_str );
        o_rc = mbsEccFir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on %s", reg_str );
            break;
        }

        if ( mbsEccFir->IsBitSet(20 + iv_rank.getMaster()) )
        {
            o_eccErrorMask |= MPE;
            io_sc.service_data->AddSignatureList(iv_mbaTrgt, PRDFSIG_MaintMPE);

            // Clean up side-effect FIRs that may be set due to the chip mark.
            o_rc = chipMarkCleanup();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"chipMarkCleanup() failed" );
                break;
            }
        }

        if ( mbsEccFir->IsBitSet(38) )
        {
            // No need to add error signature. MCE is not error. It will be
            // handled only in VCM/DSD phase 2.
            o_eccErrorMask |= MCE;
        }

        if ( mbsEccFir->IsBitSet(41) )
        {
            o_eccErrorMask |= UE;
            io_sc.service_data->AddSignatureList( iv_mbaTrgt, PRDFSIG_MaintUE );
        }

        SCAN_COMM_REGISTER_CLASS * mbaSpaFir =
                            iv_mbaChip->getRegister("MBASPA");
        o_rc = mbaSpaFir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Failed to read MBASPA Regsiter");
            break;
        }

        if ( mbaSpaFir->IsBitSet(1) )
        {
            o_eccErrorMask |= HARD_CTE;
            io_sc.service_data->AddSignatureList( iv_mbaTrgt,
                                                  PRDFSIG_MaintHARD_CTE );
        }

        if ( mbaSpaFir->IsBitSet(2) )
        {
            o_eccErrorMask |= SOFT_CTE;
            io_sc.service_data->AddSignatureList( iv_mbaTrgt,
                                                  PRDFSIG_MaintSOFT_CTE );
        }

        if ( mbaSpaFir->IsBitSet(3) )
        {
            o_eccErrorMask |= INTER_CTE;
            io_sc.service_data->AddSignatureList( iv_mbaTrgt,
                                                  PRDFSIG_MaintINTER_CTE );
        }

        if ( mbaSpaFir->IsBitSet(4) )
        {
            o_eccErrorMask |= RETRY_CTE;
            io_sc.service_data->AddSignatureList( iv_mbaTrgt,
                                                  PRDFSIG_MaintRETRY_CTE );
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlrCommon::handleMCE_VCM2( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlrCommon::handleMCE_VCM2] "

    using namespace fapi; // For spare config macros.

    int32_t o_rc = SUCCESS;

    iv_isEccSteer = false;

    do
    {
        if ( VCM_PHASE_2 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        setTdSignature( io_sc, PRDFSIG_VcmVerified );

        if ( areDramRepairsDisabled() )
        {
            iv_tdState = NO_OP; // The TD procedure is complete.

            io_sc.service_data->SetServiceCall();

            break; // nothing else to do.
        }

        // If there is a symbol mark on the same DRAM as the newly verified chip
        // mark, remove the symbol mark.
        if ( iv_mark.getCM().getDram() == iv_mark.getSM().getDram() )
        {
            iv_mark.clearSM();
            bool blocked; // Won't be blocked because chip mark is in place.
            o_rc = mssSetMarkStore( iv_mbaTrgt, iv_rank, iv_mark, blocked );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"mssSetMarkStore() failed" );
                break;
            }
        }

        bool startDsdProcedure = false;

        // Read VPD.
        CenDqBitmap bitmap;
        o_rc = getBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getBadDqBitmap() failed" );
            break;
        }

        // The chip mark is considered verified, so set it in VPD.
        // NOTE: If this chip mark was placed on the spare, the original failing
        //       DRAM will have already been set in VPD so this will be
        //       redundant but it simplifies the rest of the logic below.
        o_rc = bitmap.setDram( iv_mark.getCM().getSymbol() );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setDram() failed" );
            break;
        }

        uint8_t ps = iv_mark.getCM().getPortSlct();
        uint8_t spareConfig = ENUM_ATTR_EFF_DIMM_SPARE_NO_SPARE;
        o_rc = getDimmSpareConfig( iv_mbaTrgt, iv_rank, ps,
                                   spareConfig );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getDimmSpareConfig() failed" );
            break;
        }

        // Check if DRAM spare is present. Also, ECC spares are available on all
        // x4 DIMMS.
        if ( ( ENUM_ATTR_EFF_DIMM_SPARE_NO_SPARE != spareConfig ) || iv_x4Dimm )
        {
            // It is possible that a Centaur DIMM does not have spare DRAMs.
            // Check the VPD for available spares. Note that a x4 DIMM has
            // DRAM spares and ECC spares, so check for availability on both.
            bool dramSparePossible = false;
            o_rc = bitmap.isDramSpareAvailable( ps, dramSparePossible );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"isDramSpareAvailable() failed" );
                break;
            }

            if ( dramSparePossible )
            {
                // Verify the spare is not already used.
                CenSymbol sp0, sp1, ecc;
                o_rc = mssGetSteerMux( iv_mbaTrgt, iv_rank, sp0, sp1, ecc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC"mssGetSteerMux() failed" );
                    break;
                }

                // If spare DRAM is bad, HW can not steer another DRAM even
                // if it is available ( e.g. ECC spare ). So if chip mark is on
                // spare DRAM, update VPD and make predictive callout.
                if ( ( iv_mark.getCM().getDram() ==
                          (0 == ps ? sp0.getDram() : sp1.getDram()) )
                     || ( iv_mark.getCM().getDram() == ecc.getDram() ))
                {

                    setTdSignature( io_sc, PRDFSIG_VcmBadSpare );

                    // The chip mark was on the spare DRAM and it is bad, so
                    // call it out and set it in VPD.

                    MemoryMru memmru ( iv_mbaTrgt, iv_rank, iv_mark.getCM() );
                    io_sc.service_data->SetCallout( memmru );

                    io_sc.service_data->SetServiceCall();

                    if ( iv_mark.getCM().getDram() == ecc.getDram() )
                    {
                        o_rc = bitmap.setEccSpare();
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC"setEccSpare() failed" );
                            break;
                        }
                    }
                    else
                    {
                        o_rc = bitmap.setDramSpare( ps );
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC"setDramSpare() failed" );
                            break;
                        }
                    }
                }
                else if ( ((0 == ps) && !sp0.isValid()) ||
                          ((1 == ps) && !sp1.isValid()) )
                {
                    // A spare DRAM is available.
                    startDsdProcedure = true;
                }
                else if ( isDramWidthX4(iv_mbaTrgt) && !ecc.isValid() )
                {
                    startDsdProcedure = true;
                    iv_isEccSteer = true;
                }
                else
                {
                    // Chip mark and DRAM spare are both used.
                    io_sc.service_data->SetErrorSig( PRDFSIG_VcmMarksUnavail );
                    io_sc.service_data->SetServiceCall();
                }
            }
            else
            {
                // Chip mark is in place and sparing is not possible.
                setTdSignature( io_sc, PRDFSIG_VcmMarksUnavail );
                io_sc.service_data->SetServiceCall();
            }
        }
        else // DRAM spare not supported.
        {
            // Not able to do dram sparing. If there is a symbol mark, there are
            // no repairs available so call it out and set the error log to
            // predictive.
            if ( iv_mark.getSM().isValid() )
            {
                setTdSignature( io_sc, PRDFSIG_VcmMarksUnavail );
                io_sc.service_data->SetServiceCall();
            }
        }

        // Write VPD.
        o_rc = setBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setBadDqBitmap() failed" );
            break;
        }

        // Start DSD Phase 1, if possible.
        if ( startDsdProcedure )
        {
            o_rc = startDsdPhase1( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"startDsdPhase1() failed" );
                break;
            }
        }
        else
        {
            iv_tdState = NO_OP; // The TD procedure is complete.
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlrCommon::handleMCE_DSD2( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlrCommon::handleMCE_DSD2] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( DSD_PHASE_2 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        setTdSignature( io_sc, PRDFSIG_DsdBadSpare );
        io_sc.service_data->SetServiceCall();

        // Callout spare DRAM.
        MemoryMru memmru ( iv_mbaTrgt, iv_rank, iv_mark.getCM() );
        io_sc.service_data->SetCallout( memmru );

        // The spare DRAM is bad, so set it in VPD. At this point, the chip mark
        // should have already been set in the VPD because it was recently
        // verified.

        CenDqBitmap bitmap;
        o_rc = getBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getBadDqBitmap() failed" );
            break;
        }
        if ( iv_isEccSteer )
        {
            bitmap.setEccSpare();
        }
        else
        {
            o_rc = bitmap.setDramSpare( iv_mark.getCM().getPortSlct() );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"setDramSpare() failed" );
                break;
            }
        }

        o_rc = setBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setBadDqBitmap() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlrCommon::setRtEteThresholds()
{
    #define PRDF_FUNC "[CenMbaTdCtlrCommon::setRtEteThresholds] "

    int32_t o_rc = SUCCESS;

    do
    {
        const char * reg_str = (0 == iv_mbaPos) ? "MBA0_MBSTR" : "MBA1_MBSTR";
        SCAN_COMM_REGISTER_CLASS * mbstr = iv_membChip->getRegister( reg_str );

        // MBSTR's content could be modified from cleanupCmd()
        // so we need to refresh
        o_rc = mbstr->ForceRead();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"ForceRead() failed on %s", reg_str );
            break;
        }

        uint16_t softIntCe = 0;
        o_rc = getScrubCeThreshold( iv_mbaChip, iv_rank, softIntCe );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getScrubCeThreshold() failed." );
            break;
        }

        // Only care about retry CEs if there are a lot of them. So the
        // threshold will be high in the field. However, in MNFG the retry CEs
        // will be handled differently by putting every occurrence in the RCE
        // table and doing targeted diagnostics when needed.
        uint16_t retryCe = mfgMode() ? 1 : 2047;

        uint16_t hardCe = 1; // Always stop on first occurrence.

        mbstr->SetBitFieldJustified(  4, 12, softIntCe );
        mbstr->SetBitFieldJustified( 16, 12, softIntCe );
        mbstr->SetBitFieldJustified( 28, 12, hardCe    );
        mbstr->SetBitFieldJustified( 40, 12, retryCe   );

        // Set the per symbol counters to count hard CEs only. This is so that
        // when the scrub stops on the first hard CE, we can use the per symbol
        // counters to tell us which symbol reported the hard CE.
        mbstr->SetBitFieldJustified( 55, 3, 0x1 );

        o_rc = mbstr->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on %s", reg_str );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void CenMbaTdCtlrCommon::badPathErrorHandling( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlrCommon::badPathErrorHandling] "

    PRDF_ERR( PRDF_FUNC"iv_mbaChip:0x%08x iv_initialized:%c iv_tdState:%d "
              "iv_rank:M%dS%d iv_mark:%2d %2d", iv_mbaChip->GetId(),
              iv_initialized ? 'T' : 'F', iv_tdState, iv_rank.getMaster(),
              iv_rank.getSlave(), iv_mark.getCM().getSymbol(),
              iv_mark.getSM().getSymbol() );

    iv_tdState = NO_OP;

    setTdSignature( io_sc, PRDFSIG_MaintCmdComplete_ERROR );
    io_sc.service_data->SetServiceCall();

    // There may have been a code bug, callout 2nd level support.
    io_sc.service_data->SetCallout( NextLevelSupport_ENUM, MRU_HIGH );

    // Callout the rank if no other callouts have been made (besides 2nd
    // Level Support). Note that iv_mark is not always guaranteed to be
    // valid for every error scenario. For simplicity, callout the rank that
    // was targeted with low priority.
    if ( 1 == io_sc.service_data->GetMruList().size() )
    {
        MemoryMru memmru ( iv_mbaTrgt, iv_rank, MemoryMruData::CALLOUT_RANK );
        io_sc.service_data->SetCallout( memmru, MRU_LOW );
    }

    // Just in case it was a legitimate maintenance command complete (error
    // log not committed) but something else failed.
    io_sc.service_data->ClearFlag(ServiceDataCollector::DONT_COMMIT_ERRL);

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void CenMbaTdCtlrCommon::setTdSignature( STEP_CODE_DATA_STRUCT & io_sc,
                                         uint32_t i_sig )
{
    HUID mbaId = iv_mbaChip->GetId();
    (io_sc.service_data->GetErrorSignature())->setChipId(mbaId);
    io_sc.service_data->SetErrorSig( i_sig );
}

} // end namespace PRDF

