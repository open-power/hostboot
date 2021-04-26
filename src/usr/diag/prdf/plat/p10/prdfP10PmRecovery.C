/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/p10/prdfP10PmRecovery.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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

#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfP10PmRecovery.H>
#include <prdfErrlUtil.H>

#include <hwas/common/hwas.H>
#include <hwas/common/deconfigGard.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

int32_t pmRecovery( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[pmRecovery] "
    int32_t o_rc = SUCCESS;
    TargetHandle_t  target = i_chip->getTrgt();

    // p10_pm_callout HWP parameters
    RasAction ra = PROC_CHIP_CALLOUT;
    uint32_t deadCores = 0;
    std::vector < StopErrLogSectn > ffdcList;

    do {

    o_rc = pmCallout( target, ra, deadCores, ffdcList );

    if (o_rc != SUCCESS)
    {
        PRDF_ERR(PRDF_FUNC "pmCallout(0x%08x) failed", getHuid(target));
        io_sc.service_data->SetCallout(LEVEL2_SUPPORT, MRU_HIGH);
        io_sc.service_data->SetCallout(target);
        break;
    }

    PRDF_INF(PRDF_FUNC "huid=0x%08x enum=%d cores=0x%08x",
             getHuid(target), ra, deadCores);

    // Get the Global Errorlog PLID and EID
    errlHndl_t globalErrl =
        ServiceGeneratorClass::ThisServiceGenerator().getErrl();
    uint32_t plid = globalErrl->plid();

    // Runtime deconfig lost cores
    for ( uint32_t pos = 0; pos < MAX_EC_PER_PROC; ++pos )
    {
        if ( deadCores & (0x80000000 >> pos) )
        {
            // Get the core
            TargetHandle_t coreTgt = getConnectedChild( target, TYPE_CORE, pos);
            if (coreTgt == nullptr)
            {
                // This could happen in fused core mode where the other core in
                // the pair was just deconfigured.
                PRDF_INF(PRDF_FUNC "Connected core already non-functional: "
                         "huid=0x%08x pos=%d", getHuid(target), pos);
                continue;
            }

            // Call Deconfig
            errlHndl_t errl = nullptr;
            errl = HWAS::theDeconfigGard().deconfigureTargetAtRuntime(
                       coreTgt,
                       HWAS::DeconfigGard::FULLY_AT_RUNTIME,
                       globalErrl );

            if (errl)
            {
                PRDF_ERR( PRDF_FUNC "Deconfig failed: huid=0x%08x",
                          getHuid(coreTgt));
                PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            }
        }
    }

    // Make callout indicated by p10_pm_callout
    switch (ra)
    {
        case NO_CALLOUT:
            break; // Do nothing

        case PROC_CHIP_CALLOUT:
            io_sc.service_data->SetCallout(target);
            break;

        default:
            PRDF_ERR(PRDF_FUNC "Unexpected callout: huid=0x%08x enum=%d",
                     getHuid(target), ra);
            io_sc.service_data->SetCallout(LEVEL2_SUPPORT, MRU_HIGH);
            io_sc.service_data->SetCallout(target);
            break;
    }
    // Create errorlog to contain HWP FFDC
    /*@
     * @errortype
     * @reasoncode PRDF_EXTRA_FFDC
     * @severity   ERRL_SEV_INFORMATIONAL
     * @moduleid   PRDF_PM_RECOVERY_FFDC
     * @userdata1  Proc HUID
     * @userdata2  deadCores bit vector
     * @devdesc    An errorlog containing extra FFDC collected by the HWP
     */
    errlHndl_t ffdcErrl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        PRDF_PM_RECOVERY_FFDC,
                                        PRDF_EXTRA_FFDC,
                                        getHuid(target),
                                        deadCores );

    // Add FFDC sections
    for ( auto & ffdcSctn : ffdcList )
    {
        ffdcErrl->addFFDC( PRDF_COMP_ID, ffdcSctn.iv_pBufPtr,
                           ffdcSctn.iv_bufSize, ffdcSctn.iv_subsec,
                           ErrlPmFfdcData );
    }

    // Commit
    ffdcErrl->plid(plid);
    ERRORLOG::errlCommit(ffdcErrl, PRDF_COMP_ID);

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}


} // end namespace PRDF

