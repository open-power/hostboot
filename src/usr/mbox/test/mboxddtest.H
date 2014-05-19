/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/test/mboxddtest.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __MBOXDDTEST_H
#define __MBOXDDTEST_H

/**
 *  @file mboxddtest.H
 *
 *  @brief Test cases for MBOX Device Driver
*/

#include <cxxtest/TestSuite.H>
#include <intr/interrupt.H>
#include <errl/errlentry.H>
#include <errl/hberrltypes.H>
#include <limits.h>
#include <devicefw/driverif.H>
#include <mbox/mboxif.H>
#include <sys/time.h>
#include "../mboxdd.H"

extern trace_desc_t* g_trac_mbox;

using namespace TARGETING;
using namespace MBOX;
class MboxDDTest : public CxxTest::TestSuite
{
  public:


    /**
     * @brief MBOX DD test - Write (STUB)
     *        Perform basic write operation
     */
    void _testRead(void)
    {
    }

    /**
     * @brief MBOX DD test - Write (STUB)
     *        Perform basic write operation
     */
    void testEcho(void)
    {
        // this test messes up the mailbox services test
        // and requires proper simics support
#if defined(__testEcho__)
        uint64_t o_status = 0;
        errlHndl_t l_err = NULL;
        uint32_t in_mboxMsg [] = {0x12345678, 0x14785236, 0x96325874,
        0x98765432, 0x78910112, 0x66660000};
        size_t in_size = sizeof(in_mboxMsg);
        uint32_t out_mboxMsg[16] = {0};
        size_t out_size = sizeof(out_mboxMsg);

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testEcho> Begin");

        TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
        epath.addLast(TARGETING::TYPE_SYS,0);
        epath.addLast(TARGETING::TYPE_NODE,0);
        epath.addLast(TARGETING::TYPE_PROC,0);

        l_err = DeviceFW::deviceWrite(
                                      TARGETING::targetService().toTarget(epath),
                                      static_cast<void*>(in_mboxMsg),in_size,
                                      DEVICE_MBOX_ADDRESS(&o_status));
        if (l_err)
            {
            TS_FAIL("Unable to write to mailbox device.\n");
            }

        l_err = DeviceFW::deviceRead(
                                     TARGETING::targetService().toTarget(epath),
                                     static_cast<void*>(out_mboxMsg),out_size,
                                     DEVICE_MBOX_ADDRESS(&o_status));
        if (l_err)
            {
            TS_FAIL("Unable to read mailbox device.\n");
            }
        if (o_status != (MboxDD::MBOX_DATA_PENDING | MboxDD::MBOX_HW_ACK))//HW Ack & PIB Pending
            {
            TS_FAIL("PIB interrupt register shows unexpected interrupt.\n");
            }

        for (uint32_t i=0; i<sizeof(in_mboxMsg)/sizeof(uint32_t); ++i)
            {
            if (out_mboxMsg[i] != in_mboxMsg[i])
                {
                TS_FAIL("Loopback data area mismatch.\n");
                break;
                }
            }

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testEcho> End");
#endif
    }

    /**
     * @brief MBOX DD test - Write/Read
     *        Perform basic write then read operation
     *        Requires SIMICS data loopback from SP-to-Host (PIB-to-LBUS)
     */

    enum {
        NUM_TESTS = 0x3,
        MAX_DATA = 13,
        MAX_SIZE = 16,
        CTL_SIZE = 3,
        HOST_EYE = 0xBADCAFE0,
        RSP_FLAG = 0x00000001,
        
    };


    errlHndl_t readMessage(TARGETING::Target* i_target, uint32_t o_msg[], size_t& io_size, uint64_t& o_status)
    {
        errlHndl_t l_err = NULL;
        o_status = 0x0;
        size_t buf_size = io_size;
        io_size = 0x0;

        TRACFCOMP(g_trac_mbox, "MboxDDTest::readMessage> Entering loop waiting for read");
        while (!o_status && !io_size && !l_err)
            {

            /* Reset io_size to passed in buffer size*/
            io_size = buf_size;
            l_err = DeviceFW::deviceRead(i_target,
                                         static_cast<void*>(o_msg),io_size,
                                         DEVICE_MBOX_ADDRESS(&o_status));
            if (l_err)
                {
                TS_FAIL("Unable to read mailbox device.\n");
                }

            nanosleep(0,1000);
            }

        TRACFCOMP(g_trac_mbox, "MboxDDTest::readMessage> Got MSG size[%d] status[%08x]", io_size, o_status);
        TRACFCOMP(g_trac_mbox, "MboxDDTest::readMessage> Data %08x %08x %08x %08x",
                  o_msg[0], o_msg[1], o_msg[2], o_msg[3]);
        TRACFCOMP(g_trac_mbox, "MboxDDTest::readMessage> Data %08x %08x %08x %08x",
                  o_msg[4], o_msg[5], o_msg[6], o_msg[7]);
        TRACFCOMP(g_trac_mbox, "MboxDDTest::readMessage> Data %08x %08x %08x %08x",
                  o_msg[8], o_msg[9], o_msg[10], o_msg[11]);
        TRACFCOMP(g_trac_mbox, "MboxDDTest::readMessage> Data %08x %08x %08x %08x",
                  o_msg[12], o_msg[13], o_msg[14], o_msg[15]);
        TRACFCOMP(g_trac_mbox, " ");

        return l_err;
    }

    errlHndl_t readMessageInt(TARGETING::Target* i_target, uint32_t o_msg[], size_t& io_size, uint64_t& o_status)
    {
        errlHndl_t l_err = NULL;
        o_status = 0x0;
        size_t buf_size = io_size;
        io_size = 0x0;

        /* Reset io_size to passed in buffer size*/
        io_size = buf_size;
        l_err = DeviceFW::deviceRead(i_target,
                                     static_cast<void*>(o_msg),io_size,
                                     DEVICE_MBOX_ADDRESS(&o_status));
        if (l_err)
            {
            TS_FAIL("Unable to read mailbox device.\n");
            }


        TRACFCOMP(g_trac_mbox, "MboxDDTest::readMsgInt> Got MSG size[%d] status[%08x]", io_size, o_status);
        TRACFCOMP(g_trac_mbox, "MboxDDTest::readMsgInt> Data %08x %08x %08x %08x",
                  o_msg[0], o_msg[1], o_msg[2], o_msg[3]);
        TRACFCOMP(g_trac_mbox, "MboxDDTest::readMsgInt> Data %08x %08x %08x %08x",
                  o_msg[4], o_msg[5], o_msg[6], o_msg[7]);
        TRACFCOMP(g_trac_mbox, "MboxDDTest::readMsgInt> Data %08x %08x %08x %08x",
                  o_msg[8], o_msg[9], o_msg[10], o_msg[11]);
        TRACFCOMP(g_trac_mbox, "MboxDDTest::readMsgInt> Data %08x %08x %08x %08x",
                  o_msg[12], o_msg[13], o_msg[14], o_msg[15]);
        TRACFCOMP(g_trac_mbox, " ");

        return l_err;
    }

    uint32_t psuedo_rand(uint32_t seed)
    {
        uint32_t top, bottom;
        uint32_t rc;
        bottom = ((seed*59) %29)*2131*137;
        top = (bottom*941);
        rc = (top<<16) | (0x0000FFFF &bottom);
        return rc;
    }

    void bld_message(int which, uint32_t o_msg[])
    {
        o_msg[0] = HOST_EYE;
        o_msg[1] = ((uint32_t)(which<<16) | 0x0000A5A5);
        o_msg[2] = (psuedo_rand((uint64_t)&o_msg) % (MAX_DATA-1))+1;
        for(uint32_t i=3; i < (o_msg[2]+3); i++)
            {
            o_msg[i] =psuedo_rand(o_msg[i-1]);
            }
    }

    void cpy_msg(uint32_t i_msg[], uint32_t o_msg[])
    {
        for(uint32_t i=0; i < MAX_SIZE; i++)
            {
            o_msg[i] = i_msg[i];
            }
    }

    int chk_msg(uint32_t in_msg[], uint32_t orig_msg[])
    {
        uint32_t xor_mask = orig_msg[1] | (orig_msg[1] <<16);

        if (in_msg[0] != orig_msg[0])
            return 1;

        if (in_msg[1] != orig_msg[1])
            return 1;

        if (in_msg[2] != orig_msg[2])
            return 1;

        for(uint32_t i = 3; i < (orig_msg[2]+3); i++)
            {
            if (in_msg[i] != (xor_mask ^ orig_msg[i]))
                return 1;
            }

        return 0;
    }

    void apply_xor(uint32_t msg[])
    {
        uint32_t xor_mask = msg[1] | (msg[1] <<16);

        for(uint32_t i = 3; i < (msg[2]+3); i++)
            {
            msg[i] = msg[i] ^ xor_mask;
            }
    }

    void _testWRPoll(void)
    {
        /*  plan of attack is to send a slew of random messages down the mailbox and expect other side to
         echo them back.  Note that the other side will be doing the same

         1st message:  Data 0 -- Hostboot eyecatcher, Data 1 -- number of messages to echo
         <<< wait for FSP to respond: Data 0 -- Hostboot eyecatcher w Resp indicate

         From this point on pump as many messages, as quickly as possible down the pipe in the following format
         Note that host also has to respond to FSP as fast as possible.  Note that responses take preference
         Data 0 -- Hostboot eyecatcher
         Data 1 -- sequence id (top 16 bits), XOR mask (bottom 16 bits, expand to 32 bits)
         Data 2 -- number of valid words (1-13)
         Data 3-15 -- data
         Must get back:
         Data 0 -- Hostboot eyecatcher with RSP bit on
         Data 1 -- sequence id (top 16 bits), N/A (bottom 16 bits)
         Data 2 -- number of valid words 1-13)
         Data 3-15 -- data XORed
         */

        uint64_t o_status = 0;
        uint64_t notused = 0;
        errlHndl_t l_err = NULL;
        size_t write_size = CTL_SIZE *sizeof(uint32_t);
        uint32_t read_mboxMsg[MAX_SIZE] = {0};
        size_t read_size;
        uint32_t toggle = 0;

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRPoll> Begin");

        TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
        epath.addLast(TARGETING::TYPE_SYS,0);
        epath.addLast(TARGETING::TYPE_NODE,0);
        epath.addLast(TARGETING::TYPE_PROC,0);
        TARGETING::Target* my_target = TARGETING::targetService().toTarget(epath);

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRPoll> Waiting for FSP to send # tests...");
        /* Wait for FSP to ack message before starting the test*/
        while ((o_status & MBOX_DATA_PENDING) !=  MBOX_DATA_PENDING)
            {
            read_size = CTL_SIZE * sizeof(uint32_t);
            l_err = readMessage(my_target, read_mboxMsg, read_size, o_status);
            if (l_err)
                {
                TS_FAIL("Unable to read FSP control response\n");
                }
            }

        size_t num_tests = read_mboxMsg[1];

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRPoll> Ack to FSP the # of messages of %d", num_tests);
        /* Send message to FSP stating how many messages I want to test*/
        l_err = DeviceFW::deviceWrite(
                                      my_target,
                                      static_cast<void*>(read_mboxMsg), read_size,
                                      DEVICE_MBOX_ADDRESS(&notused));
        if (l_err)
            {
            TS_FAIL("Unable to write to mailbox device.\n");
            }

        size_t num_msg_send = num_tests;
        size_t num_msg_chk = num_tests;
        size_t num_msg_resp = num_tests;
        uint32_t sent_msg[num_tests][16];
        memset(sent_msg, 0x0, sizeof(uint32_t)*num_tests*16);

        uint32_t reply_msg[num_tests][16];
        memset(reply_msg, 0x0, sizeof(uint32_t)*num_tests*16);
        size_t reply_num = 0;

        /* Enter big control loop*/
        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRPoll> Enter control loop");
        while( (num_msg_send  || num_msg_resp || num_msg_chk) && !l_err)
            {

            /*read the mailbox waiting for next action*/
            read_size = MAX_SIZE * sizeof(uint32_t);
            l_err = readMessage(my_target, read_mboxMsg, read_size, o_status);
            if (l_err)
                {
                TS_FAIL("Unable to read FSP control response\n");
                }

            /*If we have a message for us, process it*/
            if(o_status & MBOX_DATA_PENDING)
                {
                if(!read_size)
                    {
                    TS_FAIL("Data pending without message size returned\n");
                    }

                /*determine if this is a echo response or a new message*/
                if(read_mboxMsg[0] == HOST_EYE)
                    {
                    TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRPoll> Got response, match and check");

                    /*response*/
                    /*use the idx to match to sent message*/
                    size_t ridx = read_mboxMsg[1] >> 16;

                    /* check message */
                    if(chk_msg(read_mboxMsg, sent_msg[ridx]))
                        {
                        TS_FAIL("Response message wasn't sent correctly\n");
                        }
                    num_msg_chk--;
                    }
                else
                    {
                    TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRPoll> FSP msg -- send back");
                    /*new message from FSP -- apply xor and send back*/
                    reply_num++;
                    cpy_msg(read_mboxMsg, reply_msg[reply_num]);
                    apply_xor(reply_msg[reply_num]);
                    }
                }


            /*see if we can send a message to the FSP*/
            if ((o_status & MBOX_HW_ACK) && (num_msg_send || reply_num))
                {
                TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRPoll> Send msg -- reply_num[%d] send_num[%d]",
                          reply_num, num_msg_send);

                uint32_t *msg = NULL;
                /*toggle between replies and new sends*/
                if(reply_num && ((toggle++ %2) || !num_msg_send))
                    {
                    msg = reply_msg[reply_num];
                    reply_num--;
                    num_msg_resp--;
                    }
                else if (num_msg_send)
                    {
                    /*Build a message*/
                    bld_message((num_msg_send-1), sent_msg[num_msg_send-1]);
                    msg = sent_msg[(num_msg_send-1)];
                    /* Decrement number of messages to send*/
                    num_msg_send--;
                    }

                if(msg)
                    {
                    /*Send the message*/
                    write_size = (CTL_SIZE+msg[2]) *sizeof(uint32_t);
                    l_err = DeviceFW::deviceWrite(
                                                  my_target,
                                                  static_cast<void*>(msg),
                                                  write_size,
                                                  DEVICE_MBOX_ADDRESS(&notused));
                    if (l_err)
                        {
                        TS_FAIL("Unable to write to mailbox device.\n");
                        }
                    }
                }

            TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRPoll> Next loop 2reply[%d] 2send[%d] chk[%d]",
                      num_msg_resp, num_msg_send, num_msg_chk);
            }

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRPoll> End");
    };


    void _testWRInt(void)
    {
        /*  plan of attack is to send a slew of random messages down the mailbox and expect other side to
         echo them back.  Note that the other side will be doing the same

         1st message:  Data 0 -- Hostboot eyecatcher, Data 1 -- number of messages to echo
         <<< wait for FSP to respond: Data 0 -- Hostboot eyecatcher w Resp indicate

         From this point on pump as many messages, as quickly as possible down the pipe in the following format
         Note that host also has to respond to FSP as fast as possible.  Note that responses take preference
         Data 0 -- Hostboot eyecatcher
         Data 1 -- sequence id (top 16 bits), XOR mask (bottom 16 bits, expand to 32 bits)
         Data 2 -- number of valid words (1-13)
         Data 3-15 -- data
         Must get back:
         Data 0 -- Hostboot eyecatcher with RSP bit on
         Data 1 -- sequence id (top 16 bits), N/A (bottom 16 bits)
         Data 2 -- number of valid words 1-13)
         Data 3-15 -- data XORed
         */

        uint64_t o_status = 0;
        uint64_t notused = 0;
        errlHndl_t l_err = NULL;
        size_t write_size = CTL_SIZE *sizeof(uint32_t);
        uint32_t read_mboxMsg[MAX_SIZE] = {0};
        size_t read_size;
        uint32_t toggle = 0;

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRInt> Begin");

        TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
        epath.addLast(TARGETING::TYPE_SYS,0);
        epath.addLast(TARGETING::TYPE_NODE,0);
        epath.addLast(TARGETING::TYPE_PROC,0);
        TARGETING::Target* my_target = TARGETING::targetService().toTarget(epath);

        /*Register for interrupt*/
        msg_q_t msgQ = msg_q_create();
        l_err = INTR::registerMsgQ(msgQ,0,(INTR::ext_intr_t)0x1A);    //Simics is setup to send IRQ on 26
        if(l_err)
            {
            TS_FAIL("Errl from INTR::registerMsgQ()");
            delete l_err;
            l_err = NULL;
            }

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRInt> Enable interrupts on MBOX");
        l_err = mboxInit(my_target);
        if(l_err)
            {
            TS_FAIL("Errl from MboxInit()");
            delete l_err;
            l_err = NULL;
            }


        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRInt> Waiting for FSP to send # tests...");
        msg_t* msg = msg_wait(msgQ); // wait for interrupt msg
        
        /*got the IRQ -- need to read the mailbox message and handle*/
        read_size = CTL_SIZE * sizeof(uint32_t);
        l_err = readMessageInt(my_target, read_mboxMsg, read_size, o_status);
        if (l_err)
            {
            TS_FAIL("Unable to read FSP control response\n");
            }

        /*Ack the IRQ*/
        msg_respond(msgQ,msg);

        if ((o_status & MBOX_DATA_PENDING) != MBOX_DATA_PENDING
            || !read_size)
            {
            TS_FAIL("First message Unable to read FSP control response\n");
            }

        size_t num_tests = read_mboxMsg[1];

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRInt> Ack to FSP the # of messages of %d", num_tests);
        /* Send message to FSP stating how many messages I want to test*/
        l_err = DeviceFW::deviceWrite(
                                      my_target,
                                      static_cast<void*>(read_mboxMsg), read_size,
                                      DEVICE_MBOX_ADDRESS(&notused));

        TRACFCOMP(g_trac_mbox, "Write complete");
        if (l_err)
            {
            TS_FAIL("Unable to write to mailbox device.\n");
            }

        size_t num_msg_send = num_tests;
        size_t num_msg_chk = num_tests;
        size_t num_msg_resp = num_tests;
        uint32_t sent_msg[num_tests][16];
        memset(sent_msg, 0x0, sizeof(uint32_t)*num_tests*16);

        uint32_t reply_msg[num_tests][16];
        memset(reply_msg, 0x0, sizeof(uint32_t)*num_tests*16);
        size_t reply_num = 0;

        /* Enter big control loop*/
        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRInt> Enter control loop");
        while( (num_msg_send  || num_msg_resp || num_msg_chk) && !l_err)
            {
            msg = msg_wait(msgQ); // wait for interrupt msg

            /*got the IRQ -- need to read the mailbox message and handle*/
            read_size = MAX_SIZE * sizeof(uint32_t);
            l_err = readMessageInt(my_target, read_mboxMsg, read_size, o_status);
            if (l_err)
                {
                TS_FAIL("Unable to read FSP control response\n");
                }

            /*Ack the IRQ*/
            msg_respond(msgQ,msg);

            /*If we have a message for us, process it*/
            if(o_status & MBOX_DATA_PENDING)
                {
                if(!read_size)
                    {
                    TS_FAIL("Data pending without message size returned\n");
                    }

                /*determine if this is a echo response or a new message*/
                if(read_mboxMsg[0] == HOST_EYE)
                    {
                    TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRInt> Got response, match and check");

                    /*response*/
                    /*use the idx to match to sent message*/
                    size_t ridx = read_mboxMsg[1] >> 16;

                    /* check message */
                    if(chk_msg(read_mboxMsg, sent_msg[ridx]))
                        {
                        TS_FAIL("Response message wasn't sent correctly\n");
                        }
                    num_msg_chk--;
                    }
                else
                    {
                    TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRInt> FSP msg -- send back");
                    /*new message from FSP -- apply xor and send back*/
                    reply_num++;
                    cpy_msg(read_mboxMsg, reply_msg[reply_num]);
                    apply_xor(reply_msg[reply_num]);
                    }
                }


            /*see if we can send a message to the FSP*/
            if ((o_status & MBOX_HW_ACK) && (num_msg_send || reply_num))
                {
                TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRInt> Send msg -- reply_num[%d] send_num[%d]",
                          reply_num, num_msg_send);

                uint32_t *msg = NULL;
                /*toggle between replies and new sends*/
                if(reply_num && ((toggle++ %2) || !num_msg_send))
                    {
                    msg = reply_msg[reply_num];
                    reply_num--;
                    num_msg_resp--;
                    }
                else if (num_msg_send)
                    {
                    /*Build a message*/
                    num_msg_send--;
                    bld_message((num_msg_send), sent_msg[num_msg_send]);
                    msg = sent_msg[(num_msg_send)];
                    /* Decrement number of messages to send*/
                    ;
                    }

                if(msg)
                    {
                    /*Send the message*/
                    write_size = (CTL_SIZE+msg[2]) *sizeof(uint32_t);
                    l_err = DeviceFW::deviceWrite(
                                                  my_target,
                                                  static_cast<void*>(msg),
                                                  write_size,
                                                  DEVICE_MBOX_ADDRESS(&notused));
                    if (l_err)
                        {
                        TS_FAIL("Unable to write to mailbox device.\n");
                        }
                    }
                }

            TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRInt> Next loop 2reply[%d] 2send[%d] chk[%d]",
                      num_msg_resp, num_msg_send, num_msg_chk);
            }

        TRACFCOMP(g_trac_mbox, "MboxDDTest::testWRInt> End");
    };

};     

#endif
