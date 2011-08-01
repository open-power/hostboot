/** @file misc.H
 *  @brief Misc. Kernel functions and utilities.
 */

#ifndef __KERNEL_MISC_H
#define __KERNEL_MISC_H

#include <stdint.h>

namespace KernelMisc
{
    /** @fn shutdown
     *  @brief Sequence kernel to shutdown and switch to payload.
     */
    void shutdown();
};
#endif
