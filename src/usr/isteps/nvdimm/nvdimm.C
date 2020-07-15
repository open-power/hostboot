/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimm.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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

#include "nvdimm.H"
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <sys/time.h>
#include <usr/devicefw/userif.H>
/* FIXME RTC:249244
#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/ddr4/nvdimm_utils.H>
#include <lib/mc/port.H>
*/
#include <isteps/nvdimm/nvdimmreasoncodes.H>
#include <isteps/nvdimm/nvdimm.H>
#include <vpd/spdenums.H>

using namespace TARGETING;
using namespace DeviceFW;
using namespace EEPROM;

trace_desc_t* g_trac_nvdimm = NULL;
TRAC_INIT(&g_trac_nvdimm, NVDIMM_COMP_NAME, 2*KILOBYTE);

// Easy macro replace for unit testing
#define TRACUCOMP(args...)  TRACFCOMP(args)
//#define TRACUCOMP(args...)


namespace NVDIMM
{
#define NUM_OFFSET 2
#define NVDIMM_SET_USER_DATA_1(left_32_ops_id, right_32_huid) \
            TWO_UINT32_TO_UINT64(left_32_ops_id, right_32_huid)

#define NVDIMM_SET_USER_DATA_2_TIMEOUT(left_32_polled, right_32_timeout) \
            NVDIMM_SET_USER_DATA_1(left_32_polled, right_32_timeout)


typedef struct ops_timeoutInfo{
    const char * desc;
    uint16_t offset[2];
    uint8_t idx;
    uint16_t status_reg_offset;
    uint8_t status_progress;
} ops_timeoutInfo_t;

// Table containing register info on the timeout registers for different ops
constexpr ops_timeoutInfo_t timeoutInfoTable[] =
{
    {"SAVE",         {CSAVE_TIMEOUT1, CSAVE_TIMEOUT0},             SAVE       , NVDIMM_CMD_STATUS0, SAVE_IN_PROGRESS},
    {"RESTORE",      {RESTORE_TIMEOUT1, RESTORE_TIMEOUT0},         RESTORE    , NVDIMM_CMD_STATUS0, RSTR_IN_PROGRESS},
    {"ERASE",        {ERASE_TIMEOUT1, ERASE_TIMEOUT0},             ERASE      , NVDIMM_CMD_STATUS0, ERASE_IN_PROGRESS},
    {"ARM",          {ARM_TIMEOUT1, ARM_TIMEOUT0},                 ARM        , NVDIMM_CMD_STATUS0, ARM_IN_PROGRESS},
    {"PAGE_SWITCH",  {PAGE_SWITCH_LATENCY1, PAGE_SWITCH_LATENCY0}, PAGE_SWITCH, 0xff, 0xff},
    {"CHARGE",       {ES_CHARGE_TIMEOUT1, ES_CHARGE_TIMEOUT0},     CHARGE     , MODULE_HEALTH_STATUS1, CHARGE_IN_PROGRESS},
};

/**
 * @brief Wrapper to call deviceOp to read the NV controller via I2C
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_addr - address/offset for the register to be read
 *
 * @param[out] o_data - returned data from read
 *
 * @param[in] page_verify - read and verify the page associated to the given address.
 *                          Change if needed. Default to true
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmReadReg(Target* i_nvdimm,
                         uint16_t i_addr,
                         uint8_t & o_data,
                         const bool page_verify)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"NVDIMM Read HUID %X, addr 0x%X",
                  TARGETING::get_huid(i_nvdimm), i_addr);

    errlHndl_t l_err = nullptr;
    size_t l_numBytes = 1;
    uint8_t l_reg_addr = ADDRESS(i_addr);
    uint8_t l_reg_page = PAGE(i_addr);

    do
    {
        // If page_verify is true, make sure the current page is set to the page
        // where i_addr is in and change if needed
        if (page_verify)
        {
            uint8_t l_data = 0;
            l_err = nvdimmReadReg(i_nvdimm, OPEN_PAGE, l_data, NO_PAGE_VERIFY);

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmReadReg() nvdimm[%X] - failed to read the current page",
                          TARGETING::get_huid(i_nvdimm));
                break;
            }

            if (l_data != l_reg_page)
            {
                l_err = nvdimmOpenPage(i_nvdimm, l_reg_page);

                if (l_err)
                {
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmReadReg() nvdimm[%X] - failed to verify page",
                              TARGETING::get_huid(i_nvdimm));
                    break;
                }
            }
        }

        l_err = DeviceFW::deviceOp( DeviceFW::READ,
                                    i_nvdimm,
                                    &o_data,
                                    l_numBytes,
                                    DEVICE_NVDIMM_ADDRESS(l_reg_addr));
    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"NVDIMM Read HUID %X, page 0x%X, addr 0x%X = %X",
                  TARGETING::get_huid(i_nvdimm), l_reg_page, l_reg_addr, o_data);

    return l_err;
}

/**
 * @brief Wrapper to call deviceOp to write the NV controller via I2C
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_addr - address/offset for the register to be written
 *
 * @param[in] i_data - data to be written to register @ i_addr
 *
 * @param[in] page_verify - read and verify the page associated to the given address.
 *                          Change if needed. Default to true
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmWriteReg(Target* i_nvdimm,
                         uint16_t i_addr,
                         uint8_t i_data,
                         const bool page_verify)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"NVDIMM Write HUID %X, addr 0x%X = %X",
                  TARGETING::get_huid(i_nvdimm), i_addr, i_data);

    errlHndl_t l_err = nullptr;
    size_t l_numBytes = 1;
    uint8_t l_reg_addr = ADDRESS(i_addr);
    uint8_t l_reg_page = PAGE(i_addr);

    do
    {
        // If page_verify is true, make sure the current page is set to the page
        // where i_addr is in and change if needed
        if (page_verify)
        {
            uint8_t l_data = 0;
            l_err = nvdimmReadReg(i_nvdimm, OPEN_PAGE, l_data, NO_PAGE_VERIFY);

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmWriteReg() nvdimm[%X] - failed to read the current page",
                          TARGETING::get_huid(i_nvdimm));
                break;
            }

            if (l_data != l_reg_page)
            {
                l_err = nvdimmOpenPage(i_nvdimm, l_reg_page);

                if (l_err)
                {
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmWriteReg() nvdimm[%X] - failed to verify page",
                              TARGETING::get_huid(i_nvdimm));
                    break;
                }
            }
        }

        l_err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                    i_nvdimm,
                                    &i_data,
                                    l_numBytes,
                                    DEVICE_NVDIMM_ADDRESS(l_reg_addr));
    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"NVDIMM Write HUID %X, page = 0x%X, addr 0x%X = %X",
                  TARGETING::get_huid(i_nvdimm), l_reg_page, l_reg_addr, i_data);

    return l_err;
}

/**
 * @brief Set the status flag
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_status_flag - status flag to set for each nvdimm
 *
 */
void nvdimmSetStatusFlag(Target *i_nvdimm, const uint8_t i_status_flag)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmSetStatusFlag() HUID[%X], i_status_flag[%X]"
                ,TARGETING::get_huid(i_nvdimm), i_status_flag);

    auto l_statusFlag = i_nvdimm->getAttr<TARGETING::ATTR_NV_STATUS_FLAG>();

    switch(i_status_flag)
    {
        // Make sure NSTD_VAL_PRSV (content preserved) is unset before setting NSTD_VAL_NOPRSV
        // (data not preserved) or NSTD_ERR_NOPRSV (error preserving data)
        case NSTD_ERR:
        case NSTD_VAL_NOPRSV:
        case NSTD_ERR_NOPRSV:
            l_statusFlag &= NSTD_VAL_PRSV_MASK;
            l_statusFlag |= i_status_flag;
            break;

        // If the content preserved(restore sucessfully), make sure
        // NSTD_VAL_NOPRSV (not preserved) and NSTD_ERR_NOPRSV (error preserving)
        // are unset before setting this flag.
        case NSTD_VAL_PRSV:
            l_statusFlag &= (NSTD_VAL_NOPRSV_MASK & NSTD_ERR_NOPRSV_MASK);
            l_statusFlag |= i_status_flag;
            break;

        case NSTD_ERR_NOBKUP:
            l_statusFlag |= i_status_flag;
            break;

        default:
            assert(0, "nvdimmSetStatusFlag() HUID[%X], i_status_flag[%X] invalid flag!",
                   TARGETING::get_huid(i_nvdimm), i_status_flag);
            break;
    }

    i_nvdimm->setAttr<TARGETING::ATTR_NV_STATUS_FLAG>(l_statusFlag);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmSetStatusFlag() HUID[%X], i_status_flag[%X]"
                ,TARGETING::get_huid(i_nvdimm), i_status_flag);
}


/**
 * @brief Check NV controller ready state
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmReady(Target *i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmReady() HUID[%X]",TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    uint8_t l_data = 0x0;
    uint8_t l_nvm_init_time = 0;
    size_t l_numBytes = 1;

    do
    {
        // Read the maximum NVM init time in seconds from the SPD
        l_err = deviceRead(i_nvdimm,
                           &l_nvm_init_time,
                           l_numBytes,
                           DEVICE_SPD_ADDRESS(SPD::NVM_INIT_TIME));

        TRACUCOMP(g_trac_nvdimm, "nvdimmReady() HUID[%X] l_nvm_init_time = %u",
                    TARGETING::get_huid(i_nvdimm), l_nvm_init_time);

        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmReady() nvdimm[%X] - failed to retrieve NVM_INIT_TIME from SPD",
                      TARGETING::get_huid(i_nvdimm));
            break;
        }

        // Convert to ms for polling
        uint32_t l_nvm_init_time_ms = l_nvm_init_time * MS_PER_SEC;
        uint32_t l_poll = 0;

        do
        {
            l_err = nvdimmReadReg(i_nvdimm, NVDIMM_READY, l_data);

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmReady() nvdimm[%X] - error getting ready status[%d]",
                          TARGETING::get_huid(i_nvdimm), l_data);
                break;
            }

            if (l_data == NV_READY)
            {
                break;
            }

            nanosleep(0, NV_READY_POLL_TIME_MS*NS_PER_MSEC);
            l_poll += NV_READY_POLL_TIME_MS;

        }while(l_poll < l_nvm_init_time_ms);

        if ((l_data != NV_READY) && !l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmReady() nvdimm[%X] - nvdimm not ready[%d]",
                      TARGETING::get_huid(i_nvdimm), l_data);
            /*@
             *@errortype
             *@reasoncode       NVDIMM_NOT_READY
             *@severity         ERRORLOG_SEV_UNRECOVERABLE
             *@moduleid         NVDIMM_CHECK_READY
             *@userdata1[0:31]  Ret value from ready register
             *@userdata1[32:63] Target Huid
             *@userdata2        <UNUSED>
             *@devdesc          Failed to read ready status or NVDIMM not ready
             *                   for host access. (userdata1 != 0xA5)
             *@custdesc         NVDIMM not ready
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           NVDIMM_CHECK_READY,
                                           NVDIMM_NOT_READY,
                                           NVDIMM_SET_USER_DATA_1(l_data, TARGETING::get_huid(i_nvdimm)),
                                           0x0,
                                           ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace(NVDIMM_COMP_NAME, 1024 );

            // If nvdimm is not ready for access by now, this is
            // a failing indication on the NV controller
            l_err->addPartCallout( i_nvdimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
        }

    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmReady() HUID[%X] ready[%X]",
                TARGETING::get_huid(i_nvdimm), l_data);

    return l_err;
}

/**
 * @brief Reset the NV controller. This operation does not interfere
 *        with the DRAM operation but will introduce loss of protection
 *        if NVDIMM was armed
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmResetController(Target *i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmResetController() HUID[%X]",TARGETING::get_huid(i_nvdimm));
    errlHndl_t l_err = nullptr;

    do
    {

        l_err = nvdimmWriteReg(i_nvdimm, NVDIMM_MGT_CMD0, RESET_CONTROLLER);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmResetController() nvdimm[%X] - error reseting the controller",
                      TARGETING::get_huid(i_nvdimm));
            break;
        }

        l_err = nvdimmReady(i_nvdimm);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmResetController() nvdimm[%X] - not ready after reset.",
                      TARGETING::get_huid(i_nvdimm));
        }

    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmResetController() HUID[%X]",TARGETING::get_huid(i_nvdimm));

    return l_err;
}

/**
 * @brief This function polls the status register for the given ops_id
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_ops_id - id assigned to each operation in nvdimm.H
 *
 * @param[out] o_poll - total polled time in ms
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmPollStatus ( Target *i_nvdimm,
                        ops_id i_ops_id,
                        uint32_t &o_poll)
{
    errlHndl_t l_err = nullptr;
    uint8_t l_data = 0x0;
    uint32_t l_target_timeout_values[6];
    bool l_done = false;

    // Get the timeout value for ops_id
    assert(i_nvdimm->tryGetAttr<TARGETING::ATTR_NV_OPS_TIMEOUT_MSEC>(l_target_timeout_values),
           "nvdimmPollStatus() HUID[%X], failed reading ATTR_NV_OPS_TIMEOUT_MSEC!", TARGETING::get_huid(i_nvdimm));
    uint32_t l_timeout = l_target_timeout_values[i_ops_id];

    do
    {
        nanosleep( 0, OPS_POLL_TIME_MS*NS_PER_MSEC ); //sleep for POLL ms

        l_err = nvdimmReadReg( i_nvdimm,
                               timeoutInfoTable[i_ops_id].status_reg_offset,
                               l_data );
        if(l_err)
        {
            break;
        }

        if((l_data & timeoutInfoTable[i_ops_id].status_progress) !=
            timeoutInfoTable[i_ops_id].status_progress) // Done
        {
            l_done = true;
            break;
        }

        o_poll += OPS_POLL_TIME_MS;

    } while (o_poll < l_timeout);

    if (!l_done && !l_err)
    {

        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmPollStatus() nvdimm[%X] - Status timed out ops_id[%d]",
                  TARGETING::get_huid(i_nvdimm), i_ops_id);
        /*@
         *@errortype
         *@reasoncode       NVDIMM_STATUS_TIMEOUT
         *@severity         ERRORLOG_SEV_PREDICTIVE
         *@moduleid         NVDIMM_POLL_STATUS
         *@userdata1[0:31]  Related ops (0xff = NA)
         *@userdata1[32:63] Target Huid
         *@userdata2[0:31]  Polled value
         *@userdata2[32:63] Timeout value
         *@devdesc          Encountered timeout while performing operation on NVDIMM
         *                   Refer to userdata1 for which operation it timed out.
         *@custdesc         NVDIMM timed out
         */
        l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       NVDIMM_POLL_STATUS,
                                       NVDIMM_STATUS_TIMEOUT,
                                       NVDIMM_SET_USER_DATA_1(i_ops_id, TARGETING::get_huid(i_nvdimm)),
                                       NVDIMM_SET_USER_DATA_2_TIMEOUT(o_poll, l_timeout),
                                       ERRORLOG::ErrlEntry::NO_SW_CALLOUT  );

        l_err->collectTrace(NVDIMM_COMP_NAME, 1024 );

        // May have to move the error handling to the caller
        // as different op could have different error severity
        l_err->addPartCallout( i_nvdimm,
                               HWAS::NV_CONTROLLER_PART_TYPE,
                               HWAS::SRCI_PRIORITY_HIGH);
    }

    return l_err;
}

/**
 * @brief This function polls the command status register for backup/CSAVE
 *        completion (does not indicate success or fail)
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[out] o_poll - total polled time in ms
 *
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmPollBackupDone(Target* i_nvdimm,
                                uint32_t &o_poll)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmPollBackupDone() nvdimm[%X]",
              TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    l_err = nvdimmPollStatus ( i_nvdimm, SAVE, o_poll);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmPollBackupDone() nvdimm[%X]",
              TARGETING::get_huid(i_nvdimm));

    return l_err;
}

/**
 * @brief This function polls the command status register for restore
 *        completion (does not indicate success or fail)
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[out] o_poll - total polled time in ms
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmPollRestoreDone(Target* i_nvdimm,
                                 uint32_t &o_poll)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmPollRestoreDone() nvdimm[%X]",
              TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    l_err = nvdimmPollStatus ( i_nvdimm, RESTORE, o_poll );

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmPollRestoreDone() nvdimm[%X]",
              TARGETING::get_huid(i_nvdimm));

    return l_err;
}

/**
 * @brief This function polls the command status register for erase
 *        completion (does not indicate success or fail)
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[out] o_poll - total polled time in ms
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmPollEraseDone(Target* i_nvdimm,
                               uint32_t &o_poll)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmPollEraseDone() nvdimm[%X]",
              TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    l_err = nvdimmPollStatus ( i_nvdimm, ERASE, o_poll);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmPollEraseDone() nvdimm[%X]",
              TARGETING::get_huid(i_nvdimm));

    return l_err;
}


/**
 * @brief This function polls the command status register for backup power
 *        charge completion (does not indicate success or fail)
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[out] o_poll - total polled time in ms
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmPollESChargeStatus(Target* i_nvdimm,
                                    uint32_t &o_poll)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmPollESChargeDone() nvdimm[%X]",
              TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    l_err = nvdimmPollStatus ( i_nvdimm, CHARGE, o_poll );

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmPollESChargeDone() nvdimm[%X]",
              TARGETING::get_huid(i_nvdimm));

    return l_err;
}

/**
 * @brief This function retrieve the restore status
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[out] o_rstrValid - returned data from the restore status register
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmGetRestoreValid(Target* i_nvdimm, uint8_t & o_rstrValid)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmGetRestoreValid() nvdimm[%X]",
              TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    l_err = nvdimmReadReg(i_nvdimm, RESTORE_STATUS, o_rstrValid);

    if (l_err){
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X], Error getting restore status!",
              TARGETING::get_huid(i_nvdimm));
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmGetRestoreValid() nvdimm[%X], restore_status[%x],",
              TARGETING::get_huid(i_nvdimm), o_rstrValid);

    return l_err;
}

/**
 * @brief This function sets the energy supply policy to device-managed
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmSetESPolicy(Target* i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmSetESPolicy() nvdimm[%X]",
                             TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    uint8_t l_data;

    do
    {

        l_err = nvdimmWriteReg(i_nvdimm, SET_ES_POLICY_CMD, ES_DEV_MANAGE);

        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_NOBKUP);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmSetESPolicy() nvdimm[%X]"
                      "failed to write ES register!",TARGETING::get_huid(i_nvdimm));
            break;
        }

        // Give it a bit of time (100ms) for the status reg to reflect the change
        nanosleep( 0, 100*NS_PER_MSEC );

        // Make sure the set was a success
        l_err = nvdimmReadReg(i_nvdimm, SET_ES_POLICY_STATUS, l_data);

        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_NOBKUP);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmSetESPolicy() nvdimm[%X]"
                      "failed to read ES register!",TARGETING::get_huid(i_nvdimm));
            break;
        }

        if ((l_data & ES_SUCCESS) != ES_SUCCESS)
        {
            TRACFCOMP(g_trac_nvdimm, EXIT_MRK"NDVIMM HUID[%X], nvdimmSetESPolicy() "
                      "failed!",TARGETING::get_huid(i_nvdimm));
            /*@
             *@errortype
             *@reasoncode       NVDIMM_SET_ES_ERROR
             *@severity         ERRORLOG_SEV_PREDICTIVE
             *@moduleid         NVDIMM_SET_ES
             *@userdata1[0:31]  Related ops (0xff = NA)
             *@userdata1[32:63] Target Huid
             *@userdata2        <UNUSED>
             *@devdesc          Encountered error setting the energy source policy
             *                   Make sure the connection between energy source and
             *                   NVDIMM is intact
             *@custdesc         NVDIMM encountered error setting the energy source policy
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           NVDIMM_SET_ES,
                                           NVDIMM_SET_ES_ERROR,
                                           NVDIMM_SET_USER_DATA_1(CHARGE, TARGETING::get_huid(i_nvdimm)),
                                           0x0,
                                           ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace(NVDIMM_COMP_NAME, 1024 );

            // Failure setting the energy source policy could mean error on the
            // battery or even the cabling
            l_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            l_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_CABLE_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
        }
    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"NDVIMM HUID[%X], nvdimmSetESPolicy(),"
              ,TARGETING::get_huid(i_nvdimm));

    return l_err;
}

/**
 * @brief This function arms/disarms the trigger based on i_state
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_state - true to arm, false to disarm
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmChangeArmState(Target *i_nvdimm, bool i_state)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmChangeArmState() nvdimm[%X]",
                        TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    // If i_state is true, arm the nvdimm in conjunction with ATOMIC_SAVE_AND_ERASE
    // feature. A separate erase command is not requred as the image will get erased
    // before backup on the next catastrophic event
    uint8_t l_data = i_state ? ARM_RESETN_AND_ATOMIC_SAVE_AND_ERASE : DISARM_RESETN;

    l_err = nvdimmWriteReg(i_nvdimm, ARM_CMD, l_data);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmChangeArmState() nvdimm[%X] error %s nvdimm!!",
                  TARGETING::get_huid(i_nvdimm), i_state? "arming" : "disarming");
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmChangeArmState() nvdimm[%X]",
                        TARGETING::get_huid(i_nvdimm));
    return l_err;
}

/**
 * @brief This function checks for valid image on the given target
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[out] o_imgValid - return true if the target has a valid image
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmValidImage(Target *i_nvdimm, bool &o_imgValid)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmValidImage(): nvdimm[%X]",
                TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    uint8_t l_data = 0x0;
    o_imgValid = false;

    l_err = nvdimmReadReg(i_nvdimm, CSAVE_INFO, l_data);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmValidImage() nvdimm[%X]"
                  "failed to for image!",TARGETING::get_huid(i_nvdimm) );
    }
    else if(l_data & VALID_IMAGE)
    {
        o_imgValid = true;
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmValidImage(): nvdimm[%X] ret[%X]",
                TARGETING::get_huid(i_nvdimm), l_data);

    return l_err;
}

#ifndef __HOSTBOOT_RUNTIME
/**
 * @brief This function handles all the restore related operations.
 *        SRE -> restore -> SRX/RCD/MRS
 *
 * @param[in] i_nvdimmList - list of nvdimms
 *
 * @param[in] i_mpipl - MPIPL mode
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmRestore(TargetHandleList i_nvdimmList, uint8_t &i_mpipl)
{
    errlHndl_t l_err = nullptr;
    bool l_imgValid;
    uint8_t l_rstrValid;
    uint32_t l_poll = 0;

    do
    {
        // Put NVDIMM into self-refresh
        for (TargetHandleList::iterator it = i_nvdimmList.begin();
             it != i_nvdimmList.end();)
        {
            l_err = nvdimmValidImage(*it, l_imgValid);

            // No reason to run if we can't figure out
            // if there is an image or not
            if (l_err)
            {
                nvdimmSetStatusFlag(*it, NSTD_ERR_NOPRSV);
                break;
            }

            if (!l_imgValid)
            {
                nvdimmSetStatusFlag(*it, NSTD_VAL_NOPRSV);
                i_nvdimmList.erase(it);
                continue;
            }

            TARGETING::TargetHandleList l_mcaList;
            getParentAffinityTargets(l_mcaList, *it, TARGETING::CLASS_UNIT, TARGETING::TYPE_MCA);
            assert(l_mcaList.size(), "nvdimmRestore() failed to find parent MCA.");

/* FIXME RTC:249244
            fapi2::Target<fapi2::TARGET_TYPE_MCA> l_fapi_mca(l_mcaList[0]);
*/

            // Before we do anything, check if we are in mpipl. If we are, make sure ddr_resetn
            // is de-asserted before kicking off the restore
            if (i_mpipl)
            {
/* FIXME RTC:249244
                FAPI_INVOKE_HWP(l_err, mss::ddr_resetn, l_fapi_mca, HIGH);

                if (l_err)
                {
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore() HUID[%X] i_mpipl[%u] failed to de-assert resetn!",
                              TARGETING::get_huid(*it), i_mpipl);

                    nvdimmSetStatusFlag(*it, NSTD_ERR_NOPRSV);
                    //@TODO RTC 199645 - add HW callout on dimm target
                    // If we failed to de-assert reset_n, the dimm is pretty much useless.
                    // Let's not restore if that happens
                    // The callout will be added inside the HWP
                    // Leaving this comment here as a reminder, will remove later
                    break;
                }
*/
            }

/* FIXME RTC:249244
            // Self-refresh is done at the port level
            FAPI_INVOKE_HWP(l_err, mss::nvdimm::self_refresh_entry, l_fapi_mca);

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore() HUID[%X] self_refresh_entry failed!",
                          TARGETING::get_huid(*it));

                nvdimmSetStatusFlag(*it, NSTD_ERR_NOPRSV);
                //@TODO RTC 199645 - add HW callout on dimm target
                // Without SRE the data could be not reliably restored
                // The callout will be added inside the HWP
                // Leaving this comment here as a reminder, will remove later
                break;
            }
*/
            it++;
        }

        if (l_err)
        {
            break;
        }

        // Nothing to do. Move on.
        if (i_nvdimmList.empty())
        {
            break;
        }

        // Kick off the restore on each nvdimm in the nvdimm list
        for (const auto & l_nvdimm : i_nvdimmList)
        {
            l_err = nvdimmWriteReg(l_nvdimm, NVDIMM_FUNC_CMD, RESTORE_IMAGE);
            if (l_err)
            {
                nvdimmSetStatusFlag(l_nvdimm, NSTD_ERR_NOPRSV);
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X], error initiating restore!!",
                          TARGETING::get_huid(l_nvdimm));
                break;
            }
        }

        if (l_err)
        {
            break;
        }

        // Make sure the restore completed
        for (const auto & l_nvdimm : i_nvdimmList)
        {
            // Since we kicked off the restore on all the modules at once, the restore
            // should complete on all of the modules in one restore window. Use the
            // polled time from the previous nvdimm as the offset for the next one.
            l_err = nvdimmPollRestoreDone(l_nvdimm, l_poll);
            if (l_err)
            {
                nvdimmSetStatusFlag(l_nvdimm, NSTD_ERR_NOPRSV);
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X], error restoring!",
                          TARGETING::get_huid(l_nvdimm));
                errlCommit(l_err, NVDIMM_COMP_ID);
                break;
            }
        }

        if (l_err)
        {
            break;
        }

        // Make sure the restore is valid
        for (const auto & l_nvdimm : i_nvdimmList)
        {
            l_err = nvdimmGetRestoreValid(l_nvdimm, l_rstrValid);
            if (l_err)
            {
                nvdimmSetStatusFlag(l_nvdimm, NSTD_ERR_NOPRSV);
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore Target[%X] error validating restore status!",
                          TARGETING::get_huid(l_nvdimm));
                break;
            }

            if ((l_rstrValid & RSTR_SUCCESS) != RSTR_SUCCESS){

                TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X] restoreValid[%d], restore failed!",
                          TARGETING::get_huid(l_nvdimm), l_rstrValid);
                /*@
                 *@errortype
                 *@reasoncode      NVDIMM_RESTORE_FAILED
                 *@severity        ERRORLOG_SEV_UNRECOVERABLE
                 *@moduleid        NVDIMM_RESTORE
                 *@userdata1       Target Huid
                 *@userdata2       <UNUSED>
                 *@devdesc         NVDIMM failed to restore data. This is likely
                 *                  due to failure entering self-refresh and/or
                 *                  restore timeout (Controller error)
                 *@custdesc        NVDIMM failed to restore data
                 */
                l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               NVDIMM_RESTORE,
                                               NVDIMM_RESTORE_FAILED,
                                               TARGETING::get_huid(l_nvdimm),
                                               0x0,
                                               ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

                l_err->collectTrace(NVDIMM_COMP_NAME, 1024 );
                nvdimmSetStatusFlag(l_nvdimm, NSTD_ERR_NOPRSV);

                // Invalid restore could be due to dram not in self-refresh
                // or controller issue. Data should not be trusted at this point
                l_err->addPartCallout( l_nvdimm,
                                       HWAS::NV_CONTROLLER_PART_TYPE,
                                       HWAS::SRCI_PRIORITY_HIGH);
                break;
            }
        }

        if (l_err)
        {
            break;
        }

/* FIXME RTC:249244
        // Exit self-refresh
        for (const auto & l_nvdimm : i_nvdimmList)
        {
            TARGETING::TargetHandleList l_mcaList;
            getParentAffinityTargets(l_mcaList, l_nvdimm, TARGETING::CLASS_UNIT, TARGETING::TYPE_MCA);
            assert(l_mcaList.size(), "nvdimmRestore() failed to find parent MCA.");

            fapi2::Target<fapi2::TARGET_TYPE_MCA> l_fapi_mca(l_mcaList[0]);

            // This is done again at the port level
            // Post restore consists of exiting self-refresh, restoring MRS/RCD, and running ZQCAL
            FAPI_INVOKE_HWP(l_err, mss::nvdimm::post_restore_transition, l_fapi_mca);

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore() HUID[%X] post_restore_transition failed!",
                          TARGETING::get_huid(l_nvdimm));

                // Commit the error from the HWP
                nvdimmSetStatusFlag(l_nvdimm, NSTD_ERR_NOPRSV);
                break;
            }
            else
            {
                // Restore success!
                nvdimmSetStatusFlag(l_nvdimm, NSTD_VAL_PRSV);
            }
        }
*/

    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmRestore() restore completed!!");

    return l_err;
}
#endif

/**
 * @brief This function checks the erase status register to make sure
 *        the last erase completed witout error
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmCheckEraseSuccess(Target *i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmCheckEraseSuccess() : nvdimm[%X]",
                TARGETING::get_huid(i_nvdimm));

    uint8_t l_data = 0;
    errlHndl_t l_err = nullptr;

    l_err = nvdimmReadReg(i_nvdimm, ERASE_STATUS, l_data);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmCheckEraseSuccess() nvdimm[%X]"
                  "failed to read erase status reg!",TARGETING::get_huid(i_nvdimm));
    }
    else if ((l_data & ERASE_SUCCESS) != ERASE_SUCCESS)
    {

        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmCheckEraseSuccess() nvdimm[%X]"
                                 "failed to erase!",TARGETING::get_huid(i_nvdimm));
        /*@
         *@errortype
         *@reasoncode       NVDIMM_ERASE_FAILED
         *@severity         ERRORLOG_SEV_PREDICTIVE
         *@moduleid         NVDIMM_CHECK_ERASE
         *@userdata1[0:31]  Related ops (0xff = NA)
         *@userdata1[32:63] Target Huid
         *@userdata2        <UNUSED>
         *@devdesc          Encountered error erasing previously stored data image
         *                   on NVDIMM. Likely due to timeout and/or controller error
         *@custdesc         NVDIMM error erasing data image
         */
        l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       NVDIMM_CHECK_ERASE,
                                       NVDIMM_ERASE_FAILED,
                                       NVDIMM_SET_USER_DATA_1(ERASE, TARGETING::get_huid(i_nvdimm)),
                                       0x0,
                                       ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

        l_err->collectTrace(NVDIMM_COMP_NAME, 1024 );
        errlCommit( l_err, NVDIMM_COMP_ID );

        // Failure to erase could mean internal NV controller error and/or
        // HW error on nand flash. NVDIMM will lose persistency if failed to
        // erase nand flash
        l_err->addPartCallout( i_nvdimm,
                               HWAS::NV_CONTROLLER_PART_TYPE,
                               HWAS::SRCI_PRIORITY_HIGH);
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmCheckEraseSuccess(): nvdimm[%X] ret[%X]",
                TARGETING::get_huid(i_nvdimm), l_data);

    return l_err;
}

/**
 * @brief This function erases image on the nvdimm target
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmEraseNF(Target *i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmEraseNF() nvdimm[%X]",
                        TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    do
    {
        l_err = nvdimmWriteReg(i_nvdimm, NVDIMM_FUNC_CMD, ERASE_IMAGE);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X] error initiating erase!!",
                      TARGETING::get_huid(i_nvdimm));
            break;
        }

        // Erase happens one module at a time. No need to set any offset on the counter
        uint32_t l_poll = 0;
        l_err = nvdimmPollEraseDone(i_nvdimm, l_poll);
        if (!l_err)
        {
            l_err = nvdimmCheckEraseSuccess(i_nvdimm);
        }

    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmEraseNF() nvdimm[%X]",
                         TARGETING::get_huid(i_nvdimm));

    return l_err;
}

/**
 * @brief This functions opens the NV controller to the specified page
 *        Refer to the BAEBI to see what each page does
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_page - page number to open to
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *                      the error log
 */
errlHndl_t nvdimmOpenPage(Target *i_nvdimm,
                          uint8_t i_page)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmOpenPage nvdimm[%X]", TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    bool l_success = false;
    uint8_t l_data;
    uint32_t l_poll = 0;
    uint32_t l_target_timeout_values[6];
    assert(i_nvdimm->tryGetAttr<TARGETING::ATTR_NV_OPS_TIMEOUT_MSEC>(l_target_timeout_values),
           "nvdimmOpenPage() HUID[%X], failed reading ATTR_NV_OPS_TIMEOUT_MSEC!", TARGETING::get_huid(i_nvdimm));

    uint32_t l_timeout = l_target_timeout_values[PAGE_SWITCH];

    do
    {

        // Open page reg is at the same address of every page
        l_err = nvdimmWriteReg(i_nvdimm, OPEN_PAGE, i_page, NO_PAGE_VERIFY);

        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmOpenPage nvdimm[%X]"
                      "error writing to page change reg", TARGETING::get_huid(i_nvdimm));
            break;
        }

        // This should not take long, but putting a loop here anyway
        // to make sure it finished within time
        // Not using the nvdimmPollStatus since this is polled differently
        do
        {
            l_err = nvdimmReadReg(i_nvdimm, OPEN_PAGE, l_data, NO_PAGE_VERIFY);
            if (l_err){
                break;
            }

            if (l_data == i_page){
                l_success = true;
                break;
            }

            nanosleep(0, PAGE_SWITCH_POLL_TIME_NS);
            l_poll += PAGE_SWITCH_POLL_TIME_NS;

        }while (l_poll < l_timeout*NS_PER_MSEC);

        if (l_err)
        {
            break;
        }

        //timed out
        if (!l_success && !l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmOpenPage nvdimm[%X] openpage_success[%d],"
                      "failure to open page!", TARGETING::get_huid(i_nvdimm), static_cast<uint8_t>(l_success));

            /*@
             *@errortype
             *@reasoncode       NVDIMM_OPEN_PAGE_TIMEOUT
             *@severity         ERRORLOG_SEV_UNRECOVERABLE
             *@moduleid         NVDIMM_OPEN_PAGE
             *@userdata1[0:31]  Related ops (0xff = NA)
             *@userdata1[32:63] Target Huid
             *@userdata2[0:31]  Polled value
             *@userdata2[32:63] Timeout value
             *@devdesc          NVDIMM OpenPage timed out, likely due to controller error
             *@custdesc         Encountered error performing internal operaiton
             *                   on NVDIMM
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           NVDIMM_POLL_STATUS,
                                           NVDIMM_STATUS_TIMEOUT,
                                           NVDIMM_SET_USER_DATA_1(PAGE_SWITCH, TARGETING::get_huid(i_nvdimm)),
                                           NVDIMM_SET_USER_DATA_2_TIMEOUT(l_poll, l_timeout),
                                           ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace(NVDIMM_COMP_NAME, 256 );

            // Failure to open page most likely means problem with
            // the NV controller.
            l_err->addPartCallout( i_nvdimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
        }
    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmOpenPage nvdimm[%X] nvdimmOpenPage.success[%d],"
                ,TARGETING::get_huid(i_nvdimm), static_cast<uint8_t>(l_success));

    return l_err;
}

/**
 * @brief This function gets the timeout values and fill out
 *        ATTR_NV_OPS_TIMEOUT_MSEC for nvdimm
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmGetTimeoutVal(Target* i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmGetTimeoutVal() HUID[%X]"
                ,TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    uint8_t l_data = 0;
    uint32_t timeout_map[6];
    i_nvdimm->tryGetAttr<TARGETING::ATTR_NV_OPS_TIMEOUT_MSEC>(timeout_map);

    //Get the 6 main timeout values
    for (uint8_t i = SAVE; i <= CHARGE; i++)
    {
        // Need to loop thru both offsets to get the full timeout value
        // The first offset contains the MSByte of the timeout value
        // with the MSB indicating ms or sec
        // The second offset contains the LSByte of the value
        for (uint8_t j = 0; j < NUM_OFFSET; j++){

            timeout_map[i] = timeout_map[i] << 8;

            l_err = nvdimmReadReg(i_nvdimm, timeoutInfoTable[i].offset[j], l_data);

            if (l_err)
            {
                break;
            }

            timeout_map[i] = timeout_map[i] | static_cast<uint32_t>(l_data);

        }

        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmGetTimeoutVal() HUID[%X] "
                      "error reading timeout value for op[%d]!", TARGETING::get_huid(i_nvdimm), i);
            break;
        }

        //Converting to msec depending on bit 15. 1 = sec, 0 = msec
        //except for charge. Charge is only in seconds so convert anyway
        if (timeout_map[i] >= 0x8000 || i == CHARGE){
            timeout_map[i] = timeout_map[i] & 0x7FFF;
            timeout_map[i] = timeout_map[i] * MS_PER_SEC;
        }

        TRACUCOMP(g_trac_nvdimm, "nvdimmGetTimeoutVal() HUID[%X], timeout_idx[%d], timeout_ms[%d]"
                ,TARGETING::get_huid(i_nvdimm), timeoutInfoTable[i].idx, timeout_map[i]);
    }

    if (!l_err)
    {
        i_nvdimm->setAttr<TARGETING::ATTR_NV_OPS_TIMEOUT_MSEC>(timeout_map);
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmGetTimeoutVal() HUID[%X]"
                ,TARGETING::get_huid(i_nvdimm));

    return l_err;
}

#ifndef __HOSTBOOT_RUNTIME

/**
 * @brief Call the HWP to pre-load the epow sequence into CCS
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 */
errlHndl_t nvdimmEpowSetup(TargetHandleList &i_nvdimmList)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmEpowSetup()");

    errlHndl_t l_err = nullptr;
/* FIXME RTC:249244
    do
    {
        // Loop through each target
        for (TargetHandleList::iterator it = i_nvdimmList.begin();
             it != i_nvdimmList.end();)
        {
            TARGETING::TargetHandleList l_mcaList;
            getParentAffinityTargets(l_mcaList, *it, TARGETING::CLASS_UNIT, TARGETING::TYPE_MCA);
            assert(l_mcaList.size(), "nvdimmEpowSetup() failed to find parent MCA.");

            fapi2::Target<fapi2::TARGET_TYPE_MCA> l_fapi_mca(l_mcaList[0]);

            // Loads CCS with the EPOW sequence. This basically does bunch of scoms to
            // CCS array
            FAPI_INVOKE_HWP(l_err, mss::nvdimm::preload_epow_sequence, l_fapi_mca);

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmEpowSetup() HUID[%X] failed to setup epow!",
                          TARGETING::get_huid(*it));

                nvdimmSetStatusFlag(*it, NSTD_ERR_NOPRSV);
                break;
            }
            it++;
        }

    }while(0);
*/
    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmEpowSetup()");
    return l_err;
}

/**
 * @brief Entry function to NVDIMM restore
 *        - Restore image from NVDIMM NAND flash to DRAM
 *        - Set up the ES policy
 *
 * @param[in] i_nvdimmList - list of nvdimm targets
 *
 */
void nvdimm_restore(TargetHandleList &i_nvdimmList)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_restore()");
    errlHndl_t l_err = nullptr;
    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget( l_sys );
    assert(l_sys, "nvdimm_restore: no TopLevelTarget");
    uint8_t l_mpipl = l_sys->getAttr<ATTR_IS_MPIPL_HB>();

    do
    {
        // Set the energy policy to device-managed
        // Don't think this is needed for the supercaps to start charging
        // but do it anyway to get the charging going
        for (const auto & l_nvdimm : i_nvdimmList)
        {
            l_err = nvdimmSetESPolicy(l_nvdimm);
            if (l_err)
            {
                // Failing this is an indication of power pack issue.
                // This will prevent future backup, but let's continue
                // since we can still restore the data if there is any
                nvdimmSetStatusFlag(l_nvdimm, NSTD_ERR_NOBKUP);
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_restore() - Failing nvdimmSetESPolicy()");
                errlCommit( l_err, NVDIMM_COMP_ID );
            }
        }

        if (l_mpipl)
        {
            // During MPIPL, make sure any in-progress save is completed before proceeding
            uint32_t l_poll = 0;
            for (const auto & l_nvdimm : i_nvdimmList)
            {
                //Check save progress
                l_err = nvdimmPollBackupDone(l_nvdimm, l_poll);

                if (l_err)
                {
                    nvdimmSetStatusFlag(l_nvdimm, NSTD_ERR_NOPRSV);
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_restore() nvdimm[%X], error backing up the DRAM!",
                              TARGETING::get_huid(l_nvdimm));
                    errlCommit(l_err, NVDIMM_COMP_ID);
                    break;
                }
            }
        }

        // Start the restore
        l_err = nvdimmRestore(i_nvdimmList, l_mpipl);

        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_restore() - Failing nvdimmRestore()");
            errlCommit( l_err, NVDIMM_COMP_ID );
            break;
        }

        // Make sure the energy source is fully charged before erasing the images
        // Doing this on all the nvdimms since the ones w/o image will need
        // to be fully charged before arming the trigger
        uint32_t l_poll = 0;
        for (const auto & l_nvdimm : i_nvdimmList)
        {
            l_err = nvdimmPollESChargeStatus(l_nvdimm, l_poll);

            if (l_err){
                nvdimmSetStatusFlag(l_nvdimm, NSTD_ERR_NOBKUP);
                errlCommit( l_err, NVDIMM_COMP_ID );
            }
        }

    }while(0);

    // At the end, pre-load CCS with commands for EPOW. This will stage the CCS
    // with the require commands to trigger the save on NVDIMMs. The actual
    // triggering will be done by OCC when EPOW is detected.
    l_err = nvdimmEpowSetup(i_nvdimmList);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_restore() - Failing nvdimmEpowSetup()");
        errlCommit( l_err, NVDIMM_COMP_ID );
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_restore()");
}

/**
 * @brief NVDIMM initialization
 *        - Checks for ready state
 *        - Gathers timeout values
 *        - Waits for the ongoing backup to complete
 *        - Disarms the trigger for draminit
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 */
void nvdimm_init(Target *i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_init() nvdimm[%X]",
                TARGETING::get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    do
    {
        l_err = nvdimmReady(i_nvdimm);

        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_int() nvdimm[%X], controller not ready",
                      TARGETING::get_huid(i_nvdimm));
            errlCommit(l_err, NVDIMM_COMP_ID);
            break;
        }

        // Get the timeout values for the major ops at init
        l_err = nvdimmGetTimeoutVal(i_nvdimm);
        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_int() nvdimm[%X], error retrieving timeout values",
                      TARGETING::get_huid(i_nvdimm));
            errlCommit(l_err, NVDIMM_COMP_ID);
            break;
        }

        //Check save progress
        uint32_t l_poll = 0;
        l_err = nvdimmPollBackupDone(i_nvdimm, l_poll);

        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_NOPRSV);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_int() nvdimm[%X], error backing up the DRAM!",
                      TARGETING::get_huid(i_nvdimm));
            errlCommit(l_err, NVDIMM_COMP_ID);
            break;
        }

        // Disarm the ddr_resetn here in case it came in armed. When the nvdimm is
        // armed the reset_n is masked off from the host, meaning the drams won't
        // be able to get reset properly later, causing training to fail.
        l_err = nvdimmChangeArmState(i_nvdimm, DISARM_TRIGGER);

        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_NOPRSV);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], error disarming the nvdimm!",
                      TARGETING::get_huid(i_nvdimm));
            errlCommit(l_err, NVDIMM_COMP_ID);
            break;
        }

    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_init() nvdimm[%X]",
                TARGETING::get_huid(i_nvdimm));
}
#endif

} // end NVDIMM namespace
