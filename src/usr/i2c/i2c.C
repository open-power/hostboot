/**
 * @file i2c.C
 *
 * @brief Implementation of the i2c device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/targetservice.H>
#include <devicefw/driverif.H>
#include <i2c/i2creasoncodes.H>

#include "i2c.H"
// ----------------------------------------------
// Trace definition
trace_desc_t* g_trac_i2c = NULL;
TRAC_INIT( & g_trac_i2c, "I2C", 4096 );

namespace I2C
{

// Register the perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::I2C,
                       TARGETING::TYPE_PROC,
                       i2cPerformOp );

// TODO - This will be added back in once the bug in the registration
// code has been fixed.  Right now it will not compile with 2 registrations
// to the same function.
// Register the perform Op with the routing code for Memory Buffers.
//DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
//                       DeviceFW::I2C,
//                       TARGETING::TYPE_MEMBUF,
//                       i2cPerformOp );

// ------------------------------------------------------------------
// i2cPerformOp
// ------------------------------------------------------------------
errlHndl_t i2cPerformOp( DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         int64_t i_accessType,
                         va_list i_args )
{
    errlHndl_t err = NULL;
    uint64_t addr = va_arg( i_args, uint64_t );

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cPerformOp()" );

    // --------------------------------------------------------------
    // NOTE: There are attributes that can be read for targetted
    // devices (slaves).  But since we don't have any of those
    // targets yet, there isn't a way to test reading those
    // attributes yet.  I assume those will be added as full device
    // driver testing is started on Simics.
    // --------------------------------------------------------------
    if( i_opType == DeviceFW::READ )
    {
        err = i2cRead( i_target,
                       addr,
                       io_buffer,
                       io_buflen );
    }
    else if( i_opType == DeviceFW::WRITE )
    {
        err = i2cWrite( i_target,
                        addr,
                        io_buffer,
                        io_buflen );
    }
    else
    {
        TRACFCOMP( g_trac_i2c,
                   ERR_MRK"i2cPerformOp() - Unknown Operation Type!" );

        /*@
         * @errortype
         * @reasoncode     I2C_INVALID_OP_TYPE
         * @severity       ERRL_SEV_UNRECOVERABLE
         * @moduleid       I2C_PERFORM_OP
         * @userdata1      i_opType
         * @userdata2      addr
         * @devdesc        Invalid Operation type.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       I2C_PERFORM_OP,
                                       I2C_INVALID_OP_TYPE,
                                       i_opType,
                                       addr );

    }

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cPerformOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end i2cPerformOp

// ------------------------------------------------------------------
// i2cRead
// ------------------------------------------------------------------
errlHndl_t i2cRead ( TARGETING::Target * i_target,
                     uint64_t i_addr,
                     void * o_buffer,
                     size_t & i_size )
{
    errlHndl_t err = NULL;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cRead()" );

    do
    {
        // TODO - Functionality still needs to be added.
        err = i2cSetup( i_target,
                        i_addr,
                        i_size,
                        true,
                        true );
    } while( 0 );

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cRead()" );

    return err;
} // end i2cRead

// ------------------------------------------------------------------
// i2cWrite
// ------------------------------------------------------------------
errlHndl_t i2cWrite ( TARGETING::Target * i_target,
                      uint64_t i_addr,
                      void * i_buffer,
                      size_t & io_size )
{
    errlHndl_t err = NULL;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cWrite()" );

    do
    {
        // TODO - Functionality still needs to be added.
        err = i2cSetup( i_target,
                        i_addr,
                        io_size,
                        true,
                        false );
    } while( 0 );

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cWrite()" );

    return err;
} // end i2cWrite

// ------------------------------------------------------------------
// i2cSetup
// ------------------------------------------------------------------
errlHndl_t i2cSetup ( TARGETING::Target * i_target,
                      uint64_t i_addr,
                      size_t & i_size,
                      bool i_withStop,
                      bool i_readNotWrite )
{
    errlHndl_t err = NULL;

    TRACFCOMP( g_trac_i2c,
               ENTER_MRK"i2cSetup()" );

    do
    {
        // TODO - Functionality still needs to be added.
    } while( 0 );

    TRACFCOMP( g_trac_i2c,
               EXIT_MRK"i2cSetup()" );

    return err;
} // end i2cSetup

} // end namespace I2C
