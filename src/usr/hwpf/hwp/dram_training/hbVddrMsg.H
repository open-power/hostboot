/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/hbVddrMsg.H $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
#include <hwpf/hwpf_reasoncodes.H>

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
     * @struct hwsvPowrVmemRequest_t
     *
     * @brief structure to contain the Vmem Voltage rail ID and 
     *        its corresponding voltage
     *
     */
    struct hwsvPowrVmemRequest_t
    {
        TARGETING::ATTR_VMEM_ID_type VmemId;
        TARGETING::ATTR_MSS_VOLT_type Voltage;
        
        hwsvPowrVmemRequest_t()
        {
            VmemId=0x0;
            Voltage=0;
        }
    }__attribute__ ((packed));

    /**
     * @struct hwsvPowrVmemReply_t
     *
     * @brief structure to contain the Vmem Voltage rail ID and 
     *        its corresponding errorlog plid from the powr function
     *        call
     *
     */
    struct hwsvPowrVmemReply_t
    {
        TARGETING::ATTR_VMEM_ID_type VmemId;
        uint32_t plid;
    
        hwsvPowrVmemReply_t()
        {
            VmemId=0x0;
            plid=0x0;
        }
    }__attribute__ ((packed));

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
    };

    /** 
     * @brief typedefs for containers for structures
     */
    typedef std::vector<hwsvPowrVmemReply_t> ResponseContainer;
    typedef std::vector<hwsvPowrVmemRequest_t> RequestContainer;

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
      *  @brief  Uses the internal mailbox to send a message to the FSP
      *
      *
      *  @par Detailed Description:
      *          This funciton will create the request message by 
      *          going through the attributes and correlating the 
      *          VID and Voltage into the final message for all the 
      *          VIDs in the system
      *
      *  @param[in/out] io_request
      *             Contains the voltage and VID pairs to be passed
      *             to hwsvd on the FSP. 
      *
      *  @return     None
    */  
    void createVddrData(RequestContainer& io_request)const;

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
    errlHndl_t sendMsg(uint32_t i_msgType) const;


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
     * @param[out] i_passed indicates if powr function succeeded or failed on the
     *               FSP.
     *
     * @return     errlHndl_t
     *              return errl ==  NULL  -> success
     *              return errl !=  NULL  -> failure
     */
    errlHndl_t processVDDRmsg(msg_t* i_recvMsg)const;

     /**
     * @brief function to create error logs for errors that occured in FSP side
     *
     * @param[in/out] io_err.  Error log to generate indicating that an error has
     *                    has occured on HB or in the powr messages.  This error
     *                    should stop the IPL from processing further.
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
