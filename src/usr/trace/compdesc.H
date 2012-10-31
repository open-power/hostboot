/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/compdesc.H $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
#ifndef __TRACE_COMPDESC_H
#define __TRACE_COMPDESC_H

/** @file compdesc.H
 *
 *  @brief Defines the classes for component descriptors and a singleton list
 *         of descriptors.
 */

#include <trace/interface.H>
#include <sys/sync.h>
#include <list>

namespace TRACEDAEMON { class Daemon; } // Forward declaration.

namespace TRACE
{

    class Entry; // Forward declaration.

    /** @class ComponentDesc
     *
     *  @brief The descriptor for a particular component.
     *
     *  @note These should not be created directly, but by the ComponentList
     *        interfaces.
     */
    class ComponentDesc
    {
        public:
            friend class ComponentList;
            friend class Service;
            friend class Buffer;
            friend class TRACEDAEMON::Daemon;

        private:
            /** Constructor
             *
             *  @param[in] i_comp - Component name.
             *  @param[in] i_size - Size limit of buffer.
             *  @param[in] i_bufferType - Type of buffer this component is
             *                            assigned to.
             */
            ComponentDesc(const char* i_comp, uint32_t i_size,
                          uint8_t i_bufferType = BUFFER_FAST);

            /** Max ength of component names. */
            enum { COMP_SIZE = TRAC_COMP_SIZE };

            char iv_compName[COMP_SIZE];        //< Component name.
            uint8_t iv_compNameLen;             //< Length in bytes of name.

            uint8_t iv_bufferType;              //< Buffer type.
            bool iv_debugEnabled;               //< Debug or Field-only traces.

            uint32_t iv_maxSize;                //< Size limit.
            uint32_t iv_curSize;                //< Current size.

            Entry* iv_first;    //< First (newest) trace entry.
            Entry* iv_last;     //< Last (oldest) trace entry.
    };

    /** @class ComponentList
     *
     *  @brief Maintains the global list of component trace descriptors.
     *
     *  It is expected that a singleton instance of this exists and all
     *  trace descriptors are allocated from it.
     */
    class ComponentList
    {
        public:
            typedef std::list<ComponentDesc> List;

            /** Default constructor */
            ComponentList();

            /** Default destructor */
            ~ComponentList();

            /** Get descriptor for a component
             *
             *  @param[in] i_comp - Name of the component.
             *  @param[in] i_size - Size limit of buffer.
             *  @param[in] i_bufferType - Buffer type.
             *
             *  If i_size is 0, that implies this is not "creating" a buffer
             *  but "requesting" the buffer, for instance to pass to the
             *  buffer-extract functions.  In that case, if the buffer does
             *  not currently exist we don't know what size-limit to use
             *  when creating the buffer, so the function will return NULL.
             *
             *  @return Descriptor or NULL.
             */
            ComponentDesc* getDescriptor(const char* i_comp, uint32_t i_size,
                                         uint8_t i_bufferType = BUFFER_FAST);

            /* Thread-safe iterator functions (for daemon). */
            /** Get the first component descriptor
             *
             *  @param[out] o_comp - Iterator to first component.
             *
             *  @return bool - True if empty-list.
             */
            bool first(List::iterator& o_comp);
            /** Get the next component descriptor
             *
             *  @param[in,out] io_comp - Iterator to increment.
             *
             *  @return bool - True if iterator was the last descriptor.
             *
             *  Ex. "if (io_comp->next == iv_components.end()) return true"
             */
            bool next(List::iterator& io_comp);

        private:
                /** List of component descriptors. */
            List iv_components;
                /** Mutex for thread-safety. */
            mutex_t iv_mutex;
    };
}

#endif
