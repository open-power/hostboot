/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemEccAnalysis.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#include <prdfMemDbUtils.H>
#include <prdfMemDqBitmap.H>
#include <prdfMemExtraSig.H>
#include <prdfPlatServices.H>

#ifdef __HOSTBOOT_RUNTIME
    #include <prdfMemDynDealloc.H>
#endif

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace MemEcc
{

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __handleMemUe( ExtensibleChip * i_chip, const MemAddr & i_addr,
                        UE_TABLE::Type i_type, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::__handleMemUe] "

    uint32_t o_rc = SUCCESS;

    MemRank rank = i_addr.getRank();

    // Add the rank to the callout list.
    MemoryMru mm { i_chip->getTrgt(), rank, MemoryMruData::CALLOUT_RANK };
    io_sc.service_data->SetCallout( mm );

    // All memory UEs should be customer viewable.
    io_sc.service_data->setServiceCall();

    // Add entry to UE table.
    MemDbUtils::addUeTableEntry<T>( i_chip, i_type, i_addr );

    #ifdef __HOSTBOOT_RUNTIME

    // Dynamically deallocate the rank.
    if ( SUCCESS != MemDealloc::rank<T>( i_chip, rank ) )
    {
        PRDF_ERR( PRDF_FUNC "MemDealloc::rank<T>(0x%08x,m%ds%d) failed",
                  i_chip->getHuid(), rank.getMaster(), rank.getSlave() );
    }

    #endif

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t handleMemUe<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                      const MemAddr & i_addr,
                                      UE_TABLE::Type i_type,
                                      STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::handleMemUe<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // Handle the memory UE.
        o_rc = __handleMemUe<TYPE_OCMB_CHIP>( i_chip, i_addr, i_type, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__handleMemUe(0x%08x,%d) failed",
                      i_chip->getHuid(), i_type );
            break;
        }

        #ifdef __HOSTBOOT_RUNTIME
        // Increment the UE counter and store the rank we're on, resetting
        // the UE and CE counts if we have stopped on a new rank.
        OcmbDataBundle * ocmbdb = getOcmbDataBundle(i_chip);
        if ( ocmbdb->iv_ceUeRank != i_addr.getRank() )
        {
            ocmbdb->iv_ceStopCounter.reset();
            ocmbdb->iv_ueStopCounter.reset();
        }
        ocmbdb->iv_ueStopCounter.inc( io_sc );
        ocmbdb->iv_ceUeRank = i_addr.getRank();
        #endif

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

template<>
uint32_t maskMemPort<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[MemEcc::maskMemPort<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // Mask all FIRs on the OCMB in the chiplet FIRs.
        SCAN_COMM_REGISTER_CLASS * chipletMask =
            i_chip->getRegister("OCMB_CHIPLET_FIR_MASK");
        SCAN_COMM_REGISTER_CLASS * chipletSpaMask =
            i_chip->getRegister("OCMB_CHIPLET_SPA_FIR_MASK");

        // We need to leave bits unmasked so we can still analyze to
        // SRQFIR[25] (to trigger a firmware initiated channel fail) and
        // the IUE bits, RDFFIR[17,37] if one of the IUE bits is set.

        chipletMask->setAllBits();
        chipletSpaMask->setAllBits();

        // Clear bits 7 and 9 so we can still analyze to the SRQFIR and RDFFIR
        chipletMask->ClearBit(7);
        chipletMask->ClearBit(9);

        o_rc = chipletMask->Write() | chipletSpaMask->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR(PRDF_FUNC "Write() failed for OCMB_CHIPLET_FIR_MASK or "
                     "OCMB_CHIPLET_SPA_FIR_MASK on 0x%08x", i_chip->getHuid());
            break;
        }

        // Mask off all bits in the SRQFIR except bit 25
        SCAN_COMM_REGISTER_CLASS * srqfir_mask_or =
            i_chip->getRegister("SRQFIR_MASK_OR");
        srqfir_mask_or->setAllBits();
        srqfir_mask_or->ClearBit(25);

        o_rc = srqfir_mask_or->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed for SRQFIR_MASK_OR on 0x%08x",
                      i_chip->getHuid() );
            break;
        }

        // Mask off all bits in the RDFFIR except bits 17,37 (if they are set)
        SCAN_COMM_REGISTER_CLASS * rdffir_mask_or =
            i_chip->getRegister("RDFFIR_MASK_OR");
        rdffir_mask_or->setAllBits();

        // We don't want to mask the IUE bits in the RDFFIR if they are on
        // so if we trigger a channel fail that causes a checkstop we have
        // something to blame it on.
        SCAN_COMM_REGISTER_CLASS * rdffir = i_chip->getRegister("RDFFIR");

        o_rc = rdffir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed for RDFFIR on 0x%08x",
                      i_chip->getHuid() );
            break;
        }

        if ( rdffir->IsBitSet(17) ) rdffir_mask_or->ClearBit(17);
        if ( rdffir->IsBitSet(37) ) rdffir_mask_or->ClearBit(37);

        o_rc = rdffir_mask_or->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed for RDFFIR_MASK_OR on 0x%08x",
                      i_chip->getHuid() );
            break;
        }

        #ifdef __HOSTBOOT_RUNTIME

        // Dynamically deallocate the port.
        if ( SUCCESS != MemDealloc::port<TYPE_OCMB_CHIP>( i_chip ) )
        {
            PRDF_ERR( PRDF_FUNC "MemDealloc::port<TYPE_OCMB_CHIP>(0x%08x) "
                      "failed", i_chip->getHuid() );
        }

        #endif

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

#endif // __HOSTBOOT_MODULE

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_RUNTIME

template<>
uint32_t triggerChnlFail<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[MemEcc::triggerChnlFail<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // Trigger a channel fail by unmasking and setting SRQFIR[25]

        // Set the SRQFIR[25] action registers to 0,0 for UNIT_CS
        // ACT0
        SCAN_COMM_REGISTER_CLASS * act0 = i_chip->getRegister( "SRQFIR_ACT0" );

        o_rc = act0->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read failed on SRQFIR_ACT0: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }

        // If bit 25 is set, clear it.
        if ( act0->IsBitSet(25) )
        {
            act0->ClearBit(25);
            o_rc = act0->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write failed on SRQFIR_ACT0: "
                          "i_chip=0x%08x", i_chip->getHuid() );
                break;
            }
        }

        // ACT1
        SCAN_COMM_REGISTER_CLASS * act1 = i_chip->getRegister( "SRQFIR_ACT1" );

        o_rc = act1->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read failed on SRQFIR_ACT1: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }

        // If bit 25 is set, clear it.
        if ( act1->IsBitSet(25) )
        {
            act1->ClearBit(25);
            o_rc = act1->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write failed on SRQFIR_ACT1: "
                          "i_chip=0x%08x", i_chip->getHuid() );
                break;
            }
        }

        // Set SRQFIR[25]
        SCAN_COMM_REGISTER_CLASS * srqfir_or = i_chip->getRegister("SRQFIR_OR");

        srqfir_or->clearAllBits();
        srqfir_or->SetBit(25);

        o_rc = srqfir_or->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write failed on SRQFIR_OR: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }

        // Unmask SRQFIR[25]
        SCAN_COMM_REGISTER_CLASS * mask_and =
            i_chip->getRegister( "SRQFIR_MASK_AND" );

        mask_and->setAllBits();
        mask_and->ClearBit(25);
        o_rc = mask_and->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write failed on SRQFIR_MASK_AND: "
                      "i_chip=0x%08x", i_chip->getHuid() );
            break;
        }

        // Reset thresholds to prevent issuing multiple channel failures on
        // the same port.
        OcmbDataBundle * db = getOcmbDataBundle( i_chip );
        for ( auto & resetTh : db->iv_iueTh )
        {
            resetTh.second.reset();
        }

        db->iv_iueChnlFail = true;

        break;
    }while(0);


    return o_rc;

    #undef PRDF_FUNC
}

#endif // __HOSTBOOT_RUNTIME

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

template<>
bool queryIueTh<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                 STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    bool iueAtTh = false;

    OcmbDataBundle * db = getOcmbDataBundle( i_chip );

    // Loop through all our thresholds
    for ( auto & th : db->iv_iueTh )
    {
        // If threshold reached
        if ( th.second.thReached(io_sc) )
        {
            iueAtTh = true;
        }
    }

    return iueAtTh;
}

#endif

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t handleMpe( ExtensibleChip * i_chip, const MemAddr & i_addr,
                    UE_TABLE::Type i_type, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::handleMpe] "

    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    MemRank rank = i_addr.getRank();

    do
    {
        // Read the chip mark from markstore.
        MemMark chipMark;
        o_rc = MarkStore::readChipMark<T>( i_chip, rank, chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark<T>(0x%08x,0x%02x) failed",
                      i_chip->getHuid(), rank.getKey() );
            break;
        }

        // If the chip mark is not valid, then somehow the chip mark was
        // placed on a rank other than the rank in which the command
        // stopped. This would most likely be a code bug.
        PRDF_ASSERT( chipMark.isValid() );

        // Add the mark to the callout list.
        MemoryMru mm { i_chip->getTrgt(), rank, chipMark.getSymbol() };
        io_sc.service_data->SetCallout( mm );

        // Add entry to UE table.
        MemDbUtils::addUeTableEntry<T>( i_chip, i_type, i_addr );

        // Add a VCM request to the TD queue if at runtime or at memdiags.
        #ifdef __HOSTBOOT_MODULE

        #ifndef __HOSTBOOT_RUNTIME
        if ( isInMdiaMode() )
        {
        #endif

        TdEntry * entry = new VcmEvent<T>( i_chip, rank, chipMark );
        MemDbUtils::pushToQueue<T>( i_chip, entry );

        #ifndef __HOSTBOOT_RUNTIME
        }
        #endif

        #endif

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

// To resolve template linker errors.
template
uint32_t handleMpe<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                    const MemAddr & i_addr,
                                    UE_TABLE::Type i_type,
                                    STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t analyzeFetchMpe( ExtensibleChip * i_chip, const MemRank & i_rank,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::analyzeFetchMpe] "

    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    #if !defined(__HOSTBOOT_RUNTIME) && defined(__HOSTBOOT_MODULE) // HB IPL

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
            o_rc = MemEcc::handleMpe<T>( i_chip, i_rank, UE_TABLE::FETCH_MPE,
                                         io_sc );
        }
        else
        {
            o_rc = MemEcc::handleMpe<T>( i_chip, addr, UE_TABLE::FETCH_MPE,
                                         io_sc );
        }
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "handleMpe<T>(0x%08x, 0x%02x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        #ifdef __HOSTBOOT_RUNTIME

        // The chip mark has already been added to the queue. Now tell the TD
        // controller to process it if not already in progress.
        o_rc = MemDbUtils::handleTdEvent<T>( i_chip, io_sc );
        if ( SUCCESS != o_rc )
        {
                PRDF_ERR( PRDF_FUNC "handleTdEvent(0x%08x) failed on rank "
                          "0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        #endif

    } while (0);

    // Add ECC capture data for FFDC.
    MemCaptureData::addEccData<T>( i_chip, io_sc );

    #endif // __HOSTBOOT_RUNTIME

    return o_rc;

    #undef PRDF_FUNC
}

// To resolve template linker errors.
template
uint32_t analyzeFetchMpe<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          const MemRank & i_rank,
                                          STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t handleMemCe( ExtensibleChip * i_chip, const MemAddr & i_addr,
                      const MemSymbol & i_symbol, bool & o_doTps,
                      STEP_CODE_DATA_STRUCT & io_sc, bool i_isHard )
{
    #define PRDF_FUNC "[MemEcc::handleMemCe] "

    uint32_t o_rc = SUCCESS;

    o_doTps = false;

    TargetHandle_t trgt = i_chip->getTrgt();
    MemRank        rank = i_addr.getRank();

    // Add the DIMM to the callout list
    MemoryMru memmru ( trgt, rank, i_symbol );
    io_sc.service_data->SetCallout( memmru, MRU_MEDA );

    // Add data to the CE table.
    uint32_t ceTableRc = MemDbUtils::addCeTableEntry<T>( i_chip, i_addr,
                                                         i_symbol, i_isHard );

    // Check MNFG thresholds, if needed.
    // NOTE: We will only check the MNFG thresholds if DRAM repairs is disabled.
    if ( areDramRepairsDisabled() )
    {
        if ( 0 != (MemCeTable<T>::MNFG_TH_DRAM & ceTableRc) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MnfgDramCte );
            io_sc.service_data->setServiceCall();
            o_doTps = true;
        }
        else if ( 0 != (MemCeTable<T>::MNFG_TH_RANK & ceTableRc) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MnfgRankCte );
            io_sc.service_data->setServiceCall();
            o_doTps = true;
        }
        else if ( 0 != (MemCeTable<T>::MNFG_TH_DIMM & ceTableRc) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MnfgDimmCte );
            io_sc.service_data->setServiceCall();
            o_doTps = true;
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
            o_doTps = true;
        }
        else if ( 0 != (MemCeTable<T>::ENTRY_TH_REACHED & ceTableRc) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MnfgEntryCte );

            // There is a single entry threshold and no other threshold
            // has been met. This is a potential flooding issue. So make
            // the DIMM callout predictive.
            io_sc.service_data->setServiceCall();
            o_doTps = true;
        }
    }
    else // field thresholds
    {
        // It is possible that the MNFG thresholds are higher than the field
        // thresholds because of the scaling due to DRAM side. Therefore, we
        // cannot simply trigger TPS on any threshold. The field and MNFG
        // thresholds must be handled separately.
        if ( !o_doTps )
            o_doTps = ( 0 != (MemCeTable<T>::FIELD_TH_ALL & ceTableRc) );
    }

    #ifdef __HOSTBOOT_RUNTIME

    if ( i_isHard )
    {
        // Dynamically deallocate the page.
        if ( SUCCESS != MemDealloc::page<T>( i_chip, i_addr ) )
        {
            PRDF_ERR( PRDF_FUNC "MemDealloc::page(0x%08x) failed",
                      i_chip->getHuid() );
        }
    }

    #endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t analyzeFetchNceTce( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::analyzeFetchNceTce] "

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

        // Get the symbols for the NCE/TCE attention.
        MemSymbol sym1, sym2;
        o_rc = getMemReadSymbol<T>( i_chip, rank, sym1, sym2 );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemReadSymbol(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Add the first symbol to the callout list and CE table.
        bool doTps = false;
        if ( sym1.isValid() )
        {
            o_rc = handleMemCe<T>( i_chip, addr, sym1, doTps, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemCe(0x%08x,0x%02x,%d) failed",
                          i_chip->getHuid(), rank.getKey(), sym1.getSymbol() );
                break;
            }
        }
        else
        {
            // The first symbol should always be valid.
            PRDF_ERR( PRDF_FUNC "getMemReadSymbol(0x%08x) returned an invalid "
                      "symbol", i_chip->getHuid() );
            o_rc = FAIL;
            break;
        }

        // Add the second symbol to the callout list and CE table, if it exists.
        if ( sym2.isValid() )
        {
            bool tmp;
            o_rc = handleMemCe<T>( i_chip, addr, sym2, tmp, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemCe(0x%08x,0x%02x,%d) failed",
                          i_chip->getHuid(), rank.getKey(), sym2.getSymbol() );
                break;
            }
            if ( tmp ) doTps = true;
        }

        // Initiate a TPS procedure, if needed.
        if ( doTps )
        {
            #ifdef __HOSTBOOT_RUNTIME

            // If a MNFG threshold has been reached (predictive callout), we
            // will still try to start TPS just in case MNFG disables the
            // termination policy.

            MemDbUtils::pushToQueue<T>( i_chip, new TpsEvent<T>(i_chip, rank) );
            o_rc = MemDbUtils::handleTdEvent<T>( i_chip, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleTdEvent(0x%08x) failed on rank "
                          "0x%02x", i_chip->getHuid(), rank.getKey() );
                break;
            }

            #endif
        }

    } while (0);

    // Add ECC capture data for FFDC.
    MemCaptureData::addEccData<T>( i_chip, io_sc );

    return o_rc;

    #undef PRDF_FUNC
}

// To resolve template linker errors.
template
uint32_t analyzeFetchNceTce<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                             STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
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

        // Do memory UE handling.
        o_rc = MemEcc::handleMemUe<T>( i_chip, addr, UE_TABLE::FETCH_UE, io_sc);
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "handleMemUe<T>(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        #ifdef __HOSTBOOT_RUNTIME

        // Add a TPS request to the TD queue for additional analysis. It is
        // unlikely the procedure will result in a repair because of the UE.
        // However, we want to run TPS once just to see how bad the rank is.
        MemRank rank = addr.getRank();
        MemDbUtils::pushToQueue<T>( i_chip, new TpsEvent<T>(i_chip, rank) );
        o_rc = MemDbUtils::handleTdEvent<T>( i_chip, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "handleTdEvent(0x%08x) failed on rank 0x%02x",
                      i_chip->getHuid(), rank.getKey() );
            break;
        }

        // Because of the UE, any further TPS requests will likely have no
        // effect. So ban all subsequent requests.
        MemDbUtils::banTps<T>( i_chip, rank );

        #endif // __HOSTBOOT_RUNTIME

    } while (0);

    // Add ECC capture data for FFDC.
    MemCaptureData::addEccData<T>( i_chip, io_sc );

    return o_rc;

    #undef PRDF_FUNC
}

// To resolve template linker errors.
template
uint32_t analyzeFetchUe<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                         STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<>
uint32_t handleMemIue<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                       const MemRank & i_rank,
                                       STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::handleMemIue] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    // Add the DIMM to the callout list.
    MemoryMru mm { i_chip->getTrgt(), i_rank, MemoryMruData::CALLOUT_RANK };
    io_sc.service_data->SetCallout( mm );

    #ifdef __HOSTBOOT_MODULE

    do
    {
        // Nothing else to do if handling a system checkstop.
        if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() ) break;

        // Get the data bundle from chip.
        OcmbDataBundle * db = getOcmbDataBundle( i_chip );

        // If we have already caused a channel fail, mask the IUE bits.
        if ( true == db->iv_iueChnlFail )
        {
            SCAN_COMM_REGISTER_CLASS * mask_or =
                i_chip->getRegister("RDFFIR_MASK_OR");

            mask_or->SetBit(17);
            mask_or->SetBit(37);

            o_rc = mask_or->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on 0x%08x",
                          i_chip->getHuid() );
                break;
            }
        }

        // Get the DIMM select.
        uint8_t ds = i_rank.getDimmSlct();

        // Initialize threshold if it doesn't exist yet.
        if ( 0 == db->iv_iueTh.count(ds) )
        {
            db->iv_iueTh[ds] = TimeBasedThreshold( getIueTh() );
        }

        // Increment the count and check if at threshold.
        if ( db->iv_iueTh[ds].inc(io_sc) )
        {
            // Make the error log predictive.
            io_sc.service_data->setServiceCall();

            // The port fail will be triggered in the PostAnalysis plugin after
            // the error log has been committed.

            // Mask off the entire port to avoid collateral.
            o_rc = MemEcc::maskMemPort<TYPE_OCMB_CHIP>( i_chip );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "MemEcc::maskMemPort(0x%08x) failed",
                          i_chip->getHuid() );
                break;
            }
        }

    } while (0);

    #endif // __HOSTBOOT_MODULE

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t analyzeMainlineIue( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::analyzeMainlineIue] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // Use the address in MBRCER. This address also traps IRCDs, but it is
        // not likely that we will have two independent failure modes at the
        // same time. So we just assume the address is correct.
        MemAddr addr;
        o_rc = getMemReadAddr<T>( i_chip, MemAddr::READ_RCE_ADDR, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemReadAddr(0x%08x, READ_RCE_ADDR) failed",
                      i_chip->getHuid() );
            break;
        }
        MemRank rank = addr.getRank();

        o_rc = handleMemIue<T>( i_chip, rank, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "handleMemIue(0x%08x,m%ds%d) failed",
                      i_chip->getHuid(), rank.getMaster(), rank.getSlave() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t analyzeMainlineIue<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                             STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t analyzeMaintIue( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemEcc::analyzeMaintIue] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // Use the current address in the MCBMCAT.
        MemAddr addr;
        o_rc = getMemMaintAddr<T>( i_chip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }
        MemRank rank = addr.getRank();

        o_rc = handleMemIue<T>( i_chip, rank, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "handleMemIue(0x%08x,m%ds%d) failed",
                      i_chip->getHuid(), rank.getMaster(), rank.getSlave() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t analyzeMaintIue<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<>
uint32_t analyzeImpe<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                      STEP_CODE_DATA_STRUCT & io_sc )
{

    #define PRDF_FUNC "[MemEcc::analyzeImpe] "

    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // get the mark shadow register
        SCAN_COMM_REGISTER_CLASS * msr = i_chip->getRegister("EXP_MSR");

        o_rc = msr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on EXP_MSR: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }

        TargetHandle_t trgt = i_chip->getTrgt();

        // get galois field code - bits 8:15 of MSR
        uint8_t galois = msr->GetBitFieldJustified( 8, 8 );

        // get rank - bits 16:18 of MSR
        uint8_t mrnk = msr->GetBitFieldJustified( 16, 3 );
        MemRank rank( mrnk );

        // get symbol and DRAM
        MemSymbol symbol = MemSymbol::fromGalois( trgt, rank, galois );
        if ( !symbol.isValid() )
        {
            PRDF_ERR( PRDF_FUNC "Galois 0x%02x from EXP_MSR is invalid: 0x%08x,"
                      "0x%02x", galois, i_chip->getHuid(), rank.getKey() );
            o_rc = FAIL;
            break;
        }

        // Add the DIMM to the callout list
        MemoryMru memmru( trgt, rank, MemoryMruData::CALLOUT_RANK );
        io_sc.service_data->SetCallout( memmru );

        #ifdef __HOSTBOOT_MODULE
        // get data bundle from chip
        OcmbDataBundle * db = getOcmbDataBundle( i_chip );
        uint8_t dram = symbol.getDram();

        // Increment the count and check threshold.
        if ( db->getImpeThresholdCounter()->inc(rank, dram, io_sc) )
        {
            // Make the error log predictive if DRAM Repairs are disabled or if
            // the number of DRAMs on this rank with IMPEs has reached threshold
            if ( areDramRepairsDisabled() ||
                 db->getImpeThresholdCounter()->queryDrams(rank, dram, io_sc) )
            {
                io_sc.service_data->setServiceCall();
            }
            else // Otherwise, place a chip mark on the failing DRAM.
            {
                MemMark chipMark( trgt, rank, galois );
                o_rc = MarkStore::writeChipMark<TYPE_OCMB_CHIP>( i_chip, rank,
                                                                 chipMark );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "writeChipMark(0x%08x,0x%02x) failed",
                              i_chip->getHuid(), rank.getKey() );
                    break;
                }

                o_rc = MarkStore::chipMarkCleanup<TYPE_OCMB_CHIP>( i_chip, rank,
                                                                   io_sc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "chipMarkCleanup(0x%08x,0x%02x) failed",
                              i_chip->getHuid(), rank.getKey() );
                    break;
                }
            }
        }

        // If a predictive callout is made, mask both mainline and maintenance
        // attentions.
        if ( io_sc.service_data->queryServiceCall() )
        {
            SCAN_COMM_REGISTER_CLASS * mask
                                  = i_chip->getRegister( "RDFFIR_MASK_OR" );
            mask->SetBit(19); // mainline
            mask->SetBit(39); // maintenance
            o_rc = mask->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on RDFFIR_MASK_OR: "
                          "0x%08x", i_chip->getHuid() );
                break;
            }
        }
        #endif // __HOSTBOOT_MODULE

    } while (0);


    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace MemEcc

} // end namespace PRDF

