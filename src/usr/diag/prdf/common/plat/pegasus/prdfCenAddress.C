/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenAddress.C $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/** @file  prdfCenAddress.C
 *  @brief General utilities to read, modify, and write the memory address
 *         registers (MBMACA, MBMEA, etc.). Also includes the CenRank class.
 */

#include <prdfCenAddress.H>

#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------
//                       MBS Address Registers
//------------------------------------------------------------------------------

CenReadAddrReg READ_NCE_ADDR_0 = "MBA0_MBNCER";
CenReadAddrReg READ_RCE_ADDR_0 = "MBA0_MBRCER";
CenReadAddrReg READ_MPE_ADDR_0 = "MBA0_MBMPER";
CenReadAddrReg READ_UE_ADDR_0  = "MBA0_MBUER";

CenReadAddrReg READ_NCE_ADDR_1 = "MBA1_MBNCER";
CenReadAddrReg READ_RCE_ADDR_1 = "MBA1_MBRCER";
CenReadAddrReg READ_MPE_ADDR_1 = "MBA1_MBMPER";
CenReadAddrReg READ_UE_ADDR_1  = "MBA1_MBUER";

//------------------------------------------------------------------------------

int32_t getCenReadAddr( ExtensibleChip * i_membChip, CenReadAddrReg i_addrReg,
                        CenAddr & o_addr )
{
    #define PRDF_FUNC "[getCenReadAddr] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t membTrgt = i_membChip->GetChipHandle();

    do
    {
        // Check parameters
        if ( TYPE_MEMBUF != getTargetType(membTrgt) )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported target type" );
            o_rc = FAIL; break;
        }

        // Read from hardware
        SCAN_COMM_REGISTER_CLASS * reg = i_membChip->getRegister(i_addrReg);
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on %s", i_addrReg );
            break;
        }
        uint64_t addr = reg->GetBitFieldJustified( 0, 64 );

        // Get the address type.
        uint32_t type = CenAddr::NONE;
        if      ( READ_NCE_ADDR_0 == i_addrReg || READ_NCE_ADDR_1 == i_addrReg )
            type = CenAddr::NCE;
        else if ( READ_RCE_ADDR_0 == i_addrReg || READ_RCE_ADDR_1 == i_addrReg )
            type = CenAddr::RCE;
        else if ( READ_MPE_ADDR_0 == i_addrReg || READ_MPE_ADDR_1 == i_addrReg )
            type = CenAddr::MPE;
        else if ( READ_UE_ADDR_0  == i_addrReg || READ_UE_ADDR_1  == i_addrReg )
            type = CenAddr::UE;
        else
        {
            PRDF_ERR( PRDF_FUNC"Unsupported register" );
            o_rc = FAIL; break;
        }

        o_addr = CenAddr::fromReadAddr( addr, type );

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: HUID=0x%08x addrReg='%s'",
                  getHuid(membTrgt), i_addrReg );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t setCenReadAddr( ExtensibleChip * i_membChip, CenReadAddrReg i_addrReg,
                        const CenAddr & i_addr )
{
    #define PRDF_FUNC "[setCenReadAddr] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t membTrgt = i_membChip->GetChipHandle();

    do
    {
        // Check parameters
        if ( TYPE_MEMBUF != getTargetType(membTrgt) )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported target type" );
            o_rc = FAIL; break;
        }

        // Write to hardware
        SCAN_COMM_REGISTER_CLASS * reg = i_membChip->getRegister(i_addrReg);
        reg->SetBitFieldJustified( 0, 64, i_addr.toReadAddr() );
        o_rc = reg->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on %s", i_addrReg );
            break;
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: HUID=0x%08x addrReg='%s'",
                  getHuid(membTrgt), i_addrReg );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------
//                       MBA Address Registers
//------------------------------------------------------------------------------

int32_t getCenMaintStartAddr( ExtensibleChip * i_mbaChip, CenAddr & o_addr )
{
    #define PRDF_FUNC "[getCenMaintStartAddr] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mbaTrgt = i_mbaChip->GetChipHandle();

    do
    {
        // Check parameters
        if ( TYPE_MBA != getTargetType(mbaTrgt) )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported target type" );
            o_rc = FAIL; break;
        }

        // Read from hardware
        SCAN_COMM_REGISTER_CLASS * reg = i_mbaChip->getRegister("MBMACA");
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on MBMACA" );
            break;
        }
        uint64_t addr = reg->GetBitFieldJustified( 0, 64 );

        o_addr = CenAddr::fromMaintStartAddr( addr );

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: HUID=0x%08x", getHuid(mbaTrgt) );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t setCenMaintStartAddr( ExtensibleChip * i_mbaChip,
                              const CenAddr & i_addr )
{
    #define PRDF_FUNC "[setCenMaintStartAddr] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mbaTrgt = i_mbaChip->GetChipHandle();

    do
    {
        // Check parameters
        if ( TYPE_MBA != getTargetType(mbaTrgt) )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported target type" );
            o_rc = FAIL; break;
        }

        // Write to hardware
        SCAN_COMM_REGISTER_CLASS * reg = i_mbaChip->getRegister("MBMACA");
        reg->SetBitFieldJustified( 0, 64, i_addr.toMaintStartAddr() );
        o_rc = reg->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on MBMACA" );
            break;
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: HUID=0x%08x", getHuid(mbaTrgt) );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t getCenMaintEndAddr( ExtensibleChip * i_mbaChip, CenAddr & o_addr )
{
    #define PRDF_FUNC "[getCenMaintEndAddr] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mbaTrgt = i_mbaChip->GetChipHandle();

    do
    {
        // Check parameters
        if ( TYPE_MBA != getTargetType(mbaTrgt) )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported target type" );
            o_rc = FAIL; break;
        }

        // Read from hardware
        SCAN_COMM_REGISTER_CLASS * reg = i_mbaChip->getRegister("MBMEA");
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on MBMEA" );
            break;
        }
        uint64_t addr = reg->GetBitFieldJustified( 0, 64 );

        o_addr = CenAddr::fromMaintEndAddr( addr );

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: HUID=0x%08x", getHuid(mbaTrgt) );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t setCenMaintEndAddr( ExtensibleChip * i_mbaChip, const CenAddr & i_addr )
{
    #define PRDF_FUNC "[setCenMaintEndAddr] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mbaTrgt = i_mbaChip->GetChipHandle();

    do
    {
        // Check parameters
        if ( TYPE_MBA != getTargetType(mbaTrgt) )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported target type" );
            o_rc = FAIL; break;
        }

        // Write to hardware
        SCAN_COMM_REGISTER_CLASS * reg = i_mbaChip->getRegister("MBMEA");
        reg->SetBitFieldJustified( 0, 64, i_addr.toMaintEndAddr() );
        o_rc = reg->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on MBMEA" );
            break;
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: HUID=0x%08x", getHuid(mbaTrgt) );
    }

    return o_rc;

    #undef PRDF_FUNC
}

} // end namespace PRDF
