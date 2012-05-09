/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/devicefw/userif.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
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
/** @file driverif.C
 *  Implement the functions from userif.H.
 */

#include <devicefw/userif.H>
#include <util/singleton.H>

#include "associator.H"

namespace DeviceFW
{
    errlHndl_t deviceRead(TARGETING::Target* i_target, 
                          void* o_buffer, size_t& io_buflen,
                          AccessType i_accessType, ...)
    {
        va_list args;
        errlHndl_t errl;

        va_start(args, i_accessType);

        errl = Singleton<Associator>::instance().performOp(
                READ, i_target, o_buffer, io_buflen,
                i_accessType, args);

        va_end(args);
        return errl;
    }

    errlHndl_t deviceWrite(TARGETING::Target* i_target, 
                           void* i_buffer, size_t& io_buflen,
                           AccessType i_accessType, ...)
    {
        va_list args;
        errlHndl_t errl;

        va_start(args, i_accessType);

        errl = Singleton<Associator>::instance().performOp(
                WRITE, i_target, i_buffer, io_buflen,
                i_accessType, args);

        va_end(args);
        return errl;
    }

};
