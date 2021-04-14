/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_pldmdd.C $                                  */
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
// Initialized in pnorrp.C

#include <errl/errlentry.H>
#include <trace/interface.H>
#include <sys/sync.h>
#include <kernel/console.H>
#include <devicefw/driverif.H>
#include <targeting/common/targetservice.H>

#include <pldm/requests/pldm_fileio_requests.H>

#include "pnor_pldmdd.H"
#include "pnor_pldm_utils.H"

extern trace_desc_t* g_trac_pnor;

/**
 * @file pnor_pldmdd.C
 *
 * @brief File containing the source code for the PLDM
 *        implementation of the PNOR DeviceFW interface.
 */

namespace PNOR
{

/**
 * @brief This function performs a PNOR Read operation. It follows a
 * pre-defined prototype function in order to be registered with the
 * device-driver framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        PNOR target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the PNOR address and chip select
 * @return  errlHndl_t
 */
errlHndl_t ddRead(DeviceFW::OperationType i_opType,
                  TARGETING::Target* i_target,
                  void* io_buffer,
                  size_t& io_buflen,
                  int64_t i_accessType,
                  va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args, uint64_t);

    do
    {
        // The PNOR device driver interface is initialized with the
        // MASTER_PROCESSOR_CHIP_TARGET_SENTINEL. Other target
        // access requires a separate PnorPldmDD class to be created
        assert( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );
        // Ensure buffer is not a nullptr
        assert (io_buffer != nullptr, "pnor_pldmd's ddRead passed a nullptr");

        // Read the flash
        l_err = Singleton<PnorPldmDD>::instance().readFlash(io_buffer,
                io_buflen,
                l_addr);

        if(l_err)
        {
            TRACFCOMP(g_trac_pnor, "PnorPldmDD::readFlash returned an error. "
                      TRACE_ERR_FMT, TRACE_ERR_ARGS(l_err));
            break;
        }

    }
    while(0);

    return l_err;
}

/**
 * @brief This function performs a PNOR Write operation. It follows a
 * pre-defined prototype function in order to be registered with the
 * device-driver framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        PNOR target
 * @param[in/out] io_buffer     Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the PNOR address and chip select
 * @return  errlHndl_t
 */
errlHndl_t ddWrite(DeviceFW::OperationType i_opType,
                   TARGETING::Target* i_target,
                   void* io_buffer,
                   size_t& io_buflen,
                   int64_t i_accessType,
                   va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args, uint64_t);

    do
    {
        // The PNOR device driver interface is initialized with the
        // MASTER_PROCESSOR_CHIP_TARGET_SENTINEL. Other target
        // access requires a separate PnorPldmDD class created
        assert( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );
        // Ensure buffer is not a nullptr
        assert (io_buffer != nullptr, "pnor_pldmd's ddWrite was passed a nullptr");

        // Write the flash
        l_err = Singleton<PnorPldmDD>::instance().writeFlash(io_buffer,
                io_buflen,
                l_addr);

        if(l_err)
        {
            TRACFCOMP(g_trac_pnor, "PnorPldmDD::writeFlash returned an error. "
                      TRACE_ERR_FMT, TRACE_ERR_ARGS(l_err));
            break;
        }

    }
    while(0);

    return l_err;
}

// Register PNORDD access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PNOR,
                      TARGETING::TYPE_PROC,
                      ddRead);

DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::PNOR,
                      TARGETING::TYPE_PROC,
                      ddWrite);
}//namespace PNOR

/**
 * @brief Performs a PNOR Read Operation
 */
errlHndl_t PnorPldmDD::readFlash(void* o_buffer,
                                 size_t& io_buflen,
                                 uint64_t i_address)
{
    TRACDCOMP(g_trac_pnor, ENTER_MRK"PnorPldmDD::readFlash(i_address=0x%llx)> ", i_address);
    mutex_lock(iv_mutex_ptr);
    auto l_err = _readFlash( i_address, io_buflen, o_buffer );
    mutex_unlock(iv_mutex_ptr);
    TRACDCOMP(g_trac_pnor, EXIT_MRK"PnorPldmDD::readFlash(i_address=0x%llx)> io_buflen=%.8X", i_address, io_buflen);
    return l_err;
}

/**
 * @brief Performs a PNOR Write Operation
 */
errlHndl_t PnorPldmDD::writeFlash(const void* i_buffer,
                                  size_t& io_buflen,
                                  uint64_t i_address)
{
    TRACDCOMP(g_trac_pnor, ENTER_MRK"PnorPldmDD::writeFlash(i_address=0x%llx)> ", i_address);
    mutex_lock(iv_mutex_ptr);
    auto l_err = _writeFlash( i_address, io_buflen, i_buffer );
    mutex_unlock(iv_mutex_ptr);
    if( l_err )
    {
        io_buflen = 0;
    }
    TRACDCOMP(g_trac_pnor, EXIT_MRK"PnorPldmDD::writeFlash(i_address=0x%llx)> io_buflen=%.8X", i_address, io_buflen);
    return l_err;
}

/**
 * @brief This is irrelevent for PLDM, return 0
 */
uint32_t PnorPldmDD::getNorSize( void ) { return 0; }

/**
 * @brief This is irrelevent for PLDM, return 0
 */
uint32_t PnorPldmDD::getNorWorkarounds( void ) { return 0; }

/********************
 Private/Protected Methods
 ********************/
mutex_t PnorPldmDD::cv_mutex = MUTEX_INITIALIZER;

/**
 * @brief Write data to PNOR using PLDM File I/O Requests
 */
errlHndl_t PnorPldmDD::_writeFlash( uint64_t i_addr,
                                    size_t &io_size,
                                    const void* i_data )
{
    errlHndl_t err = nullptr;

    // Create local copies of the input addr/size params that we can manipulate
    uint32_t offset_into_section = 0;
    assert(io_size < UINT32_MAX);
    uint32_t write_size = io_size;

    // Figure out which LID we want to read from and adjust the offset.
    auto lid = PLDM_PNOR::vaddrToLidId(i_addr, offset_into_section);

    err = PLDM::writeLidFileFromOffset(lid,
                               offset_into_section,
                               write_size,
                               reinterpret_cast<const uint8_t *>(i_data));

    io_size = (err == nullptr) ? write_size : 0;
    return err;
}

/**
 * @brief Read data from PNOR using Mbox LPC windows
 */
errlHndl_t PnorPldmDD::_readFlash( uint64_t i_addr,
                                   size_t &io_size,
                                   void* o_data )
{
    errlHndl_t err = NULL;

    // Create local copies of the input addr/size params that we can manipulate
    uint32_t offset_into_section = 0;
    assert(io_size < UINT32_MAX);
    uint32_t read_size = io_size;

    // Figure out which LID we want to read from and adjust the offset.
    auto lid = PLDM_PNOR::vaddrToLidId(i_addr, offset_into_section);

    err = PLDM::getLidFileFromOffset(lid,
                               offset_into_section,
                               read_size,
                               reinterpret_cast<uint8_t *>(o_data));
    io_size = (err == nullptr) ? read_size : 0;
    return err;
}

/**
 * @brief  Constructor
 */
PnorPldmDD::PnorPldmDD( TARGETING::Target* i_target )
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK "PnorDD::PnorDD()");

    printk("Using PLDM File I/O requests with MCTP transport for PNOR access\n");

    // Use i_target if all of these apply
    // 1) not NULL
    // 2) not MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    // 3) i_target does not correspond to Primary processor (ie the
    //    same processor as MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    // otherwise, use MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    // NOTE: i_target can only be used when targeting is loaded
    if ( ( i_target != NULL ) &&
         ( i_target != TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL ) )
    {
        iv_target = i_target;
        // Check if processor is primary
        TARGETING::ATTR_PROC_MASTER_TYPE_type type_enum =
            iv_target->getAttr<TARGETING::ATTR_PROC_MASTER_TYPE>();

        // Primary target could collide and cause deadlocks with PnorPldmDD singleton
        // used for ddRead/ddWrite with MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
        assert( type_enum != TARGETING::PROC_MASTER_TYPE_ACTING_MASTER );

        // Initialize and use class-specific mutex
        iv_mutex_ptr = &iv_mutex;
        mutex_init(iv_mutex_ptr);
        TRACFCOMP(g_trac_pnor, "PnorPldmDD::PnorPldmDD()> Using i_target=0x%X (secondary) and iv_mutex_ptr",
                  TARGETING::get_huid(i_target));
    }
    else
    {
        iv_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        iv_mutex_ptr = &(cv_mutex);
    }

    TRACFCOMP(g_trac_pnor, EXIT_MRK "PnorDD::PnorDD()" );
}

/**
 * @brief  Destructor
 */
PnorPldmDD::~PnorPldmDD()
{
}
