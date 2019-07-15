/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_qme_customize.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
//
//  @file p10_qme_customize.C
//
//  @brief Customizes QME ring section  for consumption by p10_hcode_image_build
//
//  *HWP Owner:         Mike Olsen <cmolsen@us.ibm.com>
//  *HWP Backup Owner:  Prem S Jha <premjha2@in.ibm.com>
//  *HWP Team:          Infrastructure
//  *HWP Level:         1
//  *HWP Consumed by:   HOSTBOOT, CRONUS
//
#include <common_ringId.H>
#include <p10_tor.H>
#include <p10_ringId.H>
#include <p10_qme_customize.H>

using namespace fapi2;

extern "C"
{

////////////////////////////////////////////////////////////////////////////////////////
///                        TOR ring section generation
////////////////////////////////////////////////////////////////////////////////////////


    fapi2::ReturnCode p10_qme_customize(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
        uint8_t* i_bufQmeRings,
        CUSTOM_RING_OP i_custOp,
        uint8_t* io_bufCustRings,
        uint32_t& io_bufCustRingsSize,
        uint32_t i_dbgl)
    {
        FAPI_IMP(">> p10_qme_customize ");

        int rc = INFRASTRUCT_RC_SUCCESS;

        TorHeader_t* torHeader = (TorHeader_t*) i_bufQmeRings;

        uint8_t ddLevel;
        uint8_t torVersion;
        uint32_t torMagic;
        uint32_t inputQmeRingsSize;

        ChipId_t chipId = UNDEFINED_CHIP_ID;
        ChipletData_t* chipletData;

        ddLevel = torHeader->ddLevel;
        torVersion = torHeader->version;
        torMagic = be32toh(torHeader->magic);
        chipId = torHeader->chipId;
        inputQmeRingsSize = be32toh(torHeader->size);

        RingId_t numRings = UNDEFINED_RING_ID; // Number of chiplet common or instance rings
        MyBool_t bInstCase = UNDEFINED_BOOLEAN; // 0:COMMON, 1:INSTANCE rings
        RingId_t ringId;
        uint8_t  chipletInstId;

        uint32_t maxCustRingsSize = io_bufCustRingsSize;

        uint8_t  iRing;
        void*    nextRing = NULL;
        uint32_t nextRingSize;

        FAPI_ASSERT(i_custOp < NUM_CUSTOMIZE_QME_ENTRIES
                    && i_bufQmeRings != NULL
                    && io_bufCustRings != NULL,
                    fapi2::QMEC_FUNC_CALL_ARGUMENT_ERROR()
                    .set_TARGET(i_procTarget)
                    .set_CUSTOM_RING_OP(i_custOp)
                    .set_INPUT_QME_RINGS_BUF_PTR(i_bufQmeRings)
                    .set_CUST_QME_RINGS_BUF_PTR(io_bufCustRings),
                    "Error: Some arguments in function call are invalid,\n"
                    " i_custOp=0x%08x, i_bufQmeRings=0x%016llx, io_bufCustRings=0x%016llx.\n",
                    i_custOp,
                    (uintptr_t) i_bufQmeRings,
                    (uintptr_t) io_bufCustRings);

        FAPI_ASSERT(torMagic == TOR_MAGIC_QME && torVersion == TOR_VERSION,
                    fapi2::QMEC_TOR_HEADER_MISMATCH()
                    .set_TARGET(i_procTarget)
                    .set_TOR_MAGIC_QME_IN_HEADER(torMagic)
                    .set_TOR_MAGIC_QME_DEFINED(TOR_MAGIC_QME)
                    .set_TOR_VERSION_IN_HEADER(torVersion)
                    .set_TOR_VERSION_DEFINED(TOR_VERSION),
                    "Error: TOR Magic or TOR Version not match in TOR header and the defined,\n"
                    " TOR Magic w/value =0x%08x in TOR header, TOR_MAGIC_QME w/value =0x%08x,\n"
                    " TOR Version w/value =0x%08x in TOR header, TOR_VERSION w/value =0x%08x.\n",
                    torMagic,
                    TOR_MAGIC_QME,
                    torVersion,
                    TOR_VERSION);

        // Make sure that the customized buffer size is greater than or
        // equal to the size in TOR header in the input QME ring buffer.
        FAPI_ASSERT(maxCustRingsSize >= inputQmeRingsSize,
                    fapi2::QMEC_RINGS_OUTPUT_BUFFER_TOO_SMALL()
                    .set_TARGET(i_procTarget)
                    .set_MAX_CUST_RINGS_BUF_SIZE(maxCustRingsSize)
                    .set_INPUT_QME_RINGS_BUF_SIZE(inputQmeRingsSize),
                    "Error: Input QME rings buffer size exceeds max customize ring buffer size,\n"
                    " maxCustRingsSize=0x%08x, inputQmeRingsSize=0x%08x.\n",
                    maxCustRingsSize,
                    inputQmeRingsSize);

        bInstCase = (i_custOp == CUSTOMIZE_QME_COMMON_RING) ? false : true;

//
// Step 1: Create skeleton
// Create the complete ring skeleton, but with empty TOR ring slots.
//
        rc = tor_skeleton_generation(io_bufCustRings,
                                     torMagic,
                                     torVersion,
                                     ddLevel,
                                     chipId,
                                     i_dbgl);

        FAPI_DBG("tor_skeleton_generation() completed w/rc=0x%08x,\n"
                 " torMagic=0x%08x and torVersion=0x%08x,\n"
                 " ddLevel=0x%08x and chipId=0x%08x.\n",
                 rc,
                 torMagic,
                 torVersion,
                 ddLevel,
                 chipId);

        FAPI_ASSERT(rc == INFRASTRUCT_RC_SUCCESS,
                    fapi2::QMEC_TOR_SKELETON_GEN_ERROR()
                    .set_TARGET(i_procTarget)
                    .set_API_RC(rc)
                    .set_TOR_MAGIC(torMagic)
                    .set_TOR_VER(torVersion)
                    .set_DD_LEVEL(ddLevel)
                    .set_CHIP_ID(chipId),
                    "Error: tor_skeleton_generation() failed w/rc=0x%08x,\n"
                    " torMagic=0x%08x and torVersion=0x%08x,\n"
                    " ddLevel=0x%08x and chipId=0x%08x.\n",
                    rc,
                    torMagic,
                    torVersion,
                    ddLevel,
                    chipId);

//
// Step 2: Add ring content
// Main TOR ringSection create loop
// - Generate RS4 container for each ring, attaching it to end of ringSection and update
//   the ring's TOR offset slot
//

// Get all the meta data for this chiplet and its rings
        rc = ringid_get_chipletProps(chipId,
                                     torMagic,
                                     torVersion,
                                     EQ_TYPE,
                                     &chipletData);

        FAPI_DBG("ringid_get_chipletProps() completed w/rc=0x%08x,\n"
                 " chipId=0x%08x, torMagic=0x%08x, torVersion=0x%08x.\n",
                 rc,
                 chipId,
                 torMagic,
                 torVersion);

        FAPI_ASSERT(rc == INFRASTRUCT_RC_SUCCESS,
                    fapi2::QMEC_RINGID_GET_CHIPLETPROPS_ERROR()
                    .set_TARGET(i_procTarget)
                    .set_API_RC(rc)
                    .set_TOR_MAGIC(torMagic)
                    .set_TOR_VER(torVersion),
                    "Error: ringid_get_chipletProps() failed w/rc=0x%08x,\n"
                    " ddLevel=0x%08x and torVersion=0x%08x.\n",
                    rc,
                    torMagic,
                    torVersion);

        chipletInstId = chipletData->chipletBaseId + i_custOp;

        numRings = bInstCase ?
                   chipletData->numInstanceRings :
                   chipletData->numCommonRings;

        FAPI_DBG("p10_qme_customize(): chipletInstId = 0x%08x, numRings = 0x%08x,\n"
                 " numInstanceRings = 0x%08x, numCommonRings = 0x%08x.\n",
                 chipletInstId,
                 numRings,
                 chipletData->numInstanceRings,
                 chipletData->numCommonRings);

        // Loop through all rings, get ring data for each ring and
        // append it to cust ring section.
        for (iRing = 0; iRing < numRings; iRing++)
        {
            // Extract ringId from the TOR ring index, iRing.
            rc = ringidGetRingId2(chipId,
                                  torMagic,
                                  EQ_TYPE,
                                  iRing,
                                  bInstCase,
                                  ringId,
                                  false);

            FAPI_DBG("ringidGetRingId2() completed w/rc=0x%08x,\n"
                     " torMagic=0x%08x,iRing=0x%08x,\n"
                     " bInstCase=%d, ringId=0x%08x.\n",
                     rc,
                     torMagic,
                     iRing,
                     bInstCase,
                     ringId);

            FAPI_ASSERT(rc == INFRASTRUCT_RC_SUCCESS,
                        fapi2::QMEC_RINGID_GET_RINGID2_ERROR()
                        .set_TARGET(i_procTarget)
                        .set_API_RC(rc)
                        .set_TOR_MAGIC(torMagic)
                        .set_RING_INST_ID(iRing)
                        .set_INST_CASE(bInstCase)
                        .set_RING_ID(ringId),
                        "Error: ringidGetRingId2() failed w/rc=0x%08x,\n"
                        " torMagic=0x%08x,iRing=0x%08x,\n"
                        " bInstCase=%d, ringId=0x%08x.\n",
                        rc,
                        torMagic,
                        iRing,
                        bInstCase,
                        ringId);

            io_bufCustRingsSize = be32toh(((TorHeader_t*) io_bufCustRings)->size);
            nextRing = (void*) (io_bufCustRings + io_bufCustRingsSize);
            nextRingSize = maxCustRingsSize - io_bufCustRingsSize;

            // nextRing is portion of io_bufCustRings buffer, which is used as
            // temporary memory to pass the ring in i_bufQmeRings from the
            // tor_get_single_ring() function.
            // The size of nextRing is the size of temporary memory.
            FAPI_ASSERT(maxCustRingsSize > io_bufCustRingsSize,
                        fapi2::QMEC_RINGS_OUTPUT_BUFFER_TOO_SMALL()
                        .set_MAX_CUST_RINGS_BUF_SIZE(maxCustRingsSize)
                        .set_CUST_QME_RINGS_BUF_SIZE(io_bufCustRingsSize),
                        "Error: QME rings output buffer is not large enough to use part of it for rs4Ring,\n"
                        " maxCustRingsSize=0x%08x, io_bufCustRingsSize=0x%08x.\n",
                        maxCustRingsSize,
                        io_bufCustRingsSize);

            // Extract ring data using the ringId.
            rc = tor_get_single_ring(i_bufQmeRings,
                                     ddLevel,
                                     ringId,
                                     chipletInstId, //This argument ignored for Common rings.
                                     nextRing,
                                     nextRingSize,
                                     i_dbgl);

            FAPI_DBG("tor_get_single_ring() completed w/rc=0x%08x,\n"
                     " ddLevel=0x%08x, ringId=0x%08x,\n"
                     " chipletInstId=0x%08x, nextRs4RingSize=%d.\n",
                     rc,
                     ddLevel,
                     ringId,
                     chipletInstId,
                     nextRingSize);

            FAPI_ASSERT(rc == INFRASTRUCT_RC_SUCCESS ||
                        rc == TOR_RING_IS_EMPTY,
                        fapi2::QMEC_TOR_GET_SINGLE_RING_ERROR()
                        .set_TARGET(i_procTarget)
                        .set_API_RC(rc)
                        .set_DD_LEVEL(ddLevel)
                        .set_RING_ID(ringId)
                        .set_CHIPLET_INST_ID(chipletInstId)
                        .set_NEXT_RS4RING_BUF_SIZE(nextRingSize),
                        "Error: tor_get_single_ring() failed w/rc=0x%08x,\n"
                        " ddLevel=0x%08x, ringId=0x%08x,\n"
                        " chipletInstId=0x%08x, nextRs4RingSize=%d.\n",
                        rc,
                        ddLevel,
                        ringId,
                        chipletInstId,
                        nextRingSize);

            // if ring is empty, loop through and check next ring.
            if(rc == TOR_RING_IS_EMPTY)
            {
                rc = INFRASTRUCT_RC_SUCCESS;
                continue;
            }

            // Append ring to ring section.
            // Note that this API also updates the header's ring size
            rc = tor_append_ring(io_bufCustRings,
                                 io_bufCustRingsSize,
                                 ringId,
                                 chipletInstId,
                                 (void*) nextRing,
                                 i_dbgl);

            FAPI_DBG("tor_append_ring() completed w/rc=0x%08x,\n"
                     " io_bufCustRingsSize=0x%08x, ringId=0x%x.\n",
                     rc,
                     io_bufCustRingsSize,
                     ringId);

            FAPI_ASSERT(rc == INFRASTRUCT_RC_SUCCESS,
                        fapi2::QMEC_TOR_APPEND_RING_ERROR()
                        .set_TARGET(i_procTarget)
                        .set_API_RC(rc)
                        .set_CUST_RINGS_BUF_SIZE(io_bufCustRingsSize)
                        .set_RING_ID(ringId),
                        "Error: tor_append_ring() failed w/rc=0x%08x,\n"
                        " io_bufCustRingsSize=0x%08x, ringId=0x%x.\n",
                        rc,
                        io_bufCustRingsSize,
                        ringId);
        }

        FAPI_DBG("p10_qme_customize(): io_bufCustRingsSize = 0x%08x\n",
                 io_bufCustRingsSize);

        FAPI_IMP("<< p10_qme_customize ");

    fapi_try_exit:
        return fapi2::current_err;
    }

}
