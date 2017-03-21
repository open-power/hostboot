/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemEccAnalysis.C $      */
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

#include <prdfMemEccAnalysis.H>

// Platform includes
#include <prdfMemAddress.H>
#include <prdfMemCaptureData.H>
#include <prdfP9McaDataBundle.H>
#include <prdfP9McaExtraSig.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace MemEcc
{

//------------------------------------------------------------------------------

template<>
void calloutMemUe<TYPE_MCA>( ExtensibleChip * i_chip, const MemRank & i_rank,
                             STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::calloutMemUe] "

    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    SCAN_COMM_REGISTER_CLASS * fir  = i_chip->getRegister( "DDRPHYFIR" );
    int32_t l_rc = fir->Read();
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on DDRPHYFIR: i_chip=0x%08x",
                  i_chip->getHuid() );
    }

    // Check DDRPHYFIR[54:55,57:59] to determine if this UE is a side-effect.
    if ( SUCCESS == l_rc && (0 != (fir->GetBitFieldJustified(54,6) & 0x37)) )
    {
        // Callout the MCA.
        io_sc.service_data->SetCallout( i_chip->getTrgt() );
    }
    else
    {
        // Callout the rank anyway.
        MemoryMru memmru ( i_chip->getTrgt(), i_rank,
                           MemoryMruData::CALLOUT_RANK );
        io_sc.service_data->SetCallout( memmru );
    }

    #undef PRDF_FUNC
}

template<>
void calloutMemUe<TYPE_MBA>( ExtensibleChip * i_chip, const MemRank & i_rank,
                             STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    // TODO: RTC 169933 During Memory Diagnostics we'll want to call the
    //       mssIplUeIsolation() HWP so that we can isolate to a single DIMM if
    //       possible. This may be a difficult task to do at this point in the
    //       code because it will run a maintenance command on the Centaur,
    //       which may require some cleanup of the previous command. Since there
    //       are no plans to support IS DIMMs attached to a Centaur in P9, we
    //       may be able to get rid of this requirement because the FRU will be
    //       the same regardless if one or two logical DIMMs are called out.

    MemoryMru memmru ( i_chip->getTrgt(), i_rank, MemoryMruData::CALLOUT_RANK );
    io_sc.service_data->SetCallout( memmru );
}

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

template<TARGETING::TYPE T, typename D>
uint32_t addVcmEvent( ExtensibleChip * i_chip, const MemRank & i_rank,
                      const MemMark & i_mark, STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( T == i_chip->getType() );

    D db = static_cast<D>(i_chip->getDataBundle());

    TdEntry * entry = new VcmEvent<T>( i_chip, i_rank, i_mark );

    return db->getTdCtlr()->handleTdEvent( io_sc, entry );
}

template
uint32_t addVcmEvent<TYPE_MCA, McaDataBundle *>( ExtensibleChip * i_chip,
                                                 const MemRank & i_rank,
                                                 const MemMark & i_mark,
                                                 STEP_CODE_DATA_STRUCT & io_sc);

#endif

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

template<TARGETING::TYPE T, typename D>
uint32_t addTpsEvent( ExtensibleChip * i_chip, const MemRank & i_rank,
                      STEP_CODE_DATA_STRUCT & io_sc, bool i_banTps )
{
    PRDF_ASSERT( T == i_chip->getType() );

    D db = static_cast<D>(i_chip->getDataBundle());

    TdEntry * entry = new TpsEvent<T>( i_chip, i_rank, i_banTps );

    return db->getTdCtlr()->handleTdEvent( io_sc, entry );
}

template
uint32_t addTpsEvent<TYPE_MCA, McaDataBundle *>( ExtensibleChip * i_chip,
                                                 const MemRank & i_rank,
                                                 STEP_CODE_DATA_STRUCT & io_sc,
                                                 bool i_banTps );

#endif

//------------------------------------------------------------------------------

template<TARGETING::TYPE T, typename D>
uint32_t analyzeFetchMpe( ExtensibleChip * i_chip, const MemRank & i_rank,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::analyzeFetchMpe] "

    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    #ifndef __HOSTBOOT_RUNTIME // IPL

    PRDF_ERR( PRDF_FUNC "Mainline MPE attns should be masked during IPL" );
    PRDF_ASSERT(false); // HWP bug.

    #else // runtime

    do
    {
        // Get the address of the failure.
        MemAddr addr;
        o_rc = getMemReadAddr<T>( i_chip, MemAddr::READ_MPE_ADDR, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemReadAddr(0x%08x, READ_MPE_ADDR) failed",
                      i_chip->getHuid() );
            break;
        }

        // There is only one address register and it will contain the latest
        // chip mark placed. So it is possible this address will be out of sync
        // with the rank that reported the attention. In this case, we will
        // simply fake an address with the correct rank and move on.
        if ( i_rank != addr.getRank() )
        {
            addr = MemAddr ( i_rank, 0, 0, 0 );
        }

        // Add address to UE table.
        D db = static_cast<D>(i_chip->getDataBundle());
        db->iv_ueTable.addEntry( UE_TABLE::FETCH_MPE, addr );

        // Read the chip mark from markstore.
        MemMark chipMark;
        o_rc = MarkStore::readChipMark<T>( i_chip, i_rank, chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark<T>(0x%08x,%d) failed",
                      i_chip->getHuid(), i_rank.getMaster() );
            break;
        }

        // If the chip mark is not valid, then somehow the chip mark was placed
        // on a rank other than the rank with the attention. This would most
        // likely be a code bug.
        PRDF_ASSERT( chipMark.isValid() );

        // Add the mark to the callout list.
        MemoryMru mm { i_chip->getTrgt(), i_rank, chipMark.getSymbol() };
        io_sc.service_data->SetCallout( mm );

        // Add a VCM request to the TD queue.
        o_rc = addVcmEvent<T,D>( i_chip, i_rank, chipMark, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "addVcmEvent() failed: i_chip=0x%08x "
                      "i_rank=%d,%d", i_chip->getHuid(), i_rank.getMaster(),
                      i_rank.getSlave() );
            break;
        }

    } while (0);

    // Add ECC capture data for FFDC.
    MemCaptureData::addEccData<T>( i_chip, io_sc );

    #endif // __HOSTBOOT_RUNTIME

    return o_rc;

    #undef PRDF_FUNC
}

// To resolve template linker errors.
template
uint32_t analyzeFetchMpe<TYPE_MCA, McaDataBundle *>( ExtensibleChip * i_chip,
                                                const MemRank & i_rank,
                                                STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T, typename D>
uint32_t __analyzeFetchNceTce( ExtensibleChip * i_chip, const MemAddr & i_addr,
                               const MemSymbol & i_symbol,
                               STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::__analyzeFetchNceTce] "

    uint32_t o_rc = SUCCESS;

    TargetHandle_t trgt = i_chip->getTrgt();
    MemRank        rank = i_addr.getRank();

    // Add the DIMM to the callout list
    MemoryMru memmru ( trgt, rank, i_symbol );
    io_sc.service_data->SetCallout( memmru, MRU_MEDA );

    // Add data to the CE table.
    D db = static_cast<D>(i_chip->getDataBundle());
    uint32_t ceTableRc = db->iv_ceTable.addEntry( i_addr, i_symbol );
    bool doTps = false;

    // Check MNFG thresholds, if needed.
    if ( mfgMode() )
    {
        if ( 0 != (MemCeTable<T>::MNFG_TH_DRAM & ceTableRc) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MnfgDramCte );
            io_sc.service_data->setServiceCall();
            doTps = true;
        }
        else if ( 0 != (MemCeTable<T>::MNFG_TH_RANK & ceTableRc) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MnfgRankCte );
            io_sc.service_data->setServiceCall();
            doTps = true;
        }
        else if ( 0 != (MemCeTable<T>::MNFG_TH_DIMM & ceTableRc) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MnfgDimmCte );
            io_sc.service_data->setServiceCall();
            doTps = true;
        }
        else if ( 0 != (MemCeTable<T>::TABLE_FULL & ceTableRc) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MnfgTableFull );

            // The table is full and no other threshold has been met. We are
            // in a state where we may never hit a MNFG threshold. Callout
            // all memory behind the chip. Also, since the counts are all
            // over the place, there may be a problem with the chip. So call
            // it out as well.
            MemoryMru all_mm ( trgt, rank, MemoryMruData::CALLOUT_ALL_MEM );
            io_sc.service_data->SetCallout( all_mm, MRU_MEDA );
            io_sc.service_data->SetCallout( trgt,   MRU_MEDA );
            io_sc.service_data->setServiceCall();
            doTps = true;
        }
        else if ( 0 != (MemCeTable<T>::ENTRY_TH_REACHED & ceTableRc) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MnfgEntryCte );

            // There is a single entry threshold and no other threshold
            // has been met. This is a potential flooding issue. So make
            // the DIMM callout predictive.
            io_sc.service_data->setServiceCall();
            doTps = true;
        }
    }
    else // field thresholds
    {
        // It is possible that the MNFG thresholds are higher than the field
        // thresholds because of the scaling due to DRAM side. Therefore, we
        // cannot simply trigger TPS on any threshold. The field and MNFG
        // thresholds must be handled separately.
        doTps = ( 0 != (MemCeTable<T>::FIELD_TH_ALL & ceTableRc) );
    }

    // Initiate a TPS procedure, if needed.
    if ( doTps )
    {
        #ifdef __HOSTBOOT_RUNTIME

        // If a MNFG threshold has been reached (predictive callout), we
        // will still try to start TPS just in case MNFG disables the
        // termination policy.

        o_rc = addTpsEvent<T,D>( i_chip, rank, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "addTpsEvent(0x%08x, m%ds%d) failed",
                      i_chip->getHuid(), rank.getMaster(), rank.getSlave() );
        }

        #endif
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T, typename D>
uint32_t analyzeFetchNce( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::analyzeFetchNce] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the address of the failure.
        MemAddr addr;
        o_rc = getMemReadAddr<T>( i_chip, MemAddr::READ_NCE_ADDR, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemReadAddr(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }
        MemRank rank = addr.getRank();

        // Get the symbol of the failure.
        MemSymbol symbol;
        o_rc = getMemReadSymbol<T>( i_chip, rank, symbol );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemReadSymbol(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Complete analysis.
        o_rc = __analyzeFetchNceTce<T,D>( i_chip, addr, symbol, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__analyzeFetchNceTce(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

    } while (0);

    // Add ECC capture data for FFDC.
    MemCaptureData::addEccData<T>( i_chip, io_sc );

    return o_rc;

    #undef PRDF_FUNC
}

// To resolve template linker errors.
template
uint32_t analyzeFetchNce<TYPE_MCA, McaDataBundle *>( ExtensibleChip * i_chip,
                                                STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T, typename D>
uint32_t analyzeFetchTce( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::analyzeFetchTce] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the address of the failure.
        MemAddr addr;
        o_rc = getMemReadAddr<T>( i_chip, MemAddr::READ_NCE_ADDR, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemReadAddr(0x%08x, READ_TCE_ADDR) failed",
                      i_chip->getHuid() );
            break;
        }
        MemRank rank = addr.getRank();

        // Get the first symbol of the failure.
        MemSymbol firstSymbol;
        o_rc = getMemReadSymbol<T>( i_chip, rank, firstSymbol );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "first getMemReadSymbol(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Complete analysis for first symbol.
        o_rc = __analyzeFetchNceTce<T,D>( i_chip, addr, firstSymbol, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "first __analyzeFetchNceTce(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Get the second symbol of the failure.
        MemSymbol secondSymbol;
        o_rc = getMemReadSymbol<T>( i_chip, rank, secondSymbol, true );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "second getMemReadSymbol(0x%08x, true) failed",
                      i_chip->getHuid() );
            break;
        }

        // Complete analysis for second symbol.
        o_rc = __analyzeFetchNceTce<T,D>( i_chip, addr, secondSymbol, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "second __analyzeFetchNceTce(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

    } while (0);

    // Add ECC capture data for FFDC.
    MemCaptureData::addEccData<T>( i_chip, io_sc );

    return o_rc;

    #undef PRDF_FUNC
}

// To resolve template linker errors.
template
uint32_t analyzeFetchTce<TYPE_MCA, McaDataBundle *>( ExtensibleChip * i_chip,
                                                STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T, typename D>
uint32_t analyzeFetchUe( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::analyzeFetchUe] "

    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    // All memory UEs should be customer viewable. Normally, this would be done
    // by setting the threshold to 1, but we do not want to mask UEs on the
    // first occurrence.
    io_sc.service_data->setServiceCall();

    do
    {
        // Get the address of the failure.
        MemAddr addr;
        o_rc = getMemReadAddr<T>( i_chip, MemAddr::READ_UE_ADDR, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemReadAddr(0x%08x, READ_UE_ADDR) failed",
                      i_chip->getHuid() );
            break;
        }

        // Add address to UE table.
        D db = static_cast<D>(i_chip->getDataBundle());
        db->iv_ueTable.addEntry( UE_TABLE::FETCH_UE, addr );

        // Make the hardware callout.
        MemRank rank = addr.getRank();
        calloutMemUe<T>( i_chip, rank, io_sc );

        #ifdef __HOSTBOOT_RUNTIME

        // Add a TPS request to the TD queue and ban any further TPS requests
        // for this rank.
        o_rc = addTpsEvent<T,D>( i_chip, rank, io_sc, true );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "addTpsEvent() failed: i_chip=0x%08x "
                      "rank=%d,%d", i_chip->getHuid(), rank.getMaster(),
                      rank.getSlave() );
            // NOTE: We are not adding a break here because we still want to do
            //       dynamic memory deallocation of the rank. Any code added
            //       after this will need to handled return codes judiciously.
        }

        /* TODO RTC 136129
        // Dynamically deallocation the rank.
        uint32_t dealloc_rc = MemDealloc::rank<T>( i_chip, rank );
        if ( SUCCESS != dealloc_rc )
        {
            PRDF_ERR( PRDF_FUNC "MemDealloc::rank() failed: i_chip=0x%08x "
                      "rank=m%ds%d", i_chip->getHuid(), rank.getMaster(),
                      rank.getSlave() );
            o_rc = dealloc_rc; break;
        }
        */

        #endif // __HOSTBOOT_RUNTIME

    } while (0);

    // Add ECC capture data for FFDC.
    MemCaptureData::addEccData<T>( i_chip, io_sc );

    return o_rc;

    #undef PRDF_FUNC
}

// To resolve template linker errors.
template
uint32_t analyzeFetchUe<TYPE_MCA, McaDataBundle *>( ExtensibleChip * i_chip,
                                                STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

} // end namespace MemEcc

} // end namespace PRDF

