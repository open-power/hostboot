
/**
 *  @file Controls which functions are allowed to compile within any file that
 *     resides in the same directory as this file.  Currently, Hostboot only
 *     uses stable APIs.  APIs that are being tested or deprecated are not
 *     allowed.  This file should not be confused with Hostboot's generated
 *     config.h file.
 */

#ifndef LIBPLDM_OEM_IBM_CONFIG_H

#define LIBPLDM_ABI_STABLE
#define LIBPLDM_ABI_TESTING __attribute__((error("Function is not stable")))
#define LIBPLDM_ABI_DEPRECATED __attribute__((error("Function is deprecated")))

#endif // LIBPLDM_OEM_IBM_CONFIG_H

