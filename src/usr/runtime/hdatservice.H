/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/hdatservice.H $                               */
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
#ifndef __RUNTIME_HDATSERVICE_H
#define __RUNTIME_HDATSERVICE_H

#include <sys/sync.h>
#include <util/locked/list.H>
#include <list>
#include <errl/errlentry.H>
#include <usr/devicefw/driverif.H>
#include <attributestructs.H>
#include <sys/task.h>
#include <usr/fsi/fsiif.H>

namespace RUNTIME
{
    /** @file hdatservice.H
     *  @brief Provides the definition of the HDAT Service class
     */

    /**
     * Class to service HDAT data
     *   there will be a single instance within hostboot
     */
    class hdatService
    {
      public:

        /**
         * @brief  Add the host data mainstore location to VMM
         *
         * @description  If running with the standard PHYP payload this function
         *    will map all supported HDAT sections into the VMM to allow access
         *    from user space.  When running in standalone (no payload) mode,
         *    some reserved memory will be mapped in for testcases.  If AVPs are
         *    enabled, no memory will be mapped and the PAYLOAD_KIND attribute
         *    will be set appropriately.
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t loadHostData( void );

        /**
         * @brief  Get a pointer to the beginning of a particular section of
         *         the host data memory.
         *
         * @description  The returned pointer will not include any hdat header
         *     information.
         *
         * @param[in] i_section  Chunk of data to find
         * @param[in] i_instance  Instance of section when there are multiple
         *                        entries
         * @param[out] o_dataAddr  Virtual memory address of data
         * @param[out] o_dataSize  Size of data in bytes, 0 on error,
         *                         DATA_SIZE_UNKNOWN if unknown
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t getHostDataSection( SectionId i_section,
                                       uint64_t i_instance,
                                       uint64_t& o_dataAddr,
                                       size_t& o_dataSize );


      protected:
        /**
         * @brief Constructor
         */
        hdatService();


        /**
         * @brief Destructor
         */
        ~hdatService();

        /**
         * @brief Retrieve hardcoded section addresses for standalone mode
         *
         * This is here to allow us to manually generate attribute data for
         *  the HostServices code without requiring a full FipS/PHYP boot.
         *
         * @param[in] i_section  Chunk of data to find
         * @param[in] i_instance  Instance of section when there are multiple
         *                        entries
         * @param[out] o_dataAddr  Virtual memory address of data
         * @param[out] o_dataSize  Size of data in bytes, 0 on error,
         *                         DATA_SIZE_UNKNOWN if unknown
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t get_standalone_section( RUNTIME::SectionId i_section,
                                           uint64_t i_instance,
                                           uint64_t& o_dataAddr,
                                           size_t& o_dataSize );

      private:

        /********************************************
         * VARIABLES
         ********************************************/

        /**
         * Virtual address to payload base addr
         (HDAT area is offset from there)
         */
        void * iv_payload_addr;
        void * iv_dumptest_addr;

    };

};
#endif
