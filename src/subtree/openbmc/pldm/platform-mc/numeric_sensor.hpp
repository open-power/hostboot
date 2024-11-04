#pragma once

#include "libpldm/platform.h"
#include "libpldm/pldm.h"

#include "common/types.hpp"
#include "common/utils.hpp"

#include <sdbusplus/server/object.hpp>
#include <xyz/openbmc_project/Association/Definitions/server.hpp>
#include <xyz/openbmc_project/Inventory/Source/PLDM/Entity/server.hpp>
#include <xyz/openbmc_project/Metric/Value/server.hpp>
#include <xyz/openbmc_project/Sensor/Threshold/Critical/server.hpp>
#include <xyz/openbmc_project/Sensor/Threshold/Warning/server.hpp>
#include <xyz/openbmc_project/Sensor/Value/server.hpp>
#include <xyz/openbmc_project/State/Decorator/Availability/server.hpp>
#include <xyz/openbmc_project/State/Decorator/OperationalStatus/server.hpp>

#include <string>

namespace pldm
{
namespace platform_mc
{

constexpr const char* SENSOR_VALUE_INTF = "xyz.openbmc_project.Sensor.Value";
constexpr const char* METRIC_VALUE_INTF = "xyz.openbmc_project.Metric.Value";

using SensorUnit = sdbusplus::xyz::openbmc_project::Sensor::server::Value::Unit;
using ValueIntf = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::Sensor::server::Value>;
using MetricUnit = sdbusplus::xyz::openbmc_project::Metric::server::Value::Unit;
using MetricIntf = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::Metric::server::Value>;
using ThresholdWarningIntf = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::Sensor::Threshold::server::Warning>;
using ThresholdCriticalIntf = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::Sensor::Threshold::server::Critical>;
using OperationalStatusIntf =
    sdbusplus::server::object_t<sdbusplus::xyz::openbmc_project::State::
                                    Decorator::server::OperationalStatus>;
using AvailabilityIntf = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::State::Decorator::server::Availability>;
using AssociationDefinitionsInft = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::Association::server::Definitions>;
using EntityIntf = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::Inventory::Source::PLDM::server::Entity>;

/**
 * @brief NumericSensor
 *
 * This class handles sensor reading updated by sensor manager and export
 * status to D-Bus interface.
 */
class NumericSensor
{
  public:
    NumericSensor(const pldm_tid_t tid, const bool sensorDisabled,
                  std::shared_ptr<pldm_numeric_sensor_value_pdr> pdr,
                  std::string& sensorName, std::string& associationPath);

    NumericSensor(const pldm_tid_t tid, const bool sensorDisabled,
                  std::shared_ptr<pldm_compact_numeric_sensor_pdr> pdr,
                  std::string& sensorName, std::string& associationPath);

    ~NumericSensor() {};

    /** @brief The function called by Sensor Manager to set sensor to
     * error status.
     */
    void handleErrGetSensorReading();

    /** @brief Updating the sensor status to D-Bus interface
     */
    void updateReading(bool available, bool functional, double value = 0);

    /** @brief ConversionFormula is used to convert raw value to the unit
     * specified in PDR
     *
     *  @param[in] value - raw value
     *  @return double - converted value
     */
    double conversionFormula(double value);

    /** @brief UnitModifier is used to apply the unit modifier specified in PDR
     *
     *  @param[in] value - raw value
     *  @return double - converted value
     */
    double unitModifier(double value);

    /** @brief Check if value is over threshold.
     *
     *  @param[in] alarm - previous alarm state
     *  @param[in] direction - upper or lower threshold checking
     *  @param[in] value - raw value
     *  @param[in] threshold - threshold value
     *  @param[in] hyst - hysteresis value
     *  @return bool - new alarm state
     */
    bool checkThreshold(bool alarm, bool direction, double value,
                        double threshold, double hyst);

    /** @brief Updating the association to D-Bus interface
     *  @param[in] inventoryPath - inventory path of the entity
     */
    inline void setInventoryPath(const std::string& inventoryPath)
    {
        if (associationDefinitionsIntf)
        {
            associationDefinitionsIntf->associations(
                {{"chassis", "all_sensors", inventoryPath}});
        }
    }

    /** @brief Get Upper Critical threshold
     *
     *  @return double - Upper Critical threshold
     */
    double getThresholdUpperCritical()
    {
        if (thresholdCriticalIntf)
        {
            return thresholdCriticalIntf->criticalHigh();
        }
        else
        {
            return std::numeric_limits<double>::quiet_NaN();
        }
    };

    /** @brief Get Lower Critical threshold
     *
     *  @return double - Lower Critical threshold
     */
    double getThresholdLowerCritical()
    {
        if (thresholdCriticalIntf)
        {
            return thresholdCriticalIntf->criticalLow();
        }
        else
        {
            return std::numeric_limits<double>::quiet_NaN();
        }
    };

    /** @brief Get Upper Warning threshold
     *
     *  @return double - Upper Warning threshold
     */
    double getThresholdUpperWarning()
    {
        if (thresholdWarningIntf)
        {
            return thresholdWarningIntf->warningHigh();
        }
        else
        {
            return std::numeric_limits<double>::quiet_NaN();
        }
    };

    /** @brief Get Lower Warning threshold
     *
     *  @return double - Lower Warning threshold
     */
    double getThresholdLowerWarning()
    {
        if (thresholdWarningIntf)
        {
            return thresholdWarningIntf->warningLow();
        }
        else
        {
            return std::numeric_limits<double>::quiet_NaN();
        }
    };

    /** @brief Check if value is over threshold.
     *
     *  @param[in] eventType - event level in pldm::utils::Level
     *  @param[in] direction - direction type in pldm::utils::Direction
     *  @param[in] rawValue - sensor raw value
     *  @param[in] newAlarm - trigger alarm true/false
     *  @param[in] assert - event type asserted/deasserted
     *
     *  @return PLDM completion code
     */
    int triggerThresholdEvent(pldm::utils::Level eventType,
                              pldm::utils::Direction direction, double rawValue,
                              bool newAlarm, bool assert);

    /** @brief Terminus ID which the sensor belongs to */
    pldm_tid_t tid;

    /** @brief Sensor ID */
    uint16_t sensorId;

    /** @brief  The time stamp since last getSensorReading command in usec */
    uint64_t timeStamp;

    /** @brief  The time of sensor update interval in usec */
    uint64_t updateTime;

    /** @brief  sensorName */
    std::string sensorName;

    /** @brief  sensorNameSpace */
    std::string sensorNameSpace;

  private:
    /**
     * @brief Check sensor reading if any threshold has been crossed and update
     * Threshold interfaces accordingly
     */
    void updateThresholds();

    /** @brief Create the sensor inventory path.
     *
     *  @param[in] associationPath - sensor association path
     *  @param[in] sensorName - sensor name
     *  @param[in] entityType - sensor PDR entity type
     *  @param[in] entityInstanceNum - sensor PDR entity instance number
     *  @param[in] containerId - sensor PDR entity container ID
     *
     *  @return True when success otherwise return False
     */
    inline bool createInventoryPath(
        const std::string& associationPath, const std::string& sensorName,
        const uint16_t entityType, const uint16_t entityInstanceNum,
        const uint16_t containerId);

    std::unique_ptr<MetricIntf> metricIntf = nullptr;
    std::unique_ptr<ValueIntf> valueIntf = nullptr;
    std::unique_ptr<ThresholdWarningIntf> thresholdWarningIntf = nullptr;
    std::unique_ptr<ThresholdCriticalIntf> thresholdCriticalIntf = nullptr;
    std::unique_ptr<AvailabilityIntf> availabilityIntf = nullptr;
    std::unique_ptr<OperationalStatusIntf> operationalStatusIntf = nullptr;
    std::unique_ptr<AssociationDefinitionsInft> associationDefinitionsIntf =
        nullptr;
    std::unique_ptr<EntityIntf> entityIntf = nullptr;

    /** @brief Amount of hysteresis associated with the sensor thresholds */
    double hysteresis;

    /** @brief The resolution of sensor in Units */
    double resolution;

    /** @brief A constant value that is added in as part of conversion process
     * of converting a raw sensor reading to Units */
    double offset;

    /** @brief A power-of-10 multiplier for baseUnit */
    int8_t baseUnitModifier;
    bool useMetricInterface = false;
};
} // namespace platform_mc
} // namespace pldm
