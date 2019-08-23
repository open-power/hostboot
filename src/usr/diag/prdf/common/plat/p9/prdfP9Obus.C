/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Obus.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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


// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

// Platform includes
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace obus
{

//##############################################################################
//
//                               IOOLFIR
//
//##############################################################################

/**
 * @brief If OBUS is in SMP mode, does defaultMaskedError actions and returns
 *        SUCCESS. Otherwise, returns PRD_SCAN_COMM_REGISTER_ZERO.
 */
int32_t smp_masked( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( obusInSmpMode(i_chip->getTrgt()) )
    {
        // SMP mode: This attention should be masked.
        io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_MED, NO_GARD );
        io_sc.service_data->setFlag( ServiceDataCollector::AT_THRESHOLD );
        io_sc.service_data->setFlag( ServiceDataCollector::SERVICE_CALL );
        return SUCCESS;
    }
    else
    {
        // Non-SMP mode: Try some other action.
        return PRD_SCAN_COMM_REGISTER_ZERO;
    }
}
PRDF_PLUGIN_DEFINE_NS( nimbus_obus,  obus, smp_masked );
PRDF_PLUGIN_DEFINE_NS( cumulus_obus, obus, smp_masked );
PRDF_PLUGIN_DEFINE_NS( axone_obus,   obus, smp_masked );

//------------------------------------------------------------------------------

/**
 * @brief If OBUS is NOT in SMP mode, does defaultMaskedError actions and
 *        returns SUCCESS. Otherwise, returns PRD_SCAN_COMM_REGISTER_ZERO.
 */
int32_t non_smp_masked( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( obusInSmpMode(i_chip->getTrgt()) )
    {
        // SMP mode: Try some other action.
        return PRD_SCAN_COMM_REGISTER_ZERO;
    }
    else
    {
        // Non-SMP mode: This attention should be masked.
        io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_MED, NO_GARD );
        io_sc.service_data->setFlag( ServiceDataCollector::AT_THRESHOLD );
        io_sc.service_data->setFlag( ServiceDataCollector::SERVICE_CALL );
        return SUCCESS;
    }
}
PRDF_PLUGIN_DEFINE_NS( nimbus_obus,  obus, non_smp_masked );
PRDF_PLUGIN_DEFINE_NS( cumulus_obus, obus, non_smp_masked );
PRDF_PLUGIN_DEFINE_NS( axone_obus,   obus, non_smp_masked );

//------------------------------------------------------------------------------

/**
 * @brief If OBUS is NOT in SMP mode, calls out this bus on first occurrence and
 *        returns SUCCESS. Otherwise, returns PRD_SCAN_COMM_REGISTER_ZERO.
 */
int32_t non_smp_callout_bus_th_1( ExtensibleChip * i_chip,
                                 STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( obusInSmpMode(i_chip->getTrgt()) )
    {
        // SMP mode: Try some other action.
        return PRD_SCAN_COMM_REGISTER_ZERO;
    }
    else
    {
        // Non-SMP mode: Callout this bus. Note that Hostboot does not know what
        // is on the other side of this bus and does not have any control over
        // garding/deconfiguring. Therefore, we cannot gard since we will never
        // know if the other side of the bus has been replaced. Also, there is
        // a small probability that the fault could be between the two
        // endpoints. Usually, we would do a procedure callout or call some HWP
        // that would take care of the "everything in between" scenario.
        // However, there is no existing mechanism. For now callout level 2
        // support at low priority.
        io_sc.service_data->SetCallout( i_chip->getTrgt(), MRU_MED, NO_GARD );
        io_sc.service_data->SetCallout( LEVEL2_SUPPORT,    MRU_LOW, NO_GARD );
        io_sc.service_data->setFlag( ServiceDataCollector::AT_THRESHOLD );
        io_sc.service_data->setFlag( ServiceDataCollector::SERVICE_CALL );
        return SUCCESS;
    }
}
PRDF_PLUGIN_DEFINE_NS( nimbus_obus,  obus, non_smp_callout_bus_th_1 );
PRDF_PLUGIN_DEFINE_NS( cumulus_obus, obus, non_smp_callout_bus_th_1 );
PRDF_PLUGIN_DEFINE_NS( axone_obus,   obus, non_smp_callout_bus_th_1 );

//------------------------------------------------------------------------------

/**
 * @brief If OBUS is NOT in SMP mode, calls out level 2 support on first
 *        occurrence and returns SUCCESS. Otherwise, returns
 *        PRD_SCAN_COMM_REGISTER_ZERO.
 */
int32_t non_smp_callout_lvl2_th_1( ExtensibleChip * i_chip,
                                  STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( obusInSmpMode(i_chip->getTrgt()) )
    {
        // SMP mode: Try some other action.
        return PRD_SCAN_COMM_REGISTER_ZERO;
    }
    else
    {
        // Non-SMP mode: Callout this bus on first occurrence.
        io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_MED, NO_GARD );
        io_sc.service_data->setFlag( ServiceDataCollector::AT_THRESHOLD );
        io_sc.service_data->setFlag( ServiceDataCollector::SERVICE_CALL );
        return SUCCESS;
    }
}
PRDF_PLUGIN_DEFINE_NS( nimbus_obus,  obus, non_smp_callout_lvl2_th_1 );
PRDF_PLUGIN_DEFINE_NS( cumulus_obus, obus, non_smp_callout_lvl2_th_1 );
PRDF_PLUGIN_DEFINE_NS( axone_obus,   obus, non_smp_callout_lvl2_th_1 );

//------------------------------------------------------------------------------

/**
 * @brief If OBUS is NOT in SMP mode, calls out this OBUS target and returns
 *        SUCCESS. Otherwise, returns PRD_SCAN_COMM_REGISTER_ZERO.
 */
int32_t non_smp_callout_self( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( obusInSmpMode(i_chip->getTrgt()) )
    {
        // SMP mode: Try some other action.
        return PRD_SCAN_COMM_REGISTER_ZERO;
    }
    else
    {
        // Non-SMP mode: Callout this OBUS target.
        io_sc.service_data->SetCallout( i_chip->getTrgt() );
        return SUCCESS;
    }
}
PRDF_PLUGIN_DEFINE_NS( nimbus_obus,  obus, non_smp_callout_self );
PRDF_PLUGIN_DEFINE_NS( cumulus_obus, obus, non_smp_callout_self );
PRDF_PLUGIN_DEFINE_NS( axone_obus,   obus, non_smp_callout_self );

} // end namespace obus

} // end namespace PRDF

