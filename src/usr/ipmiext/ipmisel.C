/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmiext/ipmisel.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
 * @file ipmisel.C
 * @brief IPMI system error log transport definition
 */

#include <algorithm>
#include <sys/time.h>
#include <ipmi/ipmisel.H>
#include <ipmi/ipmi_reasoncodes.H>
#include <ipmi/ipmisensor.H>
#include <ipmi/ipmiif.H>

#include <sys/task.h>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>

#include <errl/errlmanager.H>
using   namespace   TARGETING;

//Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"sel: " printf_string,##args)

// local functions
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
 * @brief Create Partial Add eSEL Header from inputs
 */
void createPartialAddHeader(uint8_t* i_reserveID, uint8_t* i_recordID,
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

enum esel_retry
{
    MAX_SEND_COUNT = 4,
    SLEEP_BASE = 2 * NS_PER_MSEC,
};


namespace IPMISEL
{
void sendESEL(uint8_t* i_eselData, uint32_t i_dataSize,
              uint32_t i_eid, std::vector<sel_info_t*>&i_selEventList,
              bool i_infoCallHome)
{
    IPMI_TRAC(ENTER_MRK "sendESEL() %d",i_selEventList.size());

#ifdef __HOSTBOOT_RUNTIME
    // HBRT doesn't send a msg, but use the msg structure to pass the data
    msg_t l_msg;
    msg_t *msg = &l_msg;
    memset(msg, 0, sizeof(msg_t));
#else
    msg_t *msg = msg_allocate();
#endif
    msg->type = MSG_SEND_ESEL;
    auto * const pData = reinterpret_cast<send_esel_data_t*>
        (msg->data);
    pData->callhome=i_infoCallHome;
    pData->eid=i_eid;

    eselInitData *eselData =
    new eselInitData(i_selEventList, i_eselData, i_dataSize);

    msg->extra_data = eselData;

#ifdef __HOSTBOOT_RUNTIME
    process_esel(msg);
#else
    // one message queue to the SEL thread
    static msg_q_t mq = Singleton<IpmiSEL>::instance().msgQueue();

    //Send the msg to the sel thread
    int rc = msg_send(mq,msg);
    if(rc)
    {
        IPMI_TRAC(ERR_MRK "Failed (rc=%d) to send message",rc);
        delete eselData;
    }
#endif
    IPMI_TRAC(EXIT_MRK "sendESEL");
    return;
}

/*
 * @brief process esel msg
 */
void process_esel(msg_t *i_msg)
{
    errlHndl_t l_err = NULL;
    IPMI::completion_code l_cc = IPMI::CC_UNKBAD;

    assert(i_msg != nullptr,"i_msg was nullptr");
    const auto * const pData = reinterpret_cast<const send_esel_data_t*>
        (i_msg->data);
    const auto callhome = pData->callhome;
    const auto l_eid = pData->eid;

    eselInitData * l_data =
            (eselInitData*)(i_msg->extra_data);
    IPMI_TRAC(ENTER_MRK "process_esel");
    selRecord l_eSel;
    oemSelRecord l_oemSel;

    do
    {
        IPMI_TRAC(ENTER_MRK"sel list size %d", l_data->selInfoList.size());
        std::vector<sel_info_t*>::iterator it;
        for (it = l_data->selInfoList.begin(); it != l_data->selInfoList.end();
        ++it)
        {
            sel_info_t *l_sel = *it;
            memset(l_data->oemSel,0,sizeof(oemSelRecord));
            memset(l_data->eSel,0,sizeof(selRecord));
            l_data->selEvent = true;

            //If sensor type is sys event then need to send the oem sel
            //to handle procedure callout
            if (l_sel->sensorType == TARGETING::SENSOR_TYPE_SYS_EVENT)
            {
                //oem sel data
                l_data->selEvent = false;
                l_oemSel.record_type =
                record_type_oem_sel_for_procedure_callout;
                l_oemSel.event_data1 = l_sel->eventOffset;
                l_sel->eventOffset = SENSOR::UNDETERMINED_SYSTEM_HW_FAILURE;
                memcpy(l_data->oemSel,&l_oemSel,sizeof(oemSelRecord));
            }

            //sel data
            l_eSel.record_type = record_type_system_event;
            l_eSel.generator_id = generator_id_ami;
            l_eSel.evm_format_version = format_ipmi_version_2_0;
            l_eSel.sensor_type = l_sel->sensorType;
            l_eSel.sensor_number = l_sel->sensorNumber;
            l_eSel.event_dir_type = l_sel->eventDirType;
            l_eSel.event_data1 = l_sel->eventOffset;
            memcpy(l_data->eSel,&l_eSel,sizeof(selRecord));


            uint32_t l_send_count = MAX_SEND_COUNT;
            while (l_send_count > 0)
            {
                // try to send the esel to the bmc
                send_esel(l_data, l_err, l_cc, callhome);

                // if no error but last completion code was:
                if ((l_err == NULL) &&
                    ((l_cc == IPMI::CC_BADRESV) ||  // lost reservation
                    (l_cc == IPMI::CC_TIMEOUT)))   // timeout
                {
                    // update our count and pause
                    l_send_count--;
                    if (l_send_count)
                    {
                        IPMI_TRAC("process_esel: sleeping; retry_count %d",
                        l_send_count);
                        // sleep 3 times - 2ms, 32ms, 512ms. if we can't get this
                        //  through by then, the system must really be busy...
                        nanosleep(0,
                        SLEEP_BASE << (4 * (MAX_SEND_COUNT - l_send_count - 1)));
                        continue;
                    }
                }
                else
                {
                    //if we enter this, then pel data has logged successfully,
                    //so we don't need to log again, make the size to zero.
                    l_data->dataSize = 0;
                }
                // else it did get sent down OR it didn't because of a bad error
                break;
            } // while
        } // for

    }while(0);

    if(l_err)
    {
#ifdef __HOSTBOOT_RUNTIME
        // HBRT can't commit an error, since this could already be in the
        // errlCommit path since HBRT is single threaded
        IPMI_TRAC(ERR_MRK "DELETING l_err 0x%.8X", l_err->eid());
        delete l_err;
        l_err = NULL;
#else
        l_err->collectTrace(IPMI_COMP_NAME);
        errlCommit(l_err, IPMI_COMP_ID);
#endif
    }
    else if((l_cc == IPMI::CC_OK) &&        // no error
            (l_eid != 0))                   // and it's an errorlog
    {
        // eSEL successfully sent to the BMC - have errlmanager do the ack
        IPMI_TRAC(INFO_MRK "Doing ack for eid 0x%.8X", l_eid);
        ERRORLOG::ErrlManager::errlAckErrorlog(l_eid);
    }

    delete l_data;

    IPMI_TRAC(EXIT_MRK "process_esel");
    return;
} // process_esel

/*
 * @brief Send esel data to bmc
 */
void send_esel(eselInitData * i_data,
            errlHndl_t &o_err, IPMI::completion_code &o_cc,
            bool i_infoCallHome)
{
    IPMI_TRAC(ENTER_MRK "send_esel");
    uint8_t* data = NULL;

    size_t len = 0;

    uint8_t sel_recordID[2] = {0,0};
    uint8_t esel_recordID[2] = {0,0};

    do
    {
        const size_t l_eSELlen = i_data->dataSize;

        if (l_eSELlen == 0)
        {
            IPMI_TRAC(INFO_MRK "no eSEL data present, skipping to SEL");

            // sending sensor SELs only, not the eSEL
            o_cc = IPMI::CC_OK;

            break;
        }

        uint8_t reserveID[2] = {0,0};
        // we need to send down the extended sel data (eSEL), which is
        // longer than the protocol buffer, so we need to do a reservation and
        // call the AMI partial_add_esel command multiple times

        // put a reservation on the SEL Device since we're doing a partial_add
        len = 0;
        delete [] data;
        data = NULL;
        o_cc = IPMI::CC_UNKBAD;
        o_err = IPMI::sendrecv(IPMI::reserve_sel(),o_cc,len,data);
        if(o_err)
        {
            IPMI_TRAC(ERR_MRK "error from reserve_sel");
            break;
        }
        if(o_cc != IPMI::CC_OK)
        {
            IPMI_TRAC(ERR_MRK "Failed to reserve_sel, o_cc %02x",o_cc);
            break;
        }
        storeReserveRecord(reserveID,data);

        // first send down the SEL Event Record data
        size_t eSELindex = 0;
        uint8_t l_lastEntry = 0;
        len = PARTIAL_ADD_ESEL_REQ + sizeof(selRecord);
        delete [] data;
        data = new uint8_t[len];

        // fill in the partial_add_esel request (command) data
        createPartialAddHeader(reserveID,esel_recordID,eSELindex,l_lastEntry,data);

        // copy in the SEL event record data
        memcpy(&data[PARTIAL_ADD_ESEL_REQ], i_data->eSel,
                sizeof(selRecord));

        // add record type for this eSEL
        if (i_infoCallHome)
        {
            data[PARTIAL_ADD_ESEL_REQ + offsetof(selRecord,record_type)] =
                record_type_oem_call_home_info_event;
        }
        else
        {
            data[PARTIAL_ADD_ESEL_REQ + offsetof(selRecord,record_type)] =
                record_type_ami_esel;
        }

        data[PARTIAL_ADD_ESEL_REQ + offsetof(selRecord,event_data1)] =
            event_data1_ami;

        o_cc = IPMI::CC_UNKBAD;
        TRACFBIN( g_trac_ipmi, INFO_MRK"1st partial_add_esel:", data, len);
        o_err = IPMI::sendrecv(IPMI::partial_add_esel(),o_cc,len,data);
        if(o_err)
        {
            IPMI_TRAC(ERR_MRK "error from first partial_add_esel");
            break;
        }
        // as long as we continue to get CC_OK, the reserve sel is good.
        // if the reservation is lost (ie, because something else tried to
        // create a SEL) then the BMC just discards all this data. the
        // errorlog will still be in PNOR and won't get ACKed, so it'll get
        // resent on the next IPL.
        if (o_cc != IPMI::CC_OK)
        {
            IPMI_TRAC(ERR_MRK "failed first partial_add_esel, o_cc %02x, eSELindex %02x",
                    o_cc, eSELindex);
            break;
        }
        // BMC returns the recordID, it's always the same (unless
        // there's a major BMC bug...)
        storeReserveRecord(esel_recordID,data);

        // now send down the eSEL data in chunks.
        const size_t l_maxBuffer = IPMI::max_buffer();
        while(eSELindex<l_eSELlen)
        {
            //if the index + the maximum buffer is less than what we still
            //have left in the eSEL, this is not the last entry (data[6] = 0)
            //otherwise, it is and data[6] = 1
            if(eSELindex + (l_maxBuffer - PARTIAL_ADD_ESEL_REQ)
                    < l_eSELlen)
            {
                len = l_maxBuffer;
                l_lastEntry = 0x00;
            }
            else
            {
                len = l_eSELlen - eSELindex + PARTIAL_ADD_ESEL_REQ;
                l_lastEntry = 0x01;
            }
            delete [] data;
            data = new uint8_t[len];

            // fill in the partial_add_esel request (command) data
            createPartialAddHeader(reserveID, esel_recordID,
                    eSELindex + sizeof(selRecord),
                    l_lastEntry, data);

            uint8_t dataCpyLen = len - PARTIAL_ADD_ESEL_REQ;
            memcpy(&data[PARTIAL_ADD_ESEL_REQ],
                    &i_data->eSelExtra[eSELindex],
                    dataCpyLen);

            // update the offset into the data
            eSELindex = eSELindex + dataCpyLen;

            o_cc = IPMI::CC_UNKBAD;
            TRACFBIN( g_trac_ipmi, INFO_MRK"partial_add_esel:", data, len);
            o_err = IPMI::sendrecv(IPMI::partial_add_esel(),o_cc,len,data);
            if(o_err)
            {
                IPMI_TRAC(ERR_MRK "error from partial_add_esel");
                break;
            }
            // as long as we continue to get CC_OK, the reserve sel is good.
            // if the reservation is lost (ie, because something else tried to
            // create a SEL) then the BMC just discards all this data. the
            // errorlog will still be in PNOR and won't get ACKed, so it'll get
            // resent on the next IPL.
            if (o_cc != IPMI::CC_OK)
            {
                IPMI_TRAC(ERR_MRK "failed partial_add_esel, o_cc %02x, eSELindex %02x",
                        o_cc, eSELindex);
                break;
            }
            // BMC returns the recordID, it's always the same (unless
            // there's a major BMC bug...)
            storeReserveRecord(esel_recordID,data);
        } // while eSELindex
        if (o_cc == IPMI::CC_OK)
        {
            memcpy(i_data->eselRecord,esel_recordID,sizeof(esel_recordID));
        }
    }while(0);

    // if eSEL wasn't created due to an error or callhome, we don't want to continue
    if ((o_err == NULL) && (o_cc == IPMI::CC_OK) && (!i_infoCallHome))
    {
        // caller wants us to NOT create sensor SEL
        if ((i_data->eSel[offsetof(selRecord,sensor_type)] == SENSOR::INVALID_TYPE) &&
            (i_data->eSel[offsetof(selRecord,sensor_number)] == TARGETING::UTIL::INVALID_IPMI_SENSOR)
            )
        {
            IPMI_TRAC(INFO_MRK "Invalid sensor type/number - NOT sending sensor SELs");
        }
        else
        {
            // if the eSEL wasn't created due to a bad completion code, we will
            // still try to send down a SEL that we create, which will contain
            // the eSEL recordID (if it was successful)
            if (data)
            {
                delete [] data;
            }
            len = sizeof(IPMISEL::selRecord);
            data = new uint8_t[len];


            // send standard SEL event
            if (i_data->selEvent)
            {
                // copy in the SEL event record data
                memcpy(data, i_data->eSel, len);
                // copy the eSEL recordID (if it was created) into the extra data area
                // and mark the event_data1 to indicate this is OEM data
                data[offsetof(selRecord,event_data1)] |= 0xA0;
                data[offsetof(selRecord,event_data2)] = i_data->eselRecord[1];
                data[offsetof(selRecord,event_data3)] = i_data->eselRecord[0];
            }
            else //send OEM SEL event
            {
                // copy in the SEL event record data
                memcpy(data, i_data->oemSel, len);
                data[offsetof(oemSelRecord,event_data5)] = i_data->eselRecord[1];
                data[offsetof(oemSelRecord,event_data6)] =i_data->eselRecord[0];
            }

            // use local cc so that we don't corrupt the esel from above
            IPMI::completion_code l_cc = IPMI::CC_UNKBAD;
            TRACFBIN( g_trac_ipmi, INFO_MRK"add_sel:", data, len);
            o_err = IPMI::sendrecv(IPMI::add_sel(),l_cc,len,data);
            if(o_err)
            {
                IPMI_TRAC(ERR_MRK "error from add_sel");
            }
            else if (l_cc != IPMI::CC_OK)
            {
                IPMI_TRAC(ERR_MRK "failed add_sel, l_cc %02x", l_cc);
            }
            else
            {
                // if CC_OK, then len=2 and data contains the recordID of the new SEL
                storeReserveRecord(sel_recordID,data);
            }
        }
    }

    if (data)
    {
        delete [] data;
    }

    IPMI_TRAC(EXIT_MRK
        "send_esel o_err=%.8X, o_cc=x%.2x, sel recID=x%x%x, esel recID=x%x%x",
        o_err ? o_err->plid() : NULL, o_cc, sel_recordID[1], sel_recordID[0],
        esel_recordID[1], esel_recordID[0]);

    return;
} // send_esel

uint32_t get_sel_time()
{
    uint8_t *data = NULL;
    size_t len = 0;
    errlHndl_t l_err;
    IPMI::completion_code l_cc = IPMI::CC_UNKBAD;

    l_err = IPMI::sendrecv( IPMI::get_sel_time(), l_cc, len, data );
    if( l_err || l_cc != IPMI::CC_OK || len != sizeof(uint32_t) )
    {
        delete l_err;
        delete [] data;
        return 0;
    }

    uint32_t timet = le32toh(*reinterpret_cast<uint32_t*>(data));
    delete [] data;
    return timet;
}

} // IPMISEL

#ifndef __HOSTBOOT_RUNTIME
/**
 * @brief Constructor
 */
IpmiSEL::IpmiSEL(void)
    :iv_msgQ(msg_q_create())
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

    INITSERVICE::registerShutdownEvent(IPMI_COMP_ID, iv_msgQ,
                                       IPMISEL::MSG_STATE_SHUTDOWN_SEL,
                                       INITSERVICE::IPMI_SEL_PRIORITY);
    bool l_terminate = false;

    while(!l_terminate)
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
            case IPMISEL::MSG_SEND_ESEL:
                IPMISEL::process_esel(msg);
                //done with msg
                msg_free(msg);
                break;

            case IPMISEL::MSG_STATE_SHUTDOWN:
                IPMI_TRAC(INFO_MRK "ipmisel shutdown event");
                l_terminate = true;

                //Respond that we are done shutting down.
                msg_respond(iv_msgQ, msg);
                break;

            case IPMISEL::MSG_STATE_SHUTDOWN_SEL:
                IPMI_TRAC(INFO_MRK "ipmisel shutdown message from initservice");
                l_terminate = true;
                msg_respond(iv_msgQ, msg);
                break;
        }
    }
    IPMI_TRAC(EXIT_MRK "message loop");
    return;
} // execute


/*
 * @brief enable IPMI errl
 */
void IpmiSEL::errlEnable(errlHndl_t& o_errl)
{
    // Force constructor to run immediately in order to register the shutdown
    // handler.
    Singleton<IpmiSEL>::instance();

}

TASK_ENTRY_MACRO( IpmiSEL::errlEnable );


#endif

