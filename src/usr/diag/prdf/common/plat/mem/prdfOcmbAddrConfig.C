/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfOcmbAddrConfig.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

#include <prdfOcmbAddrConfig.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

uint32_t OcmbAddrConfig::getMcAddrTrans0( BitStringBuffer & o_addr_trans0 )
{
    #define PRDF_FUNC "[OcmbAddrConfig::getMcAddrTrans0] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_RUNTIME

    if ( iv_addr_trans0.isZero() )
    {
        // Try to read MC_ADDR_TRANS and update the instance variable
        SCAN_COMM_REGISTER_CLASS * mc_addr_trans =
            iv_ocmb->getRegister( "MC_ADDR_TRANS" );

        o_rc = mc_addr_trans->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read failed on MC_ADDR_TRANS: iv_ocmb=0x%08x",
                      iv_ocmb->getHuid() );
        }
        else
        {
            iv_addr_trans0 = *(mc_addr_trans->GetBitString());
        }
    }

    o_addr_trans0 = iv_addr_trans0;

    #else

    // Try to read MC_ADDR_TRANS and update the instance variable
    SCAN_COMM_REGISTER_CLASS * mc_addr_trans =
        iv_ocmb->getRegister( "MC_ADDR_TRANS" );

    o_rc = mc_addr_trans->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read failed on MC_ADDR_TRANS: iv_ocmb=0x%08x",
                  iv_ocmb->getHuid() );
    }
    else
    {
        o_addr_trans0 = *(mc_addr_trans->GetBitString());
    }

    #endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t OcmbAddrConfig::getMcAddrTrans1( BitStringBuffer & o_addr_trans1 )
{
    #define PRDF_FUNC "[OcmbAddrConfig::getMcAddrTrans1] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_RUNTIME

    if ( iv_addr_trans1.isZero() )
    {
        // Try to read MC_ADDR_TRANS1 and update the instance variable
        SCAN_COMM_REGISTER_CLASS * mc_addr_trans1 =
            iv_ocmb->getRegister( "MC_ADDR_TRANS1" );

        o_rc = mc_addr_trans1->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read failed on MC_ADDR_TRANS1: iv_ocmb=0x%08x",
                      iv_ocmb->getHuid() );
        }
        else
        {
            iv_addr_trans1 = *(mc_addr_trans1->GetBitString());
        }
    }

    o_addr_trans1 = iv_addr_trans1;

    #else

    // Try to read MC_ADDR_TRANS and update the instance variable
    SCAN_COMM_REGISTER_CLASS * mc_addr_trans1 =
        iv_ocmb->getRegister( "MC_ADDR_TRANS1" );

    o_rc = mc_addr_trans1->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read failed on MC_ADDR_TRANS1: iv_ocmb=0x%08x",
                  iv_ocmb->getHuid() );
    }
    else
    {
        o_addr_trans1 = *(mc_addr_trans1->GetBitString());
    }

    #endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t OcmbAddrConfig::getMcAddrTrans2( BitStringBuffer & o_addr_trans2 )
{
    #define PRDF_FUNC "[OcmbAddrConfig::getMcAddrTrans2] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_RUNTIME

    if ( iv_addr_trans2.isZero() )
    {
        // Try to read MC_ADDR_TRANS2 and update the instance variable
        SCAN_COMM_REGISTER_CLASS * mc_addr_trans2 =
            iv_ocmb->getRegister( "MC_ADDR_TRANS2" );

        o_rc = mc_addr_trans2->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read failed on MC_ADDR_TRANS2: iv_ocmb=0x%08x",
                      iv_ocmb->getHuid() );
        }
        else
        {
            iv_addr_trans2 = *(mc_addr_trans2->GetBitString());
        }
    }

    o_addr_trans2 = iv_addr_trans2;

    #else

    // Try to read MC_ADDR_TRANS and update the instance variable
    SCAN_COMM_REGISTER_CLASS * mc_addr_trans2 =
        iv_ocmb->getRegister( "MC_ADDR_TRANS2" );

    o_rc = mc_addr_trans2->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read failed on MC_ADDR_TRANS2: iv_ocmb=0x%08x",
                  iv_ocmb->getHuid() );
    }
    else
    {
        o_addr_trans2 = *(mc_addr_trans2->GetBitString());
    }

    #endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool OcmbAddrConfig::getCol3Valid()
{
    #define PRDF_FUNC "[OcmbAddrConfig::getCol3Valid] "

    bool o_col3Valid = false;

    // If MCBCFG[56]=1, mcbist will issue 64B operations and col3 will be used
    // to select between the 2 64B halves of the 128B cacheline.
    SCAN_COMM_REGISTER_CLASS * mcbcfg = iv_ocmb->getRegister( "MCBCFG" );
    if ( SUCCESS != mcbcfg->Read() )
    {
        PRDF_ERR( PRDF_FUNC "Read failed on MCBCFG: iv_ocmb=0x%08x",
                  iv_ocmb->getHuid() );
    }
    else if ( mcbcfg->IsBitSet(56) )
    {
        o_col3Valid = true;
    }

    return o_col3Valid;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

} // end namespace PRDF

