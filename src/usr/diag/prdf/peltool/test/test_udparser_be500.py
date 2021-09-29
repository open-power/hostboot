#!/usr/bin/env python3
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/peltool/test/test_udparser_be500.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021
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
import os, sys
sys.path.append(os.path.join(os.path.dirname(sys.path[0]), 'src/build/tools/ebmc/'))


import udparsers.be500.be500
import json
import unittest

from collections import OrderedDict

class TestUserDataParser( unittest.TestCase ):

    def testExtMruData( self ):
        testData = bytearray.fromhex( '800047086000' )
        mv = memoryview( testData )

        parser = udparsers.be500.be500.errludP_prdf()
        testStr = parser.UdParserPrdfMruData( mv )
        jsonOut = json.loads( testStr )

        print( json.dumps(jsonOut, indent=4) )

        emm = 'Extended Mem Mru'
        self.assertEqual( jsonOut[emm]['Node Pos'], 0 )
        self.assertEqual( jsonOut[emm]['Proc Pos'], 0 )
        self.assertEqual( jsonOut[emm]['Component Pos'], 0 )
        self.assertEqual( jsonOut[emm]['Primary Rank'], 0 )
        self.assertEqual( jsonOut[emm]['Secondary Rank'], 0 )
        self.assertEqual( jsonOut[emm]['Symbol'], 71 )
        self.assertEqual( jsonOut[emm]['Pins'], 0 )
        self.assertEqual( jsonOut[emm]['Dram Spared'], 'No' )
        self.assertEqual( jsonOut[emm]['DQ'], 0 )
        self.assertEqual( jsonOut[emm]['isX4Dram'], 'Yes' )

    def testPfaDataParser( self ):
        testData = bytearray.fromhex(
        '4D53202044554D5040000000004B0000000310018280006F00000000050500FC000000'
        '018000470802040000000001004B0000FFFF001300' )
        mv = memoryview( testData )

        parser = udparsers.be500.be500.errludP_prdf()
        testStr = parser.UdParserPrdfPfaData( mv )

        jsonOut = json.loads( testStr )

        print ( json.dumps(jsonOut, indent=4) )

        self.assertEqual( jsonOut['DUMP Content'], '0x40000000' )
        self.assertEqual( jsonOut['DUMP HUID'], '0x004b0000' )
        self.assertEqual( jsonOut['ERRL Actions'], '0x0003' )
        self.assertEqual( jsonOut['ERRL Severity'], 'RECOVERED' )
        self.assertEqual( jsonOut['Service Action Counter'], '0x01' )
        self.assertEqual( jsonOut['SDC Flags']['DUMP'], 'True' )
        self.assertEqual( jsonOut['SDC Flags']['UERE'], 'False' )
        self.assertEqual( jsonOut['SDC Flags']['SUE'], 'False' )
        self.assertEqual( jsonOut['SDC Flags']['AT_THRESHOLD'], 'False' )
        self.assertEqual( jsonOut['SDC Flags']['DEGRADED'], 'False' )
        self.assertEqual( jsonOut['SDC Flags']['SERVICE_CALL'], 'False' )
        self.assertEqual( jsonOut['SDC Flags']['TRACKIT'], 'True' )
        self.assertEqual( jsonOut['SDC Flags']['TERMINATE'], 'False' )
        self.assertEqual( jsonOut['SDC Flags']['LOGIT'], 'True' )
        self.assertEqual( jsonOut['SDC Flags']['MEM_CHNL_FAIL'], 'False' )
        self.assertEqual( jsonOut['SDC Flags']['PROC_CORE_CS'], 'False' )
        self.assertEqual( jsonOut['SDC Flags']['USING_SAVED_SDC'], 'False' )
        self.assertEqual( jsonOut['SDC Flags']['LAST_CORE_TERM'], 'False' )
        self.assertEqual( jsonOut['SDC Flags']['DEFER_DECONFIG'], 'False' )
        self.assertEqual( jsonOut['SDC Flags']['SECONDARY_ERROR'], 'False' )
        self.assertEqual( jsonOut['Error Count'], 0 )
        self.assertEqual( jsonOut['Error Threshold'], 0 )
        self.assertEqual( jsonOut['Primary Attn Type'], 'HOST_ATTN' )
        self.assertEqual( jsonOut['Secondary Attn Type'], 'HOST_ATTN' )
        self.assertEqual( jsonOut['PRD GARD Error Type'], 'NoGard' )
        self.assertEqual( jsonOut['PRD MRU List'], 1 )
        self.assertEqual( jsonOut['MRU #0']['Priority'], 'MED_A' )
        self.assertEqual( jsonOut['MRU #0']['Type'], 'MemoryMru' )
        self.assertEqual( jsonOut['MRU #0']['Gard State'], 'NoGard' )
        self.assertEqual( jsonOut['MRU #0']['Node Pos'], 0 )
        self.assertEqual( jsonOut['MRU #0']['Proc Pos'], 0 )
        self.assertEqual( jsonOut['MRU #0']['Component Pos'], 0 )
        self.assertEqual( jsonOut['MRU #0']['Primary Rank'], 0 )
        self.assertEqual( jsonOut['MRU #0']['Secondary Rank'], 0 )
        self.assertEqual( jsonOut['MRU #0']['Symbol'], 71 )
        self.assertEqual( jsonOut['MRU #0']['Pins'], 0 )
        self.assertEqual( jsonOut['MRU #0']['Dram Spared'], 'No' )
        self.assertEqual( jsonOut['MRU #0']['DQ'], 0 )
        msl = 'Multi-Signature List'
        hexSig = '0x004b0000 0xffff0013'
        self.assertEqual( jsonOut[msl]['Count'], 1 )
        self.assertEqual( jsonOut[msl][hexSig], 'Maintenance HARD CTE' )

    def testCaptureDataParser( self ):
        testData = bytearray.fromhex(
        '0000063C000500020000003034EB00080008000000000000CBED000800000000010000'
        '009100000800EFF507FD0C7E0F7ADE0008FFFFFFFFFFFFFFFFE5BB00080000F0020000'
        '0000F6510008F798F0FF07C061BCD42100080806000010080000D423000800610F00E8'
        '379E40A6DB00081F6A30000000000058980008200000000000000059E0000800EFF3FF'
        'FFFFFFFF1A2200080000021F80401E072D1100081017006302800000A30D0008008000'
        '0000000000309C00083082107E40FF00001A7A00088F7C60003D000000874300080021'
        '0107540D500058A40008200000000000000059E9000800EFF3FFFFFFFF07EE5100084C'
        '400000000000005C5D00081581FC0000000000605D00081581FC0000000000645D0008'
        '1581FC0000000000685D00081581FC00000000006C5D00081581FC0000000000705D00'
        '081581FC0000000000745D00081581FC0000000000785D00081581FC0000000000EAB4'
        '00081581000000000000EAB800081581FC0000000000EABC00081581FC0000000000EA'
        'C000081581000000000000FEB400081581000000000000FEB800081581FC0000000000'
        'FEBC00080501FC0000000000FEC0000815810000000000005C6E000800000010000000'
        '00490C00083F0206F00000000026DE0008C028010000000000B9510008FFFFFFF00000'
        '0000A6A50008200FE3FC07000000E1AC000818C0000000000000BFE500082000000000'
        '000000BFF100082000000000000000BFFD00082000000000000000C009000820000000'
        '000000001C1E00087A00000000000000B7C30008FC6000000000000000440008000000'
        '074D7C0008200000000000000007AD00088400000000000000518B000800EFF3FFFFFF'
        'FFFFBCC50008037E7600000000007E840008DF70000000000000A8410008801000001F'
        '21FDFCD87B0008821000000F000000004900100000000BBCE500080200000001800000'
        'FA43000811003C0067800000D8130008880CC30018000000D8150008CC2FC363980000'
        '00D81700082200000000000000BD3A00080000000000018000FACB00080C8162418001'
        '8000D89B0008F00000181FF87F98D89D0008F3000C1E7FFE7FB8FF0500080000000006'
        '00000061DB00087F90006000600000004B002100000027575700086627FFE000000000'
        '383D000804000000000000002DCD0008000000002001FE0099F000081F7FF49E7201FF'
        'FE77C20008FFFFFFFFFFFFFFFF9C370008C1F00000000000000B1F00081A8000460000'
        '0000F40100080020000000000000F55100088FD9F00000000000D32100080020000000'
        '000000D323000840040000000000003E8600080090000800000000CDCB000800F80FFF'
        'A0007FFFD7A90008FFC3700017E6000053FB00080007C01C00000000B9070008001000'
        '0000000000E0E60008089FFFFFFFFFFFFFCAC40008376000000000000049F600080000'
        '0000000000FF9B7B000838AA00000000000025370008FFF0000000000000706E0008FF'
        'FFFFFF040001C05B73000800200000000000004675000800FFFFDFEC00000059690008'
        '400000000000000075A5000851C000000000000017B1000800000000000000202BE900'
        '0800800000000000622BF1000800000000020000003A75000800DF39A7E0000000CADA'
        '0008000030000000000037470008000088808200434C59BD00088207400042063DCD65'
        'E60008111000002708090A65E800080B0C050400030200752E0004900884021D95000C'
        '2FFF004448FF44014448FF44FAAB00180000F000000000FF000000000100F000000000'
        'FF000000001716012800000000000000000104000022BC4F182B0104000020402D0050'
        '0100000001B4FFD00101040000203E3D986B0104000023F241D858010400002284D8D0'
        '720100000003EBBE002D010400002354AE880201040000212647D80001000000005554'
        '586C0100000002146DC0570104000000DE6D087701040000025849985C0104000000DD'
        'D9986C010400000282DF504B0104000023BE50000801040000018AD6987F0104000003'
        'DA9F882B01040000031FBE002501040000212B06102701040000228D0FD05701040000'
        '200000000001040000008089186801040000000000000001040000008CD8183D010400'
        '00012B0E08250104000003B7D7186B0104000003C8A9804B0104000003752F00430104'
        '000002A04FD0000104000000E78F406B010400000198E49868' )
        mv = memoryview( testData )

        parser = udparsers.be500.be500.errludP_prdf()
        testStr = parser.UdParserPrdfCapData( mv )

        jsonOut = json.loads( testStr )

        print ( json.dumps(jsonOut, indent=4) )

        cd = 'Capture Data'
        r = 'Registers'
        huid = '0x00050002'
        reg = 'PBAF_FIR_MASK'.ljust(25) + ' (0x0000000003011dc3)'
        testData = '0x200fe3fc07000000'
        self.assertEqual( jsonOut[cd][r][huid][reg], testData )

        huid = '0x00440008'
        reg = 'MCFGP0'.ljust(25) + ' (0x000000000c010c0a)'
        testData = '0x801000001f21fdfc'
        self.assertEqual( jsonOut[cd][r][huid][reg], testData )

        huid = '0x00490010'
        reg = 'MC_USTL_FIR'.ljust(25) + ' (0x000000000c010e00)'
        testData = '0x0000000000018000'
        self.assertEqual( jsonOut[cd][r][huid][reg], testData )

        huid = '0x004b0021'
        reg = 'MCBMCAT'.ljust(25) + ' (0x00000000080118d7)'
        testData = '0x00ffffdfec000000'
        self.assertEqual( jsonOut[cd][r][huid][reg], testData )

        td = 'TDCTLR_STATE_DATA_START'
        self.assertEqual( jsonOut[cd][td]['State'], 'RT' )
        self.assertEqual( jsonOut[cd][td]['Version'], 1 )
        self.assertEqual( jsonOut[cd][td]['Primary Rank'], 0 )
        self.assertEqual( jsonOut[cd][td]['Secondary Rank'], 0 )
        self.assertEqual( jsonOut[cd][td]['Phase'], 2 )
        self.assertEqual( jsonOut[cd][td]['TD Type'], 'TPS' )
        self.assertEqual( jsonOut[cd][td]['Entries in Queue'], 1 )
        self.assertEqual( jsonOut[cd][td]['0']['Primary Rank'], 0 )
        self.assertEqual( jsonOut[cd][td]['0']['Secondary Rank'], 0 )
        self.assertEqual( jsonOut[cd][td]['0']['TD Type'], 'TPS' )

        drd = 'Dram Repairs Data'
        self.assertEqual( jsonOut[cd][drd]['0']['Rank'], 0 )
        self.assertEqual( jsonOut[cd][drd]['0']['Chip Mark'], 68 )
        self.assertEqual( jsonOut[cd][drd]['0']['Symbol Mark'], '--' )
        self.assertEqual( jsonOut[cd][drd]['0']['Spare0'], '--' )
        self.assertEqual( jsonOut[cd][drd]['0']['Spare1'], 68 )
        self.assertEqual( jsonOut[cd][drd]['1']['Rank'], 1 )
        self.assertEqual( jsonOut[cd][drd]['1']['Chip Mark'], 68 )
        self.assertEqual( jsonOut[cd][drd]['1']['Symbol Mark'], '--' )
        self.assertEqual( jsonOut[cd][drd]['1']['Spare0'], '--' )
        self.assertEqual( jsonOut[cd][drd]['1']['Spare1'], 68 )

        drv = 'Dram Repairs VPD'
        bitmap = '0xf000000000ff00000000'
        self.assertEqual( jsonOut[cd][drv]['0']['Rank'], 0 )
        self.assertEqual( jsonOut[cd][drv]['0']['Port'], 0 )
        self.assertEqual( jsonOut[cd][drv]['0']['Bitmap'], bitmap )
        self.assertEqual( jsonOut[cd][drv]['1']['Rank'], 1 )
        self.assertEqual( jsonOut[cd][drv]['1']['Port'], 0 )
        self.assertEqual( jsonOut[cd][drv]['1']['Bitmap'], bitmap )

        cet = 'CE Table'
        self.assertEqual( jsonOut[cd][cet]['0']['Count'], 1 )
        self.assertEqual( jsonOut[cd][cet]['0']['Primary Rank'], 1 )
        self.assertEqual( jsonOut[cd][cet]['0']['Secondary Rank'], 0 )
        self.assertEqual( jsonOut[cd][cet]['0']['Bank'], '0x3' )
        self.assertEqual( jsonOut[cd][cet]['0']['Column'], '0x2b' )
        self.assertEqual( jsonOut[cd][cet]['0']['Row'], '0x2bc4f' )
        self.assertEqual( jsonOut[cd][cet]['0']['Dram Pins'], '0x0' )
        self.assertEqual( jsonOut[cd][cet]['0']['Dram'], '0x0' )
        self.assertEqual( jsonOut[cd][cet]['0']['On Spare'], 'Yes' )
        self.assertEqual( jsonOut[cd][cet]['0']['Hard CE'], 'No' )
        self.assertEqual( jsonOut[cd][cet]['0']['Is Active'], 'No' )

        self.assertEqual( jsonOut[cd][cet]['17']['Count'], 1 )
        self.assertEqual( jsonOut[cd][cet]['17']['Primary Rank'], 0 )
        self.assertEqual( jsonOut[cd][cet]['17']['Secondary Rank'], 0 )
        self.assertEqual( jsonOut[cd][cet]['17']['Bank'], '0x11' )
        self.assertEqual( jsonOut[cd][cet]['17']['Column'], '0x2b' )
        self.assertEqual( jsonOut[cd][cet]['17']['Row'], '0x3da9f' )
        self.assertEqual( jsonOut[cd][cet]['17']['Dram Pins'], '0x0' )
        self.assertEqual( jsonOut[cd][cet]['17']['Dram'], '0x0' )
        self.assertEqual( jsonOut[cd][cet]['17']['On Spare'], 'Yes' )
        self.assertEqual( jsonOut[cd][cet]['17']['Hard CE'], 'No' )
        self.assertEqual( jsonOut[cd][cet]['17']['Is Active'], 'No' )

        self.assertEqual( jsonOut[cd][cet]['31']['Count'], 1 )
        self.assertEqual( jsonOut[cd][cet]['31']['Primary Rank'], 0 )
        self.assertEqual( jsonOut[cd][cet]['31']['Secondary Rank'], 0 )
        self.assertEqual( jsonOut[cd][cet]['31']['Bank'], '0x13' )
        self.assertEqual( jsonOut[cd][cet]['31']['Column'], '0x68' )
        self.assertEqual( jsonOut[cd][cet]['31']['Row'], '0x198e4' )
        self.assertEqual( jsonOut[cd][cet]['31']['Dram Pins'], '0x0' )
        self.assertEqual( jsonOut[cd][cet]['31']['Dram'], '0x0' )
        self.assertEqual( jsonOut[cd][cet]['31']['On Spare'], 'Yes' )
        self.assertEqual( jsonOut[cd][cet]['31']['Hard CE'], 'No' )
        self.assertEqual( jsonOut[cd][cet]['31']['Is Active'], 'No' )

    def testCaptureDataParserUeTable( self ):
        testData = bytearray.fromhex(
        '00000494000500000000002E34EB00080004000000000000CBED000800000400'
        '010000009100000800EFF507BD0C7E0F7ADE0008FFFFFFFFFFFFFFFFE5BB0008'
        '0000F02000000000F6510008EF9CF0FF0010011CD423000810630F00FFEFFEE0'
        'A6DB0008FFFFF0000000000058980008200000000000000059E0000800EFF3FF'
        'FFFFFFFF1A2200080000021F80401E072D1100081017006302800000309C0008'
        '3082107E40FF00008743000800210107540D500058A400082000000000000000'
        '59E9000800EFF3FFFFFFFF07EE5100084C600000000000005C5D00081581FC00'
        '00000000605D00081581FC0000000000645D00081581FC0000000000685D0008'
        '1581FC00000000006C5D00081581FC0000000000705D00081581FC0000000000'
        '745D00081581FC0000000000785D00081581FC0000000000EAB4000815810000'
        '00000000EAB800081581FC0000000000EABC00081581FC0000000000EAC00008'
        '1581000000000000FEB400081581000000000000FEB800081581FC0000000000'
        'FEBC00081581FC0000000000FEC0000815810000000000005C6E000800000010'
        '00000000490C00083F0206F00000000026DE0008C028010000000000B9510008'
        'FFFFFFF000000000A6A50008FFFFFFFFFF000000E1AC000818C0000000000000'
        'BFE500082000000000000000BFF100082000000000000000BFFD000820000000'
        '00000000C009000820000000000000001C1E00087A00000000000000B7C30008'
        'FC000000000000005D350008002000000000000000440001000000074D7C0008'
        '200000000000000007AD00088400000000000000518B000800EFF3FFFFFFFFFF'
        'BCC50008077E7700000000007E840008DF70000000000000A841000800000000'
        '0001FDFCA8430008000000000001FDFC0049000200000007BCE5000820000000'
        '00000000FA43000811003C0066000000D81500084423006380000000D8170008'
        '2200000000000000FACB00080C81624180018000FF050008F000000006000000'
        '61DB00087F90006000600000004B000400000023575700086627FFE000000000'
        '383D000804000000000000002DCD0008000000002001FE0099F000081F7FF49F'
        'F201FFFE77C20008FFFFFFFFFFFFFFFF9C370008C1F00000000000000B1F0008'
        '1A84004600000000F40100088020000000000000F55100088FD9F00000000000'
        'D32100080020000000000000D323000840040000000000003E86000800000001'
        '00000000CDCB0008FFFFFFFFB7007FFFD7A900080000000048E6000053FB0008'
        '0007C01C00000000B90700080010000000000000E0E600081A9FFFFFFFFFFFFF'
        'CAC4000825600000000000002537000800000000000040002539000800100000'
        '00000000887900080001010100000000706E0008FFFFFFFF040001C15B730008'
        '00200000000000004675000800FFFF9FEC000000596900084000000000000000'
        '75A30008CAC00000000000002BE9000800800000000000622BF1000800000000'
        '0200000037470008000088808200434C6323000800CA00000000000059BD0008'
        '820640003DE63DCD65E60008100F00002708090A65E800080B0C050400030200'
        '752E00081004C400C000000071160008011003FFFED87F00')
        mv = memoryview( testData )

        parser = udparsers.be500.be500.errludP_prdf()
        testStr = parser.UdParserPrdfCapData( mv )

        jsonOut = json.loads( testStr )

        print ( json.dumps(jsonOut, indent=4) )

        cd = 'Capture Data'
        uet = 'UE Table'
        self.assertEqual( jsonOut[cd][uet]['0']['Count'], 1 )
        self.assertEqual( jsonOut[cd][uet]['0']['Type'], 'SCRUB_MPE' )
        self.assertEqual( jsonOut[cd][uet]['0']['Primary Rank'], '0x0' )
        self.assertEqual( jsonOut[cd][uet]['0']['Secondary Rank'], '0x0' )
        self.assertEqual( jsonOut[cd][uet]['0']['Bank'], '0x1b' )
        self.assertEqual( jsonOut[cd][uet]['0']['Column'], '0x7f' )
        self.assertEqual( jsonOut[cd][uet]['0']['Row'], '0x3fffe' )

    def testCaptureDataParserRowRepairData( self ):
        testData = bytearray.fromhex(
        '000004A0000500000000002E34EB00080004000000000000CBED000800000400'
        '010000009100000800EFF507BD0C7E0F7ADE0008FFFFFFFFFFFFFFFFE5BB0008'
        '0000F02000000000F6510008EF9CF0FF0010011CD423000810630F00FFEFFEE0'
        'A6DB0008FFFFF0000000000058980008200000000000000059E0000800EFF3FF'
        'FFFFFFFF1A2200080000021F80401E072D1100081017006302800000309C0008'
        '3082107E40FF00008743000800210107540D500058A400082000000000000000'
        '59E9000800EFF3FFFFFFFF07EE5100084C600000000000005C5D00081581FC00'
        '00000000605D00081581FC0000000000645D00081581FC0000000000685D0008'
        '1581FC00000000006C5D00081581FC0000000000705D00081581FC0000000000'
        '745D00081581FC0000000000785D00081581FC0000000000EAB4000815810000'
        '00000000EAB800081581FC0000000000EABC00081581FC0000000000EAC00008'
        '1581000000000000FEB400081581000000000000FEB800081581FC0000000000'
        'FEBC00081581FC0000000000FEC0000815810000000000005C6E000800000010'
        '00000000490C00083F0206F00000000026DE0008C028010000000000B9510008'
        'FFFFFFF000000000A6A50008FFFFFFFFFF000000E1AC000818C0000000000000'
        'BFE500082000000000000000BFF100082000000000000000BFFD000820000000'
        '00000000C009000820000000000000001C1E00087A00000000000000B7C30008'
        'FC000000000000005D350008002000000000000000440001000000074D7C0008'
        '200000000000000007AD00088400000000000000518B000800EFF3FFFFFFFFFF'
        'BCC50008077E7700000000007E840008DF70000000000000A841000800000000'
        '0001FDFCA8430008000000000001FDFC0049000200000007BCE5000820000000'
        '00000000FA43000811003C0066000000D81500084423006380000000D8170008'
        '2200000000000000FACB00080C81624180018000FF050008F000000006000000'
        '61DB00087F90006000600000004B000400000024575700086627FFE000000000'
        '383D000804000000000000002DCD0008000000002001FE0099F000081F7FF49F'
        'F201FFFE77C20008FFFFFFFFFFFFFFFF9C370008C1F00000000000000B1F0008'
        '1A84004600000000F40100088020000000000000F55100088FD9F00000000000'
        'D32100080020000000000000D323000840040000000000003E86000800000001'
        '00000000CDCB0008FFFFFFFFB7007FFFD7A900080000000048E6000053FB0008'
        '0007C01C00000000B90700080010000000000000E0E600081A9FFFFFFFFFFFFF'
        'CAC400082560000000000000253900080010000000000000706E0008FFFFF000'
        '040000005B73000800200000000000004675000808FFFF9FEC00000059690008'
        '800000000000000075A50008CAC00000000000002BE900080080000000000062'
        '2BF10008000000000200000037470008000088808200434C6323000800CA2000'
        '0000000059BD0008820640003DE63DCD65E60008100F00002708090A65E80008'
        '0B0C050400030200186300080000000000000020752E00081208042000000000'
        '1D9500081400012448FFFF0058C60008010008DBFFFF000071160008011023FF'
        'FED87F0000' )
        mv = memoryview( testData )

        parser = udparsers.be500.be500.errludP_prdf()
        testStr = parser.UdParserPrdfCapData( mv )

        jsonOut = json.loads( testStr )

        print ( json.dumps(jsonOut, indent=4) )

        cd = 'Capture Data'
        rrv = 'Row Repair VPD'
        self.assertEqual( jsonOut[cd][rrv]['0']['Rank'], 1 )
        self.assertEqual( jsonOut[cd][rrv]['0']['Port'], 0 )
        self.assertEqual( jsonOut[cd][rrv]['0']['Repair'], '0x08dbffff' )

    def testCaptureDataParserIueCounts( self ):
        testData = bytearray.fromhex(
        '000004F0000500000000002E34EB00080008000000000000CBED000800000400'
        '010000009100000800EFF507BD0C7E0F7ADE0008FFFFFFFFFFFFFFFFE5BB0008'
        '0000F00200000000F6510008EF98F0FF07C061BCD42100080006000010080000'
        'D423000810610F00E8379E40A6DB00081F6A3000000000005898000820000000'
        '0000000059E0000800EFF3FFFFFFFFFF1A2200080000021F80401E072D110008'
        '1017006302800000309C00083082107E40FF00008743000800210107540D5000'
        '58A40008200000000000000059E9000800EFF3FFFFFFFF07EE5100084C600000'
        '000000005C5D00081581FC0000000000605D00081581FC0000000000645D0008'
        '1581FC0000000000685D00081581FC00000000006C5D00081581FC0000000000'
        '705D00081581FC0000000000745D00081581FC0000000000785D00081581FC00'
        '00000000EAB400081581000000000000EAB800081581FC0000000000EABC0008'
        '1581FC0000000000EAC000081581000000000000FEB400081581000000000000'
        'FEB800081581FC0000000000FEBC00081581FC0000000000FEC0000815810000'
        '000000005C6E00080800001000000000490C00083F0206F00000000026DE0008'
        'C028010000000000B9510008FFFFFFF000000000A6A50008200FE3FC07000000'
        'E1AC000818C0000000000000BFE500082000000000000000BFF1000820000000'
        '00000000BFFD00082000000000000000C009000820000000000000001C1E0008'
        '7B00000000000000B7C30008FC6000000000000000440000000000074D7C0008'
        '200000000000000007AD00088400000000000000518B000800EFF3FFFFFFFFFF'
        'BCC50008077E7500000000007E840008DF70000000000000A841000880004000'
        '1F41FDFCA8430008800050001F21FDFC0049000000000008BCE5000820000000'
        '00000000FA43000811003C0066000000D8130008880CC30018000000D8150008'
        'CC2FC36398000000D81700082200000000000000FACB00080C81624180018000'
        'FF050008000000000600000061DB00087F90006000600000004B000000000024'
        '575700086627FFE000000000383D000804000000000000002DCD000800000000'
        '3001FE0099F000081F7FF49FF201FFFE77C20008FFFFFFFFFFFFFFFF9C370008'
        'C1F000000000000043BE000802800000000000000B1F00081A80004600000000'
        '14FD0008A443050800000000F40100080020000000000000F55100088FD9F000'
        '00000000D32100080020000000000000D323000840040000000000003E860008'
        '0000000804000000CDCB000800F92FFFB6007FFFD7A90008FFC2500001E60000'
        '53FB00080007C01C00000000B90700080010000000000000E0E600081A9FFFFF'
        'FFFFFFFFCAC40008256000000000000049F6000800000000000000FF25370008'
        '000000FFF0000000253900080000000000000010706E0008FFFFFFFF04000040'
        '5B73000800200000000000004675000800FFFFDFEC0000005969000840000000'
        '000000002BE9000800800000000000622BF10008000000000200000037470008'
        '000088808200434C59BD00088207400042063DCD65E60008111000002708090A'
        '65E800080B0C050400030200752E00089004840080000000C8A5000400010000'
        '17160050000000000000000001008000001C45000301008000001C4508030100'
        '8000001C45100301008000001C45180301008000001C45400301008000001C45'
        '480301008000001C45500301008000001C455803' )
        mv = memoryview( testData )

        parser = udparsers.be500.be500.errludP_prdf()
        testStr = parser.UdParserPrdfCapData( mv )

        jsonOut = json.loads( testStr )

        print ( json.dumps(jsonOut, indent=4) )

        cd = 'Capture Data'
        iue = 'IUE Counts'
        self.assertEqual( jsonOut[cd][iue]['0']['Count'], 1 )
        self.assertEqual( jsonOut[cd][iue]['0']['Rank'], 0 )

if __name__ == '__main__':
    test = TestUserDataParser()
    test.testExtMruData()
    test.testPfaDataParser()
    test.testCaptureDataParser()
    test.testCaptureDataParserUeTable()
    test.testCaptureDataParserRowRepairData()
    test.testCaptureDataParserIueCounts()
