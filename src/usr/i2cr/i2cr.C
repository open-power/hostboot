/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2cr/i2cr.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
 *  @file src/usr/i2cr/i2cr.C
 *
 *  @brief Implementation of the I2CR device driver for Odyssey (DDR5)
 *         access via SCOM and CFAM(FSI) for Read & Write operations.
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <xscom/piberror.H>
#include <i2cr/i2cr_reasoncodes.H>
#include <scom/scomif.H>
#include <fsi/fsiif.H>
#include <i2c/i2cif.H>
#include <sys/time.h>
#include <utils/chipids.H>
#include "i2cr.H"
#include <arch/magic.H>
#include <console/consoleif.H>


//Globals/Constants

// Trace definition
trace_desc_t* g_trac_i2cr = NULL;
TRAC_INIT(&g_trac_i2cr, I2CR_COMP_NAME, 2*KILOBYTE); //2K

// Easy macro replace for unit testing
#define TRACUCOMP(args...)  TRACFCOMP(args)
//#define TRACUCOMP(args...)

using namespace I2C;
using namespace TARGETING;
using namespace POWER_CHIPID;

namespace I2CR
{

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/**
 *
 * @brief A utility function to swap bytes of specified size
 * @note  The caller is responsible for the input and output buffers
 *        are of valid i_sz size and also that they are different.
 *        This routine, with the current implementation will not support
 *        both the input and output buffers to be the same.
 *
 * @param [in]  i_val : input value
 * @param [out] o_val : buffer to return swapped value
 * @param [in]  i_sz  : input size
 *
 */
void swapBytes(void *i_val, void *o_val, size_t i_sz)
{
    if (i_sz == sizeof(uint32_t))
    {
        *(reinterpret_cast<uint32_t *>(o_val)) =
                   __builtin_bswap32(*(reinterpret_cast<uint32_t *>(i_val)));
    }
    else if (i_sz == sizeof(uint64_t))
    {
        *(reinterpret_cast<uint64_t *>(o_val)) =
                   __builtin_bswap64(*(reinterpret_cast<uint64_t *>(i_val)));
    }
    else
    {
        uint8_t *l_iptr =  reinterpret_cast<uint8_t*>(i_val);
        uint8_t *l_optr =  reinterpret_cast<uint8_t*>(o_val);

        for (size_t i=0; i<i_sz; i++)
        {
            l_optr[i] = l_iptr[i_sz-1-i];
        }
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/**
 *
 * @brief An inline function to convert the FSI/CFAM address to the i2CR
 *        format.
 * @note  Please refer to I2CR FW doc
 * @param [in]  i_addr : input FSI/CFAM address
 * @return l_addr : output i2cr address
 *
 */
inline uint32_t convertFsiCfamAddrToI2crAddr(const uint32_t i_addr)
{
    // Convert the FSI CFAM WORD address to the I2CR SCOM address used by OCMBs.
    uint32_t l_addr = (((i_addr & 0xFFFFFC00) >> 2) | (i_addr & 0x000001FF));
    TRACUCOMP( g_trac_i2cr, "convertFsiCfamAddrToI2CrAddr: 0x%x->0x%x",
               i_addr, l_addr);
    return l_addr;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/**
 *
 * @brief A utility routine to check the number of 1s in the input data
 * @note  This routine only supports 32bit or 64bit inputs
 *
 * @param [in]  i_data : input data
 * @param [in]  i_sz : input data size
 * @return value : 1(true) if number of 1s is odd and 0(false) if even
 *
 */
bool checkOddParity(void *i_data, size_t i_sz)
{
    uint32_t l_ones_count = 0;

    if (i_sz == sizeof(uint32_t))
    {
        l_ones_count = __builtin_popcount(*(reinterpret_cast<uint32_t *>(i_data)));
    }
    else
    {
        l_ones_count = __builtin_popcountll(*(reinterpret_cast<uint64_t *>(i_data)));
    }

    TRACUCOMP( g_trac_i2cr, "checkOddParity: l_ones_count=%d", l_ones_count);

    /* if l_ones_count is odd, least significant bit will be 1 */
    return (l_ones_count & 1);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/**
 *
 * @brief A utility routine to add the odd parity bit to the specified address.
 *        Only the bits 1 to 31 of Scom/Cfam address are used to compute the
 *        the I2CR address to access the OCMBs. These bits are left shifted
 *        by 1 bit to get the 0 to 30 bits of the I2CR address. The 31st
 *        bit of the I2CR address is the odd parity bit.
 *
 *        The way the parity bit value is computed depends of whether we are
 *        doing a read or a write operation. For a read operation, only the addr
 *        is considered. For a write operation, the parity bit is computed
 *        taking both the address and the data value that needs to be written
 *        out into account.
 *
 *        This routine assumes that the specified address is already left
 *        shifted by 1 position. The second input, i_writeDataIsOdd, says if
 *        the "data to be written" has an odd number of 1s. This should have
 *        already been checked by the caller using checkOddParity and that
 *        result is passed in this parameter. Please note this information
 *        is not relevant/applicable for a read operation!
 *
 * @note  From I2CR FW doc:
 *        -----------------
 *        Only bits 0 through 30 of the scom/PCB address are used to access the
 *        on chip registers. Bit 31 is the odd parity bit.
 *
 *        32 bit I2CR address = (SCOM/CFAM address [1:31]<<1) + Odd 31st Parity Bit
 *
 *        For a Read operation:
 *        Parity bit calculation is based on address only
 *
 *        For a Write operation:
 *        Parity bit calculation is done based on address + data to be written
 *
 *        Final Address word calculation : Input address [0:30] + Parity bit_31
 *
 * @param [in] i_addrData:  address data that needs the parity bit added
 * @param [in] i_writeDataIsOdd: This field tells if the associated data has odd
 *                               number of 1's or not. This field is false for a
 *                               read operation. For write, a value of true implies
 *                               data has odd number of 1s and false implies even.
 * @return i_addrData : addr data with the parity bit added
 *
 */
 uint32_t setOddParityBit( uint32_t i_addrData, bool i_writeDataIsOdd = false )
 {
     // The input address is expected to be shifted; so the valid
     // address bits are 0 to 30. We don't care the bit value of
     // of the 31st bit for parity calculation.
     uint32_t l_addr = i_addrData & 0xFFFFFFFE;

     bool l_addrIsOddParity = checkOddParity(&l_addr, sizeof(uint32_t));

     // Check if the other data fields (for a write operation)
     // need to be considered to adjust the final l_parity bit
     // setting.
     // NOTE: For Read operations, writeDataIsOdd is false.
     if (i_writeDataIsOdd)
     {
         // Flip the  addr parity as data has odd # of 1s.
         l_addrIsOddParity = l_addrIsOddParity ^ 1;
     }

     // Set the odd parity bit in the passed in address.
     if ( !l_addrIsOddParity )
     {
         i_addrData |= 0x00000001;
     }
     else
     {
         i_addrData &= ~0x00000001;
     }

     TRACUCOMP( g_trac_i2cr, "setOddParityBit: With l_parity: 0x%x", i_addrData);
     return i_addrData;
 }

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/**
 *
 * @brief A utility routine to fetch the i2cr control info
 *
 * @param [in] i_target : I2CR OCMB chip target
 * @param [in/out] io_i2cInfo : buffer to return the i2c control info
 * @return l_err : An error that is set in this routine
 *
 */
errlHndl_t readI2crAttributes( Target * i_target,
                               ATTR_FAPI_I2C_CONTROL_INFO_type & io_i2cInfo )
{
     errlHndl_t l_err = nullptr;

     if (!(i_target->tryGetAttr<ATTR_FAPI_I2C_CONTROL_INFO>(io_i2cInfo)))
     {
          TRACFCOMP( g_trac_i2cr,
                     ERR_MRK"readI2crAttributes() - ERROR reading "
                     "attributes for target huid 0x%.8X",
                      get_huid(i_target) );

          /*@
           * @errortype
           * @reasoncode       I2CR::RC_ATTR_NOT_FOUND
           * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
           * @moduleid         I2CR::MOD_I2CR_PERFORM_OP
           * @userdata1        HUID of target
           * @devdesc          FAPI_I2C_CONTROL_INFO attribute was not found
           * @custdesc         A problem occurred during the IPL
           *                   of the system.
           */
          l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           I2CR::MOD_I2CR_PERFORM_OP,
                                           I2CR::RC_ATTR_NOT_FOUND,
                                           get_huid(i_target),
                                           0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

          ERRORLOG::ErrlUserDetailsTarget(i_target,"OCMBs I2CR SCOM/CFAM Target").addToLog(l_err);
          l_err->collectTrace( I2CR_COMP_NAME );
     }
     return l_err;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/**
 *
 * @brief A function to do the generic i2cr Read Operation
 *
 * @param [in] i_regaddr : I2CR register address already shifted appropriately
 *                         by the caller based on whether its SCOM or CFAM
 * @param [in] i_target : Target OCMB chip
 * @param [in/out] io_buffer : buffer to return data read
 * @param [in/out] io_buflen : read size
 * @param [in] io_i2cInfo : i2c control info
 * @return l_err : An error that is set in this routine
 *
 */
errlHndl_t i2cr_generic_read( uint32_t i_regaddr,
                               Target* i_target,
                               void* io_buffer,
                               size_t& io_buflen,
                               const ATTR_FAPI_I2C_CONTROL_INFO_type & i_i2cInfo)
 {
     constexpr uint8_t OFFSET_SIZE = 4;
     errlHndl_t l_err = NULL;
     uint32_t l_regaddr = 0;
     uint8_t l_regaddr8[sizeof(l_regaddr)] = {0};

     // Determine the I2CR Master HUB chip associated with the OCMB chip
     TargetService& ts = targetService();
     Target *l_i2crMaster = ts.toTarget(i_i2cInfo.i2cMasterPath);

     TRACUCOMP( g_trac_i2cr, ENTER_MRK"i2cr_generic_read> regaddr:0x%x, "
                "target=0x%X (0x%.8X)",
                i_regaddr, i_target, get_huid(i_target));

     // Add the parity bit. The address is expected to be already shifted based on
     // the access type SCOM Vs CFAM.
     l_regaddr = setOddParityBit(i_regaddr);

     // Bytes are sent in reverse order as HB is big endian and
     // we need to send data to OCMBs in little endian format.
     swapBytes(&l_regaddr, l_regaddr8, sizeof(l_regaddr));

     do
     {
         TRACUCOMP( g_trac_i2cr, "i2cr_generic_read> Reading (0x%x bytes) from"
                    " 0x%.8X using e%d/p%d/a=0x%x",
                    io_buflen, *(reinterpret_cast<uint32_t *>(l_regaddr8)),
                    i_i2cInfo.engine, i_i2cInfo.port, i_i2cInfo.devAddr );
         l_err = deviceOp( DeviceFW::READ,
                           l_i2crMaster,
                           io_buffer,
                           io_buflen,
                           DEVICE_I2C_ADDRESS_OFFSET(
                                                     i_i2cInfo.port,
                                                     i_i2cInfo.engine,
                                                     i_i2cInfo.devAddr,
                                                     OFFSET_SIZE,
                                                     l_regaddr8,
                                                     i_i2cInfo.i2cMuxBusSelector,
                                                     &(i_i2cInfo.i2cMuxPath) ) );

         if( l_err )
         {
             TRACFCOMP( g_trac_i2cr, "i2cr_generic_read> Read Error" );
             l_err->addHwCallout(i_target, HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::NO_DECONFIG,HWAS::GARD_NULL);
             l_err->collectTrace(I2CR_COMP_NAME);
             break;
         }

         // data comes back in reverse order
         // Please note HB is BE and we get data in LE.
         uint8_t swapped[io_buflen] = {0};
         swapBytes(io_buffer, swapped, io_buflen);

         TRACDCOMP(g_trac_i2cr, EXIT_MRK"i2cr_generic_read> 0x%.8X", i_regaddr);
         TRACDBIN(g_trac_i2cr, "io_buffer=", io_buffer, io_buflen);
         TRACDBIN(g_trac_i2cr, "swapped_buffer=", swapped, io_buflen);
         // Return data in swapped format
         memcpy(io_buffer, swapped, io_buflen);

     } while (0);

     return l_err;
 }

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/**
 *
 * @brief A function to do the generic i2cr Write Operation
 *
 * @param [in] i_regaddr : I2CR register address already shifted appropriately
 *                         by the caller based on whether its SCOM or CFAM
 * @param [in] i_target : Target OCMB chip
 * @param [in/out] io_buffer : buffer with data to be written
 * @param [in/out] io_buflen : buffer size
 * @param [in] i_i2cInfo : i2c control info
 * @param [out] l_err : An error that is set in this routine
 *
 */
 errlHndl_t i2cr_generic_write( uint32_t i_regaddr,
                                Target* i_target,
                                void* io_buffer,
                                size_t& io_buflen,
                                const ATTR_FAPI_I2C_CONTROL_INFO_type & i_i2cInfo)
 {
     constexpr uint8_t OFFSET_SIZE = 4;
     errlHndl_t l_err = NULL;
     uint32_t l_regaddr = 0;
     uint8_t l_regaddr8[sizeof(l_regaddr)] = {0};
     uint8_t l_swapped[io_buflen] = {0};

     // Determine the I2CR Master HUB chip associated with the OCMB chip
     TargetService& ts = targetService();
     Target *l_i2crMaster = ts.toTarget(i_i2cInfo.i2cMasterPath);

     TRACDCOMP( g_trac_i2cr, ENTER_MRK"i2cr_generic_write> Enter: "
                "regaddr:0x%x, target=0x%X",
                i_regaddr, i_target);
     TRACDBIN(g_trac_i2cr, "io_buffer=", io_buffer, io_buflen);

     // Add the parity bit. In order to set the parity bit for a write operation,
     // we need to detemine if the data that needs to be written out has an odd
     // parity or not. The final parity bit setting is based on the number of 1s
     // in both data and address.
     bool l_data_parity = checkOddParity(io_buffer, io_buflen);

     // Now pass the info about data's parity to the routine that checks the
     // parity of the specified  address and sets the odd parity bit based on
     // the parity of both address and data.
     l_regaddr = setOddParityBit(i_regaddr, l_data_parity);

     // Bytes are sent in reverse order
     // Please note HB is BE and we need to send data in LE.
     swapBytes(&l_regaddr, l_regaddr8, sizeof(l_regaddr));

     // Swap the input data that needs to be written
     swapBytes(io_buffer, l_swapped, io_buflen);

     do
     {
         TRACUCOMP( g_trac_i2cr, "i2cr_generic_write> Writing 0x%x bytes to 0x%.8X from e%d/p%d/a=0x%x",
                    io_buflen, *(reinterpret_cast<uint32_t *>(l_regaddr8)), i_i2cInfo.engine,
                    i_i2cInfo.port, i_i2cInfo.devAddr );
         l_err = deviceOp( DeviceFW::WRITE,
                           l_i2crMaster,
                           l_swapped,
                           io_buflen,
                           DEVICE_I2C_ADDRESS_OFFSET(
                                                     i_i2cInfo.port,
                                                     i_i2cInfo.engine,
                                                     i_i2cInfo.devAddr,
                                                     OFFSET_SIZE,
                                                     l_regaddr8,
                                                     i_i2cInfo.i2cMuxBusSelector,
                                                     &(i_i2cInfo.i2cMuxPath) ) );
         if( l_err )
         {
             TRACFCOMP( g_trac_i2cr, "i2cr_generic_write> Write Error" );
             l_err->addHwCallout(i_target, HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::NO_DECONFIG,HWAS::GARD_NULL);
             l_err->collectTrace(I2CR_COMP_NAME);
             break;
         }

     } while(0);

     return l_err;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


/**
 *
 * @brief A function to do the I2CR R/W operations
 *
 * @param [in] i_opType : operation type (READ or WRITE)
 * @param [in] i_target : Target OCMB chip
 * @param [in/out] io_buffer : buffer with data to be written
 * @param [in/out] io_buflen : buffer size
 * @param [in] i_accessType : access type (SCOM/CFAM)
 * @param [in] i_args : i2cr register address (SCOM or CFAM word addr)
 * @return l_err : An error that is set in this routine
 *
 */
errlHndl_t i2crPerformOp(DeviceFW::OperationType i_opType,
                             Target* i_target,
                             void* io_buffer,
                             size_t& io_buflen,
                             int64_t i_accessType,
                             va_list i_args)
{
    // The input i2cr address is either a SCOM address or CFAM(FSI) word address
    uint64_t l_i2crAddr = va_arg(i_args,uint64_t);
    uint32_t l_shiftedI2crAddr = 0;
    ATTR_FAPI_I2C_CONTROL_INFO_type l_i2cInfo;
    errlHndl_t l_err = NULL;

    TRACUCOMP( g_trac_i2cr, ENTER_MRK"i2crPerformOp> Addr=0x%.16x io_buflen=0x%x",
               l_i2crAddr, io_buflen );
    do
    {

        // Validate Scom/CFAM Address
        if( (l_i2crAddr & 0xFFFFFFFF80000000) != 0)
        {
            TRACFCOMP( g_trac_i2cr, ERR_MRK "i2crPerformOp> Address "
                       "contains more than 31 bits : l_i2crAddr=0x%.16X", l_i2crAddr );
            /*@
             * @errortype
             * @moduleid     I2CR::MOD_I2CR_PERFORM_OP
             * @reasoncode   I2CR::RC_INVALID_ADDRESS
             * @userdata1    SCOM Address
             * @userdata2    Target HUID
             * @devdesc      i2crPerformOp> Address contains
             *               more than 31 bits.
             * @custdesc     A problem occurred during the IPL of the system:
             *               Invalid address on a register R/W operation.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            I2CR::MOD_I2CR_PERFORM_OP,
                                            I2CR::RC_INVALID_ADDRESS,
                                            l_i2crAddr,
                                            get_huid(i_target));

            ERRORLOG::ErrlUserDetailsTarget(i_target,
                      "OCMBs I2CR SCOM/CFAM Target").addToLog(l_err);
            break;
        }

        // Handle any address shifts based on the access type
        // --------------------------------------------------------------------------------
        //
        // There are two I2CR access types supported: Scom & FSI/CFAM.
        //
        // The I2CR address is formed using the bits [1:31] of the Scom address. These
        // bits are left shifted by 1 to form the bits [0:30] of the I2CR address. The
        // 31st bit of the I2CR address is the Odd Parity bit.
        // The FSI/CFAM word address is first converted to a Scom address and then shifted
        // left by 1 bit to form the I2CR address.
        // Note: The I2CR address is equal to the FSI Byte address divided by 4.
        //       This driver expects only the FSI/CFAM word address.
        //
        // The following algorithm is used to determine the Odd parity bit value.
        //
        // Parity (write operation) = Odd Parity (SCOM address [1:31] & Write data [0:63])
        // Parity (read operation) = Odd Parity (SCOM address [1:31] )
        // Address_on_I2C_lines (0 : 31) = SCOM address [1:31] & parity
        //
        // Examples:
        //   Scom addr: 0xf000f, Shifted I2CR addr: 0x1e001e, With Parity: 0x1e001f
        //   CFAM register 0x100A (FSI byte address 0x1028)
        //   Converted I2CR addr (no shift): 0x040A, Shifted I2CR addr: 0x814,
        //   With Parity: 0x814
        //
        // --------------------------------------------------------------------------------
        if (i_accessType == DeviceFW::I2CR_SCOM)
        {
            l_shiftedI2crAddr = l_i2crAddr << 1;
        }
        else if ((i_accessType == DeviceFW::I2CR_CFAM) ||
                 (i_accessType == DeviceFW::CFAM))
        {
            l_shiftedI2crAddr = convertFsiCfamAddrToI2crAddr(l_i2crAddr) << 1;
        }
        else
        {
            TRACFCOMP( g_trac_i2cr, ERR_MRK"i2crPerformOp> Unsupported Access Type: i_accessType=0x%x)",
                       i_accessType);
            /*@
             * @errortype
             * @moduleid     I2CR::MOD_I2CR_PERFORM_OP
             * @reasoncode   I2CR::RC_INVALID_ACCESSTYPE
             * @userdata1[0:31]    Access type: I2CR_SCOM or I2CR_CFAM
             * @userdata1[32:64]   Input Scom address
             * @userdata2    Target HUID
             * @devdesc      i2crPerformOp> Unsupported Access Type specified
             * @custdesc     A problem occurred during the IPL of the system:
             *               Unsupported I2CR Access type.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            I2CR::MOD_I2CR_PERFORM_OP,
                                            I2CR::RC_INVALID_ACCESSTYPE,
                                            TWO_UINT32_TO_UINT64(i_accessType,
                                                                 l_i2crAddr),
                                            get_huid(i_target),
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,
                      "OCMBs I2CR SCOM/CFAM Target").addToLog(l_err);
            break;
        }

         // Grab i2cr access information and also determine the associated HUB chip
         l_err = readI2crAttributes(i_target, l_i2cInfo);
         if (l_err) break;

         // Grab the target pointer to the master
         TargetService& ts = targetService();
         Target *i2crMaster = ts.toTarget(l_i2cInfo.i2cMasterPath);

         Target * sys = nullptr;
         ts.getTopLevelTarget( sys );

         // Master target has to exist and cannot be 'sys' target
         if( (i2crMaster == nullptr) || (i2crMaster == sys) )
         {
              char* l_masterPath = l_i2cInfo.i2cMasterPath.toString();
              TRACFCOMP( g_trac_i2cr, ERR_MRK"i2crPerformOp> "
                        "I2CR Master path (%s) not valid!", l_masterPath);
              free(l_masterPath);
              l_masterPath = nullptr;

              /*@
               * @errortype
               * @reasoncode       I2CR::RC_INVALID_MASTER_TARGET
               * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
               * @moduleid         I2CR::MOD_I2CR_PERFORM_OP
               * @userdata1        HUID of target with FAPI_I2C_CONTROL_INFO
               * @devdesc          Invalid I2C master path
               * @custdesc         A problem occurred during the IPL
               *                   of the system.
               */
              l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            I2CR::MOD_I2CR_PERFORM_OP,
                                            I2CR::RC_INVALID_MASTER_TARGET,
                                            get_huid(i_target),
                                            0,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
              ERRORLOG::ErrlUserDetailsTarget(i_target,
                        "OCMBs I2CR SCOM/CFAM Target").addToLog(l_err);
              break;
         }

         // Handle the specified operation
         if(i_opType == DeviceFW::READ)
         {
             TRACUCOMP( g_trac_i2cr, "i2crPerformOp> Read(l_i2crAddr=0x%.8X shifted=0x%.8X)",
                        l_i2crAddr, l_shiftedI2crAddr);

             // All I2CR operations (both Scom & CFAM) are 8 bytes long.
             // For CFAM access type, we may need to strip the extra 4 data bytes.
             if (((i_accessType == DeviceFW::I2CR_CFAM) ||
                 (i_accessType == DeviceFW::CFAM)) && (io_buflen == sizeof(uint32_t)))
             {
                 size_t l_sz = 8;
                 uint8_t l_buf64[l_sz] = {0};

                 // Read 8 bytes even though CFAM is typically 4 bytes long
                 l_err = i2cr_generic_read(l_shiftedI2crAddr, i_target, l_buf64, l_sz, l_i2cInfo);

                 // Just copy over the most significant 4 bytes.
                 memcpy(io_buffer, l_buf64, io_buflen);
             }
             else
             {
                 l_err = i2cr_generic_read(l_shiftedI2crAddr, i_target,
                                           reinterpret_cast<uint8_t*>(io_buffer),
                                           io_buflen, l_i2cInfo);
             }
             TRACDBIN(g_trac_i2cr, "io_buffer=", io_buffer, io_buflen);
         }
         else if(i_opType == DeviceFW::WRITE)
         {
             TRACDCOMP( g_trac_i2cr, "i2crPerformOp> Write(l_i2crAddr=0x%.8X shifted=0x%.8X",
                        l_i2crAddr, l_shiftedI2crAddr);
             TRACDBIN(g_trac_i2cr, "io_buffer=", io_buffer, io_buflen);

             // All I2CR operations (both Scom & CFAM) are 8 bytes long.
             // For CFAM access type, we may need to append the extra 4 data bytes.
             if (((i_accessType == DeviceFW::I2CR_CFAM) ||
                 (i_accessType == DeviceFW::CFAM)) && (io_buflen == sizeof(uint32_t)))
             {
                 size_t l_sz = 8;
                 uint8_t l_buf64[l_sz] = {0};

                 // Copy the 4 bytes data to be written in the most significant bits.
                 // Rest of the 4 bytes is initialized to zero.
                 memcpy(l_buf64, io_buffer, io_buflen);

                 // Write 8 bytes data.
                 l_err = i2cr_generic_write(l_shiftedI2crAddr, i_target, l_buf64, l_sz, l_i2cInfo);
             }
             else
             {
                 l_err = i2cr_generic_write(l_shiftedI2crAddr, i_target,
                                            reinterpret_cast<uint8_t*>(io_buffer),
                                            io_buflen, l_i2cInfo);
             }

             TRACDCOMP( g_trac_i2cr, "i2crPerformOp> Final write out: Addr=0x%X",
                        l_shiftedI2crAddr);
             TRACDBIN(g_trac_i2cr, "io_buffer=", io_buffer, io_buflen);
         }
         else
         {
             TRACFCOMP( g_trac_i2cr, ERR_MRK"i2crPerformOp> Unsupported Operation Type: i_opType=0x%x)",
                        i_opType);
             /*@
              * @errortype
              * @moduleid     I2CR::MOD_I2CR_PERFORM_OP
              * @reasoncode   I2CR::RC_INVALID_OPTYPE
              * @userdata1[0:31]    Operation Type (i_opType) : 0=READ, 1=WRITE
              * @userdata1[32:64]   Input Scom address
              * @userdata2    Target HUID
              * @devdesc      i2crPerformOp> Unsupported Operation Type specified
              * @custdesc     A problem occurred during the IPL of the system:
              *               Unsupported SCOM operation type.
              */
             l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             I2CR::MOD_I2CR_PERFORM_OP,
                                             I2CR::RC_INVALID_OPTYPE,
                                             TWO_UINT32_TO_UINT64(i_opType,
                                                                  l_i2crAddr),
                                             get_huid(i_target),
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
             //Add this target to the FFDC
             ERRORLOG::ErrlUserDetailsTarget(i_target,
                       "OCMBs I2CR SCOM/CFAM Target").addToLog(l_err);
             break;
         }

    } while(0);

    if (l_err)
    {
         l_err->collectTrace(I2CR_COMP_NAME);
    }

    return l_err;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


/**
 *
 * @brief A wrapper function to do the I2CR CFAM/FSI R/W operations
 *
 * @param [in] i_opType : operation type (READ or WRITE)
 * @param [in] i_target : Target OCMB chip
 * @param [in] io_buffer : buffer with data to be written
 * @param [in] io_buflen : buffer size
 * @param [in] i_accessType : access type (CFAM)
 * @param [in] i_args : i2cr register address (CFAM word addr)
 * @return l_err : An error that is set in this routine
 *
 */
errlHndl_t i2crCfamPerformOp(DeviceFW::OperationType i_opType,
                             Target* i_target,
                             void* io_buffer,
                             size_t& io_buflen,
                             int64_t i_accessType,
                             va_list i_args)
{
    // The input i2cr address is a CFAM(FSI) word address
    uint64_t l_i2crAddr = va_arg(i_args,uint64_t);
    errlHndl_t l_err = NULL;
    TARGETING::ATTR_CHIP_ID_type l_chipId = i_target->getAttr<ATTR_CHIP_ID>();

    TRACUCOMP( g_trac_i2cr, ENTER_MRK"i2crCfamPerformOp> Addr=0x%.16x io_buflen=0x%x chipId=%x",
               l_i2crAddr, io_buflen, l_chipId );
    do
    {
        if (((l_chipId == POWER_CHIPID::ODYSSEY)   ||
             (l_chipId == POWER_CHIPID::ODYSSEY_16))  &&
            ((i_accessType == DeviceFW::I2CR_CFAM) ||
             (i_accessType == DeviceFW::CFAM)))
        {
            l_err = i2crPerformOp(i_opType, i_target, io_buffer,
                                  io_buflen, i_accessType,
                                  reinterpret_cast<char *>(&l_i2crAddr));
            break;
        }

        // If we are here, the chip Id indicates either its not Odyssey type
        // or we do not have the correct access type. Log an error.

        TRACFCOMP( g_trac_i2cr, ERR_MRK"i2crCfamPerformOp> Unsupported OCMB Type or invalid access "
                   "type! chip ID=0x%x accessType=%d", l_chipId, i_accessType );

        /*@
         * @errortype
         * @moduleid     I2CR::MOD_I2CR_PERFORM_OP
         * @reasoncode   I2CR::RC_INVALID_OCMBTYPE
         * @userdata1[0:31]    Operation Type (i_opType) : 0=READ, 1=WRITE
         * @userdata1[32:64]   Input Scom address
         * @userdata2    Target HUID
         * @devdesc      i2crCfamPerformOp> Unsupported OCMB Type specified
         * @custdesc     A problem occurred during the IPL of the system:
         *               Unsupported CFAM OCMB type for I2CR operation.
         */
         l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         I2CR::MOD_I2CR_PERFORM_OP,
                                         I2CR::RC_INVALID_OCMBTYPE,
                                         TWO_UINT32_TO_UINT64(l_chipId,
                                                              l_i2crAddr),
                                         get_huid(i_target),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
         //Add this target to the FFDC
         ERRORLOG::ErrlUserDetailsTarget(i_target,
                   "OCMBs I2CR SCOM/CFAM Target").addToLog(l_err);

         l_err->collectTrace(I2CR_COMP_NAME);

    } while(0);

    return l_err;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


// Register Scom access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::I2CR_SCOM,
                      TYPE_OCMB_CHIP,
                      i2crPerformOp);

// Register FSI/CFAM access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::I2CR_CFAM,
                      TYPE_OCMB_CHIP,
                      i2crPerformOp);

// Register FSI/CFAM access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::CFAM,
                      TYPE_OCMB_CHIP,
                      i2crCfamPerformOp);


} // end I2CR namespace
