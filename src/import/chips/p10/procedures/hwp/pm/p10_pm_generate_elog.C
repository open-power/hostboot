/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_generate_elog.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024,2025                        */
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
///
/// @file p10_pm_generate_elog.H
/// @brief This hardware procedure facilitates extraction and commitment of elog in HB context:
///
/// *HWP HW Owner    : Prem S Jha (premjha2@in.ibm.com)
/// *HWP FW Owner    : Greg Still(stillgs@us.ibm.com)
/// *HWP Team        : PM
/// *HWP Consumed by : HB
/// *HWP Level       : 3
///
//  EKB-Mirror-To: hostboot

#include<p10_pm_generate_elog.H>
#include <p10_hcd_memmap_base.H>

enum
{
#ifndef __HOSTBOOT_MODULE
    QME_COMP_ID     =   0x2900,
    XGPE_COMP_ID    =   0x2F00,
#endif
    SRAM_ROW_SIZE   =   16,
};

fapi2::ReturnCode p10_pm_generate_elog( fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_procChip,
                                        uint32_t i_coreId,  ElogDissectionSum& o_logData, uint8_t* o_pBuf, uint32_t& io_bufLength )
{
    // 1)    first let us determine if  there is an error log waiting to be collected
    // 2)    Once an error log is found, identify its source
    // 3)    create an error log  instance and package the PM elog as user data payload
    // 4)    creator should be PM Complex component.
    fapi2::ReturnCode rc_fapi( fapi2::FAPI2_RC_SUCCESS );
    uint32_t l_logSlot = 0;
    uint32_t l_logSrc = QME_COMP_ID;
    //Size of rounded to multiple of 16B
    uint32_t l_elogTblSize =
        ( ( (sizeof(hcode_error_table_t) + (SRAM_ROW_SIZE - 1) ) >> 4 ) << 4 );
    hcode_error_table_t* l_pElogTbl = nullptr;
    l_pElogTbl = ( hcode_error_table_t* )new uint8_t [l_elogTblSize];
    memset( (uint8_t*)(l_pElogTbl), 0 , l_elogTblSize  );
    FAPI_INF( "Elog Table Size is 0x%08x", l_elogTblSize );
    o_logData.iv_compId = QME_COMP_ID;

    FAPI_ASSERT( ( o_pBuf != NULL ),
                 fapi2::BAD_ELOG_BUFFER()
                 .set_ELOG_BUF( o_pBuf )
                 .set_ELOG_BUF_SIZE( io_bufLength ),
                 "Invalid Elog Buffer" );

    FAPI_TRY( p10_pm_elog_list( i_procChip, PPE_TYPE_QME, ( i_coreId >> 2 ), l_pElogTbl, true ),
              "Failed To Query Hcode Log In QME SRAM" );

    l_logSlot = htobe32( l_pElogTbl->dw0.fields.total_log_slots );

    if( 0 == l_logSlot )
    {
        //No Log found in QME SRAM. Let us check OCC SRAM. Just in case QME
        //logs got copied over to OCC SRAM by XGPE
        FAPI_TRY( p10_pm_elog_list( i_procChip,
                                    PPE_TYPE_QME,
                                    ( i_coreId >> 2 ),
                                    l_pElogTbl,
                                    false ),
                  "Failed To Query Hcode Log In OCC SRAM" );

        l_logSrc = XGPE_COMP_ID; //Source of log  is XGPE SRAM
        l_logSlot = l_pElogTbl->dw0.fields.total_log_slots;

        if( 0 == l_logSlot )
        {
            //did not find a log in QME SRAM as well as OCC SRAM
            //indicate to caller through buffer length. This may
            //prevent caller from creating a false log
            io_bufLength = 0;
        }
    }

    for( uint8_t l_slot = 0; l_slot < l_logSlot; l_slot++ )
    {
        if( ! l_pElogTbl->elog[l_slot].dw0.fields.errlog_len )
        {
            continue;
        }

        uint32_t l_logLength = htobe16( l_pElogTbl->elog[l_slot].dw0.fields.errlog_len );

        FAPI_ASSERT( ( io_bufLength >= l_logLength ),
                     fapi2::BAD_ELOG_BUFFER_LENGTH()
                     .set_ACTUAL_BUFFER_LENGTH( io_bufLength )
                     .set_EXPECTED_BUFFER_LENGTH( l_logLength ),
                     "Invalid Elog Buffer Length %d", io_bufLength );

        //Found a valid log that can fit into input buffer. Let us copy it to output buffer
        FAPI_TRY( p10_pm_elog_read( i_procChip,
                                    l_pElogTbl->elog[l_slot].dw0.value,
                                    o_pBuf,
                                    (i_coreId >> 2 ), l_logLength,
                                    ( l_logSrc == QME_COMP_ID ) ? true : false ),
                  "Failed To Copy Hcode Log Into Memory Buffer" );

        //Copying actual size of buffer used
        io_bufLength = l_logLength;

        FAPI_TRY( p10_pm_elog_dissect( o_pBuf, o_logData ),
                  "Failed To Extract Hcode Log Details" );

        //breaking out on finding first valid log. This is expected to be the only
        //log available at the point of query
        break;
    }

fapi_try_exit:
    delete[] l_pElogTbl;
    return fapi2::current_err;
}
