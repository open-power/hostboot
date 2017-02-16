/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfP9Mca_common.C $        */
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

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

// Platform includes
#include <prdfMemEccAnalysis.H>
#include <prdfPlatServices.H>
#include <prdfP9McaDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p9_mca
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the data bundle.
 * @param  i_chip An MCA chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_chip )
{
    i_chip->getDataBundle() = new McaDataBundle( i_chip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p9_mca, Initialize );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip An MCA chip.
 * @param  io_sc  The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mca::PostAnalysis] "

    return SUCCESS; // Always return SUCCESS for this plugin.

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mca, PostAnalysis );

//##############################################################################
//
//                               DDRPHYFIR
//
//##############################################################################

/**
 * @brief  DDRPHYFIR[54:55,57:59] MCA/UE algorithm
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t mcaUeAlgorithm( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mca::mcaUeAlgorithm] "

    SCAN_COMM_REGISTER_CLASS * fir = nullptr;
    SCAN_COMM_REGISTER_CLASS * msk = nullptr;

    // If the attention is currently at threshold or if there is a mainline or
    // maintenance UE on at the same time as the attention:
    //  - Make the error log predictive.
    //  - Mask the attention.
    //  - Do not clear the attention. This will be used during maintenance and
    //    memory UE analysis to indicate that the MCA should be called out
    //    instead of the DIMMs. This is unconventional process is needed because
    //    maintenance UEs are always masked (handled manually in maintenance
    //    command complete attentions) and memory UEs will get unmasked anytime
    //    Targeted Diagnostics is complete on that area of memory. So we never
    //    truly have a way to permanently mask the UEs.

    bool maskDoNotClearAttn = io_sc.service_data->IsAtThreshold();

    if ( !maskDoNotClearAttn )
    {
        fir = i_chip->getRegister("MCAECCFIR");
        if ( SUCCESS != fir->Read() )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCAECCFIR: i_chip=0x%08x",
                      i_chip->getHuid() );
        }
        else
        {
            maskDoNotClearAttn = fir->IsBitSet(14) || fir->IsBitSet(34);
        }
    }

    if ( maskDoNotClearAttn )
    {
        // Get the active attentions of DDRPHYFIR[54:55,57:59] and mask.
        fir = i_chip->getRegister("DDRPHYFIR");

        if ( SUCCESS != fir->Read() )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on DDRPHYFIR: i_chip=0x%08x",
                      i_chip->getHuid() );
        }
        else
        {
            uint64_t tmp = fir->GetBitFieldJustified(54, 6) & 0x37;

            msk = i_chip->getRegister("DDRPHYFIR_MASK_OR");

            msk->clearAllBits();
            msk->SetBitFieldJustified( 54, 6, tmp );

            if ( SUCCESS != msk->Write() )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on DDRPHYFIR_MASK_OR: "
                          "i_chip=0x%08x", i_chip->getHuid() );
            }
        }
    }

    return maskDoNotClearAttn ? PRD_NO_CLEAR_FIR_BITS : SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mca, mcaUeAlgorithm );

//##############################################################################
//
//                               MCAECCFIR
//
//##############################################################################

/**
 * @brief  MCAECCFIR[0:7] - Mainline MPE.
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
#define PLUGIN_FETCH_MPE_ERROR( RANK ) \
int32_t AnalyzeFetchMpe_##RANK( ExtensibleChip * i_chip, \
                                STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    MemRank rank ( RANK ); \
    MemEcc::analyzeFetchMpe<TYPE_MCA, McaDataBundle *>( i_chip, rank, io_sc ); \
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( p9_mca, AnalyzeFetchMpe_##RANK );

PLUGIN_FETCH_MPE_ERROR( 0 )
PLUGIN_FETCH_MPE_ERROR( 1 )
PLUGIN_FETCH_MPE_ERROR( 2 )
PLUGIN_FETCH_MPE_ERROR( 3 )
PLUGIN_FETCH_MPE_ERROR( 4 )
PLUGIN_FETCH_MPE_ERROR( 5 )
PLUGIN_FETCH_MPE_ERROR( 6 )
PLUGIN_FETCH_MPE_ERROR( 7 )

#undef PLUGIN_FETCH_MPE_ERROR

//------------------------------------------------------------------------------

/**
 * @brief  MCAECCFIR[8] - Mainline NCE.
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeFetchNce( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    MemEcc::analyzeFetchNce<TYPE_MCA, McaDataBundle *>( i_chip, io_sc );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( p9_mca, AnalyzeFetchNce );

//------------------------------------------------------------------------------

/**
 * @brief  MCAECCFIR[9] - Mainline TCE.
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeFetchTce( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    MemEcc::analyzeFetchTce<TYPE_MCA, McaDataBundle *>( i_chip, io_sc );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( p9_mca, AnalyzeFetchTce );

//------------------------------------------------------------------------------

/**
 * @brief  MCAECCFIR[14] - Mainline UE.
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeFetchUe( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    MemEcc::analyzeFetchUe<TYPE_MCA, McaDataBundle *>( i_chip, io_sc );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( p9_mca, AnalyzeFetchUe );

//------------------------------------------------------------------------------

} // end namespace p9_mca

} // end namespace PRDF

