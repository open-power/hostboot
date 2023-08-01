/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemRowRepair.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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

/** @file  prdfMemRowRepair.C */

#include <prdfMemRowRepair.H>

#include <UtilHash.H>
#include <iipServiceDataCollector.h>
#include <prdfParserUtils.H>
#include <prdfErrlUtil.H>
#include <prdfMemUtils.H>
#include <target_types.H>

#ifdef __HOSTBOOT_MODULE
#include <plat_hwp_invoker.H>
#include <rowRepairsFuncs.H>
#endif // __HOSTBOOT_MODULE

namespace PRDF
{

using namespace PlatServices;
using namespace PARSERUTILS;
using namespace TARGETING;


//------------------------------------------------------------------------------

bool MemRowRepair::nonZero() const
{
    bool o_nonZero = false;

    for ( uint32_t i = 0; i < ROW_REPAIR::ROW_REPAIR_SIZE; i++ )
    {
        if ( 0 != iv_data[i] )
        {
            o_nonZero = true;
            break;
        }
    }

    return o_nonZero;
}

//##############################################################################
//                              Utility Functions
//##############################################################################

template<TARGETING::TYPE T, fapi2::TargetType F>
uint32_t __getRowRepairData( TargetHandle_t i_dimm, const MemRank & i_rank,
                             MemRowRepair & o_rowRepair )
{
    #define PRDF_FUNC "[PlatServices::__getRowRepairData] "

    uint32_t o_rc = SUCCESS;


    #ifdef __HOSTBOOT_MODULE

    uint8_t l_data[ROW_REPAIR::ROW_REPAIR_SIZE] = {0};

    errlHndl_t l_errl = nullptr;

    // get port select
    uint8_t l_ps = getDimmPort( i_dimm );

    TargetHandle_t l_trgt = getConnectedParent( i_dimm, T );
    fapi2::Target<F> l_fapiTrgt( l_trgt );

    FAPI_INVOKE_HWP( l_errl, getRowRepair, l_fapiTrgt, i_rank.getDimmSlct(),
                     i_rank.getRankSlct(), l_data, l_ps );
    if ( nullptr != l_errl )
    {
        PRDF_ERR( PRDF_FUNC "getRowRepair() failed: i_dimm=0x%08x "
                  "l_ps=%d ds=%d rs=%d", getHuid(i_dimm), l_ps,
                  i_rank.getDimmSlct(), i_rank.getRankSlct() );
        PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    else
    {
        o_rowRepair = MemRowRepair( i_dimm, i_rank, l_data );
    }

    #endif // __HOSTBOOT_MODULE

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t getRowRepairData<TYPE_MEM_PORT>( TargetHandle_t i_dimm,
    const MemRank & i_rank, MemRowRepair & o_rowRepair )
{
    return __getRowRepairData<TYPE_MEM_PORT, fapi2::TARGET_TYPE_MEM_PORT>(
        i_dimm, i_rank, o_rowRepair );
}

template<>
uint32_t getRowRepairData<TYPE_OCMB_CHIP>( TargetHandle_t i_dimm,
    const MemRank & i_rank, MemRowRepair & o_rowRepair )
{
    return __getRowRepairData<TYPE_OCMB_CHIP, fapi2::TARGET_TYPE_OCMB_CHIP>(
        i_dimm, i_rank, o_rowRepair );
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T, fapi2::TargetType F>
uint32_t __setRowRepairData( TargetHandle_t i_dimm, const MemRank & i_rank,
                           const MemRowRepair & i_rowRepair )
{
    #define PRDF_FUNC "[PlatServices::__setRowRepairData] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE

    if ( !areDramRepairsDisabled() )
    {
        uint8_t l_data[ROW_REPAIR::ROW_REPAIR_SIZE] = {0};
        memcpy( l_data, i_rowRepair.getData(), sizeof(l_data) );

        errlHndl_t l_errl = nullptr;

        // get port select
        uint8_t l_ps = getDimmPort( i_dimm );

        TargetHandle_t l_trgt = getConnectedParent(i_dimm, T);
        fapi2::Target<F> l_fapiTrgt( l_trgt );

        FAPI_INVOKE_HWP( l_errl, setRowRepair, l_fapiTrgt, i_rank.getDimmSlct(),
                         i_rank.getRankSlct(), l_data, l_ps );
        if ( nullptr != l_errl )
        {
            PRDF_ERR( PRDF_FUNC "setRowRepair() failed: i_dimm=0x%08x "
                    "l_ps=%d ds=%d rs=%d", getHuid(i_dimm), l_ps,
                    i_rank.getDimmSlct(), i_rank.getRankSlct() );
            PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
        }

    }

    #endif // __HOSTBOOT_MODULE
    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t setRowRepairData<TYPE_OCMB_CHIP>( TargetHandle_t i_dimm,
                                           const MemRank & i_rank,
                                           const MemRowRepair & i_rowRepair )
{
    return __setRowRepairData<TYPE_OCMB_CHIP, fapi2::TARGET_TYPE_OCMB_CHIP>(
        i_dimm, i_rank, i_rowRepair );
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __setRowRepairDataHelper( const MemAddr & i_addr, uint32_t & io_tmp,
                               bool i_isOdy )
{
    #ifdef __HOSTBOOT_MODULE

    // The format for bank and bank group differs from Explorer to Odyssey OCMBs
    // Odyssey OCMBs
    if (i_isOdy)
    {
        // MemAddr Bank format - OCMB (Odyssey) : b0-b1,bg0-bg2 (5-bit)
        // bank group - 3 bits (bg2-bg0)
        uint64_t l_bnkGrp = i_addr.getBank() & 0x07;
        l_bnkGrp = MemUtils::reverseBits( l_bnkGrp, 3 );

        io_tmp = ( io_tmp << 3 ) | ( l_bnkGrp & 0x07 );

        // bank - 2 bits (b1-b0)
        uint64_t l_bnk = (i_addr.getBank() & 0x18) >> 3;
        l_bnk = MemUtils::reverseBits( l_bnk, 2 );

        io_tmp = ( io_tmp << 2 ) | ( l_bnk & 0x03 );
    }
    // Explorer OCMBs
    else
    {
        // MemAddr Bank format - OCMB (Explorer): b0-b2,bg0-bg1 (5-bit)
        // bank group - 2 bits (bg1-bg0)
        uint64_t l_bnkGrp = i_addr.getBank() & 0x03;
        l_bnkGrp = MemUtils::reverseBits( l_bnkGrp, 2 );

        io_tmp = ( io_tmp << 2 ) | ( l_bnkGrp & 0x03 );

        // bank - 3 bits (b2-b0)
        uint64_t l_bnk = (i_addr.getBank() & 0x1C) >> 2;
        l_bnk = MemUtils::reverseBits( l_bnk, 3 );

        io_tmp = ( io_tmp << 3 ) | ( l_bnk & 0x03 );
    }

    // Row is stored as "MCBIST: r0-r17 (18-bit)" in a MemAddr.
    uint64_t l_row = MemUtils::reverseBits( i_addr.getRow(), 18 );

    // row - 18 bits (r17-r0)
    io_tmp = ( io_tmp << 18 ) | ( l_row & 0x0003ffff );

    #endif // __HOSTBOOT_MODULE
}

template
void __setRowRepairDataHelper<TYPE_OCMB_CHIP>(const MemAddr & i_addr,
                                              uint32_t & io_tmp, bool i_isOdy);

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t setRowRepairData( TargetHandle_t i_dimm,
                           const MemRank & i_rank,
                           const MemAddr & i_addr,
                           uint8_t i_dram )
{
    #define PRDF_FUNC "[PlatServices::setRowRepairData] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE

    if ( !areDramRepairsDisabled() )
    {
        uint32_t l_tmp = 0;

        // The format for a row repair is 32 bits total. The bank/bank group
        // fields differ slightly between Explorer and Odyssey OCMBs:
        // Explorer OCMBs:
        // 5 bits : DRAM position (x8: 0-9, x4: 0-19)
        // 3 bits : slave ranks (srank0-srank2)
        // 2 bits : bank group (bg1-bg0)
        // 3 bits : bank (b2-b0)
        // 18 bits: row (r17-r0)
        // 1 bit  : repair validity (0: invalid, 1: valid)
        // Odyssey OCMBs:
        // 5 bits : DRAM position (x8: 0-9, x4: 0-19)
        // 3 bits : secondary rank (srank0-srank2)
        // 3 bits : bank group (bg2-bg0)
        // 2 bits : bank (b1-b0)
        // 18 bits: row (r17-r0)
        // 1 bit  : repair validity (0: invalid, 1: valid)

        // dram - 5 bits
        l_tmp = ( l_tmp << 5 ) | ( i_dram & 0x1f );

        // slave rank - 3 bits
        l_tmp = ( l_tmp << 3 ) | ( i_addr.getRank().getSlave() & 0x07 );

        TargetHandle_t ocmb = getConnectedParent(i_dimm, TYPE_OCMB_CHIP);
        bool isOdy = isOdysseyOcmb(ocmb);

        // bank group, bank, and row - 23 bits
        __setRowRepairDataHelper<T>( i_addr, l_tmp, isOdy );

        // validity - 1 bit
        l_tmp = ( l_tmp << 1 ) | 0x1;

        // ROW_REPAIR_SIZE = 4
        uint8_t l_data[ROW_REPAIR::ROW_REPAIR_SIZE] = {0};
        memcpy( l_data, &l_tmp, sizeof(l_data) );

        MemRowRepair l_rowRepair( i_dimm, i_rank, l_data );

        o_rc = setRowRepairData<T>( i_dimm, i_rank, l_rowRepair );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setRowRepairData() failed" );
        }

    }

    #endif // __HOSTBOOT_MODULE

    return o_rc;

    #undef PRDF_FUNC

}

template
uint32_t setRowRepairData<TYPE_OCMB_CHIP>( TargetHandle_t i_dimm,
                                           const MemRank & i_rank,
                                           const MemAddr & i_addr,
                                           uint8_t i_dram );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t clearRowRepairData( TargetHandle_t i_dimm, const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::clearRowRepairData] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE

    if ( !areDramRepairsDisabled() )
    {
        uint8_t l_data[ROW_REPAIR::ROW_REPAIR_SIZE] = {0};
        memset( l_data, 0, sizeof(l_data) );

        MemRowRepair l_rowRepair( i_dimm, i_rank, l_data );

        o_rc = setRowRepairData<T>( i_dimm, i_rank, l_rowRepair );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setRowRepairData() failed" )
        }
    }

    #endif // __HOSTBOOT_MODULE

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t clearRowRepairData<TYPE_OCMB_CHIP>( TargetHandle_t i_dimm,
                                             const MemRank & i_rank );

//------------------------------------------------------------------------------

} // end namespace PRDF

