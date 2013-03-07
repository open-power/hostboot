/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attntestlist.H $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
};
#endif
