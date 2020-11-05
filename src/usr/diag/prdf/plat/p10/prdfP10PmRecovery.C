/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/p10/prdfP10PmRecovery.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
        PRDF_ERR(PRDF_FUNC "pmCallout failed huid %x", getHuid(target));
        io_sc.service_data->SetCallout(LEVEL2_SUPPORT, MRU_HIGH);
        io_sc.service_data->SetCallout(target);
        break;
    }

    PRDF_TRAC(PRDF_FUNC "lost cores vector %x", deadCores);

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
                PRDF_ERR(PRDF_FUNC "Failed to get child core for huid %x "
                         "core pos %d", getHuid(target), pos);
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
                PRDF_ERR( PRDF_FUNC "Deconfig failed on core %x",
                          getHuid(coreTgt));
                PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            }
        }
    }

    // Make callout indicated by p10_pm_callout
    switch (ra) {
        case PROC_CHIP_CALLOUT:
            PRDF_TRAC(PRDF_FUNC "HUID 0x%08x PROC_CHIP_CALLOUT",
                      getHuid(target));
            io_sc.service_data->SetCallout(target);
            break;
        default:
            PRDF_TRAC(PRDF_FUNC "HUID 0x%08x Unexpected callout enum",
                     getHuid(target));
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

