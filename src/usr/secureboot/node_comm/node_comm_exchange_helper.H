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
#include <isteps/hwpisteperror.H>
#include <sys/sync.h>

namespace SECUREBOOT
{

namespace NODECOMM
{

/**
 * @brief Structure to hold the node quote information. quoteData
 *        is the node quote in binary form; quoteSize is the size
 *        of the quote in bytes.
 */
typedef struct
{
    uint8_t* quoteData = nullptr;
    size_t quoteSize = 0;
} quoteInfo_t;

/**
 * @brief Virtual base class for multithreaded node comm exchange.
 */
class NodeCommExchange
{
    protected:
        // @brief Mutex to protect istep error from being accessed by different
        //        threads at the same time
        static mutex_t iv_errorMutex;

        // @brief The information about this node's IOHS position and peer
        //        node's instance and its IOHS position.
        iohs_instances_t iv_iohsInstance;

        // @brief Istep error to report back if the exchange fails
        ISTEP_ERROR::IStepError* iv_istepError;

        // @brief Handle the input error safely
        //
        // @param[in] i_errl error to handle
        void handleError(errlHndl_t i_errl);

    public:
        // @brief ThreadPool uses this function to do the actual work
        virtual void operator()() = 0;

        // @brief default destructor
        virtual ~NodeCommExchange()
        {
        }

        // A constructor that takes an IOHS info structure and an istep
        // error structure
        NodeCommExchange(const iohs_instances_t& i_iohsInfo,
                         ISTEP_ERROR::IStepError& i_istepError) :
            iv_iohsInstance(i_iohsInfo), iv_istepError(&i_istepError)
        {
        }

        // Delete copy constructor and assignment operator
        NodeCommExchange(const NodeCommExchange&) = delete;
        NodeCommExchange& operator=(const NodeCommExchange&) = delete;
};

/**
 * @brief Performs the Phase 1 of multinode comm, where nodes exchange an 8-byte
 *        random number (nonce) with their specific link information encoded
 *        into the first byte of the number.
 */
class NodeCommExchangeNonces : public NodeCommExchange
{
    public:
        // @brief ThreadPool uses this function to do the actual work
        void operator()();

        // A constructor that takes an IOHS info structure and an istep
        // error structure
        NodeCommExchangeNonces(const iohs_instances_t& i_iohsInfo,
                               ISTEP_ERROR::IStepError& i_istepError) :
            NodeCommExchange(i_iohsInfo, i_istepError)
        {
        }

        // Delete copy constructor and assignment operator
        NodeCommExchangeNonces(const NodeCommExchangeNonces&) = delete;
        NodeCommExchangeNonces& operator=(const NodeCommExchangeNonces&) = delete;

}; // class NodeCommExchangeNonces

/**
 * @brief Performs the Phase 2 of multinode comm, where nodes exchange binary
 *        blobs containing secureboot information (TPM PCR contents, TPM attestation
 *        keys, TPM logs, etc.).
 */
class NodeCommExchangeQuotes : public NodeCommExchange
{
    protected:
        // @brief A vector of quotes received from the other nodes. All quotes
        // in this vector are extended to TPM at the end of multinode exchange.
        std::vector<quoteInfo_t>* iv_quotes;

        // @brief A mutex to protect multithreaded additions to the quote vector.
        static mutex_t iv_quoteMutex;

    public:
        // @brief ThreadPool uses this function to do the actual work
        void operator()();

        // A constructor that takes an IOHS info structure, a pointer to a
        // vector of quotes from all of the nodes, and an istep error structure
        NodeCommExchangeQuotes(const iohs_instances_t& i_iohsInfo,
                               std::vector<quoteInfo_t>* i_quoteVector,
                               ISTEP_ERROR::IStepError& i_istepError) :
            NodeCommExchange(i_iohsInfo, i_istepError), iv_quotes(i_quoteVector)
        {
            iv_quotes->clear();
        }

        // Delete copy constructor and assignment operator
        NodeCommExchangeQuotes(const NodeCommExchangeQuotes&) = delete;
        NodeCommExchangeQuotes& operator=(const NodeCommExchangeQuotes&) = delete;

}; // class NodeCommExchangeQuotes

} // namespace NODECOMM

} // namespace SECUREBOOT

#endif
