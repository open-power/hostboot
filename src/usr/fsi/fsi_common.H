/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/fsi_common.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#ifndef FSI_COMMON_H
#define FSI_COMMON_H

#include <fsi/fsiif.H>

namespace FSI{

    /**
     * FSI Address Space
     */
    enum FsiAddressSpace {
        // Master control registers
        CMFSI_CONTROL_REG = 0x003000, /**< cMFSI Control Register */
        MFSI_CONTROL_REG  = 0x003400, /**< MFSI Control Register */

        // cMFSI Ports  (32KB each)
        CMFSI_PORT_0      = 0x040000, /**< cMFSI port 0 */
        CMFSI_PORT_1      = 0x048000, /**< cMFSI port 1 */
        CMFSI_PORT_2      = 0x050000, /**< cMFSI port 2 */
        CMFSI_PORT_3      = 0x058000, /**< cMFSI port 3 */
        CMFSI_PORT_4      = 0x060000, /**< cMFSI port 4 */
        CMFSI_PORT_5      = 0x068000, /**< cMFSI port 5 */
        CMFSI_PORT_6      = 0x070000, /**< cMFSI port 6 */
        CMFSI_PORT_7      = 0x078000, /**< cMFSI port 7 */
        CMFSI_PORT_MASK   = 0x078000,
                 /**< Mask to look for a valid cMFSI port */

        // Offsets to cascaded slaves within a cMFSI port
        CMFSI_SLAVE_0     = 0x000000, /**< cMFSI - Slave 0 */
        CMFSI_SLAVE_1     = 0x002000, /**< cMFSI - Slave 1 */
        CMFSI_SLAVE_2     = 0x004000, /**< cMFSI - Slave 2 */
        CMFSI_SLAVE_3     = 0x006000, /**< cMFSI - Slave 3 */

        // MFSI Ports  (512KB each)
        MFSI_PORT_LOCAL   = 0x000000, /**< Local master (for local cMFSI) */
        MFSI_PORT_0       = 0x080000, /**< MFSI port 0 */
        MFSI_PORT_1       = 0x100000, /**< MFSI port 1 */
        MFSI_PORT_2       = 0x180000, /**< MFSI port 2 */
        MFSI_PORT_3       = 0x200000, /**< MFSI port 3 */
        MFSI_PORT_4       = 0x280000, /**< MFSI port 4 */
        MFSI_PORT_5       = 0x300000, /**< MFSI port 5 */
        MFSI_PORT_6       = 0x380000, /**< MFSI port 6 */
        MFSI_PORT_7       = 0x400000, /**< MFSI port 7 */
        MFSI_PORT_MASK    = 0x780000,
                 /**< Mask to look for a valid MFSI port */

        // Offsets to cascaded slaves within a MFSI port
        MFSI_SLAVE_0      = 0x000000, /**< MFSI - Slave 0 */
        MFSI_SLAVE_1      = 0x020000, /**< MFSI - Slave 1 */
        MFSI_SLAVE_2      = 0x040000, /**< MFSI - Slave 2 */
        MFSI_SLAVE_3      = 0x060000, /**< MFSI - Slave 3 */
    };

    /**
     * Common id to identify a FSI position to use in error logs and traces
     */
    union FsiLinkId_t
    {
        uint32_t id;
        struct
        {
            uint8_t node; ///< Physical Node of FSI Master processor
            uint8_t proc; ///< Physical Position of FSI Master processor
            uint8_t type; ///< FSI Master type (FSI_MASTER_TYPE)
            uint8_t port; ///< Slave link/port number
        };
    };

    /**
     * @brief Structure which defines info necessary to access a chip via FSI
     */
    struct FsiChipInfo_t
    {
        TARGETING::Target* slave; //< FSI Slave chip
        TARGETING::Target* master; ///< FSI Master
        TARGETING::FSI_MASTER_TYPE type; ///< Master or Cascaded Master
        uint8_t port; ///< Which port is this chip hanging off of
        uint8_t cascade; ///< Slave cascade position
        union {
            TARGETING::FsiOptionFlags flagbits; ///< Special flags
            uint16_t flags; ///< Special flags
        };
        FsiLinkId_t linkid; ///< Id for traces and error logs

        FsiChipInfo_t() :
          slave(NULL), master(NULL),
        type(TARGETING::FSI_MASTER_TYPE_NO_MASTER),
        port(UINT8_MAX), cascade(0), flags(0)
        { linkid.id = 0; };
    };

    /**
     * @brief Holds a set of addressing information to describe the
     *   current FSI operation
     */
    struct FsiAddrInfo_t {
        TARGETING::Target* fsiTarg; ///< Target of FSI operation
        TARGETING::Target* opbTarg; ///< OPB control reg target
        uint32_t relAddr; ///< Input FSI address (relative to fsiTarg)
        uint32_t absAddr; ///< Absolute FSI address (relative to opbTarg)
        FsiChipInfo_t accessInfo; ///< FSI Access Info

        /** Input Arg Constructor */
        FsiAddrInfo_t( TARGETING::Target* i_target,
                       uint64_t i_address ) :
          fsiTarg(i_target), opbTarg(NULL),
        relAddr(i_address), absAddr(UINT32_MAX)
        {};

      private:
        /** Default Constructor is not allowed */
        FsiAddrInfo_t() :
          fsiTarg(NULL), opbTarg(NULL),
        relAddr(UINT32_MAX),absAddr(UINT32_MAX)
        {};
    };

    /**
     * @brief Convert a type/port pair into a FSI address offset
     *
     * @param[in] i_type  Type of FSI interface
     * @param[in] i_port  FSI link number
     * @return uint64_t  FSI address offset
     */
    uint64_t getPortOffset(TARGETING::FSI_MASTER_TYPE i_type,
                           uint8_t i_port);
}



#endif
