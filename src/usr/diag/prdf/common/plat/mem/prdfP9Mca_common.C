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
        // Make the error log predictive.
        io_sc.service_data->setServiceCall();

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
 * @brief  MCAECCFIR[8:9] - Mainline NCE and/or TCE.
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeFetchNceTce( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    MemEcc::analyzeFetchNceTce<TYPE_MCA, McaDataBundle *>( i_chip, io_sc );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( p9_mca, AnalyzeFetchNceTce );

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

/**
 * @brief  MCAECCFIR[17] - Mainline read IUE.
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeMainlineIue( ExtensibleChip * i_chip,
                                 STEP_CODE_DATA_STRUCT & io_sc )
{
    MemEcc::analyzeMainlineIue<TYPE_MCA, McaDataBundle *>( i_chip, io_sc );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( p9_mca, AnalyzeMainlineIue );

//------------------------------------------------------------------------------

/**
 * @brief  MCAECCFIR[37] - Maint IUE.
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeMaintIue( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & io_sc )
{
    MemEcc::analyzeMaintIue<TYPE_MCA, McaDataBundle *>( i_chip, io_sc );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( p9_mca, AnalyzeMaintIue );

//------------------------------------------------------------------------------

/**
 * @brief  MCAECCFIR[19,39] - Mainline and Maint IMPE
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeImpe( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    MemEcc::analyzeImpe<TYPE_MCA, McaDataBundle *>( i_chip, io_sc );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( p9_mca, AnalyzeImpe );

//------------------------------------------------------------------------------

/**
 * @brief  MCAECCFIR[13,16] - Mainline AUE and IAUE
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeFetchAueIaue( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mca::AnalyzeFetchAueIaue] "

    MemAddr addr;
    if ( SUCCESS != getMemReadAddr<TYPE_MCA>(i_chip, MemAddr::READ_AUE_ADDR,
                                             addr) )
    {
        PRDF_ERR( PRDF_FUNC "getMemReadAddr(0x%08x,READ_AUE_ADDR) failed",
                  i_chip->getHuid() );
    }
    else
    {
        MemRank rank = addr.getRank();
        MemoryMru mm { i_chip->getTrgt(), rank, MemoryMruData::CALLOUT_RANK };
        io_sc.service_data->SetCallout( mm, MRU_HIGH );
    }

    return SUCCESS; // nothing to return to rule code

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mca, AnalyzeFetchAueIaue );

/**
 * @brief  MCAECCFIR[33] - Maintenance AUE
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeMaintAue( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mca::AnalyzeMaintAue] "

    MemAddr addr;
    if ( SUCCESS != getMemMaintAddr<TYPE_MCA>(i_chip, addr) )
    {
        PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                  i_chip->getHuid() );
    }
    else
    {
        MemRank rank = addr.getRank();
        MemoryMru mm { i_chip->getTrgt(), rank, MemoryMruData::CALLOUT_RANK };
        io_sc.service_data->SetCallout( mm, MRU_HIGH );
    }

    return SUCCESS; // nothing to return to rule code

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mca, AnalyzeMaintAue );

//------------------------------------------------------------------------------

} // end namespace p9_mca

} // end namespace PRDF

