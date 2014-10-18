/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfFsiCapUtil.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

/** @file prdfFsiCapUtil.C */

#include <UtilHash.H>
#include <prdfTrace.H>
#include <prdfFsiCapUtil.H>
#include <prdfPlatServices.H>
#include <prdfExtensibleChip.H>
#include <iipServiceDataCollector.h>

using namespace TARGETING;
namespace PRDF
{
using namespace PlatServices;

namespace PLL
{

void captureFsiStatusReg( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[PLL::captureFsiStatusReg] "

    uint32_t u32Data = 0;

    int32_t rc = getCfam( i_chip, io_sc, 0x00001007, u32Data );

    if ( SUCCESS == rc )
    {
        BIT_STRING_ADDRESS_CLASS bs (0, 32, (CPU_WORD *) &u32Data);

        io_sc.service_data->GetCaptureData().Add(
                            i_chip->GetChipHandle(),
                            ( Util::hashString("CFAM_FSI_STATUS") ^
                              i_chip->getSignatureOffset() ),
                            bs);
    }

    if( TYPE_PROC == getTargetType(i_chip->GetChipHandle()) )
    {
        uint32_t fsiGp7 = 0;
        rc = getCfam( i_chip, io_sc, 0x2816, fsiGp7 );
        if ( SUCCESS == rc )
        {
            BIT_STRING_ADDRESS_CLASS bs (0, 32, (CPU_WORD *) &fsiGp7);

            io_sc.service_data->GetCaptureData().Add(
                                i_chip->GetChipHandle(),
                                ( Util::hashString("CFAM_FSI_GP7") ^
                                  i_chip->getSignatureOffset() ),
                                bs);
        }
    }

    #undef PRDF_FUNC
}

} // end namespace PLL

} // end namespace PRDF
