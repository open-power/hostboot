/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTps_ipl.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

/** @file prdfMemTps_ipl.C */

// Platform includes
#include <prdfMemDbUtils.H>
#include <prdfMemEccAnalysis.H>
#include <prdfMemIplCeStats.H>
#include <prdfMemMark.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTps.H>
#include <prdfP9McaDataBundle.H>
#include <prdfP9McaExtraSig.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//##############################################################################
//
//                          Generic template functions
//
//##############################################################################

template <TARGETING::TYPE T>
uint32_t TpsEvent<T>::nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent::nextStep] "

    // Should only do this procedure if MNFG IPL CE handling is enabled.
    PRDF_ASSERT( isMfgCeCheckingEnabled() );

    uint32_t o_rc = SUCCESS;

    o_done = false;

    do
    {
        // First, do analysis.
        o_rc = analyzePhase( io_sc, o_done );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzePhase() failed on 0x%08x,0x%2x",
                      iv_chip->getHuid(), getKey() );
            break;
        }

        if ( o_done ) break; // Nothing more to do.

        // Then, start the next phase of the procedure.
        o_rc = startNextPhase( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzePhase() failed on 0x%08x,0x%2x",
                      iv_chip->getHuid(), getKey() );
            break;
        }

    } while (0);

    // Add the rank to the callout list if no callouts in the list.
    if ( 0 == io_sc.service_data->getMruListSize() )
    {
        MemoryMru mm {iv_chip->getTrgt(), iv_rank, MemoryMruData::CALLOUT_RANK};
        io_sc.service_data->SetCallout( mm );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t TpsEvent<T>::analyzePhase( STEP_CODE_DATA_STRUCT & io_sc,
                                    bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent::analyzePhase] "

    uint32_t o_rc = SUCCESS;

    o_done = false;

    do
    {
        if ( TD_PHASE_0 == iv_phase ) break; // Nothing to analyze yet.

        // Collect the CE statistics from the command that just completed.
        MemIplCeStats<T> * ceStats = MemDbUtils::getIplCeStats<T>( iv_chip );
        switch ( iv_phase )
        {
            case TD_PHASE_1: // Collect all CE stats.
                o_rc = ceStats->collectStats( iv_rank );
                break;

            case TD_PHASE_2: // Collect hard CE stats.
                o_rc = ceStats->calloutHardCes( iv_rank );
                break;

            default: PRDF_ASSERT(false); // code bug
        }
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Failed to collect CE stats on 0x%08x,0x%02x",
                      iv_chip->getHuid(), getKey() );
            break;
        }

        // Look for any ECC errors that occurred during the command.
        uint32_t eccAttns;
        o_rc = checkEccFirs<T>( iv_chip, eccAttns );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccFirs(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Analyze the ECC errors, if needed.
        o_rc = analyzeEccErrors( eccAttns, io_sc, o_done );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeEccErrors() failed" );
            break;
        }
        if ( o_done ) break; // abort the procedure.

        // The procedure is complete if this was phase 2.
        if ( TD_PHASE_2 == iv_phase ) o_done = true;

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
bool __iueCheck( uint32_t i_eccAttns );

template<> inline
bool __iueCheck<TYPE_MCA>( uint32_t i_eccAttns )
{
    return ( 0 != (i_eccAttns & MAINT_IUE) );
}

template<> inline
bool __iueCheck<TYPE_MBA>( uint32_t i_eccAttns )
{
    // IUES are reported via RCE ETE on Centaur
    return ( 0 != (i_eccAttns & MAINT_RCE_ETE) );
}

template<TARGETING::TYPE T>
uint32_t TpsEvent<T>::analyzeEccErrors( const uint32_t & i_eccAttns,
                                        STEP_CODE_DATA_STRUCT & io_sc,
                                        bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent::analyzeEccErrors] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // At this point we don't actually have an address for any ECC errors.
        // The best we can do is get the address in which the command stopped.
        MemAddr addr;
        o_rc = getMemMaintAddr<T>( iv_chip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // IUEs are reported as UEs during read operations. Therefore, we will
        // treat IUEs like UEs for these scrub operations simply to maintain
        // consistency during all of Memory Diagnostics.
        if ( (i_eccAttns & MAINT_UE) || __iueCheck<T>(i_eccAttns) )
        {
            PRDF_TRAC( PRDF_FUNC "UE Detected: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            // Add the signature to the multi-signature list. Also, since
            // this will be a predictive callout, change the primary
            // signature as well.
            uint32_t sig = (i_eccAttns & MAINT_UE) ? PRDFSIG_MaintUE
                                                   : PRDFSIG_MaintIUE;
            io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), sig );
            io_sc.service_data->setSignature(     iv_chip->getHuid(), sig );

            o_rc = MemEcc::handleMemUe<T>( iv_chip, addr, UE_TABLE::SCRUB_UE,
                                           io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "MemEcc::handleMemUe(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // Leave the mark in place and abort this procedure.
            o_done = true; break;
        }
        else if ( i_eccAttns & MAINT_MPE )
        {
            PRDF_TRAC( PRDF_FUNC "MPE Detected: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                                  PRDFSIG_MaintMPE );

            o_rc = MemEcc::handleMpe<T>( iv_chip, addr, UE_TABLE::SCRUB_MPE,
                                         io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "MemEcc::handleMpe(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // Leave the mark in place and abort this procedure.
            o_done = true; break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t TpsEvent<T>::startNextPhase( STEP_CODE_DATA_STRUCT & io_sc )
{
    uint32_t signature = 0;

    switch ( iv_phase )
    {
        case TD_PHASE_0:
            iv_phase  = TD_PHASE_1;
            signature = PRDFSIG_StartTpsPhase1;
            break;

        case TD_PHASE_1:
            iv_phase  = TD_PHASE_2;
            signature = PRDFSIG_StartTpsPhase2;
            break;

        default: PRDF_ASSERT( false ); // invalid phase
    }

    PRDF_TRAC( "[TpsEvent] Starting TPS Phase %d: 0x%08x,0x%02x",
               iv_phase, iv_chip->getHuid(), getKey() );

    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), signature );

    return startCmd();
}

//##############################################################################
//
//                          Specializations for MCA
//
//##############################################################################

template<>
uint32_t TpsEvent<TYPE_MCA>::startCmd()
{
    #define PRDF_FUNC "[TpsEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    // We don't need to set any stop-on-error conditions or thresholds for
    // soft/inter/hard CEs during Memory Diagnostics. The design is to let the
    // command continue to the end of the rank and we do diagnostics on the
    // CE counts found in the per-symbol counters. Therefore, all we need to do
    // is tell the hardware which CE types to count.

    mss::mcbist::stop_conditions stopCond;

    switch ( iv_phase )
    {
        case TD_PHASE_1:
            // Set the per symbol counters to count only soft/inter CEs.
            stopCond.set_nce_soft_symbol_count_enable( mss::ON);
            stopCond.set_nce_inter_symbol_count_enable(mss::ON);
            break;

        case TD_PHASE_2:
            // Set the per symbol counters to count only hard CEs.
            stopCond.set_nce_hard_symbol_count_enable(mss::ON);
            break;

        default: PRDF_ASSERT( false ); // invalid phase
    }

    // Start the time based scrub procedure on this slave rank.
    o_rc = startTdScrub<TYPE_MCA>( iv_chip, iv_rank, SLAVE_RANK, stopCond );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                  iv_chip->getHuid(), getKey() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//
//                          Specializations for MBA
//
//##############################################################################

template<>
uint32_t TpsEvent<TYPE_MBA>::startCmd()
{
    #define PRDF_FUNC "[TpsEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    uint32_t stopCond = mss_MaintCmd::NO_STOP_CONDITIONS;

    // We don't need to set any stop-on-error conditions or thresholds for
    // soft/inter/hard CEs during Memory Diagnostics. The design is to let the
    // command continue to the end of the rank and we do diagnostics on the
    // CE counts found in the per-symbol counters. Therefore, all we need to do
    // is tell the hardware which CE types to count.

    do
    {
        ExtensibleChip * membChip = getConnectedParent( iv_chip, TYPE_MEMBUF );
        const char * reg_str = (0 == iv_chip->getPos()) ? "MBSTR_0" : "MBSTR_1";
        SCAN_COMM_REGISTER_CLASS * mbstr = membChip->getRegister( reg_str );
        o_rc = mbstr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s: 0x%08x", reg_str,
                      membChip->getHuid() );
            break;
        }

        switch ( iv_phase )
        {
            case TD_PHASE_1:
                // Set the per symbol counters to count only soft/inter CEs.
                mbstr->SetBitFieldJustified( 55, 3, 0x6 );
                break;

            case TD_PHASE_2:
                // Set the per symbol counters to count only hard CEs.
                mbstr->SetBitFieldJustified( 55, 3, 0x1 );
                break;

            default: PRDF_ASSERT( false ); // invalid phase
        }

        o_rc = mbstr->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s: 0x%08x", reg_str,
                      membChip->getHuid() );
            break;
        }

        // Start the time based scrub procedure on this slave rank.
        o_rc = startTdScrub<TYPE_MBA>( iv_chip, iv_rank, SLAVE_RANK, stopCond );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                      iv_chip->getHuid(), getKey() );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class TpsEvent<TYPE_MCA>;
template class TpsEvent<TYPE_MBA>;

//------------------------------------------------------------------------------

} // end namespace PRDF

