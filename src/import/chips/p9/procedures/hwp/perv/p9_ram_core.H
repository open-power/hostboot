/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_ram_core.H $       */
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
//-----------------------------------------------------------------------------------
///
/// @file p9_ram_core.H
/// @brief Class that implements the base ramming capability
///
//-----------------------------------------------------------------------------------
// *HWP HWP Owner        : Liu Yang Fan <shliuyf@cn.ibm.com>
// *HWP HWP Backup Owner : Gou Peng Fei <shgoupf@cn.ibm.com>
// *HWP FW Owner         : Thi Tran <thi@us.ibm.com>
// *HWP Team             : Perv
// *HWP Level            : 2
// *HWP Consumed by      : SBE
//-----------------------------------------------------------------------------------

#ifndef _P9_RAM_CORE_H_
#define _P9_RAM_CORE_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------
// register access type
enum Enum_RegType
{
    REG_GPR,
    REG_SPR,
    REG_FPR,
    REG_VSR
};


class RamCore
{
    public:
//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------
/// @brief Constructor of the class that implements the base ramming capability
/// @param[in] i_target => core target
/// @param[in] i_thread => thread number
//
        RamCore(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target, const uint8_t i_thread);

//-----------------------------------------------------------------------------------
/// @brief Destructor of the class that implements the base ramming capability
//
        ~RamCore();

//-----------------------------------------------------------------------------------
/// @brief Enable RAM mode and backup the registers(SCR0/GPR0/GPR1) that will be destroyed later during ramming
/// @return FAPI2_RC_SUCCESS if success, else error code.
//
        fapi2::ReturnCode ram_setup();

//-----------------------------------------------------------------------------------
/// @brief Perform the ram and check ram is done
/// @param[in] i_opcode     => opcode to ram
/// @param[in] i_allow_mult => indicate whether to setup and cleanup
///                            true: only perform ram, not to call ram_setup and ram_cleanup
///                            false: call ram_setup and ram_cleanup
/// @return FAPI2_RC_SUCCESS if success, else error code.
//
        fapi2::ReturnCode ram_opcode(const uint32_t i_opcode, const bool i_allow_mult = false);

//-----------------------------------------------------------------------------------
/// @brief Clear RAM mode and restore the backup registers
/// @return FAPI2_RC_SUCCESS if success, else error code.
//
        fapi2::ReturnCode ram_cleanup();

//-----------------------------------------------------------------------------------
/// @brief Get a register value by ramming
/// @param[in] i_type       => register type (REG_SPR/REG_GPR/REG_FPR/REG_VSR)
/// @param[in] i_reg_num    => register nubmer
/// @param[out] o_buffer    => register value
/// @param[in] i_allow_mult => indicate whether to setup and cleanup
///                            true: only perform ram, not to call ram_setup and ram_cleanup
///                            false: call ram_setup and ram_cleanup
/// @return FAPI2_RC_SUCCESS if success, else error code.
//
        fapi2::ReturnCode get_reg(const Enum_RegType i_type, const uint32_t i_reg_num, fapi2::buffer<uint64_t>* o_buffer,
                                  const bool i_allow_mult = false);

//-----------------------------------------------------------------------------------
/// @brief Put a register value by ramming
/// @param[in] i_type       => register type (REG_SPR/REG_GPR/REG_FPR/REG_VSR)
/// @param[in] i_reg_num    => register nubmer
/// @param[in] i_buffer     => register value
/// @param[in] i_allow_mult => indicate whether to setup and cleanup
///                            true: only perform ram, not to call ram_setup and ram_cleanup
///                            false: call ram_setup and ram_cleanup
/// @return FAPI2_RC_SUCCESS if success, else error code.
//
        fapi2::ReturnCode put_reg(const Enum_RegType i_type, const uint32_t i_reg_num, const fapi2::buffer<uint64_t>* i_buffer,
                                  const bool i_allow_mult = false);

//-----------------------------------------------------------------------------------
/// @brief Generate predecode for the opcode to ramming
/// @param[in] i_opcode => opcode to ram
/// @return the predecode
//
        uint8_t gen_predecode(const uint32_t i_opcode);

//-----------------------------------------------------------------------------------
/// @brief Check the opcode is load/store or not
/// @param[in] i_opcode => opcode to ram
/// @return TRUE if it is load/store
//
        bool is_load_store(const uint32_t i_opcode);

    private:
        fapi2::Target<fapi2::TARGET_TYPE_CORE> iv_target;  // core target
        uint8_t iv_thread;     // thread number
        bool iv_ram_enable;    // ram mode is enabled
        bool iv_ram_scr0_save; // SCR0 is saved when setup
        bool iv_ram_setup;     // ram mode is enabled and register backup is done
        bool iv_ram_err;       // error happened during ram
        bool iv_write_gpr0;    // putGPR0 operation is executed
        bool iv_write_gpr1;    // putGPR1 operatoin is executed
        fapi2::buffer<uint64_t> iv_backup_buf0;  // register backup data
        fapi2::buffer<uint64_t> iv_backup_buf1;  // register backup data
        fapi2::buffer<uint64_t> iv_backup_buf2;  // register backup data
};

#endif //_P9_RAM_CORE_H_
