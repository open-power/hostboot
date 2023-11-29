/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/test/errlAggregateTest.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

#ifndef ERRL_AGGREGATE_TEST_H
#define ERRL_AGGREGATE_TEST_H

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>

#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>

namespace err_test
{
using namespace ERRORLOG;
using namespace TARGETING;

class ErrlAggregateTest : public CxxTest::TestSuite
{
public:
    static std::vector<errlHndl_t> flattenAggregate(const errlHndl_t errl)
    {
        auto agg = errl->aggregated();
        return { begin(agg), end(agg) };
    }

    errlHndl_t errlog(const errlSeverity_t i_sev = ERRL_SEV_INFORMATIONAL,
                      uint8_t i_mod_id = 0,
                      uint16_t i_reason_code = 0,
                      uint64_t i_ud1 = 0,
                      uint64_t i_ud2 = 0)
    {
        return new ErrlEntry(i_sev, i_mod_id, i_reason_code, i_ud1, i_ud2);
    }

    template<typename Cont, typename T>
    static bool find(Cont&& container, T&& item)
    {
        using std::cbegin, std::cend;
        return std::find(cbegin(container), cend(container), item) != cend(container);
    }

    /* Test a simple single-layer aggregation, one parent and one
       child.

       This also implicitly tests aggregate child iteration.
     */
    void testBasicAggregation()
    {
#define TEST_FUNC "testBasicAggregation"

        const auto errl_parent = errlog();
        auto errl_child = errlog();
        const auto errl_child_copy = errl_child;

        errl_parent->aggregate(errl_child);

        TS_ASSERT(!errl_child,
                  "ErrlEntry::aggregate did not set child pointer "
                  "to null")

        auto all_logs = flattenAggregate(errl_parent);

        TS_ASSERT_RETURN(all_logs.size() == 2,
                         "Expected 2 logs in aggregate, got %d",
                         all_logs.size());

        TS_ASSERT_RETURN(find(all_logs, errl_parent),
                         "Cannot find parent in aggregate");

        TS_ASSERT_RETURN(find(all_logs, errl_child_copy),
                         "Cannot find child in aggregate");

        delete errl_parent;

#undef TEST_FUNC
    }

    void testMultilayerAggregation()
    {
#define TEST_FUNC "testMultilayerAggregation"

        const auto errl_grandparent = errlog();
        auto errl_parent = errlog();
        auto errl_child = errlog();

        const auto errl_parent_copy = errl_parent;
        const auto errl_child_copy = errl_child;

        errl_parent->aggregate(errl_child);
        errl_grandparent->aggregate(errl_parent);

        TS_ASSERT(!errl_child && !errl_parent,
                  "ErrlEntry::aggregate did not set child pointer "
                  "to null (%p, %p)",
                  errl_child, errl_parent);

        const auto parent_ag = flattenAggregate(errl_parent_copy);

        TS_ASSERT_RETURN(parent_ag.size() == 2,
                         "Expected 2 logs in parent aggregate, got %d",
                         parent_ag.size());

        TS_ASSERT(find(parent_ag, errl_parent_copy),
                  "Did not find parent in parent aggregate");

        TS_ASSERT(find(parent_ag, errl_child_copy),
                  "Did not find child in parent aggregate");

        const auto all_logs = flattenAggregate(errl_grandparent);

        TS_ASSERT_RETURN(all_logs.size() == 3,
                         "Expected 3 logs in grandparent aggregate, got %d",
                         all_logs.size());

        TS_ASSERT(find(all_logs, errl_child_copy),
                  "Failed to find child in grandparent aggregate");
        TS_ASSERT(find(all_logs, errl_parent_copy),
                  "Failed to find parent in grandparent aggregate");
        TS_ASSERT(find(all_logs, errl_grandparent),
                  "Failed to find grandparent in grandparent aggregate");

        delete errl_grandparent;

#undef TEST_FUNC
    }

    /**
     * @brief This function takes a setter and a getter, optionally
     * calls the setter with a "reset" value, and then calls the
     * setter on the parent error log. It then checks whether the
     * setter propagated to the child error log, and causes a testcase
     * fail if the behavior deviates from expectations.
     */
    template<typename Datum, typename Reader, typename Writer>
    static void setAndTest(const errlHndl_t parent,
                           const errlHndl_t child,
                           bool perform_reset,
                           Datum reset_datum,
                           Datum set_datum,
                           Reader read,
                           Writer set,
                           const char* property_name,
                           bool expect_propagate)
    {
        if (perform_reset)
        {
            set(parent, reset_datum);
            set(child, reset_datum);

            {
                const auto value = read(parent);
                if (value != reset_datum)
                {
                    TS_FAIL("ErrlAggregateTest: Propagation test failed "
                            "in parent setup reset for property %s; expected "
                            "%d, got %d",
                            property_name,
                            reset_datum,
                            value);
                    return;
                }
            }

            {
                const auto value = read(child);
                if (value != reset_datum)
                {
                    TS_FAIL("ErrlAggregateTest: Propagation test failed "
                            "in child setup reset for property %s; expected "
                            "%d, got %d",
                            property_name,
                            reset_datum,
                            value);
                    return;
                }
            }
        }

        set(parent, set_datum);

        {
            const auto value = read(parent);

            if (value != set_datum)
            {
                TS_FAIL("ErrlAggregateTest: Propagation test failed "
                        "in parent write for property %s; expected "
                        "%d, got %d",
                        property_name,
                        set_datum,
                        value);
                return;
            }
        }

        {
            const auto value = read(child);

            if ((value == set_datum) != expect_propagate)
            {
                TS_FAIL("ErrlAggregateTest: Propagation test failed "
                        "for property %s; expected "
                        "%s, but setter %s propagate (wanted %d, got %d)",
                        property_name,
                        expect_propagate ? "propagation" : "no propagation",
                        expect_propagate ? "did not" : "did",
                        set_datum,
                        value);
                return;
            }
        }
    }

    template<typename T>
    struct arg_type;

    template<typename Class, typename Ret, typename Arg, typename... Args>
    struct arg_type<Ret(Class::*)(Arg, Args...)>
    {
        using type = Arg;
    };

    template<auto mbr_func>
    static auto getprop()
    {
        return [](const errlHndl_t errl) -> uint64_t
        {
            return (errl->*mbr_func)();
        };
    }

    template<auto mbr_func>
    static auto setprop()
    {
        using Datum = typename arg_type<decltype(mbr_func)>::type;
        return [](const errlHndl_t errl, const uint64_t d)
        {
            (errl->*mbr_func)((Datum)d);
        };
    }

    template<typename Datum>
    struct propagation_test
    {
        const char* property_name = nullptr;
        bool expect_propagation = false;
        bool perform_reset = true; // whether to call the setter on
                                   // the parent and child with
                                   // reset_value or not.
        Datum reset_value = 0;
        Datum set_value = 0;
        Datum(*reader)(errlHndl_t) = nullptr;
        void(*writer)(errlHndl_t, Datum) = nullptr;
    };

    void testAggregatePropertyPropagation()
    {
#define TEST_FUNC "testAggregatePropertyPropagation"

        const auto errl_parent = errlog(ERRL_SEV_INFORMATIONAL);
        auto errl_child = errlog(ERRL_SEV_INFORMATIONAL);

        const auto errl_child_copy = errl_child;

        errl_parent->aggregate(errl_child);

        static const bool EXPECT_PROPAGATION = true;
        static const bool EXPECT_NO_PROPAGATION = false;

        static const bool DO_RESET = true;
        static const bool NO_RESET = false;

        static const propagation_test<uint64_t> tests[] =
        {
            /* Setters that can propagate */

            { "severity (1)", EXPECT_PROPAGATION, DO_RESET,
              ERRL_SEV_INFORMATIONAL, ERRL_SEV_UNRECOVERABLE,
              [](errlHndl_t errl) -> uint64_t { return errl->sev(); },
              [](errlHndl_t errl, uint64_t d) { errl->setSev((errlSeverity_t)d); }
            },
            { "severity (2)", EXPECT_NO_PROPAGATION, DO_RESET,
              ERRL_SEV_INFORMATIONAL, ERRL_SEV_UNRECOVERABLE,
              [](errlHndl_t errl) -> uint64_t { return errl->sev(); },
              [](errlHndl_t errl, uint64_t d) {
                  errl->setSev((errlSeverity_t)d, false, propagation_t::NO_PROPAGATE);
              }
            },

            { "plid (1)", EXPECT_PROPAGATION, NO_RESET, 0,
              0x123,
              [](errlHndl_t errl) -> uint64_t { return errl->plid(); },
              [](errlHndl_t errl, uint64_t d) { errl->plid(d); }
            },
            { "plid (2)", EXPECT_NO_PROPAGATION, NO_RESET, 0,
              0x456, // only the first aggregate plid() call (i.e. the
                     // one from the testcase above) will have an
                     // effect
              [](errlHndl_t errl) -> uint64_t { return errl->plid(); },
              [](errlHndl_t errl, uint64_t d) { errl->plid(d); }
            },

            { "addFFDC (1)", EXPECT_PROPAGATION, DO_RESET,
              0, 1,
              [](errlHndl_t errl) -> uint64_t { return errl->iv_SectionVector.size(); },
              [](errlHndl_t errl, uint64_t value) {
                  if (value == 0) errl->iv_SectionVector.clear();
                  else errl->addFFDC(0, "hi", 2, 1, 1, false, propagation_t::PROPAGATE);
              }
            },
            { "addFFDC (2)", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              [](errlHndl_t errl) -> uint64_t { return errl->iv_SectionVector.size(); },
              [](errlHndl_t errl, uint64_t value) {
                  if (value == 0) errl->iv_SectionVector.clear();
                  else errl->addFFDC(0, "hi", 2, 1, 1, false, propagation_t::NO_PROPAGATE);
              }
            },

            { "collectTrace (1)", EXPECT_PROPAGATION, DO_RESET,
              0, 1,
              [](errlHndl_t errl) -> uint64_t { return errl->iv_SectionVector.size(); },
              [](errlHndl_t errl, uint64_t value) {
                  if (value == 0) errl->iv_SectionVector.clear();
                  else errl->collectTrace(SBEIO_COMP_NAME, 256);
              }
            },
            { "collectTrace (2)", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              [](errlHndl_t errl) -> uint64_t { return errl->iv_SectionVector.size(); },
              [](errlHndl_t errl, uint64_t value) {
                  if (value == 0) errl->iv_SectionVector.clear();
                  else errl->collectTrace(SBEIO_COMP_NAME, 256, propagation_t::NO_PROPAGATE);
              }
            },

            { "setDeconfigState (1)", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              [](errlHndl_t errl) -> uint64_t {
                  return ((errl->queryCallouts(UTIL::assertGetToplevelTarget(),
                                               nullptr,
                                               propagation_t::NO_PROPAGATE)
                             & ErrlEntry::DECONFIG_FOUND)
                          == ErrlEntry::DECONFIG_FOUND);
              },
              [](errlHndl_t errl, uint64_t value) {
                  if (value == 0) {
                      errl->iv_SectionVector.clear();
                      errl->iv_UDDataHashes.clear();
                      errl->addHwCallout(UTIL::assertGetToplevelTarget(),
                                         HWAS::SRCI_PRIORITY_HIGH,
                                         HWAS::NO_DECONFIG,
                                         HWAS::GARD_NULL);
                  } else {
                      errl->setDeconfigState(UTIL::assertGetToplevelTarget(),
                                             HWAS::DELAYED_DECONFIG,
                                             HWAS::ALL_STYLE,
                                             HWAS::HW_CALLOUT,
                                             propagation_t::NO_PROPAGATE);
                  }
              }
            },

            { "setDeconfigState (2)", EXPECT_PROPAGATION, DO_RESET,
              0, 1,
              [](errlHndl_t errl) -> uint64_t {
                  return ((errl->queryCallouts(UTIL::assertGetToplevelTarget(),
                                               nullptr,
                                               propagation_t::NO_PROPAGATE)
                             & ErrlEntry::DECONFIG_FOUND)
                          == ErrlEntry::DECONFIG_FOUND);
              },
              [](errlHndl_t errl, uint64_t value) {
                  if (value == 0) {
                      errl->iv_SectionVector.clear();
                      errl->iv_UDDataHashes.clear();
                      errl->addHwCallout(UTIL::assertGetToplevelTarget(),
                                         HWAS::SRCI_PRIORITY_HIGH,
                                         HWAS::NO_DECONFIG,
                                         HWAS::GARD_NULL);
                  } else {
                      errl->setDeconfigState(UTIL::assertGetToplevelTarget(),
                                             HWAS::DELAYED_DECONFIG,
                                             HWAS::ALL_STYLE,
                                             HWAS::HW_CALLOUT,
                                             propagation_t::PROPAGATE);
                  }
              }
            },

            /* Setters that can't propagate */

            { "reasoncode", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              getprop<&ErrlEntry::reasonCode>(),
              setprop<&ErrlEntry::setReasonCode>()
            },
            { "module ID", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              getprop<&ErrlEntry::moduleId>(),
              setprop<&ErrlEntry::setModuleId>()
            },
            { "event type", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              getprop<&ErrlEntry::eventType>(),
              setprop<&ErrlEntry::setEventType>()
            },
            { "action flags", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              getprop<&ErrlEntry::actionFlags>(),
              setprop<&ErrlEntry::updateActionFlags>()
            },
            { "subsys", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              getprop<&ErrlEntry::subSys>(),
              setprop<&ErrlEntry::setSubSys>()
            },
            { "srcType", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              getprop<&ErrlEntry::srcType>(),
              setprop<&ErrlEntry::setSrcType>()
            },
            { "termState", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              getprop<&ErrlEntry::termState>(),
              setprop<&ErrlEntry::setTermState>()
            },
            { "userdata1", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              getprop<&ErrlEntry::getUserData1>(),
              setprop<&ErrlEntry::addUserData1>()
            },
            { "userdata2", EXPECT_NO_PROPAGATION, DO_RESET,
              0, 1,
              getprop<&ErrlEntry::getUserData2>(),
              setprop<&ErrlEntry::addUserData2>()
            },
        };

        for (const auto& test : tests)
        {
            setAndTest(errl_parent, errl_child_copy,
                       test.perform_reset,
                       test.reset_value, test.set_value,
                       test.reader, test.writer,
                       test.property_name, test.expect_propagation);
        }

        delete errl_parent;

#undef TEST_FUNC
    }

    void testHasUserData()
    {
#define TEST_FUNC "testHasUserData"

        auto parent = errlog();
        auto child = errlog();

        parent->addUserData1(1);
        parent->addUserData2(2);
        child->addUserData1(3);
        child->addUserData2(4);

        // We haven't aggregated the errors yet; parent should have
        // userdata1=1, userdata2=2, and child should have
        // userdata1=3, userdata2=4.

        // Check the parent.

        TS_ASSERT(parent->hasUserData1(1),
                  "Parent does not have userdata1=1");
        TS_ASSERT(parent->hasUserData2(2),
                  "Parent does not have userdata2=2");
        TS_ASSERT(!parent->hasUserData1(3),
                  "Parent has userdata1=3");
        TS_ASSERT(!parent->hasUserData2(4),
                  "Parent has userdata2=4");

        TS_ASSERT(!parent->hasUserData1(-1),
                  "Parent has userdata1=-1");
        TS_ASSERT(!parent->hasUserData2(-1),
                  "Parent has userdata2=-1");

        // Check the child.

        TS_ASSERT(!child->hasUserData1(1),
                  "Child hasuserdata1=1");
        TS_ASSERT(!child->hasUserData2(2),
                  "Child has userdata2=2");
        TS_ASSERT(child->hasUserData1(3),
                  "Child does not have userdata1=3");
        TS_ASSERT(child->hasUserData2(4),
                  "Child does not have userdata2=4");
        TS_ASSERT(!child->hasUserData1(-1),
                  "Child has userdata1=-1");
        TS_ASSERT(!child->hasUserData2(-1),
                  "Child has userdata2=-1");

        parent->aggregate(child);

        // Now that they're aggregated, check the parent again. It
        // should have the userdata of the parent and the child.

        TS_ASSERT(parent->hasUserData1(1),
                  "Aggregated parent does not have userdata1=1");
        TS_ASSERT(parent->hasUserData2(2),
                  "Aggregated parent does not have userdata2=2");
        TS_ASSERT(parent->hasUserData1(3),
                  "Aggregated parent does not have userdata1=3");
        TS_ASSERT(parent->hasUserData2(4),
                  "Aggregated parent does not have userdata2=4");

        TS_ASSERT(!parent->hasUserData1(-1),
                  "Aggregated parent has userdata1=-1");
        TS_ASSERT(!parent->hasUserData2(-1),
                  "Aggregated parent has userdata2=-1");

        delete parent;

#undef TEST_FUNC
    }

    void testAggregateHelper()
    {
#define TEST_FUNC "testAggregateHelper"

        auto errl_parent = errlog();
        auto errl_child = errlog();
        auto errl_child2 = errlog();

        std::vector<errlHndl_t> child_cont { errl_child, errl_child2 };

        aggregate(errl_parent, child_cont);

        auto all_logs = flattenAggregate(errl_parent);

        TS_ASSERT_RETURN(all_logs.size() == 3,
                         "Expected 3 logs in aggregate, got %d",
                         all_logs.size());

        TS_ASSERT(find(all_logs, errl_child),
                  "Failed to find child 1 in aggregate");
        TS_ASSERT(find(all_logs, errl_child2),
                  "Failed to find child 2 in aggregate");
        TS_ASSERT(find(all_logs, errl_parent),
                  "Failed to find parent in aggregate");

        delete errl_parent;

#undef TEST_FUNC
    }

    void testQueryCallouts()
    {
#define TEST_FUNC "testQueryCallouts"

        auto errl_child = errlog();

        errl_child->addHwCallout(UTIL::assertGetToplevelTarget(),
                                 HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::DELAYED_DECONFIG,
                                 HWAS::GARD_NULL);

        auto errl_child2 = errlog();

        errl_child2->addHwCallout(UTIL::assertGetToplevelTarget(),
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::NO_DECONFIG,
                                  HWAS::GARD_Fatal);

        auto errl_parent = errlog();

        auto check = [](const char* testname,
                        const errlHndl_t errl,
                        const unsigned long num_expected_deconfigs,
                        const unsigned long num_expected_gards,
                        const propagation_t i_behavior
                            = propagation_t::PROPAGATE)
        {
            ErrlEntry::deconfig_and_gard_records recs;
            const auto mask
                = errl->queryCallouts(UTIL::assertGetToplevelTarget(),
                                      &recs,
                                      i_behavior);

            {
                const auto num_deconfigs
                    = std::count(begin(recs.deconfigs), end(recs.deconfigs), HWAS::DELAYED_DECONFIG);
                const auto num_gards
                    = std::count(begin(recs.gards), end(recs.gards), HWAS::GARD_Fatal);

                TS_ASSERT(num_deconfigs == num_expected_deconfigs,
                          "Found %d deconfigs in %s callouts, expected %d",
                          num_deconfigs, testname, num_expected_deconfigs);

                TS_ASSERT(num_gards == num_expected_gards,
                          "Found %d gards in the %s callouts, expected %d",
                          num_gards, testname, num_expected_gards);
            }

            const bool want_target = num_expected_deconfigs || num_expected_gards;
            const bool want_deconfig = num_expected_deconfigs;
            const bool want_gard = num_expected_gards;

            TS_ASSERT(((mask & ErrlEntry::TARGET_MATCH) != 0) == want_target,
                      "%s TARGET_MATCH in %s mask",
                      want_target ? "Did not find" : "found",
                      testname);
            TS_ASSERT(((mask & ErrlEntry::DECONFIG_FOUND) != 0) == want_deconfig,
                      "%s DECONFIG_FOUND in %s mask",
                      want_deconfig ? "Did not find" : "found",
                      testname);
            TS_ASSERT(((mask & ErrlEntry::GARD_FOUND) != 0) == want_gard,
                      "%s GARD_FOUND in %s mask",
                      want_gard ? "Did not find" : "found",
                      testname);
        };

        /* Make sure that the parent log doesn't have any logs first */

        check("unaggregated parent", errl_parent, 0, 0);

        /* Make sure the children have callouts */

        check("child", errl_child, 1, 0);
        check("child2", errl_child2, 0, 1);

        /* Aggregate the children, and then check the callouts
         * again. We should find callouts from both the child and the
         * grandparent logs. */

        errl_child->aggregate(errl_child2);
        errl_parent->aggregate(errl_child);

        check("aggregated parent", errl_parent, 1, 1);

        /* Now disable propagation and make sure we don't get
         * anything */

        check("aggregated parent (no propagation)",
              errl_parent, 0, 0,
              propagation_t::NO_PROPAGATE);

        /* Now add a callout to the parent, and make sure we get it
         * even without propagation */

        errl_parent->addHwCallout(UTIL::assertGetToplevelTarget(),
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::NO_DECONFIG,
                                  HWAS::GARD_Fatal);

        check("aggregated parent (no propagation, callout)",
              errl_parent, 0, 1,
              propagation_t::NO_PROPAGATE);

        delete errl_parent;

#undef TEST_FUNC
    }

    void testNonPropagatingRemoveGardAndDeconfigure()
    {
#define TEST_FUNC "testNonPropagatingRemoveGardAndDeconfigure"

        const auto sys = UTIL::assertGetToplevelTarget();

        auto errl_parent = errlog();

        errl_parent->addHwCallout(sys,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::DELAYED_DECONFIG,
                                  HWAS::GARD_NULL);

        auto errl_child_orig = errlog();
        auto errl_child = errl_child_orig;

        errl_child->addHwCallout(sys,
                                 HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_Fatal);

        errl_parent->aggregate(errl_child_orig);

        TS_ASSERT(errl_parent->queryCallouts(sys, nullptr, propagation_t::NO_PROPAGATE)
                      == (ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND),
                  "Did not find callouts in parent before removing");
        TS_ASSERT(errl_child->queryCallouts(sys, nullptr, propagation_t::NO_PROPAGATE)
                      == (ErrlEntry::TARGET_MATCH | ErrlEntry::GARD_FOUND),
                  "Did not find callouts in child before removing");

        errl_parent->removeGardAndDeconfigure(propagation_t::NO_PROPAGATE);

        TS_ASSERT(errl_parent->queryCallouts(sys, nullptr, propagation_t::NO_PROPAGATE)
                      == ErrlEntry::TARGET_MATCH,
                  "Found callouts in parent after removing from parent");
        TS_ASSERT(errl_child->queryCallouts(sys, nullptr, propagation_t::NO_PROPAGATE)
                      == (ErrlEntry::TARGET_MATCH | ErrlEntry::GARD_FOUND),
                  "Did not find callouts in child after removing from parent");

        errl_child->removeGardAndDeconfigure(propagation_t::NO_PROPAGATE);

        TS_ASSERT(errl_parent->queryCallouts(sys, nullptr, propagation_t::NO_PROPAGATE)
                      == ErrlEntry::TARGET_MATCH,
                  "Found callouts in parent after removing from child");
        TS_ASSERT(errl_child->queryCallouts(sys, nullptr, propagation_t::NO_PROPAGATE)
                      == ErrlEntry::TARGET_MATCH,
                  "Found callouts in child after removing from child");

        delete errl_parent;

#undef TEST_FUNC
    }

    void testPropagatingRemoveGardAndDeconfigure()
    {
#define TEST_FUNC "testPropagatingRemoveGardAndDeconfigure"

        const auto sys = UTIL::assertGetToplevelTarget();

        auto errl_parent = errlog();

        errl_parent->addHwCallout(sys,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::DELAYED_DECONFIG,
                                  HWAS::GARD_NULL);

        auto errl_child_orig = errlog();
        auto errl_child = errl_child_orig;

        errl_child_orig->addHwCallout(sys,
                                      HWAS::SRCI_PRIORITY_HIGH,
                                      HWAS::NO_DECONFIG,
                                      HWAS::GARD_Fatal);

        errl_parent->aggregate(errl_child_orig);

        TS_ASSERT(errl_parent->queryCallouts(sys, nullptr, propagation_t::NO_PROPAGATE)
                      == (ErrlEntry::TARGET_MATCH | ErrlEntry::DECONFIG_FOUND),
                  "Did not find callouts in parent before removing");
        TS_ASSERT(errl_child->queryCallouts(sys, nullptr, propagation_t::NO_PROPAGATE)
                      == (ErrlEntry::TARGET_MATCH | ErrlEntry::GARD_FOUND),
                  "Did not find callouts in child before removing");

        errl_parent->removeGardAndDeconfigure(propagation_t::PROPAGATE);

        TS_ASSERT(errl_parent->queryCallouts(sys, nullptr, propagation_t::NO_PROPAGATE)
                      == ErrlEntry::TARGET_MATCH,
                  "Found callouts in parent after removing");
        TS_ASSERT(errl_child->queryCallouts(sys, nullptr, propagation_t::NO_PROPAGATE)
                      == ErrlEntry::TARGET_MATCH,
                  "Found callouts in child after removing");

        delete errl_parent;

#undef TEST_FUNC
    }

    void testGetUDSections()
    {
#define TEST_FUNC "testGetUDSections"

        const int ffdc_parent = 1234, ffdc_child = 4321;

        const int COMP_ID = 1, SUBSECT = 10;

        auto errl_parent = errlog();

        errl_parent->addFFDC(COMP_ID, &ffdc_parent, sizeof(ffdc_parent), 1, SUBSECT, false, propagation_t::NO_PROPAGATE);

        auto errl_child_orig = errlog();
        auto errl_child = errl_child_orig;

        errl_child_orig->addFFDC(COMP_ID, &ffdc_child, sizeof(ffdc_child), 1, SUBSECT, false, propagation_t::NO_PROPAGATE);

        errl_parent->aggregate(errl_child_orig);

        {
            auto sects = errl_parent->getUDSections(COMP_ID, SUBSECT, propagation_t::NO_PROPAGATE);

            TS_ASSERT_RETURN(sects.size() == 1,
                             "Did not find 1 UD section in parent log (found %d)",
                             sects.size());

            const int ffdc = *reinterpret_cast<const int*>(sects[0]);
            TS_ASSERT(ffdc == ffdc_parent,
                      "FFDC does not match in parent (expected %d, got %d)",
                      ffdc_parent, ffdc);
        }

        {
            auto sects = errl_child->getUDSections(COMP_ID, SUBSECT, propagation_t::NO_PROPAGATE);

            TS_ASSERT_RETURN(sects.size() == 1,
                             "Did not find 1 UD section in child log (found %d)",
                             sects.size());

            const int ffdc = *reinterpret_cast<const int*>(sects[0]);
            TS_ASSERT(ffdc == ffdc_child,
                      "FFDC does not match in child (expected %d, got %d)",
                      ffdc_child, ffdc);
        }

        {
            auto sects = errl_parent->getUDSections(COMP_ID, SUBSECT, propagation_t::PROPAGATE);

            TS_ASSERT_RETURN(sects.size() == 2,
                             "Did not find 2 UD section in aggregate log (found %d)",
                             sects.size());

            {
                const int ffdc = *reinterpret_cast<const int*>(sects[0]);
                TS_ASSERT(ffdc == ffdc_parent,
                          "FFDC does not match parent in aggregate (expected %d, got %d)",
                          ffdc_parent, ffdc);
            }

            {
                const int ffdc = *reinterpret_cast<const int*>(sects[1]);
                TS_ASSERT(ffdc == ffdc_child,
                          "FFDC does not match child in aggregate (expected %d, got %d)",
                          ffdc_child, ffdc);
            }
        }

        delete errl_parent;

#undef TEST_FUNC
    }

    void testHasErrorType()
    {
#define TEST_FUNC "testHasErrorType"

        const int PARENT_TYPE = 1, CHILD_TYPE = 2;

        auto errl_parent = errlog();
        auto errl_child_orig = errlog();
        auto errl_child = errl_child_orig;

        errl_parent->setErrorType(PARENT_TYPE);
        errl_child->setErrorType(CHILD_TYPE);

        errl_parent->aggregate(errl_child_orig);

        TS_ASSERT(errl_parent->hasErrorType(PARENT_TYPE, propagation_t::NO_PROPAGATE),
                  "Parent log doesn't have parent error type");
        TS_ASSERT(errl_child->hasErrorType(CHILD_TYPE, propagation_t::NO_PROPAGATE),
                  "Child log doesn't have child error type");

        TS_ASSERT(!errl_parent->hasErrorType(CHILD_TYPE, propagation_t::NO_PROPAGATE),
                  "Parent log has child error type");
        TS_ASSERT(!errl_child->hasErrorType(PARENT_TYPE, propagation_t::NO_PROPAGATE),
                  "Child log has parent error type");

        TS_ASSERT(errl_parent->hasErrorType(CHILD_TYPE, propagation_t::PROPAGATE),
                  "Parent log doesn't have child error type with propagation");

        delete errl_parent;

#undef TEST_FUNC
    }

    void testIterator()
    {
#define TEST_FUNC "testIterator"

        auto not_in_aggregate = errlog();

        std::vector<errlHndl_t> all_logs;

        auto parent = errlog();

        TS_INFO("ErrlAggregateTest::" TEST_FUNC ": Layer 0 = 0x%08X",
                ERRL_GETEID_SAFE(parent));

        all_logs.push_back(parent);

        for (int i = 0; i < 3; ++i)
        {
            auto child = errlog();
            TS_INFO("ErrlAggregateTest::" TEST_FUNC ": Layer 1 = 0x%08X",
                    ERRL_GETEID_SAFE(child));
            all_logs.push_back(child);

            for (int j = 0; j < 5; ++j)
            {
                auto child2 = errlog();
                TS_INFO("ErrlAggregateTest::" TEST_FUNC ": Layer 2 = 0x%08X",
                        ERRL_GETEID_SAFE(child2));
                all_logs.push_back(child2);

                for (int k = 0; k < 2; ++k)
                {
                    auto child3 = errlog();
                    TS_INFO("ErrlAggregateTest::" TEST_FUNC ": Layer 3 = 0x%08X",
                            ERRL_GETEID_SAFE(child3));
                    all_logs.push_back(child3);
                    child2->aggregate(child3);
                }

                child->aggregate(child2);
            }

            parent->aggregate(child);
        }

        auto aggregated = parent->aggregated();
        const std::vector<errlHndl_t> collapsed(begin(aggregated), end(aggregated));

        TS_ASSERT(collapsed.size() == all_logs.size(),
                  "Not all logs were captured in the aggregate; got %d, wanted %d",
                  collapsed.size(), all_logs.size());

        TS_ASSERT(!find(collapsed, not_in_aggregate),
                  "Found log that was not supposed to be in the aggregate!");

        for (const auto log : all_logs)
        {
            TS_ASSERT(find(collapsed, log),
                      "Cannot find 0x%08X in the aggregate",
                      ERRL_GETEID_SAFE(log));
        }

        delete parent;
        delete not_in_aggregate;

#undef TEST_FUNC
    }
};

}

using err_test::ErrlAggregateTest;

#endif
