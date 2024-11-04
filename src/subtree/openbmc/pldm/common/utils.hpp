#pragma once

#include "types.hpp"

#include <libpldm/base.h>
#include <libpldm/bios.h>
#include <libpldm/entity.h>
#include <libpldm/pdr.h>
#include <libpldm/platform.h>
#include <libpldm/utils.h>
#include <systemd/sd-bus.h>
#include <unistd.h>

#include <nlohmann/json.hpp>
#include <sdbusplus/server.hpp>
#include <xyz/openbmc_project/Inventory/Manager/client.hpp>
#include <xyz/openbmc_project/Logging/Entry/server.hpp>
#include <xyz/openbmc_project/ObjectMapper/client.hpp>

#include <cstdint>
#include <deque>
#include <exception>
#include <filesystem>
#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <vector>

constexpr uint64_t dbusTimeout =
    std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::seconds(DBUS_TIMEOUT))
        .count();

namespace pldm
{
namespace utils
{

enum class Level
{
    WARNING,
    CRITICAL,
    PERFORMANCELOSS,
    SOFTSHUTDOWN,
    HARDSHUTDOWN,
    ERROR
};
enum class Direction
{
    HIGH,
    LOW,
    ERROR
};

const std::set<std::string_view> dbusValueTypeNames = {
    "bool",    "uint8_t",  "int16_t",         "uint16_t",
    "int32_t", "uint32_t", "int64_t",         "uint64_t",
    "double",  "string",   "vector<uint8_t>", "vector<string>"};
const std::set<std::string_view> dbusValueNumericTypeNames = {
    "uint8_t",  "int16_t", "uint16_t", "int32_t",
    "uint32_t", "int64_t", "uint64_t", "double"};

namespace fs = std::filesystem;
using Json = nlohmann::json;
constexpr bool Tx = true;
constexpr bool Rx = false;
using ObjectMapper = sdbusplus::client::xyz::openbmc_project::ObjectMapper<>;
using inventoryManager =
    sdbusplus::client::xyz::openbmc_project::inventory::Manager<>;

constexpr auto dbusProperties = "org.freedesktop.DBus.Properties";
constexpr auto mapperService = ObjectMapper::default_service;
constexpr auto inventoryPath = "/xyz/openbmc_project/inventory";
/** @struct CustomFD
 *
 *  RAII wrapper for file descriptor.
 */
struct CustomFD
{
    CustomFD(const CustomFD&) = delete;
    CustomFD& operator=(const CustomFD&) = delete;
    CustomFD(CustomFD&&) = delete;
    CustomFD& operator=(CustomFD&&) = delete;

    CustomFD(int fd) : fd(fd) {}

    ~CustomFD()
    {
        if (fd >= 0)
        {
            close(fd);
        }
    }

    int operator()() const
    {
        return fd;
    }

  private:
    int fd = -1;
};

/** @brief Calculate the pad for PLDM data
 *
 *  @param[in] data - Length of the data
 *  @return - uint8_t - number of pad bytes
 */
uint8_t getNumPadBytes(uint32_t data);

/** @brief Convert uint64 to date
 *
 *  @param[in] data - time date of uint64
 *  @param[out] year - year number in dec
 *  @param[out] month - month number in dec
 *  @param[out] day - day of the month in dec
 *  @param[out] hour - number of hours in dec
 *  @param[out] min - number of minutes in dec
 *  @param[out] sec - number of seconds in dec
 *  @return true if decode success, false if decode failed
 */
bool uintToDate(uint64_t data, uint16_t* year, uint8_t* month, uint8_t* day,
                uint8_t* hour, uint8_t* min, uint8_t* sec);

/** @brief Convert effecter data to structure of set_effecter_state_field
 *
 *  @param[in] effecterData - the date of effecter
 *  @param[in] effecterCount - the number of individual sets of effecter
 *                              information
 *  @return[out] parse success and get a valid set_effecter_state_field
 *               structure, return nullopt means parse failed
 */
std::optional<std::vector<set_effecter_state_field>> parseEffecterData(
    const std::vector<uint8_t>& effecterData, uint8_t effecterCount);

/**
 *  @brief creates an error log
 *  @param[in] errorMsg - the error message
 */
void reportError(const char* errorMsg);

/** @brief Convert any Decimal number to BCD
 *
 *  @tparam[in] decimal - Decimal number
 *  @return Corresponding BCD number
 */
template <typename T>
T decimalToBcd(T decimal)
{
    T bcd = 0;
    T rem = 0;
    auto cnt = 0;

    while (decimal)
    {
        rem = decimal % 10;
        bcd = bcd + (rem << cnt);
        decimal = decimal / 10;
        cnt += 4;
    }

    return bcd;
}

struct DBusMapping
{
    std::string objectPath;   //!< D-Bus object path
    std::string interface;    //!< D-Bus interface
    std::string propertyName; //!< D-Bus property name
    std::string propertyType; //!< D-Bus property type
};

using PropertyValue =
    std::variant<bool, uint8_t, int16_t, uint16_t, int32_t, uint32_t, int64_t,
                 uint64_t, double, std::string, std::vector<uint8_t>,
                 std::vector<std::string>>;
using DbusProp = std::string;
using DbusChangedProps = std::map<DbusProp, PropertyValue>;
using DBusInterfaceAdded = std::vector<
    std::pair<pldm::dbus::Interface,
              std::vector<std::pair<pldm::dbus::Property,
                                    std::variant<pldm::dbus::Property>>>>>;

using ObjectPath = std::string;
using EntityName = std::string;
using Entities = std::vector<pldm_entity_node*>;
using EntityAssociations = std::vector<Entities>;
using ObjectPathMaps = std::map<fs::path, pldm_entity_node*>;
using EntityMaps = std::map<pldm::pdr::EntityType, EntityName>;

using ServiceName = std::string;
using Interfaces = std::vector<std::string>;
using MapperServiceMap = std::vector<std::pair<ServiceName, Interfaces>>;
using GetSubTreeResponse = std::vector<std::pair<ObjectPath, MapperServiceMap>>;
using GetSubTreePathsResponse = std::vector<std::string>;
using PropertyMap = std::map<std::string, PropertyValue>;
using InterfaceMap = std::map<std::string, PropertyMap>;
using ObjectValueTree = std::map<sdbusplus::message::object_path, InterfaceMap>;

/**
 * @brief The interface for DBusHandler
 */
class DBusHandlerInterface
{
  public:
    virtual ~DBusHandlerInterface() = default;

    virtual std::string getService(const char* path,
                                   const char* interface) const = 0;
    virtual GetSubTreeResponse
        getSubtree(const std::string& path, int depth,
                   const std::vector<std::string>& ifaceList) const = 0;

    virtual GetSubTreePathsResponse
        getSubTreePaths(const std::string& objectPath, int depth,
                        const std::vector<std::string>& ifaceList) const = 0;

    virtual void setDbusProperty(const DBusMapping& dBusMap,
                                 const PropertyValue& value) const = 0;

    virtual PropertyValue
        getDbusPropertyVariant(const char* objPath, const char* dbusProp,
                               const char* dbusInterface) const = 0;

    virtual PropertyMap
        getDbusPropertiesVariant(const char* serviceName, const char* objPath,
                                 const char* dbusInterface) const = 0;
};

/**
 *  @class DBusHandler
 *
 *  Wrapper class to handle the D-Bus calls
 *
 *  This class contains the APIs to handle the D-Bus calls
 *  to cater the request from pldm requester.
 *  A class is created to mock the apis in the test cases
 */
class DBusHandler : public DBusHandlerInterface
{
  public:
    /** @brief Get the bus connection. */
    static auto& getBus()
    {
        static auto bus = sdbusplus::bus::new_default();
        return bus;
    }

    /**
     *  @brief Get the DBUS Service name for the input dbus path
     *
     *  @param[in] path - DBUS object path
     *  @param[in] interface - DBUS Interface
     *
     *  @return std::string - the dbus service name
     *
     *  @throw sdbusplus::exception_t when it fails
     */
    std::string getService(const char* path,
                           const char* interface) const override;

    /**
     *  @brief Get the Subtree response from the mapper
     *
     *  @param[in] path - DBUS object path
     *  @param[in] depth - Search depth
     *  @param[in] ifaceList - list of the interface that are being
     *                         queried from the mapper
     *
     *  @return GetSubTreeResponse - the mapper subtree response
     *
     *  @throw sdbusplus::exception_t when it fails
     */
    GetSubTreeResponse
        getSubtree(const std::string& path, int depth,
                   const std::vector<std::string>& ifaceList) const override;

    /** @brief Get Subtree path response from the mapper
     *
     *  @param[in] path - DBUS object path
     *  @param[in] depth - Search depth
     *  @param[in] ifaceList - list of the interface that are being
     *                         queried from the mapper
     *
     *  @return std::vector<std::string> vector of subtree paths
     */
    GetSubTreePathsResponse getSubTreePaths(
        const std::string& objectPath, int depth,
        const std::vector<std::string>& ifaceList) const override;

    /** @brief Get property(type: variant) from the requested dbus
     *
     *  @param[in] objPath - The Dbus object path
     *  @param[in] dbusProp - The property name to get
     *  @param[in] dbusInterface - The Dbus interface
     *
     *  @return The value of the property(type: variant)
     *
     *  @throw sdbusplus::exception_t when it fails
     */
    PropertyValue
        getDbusPropertyVariant(const char* objPath, const char* dbusProp,
                               const char* dbusInterface) const override;

    /** @brief Get All properties(type: variant) from the requested dbus
     *
     *  @param[in] serviceName - The Dbus service name
     *  @param[in] objPath - The Dbus object path
     *  @param[in] dbusInterface - The Dbus interface
     *
     *  @return The values of the properties(type: variant)
     *
     *  @throw sdbusplus::exception_t when it fails
     */
    PropertyMap
        getDbusPropertiesVariant(const char* serviceName, const char* objPath,
                                 const char* dbusInterface) const override;

    /** @brief The template function to get property from the requested dbus
     *         path
     *
     *  @tparam Property - Excepted type of the property on dbus
     *
     *  @param[in] objPath - The Dbus object path
     *  @param[in] dbusProp - The property name to get
     *  @param[in] dbusInterface - The Dbus interface
     *
     *  @return The value of the property
     *
     *  @throw sdbusplus::exception_t when dbus request fails
     *         std::bad_variant_access when \p Property and property on dbus do
     *         not match
     */
    template <typename Property>
    auto getDbusProperty(const char* objPath, const char* dbusProp,
                         const char* dbusInterface)
    {
        auto VariantValue =
            getDbusPropertyVariant(objPath, dbusProp, dbusInterface);
        return std::get<Property>(VariantValue);
    }

    /** @brief Set Dbus property
     *
     *  @param[in] dBusMap - Object path, property name, interface and property
     *                       type for the D-Bus object
     *  @param[in] value - The value to be set
     *
     *  @throw sdbusplus::exception_t when it fails
     */
    void setDbusProperty(const DBusMapping& dBusMap,
                         const PropertyValue& value) const override;

    /** @brief This function retrieves the properties of an object managed
     *         by the specified D-Bus service located at the given object path.
     *
     *  @param[in] service - The D-Bus service providing the managed object
     *  @param[in] value - The object path of the managed object
     *
     *  @return A hierarchical structure representing the properties of the
     *          managed object.
     *  @throw sdbusplus::exception_t when it fails
     */
    static ObjectValueTree getManagedObj(const char* service, const char* path);

    /** @brief Retrieve the inventory objects managed by a specified class.
     *         The retrieved inventory objects are cached statically
     *         and returned upon subsequent calls to this function.
     *
     *  @tparam ClassType - The class type that manages the inventory objects.
     *
     *  @return A reference to the cached inventory objects.
     */
    template <typename ClassType>
    static auto& getInventoryObjects()
    {
        static ObjectValueTree object = ClassType::getManagedObj(
            inventoryManager::interface, inventoryPath);
        return object;
    }
};

/** @brief Fetch parent D-Bus object based on pathname
 *
 *  @param[in] dbusObj - child D-Bus object
 *
 *  @return std::string - the parent D-Bus object path
 */
inline std::string findParent(const std::string& dbusObj)
{
    fs::path p(dbusObj);
    return p.parent_path().string();
}

/** @brief Read (static) MCTP EID of host firmware from a file
 *
 *  @return uint8_t - MCTP EID
 */
uint8_t readHostEID();

/** @brief Validate the MCTP EID of MCTP endpoint
 *         In `Table 2 - Special endpoint IDs` of DSP0236. EID 0 is NULL_EID.
 *         EID from 1 to 7 is reserved EID. EID 0xFF is broadcast EID.
 *         Those are invalid EID of one MCTP Endpoint.
 *
 * @param[in] eid - MCTP EID
 *
 * @return true if the MCTP EID is valid otherwise return false.
 */
bool isValidEID(eid mctpEid);

/** @brief Convert a value in the JSON to a D-Bus property value
 *
 *  @param[in] type - type of the D-Bus property
 *  @param[in] value - value in the JSON file
 *
 *  @return PropertyValue - the D-Bus property value
 */
PropertyValue jsonEntryToDbusVal(std::string_view type,
                                 const nlohmann::json& value);

/** @brief Find State Effecter PDR
 *  @param[in] tid - PLDM terminus ID.
 *  @param[in] entityID - entity that can be associated with PLDM State set.
 *  @param[in] stateSetId - value that identifies PLDM State set.
 *  @param[in] repo - pointer to BMC's primary PDR repo.
 *  @return array[array[uint8_t]] - StateEffecterPDRs
 */
std::vector<std::vector<uint8_t>> findStateEffecterPDR(
    uint8_t tid, uint16_t entityID, uint16_t stateSetId, const pldm_pdr* repo);
/** @brief Find State Sensor PDR
 *  @param[in] tid - PLDM terminus ID.
 *  @param[in] entityID - entity that can be associated with PLDM State set.
 *  @param[in] stateSetId - value that identifies PLDM State set.
 *  @param[in] repo - pointer to BMC's primary PDR repo.
 *  @return array[array[uint8_t]] - StateSensorPDRs
 */
std::vector<std::vector<uint8_t>> findStateSensorPDR(
    uint8_t tid, uint16_t entityID, uint16_t stateSetId, const pldm_pdr* repo);

/** @brief Find sensor id from a state sensor PDR
 *
 *  @param[in] pdrRepo - PDR repository
 *  @param[in] tid - terminus id
 *  @param[in] entityType - entity type
 *  @param[in] entityInstance - entity instance number
 *  @param[in] containerId - container id
 *  @param[in] stateSetId - state set id
 *
 *  @return uint16_t - the sensor id
 */
uint16_t findStateSensorId(const pldm_pdr* pdrRepo, uint8_t tid,
                           uint16_t entityType, uint16_t entityInstance,
                           uint16_t containerId, uint16_t stateSetId);

/** @brief Find effecter id from a state effecter pdr
 *  @param[in] pdrRepo - PDR repository
 *  @param[in] entityType - entity type
 *  @param[in] entityInstance - entity instance number
 *  @param[in] containerId - container id
 *  @param[in] stateSetId - state set id
 *  @param[in] localOrRemote - true for checking local repo and false for remote
 *                             repo
 *
 *  @return uint16_t - the effecter id
 */
uint16_t findStateEffecterId(const pldm_pdr* pdrRepo, uint16_t entityType,
                             uint16_t entityInstance, uint16_t containerId,
                             uint16_t stateSetId, bool localOrRemote);

/** @brief Emit the sensor event signal
 *
 *	@param[in] tid - the terminus id
 *  @param[in] sensorId - sensorID value of the sensor
 *  @param[in] sensorOffset - Identifies which state sensor within a
 * composite state sensor the event is being returned for
 *  @param[in] eventState - The event state value from the state change that
 * triggered the event message
 *  @param[in] previousEventState - The event state value for the state from
 * which the present event state was entered.
 *  @return PLDM completion code
 */
int emitStateSensorEventSignal(uint8_t tid, uint16_t sensorId,
                               uint8_t sensorOffset, uint8_t eventState,
                               uint8_t previousEventState);

/** @brief Print the buffer
 *
 *  @param[in]  isTx - True if the buffer is an outgoing PLDM message, false if
                       the buffer is an incoming PLDM message
 *  @param[in]  buffer - Buffer to print
 *
 *  @return - None
 */
void printBuffer(bool isTx, const std::vector<uint8_t>& buffer);

/** @brief Convert the buffer to std::string
 *
 *  If there are characters that are not printable characters, it is replaced
 *  with space(0x20).
 *
 *  @param[in] var - pointer to data and length of the data
 *
 *  @return std::string equivalent of variable field
 */
std::string toString(const struct variable_field& var);

/** @brief Split strings according to special identifiers
 *
 *  We can split the string according to the custom identifier(';', ',', '&' or
 *  others) and store it to vector.
 *
 *  @param[in] srcStr       - The string to be split
 *  @param[in] delim        - The custom identifier
 *  @param[in] trimStr      - The first and last string to be trimmed
 *
 *  @return std::vector<std::string> Vectors are used to store strings
 */
std::vector<std::string> split(std::string_view srcStr, std::string_view delim,
                               std::string_view trimStr = "");
/** @brief Get the current system time in readable format
 *
 *  @return - std::string equivalent of the system time
 */
std::string getCurrentSystemTime();

/** @brief checks if the FRU is actually present.
 *  @param[in] objPath - FRU object path.
 *
 *  @return bool to indicate presence or absence of FRU.
 */
bool checkForFruPresence(const std::string& objPath);

/** @brief Method to check if the logical bit is set
 *
 *  @param[containerId] - container id of the entity
 *
 *  @return true or false based on the logic bit set
 */
bool checkIfLogicalBitSet(const uint16_t& containerId);

/** @brief setting the present property
 *
 *  @param[in] objPath - the object path of the fru
 *  @param[in] present - status to set either true/false
 */
void setFruPresence(const std::string& fruObjPath, bool present);

/** @brief Trim `\0` in string and replace ` ` by `_` to use name in D-Bus
 *         object path
 *
 *  @param[in] name - the input string
 *
 *  @return the result string
 */
std::string_view trimNameForDbus(std::string& name);

/** @brief Convert the number type D-Bus Value to the double
 *
 *  @param[in] type - string type should in dbusValueNumericTypeNames list
 *  @param[in] value - DBus PropertyValue variant
 *  @param[out] doubleValue - response value
 *
 *  @return true if data type is corrected and converting is successful
 *          otherwise return false.
 */
bool dbusPropValuesToDouble(const std::string_view& type,
                            const pldm::utils::PropertyValue& value,
                            double* doubleValue);

} // namespace utils
} // namespace pldm
