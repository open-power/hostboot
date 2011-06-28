/**
 *  @file fapiTarget.C
 *
 *  @brief Implements the FAPI part of the Target class.
 */

#include <fapiTarget.H>

namespace fapi
{

//******************************************************************************
// Default Constructor
//******************************************************************************
Target::Target() :
    iv_type(TARGET_TYPE_NONE), iv_pHandle(NULL)
{

}

//******************************************************************************
// Constructor.
//******************************************************************************
Target::Target(const TargetType i_type,
               const void * i_pHandle) :
    iv_type(i_type), iv_pHandle(i_pHandle)
{

}

//******************************************************************************
// Copy Constructor
//******************************************************************************
Target::Target(const Target & i_right) :
    iv_type(i_right.iv_type)
{
    (void) copyHandle(i_right);
}

//******************************************************************************
// Destructor
//******************************************************************************
Target::~Target()
{
    (void) deleteHandle();
}

//******************************************************************************
// Assignment Operator
//******************************************************************************
Target & Target::operator=(const Target & i_right)
{
    // Test for self assignment
    if (this != &i_right)
    {
        iv_type = i_right.iv_type;
        (void) copyHandle(i_right);
    }
    return *this;
}

//******************************************************************************
// Equality Comparison Operator
//******************************************************************************
bool Target::operator==(const Target & i_right) const
{
    bool l_equal = false;

    if (iv_type == i_right.iv_type)
    {
        l_equal = compareHandle(i_right);
    }

    return l_equal;
}

//******************************************************************************
// Inequality Comparison Operator
//******************************************************************************
bool Target::operator!=(const Target & i_right) const
{
    // Determine inequality by calling the equality comparison operator
    return (!(*this == i_right));
}

//******************************************************************************
// Get the handle.
//******************************************************************************
void * Target::get() const
{
    return const_cast<void *>(iv_pHandle);
}

//******************************************************************************
// Set the handle.
//******************************************************************************
void Target::set(const void * i_pHandle)
{
    iv_pHandle = i_pHandle;
}

//******************************************************************************
// Get the target type
//******************************************************************************
TargetType Target::getType() const
{
    return iv_type;
}

//******************************************************************************
// Set the target type
//******************************************************************************
void Target::setType(const TargetType i_type)
{
    iv_type = i_type;
}

}
