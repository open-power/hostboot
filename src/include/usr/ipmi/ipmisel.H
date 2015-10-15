/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ipmi/ipmisel.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#ifndef __IPMI_IPMISEL_H
#define __IPMI_IPMISEL_H

/**
 * @file ipmisel.H
 * @brief IPMI system error log transport definition
 */

#include <stdint.h>
#include <builtins.h>
#include <ipmi/ipmiif.H>
#include <sys/sync.h>


/**
 *
 */

namespace IPMISEL
{
    enum msg_type
    {
        MSG_SEND_ESEL,
        MSG_STATE_SHUTDOWN,
        MSG_LAST_TYPE = MSG_STATE_SHUTDOWN,
    };

    enum sel_size_constants
    {
        // size of the partial_add_esel request (command) data
        PARTIAL_ADD_ESEL_REQ = 7,

        // per MegaRAC SP-X spec
        // The size of the eSEL is configurable via PRJ
        //  it can be set to 2KB per eSEL packet.
        ESEL_MAX_SIZE = 2 * KILOBYTE,
    };

    /**
     * @brief Send the eSEL data to the BMC
     * @param[in] pointer to eSEL data
     * @param[in] size of eSEL data
     * @param[in] eid of errorlog for this eSEL (for ack)
     * @param[in] event_dir_type for this eSEL
     * @param[in] event_offset for this eSEL
     * @param[in] sensorType that caused the error/eSEL
     * @param[in] sensorNumber that caused the error/eSEL
     */
    void sendESEL(uint8_t* i_eselData, uint32_t i_dataSize,
                  uint32_t i_eid,
                  uint8_t i_eventDirType, uint8_t i_eventOffset,
                  uint8_t i_sensorType, uint8_t i_sensorNumber);

    // per IPMI Spec, section 32.1 SEL Event Records
    enum sel_record_type
    {
        record_type_system_event    = 0x02,
        record_type_ami_esel        = 0xDF,
    };

    enum sel_evm_format_version
    {
        format_ipmi_version_1_0 = 0x03,
        format_ipmi_version_2_0 = 0x04,
    };

    // sel_event_dir_type type, per section 42.1 of the IPMI spec
    // bit = 0 -> 0 is an assertion event
    // bits 1:7 describe the sensor type
    enum sel_event_dir_type
    {
        event_unspecified       = 0x00,
        event_threshhold        = 0x01,
        event_state             = 0x03,
        event_predictive        = 0x04,
        event_limit             = 0x05,
        event_performance       = 0x06,
        event_transition        = 0x07,
        sensor_specific         = 0x6f,
        event_OEM               = 0x70,
    };

    enum sel_event_data
    {
        event_data1_ami                         = 0xAA,
        event_data1_deasserted                  = 0x00,
        event_data1_asserted                    = 0x01,
        event_data1_trans_to_ok                 = 0x00,
        event_data1_trans_to_noncrit_from_ok    = 0x01,
        event_data1_trans_to_crit_from_less     = 0x02,
        event_data1_trans_to_non_recv_from_less = 0x03,
        event_data1_trans_to_non_crit_from_more = 0x04,
        event_data1_trans_to_crit_from_non_r    = 0x05,
        event_data1_trans_to_non_recoverable    = 0x06,
        event_data1_trans_monitor               = 0x07,
        event_data1_trans_informational         = 0x08,
        event_data1_invalid_offset              = 0xFF,
    };

    enum sel_generator_id
    {
        generator_id_ami        = 0x2000,
    };

    struct selRecord
    {
        // ID used for SEL Record access. The Record ID values 0000h and FFFFh
        // have special meaning in the Event Access commands and must not be
        // used as Record ID values for stored SEL Event Records.
        uint16_t recordID;

        // [7:0] - Record Type
        //  02h     = system event record
        //  C0h-DFh = OEM timestamped, bytes 8-16 OEM defined
        //  E0h-FFh = OEM non-timestamped, bytes 4-16 OEM defined
        uint8_t record_type;

        // Time when event was logged. LS byte first.
        uint32_t timestamp;

        // RqSA & LUN if event was generated from IPMB. Software ID if event was
        // generated from system software.
        //   Byte 1
        //   [7:1] - 7-bit I2C. Slave Address, or 7-bit system software ID
        //   [0]    0b = ID is IPMB Slave Address
        //          1b = system software ID
        //   Byte 2
        //   [7:4] - Channel number. Channel that event message was received over.
        //      0h if the event message was received via the system interface,
        //      primary IPMB, or internally generated by the BMC.
        //   [3:2] - reserved. Write as 00b.
        //   [1:0] - IPMB device LUN if byte 1 holds Slave Address. 00b otherwise.
        uint16_t generator_id;

        // Event Message format version
        //  (=04h for events in this specification,
        //    03h for IPMI v1.0 Event Messages.)
        uint8_t evm_format_version;

        // Sensor Type Code for sensor that generated the event
        uint8_t sensor_type;

        // Number of sensor that generated the event
        uint8_t sensor_number;

        // Event Dir
        //   [7 ]   0b = Assertion event.
        //          1b = Deassertion event.
        // Event Type
        //      Type of trigger for the event, e.g. critical threshold going high,
        //      state asserted, etc. Also indicates class of the event. E.g.
        //      discrete, threshold, or OEM. The Event Type field is encoded
        //      using the Event/Reading Type Code.
        //   [6:0] - Event Type Code
        uint8_t event_dir_type;

        uint8_t event_data1;
        uint8_t event_data2;
        uint8_t event_data3;

        // ctor
        selRecord():
            recordID(0),
            record_type(0),
            timestamp(0),
            generator_id(0),
            evm_format_version(0),
            sensor_type(0),
            sensor_number(0),
            event_dir_type(0),
            event_data1(0),
            event_data2(0),
            event_data3(0)
            { };

    } PACKED; // selRecord

    // local structure needed to pass data between sendESEL command and the sel
    // thread
    struct eselInitData
    {
        size_t dataSize;
        uint8_t eSel[sizeof(selRecord)];
        uint8_t *eSelExtra;

        // ctor
        eselInitData(selRecord* i_eSEL,
                  uint8_t* i_extraData, uint32_t i_dataSize)
        {
            dataSize = i_dataSize;
            memcpy(eSel,i_eSEL,sizeof(selRecord));
            eSelExtra = new uint8_t[i_dataSize];
            memcpy(eSelExtra, i_extraData, i_dataSize);
        }

        // dtor
        ~eselInitData()
        {
            delete eSelExtra;
        }
    };

    /**
     * @brief parse the msg and call send_esel to send the esel (handles if
     * the SEL reservation is lost)
     * @param[in] i_msg
     */
    void process_esel(msg_t *i_msg);

    /**
     * @brief do the actual ipmi calls to send the esel data to the bmc
     * @param[in] i_data  esel data
     * @param[in] o_err   any error generated during the send
     * @param[in] o_cc    ipmi completion code from last sendrecv
     */
    void send_esel(IPMISEL::eselInitData * i_data,
          errlHndl_t &o_err, IPMI::completion_code &o_cc);

} // namespace IPMISEL

#ifndef __HOSTBOOT_RUNTIME
class IpmiSEL
{
    public:

      /**
       * Thread start routine for the resource provider
       * @param[in] void* instance - 'this' instance to start.
       */
      static void* start(void* instance);

      /**
       * Default constructor
       */
      IpmiSEL(void);

      /**
       * Destructor
       */
      ~IpmiSEL(void);

      /**
       * @brief Get the message queue associated with this FRU
       * @param[in] void
       * @return, a msg_q_t which is the message queue
       */
      msg_q_t msgQueue(void) const
          { return iv_msgQ; }

    private:
      /**
       * Entry point for the SEL transport definition
       */
      void execute(void);

      msg_q_t           iv_msgQ;      //!< ipmi message queue
      barrier_t         iv_sync_start;

      //Disallow copying of this class.
      IpmiSEL& operator=(const IpmiSEL&);
      IpmiSEL(const IpmiSEL&);
};
#endif

#endif
