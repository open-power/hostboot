//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/targeting/attrrp.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __TARGETING_ATTRRP_H
#define __TARGETING_ATTRRP_H

#include <initservice/taskargs.H>
#include <sys/msg.h>

namespace TARGETING
{

    // Forward declaration of attribute section parsed information structure.
    struct AttrRP_Section;

    /** @class AttrRP
     *  @brief Attribute Resource Provider daemon class.
     *
     *  Provides all the functionality to translate between PNOR and Attribute
     *  virtual memory spaces.  Parses PNOR header for attribute sections,
     *  allocates virtual memory spaces with the kernel for each section, and
     *  handles virtual memory request messages from the kernel.
     */
    class AttrRP
    {
        public:
            /** @brief Initializes and starts the AttrRP daemon.
             *  @param[in,out]  -   ref to an errHndl_t
             *
             *  @note If any error occurs during initialization, it will be
             *        reported back through the TaskArgs structure to the init
             *        service.
             */
            static void init( errlHndl_t &io_taskRetErrl );

        protected:
            /** @brief Default constructor.
             *  Ensures member variables are initialized to sane values.
             */
            AttrRP() :
                    iv_msgQ(NULL), iv_sections(NULL), iv_sectionCount(0)
                { };

            /** @brief Default destructor.
             *  Frees any memory allocated by the daemon.
             *
             *  @note This should never actually be used because the daemon
             *        thread and the vmm blocks are unable to be reclaimed.
             *        Function will assert if called due to leaky behavior.
             */
            ~AttrRP();

        private:
            /** @brief Performs the startup of the daemon instance.
             *
             *  init() is a static function that just calls
             *  Singleton<AttrRP>::instance().startup().  See init for behavior.
             */
            void startup( errlHndl_t    &io_taskRetErrl );

            /** @brief Daemon thread processing function.
             *
             *  Performs a while(1) waiting for messages from the kernel/VMM
             *  and handles as appropriately.  Reads / writes data from / to
             *  PNOR for the attribute sections.
             */
            void msgServiceTask() const;

            /** @brief Parses the attribute section header in PNOR.
             *
             *  Constructs the local attribute section data structures
             *  (iv_sections / iv_sectionCount).
             *
             *  @return errlHndl_t - Error log if error occurs.
             */
            errlHndl_t parseAttrSectHeader();

            /** @brief Allocates VMM sections for each Attribute section.
             *
             *  Calls to the kernel to create vmm blocks for each attribute
             *  and initializes permissions appropriately based on section
             *  type.
             *
             *  @return errlHndl_t - Error log if error occurs.
             */
            errlHndl_t createVmmSections();

            /** @brief Redirect to msgServiceTask on the AttrRP instance.
             *
             *  This function, being static, can be called from task_create
             *  and is used to enter the daemon thread's msgServiceTask loop.
             *
             *  @param[in] i_instance - The AttrRP to call msgServiceTask on.
             */
            static void startMsgServiceTask(void* i_instance);

                /** Message Queue for VMM requests. */
            msg_q_t iv_msgQ;
                /** Parsed structures of the attribute sections. */
            AttrRP_Section* iv_sections;
                /** Count of attribute sections. */
            size_t iv_sectionCount;
    };
};

#endif
