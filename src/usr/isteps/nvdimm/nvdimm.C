/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimm.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
#include <errl/errludlogregister.H>
#include <errl/errludstring.H>
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
#include "errlud_nvdimm.H"
#include "nvdimmErrorLog.H"
#include <isteps/nvdimm/nvdimm.H>
#include <vpd/spdenums.H>
#include <secureboot/trustedbootif.H>
#include <targeting/common/targetUtil.H>
#ifdef __HOSTBOOT_RUNTIME
#include <runtime/hbrt_utilities.H>
#include <targeting/runtime/rt_targeting.H>
#else
#include <initservice/istepdispatcherif.H>
#endif

using namespace TARGETING;
using namespace DeviceFW;
using namespace EEPROM;
using namespace ERRORLOG;

trace_desc_t* g_trac_nvdimm = NULL;
TRAC_INIT(&g_trac_nvdimm, NVDIMM_COMP_NAME, 2*KILOBYTE);

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
#define SPLIT_SIZE 512
#define BUFFER_SIZE 100


namespace NVDIMM
{
#define NUM_OFFSET 2

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
static constexpr uint8_t NV_STATUS_UNPROTECTED_CLR   = 0xFE;
static constexpr uint8_t NV_STATUS_ENCRYPTION_SET    = 0x10;
static constexpr uint8_t NV_STATUS_ENCRYPTION_CLR    = 0xEF;
static constexpr uint8_t NV_STATUS_ERASE_VERIFY_SET  = 0x20;
static constexpr uint8_t NV_STATUS_ERASE_VERIFY_CLR  = 0xDF;
static constexpr uint8_t NV_STATUS_POSSIBLY_UNPROTECTED_SET = 0x40;

// NVDIMM key consts
static constexpr size_t NUM_KEYS_IN_ATTR = 3;
static constexpr size_t MAX_TPM_SIZE = 34;
static constexpr uint8_t KEY_TERMINATE_BYTE = 0x00;
static constexpr uint8_t KEY_ABORT_BYTE = 0xFF;

// NVDIMM CSAVE_FAIL_INFO1 Bit mask
// Currently only bits 1:6 need to be checked during init
static constexpr uint8_t CSAVE_FAIL_BITS_MASK = 0x7E;

// LOG PAGE INFO
static constexpr size_t VENDOR_LOG_UNIT_SIZE = 256;
static constexpr size_t VENDOR_LOG_BLOCK_SIZE = 32;
static constexpr size_t VENDOR_BLOCK_DATA_BYTES = 32;

// TYPED_BLOCK_DATA
static constexpr uint8_t VENDOR_DATA_TYPE = 0x04;
static constexpr uint8_t VENDOR_DEFAULT = 0x00;
static constexpr uint8_t FIRMWARE_IMAGE_DATA = 0x02;

// Commands to OPERATIONAL_UNIT_OPS_CMD
static constexpr uint8_t GET_OPERATIONAL_UNIT = 0x01;
static constexpr uint8_t GENERATE_OPERATIONAL_UNIT_CKSUM = 0x08;

static constexpr uint8_t MSBIT_SET_MASK = 0x80;
static constexpr uint8_t MSBIT_CLR_MASK = 0x7F;
static constexpr uint8_t OPERATION_SLEEP_SECONDS = 0x1;

// Bit mask for checking the fw slot running
static constexpr uint8_t RUNNING_FW_SLOT = 0xF0;

// NOTE: If the ARM_MAX_RETRY_COUNT is greater than 1 then
//       previous error logs may be lost and not reported
static constexpr size_t ARM_MAX_RETRY_COUNT = 1;
static constexpr uint8_t FW_OPS_UPDATE = 0x04;

// Secure erase verify operations
static constexpr uint8_t ERASE_VERIFY_CLEAR = 0x00;
static constexpr uint8_t ERASE_VERIFY_START = 0xC0;
static constexpr uint8_t ERASE_VERIFY_TRIGGER = 0x80;

#ifndef __HOSTBOOT_RUNTIME
// Warning thresholds
static constexpr uint8_t THRESHOLD_ES_LIFETIME = 0x07;    // 7%
static constexpr uint8_t THRESHOLD_NVM_LIFETIME = 0x31;   // 49%

// 12 bit fixed point temperature in celsius degrees
// with following bit format:
//  [15:13]Reserved
//  [12]Sign 0 = positive, 1 = negative The value of 0 C should be expressed as a positive value
//  [11]128 [10]64 [9]32 [8]16 [7]8 [6]4 [5]2 [4]1 [3]0.5 [2]0.25
//  [1]0.125   Optional for temperature reporting fields; not used for temperature threshold fields
//  [0]0.0625  Optional for temperature reporting fields; not used for temperature threshold fields
static constexpr uint8_t THRESHOLD_ES_TEMP_HIGH_1 = 0x03; // 52.5 C
static constexpr uint8_t THRESHOLD_ES_TEMP_HIGH_0 = 0x48; // 52.5 C
static constexpr uint8_t THRESHOLD_ES_TEMP_LOW_1 = 0x00;  // 2.5 C
static constexpr uint8_t THRESHOLD_ES_TEMP_LOW_0 = 0x28;  // 2.5 C
#endif

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
                                    DEVICE_NVDIMM_RAW_ADDRESS(l_reg_addr));
    }while(0);

    if (l_err)
    {
        nvdimmAddPage4Regs(i_nvdimm,l_err);
    }

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
                                    DEVICE_NVDIMM_RAW_ADDRESS(l_reg_addr));
    }while(0);

    if (l_err)
    {
        nvdimmAddPage4Regs(i_nvdimm,l_err);
    }

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
        // Make sure NSTD_VAL_RESTORED (content preserved) is unset before setting NSTD_VAL_ERASED
        // (data not preserved) or NSTD_VAL_SR_FAILED (error preserving data)
        case NSTD_ERR:
        case NSTD_VAL_ERASED:
        case NSTD_VAL_SR_FAILED:
            l_statusFlag &= NSTD_VAL_RESTORED_MASK;
            l_statusFlag |= i_status_flag;
            break;

        // If the content preserved(restore sucessfully), make sure
        // NSTD_VAL_ERASED (not preserved) and NSTD_VAL_SR_FAILED (error preserving)
        // are unset before setting this flag.
        case NSTD_VAL_RESTORED:
            l_statusFlag &= (NSTD_VAL_ERASED_MASK & NSTD_VAL_SR_FAILED_MASK);
            l_statusFlag |= i_status_flag;
            break;

        case NSTD_VAL_DISARMED:
            l_statusFlag |= i_status_flag;
            break;

        // Error detected but save/restore might work. May coexsit with other bits.
        case NSTD_ERR_VAL_SR:
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
    nvdimm_reg_t l_RegInfo;
    uint8_t l_data;
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

        // Convert to ms for polling and double the value to avoid edge condition
        uint32_t l_nvm_init_time_ms = l_nvm_init_time * MS_PER_SEC * 2;
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

            // Collect available status registers for error log
            do
            {
                // Read and save NVDIMM_READY for traces
                l_err = nvdimmReadReg(i_nvdimm, NVDIMM_READY, l_data);
                if(l_err)
                {
                    errlCommit( l_err, NVDIMM_COMP_ID );
                    break;
                }
                l_RegInfo.NVDimm_Ready = l_data;

                // Read and save MODULE_HEALTH for traces
                l_err = nvdimmReadReg(i_nvdimm, MODULE_HEALTH, l_data);
                if(l_err)
                {
                    errlCommit( l_err, NVDIMM_COMP_ID );
                    break;
                }
                l_RegInfo.Module_Health = l_data;

                // Read and save MODULE_HEALTH_STATUS0 for traces
                l_err = nvdimmReadReg(i_nvdimm, MODULE_HEALTH_STATUS0, l_data);
                if(l_err)
                {
                    errlCommit( l_err, NVDIMM_COMP_ID );
                    break;
                }
                l_RegInfo.Module_Health_Status0 = l_data;

                // Read and save MODULE_HEALTH_STATUS1 for traces
                l_err = nvdimmReadReg(i_nvdimm, MODULE_HEALTH_STATUS1, l_data);
                if(l_err)
                {
                    errlCommit( l_err, NVDIMM_COMP_ID );
                    break;
                }
                l_RegInfo.Module_Health_Status1 = l_data;

            }while(0);

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
            l_err->addHwCallout( i_nvdimm,
                                   HWAS::SRCI_PRIORITY_HIGH,
                                   HWAS::DECONFIG,
                                   HWAS::GARD_Fatal);

            // Add Register Traces to error log
            NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);
            nvdimmAddPage4Regs(i_nvdimm,l_err);
            nvdimmAddVendorLog(i_nvdimm, l_err);
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
        nvdimmAddPage4Regs(i_nvdimm,l_err);
        nvdimmAddVendorLog(i_nvdimm, l_err);
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
    nvdimm_reg_t l_RegInfo = nvdimm_reg_t();

    l_err = nvdimmPollStatus ( i_nvdimm, SAVE, o_poll);

    if (l_err)
    {
        errlCommit(l_err, NVDIMM_COMP_ID);

        /*@
         *@errortype
         *@reasoncode       NVDIMM_BACKUP_TIMEOUT
         *@severity         ERRORLOG_SEV_PREDICTIVE
         *@moduleid         NVDIMM_POLL_BACKUP
         *@userdata1[0:31]  Related ops (0xff = NA)
         *@userdata1[32:63] Target Huid
         *@devdesc          Encountered timeout while performing NVDIMM Restore operation
         *@custdesc         NVDIMM timed out
         */
        l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                         NVDIMM_POLL_BACKUP,
                                         NVDIMM_BACKUP_TIMEOUT,
                                         NVDIMM_SET_USER_DATA_1(SAVE, TARGETING::get_huid(i_nvdimm)),
                                         ERRORLOG::ErrlEntry::NO_SW_CALLOUT  );

        l_err->collectTrace( NVDIMM_COMP_NAME );
        nvdimmAddVendorLog(i_nvdimm, l_err);

        // Collect register data for FFDC Traces
        nvdimmTraceRegs ( i_nvdimm, l_RegInfo );
        nvdimmAddPage4Regs(i_nvdimm,l_err);

        // Add reg traces to the error log
        NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);
    }

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
    nvdimm_reg_t l_RegInfo = nvdimm_reg_t();

    l_err = nvdimmPollStatus ( i_nvdimm, RESTORE, o_poll );

    if (l_err)
    {
        errlCommit(l_err, NVDIMM_COMP_ID);

        /*@
         *@errortype
         *@reasoncode       NVDIMM_RESTORE_TIMEOUT
         *@severity         ERRORLOG_SEV_PREDICTIVE
         *@moduleid         NVDIMM_POLL_RESTORE
         *@userdata1[0:31]  Related ops (0xff = NA)
         *@userdata1[32:63] Target Huid
         *@devdesc          Encountered timeout while performing NVDIMM Restore operation
         *@custdesc         NVDIMM timed out
         */
        l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                         NVDIMM_POLL_RESTORE,
                                         NVDIMM_RESTORE_TIMEOUT,
                                         NVDIMM_SET_USER_DATA_1(RESTORE, TARGETING::get_huid(i_nvdimm)),
                                         ERRORLOG::ErrlEntry::NO_SW_CALLOUT  );

        l_err->collectTrace( NVDIMM_COMP_NAME );

        // May have to move the error handling to the caller
        // as different op could have different error severity
        l_err->addPartCallout( i_nvdimm,
                               HWAS::NV_CONTROLLER_PART_TYPE,
                               HWAS::SRCI_PRIORITY_HIGH);

        // Collect register data for FFDC Traces
        nvdimmTraceRegs ( i_nvdimm, l_RegInfo );
        nvdimmAddPage4Regs(i_nvdimm,l_err);
        nvdimmAddVendorLog(i_nvdimm, l_err);

        // Add reg traces to the error log
        NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);
    }

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

    l_err = nvdimmPollStatus( i_nvdimm, ERASE, o_poll);

    if (l_err)
    {
        errlCommit(l_err, NVDIMM_COMP_ID);

        /*@
         *@errortype
         *@reasoncode       NVDIMM_ERASE_TIMEOUT
         *@severity         ERRORLOG_SEV_PREDICTIVE
         *@moduleid         NVDIMM_POLL_ERASE
         *@userdata1[0:31]  Related ops (0xff = NA)
         *@userdata1[32:63] Target Huid
         *@devdesc          Encountered timeout while performing NVDIMM Restore operation
         *@custdesc         NVDIMM timed out
         */
        l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                         NVDIMM_POLL_ERASE,
                                         NVDIMM_ERASE_TIMEOUT,
                                         NVDIMM_SET_USER_DATA_1(ERASE, TARGETING::get_huid(i_nvdimm)),
                                         ERRORLOG::ErrlEntry::NO_SW_CALLOUT  );

        l_err->collectTrace( NVDIMM_COMP_NAME );
        nvdimmAddPage4Regs(i_nvdimm,l_err);
        nvdimmAddVendorLog(i_nvdimm, l_err);
    }

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

    l_err = nvdimmPollStatus( i_nvdimm, CHARGE, o_poll );

    l_err->addPartCallout( i_nvdimm,
                           HWAS::NV_CONTROLLER_PART_TYPE,
                           HWAS::SRCI_PRIORITY_HIGH);

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
    uint8_t l_data = 0x0;
    nvdimm_reg_t l_RegInfo = nvdimm_reg_t();

    do
    {

        l_err = nvdimmWriteReg(i_nvdimm, SET_ES_POLICY_CMD, ES_DEV_MANAGE);

        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_VAL_DISARMED);
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
            nvdimmSetStatusFlag(i_nvdimm, NSTD_VAL_DISARMED);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmSetESPolicy() nvdimm[%X]"
                      "failed to read ES register!",get_huid(i_nvdimm));
            break;
        }

        if (((l_data & ES_SUCCESS) != ES_SUCCESS) || ((l_data & ES_POLICY_ERROR) == ES_POLICY_ERROR))
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

            // Read relevant regs for trace data
            nvdimmTraceRegs(i_nvdimm, l_RegInfo);
            nvdimmAddPage4Regs(i_nvdimm,l_err);
            nvdimmAddVendorLog(i_nvdimm, l_err);

            // Add reg traces to the error log
            NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);
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

void maskMbacalfir(TARGETING::Target* i_nvdimm, uint64_t i_orMaskData)
{
    errlHndl_t l_err = nullptr;
    TargetHandleList l_mcaList;
    uint64_t l_writeData;
    uint32_t l_writeAddress;
    size_t l_writeSize = sizeof(l_writeData);

    getParentAffinityTargets(l_mcaList, i_nvdimm, CLASS_UNIT, TYPE_MCA);
    assert(l_mcaList.size(), "maskMbacalfir() failed to find parent MCA.");

    l_writeAddress = MBACALFIR_OR_MASK_REG;
    l_writeData = i_orMaskData;
    l_err = deviceWrite(l_mcaList[0], &l_writeData, l_writeSize,
                        DEVICE_SCOM_ADDRESS(l_writeAddress));
    if(l_err)
    {
        TRACFCOMP(g_trac_nvdimm,
            ERR_MRK "Failed to mask MBACALFIR 0x%016llX using address "
            "0x%08x on NVDIMM 0x%08X MCA 0x%08X",
            i_orMaskData, l_writeAddress, get_huid(i_nvdimm),
            get_huid(l_mcaList[0]));
        l_err->collectTrace(NVDIMM_COMP_NAME);
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
}

#ifndef __HOSTBOOT_RUNTIME
/**
 * @brief This function handles all the restore related operations.
 *        SRE -> restore -> SRX/RCD/MRS
 *
 * @param[in,out] io_nvdimmList - list of nvdimms. Each nvdimm is removed
 *                from the list after a successful restore. Leftover nvdimm
 *                is returned to the caller for error handling.
 *
 * @param[in] i_mpipl - MPIPL mode
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmRestore(TargetHandleList& io_nvdimmList, uint8_t &i_mpipl)
{
    errlHndl_t l_err = nullptr;
    uint8_t l_rstrValid;
    uint32_t l_poll = 0;
    TargetHandleList l_nvdimmList = io_nvdimmList;

    do
    {
        // Put NVDIMM into self-refresh
        for (TargetHandleList::iterator it = io_nvdimmList.begin();
             it != io_nvdimmList.end();)
        {

            // Default state during boot is unarmed, therefore not preserved
            nvdimmSetStatusFlag(*it, NSTD_VAL_DISARMED);

            TargetHandleList l_mcaList;
            getParentAffinityTargets(l_mcaList, *it, CLASS_UNIT, TYPE_MCA);
            assert(l_mcaList.size(), "nvdimmRestore() failed to find parent MCA.");

            fapi2::Target<fapi2::TARGET_TYPE_MCA> l_fapi_mca(l_mcaList[0]);

            // Before we do anything, check if we are in mpipl. If we are, make sure ddr_resetn
            // is de-asserted before kicking off the restore
            if (i_mpipl)
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimmRestore(): in MPIPL");

                // Call init for error checking skipped in the SAVE step
                nvdimm_init(*it);

                FAPI_INVOKE_HWP(l_err, mss::ddr_resetn, l_fapi_mca, HIGH);

                if (l_err)
                {
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore() HUID[%X] i_mpipl[%u] failed to de-assert resetn!",
                              get_huid(*it), i_mpipl);
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
                    l_err->collectTrace( NVDIMM_COMP_NAME );
                    ERRORLOG::errlCommit(l_err, NVDIMM_COMP_ID);
                }

            }

            // Self-refresh is done at the port level
            FAPI_INVOKE_HWP(l_err, mss::nvdimm::self_refresh_entry, l_fapi_mca);

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore() HUID[%X] self_refresh_entry failed!",
                          get_huid(*it));
                break;
            }
            it++;
        }

        if (l_err)
        {
            break;
        }

        // Kick off the restore on each nvdimm in the nvdimm list
        for (const auto & l_nvdimm : io_nvdimmList)
        {
            l_err = nvdimmWriteReg(l_nvdimm, NVDIMM_FUNC_CMD, RESTORE_IMAGE);
            if (l_err)
            {
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
        for (const auto & l_nvdimm : io_nvdimmList)
        {
            // Since we kicked off the restore on all the modules at once, the restore
            // should complete on all of the modules in one restore window. Use the
            // polled time from the previous nvdimm as the offset for the next one.
            l_err = nvdimmPollRestoreDone(l_nvdimm, l_poll);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X], error restoring!",
                          get_huid(l_nvdimm));
                break;
            }
        }

        if (l_err)
        {
            break;
        }

        // Check for restore errors
        for (TargetHandleList::iterator it = io_nvdimmList.begin();
             it != io_nvdimmList.end();)
        {
            l_err = nvdimmGetRestoreValid(*it, l_rstrValid);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore Target[%X] error validating restore status!",
                          get_huid(*it));
                break;
            }

            if ((l_rstrValid & RSTR_ERROR) == RSTR_ERROR)
            {

                TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X] restore failed due to errors",
                          get_huid(*it));
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
                            get_huid(*it),
                            0x0,
                            ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
                nvdimmAddPage4Regs(*it,l_err);
                nvdimmAddVendorLog(*it, l_err);
                break;
            }

            // Exit self-refresh
            TargetHandleList l_mcaList;
            getParentAffinityTargets(l_mcaList, *it, CLASS_UNIT, TYPE_MCA);
            assert(l_mcaList.size(), "nvdimmRestore() failed to find parent MCA.");

            fapi2::Target<fapi2::TARGET_TYPE_MCA> l_fapi_mca(l_mcaList[0]);

            // This is done again at the port level
            // Post restore consists of exiting self-refresh, restoring MRS/RCD, and running ZQCAL
            FAPI_INVOKE_HWP(l_err, mss::nvdimm::post_restore_transition, l_fapi_mca);

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmRestore() HUID[%X] post_restore_transition failed!",
                          get_huid(*it));
                nvdimmAddPage4Regs(*it,l_err);
                break;
            }
            else
            {
                // Restore success!
                // Remove dimm from list for error handling
                it = io_nvdimmList.erase(it);
            }
        }

        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmRestore() HUID[%X] encounrterd an error during restore");
            break;
        }

        if (i_mpipl)
        {
            for (const auto & l_nvdimm : l_nvdimmList)
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
                    err->collectTrace( NVDIMM_COMP_NAME );
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
 * @brief This function checks the status and success of an erase
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 * @param[in] i_statusOnly - check just the status register (not the image)
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmEraseCheck(Target *i_nvdimm, bool i_statusOnly)
{
    errlHndl_t l_err = nullptr;
    nvdimm_reg_t l_RegInfo;
    uint8_t l_data = 0;
    bool l_valid = false;

    // Erase happens one module at a time. No need to set any offset on the counter
    uint32_t l_poll = 0;
    l_err = nvdimmPollEraseDone(i_nvdimm, l_poll);

    // Add part callout, currently all erase calls have same callout
    // Dump traces to the error log if error exists
    if (l_err)
    {
        // For both Erase timeout and Erase fail
        // Callout nvdimm on high, gard and deconfig
        l_err->addHwCallout( i_nvdimm,
                             HWAS::SRCI_PRIORITY_HIGH,
                             HWAS::DECONFIG,
                             HWAS::GARD_Fatal);

        // Collect register data for FFDC Traces
        nvdimmTraceRegs ( i_nvdimm, l_RegInfo );
        nvdimmAddPage4Regs(i_nvdimm,l_err);

        // Add reg traces to the error log
        NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);
    }
    else
    {
        do
        {
            // Read Erase Status register
            l_err = nvdimmReadReg ( i_nvdimm, ERASE_STATUS, l_data);
            if (l_err)
            {
                nvdimmSetStatusFlag(i_nvdimm, NSTD_VAL_DISARMED);
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm[%X], failed to read erase status",
                          get_huid(i_nvdimm));
                break;
            }

            if (i_statusOnly)
            {
                // assume image is cleared, do not check
                TRACFCOMP(g_trac_nvdimm, "nvdimmEraseCheck() - skipping image check for nvdimm[%X]",
                    get_huid(i_nvdimm));
                l_valid = false;
            }
            else
            {
                // Check for a valid image
                l_err  = nvdimmValidImage( i_nvdimm, l_valid );
                if (l_err)
                {
                    nvdimmSetStatusFlag(i_nvdimm, NSTD_VAL_DISARMED);
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm[%X] Failed to detect valid image",
                              get_huid(i_nvdimm));
                    break;
                }
            }

            if ( (l_data & ERASE_ERROR) || l_valid )
            {
                nvdimmSetStatusFlag(i_nvdimm, NSTD_VAL_DISARMED);
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm[%X] NVDimm Erase failed due to error (ERASE_STATUS: 0x%02X, Image %s)",
                          get_huid(i_nvdimm), l_data, l_valid?"not erased":"erased");
                /*@
                 *@errortype
                 *@reasoncode       NVDIMM_ERASE_ERROR
                 *@severity         ERRORLOG_SEV_PREDICTIVE
                 *@moduleid         NVDIMM_CHECK_ERASE
                 *@userdata1[0:31]  ERASE_STATUS register
                 *@userdata1[32:63] Target Huid
                 *@userdata2        ERASE_ERROR status bit
                 *@userdata2        Image validity
                 *@devdesc          Encountered error during image erase function
                 *                   on NVDIMM. Check error register trace for details
                 *@custdesc         NVDIMM error during nvdimm erase
                 */
                l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                                 NVDIMM_CHECK_ERASE,
                                                 NVDIMM_ERASE_ERROR,
                                                 NVDIMM_SET_USER_DATA_1(l_data, get_huid(i_nvdimm)),
                                                 NVDIMM_SET_USER_DATA_1(ERASE_ERROR, l_valid),
                                                 ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

                l_err->collectTrace( NVDIMM_COMP_NAME );
                break;
            }

        } while(0);

        if(l_err)
        {
           // Callout nvdimm on high and gard. No deconfig to prevent
           // re-ipl for ESS config since this is called during IPL
           l_err->addHwCallout( i_nvdimm,
                                HWAS::SRCI_PRIORITY_HIGH,
                                HWAS::NO_DECONFIG,
                                HWAS::GARD_Fatal);

           // Collect register data for FFDC Traces
           nvdimmTraceRegs ( i_nvdimm, l_RegInfo );
           nvdimmAddPage4Regs(i_nvdimm,l_err);

           // Add reg traces to the error log
           NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);
        }
    }

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

        // Poll for success, then check the status and image
        l_err = nvdimmEraseCheck(i_nvdimm, false);

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
            nvdimmAddVendorLog(i_nvdimm, l_err);

            // Failure to open page most likely means problem with
            // the NV controller.
            l_err->addPartCallout( i_nvdimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            nvdimmAddPage4Regs(i_nvdimm,l_err);
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

                nvdimmSetStatusFlag(*it, NSTD_VAL_SR_FAILED);
                nvdimmAddPage4Regs(*it,l_err);
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
    bool l_valid = false;
    bool l_continue = true;
    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget( l_sys );
    assert(l_sys, "nvdimm_restore: no TopLevelTarget");
    uint8_t l_mpipl = l_sys->getAttr<ATTR_IS_MPIPL_HB>();
    nvdimm_reg_t l_RegInfo = nvdimm_reg_t();
    TargetHandleList l_nvdimm_restore_list = i_nvdimmList;
    uint8_t l_rstrValid;

    do
    {
        // Check MPIPL case first to make sure any on-going backup is complete
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
                    nvdimmSetStatusFlag(l_nvdimm, NSTD_VAL_ERASED);
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_restore() nvdimm[%X], error backing up the DRAM!",
                              get_huid(l_nvdimm));
                    errlCommit(l_err, NVDIMM_COMP_ID);
                    break;
                }
            }
        }

        // Compile a list of nvdimms with valid image
        // TODO: Reach out to RAS on how to handle odd number of nvdimms
        // since we always operate in pairs
        for (TargetHandleList::iterator it = l_nvdimm_restore_list.begin();
             it != l_nvdimm_restore_list.end();)
        {
            // Check for a valid image
            l_err  = nvdimmValidImage( *it, l_valid );
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_restore() nvdimm[%X] Failed to detect valid image", get_huid(*it));
                errlCommit(l_err, NVDIMM_COMP_ID);
            }

            // Remove it from the restore list if there is no valid image
            if (!l_valid)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_restore() nvdimm[%X] No valid image discovered", get_huid(*it));

                // Set ATTR NV STATUS FLAG to Erased
                nvdimmSetStatusFlag(*it, NSTD_VAL_ERASED);
                it = l_nvdimm_restore_list.erase(it);

            }
            else
            {
                it++;
            }
        }

        // Exit if there is nothing to restore
        if (l_nvdimm_restore_list.empty())
        {
            break;
        }

        // Start the restore
        l_err = nvdimmRestore(l_nvdimm_restore_list, l_mpipl);

        // Check if restore completed successfully
        if (l_err)
        {
            const auto l_nvdimm = l_nvdimm_restore_list.front();

            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_restore() - Failing nvdimmRestore()");
            nvdimmSetStatusFlag(l_nvdimm, NSTD_VAL_SR_FAILED);

            // Invalid restore could be due to dram not in self-refresh
            // or controller issue. Data should not be trusted at this point
            l_err->addHwCallout( l_nvdimm,
                                   HWAS::SRCI_PRIORITY_HIGH,
                                   HWAS::DECONFIG,
                                   HWAS::GARD_Fatal);

            // Collect register data for FFDC Traces
            nvdimmTraceRegs ( l_nvdimm, l_RegInfo );
            nvdimmAddPage4Regs(l_nvdimm,l_err);

            // Add reg traces to the error log
            NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);
            break;
        }

        // Check health status registers and exit if required
        for (const auto & l_nvdimm : i_nvdimmList)
        {
            // Post restore health check. l_continue gets set per the health check logic
            // and used later to determine if boot shall continue on error condition
            l_err = nvdimmHealthStatusCheck( l_nvdimm, HEALTH_RESTORE, l_continue );

            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_restore() nvdimm[%X] failed during health status check", get_huid(l_nvdimm));
                errlCommit( l_err, NVDIMM_COMP_ID );
                if (!l_continue)
                {
                    break;
                }
            }

            // Make sure the restore is valid
            l_err = nvdimmGetRestoreValid(l_nvdimm, l_rstrValid);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_restore Target[%X] error validating restore status!",
                          get_huid(l_nvdimm));
                break;
            }

            if ((l_rstrValid & RSTR_SUCCESS) == RSTR_SUCCESS)
            {
                // Restore success!
                nvdimmSetStatusFlag(l_nvdimm, NSTD_VAL_RESTORED);
            }

        }

    }while(0);

    if (l_err)
    {
        errlCommit(l_err, NVDIMM_COMP_ID);
    }

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
    bool l_continue = true;
    uint8_t l_data = 0;
    uint8_t l_failinfo0 = 0;
    uint8_t l_failinfo1 = 0;
    nvdimm_reg_t l_RegInfo;
    uint32_t l_poll = 0;

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

        // Set ATTR_NV_STATUS_FLAG to default disarmed state
        l_err = notifyNvdimmProtectionChange(i_nvdimm, NVDIMM_DISARMED);
        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
            errlCommit(l_err, NVDIMM_COMP_ID);
        }

        // Check if the nvdimm ready status
        l_err = nvdimmReady(i_nvdimm);

        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], controller not ready",
                      get_huid(i_nvdimm));
            break;
        }

        // Check if the firmware slot is 0
        l_err = nvdimmGetRunningSlot(i_nvdimm, l_data);
        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], failed to read slot info",
                      get_huid(i_nvdimm));
            break;
        }

        // try a reset to change to slot 1
        if (l_data == 0)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimm_init() nvdimm[%X], attempting recovery from running on slot0",
                      get_huid(i_nvdimm));

            // select slot1 to come up on
            TRACUCOMP(g_trac_nvdimm, "nvdimm_init() nvdimm[%X], select slot1 by writing 0x01 to FW_SLOT_INFO(0x%08X)",
                      get_huid(i_nvdimm), FW_SLOT_INFO);
            l_err = nvdimmWriteReg(i_nvdimm, FW_SLOT_INFO, 0x01);
            if (l_err)
            {
                nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], failed to set slot info to 1",
                      get_huid(i_nvdimm));
                break;
            }

            TRACUCOMP(g_trac_nvdimm, "nvdimm_init() nvdimm[%X], reset controller now",
                      get_huid(i_nvdimm));
            l_err = nvdimmResetController(i_nvdimm);
            if (l_err)
            {
                nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], failed reset for slot change",
                      get_huid(i_nvdimm));
                break;
            }

            // re-read the firmware slot
            TRACUCOMP(g_trac_nvdimm, "nvdimm_init() nvdimm[%X], re-read slot info",
                      get_huid(i_nvdimm));
            l_err = nvdimmGetRunningSlot(i_nvdimm, l_data);
            if (l_err)
            {
                nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], failed to re-read slot info",
                          get_huid(i_nvdimm));
                break;
            }
        }
        TRACFCOMP(g_trac_nvdimm, "nvdimm_init() nvdimm[%X], current slot running %d",
                  get_huid(i_nvdimm), l_data);

        if (l_data == 0)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_VAL_SR);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], running on fw slot 0",
                      get_huid(i_nvdimm));
            /*@
             *@errortype
             *@reasoncode       NVDIMM_INVALID_FW_SLOT
             *@severity         ERRORLOG_SEV_PREDICTIVE
             *@moduleid         NVDIMM_CHECK_FW_SLOT
             *@userdata1[0:31]  Slot running
             *@userdata1[32:63] Target Huid
             *@userdata2        <UNUSED>
             *@devdesc          Encountered error when checking the firmware slot running
             *                   on NVDIMM. Firmware is running on slot 0 instead of 1
             *@custdesc         NVDIMM incorrect firmware slot
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_CHECK_FW_SLOT,
                                             NVDIMM_INVALID_FW_SLOT,
                                             NVDIMM_SET_USER_DATA_1(l_data, get_huid(i_nvdimm)),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace( NVDIMM_COMP_NAME );

            // Add callout of nvdimm with no deconfig/gard
            l_err->addHwCallout( i_nvdimm,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL);

            errlCommit(l_err, NVDIMM_COMP_ID);
        }

        // Get the timeout values for the major ops at init
        l_err = nvdimmGetTimeoutVal(i_nvdimm);
        if (l_err)
        {
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], error retrieving timeout values",
                      get_huid(i_nvdimm));
            break;
        }

        // Check for Erase in progress and verify good status
        l_err = nvdimmEraseCheck(i_nvdimm, true);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_init() nvdimm[%X], error checking erase status",
                      get_huid(i_nvdimm));
            break;
        }

        // Check NO_RESET_N bit for power loss without save
        l_err = nvdimmReadReg ( i_nvdimm, CSAVE_FAIL_INFO1, l_data);
        if (l_err)
        {
            break;
        }
        else if ((l_data & NO_RESET_N) == NO_RESET_N)
        {
            // Set ATTR_NV_STATUS_FLAG to partial working as data may persist
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_VAL_SR);
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmInit() nvdimm[%X]"
                                 "failed to save due to power loss!",get_huid(i_nvdimm));
            /*@
             *@errortype
             *@reasoncode       NVDIMM_POWER_SAVE_FAILURE
             *@severity         ERRORLOG_SEV_PREDICTIVE
             *@moduleid         NVDIMM_CHECK_RESETN
             *@userdata1[0:31]  Related ops (0xff = NA)
             *@userdata1[32:63] Target Huid
             *@userdata2        <UNUSED>
             *@devdesc          NO_RESET_N: The NVDIMM experienced a power loss, but no CSAVE
             *                  was triggered since the NVDIMM did not detect an asserted
             *                  RESET_N. If there is a prior predicitve log for OCC in safe
             *                  mode, than this would be the reason for NO_RESET_N. Otherwise
             *                  there could be a problem with the RESET_N signal between proc
             *                  and NVDIMM.
             *@custdesc         NVDIMM error erasing data image
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_CHECK_RESETN,
                                             NVDIMM_POWER_SAVE_FAILURE,
                                             NVDIMM_SET_USER_DATA_1(l_data, get_huid(i_nvdimm)),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace( NVDIMM_COMP_NAME );
            nvdimmAddVendorLog(i_nvdimm, l_err);

            // Failure to erase could mean internal NV controller error and/or
            // HW error on nand flash. NVDIMM will lose persistency if failed to
            // erase nand flash
            l_err->addHwCallout( i_nvdimm,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL);

            // Collect register data for FFDC Traces
            nvdimmTraceRegs ( i_nvdimm, l_RegInfo );
            nvdimmAddPage4Regs(i_nvdimm,l_err);

            // Add reg traces to the error log
            NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);

            errlCommit(l_err, NVDIMM_COMP_ID);
        }
        else
        {
            // Check save progress
            l_err = nvdimmPollBackupDone(i_nvdimm, l_poll);
            if (l_err)
            {
                // May have to move the error handling to the caller
                // as different op could have different error severity
                l_err->addHwCallout( i_nvdimm,
                                       HWAS::SRCI_PRIORITY_HIGH,
                                       HWAS::DECONFIG,
                                       HWAS::GARD_Fatal);

                TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_int() nvdimm[%X], error backing up the DRAM!",
                          get_huid(i_nvdimm));
                break;
            }
        }

        // Check CSAVE FAIL INFO registers for fail errors
        l_err = nvdimmReadReg( i_nvdimm, CSAVE_FAIL_INFO0, l_failinfo0 );
        if (l_err)
        {
            break;
        }
        l_err = nvdimmReadReg ( i_nvdimm, CSAVE_FAIL_INFO1, l_failinfo1 );
        if (l_err)
        {
            break;
        }
        // Apply mask for relevant 1:6 bits to failinfo1
        l_failinfo1 &= CSAVE_FAIL_BITS_MASK;

        // Check CSAVE_STATUS Register
        l_err = nvdimmReadReg( i_nvdimm, CSAVE_STATUS, l_data );
        if (l_err)
        {
            break;
        }
        else if ((l_data == SAVE_ERROR) && ((l_failinfo0 != ZERO) || (l_failinfo1 != ZERO)))
        {
            /*@
             *@errortype
             *@reasoncode       NVDIMM_CSAVE_ERROR
             *@severity         ERRORLOG_SEV_PREDICTIVE
             *@moduleid         NVDIMM_CHECK_CSAVE
             *@userdata1[0:31]  Related ops (0xff = NA)
             *@userdata1[32:63] Target Huid
             *@userdata2        <UNUSED>
             *@devdesc          Encountered error saving during catastrophic save
             *                   on NVDIMM. Check error register trace for details
             *@custdesc         NVDIMM error during Catastrophic Save
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_CHECK_CSAVE,
                                             NVDIMM_CSAVE_ERROR,
                                             NVDIMM_SET_USER_DATA_1(l_data, get_huid(i_nvdimm)),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace( NVDIMM_COMP_NAME );

            // Collect register data for FFDC Traces
            nvdimmTraceRegs ( i_nvdimm, l_RegInfo );
            nvdimmAddPage4Regs(i_nvdimm,l_err);
            nvdimmAddVendorLog(i_nvdimm, l_err);

            // Add reg traces to the error log
            NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);

            // Check if the image is still valid
            if ( l_RegInfo.CSave_Info != VALID_IMAGE )
            {
                // Callout and gard dimm if image is not valid
                l_err->addHwCallout( i_nvdimm,
                                       HWAS::SRCI_PRIORITY_HIGH,
                                       HWAS::DECONFIG,
                                       HWAS::GARD_Fatal);
                break;
            }
            else
            {
                // Callout dimm without gard if image is valid
                l_err->addHwCallout( i_nvdimm,
                                       HWAS::SRCI_PRIORITY_LOW,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_NULL);

                // Set ATTR_NV_STATUS_FLAG to partial working as data may persist
                nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_VAL_SR);
                errlCommit(l_err, NVDIMM_COMP_ID);
            }
        }

        // Check Health Status Registers
        l_err = nvdimmHealthStatusCheck(i_nvdimm, HEALTH_SAVE, l_continue);
        if(!l_continue)
        {
            break;
        }

        // Unlock encryption if enabled
        TargetHandleList l_nvdimmTargetList;
        l_nvdimmTargetList.push_back(i_nvdimm);
        NVDIMM::nvdimm_encrypt_unlock(l_nvdimmTargetList);

    }while(0);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_init() nvdimm[%X]",
              get_huid(i_nvdimm));

    if (l_err)
    {
        l_err->collectTrace( NVDIMM_COMP_NAME );
        errlCommit(l_err, NVDIMM_COMP_ID);
    }
}


void nvdimm_thresholds(TARGETING::TargetHandleList &i_nvdimmList)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimm_thresholds()");

    errlHndl_t l_err = nullptr;

    for (const auto & l_nvdimm : i_nvdimmList)
    {
        // Set ES Policy to enable setting the BPM-related threshold values
        l_err = nvdimmSetESPolicy(l_nvdimm);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimm_thresholds() nvdimm[%X] failed to set ES Policy", get_huid(l_nvdimm));

            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module.
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);

            // Callout the nvdimm on high and gard
            l_err->addHwCallout( l_nvdimm,
                                   HWAS::SRCI_PRIORITY_HIGH,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_Fatal);

            errlCommit( l_err, NVDIMM_COMP_ID );
        }

        // ES_LIFETIME_WARNING_THRESHOLD
        l_err = nvdimmWriteReg(l_nvdimm,
                               ES_LIFETIME_WARNING_THRESHOLD,
                               THRESHOLD_ES_LIFETIME);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm,
                      ERR_MRK"nvdimm_thresholds() nvdimm[%X] "
                      "error setting ES_LIFETIME_WARNING_THRESHOLD",
                      get_huid(l_nvdimm));
            errlCommit( l_err, NVDIMM_COMP_ID );
        }

        // NVM_LIFETIME_WARNING_THRESHOLD
        l_err = nvdimmWriteReg(l_nvdimm,
                               NVM_LIFETIME_WARNING_THRESHOLD,
                               THRESHOLD_NVM_LIFETIME);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm,
                      ERR_MRK"nvdimm_thresholds() nvdimm[%X] "
                      "error setting NVM_LIFETIME_WARNING_THRESHOLD",
                      get_huid(l_nvdimm));
            errlCommit( l_err, NVDIMM_COMP_ID );
        }

        // ES_TEMP_WARNING_HIGH_THRESHOLD1
        l_err = nvdimmWriteReg(l_nvdimm,
                               ES_TEMP_WARNING_HIGH_THRESHOLD1,
                               THRESHOLD_ES_TEMP_HIGH_1);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm,
                      ERR_MRK"nvdimm_thresholds() nvdimm[%X] "
                      "error setting ES_TEMP_WARNING_HIGH_THRESHOLD1",
                      get_huid(l_nvdimm));
            errlCommit( l_err, NVDIMM_COMP_ID );
        }

        // ES_TEMP_WARNING_HIGH_THRESHOLD0
        l_err = nvdimmWriteReg(l_nvdimm,
                               ES_TEMP_WARNING_HIGH_THRESHOLD0,
                               THRESHOLD_ES_TEMP_HIGH_0);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm,
                      ERR_MRK"nvdimm_thresholds() nvdimm[%X] "
                      "error setting ES_TEMP_WARNING_HIGH_THRESHOLD0",
                      get_huid(l_nvdimm));
            errlCommit( l_err, NVDIMM_COMP_ID );
        }

        // ES_TEMP_WARNING_LOW_THRESHOLD1
        l_err = nvdimmWriteReg(l_nvdimm,
                               ES_TEMP_WARNING_LOW_THRESHOLD1,
                               THRESHOLD_ES_TEMP_LOW_1);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm,
                      ERR_MRK"nvdimm_thresholds() nvdimm[%X] "
                      "error setting ES_TEMP_WARNING_LOW_THRESHOLD1",
                      get_huid(l_nvdimm));
            errlCommit( l_err, NVDIMM_COMP_ID );
        }

        // ES_TEMP_WARNING_LOW_THRESHOLD0
        l_err = nvdimmWriteReg(l_nvdimm,
                               ES_TEMP_WARNING_LOW_THRESHOLD0,
                               THRESHOLD_ES_TEMP_LOW_0);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm,
                      ERR_MRK"nvdimm_thresholds() nvdimm[%X] "
                      "error setting ES_TEMP_WARNING_LOW_THRESHOLD0",
                      get_huid(l_nvdimm));
            errlCommit( l_err, NVDIMM_COMP_ID );
        }
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimm_thresholds()");
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
            nvdimmAddVendorLog(i_nvdimm, l_err);

            // If nvdimm is not ready for access by now, this is
            // a failing indication on the NV controller
            l_err->addPartCallout( i_nvdimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            nvdimmAddPage4Regs(i_nvdimm,l_err);
        }
    } while(0);

    return l_err;
}


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
                nvdimmAddVendorLog(l_nvdimm, l_err);
                l_err->addPartCallout( l_nvdimm,
                                       HWAS::NV_CONTROLLER_PART_TYPE,
                                       HWAS::SRCI_PRIORITY_HIGH);
                l_err->addHwCallout( l_nvdimm,
                                     HWAS::SRCI_PRIORITY_MED,
                                     HWAS::DELAYED_DECONFIG,
                                     HWAS::GARD_NULL );

                nvdimmAddPage4Regs(l_nvdimm,l_err);
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
                    nvdimmAddVendorLog(i_nvdimm, l_err);
                    l_err->addPartCallout( i_nvdimm,
                                           HWAS::NV_CONTROLLER_PART_TYPE,
                                           HWAS::SRCI_PRIORITY_HIGH);
                    nvdimmAddPage4Regs(i_nvdimm,l_err);
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
                nvdimmAddVendorLog(l_nvdimm, l_err);
                l_err->addPartCallout( l_nvdimm,
                                    HWAS::NV_CONTROLLER_PART_TYPE,
                                    HWAS::SRCI_PRIORITY_HIGH);

                nvdimmAddPage4Regs(l_nvdimm,l_err);
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
            }
            else
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimm_encrypt_enable() nvdimm[%X] encryption is enabled 0x%.02x",get_huid(l_nvdimm),l_encStatus.whole);

                l_err = notifyNvdimmProtectionChange(l_nvdimm,
                                                     ENCRYPTION_ENABLED);
                if (l_err)
                {
                    errlCommit(l_err, NVDIMM_COMP_ID);
                }
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
                nvdimmAddVendorLog(l_nvdimm, l_err);
                l_err->addPartCallout( l_nvdimm,
                                    HWAS::NV_CONTROLLER_PART_TYPE,
                                    HWAS::SRCI_PRIORITY_HIGH);

                nvdimmAddPage4Regs(l_nvdimm,l_err);
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
                nvdimmAddVendorLog(l_nvdimm, l_err);
                l_err->addPartCallout( l_nvdimm,
                                    HWAS::NV_CONTROLLER_PART_TYPE,
                                    HWAS::SRCI_PRIORITY_HIGH);

                nvdimmAddPage4Regs(l_nvdimm,l_err);
                errlCommit( l_err, NVDIMM_COMP_ID );
                nvdimmSetEncryptionError(l_nvdimm);
                l_success = false;
                continue;
            }
            else
            {
                TRACFCOMP(g_trac_nvdimm,"nvdimm_crypto_erase() nvdimm[%X] erase complete 0x%.02x",get_huid(l_nvdimm),l_encStatus.whole);

                l_err = notifyNvdimmProtectionChange(l_nvdimm,
                                                     ENCRYPTION_DISABLED);
                if (l_err)
                {
                    errlCommit(l_err, NVDIMM_COMP_ID);
                }
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
            bool l_set_encryption = false;
            bool l_clr_encryption = false;
            bool l_sev_started = false;
            bool l_sev_completed = false;

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
                case ENCRYPTION_ENABLED:
                    l_set_encryption = true;
                    break;
                case ENCRYPTION_DISABLED:
                    l_clr_encryption = true;
                    break;
                case ERASE_VERIFY_STARTED:
                    l_sev_started = true;
                    break;
                case ERASE_VERIFY_COMPLETED:
                    l_sev_completed = true;
                    break;
                case SEND_NV_STATUS:
                    // no action, just send status
                    break;
                case SBE_ACTIVE:
                    l_armed_state.sbe_active = 1;
                    break;
                case SBE_INACTIVE:
                    l_armed_state.sbe_active = 0;
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
                l_armed_state.sbe_active &&
                !l_armed_state.fatal_error_detected)
            {
                l_nv_status &= NV_STATUS_UNPROTECTED_CLR;
            }

            // Set bit 0 if unprotected nv state
            else
            {
                l_nv_status |= NV_STATUS_UNPROTECTED_SET;
            }

            // Set bit 4 if encryption enabled
            if (l_set_encryption)
            {
                l_nv_status |= NV_STATUS_ENCRYPTION_SET;
            }

            // Clear bit 4 if encryption disabled
            if (l_clr_encryption)
            {
                l_nv_status &= NV_STATUS_ENCRYPTION_CLR;
            }

            // Clear bit 5 if secure erase verify started
            if (l_sev_started)
            {
                l_nv_status &= NV_STATUS_ERASE_VERIFY_CLR;
            }

            // Set bit 5 if secure erase verify comlpleted
            if (l_sev_completed)
            {
                l_nv_status |= NV_STATUS_ERASE_VERIFY_SET;
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

        // Send combined status notification
        // Get the Proc Chip Id
        TARGETING::rtChipId_t l_chipId = 0;

        l_err = TARGETING::getRtTarget(l_proc, l_chipId);
        if(l_err)
        {
            TRACFCOMP( g_trac_nvdimm,
                ERR_MRK"notifyNvdimmProtectionChange: getRtTarget ERROR" );
            break;
        }

        // Check for valid interface
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
                  "NV_STATUS to HYP: 0x%02X",
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
 * @brief Get operational unit operation timeout
 */
errlHndl_t getOperOpsTimeout(TARGETING::Target* i_nvdimm,
                             uint16_t& o_timeout)
{
    errlHndl_t l_err = nullptr;

    do
    {
        // Get timeout lsb
        uint8_t l_lsb = 0;
        l_err = nvdimmReadReg(i_nvdimm,
                              OPERATIONAL_UNIT_OPS_TIMEOUT0,
                              l_lsb);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "getOperOpsTimeout() nvdimm[%X] error reading 0x%X",
                get_huid(i_nvdimm), OPERATIONAL_UNIT_OPS_TIMEOUT0);
            break;
        }

        // Get timeout msb
        uint8_t l_msb = 0;
        l_err = nvdimmReadReg(i_nvdimm,
                              OPERATIONAL_UNIT_OPS_TIMEOUT1,
                              l_msb);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "getOperOpsTimeout() nvdimm[%X] error reading 0x%X",
                get_huid(i_nvdimm), OPERATIONAL_UNIT_OPS_TIMEOUT1);
            break;
        }

        // Bit 7 of the MSB indicates whether the time should
        //   be interpreted in seconds or milliseconds
        //   0 = millisecond
        //   1 = second
        if (l_msb < MSBIT_SET_MASK)
        {
            o_timeout = l_msb;
            o_timeout <<= 8;
            o_timeout += l_lsb;
            o_timeout = o_timeout / MS_PER_SEC;
        }
        else
        {
            l_msb = l_msb & MSBIT_CLR_MASK;
            o_timeout = l_msb;
            o_timeout <<= 8;
            o_timeout += l_lsb;
        }

    } while(0);

    return l_err;
}


/*
 * @brief Wait for operational unit operation to complete
 */
errlHndl_t waitOperOpsComplete(TARGETING::Target* i_nvdimm, uint8_t i_cmd)
{
    errlHndl_t l_err = nullptr;
    bool l_complete = false;
    uint16_t l_timeout = 0;
    uint8_t l_status = 0;

    // Get the timeout
    l_err = getOperOpsTimeout(i_nvdimm, l_timeout);

    do
    {
        // Exit if l_timeout invalid
        if (l_err)
        {
            break;
        }

        // Delay before reading status
        nanosleep( OPERATION_SLEEP_SECONDS, 0 );
        if (OPERATION_SLEEP_SECONDS > l_timeout)
        {
            l_timeout = 0;
        }
        else
        {
            l_timeout = l_timeout - OPERATION_SLEEP_SECONDS;
        }

        // Get timeout cmd status 1
        l_err = nvdimmReadReg(i_nvdimm,
                              NVDIMM_CMD_STATUS1,
                              l_status);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "waitOperOpsComplete() nvdimm[%X] error reading 0x%X",
                get_huid(i_nvdimm), NVDIMM_CMD_STATUS1);
            break;
        }

        if (l_status >= 0x01)
        {
            // If bit 1 is set that means the command is in progress
            // Wait for it to become 0
        }
        else
        {
            l_complete = true;
            break;
        }

    } while(l_timeout > 0);

    // Timed out
    if (!l_err && (l_complete == false) )
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK
            "waitOperOpsComplete() nvdimm[%X] "
            "Timeout waiting for operation 0x%X to complete, "
            "NVDIMM_CMD_STATUS1 0x%X",
            get_huid(i_nvdimm), i_cmd, l_status);

        // Get the timeout value again
        getOperOpsTimeout(i_nvdimm, l_timeout);

        /*@
         *@errortype
         *@reasoncode    NVDIMM_VENDOR_LOG_TIMEOUT
         *@severity      ERRORLOG_SEV_PREDICTIVE
         *@moduleid      NVDIMM_WAIT_OPER_OPS_COMPLETE
         *@userdata1[0:31]    NVDIMM HUID
         *@userdata1[32:63]   OPERATIONAL_UNIT_OPS_CMD
         *@userdata2[0:31]    NVDIMM_CMD_STATUS1
         *@userdata2[32:63]   OPERATIONAL_UNIT_OPS_TIMEOUT
         *@devdesc       NVDIMM timeout reading vendor log
         *@custdesc      NVDIMM logging error
         */
        l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                        NVDIMM_WAIT_OPER_OPS_COMPLETE,
                        NVDIMM_VENDOR_LOG_TIMEOUT,
                        TWO_UINT32_TO_UINT64(
                            get_huid(i_nvdimm),
                            i_cmd
                        ),
                        TWO_UINT32_TO_UINT64(
                           l_status,
                           l_timeout
                        ),
                        ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

        l_err->collectTrace(NVDIMM_COMP_NAME);
        l_err->addPartCallout( i_nvdimm,
                               HWAS::NV_CONTROLLER_PART_TYPE,
                               HWAS::SRCI_PRIORITY_HIGH);
    }

    return l_err;
}


/*
 * @brief Get the vendor log unit
 */
errlHndl_t getLogPerUnit(TARGETING::Target* i_nvdimm,
                         uint16_t i_unitId,
                         std::vector<uint8_t>& o_unitData)
{
    // 3a)  write OPERATIONAL_UNIT_ID0 and OPERATIONAL_UNIT_ID1 with unit_id
    // 3b)  set OPERATIONAL_UNIT_OPS_CMD to GET_OPERATIONAL_UNIT
    // 3c)  wait for NVDIMM_CMD_STATUS1 to return 0
    // 3d)  for (block_id = 0;
    //           block_id < VENDOR_LOG_UNIT_SIZE/BLOCKSIZE;
    //           block_id++)
    // 3da)     Write block_id to BLOCK_ID
    // 3db)     Read TYPED_BLOCK_DATA_BYTE0 to TYPED_BLOCK_DATA_BYTE31
    // 3dc)     Save data to buffer

    errlHndl_t l_err = nullptr;

    do
    {
        // 3a)
        // Write the unit LSB
        l_err = nvdimmWriteReg(i_nvdimm,
                               OPERATIONAL_UNIT_ID0,
                               i_unitId & 0x00FF);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "getLogPerUnit() nvdimm[%X] error writing reg 0x%X to 0x%X",
                get_huid(i_nvdimm), OPERATIONAL_UNIT_ID0, (i_unitId & 0x00FF));
            break;
        }

        // Write the unit MSB
        l_err = nvdimmWriteReg(i_nvdimm,
                               OPERATIONAL_UNIT_ID1,
                               i_unitId >> 8);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "getLogPerUnit() nvdimm[%X] error writing reg 0x%X to 0x%X",
                get_huid(i_nvdimm), OPERATIONAL_UNIT_ID0, (i_unitId >> 8) );
            break;
        }

        // 3b)
        // Write the cmd
        l_err = nvdimmWriteReg(i_nvdimm,
                               OPERATIONAL_UNIT_OPS_CMD,
                               GET_OPERATIONAL_UNIT);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "getLogPerUnit() nvdimm[%X] error writing reg 0x%X to 0x%X",
                get_huid(i_nvdimm), OPERATIONAL_UNIT_OPS_CMD,
                GET_OPERATIONAL_UNIT );
            break;
        }

        // 3c
        l_err = waitOperOpsComplete(i_nvdimm, GET_OPERATIONAL_UNIT);
        if (l_err)
        {
            break;
        }

        // 3d
        for (uint8_t l_blockId = 0;
             l_blockId < (VENDOR_LOG_UNIT_SIZE / VENDOR_LOG_BLOCK_SIZE);
             l_blockId++)
        {
            // 3da
            // Write the block id
            l_err = nvdimmWriteReg(i_nvdimm,
                                   BLOCK_ID,
                                   l_blockId);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK
                    "getLogPerUnit() nvdimm[%X] error writing reg 0x%X to 0x%X",
                    get_huid(i_nvdimm), BLOCK_ID, l_blockId );
                break;
            }

            // 3db
            // Read all the block data
            for (uint16_t l_byteId = TYPED_BLOCK_DATA_BYTE0;
                 l_byteId < (TYPED_BLOCK_DATA_BYTE0 + VENDOR_BLOCK_DATA_BYTES);
                 l_byteId++)
            {
                uint8_t l_data = 0;
                l_err = nvdimmReadReg(i_nvdimm,
                                      l_byteId,
                                      l_data);
                if (l_err)
                {
                    TRACFCOMP(g_trac_nvdimm, ERR_MRK
                        "getLogPerUnit() nvdimm[%X] error reading 0x%X",
                        get_huid(i_nvdimm), l_byteId);
                    break;
                }

                // 3dc
                o_unitData.push_back(l_data);
            } // for byteId

            if (l_err)
            {
                break;
            }
        } // for blockId

    } while(0);

    return l_err;
}


/*
 * @brief Calculate CRC
 */
uint16_t crc16(const uint8_t * i_data, int i_size)
{
    // From JEDEC JESD245B.01 document
    // https://www.jedec.org/standards-documents/docs/jesd245a
    int i, crc;
    crc = 0;
    while (--i_size >= 0)
    {
        crc = crc ^ (int)*i_data++ << 8;
        for (i = 0; i < 8; ++i)
        {
           if (crc & 0x8000)
           {
               crc = crc << 1 ^ 0x1021;
           }
           else
           {
               crc = crc << 1;
           }
        }
    }
    return (crc & 0xFFFF);
}


/*
 * @brief Get operational unit crc
 */
errlHndl_t getOperUnitCrc(TARGETING::Target* i_nvdimm, uint16_t& o_crc)
{
    errlHndl_t l_err = nullptr;

    do
    {
        // Get crc lsb
        uint8_t l_lsb = 0;
        l_err = nvdimmReadReg(i_nvdimm,
                              OPERATIONAL_UNIT_CRC0,
                              l_lsb);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "getOperUnitCrc() nvdimm[%X] error reading 0x%X",
                get_huid(i_nvdimm), OPERATIONAL_UNIT_CRC0);
            break;
        }

        // Get crc msb
        uint8_t l_msb = 0;
        l_err = nvdimmReadReg(i_nvdimm,
                              OPERATIONAL_UNIT_CRC1,
                              l_msb);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "getOperUnitCrc() nvdimm[%X] error reading 0x%X",
                get_huid(i_nvdimm), OPERATIONAL_UNIT_CRC1);
            break;
        }

        o_crc = l_msb;
        o_crc <<= 8;
        o_crc += l_lsb;

    } while(0);

    return l_err;
}


/*
 * @brief Compare host and nvdimm checksum
 */
errlHndl_t compareCksum(TARGETING::Target* i_nvdimm,
                        std::vector<uint8_t>& i_unitData)
{
    // 3e) Compare checksum for unit retrieved
    // 3ea)     Write GENERATE_OPERATIONAL_UNIT_CKSUM
    //            to OPERATIONAL_UNIT_OPS_CMD
    // 3eb)     wait for NVDIMM_CMD_STATUS1 to return 0
    // 3ec)     Read OPERATIONAL_UNIT_CRC1(MSB) and OPERATIONAL_UNIT_CRC0(LSB)
    // 3ed)     Calculate host checksum
    // 3ee)     return true if 3ec) == 3ed)

    errlHndl_t l_err = nullptr;

    do
    {
        // 3ea)
        // Command the nvdimm to calculate the CRC on the unit
        l_err = nvdimmWriteReg(i_nvdimm,
                               OPERATIONAL_UNIT_OPS_CMD,
                               GENERATE_OPERATIONAL_UNIT_CKSUM);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "compareCksum() nvdimm[%X] error writing reg 0x%X to 0x%X",
                get_huid(i_nvdimm), OPERATIONAL_UNIT_OPS_CMD,
                GENERATE_OPERATIONAL_UNIT_CKSUM );
            break;
        }

        // 3eb)
        // Wait for the command to finish
        l_err = waitOperOpsComplete(i_nvdimm,
                                    GENERATE_OPERATIONAL_UNIT_CKSUM);
        if (l_err)
        {
            break;
        }

        // 3ec)
        // Read the HW CRC MSB + LSB
        uint16_t l_nvdimmCrc = 0;
        l_err = getOperUnitCrc(i_nvdimm, l_nvdimmCrc);
        if (l_err)
        {
            break;
        }

        // 3ed)
        // Calculate the host checksum
        uint8_t* l_hostData = reinterpret_cast<uint8_t*>(i_unitData.data());
        uint16_t l_hostCrc = crc16(l_hostData, i_unitData.size());

        // 3ee)
        if (l_hostCrc != l_nvdimmCrc)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "compareCksum() nvdimm[%X] compare cksum failed "
                "hostCrc 0x%X nvdimmCrc 0x%X",
                get_huid(i_nvdimm), l_hostCrc, l_nvdimmCrc);
            /*@
            *@errortype
            *@reasoncode    NVDIMM_VENDOR_LOG_CKSUM_FAILED
            *@severity      ERRORLOG_SEV_PREDICTIVE
            *@moduleid      NVDIMM_COMPARE_CKSUM
            *@userdata1     NVDIMM HUID
            *@userdata2[0:31]    HOST CRC
            *@userdata2[32:63]   NVDIMM CRC
            *@devdesc       NVDIMM vendor log checksum failed
            *@custdesc      NVDIMM logging error
            */
            l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_PREDICTIVE,
                            NVDIMM_COMPARE_CKSUM,
                            NVDIMM_VENDOR_LOG_CKSUM_FAILED,
                            get_huid(i_nvdimm),
                            TWO_UINT32_TO_UINT64(
                                l_hostCrc,
                                l_nvdimmCrc),
                            ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace(NVDIMM_COMP_NAME);
            l_err->addPartCallout( i_nvdimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
        }

    } while(0);

    return l_err;
}


/*
 * @brief Add vendor log data to FFDC
 *        Added to all NVDIMM HW errors
 */
void nvdimmAddVendorLog( TARGETING::Target* i_nvdimm, errlHndl_t& io_err )
{
    TRACFCOMP( g_trac_nvdimm, ENTER_MRK
        "nvdimmAddVendorLog: Target huid 0x%.8X",
        get_huid(i_nvdimm));

    /*
       1) Read VENDOR_LOG_PAGE_SIZE. Multiply the return value with BLOCKSIZE
          to get the total page size (LOG_PAGE_SIZE)
       2) Set TYPED_BLOCK_DATA to VENDOR_DATA_TYPE
       3) for (unit_id = 0;
               unit_id < LOG_PAGE_LENGTH/VENDOR_LOG_UNIT_SIZE;
               unit_id++)
       3a)  write OPERATIONAL_UNIT_ID0 and OPERATIONAL_UNIT_ID1 with unit_id
       3b)  set OPERATIONAL_UNIT_OPS_CMD to GET_OPERATIONAL_UNIT
       3c)  wait for NVDIMM_CMD_STATUS1 to return 0
       3d)  for (block_id = 0;
                 block_id < VENDOR_LOG_UNIT_SIZE/BLOCKSIZE;
                 block_id++)
       3da)     Write block_id to BLOCK_ID
       3db)     Read TYPED_BLOCK_DATA_BYTE0 to TYPED_BLOCK_DATA_BYTE31
       3dc)     Save data to buffer
       3e) Compare checksum for unit retrieved
       3ea)     Write GENERATE_OPERATIONAL_UNIT_CKSUM
                to OPERATIONAL_UNIT_OPS_CMD
       3eb)     wait for NVDIMM_CMD_STATUS1 to return 0
       3ec)     Read OPERATIONAL_UNIT_CRC1(MSB) and OPERATIONAL_UNIT_CRC0(LSB)
       3ed)     Calculate host checksum
       3ee)     return true if 3ec) == 3ed)
    */

    errlHndl_t l_err = nullptr;

    // Get the vendor log attribute
    auto l_vendorLog = i_nvdimm->getAttr<ATTR_NVDIMM_READING_VENDOR_LOG>();

    do
    {
        // If attr is set we are already in the process of
        // reading the vendor log, exit
        if (l_vendorLog)
        {
            break;
        }

        if (io_err == nullptr)
        {
            // A nullptr was given when it should not have been. Emit a trace
            // and break out of this function.
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                    "nvdimmAddVendorLog() io_err was nullptr!! Skip adding additional FFDC.");
            break;
        }


        // Set the vendor log attribute so we don't recursively
        // execute the nvdimmAddVendorLog function
        l_vendorLog = 0x1;
        i_nvdimm->setAttr<ATTR_NVDIMM_READING_VENDOR_LOG>(l_vendorLog);

        uint8_t l_readData = 0;
        std::vector<uint8_t> l_fullData;

        // Step 1
        l_err = nvdimmReadReg(i_nvdimm,
                              VENDOR_LOG_PAGE_SIZE,
                              l_readData);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "nvdimmAddVendorLog() nvdimm[%X] error reading 0x%X",
                get_huid(i_nvdimm), VENDOR_LOG_PAGE_SIZE);
            break;
        }

        size_t l_logPgeLength = l_readData * VENDOR_LOG_BLOCK_SIZE;

        // Step 2
        // Some weird bug here - switching directly to VENDOR_DATA_TYPE
        // would not work. Need to switch to something else first
        l_err = nvdimmWriteReg(i_nvdimm,
                               TYPED_BLOCK_DATA,
                               FIRMWARE_IMAGE_DATA);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "nvdimmAddVendorLog() nvdimm[%X] error writing 0x%X to 0x%X",
                get_huid(i_nvdimm),TYPED_BLOCK_DATA, FIRMWARE_IMAGE_DATA );
            break;
        }

        l_err = nvdimmWriteReg(i_nvdimm,
                               TYPED_BLOCK_DATA,
                               VENDOR_DATA_TYPE);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "nvdimmAddVendorLog() nvdimm[%X] error writing 0x%X to 0x%X",
                get_huid(i_nvdimm),TYPED_BLOCK_DATA, VENDOR_DATA_TYPE );
            break;
        }

        // Step 3
        // Loop through all the log units.
        for (uint16_t l_unitId = 0;
             l_unitId < (l_logPgeLength / VENDOR_LOG_UNIT_SIZE);
             l_unitId++)
        {
            // Step 3a) - 3dc)
            // Get one log unit
            std::vector<uint8_t> l_unitData;
            l_err = getLogPerUnit(i_nvdimm, l_unitId, l_unitData);
            if (l_err)
            {
                break;
            }

            // Step 3e) - 3ee)
            // Check the checksum for the entire log unit
            l_err = compareCksum(i_nvdimm, l_unitData);
            if (l_err)
            {
                break;
            }

            // Append to full data
            l_fullData.insert(l_fullData.end(),
                              l_unitData.begin(),
                              l_unitData.end());
        }

        if (l_err)
        {
            break;
        }

        // Find first NUL char in the vendor log data
        bool l_foundNull = false;
        uint32_t l_idx = 0;
        for (l_idx = 0; l_idx < l_fullData.size(); l_idx++)
        {
            if (l_fullData[l_idx] == 0x00)
            {
                l_foundNull = true;
                break;
            }
        }

        // If NULL char not found
        // then this is the old log format
        if (l_foundNull == false)
        {
            // Add NUL terminator to ascii data
            l_fullData.push_back(0x00);
        }
        // Else new log format
        else
        {
            // If the next char is not NULL
            // then the log has wrapped
            // Re-arrange the data in chronological order
            if (l_fullData[l_idx + 1] != 0x00)
            {
                // Save the data after the NULL char
                // This is the start of the log
                std::vector<uint8_t> l_tmpData;
                l_tmpData.insert(l_tmpData.begin(),
                                 l_fullData.begin() + l_idx + 1,
                                 l_fullData.end());

                // Erase this data from the vector
                l_fullData.erase(l_fullData.begin() + l_idx + 1,
                                 l_fullData.end());

                // Place the saved data at the front
                l_fullData.insert(l_fullData.begin(),
                                  l_tmpData.begin(),
                                  l_tmpData.end());
            }
            // Else log has not wrapped
            else
            {
                // Erase the data at the end of the vector
                l_fullData.erase(l_fullData.begin() + l_idx + 1,
                                 l_fullData.end());
            }
        }

        // Add vendor data to error log as string
        const char* l_fullChar = reinterpret_cast<char*>(l_fullData.data());

        const char* l_copyChar = l_fullChar;
        int l_length = strlen(l_copyChar);
        int l_remaining = l_length;

        // Count of number segments
        const int l_totalCount = (l_length % SPLIT_SIZE == 0) ?
            l_length/SPLIT_SIZE : l_length/SPLIT_SIZE + 1;
        int l_count = l_totalCount;

        // Move the string forward to the last 512 bytes
        if (l_length > SPLIT_SIZE)
        {
            l_copyChar += l_length - SPLIT_SIZE;
        }

        ERRORLOG::ErrlUserDetailsStringSet l_stringSet;
        size_t l_copySize = SPLIT_SIZE;
        while (l_remaining > 0)
        {
            char buffer[BUFFER_SIZE] = {0};

            // If at the last segment
            if (l_remaining <= SPLIT_SIZE)
            {
                l_copySize = l_remaining;
                l_copyChar = l_fullChar;
            }

            char l_blob[l_copySize+1] = {0};
            strncpy(l_blob, l_copyChar, l_copySize);
            l_blob[l_copySize+1] = '\0';

            snprintf(buffer, SPLIT_SIZE, "Vendor Log: page %d of %d, "
                "bytes %d to %d", l_count, l_totalCount,
                l_remaining - l_copySize, l_remaining - 1);
            l_stringSet.add(buffer, l_blob);

            // Move string back 512 bytes
            l_copyChar -= SPLIT_SIZE;
            l_remaining -= l_copySize;
            l_count--;
        }

        l_stringSet.addToLog(io_err);

        // Change back to default
        l_err = nvdimmWriteReg(i_nvdimm,
                               TYPED_BLOCK_DATA,
                               VENDOR_DEFAULT);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                "nvdimmAddVendorLog() nvdimm[%X] error writing 0x%X to 0x%X",
                get_huid(i_nvdimm),TYPED_BLOCK_DATA, VENDOR_DEFAULT );
            break;
        }

    } while(0);

    if (l_err)
    {
        // FFDC error, set as informational
        l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        errlCommit( l_err, NVDIMM_COMP_ID );
    }

    // Clear the vendor log attribute before exiting
    l_vendorLog = 0x0;
    i_nvdimm->setAttr<ATTR_NVDIMM_READING_VENDOR_LOG>(l_vendorLog);

    TRACFCOMP( g_trac_nvdimm, EXIT_MRK
        "nvdimmAddVendorLog: Target huid 0x%.8X",
        get_huid(i_nvdimm));
}


/*
 * @brief Add NVDIMM Update regs to FFDC for errors encountered
 *        during NVDIMM update process
 */
void nvdimmAddUpdateRegs( TARGETING::Target* i_nvdimm, errlHndl_t& io_err )
{
    errlHndl_t l_err = nullptr;

    do {

        if (io_err == nullptr)
        {
            // A nullptr was given when it should not have been. Emit a trace
            // and break out of this function.
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                    "nvdimmAddUpdateRegs() io_err was nullptr!! Skip adding additional FFDC.");
            break;
        }

        ERRORLOG::ErrlUserDetailsLogRegister l_regUD(i_nvdimm);
        const uint32_t l_regList[] = {
            NVDIMM_READY,
            FIRMWARE_OPS_STATUS,
            NVDIMM_CMD_STATUS0,
            FIRMWARE_OPS_TIMEOUT0,
            FIRMWARE_OPS_TIMEOUT1,
            FW_REGION_CRC0,
            FW_REGION_CRC1,
            MODULE_HEALTH,
            MODULE_HEALTH_STATUS0,
            MODULE_HEALTH_STATUS1,
            ERROR_THRESHOLD_STATUS,
            ENCRYPTION_CONFIG_STATUS,
            FW_SLOT_INFO,
            SLOT0_ES_FWREV0,
            SLOT0_ES_FWREV1,
            SLOT1_ES_FWREV0,
            SLOT1_ES_FWREV1,
            SLOT1_SUBFWREV,
            CSAVE_INFO,
            CSAVE_FAIL_INFO1,
            RESTORE_STATUS,
            RESTORE_FAIL_INFO,
        };
        uint8_t l_readData = 0;

        for (auto l_reg : l_regList)
        {
            l_err = nvdimmReadReg(i_nvdimm,
                                  l_reg,
                                  l_readData);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK
                          "nvdimmAddUpdateRegs() nvdimm[%X] error reading 0x%X",
                          get_huid(i_nvdimm), l_reg);

                // Don't commit, just delete the error and continue
                delete l_err;
                l_err = nullptr;
                continue;
            }

            l_regUD.addDataBuffer(&l_readData,
                                  sizeof(l_readData),
                                  DEVICE_NVDIMM_ADDRESS(l_reg));
        }

        l_regUD.addToLog(io_err);

    } while(0);
}


/*
 * @brief Add Page 4 regs to FFDC
 *        Added to all NVDIMM HW errors
 */
void nvdimmAddPage4Regs( TARGETING::Target* i_nvdimm, errlHndl_t& io_err )
{
    errlHndl_t l_err = nullptr;

    do
    {
        if (io_err == nullptr)
        {
            // A nullptr was given when it should not have been. Emit a trace
            // and break out of this function.
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                    "nvdimmAddPage4Regs() io_err was nullptr!! Skip adding additional FFDC.");
            break;
        }


        // Get the page4 attribute, if set we are already
        // reading the page4 regs, exit
        auto l_page4 = i_nvdimm->getAttr<ATTR_NVDIMM_READING_PAGE4>();
        if (l_page4)
        {
            break;
        }

        // Set the page4 attribute so we don't recursively
        // execute the nvdimmAddPage4Regs function
        l_page4 = 0x1;
        i_nvdimm->setAttr<ATTR_NVDIMM_READING_PAGE4>(l_page4);

        ERRORLOG::ErrlUserDetailsLogRegister l_regUD(i_nvdimm);
        uint32_t l_regList[] = {
            PANIC_CNT,
            PARITY_ERROR_COUNT,
            FLASH_ERROR_COUNT0,
            FLASH_ERROR_COUNT1,
            FLASH_ERROR_COUNT2,
            FLASH_BAD_BLOCK_COUNT0,
            FLASH_BAD_BLOCK_COUNT1,
            SCAP_STATUS,
            STATUS_EVENT_INT_INFO1,
            STATUS_EVENT_INT_INFO2
        };
        uint8_t l_readData = 0;

        for (auto l_reg : l_regList)
        {
            l_err = nvdimmReadReg(i_nvdimm,
                                l_reg,
                                l_readData);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK
                        "nvdimmAddPage4Regs() nvdimm[%X] error reading 0x%X",
                        get_huid(i_nvdimm), l_reg);

                // Don't commit, just delete the error and continue
                delete l_err;
                l_err = nullptr;
                continue;
            }

            l_regUD.addDataBuffer(&l_readData,
                                sizeof(l_readData),
                                DEVICE_NVDIMM_ADDRESS(l_reg));
        }

        l_regUD.addToLog(io_err);

        // Clear the page4 attribute before exiting
        l_page4 = 0x0;
        i_nvdimm->setAttr<ATTR_NVDIMM_READING_PAGE4>(l_page4);

    } while(0);
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

/**
 * @brief Grab the current slot that NVDIMM code is running
 */
errlHndl_t nvdimmGetRunningSlot(TARGETING::Target *i_nvdimm, uint8_t & o_slot)
{
    errlHndl_t l_err = nullptr;
    uint8_t l_data = 0;
    o_slot = 0;  //default to slot 0

    // Check if the firmware slot is 0
    l_err = nvdimmReadReg ( i_nvdimm, FW_SLOT_INFO, l_data);
    if (l_err)
    {
        nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR);
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmGetRunningSlot() nvdimm[%X], failed to read slot info",
                  get_huid(i_nvdimm));
    }
    else
    {
        // Bits 7-4 = RUNNING_FW_SLOT - slot number of running firmware
        o_slot = (l_data & RUNNING_FW_SLOT) >> 4;
    }
    return l_err;
}

/**
 * @brief This function polls the command status register for arm completion
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[out] o_poll - total polled time in ms
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmPollArmDone(Target* i_nvdimm,
                             uint32_t &o_poll)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmPollArmDone() nvdimm[%X]", get_huid(i_nvdimm) );

    errlHndl_t l_err = nullptr;

    l_err = nvdimmPollStatus ( i_nvdimm, ARM, o_poll);

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmPollArmDone() nvdimm[%X]",
              get_huid(i_nvdimm));

    return l_err;
}

/**
 * @brief This function checks the arm status register to make sure
 *        the trigger has been armed to ddr_reset_n
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 * @param[in] i_arm_timeout - nvdimm local timeout status
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmCheckArmSuccess(Target *i_nvdimm, bool i_arm_timeout)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmCheckArmSuccess() nvdimm[%X]",
                get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    uint8_t l_data = 0;

    l_err = nvdimmReadReg(i_nvdimm, ARM_STATUS, l_data);

    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmCheckArmSuccess() nvdimm[%X]"
                  "failed to read arm status reg!",get_huid(i_nvdimm));
    }
    else if (((l_data & ARM_ERROR) == ARM_ERROR) || ((l_data & RESET_N_ARMED) != RESET_N_ARMED) || i_arm_timeout)
    {

        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmCheckArmSuccess() nvdimm[%X]"
                                 "failed to arm! ARM status 0x%X ARM timeout %d"
                                 ,get_huid(i_nvdimm),l_data,i_arm_timeout);
        /*@
         *@errortype
         *@reasoncode       NVDIMM_ARM_FAILED
         *@severity         ERRORLOG_SEV_PREDICTIVE
         *@moduleid         NVDIMM_SET_ARM
         *@userdata1[0:31]  Related ops (0xff = NA)
         *@userdata1[32:63] Target Huid
         *@userdata2[0:31]  ARM Status
         *@userdata2[32:63] ARM Timeout
         *@devdesc          Encountered error arming the catastrophic save
         *                   trigger on NVDIMM. Make sure an energy source
         *                   is connected to the NVDIMM and the ES policy
         *                   is set properly
         *@custdesc         NVDIMM encountered error arming save trigger
         */
        l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       NVDIMM_SET_ARM,
                                       NVDIMM_ARM_FAILED,
                                       TWO_UINT32_TO_UINT64(ARM, get_huid(i_nvdimm)),
                                       TWO_UINT32_TO_UINT64(l_data, i_arm_timeout),
                                       ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

        l_err->collectTrace(NVDIMM_COMP_NAME, 256 );
        nvdimmAddVendorLog(i_nvdimm, l_err);

        // Failure to arm could mean internal NV controller error or
        // even error on the battery pack. NVDIMM will lose persistency
        // if failed to arm trigger
        l_err->addHwCallout( i_nvdimm,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::NO_DECONFIG,
                               HWAS::GARD_Fatal);
    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmCheckArmSuccess() nvdimm[%X] ret[%X]",
                get_huid(i_nvdimm), l_data);

    return l_err;
}

/**
 * @brief This function performs arm precheck.
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmArmPreCheck(Target* i_nvdimm)
{
    TRACUCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmArmPreCheck() nvdimm[%X]",
                get_huid(i_nvdimm));

    errlHndl_t l_err = nullptr;
    uint8_t l_ready = 0;
    uint8_t l_fwupdate = 0;
    uint8_t l_module_health = 0;
    uint8_t l_es_policy_status = 0;
    uint8_t l_continue = true;
    auto l_RegInfo = nvdimm_reg_t();

    do
    {
        // Read out the Module Health status register
        l_err = nvdimmReadReg(i_nvdimm, MODULE_HEALTH_STATUS0, l_module_health);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmArmPreCheck() nvdimm[%X] - failed to read Module Health Status",
                      get_huid(i_nvdimm));
            errlCommit( l_err, NVDIMM_COMP_ID );
            l_continue = false;
            break;
        }

        // Read out the NVDimm Ready register
        l_err = nvdimmReadReg(i_nvdimm, NVDIMM_READY, l_ready);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmArmPreCheck() nvdimm[%X] - failed to read NVDimm Ready register",
                      get_huid(i_nvdimm));
            errlCommit( l_err, NVDIMM_COMP_ID );
            l_continue = false;
            break;
        }

        // Read out the FW OPs Status register
        l_err = nvdimmReadReg(i_nvdimm, FIRMWARE_OPS_STATUS, l_fwupdate);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmArmPreCheck() nvdimm[%X] - failed to read Firmware OPs Status register",
                      get_huid(i_nvdimm));
            errlCommit( l_err, NVDIMM_COMP_ID );
            l_continue = false;
        }

        // Read out the SET_ES_POLICY_STATUS register
        // Adding a precheck here for SET_ES_POLICY to catch any ES_POLICY_ERROR in case
        // SET_ES_POLICY had to be done prior. i.e. setting the ES policy to set the BPM
        // threshold values
        l_err = nvdimmReadReg(i_nvdimm, SET_ES_POLICY_STATUS, l_es_policy_status);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmArmPreCheck() nvdimm[%X] - failed to read SET_ES_POLICY_STATUS register",
                      get_huid(i_nvdimm));
            errlCommit( l_err, NVDIMM_COMP_ID );
            l_continue = false;
        }

    }while(0);

    // Check ARM pre-requisites
    // All nvdimms in i_nvdimmTargetList must pass the pre-req checks
    // before continuing with arm.
    if ((!l_continue) || (l_module_health & NVM_LIFETIME_ERROR)
                      || (l_ready != NV_READY)
                      || (l_fwupdate & FW_OPS_UPDATE)
                      || (l_es_policy_status & ES_POLICY_ERROR))
    {
        TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmArmPreCheck() nvdimm[%X] - failed NVDimm Arm prechecks",
                  get_huid(i_nvdimm));
       /*@
        *@errortype
        *@reasoncode        NVDIMM_ARM_PRE_CHECK_FAILED
        *@severity          ERRORLOG_SEV_PREDICTIVE
        *@moduleid          NVDIMM_ARM_PRE_CHECK
        *@userdata1[0:31]   Target Huid
        *@userdata1[32:39]  l_continue
        *@userdata1[40:47]  l_module_health
        *@userdata1[48:56]  l_ready
        *@userdata1[57:63]  l_fwupdate
        *@userdata2         l_es_policy_status
        *@devdesc           NVDIMM failed arm precheck. Refer to FFDC for exact reason
        *@custdesc          NVDIMM failed the arm precheck and is unable to arm
        */
        l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                         NVDIMM_ARM_PRE_CHECK,
                                         NVDIMM_ARM_PRE_CHECK_FAILED,
                                         NVDIMM_SET_USER_DATA_1(TARGETING::get_huid(i_nvdimm),
                                         FOUR_UINT8_TO_UINT32(l_continue, l_module_health, l_ready, l_fwupdate)),
                                         l_es_policy_status,
                                         ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

        l_err->collectTrace( NVDIMM_COMP_NAME );

        // Callout the dimm
        l_err->addHwCallout( i_nvdimm,
                               HWAS::SRCI_PRIORITY_LOW,
                               HWAS::NO_DECONFIG,
                               HWAS::GARD_NULL);

        // Read relevant regs for trace data
        nvdimmTraceRegs(i_nvdimm, l_RegInfo);
        nvdimmAddPage4Regs(i_nvdimm,l_err);
        nvdimmAddVendorLog(i_nvdimm, l_err);

        // Add reg traces to the error log
        NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);

    }

    TRACUCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmArmPreCheck() nvdimm[%X]",
                get_huid(i_nvdimm));

    return l_err;
}


bool nvdimmArm(TargetHandleList &i_nvdimmTargetList)
{
    bool o_arm_successful = true;
    bool l_continue = true;
    bool l_arm_timeout = false;
    uint8_t l_data;
    auto l_RegInfo = nvdimm_reg_t();
    uint64_t l_writeData;
    uint32_t l_writeAddress;
    size_t l_writeSize = sizeof(l_writeData);

    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmArm() numNvdimm[%d]",
        i_nvdimmTargetList.size());

    errlHndl_t l_err = nullptr;
    errlHndl_t l_err_t = nullptr;

    // Prerequisite Arm Checks
    for (auto const l_nvdimm : i_nvdimmTargetList)
    {
        l_err = nvdimmArmPreCheck(l_nvdimm);

        // If we are failing the precheck, commit the error then exit
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmArm() failed arm precheck, exiting");
            errlCommit(l_err, NVDIMM_COMP_ID);
            return false;
        }
    }

    // Encryption unlocked check
    // Check one nvdimm at a time
    for (auto const l_nvdimm : i_nvdimmTargetList)
    {
        // Unlock function will create an error log
        // Create another here to make it clear that the arm failed
        TargetHandleList l_nvdimmTargetList;
        l_nvdimmTargetList.push_back(l_nvdimm);
        if (!nvdimm_encrypt_unlock(l_nvdimmTargetList))
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmArm() nvdimm[%X] - failed NVDimm Arm encryption unlock",
                      get_huid(l_nvdimm));
            /*@
             *@errortype
             *@reasoncode    NVDIMM_ARM_ENCRYPTION_UNLOCK_FAILED
             *@severity      ERRORLOG_SEV_PREDICTIVE
             *@moduleid      NVDIMM_ARM
             *@userdata1     Target Huid
             *@userdata2     <UNUSED>
             *@devdesc       NVDIMM failed to unlock encryption during arming
             *@custdesc      NVDIMM failed to ARM
             */
            l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_PREDICTIVE,
                            NVDIMM_ARM,
                            NVDIMM_ARM_ENCRYPTION_UNLOCK_FAILED,
                            get_huid(l_nvdimm),
                            0x0,
                            ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace( NVDIMM_COMP_NAME );

            // Callout the dimm
            l_err->addHwCallout( l_nvdimm,
                                 HWAS::SRCI_PRIORITY_MED,
                                 HWAS::DELAYED_DECONFIG,
                                 HWAS::GARD_NULL);

            // Read relevant regs for trace data
            nvdimmTraceRegs(l_nvdimm, l_RegInfo);
            nvdimmAddPage4Regs(l_nvdimm,l_err);
            nvdimmAddVendorLog(l_nvdimm, l_err);

            // Add reg traces to the error log
            NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);

            // Commit the error then exit
            errlCommit(l_err, NVDIMM_COMP_ID);
            return false;
        }
    }

    // Mask MBACALFIR EventN to separate ARM handling
    for (TargetHandleList::iterator it = i_nvdimmTargetList.begin();
         it != i_nvdimmTargetList.end();)
    {
        TargetHandleList l_mcaList;
        getParentAffinityTargets(l_mcaList, *it, CLASS_UNIT, TYPE_MCA);
        assert(l_mcaList.size(), "nvdimmArm() failed to find parent MCA.");

        l_writeAddress = MBACALFIR_OR_MASK_REG;
        l_writeData = MBACALFIR_EVENTN_OR_BIT;
        l_err = deviceWrite(l_mcaList[0], &l_writeData, l_writeSize,
                            DEVICE_SCOM_ADDRESS(l_writeAddress));
        if(l_err)
        {
              TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                        l_writeAddress);
             errlCommit( l_err, NVDIMM_COMP_ID );
        }
        it++;
    }

    for (auto const l_nvdimm : i_nvdimmTargetList)
    {
        l_arm_timeout = false;

        // skip if the nvdimm is already armed
        ATTR_NVDIMM_ARMED_type l_armed_state = {};
        l_armed_state = l_nvdimm->getAttr<ATTR_NVDIMM_ARMED>();
        if (l_armed_state.armed)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] called when already armed", get_huid(l_nvdimm));
            continue;
        }

        // Set ES Policy, contains all of its status checks
        l_err = nvdimmSetESPolicy(l_nvdimm);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed to set ES Policy", get_huid(l_nvdimm));
            o_arm_successful = false;

            nvdimmDisarm(i_nvdimmTargetList);

            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);

            // Callout the nvdimm on high and gard
            l_err->addHwCallout( l_nvdimm,
                                   HWAS::SRCI_PRIORITY_HIGH,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_Fatal);

            errlCommit( l_err, NVDIMM_COMP_ID );

            break;
        }

        // Clear all status registers in case of leftover bits
        l_err = nvdimmWriteReg(l_nvdimm, NVDIMM_MGT_CMD0, CLEAR_ALL_STATUS);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmArm() nvdimm[%X] - error clearing all status registers",
                      get_huid(l_nvdimm));
            o_arm_successful = false;
            break;
        }

        bool l_is_retryable = true;
        //continue flag set by the retry loop to continue on the outer loop
        bool l_continue_arm = false;
        //break flag set by the retry loop to break on the outer loop
        bool l_break = false;
        errlHndl_t l_err_retry = nullptr;

        // Attempt arm multiple times in case of glitches
        for (size_t l_retry = 0; l_retry <= ARM_MAX_RETRY_COUNT; l_retry++)
        {

            l_err = NVDIMM::nvdimmChangeArmState(l_nvdimm, ARM_TRIGGER);
            // If we run into any error here we will just
            // commit the error log and move on. Let the
            // system continue to boot and let the user
            // salvage the data
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed to trigger arm", get_huid(l_nvdimm));

                nvdimmDisarm(i_nvdimmTargetList);

                // Committing the error as we don't want this to interrupt
                // the boot. This will notify the user that action is needed
                // on this module
                l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                l_err->collectTrace(NVDIMM_COMP_NAME);
                errlCommit( l_err, NVDIMM_COMP_ID );
                o_arm_successful = false;

                // Cause the main loop to skip the rest of the arm procedure
                // and move to the next target
                l_continue_arm = true;
                break;
            }

            // Arm happens one module at a time. No need to set any offset on the counter
            uint32_t l_poll = 0;
            l_err = nvdimmPollArmDone(l_nvdimm, l_poll);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] arm command timed out", get_huid(l_nvdimm));
                l_arm_timeout = true;

                l_err_t = notifyNvdimmProtectionChange(l_nvdimm, NVDIMM_DISARMED);
                if (l_err_t)
                {
                    errlCommit( l_err_t, NVDIMM_COMP_ID );
                }

                // Committing the error as we don't want this to interrupt
                // the boot. This will notify the user that action is needed
                // on this module
                l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                l_err->collectTrace(NVDIMM_COMP_NAME);

                errlCommit( l_err, NVDIMM_COMP_ID );
                o_arm_successful = false;
            }

            // Pass l_arm_timeout value in for health status check
            l_continue = l_arm_timeout;

            // Sleep for 1 second before checking the health status
            // to let the glitches settle in case there were any
            nanosleep(1, 0);

            // Check health status registers and exit if required
            l_err = nvdimmHealthStatusCheck( l_nvdimm, HEALTH_PRE_ARM, l_continue );

            // Check for health status failure
            // Any fail picked up by the health check is a legit fail
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed first health status check", get_huid(l_nvdimm));

                // The arm timeout variable is used here as the continue variable for the
                // health status check. This was done to include the timeout for use in the check
                // If true either the arm timed out with a health status fail or the
                // health status check failed with another disarm and exit condition
                if (!l_continue)
                {
                    errlCommit( l_err, NVDIMM_COMP_ID );

                    // Disarming all dimms due to error
                    nvdimmDisarm(i_nvdimmTargetList);
                    o_arm_successful = false;

                    // Cause the main loop to exit out of the main arm procedure
                    l_break = true;
                    break;
                }
                else
                {
                    errlCommit( l_err, NVDIMM_COMP_ID );

                    // Cause the main loop to skip the rest of the arm procedure
                    // and move to the next target
                    l_continue_arm = true;
                    break;
                }
            }

            l_err = nvdimmCheckArmSuccess(l_nvdimm, l_arm_timeout);

            // At this point we have passed the health check. If the arm were
            // to fail now, it is likely it was due to some glitch. Let's retry
            // the arm again as long as the fail is not due to timeout.
            // A timeout would mean a charging issue, it would have been caught
            // by the health check.
            l_is_retryable = !l_arm_timeout && l_retry < ARM_MAX_RETRY_COUNT;
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed to succesfully arm. %s retryable.",
                            get_huid(l_nvdimm), l_is_retryable? "IS" : "NOT");

                if (l_is_retryable)
                {
                    // Save the original error
                    // If a previous error was saved then delete it
                    if (l_err_retry)
                    {
                        delete l_err_retry;
                    }
                    l_err_retry = l_err;

                    /*@
                    *@errortype
                    *@reasoncode       NVDIMM_ARM_RETRY
                    *@severity         ERRORLOG_SEV_INFORMATIONAL
                    *@moduleid         NVDIMM_ARM_ERASE
                    *@userdata1[0:31]  Target Huid
                    *@userdata1[32:39] l_is_retryable
                    *@userdata1[40:47] MAX arm retry count
                    *@userdata2[0:31]  Original errlog plid
                    *@userdata2[32:63] Original errlog reason code
                    *@devdesc          NVDIMM encountered a glitch causing the initial
                    *                  arm to fail. System firmware will retry the arm
                    *@custdesc         NVDIMM requires an arm retry
                    */
                    l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                                     NVDIMM_ARM_ERASE,
                                                     NVDIMM_ARM_RETRY,
                                                     NVDIMM_SET_USER_DATA_1(TARGETING::get_huid(l_nvdimm),
                                                     FOUR_UINT8_TO_UINT32(l_is_retryable, ARM_MAX_RETRY_COUNT,0,0)),
                                                     TWO_UINT32_TO_UINT64(l_err_retry->plid(), l_err_retry->reasonCode()),
                                                     ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

                    l_err->collectTrace( NVDIMM_COMP_NAME );

                    // Callout the dimm
                    l_err->addHwCallout( l_nvdimm,
                                           HWAS::SRCI_PRIORITY_LOW,
                                           HWAS::NO_DECONFIG,
                                           HWAS::GARD_NULL);

                    errlCommit( l_err, NVDIMM_COMP_ID );
                }
                else
                {
                    // Handle retryable error
                    if (l_err_retry)
                    {
                        ERRORLOG::ErrlUserDetailsString("Arm RETRY failed").addToLog(l_err_retry);

                        // Delete the current errlog and use the original errlog for callout
                        delete l_err;
                        l_err = l_err_retry;
                        l_err_retry = nullptr;
                    }

                    // Disarming all dimms due to error
                    nvdimmDisarm(i_nvdimmTargetList);

                    l_err_t = notifyNvdimmProtectionChange(l_nvdimm, NVDIMM_DISARMED);
                    if (l_err_t)
                    {
                        errlCommit( l_err_t, NVDIMM_COMP_ID );
                    }

                    // Committing the error as we don't want this to interrupt
                    // the boot. This will notify the user that action is needed
                    // on this module
                    l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                    l_err->collectTrace(NVDIMM_COMP_NAME);

                    // Dump Traces for error logs
                    nvdimmTraceRegs( l_nvdimm, l_RegInfo );
                    nvdimmAddPage4Regs(l_nvdimm,l_err);

                    // Add reg traces to the error log
                    NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);

                    errlCommit(l_err, NVDIMM_COMP_ID);
                    o_arm_successful = false;

                    // Cause the main loop to exit out of the main arm procedure
                    l_break = true;
                    break;
                }
            }
            else
            {
                // Arm worked. Exit the retry loop
                break;
            } // close nvdimmCheckArmSuccess check
        } // close arm retry loop

        if (l_continue_arm)
        {
            continue;
        }
        else if (l_break)
        {
            break;
        }

        // After arming the trigger, erase the image to prevent the possible
        // stale image getting the restored on the next boot in case of failed
        // save.
        l_err = nvdimmEraseNF(l_nvdimm);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed to erase post arm", get_huid(l_nvdimm));

            // Disarming all dimms due to error
            nvdimmDisarm(i_nvdimmTargetList);

            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit( l_err, NVDIMM_COMP_ID );
            o_arm_successful = false;
            break;
        }

        // Arm successful, update armed status
        l_err = NVDIMM::notifyNvdimmProtectionChange(l_nvdimm,
                                                     NVDIMM::NVDIMM_ARMED);
        if (l_err)
        {
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit(l_err, NVDIMM_COMP_ID);
        }

        // Enable Persistency and Warning Threshold notifications
        l_err = nvdimmWriteReg(l_nvdimm, SET_EVENT_NOTIFICATION_CMD, ENABLE_NOTIFICATIONS);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"NDVIMM HUID[%X] setting persistency notification",
                      TARGETING::get_huid(l_nvdimm));
            break;
        }

        // Poll for a status update since it might not be updated immediately
        // Status update should be valid by 1ms (usual range: 300 - 400 us)
        // but we want no chance of a false failure so we'll wait 100ms before
        // we die.
        // Wait until a valid 0x0D status or timeout
        // Hit issue where a non-zero might be returned before timeout
        // but it was not the valid 0x0D status
        l_data = 0x00;
        int status_wait_time = 100*NS_PER_MSEC; // wait 100 msec
        while( (l_data != 0x0D) && (status_wait_time > 0) )
        {
            // Check notification status and errors
            l_err = nvdimmReadReg(l_nvdimm, SET_EVENT_NOTIFICATION_STATUS, l_data);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm, ERR_MRK"NVDIMM[%X] read of SET_EVENT_NOTIFICATION_STATUS failed (%d ns remained)",
                        get_huid(l_nvdimm), status_wait_time);
                break;
            }
            if (l_data != 0x0D) // skip sleep if data is valid
            {
                nanosleep(0, NS_PER_MSEC/10); // sleep 100us (.1 ms) between reads
                status_wait_time -= (NS_PER_MSEC/10);
            }
        }
        // if error found from nvdimmReadReg
        if (l_err)
        {
            // i2c read failure, exit main nvdimmArm() loop
            break;
        }

        if (((l_data & SET_EVENT_NOTIFICATION_ERROR) == SET_EVENT_NOTIFICATION_ERROR)
              || ((l_data & NOTIFICATIONS_ENABLED) != NOTIFICATIONS_ENABLED))
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed to set event notification (last status: 0x%02X)",
                      get_huid(l_nvdimm), l_data);

            // Set NVDIMM Status flag to partial working, as error detected but data might persist
            notifyNvdimmProtectionChange(l_nvdimm, NVDIMM_RISKY_HW_ERROR);

           /*@
            *@errortype
            *@reasoncode       NVDIMM_SET_EVENT_NOTIFICATION_ERROR
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_SET_EVENT_NOTIFICATION
            *@userdata1[0:31]  Target Huid
            *@userdata2        SET_EVENT_NOTIFICATION_STATUS
            *@devdesc          NVDIMM threw an error or failed to set event
            *                  notifications during arming
            *@custdesc         NVDIMM failed to enable event notificaitons
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_SET_EVENT_NOTIFICATION,
                                             NVDIMM_SET_EVENT_NOTIFICATION_ERROR,
                                             TARGETING::get_huid(l_nvdimm),
                                             l_data,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );

            l_err->collectTrace( NVDIMM_COMP_NAME );

            // Callout the dimm
            l_err->addHwCallout( l_nvdimm,
                                   HWAS::SRCI_PRIORITY_LOW,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL);

            // Read relevant regs for trace data
            nvdimmTraceRegs(l_nvdimm, l_RegInfo);
            nvdimmAddPage4Regs(l_nvdimm,l_err);
            nvdimmAddVendorLog(l_nvdimm, l_err);

            // Add reg traces to the error log
            NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);

            errlCommit( l_err, NVDIMM_COMP_ID );

            // We are after the arm step now, so on any error cases let's log it
            // then move to the next nvdimm
            continue;
        }

        // Re-check health status registers
        l_err = nvdimmHealthStatusCheck( l_nvdimm, HEALTH_POST_ARM, l_continue );

        // Check for health status failure
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, "nvdimmArm() nvdimm[%X] failed final health status check", get_huid(l_nvdimm));

            errlCommit( l_err, NVDIMM_COMP_ID );
            continue;
        }

    }

    // Check for uncommited i2c fail error logs
    if (l_err)
    {
        TRACFCOMP(g_trac_nvdimm, "nvdimmArm() failed an i2c read/write");
        errlCommit( l_err, NVDIMM_COMP_ID );
        nvdimmDisarm(i_nvdimmTargetList);
        return false;
    }

    // Unmask firs if the arm completed successfully
    if (o_arm_successful)
    {
        // Unmask MBACALFIR EventN and set to recoverable
        for (TargetHandleList::iterator it = i_nvdimmTargetList.begin();
            it != i_nvdimmTargetList.end();)
        {
            TargetHandleList l_mcaList;
            getParentAffinityTargets(l_mcaList, *it, CLASS_UNIT, TYPE_MCA);
            assert(l_mcaList.size(), "nvdimmArm() failed to find parent MCA.");

            // Set MBACALFIR_ACTION0 to recoverable
            l_writeAddress = MBACALFIR_ACTION0_REG;
            l_writeData = 0;
            l_err = deviceRead(l_mcaList[0], &l_writeData, l_writeSize,
                               DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_err)
            {
                TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                          l_writeAddress);
                errlCommit( l_err, NVDIMM_COMP_ID );
            }


            l_writeData &= MBACALFIR_EVENTN_AND_BIT;
            l_err = deviceWrite(l_mcaList[0], &l_writeData, l_writeSize,
                                   DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_err)
            {
                TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                          l_writeAddress);
                errlCommit( l_err, NVDIMM_COMP_ID );
            }

            // Set MBACALFIR_ACTION1 to recoverable
            l_writeAddress = MBACALFIR_ACTION1_REG;
            l_writeData = 0;
            l_err = deviceRead(l_mcaList[0], &l_writeData, l_writeSize,
                               DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_err)
            {
                TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                          l_writeAddress);
                errlCommit( l_err, NVDIMM_COMP_ID );
            }

            l_writeData |= MBACALFIR_EVENTN_OR_BIT;
            l_err = deviceWrite(l_mcaList[0], &l_writeData, l_writeSize,
                                DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_err)
            {
                TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                          l_writeAddress);
                errlCommit( l_err, NVDIMM_COMP_ID );
            }

            // Unmask MBACALFIR[8]
            l_writeAddress = MBACALFIR_AND_MASK_REG;
            l_writeData = MBACALFIR_UNMASK_BIT;
            l_err = deviceWrite(l_mcaList[0], &l_writeData, l_writeSize,
                                DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_err)
            {
                TRACFCOMP(g_trac_nvdimm, "SCOM to address 0x%08x failed",
                          l_writeAddress);
                errlCommit( l_err, NVDIMM_COMP_ID );
            }

            it++;
        }

    }

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmArm() returning %d",
              o_arm_successful);
    return o_arm_successful;
}

bool nvdimmDisarm(TargetHandleList &i_nvdimmTargetList)
{
    bool o_disarm_successful = true;

    TRACFCOMP(g_trac_nvdimm, ENTER_MRK"nvdimmDisarm() %d",
        i_nvdimmTargetList.size());

    errlHndl_t l_err = nullptr;

    for (auto const l_nvdimm : i_nvdimmTargetList)
    {
        l_err = NVDIMM::nvdimmChangeArmState(l_nvdimm, DISARM_TRIGGER);
        // If we run into any error here we will just
        // commit the error log and move on. Let the
        // system continue to boot and let the user
        // salvage the data
        if (l_err)
        {
            // Committing the error as we don't want this to interrupt
            // the boot. This will notify the user that action is needed
            // on this module
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit( l_err, NVDIMM_COMP_ID );
            o_disarm_successful = false;
            continue;
        }

        // Disarm successful, update armed status
        l_err = NVDIMM::notifyNvdimmProtectionChange(l_nvdimm,
                                                     NVDIMM::NVDIMM_DISARMED);
        if (l_err)
        {
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            l_err->collectTrace(NVDIMM_COMP_NAME);
            errlCommit(l_err, NVDIMM_COMP_ID);
        }
    }

    TRACFCOMP(g_trac_nvdimm, EXIT_MRK"nvdimmDisarm() returning %d",
              o_disarm_successful);

     return o_disarm_successful;

}


/*
 * @brief Wrapper function to return NVDIMMs to factory default
 */
bool nvdimmFactoryDefault(TargetHandleList &i_nvdimmList)
{
    errlHndl_t l_err = nullptr;
    bool l_success = true;

    // Factory default for all nvdimms in the list
    for (const auto & l_nvdimm : i_nvdimmList)
    {
        l_err = nvdimm_factory_reset(l_nvdimm);
        if (l_err)
        {
            l_success = false;
            errlCommit( l_err, NVDIMM_COMP_ID );
            continue;
        }

        // Update nvdimm status
        l_err = notifyNvdimmProtectionChange(l_nvdimm, NVDIMM_DISARMED);
        if (l_err)
        {
            errlCommit( l_err, NVDIMM_COMP_ID );
        }
    }

    return l_success;
}


/*
 * @brief Function to start secure erase verify of NVDIMMs
 */
bool nvdimmSecureEraseVerifyStart(TargetHandleList &i_nvdimmList)
{
    errlHndl_t l_err = nullptr;
    bool l_success = true;

    // Secure erase verify for all nvdimms in the list
    for (const auto & l_nvdimm : i_nvdimmList)
    {
        // Clear the erase_verify_status reg
        l_err = nvdimmWriteReg(l_nvdimm,
                               ERASE_VERIFY_STATUS,
                               ERASE_VERIFY_CLEAR);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                      "nvdimmSecureEraseVerifyStart() HUID 0x%X"
                      "Failed to write ERASE_VERIFY_STATUS register",
                      get_huid(l_nvdimm));
            l_success = false;
            errlCommit( l_err, NVDIMM_COMP_ID );
            continue;
        }

        // Start the erase verify operation
        l_err = nvdimmWriteReg(l_nvdimm,
                               ERASE_VERIFY_CONTROL,
                               ERASE_VERIFY_START);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                      "nvdimmSecureEraseVerifyStart() HUID 0x%X"
                      "Failed to write ERASE_VERIFY_CONTROL register",
                      get_huid(l_nvdimm));
            l_success = false;
            errlCommit( l_err, NVDIMM_COMP_ID );
            continue;
        }

        // Call notify to clear NV_STATUS bit
        l_err = notifyNvdimmProtectionChange(l_nvdimm,
                                             ERASE_VERIFY_STARTED);
        if (l_err)
        {
            l_success = false;
            errlCommit(l_err, NVDIMM_COMP_ID);
            continue;
        }
    }

    return l_success;
}


/*
 * @brief Function to check status of secure erase verify of NVDIMMs
 */
bool nvdimmSecureEraseVerifyStatus(TargetHandleList &i_nvdimmList)
{
    errlHndl_t l_err = nullptr;
    bool l_success = true;
    uint8_t l_data = 0;

    // Check secure erase verify status for all nvdimms in the list
    for (const auto & l_nvdimm : i_nvdimmList)
    {
        // Check if secure-erase-verify is already complete for this nvdimm
        ATTR_NV_STATUS_FLAG_type l_nv_status =
                l_nvdimm->getAttr<ATTR_NV_STATUS_FLAG>();
        if (l_nv_status & NV_STATUS_ERASE_VERIFY_SET)
        {
            continue;
        }

        l_err = nvdimmReadReg(l_nvdimm, ERASE_VERIFY_CONTROL, l_data);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                      "nvdimmSecureEraseVerifyStatus() HUID 0x%X"
                      "Failed to read ERASE_VERIFY_CONTROL register",
                      get_huid(l_nvdimm));
            l_success = false;
            errlCommit( l_err, NVDIMM_COMP_ID );
            continue;  // Continue to next nvdimm
        }

        // If trigger is set the operation is not yet complete
        if (l_data & ERASE_VERIFY_TRIGGER)
        {
            continue;  // Continue to next nvdimm
        }

        // Secure erase verify on this nvdimm is complete
        // Call notify to set NV_STATUS bit
        l_err = notifyNvdimmProtectionChange(l_nvdimm,
                                             ERASE_VERIFY_COMPLETED);
        if (l_err)
        {
            l_success = false;
            errlCommit(l_err, NVDIMM_COMP_ID);
        }


        // Check the status register
        l_err = nvdimmReadReg(l_nvdimm, ERASE_VERIFY_STATUS, l_data);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                      "nvdimmSecureEraseVerifyStatus() HUID 0x%X"
                      "Failed to read ERASE_VERIFY_STATUS register",
                      get_huid(l_nvdimm));
            l_success = false;
            errlCommit( l_err, NVDIMM_COMP_ID );
            continue;  // Continue to next nvdimm
        }

        // Non-zero status is an error
        if (l_data)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmSecureEraseVerifyStatus() "
                      "HUID 0x%X ERASE_VERIFY_STATUS returned non-zero status",
                      get_huid(l_nvdimm));
            /*@
            *@errortype
            *@reasoncode       NVDIMM_ERASE_VERIFY_STATUS_NONZERO
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_SECURE_ERASE_VERIFY_STATUS
            *@userdata1        NVDIMM HUID
            *@userdata2        ERASE_VERIFY_STATUS
            *@devdesc          Error detected during secure erase verify
            *@custdesc         NVDIMM erase error
            */
            l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                NVDIMM_SECURE_ERASE_VERIFY_STATUS,
                                NVDIMM_ERASE_VERIFY_STATUS_NONZERO,
                                get_huid(l_nvdimm),
                                l_data,
                                ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace(NVDIMM_COMP_NAME);
            l_err->addPartCallout( l_nvdimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            nvdimmAddVendorLog(l_nvdimm, l_err);
            errlCommit( l_err, NVDIMM_COMP_ID );
            l_success = false;
            continue;  // Continue to next nvdimm
        }


        // Check the result registers
        uint16_t l_result = 0;
        l_err = nvdimmReadReg(l_nvdimm, ERASE_VERIFY_RESULT_MSB, l_data);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                      "nvdimmSecureEraseVerifyStatus() HUID 0x%X"
                      "Failed to read ERASE_VERIFY_RESULT_MSB register",
                      get_huid(l_nvdimm));
            l_success = false;
            errlCommit( l_err, NVDIMM_COMP_ID );
            continue;  // Continue to next nvdimm
        }

        // Save result
        l_result = l_data << 8;

        l_err = nvdimmReadReg(l_nvdimm, ERASE_VERIFY_RESULT_LSB, l_data);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK
                      "nvdimmSecureEraseVerifyStatus() HUID 0x%X"
                      "Failed to read ERASE_VERIFY_RESULT_LSB register",
                      get_huid(l_nvdimm));
            l_success = false;
            errlCommit( l_err, NVDIMM_COMP_ID );
            continue;  // Continue to next nvdimm
        }

        // Save result
        l_result |= l_data;

        // Non-zero result is an error
        if (l_result)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK"nvdimmSecureEraseVerifyStatus() "
                      "HUID 0x%X ERASE_VERIFY_RESULT returned non-zero data",
                      get_huid(l_nvdimm));
            /*@
            *@errortype
            *@reasoncode       NVDIMM_ERASE_VERIFY_RESULT_NONZERO
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_SECURE_ERASE_VERIFY_STATUS
            *@userdata1        NVDIMM HUID
            *@userdata2        ERASE_VERIFY_RESULT
            *@devdesc          Error detected during secure erase verify
            *@custdesc         NVDIMM erase error
            */
            l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                NVDIMM_SECURE_ERASE_VERIFY_STATUS,
                                NVDIMM_ERASE_VERIFY_RESULT_NONZERO,
                                get_huid(l_nvdimm),
                                l_result,
                                ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace(NVDIMM_COMP_NAME);
            l_err->addPartCallout( l_nvdimm,
                                   HWAS::NV_CONTROLLER_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            nvdimmAddVendorLog(l_nvdimm, l_err);
            errlCommit( l_err, NVDIMM_COMP_ID );
            l_success = false;
            continue;  // Continue to next nvdimm
        }

    }

    return l_success;
}


} // end NVDIMM namespace
