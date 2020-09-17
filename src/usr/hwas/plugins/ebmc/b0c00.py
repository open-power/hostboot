# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwas/plugins/ebmc/b0c00.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG
import json
from udparsers.helpers.errludP_Helpers import hexDump, intConcat
from udparsers.helpers.vpdConstants import createPGV, VPD_CP00_PG_DATA_ENTRIES

class errludP_pgData:

    def UdParserPartialGoodIssue(ver, data):
        d = dict()
        subd = dict()
        i = 0

        #Our local copy of the AG vector, which we will update with
        #the model-specific AG values as we extract them below. We
        #then take this AGV and compare it against the PG values we
        #extract, to see which ones differ.
        pgDataAG = createPGV()

        outputArray = []

        if ver > 1:
            d['HWAS PG FFDC']= 'Unknown Version (too new)'
            d['Hex Dump']=hexDump(data, 0, len(data))
        else:
            #Extract the model-specific AG values and put them into
            #pgDataAG at their proper locations
            num_ag_entries,  i= intConcat(data, i, i+4)
            for x in range(num_ag_entries):
                model_ag_index, i=intConcat(data, i, i+4)
                model_ag_value, i=hexConcat(data, i, i+4)

                if model_ag_index < VPD_CP00_PG_DATA_ENTRIES:
                    pgDataAG[model_ag_index]=model_ag_value
                else:
                    subd['Error']=( 'Model-specific AG value out of bounds: [' +
                                                                model_ag_index +
                                                                        '] = ' +
                                                                model_ag_value )

            #Extract the PG values and compare them against our AG vector
            num_pg_entries, i=intConcat(data, i, i+4)
            if num_pg_entries != VPD_CP00_PG_DATA_ENTRIES:
                subd['Error']=( 'Expected ' + VPD_CP00_PG_DATA_ENTRIES +
                                                   ' PG entries, got ' +
                                                        num_pg_entries )
            else:
                for x in range(VPD_CP00_PG_DATA_ENTRIES):
                    pgValue, i=intConcat(data, i, i+4)
                    if pgValue != pgDataAG[x]:
                        outputArray.append({'Bad': 'pgData[' + str(x) + '] = 0x' +
                                                              f'{pgValue:08x}; ' +
                                                                   'expected 0x' +
                                                            f'{pgDataAG[x]:08x}'})
                    else:
                        outputArray.append({'': 'pgData[' + str(x) + '] = 0x' +
                                                           f'{pgValue:08x}; ' +
                                                                'expected 0x' +
                                                         f'{pgDataAG[x]:08x}'})
            d['HWAS PG FFDC'] = outputArray

        jsonStr = json.dumps(d)
        return jsonStr

#Dictionary with parser functions for each subtype
#Values are from HwasPlatUserDetailsTypes in src/include/usr/hwas/common/hwas_reasoncodes.H
HwasPlatUserDetailsTypes = { 2: "UdParserPartialGoodIssue" }

def parseUDToJson(subType, ver, data):
    args = (ver, data)
    return getattr(errludP_pgData, HwasPlatUserDetailsTypes[subType])(*args)
