/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/test/ecctest.H $                                 */
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
#include <cxxtest/TestSuite.H>
#include <pnor/ecc.H>
#include <stdlib.h>
#include <string.h>

// Forward declarations, see ecc.C
namespace PNOR
{
    namespace ECC
    {
        uint8_t generateECC(uint64_t i_data);
        uint8_t verifyECC(uint64_t i_data, uint8_t i_ecc);
        uint8_t correctECC(uint64_t& io_data, uint8_t& io_ecc);
    }
}

class ECCTest : public CxxTest::TestSuite
{
    public:

        void testConsistency()
        {
            uint64_t data = 0x8d8aeff460bd2fc8; // <-- random data.
            uint8_t ecc = PNOR::ECC::generateECC(data);

            uint8_t result = PNOR::ECC::verifyECC(data, ecc);
            if (PNOR::ECC::GD != result)
            {
                TS_FAIL("ECCTest::testConsistency: Inconsistent results: "
                        "0x%16x 0x%2x: %d",
                        data, ecc, result);
            }
        }

        void testCorrection()
        {
            uint64_t data = 0x8d8aeff460bd2fc8; // <-- random data.
            uint8_t ecc = PNOR::ECC::generateECC(data);

            for (int i = 0; i < 64; i++)
            {
                uint64_t bad_data = data ^ (1ul << (63 - i));
                uint8_t result = PNOR::ECC::verifyECC(bad_data, ecc);

                if (i != result)
                {
                    TS_FAIL("ECCTest::testCorrection: Incorrect correct data: "
                            "0x%16x 0x%2x: %d %d",
                            data, ecc, i, result);
                }
            }

            for (int i = 0; i < 8; i++)
            {
                uint8_t bad_ecc = ecc ^ (1 << i);
                uint8_t result = PNOR::ECC::verifyECC(data, bad_ecc);

                if (i != (result - PNOR::ECC::E7))
                {
                    TS_FAIL("ECCTest::testCorrection: Incorrect correct ecc: "
                            "0x%16x 0x%2x: %d %d",
                            data, ecc, i, result);
                }
            }
        }

        void testUncorrectable()
        {
            uint64_t data = 0x8d8aeff460bd2fc8; // <-- random data.
            uint8_t ecc = PNOR::ECC::generateECC(data);

            for (int i = 0; i < 64; i++)
            {
                for (int j = 0; j < 64; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }

                    uint64_t bad_data = data ^ (1ul << i) ^ (1ul << j);
                    uint8_t result = PNOR::ECC::verifyECC(bad_data, ecc);

                    if (PNOR::ECC::UE != result)
                    {
                        TS_FAIL("ECCTest::testUncorrectable: Non-UE: "
                                "0x%16x 0x%2x : %d %d",
                                data, ecc, i, j);
                    }
                }
            }
        }

        void testInject()
        {
            uint64_t data = 0x8d8aeff460bd2fc8; // <-- random data.
            size_t s = sizeof(data);

            // Allocate buffers.
            uint8_t* in_data = new uint8_t[s];
            memcpy(in_data, &data, s);
            uint8_t* out_data = new uint8_t[(s * 9) / 8];

            // Inject ECC.
            PNOR::ECC::injectECC(in_data, s, out_data);

            // Clear source.
            memset(in_data, '\0', s);

            // Remove ECC.
            PNOR::ECC::removeECC(out_data, in_data, s);

            // Ensure data matches.
            if (0 != memcmp(in_data, &data, s))
            {
                TS_FAIL("ECCTest::testInject: Data mismatch: %16x %16x\n",
                        data, *reinterpret_cast<uint64_t*>(in_data));
            }

            delete[] in_data;
            delete[] out_data;
        }
};
