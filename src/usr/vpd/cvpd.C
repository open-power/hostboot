/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/cvpd.C $                                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <endian.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <vfs/vfs.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/cvpdenums.H>
#include "cvpd.H"
#include "vpd.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_vpd;


// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace CVPD
{
    // ----------------------------------------------
    // Globals
    // ----------------------------------------------
    mutex_t g_mutex = MUTEX_INITIALIZER;





    /**
     * @brief This function will perform the steps required to do a read from
     *      the Hostboot CVPD data.
     *
     * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
     *       driververif.H
     *
     * @param[in] i_target - Processor Target device
     *
     * @param [in/out] io_buffer - Pointer to the data that was read from
     *       the target device.  This parameter, when set to NULL, will return
     *       the keyword size value in io_buflen.
     *
     * @param [in/out] io_buflen - Length of the buffer to be read or written
     *       to/from the target.  This value should indicate the size of the
     *       io_buffer parameter that has been allocated.  Being returned it
     *       will indicate the number of valid bytes in the buffer being
     *       returned. This parameter will contain the size of a keyword when
     *       the io_buffer parameter is passed in NULL.
     *
     * @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
     *       usrif.H
     *
     * @param [in] i_args - This is an argument list for the device driver
     *       framework.
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t cvpdRead ( DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void * io_buffer,
                          size_t & io_buflen,
                          int64_t i_accessType,
                          va_list i_args )
    {
        errlHndl_t err = NULL;
        IpVpdFacade::input_args_t args;
        args.record = ((cvpdRecord)va_arg( i_args, uint64_t ));
        args.keyword = ((cvpdKeyword)va_arg( i_args, uint64_t ));

        TRACSSCOMP( g_trac_vpd,
                    ENTER_MRK"cvpdRead()" );

        err = Singleton<CvpdFacade>::instance().read(i_target,
                                                     io_buffer,
                                                     io_buflen,
                                                     args);

        return err;
    }


    /**
     * @brief This function will perform the steps required to do a write to
     *      the Hostboot CVPD data.
     *
     * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
     *       driververif.H
     *
     * @param[in] i_target - Processor Target device
     *
     * @param [in/out] io_buffer - Pointer to the data that was read from
     *       the target device.  It will also be used to contain data to
     *       be written to the device.
     *
     * @param [in/out] io_buflen - Length of the buffer to be read or written
     *       to/from the target.  This value should indicate the size of the
     *       io_buffer parameter that has been allocated.  Being returned it
     *       will indicate the number of valid bytes in the buffer being
     *       returned.
     *
     * @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
     *       usrif.H
     *
     * @param [in] i_args - This is an argument list for the device driver
     *       framework.
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t cvpdWrite ( DeviceFW::OperationType i_opType,
                           TARGETING::Target * i_target,
                           void * io_buffer,
                           size_t & io_buflen,
                           int64_t i_accessType,
                           va_list i_args )
    {
        errlHndl_t err = NULL;
        IpVpdFacade::input_args_t args;
        args.record = ((cvpdRecord)va_arg( i_args, uint64_t ));
        args.keyword = ((cvpdKeyword)va_arg( i_args, uint64_t ));

        TRACSSCOMP( g_trac_vpd,
                    ENTER_MRK"cvpdWrite()" );


        err = Singleton<CvpdFacade>::instance().write(i_target,
                                                      io_buffer,
                                                      io_buflen,
                                                      args);

        return err;
    }

    // Register with the routing code
    DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                           DeviceFW::CVPD,
                           TARGETING::TYPE_MEMBUF,
                           cvpdRead );
    DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                           DeviceFW::CVPD,
                           TARGETING::TYPE_MEMBUF,
                           cvpdWrite );



}; // end namespace CVPD

//CVPD Class Functions
/**
 * @brief  Constructor
 */
CvpdFacade::CvpdFacade() :
IpVpdFacade(CVPD::SECTION_SIZE,
            CVPD::MAX_SECTIONS,
            CVPD::cvpdRecords,
            (sizeof(CVPD::cvpdRecords)/sizeof(CVPD::cvpdRecords[0])),
            CVPD::cvpdKeywords,
            (sizeof(CVPD::cvpdKeywords)/sizeof(CVPD::cvpdKeywords[0])),
            PNOR::CENTAUR_VPD,
            CVPD::g_mutex,
            VPD::VPD_WRITE_MEMBUF)
{
    TRACUCOMP(g_trac_vpd, "CvpdFacade::CvpdFacade> " );

}
