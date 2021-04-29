/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/runtime/rt_pnor.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
#ifndef _RT_PNOR_H_
#define _RT_PNOR_H_

#include <pnor/pnorif.H>
#include "../pnor_common.H"
#include <errl/errlentry.H>
#include <map>

typedef std::pair<void*, void*> PnorAddrPair_t;
typedef std::map<PNOR::SectionId, PnorAddrPair_t> PnorAddrMap_t;

class RtPnor
{
    public:

      /**
       * @brief Static Initializer
       * @param[in] ref to errlHndl_t
       */
        static void init ( errlHndl_t &io_rtaskRetErrl );

      /**
       * @brief  Return the size and address of a given section
       *         of PNOR data at runtime
       *         Called by external PNOR::getSectionInfo()
       *
       * @param[in] i_section   PNOR section
       * @param[out] o_info     Location and size information
       *                        NOTE: vaddr is 0 if section is secure.
       *                              It should be loaded from Hb resv memory
       *
       * @return errlHndl_t     Error log if request was invalid
       */
        errlHndl_t getSectionInfo ( PNOR::SectionId i_section,
                                    PNOR::SectionInfo_t& o_info);

      /**
       * @brief  Writes the data back to PNOR of a given section
       *         of PNOR at runtime
       *         Called by external PNOR::flush()
       *
       * @param[in] i_section   PNOR section
       * @return errlHndl_t     Error log if request was invalid
       */
        errlHndl_t flush (PNOR::SectionId i_section);

      /**
       * @brief Returns information about a given side of pnor
       *        (Called by an external interface PNOR::getSideInfo())
       * @param[in]  i_side PNOR side
       * @param[out] o_info side information
       *
       * @return errlHndl_t Error log if request was invalid
       */
        errlHndl_t getSideInfo( PNOR::SideId i_side,
                                PNOR::SideInfo_t& o_info);

      /**
       * @brief  Clears the specified PNOR section with all FF's (w/ good ECC)
       *
       * @param[in] i_id  PNOR section to clear
       *
       * @return Error if fails
       */
        errlHndl_t clearSection(PNOR::SectionId i_section);

        /**
         * @brief Retrieve some information about the PNOR/SFC hardware
         *        In runtime, some of this information is from attributes.
         *
         * @param[out] o_pnorInfo Information about PNOR.
         */
        errlHndl_t getPnorInfo( PNOR::PnorInfo_t& o_pnorInfo );


        /**
         * @brief  Has RtPnor::init() successfully completed?
         * @return true if init() finished successfully, otherwise false
         */
        bool isPnorInitialized() { return iv_initialized; }

        /**
         * @brief  Accessor function for iv_initialized.
         *         true = RtPnor::init() finished successfully
         */
        void setInitialized(bool i_initialized);
#ifdef CONFIG_FILE_XFER_VIA_PLD
        /**
        * @brief Return a const ref to the iv_ipltime_lid std:array
        * @return a const ref to the iv_ipltime_lid member variable.
        */
        const std::array<uint32_t, PNOR::NUM_SECTIONS>& get_lid_ids() const
        {
            return this->iv_ipltime_lid_ids;
        }
#endif

    protected:
       /**
        * @brief Constructor
        */
        RtPnor();

       /**
        * @brief Destructor
        */
        ~RtPnor();

    private:
        /**
         * Cached copy of section data
         */
        PNOR::SectionData_t iv_TOC[PNOR::NUM_SECTIONS+1];
#ifdef CONFIG_FILE_XFER_VIA_PLDM
        std::array<uint32_t, PNOR::NUM_SECTIONS> iv_ipltime_lid_ids;
#endif
        /**
         * Keeps track of the data pointers for different sections in the PNOR
         */
        PnorAddrMap_t iv_pnorMap;

        /**
         * @brief  Reads data from the PNOR device
         *          and removes ecc if necessary
         *
         * @param[in] i_procId  processor id
         * @param[in] i_section section of the pnor to read from
         * @param[in] i_offset  offset into the pnor
         * @param[in] i_size    size of data to read in bytes
         * @param[in] i_ecc     true=verify and strip ECC after reading
         * @param[in] o_data    Buffer to copy data into
         *
         * @return Error from device
         */
         errlHndl_t readFromDevice (uint64_t i_procId,
                                   PNOR::SectionId i_section,
                                   uint64_t i_offset,
                                   size_t i_size,
                                   bool i_ecc,
                                   void* o_data) const;

      /**
        * @brief  Use Opal to read data from the PNOR device
        *         and remove ecc if necessary
        *
        * @param[in] i_procId  processor id
        * @param[in] i_section section of the pnor to read from
        * @param[in] i_offset  offset into the pnor
        * @param[in] i_size    size of data to read in bytes
        * @param[in] i_ecc     true=verify and strip ECC after reading
        * @param[in] o_data    Buffer to copy data into
        *
        * @return Error from device
        */
        errlHndl_t readFromDeviceOpal(uint64_t i_procId,
                                      PNOR::SectionId i_section,
                                      uint64_t i_offset,
                                      size_t i_size,
                                      bool i_ecc,
                                      void* o_data) const;

        /**
         * @brief  Write data back to the PNOR device
         *         and injects ecc if necessary
         *
         * @param[in] i_procId  processor id
         * @param[in] i_section section of the pnor to write to
         * @param[in] i_offset  offset into the pnor
         * @param[in] i_size    size of data to write in bytes
         * @param[in] i_ecc     true=apply ECC before writing
         * @param[in] i_src     Buffer to copy data from
         *
         * @return Error from device
         */
        errlHndl_t writeToDevice( uint64_t i_procId,
                                  PNOR::SectionId i_section,
                                  uint64_t i_offset,
                                  size_t i_size,
                                  bool i_ecc,
                                  void* i_src );

      /**
        * @brief  Use Opal to write data back to the PNOR device
        *         and inject ecc if necessary
        *
        * @param[in] i_procId  processor id
        * @param[in] i_section section of the pnor to write to
        * @param[in] i_offset  offset into the pnor
        * @param[in] i_size    size of data to write in bytes
        * @param[in] i_ecc     true=apply ECC before writing
        * @param[in] i_src     Buffer to copy data from
        *
        * @return Error from device
        */
        errlHndl_t writeToDeviceOpal(uint64_t i_procId,
                                    PNOR::SectionId i_section,
                                    uint64_t i_offset,
                                    size_t i_size,
                                    bool i_ecc,
                                    void* i_src);

        /**
         * @brief Verify both TOC's and store section information from one of
         *  the verified TOC's
         *
         * @return Error from device
         */
        errlHndl_t readTOC();

        /**
         * @brief Get processor id of master proc and cache in internal variable
         *
         * @return errlHndl_t - Error from runtime targeting call
         */
        errlHndl_t getMasterProcId();

        // Cached master Proc Id
        static uint64_t iv_masterProcId;

        // is RT pnor initialized?
        bool iv_initialized;

        //allow testcases to see inside the class
        friend class PnorRtTest;

        /**
         * @brief Static instance function for testcase only
         */
        static RtPnor& getInstance();
};

#endif
