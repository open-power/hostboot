/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_mboxdd.C $                                  */
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
/**
 *  @file ast_mboxdd.C
 *
 *  @brief Implementation of the PNOR Device Driver on top of AST MBOX protocol
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <sys/mmio.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludlogregister.H>
#include <errl/errludstring.H>
#include <targeting/common/targetservice.H>
#include <sio/sio.H>
#include "ast_mboxdd.H"
#include "pnor_mboxdd.H"
#include "pnor_common.H"
#include <pnor/pnorif.H>
#include <pnor/pnor_reasoncodes.H>
#include <sys/time.h>
#include <initservice/initserviceif.H>
#include <util/align.H>
#include <lpc/lpcif.H>
#include <config.h>
#include "sfcdd.H"

// Initialized in pnorrp.C
extern trace_desc_t* g_trac_pnor;

namespace PNOR
{

/**
 * @brief Performs an PNOR Read Operation
 * This function performs a PNOR Read operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        PNOR target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
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
        //@todo (RTC:36951) - add support for unaligned data
        // Ensure we are operating on a 32-bit (4-byte) boundary
        assert( reinterpret_cast<uint64_t>(io_buffer) % 4 == 0 );
        assert( io_buflen % 4 == 0 );

        // The PNOR device driver interface is initialized with the
        // MASTER_PROCESSOR_CHIP_TARGET_SENTINEL.  Other target
        // access requires a separate PnorDD class created
        assert( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

        // Read the flash
        l_err = Singleton<PnorDD>::instance().readFlash(io_buffer,
                io_buflen,
                l_addr);

        if(l_err)
        {
            break;
        }

    }
    while(0);

    return l_err;
}

/**
 * @brief Performs an PNOR Write Operation
 * This function performs a PNOR Write operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        PNOR target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
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
        //@todo (RTC:36951) - add support for unaligned data
        // Ensure we are operating on a 32-bit (4-byte) boundary
        assert( reinterpret_cast<uint64_t>(io_buffer) % 4 == 0 );
        assert( io_buflen % 4 == 0 );

        // The PNOR device driver interface is initialized with the
        // MASTER_PROCESSOR_CHIP_TARGET_SENTINEL.  Other target
        // access requires a separate PnorDD class created
        assert( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

        // Write the flash
        l_err = Singleton<PnorDD>::instance().writeFlash(io_buffer,
                io_buflen,
                l_addr);

        if(l_err)
        {
            break;
        }

    }
    while(0);

    return l_err;
}

/**
 * @brief Informs caller if the driver is using
 *        L3 Cache for fake PNOR or not.
 *
 * @return Indicate state of fake PNOR
 *         true = PNOR DD is using L3 Cache for fake PNOR
 *         false = PNOR DD not using L3 Cache for fake PNOR
 */
bool usingL3Cache()
{
    return false;
}

/**
 * @brief Retrieve some information about the PNOR/SFC hardware
 */
void getPnorInfo( PnorInfo_t& o_pnorInfo )
{
    o_pnorInfo.mmioOffset = LPC_SFC_MMIO_OFFSET | LPC_FW_SPACE;
    o_pnorInfo.norWorkarounds =
        Singleton<PnorDD>::instance().getNorWorkarounds();
    o_pnorInfo.flashSize =
        Singleton<PnorDD>::instance().getNorSize();
}



// Register MBOXDD access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PNOR,
                      TARGETING::TYPE_PROC,
                      ddRead);

DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::PNOR,
                      TARGETING::TYPE_PROC,
                      ddWrite);

}; //namespace PNOR


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


/**
 * @brief Performs a PNOR Read Operation
 */
errlHndl_t PnorDD::readFlash(void* o_buffer,
                             size_t& io_buflen,
                             uint64_t i_address)
{
    /* We support 256M max */
    uint32_t l_address = i_address & 0x0fffffff;

    mutex_lock(iv_mutex_ptr);
    errlHndl_t l_err = _readFlash( l_address, io_buflen, o_buffer );
    mutex_unlock(iv_mutex_ptr);

    return l_err;
}

/**
 * @brief Performs a PNOR Write Operation
 */
errlHndl_t PnorDD::writeFlash(const void* i_buffer,
                              size_t& io_buflen,
                              uint64_t i_address)
{
    TRACDCOMP(g_trac_pnor, ENTER_MRK"PnorDD::writeFlash(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;

    uint32_t l_address = i_address & 0x0fffffff;

    mutex_lock(iv_mutex_ptr);
    l_err = _writeFlash( l_address, io_buflen, i_buffer );
    mutex_unlock(iv_mutex_ptr);

    if( l_err )
    {
        io_buflen = 0;
    }

    TRACDCOMP(g_trac_pnor, EXIT_MRK"PnorDD::writeFlash(i_address=0x%llx)> io_buflen=%.8X", i_address, io_buflen);

    return l_err;
}


/********************
 Private/Protected Methods
 ********************/
mutex_t PnorDD::cv_mutex = MUTEX_INITIALIZER;

/**
 * LPC FW space accessors
 */
errlHndl_t PnorDD::readLpcFw(uint32_t i_offset, size_t i_size, void* o_buf)
{
    // Exploit new LPC large read facility
    return deviceOp(DeviceFW::READ, iv_target, o_buf, i_size,
                    DEVICE_LPC_ADDRESS(LPC::TRANS_FW, i_offset));
}

errlHndl_t PnorDD::writeLpcFw(uint32_t i_offset, size_t i_size,
                              const void* i_buf)
{
    // Exploit new LPC large write facility
    return deviceOp(DeviceFW::WRITE, iv_target, (void*)i_buf, i_size,
                    DEVICE_LPC_ADDRESS(LPC::TRANS_FW, i_offset));
}

errlHndl_t PnorDD::adjustMboxWindow(bool i_isWrite, uint32_t i_reqAddr,
                                    size_t i_reqSize, uint32_t& o_lpcAddr,
                                    size_t& o_chunkLen)
{
    errlHndl_t l_err = NULL;
    uint32_t l_pos, l_wSize, l_reqSize;

    do
    {
        /*
         * Handle the case where the window is already opened, is of
         * the right type and contains the requested address.
         */
        uint32_t l_wEnd = iv_curWindowOffset + iv_curWindowSize;

        /* A read request can be serviced by a write window */
        if (iv_curWindowOpen &&
            (iv_curWindowWrite || !i_isWrite) &&
            i_reqAddr >= iv_curWindowOffset && i_reqAddr < l_wEnd)
        {
            size_t l_gap = (l_wEnd - i_reqAddr);

            o_lpcAddr = iv_curWindowLpcOffset +(i_reqAddr - iv_curWindowOffset);
            o_chunkLen = std::min(i_reqSize, l_gap);
            return NULL;
        }

        /*
         * We need a window change, mark it closed first
         */
        iv_curWindowOpen = false;

        /*
         * Then open the new one at the right position. The required
         * alignment differs between protocol versions
         */
        TRACDCOMP(g_trac_pnor,
                    "astMboxDD::adjustMboxWindow using protocol version: %d",
                    iv_protocolVersion);
        if (iv_protocolVersion == 1)
        {
            l_wSize = i_isWrite ? iv_writeWindowSize : iv_readWindowSize;
            l_pos = i_reqAddr & ~(l_wSize - 1);
            l_reqSize = 0;
        }
        else
        {
            uint32_t l_blockMask = (1u << iv_blockShift) - 1;
            l_wSize = 0;
            l_pos = i_reqAddr & ~l_blockMask;
            l_reqSize = (((i_reqAddr + i_reqSize) + l_blockMask) & ~l_blockMask)
                          - l_pos;
        }

        TRACFCOMP(g_trac_pnor, "astMboxDD::adjustMboxWindow opening %s window at 0x%08x"
                  " for addr 0x%08x req_size 0x%08x",
                  i_isWrite ? "write" : "read", l_pos, i_reqAddr, l_reqSize);

        astMbox::mboxMessage winMsg(i_isWrite
                                    ? astMbox::MBOX_C_CREATE_WRITE_WINDOW :
                                    astMbox::MBOX_C_CREATE_READ_WINDOW);
        winMsg.put16(0, l_pos >> iv_blockShift);
        winMsg.put16(2, l_reqSize >> iv_blockShift);
        l_err = iv_mbox->doMessage(winMsg);

        if (l_err)
        {
            break;
        }

        iv_curWindowLpcOffset = winMsg.get16(0) << iv_blockShift;

        if (iv_protocolVersion == 1)
        {
            iv_curWindowOffset = l_pos;
            iv_curWindowLpcOffset = winMsg.get16(0) << iv_blockShift;
            iv_curWindowSize = l_wSize;
        }
        else
        {
            iv_curWindowLpcOffset = winMsg.get16(0) << iv_blockShift;
            iv_curWindowSize = winMsg.get16(2) << iv_blockShift;
            iv_curWindowOffset = winMsg.get16(4) << iv_blockShift;
        }

        iv_curWindowOpen = true;
        iv_curWindowWrite = i_isWrite;

        TRACDCOMP(g_trac_pnor, " curWindowOffset    = %08x", iv_curWindowOffset);
        TRACDCOMP(g_trac_pnor, " curWindowSize      = %08x", iv_curWindowSize);
        TRACDCOMP(g_trac_pnor, " curWindowLpcOffset = %08x", iv_curWindowLpcOffset);

    }
    while (true);

    return l_err;
}

errlHndl_t PnorDD::writeDirty(uint32_t i_addr, size_t i_size)
{
    /* To pass a correct "size" for both protocol versions, we
     * calculate the block-aligned start and end.
     */
    uint32_t l_blockMask = (1u << iv_blockShift) - 1;
    uint32_t l_start     = i_addr & ~l_blockMask;
    uint32_t l_end       = ((i_addr + i_size) + l_blockMask) & ~l_blockMask;

    astMbox::mboxMessage dirtyMsg(astMbox::MBOX_C_MARK_WRITE_DIRTY);

    if (iv_protocolVersion == 1)
    {
        dirtyMsg.put16(0, i_addr >> iv_blockShift);
        dirtyMsg.put32(2, l_end - l_start);
    }
    else
    {
        dirtyMsg.put16(0, (i_addr - iv_curWindowOffset) >> iv_blockShift);
        dirtyMsg.put16(2, (l_end - l_start)  >> iv_blockShift);
    }

    return iv_mbox->doMessage(dirtyMsg);
}

errlHndl_t PnorDD::writeFlush(void)
{
    astMbox::mboxMessage flushMsg(astMbox::MBOX_C_WRITE_FLUSH);

    flushMsg.put16(0, 0);
    flushMsg.put32(2, 0);
    return iv_mbox->doMessage(flushMsg);
}

/**
 * @brief Write data to PNOR using Mbox LPC windows
 */
errlHndl_t PnorDD::_writeFlash( uint32_t i_addr,
                                size_t i_size,
                                const void* i_data )
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"PnorDD::_writeFlash(i_addr=0x%.8X)> ", i_addr);
    errlHndl_t l_err = NULL, l_flushErr = NULL;

    while (i_size)
    {
        uint32_t l_lpcAddr;
        size_t l_chunkLen;

        l_err = adjustMboxWindow(true, i_addr, i_size, l_lpcAddr, l_chunkLen);

        if (l_err)
        {
            break;
        }

        l_err = writeLpcFw(l_lpcAddr, l_chunkLen, i_data);

        if (l_err)
        {
            break;
        }

        l_err = writeDirty(i_addr, l_chunkLen);

        if (l_err)
        {
            break;
        }

        i_addr += l_chunkLen;
        i_size -= l_chunkLen;
        i_data = (char*)i_data + l_chunkLen;
    }

    /* We flush whether we had an error or not.
     *
     * NOTE: It would help the daemon a lot if we moved that out of here
     * and instead had a single flush call over a series of writes.
     *
     * @todo (RTC:173513)
     * Investigate  erasing & re-writing the same pages at least 3 times
     * in a row during a boot.
     */
    l_flushErr = writeFlush();

    if ( l_err == NULL )
    {
        l_err = l_flushErr;
    }
    else
    {
        delete l_flushErr;
        l_flushErr = NULL;
    }

    if( l_err )
    {
        l_err->collectTrace(PNOR_COMP_NAME);
    }

    return l_err;
}

/**
 * @brief Read data from PNOR using Mbox LPC windows
 */
errlHndl_t PnorDD::_readFlash( uint32_t i_addr,
                               size_t i_size,
                               void* o_data )
{
    TRACDCOMP(g_trac_pnor, "PnorDD::_readFlash(i_addr=0x%.8X)> ", i_addr);
    errlHndl_t l_err = NULL;

    while (i_size)
    {
        uint32_t l_lpcAddr;
        size_t l_chunkLen;

        l_err = adjustMboxWindow(false, i_addr, i_size, l_lpcAddr, l_chunkLen);

        if (l_err)
        {
            break;
        }

        l_err = readLpcFw(l_lpcAddr, l_chunkLen, o_data);

        if (l_err)
        {
            break;
        }

        i_addr += l_chunkLen;
        i_size -= l_chunkLen;
        o_data = (char*)o_data + l_chunkLen;
    }

    if( l_err )
    {
        l_err->collectTrace(PNOR_COMP_NAME);
    }

    return l_err;
}

/**
 * @brief Retrieve size of NOR flash
 */
uint32_t PnorDD::getNorSize( void )
{
    return iv_flashSize;
}

/**
 * @brief Retrieve bitstring of NOR workarounds
 */
uint32_t PnorDD::getNorWorkarounds( void )
{
    return 0;
}

/**
 * @brief  Constructor
 */
PnorDD::PnorDD( TARGETING::Target* i_target )
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK "PnorDD::PnorDD()" );
    errlHndl_t l_err = NULL;

    // Use i_target if all of these apply
    // 1) not NULL
    // 2) not MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    // 3) i_target does not correspond to Master processor (ie the
    //    same processor as MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    // otherwise, use MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    // NOTE: i_target can only be used when targeting is loaded
    if ( ( i_target != NULL ) &&
         ( i_target != TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL ) )
    {

        iv_target = i_target;

        // Check if processor is MASTER
        TARGETING::ATTR_PROC_MASTER_TYPE_type type_enum =
            iv_target->getAttr<TARGETING::ATTR_PROC_MASTER_TYPE>();

        // Master target could collide and cause deadlocks with PnorDD singleton
        // used for ddRead/ddWrite with MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
        assert( type_enum != TARGETING::PROC_MASTER_TYPE_ACTING_MASTER );

        // Initialize and use class-specific mutex
        iv_mutex_ptr = &iv_mutex;
        mutex_init(iv_mutex_ptr);
        TRACFCOMP(g_trac_pnor, "PnorDD::PnorDD()> Using i_target=0x%X (non-master) and iv_mutex_ptr",
                  TARGETING::get_huid(i_target));
    }
    else
    {
        iv_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        iv_mutex_ptr = &(cv_mutex);
    }

    /* Instanciate MboxDD */
    iv_mbox = new astMbox(iv_target);

    iv_curWindowOpen = false;

    do
    {
        astMbox::mboxMessage mbInfoMsg(astMbox::MBOX_C_GET_MBOX_INFO);

        /* Initialize MBOX protocol, try protocol v2 */
        mbInfoMsg.put8(0, 2);
        l_err = iv_mbox->doMessage(mbInfoMsg);

        if (l_err)
        {
            TRACFCOMP( g_trac_pnor, "Error getting MBOX info :: RC=%.4X", ERRL_GETRC_SAFE(l_err) );
            break;
        }

        /* Check protocol */
        iv_protocolVersion = mbInfoMsg.get8(0);

        if (iv_protocolVersion == 1)
        {
            iv_blockShift = 12;
            iv_readWindowSize = mbInfoMsg.get16(1) << iv_blockShift;
            iv_writeWindowSize = mbInfoMsg.get16(3) << iv_blockShift;
        }
        else
        {
            iv_blockShift = mbInfoMsg.get8(5);
        }

        TRACFCOMP( g_trac_pnor, "mboxPnor: protocolVersion=%d blockShift=%d",
                   iv_protocolVersion, iv_blockShift);

        /* Get flash info */
        astMbox::mboxMessage flInfoMsg(astMbox::MBOX_C_GET_FLASH_INFO);
        l_err = iv_mbox->doMessage(flInfoMsg);

        if (l_err)
        {
            TRACFCOMP( g_trac_pnor, "Error getting flash info :: RC=%.4X", ERRL_GETRC_SAFE(l_err) );
            break;
        }

        /* Intepretation changes with protocol v2 */
        if (iv_protocolVersion == 1)
        {
            iv_flashSize = flInfoMsg.get32(0);
            iv_flashEraseSize = flInfoMsg.get32(4);
        }
        else
        {
            iv_flashSize = flInfoMsg.get16(0) << iv_blockShift;
            iv_flashEraseSize = flInfoMsg.get16(2) << iv_blockShift;
        }

        TRACFCOMP( g_trac_pnor, "mboxPnor: flashSize=0x%08x, eraseSize=0x%08x",
                   iv_blockShift, iv_flashSize, iv_flashEraseSize);
    }
    while(0);

    if( l_err )
    {
        TRACFCOMP( g_trac_pnor, "Failure to initialize the PNOR logic, shutting down :: RC=%.4X", ERRL_GETRC_SAFE(l_err) );
        l_err->collectTrace(PNOR_COMP_NAME);
        ERRORLOG::errlCommit(l_err, PNOR_COMP_ID);
        INITSERVICE::doShutdown( PNOR::RC_PNOR_INIT_FAILURE );
    }

    TRACFCOMP(g_trac_pnor, EXIT_MRK "PnorDD::PnorDD()" );
}

/**
 * @brief  Destructor
 */
PnorDD::~PnorDD()
{
}
