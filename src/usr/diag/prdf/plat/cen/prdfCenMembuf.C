/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/cen/prdfCenMembuf.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <prdfPluginDef.H>
#include <prdfPluginMap.H>
#include <UtilHash.H> // for Util::hashString

// Platform includes

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace centaur_membuf
{

//##############################################################################
//
//                                  MBSFIR
//
//##############################################################################

/**
 * @brief  Captures trapped address for L4 cache ECC errors.
 * @param  i_chip Centaur chip
 * @param  io_sc  Step code data struct
 * @return SUCCESS always
 * @note   This function also reset ECC trapped address regsiters so that HW can
 *         capture address for next L4 ecc error.
 */
int32_t CaptureL4CacheErr( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CaptureL4CacheErr] "

    do
    {
        i_chip->CaptureErrorData( io_sc.service_data->GetCaptureData(),
                                  Util::hashString( "L4CacheErr" ) );

        // NOTE: FW should write on MBCELOG so that HW can capture
        // address for next L4 CE error.

        // NOTE: Line delete feature for L4 cache is not available yet, but if
        // it is ever supported, we need to make sure following should be the
        // order of events:
        // 1. Capture group of registers associated with group L4CacheErr
        // 2. do L4 line delete.
        // 3. clear register MBCELOG

        // If we clear register MBCELOG before doing line delete, it is possible
        // that hardware procedures shall run into erroneous scenarios. One
        // probable order of events from PRDF's perspective which can cause
        // this is below:
        // 1. Receives an attention due to failure at cache address X.
        // 2. captures all relevant register including MBCELOG.
        // 3. cleares MBCELOG - i.e. failed address info is lost. HW populates
        //    this register with another L4 CE address say Y.
        // 4. requestes HWP for line delete operation on address X but it
        //    actually  deletes Y. It's because MBCELOG now contains address Y.

        SCAN_COMM_REGISTER_CLASS * mbcelogReg = i_chip->getRegister("MBCELOG");
        mbcelogReg->clearAllBits();

        if ( SUCCESS != mbcelogReg->Write() )
        {
            PRDF_ERR( PRDF_FUNC "MBCELOG write failed for 0x%08x",
                      i_chip->GetId() );
            break;
        }

    } while (0);

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( centaur_membuf, CaptureL4CacheErr );

//------------------------------------------------------------------------------

/**
 * @brief  Clears MBS secondary FIR bits which may come up because of primary
 *         MBS/MBI FIR bits.
 * @param  i_chip Centaur chip
 * @param  io_sc  Step code data struct
 * @return SUCCESS always
 */
int32_t ClearMbsSecondaryBits( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[ClearMbsSecondaryBits] "

    int32_t l_rc = SUCCESS;

    do
    {
        SCAN_COMM_REGISTER_CLASS * mbsFir = i_chip->getRegister("MBSFIR");
        SCAN_COMM_REGISTER_CLASS * mbsFirMask =
                                        i_chip->getRegister("MBSFIR_MASK");
        SCAN_COMM_REGISTER_CLASS * mbsFirAnd =
                                        i_chip->getRegister("MBSFIR_AND");
        l_rc  = mbsFir->Read();
        l_rc |= mbsFirMask->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBSFIR/MBSFIR_MASK read failed for 0x%08x",
                      i_chip->GetId() );
            break;
        }

        mbsFirAnd->setAllBits();

        if ( mbsFir->IsBitSet(26) &&
             mbsFir->IsBitSet(9) && !mbsFirMask->IsBitSet(9) )
        {
            mbsFirAnd->ClearBit(26);
        }

        if ( mbsFir->IsBitSet(3) || mbsFir->IsBitSet(4) )
        {
            SCAN_COMM_REGISTER_CLASS * mbiFir = i_chip->getRegister("MBIFIR");
            SCAN_COMM_REGISTER_CLASS * mbiFirMask =
                                            i_chip->getRegister("MBIFIR_MASK");
            l_rc  = mbiFir->Read();
            l_rc |= mbiFirMask->Read();
            if ( SUCCESS != l_rc )
            {
                // Do not break from here, just print error trace. If there are
                // other secondary bits ( e.g. 26, 27 ), we want to clear them.
                PRDF_ERR( PRDF_FUNC "MBIFIR/MASK read failed for 0x%08x",
                          i_chip->GetId() );
            }
            else if ( mbiFir->IsBitSet(0) && !mbiFirMask->IsBitSet(0) )
            {
                mbsFirAnd->ClearBit(3);
                mbsFirAnd->ClearBit(4);
            }
        }

        l_rc = mbsFirAnd->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBSFIR_AND write failed for 0x%08x",
                      i_chip->GetId() );
            break;
        }

    } while (0);

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( centaur_membuf, ClearMbsSecondaryBits );

//------------------------------------------------------------------------------

/**
 * @brief  Mask MBS secondary FIR bits which may come up because of L4 UE.
 * @param  i_chip Centaur chip
 * @param  io_sc  Step code data struct
 * @return SUCCESS always
 */
int32_t MaskMbsSecondaryBits( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & io_sc  )
{
    #define PRDF_FUNC "[MaskMbsSecondaryBits] "

    int32_t l_rc = SUCCESS;

    do
    {
        SCAN_COMM_REGISTER_CLASS * mbsFirMaskOr =
                                        i_chip->getRegister("MBSFIR_MASK_OR");
        mbsFirMaskOr->SetBit(27);
        l_rc = mbsFirMaskOr->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBSFIR_MASK_OR write failedfor 0x%08x",
                      i_chip->GetId() );
            break;
        }

    } while (0);

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( centaur_membuf, MaskMbsSecondaryBits );

//------------------------------------------------------------------------------

/**
 * @brief  Clears MBACAL secondary FIR bits which may come up because of MBSFIR.
 * @param  i_chip Centaur chip
 * @param  io_sc  Step code data struct
 * @return SUCCESS always

 */
int32_t ClearMbaCalSecondaryBits( ExtensibleChip * i_chip,
                                  STEP_CODE_DATA_STRUCT & io_sc  )
{
    #define PRDF_FUNC "[ClearMbaCalSecondaryBits] "

    int32_t l_rc = SUCCESS;

    do
    {
        SCAN_COMM_REGISTER_CLASS * mbsFir = i_chip->getRegister("MBSFIR");
        SCAN_COMM_REGISTER_CLASS * mbsFirMask =
                                        i_chip->getRegister("MBSFIR_MASK");
        l_rc  = mbsFir->Read();
        l_rc |= mbsFirMask->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBSFIR/MBSFIR_MASK read failed for 0x%08x",
                      i_chip->GetId() );
            break;
        }

        for ( auto & mbaChip : getConnected(i_chip, TYPE_MBA) )
        {
            SCAN_COMM_REGISTER_CLASS * mbaCalFir =
                                mbaChip->getRegister("MBACALFIR");

            if ( SUCCESS != mbaCalFir->Read() )
            {
                // Do not break. Just print error trace and look for
                // other MBA.
                PRDF_ERR( PRDF_FUNC "MBACALFIR read failed for 0x%08x",
                          mbaChip->GetId() );
                continue;
            }

            if ( !( mbaCalFir->IsBitSet(10) || mbaCalFir->IsBitSet(14) ) )
                continue;

            SCAN_COMM_REGISTER_CLASS * mbaCalAndFir =
                                mbaChip->getRegister("MBACALFIR_AND");

            mbaCalAndFir->setAllBits();

            mbaCalAndFir->ClearBit(10);
            mbaCalAndFir->ClearBit(14);

            l_rc = mbaCalAndFir->Write();
            if ( SUCCESS != l_rc )
            {
                // Do not break. Just print error trace and look for
                // other MBA.
                PRDF_ERR( PRDF_FUNC "MBACALFIR_AND write failed for 0x%08x",
                          mbaChip->GetId() );
            }
        }

    } while (0);

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( centaur_membuf, ClearMbaCalSecondaryBits );

//------------------------------------------------------------------------------

/**
 * @brief  Mask MBACAL secondary FIR bits which may come up because of L4 UE.
 * @param  i_chip Centaur chip
 * @param  io_sc  Step code data struct
 * @return SUCCESS always
 */
int32_t MaskMbaCalSecondaryBits( ExtensibleChip * i_chip,
                                 STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MaskMbaCalSecondaryBits] "

    int32_t l_rc = SUCCESS;

    do
    {
        for ( auto & mbaChip : getConnected(i_chip, TYPE_MBA) )
        {
            SCAN_COMM_REGISTER_CLASS * mbaCalFirMaskOr =
                                mbaChip->getRegister("MBACALFIR_MASK_OR");

            mbaCalFirMaskOr->SetBit(9);
            mbaCalFirMaskOr->SetBit(15);
            l_rc = mbaCalFirMaskOr->Write();
            if ( SUCCESS != l_rc )
            {
                // Do not break. Just print error trace and look for other MBA.
                PRDF_ERR( PRDF_FUNC "MBACALFIR_MASK_OR write failed for 0x%08x",
                          mbaChip->GetId() );
            }
        }

    } while (0);

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( centaur_membuf, MaskMbaCalSecondaryBits );

//------------------------------------------------------------------------------

} // end namespace centaur_membuf

} // end namespace PRDF

