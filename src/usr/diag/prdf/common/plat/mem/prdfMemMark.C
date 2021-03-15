/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemMark.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include <prdfMemUtils.H>

#include <stdio.h>

#ifdef __HOSTBOOT_MODULE
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
//                  Utilities to read/write markstore
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
//      - Chip marks will use HWMS0-7 registers:
//          Axone:  (0x08011C10-0x08011C17)
//      - Symbol marks will use FWMS0-7 registers:
//          Axone:  (0x08011C18-0x08011C1F)
//      - Each register maps to master ranks 0-7.

template<TARGETING::TYPE T>
uint32_t readChipMark( ExtensibleChip * i_chip, const MemRank & i_rank,
                       MemMark & o_mark )
{
    #define PRDF_FUNC "[readChipMark<T>] "

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

template
uint32_t readChipMark<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                       const MemRank & i_rank,
                                       MemMark & o_mark );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t writeChipMark( ExtensibleChip * i_chip, const MemRank & i_rank,
                        const MemMark & i_mark )
{
    #define PRDF_FUNC "[writeChipMark<T>] "

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

template
uint32_t writeChipMark<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                        const MemRank & i_rank,
                                        const MemMark & i_mark );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t clearChipMark( ExtensibleChip * i_chip, const MemRank & i_rank )
{
    #define PRDF_FUNC "[clearChipMark<T>] "

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

template
uint32_t clearChipMark<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                        const MemRank & i_rank );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t readSymbolMark( ExtensibleChip * i_chip,
                         const MemRank & i_rank, MemMark & o_mark )
{
    #define PRDF_FUNC "[readSymbolMark<T>] "

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

template
uint32_t readSymbolMark<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                         const MemRank & i_rank,
                                         MemMark & o_mark );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t writeSymbolMark( ExtensibleChip * i_chip, const MemRank & i_rank,
                          const MemMark & i_mark )
{
    #define PRDF_FUNC "[writeSymbolMark<T>] "

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

template
uint32_t writeSymbolMark<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          const MemRank & i_rank,
                                          const MemMark & i_mark );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t clearSymbolMark( ExtensibleChip * i_chip, const MemRank & i_rank )
{
    #define PRDF_FUNC "[clearSymbolMark<T>] "

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

template
uint32_t clearSymbolMark<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          const MemRank & i_rank );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
bool isSafeToRemoveChipMark( ExtensibleChip * i_chip, const MemRank & i_rank )
{
    bool o_safeToRemoveCm = false;

    // Check the per-symbol CE and MCE counters to determine whether it
    // is safe to remove the chip mark (bad symbol == symbol has a count of
    // more than one).
    MemUtils::MaintSymbols badNonCmSyms;
    MemSymbol junk;

    if ( SUCCESS == MemUtils::collectCeStats<T>(i_chip, i_rank, badNonCmSyms,
                                                junk, 2) )
    {
        uint8_t badCmSyms = MemUtils::collectMceBadSyms<T>( i_chip );

        // If there are 2 or more bad chip-marked symbols and 1 or more
        // non-chip marked symbols then there is a UE risk if we remove the
        // chip mark so it is not safe to do so.
        if ( badCmSyms < 2 || badNonCmSyms.size() < 1 )
        {
            o_safeToRemoveCm = true;
        }
    }

    return o_safeToRemoveCm;
}

template
bool isSafeToRemoveChipMark<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                             const MemRank & i_rank );

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
uint32_t __addRowRepairCallout( TargetHandle_t i_trgt,
                                const MemRank & i_rank,
                                STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__addRowRepairCallout] "

    uint32_t o_rc = SUCCESS;

    // Get the dimms on this rank on either port.
    TargetHandleList dimmList = getConnectedDimms( i_trgt, i_rank );

    // Check for row repairs on each dimm.
    for ( auto const & dimm : dimmList )
    {
        MemRowRepair rowRepair;
        o_rc = getRowRepairData<T>( dimm, i_rank, rowRepair );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getRowRepairData(0x%08x, 0x%02x)",
                      PlatServices::getHuid(dimm), i_rank.getKey() );
            break;
        }

        // If the row repair is valid, add it to the callout list.
        if ( rowRepair.isValid() )
        {
            io_sc.service_data->SetCallout( dimm );
        }
    }

    return o_rc;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __applyRasPolicies( ExtensibleChip * i_chip, const MemRank & i_rank,
                             STEP_CODE_DATA_STRUCT & io_sc,
                             const MemMark & i_chipMark,
                             const MemMark & i_symMark,
                             TdEntry * & o_dsdEvent, bool & o_allRepairsUsed );

template<>
uint32_t __applyRasPolicies<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                             const MemRank & i_rank,
                                             STEP_CODE_DATA_STRUCT & io_sc,
                                             const MemMark & i_chipMark,
                                             const MemMark & i_symMark,
                                             TdEntry * & o_dsdEvent,
                                             bool & o_allRepairsUsed )
{
    #define PRDF_FUNC "[__applyRasPolicies<TYPE_OCMB_CHIP>] "

    uint32_t o_rc = SUCCESS;

    do
    {
        const uint8_t ps   = i_chipMark.getSymbol().getPortSlct();
        const uint8_t dram = i_chipMark.getSymbol().getDram();

        TargetHandle_t memPort = getConnectedChild( i_chip->getTrgt(),
                                                    TYPE_MEM_PORT, ps );

        // Determine if DRAM sparing is enabled.
        bool isEnabled = false;
        o_rc = isDramSparingEnabled<TYPE_MEM_PORT>( memPort, i_rank, ps,
                                                    isEnabled );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "isDramSparingEnabled() failed." );
            break;
        }

        // Sparing supported
        if ( isEnabled )
        {
            // Sparing is enabled. Get the current spares in hardware.
            MemSymbol sp0, sp1, ecc;
            o_rc = mssGetSteerMux<TARGETING::TYPE_OCMB_CHIP>(i_chip->getTrgt(),
                                                             i_rank, sp0, sp1);
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

            // Add the row repairs to the callout list if they exist
            o_rc = __addRowRepairCallout<TARGETING::TYPE_OCMB_CHIP>( memPort,
                                                                     i_rank,
                                                                     io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__addRowRepairCallout(0x%08x,0x%02x) "
                          "failed.", i_chip->getHuid(), i_rank.getKey() );
                break;
            }

            // Certain DIMMs may have had spares intentially made unavailable by
            // the manufacturer. Check the VPD for available spares.
            bool spAvail;
            o_rc = isSpareAvailable<TYPE_MEM_PORT>( memPort, i_rank,
                                                    ps, spAvail );
            if ( spAvail )
            {
                // If spare0 is deployed and bad (has the chip mark), we want to
                // undo spare0 and then deploy spare 1.
                if ( sp0.isValid() && (dram == sp0.getDram()) )
                {
                    // TODO TMP_CNP - call to undo steering to spare0
                }
                // A spare DRAM is available.
                o_dsdEvent = new DsdEvent<TYPE_OCMB_CHIP>{ i_chip, i_rank,
                                                           i_chipMark };
            }
            else
            {
                PRDF_TRAC( PRDF_FUNC "Dram sparing enabled but not possible. "
                           "All repairs used." );
                // Chip mark is in place and sparing is not possible.
                o_allRepairsUsed = true;
                io_sc.service_data->setSignature( i_chip->getHuid(),
                                                  PRDFSIG_AllDramRepairs );
            }
        }
        // Sparing not supported
        else
        {
            // There is no DRAM sparing so simply check if both the chip and
            // symbol mark have been used.
            if ( i_chipMark.isValid() && i_symMark.isValid() )
            {
                PRDF_TRAC( PRDF_FUNC "Dram sparing not enabled. All repairs "
                           "used." );
                o_allRepairsUsed = true;
                io_sc.service_data->setSignature( i_chip->getHuid(),
                                                  PRDFSIG_AllDramRepairs );
            }

            #ifdef __HOSTBOOT_RUNTIME
            // The error log should be predictive if there has been
            // a least one false alarm on any DRAM on this rank other than this
            // DRAM. This is required because of two symbol correction,
            VcmFalseAlarm * faCntr =
                getOcmbDataBundle(i_chip)->getVcmFalseAlarmCounter();
            if ( faCntr->queryDrams(i_rank, dram, io_sc) )
            {
                // setting o_allRepairsUsed will set the service call flag to
                // make the log predictive
                o_allRepairsUsed = true;
                PRDF_TRAC( PRDF_FUNC "VCM false alarms found on other DRAMs "
                           "besides the one currently chip marked." );
            }
            #endif

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

        // Get the row repair
        // TODO RTC 210072 - support for multiple ports
        TargetHandle_t dimm = getConnectedDimm( i_chip->getTrgt(), i_rank );
        MemRowRepair rowRepair;
        o_rc = getRowRepairData<T>( dimm, i_rank, rowRepair );

        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getRowRepair(0x%08x,0x%02x) failed",
                      getHuid(dimm), i_rank.getKey() );
            break;
        }

        // If the chip mark is on the DRAM with a row repair, clear the row
        // repair from VPD.
        if ( rowRepair.isValid() &&
             (chipMark.getSymbol().getDram() == rowRepair.getRowRepairDram()) )
        {
            o_rc = clearRowRepairData<T>( dimm, i_rank );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "clearRowRepair(0x%08x,0x%02x) failed",
                          getHuid(dimm), i_rank.getKey() );
                break;
            }
        }

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

        // We want to try to avoid garding NVDIMMs, so clear gard for them now.
        io_sc.service_data->clearNvdimmMruListGard();

    }

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t applyRasPolicies<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
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

        // Set the chip mark in the DRAM Repairs VPD.
        if ( !areDramRepairsDisabled() )
        {
            o_rc = setDramInVpd( i_chip->getTrgt(), i_rank,
                                 chipMark.getSymbol() );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "setDramInVpd(0x%08x,0x%02x) failed",
                          i_chip->getHuid(), i_rank.getKey() );
                break;
            }
        }

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

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t chipMarkCleanup<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          const MemRank & i_rank,
                                          STEP_CODE_DATA_STRUCT & io_sc );

#endif // not supported on FSP

} // end namespace MarkStore

} // end namespace PRDF

