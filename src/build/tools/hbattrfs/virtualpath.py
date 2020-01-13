# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/hbattrfs/virtualpath.py $
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

# Helper library for mountfs.py
#
# Navigates the JSON structures produced from the XML files and converts paths
# from strings like '/sys-0/node-0/proc-0/...' to AttributeEntity or
# TargetEntity objects.

import sys
import json

class AttributeEntity(object):
  def __init__(self, name, value, pretty):
    self.name_, self.value, self.pretty = name, value, pretty

  def name(self):
    return self.name_

  def is_attribute(self):
    return True

  def is_target(self):
    return False

  def get_target_children(self):
    return None

  def get_attribute_value(self):
    if self.pretty:
      return self.value + '\n' + self.pretty
    else:
      return self.value

class TargetEntity(object):
  def __init__(self, name, children):
    self.name_, self.children = name, children

  def name(self):
    return self.name_

  def is_attribute(self):
    return False

  def is_target(self):
    return True

  def get_target_children(self):
    return self.children

  def get_attribute_value(self):
    return None

def lookup_entity(path, hierarchy, huid_to_target):
  components = [x for x in path[1:].split('/') if x]

  if not components:
    return TargetEntity('/', hierarchy.keys())

  huid = None
  children = []

  while components:
    component = components[0]
    components = components[1:]

    if component not in hierarchy:
      if not components:
        # try attribute, we have no more components
        attrs = huid_to_target[huid]['attributes']
        if component in attrs:
          return AttributeEntity(component,
                                 attrs[component]['value'],
                                 attrs[component]['pretty-value'])
      else:
        return None

    huid = hierarchy[component].get('huid', None)
    children = hierarchy[component].keys()
    children.remove('huid')
    hierarchy = hierarchy[component]

  if not huid:
     return TargetEntity(component, children)

  attributes = huid_to_target[huid]['attributes'].keys()

  return TargetEntity(component, children + attributes)
