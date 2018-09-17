/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_ipmidd.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
 *  @file pnor_ipmidd.C
 *
 *  @brief An implementation of the HIOMAP protocol over IPMI
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <algorithm>
#include <arch/ppc.H>
#include <sys/mmio.h>
#include <sys/msg.h>
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
#include "pnor_ipmidd.H"
#include "pnor_common.H"
#include "pnor_utils.H"
#include <pnor/pnorif.H>
#include <pnor/pnor_reasoncodes.H>
#include <sys/time.h>
#include <initservice/initserviceif.H>
#include <util/align.H>
#include <lpc/lpcif.H>
#include <config.h>
#include "sfcdd.H"
#include <ipmi/ipmiif.H>

#include <kernel/console.H>

/**
 * @brief HIOMAP commands
 */
enum {
    HIOMAP_C_RESET                      = 1,
    HIOMAP_C_GET_INFO                   = 2,
    HIOMAP_C_GET_FLASH_INFO             = 3,
    HIOMAP_C_CREATE_READ_WINDOW         = 4,
    HIOMAP_C_CLOSE                      = 5,
    HIOMAP_C_CREATE_WRITE_WINDOW        = 6,
    HIOMAP_C_MARK_DIRTY                 = 7,
    HIOMAP_C_FLUSH                      = 8,
    HIOMAP_C_ACK                        = 9,
    HIOMAP_C_ERASE                      = 10,
    HIOMAP_C_GET_FLASH_NAME             = 11,
    HIOMAP_C_LOCK                       = 12,
};

/**
 * @brief HIOMAP protocol versions
 */
enum {
    HIOMAP_V_1 = 1,
    HIOMAP_V_2 = 2,
};

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
        // access requires a separate PnorIpmiDD class created
        assert( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

        // Read the flash
        l_err = Singleton<PnorIpmiDD>::instance().readFlash(io_buffer,
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
        // access requires a separate PnorIpmiDD class created
        assert( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

        // Write the flash
        l_err = Singleton<PnorIpmiDD>::instance().writeFlash(io_buffer,
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
        Singleton<PnorIpmiDD>::instance().getNorWorkarounds();
    o_pnorInfo.flashSize =
        Singleton<PnorIpmiDD>::instance().getNorSize();
}

// Register access functions to DD framework
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
errlHndl_t PnorIpmiDD::readFlash(void* o_buffer,
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
errlHndl_t PnorIpmiDD::writeFlash(const void* i_buffer,
                                  size_t& io_buflen,
                                  uint64_t i_address)
{
    TRACDCOMP(g_trac_pnor, ENTER_MRK"PnorIpmiDD::writeFlash(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;

    uint32_t l_address = i_address & 0x0fffffff;

    mutex_lock(iv_mutex_ptr);
    l_err = _writeFlash( l_address, io_buflen, i_buffer );
    mutex_unlock(iv_mutex_ptr);

    if( l_err )
    {
        io_buflen = 0;
    }

    TRACDCOMP(g_trac_pnor, EXIT_MRK"PnorIpmiDD::writeFlash(i_address=0x%llx)> io_buflen=%.8X", i_address, io_buflen);

    return l_err;
}


/********************
 Private/Protected Methods
 ********************/
mutex_t PnorIpmiDD::cv_mutex = MUTEX_INITIALIZER;

/**
 * LPC FW space accessors
 */
errlHndl_t PnorIpmiDD::readLpcFw(uint32_t i_offset, size_t i_size, void* o_buf)
{
    // Exploit new LPC large read facility
    return deviceOp(DeviceFW::READ, iv_target, o_buf, i_size,
                    DEVICE_LPC_ADDRESS(LPC::TRANS_FW, i_offset));
}

errlHndl_t PnorIpmiDD::writeLpcFw(uint32_t i_offset, size_t i_size,
                                  const void* i_buf)
{
    // Exploit new LPC large write facility
    return deviceOp(DeviceFW::WRITE, iv_target, (void*)i_buf, i_size,
                    DEVICE_LPC_ADDRESS(LPC::TRANS_FW, i_offset));
}

errlHndl_t PnorIpmiDD::adjustWindow(bool i_isWrite, uint32_t i_reqAddr,
                                    size_t i_reqSize, uint32_t& o_lpcAddr,
                                    size_t& o_chunkLen)
{
    errlHndl_t l_err = NULL;
    uint32_t l_pos, l_reqSize;

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
            TRACDCOMP(g_trac_pnor, "LPC window @ 0x%x (0x%x + (0x%x - 0x%x)) for 0x%x\n",
                      o_lpcAddr, iv_curWindowLpcOffset, i_reqAddr,
                      iv_curWindowOffset, o_chunkLen);
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
                    "astMboxDD::adjustWindow using protocol version: %d",
                    iv_protocolVersion);
        uint32_t l_blockMask = (1u << iv_blockShift) - 1;
        l_pos = i_reqAddr & ~l_blockMask;
        l_reqSize = (((i_reqAddr + i_reqSize) + l_blockMask) & ~l_blockMask)
                      - l_pos;

        TRACDCOMP(g_trac_pnor, "adjustWindow opening %s window at 0x%08x"
                  " for addr 0x%08x req_size 0x%08x",
                  i_isWrite ? "write" : "read", l_pos, i_reqAddr, l_reqSize);

        uint8_t cmd = i_isWrite ? HIOMAP_C_CREATE_WRITE_WINDOW
                                : HIOMAP_C_CREATE_READ_WINDOW;
        HiomapMessage* winMsg = new HiomapMessage(cmd);
        winMsg->put16(0, l_pos >> iv_blockShift);
        winMsg->put16(2, l_reqSize >> iv_blockShift);

        size_t l_len = 4;
        l_err = sendCommand(winMsg, l_len);

        assert(l_len == 6);

        if (!l_err)
        {
            iv_curWindowLpcOffset = winMsg->get16(0) << iv_blockShift;
            iv_curWindowSize = winMsg->get16(2) << iv_blockShift;
            iv_curWindowOffset = winMsg->get16(4) << iv_blockShift;
        }

        delete winMsg;

        if (l_err)
        {
            break;
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

errlHndl_t PnorIpmiDD::writeDirty(uint32_t i_addr, size_t i_size)
{
    errlHndl_t l_err = NULL;

    /* To pass a correct "size" for both protocol versions, we
     * calculate the block-aligned start and end.
     */
    uint32_t l_blockMask = (1u << iv_blockShift) - 1;
    uint32_t l_start     = i_addr & ~l_blockMask;
    uint32_t l_end       = ((i_addr + i_size) + l_blockMask) & ~l_blockMask;

    HiomapMessage* dirtyMsg = new HiomapMessage(HIOMAP_C_MARK_DIRTY);

    dirtyMsg->put16(0, (i_addr - iv_curWindowOffset) >> iv_blockShift);
    dirtyMsg->put16(2, (l_end - l_start)  >> iv_blockShift);

    size_t l_len = 4;
    l_err = sendCommand(dirtyMsg, l_len);

    delete dirtyMsg;

    return l_err;
}

errlHndl_t PnorIpmiDD::writeFlush(void)
{
    errlHndl_t l_err = NULL;
    HiomapMessage* flushMsg = new HiomapMessage(HIOMAP_C_FLUSH);

    size_t l_len = 0;
    l_err = sendCommand(flushMsg, l_len);

    delete flushMsg;

    return l_err;
}

/**
 * @brief Write data to PNOR using Mbox LPC windows
 */
errlHndl_t PnorIpmiDD::_writeFlash( uint32_t i_addr,
                                    size_t i_size,
                                    const void* i_data )
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"PnorIpmiDD::_writeFlash(i_addr=0x%.8X)> ", i_addr);
    errlHndl_t l_err = NULL, l_flushErr = NULL;

    while (i_size)
    {
        uint32_t l_lpcAddr;
        size_t l_chunkLen;

        l_err = adjustWindow(true, i_addr, i_size, l_lpcAddr, l_chunkLen);

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
errlHndl_t PnorIpmiDD::_readFlash( uint32_t i_addr,
                                   size_t i_size,
                                   void* o_data )
{
    TRACDCOMP(g_trac_pnor, "PnorIpmiDD::_readFlash(i_addr=0x%.8X)> ", i_addr);
    errlHndl_t l_err = NULL;

    while (i_size)
    {
        uint32_t l_lpcAddr;
        size_t l_chunkLen;

        l_err = adjustWindow(false, i_addr, i_size, l_lpcAddr, l_chunkLen);
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
uint32_t PnorIpmiDD::getNorSize( void )
{
    return iv_flashSize;
}

/**
 * @brief Retrieve bitstring of NOR workarounds
 */
uint32_t PnorIpmiDD::getNorWorkarounds( void )
{
    return 0;
}

errlHndl_t PnorIpmiDD::sendCommand(HiomapMessage*& io_msg, size_t& io_len)
{
    IPMI::completion_code l_cc = IPMI::CC_UNKBAD;
    errlHndl_t l_err = NULL;

    io_msg->iv_seq = iv_sequence++;

    uint8_t old_cmd = io_msg->iv_cmd;
    uint8_t old_seq = io_msg->iv_seq;
    uint8_t* l_data = reinterpret_cast <uint8_t*>((char*)io_msg);
    size_t l_len = io_len + 2; /* Account for command and sequence number */

    do {
        l_err = IPMI::sendrecv(
                    IPMI::pnor_hiomap_request(), l_cc, l_len, l_data);
        if (l_err)
        {
            break;
        }

        if (l_cc != IPMI::CC_OK)
        {
            TRACFCOMP( g_trac_pnor, "HIOMAP command failed with err %d", l_cc);

            /*@
             * @errortype
             * @moduleid     PNOR::MOD_IPMIPNORDD_SEND_MESSAGE
             * @reasoncode   PNOR::RC_HIOMAP_ERROR_STATUS
             * @userdata1[48:55] mbox status 1 reg
             * @userdata1[56:63] reserved
             * @userdata2[32:39] original command code
             * @userdata2[40:47] reserved
             * @userdata2[48:55] sequence number
             * @userdata2[56:63] status code
             * @devdesc      astMbox::doMessage> Timeout waiting for
             *               message response
             * @custdesc     BMC not responding while accessing the flash
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_IPMIPNORDD_SEND_MESSAGE,
                                            PNOR::RC_HIOMAP_ERROR_STATUS,
                                          TWO_UINT8_TO_UINT16(iv_bmcStatus, 0),
                                            FOUR_UINT8_TO_UINT32(old_cmd,
                                                    0,
                                                    old_seq,
                                                    l_cc));

            // Limited in callout: no PNOR target, so calling out
            //                  Service Processor
            l_err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);

            l_err->collectTrace(PNOR_COMP_NAME);

            /* There is no message body */
            *io_msg = NULL;

            break;
        }

        /* Don't look too closely, storage size doesn't necessarily match */
        assert(l_len >= 2);
        io_msg = reinterpret_cast<HiomapMessage *>((char *)l_data);

        if (old_seq != io_msg->iv_seq)
        {
            TRACFCOMP( g_trac_pnor, "bad sequence number in HIOMAP message, got %d want %d",
                       io_msg->iv_seq, old_seq);

            /*@
             * @errortype
             * @moduleid     PNOR::MOD_IPMIPNORDD_SEND_MESSAGE
             * @reasoncode   PNOR::RC_HIOMAP_BAD_SEQUENCE
             * @userdata1[48:55] mbox status 1 reg
             * @userdata1[56:63] reserved
             * @userdata2[32:39] original command code
             * @userdata2[40:47] reserved
             * @userdata2[48:55] sequence wanted
             * @userdata2[56:63] sequence obtained
             * @devdesc      astMbox::doMessage> Timeout waiting for
             *               message response
             * @custdesc     BMC not responding while accessing the flash
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_IPMIPNORDD_SEND_MESSAGE,
                                            PNOR::RC_HIOMAP_BAD_SEQUENCE,
                                          TWO_UINT8_TO_UINT16(iv_bmcStatus, 0),
                                            FOUR_UINT8_TO_UINT32(old_cmd,
                                                    io_msg->iv_cmd,
                                                    old_seq,
                                                    io_msg->iv_seq));

            // Limited in callout: no PNOR target, so calling out
            //                  Service Processor
            l_err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);

            l_err->collectTrace(PNOR_COMP_NAME);

            /*
             * We're returning an errl, so provide consistency by cleaning up
             * the response message
             */
            delete io_msg;
            io_msg = NULL;

            // Tell code below that we generated the error (not an LPC error)
            break;
        }

        /* Output just the sum of the length of the arguments */
        io_len = l_len - 2;
    } while(0);

    /* Shut it down on error for the moment */
    if (l_err) {
        l_err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        ERRORLOG::errlCommit(l_err, PNOR_COMP_ID);
        INITSERVICE::doShutdown( PNOR::RC_PNOR_INIT_FAILURE );
    }

    return l_err;
}

errlHndl_t PnorIpmiDD::getInfo( void )
{
    errlHndl_t l_err = NULL;

    HiomapMessage* l_msg = new HiomapMessage(HIOMAP_C_GET_INFO);
    l_msg->put8(0, HIOMAP_V_2); /* Protocol version */

    do {
        size_t l_len = 1;
        l_err = sendCommand(l_msg, l_len);

        if (l_err)
        {
            break;
        }

        assert(l_len > 1);
        iv_protocolVersion = l_msg->get8(0);

        assert(iv_protocolVersion > 1); /* Version check */
        assert(l_len >= 1 + 1 + 2 );

        iv_blockShift = l_msg->get8(1);
    } while(0);

    delete l_msg;

    return l_err;
}

errlHndl_t PnorIpmiDD::getFlashInfo( void )
{
    errlHndl_t l_err = NULL;

    HiomapMessage* l_flashMsg = new HiomapMessage(HIOMAP_C_GET_FLASH_INFO);

    do {
        size_t l_len = 0;
        l_err = sendCommand(l_flashMsg, l_len);
        if (l_err)
        {
            break;
        }
        assert(l_len == 4);

        iv_flashSize = l_flashMsg->get16(0) << iv_blockShift;
        iv_flashEraseSize = l_flashMsg->get16(2) << iv_blockShift;
    } while (0);

    delete l_flashMsg;

    return l_err;
}

errlHndl_t PnorIpmiDD::initialiseHiomap( void )
{
    errlHndl_t l_err = NULL;

    l_err = getInfo();
    if (l_err)
    {
        return l_err;
    }

    l_err = getFlashInfo();
    if (l_err)
    {
        return l_err;
    }

    return NULL;
}

void *hiomap_event_task(void *context)
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK "%s", __func__);
    uint8_t *bmcStatus = static_cast<uint8_t *>(context);

    task_detach();

    msg_q_t msgQ = msg_q_create();

    IPMI::register_for_event(IPMI::hiomap_event(), msgQ);

    while (true) {
        msg_t* msg = msg_wait(msgQ);

        IPMI::oemSEL* event = reinterpret_cast<IPMI::oemSEL*>(msg->extra_data);
        *bmcStatus = event->iv_cmd[1];
        lwsync();
        TRACFCOMP(g_trac_pnor, "Received HIOMAP event: status is 0x%x",
                 *bmcStatus);

        /* TODO: Improve handling of events */
    }

    TRACFCOMP(g_trac_pnor, EXIT_MRK "%s", __func__);
    return NULL;
}

/**
 * @brief  Constructor
 */
PnorIpmiDD::PnorIpmiDD( TARGETING::Target* i_target )
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK "%s: PnorDD::PnorDD()", __FILE__ );
    printk("Using HIOMAP PNOR with IPMI transport\n");

    errlHndl_t l_err = NULL;

    task_create(&hiomap_event_task, &iv_bmcStatus);

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

        // Master target could collide and cause deadlocks with PnorIpmiDD singleton
        // used for ddRead/ddWrite with MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
        assert( type_enum != TARGETING::PROC_MASTER_TYPE_ACTING_MASTER );

        // Initialize and use class-specific mutex
        iv_mutex_ptr = &iv_mutex;
        mutex_init(iv_mutex_ptr);
        TRACFCOMP(g_trac_pnor, "PnorIpmiDD::PnorIpmiDD()> Using i_target=0x%X (non-master) and iv_mutex_ptr",
                  TARGETING::get_huid(i_target));
    }
    else
    {
        iv_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        iv_mutex_ptr = &(cv_mutex);
    }

    l_err = initialiseHiomap();
    if( l_err )
    {
        TRACFCOMP( g_trac_pnor, "Failure to initialize the PNOR logic, shutting down :: RC=%.4X", ERRL_GETRC_SAFE(l_err) );
        l_err->collectTrace(PNOR_COMP_NAME);
        ERRORLOG::errlCommit(l_err, PNOR_COMP_ID);
        INITSERVICE::doShutdown( PNOR::RC_PNOR_INIT_FAILURE );
    }

    iv_curWindowOpen = false;

    TRACFCOMP(g_trac_pnor, EXIT_MRK "%s: PnorDD::PnorDD()", __FILE__ );
}

/**
 * @brief  Destructor
 */
PnorIpmiDD::~PnorIpmiDD()
{
}
