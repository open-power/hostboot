/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/bltohbdatamgr.H $                          */
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

#ifndef __BLTOHBDATAMANAGER_H
#define __BLTOHBDATAMANAGER_H

#include <stdint.h>
#include <bootloader/bootloaderif.H>

// BlToHbDataManager class
class BlToHbDataManager
{
    private:

        /*
         * @brief Prints, via printkd, important parts of the structure
         *
         * @return N/A
         */
        void print() const;

        // Data received from the bootloader
        static Bootloader::BlToHbData iv_data;
        // Indicates if the class has been instantiated or not
        static bool iv_instantiated;
        // Indicates if the class has been initialized or not
        static bool iv_initialized;
        // Indicates if data received from the bootloader is valid
        static bool iv_dataValid;
        // Size of data that needs to be preserved and pinned.
        static size_t iv_preservedSize;
        // Converts secureROM pointer to a 64-bit address
        const uint64_t getSecureRomAddr() const;
        // Converts hw keys hash pointer to a 64-bit address
        const uint64_t getHwKeysHashAddr() const;
        // Converts HBB header pointer to a 64-bit address
        const uint64_t getHbbHeaderAddr() const;

        // Needed for testcases
        friend class AttrTankTest;

    public:

        /**
         * @brief Default Constructor
         */
        BlToHbDataManager();

        /**
         * @brief Initializes all internal data. At the time this class is
         *        instantiated the data is not known, so created this function
         *        as a type of "pseudo" constructor for the class.
         *
         * @param[in]  i_data Bootloader to Hostboot Data to initialize the
         *                    internal data with.
         *
         * @return N/A
         */
        void initValid (const Bootloader::BlToHbData& i_data);

        /**
         * @brief Sets internal members to indicate that the class has been
         *        initialized, but is invalid
         *
         * @return N/A
         */
        void initInvalid();

        /**
         * @brief Relocates preserved data to a location in cache that will not
         *        be flushed
         *        NOTE: Asserts that it's only called during initialization
         *
         * @return N/A
         */
        void relocatePreservedArea();

        /*
         * @brief Returns internal branchtable offset
         *
         * @return uint64_t     branchtable offset
         */
        const uint64_t getBranchtableOffset() const;

        /*
         * @brief Returns internal pointer to secureROM
         *
         * @return void*     pointer to secureROM
         */
        const void* getSecureRom() const;

        /*
         * @brief Returns internal secureRomSize
         *
         * @return size_t     secureRomSize
         */
        const size_t getSecureRomSize() const;

        /*
         * @brief Returns internal pointer to hwKeysHash
         *
         * @return void*      pointer to hwKeysHash
         */
        const void* getHwKeysHashPtr() const;

        /*
         * @brief Returns internal hwKeysHashSize
         *
         * @return size_t     hwKeysHashSize
         */
        const size_t getHwKeysHashSize() const;

        /*
         * @brief Returns internal Minimum FW Secure Version
         *
         * @return uint8_t     min_secure_version
         */
        const uint8_t getMinimumSecureVersion() const;

        /*
         * @brief Returns Measurement Seeprom version
         *
         * @return uint32_t     measurement_seeprom_version
         */
        const uint32_t getMeasurementSeepromVersion() const;

        /*
         * @brief Returns internal pointer to hbbHeader
         *
         * @return void*     pointer to hbbHeader
         */
        const void* getHbbHeader() const;

        /*
         * @brief Returns internal hbbHeaderSize
         *
         * @return size_t     hbbHeaderSize
         */
        const size_t getHbbHeaderSize() const;

        /*
         * @brief Returns internal Secure Setting: Secure Access Bit
         *
         * @return bool     Secure Access Bit
         */
        const bool getSecureAccessBit() const;

        /*
         * @brief Returns internal Secure Setting: Security Override
         *
         * @return bool     Security Override Setting
         */
        const bool getSecurityOverride() const;

        /*
         * @brief Returns internal Secure Setting: Allow Attribute Overrides
         *        in Secure Mode
         *
         * @return bool      Allow Attribute Overrides Setting
         */
        const bool getAllowAttrOverrides() const;

        /*
         * @brief Returns internal preserved size
         *
         * @return size_t     preserved size
         */
        const size_t getPreservedSize() const;

        /*
         * @brief Indicates if internal data is valid or not
         *
         * @return bool     true if valid; false otherwise
         */
        const bool isValid() const;

        /*
         * @brief Returns LPC BAR setup by SBE
         *
         * @return uint64_t     LPC BAR
         */
        const uint64_t getLpcBAR() const;

        /*
         * @brief Returns XSCOM BAR setup by SBE
         *
         * @return size_t     XSCP< BAR
         */
        const uint64_t getXscomBAR() const;

        /*
         * @brief Returns internal BlToHbData size
         *
         * @return size_t     BlToHbData size
         */
        const size_t getBlToHbDataSize() const;

       /**
        * @brief returns the number of key/address pairs passed to BL by SBE
        *
        * @return size_t the number of key/address pairs
        */
        const size_t getNumKeyAddrPair() const;

        /*
        * @brief The key/addr array is stored in the memory like so:
        *        [key0key1...keyNAddr0Addr1...AddrN]. This function will return
        *        the pointer to the key0. The number N can be fetched via
        *        getNumKeyAddrPairs().
        *
        * @return uint8_t* A Pointer to the first key in the key/addr array.
        */
        const uint8_t* getKeys() const;

        /*
        * @brief The key/addr array is stored in the memory like so:
        *        [key0key1...keyNAddr0Addr1...AddrN]. This function will return
        *        the pointer to the Addr0. The number N can be fetched via
        *        getNumKeyAddrPairs().
        *
        * @return uint64_t* A Pointer to the first address in the key/addr array
        */
        const uint64_t* getAddresses() const;

        /*
        * @brief Returns the value of SBE security backdoor enabled bit
        *
        * @return bool true if enabled; false otherwise
        */
        const bool getSecBackdoor() const;

        /*
         * @brief Returns the number of megabytes of cache memory allocated
         *        for hostboot.
         * @return The size of hostboot cache in MB
         */
        const size_t getHbCacheSizeMb() const;

        /*
         * @brief Returns the number of bytes of cache memory allocated
         *        for hostboot.
         * @return The size of hostboot cache in bytes
         */
        const size_t getHbCacheSizeBytes() const;

        /*
         * @brief Returns the originator of TDP (TPM Deconfig Protect) flag
         *
         * @return The enum indicating the source of the TDP bit
         */
        const Bootloader::TdpBitSources getTdpSource() const;

        /*
         * @brief Returns the value of the return code of a TPM operation that
         *        may have failed in HBBL
         *
         * @return The RC of the op that failed in HBBL
         */
        const uint32_t getTpmRc() const;

        /*
         * @brief Returns the current version of the HBBL->HB comm area
         *
         * @return The current version of the HBBL->HB comm area
         */
        const uint64_t getVersion() const;
};

// Extern global instance of the class
extern BlToHbDataManager g_BlToHbDataManager;

#endif
