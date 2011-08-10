/**
 *  @file pnordd.C
 *
 *  @brief Implementation of the PNOR Device Driver
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <sys/mmio.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/targetservice.H>
#include <errl/errlmanager.H>
#include "pnordd.H"
#include <pnor/pnorif.H>
#include <pnor/pnor_reasoncodes.H>

#define FAKE_PNOR_START 5*1024*1024
#define FAKE_PNOR_END 8*1024*1024
#define FAKE_PNOR_SIZE 3*1024*1024

extern trace_desc_t* g_trac_pnor;

namespace PNOR
{



/**
 * @brief Performs an PNOR Read Operation
 * This function performs a PNOR Read operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        PNOR target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the PNOR address and chip select
 * @return  errlHndl_t
 */
errlHndl_t ddRead(DeviceFW::OperationType i_opType,
                  TARGETING::Target* i_target,
                  void* io_buffer,
                  size_t& io_buflen,
                  int64_t i_accessType,
                  va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args,uint64_t);

    do{
        l_err = Singleton<PnorDD>::instance().read(io_buffer,
                                                   io_buflen,
                                                   l_addr);
        if(l_err)
        {
            break;
        }
 
    }while(0);

    return l_err;
}

/**
 * @brief Performs an PNOR Write Operation
 * This function performs a PNOR Write operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        PNOR target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the PNOR address and chip select
 * @return  errlHndl_t
 */
errlHndl_t ddWrite(DeviceFW::OperationType i_opType,
                  TARGETING::Target* i_target,
                  void* io_buffer,
                  size_t& io_buflen,
                  int64_t i_accessType,
                  va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args,uint64_t);

    do{
        l_err = Singleton<PnorDD>::instance().write(io_buffer,
                                                    io_buflen,
                                                    l_addr);
        if(l_err)
        {
            break;
        }
 
    }while(0);

    return l_err;
}

// Register PNORDD access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PNOR,
                      TARGETING::TYPE_PROC,
                      ddRead);

DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::PNOR,
                      TARGETING::TYPE_PROC,
                      ddWrite);


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t setLSCAccessMode(lscMode i_mode)
{
    errlHndl_t l_err = NULL;

    do{
        l_err = Singleton<PnorDD>::instance().setAccessMode(i_mode);
        if(l_err)
        {
            break;
        }
 
    }while(0);

    return l_err;
}


/**
 * @brief Read PNOR
 */
errlHndl_t PnorDD::read(void* o_buffer,
                        size_t& io_buflen,
                        uint64_t i_address)
{
    //TRACDCOMP(g_trac_pnor, "PnorDD::read(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;

    do{
        //mask off chip select for now, will probably break up fake PNOR into
        //multiple fake chips eventually
       uint64_t l_address = i_address & 0x00000000FFFFFFFF;

        l_err = verifyAddressRange(l_address, io_buflen);
        if(l_err)
        {
            io_buflen = 0;
            break;
        }

        //create a pointer to the offset start.
        char * srcPtr = (char *)(FAKE_PNOR_START+l_address);

        //@TODO: likely need a mutex around HW access

        //copy data from memory into the buffer.
        memcpy(o_buffer, srcPtr, io_buflen);


    }while(0);

    return l_err;
}

/**
 * @brief Write PNOR
 */
errlHndl_t PnorDD::write(void* i_buffer,
                         size_t& io_buflen,
                         uint64_t i_address)
{
    //TRACDCOMP(g_trac_pnor, "PnorDD::write(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;

    do{
        //mask off chip select for now, will probably break up fake PNOR into
        //multiple fake chips eventually
       uint64_t l_address = i_address & 0x00000000FFFFFFFF;


        l_err = verifyAddressRange(l_address, io_buflen);
        if(l_err)
        {
            io_buflen = 0;
            break;
        }

        //create a pointer to the offset start.
        char * destPtr = (char *)(FAKE_PNOR_START+l_address);

        //@TODO: likely need a mutex around HW access

        //copy data from memory into the buffer.
        memcpy(destPtr, i_buffer, io_buflen);


    }while(0);

    return l_err;
}

/**
 * @brief Set PNOR to desired mode
 */
errlHndl_t PnorDD::setAccessMode(lscMode i_mode)
{
    errlHndl_t l_err = NULL;
    TRACFCOMP(g_trac_pnor, "PnorDD::setAccessMode(0x%llx)> ", i_mode);

    do{
        //@TODO: real impelementation needed

        //Once we have a 'real' implementation, it will likely drive the need for mutexes
        //throughout the PnorDD interfaces, to avoid issues with weak consistency or a
        //read/write occuring while we're updating the mode, but
        //skipping that until it's actually needed.

        //Eventually need to actually change HW state here.
        //For now, just record the new mode.
        iv_lscMode = i_mode;


    }while(0);

    return l_err;
}


/********************
 Private/Protected Methods
 ********************/


/**
 * @brief  Constructor
 */
PnorDD::PnorDD()
: iv_lscMode(MMRD)
{
    TRACFCOMP(g_trac_pnor, "PnorDD::PnorDD()> ");

}

/**
 * @brief  Destructor
 */
PnorDD::~PnorDD()
{

    //Nothing to do for now
}

errlHndl_t PnorDD::verifyAddressRange(uint64_t i_address,
                                      size_t& i_length)
{
    errlHndl_t l_err = NULL;

    do{

        if((i_address+i_length) > FAKE_PNOR_SIZE)
        {
            TRACFCOMP( g_trac_pnor, "PnorDD::verifyAddressRange> Invalid Address Requested : i_address=%d", i_address );
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORDD_VERIFYADDRESSRANGE
             * @reasoncode   PNOR::RC_INVALID_SECTION
             * @userdata1    Requested Address
             * @userdata2    Requested Length
             * @devdesc      PnorDD::verifyAddressRange> Invalid Address requested
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_VERIFYADDRESSRANGE,
                                            PNOR::RC_INVALID_ADDRESS,
                                            TO_UINT64(i_address),
                                            TO_UINT64(i_length));
            break;
        }



    }while(0);

    return l_err;
}



}; //end PNOR namespace
