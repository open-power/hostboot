/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/runtime/rt_fsi.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

#include <stdlib.h>
#include <runtime/rt_targeting.H>
#include <runtime/interface.h>

#include <targeting/common/targetservice.H>

#include <fsi/fsiif.H>
#include "rt_fsi.H"
#include <util/misc.H>
#include <fsi/fsi_reasoncodes.H>

// Trace definition
trace_desc_t* g_trac_fsi = NULL;
TRAC_INIT(&g_trac_fsi, FSI_COMP_NAME, KILOBYTE); // 1K


/**
 * @brief Retrieve some FSI attribute information
 */
void FSI::getFsiLinkInfo( TARGETING::Target* i_slave,
                          FSI::FsiLinkInfo_t& o_info )
{
    Singleton<RtFsi>::instance().getFsiLinkInfo( i_slave,o_info );
}

/* Protected Methods */

/**
 * @brief Constructor
 */
RtFsi::RtFsi()
:iv_master(NULL)
,iv_useAlt(0)
{
    TRACFCOMP(g_trac_fsi, "RtFsi::RtFsi()>");

    // save away the master processor target
    TARGETING::TargetService& targetService = TARGETING::targetService();
    iv_master = NULL;
    targetService.masterProcChipTargetHandle( iv_master );
    TRACFCOMP(g_trac_fsi, "Master=%.8X",TARGETING::get_huid(iv_master));

}

/**
 * @brief Destructor
 */
RtFsi::~RtFsi()
{

}

/* Public Methods */

/**
 * @brief Retrieve the connection information needed to access FSI
 *        registers within the given chip target
 */
FSI::FsiChipInfo_t RtFsi::getFsiInfo( TARGETING::Target* i_target )
{
    FSI::FsiChipInfo_t info;

    mutex_lock(&iv_dataMutex);

    // Check if we have a cached version first
    std::map<TARGETING::Target*,FSI::FsiChipInfo_t>::iterator itr
      = iv_fsiInfoMap.find(i_target);
    if( itr != iv_fsiInfoMap.end() )
    {
        info = itr->second;
    }
    else
    {
        // fetch the data from the attributes
        info = getFsiInfoFromAttr( i_target );
        // then cache it for next time
        iv_fsiInfoMap[i_target] = info;
    }

    mutex_unlock(&iv_dataMutex);

    return info;
}

/**
 * @brief Retrieve some FSI attribute information
 */
void RtFsi::getFsiLinkInfo( TARGETING::Target* i_slave,
                            FSI::FsiLinkInfo_t& o_info )
{
    FSI::FsiAddrInfo_t addr_info( i_slave, 0x0 );
    errlHndl_t tmp_err = RtFsi::genFullFsiAddr( addr_info );
    if( tmp_err )
    {
        TRACFCOMP( g_trac_fsi, "Error getting FsiLinkInfo fo %.8X",
                        TARGETING::get_huid(i_slave));
        delete tmp_err;
        return;
    }

    o_info.master = addr_info.accessInfo.master;
    o_info.type = addr_info.accessInfo.type;
    o_info.link = addr_info.accessInfo.port;
    o_info.cascade = addr_info.accessInfo.cascade;
    o_info.mPort = 0;
    if( addr_info.accessInfo.master &&
       (addr_info.accessInfo.master != iv_master) &&
       (getFsiInfo(addr_info.accessInfo.master).flagbits.flipPort) )
    {
        o_info.mPort = 1;
    }

    // if this chip is not off the master, need to include its
    // master's offset oo
    o_info.baseAddr = addr_info.absAddr;
    if( addr_info.opbTarg != iv_master )
    {
        FSI::FsiChipInfo_t mfsi_info = getFsiInfo(addr_info.accessInfo.master);
        o_info.baseAddr |= FSI::getPortOffset(mfsi_info.type,mfsi_info.port);
    }
}

/**
 * @brief Generate a complete FSI address based on the target and the
 *        FSI offset within that target
 */
errlHndl_t RtFsi::genFullFsiAddr(FSI::FsiAddrInfo_t& io_addrInfo)
{
    errlHndl_t l_err = NULL;

    //default to using the master chip for OPB XSCOM ops
    io_addrInfo.opbTarg = iv_master;

    //start off with the addresses being the same
    io_addrInfo.absAddr = io_addrInfo.relAddr;

    //pull the FSI info out for this target
    io_addrInfo.accessInfo = getFsiInfo( io_addrInfo.fsiTarg );

    //target matches master so the address is correct as-is
    if( io_addrInfo.fsiTarg == iv_master )
    {
        return NULL;
    }

    TRACFCOMP( g_trac_fsi, "target=%.8X : Link Id=%.8X",
                    TARGETING::get_huid(io_addrInfo.fsiTarg),
                    io_addrInfo.accessInfo.linkid.id );

    //FSI master is the master proc, find the port
    if( io_addrInfo.accessInfo.master == iv_master )
    {
        //append the appropriate offset
        io_addrInfo.absAddr += FSI::getPortOffset(io_addrInfo.accessInfo.type,
                                             io_addrInfo.accessInfo.port);
    }
    //verify this target has a valid FSI master
    else if( TARGETING::FSI_MASTER_TYPE_CMFSI != io_addrInfo.accessInfo.type )
    {
        TRACFCOMP( g_trac_fsi,"target=%.8X : Master Type isn't supported = %d",
                        TARGETING::get_huid(io_addrInfo.fsiTarg),
                        io_addrInfo.accessInfo.type );
        /*@
         * @errortype
         * @moduleid     FSI::MOD_RTFSI_GENFULLFSIADDR
         * @reasoncode   FSI::RC_FSI_NOT_SUPPORTED
         * @userdata1    Target of FSI Operation
         * @userdata2[32:39]  Physical Node of FSI Master processor
         * @userdata2[40:47]  Physical Position of FSI Master processor
         * @userdata2[48:55]  FSI Master type (0=MFSI,1=CMFSI,2=NO_MASTER)
         * @userdata2[56:63]  Slave link/port number
         * @devdesc      FsiDD::genFullFsiAddr> Master Type is not supported
         * @custdesc     A problem occurred during the
         *               IPL of the system.
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                     FSI::MOD_RTFSI_GENFULLFSIADDR,
                                     FSI::RC_FSI_NOT_SUPPORTED,
                                     TARGETING::get_huid(io_addrInfo.fsiTarg),
                                     io_addrInfo.accessInfo.linkid.id,
                                     true /*SW error*/);
        l_err->collectTrace(FSI_COMP_NAME);
        return l_err;
    }
    //target is behind another proc
    else
    {
        //append the CMFSI portion first
        io_addrInfo.absAddr += FSI::getPortOffset(io_addrInfo.accessInfo.type,
                                             io_addrInfo.accessInfo.port);

        //find this port's master and then get its port information
        FSI::FsiChipInfo_t mfsi_info =
                getFsiInfo(io_addrInfo.accessInfo.master);

        //check for invalid topology
        if( mfsi_info.master != iv_master )
        {
            TRACFCOMP( g_trac_fsi,
                      "target=%.8X : master=%.8X : master's master=%.8X :"
                      " Cannot chain 2 masters",
                      TARGETING::get_huid(io_addrInfo.fsiTarg),
                      TARGETING::get_huid(io_addrInfo.accessInfo.master),
                      TARGETING::get_huid(mfsi_info.master),
                      io_addrInfo.accessInfo.type );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_RTFSI_GENFULLFSIADDR
             * @reasoncode   FSI::RC_INVALID_FSI_PATH_1
             * @userdata1[0:31]   Target of FSI Operation
             * @userdata1[32:63]  Target's FSI Master Chip
             * @userdata2[0:7]    Physical Node of FSI Master processor
             *                    [target's master]
             * @userdata2[8:15]   Physical Position of FSI Master processor
             *                    [target's master]
             * @userdata2[16:23]  FSI Master type (0=MFSI,1=CMFSI,2=NO_MASTER)
             *                    [target's master]
             * @userdata2[24:31]  Slave link/port number  [target's master]
             * @userdata2[32:39]  Physical Node of FSI Master processor
             *                    [master's master]
             * @userdata2[40:47]  Physical Position of FSI Master processor
             *                    [master's master]
             * @userdata2[48:55]  FSI Master type (0=MFSI,1=CMFSI,2=NO_MASTER)
             *                    [master's master]
             * @userdata2[56:63]  Slave link/port number  [master's master]
             * @devdesc      FsiDD::genFullFsiAddr> Cannot chain 2 masters
             * @custdesc     A problem occurred during the
             *               IPL of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        FSI::MOD_RTFSI_GENFULLFSIADDR,
                        FSI::RC_INVALID_FSI_PATH_1,
                        TWO_UINT32_TO_UINT64(
                          TARGETING::get_huid(io_addrInfo.fsiTarg),
                          TARGETING::get_huid(io_addrInfo.accessInfo.master)),
                        TWO_UINT32_TO_UINT64(
                          io_addrInfo.accessInfo.linkid.id,
                          mfsi_info.linkid.id),
                        true /*SW error*/);
            l_err->collectTrace(FSI_COMP_NAME);
            return l_err;
        }
        else if( TARGETING::FSI_MASTER_TYPE_MFSI != mfsi_info.type )
        {
            TRACFCOMP( g_trac_fsi, "target=%.8X:master=%.8X, type=%d, port=%d",
                            TARGETING::get_huid(io_addrInfo.fsiTarg),
                            TARGETING::get_huid(io_addrInfo.accessInfo.master),
                            io_addrInfo.accessInfo.type,
                            io_addrInfo.accessInfo.port );
            TRACFCOMP( g_trac_fsi,
                      "Master: target=%.8X : master=%.8X, type=%d, port=%d",
                      TARGETING::get_huid(io_addrInfo.accessInfo.master),
                      TARGETING::get_huid(mfsi_info.master),
                      mfsi_info.type, mfsi_info.port );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_RTFSI_GENFULLFSIADDR
             * @reasoncode   FSI::RC_INVALID_FSI_PATH_2
             * @userdata1[0:31]   Target of FSI Operation
             * @userdata1[32:63]  Target's FSI Master Chip
             * @userdata2[0:7]    Physical Node of FSI Master processor
             *                    [target's master]
             * @userdata2[8:15]   Physical Position of FSI Master processor
             *                    [target's master]
             * @userdata2[16:23]  FSI Master type (0=MFSI,1=CMFSI,2=NO_MASTER)
             *                    [target's master]
             * @userdata2[24:31]  Slave link/port number  [target's master]
             * @userdata2[32:39]  Physical Node of FSI Master processor
             *                    [master's master]
             * @userdata2[40:47]  Physical Position of FSI Master processor
             *                    [master's master]
             * @userdata2[48:55]  FSI Master type (0=MFSI,1=CMFSI,2=NO_MASTER)
             *                    [master's master]
             * @userdata2[56:63]  Slave link/port number  [master's master]
             * @devdesc      FsiDD::genFullFsiAddr> Invalid master type for the
             *               target's master
             * @custdesc     A problem occurred during the
             *               IPL of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        FSI::MOD_RTFSI_GENFULLFSIADDR,
                        FSI::RC_INVALID_FSI_PATH_2,
                        TWO_UINT32_TO_UINT64(
                          TARGETING::get_huid(io_addrInfo.fsiTarg),
                          TARGETING::get_huid(io_addrInfo.accessInfo.master)),
                        TWO_UINT32_TO_UINT64(
                          io_addrInfo.accessInfo.linkid.id,
                          mfsi_info.linkid.id),
                        true /*SW error*/);
            l_err->collectTrace(FSI_COMP_NAME);
            return l_err;
        }

        // If powerbus is alive, we can use the local master
        //
        if( Util::isSimicsRunning()
            && (mfsi_info.flagbits.flipPort) )
        {
            //@fixme - RTC:99928 : Simics is wired wrong on Brazos
            // so always use indirect path when talking through
            // a flipped cmfsi port

            //using the master chip so we need to append the MFSI port
            io_addrInfo.absAddr += FSI::getPortOffset(mfsi_info.type,
                                                      mfsi_info.port);
        }
        else if( (io_addrInfo.accessInfo.master)->
                 getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom
                 )
        {
            //use the local proc to drive the operation instead of
            // going through the master proc indirectly
            io_addrInfo.opbTarg = io_addrInfo.accessInfo.master;
            // Note: no need to append the MFSI port since it is now local

            // set a flag to flip the OPB port if this slave's master
            //  is reversed and it isn't the acting master
            if( io_addrInfo.accessInfo.master != iv_master )
            {
                io_addrInfo.accessInfo.flagbits.flipPort
                  = mfsi_info.flagbits.flipPort;
            }
        }
        else
        {
            //using the master chip so we need to append the MFSI port
            io_addrInfo.absAddr += FSI::getPortOffset(mfsi_info.type,
                                                      mfsi_info.port);
        }
    }

    return NULL;
}

/**
 * @brief Retrieve the connection information needed to access FSI
 *        registers within the given chip target
 */
FSI::FsiChipInfo_t RtFsi::getFsiInfoFromAttr( TARGETING::Target* i_target )
{
    FSI::FsiChipInfo_t info;
    info.slave = i_target;

    using namespace TARGETING;

    EntityPath epath;

    if( (i_target != NULL) &&
        i_target->tryGetAttr<ATTR_FSI_MASTER_TYPE>(info.type) )
    {
        if( info.type != FSI_MASTER_TYPE_NO_MASTER )
        {
            if( !iv_useAlt
                && i_target->tryGetAttr<ATTR_FSI_MASTER_CHIP>(epath) )
            {
                info.master = targetService().toTarget(epath);

                if( i_target->tryGetAttr<ATTR_FSI_MASTER_PORT>(info.port) )
                {
                    if( i_target->tryGetAttr<ATTR_FSI_SLAVE_CASCADE>
                        (info.cascade) )
                    {
                        if( !i_target->tryGetAttr<ATTR_FSI_OPTION_FLAGS>
                            (info.flagbits) )
                        {
                            info.master = NULL;
                        }
                    }
                    else
                    {
                        info.master = NULL;
                    }
                }
                else
                {
                    info.master = NULL;
                }
            }
            else if( iv_useAlt
                     && i_target->tryGetAttr<ATTR_ALTFSI_MASTER_CHIP>(epath) )
            {
                TRACFCOMP(g_trac_fsi,"Using alt path for %.8X",i_target);
                info.master = targetService().toTarget(epath);

                if( i_target->tryGetAttr<ATTR_ALTFSI_MASTER_PORT>(info.port) )
                {
                    if( i_target->tryGetAttr<ATTR_FSI_SLAVE_CASCADE>
                        (info.cascade) )
                    {
                        if( !i_target->tryGetAttr<ATTR_FSI_OPTION_FLAGS>
                            (info.flagbits) )
                        {
                            info.master = NULL;
                        }
                    }
                    else
                    {
                        info.master = NULL;
                    }
                }
                else
                {
                    info.master = NULL;
                }
            }
            else
            {
                info.master = NULL;
            }
        }
    }


    if( (info.master == NULL)
        || (info.type == FSI_MASTER_TYPE_NO_MASTER)
        || (info.port == UINT8_MAX) )
    {
        info.master = NULL;
        info.type = FSI_MASTER_TYPE_NO_MASTER;
        info.port = UINT8_MAX;
        info.cascade = 0;
        info.flags = 0;
        info.linkid.id = 0;
    }
    else
    {
        TARGETING::EntityPath master_phys;
        if( info.master->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(master_phys) )
        {
            info.linkid.node =
              master_phys.pathElementOfType(TARGETING::TYPE_NODE).instance;
            info.linkid.proc =
              master_phys.pathElementOfType(TARGETING::TYPE_PROC).instance;
            info.linkid.type = static_cast<uint8_t>(info.type);
            info.linkid.port = info.port;
        }
    }

    TRACDCOMP( g_trac_fsi,
              "getFsiInfoFromAttr> i_target=%.8X : master=%.8X, type=%X",
              TARGETING::get_huid(i_target),
              TARGETING::get_huid(info.master), info.type );
    TRACDCOMP( g_trac_fsi,
              "getFsiInfoFromAttr> port=%X, cascade=%X, flags=%X, linkid=%.8X",
              info.port, info.cascade, info.flags, info.port );
    return info;
}


