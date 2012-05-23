/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/util/utilstream.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2003-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 * @file utilstream.C
 *
 * @brief       Stream manipulation
 *
 * Used for creating and manipulating streams
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <util/utilstream.H>


/*****************************************************************************/
// Default Constructor
/*****************************************************************************/
UtilStream::UtilStream()
: iv_eof( false ), iv_lastError( 0 )
{
}


/*****************************************************************************/
// Assignment operator
/*****************************************************************************/
UtilStream & UtilStream::operator= ( const UtilStream & i_right )
{
    if ( &i_right != this )
    {
        delete iv_lastError;

        iv_eof = false;
        iv_lastError = 0;

    }

    return *this;
}


/*****************************************************************************/
// Default destructor
/*****************************************************************************/
UtilStream::~UtilStream()
{
    delete iv_lastError;
}


/*****************************************************************************/
// Set the last Error Log
/*****************************************************************************/
void UtilStream::setLastError( errlHndl_t i_error )
{
    delete iv_lastError;
    iv_lastError = i_error;
}

