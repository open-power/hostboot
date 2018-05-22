/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_firmask_save_restore.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file p9_io_obus_firmask_save_restore.H
/// @brief HWP that will give user ability to save off obus firmask into attribute
///        and restore them at a later date.
///
///-----------------------------------------------------------------------------
/// *HWP HW  Owner        : Chris Steffen    <cwsteffen@us.ibm.com>
/// *HWP HW  Backup Owner :
/// *HWP FW Owner         : Christian Geddes <crgeddes@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3
/// *HWP Consumed by      : HB
///-----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// This procedure will provide a way to save and restore OBUS and PB fir masks that
/// have to do with OBUS peer targets. During the IPL Hostboot will not know about other
/// OBUS peers so we must mask off OBUS peer related firs until HBRT when Hostboot is
/// aware of the OBUS peer targets.
///
/// Procedure Prereq:
///   - PB and OBUS scom init is called prior to saving off fir masks
///   - The save command is called prior to the restore command
///
/// @endverbatim
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Defines
//------------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9_io_obus_firmask_save_restore.H>
#include <p9_obus_scom_addresses.H>
#include <p9_obus_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include <fapi2.H>

// Firs to save and restore
// 0x5013803  = PBIOOFIR MASK
// Bits Masked on Save :
//      PARSER00_ATTN_MASK:28
//      PARSER01_ATTN_MASK:29
//      PARSER02_ATTN_MASK:30
//      PARSER03_ATTN_MASK:31
//      PARSER04_ATTN_MASK:32
//      PARSER05_ATTN_MASK:33
//      PARSER06_ATTN_MASK:34
//      PARSER07_ATTN_MASK:35
//      DOB01_ERR_MASK:52
//      DOB23_ERR_MASK:53
//      DOB45_ERR_MASK:54
//      DOB67_ERR_MASK:55
//      DIB01_ERR_MASK:56
//      DIB23_ERR_MASK:57
//      DIB45_ERR_MASK:58
//      DIB67_ERR_MASK:59
// 0x9010803  = IOOLFIR MASK ( obus 0)
// 0xA010803  = IOOLFIR MASK ( obus 1)
// 0xB010803  = IOOLFIR MASK ( obus 2)
// 0xC010803  = IOOLFIR MASK ( obus 3)
// Bits Potentially Masked on Save :
//       FIR_LINK0_NO_SPARE_MASK:42
//       FIR_LINK1_NO_SPARE_MASK:43
//       FIR_LINK0_SPARE_DONE_MASK:44
//       FIR_LINK1_SPARE_DONE_MASK:45
//       FIR_LINK0_TOO_MANY_CRC_ERRORS_MASK:46
//       FIR_LINK1_TOO_MANY_CRC_ERRORS_MASK:47
//       FIR_LINK0_CORRECTABLE_ARRAY_ERROR_MASK:52
//       FIR_LINK1_CORRECTABLE_ARRAY_ERROR_MASK:53
//       FIR_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK:54
//       FIR_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK:55
//       FIR_LINK0_TRAINING_FAILED_MASK:56
//       FIR_LINK1_TRAINING_FAILED_MASK:57
//       FIR_LINK0_UNRECOVERABLE_ERROR_MASK:58
//       FIR_LINK1_UNRECOVERABLE_ERROR_MASK:59

//-----------------------------------------------------------------------------
//  Definitions
//-----------------------------------------------------------------------------
constexpr uint8_t  SET_BYTE     = 0xFF;
// LINK_NO_SPARE_MASK Not defined in p9_obus_scom_addresses_fld so must define here
constexpr uint32_t PB_IOOL_FIR_MASK_REG_FIR_LINK0_NO_SPARE_MASK = 42;
constexpr uint32_t SET_LENGTH_8 = 8;

/**
*        @brief This function will do getScoms on the firmask regs that are OBUS related and
*               will save off the values read into attributes for later use.
*
*        @param[in] i_target_chip   Processor target we want to save/restore OBUS firmasks for
*        @param[in] i_obus_targets  vector the Processor's functional child OBUS targets
*
*        @retval    ReturnCode
*/
fapi2::ReturnCode p9_io_obus_firmask_save(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>> i_obus_targets);

/**
*        @brief This function will look up attributes that contain firmask values that we have saved off earlier
*               and write the values to the appropriate firmask registers. If one or both of the attributes
*               then we will not restore either of the masks
*
*        @param[in] i_target_chip   Processor target we want to save/restore OBUS firmasks for
*        @param[in] i_obus_targets  vector the Processor's functional child OBUS targets
*
*        @retval    ReturnCode
*/
fapi2::ReturnCode p9_io_obus_firmask_restore(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>> i_obus_targets);


fapi2::ReturnCode p9_io_obus_firmask_save_restore(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        const p9iofirmasksaverestore::OP_TYPE i_op)
{
    FAPI_DBG("p9_io_obus_firmask_save_restore: Entering...");

    const auto l_obus_func_vector =
        i_target_chip.getChildren<fapi2::TARGET_TYPE_OBUS>(fapi2::TARGET_STATE_FUNCTIONAL);

    if(i_op == p9iofirmasksaverestore::SAVE)
    {
        // run save method
        FAPI_TRY(p9_io_obus_firmask_save(i_target_chip, l_obus_func_vector));
    }
    else
    {
        // run restore method
        FAPI_TRY(p9_io_obus_firmask_restore(i_target_chip, l_obus_func_vector));
    }

fapi_try_exit:
    FAPI_DBG("p9_io_obus_firmask_save_restore: Exiting...");
    return fapi2::current_err;
}

fapi2::ReturnCode p9_io_obus_firmask_save(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>> i_obus_targets)
{
    FAPI_IMP("p9_io_obus_firmask_save: Entering...");

    fapi2::buffer<uint64_t> l_scomBuffer = 0;
    fapi2::buffer<uint64_t> l_action0Buffer = 0;
    fapi2::buffer<uint64_t> l_action1Buffer = 0;

    // First read the PB IOO fir mask register
    FAPI_TRY(fapi2::getScom(i_target_chip,
                            PU_IOE_PB_IOO_FIR_MASK_REG,
                            l_scomBuffer),
             "getScom of PU_IOE_PB_IOO_FIR_MASK_REG failed");

    // Save off scom value we read into ATTR_IO_PB_IOOFIR_MASK
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_PB_IOOFIR_MASK,
                           i_target_chip,
                           l_scomBuffer),
             "failed to set attribute ATTR_IO_PB_IOOFIR_MASK");

    // Apply mask required for Hostboot IPL time
    // Set bits 28-35 (see above for more details)
    l_scomBuffer.insertFromRight<PU_IOE_PB_IOO_FIR_MASK_REG_PARSER00_ATTN,
                                 SET_LENGTH_8>(SET_BYTE);
    // Set bits 52-59 (see above for more details)
    l_scomBuffer.insertFromRight<PU_IOE_PB_IOO_FIR_MASK_REG_DOB01_ERR,
                                 SET_LENGTH_8>(SET_BYTE);

    // Write modified mask back to scom register
    FAPI_TRY(fapi2::putScom(i_target_chip,
                            PU_IOE_PB_IOO_FIR_MASK_REG,
                            l_scomBuffer),
             "putScom of PU_IOE_PB_IOO_FIR_MASK_REG failed");

    // Loop through obus targets and save off IOO LFIR
    for(const auto& l_obusTarget : i_obus_targets)
    {
        // For each obus target read the IOOL FIR mask and store it in
        // the ATTR_IO_OLLFIR_MASK attribute for later
        FAPI_TRY(fapi2::getScom(l_obusTarget,
                                OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG,
                                l_scomBuffer),
                 "getScom of OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG failed");

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_OLLFIR_MASK,
                               l_obusTarget,
                               l_scomBuffer),
                 "failed to set attribute ATTR_IO_OLLFIR_MASK");

        // For each obus target read the IOOL FIR action registers
        FAPI_TRY(fapi2::getScom(l_obusTarget,
                                OBUS_LL0_PB_IOOL_FIR_ACTION0_REG,
                                l_action0Buffer),
                 "getScom of OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG failed");

        FAPI_TRY(fapi2::getScom(l_obusTarget,
                                OBUS_LL0_PB_IOOL_FIR_ACTION1_REG,
                                l_action1Buffer),
                 "getScom of OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG failed");

        // Apply mask required for Hostboot IPL time, we must mask additional
        // bits during IPL time because Hostboot does not know about OBUS
        // peer targets yet. When PRD attempts to handle some of these FIRs
        // it will expect the PEER_TARGET information to be there.

        // Set bits 42-47 if the action register indicate the error as recoverable
        for(uint64_t i = PB_IOOL_FIR_MASK_REG_FIR_LINK0_NO_SPARE_MASK;
            i <= OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS;
            i++)
        {
            if(l_action0Buffer.getBit(i) == 0 &&
               l_action1Buffer.getBit(i) == 1 )
            {
                l_scomBuffer.setBit(i);
            }
        }

        // Set bits 52-59 if the action register indicate the error as recoverable
        for(uint64_t i = OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR;
            i <= OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS;
            i++)
        {
            if(l_action0Buffer.getBit(i) == 0 &&
               l_action1Buffer.getBit(i) == 1 )
            {
                l_scomBuffer.setBit(i);
            }
        }

        // Write modified mask back to scom register
        FAPI_TRY(fapi2::putScom(l_obusTarget,
                                OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG,
                                l_scomBuffer),
                 "putScom of OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG failed");
    }

fapi_try_exit:
    FAPI_IMP("p9_io_obus_firmask_restore: Exiting...");
    return fapi2::current_err;
}

fapi2::ReturnCode p9_io_obus_firmask_restore(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>> i_obus_targets)
{
    FAPI_IMP("p9_io_obus_firmask_restore: Entering...");
    uint64_t l_restoreValue;

    // Read the proc's obus firmask value we stored previously
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_PB_IOOFIR_MASK,
                           i_target_chip,
                           l_restoreValue),
             "failed to get attribute ATTR_IO_PB_IOOFIR_MASK");

    // If ATTR_IO_PB_IOOFIR_MASK is zero that indicates that firmask_save has not been
    // called yet so we will not restore this firmask
    // Note: it was decided to keep these attribute checks seperate to allow
    //       attribute overrides of these attributes to take effect on HBRT reset
    if(l_restoreValue)
    {
        // Write the stored value back to the scom register
        FAPI_TRY(fapi2::putScom(i_target_chip,
                                PU_IOE_PB_IOO_FIR_MASK_REG,
                                l_restoreValue),
                 "putScom of PU_IOE_PB_IOO_FIR_MASK_REG failed");

        // Need to write 0 to ATTR_IO_PB_IOOFIR_MASK to ensure
        // we do not re-write the obus firmask values on HBRT
        // reboots or MPIPLs
        l_restoreValue = 0;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_PB_IOOFIR_MASK,
                               i_target_chip,
                               l_restoreValue),
                 "failed to set attribute ATTR_IO_PB_IOOFIR_MASK");
    }
    else
    {
        FAPI_IMP("p9_io_obus_firmask_restore: Skipping restore of PU_IOE_PB_IOO_FIR_MASK_REG because ATTR_IO_PB_IOOFIR_MASK  is 0");
    }


    // Loop through obus targets and restore the IOO LFIR value if necessary
    for(const auto& l_obusTarget : i_obus_targets)
    {
        // Read the obus's obus firmask value we stored previously
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OLLFIR_MASK,
                               l_obusTarget,
                               l_restoreValue),
                 "failed to get attribute ATTR_IO_OLLFIR_MASK");

        // If ATTR_IO_OLLFIR_MASK is zero that indicates that firmask_save has not been
        // called yet so we will not restore this firmask
        // Note: it was decided to keep these attribute checks seperate to allow
        //       attribute overrides of these attributes to take effect on HBRT reset
        if(l_restoreValue)
        {

            // Write the stored value back to the scom register
            FAPI_TRY(fapi2::putScom(l_obusTarget,
                                    OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG,
                                    l_restoreValue),
                     "putScom of OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG failed");

            // Need to write 0 to ATTR_IO_OLLFIR_MASK to ensure
            // we do not re-write the obus firmask values on HBRT
            // reboots or MPIPLs
            l_restoreValue = 0;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_OLLFIR_MASK,
                                   l_obusTarget,
                                   l_restoreValue),
                     "failed to set attribute ATTR_IO_OLLFIR_MASK");
        }
        else
        {
            FAPI_IMP("p9_io_obus_firmask_restore: Skipping restore of OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG because ATTR_IO_OLLFIR_MASK is 0");
        }
    }

fapi_try_exit:
    FAPI_IMP("p9_io_obus_firmask_restore: Exiting...");
    return fapi2::current_err;
}
