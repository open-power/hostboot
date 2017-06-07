/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemVcm_rt.C $                  */
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

/** @file prdfMemVcm_rt.C */

// Platform includes
#include <prdfMemVcm.H>
#include <prdfP9McaDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//##############################################################################
//
//                          Generic template functions
//
//##############################################################################

template<TARGETING::TYPE T>
uint32_t VcmEvent<T>::falseAlarm( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[VcmEvent::falseAlarm] "

    uint32_t o_rc = SUCCESS;

    PRDF_TRAC( PRDF_FUNC "Chip mark false alarm: 0x%08x,0x%02x",
               iv_chip->getHuid(), getKey() );

    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                      PRDFSIG_VcmFalseAlarm );

    do
    {
        // If DRAM repairs are disabled, make the error log predictive.
        if ( areDramRepairsDisabled() )
        {
            io_sc.service_data->setServiceCall();
            break; // Nothing more to do.
        }

        // Increment the false alarm counter and check threshold.
        if ( cv_falseAlarm.inc(iv_chip, getKey(), io_sc) )
        {
            // False alarm threshold has been reached. Leave the mark in place
            // and treat the chip mark as verified.

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_VcmFalseAlarmTH );

            PRDF_TRAC( PRDF_FUNC "False alarm threshold: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            o_rc = verified( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "verified() failed" );
                break;
            }
        }
        else
        {
            // Remove the chip mark.
            o_rc = MarkStore::clearChipMark<T>( iv_chip, iv_rank );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "clearChipMark(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class VcmEvent<TYPE_MCA>;
template class VcmEvent<TYPE_MBA>;

//##############################################################################
//
//                          Specializations for MCA
//
//##############################################################################

template<>
TdFalseAlarm VcmEvent<TYPE_MCA>::cv_falseAlarm
                            = TdFalseAlarm { 4, ThresholdResolution::ONE_DAY };

//------------------------------------------------------------------------------

template<>
uint32_t VcmEvent<TYPE_MCA>::checkEcc( const uint32_t & i_eccAttns,
                                       STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[VcmEvent<TYPE_MCA>::checkEcc] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( i_eccAttns & MAINT_UE )
        {
            PRDF_TRAC( PRDF_FUNC "UE Detected: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintUE );

            o_rc = MemEcc::handleMemUe<TYPE_MCA>( iv_chip,
                                                  MemAddr::fromRank(iv_rank),
                                                  UE_TABLE::SCRUB_UE, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // Leave the mark in place and abort this procedure.
            o_done = true; break;
        }

        if ( mfgMode() && (i_eccAttns & MAINT_IUE) )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintIUE );

            o_rc = MemEcc::handleMemIue<TYPE_MCA, McaDataBundle *>( iv_chip,
                                                                    iv_rank,
                                                                    io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemIue(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // If service call is set, then IUE threshold was reached.
            if ( io_sc.service_data->queryServiceCall() )
            {
                PRDF_TRAC( PRDF_FUNC "IUE threshold detected: 0x%08x,0x%02x",
                           iv_chip->getHuid(), getKey() );

                // Leave the mark in place and abort this procedure.
                o_done = true; break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//
//                          Specializations for MBA
//
//##############################################################################

template<>
TdFalseAlarm VcmEvent<TYPE_MBA>::cv_falseAlarm
                        = TdFalseAlarm { 4, 7 * ThresholdResolution::ONE_DAY };

//------------------------------------------------------------------------------

template<>
uint32_t VcmEvent<TYPE_MBA>::checkEcc( const uint32_t & i_eccAttns,
                                       STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[VcmEvent<TYPE_MBA>::checkEcc] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( i_eccAttns & MAINT_UE )
        {
            PRDF_TRAC( PRDF_FUNC "UE Detected: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintUE );

            /* TODO: RTC 157888
            o_rc = MemEcc::handleMemUe<TYPE_MBA>( iv_chip,
                                                  MemAddr::fromRank(iv_rank),
                                                  UE_TABLE::SCRUB_UE, io_sc );
            */
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

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
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

