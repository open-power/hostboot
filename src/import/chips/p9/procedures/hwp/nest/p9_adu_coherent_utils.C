/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_adu_coherent_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
//
/// @file p9_adu_coherent_utils.C
/// @brief ADU alter/display library functions (FAPI)
///
// *HWP HWP Owner: Joe McGill jmcgill@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: SBE
//
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_adu_coherent_utils.H>
#include <p9_misc_scom_addresses.H>
#include <p9_fbc_utils.H>
#include <p9_misc_scom_addresses_fld.H>

extern "C"
{
    //---------------------------------------------------------------------------------
    // Constant definitions
    //---------------------------------------------------------------------------------

    //ADU register field/bit definitions

    // ADU Option Register field/bit definitions
    const uint32_t FBC_ALTD_HW397129 = 52;

    //TType Constant variables
    const uint32_t ALTD_CMD_TTYPE_CL_DMA_RD   = 6;  //0b0000110
    const uint32_t ALTD_CMD_TTYPE_DMA_PR_WR   = 38; //0b0100110
    const uint32_t ALTD_CMD_TTYPE_CI_PR_RD    = 52; //0b0110100
    const uint32_t ALTD_CMD_TTYPE_CI_PR_WR    = 55; //0b0110111
    const uint32_t ALTD_CMD_TTYPE_PB_OPER     = 0b0111111;
    const uint32_t ALTD_CMD_TTYPE_PMISC_OPER  = 0b0110001;

    //these should be 1, 2, 3, 4 but they are shifted over one to the left because for
    //ci_pr_rd and ci_pr_w the secondary encode is 0ttt ssss0
    const uint32_t ALTD_CMD_CI_TSIZE_1 = 2;
    const uint32_t ALTD_CMD_CI_TSIZE_2 = 4;
    const uint32_t ALTD_CMD_CI_TSIZE_4 = 6;
    const uint32_t ALTD_CMD_CI_TSIZE_8 = 8;
    //these should be 1, 2, 4, 8 but they are shifted over one to the left because for
    //dma_pr_w the secondary encode is tSize & '0'
    const uint32_t ALTD_CMD_DMAW_TSIZE_1 = 2;
    const uint32_t ALTD_CMD_DMAW_TSIZE_2 = 4;
    const uint32_t ALTD_CMD_DMAW_TSIZE_4 = 8;
    const uint32_t ALTD_CMD_DMAW_TSIZE_8 = 16;
    //I think that the secondary encoding should always be 0 for cl_dma_rd
    const uint32_t ALTD_CMD_DMAR_TSIZE = 0;

    //Value for scope for any DMA write operations
    const uint32_t ALTD_CMD_SCOPE_GROUP         = 0b00000011;

    // Values for PB operations
    const uint32_t ALTD_CMD_PB_DIS_OPERATION_TSIZE  = 0b00001000;
    const uint32_t ALTD_CMD_PB_INIT_OPERATION_TSIZE  = 0b00001011;
    const uint32_t ALTD_CMD_SCOPE_SYSTEM        = 0b00000101;

    // Values for PMISC operations
    const uint32_t ALTD_CMD_PMISC_TSIZE_1  = 0b00000010;    // PMISC SWITCH
    const uint32_t ALTD_CMD_PMISC_TSIZE_2  = 0b01000000;    // PMISC HTM

    // OPTION reg values for SWITCH operation
    const uint32_t QUIESCE_SWITCH_WAIT_COUNT = 128;
    const uint32_t INIT_SWITCH_WAIT_COUNT = 128;

    //FORCE ECC Register field/bit definitions
    const uint32_t ALTD_DATA_TX_ECC_END_BIT = 16;

    const uint32_t ALTD_DATA_ECC_MASK = 0xFFFFull;

    // ADU operation delay times for HW/sim
    const uint32_t PROC_ADU_UTILS_ADU_OPER_HW_NS_DELAY = 10000;
    const uint32_t PROC_ADU_UTILS_ADU_OPER_SIM_CYCLE_DELAY = 50000;
    const uint32_t PROC_ADU_UTILS_ADU_STATUS_HW_NS_DELAY = 100;
    const uint32_t PROC_ADU_UTILS_ADU_STATUS_SIM_CYCLE_DELAY = 20000;

    //---------------------------------------------------------------------------------
    // Function definitions
    //---------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode p9_adu_coherent_utils_check_args(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const uint32_t i_flags)
    {
        FAPI_DBG("Start");

        p9_ADU_oper_flag l_myAduFlag;
        p9_ADU_oper_flag::Transaction_size_t l_transSize;
        uint32_t l_actualTransSize;

        //Get the transaction size
        l_transSize = l_myAduFlag.getTransactionSize();

        //Translate the transaction size to the actual size (1, 2, 4, or 8 bytes)
        if ( l_transSize == p9_ADU_oper_flag::TSIZE_1 )
        {
            l_actualTransSize = 1;
        }
        else if ( l_transSize == p9_ADU_oper_flag::TSIZE_2 )
        {
            l_actualTransSize = 2;
        }
        else if ( l_transSize == p9_ADU_oper_flag::TSIZE_4 )
        {
            l_actualTransSize = 4;
        }
        else
        {
            l_actualTransSize = 8;
        }

        //Check the address alignment
        FAPI_ASSERT(!(i_address & (l_actualTransSize - 1)),
                    fapi2::P9_ADU_COHERENT_UTILS_INVALID_ARGS().set_TARGET(i_target).set_ADDRESS(
                        i_address).set_FLAGS(i_flags),
                    "Address is not cacheline aligned");

        //Make sure the address is within the ADU bounds
        FAPI_ASSERT(i_address <= P9_FBC_UTILS_FBC_MAX_ADDRESS,
                    fapi2::P9_ADU_COHERENT_UTILS_INVALID_ARGS().set_TARGET(i_target).set_ADDRESS(
                        i_address).set_FLAGS(i_flags),
                    "Address exceeds supported fabric real address range");


    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode p9_adu_coherent_utils_check_fbc_state(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        bool fbc_initialized = false;
        bool fbc_running = false;
        FAPI_DBG("Start");

        //Get the state of the fabric
        FAPI_TRY(p9_fbc_utils_get_fbc_state(i_target, fbc_initialized, fbc_running),
                 "Error from p9_fbc_utils_get_fbc_state");

        //Make sure the fabric is initialized and running othewise set an error
        FAPI_ASSERT(fbc_initialized
                    && fbc_running, fapi2::P9_ADU_FBC_NOT_INITIALIZED_ERR().set_TARGET(i_target).set_INITIALIZED(
                        fbc_initialized).set_RUNNING(
                        fbc_running), "Fabric is not initialized or running");

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;

    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode p9_adu_coherent_utils_get_num_granules(
        const uint64_t i_address,
        uint32_t& o_numGranules)
    {
        fapi2::ReturnCode rc;
        FAPI_DBG("Start");

        //From the address figure out when it is going to no longer be within the ADU bound by
        //doing the max fbc address minus the address and then divide by 8 to get number of bytes
        //and by 8 to get number of 8 byte granules that can be sent
        o_numGranules = ((P9_FBC_UTILS_FBC_MAX_ADDRESS - i_address) / 8) / 8;

        FAPI_DBG("Exiting");
        return rc;
    }



    ///
    /// @brief Setup the value for ADU option register to enable
    ///        quiesce & init around a switch operation.
    ///
    /// @param [in] i_target   Proc target
    ///
    /// @return FAPI2_RC_SUCCESS if OK
    ///
    fapi2::ReturnCode setQuiesceInit(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> altd_option_reg_data(0);

        // Set up quiesce
        altd_option_reg_data.setBit<PU_ALTD_OPTION_REG_FBC_WITH_PRE_QUIESCE>();
        altd_option_reg_data.insertFromRight<PU_ALTD_OPTION_REG_FBC_AFTER_QUIESCE_WAIT_COUNT,
                                             PU_ALTD_OPTION_REG_FBC_AFTER_QUIESCE_WAIT_COUNT_LEN>
                                             (QUIESCE_SWITCH_WAIT_COUNT);

        // Setup Post-command init
        altd_option_reg_data.setBit<PU_ALTD_OPTION_REG_FBC_WITH_POST_INIT>();
        altd_option_reg_data.insertFromRight<PU_ALTD_OPTION_REG_FBC_BEFORE_INIT_WAIT_COUNT,
                                             PU_ALTD_OPTION_REG_FBC_BEFORE_INIT_WAIT_COUNT_LEN>
                                             (INIT_SWITCH_WAIT_COUNT);

        //If DD2 setup workaround for HW397129 to re-enable fastpath for DD2
        altd_option_reg_data.setBit<FBC_ALTD_HW397129>();

        // Write to ADU option reg
        FAPI_DBG("OPTION reg value 0x%016llX", altd_option_reg_data);
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_OPTION_REG, altd_option_reg_data),
                 "Error writing to PU_ALTD_OPTION_REG register");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode p9_adu_coherent_setup_adu(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const bool i_rnw,
        const uint32_t i_flags)
    {
        //Print the address and the flag along with start
        FAPI_DBG("Start Addr 0x%.16llX, Flag 0x%.8X", i_address, i_flags);

        fapi2::ReturnCode rc;
        fapi2::buffer<uint64_t> altd_cmd_reg_data(0x0);
        fapi2::buffer<uint64_t> altd_addr_reg_data(i_address);
        fapi2::buffer<uint64_t> altd_option_reg_data(0x0);
        p9_ADU_oper_flag l_myAduFlag;
        p9_ADU_oper_flag::OperationType_t l_operType;
        p9_ADU_oper_flag::Transaction_size_t l_transSize;
        uint32_t var_PU_ALTD_CMD_REG_FBC_TTYPE = 0;
        uint32_t var_PU_ALTD_CMD_REG_FBC_TSIZE = 0;

        //Write the address into altd_addr_reg
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_ADDR_REG, altd_addr_reg_data),
                 "Error writing to ALTD_ADDR Register");

        // Process input flag
        l_myAduFlag.getFlag(i_flags);
        l_operType = l_myAduFlag.getOperationType();
        l_transSize = l_myAduFlag.getTransactionSize();

        //Now work on getting the altd cmd register set up - go through all the bits and set/clear as needed
        //this routine assumes the lock is held by the caller, preserve this locked state
        altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_LOCKED>();

        // ---------------------------------------------
        // Setting for DMA and CI operations
        // ---------------------------------------------
        if ( (l_operType == p9_ADU_oper_flag::CACHE_INHIBIT) ||
             (l_operType == p9_ADU_oper_flag::DMA_PARTIAL) )
        {

            // ---------------------------------------------
            // DMA & CI common settings
            // ---------------------------------------------
            // Set fbc_altd_rnw if it's a read
            if (i_rnw)
            {
                altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_RNW>();
            }
            // Clear fbc_altd_rnw if it's a write
            else
            {
                altd_cmd_reg_data.clearBit<PU_ALTD_CMD_REG_FBC_RNW>();
            }

            // If auto-inc set the auto-inc bit
            if (l_myAduFlag.getAutoIncrement() == true)
            {
                altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_AUTO_INC>();
            }

            // ---------------------------------------------------
            // Cache Inhibit specific: TTYPE & TSIZE
            // ---------------------------------------------------
            if (l_operType == p9_ADU_oper_flag::CACHE_INHIBIT)
            {
                FAPI_DBG("ADU operation type: Cache Inhibited");

                // Set TTYPE
                if (i_rnw)
                {
                    var_PU_ALTD_CMD_REG_FBC_TTYPE = ALTD_CMD_TTYPE_CI_PR_RD;
                }
                else
                {
                    var_PU_ALTD_CMD_REG_FBC_TTYPE = ALTD_CMD_TTYPE_CI_PR_WR;
                }

                // Set TSIZE
                if ( l_transSize == p9_ADU_oper_flag::TSIZE_1 )
                {
                    var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_CI_TSIZE_1;
                }
                else if ( l_transSize == p9_ADU_oper_flag::TSIZE_2 )
                {
                    var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_CI_TSIZE_2;
                }
                else if ( l_transSize == p9_ADU_oper_flag::TSIZE_4 )
                {
                    var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_CI_TSIZE_4;
                }
                else
                {
                    var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_CI_TSIZE_8;
                }
            }

            // ---------------------------------------------------
            // DMA specific: TTYPE & TSIZE
            // ---------------------------------------------------
            else
            {
                FAPI_DBG("ADU operation type: DMA");

                // If a read, set ALTD_CMD_TTYPE_CL_DMA_RD
                // Set the tsize to ALTD_CMD_DMAR_TSIZE
                if (i_rnw)
                {
                    var_PU_ALTD_CMD_REG_FBC_TTYPE = ALTD_CMD_TTYPE_CL_DMA_RD;
                    var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_DMAR_TSIZE;
                }
                // If a write set ALTD_CMD_TTYPE_DMA_PR_WR
                // Set the tsize according to flag setting
                else
                {
                    var_PU_ALTD_CMD_REG_FBC_TTYPE = ALTD_CMD_TTYPE_DMA_PR_WR;

                    //Set scope to group scope
                    altd_cmd_reg_data.insertFromRight<PU_ALTD_CMD_REG_FBC_SCOPE, PU_ALTD_CMD_REG_FBC_SCOPE_LEN>(ALTD_CMD_SCOPE_GROUP);

                    // Set TSIZE
                    if ( l_transSize == p9_ADU_oper_flag::TSIZE_1 )
                    {
                        var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_DMAW_TSIZE_1;
                    }
                    else if ( l_transSize == p9_ADU_oper_flag::TSIZE_2 )
                    {
                        var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_DMAW_TSIZE_2;
                    }
                    else if ( l_transSize == p9_ADU_oper_flag::TSIZE_4 )
                    {
                        var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_DMAW_TSIZE_4;
                    }
                    else
                    {
                        var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_DMAW_TSIZE_8;
                    }
                }
            }
        }

        // ---------------------------------------------
        // Setting for PB and PMISC operations
        // ---------------------------------------------
        if ( (l_operType == p9_ADU_oper_flag::PB_DIS_OPER) ||
             (l_operType == p9_ADU_oper_flag::PB_INIT_OPER) ||
             (l_operType == p9_ADU_oper_flag::PMISC_OPER) )
        {

            // ---------------------------------------------
            // PB & PMISC common settings
            // ---------------------------------------------

            // Set the start op bit
            altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_START_OP>();

            // Set operation scope
            altd_cmd_reg_data.insertFromRight<PU_ALTD_CMD_REG_FBC_SCOPE,
                                              PU_ALTD_CMD_REG_FBC_SCOPE_LEN>(ALTD_CMD_SCOPE_SYSTEM);

            // Set DROP_PRIORITY = HIGH
            altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_DROP_PRIORITY>();

            // Set AXTYPE = Address only
            altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_AXTYPE>();

            // ---------------------------------------------------
            // PB specific: TTYPE & TSIZE
            // ---------------------------------------------------
            if ((l_operType == p9_ADU_oper_flag::PB_DIS_OPER) ||
                (l_operType == p9_ADU_oper_flag::PB_INIT_OPER))
            {
                FAPI_DBG("ADU operation type: PB OPERATION");

                // Set TTYPE
                var_PU_ALTD_CMD_REG_FBC_TTYPE = ALTD_CMD_TTYPE_PB_OPER;
                // Set TM_QUIESCE
                altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_WITH_TM_QUIESCE>();

                if (l_operType == p9_ADU_oper_flag::PB_DIS_OPER)
                {
                    // TSIZE for PB operation is fixed value: 0b00001000
                    var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_PB_DIS_OPERATION_TSIZE;
                }
                else
                {
                    // Set OVERWRITE_PBINIT
                    altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_OVERWRITE_PBINIT>();

                    // Set up quiesce
                    altd_option_reg_data.setBit<PU_ALTD_OPTION_REG_FBC_WITH_PRE_QUIESCE>();
                    altd_option_reg_data.insertFromRight<PU_ALTD_OPTION_REG_FBC_AFTER_QUIESCE_WAIT_COUNT,
                                                         PU_ALTD_OPTION_REG_FBC_AFTER_QUIESCE_WAIT_COUNT_LEN>
                                                         (QUIESCE_SWITCH_WAIT_COUNT);
                    FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_OPTION_REG, altd_option_reg_data),
                             "Error writing to ALTD_OPTION Register");

                    // TSIZE for PB operation is fixed value: 0b00001011
                    var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_PB_INIT_OPERATION_TSIZE;
                }
            }

            // ---------------------------------------------------
            // PMISC specific: TTYPE & TSIZE
            // ---------------------------------------------------
            else
            {
                FAPI_DBG("ADU operation type: PMISC");

                // Set TTYPE
                var_PU_ALTD_CMD_REG_FBC_TTYPE = ALTD_CMD_TTYPE_PMISC_OPER;

                // Set TSIZE
                if ( l_transSize == p9_ADU_oper_flag::TSIZE_1 )
                {
                    // Set TM_QUIESCE
                    altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_WITH_TM_QUIESCE>();

                    var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_PMISC_TSIZE_1;
                    // Set quiesce and init around a switch operation in option reg
                    FAPI_TRY(setQuiesceInit(i_target), "setQuiesceInit() returns error");
                }
                else if ( l_transSize == p9_ADU_oper_flag::TSIZE_2 )
                {
                    var_PU_ALTD_CMD_REG_FBC_TSIZE = ALTD_CMD_PMISC_TSIZE_2;
                }

            }
        }

        altd_cmd_reg_data.insertFromRight<PU_ALTD_CMD_REG_FBC_TTYPE, PU_ALTD_CMD_REG_FBC_TTYPE_LEN>
        (var_PU_ALTD_CMD_REG_FBC_TTYPE);
        altd_cmd_reg_data.insertFromRight<PU_ALTD_CMD_REG_FBC_TSIZE,
                                          PU_ALTD_CMD_REG_FBC_TSIZE_LEN>(var_PU_ALTD_CMD_REG_FBC_TSIZE);

        //Print out what we are setting for altd cmd register data
        FAPI_DBG("CMD reg value 0x%016llX", altd_cmd_reg_data);

        //Write altd cmd register with the settings that were set above
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data),
                 "Error writing to ALTD_CMD Register");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode p9_adu_coherent_adu_write(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_firstGranule,
        const uint64_t i_address,
        p9_ADU_oper_flag& i_aduOper,
        const uint8_t i_write_data[])
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> altd_cmd_reg_data;
        fapi2::buffer<uint64_t> altd_status_reg_data;
        fapi2::buffer<uint64_t> force_ecc_reg_data;
        uint64_t write_data = 0x0ull;
        int eccIndex = 8;

        // Get ADU operation info from flag
        bool l_itagMode          = i_aduOper.getItagMode();
        bool l_eccMode           = i_aduOper.getEccMode();
        bool l_overrideEccMode   = i_aduOper.getEccItagOverrideMode();
        bool l_autoIncMode       = i_aduOper.getAutoIncrement();
        bool l_accessForceEccReg = (l_itagMode | l_eccMode | l_overrideEccMode);

        // Dump ADU write settings
        FAPI_DBG("Modes: ITAG 0x%.8X, ECC 0x%.8X, OVERRIDE_ECC 0x%.8X",
                 l_itagMode, l_eccMode, l_overrideEccMode);
        FAPI_DBG("       AUTOINC 0x%.8X", l_autoIncMode);

        //Get the write data that was passed in as a uint8 into a uint64
        for (int i = 0; i < 8; i++)
        {
            write_data |= ( static_cast<uint64_t>(i_write_data[i]) << (56 - (8 * i)) );
        }

        //Put the uint64 write data into the buffer
        fapi2::buffer<uint64_t> altd_data_reg_data(write_data);

        //If we are doing something with ecc/itag data
        if (l_accessForceEccReg == true)
        {
            //Read the FORCE_ECC register
            FAPI_TRY(fapi2::getScom(i_target, PU_FORCE_ECC_REG, force_ecc_reg_data), "Error reading the FORCE_ECC Register");

            //if we want to write the itag bit set that bit
            if (l_itagMode == true)
            {
                eccIndex++;
                force_ecc_reg_data.setBit<PU_FORCE_ECC_REG_ALTD_DATA_ITAG>();
            }

            //if we want to write the ecc data get the data
            if (l_eccMode == true)
            {
                force_ecc_reg_data.insertFromRight < PU_FORCE_ECC_REG_ALTD_DATA_TX,
                                                   PU_FORCE_ECC_REG_ALTD_DATA_TX_LEN >
                                                   ((uint64_t)i_write_data[eccIndex]);
            }

            //if we want to overwrite the ecc data set that bit
            if (l_overrideEccMode == true)
            {
                force_ecc_reg_data.setBit<PU_FORCE_ECC_REG_ALTD_DATA_TX_OVERWRITE>();
            }

            //Write to the FORCE_ECC register
            FAPI_TRY(fapi2::putScom(i_target, PU_FORCE_ECC_REG, force_ecc_reg_data), "Error writing to the FORCE_ECC Register");
        }

        //write the data into the altd_data_reg
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_DATA_REG, altd_data_reg_data),
                 "Error writing to ALTD_DATA Register");

        //Set the ALTD_CMD_START_OP bit to start the write(first granule for autoinc case or not autoinc)
        if ( i_firstGranule || (l_autoIncMode == false) )
        {
            //read the altd_cmd_register
            FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error reading from the ALTD_CMD_REG");
            //set the start op bit
            altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_START_OP>();
            //write the altd_cmd_register
            FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error writing to the ALTD_CMD_REG");
        }

        //If this is a ci operation we want to poll the status register for completion
        if (i_aduOper.getOperationType() == p9_ADU_oper_flag::CACHE_INHIBIT)
        {
            bool l_busyBitStatus = true;

            for (uint32_t i = 0; i < 100000; i++)
            {
                //Check the busy bit if it's busy exit otherwise check the status
                FAPI_TRY(p9_adu_coherent_status_check(i_target, EXIT_ON_BUSY, false,
                                                      l_busyBitStatus),
                         "Error from p9_adu_coherent_status_check");

                //If the data done bit is set (the data transfer is done we are done
                if (!l_busyBitStatus)
                {
                    break;
                }
            }
        }
        //If it's not a ci operation we just want to delay for a while and then this write is done
        else
        {
            //delay to allow time for the write to progress
            FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_OPER_HW_NS_DELAY,
                                  PROC_ADU_UTILS_ADU_OPER_SIM_CYCLE_DELAY), "fapiDelay error");
        }

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode p9_adu_coherent_adu_read(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_firstGranule,
        const uint64_t i_address,
        p9_ADU_oper_flag& i_aduOper,
        uint8_t o_read_data[])
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> altd_cmd_reg_data;
        fapi2::buffer<uint64_t> altd_status_reg_data;
        fapi2::buffer<uint64_t> altd_data_reg_data;
        fapi2::buffer<uint64_t> force_ecc_reg_data;
        int eccIndex = 8;

        // Get ADU operation info from flag
        bool l_itagMode          = i_aduOper.getItagMode();
        bool l_eccMode           = i_aduOper.getEccMode();
        bool l_autoIncMode       = i_aduOper.getAutoIncrement();

        // Dump ADU read settings
        FAPI_DBG("Modes: ITAG 0x%.8X, ECC 0x%.8X, AUTOINC 0x%.8X",
                 l_itagMode, l_eccMode, l_autoIncMode);

        //Set the ALTD_CMD_START_OP bit to start the read(first granule for autoinc case or not autoinc)
        if ( i_firstGranule || (l_autoIncMode == false) )
        {
            //read the altd_cmd_register
            FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error reading from the ALTD_CMD_REG");
            //set the start op bit
            altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_START_OP>();
            //write the altd_cmd_register
            FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error writing to the ALTD_CMD_REG");
        }

        //If this is a ci operation we want to poll the status register for completion
        if (i_aduOper.getOperationType() == p9_ADU_oper_flag::CACHE_INHIBIT)
        {
            bool l_busyBitStatus = true;

            for (uint32_t i = 0; i < 100000; i++)
            {
                //We want to exit if it's still busy and keep polling on that bit - otherwise actually check the status
                FAPI_TRY(p9_adu_coherent_status_check(i_target, EXIT_ON_BUSY, false,
                                                      l_busyBitStatus),
                         "Error from p9_adu_coherent_status_check");

                //If the data done bit is set (the data transfer is done we can go read the data
                if (!l_busyBitStatus)
                {
                    break;
                }
            }
        }
        else
        {
            //delay to allow time for the read to progress
            FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_OPER_HW_NS_DELAY,
                                  PROC_ADU_UTILS_ADU_OPER_SIM_CYCLE_DELAY), "fapiDelay error");
        }

        //if we want to include the itag and ecc data collect them before the read
        if ( l_itagMode || l_eccMode )
        {
            //Read the FORCE_ECC register
            FAPI_TRY(fapi2::getScom(i_target, PU_FORCE_ECC_REG, force_ecc_reg_data),
                     "Error reading from the FORCE_ECC Register");

            //If we are reading the itag get that data and put it in the read_data array
            if (l_itagMode)
            {
                eccIndex = 9;
                o_read_data[8] = force_ecc_reg_data.getBit<PU_FORCE_ECC_REG_ALTD_DATA_ITAG>();
            }

            //If we are reading the ecc get that data and put it in the read_data array
            if (l_eccMode)
            {
                o_read_data[eccIndex] = (force_ecc_reg_data >> (63 - ALTD_DATA_TX_ECC_END_BIT)) & ALTD_DATA_ECC_MASK;
            }
        }

        //read data from altd_data_reg
        FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_DATA_REG, altd_data_reg_data),
                 "Error reading from the ALTD_DATA Register");

        //Format the uint64 read data into an uint8 array
        for (int i = 0; i < 8; i++)
        {
            o_read_data[i] = (altd_data_reg_data >> (56 - (i * 8))) & 0xFFull;
        }

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode p9_adu_coherent_utils_reset_adu(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> altd_cmd_reg_data(0x0);

        //Get the current value from altd_cmd register so we don't write over anything
        FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error reading from ALTD_CMD Register");

        //set the reset_fsm, clear_status, and locked bits to do an ADU reset
        altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_RESET_FSM>();
        altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_CLEAR_STATUS>();
        altd_cmd_reg_data.setBit<PU_ALTD_CMD_REG_FBC_LOCKED>();
        //Write the altd_cmd register
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data),
                 "Error setting the reset_fsm bit from the ALTD_CMD Register");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode p9_adu_coherent_cleanup_adu(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> altd_cmd_reg_data(0x0);

        //write all 0s to altd_cmd_reg to cleanup everything
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data),
                 "Error clearing the ALTD_CMD Register");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode p9_adu_coherent_status_check(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const adu_status_busy_handler i_busyBitHandler,
        const bool i_addressOnlyOper,
        bool& o_busyBitStatus)
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> l_statusReg(0x0);
        bool l_statusError = false;

        //Check for a successful status 10 times
        for (int i = 0; i < 10; i++)
        {
            //Delay to allow the write/read/other command to finish
            FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_STATUS_HW_NS_DELAY,
                                  PROC_ADU_UTILS_ADU_STATUS_SIM_CYCLE_DELAY),
                     "fapiDelay error");

            l_statusError = false;

            // Read ALTD_STATUS_REG
            FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_STATUS_REG, l_statusReg),
                     "Error reading from ALTD_STATUS Register");
            //print out altd_status_reg
            FAPI_DBG("PU_ALTD_STATUS_REG reg value 0x%016llX", l_statusReg);

            // ---- Handle busy options ----

            // Get busy bit output
            o_busyBitStatus = l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_ALTD_BUSY>();

            // Handle busy bit according to specified input
            if (o_busyBitStatus == true)
            {
                // Exit if busy
                if (i_busyBitHandler == EXIT_ON_BUSY)
                {
                    goto fapi_try_exit;
                }
                // if the busy bit was set and it was expected to be clear there is a status error
                else if (i_busyBitHandler == EXPECTED_BUSY_BIT_CLEAR)
                {
                    l_statusError = true;
                }
            }
            //If the busy bit was not set and it was expected to be set there is a status error
            else if (i_busyBitHandler == EXPECTED_BUSY_BIT_SET)
            {
                l_statusError = true;
            }

            // ---- Check for other errors ----
            // Check the WAIT_CMD_ARBIT bit and make sure it's 0
            // Check the ADDR_DONE bit and make sure it's set
            // Check the WAIT_RESP bit to make sure it's clear
            // Check the OVERRUN_ERR to make sure it's clear
            // Check the AUTOINC_ERR to make sure it's clear
            // Check the COMMAND_ERR to make sure it's clear
            // Check the ADDRESS_ERR to make sure it's clear
            // Check the COMMAND_HANG_ERR to make sure it's clear
            // Check the DATA_HANG_ERR to make sure it's clear
            // Check the PBINIT_MISSING to make sure it's clear
            // Check the ECC_CE to make sure it's clear
            // Check the ECC_UE to make sure it's clear
            // Check the ECC_SUE to make sure it's clear
            l_statusError =
                ( l_statusError ||
                  l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_WAIT_CMD_ARBIT>()        ||
                  !l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_ADDR_DONE>()        ||   //The address potion of the operation is complete
                  l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_WAIT_RESP>()         ||   //Waiting for a clean combined response (CResp)
                  l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_OVERRUN_ERROR>()
                  ||   //New data was written before the previous data was used/read or a read was performed without new data arriving
                  l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_AUTOINC_ERROR>()
                  || //AutoInc Error indicates internal address counter rolled over the 0.5M boundary
                  l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_COMMAND_ERROR>()
                  || //New command was issued before previous one finished
                  l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_ADDRESS_ERROR>()
                  || //Invalid Address error : PB responded with Address Error CResp
                  l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_PBINIT_MISSING>()    ||   //attempt to start a command without pb_init active
                  l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_ECC_CE>()            ||   //ECC Correctable error
                  l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_ECC_UE>()            ||   //ECC Uncorrectable error
                  l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_ECC_SUE>()                //ECC Special Uncorrectable error
                );

            // If Address only operation, do not check for PU_ALTD_STATUS_REG_FBC_DATA_DONE otherwise it should be set
            if ( i_addressOnlyOper == false )
            {
                l_statusError |= !l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_DATA_DONE>();
            }

            //If there is not a status error, we can break out of checking status 10 times
            if (!l_statusError)
            {
                break;
            }
        }

        // If error, display trace
        if (l_statusError)
        {
            FAPI_ERR("Status mismatch detected");

            FAPI_ERR("FBC_ALTD_BUSY = %d", (o_busyBitStatus ? 1 : 0));
            FAPI_ERR("ALTD_STATUS_REG = %016llX", l_statusReg);
        }

        if (l_statusReg.getBit<PU_ALTD_STATUS_REG_FBC_ADDRESS_ERROR>())
        {
            //If there's an error, raise an error
            FAPI_ASSERT( (l_statusError == false), fapi2::P9_ADU_STATUS_REG_ERR_ADDR_ERR()
                         .set_TARGET(i_target)
                         .set_STATUSREG(l_statusReg),
                         "Status Register check error");
        }
        else
        {
            //If there's an error, raise an error
            FAPI_ASSERT( (l_statusError == false), fapi2::P9_ADU_STATUS_REG_ERR_NO_ADDR_ERR()
                         .set_TARGET(i_target)
                         .set_STATUSREG(l_statusReg),
                         "Status Register check error");
        }

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode p9_adu_coherent_clear_autoinc(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> altd_cmd_reg_data;

        //Get the value of altd_cmd register so we don't write over it
        FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data),
                 "Error reading from ALTD_CMD Register");

        //clear the autoinc bit
        altd_cmd_reg_data.clearBit<PU_ALTD_CMD_REG_FBC_AUTO_INC>();

        //Write to the altd_cmd register with the autoinc bit cleared
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data),
                 "Error clearing the auto_inc bit from the ALTD_CMD Register");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode p9_adu_coherent_manage_lock(const
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
            const bool i_lock_pick,
            const bool i_lock,
            const uint32_t i_num_attempts)
    {
        FAPI_DBG("Start");

        fapi2::ReturnCode rc;
        fapi2::buffer<uint64_t> lock_control(0x0);
        uint32_t attempt_count = 1;
        bool lock_pick_first_time = true;

        // num_attempts cannot be 0, otherwise throw an error
        if (i_num_attempts == 0)
        {
            FAPI_ERR("Invalid value %d for number of lock manipulation attempts",
                     i_num_attempts);
        }

        // set up data buffer to perform desired lock manipulation operation
        // If we are locking set the locked bit, reset_fsm bit, and clear_status bit
        if (i_lock)
        {
            FAPI_DBG("Configuring lock manipulation control data buffer to perform lock acquisition");
            lock_control.setBit(PU_ALTD_CMD_REG_FBC_LOCKED);
            lock_control.setBit<PU_ALTD_CMD_REG_FBC_RESET_FSM>();
            lock_control.setBit<PU_ALTD_CMD_REG_FBC_CLEAR_STATUS>();
        }
        else
        {
            FAPI_DBG("Configuring lock manipulation control data buffer to perform lock release");
        }

        // try to lock/unlock the lock the number of times specified with i_num_attempts
        while (1)
        {
            // write ADU command register to attempt lock manipulation
            FAPI_DBG("Writing ADU Command register to attempt lock manipulation");
            rc = fapi2::putScom(i_target, PU_ALTD_CMD_REG, lock_control);

            // pass back return code to caller unless it specifically indicates
            // that the ADU lock manipulation was unsuccessful and we're going
            // to try again
            if ((rc != fapi2::FAPI2_RC_PLAT_ERR_ADU_LOCKED)
                || (attempt_count == i_num_attempts))
            {
                // rc does not indicate success
                if (rc)
                {
                    // rc does not indicate lock held, exit
                    if (rc != fapi2::FAPI2_RC_PLAT_ERR_ADU_LOCKED)
                    {
                        FAPI_ERR("fapiPutScom error (PU_ALTD_CMD_REG)");
                        break;
                    }

                    // rc indicates lock held, out of attempts
                    if (attempt_count == i_num_attempts)
                    {
                        //if out of attempts but lock pick is desired try to pick the lock once and see if it works
                        if (i_lock_pick && i_lock && lock_pick_first_time)
                        {
                            lock_control.setBit(PU_ALTD_CMD_REG_FBC_LOCK_PICK);
                            attempt_count--;
                            lock_pick_first_time = false;
                            FAPI_DBG("Trying to do a lock pick as desired");
                        }
                        //If we are out of attempts and are not trying to pick the lock or if we already picked the lock, error out
                        else
                        {
                            FAPI_ASSERT(false, fapi2::P9_ADU_COHERENT_UTILS_LOCK_ERR().set_TARGET(i_target).set_LOCK_PICK(i_lock_pick).set_LOCK(
                                            i_lock).set_NUM_ATTEMPTS(i_num_attempts),
                                        "Ran out of lock attempts or were unable to pick lock");
                            break;
                        }
                    }
                }

                // rc clean, lock management operation successful
                FAPI_DBG("Lock manipulation successful or going to try a lock pick");
                break;
            }

            // delay to provide time for ADU lock to be released
            FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_STATUS_HW_NS_DELAY,
                                  PROC_ADU_UTILS_ADU_STATUS_SIM_CYCLE_DELAY),
                     "fapiDelay error");

            // increment attempt count, loop again
            attempt_count++;
            FAPI_DBG("Attempt %d of %d", attempt_count,
                     i_num_attempts);
        }

    fapi_try_exit:

        //if there is an error from trying to lock/unlock
        if(rc)
        {
            fapi2::current_err = rc;
        }

        FAPI_DBG("End");
        return fapi2::current_err;

    }

    void p9_adu_coherent_append_input_data(const uint64_t i_address, const bool i_rnw, const uint32_t i_flags,
                                           fapi2::ReturnCode& o_rc)
    {

#ifndef __PPE__
        uint64_t l_address = i_address;
        bool l_rnw = i_rnw;
        uint32_t l_flags = i_flags;
        fapi2::ffdc_t ADDRESS;
        fapi2::ffdc_t RNW;
        fapi2::ffdc_t FLAGS;
        ADDRESS.ptr() = static_cast<void*>(&l_address);
        ADDRESS.size() = sizeof(l_address);
        RNW.ptr() = static_cast<void*>(&l_rnw);
        RNW.size() = sizeof(l_rnw);
        FLAGS.ptr() = static_cast<void*>(&l_flags);
        FLAGS.size() = sizeof(l_flags);

        if ((o_rc == (fapi2::ReturnCode) fapi2::RC_P9_ADU_COHERENT_UTILS_INVALID_ARGS)
            || (o_rc == (fapi2::ReturnCode) fapi2::RC_P9_ADU_FBC_NOT_INITIALIZED_ERR)
            || (o_rc == (fapi2::ReturnCode) fapi2::RC_P9_ADU_STATUS_REG_ERR_ADDR_ERR)
            || (o_rc == (fapi2::ReturnCode) fapi2::RC_P9_ADU_STATUS_REG_ERR_NO_ADDR_ERR)
            || (o_rc == (fapi2::ReturnCode) fapi2::RC_P9_ADU_COHERENT_UTILS_LOCK_ERR))
        {
            FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_P9_ADU_COHERENT_UTILS_EXTRA_INPUT_DATA);
        }

#endif
    }

} // extern "C
