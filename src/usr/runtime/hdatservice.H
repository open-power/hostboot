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
          errlHndl_t verify_hdat_address( void* i_addr,
                                          size_t i_size );

        /**
         * @brief Verify the header portion of an HDAT section
         * @param i_header  Actual header data
         * @param i_exp  Expected header data
         * @return Error on mismatch
         */
        errlHndl_t check_header( hdatHDIF_t* i_header,
                                 const hdatHeaderExp_t& i_exp );

          /**
           * @brief Verify basic characteristics of a HDAT Tuple structure
           * @param i_section  Section name being verified
           * @param i_tuple  Tuple to check
           * @return Error if Tuple is unallocated
           */
          errlHndl_t check_tuple( const RUNTIME::SectionId i_section,
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
        errlHndl_t get_standalone_section( RUNTIME::SectionId i_section,
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
         * Count of number of MDRT entries present
         * on MPIPL/Dump.  A value of 0 implies it
         * doesn't need to be written
         */
        uint16_t iv_mdrtCnt;

      public:
        /**
         * @brief  Update the actual count of MDRT.  Called by dump
         *  and needs to be saved away till populate_attributes.  Can't
         *  be directly written by dump since FSP will load new value over

         * @param[in] i_count   Actual count for MDRT entries
         *
         */
        void updateMdrtCount( uint16_t i_count )
        {
            iv_mdrtCnt = i_count;
        }

        /**
         * @brief  Write the MDRT stored value to SPIRA
         *
         * @return errlHndl_t  NULL on success
         */
        errlHndl_t writeMdrtCount( void )
        {
            errlHndl_t l_err = NULL;
            if(iv_mdrtCnt)
            {
                l_err = updateHostDataSectionActual(
                                   MS_DUMP_RESULTS_TBL,iv_mdrtCnt);
            }
            return l_err;
        }
    };

};
#endif
