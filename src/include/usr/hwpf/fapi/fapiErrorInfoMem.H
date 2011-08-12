/**
 *  @file fapiErrorInfoMem.H
 *
 *  @brief Defines the ErrorInfoRepositoryMem class.
 *
 *  ErrorInfoRepositoryMem is a concrete Error Info repository that stores
 *  ErrorInfoRecords in heap based memory. A particular platform may choose to
 *  implement a different repository (in which case it would not compile this
 *  file)
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 */

#ifndef FAPIERRORINFOMEM_H_
#define FAPIERRORINFOMEM_H_

#include <stdint.h>
#include <fapiReturnCode.H>
#include <fapiErrorInfo.H>
#include <vector>

namespace fapi
{

/**
 * @class ErrorInfoRepositoryMem
 *
 * This class defines a concrete error information repository. ErrorInfoRecords
 * are stored in heap based memory.
 */
class ErrorInfoRepositoryMem : public ErrorInfoRepository
{
public:

    /**
     * @brief Default constructor.
     */
    ErrorInfoRepositoryMem();

    /**
     * @brief Destructor
     */
    virtual ~ErrorInfoRepositoryMem();

    /**
     * @brief Find Error Information Record for given ReturnCode value
     *
     * Implementation of pure virtual function in base ErrorInfoRepository class
     *
     * @param[in]  i_rc     The ReturnCode value. User can pass in a ReturnCode
     *                      object and it will be implicitly converted to a
     *                      uint32_t using the ReturnCode conversion operator
     * @param[out] o_record Reference to a ErrorInfoRecord. If the record is
     *                      found then it is assigned to o_record, else it is
     *                      not. User should pass an ErrorInfoRecord with a good
     *                      ReturnCode value and then look to see if the value
     *                      was changed to the ReturnCode value to figure out if
     *                      the record was found.
     *
     * @return ReturnCode. Always success.
     */
    virtual ReturnCode find(const uint32_t i_rc,
                            ErrorInfoRecord & o_record);

private:

    /**
     * @brief Initialize the repository with ErrorInfoRecords
     *
     * This function is implemented in the generated fapiErrorInfoMemInit.C file
     * (generated using data from the Error Information XML file)
     */
    void init();

    // Vector of ErrorInfoRecords
    std::vector<ErrorInfoRecord> iv_errorInfoRecords;
    typedef std::vector<ErrorInfoRecord>::iterator ErrorInfoRecordItr_t;
};

}

#endif // FAPIERRORINFOMEM_H_
