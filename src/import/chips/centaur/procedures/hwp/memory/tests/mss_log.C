/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/tests/mss_log.C $ */
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
/// @file mss_log.C
/// @brief Imlpementation for mss logging functions
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 4
// *HWP Consumed by: CI


#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <stdarg.h>
#include <unistd.h>
#include <fapi2.H>
#include <mss_log.H>
#include <croClientCapi.H>


namespace mss
{

///
/// @brief Retrieves the env var and return as std::string
/// @param[in] i_env_name Environment Var Name to retrieve
/// @return std::string representing the env string
///
static std::string get_env(const char* i_env_name)
{
    auto l_env_str = ::getenv(i_env_name);
    return((nullptr == l_env_str) ? "" : l_env_str);
}



///
/// @brief Retrieves the string representation of the logging level
/// @param[in] i_level log level to retrieve
/// @return C String representing the log level
///
static const char* log_level_str(const logging_level i_level)
{
    switch(i_level)
    {
        case TRACE:
            return "TRC";
            break;

        case DEBUG:
            return "DBG";
            break;

        case INFO:
            return "INF";
            break;

        case WARN:
            return "WRN";
            break;

        case ERROR:
            return "ERR";
            break;

        case FATAL:
            return "FTL";
            break;
    }

    return "UNK";
}

///
/// @struct logger
/// @brief This structure represents a physical logging instance.
///  It is responsible for opening and closing the database
///
struct logger
{
    /// When true will log to a file
    ///  TK: Not actually writing log until we have stuff to write
    bool iv_do_file_logging = false;

    /// When true will log to the cosoole
    bool iv_do_console_logging = true;

    ///
    /// @brief determines logging file
    /// @return filename only of log file
    ///
    std::string get_filename()
    {
        //See if an environment variable is trying to override logging
        //filename.
        std::string l_filename(get_env("MSS_LOG_FILENAME"));

        if(l_filename.empty())
        {
            //Build the filename
            std::ostringstream l_fn_strm;

            //Add Login name to filename
            l_fn_strm << getlogin() << "_";

            //Get current date/time to add to filename
            std::time_t l_now_time = std::time(nullptr);
            auto l_gm_time = gmtime(&l_now_time);
            l_fn_strm << std::setfill('0')
                      << std::setw(2) << l_gm_time->tm_hour
                      << std::setw(2) << l_gm_time->tm_min
                      << std::setw(2) << l_gm_time->tm_sec << "_"
                      << std::setw(2) << l_gm_time->tm_mon + 1
                      << std::setw(2) << l_gm_time->tm_mday
                      << l_gm_time->tm_year + 1900 << "_";

            //Get UUID from the kernel to add to filename to make it unique
            std::ifstream l_uuid_fn("/proc/sys/kernel/random/uuid");
            l_fn_strm << std::string((std::istreambuf_iterator<char>(l_uuid_fn)),
                                     std::istreambuf_iterator<char>());
            l_filename = l_fn_strm.str();
        }

        return l_filename;
    }

    ///
    /// @brief determing the path for the logging file
    /// @return the full path to the log file.
    ///
    std::string get_log_file_path()
    {
        //See if an environment variable is trying to override logging
        //filename.
        std::string l_log_path(get_env("MSS_LOG_PATH"));

        if(l_log_path.empty())
        {
            l_log_path = "/gsa/ausgsa/projects/m/mss_lab/logs/";
        }

        return l_log_path;
    }

    /// @brief Determine logging targets
    void determine_logging_targets()
    {
        //This is a mechanism to overide default output targets
        // by default logging goes to file and console.
        std::string l_log_targets = get_env("MSS_LOG_OUTPUT_TARGETS");

        //If someone has set this env varliable we need to honour it
        if(!l_log_targets.empty())
        {

            //Setting File Logging flag
            iv_do_file_logging =
                (std::string::npos != l_log_targets.find("FILE"));

            //Setting Console Logging flag
            iv_do_console_logging =
                (std::string::npos != l_log_targets.find("CONSOLE"));
        }
    }

    ///
    /// @brief Constructor. Initializes the database and redies it for
    ///   logging
    ///
    logger()
    {
        //Determines what our logging targets are.
        determine_logging_targets();

        if(iv_do_file_logging)
        {
            std::string l_log_file = get_env("MSS_LOG_FQFN"); //":memory:"

            //Get Log File Path
            l_log_file = get_log_file_path();

            //Get Log Filename and combine to get the fqfn
            l_log_file.append(get_filename());

            std::cout << "Using log file path: " << l_log_file << std::endl;
        }

        if(iv_do_console_logging)
        {
            // needed for croIsDebugOn checks for message display threshold
            croInitExtension();
        }
    }

    ///
    /// @brief Destructor
    ///
    ~logger()
    {
    }

    ///
    /// @brief writes a message to the logging database
    /// @param[in] i_level logging level to write
    /// @param[in] i_msg message to log
    ///
    void write(const logging_level i_level, const char* i_msg)
    {
        struct timespec l_ts;
        clock_gettime(CLOCK_REALTIME, &l_ts);
        auto l_gm_time = gmtime(&l_ts.tv_sec);

        // Write out log message to console if console logging is enabled
        if(iv_do_console_logging)
        {
            // Check Cronus debug6 flag to conditionally display INFO
            // and DEBUG messages
            bool l_log_to_console = true;

            switch (i_level)
            {
                case INFO:
                    l_log_to_console = croIsDebugOn('6', 'I');
                    break;

                case DEBUG:
                    l_log_to_console = croIsDebugOn('6', 'D');
                    break;

                default:
                    l_log_to_console = true;
            }

            if (l_log_to_console)
            {
                std::cout << std::setfill('0')
                          << l_gm_time->tm_year + 1900 << "-"
                          << std::setw(2) << l_gm_time->tm_mon + 1 << "-"
                          << std::setw(2) << l_gm_time->tm_mday << "T"
                          << std::setw(2) << l_gm_time->tm_hour << ":"
                          << std::setw(2) << l_gm_time->tm_min << ":"
                          << std::setw(2) << l_gm_time->tm_sec << "."
                          << std::setw(9) << l_ts.tv_nsec << ","
                          << "[" << log_level_str(i_level) << "]:"
                          << i_msg << std::endl;
            }
        }

        if(FATAL == i_level)
        {
            // exit will properly perform ecmd cleanup before termination
            // due to ecmdUnloadDll being in std::atexit stack
            exit(-1);
        }
    }
};

///
/// @brief Returns logger
/// @note This function could be expanded to retrieve diffent logging
///   destinations.
/// @returns the default logger to use.
///
static logger& get_logger()
{
    ///This ensures we only have one instance of this logger
    static logger l_logger;
    return l_logger;
}

///
/// @brief Log a string to the mss log logging system
/// @param[in] i_level Level to log messages
/// @param[in] i_msg message to log.
///
void log(const logging_level i_level, const std::string& i_msg)
{
    auto l_logger = get_logger();
    l_logger.write(i_level, i_msg.c_str());
}

///
/// @brief Log a string to the mss log logging system
/// @param[in] i_level Level to log messages
/// @param[in] i_format_str is the string format @note see printf
/// @param[in] ... variable list of args to be written out
///
void logf(const logging_level i_level, const char* i_format_str, ...)
{
    //Get logger instance
    auto l_logger = get_logger();

    va_list l_args;
    va_start (l_args, i_format_str);
    const auto l_init_sizeof_string(200);

    //Initial buffer
    char l_ostr[l_init_sizeof_string] = {0};

    //write log message to buffer
    auto l_written = vsnprintf(l_ostr, l_init_sizeof_string, i_format_str, l_args);
    va_end (l_args);

    //Check to see if there was enough buffer to write all of command
    if(l_written > l_init_sizeof_string - 1)
    {
        //Need to allocate a bigger buffer
        const auto l_new_buffer_size = l_written + 1;
        //TK: When we go to c++14 support this should be changed to std::make_unique
        std::unique_ptr<char[]> l_ostr_longer(new char[ l_new_buffer_size ]);
        l_ostr_longer.get()[0] = '\0';

        //write log message to longer buffer
        va_start (l_args, i_format_str);
        l_written = vsnprintf(l_ostr_longer.get(), l_new_buffer_size, i_format_str, l_args);
        va_end (l_args);

        //Log the message
        l_logger.write(i_level, l_ostr_longer.get());
    }
    else
    {
        //Log the message
        l_logger.write(i_level, l_ostr);
    }
}


} /* ns mss */
