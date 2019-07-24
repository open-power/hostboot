/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimm.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2019                        */
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
#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/ccs/ccs_nimbus.H>
#include <lib/dimm/ddr4/nvdimm_utils.H>
#include <lib/mc/port.H>
#include <isteps/nvdimm/nvdimmreasoncodes.H>
#include <isteps/nvdimm/nvdimm.H>
#include <vpd/spdenums.H>
#include <secureboot/trustedbootif.H>
#include <targeting/common/targetUtil.H>
#ifdef __HOSTBOOT_RUNTIME
#include <runtime/hbrt_utilities.H>
#include <usr/runtime/rt_targeting.H>
#else
#include <initservice/istepdispatcherif.H>
#endif

using namespace TARGETING;
using namespace DeviceFW;
using namespace EEPROM;

trace_desc_t* g_trac_nvdimm = NULL;
TRAC_INIT(&g_trac_nvdimm, NVDIMM_COMP_NAME, 2*KILOBYTE);

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


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

// Definition of ENCRYPTION_CONFIG_STATUS -- page 5 offset 0x20
typedef union {
    uint8_t whole;
    struct
    {
        uint8_t reserved : 1;               // [7]
        uint8_t unsupported_field : 1;      // [6]
        uint8_t erase_pending : 1;          // [5]
        uint8_t encryption_unlocked : 1;    // [4]
        uint8_t encryption_enabled : 1;     // [3]
        uint8_t erase_key_present : 1;      // [2]
        uint8_t random_string_present : 1;  // [1]
        uint8_t encryption_supported : 1;   // [0]
    } PACKED;
} encryption_config_status_t;

// Valid bits to check against (skips reserved and unsupported)
static constexpr uint8_t ENCRYPTION_STATUS_CHECK_MASK = 0x3F;
static constexpr uint8_t ENCRYPTION_STATUS_DISABLED = 0x01;
static constexpr uint8_t ENCRYPTION_STATUS_ENABLED = 0x1F;

// NV_STATUS masks
static constexpr uint8_t NV_STATUS_OR_MASK = 0xFB;
static constexpr uint8_t NV_STATUS_AND_MASK = 0x04;
static constexpr uint8_t NV_STATUS_UNPROTECTED_SET   = 0x01;
static constexpr uint8_t NV_STATUS_UNPROTECTED_CLEAR = 0xFE;
static constexpr uint8_t NV_STATUS_POSSIBLY_UNPROTECTED_SET   = 0x40;
static constexpr uint8_t NV_STATUS_POSSIBLY_UNPROTECTED_CLEAR = 0xBF;

// NVDIMM key consts
static constexpr size_t NUM_KEYS_IN_ATTR = 3;
static constexpr size_t MAX_TPM_SIZE = 34;
static constexpr uint8_t KEY_TERMINATE_BYTE = 0x00;
static constexpr uint8_t KEY_ABORT_BYTE = 0xFF;

// Definition of ENCRYPTION_KEY_VALIDATION -- page 5 offset 0x2A
typedef union {
    uint8_t whole;
    struct
    {
        uint8_t reserved : 5;               // [7:3]
        uint8_t keys_validated : 1;         // [2]
        uint8_t access_key_valid : 1;       // [1]
        uint8_t erase_key_valid : 1;        // [0]
    } PACKED;
} encryption_key_validation_t;

/**
 * @brief Utility function to send the value of
 *   ATTR_NVDIMM_ARMED to the FSP
 */
void send_ATTR_NVDIMM_ARMED( Target* i_nvdimm,
                             ATTR_NVDIMM_ARMED_type& i_val );

/**
 * @brief Utility function to set ATTR_NVDIMM_ENCRYPTION_KEYS_FW
 *        and send the value to the FSP
 */
void set_ATTR_NVDIMM_ENCRYPTION_KEYS_FW(
            ATTR_NVDIMM_ENCRYPTION_KEYS_FW_typeStdArr& i_val )
{
    Target* l_sys = nullptr;
    targetService().getTopLevelTarget( l_sys );
    assert(l_sys, "set_ATTR_NVDIMM_ENCRYPTION_KEYS_FW: no TopLevelTarget");

    l_sys->setAttrFromStdArr
      <ATTR_NVDIMM_ENCRYPTION_KEYS_FW>(i_val);

#ifdef __HOSTBOOT_RUNTIME
    errlHndl_t l_err = nullptr;

    // Send attr to HWSV if at runtime
    AttributeTank::Attribute l_attr = {};
    if( !makeAttributeStdArr<ATTR_NVDIMM_ENCRYPTION_KEYS_FW>
        (l_sys, l_attr) )
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"set_ATTR_NVDIMM_ENCRYPTION_KEYS_FW() Could not create Attribute");
        /*@
         *@errortype
         *@reasoncode       NVDIMM_CANNOT_MAKE_ATTRIBUTE
         *@severity         ERRORLOG_SEV_PREDICTIVE
         *@moduleid         SET_ATTR_NVDIMM_ENCRYPTION_KEYS_FW
         *@devdesc          Couldn't create an Attribute to send the data
         *                  to the FSP
         *@custdesc         NVDIMM encryption error
         */
        l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_PREDICTIVE,
                            SET_ATTR_NVDIMM_ENCRYPTION_KEYS_FW,
                            NVDIMM_CANNOT_MAKE_ATTRIBUTE,
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
        l_err->collectTrace(NVDIMM_COMP_NAME);
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    else
    {
        std::vector<TARGETING::AttributeTank::Attribute> l_attrList;
        l_attrList.push_back(l_attr);
        l_err = sendAttributes( l_attrList );
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"set_ATTR_NVDIMM_ENCRYPTION_KEYS_FW() Error sending ATTR_NVDIMM_ENCRYPTION_KEYS_FW down to FSP");
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit( l_err, NVDIMM_COMP_ID );
        }
    }
#endif //__HOSTBOOT_RUNTIME

}

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
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"NVDIMM Read HUID 0x%X, addr 0x%X",
              get_huid(i_nvdimm), i_addr);

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
                          get_huid(i_nvdimm));
                break;
            }

            if (l_data != l_reg_page)
            {
                l_err = nvdimmOpenPage(i_nvdimm, l_reg_page);

                if (l_err)
                {
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmReadReg() nvdimm[%X] - failed to verify page",
                              get_huid(i_nvdimm));
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

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"NVDIMM Read HUID 0x%X, page 0x%X, addr 0x%X = 0x%X",
              get_huid(i_nvdimm), l_reg_page, l_reg_addr, o_data);

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
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"NVDIMM Write HUID 0x%X, addr 0x%X = 0x%X",
              get_huid(i_nvdimm), i_addr, i_data);

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
                          get_huid(i_nvdimm));
                break;
            }

            if (l_data != l_reg_page)
            {
                l_err = nvdimmOpenPage(i_nvdimm, l_reg_page);

                if (l_err)
                {
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmWriteReg() nvdimm[%X] - failed to verify page",
                              get_huid(i_nvdimm));
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

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"NVDIMM Write HUID 0x%X, page = 0x%X, addr 0x%X = 0x%X",
              get_huid(i_nvdimm), l_reg_page, l_reg_addr, i_data);

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
                ,get_huid(i_nvdimm), i_status_flag);

    auto l_statusFlag = i_nvdimm->getAttr<ATTR_NV_STATUS_FLAG>();

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
                   get_huid(i_nvdimm), i_status_flag);
            break;
    }

    i_nvdimm->setAttr<ATTR_NV_STATUS_FLAG>(l_statusFlag);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmSetStatusFlag() HUID[%X], i_status_flag[%X]"
                ,get_huid(i_nvdimm), i_status_flag);
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
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmReady() HUID[%X]",get_huid(i_nvdimm));

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
                  get_huid(i_nvdimm), l_nvm_init_time);

        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmReady() nvdimm[%X] - failed to retrieve NVM_INIT_TIME from SPD",
                      get_huid(i_nvdimm));
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
                          get_huid(i_nvdimm), l_data);
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
                      get_huid(i_nvdimm), l_data);
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
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        NVDIMM_CHECK_READY,
                        NVDIMM_NOT_READY,
                        NVDIMM_SET_USER_DATA_1(l_data, get_huid(i_nvdimm)),
                        0x0,
                        ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace(NVDIMM_COMP_NAME);

            // If nvdimm is not ready for access by now, this is
            // a failing indication on the NV controller
            l_err->addPartCallout( i_nvdimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
        }

    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmReady() HUID[%X] ready[%X]",
              get_huid(i_nvdimm), l_data);

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
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmResetController() HUID[%X]",get_huid(i_nvdimm));
    errlHndl_t l_err = nullptr;

    do
    {

        l_err = nvdimmWriteReg(i_nvdimm, NVDIMM_MGT_CMD0, RESET_CONTROLLER);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmResetController() nvdimm[%X] - error reseting the controller",
                      get_huid(i_nvdimm));
            break;
        }

        l_err = nvdimmReady(i_nvdimm);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmResetController() nvdimm[%X] - not ready after reset.",
                      get_huid(i_nvdimm));
        }

    }while(0);

    // Reset will lock encryption so unlock again
    TargetHandleList l_nvdimmTargetList;
    l_nvdimmTargetList.push_back(i_nvdimm);
    nvdimm_encrypt_unlock(l_nvdimmTargetList);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmResetController() HUID[%X]",get_huid(i_nvdimm));

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
    assert(i_nvdimm->tryGetAttr<ATTR_NV_OPS_TIMEOUT_MSEC>(l_target_timeout_values),
           "nvdimmPollStatus() HUID[%X], failed reading ATTR_NV_OPS_TIMEOUT_MSEC!", get_huid(i_nvdimm));
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

    } while (o_poll <= l_timeout);

    if (!l_done && !l_err)
    {

        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmPollStatus() nvdimm[%X] - Status timed out ops_id[%d]",
                  get_huid(i_nvdimm), i_ops_id);
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
        l_err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                    NVDIMM_POLL_STATUS,
                    NVDIMM_STATUS_TIMEOUT,
                    NVDIMM_SET_USER_DATA_1(i_ops_id, get_huid(i_nvdimm)),
                    NVDIMM_SET_USER_DATA_2_TIMEOUT(o_poll, l_timeout),
                    ERRORLOG::ErrlEntry::NO_SW_CALLOUT  );

        l_err->collectTrace(NVDIMM_COMP_NAME);

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
              get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    l_err = nvdimmPollStatus ( i_nvdimm, SAVE, o_poll);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmPollBackupDone() nvdimm[%X]",
              get_huid(i_nvdimm));

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
              get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    l_err = nvdimmPollStatus ( i_nvdimm, RESTORE, o_poll );

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmPollRestoreDone() nvdimm[%X]",
              get_huid(i_nvdimm));

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
              get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    l_err = nvdimmPollStatus ( i_nvdimm, ERASE, o_poll);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmPollEraseDone() nvdimm[%X]",
              get_huid(i_nvdimm));

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
              get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    l_err = nvdimmPollStatus ( i_nvdimm, CHARGE, o_poll );

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmPollESChargeDone() nvdimm[%X]",
              get_huid(i_nvdimm));

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
              get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    l_err = nvdimmReadReg(i_nvdimm, RESTORE_STATUS, o_rstrValid);

    if (l_err){
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X], Error getting restore status!",
                  get_huid(i_nvdimm));
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmGetRestoreValid() nvdimm[%X], restore_status[%x],",
              get_huid(i_nvdimm), o_rstrValid);

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
                             get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    uint8_t l_data;

    do
    {

        l_err = nvdimmWriteReg(i_nvdimm, SET_ES_POLICY_CMD, ES_DEV_MANAGE);

        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_NOBKUP);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmSetESPolicy() nvdimm[%X]"
                      "failed to write ES register!",get_huid(i_nvdimm));
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
                      "failed to read ES register!",get_huid(i_nvdimm));
            break;
        }

        if ((l_data & ES_SUCCESS) != ES_SUCCESS)
        {
            TRACFCOMP(g_trac_nvdimm, EXIT_MRK"NDVIMM HUID[%X], nvdimmSetESPolicy() "
                      "failed!",get_huid(i_nvdimm));
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
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                        NVDIMM_SET_ES,
                        NVDIMM_SET_ES_ERROR,
                        NVDIMM_SET_USER_DATA_1(CHARGE, get_huid(i_nvdimm)),
                        0x0,
                        ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace(NVDIMM_COMP_NAME);

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
              ,get_huid(i_nvdimm));

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
              get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    // If i_state is true, arm the nvdimm in conjunction with ATOMIC_SAVE_AND_ERASE
    // feature. A separate erase command is not requred as the image will get erased
    // before backup on the next catastrophic event
    uint8_t l_data = i_state ? ARM_RESETN_AND_ATOMIC_SAVE_AND_ERASE : DISARM_RESETN;

    l_err = nvdimmWriteReg(i_nvdimm, ARM_CMD, l_data);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmChangeArmState() nvdimm[%X] error %s nvdimm!!",
                  get_huid(i_nvdimm), i_state? "arming" : "disarming");
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmChangeArmState() nvdimm[%X]",
              get_huid(i_nvdimm));
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
              get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    uint8_t l_data = 0x0;
    o_imgValid = false;

    l_err = nvdimmReadReg(i_nvdimm, CSAVE_INFO, l_data);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmValidImage() nvdimm[%X]"
                  "failed to for image!",get_huid(i_nvdimm) );
    }
    else if(l_data & VALID_IMAGE)
    {
        o_imgValid = true;
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmValidImage(): nvdimm[%X] ret[%X]",
              get_huid(i_nvdimm), l_data);

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
            // Default state during boot is unarmed, therefore not preserved
            nvdimmSetStatusFlag(*it, NSTD_ERR_NOBKUP);

            l_err = nvdimmValidImage(*it, l_imgValid);

            // No reason to run if we can't figure out
            // if there is an image or not
            if (l_err)
            {
                break;
            }

            if (!l_imgValid)
            {
                nvdimmSetStatusFlag(*it, NSTD_VAL_NOPRSV);
                i_nvdimmList.erase(it);
                continue;
            }

            TargetHandleList l_mcaList;
            getParentAffinityTargets(l_mcaList, *it, CLASS_UNIT, TYPE_MCA);
            assert(l_mcaList.size(), "nvdimmRestore() failed to find parent MCA.");

            fapi2::Target<fapi2::TARGET_TYPE_MCA> l_fapi_mca(l_mcaList[0]);

            // Before we do anything, check if we are in mpipl. If we are, make sure ddr_resetn
            // is de-asserted before kicking off the restore
            if (i_mpipl)
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimmRestore(): in MPIPL");
                FAPI_INVOKE_HWP(l_err, mss::ddr_resetn, l_fapi_mca, HIGH);

                if (l_err)
                {
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore() HUID[%X] i_mpipl[%u] failed to de-assert resetn!",
                              get_huid(*it), i_mpipl);

                    nvdimmSetStatusFlag(*it, NSTD_ERR_NOPRSV);
                    //@TODO RTC 199645 - add HW callout on dimm target
                    // If we failed to de-assert reset_n, the dimm is pretty much useless.
                    // Let's not restore if that happens
                    // The callout will be added inside the HWP
                    // Leaving this comment here as a reminder, will remove later
                    break;
                }

                // In MPIPL, invalidate the BAR to prevent any traffic from stepping on
                // the restore
                FAPI_INVOKE_HWP(l_err, mss::nvdimm::change_bar_valid_state, l_fapi_mca, LOW);

                // This should not fail at all (scom read/write). If it does, post an informational log
                // to leave some breadcrumbs
                if (l_err)
                {
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore() HUID[%X] i_mpipl[%u] failed to invalidate BAR!",
                              get_huid(*it), i_mpipl);

                    l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    l_err->collectTrace(NVDIMM_COMP_NAME, 256);
                    ERRORLOG::errlCommit(l_err, NVDIMM_COMP_ID);
                }

            }

            // Self-refresh is done at the port level
            FAPI_INVOKE_HWP(l_err, mss::nvdimm::self_refresh_entry, l_fapi_mca);

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore() HUID[%X] self_refresh_entry failed!",
                          get_huid(*it));

                nvdimmSetStatusFlag(*it, NSTD_ERR_NOPRSV);
                //@TODO RTC 199645 - add HW callout on dimm target
                // Without SRE the data could be not reliably restored
                // The callout will be added inside the HWP
                // Leaving this comment here as a reminder, will remove later
                break;
            }
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
                          get_huid(l_nvdimm));
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
                          get_huid(l_nvdimm));
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
                          get_huid(l_nvdimm));
                break;
            }

            if ((l_rstrValid & RSTR_SUCCESS) != RSTR_SUCCESS){

                TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X] restoreValid[%d], restore failed!",
                          get_huid(l_nvdimm), l_rstrValid);
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
                l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            NVDIMM_RESTORE,
                            NVDIMM_RESTORE_FAILED,
                            get_huid(l_nvdimm),
                            0x0,
                            ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

                l_err->collectTrace(NVDIMM_COMP_NAME);
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

        // Exit self-refresh
        for (const auto & l_nvdimm : i_nvdimmList)
        {

            TargetHandleList l_mcaList;
            getParentAffinityTargets(l_mcaList, l_nvdimm, CLASS_UNIT, TYPE_MCA);
            assert(l_mcaList.size(), "nvdimmRestore() failed to find parent MCA.");

            fapi2::Target<fapi2::TARGET_TYPE_MCA> l_fapi_mca(l_mcaList[0]);

            // This is done again at the port level
            // Post restore consists of exiting self-refresh, restoring MRS/RCD, and running ZQCAL
            FAPI_INVOKE_HWP(l_err, mss::nvdimm::post_restore_transition, l_fapi_mca);

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore() HUID[%X] post_restore_transition failed!",
                          get_huid(l_nvdimm));

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

        if (i_mpipl)
        {
            for (const auto & l_nvdimm : i_nvdimmList)
            {
                TargetHandleList l_mcaList;
                errlHndl_t err = nullptr;
                getParentAffinityTargets(l_mcaList, l_nvdimm, CLASS_UNIT, TYPE_MCA);
                assert(l_mcaList.size(), "nvdimmRestore() failed to find parent MCA.");

                // Re-validate the BAR after restore
                fapi2::Target<fapi2::TARGET_TYPE_MCA> l_fapi_mca(l_mcaList[0]);
                FAPI_INVOKE_HWP(err, mss::nvdimm::change_bar_valid_state, l_fapi_mca, HIGH);

                // This should not fail at all (scom read/write). If it does, post an informational log
                // to leave some breadcrumbs
                if (err)
                {
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore() HUID[%X] i_mpipl[%u] failed to invalidate BAR!",
                              get_huid(l_nvdimm), i_mpipl);

                    err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    err->collectTrace(NVDIMM_COMP_NAME, 256);
                    ERRORLOG::errlCommit(err, NVDIMM_COMP_ID);
                }
            }
        }

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
              get_huid(i_nvdimm));

    uint8_t l_data = 0;
    errlHndl_t l_err = nullptr;

    l_err = nvdimmReadReg(i_nvdimm, ERASE_STATUS, l_data);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmCheckEraseSuccess() nvdimm[%X]"
                  "failed to read erase status reg!",get_huid(i_nvdimm));
    }
    else if ((l_data & ERASE_SUCCESS) != ERASE_SUCCESS)
    {

        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmCheckEraseSuccess() nvdimm[%X]"
                                 "failed to erase!",get_huid(i_nvdimm));
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
        l_err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                    NVDIMM_CHECK_ERASE,
                    NVDIMM_ERASE_FAILED,
                    NVDIMM_SET_USER_DATA_1(ERASE, get_huid(i_nvdimm)),
                    0x0,
                    ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

        l_err->collectTrace(NVDIMM_COMP_NAME);
        errlCommit( l_err, NVDIMM_COMP_ID );

        // Failure to erase could mean internal NV controller error and/or
        // HW error on nand flash. NVDIMM will lose persistency if failed to
        // erase nand flash
        l_err->addPartCallout( i_nvdimm,
                               HWAS::NV_CONTROLLER_PART_TYPE,
                               HWAS::SRCI_PRIORITY_HIGH);
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmCheckEraseSuccess(): nvdimm[%X] ret[%X]",
              get_huid(i_nvdimm), l_data);

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
              get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    do
    {
        l_err = nvdimmWriteReg(i_nvdimm, NVDIMM_FUNC_CMD, ERASE_IMAGE);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X] error initiating erase!!",
                      get_huid(i_nvdimm));
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
              get_huid(i_nvdimm));

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
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmOpenPage nvdimm[%X]", get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    bool l_success = false;
    uint8_t l_data;
    uint32_t l_poll = 0;
    uint32_t l_target_timeout_values[6];
    assert(i_nvdimm->tryGetAttr<ATTR_NV_OPS_TIMEOUT_MSEC>(l_target_timeout_values),
           "nvdimmOpenPage() HUID[%X], failed reading ATTR_NV_OPS_TIMEOUT_MSEC!", get_huid(i_nvdimm));

    uint32_t l_timeout = l_target_timeout_values[PAGE_SWITCH];

    do
    {

        // Open page reg is at the same address of every page
        l_err = nvdimmWriteReg(i_nvdimm, OPEN_PAGE, i_page, NO_PAGE_VERIFY);

        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmOpenPage nvdimm[%X]"
                      "error writing to page change reg", get_huid(i_nvdimm));
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
                      "failure to open page!", get_huid(i_nvdimm), static_cast<uint8_t>(l_success));

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
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        NVDIMM_OPEN_PAGE,
                        NVDIMM_OPEN_PAGE_TIMEOUT,
                        NVDIMM_SET_USER_DATA_1(PAGE_SWITCH, get_huid(i_nvdimm)),
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
                ,get_huid(i_nvdimm), static_cast<uint8_t>(l_success));

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
                ,get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    uint8_t l_data = 0;
    uint32_t timeout_map[6];
    i_nvdimm->tryGetAttr<ATTR_NV_OPS_TIMEOUT_MSEC>(timeout_map);

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
                      "error reading timeout value for op[%d]!", get_huid(i_nvdimm), i);
            break;
        }

        //Converting to msec depending on bit 15. 1 = sec, 0 = msec
        //except for charge. Charge is only in seconds so convert anyway
        //Double the timeout values for margins
        if (timeout_map[i] >= 0x8000 || i == CHARGE){
            timeout_map[i] = timeout_map[i] & 0x7FFF;
            timeout_map[i] = timeout_map[i] * MS_PER_SEC * 2;
        }
        else
        {
            timeout_map[i] = timeout_map[i] * 2;
        }

        TRACUCOMP(g_trac_nvdimm, "nvdimmGetTimeoutVal() HUID[%X], timeout_idx[%d], timeout_ms[%d]"
                ,get_huid(i_nvdimm), timeoutInfoTable[i].idx, timeout_map[i]);
    }

    if (!l_err)
    {
        i_nvdimm->setAttr<ATTR_NV_OPS_TIMEOUT_MSEC>(timeout_map);
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmGetTimeoutVal() HUID[%X]"
                ,get_huid(i_nvdimm));

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
    do
    {
        // Loop through each target
        for (TargetHandleList::iterator it = i_nvdimmList.begin();
             it != i_nvdimmList.end();)
        {
            TargetHandleList l_mcaList;
            getParentAffinityTargets(l_mcaList, *it, CLASS_UNIT, TYPE_MCA);
            assert(l_mcaList.size(), "nvdimmEpowSetup() failed to find parent MCA.");

            fapi2::Target<fapi2::TARGET_TYPE_MCA> l_fapi_mca(l_mcaList[0]);

            // Loads CCS with the EPOW sequence. This basically does bunch of scoms to
            // CCS array
            FAPI_INVOKE_HWP(l_err, mss::nvdimm::preload_epow_sequence, l_fapi_mca);

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmEpowSetup() HUID[%X] failed to setup epow!",
                          get_huid(*it));

                nvdimmSetStatusFlag(*it, NSTD_ERR_NOPRSV);
                break;
            }
            it++;
        }

    }while(0);

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
    Target* l_sys = nullptr;
    targetService().getTopLevelTarget( l_sys );
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
                              get_huid(l_nvdimm));
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
 * @brief Force a factory reset of the NV logic and flash
 *
 * @param[in] i_nvdimm - NVDIMM Target
 */
errlHndl_t nvdimm_factory_reset(Target *i_nvdimm)
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_factory_reset() nvdimm[%X]",
              get_huid(i_nvdimm));
    errlHndl_t l_err = nullptr;

    do
    {
        // Send the reset command
        l_err = nvdimmWriteReg(i_nvdimm, NVDIMM_FUNC_CMD, FACTORY_DEFAULT);
        if( l_err )
        {
            break;
        }

        // Poll 2 minutes for completion
        //   We could get the timeout value from the dimm but since we're
        //   doing a hard reset anyway I just want to use a big number that
        //   can handle any lies that the controller might tell us.
        uint8_t l_data = 0;
        constexpr uint64_t MAX_POLL_SECONDS = 120;
        uint64_t poll = 0;
        for( poll = 0; poll < MAX_POLL_SECONDS; poll++ )
        {
            l_err = nvdimmReadReg(i_nvdimm, NVDIMM_CMD_STATUS0, l_data);
            if( l_err )
            {
                break;
            }

            if( l_data != FACTORY_RESET_IN_PROGRESS )
            {
                break;
            }

#ifndef __HOSTBOOT_RUNTIME
            // kick the watchdog since this can take awhile
            INITSERVICE::sendProgressCode();
#endif

            // sleep 1 second
            nanosleep(1, 0);
        }
        if( l_err ) { break; }

        // Make an error if it never finished
        if( poll >= MAX_POLL_SECONDS )
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_factory_reset() nvdimm[%X] - factory reset never completed[%d]",
                      get_huid(i_nvdimm), l_data);
            /*@
             *@errortype
             *@reasoncode       NVDIMM_NOT_READY
             *@severity         ERRORLOG_SEV_UNRECOVERABLE
             *@moduleid         NVDIMM_FACTORY_RESET
             *@userdata1[0:31]  Ret value from ready register
             *@userdata1[32:63] Target Huid
             *@userdata2        Number of seconds waited
             *@devdesc          NVDIMM factory reset never completed
             *@custdesc         NVDIMM still in reset
             */
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        NVDIMM_FACTORY_RESET,
                        NVDIMM_NOT_READY,
                        NVDIMM_SET_USER_DATA_1(l_data, get_huid(i_nvdimm)),
                        MAX_POLL_SECONDS,
                        ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace(NVDIMM_COMP_NAME);

            // If nvdimm is not ready for access by now, this is
            // a failing indication on the NV controller
            l_err->addPartCallout( i_nvdimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
        }
    } while(0);

    return l_err;
}

/**
 * @brief NVDIMM initialization
 *        - Checks for ready state
 *        - Gathers timeout values
 *        - Waits for the ongoing backup to complete
 *        - Unlocks encryption
 *        - Disarms the trigger for draminit
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 */
void nvdimm_init(Target *i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_init() nvdimm[%X]",
              get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;

    do
    {
        // Force a factory reset if told to via attribute override
        //  This will allow us to recover from bad images, lost keys, etc
        Target* l_sys = nullptr;
        targetService().getTopLevelTarget( l_sys );
        assert(l_sys, "nvdimm_init: no TopLevelTarget");
        if( l_sys->getAttr<ATTR_FORCE_NVDIMM_RESET>() )
        {
            l_err = nvdimm_factory_reset(i_nvdimm);
            if (l_err)
            {
                nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], factory reset failed",
                          get_huid(i_nvdimm));
                errlCommit(l_err, NVDIMM_COMP_ID);
            }
        }

        l_err = nvdimmReady(i_nvdimm);

        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], controller not ready",
                      get_huid(i_nvdimm));
            errlCommit(l_err, NVDIMM_COMP_ID);
            break;
        }

        // Get the timeout values for the major ops at init
        l_err = nvdimmGetTimeoutVal(i_nvdimm);
        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], error retrieving timeout values",
                      get_huid(i_nvdimm));
            errlCommit(l_err, NVDIMM_COMP_ID);
            break;
        }

        //Check save progress
        uint32_t l_poll = 0;
        l_err = nvdimmPollBackupDone(i_nvdimm, l_poll);

        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_NOPRSV);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], error backing up the DRAM!",
                      get_huid(i_nvdimm));
            errlCommit(l_err, NVDIMM_COMP_ID);
            break;
        }

        // Unlock encryption if enabled
        TargetHandleList l_nvdimmTargetList;
        l_nvdimmTargetList.push_back(i_nvdimm);
        NVDIMM::nvdimm_encrypt_unlock(l_nvdimmTargetList);

        // Disarm the ddr_resetn here in case it came in armed. When the nvdimm is
        // armed the reset_n is masked off from the host, meaning the drams won't
        // be able to get reset properly later, causing training to fail.
        l_err = nvdimmChangeArmState(i_nvdimm, DISARM_TRIGGER);

        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_NOPRSV);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], error disarming the nvdimm!",
                      get_huid(i_nvdimm));
            errlCommit(l_err, NVDIMM_COMP_ID);
            break;
        }

    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_init() nvdimm[%X]",
              get_huid(i_nvdimm));
}


errlHndl_t nvdimm_getRandom(uint8_t* o_genData)
{
    errlHndl_t l_err = nullptr;
    uint8_t l_xtraData[ENC_KEY_SIZE] = {0};

    do
    {
        // Get a pointer to the TPM
        Target* l_tpm = nullptr;
        l_err = nvdimm_getTPM(l_tpm);
        if (l_err)
        {
            break;
        }

        // Get a random number from the TPM
        l_err = TRUSTEDBOOT::GetRandom(l_tpm, ENC_KEY_SIZE, o_genData);
        if (l_err)
        {
            break;
        }

        // Validate and update the random number
        // Retry if more randomness required
        do
        {
            //Get replacement data
            l_err = TRUSTEDBOOT::GetRandom(l_tpm, ENC_KEY_SIZE, l_xtraData);
            if (l_err)
            {
                break;
            }

        }while (nvdimm_keyifyRandomNumber(o_genData, l_xtraData));

    } while(0);

    return l_err;
}


errlHndl_t nvdimm_getTPM(Target*& o_tpm)
{
    errlHndl_t l_err = nullptr;

    do
    {
        // Get all functional TPMs
        TargetHandleList l_tpmList;
        TRUSTEDBOOT::getTPMs(l_tpmList,
                            TRUSTEDBOOT::TPM_FILTER::ALL_FUNCTIONAL);

        if (l_tpmList.size())
        {
            o_tpm = l_tpmList[0];
            break;
        }

        // No TPMs, generate error
        TRACFCOMP(g_trac_nvdimm,ERR_MRK"nvdimm_getTPM() No functional TPMs found");

        /*@
        *@errortype
        *@reasoncode    NVDIMM_TPM_NOT_FOUND
        *@severity      ERRORLOG_SEV_PREDICTIVE
        *@moduleid      NVDIMM_GET_TPM
        *@devdesc       Functional TPM required to generate encryption keys
        *@custdesc      NVDIMM error generating encryption keys
        */
        l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                        NVDIMM_GET_TPM,
                        NVDIMM_TPM_NOT_FOUND,
                        0x0,
                        0x0,
                        ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

        l_err->collectTrace(NVDIMM_COMP_NAME);

        // Get all TPMs
        TRUSTEDBOOT::getTPMs(l_tpmList,
                             TRUSTEDBOOT::TPM_FILTER::ALL_IN_BLUEPRINT);
        if (l_tpmList.size() == 0)
        {
            // No TPMs, we probably have nvdimms enabled
            // when they should not be
            l_err->addProcedureCallout(
                                HWAS::EPUB_PRC_HB_CODE,
                                HWAS::SRCI_PRIORITY_HIGH);
        }
        else
        {
            // If a TPM exists it must be deconfigured
            l_err->addProcedureCallout(
                                HWAS::EPUB_PRC_FIND_DECONFIGURED_PART,
                                HWAS::SRCI_PRIORITY_HIGH);
            l_err->addProcedureCallout(
                                HWAS::EPUB_PRC_HB_CODE,
                                HWAS::SRCI_PRIORITY_MED);
        }

    }while(0);

    // Functional TPM not found
    return l_err;
}


#endif


bool nvdimm_encrypt_unlock(TargetHandleList &i_nvdimmList)
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_encrypt_unlock()");
    errlHndl_t l_err = nullptr;
    bool l_success = true;

    do
    {
        // Do not check ATTR_NVDIMM_ENCRYPTION_ENABLE
        // The attribute could have been reset by flashing the FSP
        // Unlock if the keys are valid and NVDIMM hw encryption is enabled

        // Get the sys pointer, attribute keys are system level
        Target* l_sys = nullptr;
        targetService().getTopLevelTarget( l_sys );
        assert(l_sys, "nvdimm_encrypt_unlock() no TopLevelTarget");

        // Get the FW key attributes
        auto l_attrKeysFw =
            l_sys->getAttrAsStdArr<ATTR_NVDIMM_ENCRYPTION_KEYS_FW>();

        // Cast to key data struct type for easy access to each key
        nvdimmKeyData_t* l_keysFw =
                reinterpret_cast<nvdimmKeyData_t*>(&l_attrKeysFw);

        // Check encryption unlock for all nvdimms
        for (const auto & l_nvdimm : i_nvdimmList)
        {
            // Get encryption state in the config/status reg
            encryption_config_status_t l_encStatus = {0};
            l_err = nvdimmReadReg(l_nvdimm,
                                  ENCRYPTION_CONFIG_STATUS,
                                  l_encStatus.whole);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_encrypt_unlock() nvdimm[%X] error reading ENCRYPTION_CONFIG_STATUS",get_huid(l_nvdimm));
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }

            // Already unlocked or not enabled then exit
            if (l_encStatus.encryption_unlocked ||
                !l_encStatus.encryption_enabled)
            {
                break;
            }

            // Check for valid key attribute data
            l_err = nvdimm_checkValidAttrKeys(l_keysFw);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                break;
            }

            // Else encryption is enabled but needs unlock
            TRACFCOMP(g_trac_nvdimm, "nvdimm_encrypt_unlock() nvdimm[%X] enabled, unlocking...",get_huid(l_nvdimm));

            // Set the Unlock Access Key Reg
            l_err = nvdimm_setKeyReg(l_nvdimm,
                                     l_keysFw->ak,
                                     ENCRYPTION_ACCESS_KEY_UNLOCK,
                                     ENCRYPTION_ACCESS_KEY_VERIFY,
                                     false);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }

            // Verify encryption is unlocked
            l_err = nvdimmReadReg(l_nvdimm,
                                  ENCRYPTION_CONFIG_STATUS,
                                  l_encStatus.whole);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_encrypt_unlock() nvdimm[%X] error reading ENCRYPTION_CONFIG_STATUS after unlock",get_huid(l_nvdimm));
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }

            if (!l_encStatus.encryption_unlocked)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_encrypt_unlock() nvdimm[%X] encryption unlock failed, expected ENCRYPTION_CONFIG_STATUS=0x%.02X, expected=0x1F ",get_huid(l_nvdimm),l_encStatus.whole);
                /*@
                *@errortype
                *@reasoncode    NVDIMM_ENCRYPTION_UNLOCK_FAILED
                *@severity      ERRORLOG_SEV_PREDICTIVE
                *@moduleid      NVDIMM_ENCRYPT_UNLOCK
                *@userdata1     NVDIMM HUID
                *@userdata2     ENCRYPTION_CONFIG_STATUS
                *@devdesc       NVDIMM failed to unlock encryption
                *@custdesc      NVDIMM encryption error
                */
                l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                NVDIMM_ENCRYPT_UNLOCK,
                                NVDIMM_ENCRYPTION_UNLOCK_FAILED,
                                get_huid(l_nvdimm),
                                l_encStatus.whole,
                                ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

                l_err->collectTrace(NVDIMM_COMP_NAME);
                l_err->addPartCallout( l_nvdimm,
                                       HWAS::NV_CONTROLLER_PART_TYPE,
                                       HWAS::SRCI_PRIORITY_HIGH);
                l_err->addHwCallout( l_nvdimm,
                                     HWAS::SRCI_PRIORITY_MED,
                                     HWAS::DECONFIG,
                                     HWAS::GARD_NULL );

                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
            }
            else
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimm_encrypt_unlock() nvdimm[%X] encryption is unlocked 0x%.02x",get_huid(l_nvdimm),l_encStatus.whole);
            }
        }
    }while(0);

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_encrypt_unlock()");
    return l_success;
}


void nvdimmSetEncryptionError(Target *i_nvdimm)
{
    ATTR_NVDIMM_ARMED_type l_armed_state = {};
    l_armed_state = i_nvdimm->getAttr<ATTR_NVDIMM_ARMED>();

    l_armed_state.encryption_error_detected = 1;

    i_nvdimm->setAttr<ATTR_NVDIMM_ARMED>(l_armed_state);
}


bool nvdimm_keyifyRandomNumber(uint8_t* o_genData, uint8_t* i_xtraData)
{
    bool l_failed = false;
    uint32_t l_xtraByte = 0;

    for (uint32_t l_byte = 0; l_byte < ENC_KEY_SIZE; l_byte++)
    {
        if ((o_genData[l_byte] != KEY_TERMINATE_BYTE) &&
            (o_genData[l_byte] != KEY_ABORT_BYTE))
        {
            // This byte is valid
            continue;
        }

        // This byte is not valid, replace it
        // Find a valid byte in the replacement data
        while ((i_xtraData[l_xtraByte] == KEY_TERMINATE_BYTE) ||
               (i_xtraData[l_xtraByte] == KEY_ABORT_BYTE))
        {
            l_xtraByte++;

            if (l_xtraByte == ENC_KEY_SIZE)
            {
                l_failed = true;
                break;
            }
        }

        if (l_failed)
        {
            break;
        }

        // Replace the invalid byte with the valid extra byte
        o_genData[l_byte] = i_xtraData[l_xtraByte];
    }

    return l_failed;
}


bool nvdimm_validRandomNumber(uint8_t* i_genData)
{
    bool l_valid = true;
    for (uint32_t l_byte = 0; l_byte < ENC_KEY_SIZE; l_byte++)
    {
        if ((i_genData[l_byte] == KEY_TERMINATE_BYTE) ||
            (i_genData[l_byte] == KEY_ABORT_BYTE))
        {
            l_valid = false;
            break;
        }
    }
    return l_valid;
}


errlHndl_t nvdimm_checkValidAttrKeys( nvdimmKeyData_t* i_attrData )
{
    errlHndl_t l_err = nullptr;
    bool l_valid = false;

    do
    {
        l_valid = nvdimm_validRandomNumber(i_attrData->rs);
        if (!l_valid)
        {
            break;
        }
        l_valid = nvdimm_validRandomNumber(i_attrData->ek);
        if (!l_valid)
        {
            break;
        }
        l_valid = nvdimm_validRandomNumber(i_attrData->ak);
        if (!l_valid)
        {
            break;
        }
    }while(0);

    if (!l_valid)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_checkValidAttrKeys() ATTR_NVDIMM_ENCRYPTION_KEYS_FW contains invalid data");
        /*@
        *@errortype
        *@reasoncode    NVDIMM_ENCRYPTION_INVALID_ATTRIBUTE
        *@severity      ERRORLOG_SEV_PREDICTIVE
        *@moduleid      NVDIMM_CHECK_VALID_ATTR_DATA
        *@devdesc       ATTR_NVDIMM_ENCRYPTION_KEYS_FW has invalid data
        *@custdesc      NVDIMM encryption error
        */
        l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                        NVDIMM_CHECK_VALID_ATTR_DATA,
                        NVDIMM_ENCRYPTION_INVALID_ATTRIBUTE,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

        l_err->collectTrace(NVDIMM_COMP_NAME);
    }

    return l_err;
}


errlHndl_t nvdimm_handleConflictingKeys(
        ATTR_NVDIMM_ENCRYPTION_KEYS_FW_typeStdArr& i_attrKeysFw,
        ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR_typeStdArr& i_attrKeysAnchor)
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_handleConflictingKeys()");
    errlHndl_t l_err = nullptr;
    bool l_validKeyFound = false;

    // Recast to key data type to simplify parsing
    nvdimmKeyData_t* l_keysFw =
            reinterpret_cast<nvdimmKeyData_t*>(&i_attrKeysFw);
    nvdimmKeyData_t* l_keysAnchor =
            reinterpret_cast<nvdimmKeyData_t*>(&i_attrKeysAnchor);

    // Get the nvdimm target pointers
    TargetHandleList l_nvdimmTargetList;
    nvdimm_getNvdimmList(l_nvdimmTargetList);
    for (const auto & l_nvdimm : l_nvdimmTargetList)
    {
        // Check encryption state in the config/status reg
        encryption_config_status_t l_encStatus = {0};
        l_err = nvdimmReadReg(l_nvdimm,
                              ENCRYPTION_CONFIG_STATUS,
                              l_encStatus.whole);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_handleConflictingKeys() nvdimm[%X] error reading ENCRYPTION_CONFIG_STATUS",get_huid(l_nvdimm));
            errlCommit( l_err, NVDIMM_COMP_ID );
            nvdimmSetEncryptionError(l_nvdimm);
            continue;
        }

        // Encryption is not enabled
        // Keys are not in use so could use either set of keys
        // Use the ANCHOR card keys
        if (!l_encStatus.encryption_enabled)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimm_handleConflictingKeys() nvdimm[%X] copying ANCHOR keys to FW",get_huid(l_nvdimm));
            l_validKeyFound = true;
            set_ATTR_NVDIMM_ENCRYPTION_KEYS_FW(i_attrKeysAnchor);
            continue;
        }

        // Encryption is enabled, test the keys
        // Write the EK test reg with the FW attr value
        l_err = nvdimm_setKeyReg(l_nvdimm,
                                 l_keysFw->ek,
                                 ENCRYPTION_ERASE_KEY_TEST,
                                 ENCRYPTION_ERASE_KEY_TEST_VERIFY,
                                 false);
        if (l_err)
        {
            break;
        }

        // Check for erase key valid in the validation reg
        encryption_key_validation_t l_keyValid = {0};
        l_err = nvdimmReadReg(l_nvdimm,
                              ENCRYPTION_KEY_VALIDATION,
                              l_keyValid.whole);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_handleConflictingKeys() nvdimm[%X] error reading ENCRYPTION_KEY_VALIDATION",get_huid(l_nvdimm));
            break;
        }
        if (l_keyValid.erase_key_valid)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_handleConflictingKeys() nvdimm[%X] ATTR_NVDIMM_ENCRYPTION_KEYS_FW valid",get_huid(l_nvdimm));
            l_validKeyFound = true;
            // Re-write the FW keys, this will also update the ANCHOR keys
            set_ATTR_NVDIMM_ENCRYPTION_KEYS_FW(i_attrKeysFw);
            break;
        }

        // Write the EK test reg with the Anchor attr value
        l_err = nvdimm_setKeyReg(l_nvdimm,
                                 l_keysAnchor->ek,
                                 ENCRYPTION_ERASE_KEY_TEST,
                                 ENCRYPTION_ERASE_KEY_TEST_VERIFY,
                                 false);
        if (l_err)
        {
            break;
        }

        // Check for erase key valid in the validation reg
        l_keyValid.whole = 0;
        l_err = nvdimmReadReg(l_nvdimm,
                              ENCRYPTION_KEY_VALIDATION,
                              l_keyValid.whole);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_handleConflictingKeys() nvdimm[%X] error reading ENCRYPTION_KEY_VALIDATION",get_huid(l_nvdimm));
            break;
        }
        if (l_keyValid.erase_key_valid)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_handleConflictingKeys() nvdimm[%X] ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR valid",get_huid(l_nvdimm));
            l_validKeyFound = true;
            // Copy anchor attr value to FW attribute
            set_ATTR_NVDIMM_ENCRYPTION_KEYS_FW(i_attrKeysAnchor);

            break;
        }
    }

    if (!l_validKeyFound)
    {
        // Neither key attribute is valid
        TRACFCOMP(g_trac_nvdimm,ERR_MRK"nvdimm_handleConflictingKeys() ATTR_NVDIMM_ENCRYPTION_KEYS_FW and ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR invalid.");
        /*@
        *@errortype
        *@reasoncode       NVDIMM_ENCRYPTION_KEY_ATTRS_INVALID
        *@severity         ERRORLOG_SEV_PREDICTIVE
        *@moduleid         NVDIMM_HANDLE_CONFLICTING_KEYS
        *@devdesc          NVDIMM encryption key attributes invalid
        *@custdesc         NVDIMM encryption error
        */
        l_err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                    NVDIMM_HANDLE_CONFLICTING_KEYS,
                    NVDIMM_ENCRYPTION_KEY_ATTRS_INVALID,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

        l_err->collectTrace(NVDIMM_COMP_NAME);
    }

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_handleConflictingKeys()");
    return l_err;
}


void nvdimm_getNvdimmList(TargetHandleList &o_nvdimmTargetList)
{
    // Check for any NVDIMMs after the mss_power_cleanup
    TargetHandleList l_dimmTargetList;
    getAllLogicalCards(l_dimmTargetList, TYPE_DIMM);

    // Walk the dimm list and collect all the nvdimm targets
    for (auto const l_dimm : l_dimmTargetList)
    {
        if (isNVDIMM(l_dimm))
        {
            o_nvdimmTargetList.push_back(l_dimm);
        }
    }
}


bool nvdimm_gen_keys(void)
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_gen_keys()");
    errlHndl_t l_err = nullptr;
    bool l_success = true;

    do
    {
        // Determine if key generation required
        Target* l_sys = nullptr;
        targetService().getTopLevelTarget( l_sys );
        assert(l_sys, "nvdimm_gen_keys: no TopLevelTarget");

        // Key size must be less that max TPM random generator size
        static_assert(ENC_KEY_SIZE <= MAX_TPM_SIZE,
            "nvdimm_gen_keys() ENC_KEY_SIZE is greater than MAX_TPM_SIZE");

        // Key attributes should be same size
        static_assert( sizeof(ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR_type) ==
                       sizeof(ATTR_NVDIMM_ENCRYPTION_KEYS_FW_type),
            "nvdimm_gen_keys() size of ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR_type does not match ATTR_NVDIMM_ENCRYPTION_KEYS_FW_type");

        // Get the key attributes
        auto l_attrKeysFw =
            l_sys->getAttrAsStdArr<ATTR_NVDIMM_ENCRYPTION_KEYS_FW>();
        auto l_attrKeysAn =
            l_sys->getAttrAsStdArr<ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR>();

        // Check the attribute sizes
        static_assert(sizeof(l_attrKeysFw) == (NUM_KEYS_IN_ATTR * ENC_KEY_SIZE),
            "nvdimm_gen_keys() Size of ATTR_NVDIMM_ENCRYPTION_KEYS_FW does not match NUM_KEYS_IN_ATTR * ENC_KEY_SIZE");
        static_assert(sizeof(l_attrKeysAn) == (NUM_KEYS_IN_ATTR * ENC_KEY_SIZE),
            "nvdimm_gen_keys() Size of ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR does not match NUM_KEYS_IN_ATTR * ENC_KEY_SIZE");

        // Compare attributes to zero
        std::array<uint8_t,sizeof(l_attrKeysFw)> l_zero = {0};
        bool l_fwZero = (l_attrKeysFw == l_zero);
        bool l_anZero = (l_attrKeysAn == l_zero);

        // Compare the attribute values
        if (!l_fwZero && !l_anZero)
        {
            if (l_attrKeysFw != l_attrKeysAn)
            {
                // Handle conflicting keys
                TRACFCOMP(g_trac_nvdimm, "nvdimm_gen_keys() ATTR_NVDIMM_ENCRYPTION_KEYS_FW != ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR");
                l_err = nvdimm_handleConflictingKeys(l_attrKeysFw,l_attrKeysAn);
            }
            else
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimm_gen_keys() ATTR_NVDIMM_ENCRYPTION_KEYS_FW == ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR");
            }
            break;
        }
        else if (!l_fwZero && l_anZero)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimm_gen_keys() ATTR_NVDIMM_ENCRYPTION_KEYS_FW != 0 and ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR = 0");
            break;
        }
        else if (l_fwZero && !l_anZero)
        {
            // Set FW attr = Anchor attr
            TRACFCOMP(g_trac_nvdimm, "nvdimm_gen_keys() Setting ATTR_NVDIMM_ENCRYPTION_KEYS_FW = ATTR_NVDIMM_ENCRYPTION_KEYS_ANCHOR");
            set_ATTR_NVDIMM_ENCRYPTION_KEYS_FW(l_attrKeysAn);
            break;
        }

        // If we get here then both key attributes are zero, generate new keys
        assert(sizeof(l_attrKeysFw) == sizeof(nvdimmKeyData_t),
            "nvdimm_gen_keys() ATTR_NVDIMM_ENCRYPTION_KEYS_FW size does not match nvdimmKeyData_t");
        nvdimmKeyData_t* l_keys =
            reinterpret_cast<nvdimmKeyData_t*>(&l_attrKeysFw);

        // Generate Random String (RS)
        l_err = nvdimm_getRandom(l_keys->rs);
        if (l_err)
        {
            break;
        }

        // Generate Erase Key (EK)
        l_err = nvdimm_getRandom(l_keys->ek);
        if (l_err)
        {
            break;
        }

        // Generate Access Key (AK)
        l_err = nvdimm_getRandom(l_keys->ak);
        if (l_err)
        {
            break;
        }

        // Set the FW attribute
        set_ATTR_NVDIMM_ENCRYPTION_KEYS_FW(l_attrKeysFw);

    }while(0);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_gen_keys() Failed to generate keys, will not set ATTR_NVDIMM_ENCRYPTION_KEYS_FW");
        errlCommit( l_err, NVDIMM_COMP_ID );
        l_success = false;

        // Set the encryption error for all nvdimms
        TargetHandleList l_nvdimmTargetList;
        nvdimm_getNvdimmList(l_nvdimmTargetList);
        for (const auto & l_nvdimm : l_nvdimmTargetList)
        {
            nvdimmSetEncryptionError(l_nvdimm);
        }
    }

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_gen_keys()");
    return l_success;
}


bool nvdimm_remove_keys(void)
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_remove_keys()");
    bool l_success = true;

    // Get the sys pointer, attribute keys are system level
    Target* l_sys = nullptr;
    targetService().getTopLevelTarget( l_sys );
    assert(l_sys, "nvdimm_remove_keys() no TopLevelTarget");

    // Set the FW attribute = 0
    TRACFCOMP(g_trac_nvdimm, "nvdimm_remove_keys() Setting ATTR_NVDIMM_ENCRYPTION_KEYS_FW=0");
    ATTR_NVDIMM_ENCRYPTION_KEYS_FW_typeStdArr l_attrKeysFw = {0};
    set_ATTR_NVDIMM_ENCRYPTION_KEYS_FW(l_attrKeysFw);

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_remove_keys()");
    return l_success;
}


errlHndl_t nvdimm_setKeyReg(Target* i_nvdimm,
                            uint8_t* i_keyData,
                            uint32_t i_keyReg,
                            uint32_t i_verifyReg,
                            bool i_secondAttempt)
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_setKeyReg(0x%X) reg=0x%X",get_huid(i_nvdimm),i_keyReg);
    errlHndl_t l_err = nullptr;

    do
    {
        uint32_t l_byte = 0;
        uint8_t l_verifyData = 0x0;

        // Before setting the key reg we need to
        // init the verif reg with a random value
        uint8_t l_genData[ENC_KEY_SIZE] = {0};
        l_err = nvdimm_getRandom(l_genData);
        if (l_err)
        {
            break;
        }

        // Write the verif reg one byte at a time
        for (l_byte = 0; l_byte < ENC_KEY_SIZE; l_byte++)
        {
            // Write the verification byte
            l_err = nvdimmWriteReg(i_nvdimm, i_verifyReg, l_genData[l_byte]);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_setKeyReg() huid=0x%X, error writing verif reg=0x%.03X byte=0x%d", get_huid(i_nvdimm), i_verifyReg, l_byte);
                break;
            }
        }

        // Delay to allow verif write to complete
        nanosleep(0, KEY_WRITE_DELAY_MS*NS_PER_MSEC);

        // Write the reg, one byte at a time
        for (l_byte = 0; l_byte < ENC_KEY_SIZE; l_byte++)
        {
            // Write the key byte
            l_err = nvdimmWriteReg(i_nvdimm, i_keyReg, i_keyData[l_byte]);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_setKeyReg() huid=0x%X, error writing key reg 0x%.03X byte=0x%d", get_huid(i_nvdimm), i_keyReg, l_byte);
                break;
            }

            // Read the verification byte
            l_err = nvdimmReadReg(i_nvdimm, i_verifyReg, l_verifyData);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_setKeyReg() huid=0x%X, error reading verif reg=0x%.03X byte=0x%d", get_huid(i_nvdimm), i_verifyReg, l_byte);
                break;
            }

            // Verify the key byte
            if (l_verifyData != i_keyData[l_byte])
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_setKeyReg() huid=0x%X, key verification failed reg=0x%.03X byte=0x%d set=0x%.02x get=0x%.02x", get_huid(i_nvdimm), i_keyReg, l_byte, i_keyData[l_byte], l_verifyData);
                // Write KEY_ABORT_BYTE to abort the key write sequence
                l_err = nvdimmWriteReg(i_nvdimm, i_keyReg, KEY_ABORT_BYTE);
                if (i_secondAttempt)
                {
                    // Verify check byte failed for the second time
                    TRACFCOMP(g_trac_nvdimm,ERR_MRK"nvdimm_getTPM() Key verification byte check failed on second attempt.");
                    /*@
                    *@errortype
                    *@reasoncode       NVDIMM_VERIF_BYTE_CHECK_FAILED
                    *@severity         ERRORLOG_SEV_PREDICTIVE
                    *@moduleid         NVDIMM_SET_KEY_REG
                    *@userdata1        NVDIMM HUID
                    *@userdata2[0:31]  Key Register
                    *@userdata2[32:63] Verif Register
                    *@devdesc          NVDIMM failed to set encryption register
                    *@custdesc         NVDIMM register error
                    */
                    l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                NVDIMM_SET_KEY_REG,
                                NVDIMM_VERIF_BYTE_CHECK_FAILED,
                                get_huid(i_nvdimm),
                                NVDIMM_SET_USER_DATA_1(i_keyReg,i_verifyReg),
                                ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

                    l_err->collectTrace(NVDIMM_COMP_NAME);
                    l_err->addPartCallout( i_nvdimm,
                                           HWAS::NV_CONTROLLER_PART_TYPE,
                                           HWAS::SRCI_PRIORITY_HIGH);
                }
                else
                {
                    // Try writing the reg again
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_setKeyReg() huid=0x%X, writing reg=0x%.03X again", get_huid(i_nvdimm), i_keyReg);
                    l_err = nvdimm_setKeyReg(i_nvdimm,
                                             i_keyData,
                                             i_keyReg,
                                             i_verifyReg,
                                             true);
                }
                break;
            }
        }

        // Delay to allow write to complete
        nanosleep(0, KEY_WRITE_DELAY_MS*NS_PER_MSEC);

    }while(0);

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_setKeyReg(0x%X) reg=0x%X",get_huid(i_nvdimm),i_keyReg);
    return l_err;
}


bool nvdimm_encrypt_enable(TargetHandleList &i_nvdimmList)
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_encrypt_enable()");
    errlHndl_t l_err = nullptr;
    bool l_success = true;

    do
    {
        // Get the sys pointer, attribute keys are system level
        Target* l_sys = nullptr;
        targetService().getTopLevelTarget( l_sys );
        assert(l_sys, "nvdimm_encrypt_enable() no TopLevelTarget");

        // Exit if encryption is not enabled via the attribute
        if (!l_sys->getAttr<ATTR_NVDIMM_ENCRYPTION_ENABLE>())
        {
            TRACFCOMP(g_trac_nvdimm,"ATTR_NVDIMM_ENCRYPTION_ENABLE=0");
            break;
        }

        // Get the FW key attributes
        auto l_attrKeysFw =
            l_sys->getAttrAsStdArr<ATTR_NVDIMM_ENCRYPTION_KEYS_FW>();

        // Cast to key data struct type for easy access to each key
        nvdimmKeyData_t* l_keysFw =
                reinterpret_cast<nvdimmKeyData_t*>(&l_attrKeysFw);

        // Check for valid key attribute key data
        l_err = nvdimm_checkValidAttrKeys(l_keysFw);
        if (l_err)
        {
            break;
        }

        // Handle encryption for all nvdimms
        for (const auto & l_nvdimm : i_nvdimmList)
        {
            // Check encryption state in the config/status reg
            encryption_config_status_t l_encStatus = {0};
            l_err = nvdimmReadReg(l_nvdimm,
                                ENCRYPTION_CONFIG_STATUS,
                                l_encStatus.whole);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_encrypt_enable() nvdimm[%X] error reading ENCRYPTION_CONFIG_STATUS",get_huid(l_nvdimm));
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }

            // Encryption is enabled and unlocked
            if (l_encStatus.encryption_unlocked &&
                l_encStatus.encryption_enabled)
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimm_encrypt_enable() nvdimm[%X] enabled and unlocked",get_huid(l_nvdimm));
                continue;
            }

            // Need to handle these cases?
            if (!((l_encStatus.whole & ENCRYPTION_STATUS_CHECK_MASK)
                  == ENCRYPTION_STATUS_DISABLED))
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimm_encrypt_enable() nvdimm[%X] unsupported state 0x%.02X",get_huid(l_nvdimm),l_encStatus.whole);
                continue;
            }

            // Status = 0x01, enable encryption
            // Set the Random String (RS) reg
            TRACFCOMP(g_trac_nvdimm,"nvdimm_encrypt_enable() nvdimm[%X] status=0x01 0x%.02x",get_huid(l_nvdimm),l_encStatus.whole);
            l_err = nvdimm_setKeyReg(l_nvdimm,
                                    l_keysFw->rs,
                                    ENCRYPTION_RAMDOM_STRING_SET,
                                    ENCRYPTION_RANDOM_STRING_VERIFY,
                                    false);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }

            // Set the Erase Key (EK) Reg
            l_err = nvdimm_setKeyReg(l_nvdimm,
                                    l_keysFw->ek,
                                    ENCRYPTION_ERASE_KEY_SET,
                                    ENCRYPTION_ERASE_KEY_VERIFY,
                                    false);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }

            // Set the Access Key (AK) Reg
            l_err = nvdimm_setKeyReg(l_nvdimm,
                                    l_keysFw->ak,
                                    ENCRYPTION_ACCESS_KEY_SET,
                                    ENCRYPTION_ACCESS_KEY_VERIFY,
                                    false);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }

            // Verify encryption is enabled
            l_err = nvdimmReadReg(l_nvdimm,
                                ENCRYPTION_CONFIG_STATUS,
                                l_encStatus.whole);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_encrypt_enable() nvdimm[%X] error reading ENCRYPTION_CONFIG_STATUS after enable",get_huid(l_nvdimm));
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }
            if (!((l_encStatus.whole & ENCRYPTION_STATUS_CHECK_MASK)
                  == ENCRYPTION_STATUS_ENABLED))
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_encrypt_enable() nvdimm[%X] encryption enable failed, ENCRYPTION_CONFIG_STATUS=0x%.02X, expected=0x1F ",get_huid(l_nvdimm),l_encStatus.whole);
                /*@
                *@errortype
                *@reasoncode    NVDIMM_ENCRYPTION_ENABLE_FAILED
                *@severity      ERRORLOG_SEV_PREDICTIVE
                *@moduleid      NVDIMM_ENCRYPT_ENABLE
                *@userdata1     NVDIMM HUID
                *@userdata2     ENCRYPTION_CONFIG_STATUS
                *@devdesc       NVDIMM failed to enable encryption
                *@custdesc      NVDIMM encryption error
                */
                l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                NVDIMM_ENCRYPT_ENABLE,
                                NVDIMM_ENCRYPTION_ENABLE_FAILED,
                                get_huid(l_nvdimm),
                                l_encStatus.whole,
                                ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

                l_err->collectTrace(NVDIMM_COMP_NAME);
                l_err->addPartCallout( l_nvdimm,
                                    HWAS::NV_CONTROLLER_PART_TYPE,
                                    HWAS::SRCI_PRIORITY_HIGH);

                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
            }
            else
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimm_encrypt_enable() nvdimm[%X] encryption is enabled 0x%.02x",get_huid(l_nvdimm),l_encStatus.whole);
            }
        }
    }while(0);

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_encrypt_enable()");
    return l_success;
}


bool nvdimm_crypto_erase(TargetHandleList &i_nvdimmList)
{
    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_crypto_erase()");
    errlHndl_t l_err = nullptr;
    bool l_success = true;

    do
    {
        // Get the sys pointer, attribute keys are system level
        Target* l_sys = nullptr;
        targetService().getTopLevelTarget( l_sys );
        assert(l_sys, "nvdimm_crypto_erase: no TopLevelTarget");

        // Exit if encryption is not enabled via the attribute
        if (!l_sys->getAttr<ATTR_NVDIMM_ENCRYPTION_ENABLE>())
        {
            TRACFCOMP(g_trac_nvdimm,"ATTR_NVDIMM_ENCRYPTION_ENABLE=0");
            break;
        }

        // Get the FW key attributes
        auto l_attrKeysFw =
            l_sys->getAttrAsStdArr<ATTR_NVDIMM_ENCRYPTION_KEYS_FW>();

        // Cast to key data struct type for easy access to each key
        nvdimmKeyData_t* l_keysFw =
                reinterpret_cast<nvdimmKeyData_t*>(&l_attrKeysFw);

        // Check for valid key attribute key data
        l_err = nvdimm_checkValidAttrKeys(l_keysFw);
        if (l_err)
        {
            break;
        }

        // Handle erase for all nvdimms
        for (const auto & l_nvdimm : i_nvdimmList)
        {
            // Check encryption state in the config/status reg
            encryption_config_status_t l_encStatus = {0};
            l_err = nvdimmReadReg(l_nvdimm,
                                  ENCRYPTION_CONFIG_STATUS,
                                  l_encStatus.whole);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_crypto_erase() nvdimm[%X] error reading ENCRYPTION_CONFIG_STATUS",get_huid(l_nvdimm));
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }
            // Encryption enabled must be set to crypto erase
            if (!l_encStatus.encryption_enabled)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_crypto_erase() nvdimm[%X] encryption not enabled, will not cypto erase 0x%.02x",get_huid(l_nvdimm),l_encStatus.whole);
                l_success = false;
                continue;
            }
            else
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimm_crypto_erase() nvdimm[%X] encryption enabled 0x%.02x",get_huid(l_nvdimm),l_encStatus.whole);
            }

            // Set the Erase Key (EK) Reg
            l_err = nvdimm_setKeyReg(l_nvdimm,
                                    l_keysFw->ek,
                                    ENCRYPTION_ERASE_KEY_SET,
                                    ENCRYPTION_ERASE_KEY_VERIFY,
                                    false);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }

            // Check encryption state in the config/status reg
            l_err = nvdimmReadReg(l_nvdimm,
                                ENCRYPTION_CONFIG_STATUS,
                                l_encStatus.whole);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_crypto_erase() nvdimm[%X] error reading ENCRYPTION_CONFIG_STATUS",get_huid(l_nvdimm));
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }
            // Erase pending bit should be set
            if (!l_encStatus.erase_pending)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_crypto_erase() nvdimm[%X] expected erase pending = 1 0x%.02x",get_huid(l_nvdimm),l_encStatus.whole);
                /*@
                *@errortype
                *@reasoncode    NVDIMM_ENCRYPTION_ERASE_PENDING_FAILED
                *@severity      ERRORLOG_SEV_PREDICTIVE
                *@moduleid      NVDIMM_CRYPTO_ERASE
                *@userdata1     NVDIMM HUID
                *@userdata2     ENCRYPTION_CONFIG_STATUS
                *@devdesc       NVDIMM failed to set encryption register
                *@custdesc      NVDIMM register error
                */
                l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                NVDIMM_CRYPTO_ERASE,
                                NVDIMM_ENCRYPTION_ERASE_PENDING_FAILED,
                                get_huid(l_nvdimm),
                                l_encStatus.whole,
                                ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

                l_err->collectTrace(NVDIMM_COMP_NAME);
                l_err->addPartCallout( l_nvdimm,
                                    HWAS::NV_CONTROLLER_PART_TYPE,
                                    HWAS::SRCI_PRIORITY_HIGH);

                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }
            else
            {
                TRACFCOMP(g_trac_nvdimm,"nvdimm_crypto_erase() nvdimm[%X] erase pending 0x%.02x",get_huid(l_nvdimm),l_encStatus.whole);
            }

            // Generate a generic erase key
            uint8_t l_genData[ENC_KEY_SIZE] = {0};
            l_err = nvdimm_getRandom(l_genData);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }

            // Set the Erase Key (EK) Reg
            l_err = nvdimm_setKeyReg(l_nvdimm,
                                    l_genData,
                                    ENCRYPTION_ERASE_KEY_SET,
                                    ENCRYPTION_ERASE_KEY_VERIFY,
                                    false);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }

            // Check encryption state in the config/status reg
            l_err = nvdimmReadReg(l_nvdimm,
                                ENCRYPTION_CONFIG_STATUS,
                                l_encStatus.whole);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_crypto_erase() nvdimm[%X] error reading ENCRYPTION_CONFIG_STATUS",get_huid(l_nvdimm));
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }
            // Encryption enabled bit should not be set
            if (l_encStatus.encryption_enabled)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_crypto_erase() nvdimm[%X] expected encryption enabled = 0 0x%.02x",get_huid(l_nvdimm),l_encStatus.whole);
                /*@
                *@errortype
                *@reasoncode    NVDIMM_ENCRYPTION_ERASE_FAILED
                *@severity      ERRORLOG_SEV_PREDICTIVE
                *@moduleid      NVDIMM_CRYPTO_ERASE
                *@userdata1     NVDIMM HUID
                *@userdata2     ENCRYPTION_CONFIG_STATUS
                *@devdesc       NVDIMM failed to set encryption register
                *@custdesc      NVDIMM register error
                */
                l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                NVDIMM_CRYPTO_ERASE,
                                NVDIMM_ENCRYPTION_ERASE_FAILED,
                                get_huid(l_nvdimm),
                                l_encStatus.whole,
                                ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

                l_err->collectTrace(NVDIMM_COMP_NAME);
                l_err->addPartCallout( l_nvdimm,
                                    HWAS::NV_CONTROLLER_PART_TYPE,
                                    HWAS::SRCI_PRIORITY_HIGH);

                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }
            else
            {
                TRACFCOMP(g_trac_nvdimm,"nvdimm_crypto_erase() nvdimm[%X] erase complete 0x%.02x",get_huid(l_nvdimm),l_encStatus.whole);
            }
        }
    }while(0);

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_crypto_erase()");
    return l_success;
}


errlHndl_t notifyNvdimmProtectionChange(Target* i_target,
                                        const nvdimm_protection_t i_state)
{
    TRACFCOMP( g_trac_nvdimm, ENTER_MRK
        "notifyNvdimmProtectionChange: Target huid 0x%.8X, state %d",
        get_huid(i_target), i_state);

    errlHndl_t l_err = nullptr;

    do
    {
        // Get the type of target passed in
        // It could be proc_type for OCC state
        // Or dimm_type for ARM/ERROR state
        ATTR_TYPE_type l_type = i_target->getAttr<ATTR_TYPE>();
        assert((l_type == TYPE_PROC)||(l_type == TYPE_DIMM),
               "notifyNvdimmProtectionChange invalid target type");

        // Load the nvdimm list
        TargetHandleList l_nvdimmTargetList;
        Target* l_proc = nullptr;
        if (l_type == TYPE_PROC)
        {
            // Get the nvdimms under this proc target
            l_nvdimmTargetList = getProcNVDIMMs(i_target);

            // Only send command if the processor has an NVDIMM under it
            if (l_nvdimmTargetList.empty())
            {
                TRACFCOMP( g_trac_nvdimm, "notifyNvdimmProtectionChange: "
                    "No NVDIMM found under processor 0x%.8X",
                    get_huid(i_target));
                break;
            }

            // The proc target is the passed-in target
            l_proc = i_target;
        }
        else
        {
            // Only a list of one but keep consistent with proc type
            l_nvdimmTargetList.push_back(i_target);

            // Find the proc target from nvdimm target passed in
            TargetHandleList l_procList;
            getParentAffinityTargets(l_procList,
                                     i_target,
                                     CLASS_CHIP,
                                     TYPE_PROC,
                                     UTIL_FILTER_ALL);
            assert(l_procList.size() == 1, "notifyNvdimmProtectionChange:"
                                        "getParentAffinityTargets size != 1");
            l_proc = l_procList[0];
        }


        // Update the nvdimm status attributes
        for (auto const l_nvdimm : l_nvdimmTargetList)
        {
            // Get the armed status attr and update it
            ATTR_NVDIMM_ARMED_type l_armed_state = {};
            l_armed_state = l_nvdimm->getAttr<ATTR_NVDIMM_ARMED>();

            // If we change the armed state, need to tell FSP
            bool l_armed_change = false;

            switch (i_state)
            {
                case NVDIMM_ARMED:
                    l_armed_state.armed = 1;
                    l_armed_change = true;
                    break;
                case NVDIMM_DISARMED:
                    l_armed_state.armed = 0;
                    l_armed_change = true;
                    break;
                case OCC_ACTIVE:
                    l_armed_state.occ_active = 1;
                    break;
                case OCC_INACTIVE:
                    l_armed_state.occ_active = 0;
                    break;
                case NVDIMM_FATAL_HW_ERROR:
                    l_armed_state.fatal_error_detected = 1;
                    break;
                case NVDIMM_RISKY_HW_ERROR:
                    l_armed_state.risky_error_detected = 1;
                    break;
                case NVDIMM_ENCRYPTION_ERROR:
                    l_armed_state.encryption_error_detected = 1;
                    break;
            }

            // Set the attribute and send it to the FSP if needed
            l_nvdimm->setAttr<ATTR_NVDIMM_ARMED>(l_armed_state);
            if( l_armed_change )
            {
                send_ATTR_NVDIMM_ARMED( l_nvdimm, l_armed_state );
            }

            // Get the nv status flag attr and update it
            ATTR_NV_STATUS_FLAG_type l_nv_status =
                        l_nvdimm->getAttr<ATTR_NV_STATUS_FLAG>();

            // Clear bit 0 if protected nv state
            if (l_armed_state.armed &&
                l_armed_state.occ_active &&
                !l_armed_state.fatal_error_detected)
            {
                l_nv_status &= NV_STATUS_UNPROTECTED_CLEAR;
            }

            // Set bit 0 if unprotected nv state
            else
            {
                l_nv_status |= NV_STATUS_UNPROTECTED_SET;
            }

            // Set bit 6 if risky error
            if (l_armed_state.risky_error_detected)
            {
                l_nv_status |= NV_STATUS_POSSIBLY_UNPROTECTED_SET;
            }

            l_nvdimm->setAttr<ATTR_NV_STATUS_FLAG>(l_nv_status);

        } // for nvdimm list

        // Generate combined nvdimm status for the proc
        // Bit 2 of NV_STATUS_FLAG is 'Device contents are persisted'
        //   and must be ANDed for all nvdimms
        //   the rest of the bits are ORed for all nvdimms
        ATTR_NV_STATUS_FLAG_type l_combined_or     = 0x00;
        ATTR_NV_STATUS_FLAG_type l_combined_and    = 0xFF;
        ATTR_NV_STATUS_FLAG_type l_combined_status = 0x00;
        l_nvdimmTargetList = getProcNVDIMMs(l_proc);
        for (auto const l_nvdimm : l_nvdimmTargetList)
        {
            l_combined_or  |= l_nvdimm->getAttr<ATTR_NV_STATUS_FLAG>();
            l_combined_and &= l_nvdimm->getAttr<ATTR_NV_STATUS_FLAG>();
        }

        // Bit 2 of NV_STATUS_FLAG is 'Device contents are persisted'
        l_combined_status =
                (l_combined_or  & NV_STATUS_OR_MASK) |
                (l_combined_and & NV_STATUS_AND_MASK);

        TRACFCOMP( g_trac_nvdimm,
            "notifyNvdimmProtectionChange: NV_STATUS for proc %X 0x%.02X",
            get_huid(l_proc), l_combined_status);

#ifdef __HOSTBOOT_RUNTIME

        // Send combined status to phyp
        // Get the Proc Chip Id
        RT_TARG::rtChipId_t l_chipId = 0;

        l_err = RT_TARG::getRtTarget(l_proc, l_chipId);
        if(l_err)
        {
            TRACFCOMP( g_trac_nvdimm,
                ERR_MRK"notifyNvdimmProtectionChange: getRtTarget ERROR" );
            break;
        }

        // send the notification msg
        if ((nullptr == g_hostInterfaces) ||
            (nullptr == g_hostInterfaces->firmware_request))
        {
            TRACFCOMP( g_trac_nvdimm, ERR_MRK"notifyNvdimmProtectionChange: "
                     "Hypervisor firmware_request interface not linked");

            /*@
             * @errortype
             * @severity          ERRL_SEV_PREDICTIVE
             * @moduleid          NOTIFY_NVDIMM_PROTECTION_CHG
             * @reasoncode        NVDIMM_NULL_FIRMWARE_REQUEST_PTR
             * @userdata1         HUID of processor target
             * @userdata2[0:31]   NV_STATUS to PHYP
             * @userdata2[32:63]  In state change
             * @devdesc           Unable to inform PHYP of NVDIMM protection
             * @custdesc          Internal firmware error
             */
             l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                            NOTIFY_NVDIMM_PROTECTION_CHG,
                            NVDIMM_NULL_FIRMWARE_REQUEST_PTR,
                            get_huid(l_proc),
                            TWO_UINT32_TO_UINT64(
                               l_combined_status,
                               i_state)
                            );

            l_err->addProcedureCallout(HWAS::EPUB_PRC_PHYP_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);

             break;
        }

        TRACFCOMP( g_trac_nvdimm,
                  "notifyNvdimmProtectionChange: 0x%.8X "
                  "NV_STATUS to PHYP: 0x%02X",
                  get_huid(l_proc),
                  l_combined_status );

        // Create the firmware_request request struct to send data
        hostInterfaces::hbrt_fw_msg l_req_fw_msg;
        memset(&l_req_fw_msg, 0, sizeof(l_req_fw_msg));  // clear it all

        // actual msg size (one type of hbrt_fw_msg)
        uint64_t l_req_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                              sizeof(l_req_fw_msg.nvdimm_protection_state);

        // Populate the firmware_request request struct with given data
        l_req_fw_msg.io_type =
                        hostInterfaces::HBRT_FW_MSG_TYPE_NVDIMM_PROTECTION;
        l_req_fw_msg.nvdimm_protection_state.i_procId = l_chipId;
        l_req_fw_msg.nvdimm_protection_state.i_state = l_combined_status;

        // Create the firmware_request response struct to receive data
        hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
        uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
        memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // Make the firmware_request call
        l_err = firmware_request_helper(l_req_fw_msg_size,
                                        &l_req_fw_msg,
                                        &l_resp_fw_msg_size,
                                        &l_resp_fw_msg);

#endif

    } while (0);

    TRACFCOMP( g_trac_nvdimm,
        EXIT_MRK "notifyNvdimmProtectionChange(%.8X, %d) - ERRL %.8X:%.4X",
        get_huid(i_target), i_state,
        ERRL_GETEID_SAFE(l_err), ERRL_GETRC_SAFE(l_err) );

    return l_err;
}

/*
 * @brief Utility function to send the value of
 *   ATTR_NVDIMM_ARMED to the FSP
 */
void send_ATTR_NVDIMM_ARMED( Target* i_nvdimm,
                             ATTR_NVDIMM_ARMED_type& i_val )
{
#ifdef __HOSTBOOT_RUNTIME
    errlHndl_t l_err = nullptr;

    // Send attr to HWSV if at runtime
    AttributeTank::Attribute l_attr = {};
    if( !makeAttribute<ATTR_NVDIMM_ARMED>
        (i_nvdimm, l_attr) )
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"send_ATTR_NVDIMM_ARMED() Could not create Attribute");
        /*@
         *@errortype
         *@reasoncode       NVDIMM_CANNOT_MAKE_ATTRIBUTE
         *@severity         ERRORLOG_SEV_PREDICTIVE
         *@moduleid         SEND_ATTR_NVDIMM_ARMED
         *@devdesc          Couldn't create an Attribute to send the data
         *                  to the FSP
         *@custdesc         NVDIMM encryption error
         */
        l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_PREDICTIVE,
                            SEND_ATTR_NVDIMM_ARMED,
                            NVDIMM_CANNOT_MAKE_ATTRIBUTE,
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
        l_err->collectTrace(NVDIMM_COMP_NAME);
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    else
    {
        std::vector<TARGETING::AttributeTank::Attribute> l_attrList;
        l_attrList.push_back(l_attr);
        l_err = sendAttributes( l_attrList );
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"send_ATTR_NVDIMM_ARMED() Error sending ATTR_NVDIMM_ARMED down to FSP");
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit( l_err, NVDIMM_COMP_ID );
        }
    }
#endif //__HOSTBOOT_RUNTIME
}


} // end NVDIMM namespace
