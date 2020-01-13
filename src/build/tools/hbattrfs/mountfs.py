#!/usr/bin/env python
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/hbattrfs/mountfs.py $
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

# Uses the Fuse library to mount a virtual filesystem for HB attributes on a
# given directory.

import json
import virtualpath
import sys
import os, stat, errno

try:
  import _find_fuse_parts
except ImportError:
  pass
import fuse
from fuse import Fuse

fuse.fuse_python_api = (0, 2)

class FileInfo(fuse.Stat):
  def __init__(self):
    self.st_mode = 0
    self.st_ino = 0
    self.st_dev = 0
    self.st_nlink = 0
    self.st_uid = 0
    self.st_gid = 0
    self.st_size = 0
    self.st_atime = 0
    self.st_mtime = 0
    self.st_ctime = 0

class VirtualAttrFS(Fuse):
  _attrDict = None
  _dirTreeDict = None

  # What stat calls
  def getattr(self, path):
    st = FileInfo()

    hierarchy = VirtualAttrFS._dirTreeDict
    huid_to_target = VirtualAttrFS._attrDict

    try:
      ent = virtualpath.lookup_entity(path, hierarchy, huid_to_target)
    except Exception as e:
      return -errno.ENOENT

    if ent.is_target():
      st.st_mode = stat.S_IFDIR | 0o755
      st.st_nlink = 2
    elif ent.is_attribute():
      st.st_mode = stat.S_IFREG | 0o444
      st.st_nlink = 1
      st.st_size = len(ent.get_attribute_value()) + 1
    else:
      return -errno.ENOENT
    return st

  # ls
  def readdir(self, path, offset):
    hierarchy = VirtualAttrFS._dirTreeDict
    huid_to_target = VirtualAttrFS._attrDict

    entObj = virtualpath.lookup_entity(path, hierarchy, huid_to_target)
    listChilds = entObj.get_target_children()

    dispList = [x.encode('utf-8') for x in [".", ".."] + listChilds]

    for r in dispList:
      yield fuse.Direntry(r)

  # cat
  def open(self, path, flags):
    hierarchy = VirtualAttrFS._dirTreeDict
    huid_to_target = VirtualAttrFS._attrDict

    entObj = virtualpath.lookup_entity(path, hierarchy, huid_to_target)

    if not entObj:
      return -errno.ENOENT
    accmode = os.O_RDONLY | os.O_WRONLY | os.O_RDWR
    if (flags & accmode) != os.O_RDONLY:
      return -errno.EACCES

  # cat
  def read(self, path, size, offset):
    hierarchy = VirtualAttrFS._dirTreeDict
    huid_to_target = VirtualAttrFS._attrDict

    entObj = virtualpath.lookup_entity(path, hierarchy, huid_to_target)

    if not entObj or not entObj.is_attribute():
      return -errno.ENOENT

    hello_str = (entObj.get_attribute_value() + '\n').encode('utf-8')

    slen = len(hello_str)
    if offset < slen:
      if offset + size > slen:
        size = slen - offset
      buf = hello_str[offset:offset+size]
    else:
      buf = b''
    return buf

def readJson(jsonFilePath):
  with open(jsonFilePath, 'r') as jsonFile:
    return json.load(jsonFile)

def main(attrJSON, treeDirJSON):
  VirtualAttrFS._attrDict = readJson(attrJSON)
  VirtualAttrFS._dirTreeDict = readJson(treeDirJSON)

  server = VirtualAttrFS(version="%prog " + fuse.__version__,
                         usage="Hostboot Attribute virtual filesystem\n" + Fuse.fusage,
                         dash_s_do='setsingle')

  server.parse(errex=1)
  server.main()

if __name__ == '__main__':
  jsonAttr = sys.argv[1]
  jsonDirTree = sys.argv[2]
  sys.argv = sys.argv[0:1] + sys.argv[3:] # don't show the fuse library our arguments

  main(jsonAttr, jsonDirTree)
