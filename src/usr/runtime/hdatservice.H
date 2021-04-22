/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/hdatservice.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#ifndef __RUNTIME_HDATSERVICE_H
#define __RUNTIME_HDATSERVICE_H

#include <sys/sync.h>
#include <util/locked/list.H>
#include <list>
#include <errl/errlentry.H>
#include <attributestructs.H>
#include <sys/task.h>
#include <vector>

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
        struct hdatMemRegion_t
        {
            uint64_t    phys_addr;
            void *      virt_addr;
            size_t      size;

            /**
             * Default Contructor
             */
            hdatMemRegion_t() :
              phys_addr(0), virt_addr(NULL), size(0) {}
        };

        typedef std::vector<hdatMemRegion_t>::iterator    memRegionItr;
        typedef std::vector<hdatMemRegion_t>::const_iterator    cmemRegionItr;

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
                                       size_t& o_dataSize);

        /**
         * @brief  Clear or invalidate a particular section of the host data
         *         memory.
         *         NOTE: Section must be supported by getInstanceCount to
         *               actually clear.
         *
         * @param[in] i_section  Chunk of data to clear
         *
         * @return errlHndl_t  NULL on success; errlog otherwise
         */
        errlHndl_t clearHostDataSection(const RUNTIME::SectionId i_section);

        /**
         * @brief See documentation for get_instance_count in runtime.H
         */
        errlHndl_t getInstanceCount( const SectionId i_section,
                                     uint64_t& o_count);

        /**
         * @brief  Update the actual count of section.  Only supported for
         *         memory dump results table
         *
         * @param[in] i_section  Chunk of data to find
         * @param[in] i_count   Actual count
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t updateHostDataSectionActual( SectionId i_section,
                                                uint16_t i_count );

        /**
         * @brief  Update Processor Dump area section.
         *
         * @param[in] i_section        Chunk of data to find
         * @param[in] threadRegSize    Size of each thread register data
         * @param[in] threadRegVersion Register data format version
         *
         * @return errlHndl_t          NULL on success
         */
        errlHndl_t updateHostProcDumpActual( SectionId i_section,
                                             uint32_t threadRegSize,
                                             uint8_t threadRegVersion);

        /**
         * @brief  Update Hardware Dump area section
         *
         * @param[in] i_section        Chunk of data to find
         * @param[in] maxHwDumpSize    HW Data size per processor (Includes FFDC)
         *
         * @return errlHndl_t          NULL on success
         */
        errlHndl_t updateHWDumpActual( SectionId i_section,
                                             uint32_t maxHwDumpSize);


        /**
         * @brief  Retrieve and log FFDC data relevant to a given section of
         *         host data memory
         *
         * @param[in] i_section  Relevant section
         * @param[inout] io_errlog  Log to append FFDC to
         *
         * @return errlHndl_t  NULL on success
         */
        void addFFDC( SectionId i_section,
                      errlHndl_t& io_errlog );

        /*
         * @brief Clear out any cached data and rediscover the location
         *        of the HDAT memory
         */
        void rediscoverHDAT( void );

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
         * @brief Map a region of memory
         *
         * Utility to map a region of memory so it can be accessed.
         * Map information is stored as a class variable
         *
         * @param[in] i_addr  Physical address to map
         * @param[in] i_bytes Number of bytes to map
         * @param[out] o_vaddr Virtual address mapped to
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t mapRegion( uint64_t i_addr, size_t i_bytes,
                              uint64_t &o_vaddr);

        /**
         * @brief Retrieve (and map if necessary) a SPIRA data area
         *
         *  PHYP SPIRA is within the base mapping, Sapphire is not
         *
         * @param[in] i_tuple Valid tuple pointer to area to be mapped
         * @param[out] o_vaddr Virtual address to access data area
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t getSpiraTupleVA(hdat5Tuple_t* i_tuple,
                                     uint64_t & o_vaddr);

          /**
           * @brief Verify that a block of memory falls inside a safe range
           * @param i_addr  Address to check
           * @param i_size  Number of bytes to check
           * @return Error if address seems wrong
           */
          errlHndl_t verify_hdat_address( const void* i_addr,
                                          size_t i_size );

        /**
         * @brief Verify the header portion of an HDAT section
         * @param i_header  Actual header data
         * @param i_exp  Expected header data
         * @return Error on mismatch
         */
        errlHndl_t check_header( const hdatHDIF_t* i_header,
                                 const hdatHeaderExp_t& i_exp );

          /**
           * @brief Verify basic characteristics of a HDAT Tuple structure
           * @param i_section  Section name being verified
           * @param i_tuple  Tuple to check
           * @return Error if Tuple is unallocated
           */
          errlHndl_t check_tuple( const SectionId i_section,
                                  hdat5Tuple_t* i_tuple );


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
        errlHndl_t get_standalone_section( SectionId i_section,
                                           uint64_t i_instance,
                                           uint64_t& o_dataAddr,
                                           size_t& o_dataSize );

        /**
         * @brief Locates the proper SPIRA structure and sets instance vars
         *
         * Walks the NACA and interrogates structures to determine which
         * kind of SPIRA is available (if any).
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t findSpira( void );

      private:

        /**
         * @brief Get the tuple associated with a section and check it's valid
         *        Note: Asserts on unsupported section
         *
         * @param[in] i_section The section for which the instance count is
         *            desired
         *
         * @param[out] o_tuple The tuple associated with the section
         *
         * @return errlHndl_t Returns nullptr on success. otherwise errlog
         *
         */
        errlHndl_t getAndCheckTuple(const SectionId i_section,
                                    hdat5Tuple_t*& o_tuple);

        /**
         * @brief Get pointer to reserved memory array header
         *
         * @param[out] o_resvMemArrHdr Pointer, by reference, to the array header
         *
         * @return errlHndl_t Returns nullptr on success; otherwise errlog
         */
        errlHndl_t getResvMemArrHdr(hdatMsReservedMemArrayHeader_t*&
                                    o_resvMemArrHdr);

        /********************************************
         * VARIABLES
         ********************************************/

        /**
         * Vector of virtual address mapped in
         */
        std::vector<hdatMemRegion_t>    iv_mem_regions;

        /**
         * Legacy SPIRA
         */
        hdatSpira_t* iv_spiraL;

        /**
         * SPIRA-H
         */
        hdatSpira_t* iv_spiraH;

        /**
         * SPIRA-S
         */
        hdatSpira_t* iv_spiraS;

        /**
         * Save the actual count value for sections
         * -Used to keep track of things across HDAT writes
         *  from FSP
         */
        uint16_t iv_actuals[RUNTIME::LAST_SECTION+1];

        /**
         * Used to identify whether to use relocated payload base address
         * or normal address.
         */
        bool iv_useRelocatedPayload;

        /**
         * Dummy value for unassigned actual
         */
        enum {
            ACTUAL_NOT_SET = 0xFFFF
        };

      public:
        /**
         * @brief  Store the actual count of a section.
         *
         * @param[in] i_section  Chunk of data to update
         * @param[in] i_count   Actual count for MDRT entries
         *
         */
        void saveActualCount( SectionId i_id,
                              uint16_t i_count )
        {
            iv_actuals[i_id] = i_count;
        }

        /**
         * @brief  Write the stored actual count to SPIRA
         *
         * @param[in] i_section  Chunk of data to update
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t writeActualCount( SectionId i_id )
        {
            errlHndl_t l_err = NULL;
            if(iv_actuals[i_id] != ACTUAL_NOT_SET)
            {
                l_err = updateHostDataSectionActual( i_id, iv_actuals[i_id] );
            }
            return l_err;
        }

        /**
         * @brief  Use relocated payload base address
         *
         * @param[in] val  'true' for post dump data collection
         *
         */
        void useRelocatedPayloadAddr(bool val)
        {
            iv_useRelocatedPayload = val;
        }
    };

};
#endif
