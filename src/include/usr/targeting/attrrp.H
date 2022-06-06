/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/attrrp.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#ifndef __TARGETING_ATTRRP_H
#define __TARGETING_ATTRRP_H

/**
 *  @file targeting/attrrp.H
 *
 *  @brief Interface for the attribute resource provider, which manages the
 *      memory associated with targeting attributes and provides any
 *      translation, if necessary
 */
//******************************************************************************
// Includes
//******************************************************************************

#include <vector>
#include <initservice/taskargs.H>
#include <sys/msg.h>
#include <targeting/adapters/types.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/attributeTank.H>

namespace TARGETING
{

// Forward declaration of attribute section parsed information structure.
struct AttrRP_Section;

// These constexprs are used by editPagePermissions function
constexpr uint32_t DEFAULT_PERMISSIONS = 0xFFFFFFFF;
constexpr uint8_t ALL_SECTION_TYPES = 0xFF;

#ifdef __HOSTBOOT_RUNTIME
/**
 *  @brief Structure used to store Node specific information
 */
struct NodeInfo
{

    NodeInfo() :
        pTargetMap(nullptr),
        pSections(nullptr),
        sectionCount(0),
        isValid(false)
    {
    }

    // helper to determine if NodeInfo struct has
    // been initialized or not
    bool getIsValid() const  { return isValid; };

    // set the instance var to indicate the NodeInfo
    // struct has ben initialized
    void setIsValid( bool i_valid )
    {
        isValid = i_valid;
    };

    // Pointer to the targeting image
    void*           pTargetMap;

    // Parsed structures of the attribute sections.
    AttrRP_Section* pSections;

    // Count of attribute sections.
    size_t          sectionCount;

    // has this node info struct been setup
    bool            isValid;

};

#endif

/**
 *  @class AttrRP
 *
 *  @brief Attribute Resource Provider daemon class.
 *
 *  @par Detailed Description:
 *      Provides all the functionality to translate between PNOR and
 *      Attribute virtual memory spaces.  Parses PNOR header for attribute
 *      sections, allocates virtual memory spaces with the kernel for each
 *      section, and handles virtual memory request messages from the
 *      kernel.
 */
class AttrRP
{

    // add some friends for the attribute sync features
#ifndef __HOSTBOOT_RUNTIME
    friend  bool TargetService::writeSectionData(
                           const std::vector<sectionRefData>& i_pages );

    friend  void TargetService::readSectionData(
                           std::vector<sectionRefData>& o_pages,
                           const SECTION_TYPE i_sectionId,
                           const TARGETING::NODE_ID i_nodeId);

#else
    friend errlHndl_t RT_TARG::saveRestoreAttrs(void *,
                                                void *,
                                                uint8_t);
#endif

    public:

        /**
         *  @brief Returns physical address of HB data reserved mem TOC
         *         note: does not unmap address
         *
         *  @return phys addr of table of contents of hb data reserved memory
         *
         */
        static uint64_t getHbDataTocAddr();

#ifdef __HOSTBOOT_RUNTIME
        /**
         *  @brief Initialize node struct for a given node
         *
         *  @param[in/out] io_nodeCont
         *      Node struct to be initialized
         *
         *  @param[in] i_header
         *      Targeting image header for node
         *
         *  @param[in] i_nodeId
         *      Node ID for which to initialize node struct
         *
         *  @return Error log
         */
        errlHndl_t nodeInfoInit(NodeInfo& io_nodeCont,
                                TargetingHeader* i_header,
                                const NODE_ID i_nodeId);

        /**
         *  @brief Returns address of targeting image in reserved memory
         *
         *  @param[in] i_nodeId
         *      Node ID for which to get targeting image address
         *
         *  @return Address of targeting image as a void*
         */
        void* getTargetMapPtr(const NODE_ID i_nodeId);

       /**
        *  @brief Converts target's platform address to a common address
        *
        *  @par Detailed Description:
        *      Takes a platform target address, and converts it to a
        *      common address by looking up the node/section holding the
        *      address and adding the previously stripped out VMM offset
        *      back in
        *
        *  @param[in] i_pTarget
        *      Pointer to target. Must not be nullptr (decode error otherwise)
        *  @param[out] o_rawAddr
        *      Target's platform address converted to common address.  On
        *      failure, returns 0.  May include node ID in leftmost byte.
        *
        *  @return Error log handle indicating the status of the request
        *
        *  @retval nullptr Translated the platform address into a common
        *      address and returned result in o_rawAddr
        *  @retval !nullptr Failed to translate the platform address into a
        *      common address and set o_rawAddr to 0
        *
        *      Error log handle points to a valid error log object whose
        *      primary SRC reason code (pError->getSRC()->reasonCode())
        *      indicates the type of error.  This API may return one
        *      of the following "special" reason codes:
        *          N/A
        *
        *  @note It is up to the caller to change the severity of the
        *      returned error based on what it decides to do with it.  By
        *      default any returned error created by this function will
        *      be a non-reported tracing event error log.
        */
        errlHndl_t convertPlatTargAddrToCommonAddr(
                   const Target* const i_pTarget,
                   uint64_t&     o_rawAddr) const;
#endif

        /**
         *  @brief Returns relocated absolute address of payload
         *
         *  @return phys addr of payload
         *
         */
        static uint64_t getHbDataRelocPayloadAddr();

        /**
         *  @brief Returns base address of the RO section containing the
         *      targets
         *
         *  @param[in] i_nodeId
         *      Node ID to get base address for, ignored by Hostboot, which
         *      always gets base address of local node
         *
         *  @return Base address of the RO section containing the targets as
         *      a void*
         */
        void* getBaseAddress(const NODE_ID i_nodeId);

        /**
         *  @brief Returns Node Id of the Target handle passed (internal)
         *
         *  @param[in] i_pTarget
         *      Non-NULL Target handle for which node ID is required.
         *  @param[out] o_nodeId
         *      Node ID of the Target Handle requested. If Target not found
         *      the invalid node will be return in here.
         *
         *  @return void
         */
        void getNodeId(const Target* i_pTarget,
                       NODE_ID& o_nodeId) const;
        /**
         *  @brief Setup physical TOC address and read the TOC to look
         *  for the reserved memory region
         *
         *  @param[out] o_phys_attr_data_addr, Physical attribute data address
         *  @param[out] o_attr_data_size_bytes, Attribute data size
         *
         *  @return errlHndl_t Error log handle
         *  @retval nullptr Success, successfully got the reserved memory region
         *  @retval !nullptr Failure, points to a valid error log
         */
        static errlHndl_t getReservedMemoryRegion(uint64_t& o_phys_attr_data_addr,
                                                  uint64_t& o_attr_data_size_bytes);

#ifdef __HOSTBOOT_RUNTIME
        /**
         *  @brief Returns Node Id of the Target handle passed (external)
         *
         *  @param[in] i_pTarget
         *      Non-NULL Target handle for which node ID is required.
         *  @return NODE_ID
         *      Node ID of the Target Handle requested. If Target not found
         *      the invalid node will be return in here.
         */
        static NODE_ID getNodeId(const Target* i_pTarget);
#endif

        /**
         *  @brief Translates given address, according to the resource
         *      provider's translation algorithm
         *
         * @param[in] i_pAddress
         *     Address to translate
         *
         * @param[in] i_pTarget
         *     Node target used by common code, unused in Hostboot
         *
         * @return void* Returns the translated address.  Common attribute
         *     code has a static, compile time check that is used to
         *     determine whether to call this function, however the Hostboot
         *     compiler complains when this is not provided.  Therefore
         *     while this method exists, Hostboot will never call it, and if
         *     it does it will always get a no-op translation.
         */
        void* translateAddr(
            void* i_pAddress,
            const Target* i_pTarget)
#ifndef __HOSTBOOT_RUNTIME
        {
            return i_pAddress;
        }
#else
        ;
#endif

        /**
         *  @brief Translates given address, according to the resource
         *      provider's translation algorithm
         *
         * @param[in] i_pAddress
         *     Address to translate
         *
         * @param[in] i_nodeId
         *     Node ID used by common code, unused in Hostboot
         *
         * @return void* Returns the translated address.  Common attribute
         *     code has a static, compile time check that is used to
         *     determine whether to call this function, however the Hostboot
         *     compiler complains when this is not provided.  Therefore
         *     while this method exists, Hostboot will never call it, and if
         *     it does it will always get a no-op translation.
         */
        void* translateAddr(
            void* i_pAddress,
            const TARGETING::NODE_ID i_nodeId)
#ifndef __HOSTBOOT_RUNTIME
        {
            return i_pAddress;
        }
#else
        ;
#endif

        /**
         *  @brief Initializes and starts the AttrRP daemon.
         *
         *  @param[in/out] io_taskRetErrl
         *      Error log handle; on input, a NULL error log handle; on
         *      output, a NULL error log handle on success, or !NULL handle
         *      on failure
         *
         *  @note If any error occurs during initialization, it will be
         *        reported back through the TaskArgs structure to the init
         *        service.
         */
        static void init(errlHndl_t& io_taskRetErrl, bool i_isMpipl = false);

#ifndef __HOSTBOOT_RUNTIME

        /**
          * @enum msg_mm_rp_runtime_prep_t
          *
          * @brief Message subtypes for the MSG_MM_RP_RUNTIME_PREP message
          */
        enum msg_mm_rp_runtime_prep_t
        {
            // data[0] = MSG_MM_RP_RUNTIME_PREP_BEGIN or
            // data[0] = MSG_MM_RP_RUNTIME_PREP_END
            MSG_MM_RP_RUNTIME_PREP_BEGIN, ///< Force all pages to be validated
            MSG_MM_RP_RUNTIME_PREP_END,   ///< Disable force validation
        };

        /**
         *  @enum ATTRRP_MSG_TYPE
         *
         *  @brief Non-kernel message types for the attribute resource provider
         *      message handler
         */
        enum ATTRRP_MSG_TYPE : uint32_t
        {
            // Prepare runtime for secure transition of attributes
            MSG_MM_RP_RUNTIME_PREP        = 0x00000002,
            // Arm service to synchronize attributes
            MSG_PRIME_ATTR_SYNC           = 0x00000003,
            // Invoke attribute synchronization
            MSG_INVOKE_ATTR_SYNC          = 0x00000004,
            // Shutdown attribute synchronization
            MSG_SHUTDOWN_ATTR_SYNC        = 0x00000005,
            // Attribute overrides and syncs
            MSG_ATTR_OVERRIDE_SYNC        = 0x00000006,
            // Attribute Sync presence detect completed
            MSG_ATTR_SYNC_WINDOW_OPEN  = 0x00000007,
            // Explicitly disable the SP sync of attributes on shutdown
            MSG_ATTR_DO_NOT_SYNC_ON_SHUTDOWN  = 0x00000008,
            // Sentinel value for when message type is not yet known
            MSG_INVALID                   = 0xFFFFFFFF,
        };

        /**
         *  @enum RESOURCE
         *
         *  @brief Enumeration which indicates a specific resource (service,
         *      condition, etc.)
         */
        enum RESOURCE : uint8_t
        {
            MAILBOX, ///< FSI mailbox service
            SYNC_WINDOW_OPEN, ///< State when safe to sync attributes
        };

        /**
         *  @brief This is a static wrapper around _notifyResourceReady
         *
         *  @see _notifyResourceReady for documentation
         */
        static errlHndl_t notifyResourceReady(RESOURCE i_resource);

        /**
         *  @brief This is a static wrapper around _syncAllAttributesToSP
         *
         *  @see _syncAllAttributesToSP for documentation
         */
        static errlHndl_t syncAllAttributesToSP();

        /**
         *  @brief This is a static wrapper around _sendAttrOverridesAndSyncs
         *
         *  @see _sendAttrOverridesAndSyncs for documentation
         */
        static errlHndl_t sendAttrOverridesAndSyncs();

        /**
         *  @brief This is a static wrapper around _disableAttributeSyncToSP
         *
         *  @see _disableAttributeSyncToSP for documentation
         */
        static errlHndl_t disableAttributeSyncToSP();

        /**
        *  @brief Modifies the memory R/W permissions on VMM pages for a
        *         given type of AttrRP_Section. Valid types can be found
        *         in the generated file pnorheader.H. Valid permissions
        *         can be found in src/include/sys/mm.h . It was chosen to
        *         not use the enums to avoid needing to include the headers
        *         all over.
        *
        *  @param[in] i_type The type of AttrRP_Section we want to apply the permission
        *                    edits to. Valid options for the attrrp types are:
        *                    SECTION_TYPE_PNOR_RO           = 0x00
        *                    SECTION_TYPE_PNOR_RW           = 0x01
        *                    SECTION_TYPE_HEAP_PNOR_INIT    = 0x02
        *                    SECTION_TYPE_HEAP_ZERO_INIT    = 0x03
        *                    SECTION_TYPE_HB_HEAP_ZERO_INIT = 0x0A
        *                    ALL_SECTION_TYPES              = 0xFF
        *
        *  @param[in] i_permission The R/W permissions the user desires to apply to a
        *                          given section. Note that values can be OR'ed
        *                          together. Valid options are :
        *                          READ_ONLY             = 0x00000001
        *                          WRITABLE              = 0x00000002
        *                          EXECUTABLE            = 0x00000004
        *                          WRITE_TRACKED         = 0x00000008
        *                          ALLOCATE_FROM_ZERO    = 0x00000010
        *                          NO_ALLOCATE_FROM_ZERO = 0x00000020
        *                          NO_ACCESS             = 0x00000040
        *                          BYPASS_HRMOR          = 0x00000080
        *                          GUARDED               = 0x00000100
        *                          DEFAULT_PERMISSIONS    = 0xFFFFFFFF
        *
        *  @note If the value 0xFF is passed in for i_type then all types will
        *         get permissions updated to i_permission.
        *        If the value 0xFFFF is passed in for i_permission then the sections
        *        will have their R/W permissions set up to the default values given
        *        in PNOR
        */
        errlHndl_t editPagePermissions(uint8_t i_type, uint32_t i_permission);

        /**
         *  @brief Copies all present attribute sections to memory.
         *
         *  @param[in,out] i_addr
         *      Physical address at the bottom of the desired region to
         *      place.
         *
         *  @return Virtual address to the region.
         */
        static void* save(uint64_t& io_addr);

        /**
         *  @brief Copies all present attribute sections to memory.
         *
         *  @param[in] i_dest
         *      Physical address to copy override data into
         *  @param[in,out] io_size
         *      in: Maximum size of allocated space in bytes
         *      out: Actual number of bytes used (zero means no overrides)
         *
         *  @return Error log
         */
        static errlHndl_t save(uint8_t * i_dest, size_t & io_size);

        /**
         *  @brief Returns size needed to save all attributes
         *
         *  HDAT requires up front knowledge of largest section
         *
         *
         *  @return Size of all attribute sections
         */
        static uint64_t  maxSize( );

        /**
         *  @brief Copies all present attribute override tanks to memory.
         *
         *  @param[in] i_dest
         *      Physical address to copy override data into
         *  @param[in,out] io_size
         *      in: Maximum size of allocated space in bytes
         *      out: Actual number of bytes used (zero means no overrides)
         *
         *  @return Error log
         */
        static errlHndl_t saveOverrides( uint8_t* i_dest,
                                         size_t& io_size );

        /**
         * @brief Performs the merge of attributes from the HBD_RW PNOR section
         *        to HBD section. Non-volatile, read-write attributes are copied
         *        into the HBD partition from HBD_RW if their sizes and
         *        persistencies match across HBD and HBD_RW. Attributes whose
         *        size or persistency changed retain the value from HBD
         *        partition.
         *
         * @return nullptr on success; non-nullptr on error.
         */
        static errlHndl_t mergeAttributes();

        /**
         * @brief Dumps all of the Hostboot attributes and their values to a
         * lid file (ATTR_DUMP_LIDID)
         *
         * @return nullptr on success; valid error log on error.
         */
        static errlHndl_t dumpAttrs();

#else
        /**
         *  @brief Get count of nodes handled by attribute resource provider.
         *
         *  @return Number of node containers
         */
        size_t getNodeCount()
        {
            return iv_nodeContainer.size();
        }
#endif

    protected:

        /**
         *  @brief Initialize the attribute resource provider
         *
         *  @par Detailed Description:
         *      Ensures member variables are initialized to sane values.
         */
        AttrRP()
#ifndef __HOSTBOOT_RUNTIME
            : iv_msgQ(nullptr), iv_attrSyncMsgQ(msg_q_create()),
              iv_sections(nullptr), iv_sectionCount(0),
              iv_attrSyncPrimed(false),iv_attrSyncWindowOpen(false),iv_isMpipl(false)
#else
            : iv_isTempInstance(false), iv_isMpipl(false)
#endif
        {
        };

#ifdef __HOSTBOOT_RUNTIME
        /**
         *  @brief Initialize temporary attribute resource provider
         *
         *  @par Detailed Description:
         *      Ensures member variables are initialized to sane values.
         *
         *  @param[in] i_header, Targeting Header for the node of interest
         *  @param[in] i_nodeId, Node ID for the node of interest
         *  @param[in] i_nodeCount, Number of nodes to initialize
         */
        AttrRP(TargetingHeader* i_header,
               NODE_ID i_nodeId,
               size_t i_nodeCount)
            : iv_isTempInstance(true), iv_isMpipl(false)
        {
            // Work with nodes before passed in node
            for(NODE_ID l_nodeId = NODE0; l_nodeId < i_nodeCount; ++l_nodeId)
            {
                // Create local copy of container for node info struct
                NodeInfo l_nodeCont;

                if(l_nodeId == i_nodeId)
                {
                    // Initialize local copy of container for node info struct
                    errlHndl_t l_errl = nodeInfoInit(l_nodeCont,
                                                     i_header,
                                                     i_nodeId);
                    if (l_errl)
                    {
                        l_errl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);

                        /* Commit the error */
                        errlCommit(l_errl, TARG_COMP_ID);

                        break;
                    }
                }

                // Push back node info struct into the node container
                iv_nodeContainer.push_back(l_nodeCont);
            }
        };
#endif

        /**
         *  @brief Destroy the attribute resource provider
         *
         *  @par Detailed Description:
         *      Frees any memory allocated by the resource provider.
         *
         *  @note This should never actually be used for the singleton
         *        instance because the daemon thread and the vmm blocks
         *        are unable to be reclaimed.  Function will assert if
         *        called due to leaky behavior.
         */
        ~AttrRP();

#ifndef __HOSTBOOT_RUNTIME
        /**
         *  @brief Copies the section data buffer from the vector to the
         *  appropriate section offset with respect to the node target ptr
         *  and section id.
         *
         *  @param[in] i_pages, vector of sectionRefData struct
         *
         *  @return true successful in writing Section Data
         *  @return false failed writing Section Data
         */

        bool writeSectionData(
                const std::vector <sectionRefData>& i_pages) const;

        /**
         *  @brief Populates the output vector with the correct information
         *         for the data pages specified by the selected section
         *
         *  @param[out] o_pages, vector of sectionRefData struct
         *  @param[in] i_sectionType
         *      Type of section to read
         *  @param[in] Node associated with the section, unused in HB
         *
         *  @return void
         */
        void readSectionData(
                  std::vector <sectionRefData>& o_pages,
            const SECTION_TYPE                  i_sectionType,
            const NODE_ID                       i_nodeId = 0) const;
#else
        /**
         *  @brief Check the HB existing image attribute from the system target
         *         in the targeting data for the node.  Use image to determine
         *         if node of interest (instance) is a node that is shown to be
         *         present.  Also update the maximum node ID as needed.
         *
         *  @param[in] i_header, Targeting Header for the node of interest
         *  @param[in] i_instance, Specifies the node of interest
         *  @param[in/out] io_maxNodeId, maximum node ID in use on the system
         *
         *  @return Error log
         */
        errlHndl_t checkHbExistingImage(TargetingHeader* i_header,
                                        uint8_t i_instance,
                                        NODE_ID &io_maxNodeId);
#endif


    private:

        /**
         *  @brief Performs the startup of the daemon instance.
         *
         *  @par Detailed Description:
         *      init() is a static function that just calls
         *      Singleton<AttrRP>::instance().startup().  See init for
         *      behavior.
         *
         *  @param[in/out] io_taskRetErrl
         *      Error log handle; on input, a NULL error log handle; on
         *      output, a NULL error log handle on success, or !NULL handle
         *      on failure
         */
        void startup(errlHndl_t& io_taskRetErrl,  bool i_isMpipl = false);

#ifndef __HOSTBOOT_RUNTIME

        /**
         *  @brief Notifies the attribute resource provider that a specific
         *      resource of interest is ready/available
         *
         *  @param[in] i_resource Resource that is ready/available
         *
         *  @return errlHndl_t Error log handle
         *  @retval nullptr  Resource notification successful
         *  @retval !nullptr Resource notification failed; handle
         *      references valid error log
         */
        errlHndl_t _notifyResourceReady(RESOURCE i_resource) const;

        /**
         *  @brief Forces attributes to sync down to SP (FSP/BMC)
         *
         *  @return errlHndl_t Error log handle
         *  @retval nullptr  Attribute synchronization successful
         *  @retval !nullptr Attribute synchronization failed; handle
         *      references valid error log
         */
        errlHndl_t _syncAllAttributesToSP() const;

        /**
         *  @brief Send attribute overrides and sync down to FSP
         *
         *  @return errlHndl_t Error log handle
         *  @retval nullptr  Send attribute overrides and sync successful
         *  @retval !nullptr Send attribute overrides and sync failed; handle
         *      references valid error log
         */
        errlHndl_t _sendAttrOverridesAndSyncs() const;

        /**
         *  @brief Disables the normal attribute sync process that happens
         *    on all shutdowns.  This is useful if we're shutting down for
         *    certain reasons, e.g. controlled powerdown.
         *
         *  @return errlHndl_t Error log handle
         *  @retval nullptr  Disablement of attribute sync successful
         *  @retval !nullptr Disablement of attribute sync  failed; handle
         *      references valid error log
         */
        errlHndl_t _disableAttributeSyncToSP() const;

        /**
         *  @brief Sends message of the given type to the attribute resource
         *      provider
         *
         *  @param[in] i_msgType Type of message to send
         *  @param[in] i_sync    true, if the message is synchronous, false
         *      otherwise
         *
         *  @return errlHndl_t Error log handle
         *  @retval nullptr  Message processed successfully
         *  @retval !nullptr Message processing failed; handle references
         *      valid error log
         */
        errlHndl_t _sendAttrSyncMsg(
            ATTRRP_MSG_TYPE i_msgType,
            bool            i_sync) const;

        /**
         *  @brief Synchronizes attributes to SP (FSP or BMC)
         *  *
         *  @par Detailed Description:
         *      During a user space initiated shutdown, the init service calls
         *      the resource provider shutdown handler which attempts to
         *      synchronize attributes down to the SP.  For this to succeed,
         *      the SP must be available, the mailbox must be online (and have
         *      earlier called notifyResourceReady API to arm the
         *      synchronization). Various isteps also invoke attribute
         *      synchronization explicitly via this API when needed.
         *
         *  @return errlHndl_t Error log handle
         *  @retval nullptr  Attribute synchronization successful
         *  @retval !nullptr Attribute synchronization failed; handle
         *      references valid error log
         */
        errlHndl_t _invokeAttrSync() const;

        /**
         *  @brief Synchronizes attributes to FSP
         *  *
         *  @par Detailed Description:
         *      See _invokeAttrSync description above.
         *      SBE must not be quiesced (or mailbox
         *      traffic going through the SBE FIFO in secure mode will fail).
         *
         *  @return errlHndl_t Error log handle
         *  @retval nullptr  Attribute synchronization successful
         *  @retval !nullptr Attribute synchronization failed; handle
         *      references valid error log
         */
        errlHndl_t _invokeFspSync() const;

        /**
         *  @brief Processes daemon messages
         *
         *  @par Detailed Description:
         *      Performs a while(1) waiting for messages from
         *      kernel/VMM/user space and handles as appropriate.  Reads /
         *      writes data from / to PNOR for the attribute sections for
         *      kernel/VMM messages.
         */
        void msgServiceTask() const;

        /**
         *  @brief Task which processes attribute synchronization requests
         *
         *  @par Detailed Description:
         *      Processes attribute synchronization requests, especially in
         *      relation to synchronizing attributes when Hostboot terminates.
         */
        void attrSyncTask();

        /**
         *  @brief Parses the attribute section header in PNOR.
         *
         *  @par Detailed Description:
         *      Constructs the local attribute section data structures
         *      (iv_sections / iv_sectionCount).
         *
         *  @return errlHndl_t
         *      Returns an error log handle that is NULL on success or !NULL
         *      on failure
         */
        errlHndl_t parseAttrSectHeader();

        /**
         *  @brief Allocates VMM sections for each Attribute section.
         *
         *  @par Detailed Description:
         *      Calls to the kernel to create VMM blocks for each attribute
         *      and initializes permissions appropriately based on section
         *      type.
         *
         *  @return errlHndl_t
         *      Returns an error log handle that is NULL on success or !NULL
         *      on failure
         */
        errlHndl_t createVmmSections();

        /**
        *  @brief Populates R/W and Heap Zero init sections of HBD from the
        *         values that we stored before we attempted the MPIPL
        *
        *  @par Detailed Description:
        *      Performs a memcpy from the physical address where HDAT information
        *      was stored by HBRT to the VMM addresses used by ATTR RP to look up
        *      attr values
        *
        *  @return void
        */
        void populateAttrsForMpipl(void);

        /** Internal implementation of save function. */
        void* _save(uint64_t&);

        /** Internal implementation of save function. */
        errlHndl_t _save(uint8_t* i_dest, size_t& io_size );

        /** Internal implementation of saveOverrides function. */
        errlHndl_t _saveOverrides( uint8_t* i_dest,
                                   size_t& io_size );

        /**
         * @brief Serialize and copy a single override tank out to memory
         *
         * @param[in]  i_dest  Starting address to copy data into
         * @param[inout] io_size  Input: Size of i_dest buffer
         *                        Output: Size of serialized data
         * @param[in]  i_tank  Override tank to serialize out
         * @param[in]  i_layer  Type of tank being worked on
         *
         * @return Error log
         */
        errlHndl_t saveOverrideTank( uint8_t* i_dest,
                                     size_t& io_size,
                                     AttributeTank* i_tank,
                                     AttributeTank::TankLayer i_layer );

        /**
         *  @brief Starts the attribute provider's message processor
         *
         *  @par Detailed Description:
         *      This function, being static, can be called from task_create
         *      and is used to enter the daemon thread's msgServiceTask
         *      loop to process messages.
         *
         *  @param[in] i_pInstance
         *      The AttrRP to call msgServiceTask on.
         */
        static void* startMsgServiceTask(void* i_pInstance);

        /**
         *  @brief Starts the attribute provider's attribute synchronization
         *      task
         *
         *  @par Detailed Description:
         *      task_create should call this static function to enter the
         *      daemonized attribute synchronization task which handles
         *      attribute synchronization requests
         *
         *  @param[in] i_pInstance The AttrRP to call attrSyncTask on.  Must not
         *      be nullptr (or asserts);
         */
        static void* startAttrSyncTask(void* i_pInstance);

        /**
         * @brief Update the preserved RW attribute section with the current
         *        state of HBD so that potentially new RW attributes are
         *        preserved across code updates/reboots. This needs to be
         *        done after mergeAttributes so that all existing RW attrs
         *        are preserved. The preserved HBD partition is cleared
         *        before the new data is written into it.
         *
         * @return nullptr on success; non-nullptr on error.
         */
        static errlHndl_t updatePreservedAttrSection();

        // Message Queue for VMM requests
        msg_q_t iv_msgQ;

        // Message Queue for attribute sync requests
        msg_q_t iv_attrSyncMsgQ;

        // Parsed structures of the attribute sections.
        AttrRP_Section* iv_sections;

        // Count of attribute sections.
        size_t iv_sectionCount;

        // Whether service is primed to invoke attribute synchronization
        bool iv_attrSyncPrimed;
        // Whether presence detection is completed to allow attribute synchronization
        bool iv_attrSyncWindowOpen;
#else
        // Indicator that AttrRP instance is a temporary one, not the singleton
        bool iv_isTempInstance;

        // Node Container
        std::vector<NodeInfo> iv_nodeContainer;
#endif

        bool iv_isMpipl;
};

/**
 *  @brief Give callers access to the singleton
 */
TARG_DECLARE_SINGLETON(TARGETING::AttrRP,theAttrRP);

extern const char* ATTRRP_MSG_Q;
extern const char* ATTRRP_ATTR_SYNC_MSG_Q;


} // End namespace TARGETING

#endif // __TARGETING_ATTRRP_H
