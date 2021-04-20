/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_scomAccessdd.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
 * @file sbe_scomAccess.C
 * @brief SCOM Access Message client interface
 */

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <devicefw/driverif.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbeioreasoncodes.H>
#include "sbe_fifodd.H"

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"ScomAccessDD: " printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"ScomAccessDD: " printf_string,##args)

namespace SBEIO
{

/**
 * @brief Performs a SBE FIFO device driver get/put scom operation
 *
 *        Provides device driver interface to scom operations to be
 *        used, for example, the scom device driver. This is a wrapper
 *        to the fifo scom client interfaces.
 *
 * @param[in]     i_opType      Operation type, see DeviceFW::OperationType
 * @param[in]     i_target      Target
 * @param[in/out] io_pBuffer    Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size must be 8 bytes
 *                              Output: Success = input value, Failure = 0
 * @param[in]     i_accessType  DeviceFW::AccessType enum
 * @param[in]     i_args        This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the address
 * @return  errlHndl_t
 */
errlHndl_t ddFifoScomChipOp(DeviceFW::OperationType i_opType,
                TARGETING::Target* i_target,
                void   * io_pBuffer,
                size_t & io_buflen,
                int64_t  i_accessType,
                va_list  i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t i_addr = va_arg(i_args,uint64_t);

    SBE_TRACD(ENTER_MRK "ddFifoChipOp: i_addr=%llX, target=%.8X",
                        i_addr, TARGETING::get_huid(i_target) );
    do
    {
        uint64_t l_data = 0;
        // validate data length
        if (unlikely( ( io_buflen != sizeof(uint64_t) )))
        {
            SBE_TRACF(ERR_MRK"fifoScomInterfaceChecks: "
                             "Invalid data length : io_buflen=%d",
                              io_buflen );
            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_INVALID_LENGTH
             * @userdata1    Request Address
             * @userdata2    Invalid request length
             * @devdesc      Request length must be 8 bytes
             * @custdesc     Firmware error communicating with boot device
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SBEIO_FIFO,
                                           SBEIO_FIFO_INVALID_LENGTH,
                                           i_addr,
                                           TO_UINT64(io_buflen),
                                           true /*SW error*/);
            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            l_err->collectTrace(SBEIO_COMP_NAME);
            break;
        }

        // do the read
        if( DeviceFW::READ == i_opType )
        {
            l_err = getFifoScom(i_target,
                                i_addr,
                                l_data);
            if (l_err) break;

            //return data to caller
            memcpy(io_pBuffer,&l_data,sizeof(uint64_t));
        }
        // do the write
        else if( DeviceFW::WRITE == i_opType )
        {
            //get data from caller
            memcpy(&l_data,io_pBuffer,sizeof(uint64_t));

            l_err = putFifoScom(i_target,
                                i_addr,
                                l_data);
            if (l_err) break;
        }
        else
        {
            SBE_TRACF(ERR_MRK "ddFifoChipOp: Invalid Op Type = %d",
                               i_opType );
            /*@
             * @errortype
             * @moduleid     SBEIO_FIFO
             * @reasoncode   SBEIO_FIFO_INVALID_OPERATION
             * @userdata1    Request Address
             * @userdata2    Request operation
             * @devdesc      Invalid operation. Read and Write supported.
             * @custdesc     Firmware error communicating with boot device
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SBEIO_FIFO,
                                            SBEIO_FIFO_INVALID_OPERATION,
                                            i_addr,
                                            TO_UINT64(i_opType),
                                            true /*SW error*/);
            l_err->collectTrace(SBEIO_COMP_NAME);
        }

    }
    while(0);

    if ( l_err )
    {
        // On fail, assume no data was read or written
        io_buflen = 0;
    }

    return l_err;
};

/**
* @brief Performs a SBE PSU device driver get scom operation
*
*        Provides device driver interface to scom operations to be
*        used, for example, the scom device driver. This is a wrapper
*        to the psu scom client interfaces.
*
* @param[in]     i_opType      Operation type, see DeviceFW::OperationType
* @param[in]     i_target      Target
* @param[in/out] io_pBuffer    Read: Pointer to output data storage
* @param[in/out] io_buflen     Input: size must be 8 bytes
*                              Output: Success = input value, Failure = 0
* @param[in]     i_accessType  DeviceFW::AccessType enum
* @param[in]     i_args        This is an argument list for DD framework.
*                              In this function, there's only one argument,
*                              containing the address
* @return  errlHndl_t
*/
errlHndl_t ddPsuScomChipOp(DeviceFW::OperationType i_opType,
                            TARGETING::Target* i_target,
                            void   * io_pBuffer,
                            size_t & io_buflen,
                            int64_t  i_accessType,
                            va_list  i_args)
{
    errlHndl_t errl = nullptr;
    uint64_t address = va_arg(i_args,uint64_t);

    SBE_TRACD(ENTER_MRK "ddPsuScomChipOp: i_addr=%llX, target=%.8X",
                        address, TARGETING::get_huid(i_target) );
    do{
        if(i_opType != DeviceFW::READ)
        {
            SBE_TRACF(ERR_MRK "Currently psu scom writes are not supported");
            /*@
             * @errortype
             * @moduleid     SBEIO_PSU
             * @reasoncode   SBEIO_PSU_INVALID_OPERATION
             * @userdata1    Request Address
             * @userdata2    Request operation
             * @devdesc      Invalid operation. Only PSU Scom Reads are supported
             * @custdesc     Firmware error communicating with boot device
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SBEIO_PSU,
                                            SBEIO_PSU_INVALID_OPERATION,
                                            address,
                                            TO_UINT64(i_opType),
                                            true /*SW error*/);
            errl->collectTrace(SBEIO_COMP_NAME);
            break;
        }
        assert(io_buflen == sizeof(uint64_t) ,
               "We only support read lengths of 8 bytes for PSU scom ops");
        errl = sendPsuGetHwRegRequest(i_target,
                                      address,
                                      *static_cast<uint64_t *>(io_pBuffer));
    }while(0);

    SBE_TRACF(ENTER_MRK "ddPsuScomChipOp: value=%llX",
                    *static_cast<uint64_t *>(io_pBuffer) );

    return errl;
}

// Register fsidd access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::SBESCOM,
                      TARGETING::TYPE_PROC,
                      ddFifoScomChipOp);

// Register fsidd access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::SBESCOM,
                      TARGETING::TYPE_PROC,
                      ddFifoScomChipOp);

// Register psu get hw register operation to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SBESCOM,
                      TARGETING::TYPE_OCMB_CHIP,
                      ddPsuScomChipOp);

} //end namespace SBEIO

