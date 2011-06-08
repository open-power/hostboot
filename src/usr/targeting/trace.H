
#ifndef TARG_TRACE_H
#define TARG_TRACE_H

/**
 *  @file trace.H
 *
 *  @brief Targeting related trace macros.  Callers of these macros must
 *      define TARG_NAMESPACE, TARG_CLASS, and TARG_FN as appropriate
 */

//******************************************************************************
// Includes
//******************************************************************************

// Other Components
#include <trace/interface.H>

// Give callers access to the trace buffer
namespace TARGETING
{
    extern trace_desc_t* g_trac_targeting;
}

#define TARG_TAG "[TARG]"
#define TARG_ENTER(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " ENTER_MRK " " TARG_NAMESPACE \
        TARG_CLASS TARG_FN " " args)

#define TARG_EXIT(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " EXIT_MRK " " TARG_NAMESPACE \
        TARG_CLASS TARG_FN " " args)

#define TARG_ERR(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " ERR_MRK " " args)

#define TARG_INF(args...) \
    TRACFCOMP(TARGETING::g_trac_targeting,TARG_TAG " " INFO_MRK " " args)

#define TARG_BIN(args...) \
    TRACFBIN(TARGETING::g_trac_targeting,TARG_TAG " " args)

#endif // TARG_TRACE_H
