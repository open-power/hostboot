/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaTdCtlr_common.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        setTdSignature( io_sc, PRDFSIG_VcmVerified );

        if ( areDramRepairsDisabled() )
        {
            iv_tdState = NO_OP; // The TD procedure is complete.

            io_sc.service_data->setServiceCall();

            break; // nothing else to do.
        }

        // If there is a symbol mark on the same DRAM as the newly verified chip
        // mark, remove the symbol mark.
        const uint8_t cmDram = iv_mark.getCM().getDram();
        if ( cmDram == iv_mark.getSM().getDram() )
        {
            iv_mark.clearSM();
            bool blocked; // Won't be blocked because chip mark is in place.
            o_rc = mssSetMarkStore( iv_mbaTrgt, iv_rank, iv_mark, blocked );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "mssSetMarkStore() failed" );
                break;
            }
        }

        bool startDsdProcedure = false;

        // Read VPD.
        CenDqBitmap bitmap;
        o_rc = getBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed" );
            break;
        }

        // The chip mark is considered verified, so set it in VPD.
        o_rc = bitmap.setDram( iv_mark.getCM() );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setDram() failed" );
            break;
        }

        uint8_t ps = iv_mark.getCM().getPortSlct();
        uint8_t spareConfig = ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE;
        o_rc = getDimmSpareConfig( iv_mbaTrgt, iv_rank, ps,
                                   spareConfig );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getDimmSpareConfig() failed" );
            break;
        }

        // Check if DRAM spare is present. Also, ECC spares are available on all
        // x4 DIMMS.
        if ( ( ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE != spareConfig ) || iv_x4Dimm )
        {
            // Get the current spares in hardware.
            CenSymbol sp0, sp1, ecc;
            o_rc = mssGetSteerMux( iv_mbaTrgt, iv_rank, sp0, sp1, ecc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed" );
                break;
            }

            // If the verified chip mark is on a spare then the spare is bad and
            // hardware can not steer it to another DRAM even if one is
            // available (e.g. ECC spare). In this this case, make error log
            // predictive (remember that the chip mark has already been added to
            // the callout list.
            if ( ( cmDram == (0 == ps ? sp0.getDram() : sp1.getDram()) ) ||
                 ( cmDram == ecc.getDram() ) )
            {
                setTdSignature( io_sc, PRDFSIG_VcmBadSpare );
                io_sc.service_data->setServiceCall();
            }
            else
            {
                // Certain DIMMs may have had spares intentially made
                // unavailable by the manufacturer. Check the VPD for available
                // spares. Note that a x4 DIMM has DRAM spares and ECC spares,
                // so check for availability on both.
                bool dramSparePossible = false;
                bool eccSparePossible  = false;
                o_rc = bitmap.isSpareAvailable( ps, dramSparePossible,
                                                eccSparePossible );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "isDramSpareAvailable() failed" );
                    break;
                }

                if ( dramSparePossible &&
                     (0 == ps ? !sp0.isValid() : !sp1.isValid()) )
                {
                    // A spare DRAM is available.
                    startDsdProcedure = true;
                }
                else if ( eccSparePossible && !ecc.isValid() )
                {
                    startDsdProcedure = true;
                    iv_isEccSteer = true;
                }
                else
                {
                    // Chip mark is in place and sparing is not possible.
                    setTdSignature( io_sc, PRDFSIG_VcmCmAndSpare );
                    io_sc.service_data->setServiceCall();

                    // The mark has already been added to the callout list.
                    // Callout the used spares, if they exists.
                    if ( sp0.isValid() )
                    {
                        MemoryMru memmru ( iv_mbaTrgt, iv_rank, sp0 );
                        io_sc.service_data->SetCallout( memmru );
                    }
                    if ( sp1.isValid() )
                    {
                        MemoryMru memmru ( iv_mbaTrgt, iv_rank, sp1 );
                        io_sc.service_data->SetCallout( memmru );
                    }
                    if ( ecc.isValid() )
                    {
                        MemoryMru memmru ( iv_mbaTrgt, iv_rank, ecc );
                        io_sc.service_data->SetCallout( memmru );
                    }
                }
            }
        }
        else // DRAM spare not supported.
        {
            // Not able to do dram sparing. If there is a symbol mark, there are
            // no repairs available so call it out and set the error log to
            // predictive.
            if ( iv_mark.getSM().isValid() )
            {
                setTdSignature( io_sc, PRDFSIG_VcmCmAndSm );
                io_sc.service_data->setServiceCall();
            }
        }

        // Write VPD.
        o_rc = setBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setBadDqBitmap() failed" );
            break;
        }

        // Start DSD Phase 1, if possible.
        if ( startDsdProcedure )
        {
            o_rc = startDsdPhase1( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startDsdPhase1() failed" );
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
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        setTdSignature( io_sc, PRDFSIG_DsdBadSpare );
        io_sc.service_data->setServiceCall();

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
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed" );
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
                PRDF_ERR( PRDF_FUNC "setDramSpare() failed" );
                break;
            }
        }

        o_rc = setBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setBadDqBitmap() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

} // end namespace PRDF

