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

#include "ocmb_spd.H"
#include "spd.H"
#include "errlud_vpd.H"

extern trace_desc_t * g_trac_spd;

//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

// Namespace alias for targeting
namespace T = TARGETING;

namespace SPD
{

/**
 * @brief Handle SPD READ deviceOp to OCMB_CHIP targets
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
 */
errlHndl_t ocmbSPDPerformOp(DeviceFW::OperationType i_opType,
                            T::TargetHandle_t       i_target,
                            void*                   io_buffer,
                            size_t&                 io_buflen,
                            int64_t                 i_accessType,
                            va_list                 i_args);

// Register the perform Op with the routing code for OCMBs.
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::SPD,
                      T::TYPE_OCMB_CHIP,
                      ocmbSPDPerformOp);

/**
 * @brief Read keyword from SPD
 *
 *        Currently used to detect I2C_MUTEX and OCMB_CHIP targets
 *
 * @param[in]     i_target     OCMB target to read data from
 * @param[in/out] io_buffer    databuffer SPD will be written to
 * @param[in/out] io_buflen    length of the given data buffer
 * @param[in]     i_keyword    keyword from spdenums.H to read
 * @param[in]     i_memType    The memory type of this target.
 *
 * @pre io_buffer and i_target must be non-null
 * @pre currenlty only supported value for i_keyword is ENTIRE_SPD
 *
 * @return  errlHndl_t
 */
errlHndl_t ocmbGetSPD(T::TargetHandle_t        i_target,
                            void* const        io_buffer,
                            size_t&            io_buflen,
                      const uint64_t &         i_keyword,
                      const uint8_t            i_memType)
{
    errlHndl_t l_errl = nullptr;

    assert(i_target != nullptr, "i_target is nullptr in ocmbGetSPD");

    do {

        const KeywordData* entry = nullptr;
        l_errl = getKeywordEntry(i_keyword,
                                 i_memType,
                                 i_target,
                                 entry);
        if (l_errl != nullptr)
        {
            break;
        }

        // Check to be sure entry is not nullptr.
        if (entry == nullptr)
        {
            TRACFCOMP(g_trac_spd,
                      ERR_MRK"KeywordData entry pointer is nullptr!");

            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         VPD::VPD_OCMB_GET_SPD
            * @reasoncode       VPD::VPD_NULL_ENTRY
            * @userdata1[00:31] Buffer Size
            * @userdata1[32:63] Memory Type
            * @userdata2[00:31] SPD Keyword
            * @userdata2[32:63] Target HUID
            * @devdesc          SPD is not valid for this part
            * @custdesc         A problem occurred during the IPL
            *                   of the system.
            */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          VPD::VPD_OCMB_GET_SPD,
                                          VPD::VPD_NULL_ENTRY,
                                          TWO_UINT32_TO_UINT64(io_buflen,
                                            i_memType),
                                          TWO_UINT32_TO_UINT64(i_keyword,
                                              T::get_huid(i_target)),
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            l_errl->collectTrace( "SPD", 256);

            break;
        }

        // Only allow keywords supported by DDIMM
        l_errl = checkModSpecificKeyword(*entry,
                                         i_memType,
                                         i_target,
                                         VPD::SEEPROM);

        if (l_errl != nullptr)
        {
            break;
        }

        if (entry->isSpecialCase)
        {
            l_errl = spdSpecialCases(*entry,
                                     io_buffer,
                                     i_target,
                                     i_memType,
                                     VPD::SEEPROM);
            if (l_errl != nullptr)
            {
                break;
            }
        }

        // For ENTIRE_SPD, we must read OCMB SPD and EFD combined size.
        size_t dataSize = entry->length;
        if (i_keyword == ENTIRE_SPD)
        {
            assert(((io_buflen >= OCMB_SPD_EFD_COMBINED_SIZE)
                    || (io_buffer == nullptr)),
                   "Buffer must be at least 2 KB in ocmbGetSPD for ENTIRE_SPD");
            dataSize = OCMB_SPD_EFD_COMBINED_SIZE;
        }

        // Support passing in nullptr buffer to return VPD field size.
        if (io_buffer == nullptr)
        {
            io_buflen = dataSize;
            break;
        }

        l_errl = spdCheckSize(io_buflen,
                              dataSize,
                              i_keyword);

        if (l_errl != nullptr)
        {
            break;
        }

        l_errl = ocmbFetchData(i_target,
                               entry->offset,
                               dataSize,
                               io_buffer,
                               EEPROM::AUTOSELECT);

        if (l_errl != nullptr)
        {
            break;
        }

        // Return the size read.
        io_buflen = dataSize;

    } while(0);

    return l_errl;
}

// ------------------------------------------------------------------
// ocmbFetchData
// ------------------------------------------------------------------
errlHndl_t ocmbFetchData(T::TargetHandle_t    i_target,
                        uint64_t              i_byteAddr,
                        size_t                i_numBytes,
                        void*                 o_data,
                        EEPROM::EEPROM_SOURCE i_location)
{
    errlHndl_t err = nullptr;

    TRACSSCOMP(g_trac_spd,
               ENTER_MRK"ocmbFetchData()" );

    do
    {
        // Get the data
        err = DeviceFW::deviceOp(DeviceFW::READ,
                                 i_target,
                                 o_data,
                                 i_numBytes,
                                 DEVICE_EEPROM_ADDRESS(EEPROM::VPD_PRIMARY,
                                                       i_byteAddr,
                                                       i_location));
        if( err )
        {
            TRACFCOMP(g_trac_spd,
                      ERR_MRK"ocmbFetchData(): failing out of deviceOp");
            break;
        }

    } while(0);

    TRACSSCOMP(g_trac_spd,
               EXIT_MRK"ocmbFetchData(): returning %s errors",
               ((err != nullptr) ? "with" : "with no") );

    return err;
}

// ------------------------------------------------------------------
// isValidOcmbDimmType
// ------------------------------------------------------------------
bool isValidOcmbDimmType(const uint8_t i_dimmType)
{
    return ((SPD_DDR4_TYPE == i_dimmType ));
}

// ------------------------------------------------------------------
// getMemType
// ------------------------------------------------------------------
errlHndl_t getMemType(uint8_t&           o_memType,
                      T::TargetHandle_t  i_target)
{
    errlHndl_t err = nullptr;

    err = ocmbFetchData(i_target,
                        MEM_TYPE_ADDR,
                        MEM_TYPE_SZ,
                        &o_memType,
                        EEPROM::AUTOSELECT);

    TRACSSCOMP(g_trac_spd,
               EXIT_MRK"SPD::getMemType() - MemType: 0x%02x, Error: %s",
               o_memType,
               ((err != nullptr) ? "Yes" : "No"));

    return err;
}

// See above for details
errlHndl_t ocmbSPDPerformOp(DeviceFW::OperationType i_opType,
                            T::TargetHandle_t i_target,
                            void* io_buffer,
                            size_t& io_buflen,
                            int64_t i_accessType,
                            va_list i_args)
{
    errlHndl_t errl = nullptr;
    const uint64_t keyword = va_arg(i_args, uint64_t);

    TRACSSCOMP(g_trac_spd,
               ENTER_MRK"ocmbSPDPerformOP(), io_buflen: %d, keyword: 0x%04x",
               io_buflen, keyword );

    do
    {
        // Read the Basic Memory Type
        uint8_t memType(MEM_TYPE_INVALID);
        errl = getMemType(memType, i_target);

        if( errl )
        {
            break;
        }

        TRACSSCOMP(g_trac_spd,
                   INFO_MRK"Mem Type: %04x",
                   memType);

        // Check the Basic Memory Type
        if (isValidOcmbDimmType(memType))
        {
            // If the user wanted the Basic memory type, return this now.
            if(BASIC_MEMORY_TYPE == keyword)
            {
                io_buflen = MEM_TYPE_SZ;
                if (io_buffer != nullptr)
                {
                    memcpy(io_buffer, &memType, io_buflen);
                }
                break;
            }

            // Read the keyword value
            errl = ocmbGetSPD(i_target,
                              io_buffer,
                              io_buflen,
                              keyword,
                              memType);

            if( errl )
            {
                break;
            }
        }
        else
        {
            TRACFCOMP(g_trac_spd,
                      ERR_MRK"Invalid Basic Memory Type (0x%04x), "
                      "target huid = 0x%x",
                      memType,
                      T::get_huid(i_target));

            /*@
            * @errlortype
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         VPD::VPD_OCMB_SPD_PERFORM_OP
            * @reasoncode       VPD::VPD_INVALID_BASIC_MEMORY_TYPE
            * @userdata1[00:31] Basic Memory Type (Byte 2)
            * @userdata1[32:63] Target HUID
            * @userdata2        Keyword Requested
            * @devdesc          Invalid Basic Memory Type
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_OCMB_SPD_PERFORM_OP,
                                           VPD::VPD_INVALID_BASIC_MEMORY_TYPE,
                                           TWO_UINT32_TO_UINT64(memType,
                                               T::get_huid(i_target)),
                                           keyword);

            // User could have installed a bad/unsupported dimm
            errl->addHwCallout(i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::DECONFIG,
                               HWAS::GARD_NULL);

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_LOW);

            errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                      HWAS::SRCI_PRIORITY_LOW);

            errl->collectTrace("SPD", 256);

            break;
        }
    } while(0);

    // If there is an error, add parameter info to log
    if ( errl != nullptr )
    {
        VPD::UdVpdParms(i_target,
                        io_buflen,
                        0,
                        keyword,
                        true) // read
            .addToLog(errl);
    }

    TRACSSCOMP(g_trac_spd,
               EXIT_MRK"ocmbSPDPerformOP(): returning %s errors",
               (errl ? "with" : "with no") );

    return errl;

}


} // End of SPD namespace
