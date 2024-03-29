/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/rowRepairsFuncs.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2023                        */
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
#include <rowRepairsFuncs.H>
#include <string.h>
#include <attribute_service.H>
#include <target.H>
#include <errl/errlmanager.H>
#include <mss_generic_consts.H>
#include <lib/shared/exp_consts.H>

using namespace TARGETING;

extern "C"
{

using namespace mss;

fapi2::ReturnCode __getDimmRepairData( const fapi2::Target
    <fapi2::TARGET_TYPE_MEM_PORT|fapi2::TARGET_TYPE_OCMB_CHIP> & i_fapiTrgt,
    const uint8_t i_dimm,
    const uint8_t i_rank,
    TARGETING::TargetHandle_t & o_dimmTrgt,
    uint8_t (&o_data)[MAX_RANK_PER_DIMM]
                     [ROW_REPAIR_BYTE_COUNT],
    const uint8_t i_port )
{
    fapi2::ReturnCode l_rc;

    do
    {
        // Check parameters.
        if ( (i_dimm >= exp::sizes::MAX_DIMM_PER_PORT) ||
             (i_rank >= exp::sizes::MAX_RANK_PER_DIMM) )
        {
            FAPI_ERR( "__getDimmRepairData: Bad parameter. "
                      "i_dimm:%d i_rank:%d", i_dimm, i_rank );
            l_rc = fapi2::FAPI2_RC_INVALID_ATTR_GET;
            break;
        }

        errlHndl_t l_errl = nullptr;
        TARGETING::TargetHandle_t l_trgt = nullptr;

        l_errl = fapi2::platAttrSvc::getTargetingTarget(i_fapiTrgt, l_trgt);
        if ( l_errl )
        {
            FAPI_ERR( "__getDimmRepairData: Error from getTargetingTarget" );
             // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        // Get all functional DIMMs
        TargetHandleList l_dimmList;
        getChildAffinityTargets( l_dimmList, l_trgt, CLASS_NA, TYPE_DIMM );

        for ( auto &dimmTrgt : l_dimmList )
        {
            // Get and compare the port
            // TODO: check dimm ATTR_MEM_PORT if support for it is added back
            TargetHandle_t memport = getAffinityParent(dimmTrgt, TYPE_MEM_PORT);
            uint8_t l_port = memport->getAttr<ATTR_REL_POS>();

            if ( l_port == i_port )
            {
                // Get and compare the dimm
                const uint8_t l_dimm =
                    dimmTrgt->getAttr<ATTR_POS_ON_MEM_PORT>();

                if ( l_dimm == i_dimm )
                {
                    o_dimmTrgt = dimmTrgt;
                    // Port and dimm are correct, get the row repair data
                    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_fapiDimm(dimmTrgt);
                    l_rc = FAPI_ATTR_GET( fapi2::ATTR_ROW_REPAIR_DATA,
                                          l_fapiDimm,
                                          o_data );
                    if ( l_rc ) break;
                }
            }
        }

    }while(0);

    if ( l_rc )
    {
        FAPI_ERR( "__getDimmRepairData: Error getting ATTR_ROW_REPAIR_DATA." );
    }

    return l_rc;
}

//------------------------------------------------------------------------------
fapi2::ReturnCode getRowRepair( const fapi2::Target
    <fapi2::TARGET_TYPE_MEM_PORT|fapi2::TARGET_TYPE_OCMB_CHIP> & i_fapiTrgt,
    const uint8_t i_dimm,
    const uint8_t i_rank,
    uint8_t (&o_data)[ROW_REPAIR_BYTE_COUNT],
    const uint8_t i_port )
{
    FAPI_INF( ">>getRowRepair. %d:%d", i_dimm, i_rank );

    fapi2::ReturnCode l_rc;

    do
    {

        uint8_t l_data[MAX_RANK_PER_DIMM][ROW_REPAIR_BYTE_COUNT];
        TARGETING::TargetHandle_t l_dimmTrgt = nullptr;

        // Check parameters and get Row Repair Data
        l_rc = __getDimmRepairData( i_fapiTrgt, i_dimm, i_rank,
                                    l_dimmTrgt, l_data, i_port );
        if ( l_rc )
        {
            FAPI_ERR( "getRowRepair: Error from __getDimmRepairData." );
            break;
        }

        // Write contents of DQ bitmap for specific rank to o_data.
        memcpy( o_data, l_data[i_rank], ROW_REPAIR_BYTE_COUNT );

    }while(0);

    FAPI_INF( "<<getRowRepair" );

    return l_rc;
}

//------------------------------------------------------------------------------
fapi2::ReturnCode setRowRepair( const fapi2::Target
    <fapi2::TARGET_TYPE_MEM_PORT|fapi2::TARGET_TYPE_OCMB_CHIP> & i_fapiTrgt,
    const uint8_t i_dimm,
    const uint8_t i_rank,
    uint8_t (&i_data)[ROW_REPAIR_BYTE_COUNT],
    const uint8_t i_port )
{
    FAPI_INF( ">>setRowRepair. %d:%d", i_dimm, i_rank );

    fapi2::ReturnCode l_rc;

    do
    {
        uint8_t l_data[MAX_RANK_PER_DIMM][ROW_REPAIR_BYTE_COUNT];
        TARGETING::TargetHandle_t l_dimmTrgt = nullptr;

        // Check parameters and get row repair data.
        l_rc = __getDimmRepairData( i_fapiTrgt, i_dimm, i_rank,
                                    l_dimmTrgt, l_data, i_port );
        if ( l_rc )
        {
            FAPI_ERR( "setRowRepair: Error from __getDimmRepairData." );
            break;
        }

        // Update the row repair data.
        memcpy( l_data[i_rank], i_data, ROW_REPAIR_BYTE_COUNT );

        fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_fapiDimm(l_dimmTrgt);
        l_rc = FAPI_ATTR_SET( fapi2::ATTR_ROW_REPAIR_DATA,
                              l_fapiDimm,
                              l_data );
        if ( l_rc )
        {
            FAPI_ERR("setRowRepair: Error setting ATTR_ROW_REPAIR_DATA.");
        }
    }while(0);

    FAPI_INF( "<<setRowRepair" );

    return l_rc;
}

} // extern "C"
