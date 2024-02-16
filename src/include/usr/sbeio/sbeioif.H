/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbeioif.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2024                        */
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
#ifndef _SBEIOIF_H
#define _SBEIOIF_H

#include <errl/errlentry.H>

/* Associated defines for sendPsuReadSeeprom() function below */
#define CHIPOP_READ_SEEPROM_SIZE_ALIGNMENT_BYTES 128
#define CHIPOP_READ_SEEPROM_DEST_ADDR_ALIGNMENT_BYTES 8

namespace SBEIO
{
    /**
     * @brief enums for Execute Hardware Procedure Messages
     */
    enum fifoExecuteHardwareProcedureClass
    {
        SBE_FIFO_EXEC_HWP_CLASS_IO     = 0x01,
        SBE_FIFO_EXEC_HWP_CLASS_MEMORY = 0x02,
    };

    /**
     * @brief enum for all valid IO class type messages for Execute Hardware Procedure
     */
    enum fifoExecuteHardwareProcedureIo
    {
        IO_ODY_OMI_HSS_LOAD_PPE     = 0x01,
        IO_ODY_OMI_HSS_CONFIG       = 0x02,
        IO_ODY_OMI_HSS_START_PPE    = 0x03,
        IO_ODY_OMI_HSS_BIST_INIT    = 0x04,
        IO_ODY_OMI_HSS_BIST_START   = 0x05,
        IO_ODY_OMI_HSS_BIST_POLL    = 0x06,
        IO_ODY_OMI_HSS_BIST_CLEANUP = 0x07,
        IO_ODY_OMI_HSS_INIT         = 0x08,
        IO_ODY_OMI_HSS_DCCAL_START  = 0x09,
        IO_ODY_OMI_HSS_DCCAL_POLL   = 0x0A,
        IO_ODY_OMI_HSS_TX_ZCAL      = 0x0B,
        IO_ODY_OMI_PRETRAIN_ADV     = 0x0C,
        IO_ODY_OMI_SETUP            = 0x0D,
        IO_ODY_OMI_TRAIN            = 0x0E,
        IO_ODY_OMI_TRAIN_CHECK      = 0x0F,
        IO_ODY_OMI_POSTTRAIN_ADV    = 0x10,
    };

    /**
     * @brief enum for all valid MEMORY class type messages for Execute Hardware Procedure
     */
    enum fifoExecuteHardwareProcedureMemory
    {
        MEM_ODY_SCOMINIT       = 0x01,
        MEM_ODY_DDRPHYINIT     = 0x02,
        MEM_ODY_DDRPHYINIT_ATE = 0x03,
        MEM_ODY_LOAD_IMEM      = 0x04,
        MEM_ODY_LOAD_DMEM      = 0x05,
        MEM_ODY_SPPE_DRAMINIT  = 0x06,
        MEM_ODY_ATE_FW         = 0x07,
        MEM_ODY_LOAD_PIE       = 0x08,
        MEM_ODY_DRAMINIT_MC    = 0x09,
        MEM_ODY_ENABLE_ECC     = 0x0A,
        MEM_ODY_THERMAL_INIT   = 0x0B,
    };

    enum KeyAddrStashKeys
    {
        RSV_MEM_ATTR_ADDR  = 0x01,  // Start at non-zero
        DEPRECATED_1       = 0x02,  // 0x2 was previously planned to be
                                    // used to pass HRMOR but SBE did not
                                    // implement it. There is old version
                                    // of hostboot that look at this so
                                    // reusing this could break backwards
                                    // compatibility
        RELOC_PAYLOAD_ADDR = 0x03,
        ARCH_REG_DATA_ADDR = 0x04,
        //On SBE side struct is defaulted so that
        //Keys are 0xFF and Vals are 0xFFFFFFFFFFFFFFFF
        //So a key w/ FF means its empty or at its default val
        SBE_DEFAULT       = 0xFF
    };

    /**
     * @brief Enum denoting the image side of a device to check for SPI flash errors.
     *        Used with SPI flash checking chip op. The different sides can
     *        be OR'ed together for multi-side check.
     */
    enum flashCheckSide : uint8_t
    {
        SIDE_0       = 0x1,
        SIDE_1       = 0x2,
        SIDE_GOLDEN  = 0x4,
        ALL_SIDES    = SIDE_0 | SIDE_1 | SIDE_GOLDEN,
    };

    /**
     * @brief Enum denoting the scope of SPI flash check:
     *        - IMAGE only checks the images present on the flash
     *        - FULL checks the entire flash side of the device (including padding
     *        and space between images)
     */
    enum flashCheckScope : uint8_t
    {
        IMAGE = 0x01,
        FULL  = 0x02,
    };

    /**
     * @brief Enum denoting the device selection of the devices to run SPI flash check on.
     *        The different devices can be OR'ed together for multi-device check.
     */
    enum flashCheckDeviceId : uint8_t
    {
        DEVICE_0 = 0x01,
        DEVICE_1 = 0x02,
        DEVICE_2 = 0x04,
        DEVICE_3 = 0x08,
        ALL_DEVICES = DEVICE_0 | DEVICE_1 | DEVICE_2 | DEVICE_3,
    };

    /**
     * @brief The type returned by sbeMalloc and deallocated by sbeFree
     */
    class sbeAllocationHandle_t
    {
      public:
        // Pointer to the beginning of allocated memory
        void* bufPtr;

        // Cacheline-aligned address (==dataPtr as non pointer type)
        uint64_t aligned;

        // Virtual address of cacheline-aligned data buffer
        void* dataPtr;

        // Physical address of cacheline-aligned data buffer
        uint64_t physAddr;

        sbeAllocationHandle_t( void* i_bufPtr = nullptr,
                               uint64_t i_aligned = 0,
                               void* i_dataPtr = nullptr,
                               uint64_t i_physAddr = 0 )
          : bufPtr(i_bufPtr), aligned(i_aligned),
            dataPtr(i_dataPtr), physAddr(i_physAddr)
        {};

        /* @brief Null test for data member.
         */
        operator bool() const
        {
            return bufPtr;
        };
    };

    /**
     * @brief Allocate memory suitable to pass to SBE
     *
     * @note The memory allocated by this function should be deallocated by
     *       passing the returned sbeAllocationHandle_t to sbeFree. Do NOT
     *       pass the value of o_allocation to free().
     *
     * @param[in] i_bytes      The number of bytes to allocate
     * @param[in] o_allocation The resulting memory allocation
     *
     * @return sbeAllocationHandle_t A handle that should be passed to sbeFree
     *                               to deallocate the memory.
     */
    sbeAllocationHandle_t sbeMalloc(size_t i_bytes, void*& o_allocation);
    sbeAllocationHandle_t sbeMalloc(size_t i_bytes);

    /**
     * @brief Frees an allocation previously allocated with sbeMalloc
     *
     * @param[in] i_handle The handle to deallocate
     */
    void sbeFree(sbeAllocationHandle_t& i_handle);

    /**
     * @brief Start Deadman loop
     *
     * @note  This function must not be called twice without an intervening call
     *        to stopDeadmanLoop.
     *
     * @param[in] i_waitTime     Time to wait in milliseconds
     * @param[in] i_regInits     Array of SCOM register/value pairs to write
     * @param[in] i_regInitCount Number of elements in i_regInits
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t startDeadmanLoop(
        uint64_t i_waitTime,
        const std::pair<uint64_t, uint64_t>* i_regInits = nullptr,
        size_t i_regInitCount = 0
    );

    /**
     * @brief Stop Deadman loop
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t stopDeadmanLoop( );

    /**
    * @brief Send System Configuration
    *
    * @param[in] i_systemConfig Fabric grouping map bitstring
    *                           Examples:
    *                           bit 0  = proc 0 group 0
    *                           bit 8  = proc 0 group 1
    *                           bit 12 = proc 4 group 1
    * @param[in] i_procChip     Proc you would like to send the config to
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendSystemConfig(const uint64_t i_systemConfig,
                                TARGETING::Target * i_procChip);


    /**
    * @brief Send the TPM Extend Mode command to the SBE with Enter ctrl flag
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t psuTPMExtendModeEnter();


    /**
    * @brief Send the TPM Extend Mode command to the SBE with Exit ctrl flag
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t psuTPMExtendModeExit();


    /**
    * @brief Send the signal to the sbe that we are performing a MPIPL
    *
    * @param[in] i_procChip The proc you would like to request continueMPIPL to
    *                       NOTE: HB should only be sending this to slave procs
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendContinueMpiplRequest(TARGETING::Target * i_procChip);


    /**
     * @brief Sends a PSU chipOp to quiesce the SBE
     *
     * @param[in]  i_pProc  Processor target with SBE to quiesce.
     *     Throws error if requested target is nullptr or does not
     *     refer to a processor.
     *
     * @note Sets the requested processor's ASSUME_SBE_QUIESCED attribute
     *   to true to inhibit future quiesce sensitive operations.
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t sendPsuQuiesceSbe(TARGETING::Target* i_pProc);


    /**
     * @brief Send OCMB configuration info to the SBE
     *
     * @param[in] i_pProc - Pointer to the PROC target that contains
     *                      the OCMB Targets
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t psuSendSbeOcmbConfig(TARGETING::Target* i_pProc);

    /**
     * @brief Send Memory configuration info to the SBE
     *
     * @param[in] i_pProc - Pointer to the PROC target that contains
     *                      the Memory Targets
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t psuSendSbeMemConfig(TARGETING::Target* i_pProc);

    /**
     * @brief Send Core configuration info to the SBE
     *
     * @param[in] i_pProc - Pointer to the PROC target that contains
     *                      the Cores
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t psuSendSbeCoreConfig(TARGETING::Target* i_pProc);


    /*
     * @brief Get PMIC Health Check Data from the SBE for the given 4U DDIMM. Optionally, associate the committed health
     *        check log with the given PLID.
     *
     * @param[in]  i_ocmb     The OCMB target used to collect the 4U DDIMM data from.
     * @param[in]  i_plid     The PLID to associate the committed log to, if needed.
     */
    void get4uDdimmPmicHealthCheckData(TARGETING::Target * i_ocmb, uint32_t i_plid = 0);

    /**
     * @brief Get PMIC Health Check Data from the SBE
     *
     * @param[in] i_ddr5_health_check A flag set from the registered
     *            callback which indicates if this is for a HWP Health
     *            Check or HWP Telemetry Check
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t getAllPmicHealthCheckData(bool i_ddr5_health_check = false);

     /**
     * @brief Get the capabilities of the SBE via PSU
     *
     * @param[in]  i_target Target with SBE to get capabilities from
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t getPsuSbeCapabilities(TARGETING::TargetHandle_t i_target);

     /**
     * @brief Get the capabilities of the SBE via FIFO
     *
     * @param[in]  i_target Target with SBE to get capabilities from
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t getFifoSbeCapabilities(TARGETING::TargetHandle_t i_target);

    /**
    * @brief Checks whether the SBE supports the SPI flash check chip-op.
    * @note If ATTR_SBE_NUM_CAPABILITIES or ATTR_SBE_FIFO_CAPABILITIES
    *       are not populated, the function will return false.
    *
    * @param[in] i_sbe the SBE chip to check for capability
    * @return true : SBE supports SPI flash check; false : SBE does not
    *         support SPI flash check.
    */
    bool sbeSpiFlashCheckSupported(TARGETING::Target* const i_sbe);



    /**
    * @brief Package and Send Exit Cache Contained to the SBE via PSU
    *
    * @param[in]  i_argPtr  Buffer of Input arguments from HWP Call
    *             i_argSize Size of Input argument data
    */
    errlHndl_t sendExitCacheContainedOp(const uint8_t * i_argPtr,
                                        size_t    i_argSize );

    /**
    * @brief Send putSram chipop to the SBE via SBE FIFO
    *
    * @param[in]  i_argPtr  Buffer of Input arguments from HWP Call
    *             i_argSize Size of Input argument data
    *
    * @return errlHndl_t Error log handle on failure.
    */
    errlHndl_t sendPutSramOp(const uint8_t * i_argPtr,
                             size_t    i_argSize );


    /**
    * @brief Sends a PSU chipOp to stash away a key,addr pair on the SBE
    *
    * @param[in]  i_key      The key used to identify what the value is
    * @param[in]  i_value    Value that will be passed (likely an address)
    * @param[in]  i_procChip The proc we wish to send the op to
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuStashKeyAddrRequest(const uint8_t i_key,
                                          const uint64_t i_value,
                                          TARGETING::Target * i_procChip);

    /**
     * @brief Get SCOM via SBE FIFO
     *
     * @param[in]  i_target  Processor Target to access
     * @param[in]  i_addr    Requested register address
     * @param[out] o_data    Returned data
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t getFifoScom(TARGETING::Target * i_target,
                           uint64_t            i_addr,
                           uint64_t          & o_data);
    /**
     * @brief Put SCOM via SBE FIFO
     *
     * @param[in]  i_target  Processor Target to access
     * @param[in]  i_addr    Requested register address
     * @param[in]  i_data    Data to write
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t putFifoScom(TARGETING::Target * i_target,
                           uint64_t            i_addr,
                           uint64_t            i_data);

    /**
     * @brief Put SCOM under mask via SBE FIFO
     *
     * @param[in]  i_target  Processor Target to access
     * @param[in]  i_addr    Requested register address
     * @param[in]  i_data    Data to write
     * @param[in]  i_mask    SCOM mask
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t putFifoScomUnderMask(TARGETING::Target * i_target,
                                    uint64_t            i_addr,
                                    uint64_t            i_data,
                                    uint64_t            i_mask);

    /**
     * @brief Issue Reset to SBE FIFO.  Note this can ONLY be
     *        done on slave processors on FSI SBE FIFO path
     *        never on the master chip.  This function is
     *        only intended to be used to cleanup the FIFO
     *        on IPLs -- as it doesn't follow the protocol
     *        with a running SBE
     *
     *
     * @param[in]  i_target  Processor Target to access
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t sendFifoReset(TARGETING::Target * i_target);

    /**
    * @brief Get the SBE FFDC.  Request that SBE retrieve the SBE FFDC
    *
    * @param[in]     i_chip      The chip from which to get the SBE FFDC
    * @param[out]    o_pFifoResponse Pointer to response
    * @param[in]     i_responseSize  Size of response in bytes
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t getFifoSBEFFDC(TARGETING::Target *i_chip,
                              uint32_t *o_pFifoResponse,
                              uint32_t &i_responseSize);

    /**
     * @brief Sends a scratch data request to all OCMB chips
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t purgeAllSbeScratchData();

    /**
     * @brief A helper function to handle the PRD's request to grab the SBE
     *        scratch reg data (Synopsys data). The function will commit any
     *        internal error logs that are produced. If any are produced, they
     *        will be linked to the input PLID.
     *
     * @param[in] i_chipTarget the Odyssey chip target
     * @param[in] i_plid the optional PLID to link the error log(s) to
     */
    void handleGetScratchDataPrdRequest(TARGETING::Target* i_chipTarget, uint32_t i_plid = 0);

    /**
     * @brief Purges data stored in the SBE Scratch area.
     *
     * @param[in] i_chipTarget The chip you would like to perform the chipop on
     *                       NOTE: HB should only be sending this to Odyssey chips
     * @param[out]    o_pFifoResponse Pointer to response
     * @param[in]     i_responseSize  Size of response in bytes
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t sendPurgeScratchDataRequest(TARGETING::Target      * i_chipTarget,
                                           uint32_t               * o_pFifoResponse,
                                           uint32_t                 i_responseSize);
    /**
     * @brief Retrieves data stored in the SBE Scratch area. Due to tight memory constraints, the SBE scratch area will
     *        always be cleared on successful execution of this command. The data in the scratch area is typically
     *        generated by hardware procedures running on the SBE.
     *        NOTE: The response from the chip-op is larger than Hostboot's stack size so the buffer needs to be
     *              allocated on the heap. To ease the caller's responsibility this chip-op allocates a shared_ptr of
     *              the correct size and returns it to the caller.
     *
     * @param[in] i_chipTarget The chip you would like to perform the chipop on
     *                       NOTE: HB should only be sending this to Odyssey chips
     * @param[out]    o_pFifoResponse Pointer to response. IN: nullptr OUT: Points to the response buffer
     * @param[out]    o_actualSize The size of the actual returned data
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    // Declare a couple of helpful consts for sendGetScratchDataRequest.
    constexpr uint32_t MAX_SBE_SCRATCH_DATA_WORDS = (64 * KILOBYTE) / sizeof(uint32_t);
    typedef std::shared_ptr<std::array<uint32_t, MAX_SBE_SCRATCH_DATA_WORDS>> sbeScratchDataResponse_t;
    errlHndl_t sendGetScratchDataRequest(TARGETING::Target      * i_chipTarget,
                                         sbeScratchDataResponse_t & o_pFifoResponse,
                                         uint32_t                 & o_actualSize);

    /**
     * @brief Retrieve data stored in the SBE scratch area and produce error log(s)
     *        with this data as FFDC fields. If the total size of scratch data is
     *        bigger than the size of one error log, the data will be split between
     *        multiple error logs. The resulting error logs are tied with PLID and
     *        are aggregated together for ease of management.
     *
     * @param[in] i_chipTarget the Odyssey chip target to retrieve the scratch
     *            data from.
     * @param[out] o_errls the error log(s) with Odyssey scratch data.
     *
     * @return Valid error log if a failure occurred while fetching the scratch
     *         data; nullptr otherwise.
     * @note o_errls will not be valid if an error is returned.
     */
    errlHndl_t getAndProcessScratchData(TARGETING::Target* i_chipTarget,
                                        errlHndl_t& o_errls);


#ifndef __HOSTBOOT_RUNTIME
    /**
    * @brief Set the FFDC address for the SBE so it is aware of the FFDC buffer
    *        and its size and it is aware of the SBE Communication buffer and
    *        its size
    *
    * @param[in] i_sbeffdcSize uint32 Size of SBE FFDC buffer
    * @param[in] i_sbeCommSize uint32 Size of SBE Communication buffer
    * @param[in] i_sbeffdcAddr uint64 Physical mainstore address of FFDC buffer
    * @param[in] i_sbeCommAddr uint64 Physical mainstore address of Comm buffer
    * @param[in] i_procChip The proc to which you would like to send the info
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendSetFFDCAddr(const uint32_t i_sbeffdcSize,
                               const uint32_t i_sbeCommSize,
                               const uint64_t i_sbeffdcAddr,
                               const uint64_t i_sbeCommAddr,
                               TARGETING::Target * i_procChip);
#endif //__HOSTBOOT_RUNTIME

    /**
     * @brief Open Unsecure Memory Region via the SBE
     *
     * @param[in] i_start_addr  Starting Physical Memory Address of the
     *                          Unsecure Memory Region to Open
     *
     * @param[in] i_size        Size in bytes of the Unsecure Memory Region
     *                          Assert if size = 0
     *
     * @param[in] i_isWritable  Specifies if the Unsecure Memory is Read-Only
     *                          or Read-Write: If false then Read-Only Region
     *                                         If true then Read-Write Region
     *
     * @param[in] i_target      Processor Target associated with SBE command
     *                          If nullptr, default to Master Processor
     *
     * @return errlHndl_t Error log handle on failure.
     *
     * @note  Function is not thread-safe.
     * @note  Read-Only/Read-Write settings and Target associated with the
     *        region are not considered when closing any existing regions
     *        that overlap with the requested region to open.
     */
    errlHndl_t openUnsecureMemRegion(const uint64_t i_start_addr,
                                     const uint32_t i_size,
                                     const bool     i_isWritable,
                                     TARGETING::Target*  i_target=nullptr);

    /**
     * @brief Close Unsecure Memory Region
     *
     * @param[in] i_start_addr  Starting Physical Memory Address of the
     *                          Unsecure Memory Region to Close
     *
     * @param[in] i_target      Processor Target associated with SBE command
     *                          If nullptr, default to Master Processor
     *
     * @return errlHndl_t Error log handle on failure.
     *
     * @note  Function is not thread-safe.
     */
    errlHndl_t closeUnsecureMemRegion(const uint64_t i_start_addr,
                                      TARGETING::Target*  i_target=nullptr);

    /**
     * @brief Close All Unsecure Memory Regions
     *
     * @return errlHndl_t Error log handle on failure.
     *
     * @note  Function is not thread-safe.
     */
    errlHndl_t closeAllUnsecureMemRegions();

    /**
     * @brief Gathers FFDC and recovers from SBE errors
     *
     * @return errlHndl_t Error log handle on failure.
     *
     * @param[in] i_target  Processor Target associated with SBE attention
     */
    errlHndl_t handleVitalAttn( TARGETING::Target* i_procTarg );

    /**
    * @brief Request the SBE to do a specific chip op
    *
    * @param[in] i_dataPointer  Pointer to a blob of data that contains
    *                           additional parameters for the requests
    *                           HWP. If a Target object is needed it is
    *                           expected to be sent as part of this
    *                           data blob.
    *
    * @param[in] i_dataSize     Size of blob of data that contains additional
    *                           parameters for the requests HWP
    *
    * @param[in] i_hwpName      Pointer to string of chars representing hwp name
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendSecureHwpRequest(uint8_t * i_dataPointer,
                                    uint64_t i_dataSize,
                                    const char * i_hwpName);

    /**
    * @brief Sends a PSU chipOp to request Seeprom read from SBE
    *
    * @param[in]  i_target         Target with SBE to send read request to
    *                              Assert if i_target == nullptr
    * @param[in]  i_seepromOffset  Offset in the seeprom image where we want
    *                              to start copying from (ignores ECC)
    * @param[in]  i_readSize       Amount of bytes we want to copy (ignores ECC)
    *                              Assert if i_readSize is not 128-byte-aligned
    * @param[in]  i_destAddr       Address that hostboot has prepared which the
    *                              sbe will write too
    *                              Assert if i_destAddr is not 8-byte aligned
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuReadSeeprom(TARGETING::Target * i_target,
                                  uint32_t i_seepromOffset,
                                  uint32_t i_readSize,
                                  uint64_t i_destAddr);

    /**
    * @brief Sends a PSU chipOp to fetch security list binary dump in the SBE
    *
    * @param[in]  i_addr         Address that hostboot has prepared which the
    *                            securityList Bin Dump addr sbe will write too
    *
    * @param[in]  i_procChip     Target with SBE to send read request to
    *                            Assert if i_procChip == nullptr
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuSecurityListBinDumpRequest(const uint64_t i_addr,
                                         TARGETING::Target *i_procChip);

    /**
    * @brief Sends a PSU chipOp to to have SBE perform a HW register read for
    *        Hostboot. Note that this works for scom addresses.
    *
    * @param[in]   i_target       Target which has the HW register we want to read.
    *                             Assert if i_target == nullptr
    * @param[in]   i_addr         HW Register Address (scom address works)
    * @param[out]  o_value        Value read from the HW register by the SBE
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuGetHwRegRequest(TARGETING::Target * i_target,
                                     const uint64_t i_addr,
                                     uint64_t & o_value);

    /**
    * @brief Sends a PSU chipOp with the value of the Fabric Topology ID Table.
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t psuSendTopologyIdTable(void);


    /**
    * @brief Send halt message to the secondary/non-boot SBE
    *        No response for halt message.
    *        User should monitor SBE ATTN bit to verify SBE is halted.
    *
    * @param[in] i_procChip The proc you would like to request halt on
    *            NOTE: HB should only be sending this to non-boot procs
    *
    * @return errlHndl_t Error log handle on failure.
    */
    errlHndl_t sendSecondarySbeHaltRequest(TARGETING::Target * i_procChip);

    /** @brief Describes the version of an SPPE code image
     */
    struct codelevel_info_t
    {
        enum codelevel_info_type
        {
            // The order of this enumeration should not be
            // changed. Code depends on it for sorting.
            bootloader,
            runtime
        };

        codelevel_info_type type;
        uint8_t hash[64];
        codelevel_info_t() {};
        codelevel_info_t(codelevel_info_type i_type, uint8_t *i_hash)
        {
            type = i_type;
            memcpy(hash,i_hash,64);
        }
    };

    /**
     * @brief Get current code levels on the given chip's SPPE.
     *
     * @param[in] i_chipTarget   The chip you would like to perform the chipop on
     *                           NOTE: Only valid on Odyssey chips.
     *
     * @return errlHndl_t        Error log handle on failure.
     */
    errlHndl_t sendGetCodeLevelsRequest(TARGETING::Target * i_chipTarget);

    /**
     * @brief Update the image described by the given codelevel info
     * structure with the given image data.
     *
     * @param[in] i_chipTarget  The Odyssey chip target.
     * @param[in] i_clip        The descriptor of the image on the SPPE to update.
     *                          (The hash is ignored.)
     * @param[in] i_img         The image contents to write to SPPE storage.
     * @param[in] i_img_size    The size of the image contents to write.
     *
     * @return errlHndl_t        Error log handle on failure.
     */
    errlHndl_t sendUpdateImageRequest(TARGETING::Target* i_chipTarget,
                                      const codelevel_info_t& i_clip,
                                      const void* i_img,
                                      size_t i_img_size);

    /**
     * @brief Sync the backup code image with the running code image.
     *
     * @param[in] i_chipTarget  The Odyssey chip target.
     * @param[in] i_force_sync  Whether to force a sync even if the code levels match.
     *
     * @return errlHndl_t        Error log handle on failure.
     */
    errlHndl_t sendSyncCodeLevelsRequest(TARGETING::Target* i_chipTarget,
                                         bool i_force_sync = false);

    /**
    * @brief Send the IO or MEMORY HWP request to the SBE.  These overloaded
    *        wrapper functions perform initial checks and then call the local
    *        function to send the HWP request.
    *
    * @param[in] i_chipTarget The Odyssey chip to perform the chipop on
    * @param[in] i_hwpNumber The HWP number, differs depending on class
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendExecHWPRequest(TARGETING::Target * i_chipTarget,
                                  fifoExecuteHardwareProcedureIo i_hwpNumber);
    errlHndl_t sendExecHWPRequest(TARGETING::Target * i_chipTarget,
                                  fifoExecuteHardwareProcedureMemory i_hwpNumber);

    /**
     * @brief Send the request to update the attributes on SPPE with the generated
     *        attribute blob from the Host (attribute push). The attribute blob
     *        is generated by a HWP and contains the attribute hashes and values
     *        of all attributes involved in attribute exchange. The blob is sent
     *        to SPPE via a chip op AD-03.
     *
     * @param[in] i_chipTarget The Odyssey chip to perform the chipop on
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t sendAttrUpdateRequest(TARGETING::Target* i_chipTarget);

    /**
     * @brief Send the attribute pull request to SPPE and process the returned attribute
     *        blob. We request the attribute blob via a chip op AD-02; SPPE returns back
     *        the list of all attributes requiring sync and their values. A HWP then
     *        takes the returned blob, parses it, and sets the Host-side of attributes
     *        according to the parsed values.
     *
     * @param[in] i_chipTarget The Odyssey chip to perform the chipop on
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t sendAttrListRequest(TARGETING::Target* i_chipTarget);

    /**
     * @brief Send the request to SBE to enable thermal sensor polling and DQA tracking.
     *        This request is sent via the chip op AC-02.
     *
     * @param[in] i_chipTarget The Odyssey chip to perform the chipop on
     * @param[in] i_interval   The thermal sensor polling interval in MS
     * @param[in] i_dqa        The DQA tracking interval
     *
     * @return errlHndl_t Error log handle on failure.
     */
    errlHndl_t sendExecHWPRequestForThermalSensorPolling(TARGETING::Target* i_chipTarget,
                                                         uint32_t i_interval,
                                                         uint8_t i_dqa);

    /**
     * @brief Grab the Odyssey FIFO FFDC and create error log(s) with the returned data.
     *        The function uses a chipop to Odyssey to get the data. The data returned from
     *        the chip varies based on a number of circumstances. When there are no error conditions
     *        on the chip the return data will be trace and attribute data. The severity of the logs
     *        are given by the SBE and it's the callers responsibility to overwrite that severity if
     *        necessary.
     *
     * @param[in] i_chipTarget The Odyssey chip to perform the chipop on
     * @param[out] o_err       All error logs returned from SBE as FFDC
     *
     * @return The error encountered while fetching FFDC, if any
     *
     * @note If an error is returned, o_errs will be unmodified.
     */
    errlOwner genFifoSBEFFDCErrls(TARGETING::Target* i_chipTarget,
                                  errlHndl_t& o_errs);

    /**
     * @brief Calls genFifoSBEFFDCErrl per each functional Odyssey OBMC chip
     *        on the system.
     *
     * @note  All errors are committed internally.
     */
    void handleGenFifoSBEFFDCErrlRequest();

    /**
     * @brief Request the SPPE to perform a SPI flash check on the given
     *        sides of the given devices.
     * @param[in] i_ocmb the SPPE target to operate on
     * @param[in] i_scope the scope of the flash check
     * @param[in] i_side a bitwise OR of the side(s) to perform the check on
     * @param[in] i_deviceId a bitwise OR of the device ID(s) to perform the check on
     *
     * @return nullptr on success; valid error log on failure
     */
    errlHndl_t sendSpiFlashCheckRequest(TARGETING::Target* i_ocmb,
                                        uint8_t i_scope,
                                        uint8_t i_side,
                                        uint8_t i_deviceId);

    /**
     * @brief If FFDC is available, grab it, parse it, and commit the
     *        resulting error logs as informational
     *
     * @param[in] i_chipTarget grab the FFDC for this OCMB target
     *
     * @return bool, flag to indicate if hreset had already been called
     */
    bool checkOdyFFDC(TARGETING::Target* i_chipTarget);

    /**
     * @brief Perform a chipop to the given OCMB to request an Odyssey
     * hardware dump, and place the contents of that dump at the given
     * (virtual) address.
     * @param[in] i_ocmb              The OCMB to dump.
     * @param[in] i_buffer            The buffer to place the dump in.
     * @param[in/out] io_buffer_size  In: the size of i_buffer. Out: The size of the dump.
     * @return Error if any, otherwise nullptr.
     */
    errlOwner getOdysseyHardwareDump(TARGETING::Target* i_ocmb,
                                     uint8_t* i_buffer,
                                     uint32_t& io_buffer_size);

} //end namespace SBEIO

#endif /* _SBEIOIF_H */
