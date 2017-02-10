/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/tests/ecmd_facade.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

///
/// @file ecmd_facade.H
/// @brief eCMD Facade to hide the repetitive actions we do with eCMD
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 4
// *HWP Consumed by: CI

#ifndef MSS_ECMD_FACADE_H_
#define MSS_ECMD_FACADE_H_

#include <cstdarg>
#include <sys/types.h>
#include <unistd.h>

#include <croClientCapi.H>
#include <ecmdClientCapi.H>
#include <ecmdUtils.H>
#include <ecmdSharedUtils.H>


// from prcdUtils
#include <prcdUtils.H>
extern bool GLOBAL_SIM_MODE;
extern bool GLOBAL_VERIF_MODE;

namespace mss
{
namespace ecmd
{
//Repurpose ecmd output commands
static const auto LERR = ecmdOutputError;
static const auto LDBG = ecmdOutput;

///
/// @brief Creates a unified ecmd output utility using the passed in ecmd output functions
/// @tparam Writer is a function that would be used to write output
/// @param[in] i_writer is a function that will be used to write output
/// @param[in] i_format_str is the string format @note see printf
/// @param[in] ... variable list of args to be written out
///
template<typename Writer>
void ecmd_outp(Writer i_writer, const char* i_format_str, ...)
{
    va_list l_args;
    va_start (l_args, i_format_str);
    const auto l_init_sizeof_string(200);

    //Initial buffer
    char l_ostr[l_init_sizeof_string] = {0};

    //write message to buffer
    auto l_written = vsnprintf(l_ostr, l_init_sizeof_string, i_format_str, l_args);

    //Check to see if there was enough buffer to write all of command
    if(l_written > l_init_sizeof_string - 1)
    {
        //Need to allocate a bigger buffer
        const auto l_new_buffer_size = l_written + 1;
        std::unique_ptr<char[]> l_ostr_longer(new char[ l_new_buffer_size ]);

        //write log message to longer buffer
        vsnprintf(l_ostr_longer.get(), l_new_buffer_size, i_format_str, l_args);

        //Log the message
        i_writer(l_ostr_longer.get());
    }
    else
    {
        //Log the message
        i_writer(l_ostr);
    }

    va_end (l_args);
}


///
/// @class ecmd_facade
/// @brief Facade interface around the ecmd api. It also manages the emcd dll and will unload it
/// upon destruction.
/// @note there should only be one instance of this object
/// ...Should be turned into a factory.
///
class ecmd_facade
{
    private:
        bool iv_is_loaded = false;

        ///
        /// @brief Loads the ecmd shared object
        ///
        uint64_t load_ecmd_dll()
        {
            auto l_rc =  ecmdLoadDll("");

            if(l_rc)
            {
                iv_is_loaded = true;
            }

            return l_rc;
        }


        ///
        /// @brief  Initializes the ecmd interface
        ///
        uint64_t initialize_ecmd()
        {
            // flow/control variables
            auto l_rc = ECMD_SUCCESS;
            ecmdDllInfo DLLINFO;

            // load and initialize the eCMD Dll
            // if left NULL, which DLL to load is determined by the ECMD_DLL_FILE environment variable
            // if set to a specific value, the specified DLL will be loaded
            l_rc = load_ecmd_dll();

            if (l_rc)
            {
                return l_rc;
            }

            // establish if this is a simulation run or not
            l_rc = ecmdQueryDllInfo(DLLINFO);

            if (l_rc)
            {
                return l_rc;
            }

            if (DLLINFO.dllEnv == ECMD_DLL_ENV_SIM)
            {
                GLOBAL_SIM_MODE = true;
            }


            // Let's always print the dll info to the screen, unless in quiet mode
            if (!is_in_quiet_mode())
            {
                // always print the DLL info to the screen, unless in quiet mode
                l_rc = ecmdDisplayDllInfo();

                if (l_rc)
                {
                    return l_rc;
                }
            }

            return l_rc;
        }

        ///
        /// @brief Parses ecmd specific command line options.
        /// @param io_argc is number of options on command line
        /// @param io_argv is a null delimeted array of command line options
        ///
        void  parse_ecmd_options(int io_argc, char** io_argv)
        {
            // run procedure in sim verification mode
            if (ecmdParseOption(&io_argc, &io_argv, "-verif"))
            {
                GLOBAL_VERIF_MODE = true;
            }
        }

    public:
        ///
        /// @brief Constructor
        /// @param o_rc is the return code for initialization
        /// @param io_argc is the number of args to pass to ecmd options parser
        /// @param io_argv is the null delimited char array of arguments
        ///
        ecmd_facade(uint64_t& o_rc, int io_argc = 0, char** io_argv = nullptr)
        {
            o_rc = initialize_ecmd();

            if(!o_rc && 0 != io_argc)
            {
                parse_ecmd_options(io_argc, io_argv);
            }
        }

        ///
        /// @brief determines if ecmd env varliable is set to quiet mode
        /// @return true if ecmd global var is set to quiet mode
        ///
        bool is_in_quiet_mode()
        {
            static auto l_is_in_quiet_mode = ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE);
            return l_is_in_quiet_mode;
        }

        ///
        /// @brief Destructor unloads the ecmd shared object library
        ///
        ~ecmd_facade()
        {
            if(iv_is_loaded)
            {
                ecmdUnloadDll();
            }
        }

};

} /* ns ecmd */
} /* ns mss */

#endif // MSS_ECMD_FACADE_H_
