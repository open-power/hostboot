/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmisel.H $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#ifndef __IPMI_IPMISEL_H
#define __IPMI_IPMISEL_H

/**
 * @file ipmisel.H
 * @brief IPMI system error log transport definition
 */

#include <stdint.h>
#include <builtins.h>
#include <ipmi/ipmiif.H>
#include "ipmibt.H"
#include <errl/errlentry.H>

/**
 *
 */

const uint8_t SEL_LENGTH = 16;
const uint8_t ESEL_META_LEN = 7;

struct selInitData
{
    uint8_t sel[SEL_LENGTH];
    uint8_t eSel[SEL_LENGTH];
    //2048 being the max length of an eSEL supported by AMI
    uint8_t eSelExtra[2048];
};

namespace IPMISEL
{
    void sendData(uint8_t* i_SEL, uint8_t* i_eSEL,
                  uint8_t* i_extraData, uint32_t i_dataSize);
    enum msg_type
    {
        MSG_SEND_SEL,
        MSG_STATE_SHUTDOWN,
        MSG_LAST_TYPE = MSG_STATE_SHUTDOWN,
    };
}


class IpmiSEL
{
    public:

      /**
       * Thread start routine for the resource provider
       * @param[in] void*, unused
       */
      static void* start(void* unused);

      /**
       * Default constructor
       */
      IpmiSEL(void);

      /**
       * Destructor
       */
      ~IpmiSEL(void);

      /**
       * @brief Get the message queue associated with this FRU
       * @param[in] void
       * @return, a msg_q_t which is the message queue
       */
      msg_q_t msgQueue(void)
          { return iv_msgQ; }

    private:
      /**
       * Entry point for the SEL transport definition
       */
      void execute(void);

      /**
       * @brief
       * @param[in] i_msg
       */
      void send_sel(msg_t *i_msg);

      msg_q_t           iv_msgQ;      //!< ipmi message queue

      //Disallow copying of this class.
      IpmiSEL& operator=(const IpmiSEL&);
      IpmiSEL(const IpmiSEL&);
};

#endif
