/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/fsidd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2017                        */
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
#ifndef __FSI_FSIDD_H
#define __FSI_FSIDD_H

#include <sys/sync.h>
#include <util/locked/list.H>
#include <list>
#include <errl/errlentry.H>
#include <usr/devicefw/driverif.H>
#include <attributestructs.H>
#include <sys/task.h>
#include <usr/fsi/fsiif.H>
#include <usr/fsi/fsi_reasoncodes.H>
#include <map>
#include "fsi_common.H"

namespace FSI { class UdPresence; }

/** @file fsidd.H
 *  @brief Provides the definition of the FSI Device Driver class
 */

/**
 * Class to handle the FSI Master operations
 *   there will be a single instance within hostboot
 */
class FsiDD
{
  public:

    /**
     * @brief Initialize the FSI hardware
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initializeHardware();

    /**
     * @brief Performs an FSI Read Operation
     *
     * @param[in] i_target  Chip target of FSI operation
     * @param[in] i_address  Address to read (relative to target)
     * @param[out] o_buffer  Destination buffer for data
     * @parm[in]  i_buflen   Length of data to read in bytes
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t read(TARGETING::Target* i_target,
                    uint64_t i_address,
                    uint32_t* o_buffer,
                    size_t  i_buflen = 4);

    /**
     * @brief Performs an FSI Write Operation
     *
     * @param[in] i_target  Chip target of FSI operation
     * @param[in] i_address  Address to write (relative to target)
     * @param[out] i_buffer  Source buffer for data
     * @parm[in]  i_buflen   Length of data to write in bytes
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t write(TARGETING::Target* i_target,
                     uint64_t i_address,
                     uint32_t* i_buffer,
                     size_t  i_buflen = 4);


    /**
     * @brief Retrieves the status of a given port
     *
     * @param[in] i_fsiMaster  FSI Master chip
     * @param[in] i_type  FSI Master Type (MFSI or cMFSI)
     * @param[in] i_port  Slave port number
     * @param[out] o_detected  Bitstring of detected slaves
     *
     * @return bool  true if port sensed as active during FSI initialization
     */
    bool isSlavePresent( TARGETING::Target* i_fsiMaster,
                         TARGETING::FSI_MASTER_TYPE i_type,
                         uint8_t i_port,
                         uint8_t& o_detected );

    /**
     * @brief Retrieves the FSI status of a given chip
     *
     * @param[in] i_target
     * @param[out] o_detected  Bitstring of detected slaves
     *
     * @return bool  true if port sensed as active during FSI initialization
     */
    bool isSlavePresent( TARGETING::Target* i_target,
                         uint8_t& o_detected  );

    /**
     * @brief Add FFDC for the target to an error log
     *
     * @param[in] i_ffdc_type   Type of FFDC to add
     * @param[in,out] io_log   Error Log to add FFDC to
     * @param[in] i_target     Chip Target, for OPB_FAIL this should
     *    be the FSI Master, otherwise it should be the target of
     *    the FSI operation (i.e. the FSI Slave)
     *
     * @return void
     */
    void getFsiFFDC( FSI::fsiFFDCType_t  i_ffdc_type,
                     errlHndl_t          &io_log,
                     TARGETING::Target*  i_target );

    /**
     * @brief Cleanup the FSI PIB2OPB logic on the procs
     *
     * @param[in] i_target  Proc Chip Target to reset
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t resetPib2Opb( TARGETING::Target* i_target );

    /**
     * @brief Retrieve some FSI attribute information
     *
     * @param[in] i_slave  Slave Chip Target to query
     * @param[out] o_info  FSI Link Information
     */
    void getFsiLinkInfo( TARGETING::Target* i_slave,
                         FSI::FsiLinkInfo_t& o_info );


  protected:
    /**
     * @brief Constructor
     */
    FsiDD();


    /**
     * @brief Destructor
     */
    ~FsiDD();

    /**
     * @brief Performs an FSI Read Operation to an absolute address
     *   using the master processor chip to drive it
     *
     * @param[in] i_address  Absolute FSI address to read relative to
     *     the OPB master processor chip
     * @param[out] o_buffer  Destination buffer for data
     * @parm[in]  i_buflen   Length of data to read in bytes
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t read(uint64_t i_address,
                    uint32_t* o_buffer,
                    size_t  i_buflen = 4);

    /**
     * @brief Performs an FSI Write Operation to an absolute address
     *   using the master processor chip to drive it
     *
     * @param[in] i_address  Absolute FSI address to write relative to
     *     the OPB master processor chip
     * @param[out] i_buffer  Source buffer for data
     * @parm[in]  i_buflen   Length of data to write in bytes
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t write(uint64_t i_address,
                     uint32_t* i_buffer,
                     size_t  i_buflen = 4);

    /**
     * @brief Performs an FSI Read Operation
     *
     * @param[in] i_addrInfo  Addressing information
     * @param[out] o_buffer  Destination buffer for data
     * @parm[in]  i_buflen   Length of data to read in bytes
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t read(FSI::FsiAddrInfo_t& i_addrInfo,
                    uint32_t* o_buffer,
                    size_t  i_buflen = 4);

    /**
     * @brief Performs an FSI Write Operation to an absolute address
     *
     * @param[in] i_addrInfo  Addressing information
     * @param[out] i_buffer  Source buffer for data
     * @parm[in]  i_buflen   Length of data to write in bytes
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t write(FSI::FsiAddrInfo_t& i_addrInfo,
                     uint32_t* i_buffer,
                     size_t  i_buflen = 4);

    /**
     * @brief Initializes the FSI master control registers
     *
     * @param[in] i_master  Target of FSI master chip to initialize
     * @param[in] i_type  Type of FSI interface
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initMasterControl(TARGETING::Target* i_master,
                                 TARGETING::FSI_MASTER_TYPE i_type);

    /**
     * @brief Initializes the FSI link to allow slave access
     *
     * @param[in] i_fsiInfo  FSI Chip Information for the slave port
     *    that is being initialized
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initPort(FSI::FsiChipInfo_t i_fsiInfo,
                        bool& o_enabled);

    /**
     * @brief Analyze error bits and recover hardware as needed
     *
     * @param[in] i_addrInfo  FSI addressing information
     * @param[in] i_opbStatAddr  OPB Status Register Address
     * @param[in] i_opbStatData  OPB Status bits (OPB_REG_STAT[0:31])
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t handleOpbErrors(FSI::FsiAddrInfo_t& i_addrInfo,
                               uint32_t i_opbStatAddr,
                               uint32_t i_opbStatData);

    /**
     * @brief  Poll for completion of a FSI operation, return data on read
     *
     * @param[in] i_addrInfo  FSI addressing information
     * @param[out] o_readData  buffer to copy read data into, set to NULL
     *       for write operations
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t pollForComplete(FSI::FsiAddrInfo_t& i_addrInfo,
                               uint32_t* o_readData);

    /**
     * @brief Figure out the optimal OPB Master to use and generate a
     *    complete FSI address relative to that master based on the target
     *    and the FSI offset within that target
     *
     * @param[inout] io_addrInfo  FSI addressing information,
     *     expects fsiTarg and relAddr to be populated as input
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t genFullFsiAddr(FSI::FsiAddrInfo_t& io_addrInfo);

    /**
     * @brief Generate a valid SCOM address to access the OPB, this will
     *    choose the correct PIB2OPB port.
     *
     * @param[in] i_addrInfo  FSI connection data for the target of the FSI
     *      operation
     * @param[in] i_address  Address of OPB register relative to OPB space,
     *      e.g. OPB_REG_CMD
     *
     * @return uint64_t  Fully qualified OPB SCOM address
     */
    uint64_t genOpbScomAddr(FSI::FsiAddrInfo_t& i_addrInfo,
                            uint64_t i_opbOffset);


    /**
     * PIB2OPB Registers
     */
    enum Pib2OpbRegisters {
        OPB_REG_CMD   = 0x0000, /**< Command Register */
        OPB_REG_STAT  = 0x0001, /**< Status Register */
        OPB_REG_LSTAT = 0x0002, /**< Locked Status */
        // no reg for 0x0003
        OPB_REG_RES   = 0x0004, /**< Reset */
        OPB_REG_CRSIC = 0x0005, /**< cMFSI Remote Slave Interrupt Condition */
        OPB_REG_CRSIM = 0x0006, /**< cMFSI Remote Slave Interrupt Mask */
        OPB_REG_CRSIS = 0x0007, /**< cMFSI Remote Slave Interrupt Status */
        OPB_REG_RSIC  = 0x0008, /**< MFSI Remote Slave Interrupt Condition */
        OPB_REG_RSIM  = 0x0009, /**< MFSI Remote Slave Interrupt Mask */
        OPB_REG_RSIS  = 0x000A, /**< MFSI Remote Slave Interrupt Status */

        // Offsets for cMFSI
        FSI2OPB_OFFSET_0 = 0x00020000, /**< cMFSI 0 and MFSI */
        FSI2OPB_OFFSET_1 = 0x00030000, /**< cMFSI 1 */

        // Bit masks
        OPB_STAT_BUSY       = 0x00010000, /**< 15 is the Busy bit */
        OPB_STAT_READ_VALID = 0x00020000, /**< 14 is the Valid Read bit */
        OPB_STAT_ERRACK     = 0x00100000, /**< 11 is OPB errAck */
        OPB_STAT_ANYERR     = 0x80000000, /**< 0 is Any error */
        OPB_STAT_ERR_OPB    = 0x7FEC0000, /**< 1:10,12:13 are OPB errors */
        OPB_STAT_ERR_CMFSI  = 0x0000FC00, /**< 16:21 are cMFSI errors */
        OPB_STAT_ERR_MFSI   = 0x000000FC, /**< 24:29 are MFSI errors */
        OPB_STAT_ERR_ANY    = (OPB_STAT_ERR_OPB |
                               OPB_STAT_ERR_CMFSI |
                               OPB_STAT_ERR_MFSI |
                               OPB_STAT_ERRACK |
                               OPB_STAT_ANYERR ),
    };

    /**
     * FSI Control Registers
     */
    enum FsiControlRegisters {
        FSI_MMODE_000   = 0x000,
        FSI_MDLYR_004   = 0x004,
        FSI_MCRSP0_008  = 0x008,
        FSI_MENP0_010   = 0x010,
        FSI_MLEVP0_018  = 0x018,
        FSI_MSENP0_018  = 0x018,
        FSI_MCENP0_020  = 0x020,
        FSI_MSIEP0_030  = 0x030,
        FSI_MAESP0_050  = 0x050,
        FSI_MAEB_070    = 0x070, //MREFP0
        FSI_MBSYP0_078  = 0x078,
        FSI_MRESP0_0D0  = 0x0D0,
        FSI_MSTAP0_0D0  = 0x0D0,
        FSI_MRESP0_0D1  = 0x0D1,
        FSI_MSTAP0_0D1  = 0x0D1,
        FSI_MRESP0_0D2  = 0x0D2,
        FSI_MSTAP0_0D2  = 0x0D2,
        FSI_MRESP0_0D3  = 0x0D3,
        FSI_MSTAP0_0D3  = 0x0D3,
        FSI_MRESP0_0D4  = 0x0D4,
        FSI_MSTAP0_0D4  = 0x0D4,
        FSI_MRESP0_0D5  = 0x0D5,
        FSI_MSTAP0_0D5  = 0x0D5,
        FSI_MRESP0_0D6  = 0x0D6,
        FSI_MSTAP0_0D6  = 0x0D6,
        FSI_MRESP0_0D7  = 0x0D7,
        FSI_MSTAP0_0D7  = 0x0D7,
        FSI_MESRB0_1D0  = 0x1D0,
        FSI_MSCSB0_1D4  = 0x1D4,
        FSI_MATRB0_1D8  = 0x1D8,
        FSI_MDTRB0_1DC  = 0x1DC,
        FSI_MECTRL_2E0  = 0x2E0,
        FSI_CTLREG_MASK = 0x2FF
    };


    /**
     * General Constants
     */
    enum Constants {
        MAX_SLAVE_PORTS = 8, /**< Maximum of 8 slave ports */
        LOCAL_MFSI_PORT_SELECT = MAX_SLAVE_PORTS + TARGETING::FSI_MASTER_TYPE_MFSI,
        LOCAL_CMFSI_PORT_SELECT = MAX_SLAVE_PORTS + TARGETING::FSI_MASTER_TYPE_CMFSI,
        INVALID_SLAVE_INDEX = 0x12345678
    };

    /**
     * @brief Retrieve the control register address based on type
     * @param[in] i_type  Type of FSI interface
     * @return uint64_t  FSI address offset 
     */
    uint64_t getControlReg(TARGETING::FSI_MASTER_TYPE i_type)
    {
        uint64_t ctl_reg = FSI::MFSI_CONTROL_REG;
        if( TARGETING::FSI_MASTER_TYPE_CMFSI == i_type )
        {
            ctl_reg = FSI::CMFSI_CONTROL_REG;
        }
        return ctl_reg;
    };

    /**
     * @brief Retrieve the slave enable index
     * @param[in] i_master  Target of FSI Master
     * @param[in] i_type  Type of FSI interface
     * @return uint64_t  Index into iv_slaves array
     */
    uint64_t getSlaveEnableIndex( TARGETING::Target* i_master,
                                  TARGETING::FSI_MASTER_TYPE i_type );

    /**
     * @brief Retrieve the connection information needed to access FSI
     *        registers within the given chip target
     *
     * @param[in] i_target  Target of FSI Slave to access
     *
     * @return FsiChipInfo_t  FSI Chip Information
     */
    FSI::FsiChipInfo_t getFsiInfo( TARGETING::Target* i_target );

    /**
     * @brief Clear out the error indication so that we can do more FSI ops
     *
     * @param[in] i_addrInfo  FSI Operation in error
     * @param[in] i_errType  Which type of error is being recovered from
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t errorCleanup( FSI::FsiAddrInfo_t& i_addrInfo,
                             FSI::FSIReasonCode i_errType );

    /**
     * @brief Check for FSI errors anywhere in the system
     *
     * @param[in] i_chipInfo  FSI Chip Information
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t checkForErrors( FSI::FsiChipInfo_t& i_chipInfo );

    /**
     * @brief Check for FSI errors anywhere in the system
     *
     * @param[in] i_addrInfo  FSI Operation in error
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t checkForErrors( FSI::FsiAddrInfo_t& i_addrInfo );

    /**
     * @brief Verify that the slave target was detected
     *
     * @param[in] i_target  FSI Slave target
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t verifyPresent( TARGETING::Target* i_target );

    /**
     * @brief Retrieve the connection information needed to access FSI
     *        registers within the given chip target from attributes
     *
     * @param[in] i_target  Target of FSI Slave to access
     *
     * @return FsiChipInfo_t  FSI Chip Information
     */
    FSI::FsiChipInfo_t getFsiInfoFromAttr( TARGETING::Target* i_target );


    /********************************************
     * VARIABLES
     ********************************************/

    /**
     * Active slaves, 1 bit per port, 1=active,
     *   one entry per MFSI port, plus local MFSI and local cMFSI
     */
    uint8_t iv_slaves[MAX_SLAVE_PORTS+2];

    /**
     * Master processor target
     */
    TARGETING::Target* iv_master;

    /**
     * Using alternate master
     */
    uint8_t iv_useAlt;

    /**
     * Non-zero if a Task is currently collecting FFDC
     */
    tid_t iv_ffdcTask;

    /**
     * OPB Error Bits
     */
    uint32_t iv_opbErrorMask;

    /**
     * Last OPB Command
     */
    uint64_t iv_lastOpbCmd;

    /**
     * Cache of FSI connection information gleaned from attributes
     *   Indexed by Target*, returns FsiChipInfo_t
     */
    std::map<TARGETING::Target*,FSI::FsiChipInfo_t> iv_fsiInfoMap;

    /**
     * Mutex to protect the internal maps
     */
    mutex_t iv_dataMutex;

  private:

    // let my testcase poke around
    friend class FsiDDTest;

    // let the UserDetails classes see internal structures
    friend class FSI::UdPresence;
};


#endif
