/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/attrrp.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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

#include <initservice/taskargs.H>
#include <sys/msg.h>
#include <targeting/adapters/types.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/attributeTank.H>

namespace TARGETING
{

// Forward declaration of attribute section parsed information structure.
struct AttrRP_Section;

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
    friend  bool TargetService::writeSectionData(
                           const std::vector<sectionRefData>& i_pages );

    friend  void TargetService::readSectionData(
                           std::vector<sectionRefData>& o_pages,
                           const SECTION_TYPE i_sectionId,
                           const TARGETING::NODE_ID i_nodeId);

#ifdef __HOSTBOOT_RUNTIME
    friend int RT_TARG::saveRestoreAttrs(void *,
                                         void *);
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

        /**
         *  @brief Returns base address of the RO section containing the
         *      targets
         *
         *  @param[in] i_nodeIdUnused
         *      Node ID to get base address for, ignored by Hostboot, which
         *      always gets base address of local node
         *
         *  @return Base address of the RO section containing the targets as
         *      a void*
         */
        void* getBaseAddress(const NODE_ID i_nodeIdUnused);

        /**
         *  @brief Translates given address, according to the resource
         *      provider's translation algorithm
         *
         * @param[in] i_pAddress
         *     Address to translate
         *
         * @param[in] i_pUnused
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
            const Target* i_pUnused)
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
         * @param[in] i_unused
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
            const TARGETING::NODE_ID i_unused)
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

#else
        /**
         *  @brief Fill in new attribute resource provider for HBRT.
         *
         *  @param[in] i_header
         *      TargetingHeader to use with filling in the new RT AttrRP.
         *
         *  @return void
         */
        void fillInAttrRP(TargetingHeader* i_header);
#endif

    protected:

        /**
         *  @brief Initialize the attribute resource provider
         *
         *  @par Detailed Description"
         *      Ensures member variables are initialized to sane values.
         */
        AttrRP()
#ifndef __HOSTBOOT_RUNTIME
            : iv_msgQ(NULL), iv_sections(NULL), iv_sectionCount(0),
              iv_isMpipl(false)
#else
            : iv_isTempInstance(false), iv_sections(NULL), iv_sectionCount(0),
              iv_isMpipl(false)
#endif
        {
        };

#ifdef __HOSTBOOT_RUNTIME
        /**
         *  @brief Initialize temporary attribute resource provider
         *
         *  @par Detailed Description"
         *      Ensures member variables are initialized to sane values.
         */
        AttrRP(TargetingHeader* i_header)
            : iv_isTempInstance(true), iv_isMpipl(false)
        {
            // Fill in member variables
            fillInAttrRP(i_header);
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
         *  @brief Processes daemon messages
         *
         *  @par Detailed Description:
         *      Performs a while(1) waiting for messages from the
         *      kernel/VMM and handles as appropriately.  Reads / writes
         *      data from / to PNOR for the attribute sections.
         */
        void msgServiceTask() const;

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

        // Message Queue for VMM requests
        msg_q_t iv_msgQ;
#else
        // Indicator that AttrRP instance is a temporary one, not the singleton
        bool iv_isTempInstance;
#endif
        // Parsed structures of the attribute sections.
        AttrRP_Section* iv_sections;

        // Count of attribute sections.
        size_t iv_sectionCount;

        bool iv_isMpipl;
};

/**
 *  @brief Give callers access to the singleton
 */
TARG_DECLARE_SINGLETON(TARGETING::AttrRP,theAttrRP);

extern const char* ATTRRP_MSG_Q;

// user-defined message subtype for MSG_MM_RP_RUNTIME_PREP
/** @enum msg_mm_rp_runtime_prep_t
  * @brief Message type and subtypes for the MSG_MM_RP_RUNTIME_PREP message
  */
enum msg_mm_rp_runtime_prep_t
{
    MSG_MM_RP_RUNTIME_PREP = 0x2, // prepare runtime for secure transition
                                  // of attrs
                                  // data[0] = MSG_MM_RP_RUNTIME_PREP_BEGIN or
                                  // data[0] = MSG_MM_RP_RUNTIME_PREP_END
    MSG_MM_RP_RUNTIME_PREP_BEGIN,
    MSG_MM_RP_RUNTIME_PREP_END,
};

} // End namespace TARGETING

#endif // __TARGETING_ATTRRP_H
