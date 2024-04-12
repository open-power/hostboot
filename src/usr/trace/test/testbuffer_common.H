/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/test/testbuffer_common.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2024                        */
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
 * @file testbuffer_common.H
 * @brief Testcases for TRACE::Buffer (common between IPL and RUNTIME)
 */
#include <trace/buffer.H>
#include <trace/bufferpage.H>
#include <trace/compdesc.H>
#include <trace/entry.H>
#include <trace/daemonif.H>

#include <cxxtest/TestSuite.H>

#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errlreasoncodes.H>

using namespace ERRORLOG;
using namespace TRACE;

class BufferTestCommon : public CxxTest::TestSuite
{
  public:

    /**
     *   @brief Create a v2 trace buffer with test data
     *
     *   @param [in]  name of the trace component
     *   @param [out] buffer to contain the traces
     *   @param [in]  number of traces desired
     *   @param [in]  size of the buffer
     *
     *   @return trace_buf_head_v2_t*
     */
    trace_buf_head_v2_t* createTrace_v2(const char *i_comp,
                                        char       *o_data,
                                        int         i_num,
                                        size_t      i_max)
    {
        trace_buf_head_v2_t *l_tbh{nullptr};
        trace_bin_entry_t   *l_bin_entry{nullptr};
        uint32_t             l_entry_size = sizeof(trace_bin_entry_t);
        size_t               l_comp_size  = strlen(i_comp) + 1;

        l_tbh = reinterpret_cast<trace_buf_head_v2_t*>(o_data);
        l_tbh->init(i_max);

        char *l_o_data_end = l_tbh->getEndPtr();

        l_bin_entry = reinterpret_cast<trace_bin_entry_t*>(l_tbh->iv_next);

        // load entries into the trace buffer
        for (int i=1; i<=i_num && l_tbh->iv_next+l_comp_size+l_entry_size <= l_o_data_end; i++)
        {
            memcpy(l_bin_entry,i_comp,l_comp_size);
            l_tbh->iv_size += l_comp_size;
            l_tbh->iv_next += l_comp_size;
            l_bin_entry     = reinterpret_cast<trace_bin_entry_t*>(l_tbh->iv_next);
            l_bin_entry->stamp.tbh   = 0;
            l_bin_entry->stamp.tbl   = i;
            l_bin_entry->stamp.tid   = i;
            l_bin_entry->head.length = 0;
            l_bin_entry->head.tag    = TRACE_COMP_TRACE;
            l_bin_entry->head.hash   = 100+i;
            l_bin_entry->head.line   = 200+i;
            l_tbh->iv_size += l_entry_size;
            l_tbh->iv_next += l_entry_size;
            l_bin_entry = reinterpret_cast<trace_bin_entry_t*>(l_tbh->iv_next);
        }
        return l_tbh;
    }

    /**
     *   @brief Load v1 test trace entries into i_buffer
     *
     *   @param [in]  i_buffer       trace buffer to insert v1 traces into
     *   @param [in]  i_comp_desc    descriptor for i_buffer
     *   @param [in]  i_num_entries  number of traces to insert
     */
    void loadTraceEntries(Buffer        &i_buffer,
                          ComponentDesc *i_comp_desc,
                          int            i_num_entries)
    {
        Entry             *l_entry{};
        trace_bin_entry_t *l_bin_entry{};
        uint32_t           l_entrySize = sizeof(trace_bin_entry_t);

        // load nine test trace entries into l_buffer
        for (int i=1; i<=i_num_entries; i++)
        {
            l_entry = i_buffer.claimEntry(i_comp_desc, l_entrySize);
            if (!l_entry) {break;}

            l_bin_entry = reinterpret_cast<trace_bin_entry_t*>(l_entry->data);
            l_bin_entry->stamp.tbh   = 0;
            l_bin_entry->stamp.tbl   = i;
            l_bin_entry->stamp.tid   = i;
            l_bin_entry->head.length = 0;
            l_bin_entry->head.tag    = TRACE_COMP_TRACE;
            l_bin_entry->head.hash   = 100+i;
            l_bin_entry->head.line   = 200+i;
            i_buffer.commitEntry(l_entry);
        }
        return;
    }

    /**
     *   @brief Debug print the traces in the buffer
     *
     *   @param [in]  i_vec    vector with ptrs to the traces to print
     *   @param [in]  i_label  txt to prefix each printed trace
     */
    void printTraceVec(std::vector<trace_bin_entry_v2_t*> i_vec,
                       const char                        *i_label)
    {
        for (auto itr : i_vec)
        {
            trace_bin_entry_t *l_entry = itr->getEntry();

            TS_INFO("PR_%s: %s e:%p tbl:%d hash:%d",
                    i_label,
                    itr->iv_comp,
                    itr,
                    l_entry->stamp.tbl,
                    l_entry->head.hash);
        }
    }

    /**
     *   @brief Testcases for collectTrace using a list of components
     */
    void testBufferCompList()
    {
        TS_INFO("testBufferCompList: TC1");
        errlHndl_t l_errl  = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                           ERRL_TEST_MOD_ID,
                                           ERRL_TEST_REASON_CODE);
        errlHndl_t l_errl2 = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                           ERRL_TEST_MOD_ID,
                                           ERRL_TEST_REASON_CODE);
        l_errl->aggregate(l_errl2);

        std::list<const char*> l_comps_empty;
        l_errl->collectTrace(l_comps_empty, 2000, propagation_t::PROPAGATE);

        TS_INFO("testBufferCompList: TC2");
        std::list<const char*> l_comps{"ISTEPS_TRACE","INITSVC","ERRL","PLDM","NOTFOUND",""};
        l_errl->collectTrace(l_comps,4000);
        l_errl->collectTrace(l_comps,2000,propagation_t::PROPAGATE);
        l_errl->setSev(ERRL_SEV_INFORMATIONAL);
        errlCommit(l_errl, CXXTEST_COMP_ID);
        return;
    }

    /**
     *   @brief Testcases for collectThreadTrace and its utilities
     *           TC1 - underflow conditions
     *           TC2 - overflow conditions
     *           TC3 - filter by TID
     *           TC4 - duplicate trace cleanup
     *           TC5 - call collectThreadTrace
     */
    void testBufferTIDs()
    {
        size_t               l_max{512};
        size_t               l_rc{0};
#ifndef __HOSTBOOT_RUNTIME
        DaemonIf             l_d;
#else
        TRACEDAEMON::Daemon  l_d;
#endif
        Buffer               l_buffer(&l_d, Buffer::UNLIMITED);
        ComponentList        l;
        ComponentDesc       *l_comp_desc       = l.getDescriptor("TCOMP1", l_max);
        char                 l_orig_buf[l_max] = {0};
        char                 l_alt_buf[l_max]  = {0};
        trace_buf_head_v2_t *l_orig = reinterpret_cast<trace_buf_head_v2_t*>(l_orig_buf);
        trace_buf_head_v2_t *l_alt{nullptr};

        std::vector<trace_bin_entry_v2_t*> l_vec;
        std::list<tid_t>                   l_tids;

        //----------------------------------------------------------------------
        // TC1 - test utilites with an empty trace buffer (underflow)
        //----------------------------------------------------------------------
        TS_INFO("testBufferTIDs: TC1");
        l_rc = l_buffer.getTrace(nullptr, l_tids, l_orig, l_max);
        if (l_rc != 0) {TS_FAIL("testBufferTIDs: TC1 rc:%d", l_rc);}

        TS_INFO("testBufferTIDs: TC1.1");
        l_rc = l_buffer.getTrace(l_comp_desc, l_tids, nullptr, l_max);
        if (l_rc != 0) {TS_FAIL("testBufferTIDs: TC1.1 rc:%d", l_rc);}

        TS_INFO("testBufferTIDs: TC1.2");
        l_rc = l_buffer.getTrace(l_comp_desc, l_tids, l_orig, 0);
        if (l_rc != 0) {TS_FAIL("testBufferTIDs: TC1.2 rc:%d", l_rc);}

        TS_INFO("testBufferTIDs: TC1.3");
        l_rc = l_buffer.getTrace(l_comp_desc, l_tids, l_orig, l_max);
        if (l_rc != 0) {TS_FAIL("testBufferTIDs: TC1.3 rc:%d", l_rc);}

        TS_INFO("testBufferTIDs: TC1.4");
        l_orig->extract(l_vec, 0);
        if (l_vec.size() != 0) {TS_FAIL("testBufferTIDs: TC1.4 size:%d", l_vec.size());}

        TS_INFO("testBufferTIDs: TC1.5");
        l_orig->extract(l_vec, l_max);
        if (l_vec.size() != 0) {TS_FAIL("testBufferTIDs: TC1.5 size:%d", l_vec.size());}

        TS_INFO("testBufferTIDs: TC1.6");
        l_orig->append(nullptr);

        TS_INFO("testBufferTIDs: TC1.7");
        l_orig->append(l_alt);

        TS_INFO("testBufferTIDs: TC1.8");
        l_orig->extract(l_vec, l_max);
        if (l_vec.size() != 0) {TS_FAIL("testBufferTIDs: TC1.8 size:%d", l_vec.size());}

        TS_INFO("testBufferTIDs: TC1.9");
        l_orig->cleanup(l_vec);

        //----------------------------------------------------------------------
        // TC2 - test utilites with too many traces in the buffers (overflow)
        //----------------------------------------------------------------------
        TS_INFO("testBufferTIDs: TC2");

        // load more entries into l_buffer than will fit in l_orig
        loadTraceEntries(l_buffer, l_comp_desc, 10);

        // attempt to load more traces than will fit into l_orig
        //  l_orig should fit 16 v2 traces (1 + 7+24 + 7+24 ...)
        TS_INFO("testBufferTIDs: TC2.1");

        // only extract TIDs 1 to 8
        l_tids.clear();
        for (int i=1; i<=8; i++) {l_tids.push_back(i);}
        l_buffer.getTrace(l_comp_desc, l_tids, l_orig, l_max);

        // extract the traces in l_orig and verify the count
        TS_INFO("testBufferTIDs: TC2.2");
        l_vec.clear();
        l_orig->extract(l_vec, l_max);
        if (l_vec.size() != 8) {TS_FAIL("testBufferTIDs: TC2.2 size:%d", l_vec.size());}

        // create a trace buf l_alt with 4 entries
        TS_INFO("testBufferTIDs: TC2.3");
        l_alt = createTrace_v2("TCOMP2", l_alt_buf, 30, l_max);
        l_vec.clear();
        l_alt->extract(l_vec, l_max);
        if (l_vec.size() != 15) {TS_FAIL("testBufferTIDs: TC2.3 size:%d", l_vec.size());}

        // attempt to append l_alt to l_orig, this is an overflow
        TS_INFO("testBufferTIDs: TC2.4");
        l_orig->append(l_alt);
        TS_INFO("testBufferTIDs: TC2.4.1");
        l_vec.clear();
        l_orig->extract(l_vec, l_max);
        if (l_vec.size() != 15) {TS_FAIL("testBufferTIDs: TC2.4 size:%d", l_vec.size());}

        //----------------------------------------------------------------------
        // TC3 - filter trace buffer by TIDs, verify
        //----------------------------------------------------------------------
        TS_INFO("testBufferTIDs: TC3");

        // create a list of TIDs to filter from the trace buffer
        l_tids.clear();
        l_tids.push_back(0);
        l_tids.push_back(2);
        l_tids.push_back(4);
        l_tids.push_back(6);
        l_tids.push_back(8);
        l_tids.push_back(20);

        // get the filtered list of traces from l_buffer matching the tids
        l_buffer.getTrace(l_comp_desc, l_tids, l_orig, l_max);

        // get a vector of trace ptrs from l_orig
        TS_INFO("testBufferTIDs: TC3.1");
        l_vec.clear();
        l_orig->extract(l_vec, l_max);

        // search the trace ptrs for the expected TID traces
        TS_INFO("testBufferTIDs: TC3.2");
        bool found2{false};
        bool found4{false};
        bool found6{false};
        bool found8{false};
        for (auto itr : l_vec)
        {
            trace_bin_entry_t *l_entry = itr->getEntry();
            if (l_entry->stamp.tid == 2) {found2=true;}
            if (l_entry->stamp.tid == 4) {found4=true;}
            if (l_entry->stamp.tid == 6) {found6=true;}
            if (l_entry->stamp.tid == 8) {found8=true;}
        }
        // verify we found only the expected traces
        if (l_vec.size() != 4) {TS_FAIL("testBufferTIDs: TC3.2 size:%d", l_vec.size());}
        if (!found2) {TS_FAIL("testBufferTIDs: extractTrace: tid2 not found");}
        if (!found4) {TS_FAIL("testBufferTIDs: extractTrace: tid4 not found");}
        if (!found6) {TS_FAIL("testBufferTIDs: extractTrace: tid6 not found");}
        if (!found8) {TS_FAIL("testBufferTIDs: extractTrace: tid8 not found");}

        //----------------------------------------------------------------------
        // TC4 - create a trace buffer with dups, then cleanp and verify
        //----------------------------------------------------------------------
        TS_INFO("testBufferTIDs: TC4");

        // get the filtered list of traces from l_buffer matching the tids
        l_buffer.getTrace(l_comp_desc, l_tids, l_orig, l_max);

        // create trace with 4 entries
        l_alt = createTrace_v2("TCOMP2",l_alt_buf, 4, l_max);
        l_orig->append(l_alt);
        l_vec.clear();
        l_orig->extract(l_vec, l_max);

        // create trace with 4 entries
        TS_INFO("testBufferTIDs: TC4.1");
        l_alt = createTrace_v2("TCOMP3",l_alt_buf, 4, l_max);
        l_orig->append(l_alt);

        // extract ptrs from l_orig to l_vec
        TS_INFO("testBufferTIDs: TC4.2");
        l_vec.clear();
        l_orig->extract(l_vec, l_max);

        // cleanup ptrs from l_orig
        TS_INFO("testBufferTIDs: TC4.3");
        l_orig->cleanup(l_vec);

        // search the trace ptrs for the expected TID traces
        bool found1{false};
        bool found3{false};
        for (auto itr : l_vec)
        {
            trace_bin_entry_t *l_entry = itr->getEntry();
            if (l_entry->stamp.tid == 1) {found1=true;}
            if (l_entry->stamp.tid == 2) {found2=true;}
            if (l_entry->stamp.tid == 3) {found3=true;}
            if (l_entry->stamp.tid == 4) {found4=true;}
            if (l_entry->stamp.tid == 6) {found6=true;}
            if (l_entry->stamp.tid == 8) {found8=true;}
        }
        // verify we found only the expected traces
        if (l_vec.size() != 6) {TS_FAIL("testBufferTIDs: TC4.3 l_vec.size:%d", l_vec.size());}
        if (!found1) {TS_FAIL("testBufferTIDs: cleanup: tid1 not found");}
        if (!found2) {TS_FAIL("testBufferTIDs: cleanup: tid2 not found");}
        if (!found3) {TS_FAIL("testBufferTIDs: cleanup: tid3 not found");}
        if (!found4) {TS_FAIL("testBufferTIDs: cleanup: tid4 not found");}
        if (!found6) {TS_FAIL("testBufferTIDs: cleanup: tid6 not found");}
        if (!found8) {TS_FAIL("testBufferTIDs: cleanup: tid8 not found");}

        // output the data from l_orig/l_vec to l_alt and verify
        TS_INFO("testBufferTIDs: TC4.4");
        l_alt->output(l_vec);
        l_vec.clear();
        l_alt->extract(l_vec, l_max);
        for (auto itr : l_vec)
        {
            trace_bin_entry_t *l_entry = itr->getEntry();
            if (l_entry->stamp.tid == 1) {found1=true;}
            if (l_entry->stamp.tid == 2) {found2=true;}
            if (l_entry->stamp.tid == 3) {found3=true;}
            if (l_entry->stamp.tid == 4) {found4=true;}
            if (l_entry->stamp.tid == 6) {found6=true;}
            if (l_entry->stamp.tid == 8) {found8=true;}
        }
        // verify we found only the expected traces
        if (l_vec.size() != 6) {TS_FAIL("testBufferTIDs: TC4.4 size:%d", l_vec.size());}
        if (!found1) {TS_FAIL("testBufferTIDs: output: tid1 not found");}
        if (!found2) {TS_FAIL("testBufferTIDs: output: tid2 not found");}
        if (!found3) {TS_FAIL("testBufferTIDs: output: tid3 not found");}
        if (!found4) {TS_FAIL("testBufferTIDs: output: tid4 not found");}
        if (!found6) {TS_FAIL("testBufferTIDs: output: tid6 not found");}
        if (!found8) {TS_FAIL("testBufferTIDs: output: tid8 not found");}

        //----------------------------------------------------------------------
        // TC5 - create a log and call collectThreadTrace
        //----------------------------------------------------------------------
        TS_INFO("testBufferTIDs: TC5");

        errlHndl_t l_errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                          ERRL_TEST_MOD_ID,
                                          ERRL_TEST_REASON_CODE);
        TS_INFO("testBufferTIDs: TC5.1");
        l_errl->collectThreadTrace();

        TS_INFO("testBufferTIDs: TC5.2");
        std::list<const char*> l_comps{"ISTEPS_TRACE","INITSVC","ERRL","FAPI","PLDM"};
        l_errl->collectThreadTrace(l_comps,4000);
        l_errl->setSev(ERRL_SEV_INFORMATIONAL);
        errlCommit(l_errl, CXXTEST_COMP_ID);

        TS_INFO("testBufferTIDs: exit");

        return;
    }
};

