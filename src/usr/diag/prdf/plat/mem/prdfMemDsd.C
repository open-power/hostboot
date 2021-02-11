/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemDsd.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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

/** @file prdfMemDsd_rt.C */

// Platform includes
#include <prdfMemDsd.H>

#include <exp_defaults.H>
#include <exp_rank.H>
#include <kind.H>
#include <hwp_wrappers.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

template<TARGETING::TYPE T>
uint32_t DsdEvent<T>::checkEcc( const uint32_t & i_eccAttns,
                                STEP_CODE_DATA_STRUCT & io_sc,
                                bool & o_done )
{
    #define PRDF_FUNC "[DsdEvent<T>::checkEcc] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( i_eccAttns & MAINT_UE )
        {
            PRDF_TRAC( "[DsdEvent] UE Detected: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintUE );

            // At this point we don't actually have an address for the UE. The
            // best we can do is get the address in which the command stopped.
            MemAddr addr;
            o_rc = getMemMaintAddr<T>( iv_chip, addr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            o_rc = MemEcc::handleMemUe<T>( iv_chip, addr,
                                           UE_TABLE::SCRUB_UE, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            #ifdef __HOSTBOOT_RUNTIME
            // Because of the UE, any further TPS requests will likely have no
            // effect. So ban all subsequent requests.
            MemDbUtils::banTps<T>( iv_chip, addr.getRank() );
            #endif

            // Leave the mark in place and abort this procedure.
            o_done = true; break;
        }

        if ( i_eccAttns & MAINT_RCE_ETE )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintRETRY_CTE );

            // Add the rank to the callout list.
            MemoryMru mm { iv_chip->getTrgt(), iv_rank,
                           MemoryMruData::CALLOUT_RANK };
            io_sc.service_data->SetCallout( mm );

            // Make the error log predictive.
            io_sc.service_data->setServiceCall();

            // Don't abort continue the procedure.
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t DsdEvent<T>::verifySpare( const uint32_t & i_eccAttns,
                                   STEP_CODE_DATA_STRUCT & io_sc,
                                   bool & o_done )
{
    #define PRDF_FUNC "[DsdEvent<T>::verifySpare] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( TD_PHASE_1 != iv_phase ) break; // nothing to do

        o_done = true;

        // If it is safe to remove the chip mark, do so. Then the DRAM spare
        // has been applied successfully.
        if ( MarkStore::isSafeToRemoveChipMark<T>( iv_chip, iv_rank ) )
        {
            PRDF_TRAC( "[DsdEvent] DRAM spare applied successfully: "
                       "0x%08x,0x%02x", iv_chip->getHuid(), getKey() );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_DsdDramSpared );

            o_rc = MarkStore::clearChipMark<T>( iv_chip, iv_rank );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "clearChipMark(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }
        }
        // Else if it is not safe to remove the chip mark, the DRAM spare is bad
        else
        {
            PRDF_TRAC( "[DsdEvent] DRAM spare is bad: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_DsdBadSpare );

            // TODO TMP_CNP follow steps in Once VCM Verified
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t DsdEvent<TYPE_OCMB_CHIP>::startCmd()
{
    #define PRDF_FUNC "[DsdEvent<TYPE_OCMB_CHIP>::startCmd] "

    uint32_t o_rc = SUCCESS;

    mss::mcbist::stop_conditions<mss::mc_type::EXPLORER> stopCond;

    // Set the per-symbol counters to count all 3 CE types: hard, soft, int
    stopCond.set_nce_soft_symbol_count_enable( mss::ON);
    stopCond.set_nce_inter_symbol_count_enable(mss::ON);
    stopCond.set_nce_hard_symbol_count_enable( mss::ON);

    // Set the per-symbol MCE counters to count only hard MCEs
    stopCond.set_mce_hard_symbol_count_enable(mss::ON);

    // Start the time based scrub procedure on this master rank.
    o_rc = startTdScrub<TYPE_OCMB_CHIP>( iv_chip, iv_rank, MASTER_RANK,
                                         stopCond );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                  iv_chip->getHuid(), getKey() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t DsdEvent<T>::startNextPhase( STEP_CODE_DATA_STRUCT & io_sc )
{
    uint32_t signature = 0;

    switch ( iv_phase )
    {
        case TD_PHASE_0:
            iv_phase  = TD_PHASE_1;
            signature = PRDFSIG_StartDsdPhase1;
            break;

        default: PRDF_ASSERT( false ); // invalid phase
    }

    PRDF_TRAC( "[DsdEvent] Starting DSD Phase %d: 0x%08x,0x%02x",
               iv_phase, iv_chip->getHuid(), getKey() );

    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), signature );

    return startCmd();
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class DsdEvent<TYPE_OCMB_CHIP>;

} // end namespace PRDF

