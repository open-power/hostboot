/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmiext/ipmisensor.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
/* [+] Google Inc.                                                        */
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
 * @file ipmisensor.C
 * @brief IPMI sensor manipulation
 */

#include <ipmi/ipmisensor.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/target.H>
#include <attributetraits.H>
#include <targeting/common/utilFilter.H>
#include <ipmi/ipmi_reasoncodes.H>
#include <endian.h>
#include <vpd/pvpdenums.H>
#include <devicefw/userif.H>
#include <hdat/hdat.H>


extern trace_desc_t * g_trac_ipmi;

namespace SENSOR
{

    //
    // Base class for sensor construction.  It is expected that this object will
    // be used as the base for any additional sensors defined.
    //
    SensorBase::SensorBase( TARGETING::SENSOR_NAME i_name,
                             const TARGETING::Target * i_target)
        :iv_name(i_name) ,iv_target(i_target)
    {
        // allocate a new message structure to use with our sensors
        // this will be the payload for the IPMI send/sendrecv sensor message.
        iv_msg = new setSensorReadingRequest;
    };

    SensorBase::~SensorBase()
    {
        // The memory allocated for the set sensor reading command is deleted
        // by the IPMI transport layer.  Since we are sending messages
        // asynchronously, the IPMI resource provider deletes the message
        // and there is nothing to delete here.
    };

    //
    // Helper function to process completion codes returned from the BMC.
    // If the completion code warrants a PEL the function will build and
    // return an error log with the correct data captured.
    //
    errlHndl_t SensorBase::processCompletionCode( IPMI::completion_code i_rc )
    {
        errlHndl_t l_err = NULL;

        IPMI::IPMIReasonCode l_reasonCode;

        if( i_rc != IPMI::CC_OK )
        {
            // bad rc from the BMC
            TRACFCOMP(g_trac_ipmi,"completion code 0x%x returned from the BMC"
                      " , creating error log", i_rc);

            switch(i_rc)
            {
                case  SENSOR::CC_SENSOR_READING_NOT_SETTABLE:
                {
                   /*@
                    * @errortype       ERRL_SEV_UNRECOVERABLE
                    * @moduleid        IPMI::MOD_IPMISENSOR
                    * @reasoncode      IPMI::RC_SENSOR_NOT_SETTABLE
                    * @userdata1       BMC IPMI Completion code.
                    * @userdata2       bytes [0-1]sensor name
                    *                  bytes [2-3]sensor number
                    *                  bytes [4-7]HUID of target.
                    * @devdesc         Set sensor reading command failed.
                    */
                    l_reasonCode = IPMI::RC_SENSOR_NOT_SETTABLE;
                    TRACFCOMP(g_trac_ipmi,"Attempt to change sensor reading or"
                              "set/clear status bits that are not settable"
                              " via this command");
                    break;
                }

                case  SENSOR::CC_EVENT_DATA_BYTES_NOT_SETTABLE:
                {
                   /*@
                    * @errortype       ERRL_SEV_UNRECOVERABLE
                    * @moduleid        IPMI::MOD_IPMISENSOR
                    * @reasoncode      IPMI::RC_EVENT_DATA_NOT_SETTABLE
                    * @userdata1       BMC IPMI Completion code.
                    * @userdata2       bytes[0-3]sensor number
                    *                  bytes[4-7]HUID of target.
                    * @devdesc         Set sensor reading command failed.
                    */
                    l_reasonCode = IPMI::RC_EVENT_DATA_NOT_SETTABLE;
                    TRACFCOMP(g_trac_ipmi,"Attempted to set event data bytes "
                            "but setting event data bytes is not supported for"
                            " this sensor");
                    break;
                }

                case IPMI::CC_CMDSENSOR:
                {
                   /*@
                    * @errortype       ERRL_SEV_UNRECOVERABLE
                    * @moduleid        IPMI::MOD_IPMISENSOR
                    * @reasoncode      IPMI::RC_INVALID_SENSOR_CMD
                    * @userdata1       BMC IPMI Completion code.
                    * @userdata2       bytes [0-1]sensor name
                    *                  bytes [2-3]sensor number
                    *                  bytes [4-7]HUID of target.
                    * @devdesc         Command not valid for this sensor.
                    */
                    l_reasonCode = IPMI::RC_INVALID_SENSOR_CMD;
                    TRACFCOMP(g_trac_ipmi,"Command not valid for this sensor");
                    break;
                }

                case IPMI::CC_BADSENSOR:
                {
                   /*@
                    * @errortype       ERRL_SEV_UNRECOVERABLE
                    * @moduleid        IPMI::MOD_IPMISENSOR
                    * @reasoncode      IPMI::RC_SENSOR_NOT_PRESENT
                    * @userdata1       BMC IPMI Completion code.
                    * @userdata2       bytes [0-1]sensor name
                    *                  bytes [2-3]sensor number
                    *                  bytes [4-7]HUID of target.
                    * @devdesc         Requested sensor is not present.
                    */
                    l_reasonCode = IPMI::RC_SENSOR_NOT_PRESENT;
                    TRACFCOMP(g_trac_ipmi,"Requested sensor not present");
                    break;
                }

                default:
                {
                    // lump everything else into a general failure for
                    // now.
                   /*@
                    * @errortype       ERRL_SEV_UNRECOVERABLE
                    * @moduleid        IPMI::MOD_IPMISENSOR
                    * @reasoncode      IPMI::RC_SET_SENSOR_FAILURE
                    * @userdata1       BMC IPMI Completion code.
                    * @userdata2       bytes [0-1]sensor name
                    *                  bytes [2-3]sensor number
                    *                  bytes [4-7]HUID of target.
                    * @devdesc         Set sensor reading command failed.
                    */
                    TRACFCOMP(g_trac_ipmi,"Set sensor reading command failed");
                    l_reasonCode = IPMI::RC_SET_SENSOR_FAILURE;
                    break;
                }
            }

                // shift the sensor number into to bytes 0-3 and then
                // or in the HUID to bytes 4-7
                uint32_t sensor_number = getSensorNumber();
                uint32_t huid = TARGETING::get_huid( iv_target );

                TRACFCOMP(g_trac_ipmi,"Sensor Number: 0x%X, HUID: 0x%X", sensor_number, huid );

                l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                IPMI::MOD_IPMISENSOR,
                                l_reasonCode,
                                i_rc,
                                TWO_UINT32_TO_UINT64(
                                       TWO_UINT16_TO_UINT32(iv_name,
                                                            sensor_number),
                                       huid ),
                                true);

                l_err->collectTrace(IPMI_COMP_NAME);

        }
        return l_err;
    }

    //
    // Helper function to send the data to the BMC using the correct interface
    // protocol
    //
    errlHndl_t SensorBase::writeSensorData()
    {

        errlHndl_t l_err = NULL;

#if 0 // TODO RTC: 246392 Remove this code when PLDM is up
        iv_msg->iv_sensor_number = static_cast<uint8_t>(getSensorNumber());

        if( iv_msg->iv_sensor_number != TARGETING::UTIL::INVALID_IPMI_SENSOR )
        {

            // iv_msg is deleted by the IPMI resource provider.
            l_err = sendSetSensorReading( iv_msg);

            if( l_err )
            {
                TRACFCOMP(g_trac_ipmi,"error returned from "
                        "sendSetSensorReading() for sensor number 0x%x",
                        getSensorNumber());
            }
        }
        else
        {
            TRACFCOMP(g_trac_ipmi,"We were not able to find a sensor number in"
                      " the IPMI_SENSORS attribute for sensor_name=0x%x "
                      "for target with huid=0x%x, skipping call to "
                      "sendSetSensorReading()",
                    iv_name, TARGETING::get_huid( iv_target ));

            /*@
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        IPMI::MOD_IPMISENSOR
             * @reasoncode      IPMI::RC_SENSOR_NOT_FOUND
             * @userdata1       Returned sensor number.
             * @userdata2       bytes [0-3]sensor name
             *                  bytes [4-7]HUID of target.
             * @devdesc         Requested sensor attribute not found.
             */
            l_err = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                IPMI::MOD_IPMISENSOR,
                IPMI::RC_SENSOR_NOT_FOUND,
                iv_msg->iv_sensor_number,
                TWO_UINT32_TO_UINT64( iv_name,
                                      TARGETING::get_huid( iv_target ) ),
                true);

            delete iv_msg;
        }
#endif

        return l_err;
    };

    //
    // Helper function to set the bit in the assertion/deassertion mask
    // associated with the desired sensor specific offset
    //
    uint16_t SensorBase::setMask( const uint8_t offset, bool swap )
    {
        const uint16_t mask = (0x0001 << offset);

        if(swap)
        {
            // need to byte swap the mask (see set sensor reading in spec)
            return le16toh(mask);
        }
        else
        {
            return mask;
        }

    };

    //
    // Helper function to translate the assertion/deassertion mask into
    // the correct event offset.
    //
    uint8_t SensorBase::getOffset( uint16_t mask )
    {
        // $TODO RTC:117872
        return 0;
    };

    // read data from the sensor.
    errlHndl_t SensorBase::readSensorData( getSensorReadingData& o_data)
    {

        // get sensor reading command only requires one byte of extra data,
        // which will be the sensor number, the command will return between
        // 3 and 5 bytes of data.
        size_t len =  1;

        // need to allocate some memory to hold the sensor number this will be
        // deleted by the IPMI transport layer
        uint8_t * l_data = new uint8_t[len];

        l_data[0] = static_cast<uint8_t>(getSensorNumber());

        IPMI::completion_code cc = IPMI::CC_UNKBAD;

        // o_data will hold the response when this returns
        errlHndl_t l_err = sendrecv(IPMI::get_sensor_reading(), cc, len,
                                  l_data);

        // if we didn't get an error back from the BT interface, but see a
        // bad completion code from the BMC, process the CC to see if we
        // need to create a PEL - if an error occurs sendrcv will clean up
        // l_data for us
        if(  l_err == NULL )
        {
            l_err = processCompletionCode( cc );

            if( l_err == NULL )
            {
                // populate the output structure with the sensor data
                o_data.completion_code = cc;

                o_data.sensor_status = l_data[0];

                o_data.sensor_reading = l_data[1];

                // bytes 3-5 of the reading are optional and will be dependent
                // on the value of the sensor status byte.
                if( !( o_data.sensor_status &
                     ( SENSOR::SENSOR_DISABLED |
                       SENSOR::SENSOR_SCANNING_DISABLED )) ||
                     ( o_data.sensor_status & SENSOR::READING_UNAVAILABLE ))
                {
                    // sensor reading is available
                    o_data.event_status =
                                (( (uint16_t) l_data[3]) << 8  | l_data[2] );

                    // spec indicates that the high order bit should be
                    // ignored on a read, so lets mask it off now.
                    o_data.event_status &= 0x7FFF;
                }
                else
                {
                    uint32_t l_sensorNumber = getSensorNumber();

                    TRACFCOMP(g_trac_ipmi,"Sensor reading not available: status = 0x%x",o_data.sensor_status);
                    TRACFCOMP(g_trac_ipmi,"sensor number 0x%x, huid 0x%x",l_sensorNumber ,get_huid(iv_target));

                    // something happened log an error to indicate the request
                    // failed
                    /*@
                     * @errortype           ERRL_SEV_UNRECOVERABLE
                     * @moduleid            IPMI::MOD_IPMISENSOR
                     * @reasoncode          IPMI::RC_SENSOR_READING_NOT_AVAIL
                     * @userdata1           sensor status indicating reason for
                     *                      reading not available
                     * @userdata2[0:31]     sensor number
                     * @userdata2[32:64]    HUID of target
                     *
                     * @devdesc             Set sensor reading command failed.
                     * @custdesc            Request to get sensor reading
                     *                      IPMI completion code can be seen
                     *                      in userdata1 field of the log.
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            IPMI::MOD_IPMISENSOR,
                            IPMI::RC_SENSOR_READING_NOT_AVAIL,
                            o_data.sensor_status,
                            TWO_UINT32_TO_UINT64( l_sensorNumber,
                                TARGETING::get_huid(iv_target)), true);

                    l_err->collectTrace(IPMI_COMP_NAME);

                }

            }

            delete[] l_data;
        }
        return l_err;
    };

    //
    //  Asynchronously send a set sensor reading command to the BMC.
    //
    errlHndl_t SensorBase::sendSetSensorReading(
                            setSensorReadingRequest * i_data)
    {

        size_t l_len = sizeof( setSensorReadingRequest );

        // i_data will hold the response when this returns
        errlHndl_t l_err = send(IPMI::set_sensor_reading(),
                            l_len, (uint8_t *)i_data);

        return l_err;
    }

    // return the sensor type and event reading data
    errlHndl_t SensorBase::getSensorType(uint32_t i_sensorNumber,
                                         uint8_t &o_sensorType,
                                         uint8_t &o_eventReadingType )
    {

        size_t len =  1;

        o_sensorType = INVALID_TYPE;
        o_eventReadingType = INVALID_TYPE;

        // need to allocate some memory to hold the sensor number this will be
        // deleted by the IPMI transport layer
        uint8_t *l_data = new uint8_t[len];

        l_data[0] = i_sensorNumber;

        IPMI::completion_code cc = IPMI::CC_UNKBAD;

        // l_data will hold the response when this returns
        errlHndl_t l_err = sendrecv(IPMI::get_sensor_type(), cc, len,
                                  l_data);

        // if we didn't get an error back from the BT interface,
        // process the CC to see if we need to create a PEL
        if( l_err == NULL )
        {
            // check the completion code
            if( cc!= IPMI::CC_OK )
            {
                TRACFCOMP(g_trac_ipmi,"bad completion code from BMC=0x%x",cc);

                /*@
                 * @errortype       ERRL_SEV_INFORMATIONAL
                 * @moduleid        IPMI::MOD_IPMISENSOR
                 * @reasoncode      IPMI::RC_GET_SENSOR_TYPE_CMD_FAILED
                 * @userdata1       BMC IPMI Completion code.
                 * @devdesc         Request to get sensor type form the bmc
                 *                  failed.
                 */
                l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            IPMI::MOD_IPMISENSOR,
                            IPMI::RC_GET_SENSOR_TYPE_CMD_FAILED,
                            static_cast<uint64_t>(cc),0, true);

                l_err->collectTrace(IPMI_COMP_NAME);


            }
            else
            {
                    // grab the type and reading code to pass back to the caller
                    o_sensorType = l_data[0];

                    // high order bit is reserved
                    o_eventReadingType = ( 0x7f & l_data[1]);

            }
            delete[] l_data;
        }
        return l_err;
    };


    /**
     *  @brief Returns major type of input sensor name
     *
     *  @param[in] i_sensorName
     *      Name of the sensor
     *
     *  @return Major type of input sensor name
     */
    static inline uint16_t getMajorType(
        const uint16_t i_sensorName)
    {
        return (i_sensorName & SENSOR_NAME_MAJOR_MASK);
    }

    /**
     *  @brief Returns minor type of input sensor name
     *
     *  @param[in] i_sensorName
     *      Name of the sensor
     *
     *  @return Minor type of input sensor name
     */
    static inline uint16_t getMinorType(
        const uint16_t i_sensorName)
    {
        return (i_sensorName & SENSOR_NAME_MINOR_MASK);
    }

    /**
     *  @brief Returns whether the supplied sensor record's major type is less
     *      than the major type of the supplied sensor name
     *
     *  @param[in] i_sensorRecord
     *      Sensor record to compare
     *
     *  @param[in] i_sensorName
     *      Name of the sensor to compare
     *
     *  @retval true  Major type of sensor record is less than major type of
     *      sensor name
     *  @retval false Major type of sensor record is not less than major type of
     *      sensor name
     */
    static inline bool compare_major(
        const uint16_t (&i_sensorRecord)[2],
        const uint16_t i_sensorName)
    {
        return getMajorType(i_sensorRecord[0]) < getMajorType(i_sensorName);
    }

    /**
     *  @brief Returns whether the supplied sensor record's major type equals
     *      the major type of the supplied sensor name
     *
     *  @param[in] i_sensorRecord
     *      Sensor record to compare
     *
     *  @param[in] i_sensorName
     *      Name of the sensor to compare
     *
     *  @retval true  Major type of sensor record equals major type of
     *      sensor name
     *  @retval false Major type of sensor record does not equal major type of
     *      sensor name
     */
    static inline bool equals_major(
        const uint16_t (&i_sensorRecord)[2],
        const uint16_t i_sensorName)
    {
        return getMajorType(i_sensorRecord[0]) == getMajorType(i_sensorName);
    }

    ///
    // FirmwareProgressSensor constructor - uses system target
    //
    FirmwareProgressSensor::FirmwareProgressSensor( )
        :SensorBase(TARGETING::SENSOR_NAME_FW_BOOT_PROGRESS, NULL)
    {
        // message buffer created and initialized in base object.

        // assert the system firmware progress offset.
        iv_msg->iv_assertion_mask = setMask( SYSTEM_FIRMWARE_PROGRESS );
    };

    //
    // FirmwareProgressSensor destructor
    //
    FirmwareProgressSensor::~FirmwareProgressSensor( )
    {

    };

    //
    // setBootProgressPhase - update the boot progress sensor of the BMC
    //
    errlHndl_t FirmwareProgressSensor::setBootProgressPhase(
            INITSERVICE::firmwareProgressPhase phase )
    {
        // event data 2 holds the progress info
        iv_msg->iv_event_data[1] = phase;

        return writeSensorData();
    };

    //
    // RebootCountSensor constructor - uses system target
    //
    RebootCountSensor::RebootCountSensor()
        :SensorBase(TARGETING::SENSOR_NAME_REBOOT_COUNT, NULL)
    {
        // message buffer created and initialized in base object.

    }

    //
    // RebootCountSensor destructor
    //
    RebootCountSensor::~RebootCountSensor(){};

    //
    // setRebootCount - send a new value for the reboot count to the BMC.
    //
    errlHndl_t RebootCountSensor::setRebootCount( uint16_t i_count )
    {
        // adjust the operation to overwrite the sensor reading
        // to the value we send.
        iv_msg->iv_operation = SET_SENSOR_VALUE_OPERATION;

        // the Reboot_count sensor is defined as a discrete sensor
        // but the assertion bytes are being used to transfer the count
        // to the bmc, will need to byte swap the data
        iv_msg->iv_assertion_mask = le16toh(i_count);

        return writeSensorData();

    }

    //
    // getRebootCount - get the reboot count from the BMC
    //
    errlHndl_t RebootCountSensor::getRebootCount( uint16_t &o_rebootCount )
    {

        // the Reboot_count sensor is defined as a discrete sensor
        // but the assertion bytes are being used to transfer the count
        // from the BMC
        getSensorReadingData l_data;

        errlHndl_t l_err = readSensorData( l_data );

        if( l_err == NULL )
        {
            // this value is already byteswapped
            o_rebootCount = l_data.event_status;
        }
        return l_err;

    }

    //
    // RebootControlSensor constructor - uses system target
    //
    RebootControlSensor::RebootControlSensor()
        :SensorBase(TARGETING::SENSOR_NAME_HOST_AUTO_REBOOT_CONTROL, NULL)
    {
        // message buffer created and initialized in base object.

    }

    //
    // RebootCountSensor destructor
    //
    RebootControlSensor::~RebootControlSensor(){};

    //
    // setRebootControl - turn reboots on or off to the BMC
    //
    errlHndl_t RebootControlSensor::setRebootControl(
                                                autoRebootSetting i_setting )
    {
        // adjust the operation to overwrite the sensor reading
        // to the value we send.
        iv_msg->iv_operation = SET_SENSOR_VALUE_OPERATION;

        // the Reboot Control Sensor is defined as a discrete sensor
        // but the assertion bytes are being used to transfer the state
        iv_msg->iv_assertion_mask = le16toh(i_setting);

        TRACFCOMP(g_trac_ipmi,"RebootControlSensor::setRebootControl(%d)",
                    i_setting);

        return writeSensorData();
    }

    //
    // getRebootCount - get the reboot setting from the BMC
    //
    errlHndl_t RebootControlSensor::getRebootControl(
                                                autoRebootSetting &o_setting )
    {
        // the Reboot control sensor is defined as a discrete sensor
        // DISABLE_REBOOT - keep current state (no reboot)
        // ENABLE_REBOOT  - Allow analysis of FIRDATA on XSTOP
        getSensorReadingData l_data;

        errlHndl_t l_err = readSensorData( l_data );

        if( l_err == NULL )
        {
            // Check that this value is a valid enum value
            if ( l_data.event_status == ENABLE_REBOOTS ||
                 l_data.event_status == DISABLE_REBOOTS )
            {
                o_setting = static_cast<autoRebootSetting>(l_data.event_status);
            }
            else
            {
                TRACFCOMP(g_trac_ipmi,"Unknown reboot control setting: %d",
                    l_data.event_status);

                /*@
                 * @errortype    ERRL_SEV_UNRECOVERABLE
                 * @moduleid     IPMI::MOD_IPMISENSOR_REBOOTCNTRL
                 * @reasoncode   IPMI::RC_INVALID_SENSOR_SETTING
                 * @userdata1    Invalid reboot control setting
                 * @userdata2    <unused>
                 * @devdesc      The sensor returned an invalid setting
                 * @custdesc     Unable to find a valid sensor setting.
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            IPMI::MOD_IPMISENSOR_REBOOTCNTRL,
                                            IPMI::RC_INVALID_SENSOR_SETTING,
                                            l_data.event_status,
                                            0,
                                            false);
            }
        }
        return l_err;
    }


    //
    // StatusSensor constructor - uses system DIMM/CORE/PROC target
    //
    StatusSensor::StatusSensor( TARGETING::ConstTargetHandle_t i_target )
        :SensorBase(TARGETING::SENSOR_NAME_STATE, i_target)
    {
        iv_functionalOffset  = PROC_DISABLED;
        iv_presentOffset     = PROC_PRESENCE_DETECTED;

        switch ( i_target->getAttr<TARGETING::ATTR_TYPE>() )
        {
            case TARGETING::TYPE_DIMM:
                {
                    iv_functionalOffset  = MEMORY_DEVICE_DISABLED;
                    iv_presentOffset     = MEM_DEVICE_PRESENCE_DETECTED;
                    iv_name = TARGETING::SENSOR_NAME_DIMM_STATE;
                    break;
                }
            case TARGETING::TYPE_MEMBUF:
                {
                    iv_functionalOffset  = MEMORY_DEVICE_DISABLED;
                    iv_presentOffset     = MEM_DEVICE_PRESENCE_DETECTED;
                    iv_name = TARGETING::SENSOR_NAME_MEMBUF_STATE;
                    break;
                }
            case TARGETING::TYPE_PROC:
                iv_name = TARGETING::SENSOR_NAME_PROC_STATE;
                break;

            case TARGETING::TYPE_CORE:
                iv_name = TARGETING::SENSOR_NAME_CORE_STATE;
                break;

            default:
                TRACFCOMP(g_trac_ipmi,"INF>>No status sensor associated with target type 0x%x",
                         i_target->getAttr<TARGETING::ATTR_TYPE>());
                iv_functionalOffset = INVALID_OFFSET;
                iv_presentOffset    = INVALID_OFFSET;
                break;
        }

    };

    //
    // StatusSensor destructor
    //
    //
    StatusSensor::~StatusSensor()
    {};


    // Convert the input status to the correct sensor offset value, then
    // send the message to the BMC to update the event status for this sensor.
    errlHndl_t StatusSensor::setStatus( statusEnum i_state )
    {

        errlHndl_t l_err = NULL;

        if( iv_functionalOffset != INVALID_OFFSET
                && iv_presentOffset != INVALID_OFFSET )
        {
            uint16_t func_mask = setMask( iv_functionalOffset );
            uint16_t pres_mask = setMask( iv_presentOffset );

            switch ( i_state )
            {
                case NOT_PRESENT:
                    // turn off the present bit
                    iv_msg->iv_deassertion_mask = pres_mask;

                    // turn off the disabled bit in case it was on
                    iv_msg->iv_deassertion_mask |= func_mask;
                    break;

                case PRESENT:
                    // turn on the present bit
                    iv_msg->iv_assertion_mask = pres_mask;
                    break;

                case FUNCTIONAL:
                    // turn off the disabled bit
                    iv_msg->iv_deassertion_mask = func_mask;
                    break;

                case PRESENT_FUNCTIONAL:
                    // assert the present bit
                    iv_msg->iv_assertion_mask = pres_mask;
                    // turn off the disabled bit
                    iv_msg->iv_deassertion_mask = func_mask;
                    break;

                case PRESENT_NONFUNCTIONAL:
                    // assert the present bit
                    iv_msg->iv_assertion_mask = pres_mask;
                    // assert the disabled bit
                    iv_msg->iv_assertion_mask |= func_mask;
                    break;

                case NON_FUNCTIONAL:
                    // assert the disabled bit
                    iv_msg->iv_assertion_mask = func_mask;
                    break;

                default:
                    // mark as not present
                    iv_msg->iv_deassertion_mask = pres_mask;
                    iv_msg->iv_assertion_mask = func_mask;
                    break;
            }

            l_err = writeSensorData();
        }
        return l_err;

    };

    //**************************************************************************
    // GpuSensor constructor
    //**************************************************************************
    GpuSensor::GpuSensor(TARGETING::SENSOR_NAME i_name, uint16_t i_num,
                     TARGETING::ConstTargetHandle_t i_target)
             : StatusSensor(i_target)

    {
        /* Note: StatusSensor sets these for processor target */
        //iv_functionalOffset  = PROC_DISABLED;
        //iv_presentOffset     = PROC_PRESENCE_DETECTED;

        // Override iv_name set by parent constructor
        iv_name = i_name;

        // 3 numbers possible (1 per GPU) for each name, so save which one
        iv_sensorNumber = i_num;
    };

    //**************************************************************************
    // GpuSensor destructor
    //**************************************************************************
    GpuSensor::~GpuSensor()
    {
    }

    //**************************************************************************
    // FaultSensor constructor
    //**************************************************************************

    FaultSensor::FaultSensor(
            TARGETING::ConstTargetHandle_t i_pTarget)
        : SensorBase(TARGETING::SENSOR_NAME_FAULT, i_pTarget)
    {
    }

    //**************************************************************************
    // FaultSensor constructor for associated targets
    //**************************************************************************

    FaultSensor::FaultSensor(
            TARGETING::ConstTargetHandle_t i_pTarget,
            const TARGETING::ENTITY_ID i_associatedType)
        : SensorBase(
                static_cast<TARGETING::SENSOR_NAME>(
                    TARGETING::SENSOR_NAME_FAULT | i_associatedType),
                i_pTarget)
    {
    }

    //**************************************************************************
    // FaultSensor destructor
    //**************************************************************************

    FaultSensor::~FaultSensor()
    {
    }

    //**************************************************************************
    // FaultSensor::setStatus
    //**************************************************************************

    errlHndl_t FaultSensor::setStatus(
            const FAULT_STATE i_faultState)
    {
        errlHndl_t pError = NULL;

        switch(i_faultState)
        {
            case FAULT_STATE_ASSERTED:
                iv_msg->iv_assertion_mask = setMask(FAULT_ASSERTED_OFFSET);
                break;
            case FAULT_STATE_DEASSERTED:
                iv_msg->iv_deassertion_mask = setMask(FAULT_ASSERTED_OFFSET);
                break;
            default:
                assert(0,"Caller passed unsupported fault state of 0x%X",
                        i_faultState);
        }

        pError = writeSensorData();
        if(pError)
        {
            TRACFCOMP(g_trac_ipmi, ERR_MRK " "
                    "Failed to write sensor data for sensor name 0x%X",
                    iv_name);
        }

        return pError;
    }

    //
    // HostStausSensor constructor - uses system target
    //
    //
    HostStatusSensor::HostStatusSensor()
        :SensorBase(TARGETING::SENSOR_NAME_HOST_STATUS, NULL)
    {

    };

    //
    // HostStatusSensor destructor
    //
    //
    HostStatusSensor::~HostStatusSensor(){};

    //
    // updateHostStaus - update the BMC HostStatus sensor with the passed in
    //                   value.
    //
    //
    errlHndl_t HostStatusSensor::updateHostStatus( hostStatus status )
    {
        iv_msg->iv_operation = SET_SENSOR_VALUE_OPERATION;
        iv_msg->iv_assertion_mask = setMask((uint8_t)status);

        return writeSensorData();
    };

    //
    // KeyClearRequestSensor constructor - uses system target
    //
    KeyClearRequestSensor::KeyClearRequestSensor()
        :SensorBase(TARGETING::SENSOR_NAME_KEY_CLEAR_REQUEST, nullptr)
    {
        // message buffer created and initialized in base object.

    }

    //
    // KeyClearRequestSensor destructor
    //
    KeyClearRequestSensor::~KeyClearRequestSensor(){};

    //
    // setKeyClearRequest - send a new value for the key clear request sensor
    //                      to the BMC.
    //
    errlHndl_t KeyClearRequestSensor::setKeyClearRequest(const uint8_t i_value)
    {
        // This is a threshold sensor that sets one byte of data in the
        // iv_sensor_reading field
        iv_msg->iv_sensor_reading = i_value;

        return writeSensorData();
    }

    //
    // getKeyClearRequest - Get the value of the key clear request sensor from the BMC
    //
    errlHndl_t KeyClearRequestSensor::getKeyClearRequest( uint8_t &o_value )
    {
        // This is a threshold sensor that returns one byte of data in
        // the sensor_status field
        getSensorReadingData l_data;

        errlHndl_t l_err = readSensorData( l_data );

        if( l_err == nullptr )
        {
            o_value = l_data.sensor_status;
        }

        // It's possible that the sensor_status byte being used as "data" has
        // bits on that are treated as "status" and causing errors to be
        // created in readSensorData.
        // Look for that specific error and delete it, as the "data" should
        // still be good
        else if ((l_err->moduleId() == IPMI::MOD_IPMISENSOR) &&
                 (l_err->reasonCode() == IPMI::RC_SENSOR_READING_NOT_AVAIL))
        {
            o_value = l_data.sensor_status;

            TRACFCOMP(g_trac_ipmi, INFO_MRK "getKeyClearRequest() failed in "
                      "an expected way. Deleting this error and returning good "
                      "data 0x%.2X: "
                      TRACE_ERR_FMT,
                      o_value, TRACE_ERR_ARGS(l_err));
            delete l_err;
            l_err = nullptr;
        }
        return l_err;
    }

    //
    //  Used to update the sensor status for a specific set of target types
    //  currently supported types are TYPE_DIMM, TYPE_MEMBUF, TYPE_CORE,
    //  TYPE_PROC.  These are virtual sensors where Hostboot updates the
    //  present and functional states and the BMC maintains the sensor.
    //
    void updateBMCSensorStatus(TARGETING::TYPE i_type)
    {

        TARGETING::TargetHandleList l_tList;

        // get all targets of the passed in type, functional or not
        switch( i_type )
        {

            case TARGETING::TYPE_DIMM:
                getAllLogicalCards( l_tList, TARGETING::TYPE_DIMM, false );
                break;

            case TARGETING::TYPE_MEMBUF:
                getAllChips( l_tList, TARGETING::TYPE_MEMBUF, false );
                break;

            case TARGETING::TYPE_PROC:
                getAllChips( l_tList, TARGETING::TYPE_PROC, false );
                break;

            case TARGETING::TYPE_CORE:
                getAllChiplets( l_tList, TARGETING::TYPE_CORE, false);
                break;

            default:
                assert(0, "invalid target type for BMC update");

        }

        // have a list of targets now set the status sensor on the BMC for each
        // one.
        for(TARGETING::TargetHandleList::const_iterator pTargetIt =
            l_tList.begin();
            pTargetIt != l_tList.end();
            ++pTargetIt )
        {

            StatusSensor::statusEnum l_status
                                    = StatusSensor::PRESENT_FUNCTIONAL;

            // create a status sensor for our needs
            StatusSensor l_sensor((*pTargetIt));

            TARGETING::HwasState l_state =
                    (*pTargetIt)->getAttr<TARGETING::ATTR_HWAS_STATE>();

            if( l_state.present == true )
            {
                if( l_state.functional == false )
                {
                    l_status = StatusSensor::PRESENT_NONFUNCTIONAL;
                }
            }
            else
            {
                l_status = StatusSensor::NOT_PRESENT;
            }

            // send the status to the BMC
            errlHndl_t l_err = l_sensor.setStatus( l_status );

            // commit the error and move to the next target
            if( l_err )
            {
               errlCommit( l_err, IPMI_COMP_ID );
            }
       }

     }

    void updateBMCFaultSensorStatus(void)
    {
        TARGETING::ATTR_IPMI_SENSORS_type noSensors = {{0}};

        // No sensor attribute is all 0's; therefore if a sensor attribute is
        // found and is not all zeros (using the predicate value inversion
        // feature) then the sensor attribute has potential
        // sensors to iterate through
        TARGETING::PredicateAttrVal<TARGETING::ATTR_IPMI_SENSORS>
            hasSensors(noSensors,true);
        TARGETING::TargetRangeFilter targetsWithSensorsItr(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &hasSensors);
        for (; targetsWithSensorsItr; ++targetsWithSensorsItr)
        {
            // Cache the target for ease of reading/usage
            TARGETING::TargetHandle_t pTarget = *targetsWithSensorsItr;

            TARGETING::ATTR_IPMI_SENSORS_type sensors = {{0}};
            assert(pTarget->tryGetAttr<TARGETING::ATTR_IPMI_SENSORS>(sensors));

            // Derive number of sensor records by dividing attribute size by
            // size of each sensor record
            uint16_t sensorRows = (sizeof(sensors)/sizeof(sensors[0]));

            // Ceate an iterator pointing to the first element of the array
            uint16_t (*begin)[2] = &sensors[0];

            // Using the number entries as the index into the array will set the
            // end iterator to the correct position (one entry past the last
            // element of the array)
            uint16_t (*end)[2] = &sensors[sensorRows];

            // Locate the first record that could possibly match the criteria
            uint16_t (*ptr)[2] =
                std::lower_bound(begin, end,
                    TARGETING::SENSOR_NAME_FAULT, &compare_major);

            // Process any match, and all remaining matches after that, until
            // there is no additional match.  Here we are matching the major
            // sensor type only
            while(   (ptr != end)
                  && (   getMajorType((*ptr)[0])
                      == TARGETING::SENSOR_NAME_FAULT ))
            {
                TRACFCOMP(g_trac_ipmi, INFO_MRK " "
                    "Found fault sensor name 0x%X and ID 0x%X for HUID 0x%X",
                    (*ptr)[0], (*ptr)[1], TARGETING::get_huid(pTarget));

                FaultSensor faultSensor(pTarget,
                    static_cast<TARGETING::ENTITY_ID>(
                        getMinorType((*ptr)[0])));

                errlHndl_t pError = faultSensor.setStatus(
                    FaultSensor::FAULT_STATE_DEASSERTED);
                if(pError)
                {
                    TRACFCOMP(g_trac_ipmi, ERR_MRK " "
                        "Failed setting fault sensor name 0x%X and ID 0x%X for "
                        "HUID 0x%X",
                        (*ptr)[0], (*ptr)[1], TARGETING::get_huid(pTarget));
                    errlCommit(pError, IPMI_COMP_ID);
                }

                ++ptr;
            }
        }
    }

    void updateBMCSensorStatus()
    {

        // send status of all MEMBUF targets
        updateBMCSensorStatus(TARGETING::TYPE_MEMBUF);

        // send status of all DIMM targets
        updateBMCSensorStatus(TARGETING::TYPE_DIMM);

        // send status for all PROC targets
        updateBMCSensorStatus(TARGETING::TYPE_PROC);

        updateBMCSensorStatus(TARGETING::TYPE_CORE);

        // Send status for all simple fault sensors in the system
        updateBMCFaultSensorStatus();
    };

    // returns a sensor number for the FRU based on input target type
    // there are currently 4 frus defined system, backplane, DIMM, PROC
    //
    uint32_t getFaultSensorNumber( TARGETING::ConstTargetHandle_t i_pTarget )
    {
        TRACDCOMP(g_trac_ipmi,">>getFaultSensorNumber()");

        TARGETING::TYPE l_type = i_pTarget->getAttr<TARGETING::ATTR_TYPE>();

        uint32_t l_sensor_number = TARGETING::UTIL::INVALID_IPMI_SENSOR;

        switch( l_type )
        {

            case TARGETING::TYPE_SYS:
                {
                    TRACDCOMP(g_trac_ipmi, "returning the \"System Event\" sensor\n");
                    l_sensor_number = TARGETING::UTIL::getSensorNumber(
                            i_pTarget,
                            TARGETING::SENSOR_NAME_SYSTEM_EVENT );

                    TRACDCOMP(g_trac_ipmi,"Sensor Number = 0x%x", l_sensor_number);
                    break;
                }

            case TARGETING::TYPE_NODE:
                {
                    TRACDCOMP(g_trac_ipmi, "returning the \"BACKPLANE_FAULT\" sensor\n");
                    l_sensor_number = TARGETING::UTIL::getSensorNumber(
                            i_pTarget,
                            TARGETING::SENSOR_NAME_BACKPLANE_FAULT );

                    TRACDCOMP(g_trac_ipmi,"Sensor Number = 0x%x", l_sensor_number);
                    break;
                }

            // these targets have specific status sensors
            case TARGETING::TYPE_DIMM:
            case TARGETING::TYPE_MEMBUF:
            case TARGETING::TYPE_PROC:
                {
                    l_sensor_number =
                                StatusSensor(i_pTarget).getSensorNumber();

                    TRACDCOMP(g_trac_ipmi,"Sensor Number = 0x%x", l_sensor_number);
                    break;
                }

            default:
                {

                    TARGETING::EntityPath l_targetPath =
                        i_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>();

                    // chop off the last part and go again.
                    l_targetPath.removeLast();

                    TARGETING::TargetHandle_t l_target = NULL;
                    l_target =
                        TARGETING::targetService().toTarget(l_targetPath);

                    l_sensor_number =  getFaultSensorNumber(
                        static_cast<TARGETING::ConstTargetHandle_t>(l_target));

                    break;
                }
        }

        TRACDCOMP(g_trac_ipmi,"<<getFaultSensorNumber() returning sensor number %#x", l_sensor_number);

        return l_sensor_number;
    }

    // interface to retrieve the APSS channel sensor numbers.
    errlHndl_t getAPSSChannelSensorNumbers(
            const uint32_t (* &o_sensor_numbers)[16])
    {

        TARGETING::TargetHandle_t l_sys;

        // get the "system error" sensor number associated with the
        // system target.

        TARGETING::targetService().getTopLevelTarget(l_sys);

        static TARGETING::ATTR_ADC_CHANNEL_SENSOR_NUMBERS_type
                                                apss_sensors;

        if( l_sys->tryGetAttr<TARGETING::
                ATTR_ADC_CHANNEL_SENSOR_NUMBERS>(apss_sensors) )
        {
            o_sensor_numbers = &apss_sensors;
        }
        else
        {
            // need that attribute or things dont work
            assert(0,"Missing ADC_CHANNEL_SENSOR_NUMBERS attribute");
        }

        return NULL;
    }

    uint16_t getSensorOffsets( TARGETING::SENSOR_NAME i_name,
                             sensorReadingType &o_readType )
    {

        uint16_t offsets = 0;

        // most of our sensors use generic sensor specific reading types
        // so use that as the default value
        o_readType = SENSOR_SPECIFIC;

        // sensor type is lower byte of sensor name, if we dont match
        // based on name, then try the sensor type
        uint16_t t = ( i_name >> 8 ) & 0x00FF;

        switch( i_name )
        {
            case TARGETING::SENSOR_NAME_FW_BOOT_PROGRESS:
                {
                    offsets = ( 1 << SYSTEM_FIRMWARE_PROGRESS );
                    break;
                }
            case TARGETING::SENSOR_NAME_HOST_STATUS:
                {
                    offsets = ( 1 << S0_G0_WORKING ) |
                              ( 1 << G5_SOFT_OFF )   |
                              ( 1 << LEGACY_ON );
                    break;
                }
            case TARGETING::SENSOR_NAME_PCI_ACTIVE:
            case TARGETING::SENSOR_NAME_OS_BOOT:
                {
                    // default all offsets enabled
                    offsets = 0x7FFF;
                    break;
                }

            default:
                {
                    // try sensor type
                    switch (t)
                    {
                        case TARGETING::SENSOR_TYPE_FAULT:
                            offsets = ( 1 << ASSERTED );
                            o_readType = DIGITAL_ASSERT_DEASSERT;
                            break;

                        case TARGETING::SENSOR_TYPE_PROCESSOR:
                            offsets = ( 1 << PROC_PRESENCE_DETECTED ) |
                                      ( 1 << PROC_DISABLED )          |
                                      ( 1 << IERR );
                            break;

                        case TARGETING::SENSOR_TYPE_MEMORY:
                            offsets = ( 1 << MEMORY_DEVICE_DISABLED ) |
                                ( 1 << MEM_DEVICE_PRESENCE_DETECTED );
                            break;
                        default:
                            offsets = 0;
                            o_readType = THRESHOLD;
                            break;
                    }

                }
        }

        return offsets;
    }

    uint8_t getBackPlaneFaultSensor()
    {
        TARGETING::TargetHandle_t sys = NULL;
        TARGETING::TargetHandleList nodes;
        TARGETING::targetService().getTopLevelTarget(sys);
        assert(sys != NULL);
        getChildAffinityTargets(nodes, sys, TARGETING::CLASS_ENC,
                                TARGETING::TYPE_NODE);
        assert(!nodes.empty());

        //Backplane sensor ID
        return TARGETING::UTIL::getSensorNumber(nodes[0],
                                        TARGETING::SENSOR_NAME_BACKPLANE_FAULT);
    }

    /**
     * @brief  All sensors returned cfgID bit
     */
    static const uint16_t NVCFG_ALL_SENSORS_RETURNED = 0xFFFF;

    /**
     * @brief  Helper function to getGpuSensors()
     *         NV keyword tells us what backplane is installed,
     *         thus what GPUs are supported
     *
     * @param[out] returns NV keyword in bitwise format
     *
     * @return  Error log handle if a deviceRead fails
     */
    errlHndl_t getNVCfgIDBit(uint16_t & o_cfgID_bitwise)
    {
        errlHndl_t l_err = nullptr;
        /* TODO RTC: 257493 remove IPMI fru inventory code */
        return l_err;
    }

    /**
     *  @brief Grab the GPU sensor type IDs for a particular processor target
     *
     *   Will return all sensor ids that match the type for a given target.
     *
     *  @param[in] - i_proc  - processor target
     *  @param[in] - i_type  - Functional/state, gpucoretemp, gpumemtemp
     *  @param[out] - o_num_ids - number of valid IDs returned in o_ids
     *  @param[out] - o_ids     - ordered list of sensor IDs
     *
     *  @return Errorlog handle
     */
    errlHndl_t getGpuSensors( TARGETING::Target* i_proc,
                              HWAS::sensorTypeEnum i_type,
                              uint8_t & o_num_ids,
                              uint32_t o_ids[MAX_GPU_SENSORS_PER_PROCESSOR] )
    {
        static uint16_t L_obus_cfgID_bit = 0;
        errlHndl_t l_errl = nullptr;

        // default to no ids returned
        o_num_ids = 0;

        TARGETING::AttributeTraits<TARGETING::ATTR_GPU_SENSORS>::Type
                                                                 l_sensorArray;

        bool foundSensors = i_proc->tryGetAttr<TARGETING::ATTR_GPU_SENSORS>
                                                                (l_sensorArray);

        // Verify we are getting non-default values
        if (foundSensors && l_sensorArray[0][0] != 0)
        {
            // Figure out which backplane we have
            // Only read NV keyword once (if possible)
            if (L_obus_cfgID_bit == 0)
            {
                l_errl = getNVCfgIDBit(L_obus_cfgID_bit);
                if (l_errl || (L_obus_cfgID_bit == 0))
                {
                    delete l_errl;
                    l_errl = nullptr;
                    // default to full list of GPU sensors
                    L_obus_cfgID_bit = NVCFG_ALL_SENSORS_RETURNED;
                }
            }

            uint32_t elementCount = (sizeof(l_sensorArray)/
                                     sizeof(l_sensorArray[0]));
            TRACFCOMP(g_trac_ipmi,"getGpuSensors() -> GPU_SENSORS array size = %d, cfgBit = 0x%x",
                     elementCount, L_obus_cfgID_bit);

            // verify array index won't exceed output array (o_ids)
            assert(elementCount <= MAX_GPU_SENSORS_PER_PROCESSOR);

            // now cycle through each GPU row
            for (uint32_t index = 0; index < elementCount; index++)
            {
                uint16_t * row_ptr = &l_sensorArray[index][0];

                TRACFCOMP(g_trac_ipmi,"getGpuSensors() -> ROW %d, 0x%04X, 0x%X, 0x%04X, 0x%X, 0x%04X, 0x%X, 0x%X",
                        index, row_ptr[0], row_ptr[1], row_ptr[2],
                        row_ptr[3], row_ptr[4], row_ptr[5], row_ptr[6]);

                // Include Sensor if the GPU is present in the current OBUS_CFG
                if ( (L_obus_cfgID_bit == NVCFG_ALL_SENSORS_RETURNED) ||
                    ((L_obus_cfgID_bit &
                      row_ptr[TARGETING::GPU_SENSOR_ARRAY_OBUS_CFG_OFFSET])
                    == L_obus_cfgID_bit) )
                {
                    switch(i_type)
                    {
                        case HWAS::GPU_FUNC_SENSOR:
                            o_ids[index] =
                            row_ptr[TARGETING::GPU_SENSOR_ARRAY_FUNC_ID_OFFSET];
                            o_num_ids++;
                        break;
                        case HWAS::GPU_MEMORY_TEMP_SENSOR:
                            o_ids[index] =
                        row_ptr[TARGETING::GPU_SENSOR_ARRAY_MEM_TEMP_ID_OFFSET];
                            o_num_ids++;
                        break;
                        case HWAS::GPU_TEMPERATURE_SENSOR:
                            o_ids[index] =
                            row_ptr[TARGETING::GPU_SENSOR_ARRAY_TEMP_ID_OFFSET];
                            o_num_ids++;
                        break;
                        default:
                            TRACFCOMP(g_trac_ipmi,"getGpuSensors() -> unknown sensor type 0x%02X", i_type);
                            o_ids[index] = TARGETING::UTIL::INVALID_IPMI_SENSOR;
                    }
                }
                else
                {
                    o_ids[index] = TARGETING::UTIL::INVALID_IPMI_SENSOR;
                }
                TRACFCOMP(g_trac_ipmi,
                    "getGpuSensors() -> o_id[%d] = 0x%X", index, o_ids[index]);
            } // end of for loop
        } // end of if check for non-default values

        return NULL;
    } // end getGpuSensors()


    /**
     * @brief   Helper function that sends GPU sensor status to BMC
     *
     * @param[in] sensor name (IPMI_SENSOR_TYPE with IPMI_ENTITY_ID)
     * @param[in] sensor id number
     * @param[in] processor target
     * @param[in] status to send for the identified GPU sensor
     */
    void sendGpuSensorStatus(uint16_t i_sensor_name_value,
                            uint16_t i_sensor_id,
                            TARGETING::ConstTargetHandle_t i_target,
                            StatusSensor::statusEnum & i_status)
    {
        TRACFCOMP(g_trac_ipmi, "sendGpuSensorStatus(0x%0X, 0x%X, Target 0x%X, status: %d)",
            i_sensor_name_value, i_sensor_id,
            TARGETING::get_huid(i_target), i_status);

        TARGETING::SENSOR_NAME l_sensor_name;
        switch(i_sensor_name_value)
        {
            case TARGETING::SENSOR_NAME_GPU_TEMP:
                l_sensor_name = TARGETING::SENSOR_NAME_GPU_TEMP;
                break;
            case TARGETING::SENSOR_NAME_GPU_STATE:
                l_sensor_name = TARGETING::SENSOR_NAME_GPU_STATE;
                break;
            case TARGETING::SENSOR_NAME_GPU_MEM_TEMP:
                l_sensor_name = TARGETING::SENSOR_NAME_GPU_MEM_TEMP;
                break;
            default:
                TRACFCOMP(g_trac_ipmi, "sendGpuSensorStatus(0x%0X, 0x%X) - unknown GPU sensor name",
                    i_sensor_name_value, i_sensor_id);
                l_sensor_name = TARGETING::SENSOR_NAME_FAULT;
            break;
        }

        // Only update if we found a valid gpu sensor name
        if (l_sensor_name != TARGETING::SENSOR_NAME_FAULT)
        {
            // create a GPU status sensor for our needs
            GpuSensor l_sensor(l_sensor_name, i_sensor_id, i_target);

            // send the status to the BMC
            errlHndl_t l_err = l_sensor.setStatus( i_status );

            // commit the error and move to the next target
            if( l_err )
            {
               errlCommit( l_err, IPMI_COMP_ID );
            }
        }
    }

    /**
     *  @brief  Updates GPU sensor status for GPUs on this
     *          particular processor target
     *
     *  @param[in] - i_proc       - processor target
     *  @param[in] - i_gpu_status - status of GPU0, GPU1 and GPU2
     */
    void updateGpuSensorStatus( TARGETING::Target* i_proc,
                    StatusSensor::statusEnum i_gpu_status[MAX_PROCESSOR_GPUS] )
    {
        uint16_t obus_cfgID_bit = 0;

        TARGETING::AttributeTraits<TARGETING::ATTR_GPU_SENSORS>::Type
                                                                  l_sensorArray;

        bool foundSensors = i_proc->tryGetAttr<TARGETING::ATTR_GPU_SENSORS>
                                                                (l_sensorArray);

        // Verify we are getting non-default values
        if (foundSensors && (l_sensorArray[0][0] != 0))
        {
            // Figure out which backplane we have
            // Only read NV keyword once (if possible)
            errlHndl_t l_errl = getNVCfgIDBit(obus_cfgID_bit);
            if (l_errl || (obus_cfgID_bit == 0))
            {
                // default to all sensors
                obus_cfgID_bit = NVCFG_ALL_SENSORS_RETURNED;
                delete l_errl;
            }

            uint32_t elementCount = (sizeof(l_sensorArray)/
                                     sizeof(l_sensorArray[0]));
            TRACDCOMP(g_trac_ipmi,"updateGpuSensorStatus() -> array size = %d, cfgBit = 0x%x",
                     elementCount, obus_cfgID_bit);

            // verify array index won't exceed output array (o_ids)
            assert(elementCount <= MAX_PROCESSOR_GPUS);

            // now cycle through each GPU row
            for (uint8_t index = 0; index < MAX_PROCESSOR_GPUS; index++)
            {
                uint16_t * sensor_row_ptr = &l_sensorArray[index][0];
                StatusSensor::statusEnum newStatus = i_gpu_status[index];

                // Include Sensor if the GPU is present in the current OBUS_CFG
                if ( (obus_cfgID_bit == NVCFG_ALL_SENSORS_RETURNED) ||
                    ((obus_cfgID_bit &
                    sensor_row_ptr[TARGETING::GPU_SENSOR_ARRAY_OBUS_CFG_OFFSET])
                    == obus_cfgID_bit) )
                {
                    // Only update the GPU status sensors, skip temperature ones
                    // GPU core Status/Functional Sensor
                    uint16_t sensor_name =
                sensor_row_ptr[TARGETING::GPU_SENSOR_ARRAY_FUNC_OFFSET];
                    uint16_t sensor_id =
                sensor_row_ptr[TARGETING::GPU_SENSOR_ARRAY_FUNC_ID_OFFSET];
                    sendGpuSensorStatus(sensor_name,sensor_id,i_proc,newStatus);
                }
            } // end of GPU loop
        } // end of if check for non-default values
    } // end of updateGpuSensorStatus()


    //
    // HbVolatileSensor constructor - uses system target
    //
    HbVolatileSensor::HbVolatileSensor()
        :SensorBase(TARGETING::SENSOR_NAME_HB_VOLATILE, NULL)
    {
        // message buffer created and initialized in base object.
    }

    //
    // HbVolatileSensor destructor
    //
    HbVolatileSensor::~HbVolatileSensor(){};

    //
    // setHbVolatile - tell BMC to make hostboot volatile memory
    //                 (volatile(2) or not(1))
    //
    errlHndl_t HbVolatileSensor::setHbVolatile( hbVolatileSetting i_setting )
    {
        // adjust the operation to overwrite the sensor reading
        // to the value we send.
        iv_msg->iv_operation = SET_SENSOR_VALUE_OPERATION;

        // the HB_VOLATILE Sensor is defined as a discrete sensor
        // but the assertion bytes are being used to transfer the state
        iv_msg->iv_assertion_mask = le16toh(i_setting);

        TRACFCOMP(g_trac_ipmi,"HbVolatileSensor::setHbVolatile(%d)",
                    i_setting);

        return writeSensorData();
    }

    //
    // getHbVolatile - get the HB volatile memory setting from the BMC
    //
    errlHndl_t HbVolatileSensor::getHbVolatile( hbVolatileSetting &o_setting )
    {
        // the HB_VOLATILE sensor is defined as a discrete sensor
        getSensorReadingData l_data;

        errlHndl_t l_err = readSensorData( l_data );

        if( l_err == nullptr )
        {
            // check if in valid range of hbVolatileSetting enums
            if ( l_data.event_status == ENABLE_VOLATILE ||
                 l_data.event_status == DISABLE_VOLATILE )
            {
                o_setting = static_cast<hbVolatileSetting>(l_data.event_status);
            }
            else
            {
                TRACFCOMP(g_trac_ipmi,"Unknown hb volatile setting: %d",
                    l_data.event_status);

                /*@
                 * @errortype    ERRL_SEV_UNRECOVERABLE
                 * @moduleid     IPMI::MOD_IPMISENSOR_HBVOLATILE
                 * @reasoncode   IPMI::RC_INVALID_SENSOR_SETTING
                 * @userdata1    Invalid hb volatile control setting
                 * @userdata2    <unused>
                 * @devdesc      The sensor returned an invalid setting
                 * @custdesc     Unable to find a valid sensor setting.
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            IPMI::MOD_IPMISENSOR_HBVOLATILE,
                                            IPMI::RC_INVALID_SENSOR_SETTING,
                                            l_data.event_status,
                                            0,
                                            false);
            }
        }
        return l_err;
    }

}; // end name space
