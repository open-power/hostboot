/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ipmi/ipmisensor.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
/**
 *  @file ipmisensor.H
 *
 *  @brief Interface for the Sensor class
 *
 *  This header file contains the interfaces for the sensor class which
 *  is used to handle setting the virtual sensors maintained by the BMC.
 */

#include <attributeenums.H>
#include <targeting/common/target.H>
#include <errl/errlentry.H>
#include <targeting/common/targetservice.H>
#include <ipmi/ipmiif.H>

#ifndef __IPMI_IPMISENSOR_H
#define __IPMI_IPMISENSOR_H

namespace SENSOR
{
    //**  Bit definition for set sensor reading cmd operation field
    //      [7:6] 10b - write given values to event data bytes let BMC handle
    //                  offset in event data 1 when an external event is
    //                  triggered based on the new data.
    //      [5:4] 10b - a one causes a one in the corresponding position of
    //                  the event assertion bits, zeros are ignored.
    //      [3:2] 10b - a one causes a one in the  corresponding position of
    //                  the event deassertion bits, zeros are ignored.
    //      [0:1] 01b - write the given value to the sensor reading byte.
    //
    //      default operation = 1010 1001
    static const uint8_t DEFAULT_OPERATION = 0xA9;  // see IPMI Spec. "Set
    // Sensor Reading and Event
    // Status command" for
    // details on this byte.

    // sensors have the range 0x0-0xFE - 0xFF is reserved for invalid sensor
    static const uint16_t INVALID_SENSOR = 0xFF;

    // Mask which preserves major type of the sensor
    static const uint16_t SENSOR_NAME_MAJOR_MASK = 0xFF00;

    // Mask which preserves minor type of the sensor
    static const uint16_t SENSOR_NAME_MINOR_MASK = 0x00FF;

    /**
     *   @struct set_sensor_reading_request
     *       structure holding the data for the set sensor reading command which
     *       Hostboot will send to the BMC to update sensor status/readings.
     *
     */
    struct setSensorReadingRequest
    {
        uint8_t   iv_sensor_number;
        uint8_t   iv_operation;
        uint8_t   iv_sensor_reading;
        uint16_t  iv_assertion_mask;
        uint16_t  iv_deassertion_mask;
        uint8_t   iv_event_data[3];

        // constructor for our data set
        setSensorReadingRequest()
            :iv_sensor_number(0),iv_operation(DEFAULT_OPERATION),
            iv_sensor_reading(0), iv_assertion_mask(0), iv_deassertion_mask(0)
        {
            memset(iv_event_data,0, sizeof(iv_event_data));
        };
    }PACKED;


    /**
     *  @enum  completionCode
     *  Sensor specific completion codes, defined in IPMI Spec.
     *
     */
    enum completionCode
    {
        CC_SENSOR_READING_NOT_SETTABLE    = 0x80,
        CC_EVENT_DATA_BYTES_NOT_SETTABLE  = 0x81
    };

    /**
     *  @enum procStatusSensorOffsets
     *  Sensor specific completion codes, defined in IPMI Spec.
     *
     */
    enum procStatusSensorOfffsets
    {
        PROC_PRESENT            = 0x07,
        PROC_FUNCTIONAL_OFFSET  = 0x08,
    };

    /**
     *  @enum dimmStatusSensorOffsets
     *  Dimm specific offsets for status sensor, defined in IPMI Spec.
     *
     */
    enum dimmStatusSensorOffsets
    {
        DIMM_PRESENT_OFFSET     = 0x06,
        DIMM_FUNCTIONAL_OFFSET  = 0x04,
    };

    /**
     *  @class SensorBase
     *
     *  @brief Base class for sensors
     *
     *  @par Detailed Description:
     *      Provides the base functionality to set IPMI sensor from Hostboot
     *      including finding the sensor number given a specific target type.
     *      The constructor takes a SENSOR_NAME and a target pointer. If a null
     *      is passed in as the target pointer, the system target will be used
     *      to search for the requested sensor name.
     */
    class SensorBase
    {

        public:
            /**
             *  @brief Generic base class constructor for sensor objects
             *
             *  @brief Base class for sensor derivation - takes a sensor name,
             *  and a target* as input.
             *
             *  @par Detailed Description:
             */
            SensorBase(TARGETING::SENSOR_NAME i_name,
                    TARGETING::Target * i_target);

            /**
             *  @brief Destructor for the base sensor object
             *
             *  Destroys the sensor object and any owned resources, does not
             *  alter the state on the BMC
             *
             *  @post Sensor object is destroyed, and all resources are
             *        reclaimed
             */
            virtual  ~SensorBase();

            // low level communication to update sensor readings on the BMC

            /**
             * @brief write sensor data
             *    Low level interface to send the set sensor and event data
             *    reading command to the BMC through the BT interface.
             *
             * @return Errorlog handle
             *
             */
            virtual errlHndl_t  writeSensorData();

            /**
             * @brief read sensor data
             *    Low level interface to send get sensor and event data reading
             *    command to the BMC through the BT interface.
             *
             * @param[out] o_data - buffer containing the response data from the
             *                      BMC,
             *  NOTE: caller is responsible for deleting the memory pointed to
             *        by o_data.
             *
             * @return Errorlog handle
             *
             */
            virtual errlHndl_t readSensorData(uint8_t *& o_data);


            /**
             * @brief process completion codes
             *    Converts completion code values returned from the IPMI
             *    transport layer into an error log.
             *
             * @param[in] i_cc - completion code returned from the IPMI
             *                   transport layer.
             *
             * @return Errorlog handle
             *
             */
            errlHndl_t processCompletionCode(IPMI::completion_code i_cc);

            /**
             * @brief Send set sensor reading and event status command
             *    Helper function to send the sensor reading to the BMC, this
             *    command executes synchronously.
             *
             * @param[inout] io_data - Initially contains the command and data
             *                         to send to the BMC, will hold the BMC
             *                         response when the command returns.
             *
             * @param[out] o_completion_code - Return value defined by the IPMI
             *                                 spec and returned in the message
             *                                 from the BMC to indicate if the
             *                                 command processing completed
             *                                 successfully.
             *
             * @return Errorlog handle
             *
             */
            errlHndl_t sendSetSensorReading(
                    setSensorReadingRequest *& io_data,
                    IPMI::completion_code& o_completion_code );

        protected:

            /**
             * @brief setup mask for event assertion/deassertion
             *
             * Translate the passed in offset into a mask for use in
             * as an assertion or deassertion mask.
             *
             * @param[in] = i_offset - offset for event do be signaled
             *
             * @return  eventMask - event status mask with correctly set bit
             *                      matching the offset passed in.
             *
             */
            static uint16_t setMask( uint8_t i_offset );

            /**
             * @brief return the event offset from an assertion/deassertion mask
             *
             * Translate the assertion/deassertion mask into the correct event
             * offset.
             *
             * @param[in] = i_mask - offset for event do be signaled
             *
             * @return offset - offset of the bit which is set in the passed in
             *                  mask.
             *
             */
            static uint8_t getOffset( uint16_t i_mask );

            // Name of this sensor, name is used to find the sensor number in
            // the IPMI_SENSORS attribute.
            TARGETING::SENSOR_NAME iv_name;

            // Target associated with this sensor.
            TARGETING::Target * iv_target;

            // data structure for the send sensor reading command.
            setSensorReadingRequest * iv_msg;

        private:
            //disable default constructor, copy constructor and the assignment
            // operator.
            SensorBase();

            SensorBase& operator=(const SensorBase& i_right);

            SensorBase(const SensorBase& thing );

            // helper function to get sensor number attribute
            // of passed in target
            uint16_t  getSensorNumber();

    };

    /**
     *  @class FirmwareProgressSensor
     *
     *  @brief Specialized sensor class for the firmware progress sensor
     *
     *  @par Detailed Description:
     *      Provides the functionality needed to set the firmware progress
     *      virtual sensor maintained by the BMC.
     */
    class FirmwareProgressSensor : public SensorBase
    {

        public:

            /**
             * @enum firmwareProgressPhase
             *
             * Current firmware progress phase
             *
             */
            enum firmwareProgressPhase
            {
                MEMORY_INIT         = 0x01, //< isteps 10->14
                SEC_PROCESSOR_INIT  = 0x03, //< isteps 15->16
                STARTING_OS         = 0x13, //< isteps 17->21
                BASE_INITIALIZATION = 0x14, //< isteps  6-> 9
                PHASE_NA            = 0xFF, // Not applicable

            };

            /**
             *  @brief Constructor for the FirmwareProgressSensor
             *
             *  The firmware progress sensor is used to update the BMC
             *  with the current firmware phase.
             *  The system target holds the IPMI sensor number for this sensor.
             *
             */
            FirmwareProgressSensor();

            /**
             *  @brief destructor for the FirmwareProgressSensor
             *
             *  The firmware progress sensor is used to update the BMC
             */
            ~FirmwareProgressSensor();

            /**
             *
             * @brief Set the current firmware boot progress phase
             *    Interface used to update the event status for the system
             *    firmware progress sensor.  phases are defined by the enum
             *    firmware_progress_phase. Further information can be found in
             *    the IPMI specification.
             *
             * @param[in] i_phase - current firmware progress phase.
             *
             * @return Errorlog handle
             *
             */
            errlHndl_t setBootProgressPhase(firmwareProgressPhase i_phase);

        private:
            // @enum firmwareProgressOfsets
            //
            // sensor specific offset used to specify that the event which is
            // being signaled is for the system firmware progress sensor.
            enum firmwareProgressOffsets
            {
                SYSTEM_FIRMWARE_PROGRESS    = 0x02  //< Sensor specific offset
                                                    //< for system firmware
                                                    //< progress event.
            };

    };

    /**
     *  @class HostStatusSensor
     *
     *  @brief Specialized class for the host status sensor.
     *
     *  @par Detailed Description:
     *      Provides the functionality needed to set the Host_Status sensor also
     *      known as the ACPI power state. The Host_status sensor is a virtual
     *      sensor maintained by the BMC,
     */
    class HostStatusSensor : public SensorBase
    {
        public:

            /**
             * @enum hostStatus
             *      enum to define the ACPI power state of the system, this
             *      sensor will be updated by Hostboot and opal.
             */
            enum hostStatus
            {
                S0_G0_WORKING   = 0x00,  //< Host up
                S5_G2_SOFT_OFF  = 0x05,  //< Soft power off
                LEGACY_ON_STATE = 0x0B   //< Host not up, but started
            };

            /**
             *  @brief Constructor for the HostStatusSensor
             *
             *  The firmware progress sensor is used to update the BMC
             *  with the current ACIP power state of the system.
             *  The system target holds the IPMI sensor number for this sensor.
             *
             */
            HostStatusSensor();

            /**
             *  @brief Destructor for the HostStatusSensor
             *
             */
            ~HostStatusSensor();

            /**
             *
             * @brief Set the current HostStatus
             *    Interface used to update the event status for the ACPI
             *    power state of the system. States are defined by the enum
             *    host_status.  Further information can be found in the IPMI
             *    specification.
             *
             *
             * @param[in] i_phase - current firmware progress phase.
             *
             * @return Errorlog handle
             *
             */
            errlHndl_t updateHostStatus( hostStatus status );

    };

    /**
     *  @class RebootCountSensor
     *
     *  @brief Specialized class for the system reboot count.
     *
     *  @par Detailed Description:
     *      Provides the functionality needed to set the reboot count. The
     *      reboot count is a special sensor maintained by the BMC.
     *
     *   Usage:
     *     reboot_count_t count = 3;
     *      RebootCountSensor l_sensor;
     *      l_sensor.setRebootCount( count );
     *
     */
    class RebootCountSensor : public SensorBase
    {

        //< reboot count type
        typedef uint8_t rebootCount_t;

        public:

            /**
             *  @brief Constructor for the RebootCountSensor
             *
             *  The reboot count sensor is used to update the reboot count
             *  sensor maintained by the BMC.
             *
             *  The system target holds the IPMI sensor number for this sensor.
             *
             */
            RebootCountSensor();

            /**
             *  @brief Destructor for the RebootCountSensor
             *
             */
            ~RebootCountSensor();

            /**
             * @brief Sent a value for the reboot count to the BMC.
             *
             * @param[in] i_count - new reboot count value.
             *
             * @return Errorlog handle
             *
             */
            errlHndl_t setRebootCount( rebootCount_t i_count );

    };

    /**
     *  @class StatusSensor
     *
     *  @brief Specialized class to handle DIMM, PROC and Core status.
     *
     *  @par Detailed Description:
     *      Provides the functionality needed to set the status of DIMMS, Cores,
     *      and processors.  The object will determine from the Target* what
     *      sensor offsets should be used, and configure itself accordingly.
     */

    class StatusSensor : public SensorBase
    {

        public:

            /**
             * @enum statusEnum
             *
             *  enum defining the status of targets which use the
             *  status sensor to report functional and present states.
             */
            enum statusEnum
            {
                NOT_PRESENT             = 0x0000,
                PRESENT                 = 0x0001,
                FUNCTIONAL              = 0x0002,
                PRESENT_FUNCTIONAL      = 0x0003,
                NON_FUNCTIONAL          = 0x0004,
                PRESENT_NONFUNCTIONAL   = 0x0005,
            };

            /**
             *  @brief Constructor for a status sensor
             *
             *  The status sensor is used for DIMMS, Cores and Procs. Hostboot
             *  will update the present and functional state for the status
             *  sensor associated with each instance of these target types.
             *
             *
             *  The IPMI sensor number for these sensors are associated with
             *  each instance of the DIMM, CORE and Processor targets.
             *
             */
            StatusSensor( TARGETING::Target * );

            /**
             *  @brief Destructor for the StatusSensor
             *
             */
            ~StatusSensor();

            errlHndl_t setStatus( statusEnum status );

        private:
            // disable the default constructor
            StatusSensor();

            // internal offset data which is configured based on target type
            // used in construction.
            uint8_t iv_presentOffset;
            uint8_t iv_functionalOffset;

    };

    /**
     *  @class FaultSensor
     *
     *  @brief Specialized class implementing a simple fault sensor
     *
     *  @par Detailed Description:
     *      Provides the functionality needed to assert or deassert a fault
     *      condition for a given target.  These are typically used for
     *      things that have failed which may not have a full targeting
     *      implementation.  Implemented using a 0x03 'digital' discrete
     *      generic sensor profile.
     */
    class FaultSensor : public SensorBase
    {
        public:

            /**
             *  @enum FAULT_SENSOR_OFFSET
             *
             *  Indicates the correct sensor offset to use for sensor fault
             *  assertions/deassertions.
             */
            enum FAULT_SENSOR_OFFSET
            {
                FAULT_DEASSERTED_OFFSET = 0x00,
                FAULT_ASSERTED_OFFSET   = 0x01,
            };

            /**
             *  @enum FAULT_STATE
             *
             *  Enum indicating whether the fault sensor is asserted or not
             */
            enum FAULT_STATE
            {
                FAULT_STATE_DEASSERTED = 0x00,
                FAULT_STATE_ASSERTED   = 0x01,
            };

            /**
             *  @brief Constructor for a fault sensor
             *
             *  @param[in] i_pTarget
             *      Target associated with the fault sensor.  Must not be NULL.
             */
            FaultSensor(TARGETING::Target* i_pTarget);

            /**
             *  @brief Constructor for a fault sensor, used to differentiate
             *      multiple sensors of similar type on same target
             *
             *  @param[in] i_pTarget
             *      Target associated with the fault sensor.  Must not be NULL.
             *
             *  @param[in] i_associatedType
             *      Type of non-instantiated target linked to the main target
             *      for which this sensor provides readings.
             */
            FaultSensor(TARGETING::Target* i_pTarget,
                TARGETING::TYPE i_associatedType = TARGETING::TYPE_NA);

            /**
             *  @brief Destructor for a fault sensor
             *
             */
            ~FaultSensor();

            /**
             *  @brief Set the fault sensor to faulted or non-faulted
             *
             *  @param[in] i_faultState
             *      Whether sensor is faulted or not
             *
             *  @return Error log handle
             *  @retval NULL  Status set successfully
             *  @retval !NULL Failed to set status
             */
            errlHndl_t setStatus(FAULT_STATE i_faultState);

        private:

            // Disable the default constructor
            FaultSensor();

            // Disable assignment operator
            FaultSensor& operator=(const FaultSensor& i_rhs);

            // Disable copy constructor
            FaultSensor(const FaultSensor& i_rhs);
    };

    /**
     *  @brief Updates initial state of Hostboot relevant fault sensors on the
     *      BMC
     *
     *  @par Detailed Description:
     *      Updates initial state of Hostboot relevant fault sensors on the
     *      BMC to "not faulted" for all applicable fault sensors detected in
     *      the system.  All errors will be internally committed.
     */
    void updateBMCFaultSensorStatus(void);

    /**
     *   @brief Update DIMM/CORE/Processor status sensors on the BMC.
     *   Update the present/functional status on the BMC for status sensors
     *   monitored by Hostboot.  The sensor will be updated based on the
     *   HWAS state of the target. Currently handles DIMM/CORE/PROC present
     *   and functional status.
     *
     */
    void updateBMCSensorStatus(void);


    /**
     *   Helper function to update the status sensor for a specific target
     *   type.  Currently supports DIMM, CORE and Processor target types.
     *
     *  @param[in] - i_type, target type to set the status for
     *
     */
    void updateBMCSensorStatus( TARGETING::TYPE i_type );


}; // end namespace

#endif
