#ifndef __XCOMTEST_H
#define __XCOMTEST_H

/**
 *  @file xscomtest.H
 *
 *  @brief Test case for XSCOM code
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errltypes.H>
#include <devicefw/userif.H>

using namespace TARGETING;

// Address and data to read/write
struct testXscomAddrData
{
    uint32_t addr;
    uint64_t data;
};

// Test table values
//@todo - Select scratch register so chip doesn't get messed-up
const testXscomAddrData g_xscomAddrTable[] =
{
    {0x08030007, 0x8000000000000001},
    {0x08010587, 0x9000000000000003},

};
const uint32_t g_xscomAddrTableSz =
                    sizeof(g_xscomAddrTable)/sizeof(testXscomAddrData);


class XscomTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief XSCOM test #1
     *        Write value and read back to verify
     */
    void testXscom1(void)
    {

        //@todo - Replace printk with traces

        TARGETING::Target* l_testTarget = MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        size_t l_size = sizeof(uint64_t);

        // Loop thru table
        for( uint32_t l_num=0; l_num < g_xscomAddrTableSz; l_num++)
        {
             testXscomAddrData l_testEntry = g_xscomAddrTable[l_num];

             // Perform XSComOM read
             uint64_t l_data = 0;
             errlHndl_t l_err = deviceRead(l_testTarget,
                                &l_data,
                                l_size,
                                DEVICE_SCOM_ADDRESS(l_testEntry.addr));
             if (l_err)
             {
                 printk("\ntestXscom1: XSCom read: deviceRead() fails (1) !\n");
             }
             else
             {
                 printk("\ntestXscom1: XSCom read (1) Address 0x%.8X, Data %llx\n\n\n",
                          l_testEntry.addr,
                          (long long unsigned)l_data);
             }

             // Perform an XSCom write
             l_err = deviceWrite(l_testTarget,
                     &l_testEntry.data,
                     l_size,
                     DeviceFW::SCOM,
                     l_testEntry.addr);

             if (l_err)
             {
                 printk("\ntestXscom1: XSCom write: deviceWrite() fails!\n");
                 break;
             }
             else
             {
                 printk("\ntestXscom1: XSCom write Address 0x%.8X, Data %llx\n",
                         l_testEntry.addr,
                         (long long unsigned)l_testEntry.data);
             }

             // Read back
             l_data = 0;
             l_err = deviceRead(l_testTarget,
                                &l_data,
                                l_size,
                                DEVICE_SCOM_ADDRESS(l_testEntry.addr));
             if (l_err)
             {
                 printk("\ntestXscom1: XSCom read: deviceRead() fails (2) !\n");
             }
             else
             {
                 printk("\ntestXscom1: XSCom read (2) Address 0x%.8X, Data %llx\n\n\n",
                          l_testEntry.addr,
                          (long long unsigned)l_data);
             }
         }
         return;
    }
};

#endif
