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

CenReadAddrReg READ_NCE_ADDR = "MBNCER";
CenReadAddrReg READ_RCE_ADDR = "MBRCER";
CenReadAddrReg READ_MPE_ADDR = "MBMPER";
CenReadAddrReg READ_UE_ADDR  = "MBUER";

//------------------------------------------------------------------------------

int32_t getCenReadAddr( ExtensibleChip * i_membChip, uint32_t i_mbaPos,
                        CenReadAddrReg i_addrReg, CenAddr & o_addr )
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

        if ( MAX_MBA_PER_MEMBUF <= i_mbaPos )
        {
            PRDF_ERR( PRDF_FUNC"Invalid MBA position" );
            o_rc = FAIL; break;
        }

        // Build register string
        char reg_str[64];
        sprintf( reg_str, "MBA%d_%s", i_mbaPos, i_addrReg );

        // Read from hardware
        SCAN_COMM_REGISTER_CLASS * reg = i_membChip->getRegister(reg_str);
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on %s", reg_str );
            break;
        }
        uint64_t addr = reg->GetBitFieldJustified( 0, 64 );

        // Get the address type.
        uint32_t type = CenAddr::NONE;
        if      ( READ_NCE_ADDR == i_addrReg ) type = CenAddr::NCE;
        else if ( READ_RCE_ADDR == i_addrReg ) type = CenAddr::RCE;
        else if ( READ_MPE_ADDR == i_addrReg ) type = CenAddr::MPE;
        else if ( READ_UE_ADDR  == i_addrReg ) type = CenAddr::UE;
        else
        {
            PRDF_ERR( PRDF_FUNC"Unsupported register" );
            o_rc = FAIL; break;
        }

        o_addr = CenAddr::fromReadAddr( addr, type );

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_membChip=0x%08x i_mbaPos=%d i_addrReg=%s",
                  i_membChip->GetId(), i_mbaPos, i_addrReg );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t setCenReadAddr( ExtensibleChip * i_membChip, uint32_t i_mbaPos,
                        CenReadAddrReg i_addrReg, const CenAddr & i_addr )
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

        if ( MAX_MBA_PER_MEMBUF <= i_mbaPos )
        {
            PRDF_ERR( PRDF_FUNC"Invalid MBA position" );
            o_rc = FAIL; break;
        }

        // Build register string
        char reg_str[64];
        sprintf( reg_str, "MBA%d_%s", i_mbaPos, i_addrReg );

        // Write to hardware
        SCAN_COMM_REGISTER_CLASS * reg = i_membChip->getRegister(reg_str);
        reg->SetBitFieldJustified( 0, 64, i_addr.toReadAddr() );
        o_rc = reg->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on %s", reg_str );
            break;
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_membChip=0x%08x i_mbaPos=%d i_addrReg=%s",
                  i_membChip->GetId(), i_mbaPos, i_addrReg );
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
