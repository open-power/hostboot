#!/usr/bin/env python3
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/hwpf/sbe_utils/gentool/attrtool/attrdb.py $
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

from xml.dom.minidom import Element
import xml.etree.ElementTree as etree
from textwrap import dedent
from collections import namedtuple
import json
import copy

#attrltool library imports
from attrtoolutils import *
import attrdatatype

###############################################################
# attrtool helper classess
#
# The attribute definition XML files are parsed and stored in
# attrdb. As SBE is memonry constrained, not all the attributes
# defined are supported. For an attribute to be supported by,
# SBE, it must be listed in the SBE attribute XML files which
# are called as filter XML in SBE parlance.
#
# The python classes:
#   RealAttribute - represents an attribute element in the
#                   attribute definition XML.
#   ECAttribute   - attribute element having a child element
#                   called chipEcFeature
#   AttributeDB   - represents a collection of all attributes
#                   both RealAttribute and ECAttribute
#   SBEAttributes - represents a collection of all SBE supported
#                   attributes
#   SBEnry        - represents an attribute supported by SBE
#   TargetEntry   - represents a child of SBE attribute to
#                   provide values for compile time initialization
###############################################################

TargetTypeInfo = namedtuple("TargetTypeInfo", "ntargets")

def targetTypeInfoLoader(**kwarg : dict):
    if '__targInfo__' in kwarg:
        return TargetTypeInfo(kwarg['ntargets'])
    return kwarg

class ParseError(Exception):
    pass

class RealAttribute(object):
    """
    Class to parse attribute from XML which need a real storage location
    """

    class SbeAttrSync(object):
        '''
        class to parse sbeAttrSync tag
        '''
        def __init__(self, sync_node:Element, i_ekb_targets:'list[str]') -> None:
            self.to_sbe :bool = (sync_node.attrib.get("toSBE") == "1")
            self.from_sbe :bool = (sync_node.attrib.get("fromSBE") == "1")

            _chip_types :str = sync_node.attrib.get("chipTypes")
            self.chip_types :list[str] = _chip_types.split(',')

            _target_types :str = sync_node.find("targetTypes").text
            self.target_types :list[str] = [targ.strip().upper() for targ in _target_types.split(',')]

            if(not (self.to_sbe or self.from_sbe)):
                raise ParseError("sbeAttrSync doesn't enabling either to_sbe nor from_sbe")

            if(not set(self.target_types).issubset(set(i_ekb_targets))):
                raise ParseError("sbeAttrSync has target types not supported for this attribute")


    def __init__(self, db:"AttributeDB", node:Element):
        self.db = db
        self.sbe_entry:"SBEEntry" = None
        self.attr_sync = None
        self.unsupported_attribute = False

        name, target_type, value_type, description, enum_values, array_dims, attr_sync = (
            node.find(tag) for tag in ("id", "targetType", "valueType", "description", "enum", "array", "sbeAttrSync"))

        if name is None:
            raise ParseError("Unnamed attribute")
        self.name = name.text

        if target_type is None or value_type is None:
            raise ParseError("Attribute %s is missing a target type or value type" % self.name)
        self.target_type = target_type.text
        self.value_type = value_type.text

        target_type_str_list = [targ.strip().upper() for targ in self.target_type.split(',')]
        self.sbe_target_type:list[str] = []
        # workaround to support POZ_ANY_CHIP attributes
        self.ekb_target_type:list[str] = []

        for targ in target_type_str_list:
            targ_type = AttributeDB.TARGET_TYPES.get(targ, None)
            if targ_type != None:
                self.sbe_target_type.append(targ)
            self.ekb_target_type.append(targ)

        if(attr_sync != None):
            try:
                self.attr_sync = RealAttribute.SbeAttrSync(attr_sync, self.sbe_target_type)
            except ParseError as e:
                raise ParseError("SbeAttrSync parsing failed for " + self.name) from e


        if (len(self.sbe_target_type) == 0) and (self.attr_sync == None):
            self.unsupported_attribute = True
            return

        self.description = dedent(description.text.strip("\n")) if description else None

        self.enum_values = enum_values

        if array_dims is None:
            self.array_dims = []
        else:
            # TODO: Be strict about commas
            self.array_dims = [int(dim, 0) for dim in array_dims.text.replace(",", " ").split()]

        self.tot_size = attrdatatype.VALUE_TYPES[self.value_type.lower()].size
        for dim in self.array_dims:
            self.tot_size *= dim

        if node.find("writeable") != None:
            self.writeable = True
        else:
            self.writeable = False
            if(self.attr_sync != None):
                # 1. Since it's a read-only attribute, we expect no change in this value in the SBE after
                #    the attribute push.
                # 2. And, the HWP will apply the value to the host by calling FAPI_ATTR_SET, but this macro
                #    will not be available for read-only attributes.
                assert (self.attr_sync.from_sbe == False), "fromSBE is set for read-only attribute " + self.name

        if node.find("platInit") != None:
            self.platinit = True
        else:
            self.platinit = False

        # TODO: Support tags <default> and <initToZero/>

    def fromSbeSync(self, i_chip_type, i_target) -> None :
        return ((self.attr_sync != None) and
            (i_chip_type in self.attr_sync.chip_types) and
            (i_target in self.attr_sync.target_types) and
            (self.attr_sync.from_sbe))

    def validate_and_return_sbe_attribute(self, sbe_value:"SBEEntry") -> "SBEEntry":
        if sbe_value != None:
            vprint("Validating attribute: " + self.name)

            if self.unsupported_attribute == True:
                raise ParseError(self.name + " have no supported targets")

            if ((self.writeable == True) and (sbe_value.virtual == True)):
                raise ParseError(self.name + " is writeable but virtual")

            array_size = 1
            for dim in self.array_dims:
                array_size *= dim

            for target_entry in sbe_value.target_entries:
                if ( (target_entry.name == "ALL")  and
                     (len(sbe_value.target_entries) > 1) ):
                    raise ParseError(self.name + ":" + \
                    "More than one target_entry with value 'ALL'")

                #Check if the target_type is supported for the attribute
                if ( (target_entry.name != "ALL") and
                     (target_entry.name not in self.sbe_target_type) ):
                    raise ParseError(self.name + ":" + \
                    "Trying to initialize values for the unsupported target type " + \
                    target_entry.name)

                for value in target_entry.values:
                    if ( len(target_entry.values[value]) != array_size ):
                        raise ParseError("%s : Number of <value> not "
                                "enough to initialize attribute" % (self.name))

            sbe_value.validated = True

        return sbe_value

class ECAttribute(object):
    """
    Class to parse EC feature realted attribute from xml. (These attribute doesnt
        need a storage location.)
    """
    def __init__(self, db:"AttributeDB", node:Element):
        # TODO: Derive RealAttribute and ECAttribute from a common class to remove code duplication

        self.db = db
        self.sbe_entry:"SBEEntry" = None

        name, target_type, description, enum_values, array_dims = (
            node.find(tag) for tag in ("id", "targetType", "description", "enum", "array"))

        if name is None:
            raise ParseError("Unnamed attribute")
        self.name = name.text

        if target_type is None:
            raise ParseError("Attribute %s is missing a target type" % self.name)
        self.target_type = target_type.text

        target_type_str_list = [targ.strip().upper() for targ in self.target_type.split(',')]
        self.ekb_target_type:list[str] = []
        for targ in target_type_str_list:
            self.ekb_target_type.append(targ)

        self.value_type = "uint8"
        self.array_dims = []
        self.enum_values = None

        self.chip_name = node.find("chipEcFeature").find("chip").find("name").text
        self.ec_value = node.find("chipEcFeature").find("chip").find("ec").find("value").text
        self.ec_test = node.find("chipEcFeature").find("chip").find("ec").find("test").text

    def validate_and_return_sbe_attribute(self, sbe_value:"SBEEntry") -> "SBEEntry":
        #TODO: Enable this while supporting EC_attribute
        if sbe_value != None:
            vprint("Validating attribute: " + self.name)
            '''
            if sbe_value.virtual == False:
                raise ParseError(self.name + " is EC attribute but not virtual")

            if self.target_type != 'TARGET_TYPE_PROC_CHIP':
                raise ParseError(self.name + " is EC attribute but target is not"
                        " valid: " + self.target_type)

            if self.ec_test != "EQUAL":
                raise ParseError(self.name + " is EC attribute but target is not valid")
            '''

            sbe_value.validated = True

        return sbe_value

class AttributeDB(object):
    """
    An object of this class will represent collection of all attributes in
        attribute xmls from EKB.
    """
    TARGET_TYPES : 'dict[str, TargetTypeInfo]' = dict()

    '''
    An object of this class will be instantiated for two purposes.
    1. HWP auto-generation: here we will be only supplied by ekb XMLs, and it will have information about different chip's attributes.
       So we need an input (i_chip_type) to select the attributes which are interesting to us.
    2. SBE source code generation: here we will be supplied with ekb XMLs and SBE XMLs, and we have to combine the information in
       these two to generate the source code. Here SBE XML will have information, which all attributes are interesting to us.
       So "i_chip_type" is not required here.
    '''
    def __init__(self, i_target_json_path : str, i_chip_type : str = None):
        with open(i_target_json_path, 'r') as fp:
            AttributeDB.TARGET_TYPES =json.load(
                    fp, object_hook= lambda d : targetTypeInfoLoader(**d))

        self.attributes : 'dict[str, RealAttribute|ECAttribute]' = dict()
        self.chip_type = i_chip_type
        self.sync_attr_tabulated = False
        self.to_sbe_list :dict[str,RealAttribute] = dict()
        self.from_sbe_list :dict[str,RealAttribute] = dict()
        # Attribute update header size is 4 bytes
        self.attr_upd_blob_size = 4

    def load_xml(self, fname):
        root = etree.parse(fname).getroot()
        for elem in root.iter("attribute"):
            attr = ECAttribute(self, elem) if elem.find("chipEcFeature") else RealAttribute(self, elem)

            if attr.name in self.attributes:
                raise ParseError("Duplicate attribute " + attr.name)
            self.attributes[attr.name] = attr

    '''
    Arrange the attributes into dictionaries to_sbe_list and from_sbe_list, with target as keys.
    Also calculate the attribute_update_blob size for the sync attributes.
    '''
    def tabulateSyncAttributes(self):
        if(self.sync_attr_tabulated):
            return

        for attr in self.attributes.values():
            if(not isinstance(attr, RealAttribute)):
                continue

            if((attr.attr_sync != None) and
                (attr.attr_sync.to_sbe) and
                (self.chip_type in attr.attr_sync.chip_types)):

                for targ in attr.attr_sync.target_types:
                    target_section_size = 0
                    if(targ not in self.to_sbe_list.keys()):
                        self.to_sbe_list[targ] = []
                        # target header size is 4 bytes
                        target_section_size += 4

                    self.to_sbe_list[targ].append(attr)
                    self.calculateBlobSizeForAttribute(
                        targ, attr.tot_size, target_section_size);

            # in apply_attribute HWP, we need all the attributes
            #   since we have to ignore the attributes in the xml but
            #   fromSbe is not set, and we have to throw error for
            #   attributes thats not present in any xml
            for targ in attr.sbe_target_type:
                if(targ not in self.from_sbe_list.keys()):
                    self.from_sbe_list[targ] = []
                self.from_sbe_list[targ].append(attr)

        self.sync_attr_tabulated = True

    def calculateBlobSizeForAttribute(self, i_targ, i_attr_size, i_target_section_size):
        # The actual size of the attribute row :
        # The size of the attribute id   = 4 bytes +
        # The number of bytes to specify
        #     attribute data size        = 2 bytes +
        # The number of bytes used to
        #     specify the co-ordinates
        #     row,col,hgt,1 byte reserved= 4 bytes +
        # The number of bytes to store actual data size

        attr_actual_data_size = 10 + i_attr_size
        attr_aligned_data_size= (attr_actual_data_size+7) & (~7)

        i_target_section_size  += attr_aligned_data_size

        i_target_section_size *= self.TARGET_TYPES[i_targ].ntargets

        self.attr_upd_blob_size += i_target_section_size

    def getToSbeSystemAttributes(self):
        self.tabulateSyncAttributes()

        try:
            return self.to_sbe_list['TARGET_TYPE_SYSTEM']
        except KeyError:
            # return empty list, if no entry for this target
            return []

    def getToSbeOdysseyChipAttributes(self):
        self.tabulateSyncAttributes()

        try:
            assert self.chip_type == "ody", "This function is valid only for ody chip type"
            return self.to_sbe_list['TARGET_TYPE_OCMB_CHIP']
        except KeyError:
            # return empty list, if no entry for this target
            return []

class TargetEntry(object):
    """
    Parse target_type element of sbe attribute xml (which will define SBE related
        properties)
    """
    def __init__(self, name) -> None:
        self.name = name
        self.comm_values = False # indicates common values for all instance in this target
        if(name == 'ALL'):
            #if target entry is common for all target then it should be common for all instances
            self.comm_values = True
        self.values :dict[int, list[int]] = {}

    def add_values(self, values:list, instance:int = 0xFF):
        if(self.comm_values):
            if(instance != 0xFF):
                raise Exception("Invalid instance number %d" %instance)
        elif(instance == 0xFF):
            self.comm_values = True
        if(instance in self.values.keys()):
            raise Exception("Instance already present")
        self.values[instance] = values

class SBEEntry(object):
    """
    Parse an entry inside sbe attribute xml (which will define SBE related
        properties)
    """
    def __init__(self) -> None:
        self.is_empty = True
        self.target_entries:list[TargetEntry] = list()
        self.virtual = False
        self.overridable = False
        self.validated = False

    def set_overridable(self):
        self.is_empty = False
        self.overridable = True

    def set_virtual(self, img_type:str="GENERIC"):
        self.is_empty = False
        self.virtual = True

    def add_target_entry(self, target_entry:TargetEntry):
        self.is_empty = False
        self.target_entries.append(target_entry)

    def get_target_entry(self, targ_name:str) -> TargetEntry:
        if(self.target_entries[0].name == 'ALL'):
            return self.target_entries[0]
        for targ in self.target_entries:
            if(targ.name == targ_name):
                return targ

        vprint("Target entry not found for target %s" % targ_name)
        return None

    def update_sbe_entry(self, in_entry:"SBEEntry") -> None:
        if (in_entry == None) or in_entry.is_empty:
            return
        self.target_entries.clear()
        self.target_entries = copy.deepcopy(in_entry.target_entries)
        if in_entry.overridable:
            self.overridable = True
        if in_entry.virtual:
            self.virtual = True

class SBEAttributes(object):
    """
    This class represent collection of all SBE entries.
    """
    def __init__(self, fname):
        root = etree.parse(fname).getroot()
        self.attributes : dict[str,SBEEntry]  = dict()
        elem_count = 0
        for elem in root.iter("entry"):
            elem_count += 1
            vprint("Processing XML element <entry> ..." + str(elem_count))
            name = elem.attrib.get("name")
            target_types = elem.findall("target_type")
            virtual = elem.find("virtual")
            overridable = elem.find("Overridable")
            values = elem.findall("value")

            if name is None:
                raise ParseError("Unnamed SBE attribute")

            if name in self.attributes:
                raise ParseError("Duplicate entry for attribute " + name)

            entry = SBEEntry()

            if virtual != None:
                entry.set_virtual()

            if overridable != None:
                entry.set_overridable()

            #<value> can also be direct children of <entry>
            #In that case, that attribute will be initialized
            #with the value for all the targets and their instances
            if values:
                target_entry = TargetEntry('ALL')
                target_entry.add_values([int(value.text, 0) for value in values])
                entry.add_target_entry(target_entry)
                if ( len(target_types) > 0 ):
                    raise ParseError(
                      "If <value> element is present as a child of <attribute> "
                      "then <target_entry> element is not supported")
            else:
                # Look for the XML element <target_type> with the same instance-id
                # and throw error
                tgt_ins : dict[str,TargetEntry] = dict()

                for target_type in target_types:
                    target_name = target_type.attrib.get("name",None)
                    instance_str = target_type.attrib.get("instance",None)
                    values = target_type.findall("value")

                    if target_name is None:
                        raise ParseError("%s : Unnamed XML element <target_type> " % name)

                    if target_name not in tgt_ins.keys():
                        tgt_ins[target_name] = TargetEntry(target_name)

                    if instance_str is not None:
                        try:
                            instance = int(instance_str,0)
                        except ValueError as ex:
                            raise ParseError(("%s : %s : instance [%s] is not valid") %
                                        (name, target_name, instance_str))

                        if (instance != 0xFF):
                            ntargets = AttributeDB.TARGET_TYPES[target_name].ntargets
                            if (instance >= ntargets):
                                raise ParseError(("%s : %s : instance=%d exceeds " +
                                        "max instance [%d]") %
                                        (name, target_name, instance, (ntargets-1)))
                    else:
                        instance = 0xFF


                    if not values:
                        raise ParseError(("%s : %s : For the instance [%d], <value> element(s) "
                                        "are not present") % (name, target_name, instance))

                    tgt_ins[target_name].add_values(
                                        [int(value.text, 0) for value in values],
                                        instance)

                for targ_entry in tgt_ins:
                    entry.add_target_entry(tgt_ins[targ_entry])

            if not entry.is_empty:
                self.attributes[name] = entry

    def update_attrdb(self, db:AttributeDB) -> None:
        for attr in db.attributes.values():
            entry_value = attr.validate_and_return_sbe_attribute(
                                self.attributes.get(attr.name, None))
            if (not attr.sbe_entry) or (attr.sbe_entry == None):
                attr.sbe_entry = entry_value
            else:
                attr.sbe_entry.update_sbe_entry(entry_value)

        for attr in self.attributes.keys():
            if self.attributes[attr].validated == False:
                raise ParseError("Invalid SBE attribute " + attr)
