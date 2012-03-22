//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/intr/test/intrtest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#ifndef __INTRTEST_H
#define __INTRTEST_H

#include <cxxtest/TestSuite.H>
#include <intr/interrupt.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <kernel/console.H>
#include <targeting/targetservice.H>
#include <targeting/util.H>
#include <sys/time.h>
#include <sys/mmio.h>

extern trace_desc_t * g_trac_intr;


class IntrTest: public CxxTest::TestSuite
{
    public:
        /**
         * @brief INTR test setup values
         */
        void test_verifyState( void )
        {

            // TODO Temporaritly DISABLE in VBU until P8 support is verfied
            if( TARGETING::is_vpo() )
            {
                return;
            }

            //// Add support for second chip (dummy)
            ////uint32_t fake_pir = 0x00000001 << 5;  // P7
            //uint32_t fake_pir = 0x00000001 << 7;  // P8
            //msg_q_t intr_msgQ = msg_q_resolve(INTR_MSGQ);
            //msg_t * msg = msg_allocate();
            //msg->type = INTR::MSG_INTR_ADD_CPU_USR;
            //msg->data[0] = fake_pir;

            //msg_sendrecv(intr_msgQ, msg);
            //msg_free(msg);

            // all the simics registers
            for(uint64_t chip = 0; chip < 1; ++chip)
            {
                // simics P8 appears to support 8 threads on 1 core.
                // simics P7 appears to support 4 threads on 2 cores.
                // for P7, pretending to have 8 threads works because the
                // bit fields for cores and threads are contiguous so we can
                // let the thread count overflow into the core field. so this
                // works for p7 as well.
                for(uint64_t thread = 0; thread < 8; ++thread)
                {
                    uint64_t offset = (chip << 20) | (thread << 12);

                    uint32_t * addr =
                        reinterpret_cast<uint32_t *>(iv_baseAddr + offset);

                    if(offset == 0) // Master cpu
                    {
                        if(*addr != 0xFF000000)
                        {
                            TS_FAIL
                                ("INTR:Master cpu not initialized-XIRR@%p=0x%08x",
                                 addr,*addr);
                        }
                    }

                    // TODO remove restriction when/if simics supports
                    // more than 2 chips and 4 threads each
                    if (chip < 2 && thread < 4)
                    {
                        if(offset != 0 && *addr != 0)
                        {
                            TS_FAIL("INTR:Chip %ld Thread %ld bad XIRR@%p=0x%08x",
                                    chip,thread,addr,*addr);
                        }



                        if(*(addr+4) != 0x40000000 ||
                           *(addr+5) != 0x40000000 ||
                           *(addr+6) != 0xC0000000)
                        {
                            TS_FAIL("INTR:Chip %ld Thread %ld bad LINKS"
                                    " 0x%08x 0x%08x 0x%08x",
                                    chip,thread,
                                    *(addr+4),*(addr+5),*(addr+6));
                        }
                    }
                }
            }
        }

        /**
         * @brief Disable then Enable interrupt handling
         */
        void test_enableDisable( void )
        {
            // TODO Temporaritly DISABLE in VBU until P8 support is confirmed
            if( TARGETING::is_vpo() )
            {
                return;
            }

            uint32_t * addr = reinterpret_cast<uint32_t *>(iv_baseAddr);

            errlHndl_t err = INTR::disableExternalInterrupts();

            if(err)
            {
                TS_FAIL("INTR::disableExternalInterrupts returned error log");
                delete err;
                err = NULL;
            }

            if((*addr & 0xFF000000) != 0)
            {
                TS_FAIL("INTR not disabled. Addr %p",addr);
            }

            err = INTR::enableExternalInterrupts();

            if(err)
            {
                TS_FAIL("INTR::enableExternalInterrupts returned error log");
                delete err;
                err = NULL;
            }


            if((*addr & 0xFF000000) != 0xFF000000)
            {
                TS_FAIL("INTR not enabled. Addr %p", addr);
            }
        }

        /**
         * @brief Register an interrupt message queue, force an interrupt,
         *        then handle the interrupt.
         */
        void test_intr( void )
        {
            // TODO Temporaritly DISABLE in VBU until P8 support is confirmed
            if( TARGETING::is_vpo() )
            {
                return;
            }

            errlHndl_t err = NULL;

            // Need to register a msgq
            msg_q_t msgQ = msg_q_create();
            err = INTR::registerMsgQ(msgQ,INTR::INTERPROC);
            if(err)
            {
                TS_FAIL("Errl from INTR::registerMsgQ()");
                delete err;
                err = NULL;
            }

            // Force an interrupt by writing to the MFFR on master
            volatile uint8_t * mfrr = 
                reinterpret_cast<uint8_t *>(iv_baseAddr+12);
            *(mfrr) = 0x55;
            *(mfrr) = 0xff;

            msg_t* msg = msg_wait(msgQ); // wait for interrupt msg
            TRACFCOMP(g_trac_intr,"Interrupt handled! Type=%lx",msg->type);
            if(msg->type != INTR::INTERPROC)
            {
                TS_FAIL("INTR::unexpected interrupt type %lx",msg->type);
            }
            msg_respond(msgQ,msg);

            msgQ = INTR::unRegisterMsgQ(INTR::INTERPROC);
            if(msgQ)
            {
                msg_q_destroy(msgQ);
            }
            else
            {
                TS_FAIL("INTR::unRegisterMsgQ failed");
            }
        }


      IntrTest() : CxxTest::TestSuite()
      {
          iv_baseAddr = reinterpret_cast<uint64_t>
            (mmio_dev_map(reinterpret_cast<void*>(cv_realAddr),THIRTYTWO_MB));
          TRACDCOMP(g_trac_intr,"IntrTest()> iv_baseAddr=0x%.X",iv_baseAddr);
      };


      ~IntrTest()
      {
          mmio_dev_unmap(reinterpret_cast<void*>(iv_baseAddr));
      };

    private:

      uint64_t iv_baseAddr;
      static const uint64_t cv_realAddr;
};

//note: this must be changed if the BAR changes
const uint64_t IntrTest::cv_realAddr = 0x3fbff9000000ul;



#endif

