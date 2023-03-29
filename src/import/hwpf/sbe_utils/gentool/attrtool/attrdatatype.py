# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/hwpf/sbe_utils/gentool/attrtool/attrdatatype.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2023
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
#standard library imports
import struct
from typing import NamedTuple

#attrtool library imports
from attrtoolutils import *

class ArgumentError(Exception):
    def __init__(self, message="Argument Exception occured"):
        self.message = "Argument Error :\n"+message
        super().__init__(self.message)

class DumpRecord(NamedTuple):
    name:str
    targ:str
    value:str

class AttrIntValueType(object):
    def __init__(self, typestr:str):
        self._type = typestr
        self.size = struct.calcsize(typestr)

    def get(self, image:bytearray, offset:int) -> int:
        return struct.unpack_from(self._type, image, offset)[0]

    def valuestr(self, image:bytearray, offset:int) -> str:
        return "0x%x" % struct.unpack_from(self._type, image, offset)[0]

    def dump_record_row(self,
                        image:bytearray, offset:int,
                        partial_row:DumpRecord) -> 'list[DumpRecord]':

        value = "0x%x" % self.get(image, offset)
        return [DumpRecord(partial_row.name, partial_row.targ, value)]

    def set(self, image:bytearray, offset:int, value:list):
        if (len(value) != 1):
            raise ValueError("Invalid array attribute value - expected len=1, but len=%d" % (len(value)))
        struct.pack_into(self._type, image, offset, value[0])

    def set_element(self, image:bytearray, offset:int, value:int):
        struct.pack_into(self._type, image, offset, value)


VALUE_TYPES = {
    "int8":   AttrIntValueType(">b"),
    "uint8":  AttrIntValueType(">B"),
    "int16":  AttrIntValueType(">h"),
    "uint16": AttrIntValueType(">H"),
    "int32":  AttrIntValueType(">i"),
    "uint32": AttrIntValueType(">I"),
    "int64":  AttrIntValueType(">q"),
    "uint64": AttrIntValueType(">Q"),
}


class EnumValueType(object):
    def __init__(self, base_type:AttrIntValueType, enum_values:dict):
        self._base = base_type
        self._values = enum_values
        self._inverse = {v: k for k, v in enum_values.items()}
        self.size = base_type.size

    def get(self, image:bytearray, offset:int):
        value = self._base.get(image, offset)
        try:
            return self._inverse[value]
        except KeyError:
            return value

    def dump_record_row(self,
                        image:bytearray, offset:int,
                        partial_row:DumpRecord) -> 'list[DumpRecord]':

        value = str(self.get(image, offset)) + \
                "("+str(self._base.get(image, offset))+")"
        return [DumpRecord(partial_row.name, partial_row.targ, value)]

    def set(self, image:bytearray, offset:int, value:list):
        if isinstance(value, str):
            self._base.set_element(image, offset, self._values[value[0]])
        else:
            self._base.set_element(image, offset, value[0])

    def set_element(self, image:bytearray, offset:int, value:'int|str'):
        if isinstance(value, str):
            if value in self._values:
                self._base.set_element(image, offset, self._values[value])
            else:
                raise ArgumentError('Value is not an enum')
        else:
            if value in self._values.values():
                self._base.set_element(image, offset, value)
            else:
                raise ArgumentError('Integer value passed does not map to any\
 enum')

class ArrayValueType(object):
    def __init__(self, base_type:AttrIntValueType, dim:int, is_targ_dim:bool = False):
        self._base = base_type
        self._dim = dim
        self.size = base_type.size * dim
        self._is_targ_dim = is_targ_dim

    def get(self, image:bytearray, offset:int) -> list:
        return [self._base.get(image, offset + self._base.size * i) for i in \
                range(self._dim)]

    def dump_record_row(self,
                        image:bytearray, offset:int,
                        partial_row:DumpRecord) -> 'list[DumpRecord]':

        ret_list:list[DumpRecord] = []
        for i in range(self._dim):
            if(self._is_targ_dim):
                targ_append = "[" + str(i) + "]"
                name_append = ""
            else:
                name_append = "[" + str(i) + "]"
                targ_append = ""

            new_partial_row = DumpRecord(
                partial_row.name + name_append, partial_row.targ + targ_append, '')

            ret_list += self._base.dump_record_row(image,
                                    offset + self._base.size * i,
                                    new_partial_row)

        return ret_list

    def set_element(self, image:bytearray, offset:int, value:int):
        self._base.set_element(image, offset, value)

    def set_element_by_index(
        self, image:bytearray, base_offset:int, value:int, index:list, cur_dim:int=0):

        if(len(index) == 0):
            raise ArgumentError("Expected index")
        if(index[0] >= self._dim):
            vprint("index (%d) at dimension %d, is out of range (%d)"
                    %(index[0], cur_dim, self._dim))
            raise ArgumentError("Index(%d) out of range(%d)" % (index[0],self._dim))
        base_offset = base_offset + index[0] * self._base.size
        if(isinstance(self._base, ArrayValueType)):
            return self._base.set_element_by_index(
                image, base_offset, value, index[1:], cur_dim + 1)
        else:
            # this the 0th dimension
            assert (len(index) == 1), "more dimension than expected"
            return self.set_element(image, base_offset, value)

    def set(self, image:bytearray, offset:int, value:list):
        if (len(value) % self._dim != 0):
            raise ValueError(
                "Invalid array attribute value - array dim %d, value dim %d" %
                (self._dim, len(value)))

        sub_list_len = int(len(value) / self._dim)
        for i in range(self._dim):
            sub_list = [value[j] for j in range(i * sub_list_len, (i + 1) * sub_list_len)]
            self._base.set(image, offset + self._base.size * i, sub_list)
