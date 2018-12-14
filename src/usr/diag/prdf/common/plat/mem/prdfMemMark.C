/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemMark.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

#include <prdfMemMark.H>

#include <prdfTrace.H>
#include <prdfErrlUtil.H>
#include <prdfMemDbUtils.H>

#ifdef __HOSTBOOT_MODULE
#include <prdfCenMbaExtraSig.H>
#include <prdfMemDsd.H>
#include <prdfMemVcm.H>
#endif

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace MarkStore
{

//##############################################################################
//                  Utilities to read/write markstore (MCA)
//##############################################################################

//  - We have the ability to set chip marks via the FWMSx registers, but there
//    are only eight repairs total that we can use in the FWMSx registers.
//    Therefore we will always use the HWMSx registers for the chip marks on
//    master ranks and use the FWMSx registers for other repairs.
//  - Also, we have the ability in the FWMSx registers to scale the range of
//    where the chip/symbol marks are placed (i.e. slave ranks, banks, etc.).
//    However, we are still limited to 8 repairs and the complication of
//    managing the repairs dynamically to ensure we can place as many repairs as
//    possible is more work than what we want to deal with at this time.
//    Therefore, we will only use the FWMSx registers to place a single symbol
//    mark per master rank. This matches the P8 behavior. This could be improved
//    upon later if we have the time, but doubtful.
//  - Summary:
//      - Chip marks will use HWMS0-7 registers (0x07010AD0-0x07010AD7).
//      - Symbol marks will use FWMS0-7 registers (0x07010AD8-0x07010ADF).
//      - Each register maps to master ranks 0-7.

template<>
uint32_t readChipMark<TYPE_MCA>( ExtensibleChip * i_chip,
                                 const MemRank & i_rank, MemMark & o_mark )
{
    #define PRDF_FUNC "[readChipMark<TYPE_MCA>] "

    uint32_t o_rc = SUCCESS;
    o_mark = MemMark(); // ensure invalid

    // get the register name
    char msName[64];
    sprintf( msName, "HW_MS%x", i_rank.getMaster() );

    // get the mark store register
    SCAN_COMM_REGISTER_CLASS * hwms = i_chip->getRegister( msName );

    o_rc = hwms->ForceRead(); // always read latest
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "ForceRead() failed on %s: i_chip=0x%08x",
                  msName, i_chip->getHuid() );
    }
    else
    {
        // HWMSx[0:7] contains the Galois field
        uint8_t galois = hwms->GetBitFieldJustified(0,8);

        // If the Galois field is zero, do nothing and use the default
        // constructor for o_mark
        if (0 != galois)
        {
            // get the target
            TargetHandle_t trgt = i_chip->getTrgt();

            // get the MemMark
            o_mark = MemMark(trgt, i_rank, galois);
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t writeChipMark<TYPE_MCA>( ExtensibleChip * i_chip,
                                  const MemRank & i_rank,
                                  const MemMark & i_mark )
{
    #define PRDF_FUNC "[writeChipMark<TYPE_MCA>] "

    PRDF_ASSERT( i_mark.isValid() );

    uint32_t o_rc = SUCCESS;

    // get the register name
    char msName[64];
    sprintf( msName, "HW_MS%x", i_rank.getMaster() );

    // get the mark store register
    SCAN_COMM_REGISTER_CLASS * hwms = i_chip->getRegister( msName );

    // HWMSx[0:7] set this to the Galois field.
    hwms->SetBitFieldJustified( 0, 8, i_mark.getDramGalois() );

    // HWMSx[8] confirmed with the hardware team that this will not trigger
    //          another MPE attention and that they want this set to 1.
    hwms->SetBit( 8 );

    // HWMSx[9] set to 1 to enable exit 1 for markstore reads. This is a
    //          performance improvement because we know the DRAM is bad.
    hwms->SetBit( 9 );

    o_rc = hwms->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on %s: i_chip=0x%08x",
                  msName, i_chip->getHuid() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t clearChipMark<TYPE_MCA>( ExtensibleChip * i_chip,
                                  const MemRank & i_rank )
{
    #define PRDF_FUNC "[clearChipMark<TYPE_MCA>] "

    uint32_t o_rc = SUCCESS;

    // get the register name
    char msName[64];
    sprintf( msName, "HW_MS%x", i_rank.getMaster() );

    // get the mark store register
    SCAN_COMM_REGISTER_CLASS * hwms = i_chip->getRegister( msName );

    // Clear the entire HWMSx register.
    hwms->clearAllBits();

    o_rc = hwms->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on %s: i_chip=0x%08x",
                  msName, i_chip->getHuid() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t readSymbolMark<TYPE_MCA>( ExtensibleChip * i_chip,
                                   const MemRank & i_rank, MemMark & o_mark )
{
    #define PRDF_FUNC "[readSymbolMark<TYPE_MCA>] "

    uint32_t o_rc = SUCCESS;
    o_mark = MemMark(); // ensure invalid

    // get the register name
    char msName[64];
    sprintf( msName, "FW_MS%x", i_rank.getMaster() );

    // get the mark store register
    SCAN_COMM_REGISTER_CLASS * fwms = i_chip->getRegister( msName );

    o_rc = fwms->ForceRead(); // always read latest
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "ForceRead() failed on %s: i_chip=0x%08x",
                  msName, i_chip->getHuid() );
    }
    else
    {
        // FWMSx[0:7] contains the Galois field
        uint8_t galois = fwms->GetBitFieldJustified(0,8);

        // If the Galois field is zero, do nothing and use the default
        // constructor for o_mark
        if (0 != galois)
        {
            // check other fields for accuracy - assert on failure

            // FWMSx[8] should be 1 to indicate a symbol mark.
            PRDF_ASSERT( fwms->IsBitSet(8) );

            // FWMSx[9:11] should be 0b101 to indicate master rank.
            PRDF_ASSERT( 0x5 == fwms->GetBitFieldJustified(9,3) );

            // FWMSx[12:14] is the master rank and should match the register
            //              number.
            PRDF_ASSERT( i_rank.getMaster() ==
                         fwms->GetBitFieldJustified(12,3) );

            // FWMSx[15:22] should be all zeros
            PRDF_ASSERT( 0x0 == fwms->GetBitFieldJustified(15,8) );

            // get the target
            TargetHandle_t trgt = i_chip->getTrgt();

            // get the MemMark
            o_mark = MemMark(trgt, i_rank, galois);
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t writeSymbolMark<TYPE_MCA>( ExtensibleChip * i_chip,
                                    const MemRank & i_rank,
                                    const MemMark & i_mark )
{
    #define PRDF_FUNC "[writeSymbolMark<TYPE_MCA>] "

    PRDF_ASSERT( i_mark.isValid() );

    uint32_t o_rc = SUCCESS;

    // get the register name
    char msName[64];
    sprintf( msName, "FW_MS%x", i_rank.getMaster() );

    // get the mark store register
    SCAN_COMM_REGISTER_CLASS * fwms = i_chip->getRegister( msName );

    // FWMSx[0:7] set this to the Galois field.
    fwms->SetBitFieldJustified( 0, 8, i_mark.getGalois() );

    // FWMSx[8] set to 1 to indicate a symbol mark.
    fwms->SetBit( 8 );

    // FWMSx[9:11]  set to 0b101 to indicate master rank.
    fwms->SetBitFieldJustified( 9, 3, 0x5 );

    // FWMSx[12:14] set this to the master rank which should match the
    //              register number.
    fwms->SetBitFieldJustified( 12, 3, i_rank.getMaster() );

    // FWMSx[15:22] set to all zeros
    fwms->SetBitFieldJustified( 15, 8, 0x0 );

    // FWMSx[23] set to 1 to enable exit 1 for markstore reads. This is a
    //           performance improvement because we know the symbol is bad.
    fwms->SetBit( 23 );

    o_rc = fwms->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on %s: i_chip=0x%08x",
                  msName, i_chip->getHuid() );
    }

    // Nimbus symbol mark performance workaround
    // When a symbol mark is placed at runtime
    #ifdef __HOSTBOOT_RUNTIME

    // Trigger WAT logic to 'disable bypass'
    // Get the ECC Debug/WAT Control register
    SCAN_COMM_REGISTER_CLASS * dbgr = i_chip->getRegister( "DBGR" );

    // Set DBGR[8] = 0b1
    dbgr->SetBit( 8 );
    o_rc = dbgr->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on DBGR: mca=0x%08x",
                  i_chip->getHuid() );
    }
    #endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t clearSymbolMark<TYPE_MCA>( ExtensibleChip * i_chip,
                                    const MemRank & i_rank )
{
    #define PRDF_FUNC "[clearSymbolMark<TYPE_MCA>] "

    uint32_t o_rc = SUCCESS;

    // get the register name
    char msName[64];
    sprintf( msName, "FW_MS%x", i_rank.getMaster() );

    // get the mark store register
    SCAN_COMM_REGISTER_CLASS * fwms = i_chip->getRegister( msName );

    // Clear the entire FWMSx register.
    fwms->clearAllBits();

    o_rc = fwms->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on %s: i_chip=0x%08x",
                  msName, i_chip->getHuid() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//                  Utilities to read/write markstore (MBA)
//##############################################################################

template<TARGETING::TYPE>
uint32_t __readMarks( ExtensibleChip * i_chip, const MemRank & i_rank,
                      MemMark & o_symMark, MemMark & o_chipMark );

template<>
uint32_t __readMarks<TYPE_MBA>( ExtensibleChip * i_chip, const MemRank & i_rank,
                                MemMark & o_symMark, MemMark & o_chipMark )
{
    #define PRDF_FUNC "[__readMarks<TYPE_MBA>] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    uint8_t l_sm = 0;
    uint8_t l_cm = 0;
    do
    {
        errlHndl_t l_errl = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt( i_chip->getTrgt() );
        FAPI_INVOKE_HWP( l_errl, mss_get_mark_store, fapiTrgt,
                         i_rank.getMaster(), l_sm, l_cm );

        if ( nullptr != l_errl )
        {
            PRDF_ERR( PRDF_FUNC "mss_get_mark_store() failed. HUID: 0x%08x "
                      "rank: 0x%02x", i_chip->getHuid(), i_rank.getKey() );
            PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

        MemSymbol l_cmSym = MemSymbol::fromSymbol( i_chip->getTrgt(), i_rank,
                                                   l_cm );
        MemSymbol l_smSym = MemSymbol::fromSymbol( i_chip->getTrgt(), i_rank,
                                                   l_sm );

        // Check if the chip mark is on any of the spares
        MemSymbol sp0, sp1, ecc;
        o_rc = mssGetSteerMux<TARGETING::TYPE_MBA>( i_chip->getTrgt(), i_rank,
                                                    sp0, sp1, ecc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed. HUID: 0x%08x "
                      "rank: 0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }
        l_cmSym.updateSpared(sp0,sp1,ecc);
        l_smSym.updateSpared(sp0,sp1,ecc);

        o_chipMark = MemMark( i_chip->getTrgt(), i_rank, l_cmSym );
        o_symMark  = MemMark( i_chip->getTrgt(), i_rank, l_smSym );

    }while(0);
    #endif

    return o_rc;

    #undef PRDF_FUNC
}

template<TARGETING::TYPE>
uint32_t __clearFetchAttn( ExtensibleChip * i_chip, const MemRank & i_rank );

template<>
uint32_t __clearFetchAttn<TYPE_MBA>( ExtensibleChip * i_chip,
                                     const MemRank & i_rank )
{
    #define PRDF_FUNC "[__clearFetchAttn<TYPE_MBA>] "

    uint32_t o_rc = SUCCESS;

    // Clear the fetch MPE attention.
    ExtensibleChip * l_membChip = getConnectedParent( i_chip, TYPE_MEMBUF );
    const char * reg_str = ( 0 == i_chip->getPos() ) ? "MBSECCFIR_0_AND"
                                                     : "MBSECCFIR_1_AND";
    SCAN_COMM_REGISTER_CLASS * firand = l_membChip->getRegister( reg_str );

    firand->setAllBits();
    firand->ClearBit( 0 + i_rank.getMaster() ); // fetch
    o_rc = firand->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t readChipMark<TYPE_MBA>( ExtensibleChip * i_chip,
                                 const MemRank & i_rank, MemMark & o_mark )
{
    #define PRDF_FUNC "[readChipMark<TYPE_MBA>] "

    uint32_t o_rc = SUCCESS;

    o_mark = MemMark(); // ensure invalid

    do
    {
        // __readMarks will use mss_get_mark_store to get back the symbol
        // value for both the chip and symbol marks, so the symbol mark value
        // we get back here is irrelevant in this case.
        MemMark l_junk;
        o_rc = __readMarks<TYPE_MBA>( i_chip, i_rank, l_junk, o_mark );
        if ( o_rc != SUCCESS )
        {
            PRDF_ERR( PRDF_FUNC "__readMarks<TYPE_MBA> failed. HUID: 0x%08x "
                      "rank: 0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }
    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t readSymbolMark<TYPE_MBA>( ExtensibleChip * i_chip,
                                   const MemRank & i_rank, MemMark & o_mark )
{
    #define PRDF_FUNC "[readSymbolMark<TYPE_MBA>] "

    uint32_t o_rc = SUCCESS;

    o_mark = MemMark(); // ensure invalid

    do
    {
        // __readMarks will use mss_get_mark_store to get back the symbol
        // value for both the chip and symbol marks, so the chip mark value
        // we get back here is irrelevant in this case.
        MemMark l_junk;
        o_rc = __readMarks<TYPE_MBA>( i_chip, i_rank, o_mark, l_junk );
        if ( o_rc != SUCCESS )
        {
            PRDF_ERR( PRDF_FUNC "__readMarks<TYPE_MBA> failed. HUID: 0x%08x "
                      "rank: 0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }
    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t writeChipMark<TYPE_MBA>( ExtensibleChip * i_chip,
                                  const MemRank & i_rank,
                                  const MemMark & i_mark )
{
    #define PRDF_FUNC "[writeChipMark<TYPE_MBA>] "

    PRDF_ASSERT( i_mark.isValid() );

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    do
    {
        // mss_put_mark_store will overwrite both the chip and symbol marks,
        // so we want to do a read of the symbol mark to ensure we do not
        // overwrite it.
        MemMark l_symMark;
        o_rc = readSymbolMark<TYPE_MBA>( i_chip, i_rank, l_symMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readSymbolMark failed. HUID: 0x%08x Rank: "
                      "0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        uint8_t l_sm = l_symMark.isValid() ? l_symMark.getSymbol().getSymbol()
                                           : MSS_INVALID_SYMBOL;
        uint8_t l_cm = i_mark.isValid() ? i_mark.getSymbol().getDramSymbol()
                                        : MSS_INVALID_SYMBOL;

        errlHndl_t l_errl = nullptr;
        fapi2::ReturnCode l_rc;
        fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt( i_chip->getTrgt() );
        FAPI_INVOKE_HWP_RC( l_errl, l_rc, mss_put_mark_store, fapiTrgt,
                            i_rank.getMaster(), l_sm, l_cm );

        if ( (fapi2::ReturnCode)fapi2::RC_CEN_MSS_MAINT_MARKSTORE_WRITE_BLOCKED
             == l_rc )
        {
            delete l_errl;
            l_errl = nullptr;

            // Write was blocked by hardware, we will try one rewrite.
            PRDF_TRAC( PRDF_FUNC "Write chip mark blocked by hardware on "
                       "HUID: 0x%08x Rank: 0x%02x.", i_chip->getHuid(),
                       i_rank.getKey() );

            // Clear the fetch attn before attempting the rewrite to markstore.
            o_rc = __clearFetchAttn<TYPE_MBA>( i_chip, i_rank );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__clearFetchAttn failed. HUID: 0x%08x "
                          "Rank: 0x%02x", i_chip->getHuid(), i_rank.getKey() );
                break;
            }

            // Attempt to rewrite the chip mark.
            FAPI_INVOKE_HWP( l_errl, mss_put_mark_store, fapiTrgt,
                             i_rank.getMaster(), l_sm, l_cm );
            if ( nullptr != l_errl )
            {
                PRDF_ERR( PRDF_FUNC "mss_put_mark_store rewrite failed." );
                PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );
                o_rc = FAIL;
            }
        }
        else if ( nullptr != l_errl )
        {
            PRDF_ERR( PRDF_FUNC "mss_put_mark_store() failed. HUID: 0x%08x "
                      "Rank: 0x%02x sm: %d cm: %d", i_chip->getHuid(),
                      i_rank.getKey(), l_sm, l_cm );
            PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
        }

    }while(0);
    #endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t clearChipMark<TYPE_MBA>( ExtensibleChip * i_chip,
                                  const MemRank & i_rank )
{
    #define PRDF_FUNC "[clearChipMark<TYPE_MBA>] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    do
    {
        // Check to make sure there is a chip mark to clear
        MemMark l_chipMark;
        o_rc = readChipMark<TYPE_MBA>( i_chip,  i_rank, l_chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark failed. HUID: 0x%08x Rank: "
                      "0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }
        else if ( !l_chipMark.isValid() )
        {
            PRDF_ERR( PRDF_FUNC "There is no chip mark to clear on HUID: 0x%08x"
                      " Rank: 0x%02x", i_chip->getHuid(), i_rank.getKey() );
            o_rc = FAIL;
            break;
        }

        // Clear the fetch attention before attempting the write to markstore.
        o_rc = __clearFetchAttn<TYPE_MBA>( i_chip, i_rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__clearFetchAttn failed. HUID: 0x%08x Rank: "
                      "0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        // mss_put_mark_store will overwrite both the chip and symbol marks,
        // so we want to do a read of the symbol mark to ensure we do not
        // overwrite it.
        MemMark l_symMark;
        o_rc = readSymbolMark<TYPE_MBA>( i_chip, i_rank, l_symMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readSymbolMark failed. HUID: 0x%08x Rank: "
                      "0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        uint8_t l_sm = l_symMark.isValid() ? l_symMark.getSymbol().getSymbol()
                                           : MSS_INVALID_SYMBOL;
        uint8_t l_cm = MSS_INVALID_SYMBOL;

        errlHndl_t l_errl = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt( i_chip->getTrgt() );

        fapi2::ReturnCode l_rc;
        FAPI_INVOKE_HWP_RC( l_errl, l_rc, mss_put_mark_store, fapiTrgt,
                            i_rank.getMaster(), l_sm, l_cm );

        if ( (fapi2::ReturnCode)fapi2::RC_CEN_MSS_MAINT_MARKSTORE_WRITE_BLOCKED
             == l_rc )
        {
            delete l_errl;
            l_errl = nullptr;

            // Since we were clearing the chip mark, we know we can't be
            // blocked be an incoming chip mark. However, there is a small
            // window after removing the chip mark and before the HWP checks the
            // chip mark attentions, that a new chip mark can happen. If this is
            // the case, re-read markstore and put the new chip mark in the
            // queue.

            MemMark l_newChipMark;
            o_rc = readChipMark<TYPE_MBA>( i_chip, i_rank, l_newChipMark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark failed. HUID: 0x%08x Rank: "
                          "0x%02x", i_chip->getHuid(), i_rank.getKey() );
                break;
            }

            TdEntry * entry = new VcmEvent<TYPE_MBA>( i_chip, i_rank,
                                                      l_newChipMark );
            MemDbUtils::pushToQueue<TYPE_MBA>( i_chip, entry );

            // Clear the fetch attention so we don't get a redundant attention.
            o_rc = __clearFetchAttn<TYPE_MBA>( i_chip, i_rank );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__clearFetchAttn failed. HUID: 0x%08x "
                          "Rank: 0x%02x", i_chip->getHuid(), i_rank.getKey() );
                break;
            }
        }
        else if ( nullptr != l_errl )
        {
            PRDF_ERR( PRDF_FUNC "mss_put_mark_store() failed. HUID: 0x%08x "
                      "Rank: 0x%02x sm: %d cm: %d", i_chip->getHuid(),
                      i_rank.getKey(), l_sm, l_cm );
            PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
        }

    }while(0);
    #endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t clearSymbolMark<TYPE_MBA>( ExtensibleChip * i_chip,
                                    const MemRank & i_rank )
{
    #define PRDF_FUNC "[clearSymbolMark<TYPE_MBA>] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    do
    {
        // Check to make sure there is a symbol mark to clear
        MemMark l_symMark;
        o_rc = readSymbolMark<TYPE_MBA>( i_chip,  i_rank, l_symMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readSymbolMark failed. HUID: 0x%08x Rank: "
                      "0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }
        else if ( !l_symMark.isValid() )
        {
            PRDF_ERR( PRDF_FUNC "There is no symbol mark to clear on HUID: "
                      "0x%08x Rank: 0x%02x", i_chip->getHuid(),
                      i_rank.getKey() );
            o_rc = FAIL;
            break;
        }

        // mss_put_mark_store will overwrite both the chip and symbol marks,
        // so we want to do a read of the symbol mark to ensure we do not
        // overwrite it.
        MemMark l_chipMark;
        o_rc = readChipMark<TYPE_MBA>( i_chip, i_rank, l_chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark failed. HUID: 0x%08x Rank: "
                      "0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        uint8_t l_cm = l_chipMark.isValid() ? l_chipMark.getSymbol().getSymbol()
                                            : MSS_INVALID_SYMBOL;
        uint8_t l_sm = MSS_INVALID_SYMBOL;

        errlHndl_t l_errl = nullptr;
        fapi2::ReturnCode l_rc;
        fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt( i_chip->getTrgt() );
        FAPI_INVOKE_HWP_RC( l_errl, l_rc, mss_put_mark_store, fapiTrgt,
                            i_rank.getMaster(), l_sm, l_cm );

        if ( (fapi2::ReturnCode)fapi2::RC_CEN_MSS_MAINT_MARKSTORE_WRITE_BLOCKED
             == l_rc )
        {
            delete l_errl;
            l_errl = nullptr;

            // Hardware blocked the write so reread the chip mark and set mark
            // store again with chip mark and without symbol mark.
            MemMark l_newChipMark;
            o_rc = readChipMark<TYPE_MBA>( i_chip, i_rank, l_newChipMark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark failed. HUID: 0x%08x Rank: "
                          "0x%02x", i_chip->getHuid(), i_rank.getKey() );
                break;
            }
            uint8_t l_newCm = l_newChipMark.isValid()
                ? l_newChipMark.getSymbol().getSymbol() : MSS_INVALID_SYMBOL;

            // Clear the fetch attention before attempting the write to
            // markstore
            o_rc = __clearFetchAttn<TYPE_MBA>( i_chip, i_rank );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__clearFetchAttn failed. HUID: 0x%08x "
                          "Rank: 0x%02x", i_chip->getHuid(), i_rank.getKey() );
                break;
            }

            // Since we cleared the attn, add the chip mark to the queue
            TdEntry * entry = new VcmEvent<TYPE_MBA>( i_chip, i_rank,
                                                      l_newChipMark );
            MemDbUtils::pushToQueue<TYPE_MBA>( i_chip, entry );

            // Try to write mark store again
            FAPI_INVOKE_HWP( l_errl, mss_put_mark_store, fapiTrgt,
                             i_rank.getMaster(), l_sm, l_newCm );
            if ( nullptr != l_errl )
            {
                PRDF_ERR( PRDF_FUNC "mss_put_mark_store rewrite failed." );
                PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );
                o_rc = FAIL;
            }
        }
        else if ( nullptr != l_errl )
        {
            PRDF_ERR( PRDF_FUNC "mss_put_mark_store() failed. HUID: 0x%08x "
                      "Rank: 0x%02x sm: %d cm: %d", i_chip->getHuid(),
                      i_rank.getKey(), l_sm, l_cm );
            PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
        }

    }while(0);
    #endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t writeSymbolMark<TYPE_MBA>( ExtensibleChip * i_chip,
                                    const MemRank & i_rank,
                                    const MemMark & i_mark )
{
    #define PRDF_FUNC "[writeSymbolMark<TYPE_MBA>] "

    PRDF_ASSERT( i_mark.isValid() );

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    do
    {
        // mss_put_mark_store will overwrite both the chip and symbol marks,
        // so we want to do a read of the chip mark to ensure we do not
        // overwrite it.
        MemMark l_chipMark;
        o_rc = readChipMark<TYPE_MBA>( i_chip, i_rank, l_chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark failed. HUID: 0x%08x Rank: "
                      "0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        uint8_t l_cm = l_chipMark.isValid() ? l_chipMark.getSymbol().getSymbol()
                                            : MSS_INVALID_SYMBOL;
        uint8_t l_sm = i_mark.isValid() ? i_mark.getSymbol().getSymbol()
                                        : MSS_INVALID_SYMBOL;

        errlHndl_t l_errl = nullptr;
        fapi2::ReturnCode l_rc;
        fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt( i_chip->getTrgt() );
        FAPI_INVOKE_HWP_RC( l_errl, l_rc, mss_put_mark_store, fapiTrgt,
                            i_rank.getMaster(), l_sm, l_cm );

        if ( (fapi2::ReturnCode)fapi2::RC_CEN_MSS_MAINT_MARKSTORE_WRITE_BLOCKED
             == l_rc )
        {
            delete l_errl;
            l_errl = nullptr;

            // The write was blocked by hardware, reread the chip mark.
            MemMark l_newChipMark;
            o_rc = readChipMark<TYPE_MBA>( i_chip, i_rank, l_newChipMark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark failed. HUID: 0x%08x "
                        "Rank: 0x%02x", i_chip->getHuid(),
                        i_rank.getKey() );
                break;
            }
            uint8_t l_newCm = l_newChipMark.isValid()
                ? l_newChipMark.getSymbol().getSymbol() : MSS_INVALID_SYMBOL;

            // If the chip mark and symbol mark are on the same DRAM
            if ( l_newChipMark.getSymbol().getDram() ==
                 i_mark.getSymbol().getDram() )
            {
                // Print trace indicating write blocked
                PRDF_TRAC( PRDF_FUNC "Write chip mark blocked by hardware on "
                           "HUID: 0x%08x Rank: 0x%02x.", i_chip->getHuid(),
                           i_rank.getKey() );

                // Don't write the symbol mark and let the fetch MPE attention
                // add the chip mark to the queue
            }
            // If the chip mark and symbol mark are on separate DRAMS
            else
            {
                // Clear the fetch attention
                o_rc = __clearFetchAttn<TYPE_MBA>( i_chip, i_rank );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "__clearFetchAttn failed. HUID: 0x%08x "
                              "Rank: 0x%02x", i_chip->getHuid(),
                              i_rank.getKey() );
                    break;
                }

                // Since we cleared the attn, add the chip mark to the queue
                TdEntry * entry = new VcmEvent<TYPE_MBA>( i_chip, i_rank,
                                                          l_newChipMark );
                MemDbUtils::pushToQueue<TYPE_MBA>( i_chip, entry );

                // Try to write mark store again
                FAPI_INVOKE_HWP( l_errl, mss_put_mark_store, fapiTrgt,
                                i_rank.getMaster(), l_sm, l_newCm );
                if ( nullptr != l_errl )
                {
                    PRDF_ERR( PRDF_FUNC "mss_put_mark_store rewrite failed." );
                    PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );
                    o_rc = FAIL;
                }
            }
        }
        else if ( nullptr != l_errl )
        {
            PRDF_ERR( PRDF_FUNC "mss_put_mark_store() failed. HUID: 0x%08x "
                      "Rank: 0x%02x sm: %d cm: %d", i_chip->getHuid(),
                      i_rank.getKey(), l_sm, l_cm );
            PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }

    }while(0);
    #endif

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//          Utilities to cleanup markstore after a chip mark is verified
//##############################################################################

#ifdef __HOSTBOOT_MODULE // Not supported on FSP.

//------------------------------------------------------------------------------

void __addCallout( ExtensibleChip * i_chip, const MemRank & i_rank,
                   const MemSymbol & i_symbol, STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( i_symbol.isValid() )
    {
        MemoryMru mm { i_chip->getTrgt(), i_rank, i_symbol };
        io_sc.service_data->SetCallout( mm );
    }
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __applyRasPolicies( ExtensibleChip * i_chip, const MemRank & i_rank,
                             STEP_CODE_DATA_STRUCT & io_sc,
                             const MemMark & i_chipMark,
                             const MemMark & i_symMark,
                             TdEntry * & o_dsdEvent, bool & o_allRepairsUsed );

template<>
uint32_t __applyRasPolicies<TYPE_MCA>( ExtensibleChip * i_chip,
                                       const MemRank & i_rank,
                                       STEP_CODE_DATA_STRUCT & io_sc,
                                       const MemMark & i_chipMark,
                                       const MemMark & i_symMark,
                                       TdEntry * & o_dsdEvent,
                                       bool & o_allRepairsUsed )
{
    // There is no DRAM sparing on Nimbus so simply check if both the chip and
    // symbol mark have been used.
    if ( i_chipMark.isValid() && i_symMark.isValid() )
    {
        o_allRepairsUsed = true;
        io_sc.service_data->setSignature( i_chip->getHuid(),
                                          PRDFSIG_AllDramRepairs );
    }

    return SUCCESS;
}

template<>
uint32_t __applyRasPolicies<TYPE_MBA>( ExtensibleChip * i_chip,
                                       const MemRank & i_rank,
                                       STEP_CODE_DATA_STRUCT & io_sc,
                                       const MemMark & i_chipMark,
                                       const MemMark & i_symMark,
                                       TdEntry * & o_dsdEvent,
                                       bool & o_allRepairsUsed )
{
    #define PRDF_FUNC "[__applyRasPolicies<TYPE_MBA>] "

    uint32_t o_rc = SUCCESS;

    do
    {
        const uint8_t ps   = i_chipMark.getSymbol().getPortSlct();
        const uint8_t dram = i_chipMark.getSymbol().getDram();

        const bool isX4 = isDramWidthX4( i_chip->getTrgt() );

        // Determine if DRAM sparing is enabled.
        bool isEnabled = false;
        o_rc = isDramSparingEnabled<TYPE_MBA>( i_chip->getTrgt(), i_rank, ps,
                                               isEnabled );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "isDramSparingEnabled() failed." );
            break;
        }

        if ( isEnabled )
        {
            // Sparing is enabled. Get the current spares in hardware.
            MemSymbol sp0, sp1, ecc;
            o_rc = mssGetSteerMux<TARGETING::TYPE_MBA>( i_chip->getTrgt(),
                                                        i_rank, sp0, sp1, ecc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "mssGetSteerMux(0x%08x,0x%02x) failed",
                          i_chip->getHuid(), i_rank.getKey() );
                break;
            }

            // Add the spares to the callout list if they exist.
            __addCallout( i_chip, i_rank, sp0, io_sc );
            __addCallout( i_chip, i_rank, sp1, io_sc );
            __addCallout( i_chip, i_rank, ecc, io_sc );

            // If the chip mark is on a spare then the spare is bad and hardware
            // can not steer it to another DRAM even if one is available (e.g.
            // the ECC spare). In this this case, make error log predictive.
            if ( ( (0 == ps) && sp0.isValid() && (dram == sp0.getDram()) ) ||
                 ( (1 == ps) && sp1.isValid() && (dram == sp1.getDram()) ) ||
                 ( isX4      && ecc.isValid() && (dram == ecc.getDram()) ) )
            {
                o_allRepairsUsed = true;
                io_sc.service_data->setSignature( i_chip->getHuid(),
                                                  PRDFSIG_VcmBadSpare );
                break; // Nothing more to do.
            }

            // Certain DIMMs may have had spares intentially made unavailable by
            // the manufacturer. Check the VPD for available spares.
            bool spAvail, eccAvail;
            o_rc = isSpareAvailable<TYPE_MBA>( i_chip->getTrgt(), i_rank, ps,
                                               spAvail, eccAvail );
            if ( spAvail )
            {
                // A spare DRAM is available.
                o_dsdEvent = new DsdEvent<TYPE_MBA>{ i_chip, i_rank,
                                                     i_chipMark };
            }
            else if ( eccAvail )
            {
                // The ECC spare is available.
                o_dsdEvent = new DsdEvent<TYPE_MBA>{ i_chip, i_rank,
                                                     i_chipMark, true };
            }
            else
            {
                // Chip mark is in place and sparing is not possible.
                o_allRepairsUsed = true;
                io_sc.service_data->setSignature( i_chip->getHuid(),
                                                  PRDFSIG_AllDramRepairs );
            }
        }
        // There is no DRAM sparing so simply check if both the chip and symbol
        // mark have been used.
        else if ( i_chipMark.isValid() && i_symMark.isValid() )
        {
            o_allRepairsUsed = true;
            io_sc.service_data->setSignature( i_chip->getHuid(),
                                              PRDFSIG_AllDramRepairs );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t applyRasPolicies( ExtensibleChip * i_chip, const MemRank & i_rank,
                           STEP_CODE_DATA_STRUCT & io_sc,
                           TdEntry * & o_dsdEvent )
{
    #define PRDF_FUNC "[MarkStore::applyRasPolicies] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    delete o_dsdEvent; o_dsdEvent = nullptr; // just in case

    bool allRepairsUsed = false;

    do
    {
        // Get the chip mark.
        MemMark chipMark;
        o_rc = readChipMark<T>( i_chip, i_rank, chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark(0x%08x,0x%02x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        // There is nothing else to do if there is no chip mark.
        if ( !chipMark.isValid() ) break;

        // Add the chip mark to the callout list.
        __addCallout( i_chip, i_rank, chipMark.getSymbol(), io_sc );

        // Get the symbol mark.
        MemMark symMark;
        o_rc = readSymbolMark<T>( i_chip, i_rank, symMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readSymbolMark(0x%08x,0x%02x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        // If both the chip and symbol mark are on the same DRAM, clear the
        // symbol mark.
        if ( symMark.isValid() &&
             chipMark.getSymbol().getDram() == symMark.getSymbol().getDram() )
        {
            o_rc = clearSymbolMark<T>( i_chip, i_rank );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "clearSymbolMark(0x%08x,0x%02x) failed",
                          i_chip->getHuid(), i_rank.getKey() );
                break;
            }

            // Reset the symbol mark variable to invalid.
            symMark = MemMark();
        }

        // Add the symbol mark to the callout list if it exists.
        __addCallout( i_chip, i_rank, symMark.getSymbol(), io_sc );

        // Make the error log predictive and exit if DRAM repairs are disabled.
        if ( areDramRepairsDisabled() )
        {
            io_sc.service_data->setServiceCall();
            break; // nothing else to do
        }

        // Apply type specific RAS policies.
        o_rc = __applyRasPolicies<T>( i_chip, i_rank, io_sc, chipMark, symMark,
                                      o_dsdEvent, allRepairsUsed );
        if ( SUCCESS != o_rc ) break;

    } while (0);

    if ( allRepairsUsed )
    {
        io_sc.service_data->setServiceCall();

        #ifdef __HOSTBOOT_RUNTIME
        // No more repairs left so no point doing any more TPS procedures.
        MemDbUtils::banTps<T>( i_chip, i_rank );
        #endif
    }

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t applyRasPolicies<TYPE_MCA>( ExtensibleChip * i_chip,
                                     const MemRank & i_rank,
                                     STEP_CODE_DATA_STRUCT & io_sc,
                                     TdEntry * & o_dsdEvent );
template
uint32_t applyRasPolicies<TYPE_MBA>( ExtensibleChip * i_chip,
                                     const MemRank & i_rank,
                                     STEP_CODE_DATA_STRUCT & io_sc,
                                     TdEntry * & o_dsdEvent );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t chipMarkCleanup( ExtensibleChip * i_chip, const MemRank & i_rank,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[chipMarkCleanup] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // It is possible this function was called and there is no chip mark. So
        // first check if one exists.
        MemMark chipMark;
        o_rc = readChipMark<T>( i_chip, i_rank, chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark(0x%08x,0x%02x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        // There is nothing else to do if there is no chip mark.
        if ( !chipMark.isValid() ) break;

        // Apply all RAS policies.
        TdEntry * dsdEvent = nullptr;
        o_rc = applyRasPolicies<T>( i_chip, i_rank, io_sc, dsdEvent );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "applyRasPolicies(0x%08x,0x%02x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        // Add the DRAM spare event to the queue if needed.
        if ( nullptr != dsdEvent )
        {
            MemDbUtils::pushToQueue<T>( i_chip, dsdEvent );
        }

        // Set the chip mark in the DRAM Repairs VPD.
        if ( !areDramRepairsDisabled() )
        {
            o_rc = setDramInVpd( i_chip, i_rank, chipMark.getSymbol() );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "setDramInVpd(0x%08x,0x%02x) failed",
                          i_chip->getHuid(), i_rank.getKey() );
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t chipMarkCleanup<TYPE_MCA>( ExtensibleChip * i_chip,
                                    const MemRank & i_rank,
                                    STEP_CODE_DATA_STRUCT & io_sc );
template
uint32_t chipMarkCleanup<TYPE_MBA>( ExtensibleChip * i_chip,
                                    const MemRank & i_rank,
                                    STEP_CODE_DATA_STRUCT & io_sc );

#endif // not supported on FSP

} // end namespace MarkStore

} // end namespace PRDF

