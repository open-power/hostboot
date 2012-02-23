//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/scom/scomtrans.H $
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
#ifndef __SCOMTRANS_H
#define __SCOMTRANS_H

#include <devicefw/driverif.H>

/** @file  scomtrans.H
 *  @brief Provides the interfaces to perform a SCom
 */

namespace SCOM
{


    enum ScomTransMask
    {
        SCOM_TRANS_EX_MASK =          0xFFFFFFFF7F000000,
        SCOM_TRANS_MCS_MASK =         0xFFFFFFFF7FFFFF80,
        SCOM_TRANS_MBA_MASK =         0xFFFFFFFF7FFFFC00,
        SCOM_TRANS_XBUS_MASK =        0x00000000FFFFFC00,
        SCOM_TRANS_IND_MCS_DMI_MASK = 0x80000060FFFFFFFF,
        SCOM_TRANS_IND_MBA_MASK =     0x80000000FFFFFFFF,
        SCOM_TRANS_ABUS_MASK =        0x000000FFFFFFFC00,
        SCOM_TRANS_INDIRECT_MASK =    0x8000000000000000,     
    };

    enum ScomTransBaseAddr
    {
        SCOM_TRANS_EX_BASEADDR =          0x0000000010000000,
        SCOM_TRANS_MCS_BASEADDR =         0x0000000002011800,
        SCOM_TRANS_MCS_DMI_BASEADDR =     0x0000000002011A00,
        SCOM_TRANS_IND_MCS_BASEADDR =     0x8000000002011A00,
        SCOM_TRANS_MBA_BASEADDR =         0x0000000003010400,
       // SCOM_TRANS_MBS_DPHY_BASEADDR =    0x0000000003011000,
        SCOM_TRANS_XBUS_BASEADDR =        0x0000000004011000,
        SCOM_TRANS_ABUS_BASEADDR =        0x0000000008010C00,
        SCOM_TRANS_IND_MBA_BASEADDR =     0x800000000301143f,
        SCOM_TRANS_IND_MCS_DMI_BASEADDR = 0x8000000002011A3F,
        SCOM_TRANS_INDIRECT_ADDRESS =     0x8000000000000000,
    };



/**
 * @brief Performs a SCom Translation of the scom address
 * This function performs the translation and get the
 * correct target and continues the scom Operation.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        SCom target
 * @param[in/out] io_buffer     Read: pointer to output data storage
 *                              Write: pointer to data to be written
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output: Read: size of output data
 *                                      Write: size of data written
 * @param[in]   i_accessType    Select from DeviceFW::AccessType enum
 *                              (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the SCom address value.
 */
errlHndl_t scomTranslate(DeviceFW::OperationType i_opType,
                         TARGETING::Target* i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_args);


/**
 * @brief Utility function does the address translation for
 *   unit types that have similar unit identifying strategy
 *
 * @param[in]      i_epath   entity path is passed in 
 * @param[in]      i_ctype   Current targets target type
 * @param[in]      i_ptype   Target type of the parent
 * @param[in]      i_shift   Number of bits the instance needs to shift
 * @param[in]      i_mask    Mask value
 * @param[in|out]  o_target  SCom target is passed in and after
 *                           translation return a scomable target
 * @param[in|out}  i_addr    Address passed in and return as a
 *                           translated address
 * @return  errlHndl_t
 */
errlHndl_t scomPerformTranslate(TARGETING::EntityPath i_epath,
                                TARGETING::TYPE i_ctype,
		                TARGETING::TYPE i_ptype,
                                int i_shift,
                                uint64_t i_mask,
                                TARGETING::Target * &o_target,
                                uint64_t &i_addr );

/**
 * @brief This function finds the parent target type and returns
 *   that as the new target
 *
 * @param[in]      i_epath   SCom target is passed in and return
 *                           the parent type requested
 * @param[in]      i_ptype   Target type needed for the parent requested
 * @param[in|out]  o_target  SCom target is passed in and after
 *                           translation return a parent target
 * @return  errlHndl_t
 */
errlHndl_t scomfindParentTarget( TARGETING::EntityPath i_epath,
				 TARGETING::TYPE i_ptype,
                                 TARGETING::Target * &o_target);


}; // End namespace

#endif
