/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utilxipimage.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

#include <string.h>
#include <util/utilxipimage.H>

//Procedures
#include <p9_xip_image.h>

namespace Util
{
    void pullTraceBuildInfo(void* i_imagePtr,
                            imageBuild_t& o_imageBuild,
                            trace_desc_t* i_traceDesc)
    {
        // Pull build information from XIP header
        P9XipHeader* l_xipHeader = reinterpret_cast<P9XipHeader *>(i_imagePtr);

        o_imageBuild.buildDate = l_xipHeader->iv_buildDate;
        o_imageBuild.buildTime = l_xipHeader->iv_buildTime;
        memcpy(o_imageBuild.buildTag,
               l_xipHeader->iv_buildTag,
               sizeof(o_imageBuild.buildTag) );

        // Trace build information if trace parameter supplied
        if(i_traceDesc != nullptr)
        {
            TRACFCOMP(i_traceDesc, "pullTraceBuildInfo: image build date "
                      "= %8d, build time = %04d, build tag = %-.20s",
                      o_imageBuild.buildDate,
                      o_imageBuild.buildTime,
                      o_imageBuild.buildTag);
        }
    }
}