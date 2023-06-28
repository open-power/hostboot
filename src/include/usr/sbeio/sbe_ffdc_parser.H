/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbe_ffdc_parser.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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

#ifndef __SBEFFDC_H
#define __SBEFFDC_H

#include <xscom/piberror.H>
#include <memory>
#include <vector>
/**
 * @file sbe_ffdc_parser.H
 * @brief SBE FFDC package parser
 */


namespace SBEIO
{

/*
 * @brief Type to hold the ffdc package and other useful data from the package header.
*/
struct ffdc_package
{
    void         * ffdcPtr;
    uint32_t       rc; // SBE Return code
    size_t         size; // number of FFDC data words
    // Odyssey SBE uses this to aggregate data across many packages into the same PEL
    // For P10, this will always be zero since those SBE packages do not have this field and should be ignored.
    // SLID == 0 is considered invalid.
    uint16_t       slid; // SBE Log Id
    // Odyssey SBE uses this field. Maps to fapi2::errlSeverity_t which is a subset of ERRORLOG::errlSeverity_t
    // For P10, this will always be ERRL_SEV_UNRECOVERABLE since those SBE packages do not have this field and
    // historically that was the only severity used.
    ERRORLOG::errlSeverity_t severity;

    ffdc_package() : ffdcPtr(nullptr), rc(0), size(0), slid(0), severity(ERRORLOG::ERRL_SEV_UNRECOVERABLE)
    { };

    ~ffdc_package() { };

};

class SbeFFDCParser
{
    public:

        /**
         * @brief Constructor
         */
        SbeFFDCParser() = default;

        /**
         * @brief Destructor
         */
        ~SbeFFDCParser();

        /**
         * @brief constants to keep track while parsing
         */
        // The minimum size an FFDC package can be for P10 chips, in words (per spec).
        // Includes the first FFDC data word.
        static constexpr uint8_t  MIN_FFDC_PACKAGE_WORD_SIZE = 4;
        // The minimum size an FFDC package can be for Odyssey chips, in words (per spec).
        // Includes the first FFDC data word.
        static constexpr uint8_t  MIN_FFDC_PACKAGE_WORD_SIZE_ODYSSEY = 5;

        // The header size of a P10 SBE FFDC Package in bytes.
        static constexpr uint8_t  HEADER_SIZE_IN_BYTES = (MIN_FFDC_PACKAGE_WORD_SIZE - 1) * sizeof(uint32_t);
        // The header size of an Odyssey FFDC Package in bytes.
        static constexpr uint8_t  HEADER_SIZE_IN_BYTES_ODYSSEY = (MIN_FFDC_PACKAGE_WORD_SIZE_ODYSSEY - 1)
                                                               * sizeof(uint32_t);
        // Offset to the SBE Log Id in an Odyssey FFDC Package. Word 2 of header
        static constexpr uint8_t SLID_OFFSET = 2 * sizeof(uint32_t);

        /**
         * @brief Parses the FFDC data package
         *  @param[in]  i_ffdcPackageBuffer Memory buffer contains FFDC package
         *
         */
        void parseFFDCData(void * i_ffdcPackageBuffer);

        /**
         * @brief Returns number of FFDC packages found
         *  @retval: number of FFDC packages found
         */
        size_t getTotalPackages();

        /**
         * @brief Get the raw ffdc package stored
         *  @retval: return pointer to raw ffdc package
         *  @param[in]  i_index  index number
         */
        void * getFFDCPackage(size_t i_index);

        /**
         * @brief Get the raw ffdc package stored
         *  @retval: True if an ffdc package is stored at index, else false.
         *  @param[in]  i_index  index number
         *  @param[out] o_package The package structure to fill.
         */
        bool getFFDCPackage(size_t i_index, ffdc_package& o_package);

        /**
         * @brief Get the return code of the package
         *  @retval: return code of the ffdc package
         *  @param[in]  i_index  index number
         */
        uint32_t getPackageRC(size_t i_index);

        /**
         * @brief Returns the size of a ffdc package (bytes)
         *  @retval: length of data stored
         *  @param[in]  i_index  index number
         */
        uint32_t getPackageLength(size_t i_index);


        /*
         * @brief Returns the SBE log id from the FFDC package at the given index.
         */
        uint16_t getPackageSlid(size_t i_index);

        /*
         * @brief Returns the errlSeverity_t from the FFDC package at the given index.
         */
        ERRORLOG::errlSeverity_t getPackageSeverity(size_t i_index);

        /**
         * @brief: converts fapi2 rc to pib rc
         * @param[in]: i_index index in the ffdc package
         */
        PIB::PibError getPibRc (size_t i_index);
    private:
        /**
         * @brief List of ffdc packages
         */
        std::vector<std::unique_ptr<ffdc_package>> iv_ffdcPackages;

        inline bool isIndexValid(const size_t i_index)
        {
            return (i_index >= 0) && (i_index < getTotalPackages());
        };

        /*
         * @brief Converts a uint8_t from an FFDC package into ERRORLOG::errlSeverity_t. If the conversion cannot be
         *        done then the return will be ERRL_SEV_UNRECOVERABLE.
         *
         * @param[in]  i_sev  The severity value to convert.
         *
         * @return ERRORLOG::errlSeverity_t
         */
        ERRORLOG::errlSeverity_t setSeverity(uint8_t i_sev);

        /**
         * @brief Store the data words found in FFDC package
         *  @param[in]  i_ffdcPackage   FFDC package to store
         *  @param[in]  i_rc            the RC word
         *  @param[in]  i_packageLen    length of package
         *  @param[in]  i_slid          SBE Log Id. For P10, 0 as it does not exist.
         *  @param[in]  i_sev           fapi2::errlSeverity from FFDC package. For P10, does not exist.
         */

        void addFFDCPackage(void * i_ffdcPackage,
                            uint32_t i_rc,
                            uint32_t i_packageLen,
                            uint16_t i_slid,
                            uint8_t  i_sev);

};

}

#endif
