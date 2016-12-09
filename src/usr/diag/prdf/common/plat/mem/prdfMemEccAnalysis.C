/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemEccAnalysis.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <prdfMemMark.H>
#include <prdfP9McaDataBundle.H>

#ifdef __HOSTBOOT_RUNTIME
  #include <prdfMemTps.H>
  #include <prdfMemVcm.H>
  #include <prdfP9McbistDataBundle.H>
#endif

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace MemEcc
{

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_RUNTIME

template<TARGETING::TYPE T>
uint32_t __addVcmEvent( ExtensibleChip * i_chip, const MemRank & i_rank,
                        const MemMark & i_mark, STEP_CODE_DATA_STRUCT & io_sc );

template<>
uint32_t __addVcmEvent<TYPE_MCA>( ExtensibleChip * i_chip,
                                  const MemRank & i_rank,
                                  const MemMark & i_mark,
                                  STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );
    PRDF_ASSERT( nullptr != mcbChip ); // definitely a bug

    McbistDataBundle * mcbdb = getMcbistDataBundle( mcbChip );

    TdEntry * entry = new VcmEvent<TYPE_MCA>( i_chip, i_rank, i_mark );

    return mcbdb->getTdCtlr()->handleTdEvent( io_sc, entry );
}

/* TODO: RTC 144083
template<>
uint32_t __addVcmEvent<TYPE_MBA>( ExtensibleChip * i_chip,
                                  const MemRank & i_rank,
                                  const MemMark & i_mark,
                                  STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    CenMbaDataBundle * mbadb = getMbaDataBundle( i_chip );

    TdEntry * entry = new VcmEvent<TYPE_MBA>( i_chip, i_rank, i_mark );

    return mbadb->getTdCtlr()->handleTdEvent( io_sc, entry );
}
*/

#endif

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_RUNTIME

template<TARGETING::TYPE T>
uint32_t __addTpsEvent( ExtensibleChip * i_chip, const MemRank & i_rank,
                        STEP_CODE_DATA_STRUCT & io_sc, bool i_banTps = false );

template<>
uint32_t __addTpsEvent<TYPE_MCA>( ExtensibleChip * i_chip,
                                  const MemRank & i_rank,
                                  STEP_CODE_DATA_STRUCT & io_sc, bool i_banTps )
{
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );
    PRDF_ASSERT( nullptr != mcbChip ); // definitely a bug

    McbistDataBundle * mcbdb = getMcbistDataBundle( mcbChip );

    TdEntry * entry = new TpsEvent<TYPE_MCA>( i_chip, i_rank, i_banTps );

    return mcbdb->getTdCtlr()->handleTdEvent( io_sc, entry );
}

/* TODO: RTC 144083
template<>
uint32_t __addTpsEvent<TYPE_MBA>( ExtensibleChip * i_chip,
                                  const MemRank & i_rank,
                                  STEP_CODE_DATA_STRUCT & io_sc, bool i_banTps )
{
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    CenMbaDataBundle * mbadb = getMbaDataBundle( i_chip );

    TdEntry * entry = new TpsEvent<TYPE_MBA>( i_chip, i_rank, i_banTps );

    return mbadb->getTdCtlr()->handleTdEvent( io_sc, entry );
}
*/

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
        o_rc = __addVcmEvent<T>( i_chip, i_rank, chipMark, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__addVcmEvent() failed: i_chip=0x%08x "
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

        // Callout the rank.
        MemRank rank = addr.getRank();
        MemoryMru memmru ( i_chip->getTrgt(), rank,
                           MemoryMruData::CALLOUT_RANK );
        io_sc.service_data->SetCallout( memmru );

        #ifdef __HOSTBOOT_RUNTIME

        // Add a TPS request to the TD queue and ban any further TPS requests
        // for this rank.
        o_rc = __addTpsEvent<T>( i_chip, rank, io_sc, true );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__addTpsEvent() failed: i_chip=0x%08x "
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

