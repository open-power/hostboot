/**
 * @file    initservicevfs2.C
 *
 *  Private functions for VFS2 phase.
 */

#include <kernel/console.H>
#include <sys/vfs.h>
#include <sys/task.h>
#include <trace/interface.H>

#include    "initservice.H"

#include    "initsvctasks.H"


namespace   INITSERVICE
{


/******************************************************************************/
//  private functions for VFS 2 phase
/******************************************************************************/


void    InitService::startTargetting( errlHndl_t    &io_rerrl )         const
{


   return;
}


 void    InitService::getMasterChipTarget( errlHndl_t    &io_rerrl )    const
{


   return;
}


 void    InitService::startMailboxDD( errlHndl_t    &io_rerrl )         const
{


   return;
}


 void    InitService::startSPComm( errlHndl_t    &io_rerrl )            const
{


    return;
}


 void    InitService::enableStreamingTrace( errlHndl_t    &io_rerrl )   const
{


    return;
}


 void    InitService::startProgressCodes( errlHndl_t    &io_rerrl )     const
{

   return;

}


 void    InitService::startFSIDD( errlHndl_t    &io_rerrl )             const
{


   return;
}


 void    InitService::setupSlaveLinks( errlHndl_t    &io_rerrl )        const
{


   return;
}


 void    InitService::startFSISCOM( errlHndl_t    &io_rerrl )           const
{


   return;
}


 void    InitService::startFSII2C( errlHndl_t    &io_rerrl )            const
{


   return;
}


 void    InitService::startHWPF( errlHndl_t    &io_rerrl )               const
{


   return;
}


 void    InitService::readMaxConfigfromPNOR( errlHndl_t    &io_rerrl )  const
{


   return;
}


void    InitService::applyPresenceDetect( errlHndl_t    &io_rerrl )     const
{


   return;
}


 void    InitService::applyPartialBad( errlHndl_t    &io_rerrl )        const
{


   return;
}

void    InitService::applyGard( errlHndl_t    &io_rerrl )               const
{


   return;
}


void    InitService::collectHWIDEC( errlHndl_t    &io_rerrl )           const
{


   return;
}


 void    InitService::verifyIDEC( errlHndl_t    &io_rerrl )             const
{


   return;
}


 void    InitService::disableWatchDog( errlHndl_t    &io_rerrl )        const
{


   return;
}


 void    InitService::executeISteps( errlHndl_t    &io_rerrl )          const
{


   return;
}

}   // namespace    INITSERVICE
