/**
 *  @file fapiFfdcHwpData.H
 *
 *  @brief Defines all FFDC data that can be returned by FFDC HWPs
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 *
 */

#ifndef FAPIFFDCHWPDATA_H_
#define FAPIFFDCHWPDATA_H_

namespace fapi
{

/**
 * @brief An FFDC structure contining a single uint64_t of data
 */
struct TestFfdc1
{
    uint64_t iv_data;
};

}

#endif // FAPIFFDCHWPDATA_H_

