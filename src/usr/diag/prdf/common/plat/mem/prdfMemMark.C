/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemMark.C $             */
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

#include <prdfMemMark.H>

#include <prdfTrace.H>

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

    o_rc = hwms->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on %s: i_chip=0x%08x",
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
    hwms->SetBitFieldJustified( 0, 8, i_mark.getGalois() );

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

    o_rc = fwms->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on %s: i_chip=0x%08x",
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

template<>
uint32_t readChipMark<TYPE_MBA>( ExtensibleChip * i_chip,
                                 const MemRank & i_rank, MemMark & o_mark )
{
    #define PRDF_FUNC "[readChipMark<TYPE_MBA>] "

    uint32_t o_rc = SUCCESS;

    o_mark = MemMark(); // ensure invalid

    // TODO: RTC 157888

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );

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

    // TODO: RTC 157888

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );

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

    // TODO: RTC 157888

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );

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

    // TODO: RTC 157888

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );

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

    // TODO: RTC 157888

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );

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

    // TODO: RTC 157888

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace MarkStore

} // end namespace PRDF

