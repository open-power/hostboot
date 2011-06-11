/**
 *  @file scom.C
 *
 *  @brief Implementation of SCOM operations
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include "scom.H"

namespace SCOM
{

// Register SCom access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      DeviceFW::PROCESSOR,
                      scomPerformOp);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t scomPerformOp(DeviceFW::OperationType i_opType,
                         DeviceFW::TargetHandle_t i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_args)
{
    errlHndl_t l_err = NULL;

    //@todo - For now, just call XSCOM
    l_err = deviceOp(i_opType,
                     i_target,
                     io_buffer,
                     io_buflen,
                     DEVICE_XSCOM_ADDRESS(va_arg(i_args,uint64_t)));

    return l_err;
}

} // end namespace
