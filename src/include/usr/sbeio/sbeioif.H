/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbeioif.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
     * @brief The type returned by sbeMalloc and deallocated by sbeFree
     */
    struct sbeAllocationHandle_t
    {
        void* data = nullptr;

        /* @brief Null test for data member.
         */
        operator bool() const
        {
            return data;
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

    /**
     * @brief Frees an allocation previously allocated with sbeMalloc
     *
     * @param[in] i_handle The handle to deallocate
     */
    inline void sbeFree(sbeAllocationHandle_t& i_handle)
    {
        free(i_handle.data);
        i_handle.data = nullptr;
    }

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
    * @brief Semd System Configuration
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
    * @param[in]     i_procChip      The proc from which to get the SBE FFDC
    * @param[out]    o_pFifoResponse Pointer to response
    * @param[in]     i_responseSize  Size of response in bytes
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t getFifoSBEFFDC(TARGETING::Target *i_procChip,
                              uint32_t *o_pFifoResponse,
                              uint32_t &i_responseSize);
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
    * @param[out] o_opSupported    Bool which tells us if the sbe supports the
    *                              chipOp or not
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuReadSeeprom(TARGETING::Target * i_target,
                                  uint32_t i_seepromOffset,
                                  uint32_t i_readSize,
                                  uint64_t i_destAddr,
                                  bool   & o_opSupported);

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

} //end namespace SBEIO

#endif /* _SBEIOIF_H */
