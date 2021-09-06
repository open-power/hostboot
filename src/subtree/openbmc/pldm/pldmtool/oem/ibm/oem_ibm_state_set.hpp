#include "oem/ibm/libpldmresponder/oem_ibm_handler.hpp"

/** @brief PLDM OEM State Set range as per DSP0249_1.1.0 specification
 */
enum pldm_oem_state_set_id_codes
{
    PLDM_OEM_STATE_SET_START = 32768,
    PLDM_OEM_STATE_SET_END = 65535,

};

/** @brief PLDM OEM IBM Code Update possible state set values
 */
enum pldm_oem_ibm_cu_state_set_values
{
    OEM_IBM_STATE_SET_CU_START = 1,
    OEM_IBM_STATE_SET_CU_END = 2,
    OEM_IBM_STATE_SET_CU_FAIL = 3,
    OEM_IBM_STATE_SET_CU_ABORT = 4,
    OEM_IBM_STATE_SET_CU_ACCEPT = 5,
    OEM_IBM_STATE_SET_CU_REJECT = 6,
};

/** @brief PLDM OEM IBM Verification possible state set values
 */
enum pldm_oem_ibm_verification_state_set_values
{
    OEM_IBM_STATE_SET_VERFICATION_VALID = 0,
    OEM_IBM_STATE_SET_VERFICATION_ENTITLEMENT_FAIL = 1,
    OEM_IBM_STATE_SET_VERFICATION_BANNED_PLATFORM_FAIL = 2,
    OEM_IBM_STATE_SET_VERFICATION_MIN_MIF_FAIL = 4,
};

/** @brief PLDM OEM IBM system power state possible state set values
 */
enum pldm_oem_ibm_sys_power_state_set_values
{
    OEM_IBM_STATE_SET_SYS_PWR_STATE_RECYCLE_HARD = 1,
};

/** @brief PLDM OEM IBM boot state possible state set values
 */
enum pldm_oem_ibm_boot_state_set_values
{
    OEM_IBM_STATE_SET_BOOT_STATE_P_SIDE = 1,
    OEM_IBM_STATE_SET_BOOT_STATE_T_SIDE = 2,
};

/** @brief Map for PLDM OEM IBM Entity Types
 */
extern const std::map<uint8_t, std::string> OemIBMEntityType{
    {pldm::responder::oem_ibm_platform::PLDM_OEM_IBM_ENTITY_FIRMWARE_UPDATE,
     "OEM IBM Firmware Update"},
    {PLDM_OEM_ENTITY_TYPE_START, "OEM IBM Entity Type Start"},
    {PLDM_OEM_ENTITY_TYPE_END, "OEM IBM Entity Type End"},
};

/** @brief Map for PLDM OEM IBM State Sets
 */
extern const std::map<uint16_t, std::string> OemIBMstateSet{
    {PLDM_OEM_IBM_FIRMWARE_UPDATE_STATE, "OEM IBM Firmware Update State"},
    {PLDM_OEM_IBM_BOOT_STATE, "OEM IBM Boot State"},
    {pldm::responder::oem_ibm_platform::PLDM_OEM_IBM_VERIFICATION_STATE,
     "OEM IBM Verification State"},
    {PLDM_OEM_IBM_SYSTEM_POWER_STATE, "OEM IBM System Power State"}};

/** @brief Map for PLDM OEM IBM firmware update possible state values
 */
extern const std::map<uint8_t, std::string> SetOemIBMFWUpdateStateValues{
    {OEM_IBM_STATE_SET_CU_START, "Start"},
    {OEM_IBM_STATE_SET_CU_END, "End"},
    {OEM_IBM_STATE_SET_CU_FAIL, "Fail"},
    {OEM_IBM_STATE_SET_CU_ABORT, "Abort"},
    {OEM_IBM_STATE_SET_CU_ACCEPT, "Accept"},
    {OEM_IBM_STATE_SET_CU_REJECT, "Reject"}};

/** @brief Map for PLDM OEM IBM verification state possible state values
 */
extern const std::map<uint8_t, std::string> SetOemIBMVerStateValues{
    {OEM_IBM_STATE_SET_VERFICATION_VALID, "Valid"},
    {OEM_IBM_STATE_SET_VERFICATION_ENTITLEMENT_FAIL, "Entitlement Fail"},
    {OEM_IBM_STATE_SET_VERFICATION_BANNED_PLATFORM_FAIL,
     "Banned Platform Fail"},
    {OEM_IBM_STATE_SET_VERFICATION_MIN_MIF_FAIL, "Minimum MIF Fail"}};

/** @brief Map for PLDM OEM IBM systerm power state possible state values
 */
extern const std::map<uint8_t, std::string> SetOemIBMSysPowerStatesValues{
    {OEM_IBM_STATE_SET_SYS_PWR_STATE_RECYCLE_HARD, "Power Cycle Hard"}};

/** @brief Map for PLDM OEM IBM boot state possible state values
 */
extern const std::map<uint8_t, std::string> SetOemIBMBootStateValues{
    {OEM_IBM_STATE_SET_BOOT_STATE_P_SIDE, "P Side"},
    {OEM_IBM_STATE_SET_BOOT_STATE_T_SIDE, "T side"}};

/** @brief Map for populating PLDM OEM IBM state sets with possible state values
 */
extern const std::map<uint16_t, const std::map<uint8_t, std::string>>
    populateOemIBMStateMaps{
        {pldm::responder::oem_ibm_platform::PLDM_OEM_IBM_VERIFICATION_STATE,
         SetOemIBMVerStateValues},
        {PLDM_OEM_IBM_SYSTEM_POWER_STATE, SetOemIBMSysPowerStatesValues},
        {PLDM_OEM_IBM_BOOT_STATE, SetOemIBMBootStateValues},
        {PLDM_OEM_IBM_FIRMWARE_UPDATE_STATE, SetOemIBMFWUpdateStateValues},
    };
