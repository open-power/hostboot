/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_adu_coherent_utils.C $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//-----------------------------------------------------------------------------------
//
/// @file p9_adu_coherent_utils.C
/// @brief ADU alter/display library functions (FAPI)
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: SBE
//
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_adu_coherent_utils.H>
#include <p9_misc_scom_addresses.H>
#include <p9_fbc_utils.H>

extern "C"
{
    //---------------------------------------------------------------------------------
    // Constant definitions
    //---------------------------------------------------------------------------------

    //ADU Delay Constants

    //ADU register field/bit definitions

    // ADU Option Register field/bit definitions
    const uint32_t FBC_ALTD_WITH_PRE_QUIESCE = 23;
    const uint32_t FBC_ALTD_PRE_QUIESCE_COUNT_START_BIT = 28;  // Bits 28:47
    const uint32_t FBC_ALTD_PRE_QUIESCE_COUNT_NUM_OF_BITS = 20;

    const uint32_t FBC_ALTD_WITH_POST_INIT = 51;
    const uint32_t FBC_ALTD_POST_INIT_COUNT_START_BIT = 54;    // Bits 54:63
    const uint32_t FBC_ALTD_POST_INIT_COUNT_NUM_OF_BITS = 10;

    // ADU Command Register field/bit definitions
    const uint32_t ALTD_CMD_START_OP_BIT = 2;
    const uint32_t ALTD_CMD_CLEAR_STATUS_BIT = 3;
    const uint32_t ALTD_CMD_RESET_FSM_BIT = 4;
    const uint32_t ALTD_CMD_RNW_BIT = 5;
    const uint32_t ALTD_CMD_ADDRESS_ONLY_BIT = 6;
    const uint32_t ALTD_CMD_LOCK_PICK_BIT = 10;
    const uint32_t ALTD_CMD_LOCK_BIT = 11;
    const uint32_t ALTD_CMD_LOCK_ID_START_BIT = 12;
    const uint32_t ALTD_CMD_LOCK_ID_END_BIT = 15;
    const uint32_t ALTD_CMD_SCOPE_START_BIT = 16;
    const uint32_t ALTD_CMD_SCOPE_END_BIT = 18;
    const uint32_t ALTD_CMD_AUTO_INC_BIT = 19;
    const uint32_t ALTD_CMD_DROP_PRIORITY_BIT = 20;
    const uint32_t ALTD_CMD_DROP_PRIORITY_MAX_BIT = 21;
    const uint32_t ALTD_CMD_OVERWRITE_PBINIT_BIT = 22;
    const uint32_t ALTD_CMD_PIB_DIRECT_BIT = 23;
    const uint32_t ALTD_CMD_WITH_TM_QUIESCE_BIT = 24;
    const uint32_t ALTD_CMD_TTYPE_START_BIT = 25;
    const uint32_t ALTD_CMD_TTYPE_END_BIT = 31;
    const uint32_t ALTD_CMD_TSIZE_START_BIT = 32;
    const uint32_t ALTD_CMD_TSIZE_END_BIT = 39;

    const uint32_t ALTD_CMD_SCOPE_NUM_BITS = (ALTD_CMD_SCOPE_END_BIT -
            ALTD_CMD_SCOPE_START_BIT) + 1;
    const uint32_t ALTD_CMD_TTYPE_NUM_BITS = (ALTD_CMD_TTYPE_END_BIT -
            ALTD_CMD_TTYPE_START_BIT) + 1;
    const uint32_t ALTD_CMD_TSIZE_NUM_BITS = (ALTD_CMD_TSIZE_END_BIT -
            ALTD_CMD_TSIZE_START_BIT) + 1;

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

    // Values for PB operations
    const uint32_t ALTD_CMD_PB_OPERATION_TSIZE  = 0b00001000;
    const uint32_t ALTD_CMD_SCOPE_SYSTEM        = 0b00000101;

    // Values for PMISC operations
    const uint32_t ALTD_CMD_PMISC_TSIZE_1  = 0b00000010;    // PMISC SWITCH
    const uint32_t ALTD_CMD_PMISC_TSIZE_2  = 0b01000000;    // PMISC HTM

    // OPTION reg values for SWITCH operation
    const uint32_t QUIESCE_SWITCH_WAIT_COUNT = 128;
    const uint32_t INIT_SWITCH_WAIT_COUNT = 128;

    // ADU Status Register field/bit definitions
    const uint32_t ALTD_STATUS_BUSY_BIT = 0;
    const uint32_t ALTD_STATUS_WAIT_CMD_ARBIT = 1;
    const uint32_t ALTD_STATUS_ADDR_DONE_BIT = 2;
    const uint32_t ALTD_STATUS_DATA_DONE_BIT = 3;
    const uint32_t ALTD_STATUS_WAIT_RESP_BIT = 4;
    const uint32_t ALTD_STATUS_OVERRUN_ERROR_BIT = 5;
    const uint32_t ALTD_STATUS_AUTOINC_ERR_BIT = 6;
    const uint32_t ALTD_STATUS_COMMAND_ERR_BIT = 7;
    const uint32_t ALTD_STATUS_ADDRESS_ERR_BIT = 8;
    const uint32_t ALTD_STATUS_PB_OP_HANG_ERR_BIT = 9;
    const uint32_t ALTD_STATUS_PB_DATA_HANG_ERR_BIT = 10;
    const uint32_t ALTD_STATUS_PB_UNEXPECT_CRESP_ERR_BIT = 11;
    const uint32_t ALTD_STATUS_WAIT_PIB_DIRECT = 16;
    const uint32_t ALTD_STATUS_PIB_DIRECT_DONE = 17;
    const uint32_t ALTD_STATUS_PBINIT_MISSING_BIT = 18;
    const uint32_t ALTD_STATUS_ECC_CE_BIT = 48;
    const uint32_t ALTD_STATUS_ECC_UE_BIT = 49;
    const uint32_t ALTD_STATUS_ECC_SUE_BIT = 50;
    const uint32_t ALTD_STATUS_CRESP_START_BIT = 59;
    const uint32_t ALTD_STATUS_CRESP_END_BIT = 63;

    const uint32_t ALTD_STATUS_CRESP_NUM_BITS = (ALTD_STATUS_CRESP_END_BIT
            - ALTD_STATUS_CRESP_START_BIT + 1);

    //FORCE ECC Register field/bit definitions
    const uint32_t ALTD_DATA_ITAG_BIT = 0;
    const uint32_t ALTD_DATA_TX_ECC_START_BIT = 1;
    const uint32_t ALTD_DATA_TX_ECC_END_BIT = 16;
    const uint32_t ALTD_DATA_TX_ECC_OVERWRITE_BIT = 17;

    const uint32_t ALTD_DATA_ECC_MASK = 0xFFFFull;

    // ADU operation delay times for HW/sim
    const uint32_t PROC_ADU_UTILS_ADU_HW_NS_DELAY = 100000000;
    const uint32_t PROC_ADU_UTILS_ADU_SIM_CYCLE_DELAY = 100000;

    //---------------------------------------------------------------------------------
    // Function definitions
    //---------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode p9_adu_coherent_utils_check_args(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address)
    {
        FAPI_DBG("Start");

        //Check the address alignment
        FAPI_ASSERT(!(i_address & P9_FBC_UTILS_CACHELINE_MASK),
                    fapi2::P9_ADU_COHERENT_UTILS_INVALID_ARGS().set_TARGET(i_target).set_ADDRESS(
                        i_address),
                    "Address is not cacheline aligned");

        //Make sure the address is within the ADU bounds
        FAPI_ASSERT(i_address <= P9_FBC_UTILS_FBC_MAX_ADDRESS,
                    fapi2::P9_ADU_COHERENT_UTILS_INVALID_ARGS().set_TARGET(i_target).set_ADDRESS(
                        i_address),
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

        //Make sure the fabric is initialized and running
        FAPI_TRY(p9_fbc_utils_get_fbc_state(i_target, fbc_initialized, fbc_running),
                 "Error from p9_fbc_utils_get_fbc_state");
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
        altd_option_reg_data.setBit<FBC_ALTD_WITH_PRE_QUIESCE>();
        altd_option_reg_data.insertFromRight<FBC_ALTD_PRE_QUIESCE_COUNT_START_BIT,
                                             FBC_ALTD_PRE_QUIESCE_COUNT_NUM_OF_BITS>
                                             (QUIESCE_SWITCH_WAIT_COUNT);

        // Setup Post-command init
        altd_option_reg_data.setBit<FBC_ALTD_WITH_POST_INIT>();
        altd_option_reg_data.insertFromRight<FBC_ALTD_POST_INIT_COUNT_START_BIT,
                                             FBC_ALTD_POST_INIT_COUNT_NUM_OF_BITS>
                                             (INIT_SWITCH_WAIT_COUNT);

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
        FAPI_DBG("Start Addr 0x%.16llX, Flag 0x%.8X", i_address, i_flags);

        fapi2::ReturnCode rc;
        fapi2::buffer<uint64_t> altd_cmd_reg_data(0x0);
        fapi2::buffer<uint64_t> altd_addr_reg_data(i_address);
        fapi2::buffer<uint64_t> altd_data_reg_data(0x0);
        fapi2::buffer<uint64_t> altd_option_reg(0x0);
        p9_ADU_oper_flag l_myAduFlag;
        p9_ADU_oper_flag::OperationType_t l_operType;
        p9_ADU_oper_flag::Transaction_size_t l_transSize;

        // Write to the altd_cmd_reg to set the fbc_locked bit
        altd_cmd_reg_data.setBit<ALTD_CMD_LOCK_BIT>();
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data),
                 "Error writing the lock bit to ALTD_CMD Register");

        //Write the address into altd_addr_reg
        FAPI_DBG("Write PU_ALTD_ADDR_REG 0x%.16llX, Value 0x%.16llX",
                 PU_ALTD_ADDR_REG, altd_addr_reg_data);
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_ADDR_REG, altd_addr_reg_data),
                 "Error writing to ALTD_ADDR Register");

        // Process input flag
        l_myAduFlag.getFlag(i_flags);
        l_operType = l_myAduFlag.getOperationType();
        l_transSize = l_myAduFlag.getTransactionSize();

        // ---------------------------------------------
        // Setting for DMA and CI operations
        // ---------------------------------------------
        if ( (l_operType == p9_ADU_oper_flag::CACHE_INHIBIT) ||
             (l_operType == p9_ADU_oper_flag::DMA_PARTIAL) )
        {

            // ---------------------------------------------
            // DMA & CI common settings
            // ---------------------------------------------
            // Write the altd_cmd_reg
            // Set fbc_altd_rnw if it's a read
            if (i_rnw)
            {
                altd_cmd_reg_data.setBit<ALTD_CMD_RNW_BIT>();
            }
            // Clear fbc_altd_rnw if it's a write
            else
            {
                altd_cmd_reg_data.clearBit<ALTD_CMD_RNW_BIT>();
            }

            // If auto-inc set the auto-inc bit
            if (l_myAduFlag.getAutoIncrement() == true)
            {
                altd_cmd_reg_data.setBit<ALTD_CMD_AUTO_INC_BIT>();
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
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TTYPE_START_BIT, ALTD_CMD_TTYPE_NUM_BITS>(ALTD_CMD_TTYPE_CI_PR_RD);
                }
                else
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TTYPE_START_BIT, ALTD_CMD_TTYPE_NUM_BITS>(ALTD_CMD_TTYPE_CI_PR_WR);
                }

                // Set TSIZE
                if ( l_transSize == p9_ADU_oper_flag::TSIZE_1 )
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                      ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_CI_TSIZE_1);
                }
                else if ( l_transSize == p9_ADU_oper_flag::TSIZE_2 )
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                      ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_CI_TSIZE_2);
                }
                else if ( l_transSize == p9_ADU_oper_flag::TSIZE_4 )
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                      ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_CI_TSIZE_4);
                }
                else
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                      ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_CI_TSIZE_8);
                }
            }

            // ---------------------------------------------------
            // DMA specific: TTYPE & TSIZE
            // ---------------------------------------------------
            else if (l_operType == p9_ADU_oper_flag::DMA_PARTIAL)
            {
                FAPI_DBG("ADU operation type: DMA");

                // If a read, set ALTD_CMD_TTYPE_CL_DMA_RD
                // Set the tsize to ALTD_CMD_DMAR_TSIZE
                if (i_rnw)
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TTYPE_START_BIT, ALTD_CMD_TTYPE_NUM_BITS>(ALTD_CMD_TTYPE_CL_DMA_RD);
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                      ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_DMAR_TSIZE);
                }
                // If a write set ALTD_CMD_TTYPE_DMA_PR_WR
                // Set the tsize according to flag setting
                else
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TTYPE_START_BIT,
                                                      ALTD_CMD_TTYPE_NUM_BITS>(ALTD_CMD_TTYPE_DMA_PR_WR);

                    // Set TSIZE
                    if ( l_transSize == p9_ADU_oper_flag::TSIZE_1 )
                    {
                        altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                          ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_DMAW_TSIZE_1);
                    }
                    else if ( l_transSize == p9_ADU_oper_flag::TSIZE_2 )
                    {
                        altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                          ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_DMAW_TSIZE_2);
                    }
                    else if ( l_transSize == p9_ADU_oper_flag::TSIZE_4 )
                    {
                        altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                          ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_DMAW_TSIZE_4);
                    }
                    else
                    {
                        altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                          ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_DMAW_TSIZE_8);
                    }
                }
            }
        }

        // ---------------------------------------------
        // Setting for PB and PMISC operations
        // ---------------------------------------------
        if ( (l_operType == p9_ADU_oper_flag::PB_OPER) ||
             (l_operType == p9_ADU_oper_flag::PMISC_OPER) )
        {

            // ---------------------------------------------
            // PB & PMISC common settings
            // ---------------------------------------------

            // Set the start op bit
            altd_cmd_reg_data.setBit<ALTD_CMD_START_OP_BIT>();

            // Set operation scope
            altd_cmd_reg_data.insertFromRight<ALTD_CMD_SCOPE_START_BIT,
                                              ALTD_CMD_SCOPE_NUM_BITS>(ALTD_CMD_SCOPE_SYSTEM);

            // Set DROP_PRIORITY = HIGH
            altd_cmd_reg_data.setBit<ALTD_CMD_DROP_PRIORITY_BIT>();

            // Set AXTYPE = Address only
            altd_cmd_reg_data.setBit<ALTD_CMD_ADDRESS_ONLY_BIT>();

            // Set OVERWRITE_PBINIT
            altd_cmd_reg_data.setBit<ALTD_CMD_OVERWRITE_PBINIT_BIT>();

            // Set TM_QUIESCE
            altd_cmd_reg_data.setBit<ALTD_CMD_WITH_TM_QUIESCE_BIT>();


            // ---------------------------------------------------
            // PB specific: TTYPE & TSIZE
            // ---------------------------------------------------
            if (l_operType == p9_ADU_oper_flag::PB_OPER)
            {
                FAPI_DBG("ADU operation type: PB");

                // Set TTYPE
                altd_cmd_reg_data.insertFromRight<ALTD_CMD_TTYPE_START_BIT,
                                                  ALTD_CMD_TTYPE_NUM_BITS>(ALTD_CMD_TTYPE_PB_OPER);

                // TSIZE for PB operation is fixed value: 0b00001000
                altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                  ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_PB_OPERATION_TSIZE);
            }

            // ---------------------------------------------------
            // PMISC specific: TTYPE & TSIZE
            // ---------------------------------------------------
            else if (l_operType == p9_ADU_oper_flag::PMISC_OPER)
            {
                FAPI_DBG("ADU operation type: PMISC");

                // Set TTYPE
                altd_cmd_reg_data.insertFromRight<ALTD_CMD_TTYPE_START_BIT,
                                                  ALTD_CMD_TTYPE_NUM_BITS>(ALTD_CMD_TTYPE_PMISC_OPER);

                // Set TSIZE
                if ( l_transSize == p9_ADU_oper_flag::TSIZE_1 )
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                      ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_PMISC_TSIZE_1);
                }
                else if ( l_transSize == p9_ADU_oper_flag::TSIZE_2 )
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                      ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_PMISC_TSIZE_2);
                }

                // Set quiesce and init around a switch operation in option reg
                FAPI_TRY(setQuiesceInit(i_target), "setQuiesceInit() returns error");
            }
        }

        //This sets everything that should be set for the ALTD_CMD_Register
        FAPI_DBG("CMD reg value 0x%016llX", altd_cmd_reg_data);

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
        bool l_fastMode          = i_aduOper.getFastMode();
        bool l_accessForceEccReg = (l_itagMode | l_eccMode | l_overrideEccMode);

        // Dump ADU write settings
        FAPI_DBG("Modes: ITAG 0x%.8X, ECC 0x%.8X, OVERRIDE_ECC 0x%.8X",
                 l_itagMode, l_eccMode, l_overrideEccMode);
        FAPI_DBG("       AUTOINC 0x%.8X, FASTMODE 0x%.8X",
                 l_autoIncMode, l_fastMode);

        for (int i = 0; i < 8; i++)
        {
            write_data |= ( static_cast<uint64_t>(i_write_data[i]) << (56 - (8 * i)) );
        }

        fapi2::buffer<uint64_t> altd_data_reg_data(write_data);

        if (l_accessForceEccReg == true)
        {
            FAPI_TRY(fapi2::getScom(i_target, PU_FORCE_ECC_REG, force_ecc_reg_data), "Error reading the FORCE_ECC Register");
        }

        //if we want to write the itag bit set it
        if (l_itagMode == true)
        {
            eccIndex++;
            force_ecc_reg_data.setBit<ALTD_DATA_ITAG_BIT>();
        }

        //if we want to write the ecc data get the data
        if (l_eccMode == true)
        {
            force_ecc_reg_data.insertFromRight < ALTD_DATA_TX_ECC_START_BIT,
                                               (ALTD_DATA_TX_ECC_END_BIT - ALTD_DATA_TX_ECC_START_BIT) + 1 >
                                               ((uint64_t)i_write_data[eccIndex]);
        }

        //if we want to overwrite the ecc data
        if (l_overrideEccMode == true)
        {
            force_ecc_reg_data.setBit<ALTD_DATA_TX_ECC_OVERWRITE_BIT>();
        }

        if (l_accessForceEccReg == true)
        {
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
            altd_cmd_reg_data.setBit<ALTD_CMD_START_OP_BIT>();
            //write the altd_cmd_register
            FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error writing to the ALTD_CMD_REG");
        }

        //if we are not in fastmode delay to allow time for the write to go through before we check the status
        if (l_fastMode == false)
        {
            FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_HW_NS_DELAY,
                                  PROC_ADU_UTILS_ADU_SIM_CYCLE_DELAY),
                     "fapiDelay error");
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
        bool l_fastMode          = i_aduOper.getFastMode();

        // Dump ADU read settings
        FAPI_DBG("Modes: ITAG 0x%.8X, ECC 0x%.8X, AUTOINC 0x%.8X, FASTMODE 0x%.8X",
                 l_itagMode, l_eccMode, l_autoIncMode, l_fastMode);

        //Set the ALTD_CMD_START_OP bit to start the read(first granule for autoinc case or not autoinc)
        if ( i_firstGranule || (l_autoIncMode == false) )
        {
            //read the altd_cmd_register
            FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error reading from the ALTD_CMD_REG");
            //set the start op bit
            altd_cmd_reg_data.setBit<ALTD_CMD_START_OP_BIT>();
            //write the altd_cmd_register
            FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error writing to the ALTD_CMD_REG");
        }

        //if we are not in fastmode delay to allow time for the read to go through before we get the data
        if ( l_fastMode == false )
        {
            FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_HW_NS_DELAY,
                                  PROC_ADU_UTILS_ADU_SIM_CYCLE_DELAY),
                     "fapiDelay error");
        }


        //if we want to include the itag and ecc data collect them before the read
        if ( l_itagMode || l_eccMode )
        {
            FAPI_TRY(fapi2::getScom(i_target, PU_FORCE_ECC_REG, force_ecc_reg_data),
                     "Error reading from the FORCE_ECC Register");
        }

        if (l_itagMode)
        {
            eccIndex = 9;
            o_read_data[8] = force_ecc_reg_data.getBit<ALTD_DATA_ITAG_BIT>();
        }

        if (l_eccMode)
        {
            o_read_data[eccIndex] = (force_ecc_reg_data >> ALTD_DATA_TX_ECC_END_BIT) & ALTD_DATA_ECC_MASK;
        }

        FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_STATUS_REG, altd_status_reg_data),
                 "Error reading from ALTD_STATUS Register");

        //read data from altd_data_reg
        FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_DATA_REG, altd_data_reg_data),
                 "Error reading from the ALTD_DATA Register");

        for (int i = 0; i < 8; i++)
        {
            o_read_data[i] = (altd_data_reg_data >> (56 - (i * 8))) & 0xFFull;
        }

        //o_read_data[0] = altd_data_reg_data;
        FAPI_DBG("altd_data_reg_data = %lu\n", altd_data_reg_data);

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode p9_adu_coherent_utils_reset_adu(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> altd_cmd_reg_data(0x0);

        FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error reading from ALTD_CMD Register");

        //write altd_cmd_reg to set the reset_fsm bit
        altd_cmd_reg_data.setBit<ALTD_CMD_RESET_FSM_BIT>();
        altd_cmd_reg_data.setBit<ALTD_CMD_CLEAR_STATUS_BIT>();
        altd_cmd_reg_data.setBit<ALTD_CMD_LOCK_BIT>();
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

        FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data),
                 "Error reading from ALTD_CMD Register");

        //write altd_cmd_reg to clear the fbc_locked bit
        altd_cmd_reg_data.clearBit<ALTD_CMD_LOCK_BIT>();
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data),
                 "Error clearing the fbc_locked bit from the ALTD_CMD Register");

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

        // Check the ALTD_STATUS_REG
        FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_STATUS_REG, l_statusReg),
                 "Error reading from ALTD_STATUS Register");
        FAPI_DBG("PU_ALTD_STATUS_REG reg value 0x%016llX", l_statusReg);

        // ---- Handle busy options ----

        // Get busy bit output
        o_busyBitStatus = l_statusReg.getBit<ALTD_STATUS_BUSY_BIT>();

        // Handle busy bit according to specified input
        if (o_busyBitStatus == true)
        {
            // Exit if busy
            if (i_busyBitHandler == EXIT_ON_BUSY)
            {
                goto fapi_try_exit;
            }
            else if (i_busyBitHandler == EXPECTED_BUSY_BIT_CLEAR)
            {
                l_statusError = true;
            }
        }
        else if (i_busyBitHandler == EXPECTED_BUSY_BIT_SET)
        {
            l_statusError = true;
        }

        // ---- Check for other errors ----
        // Check the WAIT_CMD_ARBIT bit and make sure it's 0
        // Check the ADDR_DONE bit and make sure it's set
        // Check the DATA_DONE bit and make sure it's set
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
              l_statusReg.getBit<ALTD_STATUS_WAIT_CMD_ARBIT>()        ||
              !l_statusReg.getBit<ALTD_STATUS_ADDR_DONE_BIT>()        ||
              l_statusReg.getBit<ALTD_STATUS_WAIT_RESP_BIT>()         ||
              l_statusReg.getBit<ALTD_STATUS_OVERRUN_ERROR_BIT>()     ||
              l_statusReg.getBit<ALTD_STATUS_AUTOINC_ERR_BIT>()       ||
              l_statusReg.getBit<ALTD_STATUS_COMMAND_ERR_BIT>()       ||
              l_statusReg.getBit<ALTD_STATUS_ADDRESS_ERR_BIT>()       ||
              l_statusReg.getBit<ALTD_STATUS_PB_OP_HANG_ERR_BIT>()    ||
              l_statusReg.getBit<ALTD_STATUS_PB_DATA_HANG_ERR_BIT>()  ||
              l_statusReg.getBit<ALTD_STATUS_PBINIT_MISSING_BIT>()    ||
              l_statusReg.getBit<ALTD_STATUS_ECC_CE_BIT>()            ||
              l_statusReg.getBit<ALTD_STATUS_ECC_UE_BIT>()            ||
              l_statusReg.getBit<ALTD_STATUS_ECC_SUE_BIT>()
            );

        // If Address only operation, do not check for ALTD_STATUS_DATA_DONE_BIT
        if ( i_addressOnlyOper == false )
        {
            l_statusError |= !l_statusReg.getBit<ALTD_STATUS_DATA_DONE_BIT>();
        }

        // If error, display trace
        if (l_statusError)
        {
            FAPI_ERR("Status mismatch detected");

            FAPI_ERR("FBC_ALTD_BUSY = %d", (o_busyBitStatus ? 1 : 0));
            FAPI_ERR("ALTD_STATUS_REG = %016llX", l_statusReg);
        }

        FAPI_ASSERT( (l_statusError == false), fapi2::P9_ADU_STATUS_REG_ERR()
                     .set_TARGET(i_target)
                     .set_STATUSREG(l_statusReg),
                     "Status Register check error");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode p9_adu_coherent_clear_autoinc(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> altd_cmd_reg_data;

        FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data),
                 "Error reading from ALTD_CMD Register");

        altd_cmd_reg_data.clearBit<ALTD_CMD_AUTO_INC_BIT>();
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

        // validate input parameters
        if (i_num_attempts == 0)
        {
            FAPI_ERR("Invalid value %d for number of lock manipulation attempts",
                     i_num_attempts);
        }

        // set up data buffer to perform desired lock manipulation operation
        if (i_lock)
        {
            FAPI_DBG("Configuring lock manipulation control data buffer to perform lock acquisition");
            lock_control.setBit(ALTD_CMD_LOCK_BIT);
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
                            lock_control.setBit(ALTD_CMD_LOCK_PICK_BIT);
                            attempt_count--;
                            lock_pick_first_time = false;
                            FAPI_DBG("Trying to do a lock pick as desired");
                        }
                        else
                        {
                            FAPI_ERR("Desired ADU lock manipulation was not successful after %d attempts",
                                     i_num_attempts);
                            break;
                        }
                    }
                }

                // rc clean, lock management operation successful
                FAPI_DBG("Lock manipulation successful or going to try a lock pick");
                break;
            }

            // delay to provide time for ADU lock to be released
            FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_HW_NS_DELAY,
                                  PROC_ADU_UTILS_ADU_SIM_CYCLE_DELAY),
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

} // extern "C
