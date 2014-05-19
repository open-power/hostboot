/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/intr/test/intrtest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <sys/internode.h>
#include <sys/mm.h>
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

        void test_mpipl_node_data( void )
        {
            errlHndl_t err = NULL;
            for(uint64_t hb_node = 0; hb_node < MAX_NODES_PER_SYS; ++hb_node)
            {
                // This message is async so the NODE_INFO_AREA may take
                // a bit to show the changes
                err = INTR::addHbNode(hb_node);

                if ( err )
                {
                    break;
                }
            }

            if ( err )
            {
                TS_FAIL("Error log from INTR::addHbNode");
                errlCommit(err, INTR_COMP_ID);
            }

            // Unregister a non-existant mesgq - This not only tests this
            // interface using a bad param, but also serves to synchonize the
            // async messages above so we don't check the NODE_DATA_AREA before
            // it has been set.
            msg_q_t msgQ = INTR::unRegisterMsgQ(0xff);
            if(msgQ != NULL)
            {
                TS_FAIL("INTR: non-existant external interrupt type returned "
                        "a valid msgQ");
            }

            void * node_info_ptr =
                reinterpret_cast<void *>(VMM_INTERNODE_PRESERVED_MEMORY_ADDR);

            internode_info_t * this_node_info =
                reinterpret_cast<internode_info_t *>
                (mm_block_map(node_info_ptr,INTERNODE_INFO_SIZE));

            if(this_node_info)
            {
                if(this_node_info->eye_catcher != NODE_INFO_EYE_CATCHER)
                {
                    TS_FAIL("INTR: NODE_DATA_AREA not initialized");
                }
                for(uint64_t hb_node = 0;
                    hb_node < MAX_NODES_PER_SYS;
                    ++hb_node)
                {
                    if(this_node_info->exist[hb_node] != true)
                    {
                        TS_FAIL
                            ("INTR: NODE_DATA_AREA.exist not true for node %d",
                             hb_node);
                    }
                }

                mm_block_unmap(this_node_info);
            }
            else
            {
                TS_FAIL("INTR Could not map memory of NODE_DATA_AREA");
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

