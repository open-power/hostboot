/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utilstream.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2014              */
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

