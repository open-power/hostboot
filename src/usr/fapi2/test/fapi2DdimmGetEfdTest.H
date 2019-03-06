/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2DdimmGetEfdTest.H $                   */
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

#ifndef __FAPI2_DDIMM_GET_EFD_TEST_H
#define __FAPI2_DDIMM_GET_EFD_TEST_H

#include <cxxtest/TestSuite.H>
#include <ddimm_get_efd.H>

//******************************************************************************
// class fapi2DdimmGetEfdTest
//
// @brief This tests the HWP call ddimm_get_efd/ddr4_get_efd
//
//******************************************************************************
class fapi2DdimmGetEfdTest : public CxxTest::TestSuite
{
public:

//******************************************************************************
//                                 Public API
//******************************************************************************

//******************************************************************************
// fapi2DdimmGetEfdTest ctor
//******************************************************************************
fapi2DdimmGetEfdTest();

//******************************************************************************
// testDdimmGetEfdHwpCall
//
// @brief A wrapper around the actual test procedures.
//
//******************************************************************************
void testDdimmGetEfdHwpCall();

private:

//******************************************************************************
// Private Test Cases
//******************************************************************************

//******************************************************************************
// sanityCheckTest
//
// @brief The setup creates a perfect scenario to get a match from the get go.
//        If this fails, then setup is broken/corrupt, design has changed, etc.
//        Either way, no point in continuing until fixed.
//
// @return true if a match was found (which signifies that the test suite has
//         been initialized correctly), false if no match found (which
//         signifies that the test suite has NOT been initialized correctly)
//
//******************************************************************************
bool sanityCheckTest();

//******************************************************************************
// sizeMisMatchTest
//
// @brief Do negative testing on the sizes of the different elements - SPD
//        buffer, EFD memory space size, etc.
//
//******************************************************************************
void sizeMisMatchTest();

//******************************************************************************
// dmbDataTest
//
// @brief Do negative testing on the DMB manufacturer ID and the DMB revision.
//        Test for incorrect values.
//
//******************************************************************************
void dmbDataTest();

//******************************************************************************
// vpdInfoInputTest
//
// @brief Do negative testing on the frequency and master rank data passed in
//        via the VPDInfo struct. Test for incorrect values.
//
//******************************************************************************
void vpdInfoInputTest();

//******************************************************************************
// findMatchTest
//
// @brief Do positive testing on finding/not finding a match for given
//        frequency and rank.
//
//******************************************************************************
void findMatchTest();



//******************************************************************************
//
// Private utilities to facilitate the testing.  These utilities help
// to manipulate buffers for easy testing.
//
//******************************************************************************

/*
 * @brief Initialize the SPD buffer to a good state - one that has no issues
 *        finding an EFD to match the criteria in the VPDInfo struct.
 */
void initializeSpdBuffer();

/*
 * @brief Create the buffer for the SPD with given parameters.
 *
 * @param[out] o_spdBufferPtr, pointer to a newly created SPD buffer
 * @param[in]  i_spdBufferSize, size to make the SPD buffer
 */
void createSpdBuffer(      uint8_t* &o_spdBufferPtr,
                     const size_t    i_spdBufferSize);

/*
 * @brief Set the DDIMM type of SPD buffer at the proper location
 *        within the SPD buffer.
 *
 * @param[in] i_spdDdimmType, DDIMM type to set within the SPD buffe
 */
void setSpdDdimmType(const uint8_t i_spdDdimmType);

/*
 * @brief Set the EFD memory space location at the proper location
 *        within the SPD buffer.
 *
 * @param[in] i_efdMemorySpaceLocation, the EFD memory space location
 */
void setEfdMemorySpaceLocation(const uint64_t i_efdMemorySpaceLocation);

/*
 * @brief Set the EFD memory space size at the proper location
 *        within the SPD buffer.
 *
 * @param[in] i_efdMemorySpaceSize, the EFD memory space size
 */
void setEfdMemorySpaceSize(const uint8_t   i_efdMemorySpaceSize);

/*
 * @brief Set the number of EFDs, for this buffer, at the proper location
 *        within the SPD buffer.
 *
 * @param[in] i_efdCount, the number of EFDs
 */
void setEfdCount(const uint16_t i_efdCount);

/*
 * @brief Set the DMB manufacturer ID at the proper location
 *        within the SPD buffer.
 *
 * @param[in] i_spdDmbMfgId, the DMB manufacturer ID
 */
void setSpdDmbMfgId(const uint16_t i_spdDmbMfgId);

/*
 * @brief Set the DMB revision at the proper location within the SPD buffer.
 *
 * @param[in]  i_spdDmbMfgId, the DMB revision
 */
void setSpdDmbRevision(const uint8_t i_spdDmbRevision);

/*
 * @brief Set individual EFD data block ending offset within the EFD meta data
 *
 * @param[in] i_efdMetaDataN, the individual EFD meta data to modify, 0 based
 * @param[in] i_efdDataBlockEnd, the corresponding EFD data block end
 *                                for the given EFD meta data
 */
void setEfdMetaDataNEfdDataBlockEnd(const size_t  i_efdMetaDataN,
                                    const uint8_t i_efdDataBlockEnd);
/*
 * @brief Set all the EFD data block sizes within the EFD meta datas
 *
 * @param[in] i_efdDataBlockSize, size of the EFD data block
 */
void setAllEfdMetaDatasEfdDataBlockSize(const uint8_t i_efdDataBlockSize);

/*
 * @brief Set an individual EFD meta data's extended function type
 *
 * @param[in] i_efdMetaDataN, the individual EFD meta data to modify, 0 based
 * @param[in] i_extendedFunctionType, the extended function type value
 */
void setEfdMetaDataExtendedFunctionType(const size_t  i_efdMetaDataN,
                                        const uint8_t i_extendedFunctionType);

 /*
 * @brief Set all the EFD meta data's extended function type
 *
 * @param[in] i_extendedFunctionType, the extended function type value
 */
void setAllEfdMetaDatasExtendedFunctionType(
                                          const uint8_t i_extendedFunctionType);
/*
 * @brief Set an individual EFD meta data's implemented state
 *
 * @param[in] i_efdMetaDataN, the individual EFD meta data to modify, 0 based
 * @param[in] i_isImplemented, state of the EFD meta data to be set to
 */
void setEfdMetaDataNisImplemented(const size_t i_efdMetaDataN,
                                  const bool   i_isImplemented);

/*
 * @brief Set all the EFD meta data's implemented state
 *
 * @param[in] i_isImplemented, state of the EFD meta data to be set to
 */
void setAllEfdMetaDatasIsImplemented(const bool i_isImplemented);

 /*
 * @brief Set an individual EFD data block's frequency
 *
 * @param[in] i_frequency, the frequency, in numeric form
 */
uint16_t convertFrequency(const uint16_t i_frequency);

 /*
 * @brief Set an individual EFD data block's frequency
 *
 * @param[in] i_efdDataBlockN, the individual EFD data block to modify, 0 based
 * @param[in] i_frequency, the frequency, in numeric form, to set the
 *            individual EFD data block to
 */
void setEfdDataBlockNFreq(const size_t   i_efdDataBlockN,
                          const uint16_t i_frequency);

 /*
 * @brief Set all the EFD data block's frequency
 *
 * @param[in] i_frequency, the frequency, in numeric form, to set all EFD
 *            data blocks to
 */
void setAllEfdDataBlocksFreq(const uint16_t i_frequency);

 /*
 * @brief Append a frequency to an individual EFD data block
 *
 * @param[in] i_efdDataBlockN, the individual EFD data block to modify, 0 based
 * @param[in] i_frequency, the frequency, in numeric form, to append
 */
void appendToEfdDataBlockNFreq(const size_t   i_efdDataBlockN,
                               const uint16_t i_frequency);

 /*
 * @brief Append a frequency to all EFD data blocks
 *
 * @param[in] i_frequency, the frequency, in numeric form, to append
 */
void appendToAllEfdDataBlocksFreq(const uint16_t i_frequency);

/*
 * @brief Map master rank to bit mask.
 *
 * @param[in]  i_rank, the master rank, in numeric form
 */
uint8_t convertRank(const uint8_t i_rank);

/*
 * @brief Set an individual EFD data block's master rank
 *
 * @param[in] i_efdDataBlockN, the individual EFD data block to modify, 0 based
 * @param[in] i_rank, the master rank, in numeric form, to set the individual
 *            EFD data block to
 */
void setEfdDataBlockNRank(const size_t  i_efdDataBlockN,
                          const uint8_t i_rank);

 /*
 * @brief Set all the EFD data block's master rank
 *
 * @param[in] i_rank, the master rank, in numeric form, to set all EFD
 *            data blocks to
 *
 */
void setAllEfdDataBlocksRank(const uint8_t i_rank);

/*
 * @brief Create the buffer for the EFD with given parameters.
 *
 * @param[out] o_efdBufferPtr, pointer to a newly created EFD buffer
 * @param[in]  i_efdBufferSize, size to make the EFD buffer
 */
void createEfdBuffer(      uint8_t* &o_efdBufferPtr,
                     const size_t    i_efdBufferSize);

/*
 * @brief Initialize a VPDInfo struct to a known state
 *
 * @param[out] o_vpdInfo, VPDInfo struct to initialize
 */
void initializeVpdInfo(fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>& o_vpdInfo);

/*
 * @brief Configure an EFD data block to given data
 *
 * @param[in]  i_efdDataBlockN, the individual EFD data block to modify, 0 based
 * @param[in]  i_frequency, the frequency, in numeric form,
 *             to set EFD data block to
 * @param[in]  i_rank, the master rank, in numeric form,
 *             to set EFD data block to
 * @param[in]  i_beginTag, tag to use at the beginning of the EFD data block
 * @param[in]  i_endTag, tag to use at the end of the EFD data block
 */
void configureEfdDataBlockN(const size_t   i_efdDataBlockN,
                            const uint16_t i_frequency,
                            const uint8_t  i_rank,
                            const uint8_t  i_beginTag,
                            const uint8_t  i_endTag);

/*
 * @brief Verify the EFD buffer has the expected value.  It is not enough to
 *        say we found a match.  Must confirm we retrieved the correct EFD
 *        data block.
 *
 * @param[in]  i_frequency, the frequency, in numeric form,
 *             to match in EFD data block
 * @param[in]  i_rank, the master rank, in numeric form,
 *             to match in EFD data block
 * @param[in]  i_beginTag, tag to match at the beginning of the EFD data block
 * @param[in]  i_endTag, tag to match at the end of the EFD data block
 *
 * @return true if the EFD buffer matches data given, else false if no match
 */
bool verifyEfdBuffer(const uint16_t i_frequency,
                     const uint8_t  i_rank,
                     const uint8_t  i_beginTag,
                     const uint8_t  i_endTag);

/*
 * @brief Tag an EFD data block to help identify it when found
 *        Tagging the EFD data block at specific memory places within the EFD
 *        data block, ensures that when a match is found, indeed that block
 *        is returned - the called function cannot spoof the data.  The tags
 *        ensure that the called function is returning the correct EFD data
 *        block in it's entirety.
 *
 * @param[in]  i_efdDataBlockN, the individual EFD data block to modify, 0 based
 * @param[in]  i_beginTag, tag to use at the beginning of the EFD data block
 * @param[in]  i_endTag, tag to use at the end of the EFD data block
 */
void tagEfdDataBlockN(const size_t  i_efdDataBlockN,
                      const uint8_t i_beginTag,
                      const uint8_t i_endTag);

//******************************************************************************
//
// Private data members
//
//******************************************************************************

    uint8_t* iv_efdBufferPtr;
    uint8_t* iv_spdBufferPtr;
    size_t   iv_spdBufferSize;
    uint8_t* iv_efdMetaDataPtr;
    uint8_t* iv_efdBlockDataPtr;
    uint8_t  iv_efdBlockSizeMultiplier;
    size_t   iv_efdBlockSize;
    size_t   iv_efdMemorySpaceLocation;
    size_t   iv_efdMemorySpaceSize;
    uint16_t iv_efdCount;
    uint16_t iv_spdDmbMfgId;
    uint8_t  iv_spdDmbRevision;
    uint8_t  iv_extendedFunctionType;
    uint16_t iv_frequency;
    uint8_t  iv_rank;

    TARGETING::Target * iv_ocmbChipTarget;
    fapi2::ReturnCode iv_rc;
    fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP> iv_vpdInfo;

    size_t iv_numTests;
    size_t iv_numFails;
    TARGETING::MODEL iv_attrModel;
};  // end class fapi2DdimmGetEfdTest

#endif

