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
#include <util/runtime/util_rt.H>
#include <sys/internode.h>
#include <map>

#include "../attrrp_common.C"

using namespace ERRORLOG;

namespace TARGETING
{

    const uint64_t MASK_OFF_UPPER_BYTE = 0x00FFFFFFFFFFFFFFULL;

    errlHndl_t AttrRP::checkHbExistingImage(TargetingHeader* i_header,
                                            uint8_t i_instance,
                                            NODE_ID &io_maxNodeId)
    {
        TRACFCOMP(g_trac_targeting, "AttrRP::checkHbExistingImage");
        errlHndl_t l_errl = nullptr;

        // Validity of the node instance
        bool l_validNode = false;

        // Get pointer to number of targets
        const AbstractPointer<uint32_t>* l_pNumTargetsPtr =
            static_cast<const AbstractPointer<uint32_t>*>(
                reinterpret_cast<void*>(
                reinterpret_cast<char*>(i_header) +
                                        i_header->headerSize));
        uint32_t* l_pNumTargets = TARG_TO_PLAT_PTR(*l_pNumTargetsPtr);

        // Only translate addresses on platforms where addresses are 4 bytes
        // wide (FSP).  The compiler should perform dead code elimination of
        // this path on platforms with 8 byte wide addresses (Hostboot), since
        // the "if" check can be statically computed at compile time.
        if(TARG_ADDR_TRANSLATION_REQUIRED)
        {
            l_pNumTargets = static_cast<uint32_t*>(
                this->translateAddr(l_pNumTargets, i_instance));
        }

        // Get pointer to targets
        Target (*l_pTargets)[] =
            reinterpret_cast<Target(*)[]> (l_pNumTargets + 1);

        // Walk through targets until system target is found
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
                           "Target %d of %d, %s, HB images %0.2x",
                           l_targetNum,
                           *l_pNumTargets,
                           l_physPath.toString(),
                           l_hb_images);

                // Start the 1 in the mask at leftmost position
                decltype(l_hb_images) l_mask =
                    0x1 << ((sizeof(l_hb_images) * 8) - 1);

                NODE_ID l_node = NODE0;

                // Check if multi-node system
                if(l_hb_images)
                {
                    // While valid mask and valid node
                    while(l_mask && (l_node < MAX_NODES_PER_SYS))
                    {
                        // If node is present
                        if(l_mask & l_hb_images)
                        {
                            // Check if current node is the node of interest
                            if(l_node == i_instance)
                            {
                                // Flag that input instance is a valid node
                                l_validNode = true;
                            }

                            // Check if maximum node ID needs replacing
                            if(l_node > io_maxNodeId)
                            {
                                // Replace maximum node ID
                                io_maxNodeId = l_node;
                            }
                        }

                        l_mask >>= 1; // shift to the right for the next node
                        ++l_node;
                    } // while
                }
                else // Single-node system, hb_images will be zero, but the
                     // variable, i_instance, will be equal to the node id
                     // of the only functional node in the system, and will
                     // not always be node zero
                {
                    // Flag that input instance is a valid node
                    l_validNode = true;

                    // Replace maximum node ID with
                    // this nodes instance id
                    io_maxNodeId = i_instance;
                }

                // Input instance is not a valid node
                if(!l_validNode)
                {
                    TRACFCOMP(g_trac_targeting,
                              ERR_MRK"Node %d not present in HB images %0.2x",
                              i_instance,
                              l_hb_images);

                    /*@
                     *   @errortype         ERRL_SEV_UNRECOVERABLE
                     *   @moduleid          TARG_MOD_ATTRRP_RT
                     *   @reasoncode        TARG_RT_NODE_NOT_IN_IMAGE
                     *   @userdata1[00:31]  Node
                     *   @userdata1[32:64]  HB Existing Image
                     *   @userdata2         Memory address referenced.
                     *
                     *   @devdesc   Expected node is not present in
                     *              ATTR_HB_EXISTING_IMAGE
                     *   @custdesc  A problem occurred during the IPL of the
                     *              system.
                     *              Expected resource was not indicated to be
                     *              present.
                     */
                    l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                           TARG_MOD_ATTRRP_RT,
                                           TARG_RT_NODE_NOT_IN_IMAGE,
                                           TWO_UINT32_TO_UINT64(
                                               TO_UINT32(i_instance),
                                               TO_UINT32(l_hb_images)),
                                           reinterpret_cast<uint64_t>(i_header)
                                           );
                    break;
                }

                // Stop walking targets, system target was found
                break;
            }
        } // for

        return l_errl;
    }

    void AttrRP::startup(errlHndl_t& io_taskRetErrl, bool isMpipl)
    {
        TRACFCOMP(g_trac_targeting, "AttrRP::startup");
        errlHndl_t l_errl = nullptr;

        uint32_t l_instance = NODE0;    // Start with NODE 0 for first instance
        NODE_ID l_maxNodeId = NODE0;    // Start with minimal node
        bool l_rsvd_mem_exists = false; // indicates if an instance of reserved
                                        // memory has been found

        do
        {
            // Create local copy of node struct
            NodeInfo l_nodeCont;

            uint64_t attr_size = 0;
            TargetingHeader* l_header =
              reinterpret_cast<TargetingHeader*>(
                  hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_ATTR,
                                     l_instance, attr_size));

            // Check if reserved memory does not exist for this instance
            if ((NULL == l_header) || (0 == attr_size))
            {
                TRACFCOMP(g_trac_targeting,
                          "Reserved memory does not exist for Node %d, "
                          "Push empty node struct for this node",
                          l_instance);
                iv_nodeContainer.push_back(l_nodeCont);

                // Check if we haven't found reserved memory for any node and
                // if we haven't reached the maximum node ID for the system
                if(!l_rsvd_mem_exists && (l_maxNodeId < MAX_NODES_PER_SYS - 1))
                {
                    // Increase maximum node ID to allow checking another node
                    ++l_maxNodeId;
                }
            }
            else
            {
                l_rsvd_mem_exists = true;

                // Initialize local copy of node struct
                l_errl = nodeInfoInit(l_nodeCont,
                                      l_header,
                                      l_instance);

                if (l_errl)
                {
                    break;
                }


                // Push back node struct into the node container
                TRACFCOMP(g_trac_targeting,
                          "Push node struct for Node %d",
                          l_instance);
                iv_nodeContainer.push_back(l_nodeCont);

                // Check this node against the HB existing image attribute
                l_errl = checkHbExistingImage(l_header,
                                              l_instance,
                                              l_maxNodeId);

                if (l_errl)
                {
                    break;
                }
            }

            ++l_instance;
        } while(l_instance <= l_maxNodeId);

        if (l_errl)
        {
            l_errl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        }
        else if(l_maxNodeId != (iv_nodeContainer.size() - 1))
        {
            TRACFCOMP(g_trac_targeting,
                      ERR_MRK"Node container size, %d, is expected to be 1 "
                      "more than maximum Node ID, %d",
                      iv_nodeContainer.size(),
                      l_maxNodeId);
        }

        io_taskRetErrl = l_errl;
    }

    errlHndl_t AttrRP::nodeInfoInit(NodeInfo& io_nodeCont,
                                    TargetingHeader* i_header,
                                    const NODE_ID i_nodeId)
    {
        TRACFCOMP(g_trac_targeting, "AttrRP::nodeInfoInit %d", i_nodeId);
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
            // mark this node container as valid
            io_nodeCont.setIsValid(true);

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
        // initialized in here. AttrRP::INVALID_NODE_ID is a dynamic
        // value and is set to iv_nodeContainer.size()
        if((i_nodeId >= NODE0) &&
            (i_nodeId < AttrRP::INVALID_NODE_ID))
        {
            do
            {
                if(iv_nodeContainer[i_nodeId].pTargetMap == nullptr)
                {
                    // Locate targeting image for this node in reserved memory
                    TARG_INF("getTargetMapPtr Locating reserved memory "
                             "targeting image for the node %d", i_nodeId);
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
                    l_pTargetMap = iv_nodeContainer[i_nodeId].pTargetMap;
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

        TARG_DBG("getTargetMapPtr returning %p for node %d",
                 l_pTargetMap, i_nodeId);
        return l_pTargetMap;
        #undef TARG_FN
    }

    void* AttrRP::getBaseAddress(const NODE_ID i_nodeId)
    {
        #define TARG_FN "getBaseAddress()"
        TARG_ENTER();

        void* l_pMap = nullptr;

        // if i_nodeId is less than INVALID_NODE_ID then iv_nodeContainer
        // contains a node info struct for it, however it may be invalid
        // for some reason (deconfigured) so check that on the next line.
        if(i_nodeId < INVALID_NODE_ID)
        {
            // Check if the Mmap is already done
            if( iv_nodeContainer[i_nodeId].getIsValid() )
            {
                l_pMap = iv_nodeContainer[i_nodeId].pTargetMap;
            }
            else
            {
                TARG_INF("getBaseAddr nodeInfo struct for %d is invalid,"
                        " skipping", i_nodeId);

            }
        }
        else if(i_nodeId == INVALID_NODE_ID)
        {
            // If i_nodeID is equal to INVALID_NODE_ID then we add an empty
            // NodeInfo struct to iv_nodeContainer and will attempt to
            // initalize it with a call to getTargetMapPtr()
            //
            // Note: INVALID_NODE_ID is a dynamic value here which gets gets
            //       incremented each time a node info struct is pushed to
            //       iv_nodeContainer

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

    NODE_ID AttrRP::getNodeId(const Target* i_pTarget)
    {
        #define TARG_FN "getNodeId"

        NODE_ID l_nodeId = 0;

        // Call the class function with my module-local singleton
        TARGETING::AttrRP *l_attrRP = &TARG_GET_SINGLETON(TARGETING::theAttrRP);
        l_attrRP->getNodeId(i_pTarget, l_nodeId);

        return l_nodeId;
        #undef TARG_FN
    }

    void AttrRP::getNodeId(const Target* i_pTarget, NODE_ID& o_nodeId) const
    {
        #define TARG_FN "getNodeId"

        bool l_found = false;

        // Initialize with invalid
        o_nodeId = INVALID_NODE_ID;

        // Check if we have a cached version first
        static std::map<const Target*,NODE_ID> s_targToNodeMap;
        auto l_nodeItr = s_targToNodeMap.find(i_pTarget);
        if( l_nodeItr != s_targToNodeMap.end() )
        {
            o_nodeId = l_nodeItr->second;
            return;
        }

        //find the node to which this target belongs
        for(uint8_t i=0; i<INVALID_NODE_ID; ++i)
        {
           for(uint32_t j=0; j<iv_nodeContainer[i].sectionCount; ++j)
           {
               if(  iv_nodeContainer[i].pSections[j].type ==
                                  SECTION_TYPE_PNOR_RO)
               {
                   TARG_DBG("%d/%d> pTargetMap=%p, end=%p", i, j, iv_nodeContainer[i].pTargetMap, (
                        reinterpret_cast<uint8_t*>(
                            iv_nodeContainer[i].pTargetMap) +
                            iv_nodeContainer[i].pSections[j].size) );

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
                     s_targToNodeMap[i_pTarget] = i;
                     TARG_DBG("Target %p is on node %d @ %p", i_pTarget, o_nodeId, &o_nodeId );
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
        void* o_pTransAddr = i_pAddress;
        if(i_pTarget != NULL)
        {
            NODE_ID l_nodeId = NODE0;
            getNodeId(i_pTarget, l_nodeId);
            o_pTransAddr =  translateAddr(i_pAddress, l_nodeId);
        }
        return o_pTransAddr;
    }

    void* AttrRP::translateAddr(void* i_pAddress,
                                const TARGETING::NODE_ID i_nodeId)
    {
        void* l_address = reinterpret_cast<void*>(
                           reinterpret_cast<uint64_t>(i_pAddress) &
                           MASK_OFF_UPPER_BYTE);
        do
        {
            if (i_nodeId >= AttrRP::INVALID_NODE_ID)
            {
                TRACFCOMP(g_trac_targeting, "ERROR: invalid nodeid=%d"
                        " passed to translateAddr", i_nodeId);
                break;
            }

            for (size_t i = 0; i < iv_nodeContainer[i_nodeId].sectionCount; ++i)
            {
                if ((iv_nodeContainer[i_nodeId].pSections[i].vmmAddress +
                     iv_nodeContainer[i_nodeId].pSections[i].size) >=
                     reinterpret_cast<uint64_t>(l_address))
                {
                    l_address = reinterpret_cast<void*>(
                           iv_nodeContainer[i_nodeId].pSections[i].pnorAddress +
                           reinterpret_cast<uint64_t>(l_address) -
                           iv_nodeContainer[i_nodeId].pSections[i].vmmAddress);
                    break;
                }
            }
        } while (0);

        TRACDCOMP(g_trac_targeting, "Translated 0x%p to 0x%p",
                  i_pAddress, l_address);

        return l_address;
    }

    #ifdef __HOSTBOOT_RUNTIME
    errlHndl_t AttrRP::convertPlatTargAddrToCommonAddr(
        const Target* const i_pTarget,
            uint64_t&     o_rawAddr) const
    {
        errlHndl_t pError = nullptr;
        AbstractPointer<void> rawAddr;
        rawAddr.raw = 0;

        NODE_ID nodeId = TARGETING::INVALID_NODE;
        getNodeId(i_pTarget,nodeId);
        if(nodeId != TARGETING::INVALID_NODE)
        {
            AttrRP_Section* l_pSection = iv_nodeContainer[nodeId].pSections;
            for(size_t l_sectionCnt = 0;
                l_sectionCnt < iv_nodeContainer[nodeId].sectionCount;
                ++l_sectionCnt, ++l_pSection)
            {
                if(l_pSection->type == SECTION_TYPE_PNOR_RO)
                {
                    TargetingHeader* l_pHeader = static_cast<TargetingHeader*>(
                                   iv_nodeContainer[nodeId].pTargetMap);
                    uint64_t l_addr = reinterpret_cast<uint64_t>(i_pTarget) -
                                        l_pSection->pnorAddress +
                                        l_pHeader->vmmBaseAddress.raw;
                    o_rawAddr = l_addr;
                    break;
                }
            }
        }
        else
        {
            TARG_ERR("Invalid node ID of nodeId = 0x%02X when "
                    "trying to convert platform target address of %p to a "
                    "common address",
                    nodeId,
                    i_pTarget);
           /*@
            *   @errortype
            *   @moduleid           TARG_MOD_ATTRRP_TO_COMMON_ADDR
            *   @reasoncode         TARG_RC_INVALID_NODE
            *   @userdata1          Target's HUID
            *   @userdata2          Node ID
            *
            *   @devdesc            Invalid Node ID was returned for the passed
            *                       target
            *   @custdesc           A problem occurred during the IPL of the
            *                       system.
            */
            pError = new ErrlEntry(
                ERRL_SEV_UNRECOVERABLE,
                TARG_MOD_ATTRRP_TO_COMMON_ADDR,
                TARG_RC_INVALID_NODE,
                TARGETING::get_huid(i_pTarget),
                nodeId
                );
        }

        rawAddr.raw = o_rawAddr;
        // Node count starts with 1, so increment the node ID here.
        rawAddr.TranslationEncoded.nodeId = ++nodeId;
        // Update the address with the node ID.
        o_rawAddr = rawAddr.raw;

        return pError;
    }
    #endif
}
