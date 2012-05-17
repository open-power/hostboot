/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attntestlist.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __TEST_ATTNTESTLIST_H
#define __TEST_ATTNTESTLIST_H

/**
 * @file attntestlist.H
 *
 * @brief Unit test for the attnlist module.
 */

#include "../attnfwd.H"
#include "../attnlist.H"
#include <cxxtest/TestSuite.H>

using namespace ATTN;
using namespace TARGETING;
using namespace PRDF;

/**
 * @brief CounterFunct Functor for testing the forEach method.
 */
struct CounterFunct
{
    uint64_t counter;

    CounterFunct() : counter(0) {}

    void operator()(const Attention &)
    {
        counter++;
    }
};

/**
 * @brief CheckstopPredicate Predicate for testing split method.
 */
struct CheckstopPredicate
{
    bool operator()(const Attention & i_attn)
    {
        AttnData d;

        i_attn.getData(d);

        return d.attnType == CHECK_STOP;
    }
};

/**
 * @brief AttnListTest Unit test for the attnlist module.
 */
class AttnListTest : public CxxTest::TestSuite
{
    public:

        /**
         * @brief testEmpty Unit test for the
         *        empty method.
         */
        void testEmpty(void)
        {
            static AttentionOps * nullOps = 0;

            TS_TRACE(ENTER_MRK "testEmpty");

            do {

                AttentionList l;

                if(!l.empty())
                {
                    TS_FAIL("Defalt constructed attention list not empty");
                    break;
                }

                l.add(Attention(AttnData(), nullOps));

                if(l.empty())
                {
                    TS_FAIL("Attention list empty after insert");
                    break;
                }

            } while(0);

            TS_TRACE(EXIT_MRK "testEmpty");
        }

        /**
         * @brief testInsert Unit test for the
         *        insert method.
         */
        void testInsert(void)
        {
            static AttentionOps * nullOps = 0;
            static const uint64_t size = 10;

            TS_TRACE(ENTER_MRK "testInsert");

            AttentionList l;

            for(uint64_t count = 0; count < size; ++count)
            {
                l.add(Attention(AttnData(), nullOps));
            }

            // verify correct number of elements inserted

            if(l.size() != size)
            {
                TS_FAIL("Unexpected number of elements inserted: %d", l.size());
            }

            AttentionList::iterator it2 = l.begin();
            AttentionList::iterator it1 = it2;
            it2++;

            while(it2 != l.end())
            {
                if((*it2) < (*it1))
                {
                    TS_FAIL("Attention list not sorted");
                    break;
                }

                ++it1;
                ++it2;
            }

            l.clear();

            if(!l.empty())
            {
                TS_FAIL("Attention list not cleared");
            }

            TS_TRACE(EXIT_MRK "testInsert");
        }

        /**
         * @brief testGetAttnList Unit test for the
         *        getAttnList method.
         */
        void testGetAttnList(void)
        {
            static AttentionOps * nullOps = 0;
            static const TargetHandle_t nullTarget = 0;

            static const AttnData tests[] =
            {
                {nullTarget, CHECK_STOP},
                {nullTarget +1, CHECK_STOP},
                {nullTarget +2, CHECK_STOP},
                {nullTarget, RECOVERABLE},
                {nullTarget +1, RECOVERABLE},
                {nullTarget +2, RECOVERABLE},
            };
            static const AttnData * testsEnd = tests
                + sizeof(tests)/sizeof(*tests);

            TS_TRACE(ENTER_MRK "testGetAttnList");

            const AttnData * testIt = tests;

            AttentionList attentionList;

            while(testIt != testsEnd)
            {
                AttentionList l;
                l.add(Attention(*testIt, nullOps));
                attentionList.add(Attention(*testIt, nullOps));

                AttnList attnList;
                l.getAttnList(attnList);

                if(attnList.size() != 1
                        || attnList[0].targetHndl != testIt->targetHndl
                        || attnList[0].attnType != testIt->attnType)
                {
                    TS_FAIL("Unexpected error calling getAttnList");
                    break;
                }

                ++testIt;
            }

            AttnList l;
            attentionList.getAttnList(l);

            testIt = tests;

            while(testIt != testsEnd)
            {
                if(static_cast<uint64_t>(testIt - tests) >= l.size())
                {
                    TS_FAIL("Unexpected number of elements");
                    break;
                }

                AttnData & d = l[testIt - tests];

                if(d.targetHndl != testIt->targetHndl
                        || d.attnType != testIt->attnType)
                {
                    TS_FAIL("Unexpected error calling getAttnList");
                    break;
                }

                ++testIt;
            }

            TS_TRACE(EXIT_MRK "testGetAttnData");
        }

        /**
         * @brief testForEach Unit test for the
         *        forEach method.
         */
        void testForEach(void)
        {
            static AttentionOps * nullOps = 0;
            static const uint64_t size = 10;

            TS_TRACE(ENTER_MRK "testForEach");

            AttentionList l;

            for(uint64_t count = 0; count < size; ++count)
            {
                l.add(Attention(AttnData(), nullOps));
            }

            if(l.forEach(CounterFunct()).counter != size)
            {
                TS_FAIL("Unexpected result calling forEach");
            }

            TS_TRACE(EXIT_MRK "testForEach");
        }

        /**
         * @brief testSplit Unit test for the
         *        split method.
         */
        void testSplit(void)
        {
            static AttentionOps * nullOps = 0;
            static const TargetHandle_t nullTarget = 0;

            static const AttnData tests[] =
            {
                {nullTarget, CHECK_STOP},
                {nullTarget +2, CHECK_STOP},
                {nullTarget, RECOVERABLE},
                {nullTarget +1, RECOVERABLE},
                {nullTarget +2, RECOVERABLE},
                {nullTarget +1, CHECK_STOP},
            };
            static const AttnData * testsEnd = tests
                + sizeof(tests)/sizeof(*tests);

            TS_TRACE(ENTER_MRK "testSplit");

            const AttnData * testIt = tests;

            uint64_t xstpCount = 0;

            AttentionList l;

            while(testIt != testsEnd)
            {
                l.add(Attention(*testIt, nullOps));

                if(testIt->attnType == CHECK_STOP)
                {
                    ++xstpCount;
                }
                ++testIt;
            }

            AttentionList t, f;
            l.split(t, f, CheckstopPredicate());

            if(t.size() != xstpCount
                    || f.size() != static_cast<uint64_t>((
                            testsEnd - tests)) - xstpCount)
            {
                TS_FAIL("Unexpected result calling split");
            }

            AttentionList::iterator tit = t.begin();
            AttentionList::iterator fit = f.begin();

            while(tit != t.end() && fit != f.end())
            {
                AttnData td, fd;
                tit->getData(td);
                fit->getData(fd);

                if(td.attnType != CHECK_STOP
                        || fd.attnType != RECOVERABLE)
                {
                    TS_FAIL("Unexpected result calling split");
                    break;
                }

                ++tit;
                ++fit;
            }

            TS_TRACE(EXIT_MRK "testSplit");
        }

        /**
         * @brief testMerge Unit test for the
         *        merge method.
         */
        void testMerge(void)
        {
            static AttentionOps * nullOps = 0;
            static const TargetHandle_t nullTarget = 0;

            static const struct Tests
            {
              AttnData a;
              AttnData b;

            } tests[] =
            {
                {{nullTarget +1, CHECK_STOP}, {nullTarget +2, RECOVERABLE}},
                {{nullTarget +3, SPECIAL}, {nullTarget +4, RECOVERABLE}},
                {{nullTarget +5, CHECK_STOP}, {nullTarget +6, RECOVERABLE}},
                {{nullTarget +7, SPECIAL}, {nullTarget +8, RECOVERABLE}},
                {{nullTarget +9, CHECK_STOP}, {nullTarget +10, SPECIAL}},
            };
            static const Tests * testsEnd = tests
                + sizeof(tests)/sizeof(*tests);

            TS_TRACE(EXIT_MRK "testMerge");

            const Tests * testIt = tests;

            AttentionList l1, l2;

            while(testIt != testsEnd)
            {
                l1.add(Attention(testIt->a, nullOps));
                l2.add(Attention(testIt->b, nullOps));

                ++testIt;
            }

            l1.merge(l2);

            if(l1.size() != static_cast<uint64_t>((testsEnd - tests) * 2))
            {
                TS_FAIL("Attention list not merged");
            }

            AttentionList::iterator it2 = l1.begin();
            AttentionList::iterator it1 = it2;
            it2++;

            while(it2 != l1.end())
            {
                if((*it2) < (*it1))
                {
                    TS_FAIL("Attention list not sorted");
                    break;
                }

                ++it1;
                ++it2;
            }

            TS_TRACE(EXIT_MRK "testMerge");
        }
};
#endif
