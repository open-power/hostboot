/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfRepairHealth.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2014              */
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

/** @file prdfRepairHealth.H
 *  @brief Defines interfaces to get applied repairs and health for a FRU, such
 *  as a DIMM.
 */
#ifndef __PRDF_PRDFREPAIRHEALTH_H
#define __PRDF_PRDFREPAIRHEALTH_H

#include <vector>
#include <algorithm>

#include <errlentry.H>

// NOTE: Cannot use utilities prdfTrace.H because this code is pulled into
//       libprdf_asm.so which is a very limited environment.
extern tracDesc_t g_asmTracDesc;

// Forward declaration.
class PrdfRepairHealthStatus;

/** @fn prdfGetRepairHealthStatus
 *  @brief Get the repair / health information for a RID.
 *
 *  @param i_rid - The RID to get health information on.
 *  @param o_repairs - Vector containing RepairHealthStatus objects found for
 *                         the RID.
 *
 *  @return NULL or error log.
 *
 *  The vector returned can contain information about many repairs, each in
 *  their own object.  These repairs may even be of the same type but will have
 *  a unique identifier.  For instance, a DIMM RID might return a set of "Chip
 *  Marks" for each "Rank" in the DIMM, a set of "Symbol Marks" for each "Rank"
 *  in the DIMM, and a single "DRAM Steer" for the entire DIMM.
 *
 *  RID types presently supported:
 *          - DIMMs.
 */
errlHndl_t prdfGetRepairHealthStatus(uint32_t i_rid,
                            std::vector<PrdfRepairHealthStatus> & o_repairs);

/** @class PrdfRepairHealthStatus
 *  @brief Holds information about a particular repair.
 *
 *  A particular repair contains:
 *          - An identifier of the type of repair this is.
 *          - A set of identifying information about the repair.
 *          - A maximum and currently applied repair count.
 *
 *  The identifying information about a repair can be of various amounts
 *  depending on the type of repair.  For instance, a DIMM "Chip Mark" may only
 *  list the DIMM "Rank" while a "Bus eRepair" might have "Bus Direction" and
 *  two or more associated FRU identifiers.
 *
 *  @note The identifiers for Interface eRepair are not finalized.  Support for
 *  this is not until 7.2.
 */
class PrdfRepairHealthStatus
{
    public:
        /** Types of repairs possible. */
        enum RepairTypes
        {
                /** UNKNOWN / Default Repair */
            PRDF_REPAIR_UNKNOWN,
                /** DIMM Chip Mark */
            PRDF_REPAIR_CHIP_MARK,
                /** DIMM Symbol Mark */
            PRDF_REPAIR_SYMBOL_MARK,
                /** DIMM Spare DRAM Steer - not supported on all DIMMs */
            PRDF_REPAIR_SPARE_DRAM_STEER,
                /** Inter-chip Bus Repair (eRepair) */
            PRDF_REPAIR_INTERFACE_REPAIR,
        };

        /** Types of associated identifying information */
        enum RepairIdentifiers
        {
                /** DIMM Rank ID */
            PRDF_REPAIR_ID_RANK,
                /** Inter-chip Bus Repair - Bus Direction */
            PRDF_REPAIR_ID_BUS_DIRECTION,
                /** Inter-chip Bus Repair - Upstream Chip */
            PRDF_REPAIR_ID_BUS_UPSTREAM_CHIP,
        //** Inter-chip Bus Repair - Memory Controller Sequence*/
        PRDF_REPAIR_ID_BUS_MC_SEQUENCE,
        //** Inter-chip Bus Repair - Memory Controller Channel*/
        PRDF_REPAIR_ID_BUS_MC_CHANNEL,
        //** Inter-chip Bus Repair - Bus Repair Bit*/
        PRDF_REPAIR_ID_BUS_REPAIR_BIT,
        //** Inter-chip Bus Repair - Clock Repaired*/
        PRDF_REPAIR_ID_BUS_CLOCK_REPAIRED,
        };

        /** Structure to hold associated identifying information */
        struct RepairId
        {
            RepairIdentifiers idType;
            uint32_t id;
        };

    public:
        /** Default constructor */
        PrdfRepairHealthStatus() : iv_repairType(PRDF_REPAIR_UNKNOWN),
                                   iv_repairIdsCount(0),
                                   iv_repairIds(NULL),
                                   iv_repairsAllowed(0),
                                   iv_repairsPresent(0) {};
        /** Copy constructor */
        PrdfRepairHealthStatus(const PrdfRepairHealthStatus & copy)
                                : iv_repairType(copy.iv_repairType),
                                  iv_repairIdsCount(copy.iv_repairIdsCount),
                                  iv_repairsAllowed(copy.iv_repairsAllowed),
                                  iv_repairsPresent(copy.iv_repairsPresent)
                {
                    // Copy the identfying info array into new object.
                    if (NULL == copy.iv_repairIds)
                        iv_repairIds = NULL;
                    else
                    {
                        iv_repairIds = new RepairId[iv_repairIdsCount];

                        std::copy(copy.iv_repairIds,
                                  &copy.iv_repairIds[iv_repairIdsCount],
                                  iv_repairIds);
                    }
                }
        /** Destructor */
        ~PrdfRepairHealthStatus()
                {
                    // Clean up the identifying info array.
                    if (NULL != iv_repairIds)
                    {
                        delete [] iv_repairIds;
                        iv_repairIds = NULL;
                    }
                }

        // ---- External interfaces ---- //
            /** Return the type of repair. */
        RepairTypes getRepairType() const { return iv_repairType; }
            /** Return the number of associated identifying infos. */
        size_t getRepairIdsCount() const { return iv_repairIdsCount; }
            /** @fn getRepairIds
             *
             * @brief Return pointer to associated identifying info array.
             * @note This pointer should NOT be deleted by the caller.  It is
             *       owned by this object. */
        const RepairId * getRepairIds() const { return iv_repairIds; }
            /** Return maximum number of repairs allowed of this type / id */
        size_t getRepairsAllowed() const { return iv_repairsAllowed; }
            /** Return current number of repairs of this type / id */
        size_t getRepairsPresent() const { return iv_repairsPresent; }

    protected:
        /* ---- Interfaces for assigning contents. ----
         * These are defined protected so that only inheriting classes can
         * used these.  Design is that a repair type will define a "builder"
         * class that has a constructor with the parameters to complete this
         * object and fill in the extra identifying information.
         */
            /** Assign repair type */
        void setRepairType(RepairTypes i_repairType)
                { iv_repairType = i_repairType; }
            /** @fn setRepairIds
             *
             * @brief Assign identifying info
             * @param i_repairIds - This must be allocated using the new[] and
             *                 ownership of the memory transfers to this object.
             */
        void setRepairIds(size_t i_repairIdsCount, RepairId * i_repairIds)
                { iv_repairIdsCount = i_repairIdsCount;
                  iv_repairIds = i_repairIds; }
            /** Assign max / current repair counts */
        void setRepairCounts(size_t i_allowed, size_t i_present)
                { iv_repairsAllowed = i_allowed;
                  iv_repairsPresent = i_present; };

    private:
            /** Repair type */
        RepairTypes iv_repairType;

            /** Extra identifying info count */
        size_t iv_repairIdsCount;
            /** Extra identifying info array */
        RepairId * iv_repairIds;

            /** Maximum repair count. */
        size_t iv_repairsAllowed;
            /** Current repair count. */
        size_t iv_repairsPresent;
};

#endif
