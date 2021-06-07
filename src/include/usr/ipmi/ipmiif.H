/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ipmi/ipmiif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
/* [+] Google Inc.                                                        */
/* [+] International Business Machines Corp.                              */
/* [+] Maxim Polyakov                                                     */
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
#ifndef __IPMI_IPMIIF_H
#define __IPMI_IPMIIF_H

#include <sys/msg.h>
#include <errl/errlentry.H>
#include <map>

namespace IPMI
{
    // Message types which travel on the IPMI message queues
    enum msg_type
    {
        // Sent when the interface goes idle *and* we had write which
        // was told the interface was busy. We won't get notified of
        // the general idle state.
        MSG_STATE_IDLE,

        // Ready to read a response
        MSG_STATE_RESP,

        // Ready to read an event/sms
        MSG_STATE_EVNT,

        // A message which needs to be sent
        MSG_STATE_SEND,

        MSG_STATE_SHUTDOWN,

        MSG_STATE_GRACEFUL_SHUTDOWN,

        // initiate a reboot request
        MSG_STATE_INITIATE_POWER_CYCLE,

        // initiate a soft power off
        MSG_STATE_INITIATE_SOFT_POWER_OFF,

        // Used to check range. Leave as last.
        MSG_LAST_TYPE = MSG_STATE_INITIATE_SOFT_POWER_OFF,
    };

    /**
     *  @brief Returns whether IPMI message type is related to
     *    system shutdown/reboot or not
     *
     *  @param[in] i_msgType IPMI message type in question
     *
     *  @return bool True or false value indicating whether requested IPMI
     *     message type is related to system shutdown/reboot or not
     */
    inline bool validShutdownRebootMsgType(const msg_type i_msgType)
    {
        return (   (i_msgType == MSG_STATE_SHUTDOWN)
                || (i_msgType == MSG_STATE_GRACEFUL_SHUTDOWN)
                || (i_msgType == MSG_STATE_INITIATE_SOFT_POWER_OFF)
                || (i_msgType == MSG_STATE_INITIATE_POWER_CYCLE));
    }

    // chassis power off request types
    // See Section 28.3, Table 28 "Chassis Control Command" in IPMI spec v2.0
    enum power_request_type
    {
        CHASSIS_POWER_OFF = 0x00,
        CHASSIS_POWER_ON = 0x01,
        CHASSIS_POWER_CYCLE = 0x02,
        CHASSIS_POWER_RESET = 0x03,
        CHASSIS_POWER_PULSE_DIAGNOSTIC_INTR = 0x04,
        CHASSIS_POWER_SOFT_OFF_VIA_OVER_TEMP = 0x05, // Use for Soft Power Off
    };

    // Used in the factory for creating the proper subclass.
    enum message_type
    {
        TYPE_SYNC = 0,
        TYPE_ASYNC = 1,
        TYPE_EVENT = 2,
    };

    // IPMI network functions
    enum network_function
    {
        // These are the command network functions, the response
        // network functions are the function + 1. So to determine
        // the proper network function which issued the command
        // associated with a response, subtract 1.
        // Note: these are also shifted left to make room for the LUN.
        NETFUN_CHASSIS  = (0x00 << 2),
        NETFUN_BRIDGE   = (0x02 << 2),
        NETFUN_SENSOR   = (0x04 << 2),
        NETFUN_APP      = (0x06 << 2),
        NETFUN_FIRMWARE = (0x08 << 2),
        NETFUN_STORAGE  = (0x0a << 2),
        NETFUN_TRANPORT = (0x0c << 2),
        NETFUN_GRPEXT   = (0x2c << 2),
        NETFUN_IBM =      (0x3a << 2),

        // Overload the OEM netfun for a "none" netfun. We use this as a
        // default for objects which will have their netfun filled in
        NETFUN_NONE     = (0x30 << 2),
    };

    /**
     * @brief  Generate the response for IPMI network function
     * @param[in]  Standard network function
     * @return  Network function in response (+1)
     */
    inline const uint8_t gen_resp_netfn( network_function i_netfn )
    {
        return ( ( (i_netfn >> 2) + 1 ) << 2 );
    };

    // SMS_ATN OEM Event constants
    enum oem_event
    {
        OEM_VALID_NETFUN      = 0x3a,
        OEM_VALID_SEL_ID      = 0x5555,
        OEM_VALID_RECORD_TYPE = 0xC0,
    };

    // IPMI Completion Codes
    enum completion_code
    {
        CC_OK        = 0x00,
        CC_CMDSPC1   = 0x80, // command specific completion code
        CC_CMDSPC2   = 0x81, // command specific completion code
        CC_BUSY      = 0xc0,
        CC_INVALID   = 0xc1,
        CC_CMDLUN    = 0xc2,
        CC_TIMEOUT   = 0xc3,
        CC_NOSPACE   = 0xc4,
        CC_BADRESV   = 0xc5,
        CC_TRUNC     = 0xc6,
        CC_BADLEN    = 0xc7,
        CC_TOOLONG   = 0xc8,
        CC_OORANGE   = 0xc9,
        CC_LONGREPLY = 0xca,
        CC_BADSENSOR = 0xcb,
        CC_REQINVAL  = 0xcc,
        CC_CMDSENSOR = 0xcd,
        CC_CANTREPLY = 0xce,
        CC_DUPREQ    = 0xcf,
        CC_SDRUPDATE = 0xd0,
        CC_FMWUPDATE = 0xd1,
        CC_BMCINIT   = 0xd2,
        CC_BADDEST   = 0xd3,
        CC_NOPERM    = 0xd4,
        CC_BADSTATE  = 0xd5,
        CC_ILLPARAM  = 0xd6,
        CC_UNKBAD    = 0xff
    };

    // per IPMI Spec, section 32.2 OEM SEL Event Records
    struct oemSEL {

        enum Constants
        {
            MANUF_LENGTH = 3,
            CMD_LENGTH = 5,
            LENGTH = 16,
        };

        // ID used for SEL Record access. The Record ID values 0000h and FFFFh
        // have special meaning in the Event Access commands and must not be
        // used as Record ID values for stored SEL Event Records.
        uint16_t iv_record;

        // [7:0] - Record Type
        //  02h     = system event record
        //  C0h-DFh = OEM timestamped, bytes 8-16 OEM defined
        //  E0h-FFh = OEM non-timestamped, bytes 4-16 OEM defined
        uint8_t iv_record_type;

        // Time when event was logged. LS byte first.
        uint32_t iv_timestamp;

        // 3 bytes for the manuf id
        uint8_t iv_manufacturer[MANUF_LENGTH];

        // Presently 0x3A for IBM
        uint8_t iv_netfun;

        // Current command and arguments
        uint8_t iv_cmd[CMD_LENGTH];

        // @brief Populate a selRecord from the wire representation of an event
        // @param[in] i_raw_event_data, pointer to the raw data
        void populateFromEvent(uint8_t const* i_raw_event_data);

        // ctor
        oemSEL():
            iv_record(0),
            iv_record_type(0),
            iv_timestamp(0),
            iv_netfun(0)
            {
                memset(iv_manufacturer, 0, MANUF_LENGTH);
                memset(iv_cmd, 0, CMD_LENGTH);
            };

        // @Brief Create a selRecord from the wire representation of an event
        // @param[in] i_event_data, pointer to the event data
        oemSEL( uint8_t const* i_event_data )
            { populateFromEvent( i_event_data ); }

    };

    //
    // Network function, command pairs.
    //
    typedef std::pair<network_function, uint8_t> command_t;


    // Application messages
    inline const command_t get_device_id(void)
    { return std::make_pair(NETFUN_APP, 0x01); }

    inline const command_t set_acpi_power_state(void)
    { return std::make_pair(NETFUN_APP, 0x06); }

    inline const command_t set_watchdog(void)
    { return std::make_pair(NETFUN_APP, 0x24); }

    inline const command_t reset_watchdog(void)
    { return std::make_pair(NETFUN_APP, 0x22); }

    inline const command_t read_event(void)
    { return std::make_pair(NETFUN_APP, 0x35); }

    inline const command_t get_capabilities(void)
    { return std::make_pair(NETFUN_APP, 0x36); }


    // Chassis messages
    inline const command_t chassis_power_off(void)
    { return std::make_pair(NETFUN_CHASSIS, 0x02); }


    // Storage messages
    inline const command_t get_sel_time(void)
    { return std::make_pair(NETFUN_STORAGE, 0x48); }

    inline const command_t set_sel_time(void)
    { return std::make_pair(NETFUN_STORAGE, 0x49); }

    inline const command_t read_fru_data(void)
    { return std::make_pair(NETFUN_STORAGE, 0x11); }

    inline const command_t write_fru_data(void)
    { return std::make_pair(NETFUN_STORAGE, 0x12); }

    inline const command_t get_sel_info(void)
    { return std::make_pair(NETFUN_STORAGE, 0x40); }

    inline const command_t reserve_sel(void)
    { return std::make_pair(NETFUN_STORAGE, 0x42); }

    inline const command_t add_sel(void)
    { return std::make_pair(NETFUN_STORAGE, 0x44); }

    inline const command_t partial_add_esel(void)
    { return std::make_pair(NETFUN_IBM, 0xf0); }

    // event messages
    inline const command_t platform_event(void)
    { return std::make_pair(NETFUN_SENSOR, 0x02); }

    // Sensor messages
    inline const command_t set_sensor_reading(void)
    { return std::make_pair(NETFUN_SENSOR, 0x30); }

    inline const command_t get_sensor_reading(void)
    { return std::make_pair(NETFUN_SENSOR, 0x2D); }

    inline const command_t get_sensor_type(void)
    { return std::make_pair(NETFUN_SENSOR, 0x2F); }

    // OEM Messages
    inline const command_t power_off(void)
    { return std::make_pair(NETFUN_IBM, 0x04); }

    inline const command_t pnor_request(void)
    { return std::make_pair(NETFUN_IBM, 0x07); }

    inline const command_t pnor_response(void)
    { return std::make_pair(NETFUN_IBM, 0x08); }

    inline const command_t hiomap_event(void)
    { return std::make_pair(NETFUN_IBM, 0x0f); }

    // Used to get dcmi capabilities
    inline const command_t get_dcmi_capability_info(void)
    { return std::make_pair(NETFUN_GRPEXT, 0x01); }

    // This is a dcmi message used to request the
    // user defined power limit from the BMC.
    inline const command_t get_power_limit(void)
    { return std::make_pair(NETFUN_GRPEXT, 0x03); }

    // Some helper messages
    // Used to create an empty message for reception
    inline const command_t no_command(void)
    { return std::make_pair(NETFUN_NONE, 0x00); }

    // This is a message used only for testing. The ipmid responder
    // will drop this message so we can test timeouts.
    inline const command_t test_drop(void)
    { return std::make_pair(NETFUN_APP, 0x3e); }

    // IPMI PNOR
    inline const command_t pnor_hiomap_request(void)
    { return std::make_pair(NETFUN_IBM, 0x5a); }

    // Efficient comparator to see if the message is a pnor hiomap request
    inline bool is_pnor_req( uint8_t i_netfun, uint8_t i_cmd )
    {
        return (((i_netfun == NETFUN_IBM) ||
                 (i_netfun == gen_resp_netfn(NETFUN_IBM))) //response
                &&
                (i_cmd == 0x5a));
    }


    /**
     * Send message asynchronously
     * @param[in] i_cmd, the network function and command
     * @param[in] i_len, the length of the buffer
     * @param[in] i_data, the buffer - must be new'd
     * @param[in] i_type, the message type EVENT/ASYNC- defaults to ASYNC
     * @example uint8_t* data = new uint8_t[length];
     * @warning do *not* delete data, the resource provider will do that.
     *
     * @return errlHndl_t, NULL on success
     */
    errlHndl_t send(const command_t& i_cmd,
                    const size_t i_len,
                    uint8_t* i_data,
                    message_type i_type = TYPE_ASYNC);

    /**
     * Send message synchronously
     * @param[in] i_cmd, the command and network function
     * @param[out] o_completion_code,  the completion code
     * @param[in,out] io_len, the length of the buffer
     * @param[in] i_data, the buffer - must be new'd
     * @example uint8_t* data = new uint8_t[length];
     * @example delete[] data;
     *
     * @return errlHndl_t, NULL on success
     */
    errlHndl_t sendrecv(const command_t& i_cmd,
                        completion_code& o_completion_code,
                        size_t& io_len, uint8_t*& io_data);

    /**
     * Synchronously send an event
     * @param[in] i_sensor_type, the sensor type
     * @param[in] i_sensor_num, the sensor number
     * @param[in] i_assertion, bool true is assert, false is deassert.
     * @param[in] i_type, event type
     * @param[out] o_completion_code, completion code
     * @param[in] i_len, number of data bytes (1-3)
     * @param[in] i_data, data bytes
     *
     * @return errlHndl_t, NULL on success
     */
    errlHndl_t send_event(const uint8_t i_sensor_type,
                          const uint8_t i_sensor_number,
                          const bool i_assertion,
                          const uint8_t i_type,
                          completion_code& o_completion_code,
                          const size_t i_len,
                          uint8_t* i_data);

    /**
     * Register a queue to receive an IPMI SEL.
     *
     * @param[in] i_cmd, the SEL command
     * @param[in] i_msgq, the message queue on which to send the SEL
     */
    void register_for_event(const IPMI::command_t& i_cmd,
                            const msg_q_t& i_msgq);

    /**
     * Get the max buffer size
     * @param void
     *
     * @return the maximum space allowed for data, per message
     * (max message for the transport - the header size)
     */
    size_t max_buffer(void);

    /**
     * Structure to return BMC/IPMI information in
     */
    struct BmcInfo_t
    {
        uint64_t bulkTransferLpcBaseAddr; //< Base address of the bulk transfer
                            //  LPC bus. Relative to the IO space on the LPC
        uint32_t bulkTransferSize; //< Size of bulk transfer device address
                                   //  space on the LPC bus
        uint8_t chipVersion; //< ML2 chip version
        uint8_t smsAttnInterrupt; //< SMS attention interrupt number
        uint8_t bmcToHostInterrupt; //< BMC to Host response interrupt
        char bmcVendor[32]; //< BMC vendor string. AMI, Aten or OpenBmc
    };

    /**
     * Retrieve some information about the BMC and the connection
     * we have to it.
     *
     * @return Structure of BMC data
     */
    BmcInfo_t getBmcInfo(void);


}; // end namespace IPMI

#endif
