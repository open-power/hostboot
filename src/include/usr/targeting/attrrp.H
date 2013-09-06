/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/attrrp.H $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
#include <targeting/attrsync.H>

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

    public:

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
        {
            return i_pAddress;
        }

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
        {
            return i_pAddress;
        }

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
        static void init(errlHndl_t& io_taskRetErrl);

    protected:

        /**
         *  @brief Initialize the attribute resource provider
         *
         *  @par Detailed Description"
         *      Ensures member variables are initialized to sane values.
         */
        AttrRP()
            : iv_msgQ(NULL), iv_sections(NULL), iv_sectionCount(0)
        {
        };

        /**
         *  @brief Destroy the attribute resource provider
         *
         *  @par Detailed Description:
         *      Frees any memory allocated by the resource provider.
         *
         *  @note This should never actually be used because the daemon
         *        thread and the vmm blocks are unable to be reclaimed.
         *        Function will assert if called due to leaky behavior.
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
        void startup(errlHndl_t& io_taskRetErrl);

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

        // Parsed structures of the attribute sections.
        AttrRP_Section* iv_sections;

        // Count of attribute sections.
        size_t iv_sectionCount;
};

/**
 *  @brief Give callers access to the singleton
 */
TARG_DECLARE_SINGLETON(TARGETING::AttrRP,theAttrRP);

} // End namespace TARGETING

#endif // __TARGETING_ATTRRP_H
