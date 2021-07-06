/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/error_info_defs.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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

///
/// @file error_info_defs.H
/// @brief Defines to support the Error Information class
///

#ifndef FAPI2_ERRORINFO_DEFS_H_
#define FAPI2_ERRORINFO_DEFS_H_

#include <stdint.h>
#include <target.H>

#if !defined(MINIMUM_FFDC) && !defined(FAPI2_NO_FFDC)
    #include <variable_buffer.H>
    #include <utility>
#endif
namespace fapi2
{
// For HW callout - Clock position undefined to 0xFF(default)
#define CLOCK_POS_UNDEF 0xFF

///
/// @brief Type to hold the ffdc data to be sent to hostboot
///
/// Note: Typical data sent seems to be register/addresss info
///       rather than use extra space converting stuff just
///       send a uint64 always
///
struct sbeFfdc_t
{
    uint32_t  size;
    uint64_t  data;
} __attribute__((packed));

// 20 entries limits the size of SbeFfdcData_t under 256 bytes
enum
{
    MAX_SBE_FFDC_ENTRIES = 20
};

// Data type for SBE ffdc buffer sent through fifo
typedef struct
{
    uint32_t  fapiRc;      // Return code from failure
    uint32_t  ffdcLength;  // length of Fapi FFDC data (in bytes)
    struct sbeFfdc_t ffdcData[MAX_SBE_FFDC_ENTRIES]; // fapi FFDC data
} SbeFfdcData_t; // ~248 bytes

///
/// @brief Type to hold the ffdc element in the ffdc class
/// Needed so that the size can be squirled away before the
/// macro is called.
///
struct ffdc_struct
{
    const void* ptr;
    size_t size;
};


class ffdc_t
{
    public:
        ffdc_t(void)
        {}

        void operator=(const ffdc_t& i )
        {
            iv_value.ptr  = i.ptr();
            iv_value.size = i.size();
        }

        operator const void* () const
        {
            return iv_value.ptr;
        }
        operator uint8_t() const
        {
            return *(reinterpret_cast<const uint8_t*>(iv_value.ptr));
        }

        size_t size(void) const
        {
            return iv_value.size;
        }
        size_t& size(void)
        {
            return iv_value.size;
        }

        const void* ptr(void) const
        {
            return iv_value.ptr;
        }
        const void*& ptr(void)
        {
            return iv_value.ptr;
        }

    private:
        struct ffdc_struct iv_value = {}; //init to zero
};

///
/// @brief Enumeration of ErrorInfo FFDC sizes that are used to indicate a
///        special type that cannot simply be memcopied
enum ErrorInfoFfdcSize
{
    EI_FFDC_SIZE_BUF    = 0xffff,   // fapi2::buffer<T>
    EI_FFDC_SIZE_TARGET = 0xfffe,   // fapi2::Target
    EI_FFDC_SIZE_VBUF   = 0xfffd,   // fapi2::variable_buffer
    EI_FFDC_MAX_SIZE    = 0x1000,   // Limit regular FFDC capture to 4kb
};

///
/// @brief Enumeration of error log severity.
///
enum errlSeverity_t
{
    FAPI2_ERRL_SEV_UNDEFINED     = 0x00, /// Used internally by ffdc mechanism
    FAPI2_ERRL_SEV_RECOVERED     = 0x10, /// Not seen by customer
    FAPI2_ERRL_SEV_PREDICTIVE    = 0x20, /// Error recovered but customer will see
    FAPI2_ERRL_SEV_UNRECOVERABLE = 0x40  /// Unrecoverable, general
};

///
/// @brief Enumeration of ErrorInfo types
///
enum ErrorInfoType
{
    EI_TYPE_FFDC              = 0,
    EI_TYPE_HW_CALLOUT        = 1,
    EI_TYPE_PROCEDURE_CALLOUT = 2,
    EI_TYPE_BUS_CALLOUT       = 3,
    EI_TYPE_CDG               = 4, // Target Callout/Deconfig/GARD
    EI_TYPE_CHILDREN_CDG      = 5, // Children Callout/Deconfig/GARD
    EI_TYPE_COLLECT_TRACE     = 6,
    EI_LAST_TYPE              = EI_TYPE_COLLECT_TRACE + 1,
};

// @brief used when translating the SBE targets instance into a fapi pos.
enum maxTargetsPerProc : uint16_t
{
    MAX_MCBIST_PER_PROC  =  2,  //Nimbus
    MAX_MC_PER_PROC      =  2,  //Cumulus,Axone
    MAX_MI_PER_PROC      =  4,  //Cumulus,Axone
    MAX_MCS_PER_PROC     =  4,  //Nimbus
    MAX_EQ_PER_PROC      =  6,  //Nimbus,Cumulus,Axone
    MAX_MCA_PER_PROC     =  8,  //Nimbus
    MAX_PHB_PER_PROC     =  6,  //Nimbus,Cumulus,Axone
    MAX_EX_PER_PROC      = 12,  //Nimbus,Cumulus,Axone
    MAX_CORE_PER_PROC    = 24,  //Nimbus,Cumulus,Axone
    MAX_PERV_PER_PROC    = 56,  //Nimbus,Cumulus,Axone
    MAX_OBUS_PER_PROC    =  4,  //Nimbus,Cumulus,Axone
    MAX_PEC_PER_PROC     =  3,  //Nimbus,Cumulus,Axone
    MAX_OMI_PER_PROC     = 16,  //Axone
    MAX_OMIC_PER_PROC    =  6,  //Axone
    MAX_MCC_PER_PROC     =  8,  //Axone
    MAX_OCMB_CHIP_PER_PROC = MAX_OMI_PER_PROC,  //Axone
    MAX_PAU_PER_PROC     = 6,
    MAX_IOHS_PER_PROC    = 8,
    MAX_PMIC_PER_PROC    = 64,
    MAX_PAUC_PER_PROC    = 4,
    MAX_GI2C_PER_PROC    = 64,

    INVALID_TARGET_COUNT = 0xFFFF,
    INVALID_FAPI_POS     = INVALID_TARGET_COUNT,
};


#ifndef MINIMUM_FFDC
///
/// @enum HwCallout
///
/// This enumeration defines the possible Hardware Callouts that are not
/// represented by fapi2::Targets
///
/// Note that platform code may depend on the enum values starting at 0 and
/// incrementing in order to efficiently convert to a platform callout value
/// so do not reorder without consulting all platforms
///
namespace HwCallouts
{
enum HwCallout
{
    // Where indicated, a HW Callout in FAPI Error XML must include a
    // reference target that is used to identify the HW. e.g. for
    // TOD_CLOCK, the proc chip that the clock is attached to must be
    // specified
    TOD_CLOCK           = 0, // Include proc-chip ref (or child chiplet)
    MEM_REF_CLOCK       = 1, // Include membuf-chip ref (or child chiplet)
    PROC_REF_CLOCK      = 2, // Include proc-chip ref (or child chiplet)
    PCI_REF_CLOCK       = 3, // Include proc-chip ref (or child chiplet)
    FLASH_CONTROLLER_PART      = 4,
    PNOR_PART                  = 5,
    SBE_SEEPROM_PART           = 6,
    VPD_PART                   = 7,
    LPC_SLAVE_PART             = 8,
    GPIO_EXPANDER_PART         = 9,
    SPIVID_SLAVE_PART          = 10,
};
}

///
/// @enum ProcedureCallout
///
/// This enumeration defines the possible Procedure Callouts
/// These instruct the customer/customer-engineer what to do
///
/// Note that platform code may depend on the enum values starting at 0 and
/// incrementing in order to efficiently convert to a platform callout value
/// so do not reorder without consulting all platforms
///
namespace ProcedureCallouts
{
enum ProcedureCallout
{
    CODE                  = 0, // Code problem
    LVL_SUPPORT           = 1, // Call next level of support
    MEMORY_PLUGGING_ERROR = 2, // DIMM Plugging error
    BUS_CALLOUT           = 3, // Bus Called Out
    FIND_DECONFIGURED_PART = 4, // Error caused by other deconfigurations
};
}

///
/// @enum CalloutPriority
///
/// This enumeration defines the possible Procedure and Target callout priorities
///
/// Note that platform code may depend on the enum values starting at 0 and
/// incrementing in order to efficiently convert to a platform priority value
/// so do not reorder without consulting all platforms
///
namespace CalloutPriorities
{
enum CalloutPriority
{
    LOW = 0,
    MEDIUM = 1,
    HIGH   = 2,
    NONE   = 3,
};
}

///
/// @enum CollectTrace
///
/// This enumeration defines the possible firmware traces to collect
///
namespace CollectTraces
{
const uint32_t TRACE_SIZE = 256; // limit collected trace size
enum CollectTrace
{
    FSI              = 1,
    SCOM             = 2,
    SCAN             = 3,
    MBOX             = 4,
};
}

///
/// @enum gardType
///
/// This enumeration defines the possible gard types
/// NOTE:This gardType is same as the gard types defined in HWAS
/// so they should always be kept in sync.
///
namespace GardTypes
{
enum GardType
{
    GARD_NULL                   = 0x00,
    GARD_User_Manual            = 0xD2, //Manual Guard.
    GARD_Unrecoverable          = 0xE2, //TODO:RTC-76814
    GARD_Fatal                  = 0xE3, //IPL Failures, and others.
    GARD_Predictive             = 0xE6, //Policy flag to disable.
    GARD_Power                  = 0xE9, //Needed since EID is NOT passed in.
    GARD_PHYP                   = 0xEA, //Needed since EID is NOT passed in.
    GARD_Reconfig               = 0xEB, //Force deconfig on reconfig loop
    GARD_Void                   = 0xFF,
};
}

// @brief convert the processor relative sbe target instance into a fapi pos
//
// @param[in] i_targType - type of target from SBE FFDC buffer
// @param[in] i_proc     - current SBE processor number
// @param[in] i_instance - instance of i_targType relitive to the processor
//                         number i_proc.
//
uint16_t convertSbeTargInstanceToFapiPos(fapi2::TargetType i_targType,
        fapi2::Target<TARGET_TYPE_PROC_CHIP>& i_proc, uint16_t i_instance);

// NOTE - this assumes no buffer_t or variable_buffers are passed
//        data is converted to a uint64_t when placed into the sbe ffdc
//        buffer
inline fapi2::ffdc_t getFfdcData( sbeFfdc_t& i_sbeFfdc, uint8_t i_proc_instance,
                                  bool& invalid_data )
{
    fapi2::ffdc_t l_ffdc;

    l_ffdc.size() = static_cast<size_t>(i_sbeFfdc.size);

    if(l_ffdc.size() == EI_FFDC_SIZE_TARGET)
    {
#ifdef FAPI2_ENABLE_PLATFORM_GET_TARGET
        // target data will be in format
        // 0:47     = target type
        // 48:63    = instance

        uint64_t targetData = i_sbeFfdc.data;
        // get a fapi target for the passed in proc instance
        auto l_proc =
            getTarget<TARGET_TYPE_PROC_CHIP>(i_proc_instance);

        fapi2::TargetType type = static_cast<fapi2::TargetType>(targetData >> 16);

        // sbe returns the target instance based on processor scope,
        // we will need to convert that number to system scope (FAPI_POS)
        uint16_t instance = static_cast<uint16_t>(targetData & 0xFFFF);
        uint16_t fapi_pos = convertSbeTargInstanceToFapiPos(type, l_proc, instance);

        if( fapi_pos == INVALID_FAPI_POS )
        {
            invalid_data = true;
        }
        else
        {
            // call hostboot to get the fapi2 target pointer
            l_ffdc.ptr() = static_cast<void*>(getTarget<TARGET_TYPE_ALL>(type, fapi_pos));

            if(l_ffdc.ptr() == nullptr )
            {
                invalid_data = true;
            }
        }

#endif
    }
    else
    {
        // validate the size in the buffer - assumes no buffers are returned
        // from sbe -
        switch( i_sbeFfdc.size )
        {
            // valid sizes are 1,2,4 and 8 bytes only.
            case 1:
            case 2:
            case 4:
            case 8:
                // data is at least a reasonable size
                break;

            default:
                FAPI_ERR("Invalid data size in SBE FFDC buffer, i_sbeFfdc.size = %d",
                         i_sbeFfdc.size);
                invalid_data = true;
        }

        if(!invalid_data)
        {
            // adjust the pointer based on the data size.
            l_ffdc.ptr() = static_cast<void*>(reinterpret_cast<uint8_t*>(&i_sbeFfdc.data) +
                                              (sizeof(uint64_t) - i_sbeFfdc.size));
        }
    }

    return l_ffdc;
}
#endif
///
/// @brief Get FFDC Size
///
/// This is called by the FAPI_SET_HWP_ERROR macro to find out the size of
/// FFDC data. If the data is of a special type that is handled differently
/// than types that are simply memcopied then it is handled by a template
/// specialization.
/// If this function template is instantiated with a pointer, the compile
/// will fail.
///
/// @return uint16_t. Size of the FFDC data
///
template<typename T>
inline uint16_t getErrorInfoFfdcSize(const T&)
{
    static_assert(sizeof(T) <= EI_FFDC_MAX_SIZE,
                  "FFDC too large to capture");
    return sizeof(T);
}
#if !defined(MINIMUM_FFDC) && !defined(FAPI2_NO_FFDC)
///
/// @brief Compile error if caller tries to get the FFDC size of a pointer
///
template<typename T>
inline uint16_t getErrorInfoFfdcSize(const T*)
{
    static_assert(std::is_pointer<T>::value,
                  "pointer passed to getErrorInfoFfdcSize");
    return 0;
}
#endif
///
/// @brief Get FFDC Size specialization for fapi2::Target
///
template<fapi2::TargetType T, MulticastType M, typename V>
inline uint16_t getErrorInfoFfdcSize(const fapi2::Target<T, M, V>&)
{
    return EI_FFDC_SIZE_TARGET;
}

#if !defined(MINIMUM_FFDC) && !defined(FAPI2_NO_FFDC)
///
/// @brief Get FFDC Size specialization for variable buffers
///
template<>
inline uint16_t getErrorInfoFfdcSize(const fapi2::variable_buffer& i_thing)
{
    // Limit a variable buffer to 4kb bytes, and we can memcpy the storage.
    return std::min(static_cast<uint32_t>(EI_FFDC_MAX_SIZE),
                    i_thing.getLength<uint8_t>());
}
#endif

///
/// @brief Get FFDC Size specialization for ffdc_t
///
template<>
inline uint16_t getErrorInfoFfdcSize(const fapi2::ffdc_t& i_ffdc)
{
    return static_cast<uint16_t>(i_ffdc.size());
}

};

#endif // FAPI2_ERRORINFO_DEFS_H_
