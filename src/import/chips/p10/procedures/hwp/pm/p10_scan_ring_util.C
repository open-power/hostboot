/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_scan_ring_util.C $ */
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
#include "p10_scan_ring_util.H"
#include "p10_hcode_image_defines.H"
#include <fapi2.H>
#include <stdio.h>
///
/// @file   p10_scan_ring_util.C
/// @brief  utility classes and functions for scan ring debug.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot:Phyp:Cro
//

namespace hcodeImageBuild
{
//-------------------------------------------------------------------------

P10FuncModel::P10FuncModel(  ):
    iv_funcCores(0),
    iv_funcExes(0),
    iv_funcQuads(0),
    iv_ddLevel(0),
    iv_chipName(0)
{ }
//-------------------------------------------------------------------------

P10FuncModel::P10FuncModel( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP >& i_procTgt )
{
    iv_funcCores = 0;
    iv_funcExes  = 0;
    iv_funcQuads = 0;

    auto l_core_functional_vector =
        i_procTgt.getChildren<fapi2::TARGET_TYPE_CORE>(fapi2::TARGET_STATE_FUNCTIONAL);
    uint8_t l_corePos = 0;

    for( auto it : l_core_functional_vector )
    {
        FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, it, l_corePos );
        FAPI_DBG("functional cores id %d", l_corePos );
        iv_funcCores    =   iv_funcCores  | (1 << l_corePos );
        iv_funcExes     =   iv_funcExes   | (1 << (l_corePos >> 1) );
        iv_funcQuads    =   iv_funcQuads  | (1 << (l_corePos >> 2) );
    }

    FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, i_procTgt, iv_ddLevel);
    FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_procTgt, iv_chipName);

    FAPI_DBG("functional core : 0x%08x Ex  : 0x%08x quad 0x%08x"
             "EC : 0x%02x ChipName : 0x%02x ",
             iv_funcCores, iv_funcExes, iv_funcQuads, iv_ddLevel,
             iv_chipName );
}

//---------------------------------------------------------------------------

P10FuncModel::~P10FuncModel()
{
    FAPI_DBG("Destroyed P10FuncModel");
}

//---------------------------------------------------------------------------

bool P10FuncModel::isCoreFunctional( uint32_t i_corePos ) const
{
    return ( (iv_funcCores & ( 1 << i_corePos )) != 0 );
}

//-------------------------------------------------------------------------

bool P10FuncModel::isExFunctional( uint32_t i_exPos )    const
{
    return ( (iv_funcExes & ( 1 << i_exPos )) != 0 );
}

//-------------------------------------------------------------------------

bool P10FuncModel::isQuadFunctional( uint32_t i_quadPos ) const
{
    return ( (iv_funcQuads & ( 1 << i_quadPos )) != 0 );
}

//-------------------------------------------------------------------------
uint8_t P10FuncModel::getChipLevel() const
{
    return iv_ddLevel;
}

//-------------------------------------------------------------------------
uint8_t P10FuncModel::getChipName() const
{
    return iv_chipName;
}

//-------------------------------------------------------------------------

} //namespace hcodeImageBuild
