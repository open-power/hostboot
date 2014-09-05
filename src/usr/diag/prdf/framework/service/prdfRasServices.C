/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/service/prdfRasServices.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

/** @file  prdfRasServices.C
 *  @brief Utility code to parse an SDC and produce the appropriate error log.
 */

#include <prdfRasServices.H>
#include <prdfMfgSync.H>
#include <prdfErrlUtil.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

void ErrDataService::MnfgTrace( ErrorSignature * i_esig,
                                const PfaData & i_pfaData )
{
    #define PRDF_FUNC "[ErrDataService::MnfgTrace] "
    do
    {
        errlHndl_t errl = NULL;
        errl = getMfgSync().syncMfgTraceToFsp(i_esig, i_pfaData);
        if (errl)
        {
            PRDF_ERR(PRDF_FUNC "failed to sync to the FSP");
            PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);
            break;
        }
    }while(0);
    #undef PRDF_FUNC
}

//--------------------------------------------------------------------

void ErrDataService::deallocateDimms( SDC_MRU_LIST & i_mruList )
{
    //No OP for HB
}

//------------------------------------------------------------------------------

void ErrDataService::updateSrc( uint32_t i_user1, uint32_t i_user2,
                                uint32_t i_user3, uint32_t i_user4,
                                uint16_t i_rc )
{
    // We should always have a valid pointer here. If it is NULL, there
    // is some major issue.
    PRDF_ASSERT ( NULL != iv_errl);

    iv_errl->setReasonCode(i_rc);
    iv_errl->addUserData1( PRDF_GET_UINT64_FROM_UINT32( i_user1, i_user2 ));
    iv_errl->addUserData2( PRDF_GET_UINT64_FROM_UINT32( i_user3, i_user4 ));
}

//------------------------------------------------------------------------------

void ErrDataService::createInitialErrl( ATTENTION_TYPE i_attnType )
{
    // We should always have a NULL pointer here. If it is not NULL, there
    // is some major issue.
    PRDF_ASSERT ( NULL == iv_errl );
    using namespace ERRORLOG;

    iv_errl = new ErrlEntry(
                        ERRL_SEV_RECOVERED,
                        PRDF_RAS_SERVICES,
                        PRDF_CODE_FAIL, //ERRL keys off of ReasonCode to set
                                        //creator id.  ReasonCode will later be
                                        //changed to reflect the actual one
                        PRDF_GET_UINT64_FROM_UINT32( 0, 0 ),
                        PRDF_GET_UINT64_FROM_UINT32( 0, 0 ) );
}

//--------------------------------------------------------------------

bool ErrDataService::checkForceTerm( ServiceDataCollector & i_sdc,
                                     TargetHandle_t i_dumpTrgt,
                                     PfaData &io_pfaData )
{
    //Return false from HB
    return false;
}

//------------------------------------------------------------------------------

void ErrDataService::handleUnitCS( TargetHandle_t i_unitCsTarget,
                                   bool & o_initiateHwudump)
{
    // No-op in Hostboot
    o_initiateHwudump = false; // default to not initiate hwudump
}

//------------------------------------------------------------------------------

void ErrDataService::handleChannelFail( TargetHandle_t i_memTarget )
{
    // No-op in Hostboot
}

//------------------------------------------------------------------------------

void ErrDataService::handleCoreUnitCS( TargetHandle_t i_exTarget,
                                       bool & o_initiateHwudump)
{
    // No-op in Hostboot
    o_initiateHwudump = false; // default to not initiate hwudump
}

//------------------------------------------------------------------------------

void ErrDataService::handleNxUnitCS( TargetHandle_t i_nxTarget )
{
    // No-op in Hostboot
}

} // end namespace PRDF

