/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/ocmb_spd.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#include <vpd/spdenums.H>
#include <devicefw/driverif.H>
#include <i2c/eeprom_const.H>
#include <errl/errlentry.H>
#include <vpd/vpdreasoncodes.H>

extern trace_desc_t * g_trac_spd;

namespace SPD
{

/**
 * @brief Handle SPD READ deviceOp to OCMB_CHIP targets
 * This function performs read operations on OCMBs by in turn performing
 * an EEPROM deviceOp on this target, reading the first 2 KB of the OCMB's
 * Primary VPD eeprom and returning it via a buffer
 *
 * @param[in]     i_opType    Operation type, see driverif.H
 * @param[in]     i_target    MMIO target
 * @param[in/out] io_buffer   Read:   Pointer to output data storage
 *                            Write:  Pointer to input data storage
 * @param[in/out] io_buflen   Input:  Read:  size of data to read (in bytes)
 *                            Output: Read:  Size of output data
 * @param[in]   i_accessType  Access type
 * @param[in]   i_args        This is an argument list for DD framework.
 *                            In this function, there is one argument,
 *                            the l_keyword, so far we only support ENTIRE_SPD
 * @return  errlHndl_t
 *
 * NOTE: ONLY ENTIRE_SPD READ SUPPORTED CURRENTLY
 */
errlHndl_t ocmbSPDPerformOp(DeviceFW::OperationType i_opType,
                            TARGETING::Target* i_target,
                            void* io_buffer,
                            size_t& io_buflen,
                            int64_t i_accessType,
                            va_list i_args);

// Register the perform Op with the routing code for OCMBs.
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::SPD,
                       TARGETING::TYPE_OCMB_CHIP,
                       ocmbSPDPerformOp );

/**
 * @brief Read keyword from SPD
 *
 *        Currently used to detect I2C_MUTEX and OCMB_CHIP targets
 *
 * @param[in]     i_target     OCMB target to read data from
 * @param[in]     i_keyword    keyword from spdenums.H to read
 * @param[in/out] io_buffer    databuffer SPD will be written to
 * @param[in]     i_buflen     length of the given data buffer
 *
 * @pre io_buffer and i_target must be non-null
 * @pre currenlty only supported value for i_keyword is ENTIRE_SPD
 *
 * @return  errlHndl_t
 */
errlHndl_t ocmbGetSPD(const TARGETING::Target* i_target,
                      const uint64_t & i_keyword,
                      void* const io_buffer,
                      const size_t& i_buflen)
{
    errlHndl_t l_errl = nullptr;

    TRACFCOMP( g_trac_spd,
                ENTER_MRK"ocmbGetSPD()" );

    // If any of these asserts fail it is a SW error
    assert(io_buffer != nullptr, "io_buffer is nullptr in ocmbGetSPD");
    assert(i_target != nullptr, "i_target is nullptr in ocmbGetSPD");
    assert(i_buflen >= SPD::OCMB_SPD_EFD_COMBINED_SIZE, "Buffer must be at least 2 KB in ocmbGetSPD");

    do {

        if(i_keyword != ENTIRE_SPD)
        {
            TRACFCOMP( g_trac_spd,
                       "ocmbGetSPD() only entire SPD currently supported, 0x%X is not supported",
                       i_keyword);
            /*@
            * @errortype
            * @moduleid     VPD::VPD_OCMB_GET_SPD
            * @reasoncode   VPD::VPD_NOT_SUPPORTED
            * @userdata1    Keyword Enum
            * @userdata2    Target huid
            * @devdesc      Attempted to lookup SPD keyword not supported
            * @custdesc     Firmware error during system IPL
            */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            VPD::VPD_OCMB_GET_SPD,
                                            VPD::VPD_NOT_SUPPORTED,
                                            i_keyword,
                                            i_target->getAttr<TARGETING::ATTR_HUID>(),
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;

        }
        size_t l_spdReadBufferLen = SPD::OCMB_SPD_EFD_COMBINED_SIZE;

        l_errl = DeviceFW::deviceOp(DeviceFW::READ,
                                    const_cast<TARGETING::Target*>(i_target),
                                    io_buffer,
                                    l_spdReadBufferLen,
                                    DEVICE_EEPROM_ADDRESS(EEPROM::VPD_PRIMARY,
                                                          0,
                                                          EEPROM::AUTOSELECT)
                                    );


    }while(0);

    return l_errl;
}

// See above for details
errlHndl_t ocmbSPDPerformOp(DeviceFW::OperationType i_opType,
                            TARGETING::Target* i_target,
                            void* io_buffer,
                            size_t& io_buflen,
                            int64_t i_accessType,
                            va_list i_args)
{
    errlHndl_t l_errl = nullptr;
    const uint64_t l_keyword = va_arg(i_args, uint64_t);
    l_errl = ocmbGetSPD(i_target, l_keyword, io_buffer, io_buflen);
    return l_errl;
}


}
