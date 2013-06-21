/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errldisplay/errldisplay.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
/* [+] Google Inc.                                                        */
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
#ifndef ERRLDISPLAY_H
#define ERRLDISPLAY_H
/**
 *  @file src/include/usr/errldisplay/errldisplay.H
 *
 *  @brief  Error Log display for Host Boot environment
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <config.h>
#include <errl/errlentry.H>

namespace ERRORLOGDISPLAY
{

/*****************************************************************************/
// Forward class declarations
/*****************************************************************************/

class ErrLogDisplay;

/**
 *  @brief Returns a reference to the error log display singleton
 *
 *  @return Reference to the error log display
 */
ErrLogDisplay& errLogDisplay();

/**
 *  @brief  Error log display module
 *  This class provides a log dump function for host boot.
 */
class ErrLogDisplay
{

public:

    /**
     * @struct errLogInfo
     *
     * Structure that holds human-readable strings describing errors
     */
    struct errLogInfo
    {
        uint8_t moduleId;
        uint16_t reasonCode;
        const char * descriptString;
        const char * moduleName;
        const char * reasonString;
        const char * userData1String;
        const char * userData2String;
    };

    /**
     * @struct compTableInfo
     *
     * Structure that holds human readable strings for component IDs.
     */
    struct compTableInfo
    {
        const compId_t value;
        const char * name;
    };

    // Sort function to compare errLogInfo structs
    static bool errorLogInfoCompare(const errLogInfo e1, const errLogInfo e2)
    {
        if (e1.moduleId == e2.moduleId)
        {
            return (e1.reasonCode < e2.reasonCode);
        }
        return (e1.moduleId < e2.moduleId);
    }

    // Sort function to compare compTableInfo structs
    static bool compTableCompare(const compTableInfo c1, const compTableInfo c2)
    {
        return (c1.value < c2.value);
    }

    /**
     *  @brief Display a human-readable error log entry.
     *
     *  @param[in] i_err                Error log handle to be displayed
     *  @param[in] i_committerComp      The id of the component that is
     *                                  committing this error log entry
     *
     *  @return None
     */
    static void msgDisplay (const errlHndl_t &i_err, compId_t i_committerComp);

    /**
     *  @brief Initialization for the error log display function.
     *  This registers with the core error logging to provide human-readable
     *  output for errors.
     */
    errlHndl_t init();

private:

    // Auto-generated data tables that hold error information.
    static errLogInfo errorInfo [];
    static uint16_t errorInfoTableSize;
    static compTableInfo compTable [];
    static uint16_t compTableSize;

    /**
     * @brief Find the error log info struture that corresponds to the given
     * module ID & reason code.
     *
     * @param[in] moduleId    The id of the module which errored.
     * @param[in] reasonCode  The reason of the error.
     *
     * @return the error log info stucture that matches the module/reason code.
     * or NULL, if there is no structure found.
     */
    static const errLogInfo* findErrLogInfo (uint8_t i_moduleId,
                                             uint16_t i_reasonCode);

    /**
     * @brief Find the component name that corresponds to the given ID.
     *
     * @param[in] compId     The id of the component to be identified.
     *
     * @return a string with the name of the component, or "unknown" if the
     * module name is not found.
     */
    static const char * findComponentName (compId_t i_compId);

};

} // End namespace

#endif //ERRLDISPLAY_H
