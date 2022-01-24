/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/rt_targeting.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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
#include <targeting/targplatreasoncodes.H>
#include <targeting/common/attributeTank.H>
#include <targeting/attrrp.H>
#include <arch/pirformat.H>
#include <runtime/customize_attrs_for_payload.H>
#include <targeting/translateTarget.H>
#include <runtime/interface.h>
#include <pldm/pldm_errl.H>
#include <map>
#include <util/memoize.H>
#include <util/runtime/util_rt.H>
#include <util/utillidmgr.H>
#include <util/utillidpnor.H>
#include <sys/internode.h>


extern trace_desc_t* g_trac_hbrt;
using namespace TARGETING;

namespace RT_TARG
{

/**
 * @brief Validate LID Structure against Reserved Memory.  Check that the
 * TargetingHeader eyecatchers are valid, that the TargetingHeader number of
 * sections match, and that the types and sizes of each TargetingSection
 * match.
 * @param[in] Pointer to new LID Structure targeting binary data
 * @param[in] Pointer to current Reserved Memory targeting binary data
 * @param[out] Total size of all sections in the new lid
 * @return 0 on success, else return code
 */
errlHndl_t validateData(void *i_lidStructPtr,
                        void *i_rsvdMemPtr,
                        size_t& o_lidTotalSize)
{
    TRACFCOMP(g_trac_targeting, ENTER_MRK"validateData: %p %p",
              i_lidStructPtr, i_rsvdMemPtr);

    errlHndl_t l_errhdl = nullptr;

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

            /*@
             * @errortype
             * @moduleid     TARGETING::TARG_RT_VALIDATEDATA
             * @reasoncode   TARGETING::TARG_RT_BAD_EYECATCHER_LID
             * @userdata1    Eyecatcher from LID
             * @userdata2    Expected eyecatcher
             * @devdesc      Bad eyecatcher in the new lid data
             * @custdesc     Firmware error doing code update
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                TARGETING::TARG_RT_VALIDATEDATA,
                TARGETING::TARG_RT_BAD_EYECATCHER_LID,
                l_headerLid->eyeCatcher,
                PNOR_TARG_EYE_CATCHER,
                true);

            break;
        }

        // Validate Reserved Memory TargetingHeader eyecatcher
        if (l_headerRsvd->eyeCatcher != PNOR_TARG_EYE_CATCHER)
        {
            TRACFCOMP(g_trac_targeting,
                      "validateData: bad eyecatcher 0x%.8x found in "
                      "Reserved Memory TargetingHeader",
                      l_headerRsvd->eyeCatcher);

            /*@
             * @errortype
             * @moduleid     TARGETING::TARG_RT_VALIDATEDATA
             * @reasoncode   TARGETING::TARG_RT_BAD_EYECATCHER_MEM
             * @userdata1    Eyecatcher from existing memory
             * @userdata2    Expected eyecatcher
             * @devdesc      Bad eyecatcher in the existing attribute data
             * @custdesc     Firmware error doing code update
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                TARGETING::TARG_RT_VALIDATEDATA,
                TARGETING::TARG_RT_BAD_EYECATCHER_MEM,
                l_headerRsvd->eyeCatcher,
                PNOR_TARG_EYE_CATCHER,
                true);

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

            /*@
             * @errortype
             * @moduleid     TARGETING::TARG_RT_VALIDATEDATA
             * @reasoncode   TARGETING::TARG_RT_SECTION_NUM_MISMATCH
             * @userdata1    Number of sections in lid
             * @userdata2    Number of sections in existing mem
             * @devdesc      Section number mismatch between new and old data
             * @custdesc     Firmware error doing code update
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                TARGETING::TARG_RT_VALIDATEDATA,
                TARGETING::TARG_RT_SECTION_NUM_MISMATCH,
                l_headerLid->numSections,
                l_headerRsvd->numSections,
                true);

            break;
        }

        // Count of attribute sections
        size_t l_sectionCount = l_headerLid->numSections;
        o_lidTotalSize = 0;

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

                /*@
                 * @errortype
                 * @moduleid     TARGETING::TARG_RT_VALIDATEDATA
                 * @reasoncode   TARGETING::TARG_RT_SECTION_MISMATCH
                 * @userdata1    Section number
                 * @userdata2[00:31]    Section type in the lid
                 * @userdata2[32:63]    Section type in the memory
                 * @devdesc      Section number mismatch between new and old data
                 * @custdesc     Firmware error doing code update
                 */
                l_errhdl = new ERRORLOG::ErrlEntry(
                     ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                     TARGETING::TARG_RT_VALIDATEDATA,
                     TARGETING::TARG_RT_SECTION_MISMATCH,
                     i,
                     TWO_UINT32_TO_UINT64(l_sectionLid->sectionType,
                                          l_sectionRsvd->sectionType),
                     true);

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

            o_lidTotalSize += l_sectionLid->sectionSize;
        }
        // *** Could check if rc was set in for loop and break from do loop
    } while(false);

    TRACFCOMP(g_trac_targeting,
              EXIT_MRK"validateData : o_lidTotalSize=0x%llX",
              o_lidTotalSize);

    return l_errhdl;
}

/**
 * @brief Save/Restore attribute values from current Reserved Memory data
 * into new LID Structure data
 * @param[in] Pointer to current Reserved Memory targeting binary data
 * @param[in/out] Pointer to new LID Structure targeting binary data
 * @param[in] Instance, ie, Node ID
 * @return 0 on success, else return code
 */
errlHndl_t saveRestoreAttrs(void *i_rsvdMemPtr,
                            void *io_lidStructPtr,
                            uint8_t i_instance)
{
    TRACFCOMP( g_trac_targeting,
               ENTER_MRK"saveRestoreAttrs: %p %p %d",
               i_rsvdMemPtr, io_lidStructPtr, i_instance );

    errlHndl_t l_errhdl = nullptr;
    AttrRP *l_attrRPLid = nullptr;

    do
    {
        NODE_ID l_nodeId = static_cast<TARGETING::NODE_ID>(i_instance);

        // Locate current Reserved Memory data via TargetService
        TARGETING::TargetService& l_targSrv = TARGETING::targetService();

        // Get singleton AttrRP instance for current Reserved Memory data
        AttrRP *l_attrRPRsvd = &TARG_GET_SINGLETON(TARGETING::theAttrRP);

        // Create temporary AttrRP instance for new LID Structure targeting data
        l_attrRPLid =
            new AttrRP(reinterpret_cast<TargetingHeader*>(io_lidStructPtr),
                       l_nodeId,
                       l_attrRPRsvd->getNodeCount());

        // Get pointer to array of targets in the targeting image
        uint32_t l_maxTargetsLid = 0;
        Target (*l_targetsLid)[] = reinterpret_cast< Target(*)[] >(
            l_targSrv.getTargetArray(io_lidStructPtr,
                                     l_nodeId,
                                     l_attrRPLid,
                                     l_maxTargetsLid));

        TRACFCOMP( g_trac_targeting,
                   "Found %d targets in the lid for node %d",
                   l_maxTargetsLid,
                   l_nodeId );

        // Set up variables for getting attribute information for a target
        uint32_t l_attrCountRsvd = 0;
        ATTRIBUTE_ID* l_pAttrIdRsvd = nullptr;
        AbstractPointer<void>* l_ppAttrAddrRsvd = nullptr;

        uint32_t l_attrCountLid = 0;
        ATTRIBUTE_ID* l_pAttrIdLid = nullptr;
        AbstractPointer<void>* l_ppAttrAddrLid = nullptr;

        // Walk through new LID Structure Targets
        for(uint32_t l_targetNum = 1;
            (l_targetNum <= l_maxTargetsLid);
            ++l_targetNum)
        {
            // Get target for this pass through loop
            Target *l_targetLid = &(*(l_targetsLid))[l_targetNum - 1];

            // Counts of how many new attribute values were kept
            uint32_t l_kept_for_added_attr = 0;
            uint32_t l_kept_for_unknown_size = 0;

            // Get attribute information for a target in LID Structure (new)
            l_attrCountLid = l_targSrv.getTargetAttributes(l_targetLid,
                                                           l_attrRPLid,
                                                           l_pAttrIdLid,
                                                           l_ppAttrAddrLid);

            // Make sure that attributes were found
            if(l_attrCountLid == 0)
            {
                TRACFCOMP( g_trac_targeting,
                           "Target %3d has no attributes", l_targetNum );
                // Continue to next target if there were no attributes
                continue;
            }

            // Get key attributes and trace the information
            ATTR_CLASS_type l_classLid =
                l_targetLid->getAttr<ATTR_CLASS>(l_attrRPLid,
                                                 l_pAttrIdLid,
                                                 l_ppAttrAddrLid);
            ATTR_TYPE_type l_typeLid =
                l_targetLid->getAttr<ATTR_TYPE>(l_attrRPLid,
                                                l_pAttrIdLid,
                                                l_ppAttrAddrLid);
            ATTR_HUID_type l_huidLid =
                l_targetLid->getAttr<ATTR_HUID>(l_attrRPLid,
                                                l_pAttrIdLid,
                                                l_ppAttrAddrLid);
            ATTR_PHYS_PATH_type l_physPathLid =
                l_targetLid->getAttr<ATTR_PHYS_PATH>(l_attrRPLid,
                                                     l_pAttrIdLid,
                                                     l_ppAttrAddrLid);
            TRACFCOMP( g_trac_targeting,
                       "Target %3d has %3d attrs, class %0.8x, type %0.8x, "
                       "HUID 0x%0.8x, %s",
                       l_targetNum,
                       l_attrCountLid,
                       l_classLid,
                       l_typeLid,
                       l_huidLid,
                       l_physPathLid.toString());

            // Create bool used while checking if target exists in current data
            bool targetMatched = false;

            // Create TargetRangeFilter for current Reserved Memory data
            TargetRangeFilter l_allTargetsRsvd(l_targSrv.begin(l_nodeId),
                                               l_targSrv.end(),
                                               NULL);

            // Walk through current Reserved Memory Targets
            for(;
                l_allTargetsRsvd;
                ++l_allTargetsRsvd)
            {
                if((l_classLid == l_allTargetsRsvd->getAttr<ATTR_CLASS>()) &&
                   (l_typeLid == l_allTargetsRsvd->getAttr<ATTR_TYPE>()) &&
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
            TRACFCOMP( g_trac_targeting,
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
                (l_attrNumLid < l_attrCountLid);
                ++l_attrNumLid)
            {
                // Get ID for attribute on this pass through loop
                ATTRIBUTE_ID* l_pAttrId = l_pAttrIdLid + l_attrNumLid;
                TRACDCOMP( g_trac_targeting, "Attr %x", *l_pAttrId );

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
                    l_targetLid->_getAttrPtr(*l_pAttrId,
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

                        /*@
                         * @errortype
                         * @moduleid     TARGETING::TARG_RT_SAVERESTOREATTRS
                         * @reasoncode   TARGETING::TARG_RT_MISSING_ATTR
                         * @userdata1    Attribute Id
                         * @userdata2    HUID of target
                         * @devdesc      Could not find attribute data in lid
                         * @custdesc     Firmware error doing code update
                         */
                        l_errhdl = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             TARGETING::TARG_RT_SAVERESTOREATTRS,
                             TARGETING::TARG_RT_MISSING_ATTR,
                             *l_pAttrId,
                             l_huidLid,
                             true);

                        break;
                    }

                    // Look up the size of the attribute
                    uint32_t l_attrSize = attrSizeLookup(*l_pAttrId);

                    // Check that a valid size was returned for the attribute
                    if(l_attrSize == 0)
                    {
                        TRACFCOMP( g_trac_targeting,
                                   "UNEXPECTEDLY Did not find size for "
                                   "attribute ID 0x%.8x, target HUID 0x%0.8x "
                                   "in Reserved Memory, Keeping value from "
                                   "LID Structure",
                                   *l_pAttrId,
                                   l_allTargetsRsvd->getAttr<ATTR_HUID>());

                        // Increment for keeping value because size was unknown
                        ++l_kept_for_unknown_size;

                        // not an error

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
                        memcpy(l_pAttrLid, l_pAttrRsvd, l_attrSize);
                    }
                }
                else
                {
                    TRACFCOMP( g_trac_targeting,
                               "Did not find attribute ID 0x%.8x, target HUID "
                               "0x%0.8x in Reserved Memory, Keeping value from "
                               "LID Structure",
                               *l_pAttrId,
                               l_huidLid);

                    // Increment for keeping value because attribute was added
                    ++l_kept_for_added_attr;

                    // not an error

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

    return l_errhdl;
}

int hbrt_update_prep(void)
{
    TRACFCOMP(g_trac_hbrt, ENTER_MRK" prepare_hbrt_update");
    TRACFCOMP(g_trac_targeting, ENTER_MRK" hbrt_update_prep");
    errlHndl_t pError = nullptr;

    // Define a structure to defer the application of the new targeting data
    //  until after we've processed every node
    typedef struct MemChunk
    {
        uint8_t* curTarg;
        size_t curSize;
        uint8_t* newTarg;
        size_t newSize;
    } MemChunk_t;
    std::vector<MemChunk_t> l_allMemChunks;

    for(NODE_ID l_nodeId = NODE0;
        l_nodeId < Singleton<AttrRP>::instance().getNodeCount();
        l_nodeId++)
    {
        void* l_newMem = nullptr;
        void *l_lidStructPtr = nullptr;

        // Get size and location of attributes in reserved memory
        uint64_t l_attr_size = 0;
        uint64_t l_rsvdMem = hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_ATTR,
                                                l_nodeId, l_attr_size);
        TRACFCOMP( g_trac_targeting, "l_rsvdMem @ %.16llX for 0x%llX",
                   l_rsvdMem, l_attr_size );

        // Set pointer to reserved memory targeting data
        void *l_rsvdMemPtr = reinterpret_cast<void*>(l_rsvdMem);

        uint32_t lid_id = Util::TARGETING_BINARY_LIDID + l_nodeId;
#ifdef CONFIG_PLDM
        // Translate Pnor Section Id to Lid
        Util::LidAndContainerLid l_lids;
        pError = Util::getPnorSecLidIds(PNOR::HB_DATA, l_lids);

        if(pError)
        {
            TRACFCOMP( g_trac_targeting,
                       ERR_MRK"hbrt_update_prep: Unable to determine HBD_RT lid id");
            pError->collectTrace(TARG_COMP_NAME);
            break;
        }
        lid_id = l_lids.lid;
#endif

        // Set LID for this node
        UtilLidMgr l_lidMgr(lid_id);

        // Create lidMgr and get size of Targeting Binary LID
        size_t l_lidSize = 0;
        pError = l_lidMgr.getLidSize(l_lidSize);
        if(pError)
        {
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

            break;
        }

        // Get new structure from LID
        pError = l_lidMgr.getStoredLidImage(l_lidStructPtr, l_lidSize);
        if(pError)
        {
            break;
        }
        TRACFCOMP( g_trac_targeting, "LID @ %.16llX for 0x%llX",
                   l_lidStructPtr, l_lidSize );

        // Keep track of how much space the new lid data needs
        size_t l_lidDataSize = 0;

        // Validate LID Structure against Reserved Memory
        pError = validateData(l_lidStructPtr,
                              l_rsvdMemPtr,
                              l_lidDataSize);
        if(pError)
        {
            break;
        }

        // Need to allocate enough space for all the volatile attributes
        if( (l_lidDataSize <= l_attr_size)
            && (l_lidSize <= l_lidDataSize) )
        {
            l_newMem = calloc(l_lidDataSize,1);
            memcpy( l_newMem, l_lidStructPtr, l_lidSize );
            // note - original lid data is no longer used after this,
            //        lid memory is deleted as part of object destructor
        }
        else
        {
            TRACFCOMP( g_trac_targeting, "hbrt_update_prep: Size mismatches> LID=0x%llX, LID Data=0x%llX, RsvdMem=0x%llX",
                       l_lidSize, l_lidDataSize, l_attr_size );
            /*@
             * @errortype
             * @moduleid     TARGETING::TARG_RT_HBRT_UPDATE_PREP
             * @reasoncode   TARGETING::TARG_RT_BAD_ATTR_SIZES
             * @userdata1[00:31]  Lid size
             * @userdata1[32:63]  Attribute size in lid
             * @userdata2[00:31]  Reserved mem size
             * @userdata2[32:63]  unused
             * @devdesc      There is a mismatch with the sizes of the
             *               lid and/or reserved memory section
             * @custdesc     Firmware error doing code update
             */
            pError = new ERRORLOG::ErrlEntry(
                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                 TARGETING::TARG_RT_HBRT_UPDATE_PREP,
                 TARGETING::TARG_RT_BAD_ATTR_SIZES,
                 TWO_UINT32_TO_UINT64( l_lidSize, l_lidDataSize ),
                 TWO_UINT32_TO_UINT64( l_attr_size, 0 ),
                 true);
            break;
        }


        // Save/Restore attribute values from current Reserved Memory data into
        // new LID Structure data
        pError = saveRestoreAttrs(l_rsvdMemPtr,
                                  l_newMem,
                                  l_nodeId);
        if(pError)
        {
            break;
        }

        // Save off the memory addresses we need to copy later, if we do the
        //  memcpy now we break current targeting which means the UtilLidMgr
        //  call won't work in the next iteration of this loop
        MemChunk_t l_memChunk = { reinterpret_cast<uint8_t*>(l_rsvdMemPtr),
                                  l_attr_size,
                                  reinterpret_cast<uint8_t*>(l_newMem),
                                  l_lidDataSize };
        l_allMemChunks.push_back(l_memChunk);

    }

    // Add the traces onto any error log and commit it
    int l_rc = ERRL_GETRC_SAFE(pError);
    if(pError)
    {
        TRACFCOMP( g_trac_targeting,
                   "Error retrieving new data (%.4X), skipping apply",
                   l_rc);
        pError->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
        pError->collectTrace(TARG_COMP_NAME);
        errlCommit(pError,TARG_COMP_ID);

        // If anything went wrong we don't want to whack our memory
        for( auto l_memChunk : l_allMemChunks )
        {
            // Delete the scratch space for the new attributes
            if( l_memChunk.newTarg )
            {
                free( l_memChunk.newTarg );
                l_memChunk.newTarg = nullptr;
            }
        }
        l_allMemChunks.clear();
    }

    // Handle all of the live memory updates
    //  This MUST be the last thing we do since attributes go wacky in between
    for( auto l_memChunk : l_allMemChunks )
    {
        // Copy new LID Structure data over current Reserved Memory data
        size_t l_copySize = std::min(l_memChunk.newSize,
                                     l_memChunk.curSize);
        TRACFCOMP( g_trac_targeting,
                   "hbrt_update_prep: Copy 0x%0.8x bytes of targeting data",
                   l_copySize);
        TRACFCOMP( g_trac_targeting,
                   "RsvdMem @ %p, LidMem @ %p",
                   l_memChunk.curTarg, l_memChunk.newTarg );
        memcpy(l_memChunk.curTarg,
               l_memChunk.newTarg,
               l_copySize);

        // Set any remaining bytes to zero
        //  Note: earlier checks ensure curSize >= l_copySize
        size_t l_setSize = l_memChunk.curSize - l_copySize;
        if(l_setSize)
        {
            TRACFCOMP( g_trac_targeting,
                       "hbrt_update_prep: Set 0x%0.8x bytes to 0 @%p",
                       l_setSize, l_memChunk.curTarg + l_copySize);
            memset(l_memChunk.curTarg + l_copySize,
                   0,
                   l_setSize);
        }

        // Delete the scratch space for the new attributes
        if( l_memChunk.newTarg )
        {
            free( l_memChunk.newTarg );
            l_memChunk.newTarg = nullptr;
        }
    }

    TRACFCOMP(g_trac_targeting, EXIT_MRK" hbrt_update_prep");
    TRACFCOMP(g_trac_hbrt, EXIT_MRK" prepare_hbrt_update: rc=%.X", l_rc);
    return l_rc;
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
