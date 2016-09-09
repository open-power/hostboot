/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/hbToHwsvVoltageMsg.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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

#ifndef __HB_VOLT_MSG_H
#define __HB_VOLT_MSG_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <sys/task.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mm.h>
#include <sys/msg.h>
#include <sys/sync.h>
#include <stdint.h>

#include <util/singleton.H>
#include <errl/errlentry.H>
#include <kernel/timemgr.H>
#include <hbotcompid.H>
#include <hwas/common/hwasCallout.H>
#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <isteps/hwpf_reasoncodes.H>
#include <attributeenums.H>

/*****************************************************************************/
// Forward class declarations
/*****************************************************************************/
class HBToHwsvVoltageMsg;

/**
 *  @brief  HBToHwsvVoltageMsg
 *  This class provides interfaces to send and process messages to and from
 *  hwsv with respect to powr.  It also indicates when to stop the IPL via
 *  errorlogs
 */
class HBToHwsvVoltageMsg
{

public:

    /**
     *  @brief Enum specifying a memory voltage domain type
     */
    enum VOLTAGE_DOMAIN
    {
        // For unknown / uninitialized values
        VOLTAGE_DOMAIN_UNKNOWN = 0x00,

        // Valid values
        VOLTAGE_DOMAIN_MEM_VDD       = 0x01,
        VOLTAGE_DOMAIN_MEM_AVDD      = 0x02,
        VOLTAGE_DOMAIN_MEM_VCS       = 0x03,
        VOLTAGE_DOMAIN_MEM_VPP       = 0x04,
        VOLTAGE_DOMAIN_MEM_VDDR      = 0x05,  // aka VMEM
        VOLTAGE_DOMAIN_NEST_VDD      = 0x06,
        VOLTAGE_DOMAIN_NEST_VDN      = 0x07,
        VOLTAGE_DOMAIN_NEST_VCS      = 0x08,
        VOLTAGE_DOMAIN_NEST_VIO      = 0x09,
        VOLTAGE_DOMAIN_NEST_VDDR     = 0x0A,

        // Good range markers - Need to be adjusted if the above change
        VOLTAGE_DOMAIN_MIN_VALUE = VOLTAGE_DOMAIN_MEM_VDD,
        VOLTAGE_DOMAIN_MAX_VALUE = VOLTAGE_DOMAIN_NEST_VDDR,
    };

    /**
     *  @struct hwsvPowrMemVoltDomainRequest_t
     *
     *  @brief Structure containing a memory voltage domain type, ID, and
     *      voltage in mV
     */
    struct hwsvPowrMemVoltDomainRequest_t
    {
        VOLTAGE_DOMAIN      domain;
        uint16_t            domainId;
        uint32_t            voltageMillivolts;

        hwsvPowrMemVoltDomainRequest_t()
            : domain(VOLTAGE_DOMAIN_UNKNOWN),
              domainId(0x0000),
              voltageMillivolts(0x00000000)
        {
        }

    } __attribute__ ((packed));

    /**
     *  @struct hwsvPowrMemVoltDomainReply_t
     *
     *  @brief Structure containing a memory voltage domain type, ID, and error
     *      log PLID as returned by the FSP POWR function when it tried to set
     *      the implied voltage regulator to the specified voltage.
     */
    struct hwsvPowrMemVoltDomainReply_t
    {
        VOLTAGE_DOMAIN        domain;
        uint16_t              domainId;
        uint32_t              plid;

        hwsvPowrMemVoltDomainReply_t()
            : domain(VOLTAGE_DOMAIN_UNKNOWN),
              domainId(0x0000),
              plid(0x00000000)
        {
        }

    } __attribute__ ((packed));

    /**
     * @enum VOLT_MSG_TYPE
     *
     * @brief  Message enum to determine how the msg should be processed
     *
     */
    enum VOLT_MSG_TYPE
    {
        HB_VOLT_ENABLE = 0x40000041,
        HB_VOLT_DISABLE = 0x40000042,
        HB_VOLT_POST_DRAM_INIT_ENABLE = 0x40000043,
    };

    /**
     * @brief typedefs for containers for structures
     */
    typedef std::vector<hwsvPowrMemVoltDomainReply_t> ResponseContainer;
    typedef std::vector<hwsvPowrMemVoltDomainRequest_t> RequestContainer;

    /**
     * @brief Default constructor
     */
    HBToHwsvVoltageMsg();

    /**
     * @brief   Destructor
     *
     * Releases all resources owned by the handle.
     *
     * @return  None
     *
     */
    ~HBToHwsvVoltageMsg();

    /**
     *  @brief Accumulates memory voltage domain type/ID/voltage records and
     *      appends them to the provided container
     *
     *  @par Detailed Description:
     *      This function will accumulates memory voltage domain type/ID/voltage
     *      records and appends them to the provided container.  If an "enable"
     *      request, adds records from all memory voltage domains.  If a
     *      "disable" message, only adds records from the VDDR (a.k.a. VMEM)
     *      voltage domain.
     *
     *  @param[in] i_requestType
     *      Type of data accumulation request
     *
     *  @param[in/out] io_request
     *      On input, a container to hold the memory voltage domain programming
     *      records.  On output, the container holds the relevant records.
     *
     *  @return N/A
     */
    void createVddrData(
              VOLT_MSG_TYPE     i_requestType,
              RequestContainer& io_request) const;

    /**
      *  @brief  Uses the internal mailbox to send a message to the FSP
      *
      *
      *  @par Detailed Description:
      *          This function will call into mailbox FSP code using the
      *          FSP_VDDR_MSGQ as the message queue..
      *
      *  @param[in] i_msgType
      *             HBToHwsvVoltageMsg::VDDR_MSG_TYPE passed in to define the
      *             message policy.
      *
      *  @return     errlHndl_t
      *              return errl ==  NULL  -> success
      *              return errl !=  NULL  -> failure
     */
    errlHndl_t sendMsg(VOLT_MSG_TYPE i_msgType) const;


    /**
     * @brief Appropriately formats the request data and sends it to the FSP
     *
     * @param[in]     i_requests - A vector of requests
     * @param[in]     i_msgType - the type of message we are sending
     *
     * @ return errlHndl_t
     *          return errl == NULL  -> success
     *          return errl != NULL  -> failure
     */
    errlHndl_t sendRequestData( RequestContainer & i_requests,
                                VOLT_MSG_TYPE i_msgType ) const;



private:

    /**
     *  @brief For a given mcbist and memory voltage domain, adds a
     *      voltage programming request record to the input list
     *
     *  @tparam MSS_DOMAIN_PROGRAM
     *      ID of the attribute to read to determine how we program this domain.
     *      Value of the attribute should be one of these:
     *      MSS_PROGRAM_TYPE::POWERON = no additional programming necessary,
     *      MSS_PROGRAM_TYPE::STATIC  = use static value,
     *      MSS_PROGRAM_TYPE::DYNAMIC = use dynamic value
     *
     *  @tparam VOLTAGE_ATTR_STATIC
     *      ID of the attribute which should be read to obtain the given memory
     *      voltage domain's offset voltage to program.  In this case the offset
     *      voltage acts as the actual voltage.  Should be one of the
     *      TARGETING::ATTR_MSS_VOLT_*_MILLIVOLTS attribute IDs, where
     *      * = VMEM, VPP, VCS, VDD, or AVDD.  Only used when the memory voltage
     *      domain's programming equals static.  Otherwise the parameter, below,
     *      controls how the voltage, if any, is programmed.
     *
     *  @tparam VOLTAGE_ATTR_DYNAMIC
     *      ID of the attribute which should be read to obtain the given memory
     *      voltage domain's voltage to program.  Only applied if the memory
     *      voltage domain's programming equals dynamic. Should be one of the
     *      TARGETING::ATTR_MSS_VOLT_*_OFFSET_MILLIVOLTS attribute IDs,
     *      where * = VMEM, VPP, VCS, VDD, or AVDD.
     *
     *  @note: This function does not ensure that all permutations of the above
     *    template parameters are valid.
     *
     *  @param[in] i_pMcbist
     *      Handle to a MCBIST target.  Function will assert if NULL or
     *      not a MCBIST target.
     *
     *  @param[in,out] io_domains
     *      On input, an existing list of 0 or more voltage domain records.  On
     *      output, that same list with up to 1 additional voltage domain
     *      record.
     *
     *  @return N/A
     */
    template<
        const TARGETING::ATTRIBUTE_ID MSS_DOMAIN_PROGRAM,
        const TARGETING::ATTRIBUTE_ID VOLTAGE_ATTR_STATIC,
        const TARGETING::ATTRIBUTE_ID VOLTAGE_ATTR_DYNAMIC,
        const TARGETING::ATTRIBUTE_ID VOLTAGE_DOMAIN_ID_ATTR >
    void addMemoryVoltageDomains(
        const TARGETING::Target* const     i_pMcbist,
              HBToHwsvVoltageMsg::RequestContainer& io_domains) const;

protected:

     /**
     * @brief function to process a generic message recieved from the FSP
     *
     * @param[in] i_recvMsg The message from the message queue.
     *               It contains the response data from the FSP
     *
     * @return     errlHndl_t
     *              return errl ==  NULL  -> success
     *              return errl !=  NULL  -> failure
     */
    errlHndl_t processMsg(msg_t* i_recvMsg) const;

     /**
     * @brief function to process a power Vmem message recieved from the FSP
     *
     * @param[in] i_recvMsg The message from the message queue.
     *               It contains the response data from the FSP
     *
     * @param[out] i_passed indicates if powr function succeeded or failed on
     *    the FSP.
     *
     * @return     errlHndl_t
     *              return errl ==  NULL  -> success
     *              return errl !=  NULL  -> failure
     */
    errlHndl_t processVOLTmsg(msg_t* i_recvMsg)const;

     /**
     * @brief function to create error logs for errors that occured in FSP side
     *
     * @param[in/out] io_err.  Error log to generate indicating that an error
     *     has has occured on HB or in the powr messages.  This error
     *     should stop the IPL from processing further.
     *
     * @param[in] i_mod. The module where the error occured
     *
     * @param[in] i_rc. The return code for the error that occured
     *
     * @return     None
     */
    void createErrLog(errlHndl_t& io_err,
                      fapi::hwpfModuleId i_mod,
                      fapi::hwpfReasonCode i_rc,
                      uint32_t i_userData1=0x0) const;


};

//External Interfaces
/**
 * @brief Send processor voltage rail data to HWSV
 * @return NULL | error handle on error
 */
errlHndl_t platform_set_nest_voltages();

#endif
