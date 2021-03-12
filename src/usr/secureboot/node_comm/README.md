# **'node\_comm'** Secureboot Services in Hostboot
This directory implements the Hostboot functions necessary to create a
 secure channel between nodes using a series of PAUC mailbox registers
 enabled after SMPA training but before the iovalid drop.
This secure channel is used in a multi-node evironment for nodes to exchange
 cryptographic material that can later be used for internode authentication
 higher up the firmware stack.

## Key Points
* This code implements device driver-like functionality to send messages
 across the SMPA connection from one node to another
  * This functionality is based on PAUC mailbox registers which are used to
 detect incoming messages, retrieve data, and send data messages to/from
 specific nodes
* This code establishes a primary node which then starts the process of exchanging
 information with each of the other secondary nodes (Version 1)
* The files are built into libnode_comm.so
* This module implements the interfaces defined in
 [nodecommif.H](../../../include/usr/secureboot/nodecommif.H)
* Two versions of exchange exist: single-threaded, and multi-threaded

## Version 1 Description
* In version 1, one node acts as a primary node and drives the exchange
* Each secondary node sends the secureboot information to the primary node
* The primary node has a full picture of the secureboot state on other nodes
* All exchanges are performed in series with the primary node driving the exchange

## Version 2 Description
* In version 2, each node compiles the complete secureboot set of information about
  all other nodes
* Each node performs both sides of exchange with each other node
* Each node has a full picture of the secureboot state on other nodes
* Different threads are spawned to communicate with other nodes such that each thread
  services this node's back-and-forth communication with one of its peers

## Algorithm
* First, each node does the following:
  * Determine the nodes in the system
  * Determine the primary processor of this node
  * Determine the SMPA connection to its peer nodes

## Version 1 (Single-Threaded)
* ***The Primary Node*** does the following
 (see node_comm_exchange.C's nodeCommExchangePrimary()):
  * **Loop 1:** Exchange SBID/nonces between Primary and each of the Secondary Nodes
    * Generate SBID/nonce and send to secondary node
    * Look for return SBID/nonce from the secondary
  * **Loop 2:** Primary Node requests quotes from each Secondary Node
    * Generate and send Quote Request to a secondary node
    * Look for Quote Response from the secondary node
    * Process the Quote Response that was returned from the secondary node
  * NOTE:
    * Nonces are encoded 8-bytes of data: part random number, part node ID
    * Quotes are a form of attestation between two TPMs on the system.  See
 TrustedComputingGroup.org's Trusted Platform Module Library Specification,
 Family "2.0" for more details.

* ***Each Secondary Node*** does the following
 (see node_comm_exchange.C's nodeCommExchangeSecondary()):

  * Wait for SBID/nonce from the primary node
  * Send a SBID/nonce back to the primary node
  * Wait for Quote Request from primary node
  * Generate the Quote Response
  * Send the Quote Response to the primary node

## Version 2 (Multi-Threaded)
* **Loop 1:** exchangeNoncesMultithreaded/NodeCommExchangeNonces
  * In each thread:
    * A node generates a nonce for each other node the system
    * Node with lower node ID (position) sends the generated nonce to its peer first
    * Node's peer (with higher node ID) waits for the nonce first
    * Once the first exchange is complete, the roles reverse (lower node waits for nonce)
    * Both the current node and peer's nonce are extended into TPM

* **Loop 2:** exchangeQuotesMultithreaded/NodeCommExchangeQuotes
  * The TPM log on the node is extended for each TPM
  * The TPM Attestation Keys/Certificate is pre-generated
  * In each thread:
    * Node with lower node ID (position) generates and sends quote request to its peer
    * Node's peer fetches the required info from TPM and compiles the quote
    * Original node waits for the quote; peer node sends the quote
    * Once the one-way exchange is completed, the roles reverse
  * The TPM AK/Certificate is flushed
  * All received quotes are extended into TPM

* NOTE: Generating the SBID/Nonces, Quote Requests, and Quote Responses above
 all require interacting with the TPMs on the different nodes in specific
 ways
  * The devil is truly in the details, and the details can be found in the
 supporting functions of node_comm_exchange.C

## Files

* __makefile__
  * Standard Hostboot makefile

* __node_comm.C, node_comm.H__
  * The majority of the sub-functions used to implement the algorithm are
 defined and implemented here, including the SMPA mapping details between
 the nodes

* __node_comm_dd.C, node_comm_dd.H__
  * Defines and implements the "NODECOMM" device driver that interacts directly
 with the PAUC mailbox registers

* __node_comm_exchange.C__
  * The core of this module - the primary function nodeCommExchange()
 is implemented here and shows the high-level data flow between the nodes
  * The procedure for the primary node is defined in nodeCommExchangePrimary()
  * The procedure for the secondary nodes is defiend in nodeCommExchangeSecondary()
  * The interactions with the TPM - generating and logging SBID/Nonces, Quote
 Requests, Quote Responses - are all in this file

* __node_comm_test.C__
  * Implements the proof-of-concept "nodeCommXbus2ProcTest" test to transfer
 data across the x-bus between processors using a similar method to the a-bus
 mechanism

* __node_comm_transfer.C, node_comm_transfer.H__
  * Defines and implements the different types of messages that can be sent
 between the nodes, including the actual send and receive functions

* __node_comm_exchange_helper.C, node_comm_exchange_helper.H__
  * Defines and implements classes that perform the multithreaded node exchange via
 operator()
  * Contains various helper functions and error handling logic for multithreaded
 exchange

* __[README.md](./README.md)__
  * This file

