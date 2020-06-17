/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfCommonPlugins.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
         (UNIT_CS    != i_sc.service_data->getSecondaryAttnType()) )
    {
        i_sc.service_data->clearServiceCall();
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( nimbus_capp,    CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( nimbus_ec,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( nimbus_eq,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( nimbus_ex,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( nimbus_mca,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( nimbus_mcbist,  CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( nimbus_mcs,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( nimbus_obus,    CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( nimbus_pec,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( nimbus_phb,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,    CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( nimbus_xbus,    CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_capp,   CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_dmi,    CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_ec,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_eq,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_ex,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_mc,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_mi,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_obus,   CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_pec,    CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_phb,    CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_proc,   CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( cumulus_xbus,   CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( centaur_membuf, CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( centaur_mba,    CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_capp,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_ec,       CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_eq,       CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_ex,       CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_mc,       CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_mcc,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_mi,       CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_npu,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_obus,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_omic,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_pec,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_phb,      CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_proc,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( axone_xbus,     CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( explorer_ocmb,  CommonPlugins, ClearServiceCallFlag );

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
PRDF_PLUGIN_DEFINE_NS(nimbus_proc,  CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(cumulus_proc, CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(axone_proc,   CommonPlugins, ClearServiceCallFlag_mnfgInfo);

/**
 * @brief   Analyze for unit checkstops on this target.
 * @param   i_chip The chip.
 * @param   io_sc  Step code data struct
 * @returns SUCCESS always
 */
int32_t analyzeUcs( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    return i_chip->Analyze( io_sc, UNIT_CS );
}
PRDF_PLUGIN_DEFINE_NS(axone_mc, CommonPlugins, analyzeUcs);

/**
 * @brief   Will change the gard state of any NVDIMMs in the callout list to
 *          NO_GARD.
 * @param   i_chip The chip.
 * @param   io_sc  The step code data struct.
 * @returns SUCCESS
 */
int32_t ClearNvdimmGardState( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & io_sc )
{
    #ifdef __HOSTBOOT_MODULE

    // Call the sdc to clear the NVDIMM mru list.
    io_sc.service_data->clearNvdimmMruListGard();

    #endif

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS(nimbus_mca,    CommonPlugins, ClearNvdimmGardState);

/**
 * @brief   Will check if any of the DIMMs connected to this chip are NVDIMMs
 *          and send a message to PHYP/Hostboot that save/restore may work. If
 *          we are at IPL, we will callout self no gard instead of garding.
 * @param   i_chip The chip of the DIMM parent.
 * @param   io_sc  The step code data struct.
 * @returns SUCCESS if NVDIMMs found at IPL, PRD_SCAN_COMM_REGISTER_ZERO if not.
 */
int32_t CheckForNvdimms( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    int32_t rc = PRD_SCAN_COMM_REGISTER_ZERO;

    #ifdef CONFIG_NVDIMM
    #ifdef __HOSTBOOT_MODULE

    TargetHandleList dimmList = getConnected( i_chip->getTrgt(), TYPE_DIMM );

    // Always loop through all the dimms so we send the
    // nvdimmNotifyProtChange message for all the NVDIMMs on the target.
    for ( auto & dimm : dimmList )
    {
        // If the callout target is an NVDIMM send a message to
        // PHYP/Hostboot that a save/restore may work, and if we are at
        // IPL, do not gard the target.
        if ( isNVDIMM(dimm) )
        {
            // Send the message to PHYP/Hostboot
            uint32_t l_rc = PlatServices::nvdimmNotifyProtChange( dimm,
                NVDIMM::NVDIMM_RISKY_HW_ERROR );
            if ( SUCCESS != l_rc )
            {
                PRDF_TRAC( "CheckForNvdimms: nvdimmNotifyProtChange(0x%08x)"
                           " failed.", PlatServices::getHuid(dimm) );
                continue;
            }

            #ifndef __HOSTBOOT_RUNTIME
            // IPL
            // We will callout self, no gard. No need for another self callout
            // from the rule code, so return SUCCESS.
            rc = SUCCESS;
            #endif
        }
    }

    if ( SUCCESS == rc )
    {
        // Callout self, no gard
        io_sc.service_data->SetCallout( i_chip->getTrgt(), MRU_MED, NO_GARD );
    }

    #endif // __HOSTBOOT_MODULE
    #endif // CONFIG_NVDIMM

    return rc;
}
PRDF_PLUGIN_DEFINE_NS(nimbus_mcs,    CommonPlugins, CheckForNvdimms);
PRDF_PLUGIN_DEFINE_NS(nimbus_mca,    CommonPlugins, CheckForNvdimms);
PRDF_PLUGIN_DEFINE_NS(nimbus_mcbist, CommonPlugins, CheckForNvdimms);

} // namespace CommonPlugins ends

}// namespace PRDF ends

