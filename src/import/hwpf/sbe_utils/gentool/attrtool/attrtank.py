#!/usr/bin/env python3
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/hwpf/sbe_utils/gentool/attrtool/attrtank.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021,2023
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
import hashlib
import copy
from collections import namedtuple
import pickle

#attrtool library imports
from attrdb import *
import attrdatatype

###############################################################
# attrtool helper classess
#
# The attribute tank represents storage of SBE attributes
# in the PPE image and also in the PIBMEM. The classes in this
# file helps to set compile time values for the attribute. After
# parsing and validating attributes in attribute definition XML
# files, only those attributes listed in the SBE XML files are
# stored in the attribute tank.
#
# The python classes:
#   RealAttrFieldInfo    -   represents an attribute requiring
#                            memory in the attribute tank
#   EcAttrFieldInfo      -   does not occupy memory in the
#                            attribute tank. These are read only
#                            attributes
#   VirtualAttrFieldInfo -   SBE attributes with keyword virtual
#                            in the SBE XML. These attributes
#                            are also not stored in the attribute
#                            tank
#   AttributeStructure   -   represents a collection of SBE
#                            supported attributes.
#   SymbolTable          -   PPE image symbol files are parsed
#                            and stored in this class. This class
#                            provides the offset of the SBE
#                            attributes from the base of the
#                            attribute tank
###############################################################

class AttrFieldInfo(object):
    has_storage = False
    has_ec = False

    def __init__(self,
                 name: str,
                 hash: int,
                 ekb_target_type:list,
                 value_type: str,
                 enum_values: str = None,
                 writeable: bool = False,
                 platinit: bool = False) -> None:

        self.name = name
        self._hash = hash
        self.ekb_target_type = " | ".join(ekb_target_type)
        self.value_type = value_type + '_t'
        self.writeable = writeable
        self.platinit = platinit
        if enum_values is not None:
            self.enum_values = dict()
            elements = enum_values.text.split(",")
            if not elements[-1].strip():
                del elements[-1] # tolerate trailing comma
            for elem in elements:
                parts = elem.split("=")
                if len(parts) != 2:
                    raise ParseError("Attribute %s: Incorrect enum value syntax" % self.name)

                try:
                    name, value = (x.strip() for x in parts)
                    self.enum_values[name] = int(value, 0)
                except ValueError:
                    raise ParseError("Attribute %s: Invalid enum value '%s' for %s" % (self.name, value, name))
        else:
            self.enum_values = None

    def createDumpRecord(self, attr_list, image, image_base):
        raise NotImplementedError("Dumping this level attribute is not implemented")

    @property
    def hash(self) -> str:
        return hex(self._hash)

    @property
    def type_dims(self):
        return ""

    @property
    def dataType(self):
        return ""

    internal_dims = type_dims


class RealAttrFieldInfo(AttrFieldInfo):

    has_storage = True

    def __init__(self,
                 name: str,
                 hash: int,
                 sbe_target_type: str,
                 ekb_target_type: list,
                 value_type: str,
                 enum_values: str,
                 writeable: bool,
                 platinit: bool,
                 targ_entry : TargetEntry,
                 do_not_xmit_to_sbe : bool,
                 do_not_xmit_to_host: bool,
                 array_dims: list = []) -> None:
        super(RealAttrFieldInfo, self).__init__(
            name, hash, ekb_target_type, value_type, enum_values,
                    writeable, platinit)

        self.sbe_targ_type = sbe_target_type
        self.targ_entry = copy.deepcopy(targ_entry)
        self.array_dims = array_dims
        self.sbe_address = 0
        self.num_targ_inst = AttributeDB.TARGET_TYPES[sbe_target_type].ntargets
        self.do_not_xmit_to_sbe = do_not_xmit_to_sbe
        self.do_not_xmit_to_host= do_not_xmit_to_host
        try:
            self._type = attrdatatype.VALUE_TYPES[value_type.lower()]
        except KeyError:
            raise ParseError("Attribute %s: Unknown value type '%s'" % (self.name, self.value_type))

        if self.enum_values is not None:
            self._type = attrdatatype.EnumValueType(self._type, self.enum_values)

        for dim in reversed(self.array_dims):
            self._type = attrdatatype.ArrayValueType(self._type, dim)
        if(self.num_targ_inst > 1):
            self._type = attrdatatype.ArrayValueType(self._type, self.num_targ_inst, True)
        self.tot_size = self._type.size

    def set(self, image, image_base, value:list):
        try:
            self._type.set(image, self.sbe_address - image_base, value)
        except Exception as e:
            vprint("failed set " + self.name)
            vprint("value=" + str(value))
            vprint("typeofvalue=", type(value))
            vprint("dimension="+ str(self.array_dims))
            raise e

    def setfixed(self, image, image_base):
        vprint("Setting values for attribute", self.name, self.sbe_targ_type)

        values = []

        if(self.targ_entry.comm_values):
            values = self.targ_entry.values[0xFF] * self.num_targ_inst
        else:
            for i in range(self.num_targ_inst):
                values += self.targ_entry.values[i]

        vprint("values:", values)

        try:
            self._type.set(image, self.sbe_address - image_base, values)
        except Exception as e:
            vprint("failed set " + self.name)
            vprint("value=" + str(values))
            vprint("typeofvalue=", type(values))
            vprint("dimension="+ str(self.array_dims))
            raise e

    def set_value(self, image, image_base, value, instance, index:list):

        offset = self.sbe_address - image_base
        if(self.num_targ_inst > 1):
            index.insert(0, instance)
        try:
            if isinstance(self._type, attrdatatype.ArrayValueType):
                self._type.set_element_by_index(image, offset, value, index)
            else:
                self._type.set_element(image, offset, value)
        except Exception as e:
            vprint("failed set " + self.name)
            vprint("value=" + str(value))
            vprint("index= ", str(index))
            raise e

    def typestr(self):
        """
        # Function to get the attribute type in human readable format
        # TODO: Need to support enums also. (Not tested this yet)
        """
        return self.value_type + "".join("[%d]" % dim for dim in self.array_dims)

    def createDumpRecord(self, attr_list, image, image_base):
        partial_row = attrdatatype.DumpRecord(self.name, self.sbe_targ_type, '')
        dump_record_list = self._type.dump_record_row(
                                    image,
                                    self.sbe_address - image_base,
                                    partial_row)

        for dump_rec in dump_record_list:
            attr_list.append([dump_rec.name, dump_rec.targ, self.value_type, dump_rec.value])

        return attr_list

    def get(self, image, image_base):
        return self._type.get(image, self.sbe_address - image_base)

    @property
    def type_dims(self) -> str:
        retval = ""
        for dim in self.array_dims:
             retval += "[%d]" % dim
        return retval

    @property
    def internal_dims(self) -> str:
        retval = self.type_dims
        if self.num_targ_inst > 1:
            retval = "[%d]" % self.num_targ_inst + retval
        return retval

    def targ_inst(self, targ_var:str):
        inst_index = ""
        if self.num_targ_inst > 1:
            inst_index += "[" + targ_var + ".get()."
            if(self.sbe_targ_type == 'TARGET_TYPE_PERV'):
                inst_index += "getChipletNumber()"
            else:
                inst_index += "getTargetInstance()"
            inst_index += "]"
        return inst_index

    def inst_index(self, num_inst:int, targ_type:str, targ_var:str):
        inst_index = ""
        if num_inst > 1:
            inst_index += "[" + targ_var + ".get()."
            if(targ_type == 'TARGET_TYPE_PERV'):
                inst_index += "getChipletNumber()"
            else:
                inst_index += "getTargetInstance()"
            inst_index += "]"
        return inst_index

    @property
    def getter(self):
        return "ATTR::get_" + self.name + "(TARGET,VAL)"

    @property
    def setter(self):
        return "ATTR::set_" + self.name + "(TARGET,VAL)"

    @property
    def first_attribute(self):
        return (self.ekb_target_type != '')

    @property
    def support_composite_target(self):
        if(self.ekb_target_type == ''):
            return False

        targ_list = self.ekb_target_type.split('|')
        if(len(targ_list) == 1):
            return False

        return True

    @property
    def ekb_target_list(self) -> list:
        ekb_target_list = []

        if(self.ekb_target_type == ''):
            return ekb_target_list

        targ_list = self.ekb_target_type.split('|')

        for targ in targ_list:
            ekb_target_list.append(targ.strip())

        return ekb_target_list

    @property
    def ekb_full_target(self):
        comp_target = ''

        targ_list = self.ekb_target_type.split('|')
        for targ in targ_list:
            if(comp_target != ''):
                comp_target += ' | '
            comp_target += "fapi2::" + targ.strip()

        return comp_target

    def gen_attr_table(self) -> str:
        retval = ""

        retval += "{"
        #AttributeId
        retval += self.name

        #Not an array attribute
        if ( len(self.array_dims) == 0 ):
            retval += ",0,0,0"
        else:
            #Array attribute
            #cooridnates
            for dim in self.array_dims:
                retval += "," + str(dim)

            #AttributesTable supports a max of three subscripts
            #ie. x, y, and z to locate an attribute; If
            #this attribute requires only 2 subscripts(ie. x and
            # y), then fill the remaining subscript with 1
            for i in range(3 - len(self.array_dims)):
                retval += ",1"

        #size
        retval += ",sizeof(" + self.value_type + ")"

        #address where the attribute is stored
        retval += ",&" + self.sbe_targ_type + "::" + self.name
        retval += "},\n"

        return retval

class VirtualAttrFieldInfo(AttrFieldInfo):
    VIRTUAL_FUNCTION = {
        "ATTR_NAME": "_getAttrName",
        "ATTR_EC": "_getAttrEC",
        "ATTR_CHIP_UNIT_POS": "_getAttrChipUnitPos",
        "ATTR_REL_POS": "_getAttrRelPos"
    }

    def __init__(self,
                 name: str,
                 hash: int,
                 ekb_target_type: list,
                 value_type: str,
                 enum_values: str) -> None:
        super().__init__(name, hash, ekb_target_type, value_type, enum_values)

    def set(self, image, image_base, value):
        raise NotImplementedError("Cannot modify a virtual attribute")

    def set_value(self, image, image_base, value, target, index=0):
        raise NotImplementedError("Cannot modify value for virtual attribute")

    def get(self, image, image_base):
        raise NotImplementedError("Querying virtual attributes is not implemented")

    @property
    def getter(self):
        return self.VIRTUAL_FUNCTION[self.name] + "(TARGET, VAL)"

class EcAttrFieldInfo(AttrFieldInfo):
    has_ec = True

    def __init__(self,
                 name: str,
                 hash: int,
                 ekb_target_type: list,
                 value_type: str,
                 chip_name: str,
                 ec_value: str,
                 ec_test: str) -> None:

        super().__init__(name, hash, ekb_target_type, value_type)
        self.chip_name = chip_name
        self.ec_value = ec_value
        self.ec_test = ec_test

    def set(self, image, image_base, value):
        raise NotImplementedError("Cannot modify an EC level attribute")

    def get(self, image, image_base):
        raise NotImplementedError("Querying EC level attributes is not implemented")

    def set_value(self, image, image_base, value, target, index=0):
        raise NotImplementedError("Cannot modify value for EC level attribute")

    @property
    def getter(self):
        return "queryChipEcFeature(fapi2::int2Type<ID>(), TARGET, VAL)"


class AttributeStructure(object):

    def __init__(self, db: AttributeDB) -> None:
        # Using list, since we need same order while iterating
        self.field_list: list["AttrFieldInfo"] = []
        self.hash_set : set[int] = set()
        self.target_types : 'dict[str, TargetTypeInfo]' = dict()

        self.target_types = copy.deepcopy(AttributeDB.TARGET_TYPES)
        for attr in db.attributes.values():
            if (not attr.sbe_entry) or (attr.sbe_entry is None):
                continue
            vprint("Finalizing sbe fields for attribute: " + attr.name)

            attr_hash16bytes = hashlib.md5(attr.name.encode()).digest()
            attr_hash32bits = int.from_bytes(attr_hash16bytes[0:4], "big")
            attr_hash28bit = attr_hash32bits >> 4;
            if attr_hash28bit in self.hash_set:
                raise ParseError("Hash for attribute " + attr.name +
                        " already used")
            else:
                self.hash_set.add(attr_hash28bit)

            if isinstance(attr, ECAttribute):
                self.field_list.append(EcAttrFieldInfo(
                    attr.name,
                    attr_hash28bit,
                    attr.ekb_target_type,
                    attr.value_type,
                    attr.chip_name,
                    attr.ec_value,
                    attr.ec_test))
            elif attr.sbe_entry.virtual:
                self.field_list.append(VirtualAttrFieldInfo(
                    attr.name,
                    attr_hash28bit,
                    attr.ekb_target_type,
                    attr.value_type,
                    attr.enum_values))
            else:
                ekb_target_list = attr.ekb_target_type
                for sbe_targ in attr.sbe_target_type:
                    targ_entry = attr.sbe_entry.get_target_entry(sbe_targ)
                    if(targ_entry == None):
                        raise Exception("Invalid target entry list for attribute %s for target %s" % {attr.name, sbe_targ})
                    self.field_list.append(RealAttrFieldInfo(
                        attr.name,
                        attr_hash28bit,
                        sbe_targ,
                        ekb_target_list,
                        attr.value_type,
                        attr.enum_values,
                        attr.writeable,
                        attr.platinit,
                        targ_entry,
                        attr.do_not_xmit_to_sbe,
                        attr.do_not_xmit_to_host,
                        attr.array_dims))

                    # ekb_target_type is only required for the attribute structure of the first target
                    ekb_target_list = []

    ##################################################################
    #
    #   Description : Function to calculate the buffer size required
    #                 for attribute update
    #
    ##################################################################

    def calBufSize(self) -> int:

        # Attribute update header size is 4 bytes
        total_buf_size = 4
        for target_type in self.target_types.keys():
            # target header size is 4 bytes
            target_section_size = 4
            attributes = [attr for attr in self.field_list \
                                    if attr.has_storage and \
                                       attr.sbe_targ_type == target_type  and \
                                       attr.do_not_xmit_to_sbe == False]
            for attr in attributes:
                # The actual size of the attribute row :
                #       The size of the attribute id   = 4 bytes +
                #       The number of bytes to specify
                #           attribute data size        = 2 bytes +
                #       The number of bytes used to
                #           specify the co-ordinates
                #           row,col,hgt,1 byte reserved= 4 bytes +
                #       The number of bytes to store actual data size

                attr_actual_data_size = 10 + attr.tot_size
                attr_aligned_data_size= (attr_actual_data_size+7) & (~7)

                target_section_size  += attr_aligned_data_size

            # A target may have more than one instance; So, for the total size of
            # the target section, multiply the actual size by the number of instances
            target_section_size *= self.target_types[target_type].ntargets
            total_buf_size += target_section_size

        return total_buf_size

class SymbolTable(object):

    Symbol = namedtuple("Symbol", "name type offset size")

    def __init__(self, fname):
        self.symbols = dict()
        with open(fname, "r") as symtab:
            for line in symtab:
                parts = line.strip().split()
                size = None
                if len(parts) == 4:
                    size = int(parts[1], 16)
                    del parts[1]
                if len(parts) == 3:
                    # Collect only attribute variables, and remove fapi2::ATTR::
                    if parts[2].startswith("fapi2::ATTR::"):
                        attr_name = parts[2][13:]
                        self.symbols[attr_name] = self.Symbol(attr_name, parts[1], int(parts[0], 16), size)
                    else:
                        self.symbols[parts[2]] = self.Symbol(parts[2], parts[1], int(parts[0], 16), size)

    def update_attrdb(self, attr_tank:AttributeStructure):
        attr_tank.image_base = self.symbols["__vectors"].offset
        attr_tank.start_address = self.symbols["_attrs_start_"].offset
        attr_tank.end_address = self.symbols["_attrs_end_"].offset
        for attr in attr_tank.field_list:
            if not isinstance(attr, RealAttrFieldInfo):
                continue

            qual_attr_name = attr.sbe_targ_type + "::" +attr.name

            if qual_attr_name in self.symbols:
                attr.sbe_address = self.symbols[qual_attr_name].offset
            else:
                raise ParseError("Address is not present in symbol file for "
                                    +attr.name + " for the target " +
                                    attr.sbe_targ_type)
