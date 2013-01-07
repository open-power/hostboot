/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/intr/test/intrtest.H $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
#ifndef __INTRTEST_H
#define __INTRTEST_H

#include <cxxtest/TestSuite.H>
#include <intr/interrupt.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <kernel/console.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/attributes.H>
#include <sys/time.h>
#include <sys/mmio.h>
#include <sys/task.h>
#include <sys/misc.h>
#include <kernel/intmsghandler.H>

extern trace_desc_t * g_trac_intr;


class IntrTest: public CxxTest::TestSuite
{
    public:
        /**
         * @brief INTR test setup values
         */
        void test_verifyState( void )
        {

            uint32_t * addr = reinterpret_cast<uint32_t *>(iv_masterAddr);

            if(*addr != 0xFF000000) // XIRR ro reg
            {
                TS_FAIL
                    ("INTR:Master cpu not initialized-XIRR @ %p = 0x%08x",
                     addr,*addr);
            }

            size_t threads = cpu_thread_count();

            //look for an override
            TARGETING::Target* sys = NULL;
            TARGETING::targetService().getTopLevelTarget(sys);
            assert( sys != NULL );
            uint64_t en_threads = sys->getAttr<TARGETING::ATTR_ENABLED_THREADS>();

            for(size_t thread = 0; thread < threads; ++thread)
            {
                if( !(en_threads & (0x8000000000000000>>thread)) )
                {
                    continue;
                }

                addr = reinterpret_cast<uint32_t *>
                    (iv_masterAddr + (thread << 12) + 16); // LINK A reg

                uint32_t linkVal = iv_masterPIR | 0x40000000;

                if((*addr != linkVal) ||
                   (*(addr+1) != linkVal) ||
                   (*(addr+2) != (linkVal | 0x80000000)))
                {
                    TS_FAIL("INTR:Bad LINKS on chipid 0x%08x "
                            "Links: 0x%08x 0x%08x 0x%08x",
                            ((uint32_t)iv_masterPIR + thread),
                            *addr,
                            *(addr + 1),
                            *(addr + 2)
                            );
                }

            }

            // Potentially could check all link registers on other chips
        }

        /**
         * @brief Disable then Enable interrupt handling
         */
        void test_enableDisable( void )
        {

            uint32_t * addr = reinterpret_cast<uint32_t *>(iv_masterAddr);

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

            // DISABLE in VBU
            if( TARGETING::is_vpo() )
            {
                return;
            }

            errlHndl_t err = NULL;

            // Need to register a msgq
            msg_q_t msgQ = msg_q_create();
            err = INTR::registerMsgQ(msgQ,0,INTR::ISN_INTERPROC);
            if(err)
            {
                TS_FAIL("Errl from INTR::registerMsgQ()");
                delete err;
                err = NULL;
            }

            // Force an interrupt by writing to the MFFR on master
            volatile uint8_t * mfrr =
                reinterpret_cast<uint8_t *>(iv_masterAddr+12);
            *(mfrr) = 0x55;
            
            TRACFCOMP(g_trac_intr,"Waiting for IPI interrupt");
            msg_t* msg = msg_wait(msgQ); // wait for interrupt msg
            TRACFCOMP(g_trac_intr,"Interrupt handled! Type=%lx",msg->data[0]);
            if(msg->data[0] != INTR::INTERPROC_XISR)
            {
                TS_FAIL("INTR::unexpected interrupt type %lx",msg->data[0]);
            }
            msg_respond(msgQ,msg);

            msgQ = INTR::unRegisterMsgQ(INTR::ISN_INTERPROC);
            if(msgQ)
            {
                msg_q_destroy(msgQ);
            }
            else
            {
                TS_FAIL("INTR::unRegisterMsgQ failed");
            }
        }

        // This checks the enablePsiIntr. Even though the master proc
        // is already configured it does not use this interface
        // and there are no other processor currently configured in simics
        // to test with.
        void test_enablePsi( void )
        {
            errlHndl_t err = NULL;
            if( TARGETING::is_vpo() )
            {
                return;
            }

            TARGETING::Target* target = NULL;
            TARGETING::targetService().masterProcChipTargetHandle( target );

            err = INTR::enablePsiIntr(target);
            if(err)
            {
                TS_FAIL("Errl from INTER::enablePsiIntr");
                errlCommit(err,INTR_COMP_ID);
            }
        }


        IntrTest() : CxxTest::TestSuite()
        {
            iv_baseAddr = reinterpret_cast<uint64_t>
                (mmio_dev_map(reinterpret_cast<void*>(cv_realAddr),THIRTYTWO_MB));

            TRACDCOMP(g_trac_intr,"IntrTest()> iv_baseAddr=0x%.X",iv_baseAddr);

            task_affinity_pin();                // pin this task to current cpu
            task_affinity_migrate_to_master();  // Move  to the master cpu

            // Get the master cpu id, thread 0
            iv_masterPIR = task_getcpuid();

            TRACDCOMP(g_trac_intr,"IntrTest()> iv_masterPIR=0x%.X",iv_masterPIR);

            iv_masterPIR &= 0xFFFFFFF8;

            task_affinity_unpin();              // unpin this task

            iv_masterAddr = InterruptMsgHdlr::mmio_offset(iv_masterPIR) + iv_baseAddr;

        };


      ~IntrTest()
      {
          mmio_dev_unmap(reinterpret_cast<void*>(iv_baseAddr));
      };

    private:

      uint64_t iv_baseAddr;
      uint64_t iv_masterAddr;
      cpuid_t  iv_masterPIR;
      static const uint64_t cv_realAddr;
};

//note: this must be changed if the BAR changes
const uint64_t IntrTest::cv_realAddr = 0x3ffff80000000ul;



#endif

