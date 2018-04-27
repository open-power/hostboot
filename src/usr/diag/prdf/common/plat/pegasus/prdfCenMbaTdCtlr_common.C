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

