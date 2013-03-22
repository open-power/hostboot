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

ReadAddrReg READ_NCE_ADDR_0 = "MBNCER_0";
ReadAddrReg READ_RCE_ADDR_0 = "MBRCER_0";
ReadAddrReg READ_MPE_ADDR_0 = "MBMPER_0";
ReadAddrReg READ_UE_ADDR_0  = "MBUER_0";

ReadAddrReg READ_NCE_ADDR_1 = "MBNCER_1";
ReadAddrReg READ_RCE_ADDR_1 = "MBRCER_1";
ReadAddrReg READ_MPE_ADDR_1 = "MBMPER_1";
ReadAddrReg READ_UE_ADDR_1  = "MBUER_1";

//------------------------------------------------------------------------------

int32_t cenGetReadAddr( ExtensibleChip * i_mbChip, ReadAddrReg i_addrReg,
                       CenAddr & o_addr )
{
    #define PRDF_FUNC "[cenGetReadAddr] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mbTarget = i_mbChip->GetChipHandle();

    do
    {
        if ( TYPE_MEMBUF != getTargetType(mbTarget) )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported target type" );
            o_rc = FAIL; break;
        }

        SCAN_COMM_REGISTER_CLASS * reg = i_mbChip->getRegister(i_addrReg);
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC" %s Read() failed", i_addrReg );
            break;
        }

        uint32_t rank = reg->GetBitFieldJustified( 1, 3);
        uint32_t bank = reg->GetBitFieldJustified( 7, 4);
        uint32_t row  = reg->GetBitFieldJustified(11,17);
        uint32_t col  = reg->GetBitFieldJustified(28,12);

        uint32_t types = CenAddr::NONE;
        if      ( READ_NCE_ADDR_0 == i_addrReg || READ_NCE_ADDR_1 == i_addrReg )
            types = CenAddr::NCE;
        else if ( READ_RCE_ADDR_0 == i_addrReg || READ_RCE_ADDR_1 == i_addrReg )
            types = CenAddr::RCE;
        else if ( READ_MPE_ADDR_0 == i_addrReg || READ_MPE_ADDR_1 == i_addrReg )
            types = CenAddr::MPE;
        else if ( READ_UE_ADDR_0  == i_addrReg || READ_UE_ADDR_1  == i_addrReg )
            types = CenAddr::UE;
        else
        {
            PRDF_ERR( PRDF_FUNC"Unsupported register" );
            o_rc = FAIL; break;
        }

        o_addr = CenAddr ( rank, bank, row, col, types );

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: HUID=0x%08x addrReg='%s'",
                  getHuid(mbTarget), i_addrReg );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t cenSetReadAddr( ExtensibleChip * i_mbChip, ReadAddrReg i_addrReg,
                       CenAddr i_addr )
{
    #define PRDF_FUNC "[cenSetReadAddr] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mbTarget = i_mbChip->GetChipHandle();

    do
    {
        if ( TYPE_MEMBUF != getTargetType(mbTarget) )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported target type" );
            o_rc = FAIL; break;
        }

        SCAN_COMM_REGISTER_CLASS * reg = i_mbChip->getRegister(i_addrReg);
        reg->clearAllBits(); // clears out all status bits

        reg->SetBitFieldJustified(  1,  3, i_addr.getRank().flatten() );
        reg->SetBitFieldJustified(  7,  4, i_addr.getBank()           );
        reg->SetBitFieldJustified( 11, 17, i_addr.getRow()            );
        reg->SetBitFieldJustified( 28, 12, i_addr.getCol()            );

        o_rc = reg->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC" %s Write() failed", i_addrReg );
            break;
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: HUID=0x%08x addrReg='%s'",
                  getHuid(mbTarget), i_addrReg );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------
//                       MBA Address Registers
//------------------------------------------------------------------------------

MaintAddrReg MAINT_START_ADDR = "MBMACA";
MaintAddrReg MAINT_END_ADDR   = "MBMEA";

//------------------------------------------------------------------------------

int32_t cenGetMaintAddr( ExtensibleChip * i_mbaChip, MaintAddrReg i_addrReg,
                       CenAddr & o_addr )
{
    #define PRDF_FUNC "[cenGetMaintAddr] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mbaTarget = i_mbaChip->GetChipHandle();

    do
    {
        if ( TYPE_MBA != getTargetType(mbaTarget) )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported target type" );
            o_rc = FAIL; break;
        }

        SCAN_COMM_REGISTER_CLASS * reg = i_mbaChip->getRegister(i_addrReg);
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC" %s Read() failed", i_addrReg );
            break;
        }

        uint32_t rank = reg->GetBitFieldJustified( 1, 3);
        uint32_t bank = reg->GetBitFieldJustified( 7, 4);
        uint32_t row  = reg->GetBitFieldJustified(11,17);
        uint32_t col  = reg->GetBitFieldJustified(28,12);

        uint32_t types = CenAddr::NONE;
        if ( MAINT_START_ADDR == i_addrReg )
            types = reg->GetBitFieldJustified(40,7);
        else if ( MAINT_END_ADDR == i_addrReg )
            types = CenAddr::NONE;
        else
        {
            PRDF_ERR( PRDF_FUNC"Unsupported register" );
            o_rc = FAIL; break;
        }

        o_addr = CenAddr ( rank, bank, row, col, types );

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: HUID=0x%08x addrReg='%s'",
                  getHuid(mbaTarget), i_addrReg );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t cenSetMaintAddr( ExtensibleChip * i_mbaChip, MaintAddrReg i_addrReg,
                       CenAddr i_addr )
{
    #define PRDF_FUNC "[cenSetMaintAddr] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mbaTarget = i_mbaChip->GetChipHandle();

    do
    {
        if ( TYPE_MBA != getTargetType(mbaTarget) )
        {
            PRDF_ERR( PRDF_FUNC"Unsupported target type" );
            o_rc = FAIL; break;
        }

        SCAN_COMM_REGISTER_CLASS * reg = i_mbaChip->getRegister(i_addrReg);
        reg->clearAllBits(); // clears out all status bits

        reg->SetBitFieldJustified(  1,  3, i_addr.getRank().flatten() );
        reg->SetBitFieldJustified(  7,  4, i_addr.getBank()           );
        reg->SetBitFieldJustified( 11, 17, i_addr.getRow()            );
        reg->SetBitFieldJustified( 28, 12, i_addr.getCol()            );

        o_rc = reg->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC" %s Write() failed", i_addrReg );
            break;
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: HUID=0x%08x addrReg='%s'",
                  getHuid(mbaTarget), i_addrReg );
    }

    return o_rc;

    #undef PRDF_FUNC
}

} // end namespace PRDF
