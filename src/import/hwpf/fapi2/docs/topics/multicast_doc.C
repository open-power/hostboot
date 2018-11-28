/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/docs/topics/multicast_doc.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include <fapi2.H>
#include <fapi2_target.H>

using namespace fapi2;

void multicast_doc(uint8_t i_core_select)
{
    Target<TARGET_TYPE_PROC_CHIP> l_chip_target;
    Target<TARGET_TYPE_CORE> l_single_core;

    /*
    Multicast Targets: Target type
    ==============================

      # Additional TARGET_TYPE_MULTICAST
      # MC targets are composite targets, e.g. */

    Target < TARGET_TYPE_CORE | TARGET_TYPE_MULTICAST > l_mc_cores;

    /*  # IMPORTANT: Composite type means "this _could_ be multicast" - a specific target may still be unicast!
        # SCOM ops work on UC and MC targets alike
        # Attribute ops work on UC only
        # FAPI2 type-casting rules work in our favor here:
          # Procedures that accept XYZ | MULTICAST targets will implicitly accept XYZ targets
          # XYZ | MULTICAST can't be casted down to XYZ, so we can't accidentally getAttribute() on it */

    l_mc_cores = l_single_core;   // works - these are compatible
    l_single_core = l_mc_cores;   // compile error!

    /*
    Multicast Targets: Multicast type
    =================================

      # Targets gain a MulticastType template parameter, defaults to MULTICAST_OR
        # Don't care for unicast targets
        # No change to existing unicast procedures needed
          # Platform code must be adapted
          # Example SBE implementation in progress
        # No extra binary code generated for unicast targets
      # To change the MC type, use another target and simply assign: */

    Target < TARGET_TYPE_CORE | TARGET_TYPE_MULTICAST, MULTICAST_AND > l_mc_cores_and = l_mc_cores;

    /*  # Type casting / construction takes care of the icky bits
      # Procedures can specify which MC type they require in their header
        # Implicit type cast if necessary
        # Suggest not specifying unless OR type not needed */

    extern ReturnCode p9_hcd_core_chiplet_reset(
        Target < TARGET_TYPE_CORE | TARGET_TYPE_MULTICAST, MULTICAST_AND > i_targets);
    p9_hcd_core_chiplet_reset(l_mc_cores);

    /*
    Getting a multicast target
    ==========================

      # Option A: Your procedure takes an MC target
        # Platform responsible for generating the correct target
      # Option B: Your procedure takes a chip target
        # Derive MC targets yourself */

    auto l_all_mcs = l_chip_target.getMulticast<TARGET_TYPE_PERV>(MCGROUP_GOOD_MEMCTL);

    /*# Abstract MC groups
        # FAPI code never handles numeric group IDs but abstract role descriptors, such as
          "all good except TP", "all good PCI", "all good MCs", "all existing OBUS"
        # More such roles than group IDs in hardware
          # Different groups available during different system phases
        # Platform maps to hardware group IDs, fails if abstract group not mapped
    */

    /*
    Transforming multicast targets
    ============================== */

    auto l_mc_eqs = l_mc_cores.getParent < TARGET_TYPE_EQ | TARGET_TYPE_MULTICAST > ();

    /*  # Will map upwards to a multicast target of parent type
          # Only for CORE -> EQ right now
          # Also we can go back to the chip from anywhere like we're used to */

    std::vector<Target<TARGET_TYPE_EQ> > l_uc_eqs = l_mc_eqs.getChildren<TARGET_TYPE_EQ>();

    /*  # Will expand a multicast target into constituent unicast targets
        # Will return a vector of length one if the target is unicast
    */

    /*
    Special case: Multi-region targets
    ==================================

      # CORE | MULTICAST targets have an extra "core select" value that's got 1 or more bits set. */

    l_mc_cores = l_chip_target.getMulticast(MCGROUP_GOOD_EQ, MCCORE_ALL);

    /*# MulticastCoreSelect is an enum, but you're free to do bitops on it:  */

    uint8_t l_my_core_select = i_core_select & 0xA;
    l_my_core_select = i_core_select & (MCCORE_0 | MCCORE_2); // does the same but avoids magic values
    l_mc_cores = l_chip_target.getMulticast(MCGROUP_GOOD_EQ,
                                            static_cast<MulticastCoreSelect>(l_my_core_select));

    /*# Falling back to unicast will iterate over EQs in the MC group as well as selected cores:  */

    for (auto l_core : l_mc_cores.getChildren<TARGET_TYPE_CORE>())
    {
        // do something to the core
    }

    /*
    Error Handling
    ==============

      # Handling PIB/PCB errors (PIB timeout, parity error, ...) is platform responsibility
        # Gather FFDC from PCB master: Which slaves responded and how?
          # HW will have individual FFDC regs for each PIB master
        # Return to caller
      # Handling unexpected data (ABIST_DONE not on etc.) is procedure responsibility
        # Fall back to unicast and iterate over constituent targets
        # FAPI to provide helper functions to minimize boilerplate
          # Anything more than getChildren needed?
    */

}
