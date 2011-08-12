/**
 *  @file fapiErrorInfo.C
 *
 *  @brief Implements the Error Info structs and classes
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/05/2011  Created
 */

#include <fapiErrorInfo.H>
#include <string.h>

namespace fapi
{

//******************************************************************************
// ErrorInfoCallout Constructor
//******************************************************************************
ErrorInfoCallout::ErrorInfoCallout(const TargetType i_targetType,
                                   const uint32_t i_targetPos,
                                   const CalloutPriority i_priority)
: iv_targetType(i_targetType),
  iv_targetPos(i_targetPos),
  iv_priority(i_priority)
{

}

//******************************************************************************
// ErrorInfoFfdc Constructor
//******************************************************************************
ErrorInfoFfdc::ErrorInfoFfdc(const TargetType i_targetType,
                             const uint32_t i_targetPos,
                             const FfdcHwpToken i_ffdcHwpToken)
: iv_targetType(i_targetType),
  iv_targetPos(i_targetPos),
  iv_ffdcHwpToken(i_ffdcHwpToken)
{

}

//******************************************************************************
// ErrorInfoRecord Default Constructor
//******************************************************************************
ErrorInfoRecord::ErrorInfoRecord()
: iv_rc(FAPI_RC_SUCCESS),
  iv_pDescription(NULL)
{

}

//******************************************************************************
// ErrorInfoRecord Copy constructor
//******************************************************************************
ErrorInfoRecord::ErrorInfoRecord(const ErrorInfoRecord & i_right)
: iv_rc(i_right.iv_rc),
  iv_callouts(i_right.iv_callouts),
  iv_ffdcs(i_right.iv_ffdcs),
  iv_pDescription(NULL)
{
    // Perform deep copy of the description string
    if (i_right.iv_pDescription)
    {
        iv_pDescription = new char[strlen(i_right.iv_pDescription) + 1];
        strcpy(iv_pDescription, i_right.iv_pDescription);
    }
}

//******************************************************************************
// ErrorInfoRecord Destructor
//******************************************************************************
ErrorInfoRecord::~ErrorInfoRecord()
{
    delete [] iv_pDescription;
}

//******************************************************************************
// ErrorInfoRecord Assignment operator
//******************************************************************************
ErrorInfoRecord & ErrorInfoRecord::operator=(const ErrorInfoRecord & i_right)
{
    // Test for self assignment
    if (this != &i_right)
    {
        iv_rc = i_right.iv_rc;
        iv_callouts = i_right.iv_callouts;
        iv_ffdcs = i_right.iv_ffdcs;

        // Perform deep copy of the description string
        delete [] iv_pDescription;
        iv_pDescription = NULL;

        if (i_right.iv_pDescription)
        {
            iv_pDescription = new char[strlen(i_right.iv_pDescription) + 1];
            strcpy(iv_pDescription, i_right.iv_pDescription);
        }
    }
    return *this;
}

//******************************************************************************
// ErrorInfoRecord setDescription function
//******************************************************************************
void ErrorInfoRecord::setDescription(const char * i_pDescription)
{
    delete [] iv_pDescription;
    iv_pDescription = new char[strlen(i_pDescription) + 1];
    strcpy(iv_pDescription, i_pDescription);
}

//******************************************************************************
// ErrorInfoRecord getDescription function
//******************************************************************************
const char * ErrorInfoRecord::getDescription()
{
    return iv_pDescription;
}


//******************************************************************************
// ErrorInfoRepository Default Constructor
//******************************************************************************
ErrorInfoRepository::ErrorInfoRepository()
{
    // Does nothing
}

//******************************************************************************
// ErrorInfoRepository Destructor
//******************************************************************************
ErrorInfoRepository::~ErrorInfoRepository()
{
    // Does nothing
}

}
