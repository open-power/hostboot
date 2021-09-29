/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_fr.H $                                 */
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
/**
 * @file pldm_fr.H
 *
 * @brief Declares the pldmFR singleton class which manages
 *        pldm message flight recorders used for debug.
 */

#ifndef PLDMFR_H
#define PLDMFR_H

#include <openbmc/pldm/libpldm/base.h>

#define FLIGHT_RECORDER_MAX 250
enum traffic_direction : uint8_t;

/* PLDM Responses have a 1-byte completion code following
   the standard pldm_msg_hdr. We will store this completion_code
   in the response pldm flight recorders. */
struct pldm_rsp_hdr {
    pldm_msg_hdr hdr;
    uint8_t completion_code;
} __attribute__((packed));

class pldmFR
{
    public:
        /* Constructor */
        pldmFR(void);

        /**
        * @brief Log a given PLDM message in the appropriate PLDM flight recorder log
        *        based upon the information in the header of the PLDM message and
        *        the direction parameter.
        *
        * @param[in] i_hdr A ptr to a PLDM message, no change of memory ownership.
        * @param[in] i_dir The direction of the PLDM message:
        *                   - INBOUND if message is coming from the BMC.
        *                   - OUTBOUND if message is going to the BMC
        */
        void logMsg(const pldm_msg_hdr* const& i_hdr, PLDM::traffic_direction& i_dir);

    private:
        /* Max number of "flights" we will record in each flight recorder array*/
        size_t iv_frMax;
        /* Record of HB->BMC PLDM requests */
        pldm_msg_hdr iv_outReq_fr[FLIGHT_RECORDER_MAX];
        /* The next index to use in the outbound request flight recorder */
        size_t iv_outReq_fr_index;
        /* Record of BMC->HB PLDM requests */
        pldm_msg_hdr iv_inReq_fr[FLIGHT_RECORDER_MAX];
        /* The next index to use in the inbound request flight recorder */
        size_t iv_inReq_fr_index;

        /* Record of HB->BMC PLDM responses */
        pldm_rsp_hdr iv_outRsp_fr[FLIGHT_RECORDER_MAX];
        /* The next index to use in the outbound response flight recorder */
        size_t iv_outRsp_fr_index;
        /* Record of BMC->HB PLDM responses */
        pldm_rsp_hdr iv_inRsp_fr[FLIGHT_RECORDER_MAX];
        /* The next index to use in the inbound response flight recorder */
        size_t iv_inRsp_fr_index;

        /* Disallow copying this class. */
        pldmFR& operator=(const pldmFR&);
        pldmFR(const pldmFR&);
};

#endif /*PLDMFR_H*/