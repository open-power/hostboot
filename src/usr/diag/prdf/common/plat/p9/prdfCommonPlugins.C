/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfCommonPlugins.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/** @file  prdfCommonPlugins.C
 *  @brief Contains plugin code that is common for multiple chiplets
 */

#include <prdfGlobal.H>
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfPlatServices.H>
#include <xspprdService.h>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace CommonPlugins
{


/**
 * @brief   When not in MNFG mode, clear the service call flag so that
 *          thresholding will still be done, but no visible error log committed.
 * @param   i_chip EX chip
 * @param   i_sc   Step code data struct
 * @returns SUCCESS always
 */
int32_t ClearServiceCallFlag( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    if ( i_sc.service_data->IsAtThreshold() && !mfgMode() &&
         (CHECK_STOP != i_sc.service_data->getPrimaryAttnType()) &&
         (!i_sc.service_data->queryFlag(ServiceDataCollector::UNIT_CS)) )
    {
        i_sc.service_data->clearServiceCall();
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p9_nimbus,  CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_xbus,    CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_obus,    CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_ex,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_ec,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_eq,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_pec,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_mcbist,  CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_mca,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_capp,    CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_phb,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_mcs,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_cumulus, CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_mc,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_mi,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p9_dmi,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cen_centaur,CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cen_mba,    CommonPlugins, ClearServiceCallFlag );

/**
 * @brief   Clear the service call flag (field and MNFG) so that thresholding
 *          will still be done, but no visible error log committed.
 * @param   i_chip PROC
 * @param   i_sc   Step code data struct
 * @returns SUCCESS always
 */
int32_t ClearServiceCallFlag_mnfgInfo( ExtensibleChip * i_chip,
                                       STEP_CODE_DATA_STRUCT & i_sc )
{
    if ( i_sc.service_data->IsAtThreshold() )
    {
        i_sc.service_data->clearServiceCall();
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS(p9_nimbus,  CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p9_cumulus, CommonPlugins, ClearServiceCallFlag_mnfgInfo);

/**
 * @brief   PRD will perform error isolation for certain errors that may cause
 *          a HWP to fail.
 * @param   i_chip PROC or MCA
 * @param   i_sc   Step code data struct
 * @returns SUCCESS always
 */
int32_t HwpErrorIsolation( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    #if defined (__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)

    TargetHandle_t trgt = i_chip->getTrgt();
    uint32_t plid = trgt->getAttr<ATTR_PRD_HWP_PLID>();

    // Check for non-zero value in PLID attribute
    if ( 0 != plid )
    {
        // Link HWP PLID to PRD error log
        errlHndl_t errl =
            ServiceGeneratorClass::ThisServiceGenerator().getErrl();
        errl->plid(plid);

        // Make the error log and callouts predictive
        io_sc.service_data->setServiceCall();

        // Clear PRD_HWP_PLID attribute
        trgt->setAttr<ATTR_PRD_HWP_PLID>( 0 );
    }

    #endif

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS(p9_nimbus,  CommonPlugins, HwpErrorIsolation);
PRDF_PLUGIN_DEFINE_NS(p9_cumulus, CommonPlugins, HwpErrorIsolation);
PRDF_PLUGIN_DEFINE_NS(p9_mca,     CommonPlugins, HwpErrorIsolation);

} // namespace CommonPlugins ends

}// namespace PRDF ends

