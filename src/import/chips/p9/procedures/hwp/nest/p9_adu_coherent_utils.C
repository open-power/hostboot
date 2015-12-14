/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_adu_coherent_utils.C $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
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

    const uint32_t ALTD_CMD_TTYPE_NUM_BITS = (ALTD_CMD_TTYPE_END_BIT
            - ALTD_CMD_TTYPE_START_BIT + 1);
    const uint32_t ALTD_CMD_TSIZE_NUM_BITS = (ALTD_CMD_TSIZE_END_BIT
            - ALTD_CMD_TSIZE_START_BIT + 1);

    const uint32_t ALTD_CMD_TTYPE_CL_DMA_RD = 3; //0b0000011
    const uint32_t ALTD_CMD_TTYPE_DMA_PR_WR = 38;//0b0100110
    const uint32_t ALTD_CMD_TTYPE_CI_PR_RD = 52; //0b0110100
    const uint32_t ALTD_CMD_TTYPE_CI_PR_WR = 55; //0b0110111
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

    //---------------------------------------------------------------------------------
    // NOTE: description in header
    //---------------------------------------------------------------------------------
    fapi2::ReturnCode p9_adu_coherent_setup_adu(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const bool i_rnw,
        const uint32_t i_flags)
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> altd_cmd_reg_data(0x0);
        fapi2::buffer<uint64_t> altd_addr_reg_data(i_address);
        fapi2::buffer<uint64_t> altd_data_reg_data(0x0);

        //write to the altd_cmd_reg to set the fbc_locked bit
        altd_cmd_reg_data.setBit<ALTD_CMD_LOCK_BIT>();
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data),
                 "Error writing the lock bit to ALTD_CMD Register");

        //write the address into altd_addr_reg
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_ADDR_REG, altd_addr_reg_data),
                 "Error writing to ALTD_ADDR Register");

        //write the altd_cmd_reg
        //set fbc_altd_rnw if it's a read
        if (i_rnw)
        {
            altd_cmd_reg_data.setBit<ALTD_CMD_RNW_BIT>();
        }
        //clear fbc_altd_rnw if it's a write
        else
        {
            altd_cmd_reg_data.clearBit<ALTD_CMD_RNW_BIT>();
        }

        //set the ttype and tsize
        //if it's a CI write/read
        if (i_flags & FLAG_CI)
        {
            if (i_rnw)
            {
                altd_cmd_reg_data.insertFromRight<ALTD_CMD_TTYPE_START_BIT, ALTD_CMD_TTYPE_NUM_BITS>(ALTD_CMD_TTYPE_CI_PR_RD);
            }
            else
            {
                altd_cmd_reg_data.insertFromRight<ALTD_CMD_TTYPE_START_BIT, ALTD_CMD_TTYPE_NUM_BITS>(ALTD_CMD_TTYPE_CI_PR_WR);
            }

            //if tsize = 1
            if (((i_flags & FLAG_SIZE) >> FLAG_SIZE_SHIFT) == 1)
            {
                altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                  ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_CI_TSIZE_1);
            }
            else if (((i_flags & FLAG_SIZE) >> FLAG_SIZE_SHIFT) == 2)
            {
                altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                  ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_CI_TSIZE_2);
            }
            else if (((i_flags & FLAG_SIZE) >> FLAG_SIZE_SHIFT) == 4)
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
        //if it's not a CI write/read
        else
        {
            //if a read set dma_cl_rd
            //set the tsize to 8
            if (i_rnw)
            {
                altd_cmd_reg_data.insertFromRight<ALTD_CMD_TTYPE_START_BIT, ALTD_CMD_TTYPE_NUM_BITS>(ALTD_CMD_TTYPE_CL_DMA_RD);
                altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT,
                                                  ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_DMAR_TSIZE);
            }
            //if a write set pr_dma_wr
            //set the tsize to 8
            else
            {
                altd_cmd_reg_data.insertFromRight<ALTD_CMD_TTYPE_START_BIT, ALTD_CMD_TTYPE_NUM_BITS>(ALTD_CMD_TTYPE_DMA_PR_WR);

                if (((i_flags & FLAG_SIZE) >> FLAG_SIZE_SHIFT) == 1)
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT, ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_DMAW_TSIZE_1);
                }
                else if (((i_flags & FLAG_SIZE) >> FLAG_SIZE_SHIFT) == 2)
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT, ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_DMAW_TSIZE_2);
                }
                else if (((i_flags & FLAG_SIZE) >> FLAG_SIZE_SHIFT) == 4)
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT, ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_DMAW_TSIZE_4);
                }
                else
                {
                    altd_cmd_reg_data.insertFromRight<ALTD_CMD_TSIZE_START_BIT, ALTD_CMD_TSIZE_NUM_BITS>(ALTD_CMD_DMAW_TSIZE_8);
                }
            }
        }

        //if auto-inc set the auto-inc bit (bit 19)
        if (i_flags & FLAG_AUTOINC)
        {
            altd_cmd_reg_data.setBit<ALTD_CMD_AUTO_INC_BIT>();
        }

        //This sets everything that should be set for the ALTD_CMD_Register
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
        const uint32_t i_flags,
        const uint8_t i_write_data[])
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> altd_cmd_reg_data;
        fapi2::buffer<uint64_t> altd_status_reg_data;
        fapi2::buffer<uint64_t> force_ecc_reg_data;
        uint64_t write_data = 0x0ull;
        int eccIndex = 8;

        for (int i = 0; i < 8; i++)
        {
            write_data = write_data + ((uint64_t)(i_write_data) << (56 - (8 * i)));
        }

        fapi2::buffer<uint64_t> altd_data_reg_data(write_data);

        if ((i_flags & FLAG_ITAG) || (i_flags & FLAG_ECC) || (i_flags & FLAG_OVERWRITE_ECC))
        {
            FAPI_TRY(fapi2::getScom(i_target, PU_FORCE_ECC_REG, force_ecc_reg_data), "Error reading the FORCE_ECC Register");
        }

        //if we want to write the itag bit set it
        if (i_flags & FLAG_ITAG)
        {
            eccIndex++;
            force_ecc_reg_data.setBit<ALTD_DATA_ITAG_BIT>();
        }

        //if we want to write the ecc data get the data
        if (i_flags & FLAG_ECC)
        {
            force_ecc_reg_data.insertFromRight < ALTD_DATA_TX_ECC_START_BIT,
                                               (ALTD_DATA_TX_ECC_END_BIT - ALTD_DATA_TX_ECC_START_BIT) + 1 >
                                               ((uint64_t)i_write_data[eccIndex]);
        }

        //if we want to overwrite the ecc data
        if (i_flags & FLAG_OVERWRITE_ECC)
        {
            force_ecc_reg_data.setBit<ALTD_DATA_TX_ECC_OVERWRITE_BIT>();
        }

        if ((i_flags & FLAG_ITAG) || (i_flags & FLAG_ECC) || (i_flags & FLAG_OVERWRITE_ECC))
        {
            FAPI_TRY(fapi2::putScom(i_target, PU_FORCE_ECC_REG, force_ecc_reg_data), "Error writing to the FORCE_ECC Register");
        }

        //write the data into the altd_data_reg
        FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_DATA_REG, altd_data_reg_data),
                 "Error writing to ALTD_DATA Register");

        //Set the ALTD_CMD_START_OP bit to start the write(first granule for autoinc case or not autoinc)
        if (i_firstGranule || !(i_flags & adu_flags::FLAG_AUTOINC))
        {
            //read the altd_cmd_register
            FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error reading from the ALTD_CMD_REG");
            //set the start op bit
            altd_cmd_reg_data.setBit<ALTD_CMD_START_OP_BIT>();
            //write the altd_cmd_register
            FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error writing to the ALTD_CMD_REG");
        }

        //if we are not in fastmode delay to allow time for the write to go through before we check the status
        if (!(i_flags & FLAG_FASTMODE_ADU))
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
        const uint32_t i_flags,
        uint8_t o_read_data[])
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> altd_cmd_reg_data;
        fapi2::buffer<uint64_t> altd_status_reg_data;
        fapi2::buffer<uint64_t> altd_data_reg_data;
        fapi2::buffer<uint64_t> force_ecc_reg_data;
        int eccIndex = 8;

        //Set the ALTD_CMD_START_OP bit to start the read(first granule for autoinc case or not autoinc)
        if (i_firstGranule || !(i_flags & adu_flags::FLAG_AUTOINC))
        {
            //read the altd_cmd_register
            FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error reading from the ALTD_CMD_REG");
            //set the start op bit
            altd_cmd_reg_data.setBit<ALTD_CMD_START_OP_BIT>();
            //write the altd_cmd_register
            FAPI_TRY(fapi2::putScom(i_target, PU_ALTD_CMD_REG, altd_cmd_reg_data), "Error writing to the ALTD_CMD_REG");
        }

        //if we are not in fastmode delay to allow time for the read to go through before we get the data
        if (!(i_flags & FLAG_FASTMODE_ADU))
        {
            FAPI_TRY(fapi2::delay(PROC_ADU_UTILS_ADU_HW_NS_DELAY,
                                  PROC_ADU_UTILS_ADU_SIM_CYCLE_DELAY),
                     "fapiDelay error");
        }


        //if we want to include the itag and ecc data collect them before the read
        if ((i_flags & FLAG_ITAG) || (i_flags & FLAG_ECC))
        {
            FAPI_TRY(fapi2::getScom(i_target, PU_FORCE_ECC_REG, force_ecc_reg_data),
                     "Error reading from the FORCE_ECC Register");
        }

        if (i_flags & FLAG_ITAG)
        {
            eccIndex = 9;
            o_read_data[8] = force_ecc_reg_data.getBit<ALTD_DATA_ITAG_BIT>();
        }

        if (i_flags & FLAG_ECC)
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
        const bool i_busy_bit_set_expected)
    {
        FAPI_DBG("Start");

        fapi2::buffer<uint64_t> altd_status_reg_data(0x0);
        bool busyBitSetCorrectly = true;

        //check the ALTD_STATUS_REG
        FAPI_TRY(fapi2::getScom(i_target, PU_ALTD_STATUS_REG, altd_status_reg_data),
                 "Error reading from ALTD_STATUS Register");

        //If busy set is expected and the altd_status_busy bit is set or busy set is not expected and teh altd_status_busy bit is not set then the busy bit is set correctly
        if (i_busy_bit_set_expected == altd_status_reg_data.getBit<ALTD_STATUS_BUSY_BIT>())
        {
            busyBitSetCorrectly = true;
        }

        //check the FBC_ALTD_BUSY bit and make sure it's 0 unless we are in autoinc and this is not the last granule
        //check the WAIT_CMD_ARBIT bit and make sure it's 0
        //check the ADDR_DONE bit and make sure it's set
        //check the DATA_DONE bit and make sure it's set
        //check the WAIT_RESP bit to make sure it's clear
        //check the OVERRUN_ERR to make sure it's clear
        //check the AUTOINC_ERR to make sure it's clear
        //check the COMMAND_ERR to make sure it's clear
        //check the ADDRESS_ERR to make sure it's clear
        //check the COMMAND_HANG_ERR to make sure it's clear
        //check the DATA_HANG_ERR to make sure it's clear
        //check the PBINIT_MISSING to make sure it's clear
        //check the ECC_CE to make sure it's clear
        //check the ECC_UE to make sure it's clear
        //check the ECC_SUE to make sure it's clear
        FAPI_ASSERT((   busyBitSetCorrectly
                        && !altd_status_reg_data.getBit<ALTD_STATUS_WAIT_CMD_ARBIT>()
                        //TODO These were causing problems when I tried running on vhdl, need to figure out what the problem is
                        //&& altd_status_reg_data.getBit<ALTD_STATUS_ADDR_DONE_BIT>()
                        //&& altd_status_reg_data.getBit<ALTD_STATUS_DATA_DONE_BIT>()
                        //&& !altd_status_reg_data.getBit<ALTD_STATUS_WAIT_RESP_BIT>()
                        && !altd_status_reg_data.getBit<ALTD_STATUS_OVERRUN_ERROR_BIT>()
                        && !altd_status_reg_data.getBit<ALTD_STATUS_AUTOINC_ERR_BIT>()
                        && !altd_status_reg_data.getBit<ALTD_STATUS_COMMAND_ERR_BIT>()
                        && !altd_status_reg_data.getBit<ALTD_STATUS_ADDRESS_ERR_BIT>()
                        && !altd_status_reg_data.getBit<ALTD_STATUS_PB_OP_HANG_ERR_BIT>()
                        && !altd_status_reg_data.getBit<ALTD_STATUS_PB_DATA_HANG_ERR_BIT>()
                        && !altd_status_reg_data.getBit<ALTD_STATUS_PBINIT_MISSING_BIT>()
                        && !altd_status_reg_data.getBit<ALTD_STATUS_ECC_CE_BIT>() && !altd_status_reg_data.getBit<ALTD_STATUS_ECC_UE_BIT>()
                        && !altd_status_reg_data.getBit<ALTD_STATUS_ECC_SUE_BIT>()),
                    fapi2::P9_ADU_STATUS_REG_ERR().set_TARGET(i_target).set_STATUSREG(altd_status_reg_data), "Status Register check error");

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
