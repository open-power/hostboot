/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatspsubsys.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
 *  @file hdatspsubsys.H
 *
 *  @brief This file contains the class definition for the service processor
 *         subsystem object.
 *
 */

#ifndef HDATSPSUBSYS_H
#define HDATSPSUBSYS_H

/*--------------------------------------------------------------------------*/
/* Includes                                                                 */
/*--------------------------------------------------------------------------*/
#include <stdint.h>              // standard types
#include <hdat/hdat.H>                // HDAT header type definitions
#include "hdathdif.H"            // HdatHdif base class definition
#include <hdat/hdat_reasoncodes.H>

namespace HDAT
{

/*--------------------------------------------------------------------------*/
/* Type definitions                                                         */
/*--------------------------------------------------------------------------*/

/** @enum hdatSpStatus
 *        Status of a service procesor card
 */
enum hdatSpStatus
{
    HDAT_SP_INSTALLED  = 0x8000,  // service processor is installed
    HDAT_SP_FUNCTIONAL = 0x4000,  // service processor is functional
    HDAT_SP_PRIMARY    = 0x2000   // this is the primary service processor
};

// The number of data pointers in hdatDataPtrs (defined in hdatspsubsys.C)
#define HDAT_SPSUBSYS_NUM_DATA_PTRS 8

/** @brief eye catcher for the HDIF header for the SP subsystem data area
 */
const char HDAT_STRUCT_NAME[] = "SPINFO";

//TODO : : RTC Story 246434 Usage of UART validity flag
/** @brief Indicates the validity of UVART
 */
const uint8_t HDAT_UART_IS_VALID = 1;

/** @brief Structure version number
 */
const uint16_t HDAT_SP_SUBSYS_VERSION = 0x0041;

/** @brief Structure definition for service processor hardware and software.
    Reserved bytes are added to make the structure a multiple of 4 bytes.
    Adjust the reserved size as necessary if new members are added to this
    structure.
 */
struct hdatSpImpl_t
{
    uint16_t hdatHdwVer;    // 0x0000 Hardware version
    uint16_t hdatSftVer;    // 0x0002 Software version
    uint16_t hdatStatus;    // 0x0004 SP functionality/status
    uint8_t  hdatChipVer;   // 0x0006 SP chip DD level
    uint8_t  hdatReserved1; // 0x0007 padding for alignment
    char     hdatBmcFamily[64];  // 0x0008 bmc family
} __attribute__ ((packed));

/** @brief Structure for uart interrupt info
*/
struct uartIntData_t
{
     uint8_t hdatUARTIntrNum;// UART Interrupt number
     uint8_t hdatTriggerType;// UART interrupt trigger type
     uint8_t hdatIsURARTValid;// UART is valid OR not
     uint8_t hdatResrved2;// Reserved
};

/** @brief Structure for Bulk Transfer Interrupt info
*/

struct btIntData_t
{
     uint8_t hdatSMSAttnIntrNum;
     uint8_t hdatBMCtoHostRespIntrNum;
     uint8_t hdatReserved[2];
};

/** @brief Structure definition for the I/O path to the service processor
 */
struct hdatSpIoPath_t
{
    uint16_t     hdatPathType;          // 0x0000 I/O path type
    uint16_t     hdatLinkStatus;        // 0x0002 PSI Link status
    uint8_t      hdatML2ChipVer;        // 0x0004 Chip DD level of ML2 controller
    uint8_t      hdatResvd[3];          // 0x0005 Reserved
    uint32_t     hdatProcChipId;        // 0x0008 Processor chip id
    uint32_t     hdatLPCHCBarIOAdrSpc;  // 0x000C LPCHC BAR for I/O Adr Space
    uint32_t     hdatLPCHCBarMemAdrSpc; // 0x0010 LPCHC BAR for MemAdr Space
    uint32_t     hdatLPCHCBarFwAdrSpc;  // 0x0014 LPCHC BAR for FW Adr Space
    uint32_t     hdatLPCHCBarIntRegSpc; // 0x0018 LPCHC BAR for Internal Reg Space
    uint32_t     hdatLPCMCTPMemWinBar;  // 0x001C LPC MCTP Memory Window Base
                                        //        Address
    uint64_t     hdatBarOfVUART1Dev;    // 0x0020 BAR of VUART1 device on LPC
                                        //        bus
    uint32_t     hdatSizeofVUART1AdrSpc;// 0x0028 Size of VUART1 device adr
                                        //        space
    uint32_t     hdatVUART1FreqHz;      // 0x002C Clock Frequcny of VUART1 buad
                                        //        clock
    uint32_t     hdatCurVUART1DevBaudRate;    // 0x0030 Current Baud rate of
                                              //        VUART1 device
    uartIntData_t  hdatVUART1InterruptDetails;// 0x0034 VUART1 interrupt details
    uint64_t     hdatBarOfBTDev;              // 0x0038 BAR of BT device on LPC
                                              //        bus
    uint32_t     hdatSizeofBTAdrSpc;          // 0x0040 Size of BT device adr
                                              //        space
    btIntData_t  hdatBTInterruptDetails;      // 0x0044 BT interrupt details
    uint16_t     hdatKCSDataRegAddr;          // 0x0048 KCS Data Register
                                              //        Address
    uint16_t     hdatKCSStatusRegAddr;        // 0x004A KCS Status Register
                                              //        Address
    uint8_t      hdatKCSInterruptNum;         // 0x004C KCS Interrupt Number
    uint64_t     hdatBarOfVUART2Dev;          // 0x004D BAR of VUART2 device on
                                              //        LPC bus
    uint32_t     hdatSizeofVUART2AdrSpc;      // 0x0055 Size of VUART2 device
                                              //        adr space
    uint32_t     hdatVUART2FreqHz;            // 0x0059 Clock Frequcny of VUART2
                                              //        buad clock
    uint32_t     hdatCurVUART2DevBaudRate;    // 0x005D Current Baud rate of
                                              //        VUART2 device
    uartIntData_t  hdatVUART2InterruptDetails;// 0x0061 VUART2 interrupt details

    // Interface to initiate a soft reset to BMC from Host in AST2600
    uint16_t     hdatKCS2DataRegAddr;         // 0x0065 KCS 2 Data Register Address
    uint16_t     hdatKCS2StatusRegAddr;       // 0x0067 KCS 2 Status Register Address
    uint8_t      hdatKCS2InterruptNum;        // 0x0069 KCS 2 Interrupt Number

} __attribute__ ((packed));

#define HDAT_NON_FUNCTIONAL 0 // PSI link is not functional
#define HDAT_CURRENT_LINK   1 // This FSP's current functional link
#define HDAT_CANDIDATE_LINK 2 // Candidate link if current link fails

/** @brief Structure definition for the service processor memory
 */
struct hdatSpMem_t
{
    uint32_t deprecated1[5];  // Deprecated in latest spec 9.13c
    uint32_t hdatHostRamSize;  // 0x0014 Size of host private NVRAM
    uint32_t deprecated2[2];    // Deprecated in latest spec 9.13c
} __attribute__ ((packed));

/** @enum hdatSpSubSysDataPtrs
 *        Constants for the internal data pointers that are added to the base
 *        class
 */
enum hdatSpSubSysDataPtrs
{
    HDAT_SPSUBSYS_FRU_ID     = 0,
    HDAT_SPSUBSYS_KWD        = 1,
    HDAT_SPSUBSYS_IMPL       = 2,
    HDAT_SPSUBSYS_DEPRECATED = 3,
    HDAT_SPSUBSYS_MEMORY     = 4,
    HDAT_SPSUBSYS_IO_PATH    = 5,
    HDAT_SPSUBSYS_RESERVED1  = 6,
    HDAT_SPSUBSYS_RESERVED2  = 7,
    HDAT_SPSUBSYS_LAST       = 8
};

const uint32_t HDAT_MAX_NUM_IO_PATHS = 32;
const uint16_t HDAT_LPC_PATH_TYPE = 3;
const uint32_t HDAT_NUM_IO_PATHS_FOR_BMC = 1;
const uint32_t LPC_PATH_FRU_CNT_FOR_BMC = 2;


/*-----------------------------------------------------------------------------*/
/* C++ class definition                                                        */
/*-----------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatSpSubsys class is used to construct objects that describe
 *         the service processor hardware and software.
 *
 * Description: This class defines a specialized object.  It is not intended
 *              that anyone can create an object of this type.  In particular,
 *              the object is built only in the hdatstep process when the step
 *              that builds hypervisor data structures is run.
 *
 *              The real purpose of the object is to create the service processor
 *              subsystem structure as defined by the PHYP Initialization architecture
 *              This data structure is eventually DMA'd to main memory.  The
 *              class is not defined to be a general purpose interface for
 *              building this object by anyone other than the hdatstep process.
 *
 * Thread safety:  An HdatSpSubsys object is not thread safe.  That is, a single
 *                 object cannot be shared and used concurrently by
 *                 multiple threads at the same time.  An object can be used by
 *                 multiple threads if the threads serialize access.  And of
 *                 course, each thread can use its own object with no concerns
 *                 about what other threads are doing.
 *
 * Signal handler usage: This class is not intended to be used in a signal handler
 *                       and nothing has been done to try and make it safe to use
 *                       in a signal handler.
 *
 * End Class Description
 */
class HdatSpSubsys : public HdatHdif
{
    public:

        /**
         * @brief Construct an HdatSpSubsys object.
         *
         *       This is the constructor for the HdatSpSubsys object.
         *
         *       If you are constructing this object on the heap by using new, then
         *       you must check the pointer returned from new to see if it is null.
         *       If it is null, new failed to allocate storage and the constructor
         *       was not called.  If it is not null, then you must check o_errlHndl
         *       to see if the constructor ran successfully.  If o_errlHndl indicates
         *       an error was reported by the constructor, new has already allocated
         *       heap storage and the object must be deleted in order to free the
         *       heap storage.
         *
         * @pre None
         *
         * @post An HdatSpSubsys object has been constructed.  Heap storage has been allocated.
         *
         * @param o_errlHndl   - output parameter - If any errors occur, the HdatSpSubsys object
         *                       is NOT constructed and errors are returned in this parameter
         * @param i_resourceId - input parameter - The resource id of the service processor FRU
         * @param i_msAddr     - input parameter - The main memory address that the service
         *                       processor subsystem structure will be DMA'd to.
         *
         * @return A null error log handle if successful, else the return code pointed
         *         to by o_errlHndl contains one of:
         *
         * @retval HDAT_REGISTRY_ERROR
         * @retval HDAT_OTHER_COMP_ERROR
         */
        HdatSpSubsys(errlHndl_t &o_errlHndl,
                        hdatMsAddr_t &io_msAddr);


        /**
         * @brief HdatSpSubsys object destructor
         *
         *        This is the destructor for an HdatSpSubsys object.  Any heap storage
         *        allocated for the object is dallocated.
         *
         * @pre No preconditions exist
         *
         * @post The HdatSpSubsys object has been destroyed and can no longer be used.
         *
         */
        virtual ~HdatSpSubsys();
        /**
         * @brief member function to get the size of sp sub sys structure
         *
         *        Getter for iv_size
         */
         uint32_t getSpSubSysStructSize();

        /**
        * @brief function to fill internal data pointers.
        *
        * @return A null error handle if successfull
        */
        errlHndl_t hdatFillDataPtrs();


    private:
       /** Object Instance Data
         *
         * @li iv_msAddr         - Mainstore phyisical address
         * @li iv_kwdSize        - size of the ASCII keyword
         * @li iv_kwd            - ptr to storage which holds the ASCII keyword
         * @li iv_fru            - FRU Id information
         * @li iv_impl           - hardware/software implementation
         * @li iv_mem            - FSP memory information
         * @li iv_ioPathArrayHdr - I/O path array header
         * @li iv_ioPathArray    - I/O path(s) to the FSP card
         * @li iv_spSubsys       - virtual address for SP sub sys data
         * @li iv_size           - size of the sp sub sys total structure
         */
        uint64_t             iv_msAddr;
        uint32_t             iv_kwdSize;
        char                *iv_kwd;
        hdatFruId_t          iv_fru;
        hdatSpImpl_t         iv_impl;
        hdatSpMem_t          iv_mem;
        hdatHDIFDataArray_t  iv_ioPathArrayHdr;
        hdatSpIoPath_t      *iv_ioPathArray;
        uint8_t             *iv_spSubsys;
        uint32_t             iv_size;
        uint32_t             iv_numOfIoPaths;


        /** Class (static) Data
         *
         * Only one copy of this data exists in a process.
         *
         * @li cv_actualCnt - a count of how many HdatSpSubsys objects are created
         */
        static uint32_t   cv_actualCnt;

}; // end of HdatSpSubsys class

/**
 * @brief This routine Loads SP Sub sys information.
 *
 * @param io_msAddr    - input parameter - Mainstore address for SP subsys to write
 * @param o_spSubsysCnt   - output parameter - Count of SP Sub sys structures
 *
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval
 */

errlHndl_t HdatLoadSpSubSys(hdatMsAddr_t &i_msAddr,
            uint32_t &o_spSubSysTotalSize , uint32_t &o_spSubsysCnt);

}
#endif // HDATSPSUBSYS_H
