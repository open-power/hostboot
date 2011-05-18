/** @file driverif.C
 *  Implement the functions from userif.H.
 */

#include <devicefw/userif.H>
#include <util/singleton.H>

#include "associator.H"

namespace DeviceFW
{
    ErrorHandle_t deviceRead(TargetHandle_t i_target, 
                             void* o_buffer, size_t& io_buflen,
                             AccessType i_accessType, ...)
    {
        va_list args;
        ErrorHandle_t errl;

        va_start(args, i_accessType);

        errl = Singleton<Associator>::instance().performOp(
                READ, i_target, o_buffer, io_buflen,
                i_accessType, args);

        va_end(args);
        return errl;
    }

    ErrorHandle_t deviceWrite(TargetHandle_t i_target, 
                              void* i_buffer, size_t& io_buflen,
                              AccessType i_accessType, ...)
    {
        va_list args;
        ErrorHandle_t errl;

        va_start(args, i_accessType);

        errl = Singleton<Associator>::instance().performOp(
                WRITE, i_target, i_buffer, io_buflen,
                i_accessType, args);

        va_end(args);
        return errl;
    }

};
