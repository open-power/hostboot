
#include "libpldm/entity.h"
#include "libpldm/platform.h"

#include "platform-mc/numeric_sensor.hpp"
#include "platform-mc/terminus.hpp"

#include <gtest/gtest.h>

TEST(NumericSensor, conversionFormula)
{
    std::vector<uint8_t> pdr1{
        0x1,
        0x0,
        0x0,
        0x0,                     // record handle
        0x1,                     // PDRHeaderVersion
        PLDM_NUMERIC_SENSOR_PDR, // PDRType
        0x0,
        0x0,                     // recordChangeNumber
        PLDM_PDR_NUMERIC_SENSOR_PDR_FIXED_LENGTH +
            PLDM_PDR_NUMERIC_SENSOR_PDR_VARIED_SENSOR_DATA_SIZE_MIN_LENGTH +
            PLDM_PDR_NUMERIC_SENSOR_PDR_VARIED_RANGE_FIELD_MIN_LENGTH,
        0,                             // dataLength
        0,
        0,                             // PLDMTerminusHandle
        0x1,
        0x0,                           // sensorID=1
        PLDM_ENTITY_POWER_SUPPLY,
        0,                             // entityType=Power Supply(120)
        1,
        0,                             // entityInstanceNumber
        0x1,
        0x0,                           // containerID=1
        PLDM_NO_INIT,                  // sensorInit
        false,                         // sensorAuxiliaryNamesPDR
        PLDM_SENSOR_UNIT_DEGRESS_C,    // baseUint(2)=degrees C
        1,                             // unitModifier = 1
        0,                             // rateUnit
        0,                             // baseOEMUnitHandle
        0,                             // auxUnit
        0,                             // auxUnitModifier
        0,                             // auxRateUnit
        0,                             // rel
        0,                             // auxOEMUnitHandle
        true,                          // isLinear
        PLDM_RANGE_FIELD_FORMAT_SINT8, // sensorDataSize
        0,
        0,
        0xc0,
        0x3f, // resolution=1.5
        0,
        0,
        0x80,
        0x3f, // offset=1.0
        0,
        0,    // accuracy
        0,    // plusTolerance
        0,    // minusTolerance
        2,    // hysteresis
        0,    // supportedThresholds
        0,    // thresholdAndHysteresisVolatility
        0,
        0,
        0x80,
        0x3f, // stateTransistionInterval=1.0
        0,
        0,
        0x80,
        0x3f,                          // updateInverval=1.0
        255,                           // maxReadable
        0,                             // minReadable
        PLDM_RANGE_FIELD_FORMAT_UINT8, // rangeFieldFormat
        0,                             // rangeFieldsupport
        0,                             // nominalValue
        0,                             // normalMax
        0,                             // normalMin
        0,                             // warningHigh
        0,                             // warningLow
        0,                             // criticalHigh
        0,                             // criticalLow
        0,                             // fatalHigh
        0                              // fatalLow
    };

    auto numericSensorPdr = std::make_shared<pldm_numeric_sensor_value_pdr>();
    std::printf("pdr size=%ld\n", pdr1.size());
    auto rc = decode_numeric_sensor_pdr_data(pdr1.data(), pdr1.size(),
                                             numericSensorPdr.get());
    EXPECT_EQ(rc, PLDM_SUCCESS);

    std::string sensorName{"test1"};
    std::string inventoryPath{
        "/xyz/openbmc_project/inventroy/Item/Board/PLDM_device_1"};
    pldm::platform_mc::NumericSensor sensor(0x01, true, numericSensorPdr,
                                            sensorName, inventoryPath);
    double reading = 40.0;
    double convertedValue = 0;
    convertedValue = sensor.conversionFormula(reading);
    convertedValue = sensor.unitModifier(convertedValue);

    // (40*1.5 + 1.0 ) * 10^1 = 610
    EXPECT_EQ(610, convertedValue);
}

TEST(NumericSensor, checkThreshold)
{
    std::vector<uint8_t> pdr1{
        0x1,
        0x0,
        0x0,
        0x0,                     // record handle
        0x1,                     // PDRHeaderVersion
        PLDM_NUMERIC_SENSOR_PDR, // PDRType
        0x0,
        0x0,                     // recordChangeNumber
        PLDM_PDR_NUMERIC_SENSOR_PDR_FIXED_LENGTH +
            PLDM_PDR_NUMERIC_SENSOR_PDR_VARIED_SENSOR_DATA_SIZE_MIN_LENGTH +
            PLDM_PDR_NUMERIC_SENSOR_PDR_VARIED_RANGE_FIELD_MIN_LENGTH,
        0,                             // dataLength
        0,
        0,                             // PLDMTerminusHandle
        0x1,
        0x0,                           // sensorID=1
        PLDM_ENTITY_POWER_SUPPLY,
        0,                             // entityType=Power Supply(120)
        1,
        0,                             // entityInstanceNumber
        0x1,
        0x0,                           // containerID=1
        PLDM_NO_INIT,                  // sensorInit
        false,                         // sensorAuxiliaryNamesPDR
        PLDM_SENSOR_UNIT_DEGRESS_C,    // baseUint(2)=degrees C
        1,                             // unitModifier = 1
        0,                             // rateUnit
        0,                             // baseOEMUnitHandle
        0,                             // auxUnit
        0,                             // auxUnitModifier
        0,                             // auxRateUnit
        0,                             // rel
        0,                             // auxOEMUnitHandle
        true,                          // isLinear
        PLDM_RANGE_FIELD_FORMAT_SINT8, // sensorDataSize
        0,
        0,
        0xc0,
        0x3f, // resolution=1.5
        0,
        0,
        0x80,
        0x3f, // offset=1.0
        0,
        0,    // accuracy
        0,    // plusTolerance
        0,    // minusTolerance
        2,    // hysteresis
        0,    // supportedThresholds
        0,    // thresholdAndHysteresisVolatility
        0,
        0,
        0x80,
        0x3f, // stateTransistionInterval=1.0
        0,
        0,
        0x80,
        0x3f,                          // updateInverval=1.0
        255,                           // maxReadable
        0,                             // minReadable
        PLDM_RANGE_FIELD_FORMAT_UINT8, // rangeFieldFormat
        0,                             // rangeFieldsupport
        0,                             // nominalValue
        0,                             // normalMax
        0,                             // normalMin
        0,                             // warningHigh
        0,                             // warningLow
        0,                             // criticalHigh
        0,                             // criticalLow
        0,                             // fatalHigh
        0                              // fatalLow
    };

    auto numericSensorPdr = std::make_shared<pldm_numeric_sensor_value_pdr>();
    auto rc = decode_numeric_sensor_pdr_data(pdr1.data(), pdr1.size(),
                                             numericSensorPdr.get());
    EXPECT_EQ(rc, PLDM_SUCCESS);
    std::string sensorName{"test1"};
    std::string inventoryPath{
        "/xyz/openbmc_project/inventroy/Item/Board/PLDM_device_1"};
    pldm::platform_mc::NumericSensor sensor(0x01, true, numericSensorPdr,
                                            sensorName, inventoryPath);

    bool highAlarm = false;
    bool lowAlarm = false;
    double highThreshold = 40;
    double lowThreshold = 30;
    double hysteresis = 2;

    // reading     35->40->45->38->35->30->25->32->35
    // highAlarm    F->T ->T ->T ->F ->F ->F -> F-> F
    // lowAlarm     F->F ->F ->F ->F ->T ->T -> T ->F
    double reading = 35;
    highAlarm = sensor.checkThreshold(highAlarm, true, reading, highThreshold,
                                      hysteresis);
    EXPECT_EQ(false, highAlarm);
    lowAlarm = sensor.checkThreshold(lowAlarm, false, reading, lowThreshold,
                                     hysteresis);
    EXPECT_EQ(false, lowAlarm);

    reading = 40;
    highAlarm = sensor.checkThreshold(highAlarm, true, reading, highThreshold,
                                      hysteresis);
    EXPECT_EQ(true, highAlarm);
    lowAlarm = sensor.checkThreshold(lowAlarm, false, reading, lowThreshold,
                                     hysteresis);
    EXPECT_EQ(false, lowAlarm);

    reading = 45;
    highAlarm = sensor.checkThreshold(highAlarm, true, reading, highThreshold,
                                      hysteresis);
    EXPECT_EQ(true, highAlarm);
    lowAlarm = sensor.checkThreshold(lowAlarm, false, reading, lowThreshold,
                                     hysteresis);
    EXPECT_EQ(false, lowAlarm);

    reading = 38;
    highAlarm = sensor.checkThreshold(highAlarm, true, reading, highThreshold,
                                      hysteresis);
    EXPECT_EQ(true, highAlarm);
    lowAlarm = sensor.checkThreshold(lowAlarm, false, reading, lowThreshold,
                                     hysteresis);
    EXPECT_EQ(false, lowAlarm);

    reading = 35;
    highAlarm = sensor.checkThreshold(highAlarm, true, reading, highThreshold,
                                      hysteresis);
    EXPECT_EQ(false, highAlarm);
    lowAlarm = sensor.checkThreshold(lowAlarm, false, reading, lowThreshold,
                                     hysteresis);
    EXPECT_EQ(false, lowAlarm);

    reading = 30;
    highAlarm = sensor.checkThreshold(highAlarm, true, reading, highThreshold,
                                      hysteresis);
    EXPECT_EQ(false, highAlarm);
    lowAlarm = sensor.checkThreshold(lowAlarm, false, reading, lowThreshold,
                                     hysteresis);
    EXPECT_EQ(true, lowAlarm);

    reading = 25;
    highAlarm = sensor.checkThreshold(highAlarm, true, reading, highThreshold,
                                      hysteresis);
    EXPECT_EQ(false, highAlarm);
    lowAlarm = sensor.checkThreshold(lowAlarm, false, reading, lowThreshold,
                                     hysteresis);
    EXPECT_EQ(true, lowAlarm);

    reading = 32;
    highAlarm = sensor.checkThreshold(highAlarm, true, reading, highThreshold,
                                      hysteresis);
    EXPECT_EQ(false, highAlarm);
    lowAlarm = sensor.checkThreshold(lowAlarm, false, reading, lowThreshold,
                                     hysteresis);
    EXPECT_EQ(true, lowAlarm);

    reading = 35;
    highAlarm = sensor.checkThreshold(highAlarm, true, reading, highThreshold,
                                      hysteresis);
    EXPECT_EQ(false, highAlarm);
    lowAlarm = sensor.checkThreshold(lowAlarm, false, reading, lowThreshold,
                                     hysteresis);
    EXPECT_EQ(false, lowAlarm);
}
