/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/progressSrc.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#ifndef PROGRESS_SRC_H
#define PROGRESS_SRC_H

/**
 *  @file progressSrc.H
 *
 *  @brief Manage the data that makes up a System Reference Code, or SRC, that
 *  is used for sending system progress code.
 *  Progress codes (or checkpoints) offer information about the stages involved
 *  in powering on and performing initial program load (IPL).
 *
 */

#include <stdint.h>
#include <errl/errlentry.H>

namespace INITSERVICE
{

/**
 * @brief - Progress Code structure
 *
 * Data Structure Details
 * ------------------------------
 *  bits: field name
 *  8: srcitype     - Determines the type of SRC to build.
 *
 *  4: nodeID         - Physical drawer ordinal ID
 *  4: rollingCounter - Rolling counter value for each major/minor step
 *
 *  16-bit IPL reasonCode
 *  4: iplCompID    - Component ID for HB, FSP progress
 *  1: unused1
 *  5: majorNo      - IPL Istep major number
 *  1: unused2
 *  5: minorNo      - IPL Istep minor number
 */
struct ProgressCode
{
    union{
        struct {
            uint8_t srcitype;  // 'CC' = Hostboot IPL Progress code

            union{
                struct
                {
                    uint8_t nodeID : 4 ;
                    //Rolling counter will be set while catering for Multinode.
                    uint8_t rollingCounter : 4;
                };
                uint8_t moduleID;
            };

            union{
                //IPL Reason code
                struct
                {
                    uint16_t iplCompID : 4;
                    uint16_t unused1   : 1;
                    uint16_t majorNo   : 5;
                    uint16_t unused2   : 1;
                    uint16_t minorNo   : 5;
                 };
                 uint16_t reasonCode;
            };
        };
        uint32_t progress_code;
    };
} __attribute__((packed));

/**
 *  @class ProgressCodeSrc
 *  @brief Contains the data to output a progress code SRC
 */
class ProgressCodeSrc
{
public:

    /**
     * @brief Constructor.  Pass in items destined for the progress code SRC
     *
     * @param[in]  i_major_istep   major number of istep
     * @param[in]  i_minor_istep   minor number of istep
     * @param[in]  i_rolling_count rolling count of major/minor progress codes
     *
     */
    ProgressCodeSrc( uint8_t i_major_istep,
                     uint8_t i_minor_istep,
                     uint8_t i_rolling_count );

    /**
     *  @brief Data export facility to flatten data
     *         Flattened data will be in ERRORLOG::SrcSection_t format
     *
     *  @param[out] o_pBuffer  Pointer to buffer where flattened data will go.
     *  @param[in]  i_cbBuffer  Count of bytes in target buffer
     *  @return number of bytes filled in buffer
     */
    uint64_t flatten( void * o_pBuffer, const uint64_t i_cbBuffer );

    /**
     *  @brief Data export size of the full flattened SRC.
     *  This is the amount of flat storage (in bytes) required to
     *  store the object. (currently 72 bytes)
     *
     *  @return  Size in bytes.
     */
    uint64_t flatSize() const;


#ifdef CONFIG_PLDM
    /**
     * @brief Send this progress code src down to the BMC via PLDM command
     *        This also updates ATTR_LAST_PROGRESS_CODE with the 4-byte progress code
     *        being sent down to the BMC inside the SRC.
     * @return error handle if BMC send failed
     */
    errlHndl_t sendProgressCodeToBmc();
#endif

private:
    ProgressCode iv_progressCode;
};


} // end namespace INITSERVICE
#endif
