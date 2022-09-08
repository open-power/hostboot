/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_getsram.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file p10_getsram.C
/// @brief Read data from IO PPE SRAM
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus, SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_getsram.H>
#include <p10_getputsram_utils.H>
#include <p10_getsram_io_ppe.H>
#include <p10_qme_sram_access.H>
#include <p10_pm_ocb_indir_access.H>
#include <p10_read_xram.H>
#include <p10_pm_ocb_indir_setup_linear.H>
#include <p10_pm_ocb_indir_setup_circular.H>
#include <p10_hcd_memmap_occ_sram.H>
#include <p10_hcd_memmap_qme_sram.H>

/// @brief Misc constants useful for HWP
enum
{
    PGPE_SRAM_END_ADDR  = ( PGPE_SRAM_BASE_ADDR + OCC_SRAM_PGPE_REGION_SIZE ),
    XGPE_SRAM_END_ADDR  = ( XGPE_SRAM_BASE_ADDR + OCC_SRAM_XGPE_REGION_SIZE ),
    QME_SRAM_END_ADDR   = ( QME_SRAM_BASE_ADDR  + QME_SRAM_SIZE ),
};

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
/// NOTE: doxygen in header
fapi2::ReturnCode p10_getsram(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t i_pervChipletId,
    const uint8_t i_mode,
    const uint64_t i_offset,
    const uint32_t i_bytes,
    uint8_t* o_data)
{
    FAPI_DBG("Start");

    FAPI_DBG("p10_getsram: PervChipletId 0x%.8X, i_mode 0x%.2X, i_offset %p, i_bytes %u.",
             i_pervChipletId, i_mode, i_offset, i_bytes);

    //Let us determine it is not Chip0 of IOSCM
    auto l_funCoreList = i_target.getChildren< fapi2::TARGET_TYPE_CORE >();

    if ( (i_pervChipletId >= PAU0_PERV_CHIPLET_ID) && (i_pervChipletId <= PAU3_PERV_CHIPLET_ID) )
    {
        for (auto& l_pauc : i_target.getChildren<fapi2::TARGET_TYPE_PAUC>())
        {
            if (l_pauc.getChipletNumber() == i_pervChipletId)
            {
                FAPI_EXEC_HWP(fapi2::current_err,
                              p10_getsram_io_ppe,
                              l_pauc,
                              i_offset,
                              i_bytes,
                              o_data);
                goto fapi_try_exit;
            }
        }
    }
    else if ( (i_pervChipletId >= EQ0_PERV_CHIPLET_ID) && (i_pervChipletId <= EQ7_PERV_CHIPLET_ID) )
    {
        if((( i_offset >= QME_SRAM_BASE_ADDR ) && ( i_offset <= QME_SRAM_END_ADDR ) ) &&
           ( 0 == l_funCoreList.size() ))
        {
            FAPI_INF( "Ignoring SRAM dump for QME on IOSCM system" );
            goto fapi_try_exit;
        }

        // Call QME PPE SRAM read HWP here
        for (auto& l_eq : i_target.getChildren<fapi2::TARGET_TYPE_EQ>())
        {
            if (l_eq.getChipletNumber() == i_pervChipletId)
            {
                uint32_t l_bytesRead = 0;
                FAPI_TRY (p10_qme_sram_access_bytes(
                              l_eq,
                              static_cast<uint32_t>(i_offset),
                              i_bytes,
                              qmesram::GET,
                              o_data,
                              l_bytesRead));
                FAPI_DBG("p10_getsram: p10_qme_sram_access_bytes - Bytes read %u", l_bytesRead);
                goto fapi_try_exit;
            }
        }
    }
    else if ( (i_pervChipletId >= PCI0_PERV_CHIPLET_ID) && (i_pervChipletId <= PCI1_PERV_CHIPLET_ID) )
    {
        // Reading IOP XRAM
        for (const auto& l_pec : i_target.getChildren<fapi2::TARGET_TYPE_PEC>())
        {
            if (l_pec.getChipletNumber() == i_pervChipletId)
            {
                // Get top number (bit 0) of i_mode
                xramIopTopNum_t l_topNum = XRAM_TOP_0;

                if (i_mode & MODE_PCIE_TOP_BIT_MASK)
                {
                    l_topNum = XRAM_TOP_1;
                }

                // Get PHY number
                xramPhyNum_t l_phyNum = XRAM_PHY_0;

                if (i_mode & MODE_PCIE_PHY_BIT_MASK)
                {
                    l_phyNum = XRAM_PHY_1;
                }

                // Call IOP SRAM write HWP here
                FAPI_EXEC_HWP(fapi2::current_err,
                              p10_read_xram,
                              l_pec,
                              i_offset,
                              i_bytes,
                              l_topNum,
                              l_phyNum,
                              o_data);
                goto fapi_try_exit;
            }
        }
    }
    else
    {
        if((( i_offset >= PGPE_SRAM_BASE_ADDR ) && ( i_offset <= PGPE_SRAM_END_ADDR ) ) &&
           ( 0 == l_funCoreList.size() ))
        {
            FAPI_INF( "Ignoring SRAM dump for PGPE on IOSCM system" );
            goto fapi_try_exit;
        }

        if((( i_offset >= XGPE_SRAM_BASE_ADDR ) && ( i_offset <= XGPE_SRAM_END_ADDR ) ) &&
           ( 0 == l_funCoreList.size() ))
        {
            FAPI_INF( "Ignoring SRAM dump for XGPE on IOSCM system" );
            goto fapi_try_exit;
        }

        // Validate OCC mode (bits 0:1 of i_mode)
        uint8_t l_occMode = (i_mode >> MODE_OCC_ACCESS_MODE_BIT_SHIFT) & 0x3;
        FAPI_ASSERT( (l_occMode >= OCB_MODE_LOWER_LIMIT) &&
                     (l_occMode <= OCB_MODE_UPPER_LIMIT), // Must be 1-3
                     fapi2::P10_INVALID_OCC_ACCESS_MODE_ERROR()
                     .set_PROC_TARGET(i_target)
                     .set_PERV_CHIPLET_ID(i_pervChipletId)
                     .set_OCC_MODE(l_occMode)
                     .set_OFFSET(i_offset),
                     "Invalid OCC SRAM access mode (%d)", l_occMode);

        // Get OCB channel (bits 2:4 of i_mode)
        ocb::PM_OCB_CHAN_NUM l_ocbChan = getOcbChanNum(i_mode);

        FAPI_TRY (p10_ocb_handlePbaContext(i_target, i_mode, true), // save context
                  "Error in p10_ocb_handlePbaContext: save");

        // Setup Circular/Linear depending on mode
        if (l_occMode == OCB_MODE_CIRCULAR)
        {
            FAPI_EXEC_HWP(fapi2::current_err,
                          p10_pm_ocb_indir_setup_circular,
                          i_target,
                          l_ocbChan,
                          ocb::OCB_TYPE_NULL,         // ocb type
                          0,                          // ocb bar
                          0,                          // ocb_q_len
                          ocb::OCB_Q_OUFLOW_NULL,     // ocb_outflow
                          ocb::OCB_Q_ITPTYPE_NULL);   // itp_type
        }
        else
        {
            FAPI_EXEC_HWP(fapi2::current_err,
                          p10_pm_ocb_indir_setup_linear,
                          i_target,
                          l_ocbChan,
                          ocb::OCB_TYPE_LINSTR, // Linear with address inc
                          0);                   // Default to 0
        }

        // Call OCC SRAM read HWP here
        uint32_t l_bytesRead = 0;
        FAPI_TRY(p10_pm_ocb_indir_access_bytes
                 (i_target,
                  l_ocbChan,
                  ocb::OCB_GET,
                  i_bytes,
                  true,
                  static_cast<uint32_t>(i_offset),
                  l_bytesRead,
                  o_data));
        FAPI_DBG("p10_getsram: p10_pm_ocb_indir_access - Bytes read %u", l_bytesRead);

        FAPI_TRY (p10_ocb_handlePbaContext(i_target, i_mode, false), // restore context
                  "Error in p10_ocb_handlePbaContext: restore");

        goto fapi_try_exit;
    }

    FAPI_ASSERT(false,
                fapi2::P10_GETSRAM_TARGET_NOT_FUNCTIONAL_ERROR()
                .set_PROC_TARGET(i_target)
                .set_PERV_CHIPLET_ID(i_pervChipletId)
                .set_MODE(i_mode)
                .set_OFFSET(i_offset)
                .set_BYTES(i_bytes),
                "Requested pervasive chiplet ID not functional on target chip");

fapi_try_exit:

    FAPI_DBG("End");
    return fapi2::current_err;
}
