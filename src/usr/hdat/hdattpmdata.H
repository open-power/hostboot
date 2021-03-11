/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdattpmdata.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
#ifndef HDATTPMDATA_H
#define HDATTPMDATA_H

/**
 * @file hdattpmdata.H
 *
 * @brief This file contains the class definition for the TPM data object
 *        which manages the HDAT TPM section.
 *
 */

#include <stdint.h>
#include <errl/errlentry.H>
#include <hdat/hdat_reasoncodes.H>
#include "hdatutil.H"
#include <hdat/hdat.H>
#include <sys/misc.h>
#include <securerom/ROM.H>

#define TPM_SRTM_EVENT_LOG_MAX (64 * KILOBYTE)

#define TPM_DRTM_EVENT_LOG_MAX (64 * KILOBYTE)

#define NUM_I2C_PHYS_PRESENCE_DEVICES 2

namespace HDAT
{

/**
 * @brief Enumeration definition for known defaults to TPM data fields
 */
enum {
    TpmDataInstance = 0,
    TpmDataVersion = 0x30, // 0x30 is first version for P10
    TpmDataHdrSize = 0x20,
    TpmDataPtrOffset = 0x20,
    TpmDataPtrCnt = 3,
    TpmDataChildStrCnt = 0,
    TpmDataChildStrOffset = 0,
    TpmDataMinRqrdPcrdVersion = 0x25 // First version to include SPI Dev Info
};

/**
 * @brief Enumeration definition for the TPM states of existence
 */
enum TpmState {
    TpmPresentAndFunctional = 0x1,
    TpmPresentNonFunctional = 0x2,
    TpmNonPresent = 0x3,
};

/**
 * @brief Enumeration definition for the TPM roles
 */
enum TpmRole {
    HDAT_PRIMARY_TPM = 0x0,
    HDAT_BACKUP_TPM = 0x1,
};

/**
 * @brief Structure definition for HDAT Tpm Node Data Header
 */
struct hdatTpmData_t
{
    hdatHDIF_t hdatHdr;
    hdatHDIFDataHdr_t hdatSbTpmInfo; // Pointer pair to secure boot TPM info
    hdatHDIFDataHdr_t hdatPhysInter; // Physical interaction mechanism details
    hdatHDIFDataHdr_t hdatHashVerifyFunc; // Hash and Verification functions
    uint8_t hdatReserved1[8]; // Padding for alignment and growth/compatibility
} __attribute__ ((packed));

/**
 * @brief Structure definition for TPM Configuration Flags
 *
 */
struct hdatTpmConfigFlags_t
{
    uint8_t pcrPoisonedFlag : 1; // Intentionally break remote attestation
                                 // of this TPM
    uint8_t tpmRole : 1; // 0b1 = backup, 0b0 = primary
    uint8_t reserved : 6;
} __attribute__ ((packed));

/**
 *  @brief Structure definition for Secureboot TPM Instance Info
 */
struct hdatSbTpmInstInfo_t
{
    uint32_t hdatSpiDeviceId;
    // Reserved space was previously used for "Drawer/Book/Octant/Blade"-id and TPM locality values
    // which are no longer needed. Empty space kept to comform with specs.
    uint32_t reserved_0x0004;
    uint8_t reserved_0x0008;
    uint8_t reserved_0x0009;
    uint8_t reserved_0x000A;
    uint8_t reserved_0x000B;
    uint8_t hdatFunctionalStatus;
    struct hdatTpmConfigFlags_t hdatTpmConfigFlags;
    uint8_t reserved[2];
    uint32_t hdatTpmSrtmEventLogOffset;
    uint32_t hdatTpmSrtmEventLogEntrySize;
    uint32_t hdatTpmDrtmEventLogOffset;
    uint32_t hdatTpmDrtmEventLogEntrySize;
} __attribute__ ((packed));


// Type used to specify SPI Device IDs
typedef uint32_t spiDeviceId_t;

// Special spiDeviceId_t values
enum SPI_DEVICE_ID : spiDeviceId_t
{
    INVALID_SPI_DEVICE_ID = 0xFFFFFFFF,
};

/**
 *  @brief Type used to specify I2C link IDs
 */
typedef uint32_t i2cLinkId_t;

/**
 *  @brief Special/sentinel i2cLinkId_t values
 */
enum I2C_LINK_ID : i2cLinkId_t
{
    NOT_APPLICABLE = 0xFFFFFFFF,
};

/**
 * @brief Structure definition for HDAT physical interaction mechanism info
 */
struct hdatPhysInterMechInfo_t
{
    // ID of I2C device in the PCRD that supports the "window open" function
    i2cLinkId_t i2cLinkIdWindowOpen;

    // ID of I2C device in the PCRD that supports the "physical presence"
    // function
    i2cLinkId_t i2cLinkIdPhysicalPresence;

} __attribute__ ((packed));

/**
 * @brief Structure definition for HDAT Hash and Verification Function instances
 */
struct hdatHashVerifyFunc_t
{
    sbFuncType_t sbFuncType; // Type of secureboot function
    sbFuncVer_t sbFuncVer; // Version of verify function
    uint32_t dbobId; // Drawer/Book/Octant/Blade ID
    uint32_t sbFuncOffset; // Offset of function within SecureROM
};

extern const char g_hdatTpmDataEyeCatch[];

/** Begin Class Description
 *
 * @brief  The HdatTpmData class is used to construct the Node TPM Related Data
 *         hypervisor data area.
 *
 * Description: This class defines a specialized object.  It is not intended
 *              that any component can create an object of this type.
 *              In particular, the object is built only by the hdat component.
 *
 *              The real purpose of the object is to create the Node TPM
 *              data structure as defined by the PHYP Initialization
 *              architecture.  This data structure is eventually copied to
 *              main memory.  The class is not defined to be a general purpose
 *              interface for building this object by anyone other than the
 *              hdat process.
 *
 * Thread safety:  An HdatTpmData object is not thread safe.  That is, a
 *                 single object cannot be shared and used concurrently by
 *                 multiple threads at the same time.  An object can be used by
 *                 multiple threads if the threads serialize access.  And of
 *                 course, each thread can use its own object with no concerns
 *                 about what other threads are doing.
 *
 * Signal handler usage: This class is not intended to be used in a signal
 *                        handler and nothing has been done to try and make
 *                        it safe to use in a signal handler.
 *
 * End Class Description
 */
class HdatTpmData
{
    public:
        /**
         * @brief Construct an HdatTpmData object.
         *
         *       This is the constructor for the HdatTpmData object.
         *
         *       After creating a new HdatTpmData object via new, you must
         *       check o_errlHndl to see if the constructor ran successfully.
         *       If o_errHndl indicates an error was reported by the
         *       constructor, then new has already allocated heap storage and
         *       the object must be deleted in order to free the heap storage.
         *
         * @pre None
         *
         * @post An HdatTpmData object has been constructed.
         *       Heap storage has been allocated.
         *
         * @param[out] o_errlHndl If any errors occur, the HdatTpmData object is
         *                                      NOT constructed and an error is
         *                                      returned in this parameter
         * @param[in] i_msAddr The main memory address that the service
         *                                      processor subsystem structure
         *                                      will be DMA'd to.
         */
        HdatTpmData(errlHndl_t &o_errlHndl, const HDAT::hdatMsAddr_t &i_msAddr);


        /**
         * @brief HdatTpmData object destructor
         *
         *        This is the destructor for an HdatTpmData object.
         *        Any heap storage allocated for the object is deallocated.
         *
         * @pre No preconditions exist
         *
         * @post The HdatTpmData object has been destroyed and can
         *       no longer be used.
         *
         */
        ~HdatTpmData();

         /**
          * @brief Load TPM Related Data to Mainstore
          *
          * @pre None
          *
          * @post None
          *
          * @param[out] o_size Size of TPM Data structure
          * @param[out] o_count Number of TPM Data structures
          *
          * @retval errlHndl_t nullptr on success, error log on error
          */
        errlHndl_t hdatLoadTpmData(uint32_t &o_size,uint32_t &o_count);

        // delete copy/move constructors and operators
        HdatTpmData(const HdatTpmData& ) = delete;
        HdatTpmData& operator=(const HdatTpmData& ) = delete;
        HdatTpmData(HdatTpmData&&) = delete;
        HdatTpmData& operator=(HdatTpmData&&) = delete;

    private:

        HDAT::hdatMsAddr_t iv_msAddr;

        hdatTpmData_t *iv_hdatTpmData;

        uint32_t iv_numNodes;

}; // end of HdatTpmData class

/**
 * @brief Calculate the maximum number of TPMs per node for this system.
 *
 * @pre None
 *
 * @post None
 *
 * @retval uint16_t Returns the maximum number of TPMs per node for this system
 */
uint16_t hdatCalcMaxTpmsPerNode();

/**
 * @brief Calculate the maximum size of an instance of HDAT TPM data. There
 *        will be one instance per functional node in the system. It is assumed
 *        that this function will be used determine how much space one node's
 *        worth of HDAT TPM data will occupy worst case. It is assumed that each
 *        instance will have the same max size and that the instances will be
 *        placed one after another in memory (not page aligned) with enough
 *        space to accommodate the maximum possible size of each node.
 *
 * @pre None
 *
 * @post None
 *
 * @retval uint32_t Maximum size of one instance of HDAT TPM data.
 */
uint32_t hdatTpmDataCalcInstanceSize();

}
#endif // HDATTPMDATA_H
