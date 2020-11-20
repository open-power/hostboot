/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbe_ffdc_parser.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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

/**
 * @file sbe_ffdc_parser.H
 * @brief SBE FFDC package parser
 */


namespace SBEIO
{

/*
 * @brief Type to hold the ffdc package
 * This struct also holds the RC and the
 * size, in bytes, of the ffdc package
*/
struct ffdc_package
{
    void * ffdcPtr;
    uint32_t rc;
    size_t size;
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
         * @brief Parses the FFDC data package
         *  @param[in]  i_ffdcPackageBuffer Memory buffer contains FFDC package
         *
         */
        void parseFFDCData(void * i_ffdcPackageBuffer);

        /**
         * @brief Returns number of FFDC packages found
         *  @retval: number of FFDC packages found
         */
        uint8_t getTotalPackages();

        /**
         * @brief Get the raw ffdc package stored
         *  @retval: return pointer to raw ffdc package
         *  @param[in]  i_index  index number
         */
        void * getFFDCPackage(uint8_t i_index);

        /**
         * @brief Get the raw ffdc package stored
         *  @retval: True if an ffdc package is stored at index, else false.
         *  @param[in]  i_index  index number
         *  @param[out] o_package The package structure to fill.
         */
        bool getFFDCPackage(uint8_t i_index, ffdc_package& o_package);

        /**
         * @brief Get the return code of the package
         *  @retval: return code of the ffdc package
         *  @param[in]  i_index  index number
         */
        uint32_t getPackageRC(uint8_t i_index);

        /**
         * @brief Returns the size of a ffdc package (bytes)
         *  @retval: length of data stored
         *  @param[in]  i_index  index number
         */
        uint32_t getPackageLength(uint8_t i_index);

        /**
         * @brief: converts fapi2 rc to pib rc
         * @param[in]: i_index index in the ffdc package
         */
        PIB::PibError getPibRc (uint8_t i_index);
    private:

        /**
         * @brief List of ffdc packages
         */
        std::vector<ffdc_package *> iv_ffdcPackages;

        /**
         * @brief constants to keep track while parsing
         */
        const uint16_t iv_ffdcMagicByte = 0xFFDC;
        const uint8_t iv_ffdcWordLen = 4;
        const uint8_t iv_headerWordInBytes = iv_ffdcWordLen * 2;
        const uint8_t iv_ffdcPackageSize = 2;

        /**
         * @brief Store the data words found in FFDC package
         *  @param[in]  i_ffdcPackage   FFDC package to store
         *  @param[in]  i_rc            the RC word
         *  @param[in]  i_packageLen    length of package
         */

        void addFFDCPackage(void * i_ffdcPackage, uint32_t i_rc,
                            uint32_t i_packageLen);

};

}

#endif
