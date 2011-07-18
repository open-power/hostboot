#include <stdint.h>

namespace CxxTest
{

// This variable is to allow a code in a binary image not containing the
// testcase modules to query the number of failed tests
uint64_t g_FailedTests = 0;

}

