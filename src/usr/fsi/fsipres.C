//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/fsi/fsipres.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#include <devicefw/driverif.H>
#include <targeting/common/attributes.H>
#include <fsi/fsi_reasoncodes.H>
#include "fsidd.H"

extern trace_desc_t* g_trac_fsi;

namespace FSI
{

// Forward declaration from fsidd.C.
bool isSlavePresent( const TARGETING::Target* i_target );

/**
 * @brief Performs a presence detect operation.
 *
 * This function does FSI presence detect, following the pre-defined prototype
 * for a device-driver framework function.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        Presence detect target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes, always 1)
 *                              Output: Success = 1, Failure = 0
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there are no arguments.
 * @return  errlHndl_t
 */
errlHndl_t presenceDetect(DeviceFW::OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args)
{
    if (io_buflen != sizeof(bool))
    {
        TRACFCOMP(g_trac_fsi,
                  ERR_MRK "FSI::presenceDetect> Invalid data length: %d",
                  io_buflen);
        /*@
         * @errortype
         * @moduleid     FSI::MOD_FSIPRES_PRESENCEDETECT
         * @reasoncode   FSI::RC_INVALID_LENGTH
         * @userdata1    Data Length
         * @devdesc      presenceDetect> Invalid data length (!= 1 bytes)
         */
        errlHndl_t l_errl =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        FSI::MOD_FSIPRES_PRESENCEDETECT,
                                        FSI::RC_INVALID_LENGTH,
                                        TO_UINT64(io_buflen));
        io_buflen = 0;
        return l_errl;
    }

    bool present = false;

    TARGETING::Target* l_masterChip = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_masterChip);

    if ((i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) ||
        (i_target == l_masterChip))
    {
        present = true;
    }
    else
    {
        present = isSlavePresent(i_target);
    }

    memcpy(io_buffer, &present, sizeof(present));
    io_buflen = sizeof(present);

    return NULL;
}

// Register as the presence detect for processor and memory buffers.
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PRESENT,
                      TARGETING::TYPE_PROC,
                      presenceDetect);
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PRESENT,
                      TARGETING::TYPE_MEMBUF,
                      presenceDetect);

};
