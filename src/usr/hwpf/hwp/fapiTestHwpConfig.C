//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/fapiTestHwpConfig.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file fapiTestHwpConfig.C
 *
 *  @brief Implements a Hardware Procedure that exercises the FAPI System Config
 *         Query functions.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     09/12/2011  Created.
 *
 */

#include <fapiTestHwpConfig.H>

extern "C"
{

//******************************************************************************
// hwpTestConfig
//******************************************************************************
fapi::ReturnCode hwpTestConfig(const fapi::Target & i_chip)
{
    FAPI_INF("Performing HWP: hwpTestConfig");

    // Print the ecmd string of the chip
    char l_string[fapi::MAX_ECMD_STRING_LEN] = {0};
    i_chip.toString(l_string);
    FAPI_INF("hwpInitialTest: Chip: %s", l_string);

    fapi::ReturnCode l_rc;
    std::vector<fapi::Target> l_targets;

    // Call fapiGetChildChiplets to get the child MCS chiplets
    l_rc = fapiGetChildChiplets(i_chip, fapi::TARGET_TYPE_MCS_CHIPLET,
                                l_targets);

    if (l_rc)
    {
        FAPI_ERR("hwpTestConfig: Error from fapiGetChildChiplets");
    }
    else
    {
        FAPI_INF("hwpTestConfig: %d MCS chiplets", l_targets.size());

        if (l_targets.size() == 0)
        {
            FAPI_ERR("hwpTestConfig: No MCS chiplets");
            l_rc = fapi::RC_TEST_ERROR_A;
        }
        else
        {
            // Save the first MCS target
            fapi::Target l_mcs = l_targets[0];

            // Call fapiGetAssociatedDimms to get the dimms for this MCS
            l_rc = fapiGetAssociatedDimms(l_mcs, l_targets);

            if (l_rc)
            {
                FAPI_ERR("hwpTestConfig: Error from fapiGetAssociatedDimms");
            }
            else
            {
                FAPI_INF("hwpTestConfig: %d dimms", l_targets.size());

                // Call fapiGetParentChip to get the parent of the MCS
                fapi::Target l_chip;

                l_rc = fapiGetParentChip(l_mcs, l_chip);

                if (l_rc)
                {
                    FAPI_ERR("hwpTestConfig: Error from fapiGetParentChip");
                }
                else
                {
                    // Check that the parent chip is is same as the input chip
                    if (i_chip != l_chip)
                    {
                        FAPI_ERR("hwpTestConfig: Chip mismatch");
                        l_rc = fapi::RC_TEST_ERROR_B;
                    }
                }
            }
        }
    }

    return l_rc;
}

} // extern "C"
