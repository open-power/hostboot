/**
 *  @file fapiErrorInfoMem.C
 *
 *  @brief Implements the ErrorInfoRepositoryMem class
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created
 */

#include <fapiErrorInfoMem.H>
#include <fapiPlatTrace.H>

namespace fapi
{

//******************************************************************************
// ErrorInfoRepository Instance function
//******************************************************************************
ErrorInfoRepository& ErrorInfoRepository::Instance()
{
    // Use a static function variable. The ErrorInfoRepositoryMem singleton will
    // be constructed on the first call to this function.
    static ErrorInfoRepositoryMem instance;
    return instance;
}

//******************************************************************************
// ErrorInfoRepositoryMem Default Constructor
//******************************************************************************
ErrorInfoRepositoryMem::ErrorInfoRepositoryMem()
{
    // Initialize the repository with records
    init();
}

//******************************************************************************
// ErrorInfoRepositoryMem Destructor
//******************************************************************************
ErrorInfoRepositoryMem::~ErrorInfoRepositoryMem()
{
    // Does nothing
}

//******************************************************************************
// ErrorInfoRepositoryMem find function
//******************************************************************************
ReturnCode ErrorInfoRepositoryMem::find(const uint32_t i_rc,
                                        ErrorInfoRecord & o_record)
{
    // Iterate over vector of tables, until the correct one is found
    ErrorInfoRecordItr_t l_it;

    for (l_it = iv_errorInfoRecords.begin(); l_it != iv_errorInfoRecords.end();
            ++l_it)
    {
        if ((*l_it).iv_rc == i_rc)
        {
            FAPI_INF("ErrorInfoRepositoryMem: Found record, rc: 0x%x", i_rc);
            o_record = *l_it;
            break;
        }
    }

    if (l_it == iv_errorInfoRecords.end())
    {
        FAPI_ERR("ErrorInfoRepositoryMem: Not found record, rc: 0x%x", i_rc);
    }

    return FAPI_RC_SUCCESS;
}

}
