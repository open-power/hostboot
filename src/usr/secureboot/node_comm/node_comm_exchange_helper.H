/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm_exchange_helper.H $    */
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
#ifndef __NODE_COMM_EXCHANGE_HELPER
#define __NODE_COMM_EXCHANGE_HELPER

/**
 * @file node_comm_exchange_helper.H
 * @brief Contains wrapper class that can be executed in parallel to drive the
 *        node exchange.
 */

#include "node_comm.H"

namespace SECUREBOOT
{

namespace NODECOMM
{

/**
 * @brief Performs the Phase 1 of multinode comm, where nodes exchange 8-byte
 *        random number (nonce) with their specific link information encoded
 *        into the first byte of the number.
 */
class NodeCommExchangeNonces
{
    protected:
        // @brief The information about this node's IOHS position and peer
        //        node's instance and its IOHS position.
        iohs_instances_t iv_iohsInstance;

    public:
        // @brief ThreadPool uses this function to do the actual work
        void operator()();

        // A constructor that takes an IOHS info structure
        NodeCommExchangeNonces(const iohs_instances_t& i_iohsInfo) :
            iv_iohsInstance(i_iohsInfo)
        {
        }

        // Delete copy constructor and assignment operator
        NodeCommExchangeNonces(const NodeCommExchangeNonces&) = delete;
        NodeCommExchangeNonces& operator=(const NodeCommExchangeNonces&) = delete;

}; // class NodeCommExchangeNonces

} // namespace NODECOMM

} // namespace SECUREBOOT

#endif
