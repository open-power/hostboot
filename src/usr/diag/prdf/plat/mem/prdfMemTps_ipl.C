/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTps_ipl.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MCA>::nextStep( STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::nextStep] "

    uint32_t o_rc = SUCCESS;

    o_done = false;

    do
    {
        //only done in MNFG IPL CE Handling mode
        PRDF_ASSERT( isMfgCeCheckingEnabled() );

        //phase 0
        if ( TD_PHASE_0 == iv_phase )
        {
            // Start TPS phase 1
            io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                                  PRDFSIG_StartTpsPhase1 );

            PRDF_TRAC( PRDF_FUNC "Starting TPS Phase 1" );

            o_rc = startTpsPhase1<TYPE_MCA>( iv_chip, iv_rank );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startTpsPhase1(0x%08x,m%ds%d) failed",
                          iv_chip->getHuid(), iv_rank.getMaster(),
                          iv_rank.getSlave() );
                break;
            }

            iv_phase = TD_PHASE_1;
        }
        //phase 1/2
        else
        {
            // PHASE_1: Collect soft/intermittent CE for later analysis use.
            // PHASE_2: Callout all hard CEs.
            McaDataBundle * db = getMcaDataBundle( iv_chip );
            o_rc = ( TD_PHASE_1 == iv_phase )
                                ? db->getIplCeStats()->collectStats(  iv_rank)
                                : db->getIplCeStats()->calloutHardCes(iv_rank);
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "collectStats/calloutHardCes(0x%02x) "
                          "failed on 0x%08x", iv_rank.getKey(),
                          iv_chip->getHuid() );
                break;
            }

            //get the ecc attentions
            uint32_t eccAttns;
            o_rc = checkEccFirs<TYPE_MCA>( iv_chip, eccAttns );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Call to 'checkEccFirs' failed on chip: "
                          "0x%08x", iv_chip->getHuid() );
                break;
            }

            //if there was a UE or IUE
            if ( (eccAttns & MAINT_UE) || (eccAttns & MAINT_IUE) )
            {
                PRDF_TRAC( PRDF_FUNC "UE Detected. Aborting this procedure." );
                //UE
                if ( eccAttns & MAINT_UE )
                {
                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_MaintUE );
                }
                //IUE
                else
                {
                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_MaintIUE );
                }

                // Do memory UE handling.
                o_rc = MemEcc::handleMemUe<TYPE_MCA>(iv_chip,
                                                     MemAddr::fromRank(iv_rank),
                                                     UE_TABLE::SCRUB_UE, io_sc);
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "handleMemUe<T>(0x%08x) failed",
                              iv_chip->getHuid() );
                    break;
                }

                //Abort this procedure
                o_done = true;
            }
            //else if there was an MPE
            else if ( eccAttns & MAINT_MPE )
            {
                //Add the mark to the callout list
                MemMark chipMark;
                o_rc = MarkStore::readChipMark<TYPE_MCA>( iv_chip, iv_rank,
                                                          chipMark );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "readChipMark<T>(0x%08x,%d) failed",
                            iv_chip->getHuid(), iv_rank.getMaster() );
                    break;
                }

                MemoryMru memmru( iv_chip->getTrgt(), iv_rank,
                                  chipMark.getSymbol() );
                io_sc.service_data->SetCallout( memmru );

                //Add a VCM procedure to the queue
                MemEcc::addVcmEvent<TYPE_MCA, McaDataBundle *>(iv_chip, iv_rank,
                                                               chipMark, io_sc);

                //Abort this procedure
                o_done = true;
            }
            else
            {
                //Add the rank to the callout list
                MemoryMru memmru(iv_chip->getTrgt(), iv_rank,
                        MemoryMruData::CALLOUT_RANK);
                io_sc.service_data->SetCallout( memmru );

                //phase 1
                if ( TD_PHASE_1 == iv_phase )
                {
                    // Start TPS phase 2
                    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                                      PRDFSIG_StartTpsPhase2 );

                    PRDF_TRAC( PRDF_FUNC "Starting TPS Phase 2" );

                    o_rc = startTpsPhase2<TYPE_MCA>( iv_chip, iv_rank );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "startTpsPhase2(0x%08x,m%ds%d) "
                                  "failed", iv_chip->getHuid(),
                                  iv_rank.getMaster(), iv_rank.getSlave() );
                        break;
                    }

                    iv_phase = TD_PHASE_2;
                }
                //phase 2
                else
                {
                    //Abort this procedure
                    o_done = true;
                }
            }
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// TODO: RTC 157888 Actual implementation of this procedure will be done later.
template<>
uint32_t TpsEvent<TYPE_MBA>::nextStep( STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MBA>::nextStep] "

    uint32_t o_rc = SUCCESS;

    o_done = true;

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

