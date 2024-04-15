/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/ocmbupd/ody_upd_fsm.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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

/** @brief This file contains the implementation of the Odyssey Code
 *  Update FSM. The FSM is invoked whenever an Odyssey-related event
 *  occurs in the boot (i.e. an Odyssey fails to boot, or reaches
 *  update_omi_firmware successfully, or a code update operation
 *  fails, etc.) and takes actions based on that event. (Actions
 *  include switching boot sides, deconfiguring an OCMB, updating
 *  code, etc.)
 */

#include <array>

#include <fapi2/target.H>
#include <attributeenums.H>

#include <console/consoleif.H>
#include <sbeio/sbeioif.H>
#include <sbeio/errlud_sbeio.H>

#include <ocmbupd/ocmbupd.H>
#include <ocmbupd/ocmbupd_trace.H>
#include <ocmbupd/ody_upd_fsm.H>
#include <ocmbupd/ocmbupd_reasoncodes.H>

#include <targeting/odyutil.H>

#include <hwas/common/hwas.H>

#include <errl/hberrltypes.H>
#include <errl/errludstring.H>

#include <hwpThreadHelper.H>

using namespace TARGETING;
using namespace ERRORLOG;
using namespace errl_util;
using namespace OCMBUPD;
using namespace ocmbupd;
using namespace SBEIO;

using std::begin;
using std::cbegin;
using std::cend;

namespace ocmbupd
{

extern ocmbupd::ocmbfw_owning_ptr_t OCMBFW_HANDLE;

}

#define TRACF(...) TRACFCOMP(g_trac_ocmbupd, __VA_ARGS__)

/** @brief This enumeration describes the actions that can be taken in response to a code
 *  update event.
 */
enum update_action_t : uint8_t
{
    do_nothing               = 0,

    // These alter the severity of the error log related to an event, if there is one. These
    // aren't used right now but may be used if an event (like an HWP error) needs to
    // suppress the error log that caused it. Currently the severity is captured in
    // higher-level operations, e.g. deconfigure_ocmb creates an unrecoverable log.
    mark_error_predictive    = 1,
    mark_error_recovered     = 2,
    mark_error_unrecoverable = 3,

    perform_code_update      = 4,

    // Deconfigures but does not gard the OCMB. Use deconfig_gard_ocmb to deconfig & gard
    deconfigure_ocmb         = 5,
    fail_boot_bad_firmware   = 6,

    // Resets the code update FSM state on the given OCMB.
    reset_ocmb_upd_state     = 7,

    sync_images_normal       = 8,
    sync_images_forced       = 9,

    // Side-switching actions.

    // In addition to switching sides, these actions will set the severity of any related
    // error logs to RECOVERED. (This is just so that we don't have all the mark_error_*
    // actions cluttering up the table.) If there is an explicit mark_error_* action
    // alongside a switch_to_side_* in the action list for a transition, the explicit
    // mark_error_* action will take precedence over the implicit severity of these
    // side-switching actions.
    switch_to_side_0         = 0xA,
    switch_to_side_1         = 0xB,
    switch_to_side_golden    = 0xC,

    // This may mean a reconfig loop is necessary, depending on where in the IPL the event
    // happens. Whether one is required or not is determined by the caller.
    retry_check_for_ready    = 0xD, // retry_check_for_ready must ALWAYS be preceded by a side switch
                                    // (even if that "side switch" is just switching to the side that
                                    // is currently active, in case you want to retry the check_for_ready
                                    // loop without switching sides) so that the FSM can keep track of what
                                    // sides have been attempted before.

    deconfig_gard_ocmb       = 0xE,

    // This means that an invalid state/event combination has happened.
    internal_error           = 0xFF
};

/** @brief Enumeration corresponding to Odyssey boot sides. These elements can be OR'd
 *  together to make a bit set.
 */
enum ocmb_boot_side_t : uint8_t
{
    SIDE0 = 1 << 0,
    SIDE1 = 1 << 1,
    GOLDEN = 1 << 2
};

/** @brief A tristate enumeration. These elements can be OR'd together to make a bit set.
 */
enum tristate_t : uint8_t
{
    yes = 1 << 0,
    no = 1 << 1,
    unknown = 1 << 2
};

/** @brief A convenience structure to make initializing the table below easier.
 */
struct ody_upd_event_s
{
    constexpr ody_upd_event_s(const ody_upd_event_t t) : event(t) { }
    constexpr ody_upd_event_s(const unsigned int t) : event(static_cast<ody_upd_event_t>(t)) { }

    constexpr operator ody_upd_event_t() const
    {
        return event;
    }

    ody_upd_event_t event;
};

/** @brief A convenience structure to make initializing the table below easier.
 */
struct ocmb_boot_side_s
{
    constexpr ocmb_boot_side_s(const ocmb_boot_side_t t) : side(t) { }
    constexpr ocmb_boot_side_s(const unsigned int t) : side(static_cast<ocmb_boot_side_t>(t)) { }

    constexpr operator ocmb_boot_side_t() const
    {
        return side;
    }

    ocmb_boot_side_t side;
};

/** @brief A convenience structure to make initializing the table below easier.
 */
struct tristate_s
{
    constexpr tristate_s(const tristate_t t) : state(t) { }
    constexpr tristate_s(const unsigned int t) : state(static_cast<tristate_t>(t)) { }

    constexpr operator tristate_t() const
    {
        return state;
    }

    tristate_t state;
};

/** @brief This structure represents all of the state of an OCMB at a single point in time that
 *  the code update FSM needs to know to make decisions.
 */
struct state_t
{
    tristate_s update_performed = no; // can't be unknown

    // Note that golden_boot_performed is only true if the boot side was set to GOLDEN on
    // some *previous* attempt. i.e. just because boot side=GOLDEN doesn't mean "Golden boot
    // performed?" is true.
    tristate_s golden_boot_performed = no; // can't be unknown

    ocmb_boot_side_s ocmb_boot_side = SIDE0;
    tristate_s ocmb_fw_up_to_date = no;
};

/** @brief An event and actions to take when that event occurs.
 */
struct state_transition_t
{
    // This array may need to be expanded in the future if
    // we need to handle more than 4 actions.
    static const int MAX_ACTIONS = 4;

    ody_upd_event_s event = NO_EVENT;
    update_action_t actions[MAX_ACTIONS] = { };
};

/** @brief A state, and a set of transitions for possible events that can happen in that
 *  state.
 */
struct state_transitions_t
{
    // This array may need to be expanded in the future if
    // we need to handle more than 4 transitions.
    static const int MAX_TRANSITIONS = 5;

    state_t state;
    state_transition_t transitions[MAX_TRANSITIONS];
};

/** @brief This table describes the Odyssey code update state machine.
 *
 *  Each entry describes a state and a list of possible transitions/actions that can occur
 *  in that state. The actions will determine what happens and what state the FSM goes to
 *  next. The actions are performed in order from left to right.
 *
 *  Note that "Golden boot performed?" is only true if Side was set to GOLDEN on some
 *  previous attempt. i.e. just because Side=Golden doesn't mean "Golden boot performed?"
 *  is true.
 *
 *  @note This table is not marked "const" or "static" so that it can be more easily
 *        modified with DCE for testing.
 */
state_transitions_t ody_fsm_transitions[] =
{
    //                |                        | Active |                |                             |
    //  Code updated? | Golden boot performed? | Side   | Fw up to date? |  Event                      | Action
    //----------------+------------------------+--------+----------------+-----------------------------|------------------------------------------------------------------------
    { { no            , no                     , SIDE0  , unknown     },{{ OCMB_BOOT_ERROR_NO_FFDC     , {switch_to_side_1, retry_check_for_ready                       }},
                                                                         { ANY_EVENT                   , {internal_error                                                }} } },  // only OCMB_BOOT_ERROR_NO_FFDC can happen when we don't know the fw version

    { { no            , no                     , SIDE0  , no          },{{ UPDATE_OMI_FIRMWARE_REACHED
                                                                           | OCMB_BOOT_ERROR_WITH_FFDC
                                                                           | ATTRS_INCOMPATIBLE
                                                                           | OCMB_HWP_FAIL_OTHER // An OCMB HWP fail includes both FIFO timeouts (SBE crashes) and non-crash HWP fails. We always attempt a code update in either case, because in the former
                                                                                                 // case the timeout handler will catch the problem, and in the latter case the code update could fix the issue.
                                                                           | OTHER_HW_HWP_FAIL
                                                                           | OCMB_FLASH_ERROR          , {perform_code_update, switch_to_side_1, retry_check_for_ready  }},
                                                                         { OCMB_HWP_FAIL_HASH_FAIL     , {switch_to_side_1, retry_check_for_ready                       }},
                                                                         { CODE_UPDATE_CHIPOP_FAILURE  , {switch_to_side_golden, retry_check_for_ready                  }} } },

    { { no            , no                     , SIDE0  , yes         },{{ OCMB_HWP_FAIL_HASH_FAIL     , {switch_to_side_golden,  retry_check_for_ready                 }},
                                                                         { ATTRS_INCOMPATIBLE          , {fail_boot_bad_firmware                                        }},
                                                                         { IMAGE_SYNC_CHIPOP_FAILURE
                                                                           | MEAS_REGS_MISMATCH
                                                                           | OCMB_FLASH_ERROR          , {switch_to_side_1, retry_check_for_ready                       }},
                                                                         { OCMB_BOOT_ERROR_WITH_FFDC
                                                                           | OCMB_HWP_FAIL_OTHER       , {deconfigure_ocmb                                              }},
                                                                         { IPL_COMPLETE                , {sync_images_normal, reset_ocmb_upd_state                      }} } },

    //                |                        | Active |                |                             |
    //  Code updated? | Golden boot performed? | Side   | Fw up to date? |  Event                      | Action
    //----------------+------------------------+--------+----------------+-----------------------------|------------------------------------------------------------------------
    { { no            , no                     , SIDE1  , unknown     },{{ OCMB_BOOT_ERROR_NO_FFDC     , {switch_to_side_golden, retry_check_for_ready                  }},
                                                                         { ANY_EVENT                   , {internal_error                                                }} } }, // only OCMB_BOOT_ERROR_NO_FFDC can happen when we don't know the fw version

    { { no            , no                     , SIDE1  , no          },{{ OCMB_HWP_FAIL_OTHER
                                                                           | OCMB_HWP_FAIL_HASH_FAIL
                                                                           | OCMB_FLASH_ERROR          , {switch_to_side_golden, retry_check_for_ready                  }},
                                                                         { OCMB_BOOT_ERROR_WITH_FFDC
                                                                           | UPDATE_OMI_FIRMWARE_REACHED
                                                                           | ATTRS_INCOMPATIBLE
                                                                           | OTHER_HW_HWP_FAIL         , {perform_code_update, switch_to_side_0, retry_check_for_ready  }},
                                                                         { CODE_UPDATE_CHIPOP_FAILURE  , {switch_to_side_golden, retry_check_for_ready                  }} } },

    { { no            , no                     , SIDE1  , yes         },{{ OCMB_HWP_FAIL_HASH_FAIL
                                                                           | OCMB_FLASH_ERROR          , {switch_to_side_golden, retry_check_for_ready                  }},
                                                                         { OCMB_BOOT_ERROR_WITH_FFDC
                                                                           | OCMB_HWP_FAIL_OTHER
                                                                           | IMAGE_SYNC_CHIPOP_FAILURE
                                                                           | MEAS_REGS_MISMATCH        , {deconfigure_ocmb                                              }},
                                                                         { ATTRS_INCOMPATIBLE          , {fail_boot_bad_firmware                                        }},
                                                                         { IPL_COMPLETE                , {sync_images_forced, reset_ocmb_upd_state                      }} } },

    //                |                        | Active |                |                             |
    //  Code updated? | Golden boot performed? | Side   | Fw up to date? |  Event                      | Action
    //----------------+------------------------+--------+----------------+-----------------------------|------------------------------------------------------------------------
    { { yes           , no                     , SIDE0  , unknown     },{{ OCMB_BOOT_ERROR_NO_FFDC     , {switch_to_side_golden, retry_check_for_ready                  }},
                                                                         { ANY_EVENT                   , {internal_error                                                }} } }, // only OCMB_BOOT_ERROR_NO_FFDC can happen when we don't know the fw version

    { { yes           , no                     , SIDE0  , no          },{{ CHECK_FOR_READY_COMPLETED   , {deconfigure_ocmb                                              }} } }, // if code updated and fw not up to date, deconfigure ocmb asap

    { { yes           , no                     , SIDE0  , yes         },{{ OCMB_HWP_FAIL_HASH_FAIL
                                                                           | OCMB_HWP_FAIL_OTHER       , {switch_to_side_golden,  retry_check_for_ready                 }},
                                                                         { ATTRS_INCOMPATIBLE          , {fail_boot_bad_firmware                                        }},
                                                                         { OCMB_BOOT_ERROR_WITH_FFDC
                                                                           | IMAGE_SYNC_CHIPOP_FAILURE
                                                                           | MEAS_REGS_MISMATCH        , {deconfigure_ocmb                                              }},
                                                                         { IPL_COMPLETE                , {sync_images_normal, reset_ocmb_upd_state                      }} } },

    //                |                        | Active |                |                             |
    //  Code updated? | Golden boot performed? | Side   | Fw up to date? |  Event                      | Action
    //----------------+------------------------+--------+----------------+-----------------------------|------------------------------------------------------------------------
    { { yes           , no                     , SIDE1  , unknown     },{{ OCMB_BOOT_ERROR_NO_FFDC     , {switch_to_side_golden, retry_check_for_ready                  }},
                                                                         { ANY_EVENT                   , {internal_error                                                }} } }, // only OCMB_BOOT_ERROR_NO_FFDC can happen when we don't know the fw version

    { { yes           , no                     , SIDE1  , no          },{{ CHECK_FOR_READY_COMPLETED   , {deconfigure_ocmb                                              }} } }, // if code updated and fw not up to date, deconfigure ocmb asap

    { { yes           , no                     , SIDE1  , yes         },{{ OCMB_HWP_FAIL_HASH_FAIL
                                                                           | OCMB_HWP_FAIL_OTHER       , {switch_to_side_golden, retry_check_for_ready                  }},
                                                                         { OCMB_BOOT_ERROR_WITH_FFDC
                                                                           | IMAGE_SYNC_CHIPOP_FAILURE
                                                                           | MEAS_REGS_MISMATCH        , {deconfigure_ocmb                                              }},
                                                                         { ATTRS_INCOMPATIBLE          , {fail_boot_bad_firmware                                        }},
                                                                         { IPL_COMPLETE                , {sync_images_normal, reset_ocmb_upd_state                      }} } },

    //                |                        | Active |                |                             |
    //  Code updated? | Golden boot performed? | Side   | Fw up to date? |  Event                      | Action
    //----------------+------------------------+--------+----------------+-----------------------------|------------------------------------------------------------------------
    { { yes           , yes                    , SIDE0  , unknown     },{{ OCMB_BOOT_ERROR_NO_FFDC     , {switch_to_side_1, retry_check_for_ready                       }},
                                                                         { ANY_EVENT                   , {internal_error                                                }} } }, // only OCMB_BOOT_ERROR_NO_FFDC can happen when we don't know the fw version

    { { yes           , yes                    , SIDE0  , no          },{{ CHECK_FOR_READY_COMPLETED   , {deconfigure_ocmb                                              }} } }, // if code updated and fw not up to date, deconfigure ocmb asap

    { { yes           , yes                    , SIDE0  , yes         },{{ OCMB_HWP_FAIL_HASH_FAIL
                                                                           | OCMB_HWP_FAIL_OTHER
                                                                           | OCMB_FLASH_ERROR          , {switch_to_side_1, retry_check_for_ready                       }},
                                                                         { ATTRS_INCOMPATIBLE          , {fail_boot_bad_firmware                                        }},
                                                                         { OCMB_BOOT_ERROR_WITH_FFDC   , {deconfigure_ocmb                                              }},
                                                                         { IPL_COMPLETE                , {reset_ocmb_upd_state                                          }} } },

    //                |                        | Active |                |                             |
    //  Code updated? | Golden boot performed? | Side   | Fw up to date? |  Event                      | Action
    //----------------+------------------------+--------+----------------+-----------------------------|------------------------------------------------------------------------
    { { yes           , yes                    , SIDE1  , unknown     },{{ OCMB_BOOT_ERROR_NO_FFDC     , {deconfigure_ocmb                                              }},
                                                                         { ANY_EVENT                   , {internal_error                                                }} } }, // only OCMB_BOOT_ERROR_NO_FFDC can happen when we don't know the fw version

    { { yes           , yes                    , SIDE1  , no          },{{ CHECK_FOR_READY_COMPLETED   , {deconfigure_ocmb                                              }} } }, // if code updated and fw not up to date, deconfigure ocmb asap

    { { yes           , yes                    , SIDE1  , yes         },{{ OCMB_BOOT_ERROR_WITH_FFDC
                                                                           | OCMB_HWP_FAIL_HASH_FAIL
                                                                           | OCMB_HWP_FAIL_OTHER
                                                                           | OCMB_FLASH_ERROR          , {deconfig_gard_ocmb                                            }},
                                                                         { ATTRS_INCOMPATIBLE          , {fail_boot_bad_firmware                                        }},
                                                                         { IPL_COMPLETE                , {reset_ocmb_upd_state                                          }} } },

    //                |                        | Active |                |                             |
    //  Code updated? | Golden boot performed? | Side   | Fw up to date? |  Event                      | Action
    //----------------+------------------------+--------+----------------+-----------------------------|------------------------------------------------------------------------
    { { yes | no      , no                     , GOLDEN , unknown     },{{ OCMB_BOOT_ERROR_NO_FFDC     , {deconfigure_ocmb                                              }},
                                                                         { ANY_EVENT                   , {internal_error                                                }} } }, // only OCMB_BOOT_ERROR_NO_FFDC can happen when we don't know the fw version

                                                          // golden side
                                                          // is never
                                                          // up to date
    { { yes | no      , no                     , GOLDEN , no          },{{ OCMB_HWP_FAIL_OTHER
                                                                           | OCMB_HWP_FAIL_HASH_FAIL
                                                                           | CODE_UPDATE_CHIPOP_FAILURE, {deconfigure_ocmb                                              }},
                                                                         { OCMB_BOOT_ERROR_WITH_FFDC
                                                                           | CHECK_FOR_READY_COMPLETED , {perform_code_update, switch_to_side_0, retry_check_for_ready  }} } },
};

/** @brief Convert an event to a string for logs and traces.
 */
std::array<char, 256> event_to_str(const ody_upd_event_t i_event)
{
    std::array<char, 256> str = { };

    do
    {

    if (i_event == ANY_EVENT)
    {
        strcpy(&str[0], "ANY_EVENT");
        break;
    }

    fapi2::each_1bit_mask(i_event, [&](const uint64_t bit)
    {
        const auto ody_event = static_cast<ody_upd_event_t>(bit);

        switch (ody_event)
        {
        case CHECK_FOR_READY_COMPLETED:
            strcat(&str[0], "CHECK_FOR_READY_COMPLETED|"); break;
        case UPDATE_OMI_FIRMWARE_REACHED:
            strcat(&str[0], "UPDATE_OMI_FIRMWARE_REACHED|"); break;
        case OCMB_BOOT_ERROR_NO_FFDC:
            strcat(&str[0], "OCMB_BOOT_ERROR_NO_FFDC|"); break;
        case OCMB_BOOT_ERROR_WITH_FFDC:
            strcat(&str[0], "OCMB_BOOT_ERROR_WITH_FFDC|"); break;
        case OCMB_HWP_FAIL_HASH_FAIL:
            strcat(&str[0], "OCMB_HWP_FAIL_HASH_FAIL|"); break;
        case OCMB_HWP_FAIL_OTHER:
            strcat(&str[0], "OCMB_HWP_FAIL_OTHER|"); break;
        case OTHER_HW_HWP_FAIL:
            strcat(&str[0], "OTHER_HW_HWP_FAIL|"); break;
        case ATTRS_INCOMPATIBLE:
            strcat(&str[0], "ATTRS_INCOMPATIBLE|"); break;
        case CODE_UPDATE_CHIPOP_FAILURE:
            strcat(&str[0], "CODE_UPDATE_CHIPOP_FAILURE|"); break;
        case IMAGE_SYNC_CHIPOP_FAILURE:
            strcat(&str[0], "IMAGE_SYNC_CHIPOP_FAILURE|"); break;
        case MEAS_REGS_MISMATCH:
            strcat(&str[0], "MEAS_REGS_MISMATCH|"); break;
        case IPL_COMPLETE:
            strcat(&str[0], "IPL_COMPLETE|"); break;
        case OCMB_FLASH_ERROR:
            strcat(&str[0], "OCMB_FLASH_ERROR|"); break;
        case NO_EVENT: // just to satisfy the compiler
        case ANY_EVENT:
            break;
        }

        return true; // continue iteration until the end
    });

    if (strlen(&str[0]))
    {
        str[strlen(&str[0]) - 1] = '\0'; // chop off the last |
    }

    } while (false);

    return str;
}

/** @brief Determine whether a given state [lhs] matches a state pattern [rhs]. The state
 *  pattern [rhs] may have fields that are bitfields representing a set of values to match,
 *  but the state [lhs] must be a single state.
 */
bool state_pattern_matches(const state_t& lhs, const state_t& rhs)
{
    assert(__builtin_popcount(lhs.ocmb_boot_side) == 1, "state_pattern_matches: Expected a single state for matching (ocmb_boot_side)");
    assert(__builtin_popcount(lhs.update_performed) == 1, "state_pattern_matches: Expected a single state for matching (update_performed)");
    assert(__builtin_popcount(lhs.golden_boot_performed) == 1, "state_pattern_matches: Expected a single state for matching (golden_boot_performed)");
    assert(__builtin_popcount(lhs.ocmb_fw_up_to_date) == 1, "state_pattern_matches: Expected a single state for matching (ocmb_fw_up_to_date)");

    return (lhs.ocmb_boot_side & rhs.ocmb_boot_side)
        && (lhs.update_performed & rhs.update_performed)
        && (lhs.golden_boot_performed & rhs.golden_boot_performed)
        && (lhs.ocmb_fw_up_to_date & rhs.ocmb_fw_up_to_date);
}

/** @brief Determine whether a given event [lhs] matches a event pattern [rhs]. The event
 *  pattern [rhs] may have fields that are bitfields representing a set of values to match,
 *  but the event [lhs] must be a single event.
 */
bool event_pattern_matches(const ody_upd_event_t lhs, const ody_upd_event_t rhs)
{
    assert(__builtin_popcount(lhs) == 1, "event_pattern_matches: Expected a single state for matching");
    return lhs & rhs;
}

/** @brief Convert a tristate value to a string for logs and traces.
 */
std::array<char, 64> tristate_mask_to_str(const tristate_t i_state)
{
    std::array<char, 64> str = { };

    if (i_state == 0)
    {
        strcat(&str[0], "null");
    }
    else
    {
        if (i_state & yes)
        {
            strcat(&str[0], "yes|");
        }

        if (i_state & no)
        {
            strcat(&str[0], "no|");
        }

        if (i_state & unknown)
        {
            strcat(&str[0], "unknown|");
        }

        if (strlen(&str[0]))
        {
            str[strlen(&str[0]) - 1] = '\0'; // chop off the last |
        }
    }

    return str;
}

/** @brief Convert an OCMB boot side enumeration value to a string for logs and traces.
 */
std::array<char, 64> ocmb_boot_side_to_str(const ocmb_boot_side_t i_side)
{
    std::array<char, 64> str = { };

    if (i_side & SIDE0)
    {
        strcat(&str[0], "SIDE0|");
    }

    if (i_side & SIDE1)
    {
        strcat(&str[0], "SIDE1|");
    }

    if (i_side & GOLDEN)
    {
        strcat(&str[0], "GOLDEN|");
    }

    if (strlen(&str[0]))
    {
        str[strlen(&str[0]) - 1] = '\0'; // chop off the last |
    }

    return str;
}

/** @brief Convert a state to a string for logs and traces.
 */
std::array<char, 256> state_to_str(const state_t& i_state)
{
    std::array<char, 256> str = { };

    sprintf(&str[0],
            "{ update_performed: %s, golden_boot_performed: %s, ocmb_boot_side: %s, fw_up_to_date: %s }",
            tristate_mask_to_str(i_state.update_performed).data(),
            tristate_mask_to_str(i_state.golden_boot_performed).data(),
            ocmb_boot_side_to_str(i_state.ocmb_boot_side).data(),
            tristate_mask_to_str(i_state.ocmb_fw_up_to_date).data());

    return str;
}

/** @brief Convert an action to a string for logs and traces.
 */
std::array<char, 128> action_to_str(const update_action_t i_action)
{
    std::array<char, 128> str = { };

    switch (i_action)
    {
    case do_nothing: strcpy(&str[0], "do nothing"); break;
    case mark_error_predictive: strcpy(&str[0], "convert error to predictive"); break;
    case mark_error_recovered: strcpy(&str[0], "convert error to recovered"); break;
    case mark_error_unrecoverable: strcpy(&str[0], "convert error to unrecoverable"); break;
    case perform_code_update: strcpy(&str[0], "perform code update"); break;
    case deconfigure_ocmb: strcpy(&str[0], "deconfigure ocmb"); break;
    case deconfig_gard_ocmb: strcpy(&str[0], "deconfigure & guard ocmb"); break;
    case fail_boot_bad_firmware: strcpy(&str[0], "fail boot; bad firmware"); break;
    case reset_ocmb_upd_state: strcpy(&str[0], "reset ocmb update state"); break;
    case sync_images_normal: strcpy(&str[0], "sync images (normal)"); break;
    case sync_images_forced: strcpy(&str[0], "sync images (forced)"); break;
    case switch_to_side_0: strcpy(&str[0], "switch to side 0"); break;
    case switch_to_side_1: strcpy(&str[0], "switch to side 1"); break;
    case switch_to_side_golden: strcpy(&str[0], "switch to golden side"); break;
    case retry_check_for_ready: strcpy(&str[0], "retry check_for_ready"); break;
    case internal_error: strcpy(&str[0], "internal error"); break;
    }

    return str;
}

/** @brief Capture the state of the code update FSM in an error log.
 */
errlOwner capture_state_in_errlog(const errlSeverity_t i_sev,
                                  const uint8_t i_mod,
                                  const uint16_t i_rc,
                                  const bool i_sw_callout,
                                  Target* const i_ocmb,
                                  const state_t& i_state,
                                  const state_transitions_t& i_state_pattern,
                                  const state_transition_t& i_transition,
                                  const ody_upd_event_t i_event)
{
    const auto errl
        = new ErrlEntry(i_sev,
                        i_mod,
                        i_rc,
                        SrcUserData(bits{0, 31},  get_huid(i_ocmb),
                                    bits{32, 39}, i_state.update_performed,
                                    bits{40, 47}, i_state.golden_boot_performed,
                                    bits{48, 55}, i_state.ocmb_boot_side,
                                    bits{56, 63}, i_state.ocmb_fw_up_to_date),
                        SrcUserData(bits{0, 15},  i_event,
                                    bits{16, 31}, i_transition.event,
                                    bits{32, 39}, i_state_pattern.state.update_performed,
                                    bits{40, 47}, i_state_pattern.state.golden_boot_performed,
                                    bits{48, 55}, i_state_pattern.state.ocmb_boot_side,
                                    bits{56, 63}, i_state_pattern.state.ocmb_fw_up_to_date),
                        i_sw_callout);

    errl->collectTrace(OCMBUPD_COMP_NAME);
    errl->collectTrace(ISTEP_COMP_NAME);
    errl->collectTrace(SBEIO_COMP_NAME);

    const auto vsn_summary = i_ocmb->getAttrAsStdArr<ATTR_OCMB_CODE_LEVEL_SUMMARY>();
    char errl_vsn_details[sizeof(vsn_summary) + 32] = { };
    sprintf(errl_vsn_details,
            "Odyssey code versions: %s", vsn_summary.data());
    ErrlUserDetailsString(errl_vsn_details).addToLog(errl);

    return errlOwner(errl);
}

/** @brief Create and commit an error log that will immediately deconfigure the given
 *  OCMB.
 *
 *  @note The error that this function returns indicates a problem in its own operation; the
 *  error log that it creates to deconfigure the OCMB is committed, not returned.
 *
 *  @param[in] i_ocmb           The OCMB to deconfigure.
 *  @param[in] i_state          The state of the FSM for this OCMB.
 *  @param[in] i_state_pattern  The state pattern in the FSM table that the state matched.
 *  @param[in] i_transition     The transition that is being executed.
 *  @param[in] i_event          The event that caused i_transition.
 *  @param[in] i_errlog         The error log that caused this event, if any.
 *  @param[in] i_apply_gard_record Whether a gard record should be created for this OCMB
 *
 *  @return errlOwner           Error if any, otherwise nullptr.
 */
errlOwner create_and_commit_ocmb_deconfigure_log(Target* const i_ocmb,
                                                 const state_t& i_state,
                                                 const state_transitions_t& i_state_pattern,
                                                 const state_transition_t& i_transition,
                                                 const ody_upd_event_t i_event,
                                                 const errlHndl_t i_errlog,
                                                 const bool i_apply_gard_record)
{
    /*@
     *@moduleid         MOD_ODY_UPD_FSM
     *@reasoncode       ODY_UPD_DECONFIGURE_OCMB
     *@userdata1[0:31]  The OCMB's HUID
     *@userdata1[32:39] OCMB state.update_performed
     *@userdata1[40:47] OCMB state.golden_boot_performed
     *@userdata1[48:55] OCMB state.ocmb_boot_side
     *@userdata1[56:63] OCMB state.ocmb_fw_up_to_date
     *@userdata2[0:15]  The OCMB event that caused this transition
     *@userdata2[16:31] The OCMB event pattern that the event matched
     *@userdata2[32:39] The state pattern in the FSM table that the state matched (State.update_performed)
     *@userdata2[40:47] Matching state pattern's State.golden_boot_performed
     *@userdata2[48:55] Matching state pattern's State.ocmb_boot_side
     *@userdata2[56:63] Matching state pattern's ocmb_fw_up_to_date
     *@devdesc          The Odyssey code update FSM requested to deconfigure this OCMB.
     *@custdesc         A software error occurred during system boot
     */
    auto errl = capture_state_in_errlog(ERRL_SEV_UNRECOVERABLE, MOD_ODY_UPD_FSM, ODY_UPD_DECONFIGURE_OCMB,
                                        ErrlEntry::NO_SW_CALLOUT, i_ocmb, i_state, i_state_pattern, i_transition, i_event);

    auto l_gard_action = i_apply_gard_record ? HWAS::GARD_Unrecoverable : HWAS::GARD_NULL;

    errl->addHwCallout(i_ocmb, HWAS::SRCI_PRIORITY_HIGH, HWAS::DECONFIG, l_gard_action);

    // We have to do this because (1) we want to communicate the deconfigured state of the
    // target to the caller immediately, and (2) on FSP machines, addHwCallout will silently
    // convert our DECONFIG request to a DELAYED_DECONFIG request, which conflicts with
    // (1). So we can't rely on the error log to do it, even if we flush the error logs
    // here.
    const auto deconfig_errl = HWAS::theDeconfigGard().deconfigureTarget(*i_ocmb, errl->eid());

    if (i_errlog)
    { // Link the deconfig log with the originating error log.
        errl->plid(i_errlog->plid());
    }

    errlCommit(errl, OCMBUPD_COMP_ID);

    return errlOwner(deconfig_errl);
}

/** @brief Create a log for an internal error in the code update FSM. This should halt the boot.
 */
errlOwner create_internal_error_log(Target* const i_ocmb,
                                    const state_t& i_state,
                                    const state_transitions_t& i_state_pattern,
                                    const state_transition_t& i_transition,
                                    const ody_upd_event_t i_event,
                                    const uint16_t i_rc)
{
    auto errl = capture_state_in_errlog(ERRL_SEV_UNRECOVERABLE, MOD_ODY_UPD_FSM, i_rc,
                                        ErrlEntry::ADD_SW_CALLOUT, i_ocmb, i_state, i_state_pattern, i_transition, i_event);

    errl->addHwCallout(i_ocmb, HWAS::SRCI_PRIORITY_LOW, HWAS::NO_DECONFIG, HWAS::GARD_NULL);

    return errl;
}

/** @brief Create an error log for a fatal error in the Odyssey firmware. This should halt
 *  the boot.
 */
errlOwner create_boot_fail_bad_firmware_log(Target* const i_ocmb,
                                            const state_t& i_state,
                                            const state_transitions_t& i_state_pattern,
                                            const state_transition_t& i_transition,
                                            const ody_upd_event_t i_event)
{
    /*@
     *@moduleid         MOD_ODY_UPD_FSM
     *@reasoncode       ODY_UPD_BAD_FIRMWARE
     *@userdata1[0:31]  The OCMB's HUID
     *@userdata1[32:39] OCMB state.update_performed
     *@userdata1[40:47] OCMB state.golden_boot_performed
     *@userdata1[48:55] OCMB state.ocmb_boot_side
     *@userdata1[56:63] OCMB state.ocmb_fw_up_to_date
     *@userdata2[0:15]  The OCMB event that caused this transition
     *@userdata2[16:31] The OCMB event pattern that the event matched
     *@userdata2[32:39] The state pattern in the FSM table that the state matched (State.update_performed)
     *@userdata2[40:47] Matching state pattern's State.golden_boot_performed
     *@userdata2[48:55] Matching state pattern's State.ocmb_boot_side
     *@userdata2[56:63] Matching state pattern's ocmb_fw_up_to_date
     *@devdesc          The OCMB firmware is up to date but invalid.
     *@custdesc         A software error occurred during system boot
     */
    auto errl = capture_state_in_errlog(ERRL_SEV_UNRECOVERABLE, MOD_ODY_UPD_FSM, ODY_UPD_BAD_FIRMWARE,
                                        ErrlEntry::ADD_SW_CALLOUT, i_ocmb, i_state, i_state_pattern, i_transition, i_event);

    errl->addHwCallout(i_ocmb, HWAS::SRCI_PRIORITY_LOW, HWAS::NO_DECONFIG, HWAS::GARD_NULL);

    return errl;
}

/** @brief Create and commit an informational error log for a code update.
 */
void create_firmware_update_log(Target* const i_ocmb,
                                const state_t& i_state,
                                const state_transitions_t& i_state_pattern,
                                const state_transition_t& i_transition,
                                const ody_upd_event_t i_event)
{
    /*@
     *@moduleid         MOD_ODY_UPD_FSM
     *@reasoncode       ODY_UPD_FIRMWARE_UPDATED
     *@userdata1[0:31]  The OCMB's HUID
     *@userdata1[32:39] OCMB state.update_performed
     *@userdata1[40:47] OCMB state.golden_boot_performed
     *@userdata1[48:55] OCMB state.ocmb_boot_side
     *@userdata1[56:63] OCMB state.ocmb_fw_up_to_date
     *@userdata2[0:15]  The OCMB event that caused this transition
     *@userdata2[16:31] The OCMB event pattern that the event matched
     *@userdata2[32:39] The state pattern in the FSM table that the state matched (State.update_performed)
     *@userdata2[40:47] Matching state pattern's State.golden_boot_performed
     *@userdata2[48:55] Matching state pattern's State.ocmb_boot_side
     *@userdata2[56:63] Matching state pattern's ocmb_fw_up_to_date
     *@devdesc          An Odyssey OCMB was updated during the boot.
     *@custdesc         An OCMB was updated during the boot
     */
    auto errl = capture_state_in_errlog(ERRL_SEV_INFORMATIONAL, MOD_ODY_UPD_FSM, ODY_UPD_FIRMWARE_UPDATED,
                                        ErrlEntry::NO_SW_CALLOUT, i_ocmb, i_state, i_state_pattern, i_transition, i_event);

    errl->addHwCallout(i_ocmb, HWAS::SRCI_PRIORITY_LOW, HWAS::NO_DECONFIG, HWAS::GARD_NULL);

    errlCommit(errl, OCMBUPD_COMP_ID);
}

/** @brief Execute the actions for the given transition on the given OCMB.
 *
 *  @param[in] i_ocmb             The OCMB to deconfigure.
 *  @param[in] i_state            The state of the FSM for this OCMB.
 *  @param[in] i_state_pattern    The state pattern in the FSM table that the state matched.
 *  @param[in] i_transition       The transition that is being executed.
 *  @param[in] i_event            The event that caused i_transition.
 *  @param[in] i_errlog           The error log associated with the event, if any. This
 *                                function does not take ownership of the error log.
 *  @param[out] o_restart_needed  Whether the ocmb_check_for_ready loop should be
 *                                restarted on the given OCMB.
 *
 *  @return errlOwner             Error if any, otherwise nullptr.
 *
 *  @note This function is recursive and does NOT take ownership of i_errlog.
 */
errlOwner execute_actions(Target* const i_ocmb,
                          const state_t& i_state,
                          const state_transitions_t& i_state_pattern,
                          const state_transition_t& i_transition,
                          const ody_upd_event_t i_event,
                          errlHndl_t i_errlog,
                          const bool i_on_update_force_all,
                          bool& o_restart_needed)
{
    errlOwner errl = nullptr;

    bool manually_set_errl_sev = false;
    bool apply_gard_record = false;

    for (const auto& action : i_transition.actions)
    {
        if (action != do_nothing)
        {
            TRACF(INFO_MRK"ody_upd_fsm/execute_actions(0x%08X): Executing action %s",
                  get_huid(i_ocmb),
                  action_to_str(action).data());

            switch (action)
            {
            case do_nothing:
                break;
            case mark_error_predictive:
                if (i_errlog)
                {
                    i_errlog->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                }
                manually_set_errl_sev = true;
                break;
            case mark_error_recovered:
                if (i_errlog)
                {
                    i_errlog->setSev(ERRORLOG::ERRL_SEV_RECOVERED);
                }
                manually_set_errl_sev = true;
                break;
            case mark_error_unrecoverable:
                if (i_errlog)
                {
                    i_errlog->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                }
                manually_set_errl_sev = true;
                break;
            case perform_code_update:
                /* The fact that we're doing a code update means that any errors we hit prior
                   to this are from a downlevel version. Therefore none of these logs should
                   show up as visible errors.
                */
                if (i_errlog && !manually_set_errl_sev)
                {
                    i_errlog->setSev(ERRORLOG::ERRL_SEV_RECOVERED);
                }
                /*
                   Before performing a code update, we sync the code levels from the current side to
                   the other side. This is to handle the scenario where the other side has a code
                   level that is out of date, but it's not out of date on the current side, so we
                   don't think we need to update it (and therefore skip it).

                   We perform the sync just before the update so that we have the least chance of
                   overwriting a good code level with a bad one here (since the code level we're
                   syncing from has gotten us up to where the FSM thinks it's best/fastest to perform
                   the actual code update).
                */
                if (i_state.ocmb_boot_side != GOLDEN)
                {
                    errlOwner sync_err;
                    if (sync_err = SBEIO::sendSyncCodeLevelsRequest(i_ocmb, /*force_sync=*/false))
                    {
                        TRACF(ERR_MRK"ody_upd_fsm/execute_actions(0x%08X): sendSyncCodeLevelsRequest(normal) failed in perform_code_update "
                              "(attempting forced sync)"
                              TRACE_ERR_FMT,
                              get_huid(i_ocmb),
                              TRACE_ERR_ARGS(sync_err));

                        if (!sync_err->hasErrorType(SBEIO::SBEIO_ERROR_TYPE_HRESET_PERFORMED))
                        { // Only force a sync if the SPPE is not dead from the last op.
                            if (errlOwner forced_sync_err { SBEIO::sendSyncCodeLevelsRequest(i_ocmb, /*force_sync=*/true) })
                            {
                                TRACF(ERR_MRK"ody_upd_fsm/execute_actions(0x%08X): sendSyncCodeLevelsRequest(forced) failed in perform_code_update: "
                                      TRACE_ERR_FMT,
                                      get_huid(i_ocmb),
                                      TRACE_ERR_ARGS(forced_sync_err));
                                aggregate(sync_err, move(forced_sync_err), /*link_plids=*/true);
                            }
                            else
                            {
                                sync_err = nullptr;
                            }
                        }

                        if (sync_err)
                        {
                            return ody_upd_process_event(i_ocmb,
                                                         // this action is code update, so this is counted
                                                         // as a CODE_UPDATE_CHIPOP_FAILURE
                                                         CODE_UPDATE_CHIPOP_FAILURE,
                                                         move(sync_err),
                                                         o_restart_needed);
                        }
                    }
                }

                if (auto update_err = odysseyUpdateImages(i_ocmb, i_on_update_force_all))
                {
                    TRACF(ERR_MRK"ody_upd_fsm/execute_actions(0x%08X): odysseyUpdateImages failed: "
                          TRACE_ERR_FMT,
                          get_huid(i_ocmb),
                          TRACE_ERR_ARGS(update_err));

                    return ody_upd_process_event(i_ocmb,
                                                 CODE_UPDATE_CHIPOP_FAILURE,
                                                 errlOwner(update_err),
                                                 o_restart_needed);
                }

                create_firmware_update_log(i_ocmb, i_state, i_state_pattern, i_transition, i_event);
                i_ocmb->setAttr<ATTR_OCMB_CODE_UPDATED>(1);

                break;
            case switch_to_side_0:
                if (i_errlog && !manually_set_errl_sev)
                {
                    i_errlog->setSev(ERRORLOG::ERRL_SEV_RECOVERED);
                }
                if (i_state.ocmb_boot_side == GOLDEN)
                {
                    i_ocmb->setAttr<ATTR_OCMB_GOLDEN_BOOT_ATTEMPTED>(1);
                }
                i_ocmb->setAttr<ATTR_OCMB_BOOT_SIDE>(SPPE_BOOT_SIDE_SIDE0);
                break;
            case switch_to_side_1:
                if (i_errlog && !manually_set_errl_sev)
                {
                    i_errlog->setSev(ERRORLOG::ERRL_SEV_RECOVERED);
                }
                if (i_state.ocmb_boot_side == GOLDEN)
                {
                    i_ocmb->setAttr<ATTR_OCMB_GOLDEN_BOOT_ATTEMPTED>(1);
                }
                i_ocmb->setAttr<ATTR_OCMB_BOOT_SIDE>(SPPE_BOOT_SIDE_SIDE1);
                break;
            case switch_to_side_golden:
                if (i_errlog && !manually_set_errl_sev)
                {
                    i_errlog->setSev(ERRORLOG::ERRL_SEV_RECOVERED);
                }
                if (i_state.ocmb_boot_side == GOLDEN)
                {
                    i_ocmb->setAttr<ATTR_OCMB_GOLDEN_BOOT_ATTEMPTED>(1);
                }
                i_ocmb->setAttr<ATTR_OCMB_BOOT_SIDE>(SPPE_BOOT_SIDE_GOLDEN);
                break;
            case reset_ocmb_upd_state:
                ody_upd_reset_state(i_ocmb);
                break;
            case deconfig_gard_ocmb:
                apply_gard_record = true;
                // fall through
            case deconfigure_ocmb:
                if (i_errlog && !manually_set_errl_sev)
                {
                    i_errlog->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                }

                errl = create_and_commit_ocmb_deconfigure_log(i_ocmb, i_state, i_state_pattern, i_transition, i_event, i_errlog, apply_gard_record);

                if (errl)
                {
                    TRACF(ERR_MRK"ody_upd_fsm/execute_actions(0x%08X): create_and_commit_ocmb_deconfigure_log"
                          " failed - "
                          TRACE_ERR_FMT,
                          get_huid(i_ocmb),
                          TRACE_ERR_ARGS(errl));
                }

                break;
            case fail_boot_bad_firmware:
                errl = create_boot_fail_bad_firmware_log(i_ocmb, i_state, i_state_pattern, i_transition, i_event);
                break;

            case sync_images_normal:
                if (auto sync_err = SBEIO::sendSyncCodeLevelsRequest(i_ocmb, /*force_sync=*/false))
                {
                    TRACF(ERR_MRK"ody_upd_fsm/execute_actions(0x%08X): sendSyncCodeLevelsRequest(normal) failed: "
                          TRACE_ERR_FMT,
                          get_huid(i_ocmb),
                          TRACE_ERR_ARGS(sync_err));

                    aggregate(errl, sync_err);
                }
                else
                {
                    // Sync succeeded; done handling this action
                    break;
                }

                // Fall through; if a normal image sync fails, perform a forced one.

            case sync_images_forced:
                if (!errl || !errl->hasErrorType(SBEIO::SBEIO_ERROR_TYPE_HRESET_PERFORMED))
                { // Only force a sync if the SPPE isn't dead from the last operation.
                    if (auto sync_err = SBEIO::sendSyncCodeLevelsRequest(i_ocmb, /*force_sync=*/true))
                    {
                        TRACF(ERR_MRK"ody_upd_fsm/execute_actions(0x%08X): sendSyncCodeLevelsRequest(forced) failed "
                              "(attempting forced sync)"
                              TRACE_ERR_FMT,
                              get_huid(i_ocmb),
                              TRACE_ERR_ARGS(sync_err));

                        aggregate(errl, sync_err);
                    }
                    else
                    {
                        // If there was an error from a normal sync above,
                        // delete it if the forced sync succeeded.
                        errl = nullptr;
                    }
                }

                if (errl)
                {
                    return ody_upd_process_event(i_ocmb,
                                                 IMAGE_SYNC_CHIPOP_FAILURE,
                                                 move(errl),
                                                 o_restart_needed);
                }

                break;
            case retry_check_for_ready:
                o_restart_needed = true;
                break;
            case internal_error:
                /*@
                 *@moduleid         MOD_ODY_UPD_FSM
                 *@reasoncode       ODY_UPD_INTERNAL_ERROR
                 *@userdata1[0:31]  The OCMB's HUID
                 *@userdata1[32:39] OCMB state.update_performed
                 *@userdata1[40:47] OCMB state.golden_boot_performed
                 *@userdata1[48:55] OCMB state.ocmb_boot_side
                 *@userdata1[56:63] OCMB state.ocmb_fw_up_to_date
                 *@userdata2[0:15]  The OCMB event that caused this transition
                 *@userdata2[16:31] The OCMB event pattern that the event matched
                 *@userdata2[32:39] The state pattern in the FSM table that the state matched (State.update_performed)
                 *@userdata2[40:47] Matching state pattern's State.golden_boot_performed
                 *@userdata2[48:55] Matching state pattern's State.ocmb_boot_side
                 *@userdata2[56:63] Matching state pattern's ocmb_fw_up_to_date
                 *@devdesc          The Odyssey code update FSM experienced an internal error; this is a code bug.
                 *@custdesc         A software error occurred during system boot
                 */
                errl = create_internal_error_log(i_ocmb, i_state, i_state_pattern, i_transition, i_event, ODY_UPD_INTERNAL_ERROR);
                break;
            }
        }

        if (errl)
        {
            break;
        }
    }

    return errl;
}

/** @brief Masks bits out of a value and right-aligns the result.
 */
template<typename T = uint64_t>
constexpr T extract_mask(const uint64_t value, const uint64_t mask)
{
    return static_cast<T>((value & mask) >> __builtin_ctz(mask));
}

/** @brief Reads the ODYSSEY_PRIORITY_CODE_UPDATE_RULE attribute from
 *  the system target and converts it to an FSM rule. This attribute
 *  is meant to be set via an attribute override to force particular
 *  behavior from the FSM for testing.
 *
 *  If the attribute isn't set at all, the returned rule won't match
 *  any states/events.
 *
 *  The structure of the attribute should match what is described in
 *  the attribute XML.
 */
state_transitions_t parse_ody_upd_fsm_attribute_override()
{
    const auto sys = UTIL::assertGetToplevelTarget();

    const auto attr = sys->getAttrAsStdArr<ATTR_ODYSSEY_PRIORITY_CODE_UPDATE_RULE>();

    const uint64_t rule = attr[0],
                   actions = attr[1];

    state_transition_t transition = { };

    transition.event = extract_mask(rule, 0xFFFFFFFF'00000000);

    static_assert(sizeof(transition.actions) <= sizeof(actions));
    memcpy(transition.actions, &actions, sizeof(transition.actions));

    state_t state_pattern = { };

    state_pattern.update_performed.state      = extract_mask<tristate_t>      (rule, 0x00000000'FF000000);
    state_pattern.golden_boot_performed.state = extract_mask<tristate_t>      (rule, 0x00000000'00FF0000);
    state_pattern.ocmb_boot_side.side         = extract_mask<ocmb_boot_side_t>(rule, 0x00000000'0000FF00);
    state_pattern.ocmb_fw_up_to_date.state    = extract_mask<tristate_t>      (rule, 0x00000000'000000FF);

    state_transitions_t transition_set = { };

    transition_set.state = state_pattern;
    transition_set.transitions[0] = transition;

    TRACF("parse_ody_upd_fsm_attribute_override: event=0x%x, update_performed=0x%x "
          "golden_boot_performed=0x%x, ocmb_boot_side=0x%x, ocmb_fw_up_to_date=0x%x",
          transition.event,
          state_pattern.update_performed.state,
          state_pattern.golden_boot_performed.state,
          state_pattern.ocmb_boot_side.side,
          state_pattern.ocmb_fw_up_to_date.state);

    return transition_set;
}

/** @brief Process an event on the given OCMB. If an error log is
 *  related to the event, it is passed in as well, and this function
 *  takes ownership of it.
 */
errlOwner ody_upd_process_event(Target* const i_ocmb,
                                const state_t& i_state,
                                const ody_upd_event_t i_event,
                                errlOwner i_errlog,
                                bool& o_restart_needed)
{
    TRACF(ENTER_MRK"ody_upd_process_event(HUID=0x%08X): Current state+event %s + %s",
          get_huid(i_ocmb),
          state_to_str(i_state).data(),
          event_to_str(i_event).data());

    if (i_errlog)
    {
        SBEIO::UdSPPECodeLevels(i_ocmb).addToLog(i_errlog);

        const auto boot_side = ocmb_boot_side_to_str(i_state.ocmb_boot_side);
        char buf[1024] = { };
        sprintf(buf, "SPPE boot side: %s", boot_side.data());
        ErrlUserDetailsString(buf).addToLog(i_errlog);
    }

    errlOwner errl = nullptr;

    do
    {

    if (UTIL::assertGetToplevelTarget()->getAttr<ATTR_IS_MPIPL_HB>())
    {
        TRACF(INFO_MRK"ody_upd_process_event(HUID=0x%08X): No handling for MPIPL; "
              "committing error log, if any (0x%08X), and returning",
              get_huid(i_ocmb),
              ERRL_GETEID_SAFE(i_errlog));
        break;
    }

    const state_transitions_t* matched_state = nullptr;
    const state_transition_t* matched_event = nullptr;

    /* If someone has done an attribute override for this transition,
       prioritize that. */

    bool on_update_force_all = false;
    const auto override_state_pattern = parse_ody_upd_fsm_attribute_override();

    if (state_pattern_matches(i_state, override_state_pattern.state)
        && event_pattern_matches(i_event, override_state_pattern.transitions[0].event))
    {
        TRACF("ody_upd_process_event(HUID=0x%08X): Current state+event %s + %s matches "
              "attribute override; skipping normal FSM rules",
              get_huid(i_ocmb),
              state_to_str(i_state).data(),
              event_to_str(i_event).data());

        matched_state = &override_state_pattern;
        matched_event = &override_state_pattern.transitions[0];

        on_update_force_all = true; // if the override asks us to do a
                                    // code update, force an update to
                                    // everything
    }

    /* If the attribute override didn't apply here, then apply the
       normal FSM rules. */

    else
    {
        /* Special case for non-functional DIMMs upon event IPL_COMPLETE;
           we just reset all state. */

        if (!i_ocmb->getAttr<ATTR_HWAS_STATE>().functional && i_event == IPL_COMPLETE)
        {
            TRACF("ody_upd_process_event(HUID=0x%08X): Current state+event %s + %s matches "
                  "special case for non-functional OCMBs; clearing state and exiting",
                  get_huid(i_ocmb),
                  state_to_str(i_state).data(),
                  event_to_str(i_event).data());

            errl = execute_actions(i_ocmb, i_state, /* state pattern */ { }, /* transition */ { },
                                   IPL_COMPLETE, i_errlog.get(), on_update_force_all, o_restart_needed);
            break;
        }

        /* Look for a match for this state+event in our state transition table */

        for (const auto& state_pattern : ody_fsm_transitions)
        {
            if (state_pattern_matches(i_state, state_pattern.state))
            {
                matched_state = &state_pattern;

                for (const auto& event_pattern : state_pattern.transitions)
                {
                    if (event_pattern_matches(i_event, event_pattern.event))
                    {
                        matched_event = &event_pattern;
                        break;
                    }
                }

                break;
            }
        }
    }

    /* If we found a match, execute the actions! */

    if (matched_event)
    {
        TRACF("ody_upd_process_event(HUID=0x%08X): Current state+event %s + %s matches pattern %s + %s",
              get_huid(i_ocmb),
              state_to_str(i_state).data(),
              event_to_str(i_event).data(),
              state_to_str(matched_state->state).data(),
              event_to_str(matched_event->event).data());

        errl = execute_actions(i_ocmb, i_state, *matched_state, *matched_event, i_event, i_errlog.get(), on_update_force_all, o_restart_needed);
    }
    else if (matched_state)
    {
        TRACF("ody_upd_process_event(HUID=0x%08X): Current state+event %s + %s matched state pattern %s but did not match any event pattern; no actions for this event",
              get_huid(i_ocmb),
              state_to_str(i_state).data(),
              event_to_str(i_event).data(),
              state_to_str(matched_state->state).data());
    }
    else
    {
        TRACF("ody_upd_process_event(HUID=0x%08X): Current state+event %s + %s did not match any state pattern; this is a bug!",
              get_huid(i_ocmb),
              state_to_str(i_state).data(),
              event_to_str(i_event).data());

        /*@
         *@moduleid         MOD_ODY_UPD_FSM
         *@reasoncode       ODY_UPD_UNKNOWN_STATE
         *@userdata1[0:31]  The OCMB's HUID
         *@userdata1[32:39] OCMB state.update_performed
         *@userdata1[40:47] OCMB state.golden_boot_performed
         *@userdata1[48:55] OCMB state.ocmb_boot_side
         *@userdata1[56:63] OCMB state.ocmb_fw_up_to_date
         *@userdata2[0:15]  The OCMB event that caused this transition
         *@userdata2[16:31] The OCMB event pattern that the event matched
         *@userdata2[32:39] The state pattern in the FSM table that the state matched (State.update_performed)
         *@userdata2[40:47] Matching state pattern's State.golden_boot_performed
         *@userdata2[48:55] Matching state pattern's State.ocmb_boot_side
         *@userdata2[56:63] Matching state pattern's ocmb_fw_up_to_date
         *@devdesc          The Odyssey code update FSM experienced an internal error; this is a code bug.
         *@custdesc         A software error occurred during system boot
         */
        errl = create_internal_error_log(i_ocmb, i_state, { }, { }, i_event, ODY_UPD_UNKNOWN_STATE);
        break;
    }

    } while (false);

    if (i_errlog)
    {
        errlCommit(i_errlog, OCMBUPD_COMP_ID);
    }

    TRACF(EXIT_MRK"ody_upd_process_event(HUID=0x%08X) = 0x%08X",
          get_huid(i_ocmb),
          ERRL_GETPLID_SAFE(errl));

    return errl;
}

errlOwner ocmbupd::ody_upd_process_event(Target* const i_ocmb,
                                         const ody_upd_event_t i_event,
                                         errlOwner i_errlog)
{
    bool restart_needed = false;

    auto errl = ody_upd_process_event(i_ocmb, i_event, move(i_errlog), restart_needed);

    if (!errl && restart_needed)
    {
#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
        CONSOLE::displayf(CONSOLE::DEFAULT, nullptr,
                          "Performing reconfig loop for updated OCMBs");
#endif

        TRACF(INFO_MRK"ody_upd_process_event(0x%08x): Requesting reconfig loop for "
              "OCMB firmware update",
              get_huid(i_ocmb));

        setOrClearReconfigLoopReason(HWAS::ReconfigSetOrClear::RECONFIG_SET,
                                     RECONFIGURE_LOOP_OCMB_FW_UPDATE);
    }

    return errl;
}

/** @brief Process an event on the given OCMB. If an error log is
 *  related to the event, it is passed in as well, and this function
 *  takes ownership of it.
 *
 *  This function prepares the inputs to pass to the other overload of
 *  ody_upd_process_event.
 */
errlOwner ocmbupd::ody_upd_process_event(Target* const i_ocmb,
                                         const ody_upd_event_t i_event,
                                         errlOwner i_errlog,
                                         bool& o_restart_needed)
{
    state_t state = { };

    state.update_performed = i_ocmb->getAttr<ATTR_OCMB_CODE_UPDATED>() ? yes : no;
    state.golden_boot_performed = i_ocmb->getAttr<ATTR_OCMB_GOLDEN_BOOT_ATTEMPTED>() ? yes : no;

    switch (static_cast<SPPE_BOOT_SIDE>(i_ocmb->getAttr<ATTR_OCMB_BOOT_SIDE>()))
    {
    case SPPE_BOOT_SIDE_INVALID:
        assert(false, "Unexpected state for ATTR_OCMB_BOOT_SIDE"); // this can never happen
        break;
    case SPPE_BOOT_SIDE_SIDE0:
        state.ocmb_boot_side = SIDE0;
        break;
    case SPPE_BOOT_SIDE_SIDE1:
        state.ocmb_boot_side = SIDE1;
        break;
    case SPPE_BOOT_SIDE_GOLDEN:
        state.ocmb_boot_side = GOLDEN;
        break;
    }

    switch (i_ocmb->getAttr<ATTR_OCMB_FW_STATE>())
    {
    case OCMB_FW_STATE_INVALID:
    case OCMB_FW_STATE_UNKNOWN:
        state.ocmb_fw_up_to_date = unknown;
        break;
    case OCMB_FW_STATE_UP_TO_DATE:
        state.ocmb_fw_up_to_date = yes;
        break;
    case OCMB_FW_STATE_OUT_OF_DATE:
        state.ocmb_fw_up_to_date = no;
        break;
    }

    return ody_upd_process_event(i_ocmb, state, i_event, move(i_errlog), o_restart_needed);
}

/** @brief Process an event that concerns all Odyssey OCMBs in the system. This is
 *  a wrapper around ody_upd_process_event.
 */
errlOwner ocmbupd::ody_upd_all_process_event(const ody_upd_event_t i_event,
                                             const functional_ocmbs_only_t i_which_ocmbs,
                                             const perform_reconfig_t i_perform_reconfig_if_needed,
                                             bool* const o_restart_needed)
{
    ISTEP_ERROR::IStepError error_accum;
    bool restart_needed = false;

    do
    {

    ISTEP::parallel_for_each(composable(getAllChips)(TYPE_OCMB_CHIP, i_which_ocmbs == EVENT_ON_FUNCTIONAL_OCMBS),
                             error_accum,
                             "ody_upd_all_process_event",
                             [&](Target* const ocmb) -> errlHndl_t
    {
        if (!UTIL::isOdysseyChip(ocmb))
        {
            return nullptr;
        }

        TRACF(INFO_MRK"ody_upd_all_process_event: Issuing Odyssey FSM event "
              "%s on chip 0x%08X",
              event_to_str(i_event).data(),
              get_huid(ocmb));

        errlOwner event_errlog = nullptr; // no error to consider here

        // Note that all the threads have access to write to
        // restart_needed in parallel; however, since they are doing
        // simple stores (no reads), no synchronization is needed.
        auto fsm_error = ocmbupd::ody_upd_process_event(ocmb, i_event, move(event_errlog), restart_needed);

        if (fsm_error)
        {
            TRACF(ERR_MRK"ody_upd_all_process_event: ody_upd_process_event(0x%08x, %s) failed: "
                  TRACE_ERR_FMT,
                  get_huid(ocmb),
                  event_to_str(i_event).data(),
                  TRACE_ERR_ARGS(fsm_error));
            SBEIO::UdSPPECodeLevels(ocmb).addToLog(fsm_error);
        }

        return fsm_error.release();
    });

    if (!error_accum.isNull())
    { // do not set o_restart_needed or request a reconfig loop if there was an error.
        break;
    }

    if (restart_needed && (i_perform_reconfig_if_needed == REQUEST_RECONFIG_IF_NEEDED))
    {
        TRACF(INFO_MRK"ody_upd_all_process_event: Requesting reconfig loop");

        setOrClearReconfigLoopReason(HWAS::ReconfigSetOrClear::RECONFIG_SET,
                                     RECONFIGURE_LOOP_OCMB_FW_UPDATE);
    }

    if (o_restart_needed)
    {
        *o_restart_needed = restart_needed;
    }

    } while (false);

    return errlOwner(error_accum.getErrorHandle());
}

/** @brief Set the Odyssey code update state related to the firmware
 *  levels on the given target. Assumes that ATTR_SPPE_BOOT_SIDE is already
 *  set on the target.
 */
errlHndl_t ocmbupd::set_ody_code_levels_state(Target* const i_ocmb)
{
    errlHndl_t errl = nullptr;

    do
    {

    ody_cur_version_new_image_t images;
    uint64_t rt_vsn = 0, bldr_vsn = 0;

    errl = check_for_odyssey_codeupdate_needed(i_ocmb, images, &rt_vsn, &bldr_vsn);

    if (errl)
    {
        TRACF("set_ody_code_levels_state: check_for_odyssey_codeupdate_needed failed: "
              TRACE_ERR_FMT,
              TRACE_ERR_ARGS(errl));
        errl->collectTrace(OCMBUPD_COMP_NAME);
        break;
    }

    if (!images.empty())
    { // The golden side is always considered to be out of date for
      // the purposes of code update. This causes an update to always
      // happen when booting from the golden side.
        i_ocmb->setAttr<ATTR_OCMB_FW_STATE>(OCMB_FW_STATE_OUT_OF_DATE);
    }
    else
    {
        i_ocmb->setAttr<ATTR_OCMB_FW_STATE>(OCMB_FW_STATE_UP_TO_DATE);
    }

    const auto boot_side = i_ocmb->getAttr<ATTR_SPPE_BOOT_SIDE>();
    const char* side_string = "golden side";

    if (boot_side == SPPE_BOOT_SIDE_SIDE0)
    {
        side_string = "side 0";
    }
    else if (boot_side == SPPE_BOOT_SIDE_SIDE1)
    {
        side_string = "side 1";
    }

    ATTR_OCMB_CODE_LEVEL_SUMMARY_type vsn_string = { };

    snprintf(vsn_string, sizeof(vsn_string),
             "(%s) bldr vsn=0x%16lx, rt vsn=0x%16lx",
             side_string, bldr_vsn, rt_vsn);

    i_ocmb->setAttr<ATTR_OCMB_CODE_LEVEL_SUMMARY>(vsn_string);

    } while (false);

    return errl;
}


namespace ocmbupd
{
errlHndl_t ody_has_async_ffdc(Target* const i_ocmb,
                              bool& o_hasAsyncFfdc)
{
    errlHndl_t l_errl = nullptr;
    o_hasAsyncFfdc = false;

    // See mbxscratch.H for this definition
    typedef union
    {
        struct
        {
            uint32_t iv_sbeBooted : 1;
            uint32_t iv_asyncFFDC : 1;
            uint32_t iv_reserved1 : 1;
            uint32_t iv_currImage : 1; // If 0->SROM , 1->Boot Loader/Runtime
            uint32_t iv_prevState : 4;
            uint32_t iv_currState : 4;
            uint32_t iv_majorStep : 4;
            uint32_t iv_minorStep : 6;
            uint32_t iv_reserved2 : 4;
            uint32_t iv_progressCode : 6;
        };
        uint32_t iv_messagingReg;
    } messagingReg_t;

    uint32_t l_data = 0;
    uint64_t l_dataSize = sizeof(l_data);
    l_errl = deviceRead(i_ocmb,
                        &l_data,
                        l_dataSize,
                        DEVICE_CFAM_ADDRESS(0x2809));
    if(l_errl)
    {
        TRACF(ERR_MRK"ody_has_async_ffdc: Could not read SBE MSG register for OCMB 0x%.8X", get_huid(i_ocmb));
    }
    else
    {
        messagingReg_t l_msgReg;
        l_msgReg.iv_messagingReg = l_data;
        o_hasAsyncFfdc = l_msgReg.iv_asyncFFDC;
        TRACF("Reg 2809=%.8X for OCMB 0x%.8X, o_hasAsyncFfdc=%d", l_data, get_huid(i_ocmb), o_hasAsyncFfdc);
    }

    return l_errl;
}

/** @brief Combine two sha512 hashes and place the result in the
 *  first.
 */
void combine_hashes(uint8_t* const io_hash1,
                    const uint8_t* const i_hash2)
{
    std::transform(io_hash1, io_hash1 + sizeof(ocmbfw_hash_t),
                   i_hash2,
                   io_hash1,
                   [](const uint8_t a, const uint8_t b) {
                       return a ^ b;
                   });
}

/** @brief Calculate the combined hash of all the firmware images in
 *  PNOR that apply to the given OCMB, and place the hash in
 *  o_image_hash.
 */
errlOwner pnor_combined_images_hash(Target* const i_ocmb,
                                    ocmbfw_hash_t o_image_hash)
{
    errlOwner errl;

    memset(o_image_hash, 0, sizeof(*o_image_hash));

    const auto ec = i_ocmb->getAttr<ATTR_EC>();
    const auto dd_level_major = (ec & 0xF0) >> 4,
               dd_level_minor = (ec & 0x0F);

    for (const auto img_type : { IMAGE_TYPE_BOOTLOADER,
                                 IMAGE_TYPE_RUNTIME })
    {
        const ocmbfw_ext_image_info* img = nullptr;

        errlOwner pnor_errl { find_ocmbfw_ext_image(img,
                                                    OCMBFW_HANDLE.get(),
                                                    OCMB_TYPE_ODYSSEY,
                                                    img_type,
                                                    dd_level_major,
                                                    dd_level_minor) };

        if (pnor_errl)
        {
            TRACF("pnor_combined_images_hash: find_ocmbfw_ext_image(img_type=%d, dd_major=%d, dd_minor=%d) "
                  "for OCMB 0x%08X failed",
                  img_type, dd_level_major, dd_level_minor,
                  get_huid(i_ocmb));
            aggregate(errl, move(pnor_errl));
            continue;
        }

        combine_hashes(&o_image_hash[0], img->image_hash);
    }

    return errl;
}

/** @brief Initialize the Odyssey OCMB update system.
 */
errlOwner ody_upd_init()
{
    TRACF(ENTER_MRK"ody_upd_init");

    errlOwner errl;

    /* Check whether the Odyssey firmware in PNOR for any OCMB has
       changed. If so, we reset the Odyssey FSM state for that OCMB so
       that the code update procedure starts from scratch. (This
       solves the potential problem where we update an OCMB, reboot on
       the other side and check whether the update worked, but PNOR
       has changed in the meanwhile, and we detect a hash mismatch
       between PNOR and the firmware on the OCMB.) */

    for (const auto ocmb : composable(getAllChips)(TYPE_OCMB_CHIP, /*functional=*/true))
    {
        if (!UTIL::isOdysseyChip(ocmb))
        {
            continue;
        }

        alignas(uint64_t) ocmbfw_hash_t combined_hash = { };
        auto pnor_err = pnor_combined_images_hash(ocmb, combined_hash);

        if (errl)
        {
            aggregate(errl, move(pnor_err));
            continue;
        }

        alignas(uint64_t) auto previous_hash
            = ocmb->getAttrAsStdArr<ATTR_ODY_PNOR_COMBINED_IMAGES_HASH>();

        TRACF("ody_upd_init: OCMB 0x%08x New vs. old hashes: %016x[...] vs %016x[...]",
              get_huid(ocmb),
              *reinterpret_cast<uint64_t*>(combined_hash),
              *reinterpret_cast<uint64_t*>(previous_hash.data()));

        if (memcmp(previous_hash.data(), combined_hash, sizeof(ocmbfw_hash_t)))
        {
            TRACF("ody_upd_init: PNOR images for OCMB 0x%08X have changed; "
                  "restarting update process",
                  get_huid(ocmb));

            ody_upd_reset_state(ocmb);
            memcpy(previous_hash.data(), combined_hash, sizeof(ocmbfw_hash_t));
            ocmb->setAttrFromStdArr<ATTR_ODY_PNOR_COMBINED_IMAGES_HASH>(previous_hash);
        }
    }

    TRACF(EXIT_MRK"ody_upd_init = 0x%08X", ERRL_GETEID_SAFE(errl));

    return errl;
}

} // namespace ocmbupd
