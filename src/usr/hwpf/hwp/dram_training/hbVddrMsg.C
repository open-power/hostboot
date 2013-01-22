/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/hbVddrMsg.C $                  */
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
#include <sys/task.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/mm.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <trace/interface.H>
#include <trace/trace.H>
#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>

#include <hbVddrMsg.H>
#include <initservice/initserviceif.H>
#include <pnor/pnorif.H>
#include <fapi.H>


using namespace ERRORLOG;

using namespace TARGETING;

// Trace definition
trace_desc_t* g_trac_volt = NULL;
TRAC_INIT(&g_trac_volt, "HB_VDDR", 1024);

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::HBVddrMsg()
///////////////////////////////////////////////////////////////////////////////
HBVddrMsg::HBVddrMsg()
{
    TRACDCOMP( g_trac_volt, ENTER_MRK "HBVddrMsg::HBVddrMsg()" );
    TRACDCOMP( g_trac_volt, EXIT_MRK "HBVddrMsg::HBVddrMsg()" );

};

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::~HBVddrMsg()
///////////////////////////////////////////////////////////////////////////////
HBVddrMsg::~HBVddrMsg()
{
    TRACDCOMP( g_trac_volt, ENTER_MRK "HBVddrMsg::~HBVddrMsg()" );
    TRACDCOMP( g_trac_volt, EXIT_MRK "HBVddrMsg::~HBVddrMsg()" );
};


///////////////////////////////////////////////////////////////////////////////
// compareVids 
///////////////////////////////////////////////////////////////////////////////
bool compareVids(  HBVddrMsg::hwsvPowrVmemRequest_t i_req1,  
                HBVddrMsg::hwsvPowrVmemRequest_t i_req2)
{
    return( static_cast<uint16_t>(i_req1.VmemId) <
                static_cast<uint16_t>(i_req2.VmemId));
}

///////////////////////////////////////////////////////////////////////////////
// areVidEqual 
///////////////////////////////////////////////////////////////////////////////
bool areVidsEqual(HBVddrMsg::hwsvPowrVmemRequest_t i_req1,  
                HBVddrMsg::hwsvPowrVmemRequest_t i_req2)
{
    return( static_cast<uint16_t>(i_req1.VmemId) == 
                static_cast<uint16_t>(i_req2.VmemId));
}

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::createVddrData
///////////////////////////////////////////////////////////////////////////////
void HBVddrMsg::createVddrData(
                            RequestContainer& io_request) const
{
    TRACFCOMP( g_trac_volt, ENTER_MRK "HBVddrMsg::createVddrData" );

    //go through all the centaurs and gather the Voltage IDs and voltages
    io_request.clear();

    do{
    
        TARGETING::TargetHandleList l_membufTargetList;
        getAllChips(l_membufTargetList, TYPE_MEMBUF);
    
        TARGETING::Target* l_Target =NULL;

        hwsvPowrVmemRequest_t l_entry;

        for ( size_t i = 0; i < l_membufTargetList.size(); i++ )
        {
            l_Target=l_membufTargetList[i];

            TARGETING::ATTR_VMEM_ID_type l_VmemId=
                            l_Target->getAttr<TARGETING::ATTR_VMEM_ID>();
            TARGETING::ATTR_MSS_VOLT_type l_voltage = 
                            l_Target->getAttr<TARGETING::ATTR_MSS_VOLT>();  

            l_entry.VmemId = l_VmemId;
            l_entry.Voltage = static_cast<uint32_t>(l_voltage);

            io_request.push_back(l_entry);   
        }

        if (l_membufTargetList.size() >1)
        {
            //take out the duplicates Voltage IDs in io_request by first sorting and 
            //then removing the duplicates

            std::sort(io_request.begin(), io_request.end(), compareVids);

            std::vector<hwsvPowrVmemRequest_t>::iterator it;
            it=std::unique(io_request.begin(), io_request.end(), areVidsEqual);
            io_request.erase(it,io_request.end()); 
        }

    }while(0);
        
    TRACFCOMP( g_trac_volt, EXIT_MRK "HBVddrMsg::createVddrData" );
    return;
}

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::sendMsg
///////////////////////////////////////////////////////////////////////////////
errlHndl_t HBVddrMsg::sendMsg(uint32_t i_msgType) const
{
    errlHndl_t l_err = NULL;

    TRACFCOMP(g_trac_volt, ENTER_MRK "hbVddrMsg::sendMsg msg_type =0x%08X",i_msgType);

    do{
        
        RequestContainer l_request;
        
        if ( (i_msgType == HB_VDDR_ENABLE) || (i_msgType == HB_VDDR_DISABLE) )
        {
            createVddrData(l_request);
        }
        else
        {
            TRACFCOMP(g_trac_volt, ERR_MRK "hbVddrMsg::send msg with non-"
                      "valid msg type%08X",i_msgType);
            //generate errorLog;    
            // TODO RTC 62849 The reason code is in hbVddrMsg.H and does not
            // include a component ID. The component ID is essential to
            // distinguish errors between components. Error log reason codes and
            // module ids should also be in a file called <comp>reasoncodes.H.
            // This error causes the scanforsrcs parser to error out. I removed
            // '@' from the next line to stop the parser from seeing the tag.
            // Add '@' back after this is all fixed
            /*
             *   @errortype
             *   @moduleid      VDDR_SEND_MSG
             *   @reasoncode    INCORRECT_MSG_TYPE
             *   @userdata1     i_msgType 
             *   @userdata2     0
             *
             *   @devdesc       HB got an incorrect type message.  HB did not
             *                  provide the correct message type in the istep.
             *                  Userdata1 shows the message type passed in
             */
            createErrLog(l_err,VDDR_SEND_MSG,INCORRECT_MSG_TYPE,i_msgType);
            break;
        }


        
        
        size_t l_dataCount = l_request.size();
        uint32_t l_msgSize = l_dataCount*sizeof(hwsvPowrVmemRequest_t);


        //create the hb send msg.  the memory should be taken care of by mbox
        msg_t* l_msg =NULL;
        l_msg = msg_allocate();

        l_msg->type = i_msgType;        


        l_msg->data[0]=0;
        l_msg->data[1] =l_msgSize;
    
        TRACFCOMP(g_trac_volt, INFO_MRK "hbVddrMsg::l_dataCount=%d,l_msgSize=%d",l_dataCount,l_msgSize);
        void* l_data=NULL;
        l_data = malloc(l_msgSize);
       
        hwsvPowrVmemRequest_t* l_ptr = reinterpret_cast<hwsvPowrVmemRequest_t*>(l_data);
        
        for (size_t j =0; j<l_dataCount; j++)
        {
            l_ptr->VmemId=l_request.at(j).VmemId;
            l_ptr->Voltage=l_request.at(j).Voltage;

            TRACFCOMP(g_trac_volt, ENTER_MRK "hbVddrMsg::sendMsg "
                     "l_ptr->VmemId=0x%04X,l_ptr->Voltage=%d, j=%d",
                      l_ptr->VmemId, l_ptr->Voltage,j);

            l_ptr++;
        }

        l_msg->extra_data = l_data;

        TRACFBIN(g_trac_volt, "l_data", l_data, l_msgSize);
        l_err = MBOX::sendrecv( MBOX::FSP_VDDR_MSGQ, l_msg );
        if (l_err)
        {
            TRACFCOMP(g_trac_volt, ERR_MRK "Failed sending VDDR message to FSP");
    
            if (l_msg->extra_data!=NULL)
            {
                free(l_msg->extra_data);
            }
            if (l_msg)
            {
                msg_free(l_msg);
            }
        }
        else
        {
            l_err=processMsg(l_msg);
        }


    }while(0);

    TRACFCOMP(g_trac_volt, EXIT_MRK "hbEnableVddr::sendMsg");
    return l_err;
}


///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::processVDDRmsg
///////////////////////////////////////////////////////////////////////////////
errlHndl_t  HBVddrMsg::processVDDRmsg(msg_t* i_recvMsg) const
{
    TRACFCOMP(g_trac_volt, ENTER_MRK "HBVddrMsg::processVDDRmsg");
    errlHndl_t l_errLog = NULL;
    //check to see if an error occurred from the powr Enable/Disable functions
    //and is inside the message

    uint32_t l_msgSize = i_recvMsg->data[1];
    uint16_t l_elementCount = l_msgSize/sizeof(hwsvPowrVmemReply_t);
    const uint8_t* l_extraData = NULL;
    l_extraData=static_cast<uint8_t*>(i_recvMsg->extra_data);

    do{
        if (l_extraData==NULL)
        {
            //an error occred in obtaining the extra data from the response msg 
            TRACFCOMP( g_trac_volt, ERR_MRK "HBVddrMsg::processVDDRmsg: l_extraData = NULL");
            //create an errorlog
            // TODO RTC 62849 The reason code is in hbVddrMsg.H and does not
            // include a component ID. The component ID is essential to
            // distinguish errors between components. Error log reason codes and
            // module ids should also be in a file called <comp>reasoncodes.H.
            // This error causes the scanforsrcs parser to error out. I removed
            // '@' from the next line to stop the parser from seeing the tag.
            // Add '@' back after this is all fixed
            /*
            *   @errortype
            *   @moduleid      VDDR_PROC_VDDR_MSG
            *   @reasoncode    VDDR_EMPTY_MSG
            *   @userdata1     0
            *   @userdata2     0
            *
            *   @devdesc       The hwsv returned a message where the extra data 
            *                  was null.  This should not happen so need to 
            *                  tell HostBoot to stop the ipl
            */
            createErrLog(l_errLog,VDDR_PROC_VDDR_MSG,VDDR_EMPTY_MSG);
            break;
        }
        TARGETING::ATTR_VMEM_ID_type l_VmemId =0x0;
        uint32_t l_errPlid =0x0;

        TRACFCOMP( g_trac_volt, INFO_MRK "HBVddrMsg::processVDDRmsg: "
                    "l_elementCount=%d, l_msgSize =%d", 
                    l_elementCount, l_msgSize);
        const hwsvPowrVmemReply_t* l_ptr= 
                    reinterpret_cast<const hwsvPowrVmemReply_t*>(l_extraData);

        for (size_t i=0; i<l_elementCount; i++)
        {
            l_VmemId = l_ptr->VmemId;
            l_errPlid = l_ptr->plid;

            TRACFCOMP( g_trac_volt, INFO_MRK "HBVddrMsg::processVDDRmsg: "
                      "l_VmemId=0x%08X, l_errPlid=0x%08X", l_VmemId,l_errPlid);
            if (l_errPlid ==0x0)
            {
                TRACFCOMP( g_trac_volt, INFO_MRK "HBVddrMsg::processVDDRmsg: no plid "
                          "error found for l_VmemId=0x%08X", l_VmemId);
            }
            else
            {
                //error occured so break out of the loop and indicate an error was present
                TRACFCOMP( g_trac_volt, ERR_MRK "HBVddrMsg::processVDDRmsg: error occured "
                            "on the powr function called in hwsv");
                //create an errorlog
                // TODO RTC 62849 The reason code is in hbVddrMsg.H and does not
                // include a component ID. The component ID is essential to
                // distinguish errors between components. Error log reason codes and
                // module ids should also be in a file called <comp>reasoncodes.H.
                // This error causes the scanforsrcs parser to error out. I removed
                // '@' from the next line to stop the parser from seeing the tag.
                // Add '@' back after this is all fixed
                /*
                *   @errortype
                *   @moduleid      VDDR_PROC_VDDR_MSG
                *   @reasoncode    VDDR_POWR_ERR
                *   @userdata1     l_errPlid 
                *   @userdata2     0
                *
                *   @devdesc       The hwsv returned a message where there was an error
                *                  when the powr function was called.  userdata1 contains
                *                  the errorlog plid from hwsv generated by the powr function
                */
                createErrLog(l_errLog,VDDR_PROC_VDDR_MSG,VDDR_POWR_ERR,l_errPlid);
                l_errLog->plid(l_errPlid);
                break;
            }

            l_ptr++;
        }   
    }while(0);
    TRACFCOMP(g_trac_volt, EXIT_MRK "HBVddrMsg::processVDDRmsg");
    return l_errLog;    
}

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::processMsg
///////////////////////////////////////////////////////////////////////////////
errlHndl_t HBVddrMsg::processMsg(msg_t* i_Msg) const
{
    TRACFCOMP(g_trac_volt, ENTER_MRK "HBVddrMsg::processMsg");
    errlHndl_t l_errLog = NULL;

    do
    {
        //check to see if the data[0] =0 or contains a value.  A value of 0 means its a
        //response to a request and a value not equal to zero  means that its an error coming back  

        uint16_t l_value1=i_Msg->data[0];
        if (l_value1 ==0)
        {
            //process a response to a request
        
            uint32_t l_msgType =i_Msg->type;
            TRACFCOMP( g_trac_volt, INFO_MRK "HBVddrMsg::processMsg l_msgType=x%08X",l_msgType );
            if ( (l_msgType == HB_VDDR_ENABLE) || (l_msgType == HB_VDDR_DISABLE) )
            {
                //process a VDDR message    
                l_errLog=processVDDRmsg(i_Msg);
                if (l_errLog)
                {
                    break;
                }   

            }
            else
            {
                TRACFCOMP( g_trac_volt, ERR_MRK "HBVddrMsg::processMsg recv'd a non valid type");
                //generate errorLog;    
                // TODO RTC 62849 The reason code is in hbVddrMsg.H and does not
                // include a component ID. The component ID is essential to
                // distinguish errors between components. Error log reason codes and
                // module ids should also be in a file called <comp>reasoncodes.H.
                // This error causes the scanforsrcs parser to error out. I removed
                // '@' from the next line to stop the parser from seeing the tag.
                // Add '@' back after this is all fixed
                /*
                 *   @errortype
                 *   @moduleid      VDDR_PROC_MSG
                 *   @reasoncode    INCORRECT_MSG_TYPE
                 *   @userdata1     0
                 *   @userdata2     0
                 *
                 *   @devdesc       HB got an incorrect type message.  HWSV did not populate 
                 *                  the message correctly or mbox corrupted the message
                 */
                createErrLog(l_errLog,VDDR_PROC_MSG,INCORRECT_MSG_TYPE);
            }
        }
        else
        {
            //an error occurred so should stop the IPL
            TRACFCOMP( g_trac_volt, ERR_MRK "HBVddrMsg::RecvMsgHndlr recv'd an error message" );
            //generate an errorlog
            // TODO RTC 62849 The reason code is in hbVddrMsg.H and does not
            // include a component ID. The component ID is essential to
            // distinguish errors between components. Error log reason codes and
            // module ids should also be in a file called <comp>reasoncodes.H.
            // This error causes the scanforsrcs parser to error out. I removed
            // '@' from the next line to stop the parser from seeing the tag.
            // Add '@' back after this is all fixed
            /*
             *   @errortype
             *   @moduleid      VDDR_PROC_MSG
             *   @reasoncode    VDDR_ERROR_MSG
             *   @userdata1     error PLID from hwsv 
             *   @userdata2     0
             *
             *   @devdesc       The hwsv found an error while processing the 
             *                  message so it sent an error message back to
             *                  indicate to HostBoot to stop the IPL. 
             *                  Userdata1 will have the error PLID from hwsv's
             *                  errorlog
             */

            createErrLog(l_errLog,VDDR_PROC_MSG,VDDR_ERROR_MSG,i_Msg->data[1]);
            l_errLog->plid(i_Msg->data[1]);
        }

    }while(0);

    TRACFCOMP(g_trac_volt, EXIT_MRK "HBVddrMsg::processMsg");
    return l_errLog;    
}

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::createErrLog
///////////////////////////////////////////////////////////////////////////////
void HBVddrMsg::createErrLog(errlHndl_t& io_err, 
                             VddrModuleId i_mod, 
                             VddrReasonCode i_rc,
                             uint32_t i_userData1) const
{
    if (io_err == NULL)
    {
        io_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                i_mod,
                                i_rc,
                                i_userData1,
                                0);

    }   
    return;
}


