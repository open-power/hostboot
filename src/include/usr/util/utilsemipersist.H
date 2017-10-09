/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utilsemipersist.H $                      */
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
#ifndef UTILSEMIPERSIST_H
#define UTILSEMIPERSIST_H

/**
 * @file utilsemipersist.H
 *
 * @brief Utilies to access the semi persistent memory
 *
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

// Utility Includes

/*****************************************************************************/
// Forwards
/*****************************************************************************/

//*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/
namespace Util
{
    enum
    {
        PERSIST_MAGIC           =       0x48425f56, // HB_V
        MFG_TERM_REBOOT_ENABLE  =       0x4d464754, // MFGT
    };

    struct semiPersistData_t
    {
        uint32_t magic;              //HB_V
        uint32_t reboot_cnt;         // Number of reboots with valid data
        uint32_t mfg_term_reboot;    // Manufacturing Terminate set for reboot
        semiPersistData_t(): magic(0), reboot_cnt(0) {};
    } PACKED;

    /**
     * @brief This function writes data structure to the HB semi persistent
     *  region.  Data is flushed to storage once this call returns
     * @param[in] i_data        Structure to write
     *
     * @return none
     */
    void writeSemiPersistData(const semiPersistData_t i_data);

    /**
     * @brief This function reads data structure from the HB semi persistent
     *  region.  If the region cannot be found it will return 0s for all data.
     *  User must check magic header to know if data is valid
     * @param[in] o_data        Structure to read
     *
     * @return none
     */
    void readSemiPersistData(semiPersistData_t & o_data);
};

#endif //UTILMEM_H
