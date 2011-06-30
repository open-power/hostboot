/**
 *  @file fapiUtil.H
 *
 *  @brief Defines utility functions that the platform code must implement.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created.
 *                          camvanng	05/31/2011	Removed fapiOutputx macros
 *                          mjjones     06/30/2011  Removed #include
 *
 */

#ifndef FAPIUTIL_H_
#define FAPIUTIL_H_

#include <stdint.h>
#include <stddef.h>


namespace fapi
{
/**
 * @brief Assert that an expression is true. Aborting the process if false.
 *
 * @note Implemented by platform code
 *
 * @param[in] i_expression If not true then process should be aborted
 */
void fapiAssert(bool i_expression);

}

#endif // FAPIUTIL_H_
