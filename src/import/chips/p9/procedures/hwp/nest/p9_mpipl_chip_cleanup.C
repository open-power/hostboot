/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_mpipl_chip_cleanup.C $ */
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
///
/// @file   p9_mpipl_chip_cleanup.C
/// @brief  To enable MCD recovery
///
// *HWP HWP OWNER: Joshua Hannan            Email: jlhannan@us.ibm.com
// *HWP FW  OWNER: Thi Tran                 Email: thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: FSP/HB
//
//  Additional Note(s):
//
//   Checks to see if MCD recovery is already enabled by checking bit 0 of the
//   even and odd MCD config registers, which is the recovery enable bit.
//   If the bits are 0, then the procedure enables them to start MCD recovery
//
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_mpipl_chip_cleanup.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>

extern "C"
{
    //------------------------------------------------------------------------------
    // Function definitions
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    // name: p9_mpipl_chip_cleanup
    //------------------------------------------------------------------------------
    // purpose:
    // To enable MCD recovery
    //
    // Note: PHBs are left in ETU reset state after executing proc_mpipl_nest_cleanup, which runs before this procedure.  PHYP releases PHBs from ETU reset post HostBoot IPL.
    //
    // SCOM regs
    //
    // 1) MCD even recovery control register
    // PU_BANK0_MCD_REC (SCOM)
    // bit 0 (PU_BANK0_MCD_REC_ENABLE): 0 to 1 transition needed to start, reset to 0 at end of request.
    //
    // 2) MCD odd recovery control register
    // PU_MCD1_BANK0_MCD_REC (SCOM)
    // bit 0 (PU_BANK0_MCD_REC_ENABLE): 0 to 1 transition needed to start, reset to 0 at end of request.
    //
    //------------------------------------------------------------------------------
    fapi2::ReturnCode p9_mpipl_chip_cleanup(fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        const uint8_t MAX_MCD_DIRS = 2; //Max of 2 MCD Directories (even and odd)
        fapi2::buffer<uint64_t> fsi_data[MAX_MCD_DIRS];
        const uint64_t ARY_MCD_RECOVERY_CTRL_REGS_ADDRS[MAX_MCD_DIRS] =
        {
            PU_BANK0_MCD_REC, //MCD even recovery control register address
            PU_MCD1_BANK0_MCD_REC  //MCD odd recovery control register address
        };
        const char* ARY_MCD_DIR_STRS[MAX_MCD_DIRS] =
        {
            "Even", //Ptr to char string "Even" for even MCD
            "Odd"   //Ptr to char string "Odd" for odd MCD
        };

        //Verify MCD recovery was previously disabled for even and odd slices
        //If not, this is an error condition
        for (uint8_t counter = 0; counter < MAX_MCD_DIRS; counter++)
        {
            FAPI_DBG("Verifying MCD %s Recovery is disabled", ARY_MCD_DIR_STRS[counter]);
            FAPI_TRY(fapi2::getScom(i_target, ARY_MCD_RECOVERY_CTRL_REGS_ADDRS[counter], fsi_data[counter]),
                     "getScom error veryfing that MCD recovery is disabled");


            FAPI_ASSERT(!fsi_data[counter].getBit<PU_BANK0_MCD_REC_ENABLE>(),
                        fapi2::P9_MPIPL_CHIP_CLEANUP_MCD_NOT_DISABLED().set_TARGET(i_target).set_ADDRESS(
                            ARY_MCD_RECOVERY_CTRL_REGS_ADDRS[counter]).set_DATA(fsi_data[counter]), "MCD recovery not disabled as expected");
        }

        //Assert bit 0 of MCD Recovery Ctrl regs to enable MCD recovery
        for (int counter = 0; counter < MAX_MCD_DIRS; counter++)
        {
            FAPI_DBG("Enabling MCD %s Recovery", ARY_MCD_DIR_STRS[counter]);

            //Assert bit 0 of MCD Even or Odd Recovery Control reg to enable recovery
            fsi_data[counter].setBit<PU_BANK0_MCD_REC_ENABLE>();

            //Write data to MCD Even or Odd Recovery Control reg
            FAPI_TRY(fapi2::putScom(i_target, ARY_MCD_RECOVERY_CTRL_REGS_ADDRS[counter], fsi_data[counter]),
                     "putScom error assert bit 0 of MCD recovery control register");
        }


    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }



} // extern "C"
