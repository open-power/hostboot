#ifndef __PNORDDTEST_H
#define __PNORDDTEST_H

/**
 *  @file pnorddtest.H
 *
 *  @brief Test case for PNOR Resource Provider
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errltypes.H>
#include <pnor/pnorif.H>
#include <devicefw/userif.H>
//#include "../pnordd.H"

extern trace_desc_t* g_trac_pnor;
using namespace TARGETING;


class PnorDdTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief PNOR DD test #1
     *        Write some data to PNOR and read it back again
     */
    void testPnorDD1(void)
    {
      //@TODO: make this table driven so it can test more values
      //@TODO: compare results with expected data.
      //@TODO: Add some more interesting tests

      TARGETING::Target* l_testTarget = MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
      size_t l_size = sizeof(uint64_t); 
      errlHndl_t l_err = NULL;

      do{
        TS_TRACE("testPnorDD1: starting");

        // Perform PnorDD Write 1
        uint64_t l_address = 0x100;
        uint64_t l_writeData = 0x12345678FEEDB0B0;
        l_err = deviceWrite(l_testTarget,
                            &l_writeData,
                            l_size,
                            DEVICE_PNOR_ADDRESS(0, l_address));
        if (l_err)
            {
          TS_FAIL("testPnorDD1: PNORDD write 1: deviceWrite() failed! Error committed.");
          break;
            }
        else
            {
          TS_TRACE("testPnorDD1: PNORDD write 1, Address 0x%llx, Data %llx",
                   l_address,
                   (long long unsigned)l_writeData);
            }


        // Perform PnorDD Write 2
        l_address = 0x108;
        l_writeData = 0xFEEDBEEF000ABCDE;
        l_err = deviceWrite(l_testTarget,
                            &l_writeData,
                            l_size,
                            DEVICE_PNOR_ADDRESS(0, l_address));
        if (l_err)
            {
          TS_FAIL("testPnorDD1: PNORDD write 2: deviceWrite() failed! Error committed.");
          break;
            }
        else
            {
          TS_TRACE("testPnorDD1: PNORDD write 2, Address 0x%llx, Data %llx",
                   l_address,
                   (long long unsigned)l_writeData);
            }

        // Perform PnorDD read 1
        l_address = 0x100;
        uint64_t l_readData = 0;
        l_err = deviceRead(l_testTarget,
                           &l_readData,
                           l_size,
                           DEVICE_PNOR_ADDRESS(0, l_address));
        if (l_err)
            {
          TS_FAIL("testPnorDD1: PNORDD read 1: deviceRead() failed! Error committed.");
          break;
            }
        else
            {
          TS_TRACE("testPnorDD1: PNORDD read 1, Address 0x%llx, Data %llx",
                   l_address,
                   (long long unsigned)l_readData);
            }

        // Perform PnorDD read 2
        l_address = 0x108;
        l_err = deviceRead(l_testTarget,
                           &l_readData,
                           l_size,
                           DEVICE_PNOR_ADDRESS(0, l_address));
        if (l_err)
            {
          TS_FAIL("testPnorDD1: PNORDD read 2: deviceRead() failed! Error committed.");
          break;
            }
        else
            {
          TS_TRACE("testPnorDD1: PNORDD read 2, Address 0x%llx, Data %llx",
                   l_address,
                   (long long unsigned)l_readData);
            }

          }while(0);


          //@TODO: Add total fail/pass count trace to know how many passed.

    };


};     


#endif
