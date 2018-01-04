/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/rt_targeting.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2018                        */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludlogregister.H>
#include <errl/errludtarget.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicatepostfixexpr.H>
#include <targeting/common/predicates/predicateattrval.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>
#include <targeting/common/targreasoncodes.H>
#include <targeting/common/attributeTank.H>
#include <targeting/attrrp.H>
#include <arch/pirformat.H>
#include <runtime/customize_attrs_for_payload.H>
#include <runtime/rt_targeting.H>
#include <runtime/interface.h>
#include <map>
#include <util/memoize.H>
#include <util/runtime/util_rt.H>
#include <util/utillidmgr.H>

using namespace TARGETING;

namespace RT_TARG
{

errlHndl_t getRtTarget(
    const TARGETING::Target* i_pTarget,
          rtChipId_t&        o_rtTargetId)
{
    errlHndl_t pError = NULL;

    do
    {
        if(i_pTarget == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            TARGETING::Target* masterProcChip = NULL;
            TARGETING::targetService().
                masterProcChipTargetHandle(masterProcChip);
            i_pTarget = masterProcChip;
        }

        auto hbrtHypId = RUNTIME::HBRT_HYP_ID_UNKNOWN;
        if(   (!i_pTarget->tryGetAttr<TARGETING::ATTR_HBRT_HYP_ID>(hbrtHypId))
           || (hbrtHypId == RUNTIME::HBRT_HYP_ID_UNKNOWN))
        {
            auto huid = get_huid(i_pTarget);
            auto targetingTargetType =
                i_pTarget->getAttr<TARGETING::ATTR_TYPE>();
            TRACFCOMP(g_trac_targeting, ERR_MRK
                "Targeting target type of 0x%08X not supported. "
                "HUID: 0x%08X",
                targetingTargetType,
                huid);
            /*@
             * @errortype
             * @moduleid    TARG_RT_GET_RT_TARGET
             * @reasoncode  TARG_RT_TARGET_TYPE_NOT_SUPPORTED
             * @userdata1   Target's HUID
             * @userdata2   target's targeting type
             * @devdesc     Targeting target's type not supported by runtime
             *              code
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                TARGETING::TARG_RT_GET_RT_TARGET,
                TARGETING::TARG_RT_TARGET_TYPE_NOT_SUPPORTED,
                huid,
                targetingTargetType,
                true);

            ERRORLOG::ErrlUserDetailsTarget(i_pTarget,"Targeting Target").
                addToLog(pError);
        }

        o_rtTargetId = hbrtHypId;

    } while(0);

    return pError;
}

/**
 *  @brief API documentation same as for getHbTarget; this just implements the
 *      core logic (i.e. called when the memoizer doesn't have a cached answer)
 */
errlHndl_t _getHbTarget(
    const rtChipId_t          i_rtTargetId,
          TARGETING::Target*& o_target)
{
    errlHndl_t pError = NULL;

    do
    {
        // Don't even attempt the lookup if the unknown ID is used
        TARGETING::TargetHandle_t pTarget = NULL;
        if(i_rtTargetId != RUNTIME::HBRT_HYP_ID_UNKNOWN)
        {
            for (TARGETING::TargetIterator pIt =
                    TARGETING::targetService().begin();
                 pIt != TARGETING::targetService().end();
                 ++pIt)
            {
                auto rtTargetId = RUNTIME::HBRT_HYP_ID_UNKNOWN;
                if(   ((*pIt)->tryGetAttr<
                           TARGETING::ATTR_HBRT_HYP_ID>(rtTargetId))
                   && (rtTargetId == i_rtTargetId))
                {
                    pTarget = (*pIt);
                    break;
                }
            }
        }

        if(pTarget == NULL)
        {
            TRACFCOMP( g_trac_targeting, ERR_MRK
                "Can't find targeting target for runtime target ID of "
                "0x%16llX",
                i_rtTargetId);
            /*@
             * @errortype
             * @moduleid     TARGETING::TARG_RT_GET_HB_TARGET
             * @reasoncode   TARGETING::TARG_RT_TARGET_TYPE_NOT_SUPPORTED
             * @userdata1    Runtime target ID
             * @userdata2    0
             * @devdesc      Can't find targeting target for given runtime
             *               target ID
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                TARGETING::TARG_RT_GET_HB_TARGET,
                TARGETING::TARG_RT_TARGET_TYPE_NOT_SUPPORTED,
                i_rtTargetId,
                0,
                true);
        }

        o_target = pTarget;

    } while(0);

    return pError;
}

errlHndl_t getHbTarget(
    const rtChipId_t          i_rtTargetId,
          TARGETING::Target*& o_target)
{
      return Util::Memoize::memoize(_getHbTarget,i_rtTargetId,o_target);
}

/**
 * @brief Validate LID Structure against Reserved Memory.  Check that the
 * TargetingHeader eyecatchers are valid, that the TargetingHeader number of
 * sections match, and that the types and sizes of each TargetingSection
 * match.
 * @param[in] Pointer to new LID Structure targeting binary data
 * @param[in] Pointer to current Reserved Memory targeting binary data
 * @param[out] Error log userdata2 value associated with non-zero rtn code
 * @return 0 on success, else return code
 */
int validateData(void *i_lidStructPtr,
                 void *i_rsvdMemPtr,
                 uint64_t& o_userdata2)
{
    TRACFCOMP(g_trac_targeting, ENTER_MRK"validateData: %p %p",
              i_lidStructPtr, i_rsvdMemPtr);

    int rc = 0;
    o_userdata2 = 0;

    do
    {
        // Get pointers to TargetingHeader areas of each buffer
        TargetingHeader* l_headerLid =
            reinterpret_cast<TargetingHeader*>(i_lidStructPtr);
        TargetingHeader* l_headerRsvd =
            reinterpret_cast<TargetingHeader*>(i_rsvdMemPtr);

        // Find start to the first section in each buffer:
        //          (header address + size of header + offset in header)
        TargetingSection* l_sectionLid =
            reinterpret_cast<TargetingSection*>(
                reinterpret_cast<uint64_t>(l_headerLid) +
                sizeof(TargetingHeader) +
                l_headerLid->offsetToSections);
        TargetingSection* l_sectionRsvd =
            reinterpret_cast<TargetingSection*>(
                reinterpret_cast<uint64_t>(l_headerRsvd) +
                sizeof(TargetingHeader) +
                l_headerRsvd->offsetToSections);

        // Validate LID Structure TargetingHeader eyecatcher
        if (l_headerLid->eyeCatcher != PNOR_TARG_EYE_CATCHER)
        {
            TRACFCOMP(g_trac_targeting,
                      "validateData: bad eyecatcher 0x%.8x found in "
                      "LID Structure TargetingHeader",
                      l_headerLid->eyeCatcher);

            rc = 0x11;
            o_userdata2 = l_headerLid->eyeCatcher;

            break;
        }

        // Validate Reserved Memory TargetingHeader eyecatcher
        if (l_headerRsvd->eyeCatcher != PNOR_TARG_EYE_CATCHER)
        {
            TRACFCOMP(g_trac_targeting,
                      "validateData: bad eyecatcher 0x%.8x found in "
                      "Reserved Memory TargetingHeader",
                      l_headerRsvd->eyeCatcher);

            rc = 0x12;
            o_userdata2 = l_headerRsvd->eyeCatcher;

            break;
        }

        // Validate TargetingHeader number of sections
        if (l_headerLid->numSections != l_headerRsvd->numSections)
        {
            TRACFCOMP(g_trac_targeting,
                      "validateData: TargetingHeader number of sections "
                      "miscompare, %d LID Structure sections, %d Reserved "
                      "Memory sections",
                      l_headerLid->numSections,
                      l_headerRsvd->numSections);

            rc = 0x013;
            o_userdata2 = TWO_UINT32_TO_UINT64(l_headerLid->numSections,
                                               l_headerRsvd->numSections);

            break;
        }

        // Count of attribute sections
        size_t l_sectionCount = l_headerLid->numSections;

        // Loop on each TargetingSection
        for (size_t i = 0;
             i < l_sectionCount;
             ++i, ++l_sectionLid, ++l_sectionRsvd)
        {
            // Validate TargetingSection type
            if (l_sectionLid->sectionType != l_sectionRsvd->sectionType)
            {
                TRACFCOMP(g_trac_targeting,
                          "validateData: TargetingSection types miscompare, "
                          "LID Struct type 0x%0.2x, Rsvd Memory type 0x%0.2x",
                          l_sectionLid->sectionType,
                          l_sectionRsvd->sectionType);

                rc = 0x14;
                o_userdata2 = TWO_UINT32_TO_UINT64(l_sectionLid->sectionType,
                                                   l_sectionRsvd->sectionType);

                break;
            }

            // Validate TargetingSection size
            if (l_sectionLid->sectionSize != l_sectionRsvd->sectionSize)
            {
                TRACFCOMP(g_trac_targeting,
                          "validateData: TargetingSection sizes miscompare, "
                          "LID Struct size 0x%0.4x, Rsvd Memory size 0x%0.4x",
                          l_sectionLid->sectionSize,
                          l_sectionRsvd->sectionSize);

                // Just trace the size mismatch; Don't set rc or break
            }
        }
        // *** Could check if rc was set in for loop and break from do loop
    } while(false);

    TRACFCOMP(g_trac_targeting,EXIT_MRK"validateData");

    return rc;
}

/**
 * @brief Save/Restore attribute values from current Reserved Memory data
 * into new LID Structure data
 * @param[in] Pointer to current Reserved Memory targeting binary data
 * @param[in/out] Pointer to new LID Structure targeting binary data
 * @param[out] Error log userdata2 value associated with non-zero rtn code
 * @return 0 on success, else return code
 */
int saveRestoreAttrs(void *i_rsvdMemPtr,
                     void *io_lidStructPtr,
                     uint64_t& o_userdata2)
{
    TRACFCOMP( g_trac_targeting,
               ENTER_MRK"saveRestoreAttrs: %p %p",
               i_rsvdMemPtr, io_lidStructPtr);

    int rc = 0;
    o_userdata2 = 0;
    AttrRP *l_attrRPLid = nullptr;

    do
    {
        // Node ID
        NODE_ID l_nodeId = NODE0;

        // Locate current Reserved Memory data via TargetService
        TARGETING::TargetService& l_targSrv = TARGETING::targetService();

        // Get singleton AttrRP instance for current Reserved Memory data
        AttrRP *l_attrRPRsvd = &TARG_GET_SINGLETON(TARGETING::theAttrRP);

        // Create temporary AttrRP instance for new LID Structure targeting data
        l_attrRPLid =
            new AttrRP(reinterpret_cast<TargetingHeader*>(io_lidStructPtr));

        // Create TargetRangeFilter for LID Structure targeting data
        uint32_t l_maxTargetsLid = 0;
        TargetRangeFilter l_allTargetsLid =
            l_targSrv.getTargetRangeFilter(io_lidStructPtr,
                                           l_attrRPLid,
                                           l_maxTargetsLid,
                                           l_nodeId);

        // Set up variables for getting attribute information for a target
        uint32_t l_attrCountRsvd = 0;
        ATTRIBUTE_ID* l_pAttrIdRsvd = nullptr;
        AbstractPointer<void>* l_ppAttrAddrRsvd = nullptr;
        uint32_t l_attrCountLid = 0;
        ATTRIBUTE_ID* l_pAttrIdLid = nullptr;
        AbstractPointer<void>* l_ppAttrAddrLid = nullptr;
        uint32_t l_huidLid = 0;
        EntityPath l_physPathLid;

        // Walk through new LID Structure Targets
        for(uint32_t l_targetNum = 1;
            (l_targetNum <= l_maxTargetsLid) && (rc == 0);
            ++l_allTargetsLid, ++l_targetNum)
        {
            // Counts of how many new attribute values were kept
            uint32_t l_kept_for_added_attr = 0;
            uint32_t l_kept_for_unknown_size = 0;

            // Get attribute information for a target in LID Structure (new)
            l_attrCountLid = l_targSrv.getTargetAttributes(*l_allTargetsLid,
                                                           l_attrRPLid,
                                                           l_pAttrIdLid,
                                                           l_ppAttrAddrLid);

            // Make sure that attributes were found
            if(l_attrCountLid == 0)
            {
                // Continue to next target if there were no attributes
                continue;
            }

            l_huidLid = l_allTargetsLid->getAttr<ATTR_HUID>();
            l_physPathLid = l_allTargetsLid->getAttr<ATTR_PHYS_PATH>();
            TRACFCOMP( g_trac_targeting,
                       "Target %3d has %3d attrs, class %0.8x, type %0.8x, "
                       "ord ID %0.8x, HUID 0x%0.8x, %s",
                       l_targetNum,
                       l_attrCountLid,
                       l_allTargetsLid->getAttr<ATTR_CLASS>(),
                       l_allTargetsLid->getAttr<ATTR_TYPE>(),
                       l_allTargetsLid->getAttr<ATTR_ORDINAL_ID>(),
                       l_huidLid,
                       l_physPathLid.toString());

            // Create bool used while checking if target exists in current data
            bool targetMatched = false;

            // Create TargetRangeFilter for current Reserved Memory data
            TargetRangeFilter l_allTargetsRsvd(l_targSrv.begin(),
                                               l_targSrv.end(),
                                               NULL);

            // Walk through current Reserved Memory Targets
            for(;
                l_allTargetsRsvd;
                ++l_allTargetsRsvd)
            {
                if((l_allTargetsLid->getAttr<ATTR_CLASS>() ==
                    l_allTargetsRsvd->getAttr<ATTR_CLASS>()) &&
                   (l_allTargetsLid->getAttr<ATTR_TYPE>() ==
                    l_allTargetsRsvd->getAttr<ATTR_TYPE>()) &&
                   (l_allTargetsLid->getAttr<ATTR_ORDINAL_ID>() ==
                    l_allTargetsRsvd->getAttr<ATTR_ORDINAL_ID>()) &&
                   (l_physPathLid ==
                    l_allTargetsRsvd->getAttr<ATTR_PHYS_PATH>()))
                {
                    // Flag the match
                    targetMatched = true;

                    break;
                }
            }

            // Check if target was matched up
            if(!targetMatched)
            {
                TRACFCOMP( g_trac_targeting,
                           "saveRestoreAttrs: Did not find target "
                           "HUID 0x%0.8x, %s in Reserved Memory, "
                           "Keeping targeting data from LID Structure",
                           l_huidLid,
                           l_physPathLid.toString());

                // rc should not be changed

                // Go to next new LID Structure target
                continue;
            }

            // Get attribute information for a target in Reserved Memory (cur)
            l_attrCountRsvd = l_targSrv.getTargetAttributes(*l_allTargetsRsvd,
                                                            l_attrRPRsvd,
                                                            l_pAttrIdRsvd,
                                                            l_ppAttrAddrRsvd);
            TRACDCOMP( g_trac_targeting,
                       "Rsvd Memory: "
                       "HUID 0x%0.8x, attr cnt %d, AttrRP %p, pAttrId %p, "
                       "ppAttrAddr %p",
                       l_allTargetsRsvd->getAttr<ATTR_HUID>(),
                       l_attrCountRsvd,
                       l_attrRPRsvd,
                       l_pAttrIdRsvd,
                       l_ppAttrAddrRsvd);

            // Compare attribute counts for new LID Structure target and current
            // Reserved Memory target to see if they differ or not
            if(l_attrCountLid != l_attrCountRsvd)
            {
                // Trace when the attribute counts differ
                TRACFCOMP( g_trac_targeting,
                           "Attribute counts for target with HUID 0x%0.8x "
                           "differ, LID Structure count %d, Reserved Memory "
                           "count %d",
                           l_huidLid,
                           l_attrCountLid,
                           l_attrCountRsvd);
            }

            // Walk through Attributes for the new LID Structure target
            for(uint32_t l_attrNumLid = 0;
                (l_attrNumLid < l_attrCountLid) && (rc == 0);
                ++l_attrNumLid)
            {
                // Get ID for attribute on this pass through loop
                ATTRIBUTE_ID* l_pAttrId = l_pAttrIdLid + l_attrNumLid;

                // Get the Reserved Memory attribute value pointer
                void* l_pAttrRsvd = nullptr;
                l_allTargetsRsvd->_getAttrPtr(*l_pAttrId,
                                              l_attrRPRsvd,
                                              l_pAttrIdRsvd,
                                              l_ppAttrAddrRsvd,
                                              l_pAttrRsvd);

                // Check if attribute is in Reserved Memory data
                if(l_pAttrRsvd != nullptr)
                {
                    // Get the LID Structure attribute value pointer
                    void* l_pAttrLid = nullptr;
                    l_allTargetsLid->_getAttrPtr(*l_pAttrId,
                                                 l_attrRPLid,
                                                 l_pAttrIdLid,
                                                 l_ppAttrAddrLid,
                                                 l_pAttrLid);

                    // Check if attribute is in LID Structure data
                    if(l_pAttrLid == nullptr)
                    {
                        TRACFCOMP( g_trac_targeting,
                                   ERR_MRK"saveRestoreAttrs: UNEXPECTEDLY Did "
                                   "not find value pointer for attribute ID "
                                   "0x%.8x, target HUID 0x%0.8x in LID "
                                   "Structure",
                                   *l_pAttrId,
                                   l_huidLid);

                        rc = 0x21;
                        o_userdata2 = TWO_UINT32_TO_UINT64(l_huidLid,
                                                           *l_pAttrId);

                        break;
                    }

                    // Look up the size of the attribute
                    uint32_t l_attrSize = attrSizeLookup(*l_pAttrId);

                    // Check that a valid size was returned for the attribute
                    if(l_attrSize == 0)
                    {
                        TRACDCOMP( g_trac_targeting,
                                   "UNEXPECTEDLY Did not find size for "
                                   "attribute ID 0x%.8x, target HUID 0x%0.8x "
                                   "in Reserved Memory, Keeping value from "
                                   "LID Structure",
                                   *l_pAttrId,
                                   l_allTargetsRsvd->getAttr<ATTR_HUID>());

                        // Increment for keeping value because size was unknown
                        ++l_kept_for_unknown_size;

                        // rc should not be changed

                        // Continue with this target's next attribute
                        continue;
                    }

                    // Check if new attribute value differs from current value
                    if(memcmp(l_pAttrRsvd, l_pAttrLid, l_attrSize) != 0)
                    {
                        TRACDCOMP( g_trac_targeting,
                                   "Found differing values for attribute ID "
                                   "0x%.8x, HUID 0x%0.8x",
                                   *l_pAttrId,
                                   l_huidLid);

                        TRACDBIN( g_trac_targeting,
                                  "Reserved Memory value",
                                  l_pAttrRsvd,
                                  l_attrSize);

                        TRACDBIN( g_trac_targeting,
                                  "LID Structure value",
                                  l_pAttrLid,
                                  l_attrSize);

                        // Copy attribute value from current Reserved Memory
                        // attribute to new LID Structure attribute
                        memcpy(l_pAttrRsvd, l_pAttrLid, l_attrSize);
                    }
                }
                else
                {
                    TRACDCOMP( g_trac_targeting,
                               "Did not find attribute ID 0x%.8x, target HUID "
                               "0x%0.8x in Reserved Memory, Keeping value from "
                               "LID Structure",
                               *l_pAttrId,
                               l_huidLid);

                    // Increment for keeping value because attribute was added
                    ++l_kept_for_added_attr;

                    // rc should not be changed

                    // Continue with this target's next attribute
                    continue;
                }
            } // for attributes

            if((l_kept_for_added_attr != 0) || (l_kept_for_unknown_size != 0))
            {
                TRACFCOMP( g_trac_targeting,
                           "Kept LID Structure value for %d added attribute(s) "
                           "and for %d attribute(s) with unknown size",
                           l_kept_for_added_attr,
                           l_kept_for_unknown_size);
            }
        } // for targets
    } while(false);

    delete l_attrRPLid;
    l_attrRPLid = nullptr;

    TRACFCOMP( g_trac_targeting, EXIT_MRK"saveRestoreAttrs");

    return rc;
}

int hbrt_update_prep(void)
{
    int rc = 0;
    errlHndl_t pError = nullptr;
    uint64_t l_userdata2 = 0;
    UtilLidMgr l_lidMgr(Util::TARGETING_BINARY_LIDID);
    void *l_lidStructPtr = nullptr;

    do
    {
        // Get size and location of attributes in reserved memory
        uint64_t l_attr_size = 0;
        uint64_t l_rsvdMem = hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_ATTR,
                                                0, l_attr_size);

        // Set pointer to reserved memory targeting data
        void *l_rsvdMemPtr = reinterpret_cast<void*>(l_rsvdMem);

        // Create lidMgr and get size of Targeting Binary LID
        size_t l_lidSize = 0;
        pError = l_lidMgr.getLidSize(l_lidSize);
        if(pError)
        {
            pError->collectTrace(TARG_COMP_NAME);

            rc = 0x01;

            break;
        }

        if(l_lidSize > l_attr_size)
        {
            TRACFCOMP( g_trac_targeting,
                       ERR_MRK"hbrt_update_prep: Sizes of targeting data, "
                       "LID Structure(New) 0x%0.8x is too large for Rsvd "
                       "Memory(Current) 0x%0.8x",
                       l_lidSize,
                       l_attr_size);

            rc = 0x02;
            l_userdata2 = TWO_UINT32_TO_UINT64(l_lidSize,
                                               l_attr_size);

            break;
        }

        // Get new structure from LID
        pError = l_lidMgr.getStoredLidImage(l_lidStructPtr, l_lidSize);
        if(pError)
        {
            pError->collectTrace(TARG_COMP_NAME);

            rc = 0x03;

            break;
        }

        // Validate LID Structure against Reserved Memory
        rc = validateData(l_lidStructPtr,
                          l_rsvdMemPtr,
                          l_userdata2);
        if(rc)
        {
            break;
        }

        // Save/Restore attribute values from current Reserved Memory data into
        // new LID Structure data
        rc = saveRestoreAttrs(l_rsvdMemPtr,
                              l_lidStructPtr,
                              l_userdata2);
        if(rc)
        {
            break;
        }

        // Copy new LID Structure data over current Reserved Memory data
        size_t l_copySize = std::min(l_lidSize, l_attr_size);
        TRACFCOMP( g_trac_targeting,
                   "hbrt_update_prep: Copy 0x%0.8x bytes of targeting data",
                   l_copySize);
        memcpy(l_rsvdMemPtr,
               l_lidStructPtr,
               l_copySize);

        // Set any remaining bytes to zero
        size_t l_setSize = l_attr_size - l_copySize;
        if(l_setSize)
        {
            TRACFCOMP( g_trac_targeting,
                       "hbrt_update_prep: Set 0x%0.8x bytes to 0",
                       l_setSize);
            memset(reinterpret_cast<void*>(
                       reinterpret_cast<uint64_t>(l_rsvdMemPtr) + l_copySize),
                   0,
                   l_setSize);
        }
    } while(false);

    // Release the LID with new targeting structure
    pError = l_lidMgr.releaseLidImage();
    if(pError)
    {
        pError->collectTrace(TARG_COMP_NAME);

        rc = 0x04;
    }

    // Check for failing return code
    if(rc)
    {
        // Determine if an error log has not been created yet
        if(pError == nullptr)
        {
            /*@
             *   @errortype   ERRORLOG::ERRL_SEV_PREDICTIVE
             *   @moduleid    TARG_RT_HBRT_UPDATE_PREP
             *   @reasoncode  TARG_RC_CONCURRENT_CODE_UPDATE_FAIL
             *   @userdata1   HBRT Concurrent Code Update RC
             *   @userdata2   Variable depending on RC
             *
             *   @devdesc   HBRT Concurrent Code Update failure
             *
             *   @custdesc  Internal firmware error preparing
             *              for concurrent code update
             */
            pError =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                        TARG_RT_HBRT_UPDATE_PREP,
                                        TARG_RC_CONCURRENT_CODE_UPDATE_FAIL,
                                        rc,
                                        l_userdata2,
                                        true /*SW Error */);

            pError->collectTrace(TARG_COMP_NAME);
        }

        errlCommit(pError,TARG_COMP_ID);
    }

    return rc;
}

    //------------------------------------------------------------------------

    struct registerRtTarg
    {
        registerRtTarg()
        {
            // Register interface for Host to call
            runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
            rt_intf->prepare_hbrt_update = &hbrt_update_prep;
        }
    };

    registerRtTarg g_registerRtTarg;

}; // End namespace RT_TARG
