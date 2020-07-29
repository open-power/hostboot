/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Obus.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include <prdfRasServices.H>

#if !defined(__HOSTBOOT_MODULE) && !defined(ESW_SIM_COMPILE)
#include <hwsvSvrErrl.H>
#endif


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
PRDF_PLUGIN_DEFINE_NS( axone_obus,   obus, non_smp_masked );

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
PRDF_PLUGIN_DEFINE_NS( axone_obus,   obus, non_smp_callout_self );


// CAPI Callouts
int32_t callout_CapiBrick( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc,
                           uint32_t i_brickNum )
{
    int32_t              l_rc = SUCCESS;
    PredicateCTM         l_unitMatch(CLASS_UNIT, TYPE_OBUS_BRICK );
    TargetHandleList     l_brickList;
    uint32_t             l_brickNum;
    bool                 l_calloutDone = false;
    errlHndl_t           l_elog = nullptr;


    // Need the obus target
    TargetHandle_t  l_obusTrgt = i_chip->getTrgt();
    TYPE            l_targType = getTargetType(l_obusTrgt);


    // Validate we have expected target
    if ( TYPE_OBUS != l_targType )
    {
        PRDF_ERR("callout_CapiBrick Invalid Target(%d) on Brick:%d",
                  l_targType, i_brickNum );
        PRDF_ASSERT(false);
    }

    // Get the bricks associated with this OBUS
    targetService().getAssociated(
                l_brickList,   l_obusTrgt,
                TARGETING::TargetService::CHILD,
                TARGETING::TargetService::ALL,
                &l_unitMatch);

    // Find matching OBUS brick in the list
    for (const auto & l_brick : l_brickList)
    {
        // get unit number for current obus brick
        l_brickNum = (l_brick->getAttr<ATTR_CHIP_UNIT>()) % 3;

        // We want brick specified by caller
        if ( i_brickNum == l_brickNum )
        {
            l_elog = ServiceGeneratorClass::ThisServiceGenerator().getErrl();
            if ( nullptr != l_elog )
            {
                l_calloutDone = true;

    #ifdef __HOSTBOOT_MODULE
                l_elog->addPartCallout( l_brick,
                                        HWAS:: OPEN_CAPI_ADAPTER_PART_TYPE,
                                        HWAS::SRCI_PRIORITY_HIGH );

    #else
        // FSP code
        #ifndef ESW_SIM_COMPILE
                errlHndl_t  l_hwsvElog = nullptr;

                l_hwsvElog = HWSV::SvrError::handleOpenCAPIPartCallout(
                                    l_brick,  SRCI_PRIORITY_HIGH,
                                    HWAS::OPEN_CAPI_ADAPTER_PART_TYPE, l_elog );

                if (NULL != l_hwsvElog)
                {
                    PRDF_ERR("callout_CapiBrick failed - brick %d", i_brickNum);
                    l_hwsvElog->CollectTrace(PRDF_COMP_NAME, 1024);
                    l_hwsvElog->commit( PRDF_COMP_ID, ERRL_ACTION_REPORT );
                    delete l_hwsvElog;
                    l_hwsvElog = NULL;
                } // end if failed callout

       #endif // not simulation

    #endif  // else FSP side

            } // end if we have elog

            // Exit loop since we found the right OBUS brick
            break;
        } // end if matching bricknum

    } // end for loop thru brick list


    // Did we succeed finding brick for callout ?
    if ( false == l_calloutDone )
    {
        // Something is wrong, so get level2 involved
        io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_MED, NO_GARD );
    } // end if no callout done


    // Ensure elog is seen
    io_sc.service_data->setFlag( ServiceDataCollector::AT_THRESHOLD );
    io_sc.service_data->setFlag( ServiceDataCollector::SERVICE_CALL );


    return l_rc;

}  // end callout_CapiBrick


/**
 * @brief If OBUS is NOT in SMP mode, calls out OBUS BRICK 0 on first
 *        occurrence and returns SUCCESS. Note that OBUS link0 is
 *        related to OBUS BRICK 0.
 *        Otherwise, returns PRD_SCAN_COMM_REGISTER_ZERO.
 */
int32_t non_smp_callout_link_0_th_1( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & io_sc )
{
    int32_t  l_rc = SUCCESS;

    if ( obusInSmpMode(i_chip->getTrgt()) )
    {
        // SMP mode: Try some other action.
        l_rc = PRD_SCAN_COMM_REGISTER_ZERO;
    }
    else
    {
        l_rc = callout_CapiBrick(i_chip, io_sc, 0);
    }

    return l_rc;

} // end callout_CAPI_0
PRDF_PLUGIN_DEFINE_NS( axone_obus,   obus, non_smp_callout_link_0_th_1 );


/**
 * @brief If OBUS is NOT in SMP mode, calls out OBUS BRICK 2 on first
 *        occurrence and returns SUCCESS. Note that OBUS link1 is
 *        related to OBUS BRICK 2.
 *        Otherwise, returns PRD_SCAN_COMM_REGISTER_ZERO.
 */int32_t non_smp_callout_link_1_th_1( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & io_sc )
{
    int32_t  l_rc = SUCCESS;

    if ( obusInSmpMode(i_chip->getTrgt()) )
    {
        // SMP mode: Try some other action.
        l_rc = PRD_SCAN_COMM_REGISTER_ZERO;
    }
    else
    {
        l_rc = callout_CapiBrick(i_chip, io_sc, 2);
    }

    return l_rc;

} // end callout_CAPI_2
PRDF_PLUGIN_DEFINE_NS( axone_obus,   obus, non_smp_callout_link_1_th_1 );


} // end namespace obus

} // end namespace PRDF

