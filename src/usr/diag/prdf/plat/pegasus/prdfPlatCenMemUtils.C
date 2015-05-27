/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatCenMemUtils.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

/** @file  prdfPlatCenMemUtils.C
 *  @brief Hostboot Utility functions related to Centaur
 */

#include <prdfCenMemUtils.H>
#include <prdfExtensibleChip.H>
#include <prdfCenMembufDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

namespace MemUtils
{

//------------------------------------------------------------------------------

int32_t mcifirCleanup( ExtensibleChip *i_mbChip,
                       STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[MemUtils::mcifirCleanup] "

    int32_t l_rc = SUCCESS;

    // In hostboot, we need to clear associated bits in the MCIFIR bits.
    do
    {
        CenMembufDataBundle * mbdb = getMembufDataBundle(i_mbChip);
        ExtensibleChip * mcsChip = mbdb->getMcsChip();
        if ( NULL == mcsChip )
        {
            PRDF_ERR( PRDF_FUNC "CenMembufDataBundle::getMcsChip() failed" );
            l_rc = FAIL;
            break;
        }

        // Clear the associated MCIFIR bits for all attention types.
        // NOTE: If there are any active attentions left in the Centaur the
        //       associated MCIFIR bit will be redriven with the next packet on
        //       the bus.
        SCAN_COMM_REGISTER_CLASS * firand = mcsChip->getRegister("MCIFIR_AND");

        firand->setAllBits();
        firand->ClearBit(12); // CS
        firand->ClearBit(15); // RE
        firand->ClearBit(16); // SPA
        firand->ClearBit(17); // maintenance command complete

        l_rc = firand->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MCIFIR_AND write failed" );
            break;
        }

    } while (0);

    return l_rc;

    #undef PRDF_FUNC
}

} // end namespace MemUtils

} // end namespace PRDF
