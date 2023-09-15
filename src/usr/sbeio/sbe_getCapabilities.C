/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_getCapabilities.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
* @file sbe_getCapabilities.C
* @brief Get the capabilities from the SBE
*/

#include <errl/errlmanager.H> // errlHndl_t
#include <sbeio/sbe_psudd.H>  // SbeFifo::psuCommand
#include "sbe_fifodd.H"       // SbeFifo::fifoGetCapabilitiesRequest
#include <sbeio/sbe_utils.H>
#include <sbeio/sbeioreasoncodes.H> // SBEIO_PSU, SBEIO_FIFO,
#include <targeting/common/commontargeting.H>  // get_huid
#include <targeting/targplatutil.H>  //getCurrentNodeTarget
#include <targeting/odyutil.H>
#include <util/align.H>            // ALIGN_X
#include <sys/mm.h>                // mm_virt_to_phys
#include <sbeio/sbeioif.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
            TRACFCOMP(g_trac_sbeio, printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
            TRACDCOMP(g_trac_sbeio, printf_string,##args)
#define SBE_TRACDBIN(printf_string,args...) \
            TRACDBIN(g_trac_sbeio, printf_string,##args)

namespace SBEIO
{
using namespace TARGETING;
using namespace ERRORLOG;

/**
 * @brief header for p10 getCapabilities Response
 */
struct sbeCapabilities_hdr_t
{
    uint16_t majorVersion;
    uint16_t minorVersion;
    uint32_t commitId;
    char     releaseTag[SBE_RELEASE_TAG_MAX_CHARS];  // AKA build tag
} PACKED;

/**
 * @brief header for Odyssey getCapabilities Response
 */
struct sbeCapabilities_hdr_ody_t
{
    uint16_t majorVersion;
    uint16_t minorVersion;
    char     sbeBuildTag[SBE_RELEASE_TAG_MAX_CHARS];
    char     ekbBuildTag[SBE_RELEASE_TAG_MAX_CHARS];
} PACKED;

/**
 * @brief layout of an Odyssey Image for getCapabilities Response
 */
struct sbeImageInfo_t
{
    uint16_t reserved1;
    uint16_t imageType;
    uint32_t buildTime;
    uint32_t Identifier;
};

/**
 * @brief typename for each element of the capabilities array
 */
typedef uint32_t sbeCapability_t;

/**
 * @brief A Base Class to support using the GetCapabilities Response
 *
 *   The default ctor does nothing but init vars to zero
 *   The init method allocates the rsp buffer to the requested size
 *   Methods exist to get a pointer for each section,
 *     and to access data within the headers.
 */
class sbeCapabilities_rsp_t : public sbeFifo_rsp_t
{
  protected:
    bool iv_is_proc{false};
    bool iv_is_ody{false};
    bool iv_has_commitId{false};
    bool iv_has_releaseTag{false};
    bool iv_has_sbeBuildTag{false};
    bool iv_has_ekbBuildTag{false};
    bool iv_has_fifoCapabilities{false};

  public:
    bool                is_proc()              const {return iv_is_proc;}
    bool                is_ody()               const {return iv_is_ody;}
    bool                has_commitId()         const {return iv_has_commitId;}
    bool                has_releaseTag()       const {return iv_has_releaseTag;}
    bool                has_sbeBuildTag()      const {return iv_has_sbeBuildTag;}
    bool                has_ekbBuildTag()      const {return iv_has_ekbBuildTag;}
    bool                has_fifoCapabilities() const {return iv_has_fifoCapabilities;}
    virtual uint32_t    getCommitId()          const {return 0;}
    virtual const char* getReleaseTag()        const {return nullptr;}
    virtual const char* getSbeBuildTag()       const {return nullptr;}
    virtual const char* getEkbBuildTag()       const {return nullptr;}
    /**
     * @brief return the majorVersion in the hdr
     */
    uint16_t getMajor() const
    {
        return reinterpret_cast<const sbeCapabilities_hdr_t*>(iv_rsp.data())->majorVersion;
    };
    /**
     * @brief return the minorVersion in the hdr
     */
    uint16_t getMinor() const
    {
        return reinterpret_cast<const sbeCapabilities_hdr_t*>(iv_rsp.data())->minorVersion;
    };
    /**
     * @brief return the size of the image info array in bytes
     */
    virtual uint16_t getImgSize() const {return 0;}
    /**
     * @brief return a ptr to the image info array
     */
    virtual const sbeCapability_t* getImgPtr() const {return nullptr;};
    /**
     * @brief return the size of the capabilities array in bytes
     */
    virtual uint16_t getCapSize() const {return 0;}
    /**
     * @brief return a ptr to the capabilities array
     */
    virtual const sbeCapability_t* getCapPtr() const {return nullptr;}
    /**
     * @brief return a pointer to the fifo response data
     */
    virtual const SbeFifo::fifoStandardResponse* getEndPtr() const = 0;
    /**
     * @brief evaluate if the major/minor supports Halt Status
     */
    virtual bool supports_haltStatus(uint32_t i_major, uint32_t i_minor) const
    {
        return false;
    };
    /**
     * @brief evaluate if the procType/major/minor supports TPM Extended Mode
     */
    virtual bool supports_tpmExtendMode(TargetHandle_t i_target,
                                        uint32_t       i_major,
                                        uint32_t       i_minor) const
    {
        return false;
    };
};

/**
 * @brief class for the proc GetCapabilities
 */
class sbeCapabilities_rsp_proc_t : public sbeCapabilities_rsp_t
{
    static constexpr int HDR = 0; // sections[0] is hdr
    static constexpr int CAP = 1; // sections[1] is capabilities array
    static constexpr int END = 2; // sections[2] is response end data

  public:
    sbeCapabilities_rsp_proc_t()
    {
        iv_is_proc              = true;
        iv_has_commitId         = true;
        iv_has_releaseTag       = true;
        iv_has_fifoCapabilities = true;
    }
    uint32_t getCommitId() const override
    {
        return reinterpret_cast<const sbeCapabilities_hdr_t*>(iv_rsp.data())->commitId;
    }
    const char* getReleaseTag() const override
    {
        return reinterpret_cast<const sbeCapabilities_hdr_t*>(iv_rsp.data())->releaseTag;
    }
    bool supports_haltStatus(uint32_t i_major, uint32_t i_minor) const override
    {
        // SBE only supported accurate Hostboot requested halt reporting to FSP
        // as of version 1.4 or later.
        return ( (i_major == 1 && i_minor >= 4) || (i_major > 1) );
    }
    bool supports_tpmExtendMode(TargetHandle_t i_target,
                                uint32_t       i_major,
                                uint32_t       i_minor) const override
    {
        ATTR_PROC_MASTER_TYPE_type l_procMasterType =
                                     i_target->getAttr<ATTR_PROC_MASTER_TYPE>();

        // Only interrogate the boot processor's SBE to determine if the current
        // node is capable of having the boot processor's SBE perform the SMP
        // stitching and TPM measurement extending.
        // SBE support for TPM Extend Mode as of version 2.1 or later.
        return (    (l_procMasterType == PROC_MASTER_TYPE_ACTING_MASTER)
                 && ( (i_major == 2 && i_minor >= 1) || (i_major > 2) )
               );
    }
    uint16_t getCapSize() const override
    {
        return iv_sections[CAP];
    }
    const sbeCapability_t* getCapPtr() const override
    {
        return reinterpret_cast<const sbeCapability_t*>
                                            (sbeFifo_rsp_t::getSectionPtr(CAP));
    }
    const SbeFifo::fifoStandardResponse* getEndPtr() const override
    {
        return reinterpret_cast<const SbeFifo::fifoStandardResponse*>
                                            (sbeFifo_rsp_t::getSectionPtr(END));
    }
};

/**
 * @brief class for the proc GetCapabilities in the PSU path
 */
class sbeCapabilities_rsp_proc_psu_t : public sbeCapabilities_rsp_proc_t
{
  public:
    sbeCapabilities_rsp_proc_psu_t()
    {
        iv_has_fifoCapabilities = false;
    }
};

/**
 * @brief class for the Odyssey GetCapabilities
 */
class sbeCapabilities_rsp_ody_t : public sbeCapabilities_rsp_t
{
    static constexpr int HDR = 0; // sections[0] is hdr
    static constexpr int IMG = 1; // sections[1] is image info array
    static constexpr int CAP = 2; // sections[2] is capabilities array
    static constexpr int END = 3; // sections[3] is response end data

  public:
    sbeCapabilities_rsp_ody_t()
    {
        iv_is_ody               = true;
        iv_has_sbeBuildTag      = true;
        iv_has_ekbBuildTag      = true;
        iv_has_fifoCapabilities = true;
    }
    const char* getSbeBuildTag() const override
    {
        return reinterpret_cast<const sbeCapabilities_hdr_ody_t*>
                                                   (iv_rsp.data())->sbeBuildTag;
    }
    const char* getEkbBuildTag() const override
    {
        return reinterpret_cast<const sbeCapabilities_hdr_ody_t*>
                                                    (iv_rsp.data())->ekbBuildTag;
    }
    uint16_t getImgSize() const override
    {
        return iv_sections[IMG];
    }
    const sbeCapability_t* getImgPtr() const override
    {
        return reinterpret_cast<const sbeCapability_t*>
                                            (sbeFifo_rsp_t::getSectionPtr(IMG));
    }
    uint16_t getCapSize() const override
    {
        return iv_sections[CAP];
    }
    const sbeCapability_t* getCapPtr() const override
    {
        return reinterpret_cast<const sbeCapability_t*>
                                            (sbeFifo_rsp_t::getSectionPtr(CAP));
    }
    const SbeFifo::fifoStandardResponse* getEndPtr() const override
    {
        return reinterpret_cast<const SbeFifo::fifoStandardResponse*>
                                            (sbeFifo_rsp_t::getSectionPtr(END));
    }
};

 /**
 * @brief Apply the SBE capabilities to the given target.
 *
 * @param[in] i_target   Target to apply the SBE capabilities on
 * @param[in] i_rsp      The SBE capabilities themselves
 * @return    errlHndl_t Error log handle on failure
 */
void applySbeCapabilities(TargetHandle_t         i_target,
                          sbeCapabilities_rsp_t *i_rsp)
{
    uint32_t l_huid  = get_huid(i_target);
    uint32_t l_major = i_rsp->getMajor();
    uint32_t l_minor = i_rsp->getMinor();

    //-sbeVersionInfo-----------------------------------------------------------
    // Get the SBE Version from the SBE Capabilities and set the
    // attribute associated with SBE Version
    ATTR_SBE_VERSION_INFO_type l_sbeVersionInfo =
                                         TWO_UINT16_TO_UINT32(l_major, l_minor);
    i_target->setAttr<ATTR_SBE_VERSION_INFO>(l_sbeVersionInfo);
    SBE_TRACD("applySbeCapabilities: %.8X set SBE_VERSION_INFO: 0x%0.8X",
              l_huid, l_sbeVersionInfo);

    //-commitId-----------------------------------------------------------------
    if (i_rsp->has_commitId())
    {
        // Get the SBE Commit ID from the SBE Capabilities and set the
        // attribute associated with SBE Commit ID
        ATTR_SBE_COMMIT_ID_type l_sbeCommitId = i_rsp->getCommitId();
        i_target->setAttr<ATTR_SBE_COMMIT_ID>(l_sbeCommitId);
        SBE_TRACD("applySbeCapabilities: %.8x set SBE_COMMIT_ID: 0x%X",
                  l_huid, l_sbeCommitId);
    }

    //-releaseTag--------------------------------------------------------------
    if (i_rsp->has_releaseTag())
    {
        ATTR_SBE_RELEASE_TAG_type l_tagString{0};

        static_assert(SBE_RELEASE_TAG_MAX_CHARS <= ATTR_SBE_RELEASE_TAG_max_chars,
            "Copy error - size of source is greater than size of destination.");

        strncpy(l_tagString, i_rsp->getReleaseTag(), SBE_RELEASE_TAG_MAX_CHARS-1);

        i_target->setAttr<ATTR_SBE_RELEASE_TAG>(l_tagString);
        SBE_TRACD("applySbeCapabilities: %.8X set SBE_RELEASE_TAG: %s",
                  l_huid, l_tagString);
    }

    //-sbeBuildTag--------------------------------------------------------------
    if (i_rsp->has_sbeBuildTag())
    {
        ATTR_SBE_BUILD_TAG_type l_tagString{0};

        static_assert(SBE_RELEASE_TAG_MAX_CHARS <= ATTR_SBE_BUILD_TAG_max_chars,
            "Copy error - size of source is greater than size of destination.");

        strncpy(l_tagString, i_rsp->getSbeBuildTag(), SBE_RELEASE_TAG_MAX_CHARS-1);
        i_target->setAttr<ATTR_SBE_BUILD_TAG>(l_tagString);
        SBE_TRACD("applySbeCapabilities: %.8X set SBE_BUILD_TAG: %s",
                  l_huid, l_tagString);
    }

    //-ekbBuildTag--------------------------------------------------------------
    if (i_rsp->has_ekbBuildTag())
    {
        ATTR_SBE_EKB_BUILD_TAG_type l_tagString{0};

        static_assert(SBE_RELEASE_TAG_MAX_CHARS <= ATTR_SBE_EKB_BUILD_TAG_max_chars,
            "Copy error - size of source is greater than size of destination.");

        strncpy(l_tagString, i_rsp->getEkbBuildTag(), SBE_RELEASE_TAG_MAX_CHARS-1);
        i_target->setAttr<ATTR_SBE_EKB_BUILD_TAG>(l_tagString);
        SBE_TRACD("applySbeCapabilities: %.8X set SBE_EKB_BUILD_TAG: %s", l_huid, l_tagString);
    }

    //-fifoCapabilities---------------------------------------------------------
    if (i_rsp->has_fifoCapabilities())
    {
        TARGETING::ATTR_SBE_FIFO_CAPABILITIES_type l_fifo_capabilities{};
        int l_capabilities_size = i_rsp->getCapSize();
        int l_attr_size         = sizeof(ATTR_SBE_FIFO_CAPABILITIES_type);
        int l_copy_size         = std::min(l_capabilities_size, l_attr_size);

        // save capability array in ATTR_SBE_FIFO_CAPABILITIES
        // calc l_copy_size, so we dont overflow the capabilities attr type
        memcpy(l_fifo_capabilities, i_rsp->getCapPtr(), l_copy_size);
        i_target->setAttr<TARGETING::ATTR_SBE_FIFO_CAPABILITIES>(l_fifo_capabilities);
        SBE_TRACD("applySbeCapabilities: %.8X set SBE_FIFO_CAPABILITIES", l_huid);
        SBE_TRACDBIN("applySbeCapabilities: SBE capabilities array",
                     i_rsp->getCapPtr(),
                     i_rsp->getCapSize());
    }

    //-haltStatus---------------------------------------------------------------
    if (i_rsp->supports_haltStatus(l_major, l_minor))
    {
        i_target->setAttr<ATTR_SBE_SUPPORTS_HALT_STATUS>(1);
        SBE_TRACD("applySbeCapabilities: %.8X set SBE_SUPPORTS_HALT_STATUS: 1", l_huid);
    }

    //-tpmExtendMode------------------------------------------------------------
    if (i_rsp->supports_tpmExtendMode(i_target, l_major, l_minor))
    {
        #ifndef __HOSTBOOT_RUNTIME
            TargetHandle_t l_nodeTarget = UTIL::getCurrentNodeTarget();
        #else
            TargetHandle_t l_nodeTarget = UTIL::assertGetMasterNodeTarget();
        #endif
            l_nodeTarget->setAttr<ATTR_SBE_HANDLES_SMP_TPM_EXTEND>(1);
            SBE_TRACD("applySbeCapabilities: %.8X set SBE_HANDLES_SMP_TPM_EXTEND: 1", l_huid);
    }
}

/**
 * getPsuSbeCapabilities
 */
errlHndl_t getPsuSbeCapabilities(TargetHandle_t i_target)
{
    errlHndl_t l_errl(nullptr);

    SBE_TRACD( ENTER_MRK "getPsuSbeCapabilities");

    // allocate the local response buffer
    std::vector<uint16_t> sections = {
                 sizeof(sbeCapabilities_hdr_t),                      // hdr
                 sizeof(sbeCapability_t) * POZ_SBE_MAX_CAPABILITIES, // capabilities
                 sizeof(SbeFifo::fifoStandardResponse)};             // end response
    sbeCapabilities_rsp_proc_psu_t l_rsp;
    l_rsp.init(sections);

    // Cache the SBE Capabilities' size for future uses
    size_t l_sbeCapabilitiesSize = l_rsp.getBufSize();

    auto l_alignedMemHandle = sbeMalloc(l_sbeCapabilitiesSize);

    // Clear buffer up to the size of the capabilities
    memset(l_alignedMemHandle.dataPtr, 0, l_sbeCapabilitiesSize);

    // Create a PSU request message and initialize it
    SbePsu::psuCommand l_psuCommand(
                SbePsu::SBE_REQUIRE_RESPONSE |
                SbePsu::SBE_REQUIRE_ACK,                 //control flags
                SbePsu::SBE_PSU_GENERIC_MESSAGE,         //command class
                SbePsu::SBE_PSU_MSG_GET_CAPABILITIES);   //command
    l_psuCommand.cd7_getSbeCapabilities_CapabilitiesSize =
                ALIGN_X(l_sbeCapabilitiesSize,
                        SbePsu::SBE_ALIGNMENT_SIZE_IN_BYTES);
    l_psuCommand.cd7_getSbeCapabilities_CapabilitiesAddr =
                l_alignedMemHandle.physAddr;

    // Create a PSU response message
    SbePsu::psuResponse l_psuResponse;

    bool command_unsupported = false;

    // Make the call to perform the PSU Chip Operation
    l_errl = SbePsu::getTheInstance().performPsuChipOp(
                    i_target,
                    &l_psuCommand,
                    &l_psuResponse,
                    SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                    SbePsu::SBE_GET_CAPABILITIES_REQ_USED_REGS,
                    SbePsu::SBE_GET_CAPABILITIES_RSP_USED_REGS,
                    SbePsu::COMMAND_SUPPORT_OPTIONAL,
                    &command_unsupported);

    // Before continuing, make sure this request is honored

    if (command_unsupported)
    { // Traces have already been logged
        goto ERROR_EXIT;
    }

    if (l_errl)
    {
        SBE_TRACF("getPsuSbeCapabilities: "
                  "Call to performPsuChipOp failed, error returned");

        SBE_TRACDBIN("getPsuSbeCapabilities: capabilities data",
                     l_alignedMemHandle.dataPtr,
                     l_sbeCapabilitiesSize);
        goto ERROR_EXIT;
    }

    // Sanity check - are HW and HB communications in sync?
    //  *this does a double-check of the response buffer using l_psuResponse,
    //    which ensures our local variable is correctly pointing at the response data
    if ((SbePsu::SBE_PSU_GENERIC_MESSAGE      != l_psuResponse.sbe_commandClass) ||
        (SbePsu::SBE_PSU_MSG_GET_CAPABILITIES != l_psuResponse.sbe_command))
    {
        SBE_TRACF("Call to performPsuChipOp returned an unexpected "
                  "message type; "
                  "command class returned:0x%X, "
                  "expected command class:0x%X, "
                  "command returned:0x%X, "
                  "expected command:0x%X",
                  l_psuResponse.sbe_commandClass,
                  SbePsu::SBE_PSU_GENERIC_MESSAGE,
                  l_psuResponse.sbe_command,
                  SbePsu::SBE_PSU_MSG_GET_CAPABILITIES);

        /*@
         * @errortype
         * @moduleid          SBEIO_PSU
         * @reasoncode        SBEIO_RECEIVED_UNEXPECTED_MSG
         * @userdata1         Target HUID
         * @userdata2[0:15]   Requested command class
         * @userdata2[16:31]  Requested command
         * @userdata2[32:47]  Returned command class
         * @userdata2[48:63]  Returned command
         * @devdesc           Call to PSU Chip Op returned an
         *                    unexpected message type.
         */
        l_errl = new ErrlEntry(
            ERRL_SEV_INFORMATIONAL,
            SBEIO_PSU,
            SBEIO_RECEIVED_UNEXPECTED_MSG,
            get_huid(i_target),
            TWO_UINT32_TO_UINT64(
              TWO_UINT16_TO_UINT32(SbePsu::SBE_PSU_GENERIC_MESSAGE,
                                   SbePsu::SBE_PSU_MSG_GET_CAPABILITIES),
              TWO_UINT16_TO_UINT32(l_psuResponse.sbe_commandClass,
                                   l_psuResponse.sbe_command) ));

        l_errl->collectTrace(SBEIO_COMP_NAME, 256);
        goto ERROR_EXIT;
    }

    // If capabilities data returned, process it
    if (l_psuResponse.sbe_capabilities_size)
    {
        // copy SBE Capabilities to l_rsp to make it easy to pull data
        // If the returned size is greater than or equal to our response buffer,
        //  then copy the size of our response buffer
        // If the returned size is less than our response buffer
        //  then copy what was given
        int l_copy_size = std::min(
                       static_cast<size_t>(l_psuResponse.sbe_capabilities_size),
                                           l_sbeCapabilitiesSize);
        memcpy(reinterpret_cast<void*>(const_cast<uint8_t*>(l_rsp.getBufPtr())),
               l_alignedMemHandle.dataPtr,
               l_copy_size);

        applySbeCapabilities(i_target, &l_rsp);
    }

    ERROR_EXIT:

    // Free the buffer
    sbeFree(l_alignedMemHandle);

    SBE_TRACD( EXIT_MRK "getPsuSbeCapabilities");

    return l_errl;
};


#ifndef __HOSTBOOT_RUNTIME  //no FIFO at runtime
/**
 *  getFifoSbeCapabilities
 */
errlHndl_t getFifoSbeCapabilities(TargetHandle_t i_target)
{
    errlHndl_t l_errl(nullptr);
    uint32_t   l_huid = get_huid(i_target);

    SBE_TRACD( ENTER_MRK "getFifoSbeCapabilities: 0x%08X target", l_huid);

    SbeFifo::fifoGetCapabilitiesRequest  l_fifoRequest{};
    sbeCapabilities_rsp_t               *l_rsp{nullptr};
    const SbeFifo::fifoStandardResponse *l_fifoResponseEnd{nullptr};

    uint16_t l_num_images{};         // max number of images in response buffer
    uint16_t l_num_capabilities{};   // max number of capabilities in response buffer
    uint16_t l_capabilities_size{};  // max bytes of capabilities space in response buffer
    uint16_t l_images_size{};        // max bytes of image info space in response buffer

    if (i_target->getAttr<ATTR_TYPE>() == TYPE_OCMB_CHIP)
    {
        l_num_images        = i_target->getAttr<ATTR_SBE_NUM_IMAGES>();
        l_num_capabilities  = i_target->getAttr<ATTR_SBE_NUM_CAPABILITIES>();
        l_images_size       = sizeof(sbeImageInfo_t)  * l_num_images;
        l_capabilities_size = sizeof(sbeCapability_t) * l_num_capabilities;
        l_rsp               = new sbeCapabilities_rsp_ody_t;

        // allocate the space in the response buffer
        std::vector<uint16_t> sections = {
                         sizeof(sbeCapabilities_hdr_ody_t),      // hdr
                         l_images_size,                          // images
                         l_capabilities_size,                    // capabilities
                         sizeof(SbeFifo::fifoStandardResponse)}; // end response
        l_rsp->init(sections);

        SBE_TRACD("getFifoSbeCapabilities: ocmb:0x%08X num_img:%d num_cap:%d",
                   l_huid, l_num_images, l_num_capabilities);
    }
    else
    {
        l_fifoRequest.command = SbeFifo::SBE_FIFO_CMD_GET_CAPABILITIES_2;
        l_num_capabilities    = SBEIO::SBE_MAX_CAPABILITIES_2;
        l_capabilities_size   = sizeof(sbeCapability_t) * l_num_capabilities;
        l_rsp                 = new sbeCapabilities_rsp_proc_t;

        // allocate the space in the response buffer
        std::vector<uint16_t> sections = {
                         sizeof(sbeCapabilities_hdr_t),          // hdr
                         l_capabilities_size,                    // capabilities
                         sizeof(SbeFifo::fifoStandardResponse)}; // end response
        l_rsp->init(sections);

        SBE_TRACD("getFifoSbeCapabilities: proc:0x%08X max_cap: %d",
                  l_huid, l_num_capabilities);
    }

    l_errl = sbeioInterfaceChecks(i_target,
                                  SbeFifo::SBE_FIFO_CLASS_GENERIC_MESSAGE,
                                  l_fifoRequest.command);
    if (l_errl)
    {
        SBE_TRACF( "getFifoSbeCapabilities: 0x%08X sbeioInterfaceChecks failed", l_huid);
        goto ERROR_EXIT;
    }

    l_fifoResponseEnd = l_rsp->getEndPtr();

    // Make the call to perform the FIFO Chip Operation
    l_errl = SbeFifo::getTheInstance().performFifoChipOp(
         i_target,
         reinterpret_cast<uint32_t *>(&l_fifoRequest),
         reinterpret_cast<uint32_t *>(const_cast<uint8_t*>(l_rsp->getBufPtr())),
         l_rsp->getBufSize());
    if (l_errl)
    {
        SBE_TRACF("getFifoSbeCapabilities: 0x%08X performFifoChipOp failed", l_huid);
        goto ERROR_EXIT;
    }

    // Sanity check - are HW and HB communications in sync?
    //  *this does a double-check of the response buffer using l_fifoResponseEnd,
    //    which ensures our local variable is correctly pointing at the response data
    if ((SbeFifo::FIFO_STATUS_MAGIC != l_fifoResponseEnd->status.magic)        ||
        (l_fifoRequest.commandClass != l_fifoResponseEnd->status.commandClass) ||
        (l_fifoRequest.command      != l_fifoResponseEnd->status.command))
    {
        SBE_TRACF("getFifoSbeCapabilities: 0x%08X performFifoChipOp returned unexpected "
                  "message type; "
                  "magic code returned:0x%X, "
                  "expected magic code:0x%X, "
                  "command class returned:0x%X, "
                  "expected command class:0x%X, "
                  "command returned:0x%X, "
                  "expected command:0x%X",
                  l_huid,
                  l_fifoResponseEnd->status.magic,
                  SbeFifo::FIFO_STATUS_MAGIC,
                  l_fifoResponseEnd->status.commandClass,
                  l_fifoRequest.commandClass,
                  l_fifoResponseEnd->status.command,
                  l_fifoRequest.command);

        /*@
         * @errortype
         * @moduleid          SBEIO_FIFO
         * @reasoncode        SBEIO_RECEIVED_UNEXPECTED_MSG
         * @userdata1         Target HUID
         * @userdata2[0:15]   Requested command class
         * @userdata2[16:31]  Requested command
         * @userdata2[32:47]  Returned command class
         * @userdata2[48:63]  Returned command
         * @devdesc           Call to FIFO Chip Op returned an
         *                    unexpected message type.
         */
        l_errl = new ErrlEntry(
            ERRL_SEV_INFORMATIONAL,
            SBEIO_FIFO,
            SBEIO_RECEIVED_UNEXPECTED_MSG,
            l_huid,
            TWO_UINT32_TO_UINT64(
              TWO_UINT16_TO_UINT32(l_fifoRequest.commandClass,
                                   l_fifoRequest.command),
              TWO_UINT16_TO_UINT32(l_fifoResponseEnd->status.commandClass,
                                   l_fifoResponseEnd->status.command) ));

        TRACFBIN(g_trac_sbeio,"getFifoSbeCapabilities: l_fifoResponseBuffer",
                 l_rsp->getBufPtr(),
                 l_rsp->getBufSize());
        TRACFBIN(g_trac_sbeio,"getFifoSbeCapabilities: capabilities",
                 l_rsp->getCapPtr(),
                 l_rsp->getCapSize());
        TRACFBIN(g_trac_sbeio,"getFifoSbeCapabilities: l_fifoResponseEnd",
                 l_rsp->getEndPtr(),
                 sizeof(SbeFifo::fifoStandardResponse));

        l_errl->collectTrace(SBEIO_COMP_NAME, 256);
        goto ERROR_EXIT;
    }

    applySbeCapabilities(i_target, l_rsp);

    ERROR_EXIT:

    if (l_rsp) {delete l_rsp;};

    SBE_TRACD(EXIT_MRK "getFifoSbeCapabilities: 0x%08X", l_huid);

    return l_errl;
};

#endif //#ifdef __HOSTBOOT_RUNTIME

} //end namespace SBEIO
