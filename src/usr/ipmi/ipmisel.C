/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmisel.C $                                      */
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
/**
 * @file ipmisel.C
 * @brief IPMI system error log transport definition
 */

#include "ipmisel.H"
#include "ipmiconfig.H"
#include <ipmi/ipmi_reasoncodes.H>

#include <sys/task.h>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>

#include <errl/errlmanager.H>

//Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"sel: "printf_string,##args)

/**
 * @brief Constructor
 */
IpmiSEL::IpmiSEL(void):
    iv_msgQ(msg_q_create())
{
    IPMI_TRAC(ENTER_MRK "IpmiSEL ctor");
    task_create(&IpmiSEL::start,NULL);
}

/**
 * @brief Destructor
 */
IpmiSEL::~IpmiSEL(void)
{
    msg_q_destroy(iv_msgQ);
}

void* IpmiSEL::start(void* unused)
{
    Singleton<IpmiSEL>::instance().execute();
    return NULL;
}

/**
 * @brief Entry point of the sel ipmi thread
 */
//@todo: RTC 119832
void IpmiSEL::execute(void)
{
    //Mark as an independent daemon so if it crashes we terminate.
    task_detach();

    // Register shutdown events with init service.
    //      Done at the "end" of shutdown processesing.
    //      This will flush out any IPMI messages which were sent as
    //      part of the shutdown processing. We chose MBOX priority
    //      as we don't want to accidentally get this message after
    //      interrupt processing has stopped in case we need intr to
    //      finish flushing the pipe.
    INITSERVICE::registerShutdownEvent(iv_msgQ, IPMISEL::MSG_STATE_SHUTDOWN,
                                       INITSERVICE::MBOX_PRIORITY);

    while(true)
    {
        msg_t* msg = msg_wait(iv_msgQ);

        const IPMISEL::msg_type msg_type =
            static_cast<IPMISEL::msg_type>(msg->type);

        // Invert the "default" by checking here. This allows the compiler
        // to warn us if the enum has an unhadled case but still catch
        // runtime errors where msg_type is set out of bounds.
        assert(msg_type <= IPMISEL::MSG_LAST_TYPE,
               "msg_type %d not handled", msg_type);

        switch(msg_type)
        {
            case IPMISEL::MSG_SEND_SEL:
                send_sel(msg);
                //done with msg
                msg_free(msg);
                break;

            case IPMISEL::MSG_STATE_SHUTDOWN:
                IPMI_TRAC(INFO_MRK "ipmisel shutdown event");

                //Respond that we are done shutting down.
                msg_respond(iv_msgQ, msg);
                break;
        };

    }
    IPMI_TRAC(EXIT_MRK "message loop");
    return;
}

/*
 * @brief Store either Record/Reserve ID from given data
 */
void storeReserveRecord(uint8_t* o_RData, uint8_t* i_data)
{
    o_RData[0] = i_data[0];
    o_RData[1] = i_data[1];
    return;
}

/*
 * @brief Create Partial Add Header from inputs
 */
void createPAddHeader(uint8_t* i_reserveID, uint8_t* i_recordID,
                               uint16_t i_offset, uint8_t i_isLastEntry,
                               uint8_t* o_header)
{
    o_header[0] = i_reserveID[0];
    o_header[1] = i_reserveID[1];
    o_header[2] = i_recordID[0];
    o_header[3] = i_recordID[1];
    o_header[4] = (uint8_t)(i_offset & 0x00FF);
    o_header[5] = (uint8_t)((i_offset & 0xFF00) >> 8);
    o_header[6] = i_isLastEntry;
    return;
}

/*
 * @brief Send sel msg
 */
void IpmiSEL::send_sel(msg_t *i_msg)
{
    IPMI_TRAC(ENTER_MRK "send_sel");

    selInitData *l_data = (selInitData*)(i_msg->extra_data);

    size_t eSELlen = i_msg->data[0];
    uint8_t* eSelData[] = {l_data->sel,l_data->eSel,l_data->eSelExtra};

    errlHndl_t err = NULL;
    IPMI::completion_code cc = IPMI::CC_UNKBAD;
    size_t len = 0;
    uint8_t* data = NULL;
    uint8_t reserveID[2] = {0,0};
    uint8_t recordID[2] = {0,0};
    do{
        err = IPMI::sendrecv(IPMI::reserve_sel(),cc,len,data);
        if(err)
        {
            IPMI_TRAC(ERR_MRK "error from reserve sel");
            break;
        }
        else if (cc != IPMI::CC_OK)
        {
            IPMI_TRAC(ERR_MRK "Failed to reserve sel, cc is %02x",cc);
            break;
        }
        storeReserveRecord(reserveID,data);

        delete [] data;

        len = SEL_LENGTH; //16 being the size of one SEL.
        cc = IPMI::CC_UNKBAD;
        data = new uint8_t[len];
        memcpy(data,eSelData[0],len);
        err = IPMI::sendrecv(IPMI::add_sel(),cc,len,data);
        if(err)
        {
            IPMI_TRAC(ERR_MRK "error from add sel");
            break;
        }
        else if (cc != IPMI::CC_OK)
        {
            IPMI_TRAC(ERR_MRK "Failed to add sel, cc is %02x",cc);
            break;
        }
        storeReserveRecord(recordID,data);

        delete [] data;

        len = ESEL_META_LEN + SEL_LENGTH; //16: SEL size, 7: size of meta data
        cc = IPMI::CC_UNKBAD;
        data = new uint8_t[len];

        createPAddHeader(reserveID,recordID,0,0x00,data);

        memcpy(&data[ESEL_META_LEN],eSelData[1],SEL_LENGTH);

        err = IPMI::sendrecv(IPMI::partial_add_esel(),cc,len,data);
        if(err)
        {
            IPMI_TRAC(ERR_MRK "error partial add esel");
            break;
        }
        else if (cc != IPMI::CC_OK)
        {
            IPMI_TRAC(ERR_MRK "Failed to partial add sel, cc is %02x",cc);
            break;
        }
        storeReserveRecord(recordID,data);

        size_t eSELindex = 0;
        while(eSELindex<eSELlen)
        {
            if(eSELindex + (IPMI::max_buffer() - ESEL_META_LEN) < eSELlen)
            {
                len = IPMI::max_buffer();
            }
            else
            {
                len = eSELlen - eSELindex;
            }
            delete [] data;
            data = new uint8_t[len];
            cc = IPMI::CC_UNKBAD;
            const uint16_t offset = eSELindex + SEL_LENGTH;
            uint8_t dataCpyLen = 0;

            //if the index + the maximum buffer is less than what we still
            //have left in the eSEL, this is not the last entry (data[6] = 0)
            //otherwise, it is and data[6] = 1
            uint8_t l_lastEntry = 0x00;
            if(eSELindex + (IPMI::max_buffer() - ESEL_META_LEN) < eSELlen)
            {
                l_lastEntry = 0x00;
                dataCpyLen = len - ESEL_META_LEN;
            }
            else
            {
                l_lastEntry = 0x01;
                dataCpyLen = len;
            }
            createPAddHeader(reserveID,recordID,offset,l_lastEntry,data);
            memcpy(&data[ESEL_META_LEN],&eSelData[2][eSELindex],dataCpyLen);
            eSELindex = eSELindex + dataCpyLen;

            err = IPMI::sendrecv(IPMI::partial_add_esel(),cc,len,data);
            if(err)
            {
                IPMI_TRAC(ERR_MRK "error from partial add esel");
                break;
            }
            //as long as we continue to get CC_OK, the reserve sel is good.
            //the reserve sel is not valid with a 'reservation canceled' CC
            else if (cc != IPMI::CC_OK)
            {
                IPMI_TRAC(ERR_MRK "failed partial add esel, cc is %02x,",cc);
                IPMI_TRAC(ERR_MRK "eSELindex is %02x",eSELindex);
                //and normally we would have to do some clean up but
                //this will break out of the while loop and then hit the
                //usual delete messages and then exit the function.
                break;
            }
            storeReserveRecord(recordID,data);
        }
        if(err || cc != IPMI::CC_OK)
        {
            break;
        }
    }while(0);

    if(err)
    {
        err->collectTrace(IPMI_COMP_NAME);
        errlCommit(err, IPMI_COMP_ID);
    }

    delete[] l_data;
    delete[] data;

    IPMI_TRAC(EXIT_MRK "send_sel");

    return;
}

namespace IPMISEL
{
    void sendData(uint8_t* i_SEL, uint8_t* i_eSEL,
                  uint8_t* i_extraData, size_t i_dataSize)
    {
        IPMI_TRAC(ENTER_MRK "sendData()");

        // one message queue to the SEL thread
        static msg_q_t mq = Singleton<IpmiSEL>::instance().msgQueue();

        //will eventually send SEL info this way.
        msg_t *msg = msg_allocate();
        msg->type = MSG_SEND_SEL;
        msg->data[0] = i_dataSize;

        selInitData *selData = new selInitData;

        memcpy(selData->sel, i_SEL, SEL_LENGTH);
        memcpy(selData->eSel,i_eSEL,SEL_LENGTH);
        //2048 being the max size for eSELExtra
        if(i_dataSize > 2048)
        {
            memcpy(selData->eSelExtra, i_extraData, 2048);
        }
        else
        {
            memcpy(selData->eSelExtra, i_extraData, i_dataSize);
        }
        msg->extra_data = selData;

        //Send the msg to the sel thread
        int rc =msg_send(mq,msg);

        if(rc)
        {
            IPMI_TRAC(ERR_MRK "Failed (rc=%d) to send message",rc);
            delete selData;
        }
        IPMI_TRAC(EXIT_MRK "sendData");
        return;
    }
}

