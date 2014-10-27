/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmisensor.C $                                   */
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

extern trace_desc_t * g_trac_ipmi;

namespace SENSOR
{
    //
    // Base class for sensor construction.  It is expected that this object will
    // be used as the base for any additional sensors defined.
    //
    SensorBase::SensorBase( TARGETING::SENSOR_NAME i_name,
                             TARGETING::Target * i_target)
        :iv_name(i_name) ,iv_target(i_target)
    {
        // allocate a new message structure to use with our sensors
        // this will be the payload for the IPMI send/sendrecv sensor message.
        iv_msg = new setSensorReadingRequest;
    };

    // base class destructor
    SensorBase::~SensorBase()
    {
        // The memory allocated for the set sensor reading command is deleted
        // by the IPMI transport layer, this delete will get delete the memory
        // allocated by the IPMI transport layer which contains the response
        // to the set sensor reading command.
        if( iv_msg )
        {
            delete[] iv_msg;
        }
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
                   /* @errorlog tag
                    * @errortype       ERRL_SEV_UNRECOVERABLE
                    * @moduleid        IPMI::MOD_IPMISENSOR
                    * @reasoncode      IPMI::RC_SENSOR_NOT_SETTABLE
                    * @userdata1       BMC IPMI Completion code.
                    * @userdata2       bytes [0-3]sensor number
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
                   /* @errorlog tag
                    * @errortype       ERRL_SEV_UNRECOVERABLE
                    * @moduleid        IPMI::MOD_IPMISENSOR
                    * @reasoncode      IPMI::RC_EVENT_DATA_NOT_SETTABLE
                    * @userdata1       BMC IPMI Completion code.
                    * @userdata2       bytes[0-3]sensor number
                    *                  bytes[4-7]HUID of target.
                    * @devdesc         Set sensor reading command failed.
                    */
                    l_reasonCode = IPMI::RC_EVENT_DATA_NOT_SETTABLE;
                    TRACFCOMP(g_trac_ipmi,"Attempted to set event data bytes but"
                              "setting event data bytes is not supported for"
                              " this sensor");
                    break;
                }

                case IPMI::CC_CMDSENSOR:
                {
                   /* @errorlog tag
                    * @errortype       ERRL_SEV_UNRECOVERABLE
                    * @moduleid        IPMI::MOD_IPMISENSOR
                    * @reasoncode      IPMI::RC_INVALID_SENSOR_CMD
                    * @userdata1       BMC IPMI Completion code.
                    * @userdata2       bytes [0-3]sensor number
                    *                  bytes [4-7]HUID of target.
                    * @devdesc         Command not valid for this sensor.
                    */
                    l_reasonCode = IPMI::RC_INVALID_SENSOR_CMD;
                    TRACFCOMP(g_trac_ipmi,"Command not valid for this sensor");
                    break;
                }

                case IPMI::CC_BADSENSOR:
                {
                   /* @errorlog tag
                    * @errortype       ERRL_SEV_UNRECOVERABLE
                    * @moduleid        IPMI::MOD_IPMISENSOR
                    * @reasoncode      IPMI::RC_SENSOR_NOT_PRESENT
                    * @userdata1       BMC IPMI Completion code.
                    * @userdata2       bytes [0-3]sensor number
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
                   /* @errorlog tag
                    * @errortype       ERRL_SEV_UNRECOVERABLE
                    * @moduleid        IPMI::MOD_IPMISENSOR
                    * @reasoncode      IPMI::RC_SET_SENSOR_FAILURE
                    * @userdata1       BMC IPMI Completion code.
                    * @userdata2       bytes [0-3]sensor number
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
            uint64_t userdata2 = getSensorNumber();

            userdata2 = (userdata2 << 32) | TARGETING::get_huid(iv_target);

            l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                IPMI::MOD_IPMISENSOR,
                                l_reasonCode,
                                i_rc, userdata2, true);

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

        iv_msg->iv_sensor_number = getSensorNumber();

        if( iv_msg->iv_sensor_number != INVALID_SENSOR )
        {

            IPMI::completion_code l_rc = IPMI::CC_UNKBAD;

            // iv_msg is deleted by the destructor
            l_err = sendSetSensorReading( iv_msg, l_rc);

            if( l_err )
            {
                TRACFCOMP(g_trac_ipmi,"error returned from "
                        "sendSetSensorReading() for sensor number 0x%x",
                        getSensorNumber());

                // return error log to caller
            }
            else
            {
                // check the completion code to see if we need to generate a
                // PEL.
                l_err = processCompletionCode( l_rc );
            }
        }
        else
        {
            TRACFCOMP(g_trac_ipmi,"We were not able to find a sensor number in"
                      " the IPMI_SENSORS attribute for sensor_name=0x%x"
                      "for target with huid=0x%x, skipping call to "
                      "sendSetSensorReading()",
                    iv_name, TARGETING::get_huid( iv_target ));

            assert(false);

        }

        return l_err;
    };

    //
    // Helper function to set the bit in the assertion/deassertion mask
    // associated with the desired sensor specific offset
    //
    uint16_t SensorBase::setMask( const uint8_t offset )
    {
        const uint16_t mask = (0x0001 << offset);

        // need to byte swap the mask (see set sensor reading in spec)
        return le16toh(mask);
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
    errlHndl_t SensorBase::readSensorData(uint8_t *& o_data)
    {

        // get sensor reading command only requires one byte of extra data,
        // which will be the sensor number, the command will return between
        // 3 and 5 bytes of data.
        size_t len =  1;

        // need to allocate some me to hold the sensor number this will be
        // deleted by the IPMI transport layer
        o_data = new uint8_t[len];

        o_data[0] = getSensorNumber();

        IPMI::completion_code cc = IPMI::CC_UNKBAD;

        // o_data will hold the response when this returns
        errlHndl_t l_err = sendrecv(IPMI::get_sensor_reading(), cc, len,
                                  (uint8_t *&)o_data);

        // if we didn't get an error back from the BT interface, but see a
        // bad completion code from the BMC, process the CC to see if we
        // need to create a PEL
        if( (l_err == NULL ) && (cc != IPMI::CC_OK) )
        {
            l_err = processCompletionCode( cc );
        }

        return l_err;
    };

    //
    //  Synchronously send a set sensor reading command to the BMC,
    //  the response is returned with the io_data pointer
    //
    errlHndl_t SensorBase::sendSetSensorReading(
                            setSensorReadingRequest *& io_data,
                            IPMI::completion_code& o_completion_code )
    {

        size_t l_len = sizeof( setSensorReadingRequest );

        o_completion_code = IPMI::CC_UNKBAD;

        // i_data will hold the response when this returns
        errlHndl_t l_err = sendrecv(IPMI::set_sensor_reading(),
                            o_completion_code, l_len, (uint8_t *&)io_data);

        return l_err;
    }


    // given an array[][2] compare the number in the first column to the passed
    // in key value
    static inline bool compare_it( uint16_t (&a)[2], uint16_t key )
    {
        return  a[0] < key;
    };

    //
    // Helper function to search the sensor data for the correct sensor number
    // based on the sensor name.
    //
    uint16_t SensorBase::getSensorNumber()
    {

        uint16_t l_sensor_number = INVALID_SENSOR;

        if( iv_target == NULL )
        {
            // use the system target
            TARGETING::targetService().getTopLevelTarget(iv_target);

            // die if there is no system target
            assert(iv_target);

        }

        TARGETING::AttributeTraits<TARGETING::ATTR_IPMI_SENSORS>::Type
                                                                    l_sensors;

        if(  iv_target->tryGetAttr<TARGETING::ATTR_IPMI_SENSORS>(l_sensors) )
        {

            // get the number of rows by dividing the total size by the size of
            // the first row
            uint16_t array_rows = (sizeof(l_sensors)/sizeof(l_sensors[0]));

            // create an iterator pointing to the first element of the array
            uint16_t (*begin)[2]  = &l_sensors[0];

            // using the number entries as the index into the array will set the
            // end iterator to the correct position or one entry past the last
            // element of the array
            uint16_t (*end)[2] = &l_sensors[array_rows];

            uint16_t (*ptr)[2] =
                        std::lower_bound(begin, end, iv_name, &compare_it);

            // we have not reached the end of the array and the iterator
            // returned from lower_bound is pointing to an entry which equals
            // the one we are searching for.
            if( ( ptr != end ) && ( (*ptr)[0] == iv_name ) )
            {
                // found it
                l_sensor_number = (*ptr)[1];

                TRACFCOMP(g_trac_ipmi,"Found sensor number %d for HUID=0x%x",
                          l_sensor_number, TARGETING::get_huid(iv_target));
            }
        }
        else
        {
            // bug here...
            assert(0,"no IPMI_SENSOR attribute check target HUID=0x%x",
                   TARGETING::get_huid(iv_target));
        }

        return l_sensor_number;
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
            firmwareProgressPhase phase )
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
    errlHndl_t RebootCountSensor::setRebootCount( rebootCount_t i_count )
    {

        // put the reboot count into the sensor
        // reading byte of the message
        iv_msg->iv_sensor_reading = i_count;

        return writeSensorData();

    }

    //
    // StatusSensor constructor - uses system DIMM/CORE/PROC target
    //
    StatusSensor::StatusSensor( TARGETING::Target * i_target )
        :SensorBase(TARGETING::SENSOR_NAME_STATE, i_target)
    {

        switch ( i_target->getAttr<TARGETING::ATTR_TYPE>() )
        {
            case TARGETING::TYPE_DIMM:
                {
                    iv_functionalOffset  = 0x04;
                    iv_presentOffset     = 0x06;
                    break;
                }

            case TARGETING::TYPE_PROC:
            case TARGETING::TYPE_CORE:
                {
                    iv_functionalOffset  = 0x08;
                    iv_presentOffset     = 0x07;
                    break;
                }

            default:
                iv_presentOffset     = 0xFF;
                iv_functionalOffset  = 0xFF;
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
        // if the offset isn't configured then the target does not have
        // one of these sensors.
        if( iv_functionalOffset != 0xFF && iv_presentOffset != 0xFF )
        {

            uint16_t func_mask = setMask( iv_functionalOffset );
            uint16_t pres_mask = setMask( iv_presentOffset );

            switch ( i_state )
            {
                case NOT_PRESENT:
                    // turn off the present bit
                    iv_msg->iv_deassertion_mask = pres_mask;
                    // turn on the disabled bit
                    iv_msg->iv_assertion_mask = func_mask;
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
        iv_msg->iv_assertion_mask = setMask((uint8_t)status);

        return writeSensorData();
    };

    //
    //  Used to update the sensor status for a specific set of target types
    //  currently supported types are TYPE_DIMM, TYPE_CORE, TYPE_PROC.  These
    //  are virtual sensors where Hostboot updates the present and functional
    //  states and the BMC maintains the sensor.
    //
    void updateBMCSensorStatus(TARGETING::TYPE i_type)
    {

        TARGETING::TargetHandleList l_tList;

        // get all targets of the passed in type, functional or not
        switch( i_type )
        {
            case TARGETING::TYPE_PROC:
                getAllChips( l_tList, TARGETING::TYPE_PROC, false );
                break;

            case TARGETING::TYPE_DIMM:
                getAllLogicalCards( l_tList, TARGETING::TYPE_DIMM, false );
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

    void updateBMCSensorStatus()
    {
        // send status of all DIMM targets
        updateBMCSensorStatus(TARGETING::TYPE_DIMM);

        // send status for all PROC targets
        updateBMCSensorStatus(TARGETING::TYPE_PROC);

        updateBMCSensorStatus(TARGETING::TYPE_CORE);

    };

}; // end name space


