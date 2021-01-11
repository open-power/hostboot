# **'node\_comm'** Secureboot Services in Hostboot
This directory implements the Hostboot functions necessary to create a
 secure channel between nodes using a series of a-bus mailbox registers
 enabled after a-bus training but before the iovalid drop.
This secure channel is used in a multi-node evironment for nodes to exchange
 cryptographic material that can later be used for internode authentication
 higher up the firmware stack.

## Key Points
* This code implements device driver-like functionality to send messages
 across the a-bus connection from one node to another
  * This functionality is based on a-bus mailbox registers which are used to
 detect incoming messages, retrieve data, and send data messages to/from
 specific nodes
* This code establishes a master node which then starts the process of exchanging
 information with each of the other slave nodes
* The files are built into libnode_comm.so
* This module implements the interfaces defined in
 [nodecommif.H](../../../include/usr/secureboot/nodecommif.H)

## Algorithm
* First, each node does the following:
  * Determine the nodes in the system
  * Determine the master processor of this node
  * Determine the a-bus connection to its master processor peers on the
 other nodes

* ***The Master Processor on Master Node*** does the following
 (see node_comm_exchange.C's nodeCommExchangeMaster()):
  * **Loop 1:** Exchange SBID/nonces between Master and each of the Slave Nodes
    * Generate SBID/nonce and send to slave node
    * Look for return SBID/nonce from the slave
  * **Loop 2:** Master Node requests quotes from each Slave Node
    * Generate and send Quote Request to a slave
    * Look for Quote Response from the slave node
    * Process the Quote Response that was returned from the slave node
  * NOTE:
    * Nonces are encoded 64-bytes of data: part random number, part node ID
    * Quotes are a form of attestation between two TPMs on the system.  See
 TrustedComputingGroup.org's Trusted Platform Module Library Specification,
 Family "2.0" for more details.

* ***The Master Processor on each Slave Node*** does the following
 (see node_comm_exchange.C's nodeCommExchangeSlave()):

  * Wait for SBID/nonce from the master node
  * Send a SBID/nonce back to the master node
  * Wait for Quote Request from master node
  * Generate the Quote Response
  * Send the Quote Response to the master node


* NOTE: Generating the SBID/Nonces, Quote Requests, and Quote Responses above
 all require interacting with the TPMs on the different nodes in specific
 ways
  * The devil is truly in the details, and the details can be found in the
 supporting functions of node_comm_exchange.C
* NOTE: In the event that one node fails in this process there will be an
 attempt to poison the TPMs on that node and move on in most cases.  This is
 to prevent an entire system from failing to boot with one bad node.

## Files

* __makefile__
  * Standard Hostboot makefile

* __node_comm.C, node_comm.H__
  * The majority of the sub-functions used to implement the algorithm are
 defined and implemented here, including the a-bus mapping details between
 the nodes

* __node_comm_dd.C, node_comm_dd.H__
  * Defines and implements the "NODECOMM" device driver that interacts directly
 with the a-bus mailbox registers

* __node_comm_exchange.C__
  * The core of this module - the primary function nodeCommExchange()
 is implemented here and shows the high-level data flow between the nodes
  * The procedure for the master node is defined in nodeCommExchangeMaster()
  * The procedure for the slave nodes is defiend in nodeCommExchangeSlave()
  * The interactions with the TPM - generating and logging SBID/Nonces, Quote
 Requests, Quote Responses - are all in this file

* __node_comm_test.C__
  * Implements the proof-of-concept "nodeCommXbus2ProcTest" test to transfer
 data across the x-bus between processors using a similar method to the a-bus
 mechanism

* __node_comm_transfer.C, node_comm_transfer.H__
  * Defines and implements the different types of messages that can be sent
 between the nodes, including the actual send and receive functions

* __[README.md](./README.md)__
  * This file

