/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/test/mboxsptest.H $                              */
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
#ifndef __MBOXSPTEST_H
#define __MBOXSPTEST_H

/**
 *  @file mboxsptest.H
 *
 *  @brief Test cases for MBOX service provider
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/hberrltypes.H>
#include <limits.h>
#include <mbox/mboxif.H>
#include <targeting/common/util.H>
#include <sys/time.h>

extern trace_desc_t* g_trac_mbox;

using namespace TARGETING;

class MboxSPTest : public CxxTest::TestSuite
{
  public:

      bool mboxEnabled()
      {
          bool enabled = false;

          TARGETING::Target * sys = NULL;
          TARGETING::targetService().getTopLevelTarget( sys );
          TARGETING::SpFunctions spfuncs;
          if( sys &&
              sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfuncs) &&
              spfuncs.mailboxEnabled)
          {
              enabled = true;
          }
          return enabled;
      }

      /**
       * @brief MBOX - Send asynchronous message
       */
      void testSendAsync(void)
      {
          //  This testcase only works if there is no FSP.
          //  Must be disabled for vpo and
          //  TODO disble if there is an FSP.
          if( TARGETING::is_vpo() )
          {
              return;
          }

          errlHndl_t err = NULL;
          // requires proper simics model
          // msg will get echoed which looks like a new msg from FSP
          // Register a message queue to receive it.
          msg_q_t msgQ = msg_q_create();

          // Send some messages - DMA size will force a request
          // to be sent to FSP for more buffers.
          for(size_t i = 1; i < 3; ++i)
          {
              msg_t* msg = msg_allocate();
              msg->type = 1;
              msg->data[1] = 33 * 1024;
              msg->extra_data = malloc(33 * 1024);
              memcpy(msg->extra_data,"Message junk",13);

              msg->data[0] = i;
              err = MBOX::send(MBOX::HB_TEST_MSGQ,msg);
              if(err)
              {
                  TS_FAIL("MBOX::send returned an error log");
                  errlCommit(err,MBOX_COMP_ID);
              }
          }

          nanosleep(0,1000000);


          if(mboxEnabled())
          {
              // late registration to test ability to queue message until
              // a queue is ready
              err = MBOX::msgq_register(MBOX::HB_TEST_MSGQ,msgQ);
              if(err)
              {
                  TS_FAIL("MBOX: Could not register message queue");
                  errlCommit(err,MBOX_COMP_ID);
              }


              // Send last message
              msg_t * msg = msg_allocate();
              msg->type = 0xff;        // use this to terminate while loop below
              msg->extra_data = NULL;
              err = MBOX::send(MBOX::HB_TEST_MSGQ,msg);
              if(err)
              {
                  TS_FAIL("MBOX::send returned an error log");
                  errlCommit(err,MBOX_COMP_ID);
              }

              // now get the messages - they will look like async messages
              // from FSP, even though they are just the echo of the
              // async messages that hostboot just sent above.
              size_t msg_idx = 0;
              while(1)
              {
                  msg_t* msg = msg_wait(msgQ);

                  if(msg->type == 0xff)
                  {
                      msg_free(msg);
                      break;
                  }

                  ++msg_idx;

                  if(msg->type != 1 || 
                     msg->data[0] != msg_idx || 
                     msg->data[1] != 33 * 1024)
                  {
                      TS_FAIL("MBOXTEST: Unexpected message from FSP");

                      TRACFCOMP(g_trac_mbox,
                                "MBOXTEST MSG from FSP: %d %lx %lx %p",
                                msg->type,
                                msg->data[0],
                                msg->data[1],
                                msg->extra_data);
                  }
                  if(msg->extra_data)
                  {
                      TRACFCOMP(g_trac_mbox,"MBOXTEST Extra data: %s",
                                static_cast<char *>(msg->extra_data));
                      ::free(msg->extra_data);
                  }

                  msg_free(msg);
              }

              msgQ = MBOX::msgq_unregister(MBOX::HB_TEST_MSGQ);
          } // end if mboxEnabled
          msg_q_destroy(msgQ);
      }

      /**
       * @brief MBOX - Send sync message
       */
      void testSendSync(void)
      {
          //  This testcase only works if there is no FSP.
          //  Must be disabled for vpo and
          //  TODO disble if there is an FSP.
          if( TARGETING::is_vpo())
          {
              return;
          }
          // Echo What gets sent comes back
          // Will get changed to invert data (or something like that)
          msg_t * msg = msg_allocate();
          msg->type = 2;
          msg->data[0] = 0x001122334455667788;
          msg->data[1] = 1;
          msg->extra_data = NULL;

          errlHndl_t err = MBOX::sendrecv(MBOX::FSP_ECHO_MSGQ,msg);

          if(err)
          {
              if(mboxEnabled())
              {
                  TS_FAIL("MBOX::sendrecv returned an error log %p",err);
                  errlCommit(err,MBOX_COMP_ID);
              }
          }
          else
          {
              if(!mboxEnabled())
              {
                  TS_FAIL("MBOX::sendrecv expected an error log when mbox is disabled");
              }
          }

          // TODO eventually the return data will be inverted or modified in
          //      some way?
          if(msg->type != 2 ||
             msg->data[0] != 0x001122334455667788 ||
             msg->data[1] != 1)
          {
              TS_FAIL("Unexpected mailbox sync message returned");

              TRACFCOMP(g_trac_mbox,
                        "MBOXTEST SYNC response: %d %lx %lx %p",
                        msg->type,
                        msg->data[0],
                        msg->data[1],
                        msg->extra_data);
          }

          msg->type = 2;
          msg->data[1] = 128 * 1024;  // too big of message
          msg->extra_data = malloc(8);  
          err = MBOX::sendrecv(MBOX::FSP_ECHO_MSGQ,msg);

          if(!err)
          {
              TS_FAIL("MBOX::sendrecv should return an error log, extra_data too big");
          }
          else
          {
              delete err;
          }
          free(msg->extra_data);

          msg_free(msg);
      }

      void testSuspendResume(void)
      {

          errlHndl_t err = MBOX::suspend();
          if (err)
          {
              TS_FAIL("MBOX:suspend failed");
              delete err;
          }

          err = MBOX::resume();
          if (err)
          {
              TS_FAIL("MBOX::resume failed");
              delete err;
          }
      }

      void testInvalidMsg(void)
      {
          msg_t * msg = msg_allocate();
          msg->type = 0x8000ffff;
          msg->extra_data = NULL;

          // If there is no FSP then sync message will just come back OK - no errors

          // For an async message w/o an FSP:
          //   Should see that the message bounced back and was queued.
          //   Should see a trace message and error log from mbox service
          //     indicating there was an unclaimed message at shutdown.
          // For an async message with an FSP:
          //   Should just see a trace and error log from the mbox service that
          //     there was an invalid message.
          errlHndl_t err = MBOX::send(MBOX::FSP_ECHO_MSGQ,msg);
          if(err)
          {
              TS_FAIL("MBOXTEST::testInvalidMsg. Unexpected error log from send()");
              errlCommit(err,MBOX_COMP_ID);
          }
      }

      void testHardwareError(void)
      {
#if defined(__DESTRUCTIVE_MBOX_TEST__)
          msg_t * msg = msg_allocate();
          msg->type = 0x8000ffff;
          msg->extra_data = NULL;

          MBOX::forceErrorOnNextOperation();

          errlHndl_t err = MBOX::send(MBOX::FSP_ECHO_MSGQ,msg);
          if(err)
          {
              TS_FAIL("MBOXTEST::testHardwareError. Unexpected error log from send()");
              errlCommit(err,MBOX_COMP_ID);
          }

          msg = msg_allocate();
          msg->type = 0x8000fffe;
          msg->extra_data = NULL;

          err = MBOX::sendrecv(MBOX::FSP_ECHO_MSGQ,msg);
          if(!err)
          {
              TS_FAIL("MBOXTEST::testHardwareError. No error log from sendrecv()");
          }
          else
          {
              delete err;
          }

          msg->type = 0x8000fffd;
          err = MBOX::send(MBOX::FSP_ECHO_MSGQ,msg);
          if(!err)
          {
              TS_FAIL("MBOXTEST::testHardwareError. No error log from send()");
          }
          else
          {
              delete err;
          }

          msg_free(msg);
#endif
      }

      /**
       * @brief IPC message test
       * 
       */
      void testIPC(void)
      {
          errlHndl_t err = NULL;
          msg_t * msg = msg_allocate();
          msg_t * tmsg = msg_allocate();
          msg_q_t msgQ = msg_q_create();

          err = MBOX::msgq_register(MBOX::HB_TEST_MSGQ,msgQ);
          if(err)
          {
              TS_FAIL("MBOX IPC: Could not register message queue");
              errlCommit(err,MBOX_COMP_ID);
          }

          msg->type = 1;
          msg->data[0] = 0x1111111111111111ull;
          msg->data[1] = 0x4444444444444444ull;
          msg->extra_data = (void *)0x3333333333333333ull;

          *tmsg = *msg; // save for compare
          uint64_t node = 0;

          err = MBOX::send(MBOX::HB_TEST_MSGQ,msg,node);
          if(err)
          {
              TS_FAIL("MBOX::send (IPC) returned and error log");
              errlCommit(err,MBOX_COMP_ID);
              msg_free(msg);
              return;
          }

          msg_t * rmsg = msg_wait(msgQ);

          if(rmsg->type != tmsg->type || 
             rmsg->data[0] != tmsg->data[0] || 
             rmsg->data[1] != tmsg->data[1] ||
             rmsg->extra_data != tmsg->extra_data)
          {
              TS_FAIL("IPCTEST: Unexpected IPC message");

              TRACFCOMP(g_trac_mbox,
                        "IPCTEST IPC MSG: %d %lx %lx %p",
                        rmsg->type,
                        rmsg->data[0],
                        rmsg->data[1],
                        rmsg->extra_data);
          }

          msgQ = MBOX::msgq_unregister(MBOX::HB_TEST_MSGQ);
          msg_q_destroy(msgQ);
          msg_free(rmsg);
          msg_free(tmsg);
      }
};

#endif

