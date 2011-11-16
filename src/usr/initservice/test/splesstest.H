//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/test/splesstest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

#ifndef __TEST_SPLESS_H
#define __TEST_SPLESS_H

/**
 * @file    splesstest.H
 *
 *  Test SP-less interface to
 */

#include    <sys/time.h>                // nanosleep
#include    <sys/mmio.h>                // mmio_scratch_write/read

#include    <cxxtest/TestSuite.H>
#include    <devicefw/userif.H>

#include    "../istepdispatcher/istepdispatcher.H"

#include    "../istepdispatcher/splesscommon.H"

using namespace INITSERVICE;        // SPLessCommand and SPLessStatus
using namespace TARGETING;          // getIStepMode()

/**
 * @class SPLessTest
 *
 *  attempts to run ISteps using the SP-Less interface
 *
 */
class SPLessTest: public CxxTest::TestSuite
{

public:
    /**
     *  @brief  testSPLessTest1
     *
     *  -   test that IStep Mode is enabled
     *  -   read SPLess status:
     *      - ready bit should be on
     *      - running bit shold be off
     *      - status should be 0
     *
     */
    void testSPLessTest1( )
    {
        bool        l_runningbit    =   false;
        bool        l_readybit      =   false;
        uint16_t    l_IStep     =   0;
        uint16_t    l_Substep   =   0;
        uint16_t    l_taskStatus    =   0;
        uint16_t    l_istepStatus   =   0;

        if ( ! checkIStepMode() )
        {
            //  IStepMode is off, don't bother running this
            TS_TRACE("IStepMode disabled, can't run unit test" );
            return;
        }

        SPLESSSTS::read(  l_runningbit,
                          l_readybit,
                          l_IStep,
                          l_Substep,
                          l_taskStatus,
                          l_istepStatus   );
        if  ( l_readybit == false )
        {
            TS_FAIL( "Ready bit should be on");
        }

        if  ( l_runningbit == true )
        {
            TS_FAIL( "Running bit should be off");
        }

        if ( ( l_IStep != 0 )  ||
             ( l_Substep != 0 )

        )
        {
            TS_FAIL( "IStep and SubStep fields should be 0");
        }


        if ( ( l_taskStatus != 0 )  ||
             ( l_istepStatus != 0 )

        )
        {
            TS_FAIL( "Status fields should be 0");
        }

    }

    /**
     * @brief   testSPLessTest2
     *
     *  - Execute IStep 0, substep 0
     *
     *  - this should succeed.
     *
     */
    void testSPLessTest2( )
    {
        uint16_t    l_taskStatus    =   0;
        uint16_t    l_istepStatus   =   0;
        bool        l_pass          =   false;

        if ( ! checkIStepMode() )
        {
            //  IStepMode is off, don't bother running this
            TS_TRACE("IStepMode disabled, can't run unit test" );
            return;
        }

        if ( ! checkReadyBit() )
        {
            TS_FAIL( "readybit is not enabled");
            return;
        }

        //
        l_pass  =   runIStep(   0,              //  IStep = 0
                                0,              //  Substep=0
                                l_taskStatus,   //  task status
                                l_istepStatus   //  istep status
                             );

        if  ( !l_pass )
        {
            TS_FAIL( "FAILED to run IStep");
            // dump errorlog?
        }

        if ( l_taskStatus != 0 )
        {
            TS_FAIL( "bad status: taskStatus expected 0, got %d",
                    l_taskStatus);
        }


        if ( l_istepStatus != 0 )
      {
            TS_FAIL( "bad status: istepStatus expected 0, got %d",
                    l_istepStatus);
      }


    }


    /**
     *  @brief  testSPLessTest3
     *
     *      - Execute Invalid IStep
     *
     */
    void    testSPLessTest3( )
    {
        uint16_t    l_taskStatus    =   0;
        uint16_t    l_istepStatus   =   0;
        bool        l_pass          =   false;

        if ( ! checkIStepMode() )
        {
            //  IStepMode is off, don't bother running this
            TS_TRACE("IStepMode disabled, can't run unit test" );
            return;
        }


         if ( ! checkReadyBit() )
         {
             TS_FAIL( "readybit is not enabled");
             return;
         }

         // run invalid istep/substep
         l_pass  =   runIStep(   55,                //  IStep = 55
                                 55,                //  Substep=55
                                 l_taskStatus,      //  return task status
                                 l_istepStatus      //  return istep status
                              );

         if  ( !l_pass )
         {
             TS_FAIL( "FAILED to run IStep");
             // dump errorlog?
         }

         if (  (l_taskStatus != 0 ) ||
               (l_istepStatus != 0 )
               )
         {
             TS_FAIL( "bad status: taskStatus expected 0, got %d",
                     l_taskStatus);
         }


         if (
             (l_istepStatus != 0 )
             )
       {
             TS_FAIL( "bad status: istepStatus expected 0, got %d",
                     l_istepStatus);
       }

    }


    /**
     *  @brief  testSPLessTest4
     *
     *     - Execute Several ISteps
     *
     *
     *
     */
    void    testSPLessTest4( )
    {

    }


private:

    /**
     * @brief   checkIStepMode
     *
     * check that IStepMode is enabled, by reading the IStepModeSCOM for
     * a signature value.
     *
     *  @return bool
     *  @retval true if IStepMode is on, false otherwise
     */
    bool    checkIStepMode()
    {
        uint64_t    l_readData  =   0;
        bool        l_flag      =   false;

        l_readData  =   mmio_scratch_read( MMIO_SCRATCH_IPLSTEP_CONFIG );

        // check for IStep Mode signature, this is temporary
        if ( l_readData == ISTEP_MODE_ON_SIGNATURE )
        {
            l_flag    =   true;
         }
        else
        {
            l_flag    =   false;
        }


        return  l_flag;
    }

    /**
     * @brief   checkReadyBit
     *
     * check if the ready bit is on before starting any ISteps.
     *
     * This calls TS_FAIL and returns false if it cannot read the SCOM.
     *
     * @return  bool
     * @retval  true if readybit is on, false otherwise
     */
    bool  checkReadyBit( )
    {
        bool            l_runningbit    =   false;
        bool            l_readybit      =   false;
        uint16_t        l_IStep         =   0;
        uint16_t        l_Substep       =   0;
        uint16_t        l_taskStatus    =   0;
        uint16_t        l_istepStatus   =   0;

        SPLESSSTS::read(  l_runningbit,
                          l_readybit,
                          l_IStep,
                          l_Substep,
                          l_taskStatus,
                          l_istepStatus );

        return  l_readybit;
    }


    /**
     * @brief   runIStep
     *
     *  run one IStep /substep and return results.
     *
     *  Assumes that readybit is on (i.e. you should have checked it
     *  before calling this)
     *
     *  calls TS_FAIL and returns false if cannot read the SCOM regs
     *  calls TS_FAIL and returns false if times out waiting for runningbit
     *  calls TS_FAIL and returns false if ready bit goes off
     *
     *  @param[in]  i_IStep         -   IStep to run
     *  @param[in]  i_Substep       -   Substep to run
     *  @param[out] o_taskStatus    -   taskStatus returned from IStep/substep
     *  @param[out] o_istepStatus   -   istepStatus retured from IStep/substep
     *
     *  @return bool
     *  @retval true if IStep runs OK, false otherwise
     */
    bool    runIStep(   uint16_t    i_IStep,
                        uint16_t    i_Substep,
                        uint16_t    &o_taskStatus,
                        uint16_t    &o_istepStatus
                    )
    {
        bool        l_runningbit        =   false;
        bool        l_readybit          =   false;
        uint16_t    l_IStep             =   0;
        uint16_t    l_Substep           =   0;
        bool        l_pass              =   false;

        //  init outputs

        l_IStep         =   0;
        l_Substep       =   0;
        o_taskStatus    =   0;
        o_istepStatus   =   0;

        l_pass =   true;           // assume things will be OK


        //  Write gobit, istep, substep
        //
        SPLESSCMD::write( true,           //  gobit
                          i_IStep,        //  istep
                          i_Substep       //  substep
                        );
        // loop up waiting for test to finish
        int timeoutctr  =   10;
        do  {
            //  give it 500 millseconds to finish
            nanosleep( 0, 500000000 );

            SPLESSSTS::read( l_runningbit,
                             l_readybit,
                             l_IStep,
                             l_Substep,
                             o_taskStatus,
                             o_istepStatus
                            );

            //  timeout probably means the singlestep loop died.
            //  do a TS_FAIL
            if ( --timeoutctr <= 0 )
            {
                TS_FAIL( "TIMEOUT waiting for runningbit to turn off");
                l_pass  =   false;
            }

        }   while (l_runningbit);

        //  check readybit - if it's off it means the singlestep loop died.
        //  do a TS_FAIL
        if ( ! l_readybit )
        {
            TS_FAIL( "FAIL: readybit is off");
            l_pass  =   false;
        }

        return  l_pass;
    }

};  // class


#endif

