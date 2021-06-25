/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_qme_customize.C $ */
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
//
//  @file p10_qme_customize.C
//
//  @brief Customizes QME ring section  for consumption by p10_hcode_image_build
//
//  *HWP Owner:         Austin Cui <Austin.Cui@ibm.com>
//  *HWP Backup Owner:  Mike Olsen <cmolsen@us.ibm.com>
//  *HWP Team:          Infrastructure
//  *HWP Level:         1
//  *HWP Consumed by:   HOSTBOOT, CRONUS
//
#include <common_ringId.H>
#include <p10_tor.H>
#include <p10_ringId.H>
#include <p10_qme_customize.H>

using namespace fapi2;


fapi2::ReturnCode p10_qme_customize(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
    uint8_t*      i_qmeRings,          //Input QME ring section
    CUST_RING_OP  i_custOp,
    uint8_t*      io_bufCustRings,     //Buffer for customized output QME ring section
    uint32_t&     io_bufCustRingsSize, //In: Max buf size, Out: cust ring section size
    uint32_t      i_dbgl )
{
    int rc = TOR_SUCCESS;

    TorHeader_t* torHeaderQme  = (TorHeader_t*) i_qmeRings;
    TorHeader_t* torHeaderCust = (TorHeader_t*) io_bufCustRings;

    uint32_t inputQmeRingsSize = be32toh(torHeaderQme->size);
    uint32_t maxCustRingsSize = io_bufCustRingsSize;

    RingProperties_t* ringProps = nullptr;
    ChipletData_t* chipletData;
    RingId_t numRingIds = UNDEFINED_RING_ID;
    RingId_t rpIndex;
    uint8_t  chipletId;
    void*    nextRing = NULL;
    uint32_t remBufSize;

    FAPI_IMP(">> p10_qme_customize ");

    // Take note of some key TOR header input data
    uint32_t torMagic = be32toh(torHeaderQme->magic);
    uint8_t  torVersion = torHeaderQme->version;
    uint8_t  ddLevel = torHeaderQme->ddLevel;
    ChipId_t chipId = torHeaderQme->chipId;

    //
    // Step 0: Test input parameters
    //
    FAPI_ASSERT(i_custOp < NUM_QME_CUST_OPS
                && i_qmeRings != NULL
                && io_bufCustRings != NULL,
                fapi2::QMEC_FUNC_CALL_ARGUMENT_ERROR()
                .set_TARGET(i_procTarget)
                .set_CUST_RING_OP(i_custOp)
                .set_INPUT_QME_RINGS_PTR(i_qmeRings)
                .set_CUST_QME_RINGS_BUF_PTR(io_bufCustRings),
                "ERROR: Some arguments in function call are invalid:"
                " i_custOp=0x%x, i_qmeRings=0x%016llx, io_bufCustRings=0x%016llx.\n",
                i_custOp,
                (uintptr_t)i_qmeRings,
                (uintptr_t)io_bufCustRings);

    FAPI_ASSERT(torMagic == TOR_MAGIC_QME && torVersion == TOR_VERSION,
                fapi2::QMEC_TOR_HEADER_MISMATCH()
                .set_TARGET(i_procTarget)
                .set_TOR_MAGIC_QME_IN_HEADER(torMagic)
                .set_TOR_MAGIC_QME_DEFINED(TOR_MAGIC_QME)
                .set_TOR_VERSION_IN_HEADER(torVersion)
                .set_TOR_VERSION_DEFINED(TOR_VERSION),
                "ERROR: TOR Magic or TOR Version in TOR header do not match the defined values:\n"
                " torMagic=0x%08x but TOR_MAGIC_QME=0x%08x\n"
                " torVersion=%u but TOR_VERSION=%u",
                torMagic,
                TOR_MAGIC_QME,
                torVersion,
                TOR_VERSION);

    // Check that the max customized buffer size is >= the size of the input TOR ring section
    FAPI_ASSERT(maxCustRingsSize >= inputQmeRingsSize,
                fapi2::QMEC_RINGS_OUTPUT_BUFFER_TOO_SMALL()
                .set_TARGET(i_procTarget)
                .set_CUST_QME_RINGS_BUF_SIZE(maxCustRingsSize)
                .set_INPUT_QME_RINGS_SIZE(inputQmeRingsSize)
                .set_CUST_QME_RINGS_SIZE(0xffffffff), //Still undefined
                "ERROR: Max custom QME ring buf size < Input QME rings size:"
                " maxCustRingsSize=0x%08x, inputQmeRingsSize=0x%08x",
                maxCustRingsSize,
                inputQmeRingsSize);

    //
    // Step 1: Create TOR skeleton ringSection
    // Create the complete ring skeleton, but with empty TOR ring slots (ie, no ring content).
    //

    rc = tor_skeleton_generation(io_bufCustRings,
                                 torMagic,
                                 torVersion,
                                 ddLevel,
                                 chipId,
                                 i_dbgl);

    FAPI_ASSERT(rc == TOR_SUCCESS,
                fapi2::QMEC_TOR_SKELETON_GEN_ERROR()
                .set_TARGET(i_procTarget)
                .set_API_RC(rc)
                .set_TOR_MAGIC(torMagic)
                .set_TOR_VER(torVersion)
                .set_DD_LEVEL(ddLevel)
                .set_CHIP_ID(chipId),
                "ERROR: tor_skeleton_generation() failed w/rc=0x%08x for"
                " torMagic=0x%08x, torVersion=%u, ddLevel=0x%02x and chipId=0x%02x",
                rc, torMagic, torVersion, ddLevel, chipId);

    // Get the main ring properties list and the number of RingIDs
    // (Note that we can skip the second rc check since the API only fails if wrong chipId which
    // will be caught by the first rc check)
    rc = ringid_get_ringProps(chipId,
                              &ringProps);

    FAPI_ASSERT(rc == TOR_SUCCESS,
                fapi2::QMEC_RINGID_API_ERROR()
                .set_TARGET(i_procTarget)
                .set_API_RC(rc)
                .set_TOR_MAGIC(torMagic)
                .set_TOR_VER(torVersion)
                .set_CHIPLET_TYPE(UNDEFINED_CHIPLET_TYPE)
                .set_CHIP_ID(chipId)
                .set_OCCURRENCE(1),
                "ERROR: ringid_get_ringProps() failed w/rc=0x%08x\n for",
                " torMagic=0x%08x, torVersion=%u and chipId=0x%02x",
                rc, torMagic, torVersion, chipId);

    ringid_get_num_ring_ids( chipId,
                             &numRingIds );

    // Get the meta data for the QME chiplet
    rc = ringid_get_chipletProps(chipId,
                                 torMagic,
                                 torVersion,
                                 EQ_TYPE,
                                 &chipletData);

    FAPI_ASSERT(rc == TOR_SUCCESS,
                fapi2::QMEC_RINGID_API_ERROR()
                .set_TARGET(i_procTarget)
                .set_API_RC(rc)
                .set_TOR_MAGIC(torMagic)
                .set_TOR_VER(torVersion)
                .set_CHIPLET_TYPE(EQ_TYPE)
                .set_CHIP_ID(chipId)
                .set_OCCURRENCE(2),
                "ERROR: ringid_get_chipletProps() failed w/rc=0x%08x for chipletType=EQ_TYPE,"
                " torMagic=0x%08x, torVersion=%u and chipId=0x%02x",
                rc, torMagic, torVersion, chipId);

    chipletId = chipletData->chipletBaseId + i_custOp;

    //
    // Step 2: Copy and append rings
    //

    for (rpIndex = 0; rpIndex < numRingIds; rpIndex++)
    {
        io_bufCustRingsSize = be32toh(torHeaderCust->size);
        nextRing = (void*) (io_bufCustRings + io_bufCustRingsSize);

        // nextRing is portion of io_bufCustRings buffer which is used as
        // temporary buffer to pass the ring in i_qmeRings from the
        // tor_get_single_ring() function.
        // The size of this temporary buffer is captured by remBufSize.
        FAPI_ASSERT(maxCustRingsSize >= io_bufCustRingsSize,
                    fapi2::QMEC_RINGS_OUTPUT_BUFFER_TOO_SMALL()
                    .set_TARGET(i_procTarget)
                    .set_CUST_QME_RINGS_BUF_SIZE(maxCustRingsSize)
                    .set_INPUT_QME_RINGS_SIZE(inputQmeRingsSize)
                    .set_CUST_QME_RINGS_SIZE(io_bufCustRingsSize),
                    "ERROR: QME customize rings output buffer is too small since"
                    " maxCustRingsSize=0x%08x < io_bufCustRingsSize=0x%08x.",
                    maxCustRingsSize, io_bufCustRingsSize);

        remBufSize = maxCustRingsSize - io_bufCustRingsSize;

        //
        // Extract ring
        // But skip it if it doesn't qualify for current custOp context
        //

        RingId_t  ringId = ringProps[rpIndex].ringId;
        MyBool_t  bInstRing = ringid_is_instance_ring(rpIndex);

        if ( ( bInstRing == true &&
               (i_custOp >= CUST_QME0_INSTANCE_RING && i_custOp <= CUST_QME7_INSTANCE_RING) ) ||
             ( bInstRing == false &&
               (i_custOp == CUST_QME_COMMON_RING) ) )
        {
            rc = tor_get_single_ring(i_qmeRings,
                                     ddLevel,
                                     ringId,
                                     chipletId, //Arg ignored for Common rings
                                     nextRing,
                                     remBufSize,
                                     true, //This is a customized QME ringSection
                                     i_dbgl);


            FAPI_ASSERT(rc == TOR_SUCCESS ||
                        rc == TOR_RING_IS_EMPTY ||
                        rc == TOR_INVALID_CHIPLET_TYPE ||
                        rc == TOR_HOLE_RING_ID,
                        fapi2::QMEC_TOR_GET_SINGLE_RING_ERROR()
                        .set_TARGET(i_procTarget)
                        .set_API_RC(rc)
                        .set_DD_LEVEL(ddLevel)
                        .set_RING_ID(ringId)
                        .set_CHIPLET_ID(chipletId)
                        .set_REM_BUF_SIZE(remBufSize),
                        "ERROR: tor_get_single_ring() failed w/rc=0x%08x, ddLevel=0x%02x,"
                        " ringId=0x%x, chipletId=0x%02x, remBufSize=0x%08x\n",
                        rc, ddLevel, ringId, chipletId, remBufSize);

            // If ring is empty, is a hole ring or doesnt belong to QME chiplet => go to next ring
            if( rc == TOR_RING_IS_EMPTY ||
                rc == TOR_INVALID_CHIPLET_TYPE ||
                rc == TOR_HOLE_RING_ID )
            {
                //FAPI_DBG("Skipping ringId=0x%03x for rc=0x%08x", ringId, rc);
                rc = TOR_SUCCESS;
                continue;
            }
        }
        else
        {
            continue;
        }

        //
        // Append ring to customized QME ring section.
        // Note that this API also updates the header's ring size
        //
        rc = tor_append_ring(io_bufCustRings,
                             maxCustRingsSize,
                             ringId,
                             chipletId, //Arg ignored for Common rings
                             (void*)nextRing,
                             true, //Indicate producing customized ring section
                             i_dbgl);

        FAPI_ASSERT(rc == TOR_SUCCESS,
                    fapi2::QMEC_TOR_APPEND_RING_ERROR()
                    .set_TARGET(i_procTarget)
                    .set_API_RC(rc)
                    .set_RING_ID(ringId)
                    .set_CHIPLET_ID(chipletId)
                    .set_CUST_QME_RINGS_BUF_SIZE(maxCustRingsSize),
                    "ERROR: tor_append_ring() failed w/rc=0x%08x for ringId=0x%x,"
                    " chipletId=0x%02x and maxCustRingsSize=0x%08x",
                    rc, ringId, chipletId, maxCustRingsSize);

        io_bufCustRingsSize = be32toh(torHeaderCust->size);

    }

fapi_try_exit:

    FAPI_IMP("<< p10_qme_customize ");

    return fapi2::current_err;
}
