//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/mbox/test/mboxsptest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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

extern trace_desc_t* g_trac_mbox;

using namespace TARGETING;

class MboxSPTest : public CxxTest::TestSuite
{
  public:

      /**
       * @brief MBOX - Send asynchronous message
       */
      void testSendAsync(void)
      {
          // TODO Temporaritly DISABLE in VBU until INTR BAR is set
          if( TARGETING::is_vpo() )
          {
              return;
          }
          // requires proper simics model
          // msg will get echoed which looks like a new msg from FSP
          // Register a message queue to receive it.
          msg_q_t msgQ = msg_q_create();
          errlHndl_t err = MBOX::msgq_register(MBOX::HB_TEST_MSGQ,msgQ);

          if(err)
          {
              TS_FAIL("MBOX: Could not register message queue");
              errlCommit(err,HBMBOX_COMP_ID);
          }

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
                  errlCommit(err,HBMBOX_COMP_ID);
              }
          }

          // Send last message
          msg_t * msg = msg_allocate();
          msg->type = 0xff;        // use this to terminate while loop below
          msg->extra_data = NULL;
          err = MBOX::send(MBOX::HB_TEST_MSGQ,msg);
          if(err)
          {
              TS_FAIL("MBOX::send returned an error log");
              errlCommit(err,HBMBOX_COMP_ID);
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
          msg_q_destroy(msgQ);
      }

      /**
       * @brief MBOX - Send sync message
       */
      void testSendSync(void)
      {
          // TODO Temporaritly DISABLE in VBU until INTR BAR is set
          if( TARGETING::is_vpo() )
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
              TS_FAIL("MBOX::sendrecv returned an error log %p",err);
              errlCommit(err,HBMBOX_COMP_ID);
          }

          // TODO eventually the return data will be inverted or modified in
          //      some way.
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
};

#endif

