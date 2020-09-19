/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfFsiCapUtil.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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

void __captureFsiReg( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                      uint16_t i_wordAddr, const char * i_regStr )
{
    uint32_t data = 0;

    if ( SUCCESS == getCfam(i_chip, i_wordAddr, data) )
    {
        BitString bs { 32, (CPU_WORD *) &data };

        uint16_t id = Util::hashString(i_regStr) ^ i_chip->getSignatureOffset();

        io_sc.service_data->GetCaptureData().Add( i_chip->getTrgt(), id, bs );
    }
}

template<>
void captureFsiStatusReg<TYPE_PROC>( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_PROC == i_chip->getType() );

    #if defined(__HOSTBOOT_RUNTIME)

    // Do nothing. HBRT does not have any FSI access.

    #elif defined(__HOSTBOOT_MODULE)

    // Hostboot does not have FSI access to the master processor.
    if ( getMasterProc() != i_chip->getTrgt() )
    {
        __captureFsiReg( i_chip, io_sc, 0x1007, "CFAM_FSI_STATUS" );
    }

    #else

    // FSP has full FSI access.
    __captureFsiReg( i_chip, io_sc, 0x1007, "CFAM_FSI_STATUS" );

    #endif
}

} // end namespace PLL

} // end namespace PRDF
