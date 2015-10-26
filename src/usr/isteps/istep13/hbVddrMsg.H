/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/hbVddrMsg.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

#ifndef __HB_VDDR_MSG_H
#define __HB_VDDR_MSG_H

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
class HBVddrMsg;

/**
 *  @brief  HBVddrMsg
 *  This class provides interfaces to send and process messages to and from
 *  hwsv with respect to powr.  It also indicates when to stop the IPL via
 *  errorlogs
 */
class HBVddrMsg
{

public:

    /**
     *  @brief Enum specifying a memory voltage domain type
     */
    enum MEM_VOLTAGE_DOMAIN
    {
        // For unknown / uninitialized values
        MEM_VOLTAGE_DOMAIN_UNKNOWN = 0x00,

        // Valid values
        MEM_VOLTAGE_DOMAIN_VDD  = 0x01,
        MEM_VOLTAGE_DOMAIN_AVDD = 0x02,
        MEM_VOLTAGE_DOMAIN_VCS  = 0x03,
        MEM_VOLTAGE_DOMAIN_VPP  = 0x04,
        MEM_VOLTAGE_DOMAIN_VDDR = 0x05,

        // Good range markers - Need to be adjusted if the above change
        MEM_VOLTAGE_DOMAIN_MIN_VALUE = MEM_VOLTAGE_DOMAIN_VDD,
        MEM_VOLTAGE_DOMAIN_MAX_VALUE = MEM_VOLTAGE_DOMAIN_VDDR,
    };

    /**
     *  @struct hwsvPowrMemVoltDomainRequest_t
     *
     *  @brief Structure containing a memory voltage domain type, ID, and
     *      voltage in mV
     */
    struct hwsvPowrMemVoltDomainRequest_t
    {
        MEM_VOLTAGE_DOMAIN            domain;
        TARGETING::ATTR_VMEM_ID_type  domainId;
        TARGETING::ATTR_MSS_VOLT_type voltageMillivolts;

        hwsvPowrMemVoltDomainRequest_t()
            : domain(MEM_VOLTAGE_DOMAIN_UNKNOWN),
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
        MEM_VOLTAGE_DOMAIN           domain;
        TARGETING::ATTR_VMEM_ID_type domainId;
        uint32_t                     plid;

        hwsvPowrMemVoltDomainReply_t()
            : domain(MEM_VOLTAGE_DOMAIN_UNKNOWN),
              domainId(0x0000),
              plid(0x00000000)
        {
        }

    } __attribute__ ((packed));

    /**
     * @enum VDDR_MSG_TYPE
     *
     * @brief  Message enum to determine how the msg should be processed
     *
     */
    enum VDDR_MSG_TYPE
    {
        HB_VDDR_ENABLE = 0x40000041,
        HB_VDDR_DISABLE = 0x40000042,
        HB_VDDR_POST_DRAM_INIT_ENABLE = 0x40000043,
    };

    /**
     * @brief typedefs for containers for structures
     */
    typedef std::vector<hwsvPowrMemVoltDomainReply_t> ResponseContainer;
    typedef std::vector<hwsvPowrMemVoltDomainRequest_t> RequestContainer;

    /**
     * @brief Default constructor
     */
    HBVddrMsg();

    /**
     * @brief   Destructor
     *
     * Releases all resources owned by the handle.
     *
     * @return  None
     *
     */
    ~HBVddrMsg();

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
              VDDR_MSG_TYPE     i_requestType,
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
      *             HBVddrMsg::VDDR_MSG_TYPE passed in to define the
      *             message policy.
      *
      *  @return     errlHndl_t
      *              return errl ==  NULL  -> success
      *              return errl !=  NULL  -> failure
     */
    errlHndl_t sendMsg(VDDR_MSG_TYPE i_msgType) const;

private:

    /**
     *  @brief For a given memory buffer and memory voltage domain, adds a
     *      voltage programming request record to the input list
     *
     *  @tparam OFFSET_DISABLEMENT_ATTR
     *      ID of the attribute to read to determine if a given memory voltage
     *      domain offset voltage should be applied or not.  Should be one of
     *      the TARGETING::ATTR_*_ID attribute IDs, where * = VMEM, VPP, VCS,
     *      VDD, or AVDD.
     *
     *  @tparam VOLTAGE_ATTR_WHEN_OFFSET_ENABLED
     *      ID of the attribute which should be read to obtain the given memory
     *      voltage domain's offset voltage to program.  In this case the offset
     *      voltage acts as the actual voltage.  Should be one of the
     *      TARGETING::ATTR_MEM_*_OFFSET_MILLIVOLTS attribute IDs, where
     *      * = VMEM, VPP, VCS, VDD, or AVDD.  Only used when the memory voltage
     *      domain's offset voltage is enabled.  Otherwise the parameter, below,
     *      controls how the voltage, if any, is programmed.
     *
     *  @tparam VOLTAGE_ATTR_WHEN_OFFSET_DISABLED
     *      ID of the attribute which should be read to obtain the given memory
     *      voltage domain's voltage to program.  Only applied if the memory
     *      voltage domain's offset voltage is disabled -AND- the attribute ID
     *      is different than the one given by
     *      VOLTAGE_ATTR_WHEN_OFFSET_ENABLED.   Should be one of
     *      TARGETING::ATTR_VPP_BASE, TARGETING::ATTR_MSS_VOLT, or
     *      TARGETING::ATTR_MEM_*_OFFSET_MILLIVOLTS where * = VPP, AVDD, or
     *      VCS.
     *
     *  @note: This function does not ensure that all permutations of the above
     *    template parameters are valid.
     *
     *  @param[in] i_pMembuf
     *      Handle to a memory buffer target.  Function will assert if NULL or
     *      not a memory buffer target.
     *
     *  @param[in,out] io_domains
     *      On input, an existing list of 0 or more voltage domain records.  On
     *      output, that same list with up to 1 additional voltage domain
     *      record.
     *
     *  @return N/A
     */
    template<
        const TARGETING::ATTRIBUTE_ID OFFSET_DISABLEMENT_ATTR,
        const TARGETING::ATTRIBUTE_ID VOLTAGE_ATTR_WHEN_OFFSET_ENABLED,
        const TARGETING::ATTRIBUTE_ID VOLTAGE_ATTR_WHEN_OFFSET_DISABLED,
        const TARGETING::ATTRIBUTE_ID VOLTAGE_DOMAIN_ID_ATTR >
    void addMemoryVoltageDomains(
        const TARGETING::Target* const     i_pMembuf,
              HBVddrMsg::RequestContainer& io_domains) const;

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
    errlHndl_t processVDDRmsg(msg_t* i_recvMsg)const;

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


#endif
