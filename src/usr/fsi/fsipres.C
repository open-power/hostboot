/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/fsipres.C $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
#include <devicefw/driverif.H>
#include <targeting/common/attributes.H>
#include <fsi/fsiif.H>
#include <fsi/fsi_reasoncodes.H>
#include <vpd/mvpdenums.H>
#include <errl/errlmanager.H>
#include <targeting/common/predicates/predicatectm.H>

extern trace_desc_t* g_trac_fsi;

namespace FSI
{

/**
 * @brief Performs a presence detect operation on a Processor Chip.
 *
 * This function does FSI presence detect and compares it to the Module
 * VPD that is present, following the pre-defined prototype for a
 * device-driver framework function.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        Presence detect target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes, always 1)
 *                              Output: Success = 1, Failure = 0
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there are no arguments.
 * @return  errlHndl_t
 */
errlHndl_t procPresenceDetect(DeviceFW::OperationType i_opType,
                              TARGETING::Target* i_target,
                              void* io_buffer,
                              size_t& io_buflen,
                              int64_t i_accessType,
                              va_list i_args)
{
    errlHndl_t l_errl = NULL;

    if (unlikely(io_buflen < sizeof(bool)))
    {
        TRACFCOMP(g_trac_fsi,
                  ERR_MRK "FSI::procPresenceDetect> Invalid data length: %d",
                  io_buflen);
        /*@
         * @errortype
         * @moduleid     FSI::MOD_FSIPRES_PROCPRESENCEDETECT
         * @reasoncode   FSI::RC_INVALID_LENGTH
         * @userdata1    Data Length
         * @devdesc      presenceDetect> Invalid data length (!= 1 bytes)
         */
        l_errl =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        FSI::MOD_FSIPRES_PROCPRESENCEDETECT,
                                        FSI::RC_INVALID_LENGTH,
                                        TO_UINT64(io_buflen));
        io_buflen = 0;
        return l_errl;
    }

    // First look for FSI presence bits
    bool fsi_present = false;

    TARGETING::Target* l_masterChip = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_masterChip);

    if ((i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) ||
        (i_target == l_masterChip))
    {
        fsi_present = true;
    }
    else
    {
        fsi_present = isSlavePresent(i_target);
    }

    // Next look for valid Module VPD by reading the PG record
    bool mvpd_present = false;
    size_t theSize = 0;
    l_errl = deviceRead( i_target,
                         NULL,
                         theSize,
                         DEVICE_MVPD_ADDRESS( MVPD::CP00,
                                              MVPD::VD ) );
    if( l_errl )
    {
        if( fsi_present )
        {
            // commit this log because we expected to have VPD
            errlCommit( l_errl,
                        FSI_COMP_ID );
        }
        else
        {
            // just delete this
            delete l_errl;
        }
    }

    if( theSize > 0 )
    {
        uint8_t theData[theSize];
        l_errl = deviceRead( i_target,
                             theData,
                             theSize,
                             DEVICE_MVPD_ADDRESS( MVPD::CP00,
                                                  MVPD::VD ) );
        if( l_errl )
        {
            if( fsi_present )
            {
                // commit this log because we expected to have VPD
                errlCommit( l_errl,
                            FSI_COMP_ID );
            }
            else
            {
                // just delete this
                delete l_errl;
            }
        }
        else
        {
            mvpd_present = true;
        }
    }

    // Finally compare the 2 methods
    if( fsi_present != mvpd_present )
    {
        TRACFCOMP(g_trac_fsi,
                  ERR_MRK "FSI::procPresenceDetect> FSI (=%d) and MVPD (=%d) do not agree for %.8X",
                  fsi_present, mvpd_present, TARGETING::get_huid(i_target));
        /*@
         * @errortype
         * @moduleid     FSI::MOD_FSIPRES_PROCPRESENCEDETECT
         * @reasoncode   FSI::RC_FSI_MVPD_MISMATCH
         * @userdata1    HUID of processor
         * @userdata2[0:31]    FSI Presence
         * @userdata2[32:63]   MVPD Presence
         * @devdesc      presenceDetect> FSI and MVPD do not agree
         */
        l_errl =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        FSI::MOD_FSIPRES_PROCPRESENCEDETECT,
                                        FSI::RC_FSI_MVPD_MISMATCH,
                                        TWO_UINT32_TO_UINT64(
                                            fsi_present,
                                            mvpd_present));

        //@todo-callout the processor
        //l_errl->addHwCallout( i_target, LOW, NO_DECONFIG, NO_GARD );

        // commit this log and move on
        errlCommit( l_errl,
                    FSI_COMP_ID );
    }

    
    bool present = fsi_present & mvpd_present;
    memcpy(io_buffer, &present, sizeof(present));
    io_buflen = sizeof(present);

    return NULL;
}

/**
 * @brief Performs a presence detect operation on a Membuf Chip.
 *
 * This function does FSI presence detect, following the pre-defined prototype
 * for a device-driver framework function.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        Presence detect target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes, always 1)
 *                              Output: Success = 1, Failure = 0
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there are no arguments.
 * @return  errlHndl_t
 */
errlHndl_t membPresenceDetect(DeviceFW::OperationType i_opType,
                              TARGETING::Target* i_target,
                              void* io_buffer,
                              size_t& io_buflen,
                              int64_t i_accessType,
                              va_list i_args)
{
    errlHndl_t l_errl = NULL;

    if (unlikely(io_buflen < sizeof(bool)))
    {
        TRACFCOMP(g_trac_fsi,
                  ERR_MRK "FSI::membPresenceDetect> Invalid data length: %d",
                  io_buflen);
        /*@
         * @errortype
         * @moduleid     FSI::MOD_FSIPRES_MEMBPRESENCEDETECT
         * @reasoncode   FSI::RC_INVALID_LENGTH
         * @userdata1    Data Length
         * @devdesc      presenceDetect> Invalid data length (!= 1 bytes)
         */
        l_errl =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        FSI::MOD_FSIPRES_MEMBPRESENCEDETECT,
                                        FSI::RC_INVALID_LENGTH,
                                        TO_UINT64(io_buflen));
        io_buflen = 0;
        return l_errl;
    }

    // First look for FSI presence bits
    bool fsi_present = isSlavePresent(i_target);


    //@todo-RTC:44254 : Switch to FRU VPD (vs DIMM)

    // Next look for some associated DIMM VPD
    bool vpd_present = false;

    // find all of the CDIMMs associated with this membuf
    TARGETING::PredicateCTM l_dimm(TARGETING::CLASS_LOGICAL_CARD,
                                   TARGETING::TYPE_DIMM,
                                   TARGETING::MODEL_CDIMM);
    TARGETING::PredicatePostfixExpr dimm_query;
    dimm_query.push(&l_dimm);

    TARGETING::TargetHandleList dimm_list;
    TARGETING::targetService().getAssociated(dimm_list,
                                  i_target,
                                  TARGETING::TargetService::CHILD_BY_AFFINITY,
                                  TARGETING::TargetService::ALL,
                                  &dimm_query);

    if( dimm_list.empty() )
    {
        vpd_present = false;
    }
    else
    {        
        size_t presentSize = sizeof(vpd_present);
        for( TARGETING::TargetHandleList::iterator dimm = dimm_list.begin();
             (dimm != dimm_list.end()) && !vpd_present && !l_errl;
             ++dimm )
        {
            l_errl = deviceRead(*dimm,
                                &vpd_present,
                                presentSize,
                                DEVICE_PRESENT_ADDRESS());
        }
        if( l_errl )
        {
            // commit this log because we never expect this call to fail
            errlCommit( l_errl,
                        FSI_COMP_ID );
        }
    }

    // Finally compare the 2 methods
    if( fsi_present != vpd_present )
    {
        TRACFCOMP(g_trac_fsi,
                  ERR_MRK "FSI::membPresenceDetect> FSI (=%d) and VPD (=%d) do not agree for %.8X",
                  fsi_present, vpd_present, TARGETING::get_huid(i_target));
        /*@
         * @errortype
         * @moduleid     FSI::MOD_FSIPRES_MEMBPRESENCEDETECT
         * @reasoncode   FSI::RC_FSI_MVPD_MISMATCH
         * @userdata1    HUID of processor
         * @userdata2[0:31]    FSI Presence
         * @userdata2[32:63]   VPD Presence
         * @devdesc      presenceDetect> FSI and MVPD do not agree
         */
        l_errl =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        FSI::MOD_FSIPRES_MEMBPRESENCEDETECT,
                                        FSI::RC_FSI_MVPD_MISMATCH,
                                        TWO_UINT32_TO_UINT64(
                                            fsi_present,
                                            vpd_present));

        //@todo-callout the membuf
        //l_errl->addHwCallout( i_target, LOW, NO_DECONFIG, NO_GARD );

        // commit this log and move on
        errlCommit( l_errl,
                    FSI_COMP_ID );
    }
    
    bool present = fsi_present & vpd_present;
    memcpy(io_buffer, &present, sizeof(present));
    io_buflen = sizeof(present);

    return NULL;
}


// Register as the presence detect for processor and memory buffers.
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PRESENT,
                      TARGETING::TYPE_PROC,
                      procPresenceDetect);
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PRESENT,
                      TARGETING::TYPE_MEMBUF,
                      membPresenceDetect);

};
