/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemVcm_rt.C $                  */
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

/** @file prdfMemVcm_rt.C */

// Platform includes
#include <prdfMemDqBitmap.H>
#include <prdfMemVcm.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//##############################################################################
//
//                               Helper functions
//
//##############################################################################

template<TARGETING::TYPE T>
VcmFalseAlarm * __getFalseAlarmCounter( ExtensibleChip * i_chip );

template<>
VcmFalseAlarm * __getFalseAlarmCounter<TYPE_OCMB_CHIP>(ExtensibleChip * i_chip)
{
    return getOcmbDataBundle(i_chip)->getVcmFalseAlarmCounter();
}

//##############################################################################
//
//                            Generic Specializations
//
//##############################################################################

template<TARGETING::TYPE T>
uint32_t VcmEvent<T>::checkEcc( const uint32_t & i_eccAttns,
                                STEP_CODE_DATA_STRUCT & io_sc,
                                bool & o_done )
{
    #define PRDF_FUNC "[VcmEvent<T>::checkEcc] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( i_eccAttns & MAINT_UE )
        {
            PRDF_TRAC( PRDF_FUNC "UE Detected: 0x%08x,0x%02x",
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

            // Because of the UE, any further TPS requests will likely have no
            // effect. So ban all subsequent requests.
            MemDbUtils::banTps<T>( iv_chip, addr.getRank() );

            // Leave the mark in place and abort this procedure.
            o_done = true; break;
        }

        if ( mfgMode() && (i_eccAttns & MAINT_IUE) )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintIUE );

            o_rc = MemEcc::handleMemIue<T>( iv_chip, iv_rank, io_sc );
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
template
uint32_t VcmEvent<TYPE_OCMB_CHIP>::checkEcc( const uint32_t & i_eccAttns,
                                              STEP_CODE_DATA_STRUCT & io_sc,
                                              bool & o_done );

//------------------------------------------------------------------------------

template<>
uint32_t VcmEvent<TYPE_OCMB_CHIP>::cleanup( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[VcmEvent::cleanup] "

    uint32_t o_rc = SUCCESS;

    do
    {
        o_rc = MarkStore::chipMarkCleanup<TYPE_OCMB_CHIP>( iv_chip, iv_rank,
                                                           io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "chipMarkCleanup(0x%08x,0x%02x) failed",
                      iv_chip->getHuid(), iv_rank.getKey() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

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
        uint8_t dram = iv_mark.getSymbol().getDram();
        if ( __getFalseAlarmCounter<T>(iv_chip)->inc(iv_rank, dram, io_sc) )
        {
            // False alarm threshold has been reached.

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_VcmFalseAlarmTH );

            PRDF_TRAC( PRDF_FUNC "False alarm threshold: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            // Leave the chip mark in place and do any necessary cleanup.
            o_rc = cleanup( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "cleanup() failed" );
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
template class VcmEvent<TYPE_OCMB_CHIP>;

//------------------------------------------------------------------------------

} // end namespace PRDF

