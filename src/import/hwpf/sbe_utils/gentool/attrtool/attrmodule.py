# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/hwpf/sbe_utils/gentool/attrtool/attrmodule.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2022,2023
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

#attrtool library imports
from attrdb import *
from attrtank import *
from attrtoolutils import *

def set_attr(i_attrDb:AttributeStructure, io_image:bytearray, i_attr:str,\
                i_value:int, i_target:str, i_index:list, i_instance:int)->bytearray:
    attr_to_set = None
    for attr in i_attrDb.field_list:
        if not isinstance(attr, RealAttrFieldInfo):
            continue
        if((attr.name == i_attr.upper()) and (attr.sbe_targ_type == i_target)) :
            attr_to_set = attr
            break

    if attr_to_set is None :
        raise ArgumentError("Unknown attribute: " + i_attr+ "[" + i_target + "]")

    #Default is to initialize all the instances
    instance = 0xFF
    if (i_instance is not None):
        instance = int(i_instance)
    if(instance != 0xFF):
        attr_to_set.set_value(io_image, i_attrDb.image_base, i_value, instance, i_index)
    else:
        for i in range(attr_to_set.num_targ_inst):
            attr_to_set.set_value(io_image, i_attrDb.image_base, i_value, i, i_index)
    return io_image

def get_attr(i_attrDb:AttributeStructure, i_attr, i_image:bytearray)->list:
    attr_found = None
    for attr in  i_attrDb.field_list:
        if attr.name == i_attr.upper():
            attr_found = attr
            break
    if attr_found is None:
        raise ArgumentError("Attribute {} is not present".format(i_attr))
    value = attr_found.get(i_image, i_attrDb.image_base)
    return attr_found

def dump_attr(
            i_attrDb:AttributeStructure, i_image:bytearray, i_raw:str)->list:
    if i_raw =='True':
        image_base = i_attrDb.start_address
    else:
        image_base = i_attrDb.image_base
    attr_list = []
    for attr in i_attrDb.field_list:
        if isinstance(attr, RealAttrFieldInfo):
            attr.createDumpRecord(attr_list, i_image, image_base)
    return attr_list
