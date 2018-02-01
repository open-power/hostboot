/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/attrrp_rt.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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
#include <targeting/attrrp.H>
#include <targeting/common/trace.H>
#include <util/align.H>
#include <runtime/interface.h>
#include <errl/errlentry.H>
#include <targeting/common/targreasoncodes.H>
#include <targeting/targplatreasoncodes.H>
#include <targeting/attrsync.H>
#include <util/runtime/util_rt.H>
#include <sys/internode.h>

#include "../attrrp_common.C"

using namespace ERRORLOG;

namespace TARGETING
{
    void AttrRP::fillInAttrRP(TargetingHeader* i_header)
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK"AttrRP::fillInAttrRP");

        do
        {
            // Create AttributeSync
            AttributeSync l_attributeSync = AttributeSync();

            // Allocate section structures based on section count in header.
            iv_sectionCount = i_header->numSections;
            iv_sections = new AttrRP_Section[iv_sectionCount]();

            // Find start to the first section:
            //          (header address + size of header + offset in header)
            TargetingSection* l_section =
                reinterpret_cast<TargetingSection*>(
                    reinterpret_cast<uint64_t>(i_header) +
                    sizeof(TargetingHeader) + i_header->offsetToSections
                );

            uint64_t l_offset = 0;

            for (size_t i = 0; i < iv_sectionCount; ++i, ++l_section)
            {
                iv_sections[i].type = l_section->sectionType;
                iv_sections[i].size = l_section->sectionSize;

                iv_sections[i].vmmAddress =
                        static_cast<uint64_t>(
                            TARG_TO_PLAT_PTR(i_header->vmmBaseAddress)) +
                        i_header->vmmSectionOffset*i;
                iv_sections[i].pnorAddress =
                        reinterpret_cast<uint64_t>(i_header) + l_offset;

                l_offset += ALIGN_PAGE(iv_sections[i].size);

                TRACFCOMP(g_trac_targeting,
                          "Decoded Attribute Section: %d, 0x%lx, 0x%lx, 0x%lx",
                          iv_sections[i].type,
                          iv_sections[i].vmmAddress,
                          iv_sections[i].pnorAddress,
                          iv_sections[i].size);
            }
        } while(false);

        TRACFCOMP(g_trac_targeting, EXIT_MRK"AttrRP::fillInAttrRP");

        return;
    }

    void AttrRP::startup(errlHndl_t& io_taskRetErrl, bool isMpipl)
    {
        TRACFCOMP(g_trac_targeting, "AttrRP::startup");
        errlHndl_t l_errl = nullptr;

        uint8_t l_index = 0;
        uint32_t l_instance[MAX_NODES_PER_SYS];
        l_instance[l_index] = NODE0; // First instance is always NODE 0
        // Initialize rest of the instances to be invalid nodes
        for(l_index = 1; l_index < MAX_NODES_PER_SYS; l_index++)
        {
            l_instance[l_index] = INVALID_NODE;
        }

        // Handle first instance
        l_index = 0;
        uint64_t attr_size = 0;
        TargetingHeader* l_header =
          reinterpret_cast<TargetingHeader*>(
              hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_ATTR,
                                 l_instance[l_index], attr_size));

        // Create local copy of node struct
        NodeInfo l_nodeCont;

        // Initialize local copy of node struct
        l_errl = nodeInfoInit(l_nodeCont,
                              l_header,
                              l_instance[l_index]);

        // Push back node struct into the node container
        TRACFCOMP(g_trac_targeting,
                  "Push node struct for Node %d",
                  l_instance[l_index]);
        iv_nodeContainer.push_back(l_nodeCont);

        // Get pointer to number of targets
        const AbstractPointer<uint32_t>* l_pNumTargetsPtr =
            static_cast<const AbstractPointer<uint32_t>*>(
                reinterpret_cast<void*>(
                reinterpret_cast<char*>(l_header) +
                                        l_header->headerSize));
        uint32_t* l_pNumTargets = TARG_TO_PLAT_PTR(*l_pNumTargetsPtr);

        // Only translate addresses on platforms where addresses are 4 bytes
        // wide (FSP).  The compiler should perform dead code elimination of
        // this path on platforms with 8 byte wide addresses (Hostboot), since
        // the "if" check can be statically computed at compile time.
        if(TARG_ADDR_TRANSLATION_REQUIRED)
        {
            l_pNumTargets = static_cast<uint32_t*>(
                this->translateAddr(l_pNumTargets, l_instance[l_index]));
        }

        // Get pointer to targets
        Target (*l_pTargets)[] =
            reinterpret_cast<Target(*)[]> (l_pNumTargets + 1);

        // Walk through targets
        for(uint32_t l_targetNum = 1;
            l_targetNum <= *l_pNumTargets;
            ++l_targetNum)
        {
            Target* l_pTarget = &(*(l_pTargets))[l_targetNum - 1];
            TRACDCOMP( g_trac_targeting,
                       "Target %d of %d, class %0.8x, type %0.8x",
                       l_targetNum,
                       *l_pNumTargets,
                       l_pTarget->getAttr<ATTR_CLASS>(),
                       l_pTarget->getAttr<ATTR_TYPE>());

            if((l_pTarget->getAttr<ATTR_CLASS>() == CLASS_SYS) &&
               (l_pTarget->getAttr<ATTR_TYPE>() == TYPE_SYS))
            {
                // This attribute is only set on a multi-node system.
                // We will use it below to detect a multi-node scenario
                auto l_hb_images =
                    l_pTarget->getAttr<ATTR_HB_EXISTING_IMAGE>();

                EntityPath l_physPath = l_pTarget->getAttr<ATTR_PHYS_PATH>();
                TRACFCOMP( g_trac_targeting,
                           "Target %d of %d, %s, HB images %0.8x",
                           l_targetNum,
                           *l_pNumTargets,
                           l_physPath.toString(),
                           l_hb_images);

                // Start the 1 in the mask at leftmost position
                decltype(l_hb_images) l_mask =
                    0x1 << ((sizeof(l_hb_images) * 8) - 1);

                uint32_t l_node = NODE0;
                l_index = 0;
                // While multi-node system and valid mask and valid index
                while(l_hb_images && l_mask && (l_index < MAX_NODES_PER_SYS))
                {
                    // Change node instance status
                    if(iv_instanceStatus == SINGLE_NODE)
                    {
                        iv_instanceStatus = MULTI_NODE;
                    }

                    // If node is present
                    if(l_mask & l_hb_images)
                    {
                        l_instance[l_index] = l_node;

                        // Check if a previous node was skipped
                        if(iv_instanceStatus == MULTI_NODE_LT_MAX_INSTANCES)
                        {
                            // Flag that instances are not contiguous
                            iv_instanceStatus = MULTI_NODE_INSTANCE_GAP;
                        }
                    }
                    else if(iv_instanceStatus == MULTI_NODE)
                    {
                        // Flag that an instance is being skipped
                        iv_instanceStatus = MULTI_NODE_LT_MAX_INSTANCES;
                    }

                    l_mask >>= 1; // shift to the right for the next node
                    l_node++;
                    l_index++;
                }

                if(iv_instanceStatus == MULTI_NODE_INSTANCE_GAP)
                {
                    TRACFCOMP( g_trac_targeting,
                               "There is a gap in the node numbers");
                }

                break;
            }
        }

        // Handle additional instances
        l_index = 1;
        do
        {
            // Check that a valid node is set for this instnace
            if(l_instance[l_index] == INVALID_NODE)
            {
                l_index++;

                // Continue with next instance
                continue;
            }

            uint64_t attr_size = 0;
            TargetingHeader* l_header =
              reinterpret_cast<TargetingHeader*>(
                  hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_ATTR,
                                     l_instance[l_index], attr_size));

            // Check if reserved memory does not exist for this instance
            if ((NULL == l_header) && (l_instance[l_index] > NODE0))
            {
                TRACFCOMP(g_trac_targeting,
                          "Reserved memory does not exist for Node %d",
                          l_instance[l_index]);

                l_index++;

                // Continue with next instance
                continue;
            }

            // Create local copy of node struct
            NodeInfo l_nodeCont;

            // Initialize local copy of node struct
            l_errl = nodeInfoInit(l_nodeCont,
                                  l_header,
                                  l_instance[l_index]);

            // Push back node struct into the node container
            TRACFCOMP(g_trac_targeting,
                      "Push node struct for Node %d",
                      l_instance[l_index]);
            iv_nodeContainer.push_back(l_nodeCont);

            l_index++;
        } while(l_index < MAX_NODES_PER_SYS);

        if (l_errl)
        {
            l_errl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        }

        io_taskRetErrl = l_errl;
    }

    errlHndl_t AttrRP::nodeInfoInit(NodeInfo& io_nodeCont,
                                    TargetingHeader* i_header,
                                    const NODE_ID i_nodeId)
    {
        TRACFCOMP(g_trac_targeting, "AttrRP::nodeInfoInit");
        errlHndl_t l_errl = nullptr;

        do
        {
            if ((NULL == i_header) ||
                (i_header->eyeCatcher != PNOR_TARG_EYE_CATCHER))
            {
                /*@
                 *   @errortype
                 *   @moduleid          TARG_MOD_ATTRRP_RT
                 *   @reasoncode        TARG_RC_BAD_EYECATCH
                 *   @userdata1         Observed Header Eyecatch Value
                 *   @userdata2         Memory address referenced.
                 *
                 *   @devdesc   The eyecatch value observed in memory does not
                 *              match the expected value of
                 *              PNOR_TARG_EYE_CATCHER and therefore the
                 *              contents of the Attribute sections are
                 *              unable to be parsed.
                 *   @custdesc  A problem occurred during the IPL of the
                 *              system.
                 *              The eyecatch value observed in memory does not
                 *              match the expected value and therefore the
                 *              contents of the attribute sections are unable
                 *              to be parsed.
                 */
                l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                       TARG_MOD_ATTRRP_RT,
                                       TARG_RC_BAD_EYECATCH,
                                       NULL == i_header ?
                                            0 : i_header->eyeCatcher,
                                       reinterpret_cast<uint64_t>(i_header));
                break;
            }

            // Save pointer to targeting image in reserved memory for this node
            io_nodeCont.pTargetMap = reinterpret_cast<void*>(i_header);

            // Allocate section structures based on section count in header
            io_nodeCont.sectionCount = i_header->numSections;
            io_nodeCont.pSections =
                new AttrRP_Section[io_nodeCont.sectionCount]();
            if (i_nodeId == NODE0) // @TODO RTC:186585 remove
            { // @TODO RTC:186585 remove
                iv_sectionCount = io_nodeCont.sectionCount; // @TODO RTC:186585
                iv_sections = io_nodeCont.pSections; // @TODO RTC:186585 remove
            } // @TODO RTC:186585 remove

            // Find start to the first section:
            //          (header address + size of header + offset in header)
            TargetingSection* l_section =
                reinterpret_cast<TargetingSection*>(
                    reinterpret_cast<uint64_t>(i_header) +
                    sizeof(TargetingHeader) + i_header->offsetToSections
                );

            uint64_t l_offset = 0;

            for (size_t i = 0; i < io_nodeCont.sectionCount; ++i, ++l_section)
            {
                io_nodeCont.pSections[i].type = l_section->sectionType;
                io_nodeCont.pSections[i].size = l_section->sectionSize;

                io_nodeCont.pSections[i].vmmAddress =
                        static_cast<uint64_t>(
                            TARG_TO_PLAT_PTR(i_header->vmmBaseAddress)) +
                        i_header->vmmSectionOffset*i;
                io_nodeCont.pSections[i].pnorAddress =
                        reinterpret_cast<uint64_t>(i_header) + l_offset;

                l_offset += ALIGN_PAGE(io_nodeCont.pSections[i].size);

                TRACFCOMP(g_trac_targeting,
                          "Decoded Attribute Section: %d, 0x%lx, 0x%lx, 0x%lx",
                          io_nodeCont.pSections[i].type,
                          io_nodeCont.pSections[i].vmmAddress,
                          io_nodeCont.pSections[i].pnorAddress,
                          io_nodeCont.pSections[i].size);
            }
        } while(false);

        return l_errl;
    }

    void* AttrRP::getTargetMapPtr(const NODE_ID i_nodeId)
    {
        #define TARG_FN "getTargetMapPtr"
        TARG_ENTER();

        errlHndl_t l_errl = nullptr;
        void* l_pTargetMap = nullptr;

        // Cannot use isNodeValid method here since the vector itself is
        // initialized in here.
        if((i_nodeId >= NODE0) &&
            (i_nodeId < AttrRP::INVALID_NODE_ID))
        {
            do
            {
                if(iv_nodeContainer[i_nodeId].pTargetMap == nullptr)
                {
                    // Locate targeting image for this node in reserved memory
                    uint64_t attr_size = 0;
                    iv_nodeContainer[i_nodeId].pTargetMap =
                        reinterpret_cast<void*>(
                            hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_ATTR,
                                               i_nodeId,
                                               attr_size));

                    // Check for failure to locate targeting image for this node
                    if (iv_nodeContainer[i_nodeId].pTargetMap == nullptr)
                    {
                        TARG_ERR("Error: hb_get_rt_rsvd_mem call failed");
                        break;
                    }

                    // Get pointer to targeting image header
                    TargetingHeader *l_header =
                        static_cast<TargetingHeader *>(
                            iv_nodeContainer[i_nodeId].pTargetMap);

                    // Initialize the node struct for this node
                    l_errl = nodeInfoInit(iv_nodeContainer[i_nodeId],
                                          l_header,
                                          i_nodeId);
                    if(l_errl)
                    {
                        break;
                    }

                    // Set the targeting image pointer
                    l_pTargetMap = iv_nodeContainer[i_nodeId].pTargetMap;
                }
                else
                {
                    // This should return pTargetMap from here
                    break;
                }
            } while(0);
        }
        else
        {
            TARG_ERR("Invalid Node Id passed here to initialize [%d]",
                     i_nodeId);
        }

        if(l_errl)
        {
            /* Commit the error */
            errlCommit(l_errl, TARG_COMP_ID);
        }

        return l_pTargetMap;
        #undef TARG_FN
    }

    void* AttrRP::getBaseAddress(const NODE_ID i_nodeId)
    {
        #define TARG_FN "getBaseAddress()"
        TARG_ENTER();

        void* l_pMap = nullptr;

        // The init for a node id might have been done via the other way i.e.
        // setImageName, need to valid if node Id is valid and init is already
        // done validate node Id, It's a special case validation, since the node
        // which is getting validated doesn't yet have a container, so it should
        // always point to the next to be initialized.
        if(i_nodeId < INVALID_NODE_ID)
        {
            // Check if the Mmap is already done
            if(iv_nodeContainer[i_nodeId].pTargetMap != nullptr)
            {
                l_pMap = iv_nodeContainer[i_nodeId].pTargetMap;
            }
            else
            {
                TARG_ASSERT(0,
                            TARG_ERR_LOC "Node Id [%d] should have been already"
                            " initialized, before but the Mmap Address is NULL",
                            i_nodeId);
            }
        }
        else if(i_nodeId == INVALID_NODE_ID)
        {
            // Push back a node struct in the node container
            NodeInfo l_nodeCont;
            iv_nodeContainer.push_back(l_nodeCont);

            l_pMap = getTargetMapPtr(i_nodeId);
        }
        else
        {
            TARG_ERR("Invalid Node Id [%d] passed here to initialize",
                i_nodeId);
        }

        return l_pMap;
        #undef TARG_FN
    }

    void AttrRP::getNodeId(const Target* i_pTarget,
                           NODE_ID& o_nodeId) const
    {
        #define TARG_FN "getNodeId"

        bool l_found = false;

        // Initialize with invalid
        o_nodeId = INVALID_NODE_ID;

        //find the node to which this target belongs
        for(uint8_t i=0; i<INVALID_NODE_ID; ++i)
        {
           for(uint32_t j=0; j<iv_nodeContainer[i].sectionCount; ++j)
           {
               if(  iv_nodeContainer[i].pSections[j].type ==
                                  SECTION_TYPE_PNOR_RO)
               {
                 // This expects the pTarget to be always in range and !NULL.
                 // If any invalid target is passed (which is still within the
                 // RO Section scope) then behaviour is undefined.
                 if( (i_pTarget >= iv_nodeContainer[i].pTargetMap) &&
                     (i_pTarget < reinterpret_cast<Target*>((
                        reinterpret_cast<uint8_t*>(
                            iv_nodeContainer[i].pTargetMap) +
                            iv_nodeContainer[i].pSections[j].size))) )
                 {
                     l_found = true;
                     o_nodeId = i;
                     break;
                 }
               }
           }
           if(l_found)
           {
              break;
           }
        }
        #undef TARG_FN
    }

    void* AttrRP::translateAddr(void* i_pAddress,
                                const Target* i_pTarget)
    {
        #define TARG_FN "translateAddr(..., Target*)"
//        TARG_ENTER(); // Disabled due to number of traces created

        NODE_ID l_nodeId = NODE0;

        if(i_pTarget != NULL)
        {
            getNodeId(i_pTarget, l_nodeId);
        }

        void* l_address = translateAddr(i_pAddress, l_nodeId);

//        TARG_EXIT(); // Disabled due to number of traces created
        #undef TARG_FN

        return l_address;
    }

    void* AttrRP::translateAddr(void* i_pAddress,
                                const TARGETING::NODE_ID i_nodeId)
    {
        #define TARG_FN "translateAddr(..., NODE_ID)"
//        TARG_ENTER(); // Disabled due to number of traces created

        void* l_address = NULL;

        for (size_t i = 0; i < iv_nodeContainer[i_nodeId].sectionCount; ++i)
        {
            if ((iv_nodeContainer[i_nodeId].pSections[i].vmmAddress +
                 iv_nodeContainer[i_nodeId].pSections[i].size) >=
                reinterpret_cast<uint64_t>(i_pAddress))
            {
                l_address = reinterpret_cast<void*>(
                        iv_nodeContainer[i_nodeId].pSections[i].pnorAddress +
                        reinterpret_cast<uint64_t>(i_pAddress) -
                        iv_nodeContainer[i_nodeId].pSections[i].vmmAddress);
                break;
            }
        }

        TRACDCOMP(g_trac_targeting, "Translated 0x%p to 0x%p",
                  i_pAddress, l_address);

//        TARG_EXIT(); // Disabled due to number of traces created
        #undef TARG_FN

        return l_address;
    }
}
