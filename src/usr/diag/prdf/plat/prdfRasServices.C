/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfRasServices.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2024                        */
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

#include <initservice/initserviceif.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

void ErrDataService::MnfgTrace( ErrorSignature * i_esig,
                                const PfaData & i_pfaData )
{
    #define PRDF_FUNC "[ErrDataService::MnfgTrace] "

    do
    {
        // This is for Hostboot IPL and FSP machines only.
        #ifndef __HOSTBOOT_RUNTIME
        if ( !INITSERVICE::spBaseServicesEnabled() ) break;

        errlHndl_t errl = nullptr;
        errl = getMfgSync().syncMfgTraceToFsp(i_esig, i_pfaData);
        if (errl)
        {
            PRDF_ERR(PRDF_FUNC "failed to sync to the FSP");
            PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);
            break;
        }
        #endif

    } while(0);

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void ErrDataService::updateSrc( uint32_t i_user1, uint32_t i_user2,
                                uint32_t i_user3, uint32_t i_user4,
                                uint16_t i_rc )
{
    // We should always have a valid pointer here. If it is nullptr, there
    // is some major issue.
    PRDF_ASSERT ( nullptr != iv_errl);

    iv_errl->setReasonCode(i_rc);
    iv_errl->addUserData1( PRDF_GET_UINT64_FROM_UINT32( i_user1, i_user2 ));
    iv_errl->addUserData2( PRDF_GET_UINT64_FROM_UINT32( i_user3, i_user4 ));
}

//------------------------------------------------------------------------------

void ErrDataService::createInitialErrl( ATTENTION_TYPE i_attnType )
{
    // We should always have a nullptr pointer here. If it is not nullptr, there
    // is some major issue.
    PRDF_ASSERT ( nullptr == iv_errl );
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

//------------------------------------------------------------------------------


bool ErrDataService::checkForceTerm( const ServiceDataCollector & i_sdc,
                                     TargetHandle_t i_dumpTrgt,
                                     PfaData &io_pfaData )
{
    //Return false from HB
    return false;
}

//------------------------------------------------------------------------------

void ErrDataService::commitErrLog( errlHndl_t & io_errl,
                                   const PfaData & i_pfaData )

{
    errlCommit( io_errl, PRDF_COMP_ID );
    io_errl = nullptr;
}

//------------------------------------------------------------------------------

TargetHandleList ___getOcmbsFromMruList(const SDC_MRU_LIST & i_mruList)
{
    // This function will return a list of OCMB associated with any memory
    // callout in the MRU list.
    TargetHandleList ocmbList;

    // Loop through the callout list
    for (const auto & mru : i_mruList)
    {
        // Skip any callout that is set to NO_GARD
        if (NO_GARD == mru.gardState) continue;

        PRDcallout callout = mru.callout;
        // Check for any memory target callouts
        if (PRDcalloutData::TYPE_TARGET == callout.getType())
        {
            TargetHandle_t target = callout.getTarget();
            TYPE trgtType = getTargetType(target);

            switch(trgtType)
            {
                case TYPE_MEM_PORT:
                case TYPE_DIMM:
                {
                    TargetHandle_t ocmb = getConnectedParent(target,
                        TYPE_OCMB_CHIP);
                    if (std::find(ocmbList.begin(), ocmbList.end(), ocmb) ==
                        ocmbList.end())
                    {
                        ocmbList.push_back(ocmb);
                    }
                    break;
                }
                case TYPE_OCMB_CHIP:
                {
                    if (std::find(ocmbList.begin(), ocmbList.end(), target) ==
                        ocmbList.end())
                    {
                        ocmbList.push_back(target);
                    }
                    break;
                }
                default:
                    break;
            }
        }
        // Check for any memmru callouts
        else if (PRDcalloutData::TYPE_MEMMRU == callout.getType())
        {
            MemoryMru memMru (callout.flatten());

            // Add any DIMMs to the list if they aren't already there
            TargetHandleList dimms = memMru.getCalloutList();
            for (const auto & dimm : dimms)
            {
                if (TYPE_DIMM == getTargetType(dimm))
                {
                    // Get the parent OCMB
                    TargetHandle_t ocmb = getConnectedParent(dimm,
                        TYPE_OCMB_CHIP);

                    if (std::find(ocmbList.begin(), ocmbList.end(), ocmb) ==
                        ocmbList.end())
                    {
                        ocmbList.push_back(ocmb);
                    }
                }
            }
        }
    }

    return ocmbList;
}

//------------------------------------------------------------------------------

void collectPmicTelemetry(const SDC_MRU_LIST & i_mruList, uint32_t i_plid)
{
    // List of ocmbs to collect telemetry for
    TargetHandleList ocmbList = ___getOcmbsFromMruList(i_mruList);

    // Call the function to collect the PMIC telemetry for all DIMMs in the list
    for (const auto & ocmb : ocmbList)
    {
        getPmicTelemetry(ocmb, i_plid);
    }
}

//------------------------------------------------------------------------------

void collectSbeScratchRegData(const SDC_MRU_LIST & i_mruList, uint32_t i_plid )
{
    #ifndef __HOSTBOOT_RUNTIME

    // Only collect the SBE scratch reg data during memdiags
    if (!isInMdiaMode())
    {
        return;
    }

    // List of ocmbs to collect data for
    TargetHandleList ocmbList = ___getOcmbsFromMruList(i_mruList);

    // Call the function to collect the SBE data for all DIMMs in the list
    for (const auto & ocmb : ocmbList)
    {
        // Skip non Odyssey OCMBs
        if (!isOdysseyOcmb(ocmb))
        {
            continue;
        }

        getSbeScratchData(ocmb, i_plid);
    }

    #endif
}

} // end namespace PRDF

