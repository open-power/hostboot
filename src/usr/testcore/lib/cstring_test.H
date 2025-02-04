/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/cstring_test.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2025                        */
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
#ifndef __TESTCORE_CSTRING_H
#define __TESTCORE_CSTRING_H

#include <cxxtest/TestSuite.H>
#include <cstring.H>
#include <assert.h>

class CStringTest : public CxxTest::TestSuite
{
  public:

    void testCString()
    {
        TS_INFO(">testCString");
        size_t capacity = 11;
        CString s1;
        CString s2(capacity);
        CString s3("c");
        CString s4("12345");
        CString s5(s1);
        CString s6(s2);
        CString s7(s3);
        CString s8(s4);
        CString s9  = s1;
        CString s10 = s2;
        CString s11;
        CString s12;
        CString s13(10, 'x');
        CString s14(0, 'x');
        s11 = 'c';
        s12 = s4;

        assert(s1.empty());
        assert(s2.empty());
        assert(s5.empty());
        assert(s6.empty());
        assert(s9.empty());
        assert(s10.empty());

        assert(s1.length()  == 0);
        assert(s2.length()  == 0);
        assert(s3.length()  == 1);
        assert(s4.length()  == 5);
        assert(s5.length()  == 0);
        assert(s6.length()  == 0);
        assert(s7.length()  == 1);
        assert(s8.length()  == 5);
        assert(s9.length()  == 0);
        assert(s10.length() == 0);
        assert(s11.length() == 1);
        assert(s12.length() == 5);
        assert(s13.length() == 10);
        assert(s14.length() == 0);

        assert(s1.capacity()  == 1);
        assert(s2.capacity()  == 11);
        assert(s3.capacity()  == 2);
        assert(s4.capacity()  == 6);
        assert(s5.capacity()  == 1);
        assert(s6.capacity()  == 1);
        assert(s7.capacity()  == 2);
        assert(s8.capacity()  == 6);
        assert(s9.capacity()  == 1);
        assert(s10.capacity() == 1);
        assert(s11.capacity() == 2);
        assert(s12.capacity() == 6);
        assert(s13.capacity() == 11);
        assert(s14.capacity() == 1);

        assert(s1[0]   == NULL);
        assert(s2[0]   == NULL);
        assert(s2[9]   == NULL);
        assert(s3[0]   == 'c');
        assert(s3[1]   == NULL);
        assert(s4[0]   == '1');
        assert(s4[1]   == '2');
        assert(s4[4]   == '5');
        assert(s4[5]   == NULL);
        assert(s13[0]  == 'x');
        assert(s13[9]  == 'x');
        assert(s13[10] == NULL);
        assert(s14[0]  == NULL);

        assert(s1  == s5);
        assert(s1  == "");
        assert(s2  == s6);
        assert(s2  == "");
        assert(s3  == s7);
        assert(s3  == "c");
        assert(s4  == s8);
        assert(s4  == "12345");
        assert(s1  == s9);
        assert(s9  == "");
        assert(s2  == s10);
        assert(s10 == "");
        assert(s3  == s11);
        assert(s11 == "c");
        assert(s4  == s12);
        assert(s12 == "12345");

        assert(s1.compare(s5));
        assert(s1.compare(""));
        assert(s2.compare(s6));
        assert(s2.compare(""));
        assert(s3.compare(s7));
        assert(s3.compare("c"));
        assert(s4.compare(s8));
        assert(s4.compare("12345"));
        assert(s1.compare(s9));
        assert(s9.compare(""));
        assert(s2.compare(s10));
        assert(s10.compare(""));
        assert(s3.compare(s11));
        assert(s11.compare("c"));
        assert(s4.compare(s12));
        assert(s12.compare("12345"));

        s1 += s2;
        assert(s1.empty());
        assert(s1.length()   == 0);
        assert(s1.capacity() == 1);
        s1 += "";
        assert(s1.empty());
        assert(s1.length()   == 0);
        assert(s1.capacity() == 1);
        s1 += s4;
        assert(!s1.empty());
        assert(s1.length()   == 5);
        assert(s1.capacity() == 6);
        s1 += "6789";
        assert(!s1.empty());
        assert(s1.length()   == 9);
        assert(s1.capacity() == 10);
        assert(s1 == "123456789");
        s3 += 'c';
        s1 = s2 + s3 + s4;
        assert(s1 == "cc12345");
        s1 = s2 + s3 + s4 + "678";
        assert(s1 == "cc12345678");
        s1 = '0' + s4;
        assert(s1 == "012345");

        s1.clear();
        assert(s1.empty());
        assert(s1.length()   == 0);
        assert(s1.capacity() == 11);
        s1 += s4;
        assert(!s1.empty());
        assert(s1.length()   == 5);
        assert(s1.capacity() == 11);
        assert(s1 == "12345");

        s1.clear();
        assert(s1[0]   == NULL);
        assert(s1[100] == NULL);
        assert(s4[0]   == '1');
        assert(s4[4]   == '5');
        assert(s4[5]   == NULL);

        const CString s30;
        assert(s30[0] == NULL);
        const CString s31("abc123");
        assert(s31[0]  == 'a');
        assert(s31[5]  == '3');
        assert(s31[12] == NULL);
        assert(s30.at(0)  == NULL);
        assert(s31.at(0)  == 'a');
        assert(s31.at(5)  == '3');
        assert(s31.at(12) == NULL);

        assert(s1.at(0)   == NULL);
        assert(s1.at(100) == NULL);
        assert(s4.at(0)   == '1');
        assert(s4.at(4)   == '5');
        assert(s4.at(5)   == NULL);

        assert(s1.front() == NULL);
        assert(s30.front() == NULL);
        assert(s4.front() == '1');
        assert(s1.back()  == NULL);
        assert(s4.back()  == '5');
        assert(s31.front() == 'a');
        assert(s31.back()  == '3');

        assert(s1.substr(0)   == "");
        assert(s1.substr(0,0) == "");
        assert(s1.substr(0,1) == "");
        assert(s1.substr(1,2) == "");
        assert(s4.substr(0)   == "12345");
        assert(s4.substr(0,5) == "12345");
        assert(s4.substr(0,5) == "12345");
        assert(s4.substr(1)   == "2345");
        assert(s4.substr(1,3) == "234");

        s2.reserve(20);
        assert(s2.capacity() == 21);
        s2.reserve(1);
        assert(s2.capacity() == 21);
        s2 = "11111222223333344444";
        assert(s2.capacity() == 21);
        assert(s2 == "11111222223333344444");

        s2.resize(15);
        s1.shrink_to_fit();
        assert(s2.capacity() == 21);
        assert(s2 == "111112222233333");
        s2.resize(20,'4');
        assert(s2.capacity() == 21);
        assert(s2 == "11111222223333344444");
        s2.resize(25,'5');
        assert(s2.capacity() == 26);
        assert(s2 == "1111122222333334444455555");
        s2.resize(0);
        assert(s2.capacity() == 26);
        assert(s2 == "");
        s2.resize(5,'0');
        assert(s2.capacity() == 26);
        assert(s2 == "00000");

        s2.shrink_to_fit();
        assert(s2.capacity() == 6);
        s2.resize(0);
        s2.shrink_to_fit();
        assert(s2.capacity() == 1);

        CString s15("123456789", 0, 5);
        assert(s15 == "12345");
        assert(s15.capacity() == 6);
        CString s16("123456789", 5, 4);
        assert(s16 == "6789");
        assert(s16.capacity() == 5);
        CString s17(s16, 0, 2);
        assert(s17 == "67");
        assert(s17.capacity() == 3);
        CString s18((char*)nullptr, 10, 200);
        assert(s18.empty());
        assert(s18.capacity() == 1);
        CString s19(s16, 10, 200);
        assert(s19.empty());
        assert(s19.capacity() == 1);
        CString s20("", 10, 200);
        assert(s20.empty());
        assert(s20.capacity() == 1);
        CString s21("123456789", 4, CString::npos);
        assert(s21 == "56789");
        CString s22(s21, 2);
        assert(s22 == "789");
        CString s23(s21, 8);
        assert(s23 == "");
        CString s24((char**)nullptr, 16);
        assert(s24.empty());
        assert(s24.capacity() == 16);

        s1.resize(0);
        assert(s1 == "");
        s1.shrink_to_fit();
        assert(s1 == "");
        assert(s1.capacity() == 1);
        s1.insert(1, "");
        assert(s1 == "");
        assert(s1.capacity() == 1);
        s1.insert(1, "abc");
        assert(s1 == "");
        assert(s1.capacity() == 1);
        s1.insert(1, "a", 2);
        assert(s1 == "");
        assert(s1.capacity() == 1);
        s2 = "12789";
        s1.insert(0,s2);
        assert(s1 == "12789");
        assert(s1 == s2);
        s2 = "3456";
        s1.insert(2,s2);
        assert(s1 == "123456789");
        s2 = "0";
        s1.insert(0,s2);
        assert(s1 == "0123456789");
        assert(s1.capacity() == 11);
        s2 = "abc";
        s1.insert(10,s2);
        assert(s1 == "0123456789abc");
        assert(s1.capacity() == 14);

        char *arr_new{nullptr};
        CString *s40 = new CString(&arr_new, 16);
        *s40 = "abc";
        assert(*s40 == "abc");
        assert(s40->length() == 3);
        assert(s40->capacity() == 16);
        assert(strncmp(arr_new, "abc", 3) == 0);
        *s40 += "123";
        assert(strcmp(arr_new, "abc123") == 0);
        s40->clear();
        assert(strlen(arr_new) == 0);
        s40->shrink_to_fit();
        assert(*s40 == "");
        delete s40;
        s40 = nullptr;
        assert(arr_new != nullptr);
        delete arr_new;
        arr_new = nullptr;

        arr_new = new char[16]{};
        strcpy(arr_new,"abc");
        assert(strlen(arr_new) == 3);
        s40 = new CString(&arr_new, 16);
        assert(*s40 == "abc");
        assert(s40->length() == 3);
        assert(s40->capacity() == 16);
        assert(strncmp(arr_new, "abc", 3) == 0);
        *s40 += "123";
        assert(strcmp(arr_new, "abc123") == 0);
        s40->clear();
        assert(strlen(arr_new) == 0);
        s40->shrink_to_fit();
        assert(*s40 == "");
        delete s40;
        s40 = nullptr;
        assert(arr_new != nullptr);
        delete arr_new;
        arr_new = nullptr;

        CString s44(&arr_new, 16);
        s44 = "abc";
        assert(s44 == "abc");
        assert(s44.length() == 3);
        assert(s44.capacity() == 16);
        assert(strncmp(arr_new, "abc", 3) == 0);
        s44 += "123";
        assert(strcmp(arr_new, "abc123") == 0);
        s44.clear();
        assert(strlen(arr_new) == 0);
        s44.shrink_to_fit();
        assert(s44 == "");
        assert(arr_new != nullptr);
        delete arr_new;
        arr_new = nullptr;

        char arr_const[16];
        strcpy(arr_const, "abc123");
        CString *s41 = new CString(arr_const);
        *s41 += "abc";
        assert(*s41 == "abc123abc");
        assert(s41->length() == 9);
        assert(s41->capacity() == 10);
        s41->copyout(arr_const,16);
        assert(*s41 == arr_const);
        s41->clear();
        s41->shrink_to_fit();
        assert(*s41 == "");
        delete s41;

        strcpy(arr_const, "abcabc123123");
        CString s42(arr_const, 3, 6);
        s42 += "abc";
        assert(s42 == "abc123abc");
        assert(s42.length() == 9);
        assert(s42.capacity() == 10);
        s42.copyout(arr_const,16);
        assert(s42 == arr_const);
        s42.clear();
        s42.shrink_to_fit();
        assert(s42 == "");

        s1.resize(0);
        s1.shrink_to_fit();
        s1.insert(0,"12789");
        assert(s1 == "12789");
        s1.insert(2,"3456");
        assert(s1 == "123456789");
        s1.insert(0,"0");
        assert(s1 == "0123456789");
        assert(s1.capacity() == 11);
        s1.insert(10,"abc");
        assert(s1 == "0123456789abc");
        assert(s1.capacity() == 14);

        s1.resize(0);
        s1.shrink_to_fit();
        s1.insert(0,"12789",0,5);
        assert(s1 == "12789");
        s1.insert(2,"0123456789",3,4);
        assert(s1 == "123456789");
        s1.insert(0,"0",0,1);
        assert(s1 == "0123456789");
        assert(s1.capacity() == 11);
        s1.insert(10,s2,0,3);
        assert(s1 == "0123456789abc");
        assert(s1.capacity() == 14);

        s1.insert(0,4,'0');
        assert(s1 == "00000123456789abc");
        assert(s1.capacity() == 18);
        s1.insert(5,4,'1');
        assert(s1 == "000001111123456789abc");
        assert(s1.capacity() == 22);
        s1.insert(20,4,'c');
        assert(s1 == "000001111123456789abccccc");
        assert(s1.capacity() == 26);
        s1 = s2 + '1' + "23";
        assert(s1 == "abc123");
        s1.insert(6,"abcdefg",3);
        assert(s1 == "abc123defg");

        s1 = "000001111123456789abccccc";
        s1.erase(0,4);
        assert(s1 == "01111123456789abccccc");
        assert(s1.length() == 21);
        s1.erase(1,4);
        assert(s1 == "0123456789abccccc");
        assert(s1.length() == 17);
        s1.erase(12,4);
        assert(s1 == "0123456789abc");
        assert(s1.length() == 13);
        s1.erase(0,200);
        assert(s1 == "0123456789abc");
        assert(s1.length() == 13);
        s1.erase(4);
        assert(s1 == "0123");
        assert(s1.length() == 4);

        s1 = "0123456789abc";
        s2 = "abc";
        s1.shrink_to_fit();
        s1.replace(0,3,s2);
        assert(s1 == "abc3456789abc");
        assert(s1.length() == 13);
        s2 = "def";
        s1.replace(3,3,s2);
        assert(s1 == "abcdef6789abc");
        assert(s1.length() == 13);
        s2 = "012";
        s1.replace(10,3,s2);
        assert(s1 == "abcdef6789012");
        assert(s1.length() == 13);
        s2 = "0123456789abcdefghi";
        s1.replace(0,18,s2);
        assert(s1 == "0123456789abc");
        assert(s1.length() == 13);
        s1 = "0123456789abc";
        s1.shrink_to_fit();
        s1.replace(0,3,"abc");
        assert(s1 == "abc3456789abc");
        assert(s1.length() == 13);
        s1.replace(3,3,"def");
        assert(s1 == "abcdef6789abc");
        assert(s1.length() == 13);
        s1.replace(10,3,"012");
        assert(s1 == "abcdef6789012");
        assert(s1.length() == 13);
        s1.replace(0,18,"0123456789abcdefghi");
        assert(s1 == "0123456789abc");
        assert(s1.length() == 13);
        s1 = "0123456789abc";
        s1.shrink_to_fit();
        s1.replace(0,3,"abc",0);
        assert(s1 == "abc3456789abc");
        assert(s1.length() == 13);
        s1.replace(3,3,"abcdef",3);
        assert(s1 == "abcdef6789abc");
        assert(s1.length() == 13);
        s1.replace(10,3,"012",0);
        assert(s1 == "abcdef6789012");
        assert(s1.length() == 13);
        s1.replace(0,18,"0123456789abcdefghi",0);
        assert(s1 == "0123456789abc");
        assert(s1.length() == 13);
        s1.replace(0,5,"abc",0,3);
        assert(s1 == "abc3456789abc");
        assert(s1.length() == 13);
        s1 = "abcdef6789012";
        s1.replace(0,3,'.');
        assert(s1 == "...def6789012");
        assert(s1.length() == 13);
        s1.replace(3,3,'.');
        assert(s1 == "......6789012");
        assert(s1.length() == 13);
        s1.replace(12,1,'.');
        assert(s1 == "......678901.");
        assert(s1.length() == 13);
        s1.replace(16,1,'.');
        assert(s1 == "......678901.");
        assert(s1.length() == 13);
        s1.replace(0,100,'.');
        assert(s1 == ".............");
        assert(s1.length() == 13);
        s1.replace(0,CString::npos,'-');
        assert(s1 == "-------------");
        assert(s1.length() == 13);

        s1 = "0123456789abc";
        s1.shrink_to_fit();
        s2 = "012";
        assert(s1.find(s2) == 0);
        s2 = "abc";
        assert(s1.find(s2) == 10);
        s2 = "abcd";
        assert(s1.find(s2) == CString::npos);
        s2 = "012";
        assert(s1.find(s2,0) == 0);
        s2 = "abc";
        assert(s1.find(s2,6) == 10);
        s2 = "abc";
        assert(s1.find(s2,60) == CString::npos);

        assert(s1.find("012") == 0);
        assert(s1.find("abc") == 10);
        assert(s1.find("abcd") == CString::npos);
        assert(s1.find("012",0) == 0);
        assert(s1.find("abc",6) == 10);
        assert(s1.find("abc",60) == CString::npos);

        assert(s1.find("012",0,1) == 0);
        assert(s1.find("012",0,2) == 0);
        assert(s1.find("012",0,3) == 0);
        assert(s1.find("abc",4,3) == 10);
        assert(s1.find("abcd",0,4) == CString::npos);
        assert(s1.find("012",0,3) == 0);
        assert(s1.find("abc",6,3) == 10);
        assert(s1.find("abc",60,3) == CString::npos);
        assert(s1.find("abc",11,3) == CString::npos);
        assert(s1.find("abc",0,4) == CString::npos);
        assert(s1.find("abc",0,0) == CString::npos);

        assert(s1.find('0') == 0);
        assert(s1.find('c') == 12);
        assert(s1.find('a') == 10);
        assert(s1.find('z') == CString::npos);
        assert(s1.find('0',0) == 0);
        assert(s1.find('c',1) == 12);
        assert(s1.find('a',6) == 10);
        assert(s1.find('z',0) == CString::npos);
        assert(s1.find('0',10) == CString::npos);
        assert(s1.find('0',40) == CString::npos);

        s1 = "01234560123456";
        s2 = "6";
        assert(s1.rfind(s2) == 13);
        s2 = "56";
        assert(s1.rfind(s2) == 12);
        s2 = "456";
        assert(s1.rfind(s2) == 11);
        s2 = "012";
        assert(s1.rfind(s2) == 7);
        s2 = "a456";
        assert(s1.rfind(s2) == CString::npos);
        s2 = "6";
        assert(s1.rfind(s2,s1.length()) == 13);
        s2 = "56";
        assert(s1.rfind(s2,s1.length()) == 12);
        s2 = "456";
        assert(s1.rfind(s2,s1.length()) == 11);
        s2 = "012";
        assert(s1.rfind(s2,8) == 7);
        s2 = "a456";
        assert(s1.rfind(s2,s1.length()) == CString::npos);

        assert(s1.rfind("6")    == 13);
        assert(s1.rfind("56")   == 12);
        assert(s1.rfind("456")  == 11);
        assert(s1.rfind("012")  == 7);
        assert(s1.rfind("a456") == CString::npos);
        assert(s1.rfind("6",s1.length())    == 13);
        assert(s1.rfind("56",s1.length())   == 12);
        assert(s1.rfind("456",s1.length())  == 11);
        assert(s1.rfind("012",9)            == 7);
        assert(s1.rfind("a456",s1.length()) == CString::npos);

        assert(s1.rfind("6",s1.length(),1)    == 13);
        assert(s1.rfind("56",s1.length(),2)   == 12);
        assert(s1.rfind("456",s1.length(),3)  == 11);
        assert(s1.rfind("012",9,3)            == 7);
        assert(s1.rfind("012",9,2)            == 7);
        assert(s1.rfind("012",9,1)            == 7);
        assert(s1.rfind("012",9,4)            == CString::npos);
        assert(s1.rfind("012",9,0)            == CString::npos);
        assert(s1.rfind("456a",s1.length(),3) == 11);
        assert(s1.rfind("456a",s1.length(),4) == CString::npos);

        assert(s1.rfind('6') == 13);
        assert(s1.rfind('2') == 9);
        assert(s1.rfind('0') == 7);
        assert(s1.rfind('z') == CString::npos);
        assert(s1.rfind('6',s1.length())    == 13);
        assert(s1.rfind('2',s1.length())    == 9);
        assert(s1.rfind('0',s1.length())    == 7);
        assert(s1.rfind('0',5)              == 0);
        assert(s1.rfind('3',5)              == 3);
        assert(s1.rfind('0',90)             == CString::npos);
        assert(s1.rfind('z',s1.length())    == CString::npos);

        s1 = "";
        s1.uppercase();
        assert(s1 == "");
        s1 = "abcdefghijklmnopqrstuvwxyz";
        s1.uppercase();
        assert(s1 == "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        s1.lowercase();
        assert(s1 == "abcdefghijklmnopqrstuvwxyz");
        s1 = "";
        s1.lowercase();
        assert(s1 == "");
        s1 = "123abc123";
        s1.uppercase();
        assert(s1 == "123ABC123");
        s1.lowercase();
        assert(s1 == "123abc123");

        vector<CString> vec = s1.split('9');
        assert(vec[0] == "123abc123");

        vec = s1.split('1');
        assert(vec[0] == "23abc");
        assert(vec[1] == "23");
        vec = s1.split("1");
        assert(vec[0] == "23abc");
        assert(vec[1] == "23");
        vec = s1.split(CString("1"));
        assert(vec[0] == "23abc");
        assert(vec[1] == "23");

        vec = s1.split('2');
        assert(vec[0] == "1");
        assert(vec[1] == "3abc1");
        assert(vec[2] == "3");
        vec = s1.split("2");
        assert(vec[0] == "1");
        assert(vec[1] == "3abc1");
        assert(vec[2] == "3");
        vec = s1.split(CString("2"));
        assert(vec[0] == "1");
        assert(vec[1] == "3abc1");
        assert(vec[2] == "3");

        vec = s1.split("12");
        assert(vec[0] == "3abc");
        assert(vec[1] == "3");
        vec = s1.split(CString("12"));
        assert(vec[0] == "3abc");
        assert(vec[1] == "3");


        // more bad parameter and edge case checks
        char *p{nullptr};
        CString c1;
        CString c2(c1);
        CString d("abc");
        CString c3(&p,10);
        assert(c3 == "");
        assert(c3.length() == 0);
        assert(c3.capacity() == 10);
        delete p;
        p = nullptr;
        CString c4("abc",10);
        assert(c4 == "");
        assert(c4.length() == 0);
        assert(c4.capacity() == 1);
        CString c5("abc",0,5);
        assert(c5 == "");
        assert(c5.length() == 0);
        assert(c5.capacity() == 1);
        CString c6(d,10);
        assert(c6 == "");
        assert(c6.length() == 0);
        assert(c6.capacity() == 1);
        CString c7(d,0,5);
        assert(c7 == "");
        assert(c7.length() == 0);
        assert(c7.capacity() == 1);
        CString c8(&p,0);
        assert(c8 == "");
        assert(c8.length() == 0);
        assert(c8.capacity() == 1);
        delete p;
        p = nullptr;
        CString c9((char**)nullptr,0);
        assert(c9 == "");
        assert(c9.length() == 0);
        assert(c9.capacity() == 1);
        CString c10((char**)nullptr,10);
        assert(c10 == "");
        assert(c10.length() == 0);
        assert(c10.capacity() == 10);
        assert(c1[5] == NULL);
        assert(c1.at(5) == NULL);
        assert(c1.back() == NULL);
        assert(c1.front() == NULL);
        assert(c1 == c2);
        c2 = "abc";
        assert(c1 != c2);
        c1.insert(1,"abc",0,3);
        assert(c1 == "");
        c1.insert(0,"abc",5,3);
        assert(c1 == "");
        c1.insert(0,"abc",0,5);
        assert(c1 == "abc");
        c1.insert(2,"abc",2,CString::npos);
        assert(c1 == "abcc");
        c1.insert(9,32,'a');
        assert(c1 == "abcc");
        c1.insert(0,0,'a');
        assert(c1 == "abcc");
        c1.insert(2,3,'c');
        assert(c1 == "abccccc");
        c1.insert(0,3,'0');
        assert(c1 == "000abccccc");
        c1.insert(0,nullptr);
        assert(c1 == "000abccccc");
        c1.insert(0,nullptr,1);
        assert(c1 == "000abccccc");
        c1.insert(10,"abc",0);
        assert(c1 == "000abcccccabc");
        c1 = "";
        c1.shrink_to_fit();
        assert(c1 == "");
        assert(c1.capacity() == 1);
        c1.replace(0,0,nullptr,0,0);
        assert(c1 == "");
        assert(c1.capacity() == 1);
        c1.replace(0,0,nullptr,0);
        assert(c1 == "");
        assert(c1.capacity() == 1);
        c1.replace(0,0,nullptr);
        assert(c1 == "");
        assert(c1.capacity() == 1);
        c1 = "abc";
        c1.replace(0,0,'a');
        assert(c1 == "abc");
        assert(c1.capacity() == 4);
        c1.replace(4,0,'a');
        assert(c1 == "abc");
        assert(c1.capacity() == 4);
        c1.replace(4,1,'a');
        assert(c1 == "abc");
        assert(c1.capacity() == 4);
        c1.replace(3,3,'a');
        assert(c1 == "abc");
        assert(c1.capacity() == 4);
        c1.replace(2,3,'a');
        assert(c1 == "aba");
        assert(c1.capacity() == 4);
        c1 = "";
        c1.shrink_to_fit();
        assert(c1 == "");
        assert(c1.capacity() == 1);
        c1.replace(0,0,'a');
        assert(c1 == "");
        assert(c1.capacity() == 1);
        c1.replace(4,0,'a');
        assert(c1 == "");
        assert(c1.capacity() == 1);
        c1.replace(0,3,'a');
        assert(c1 == "");
        assert(c1.capacity() == 1);
        CString s50("123");
        c1 = "abc";
        c1.replace(4,0,s50);
        assert(c1 == "abc");
        c1.replace(0,0,s50);
        assert(c1 == "abc");
        c1 = "";
        c1.shrink_to_fit();
        assert(c1 == "");
        assert(c1.capacity() == 1);
        c1.replace(0,0,s50,4,1);
        assert(c1 == "");
        assert(c1.capacity() == 1);
        c1.replace(4,1,nullptr);
        assert(c1 == "");
        assert(c1.capacity() == 1);
        c1 = "abc";
        assert(c1 == "abc");
        assert(c1.capacity() == 4);
        c1.replace(2,2,"123",0,3);
        assert(c1 == "ab1");
        assert(c1.capacity() == 4);
        c1.replace(1,2,"123456",2,4);
        assert(c1 == "a34");
        assert(c1.capacity() == 4);
        c1.replace(0,3,"0123456",4,1);
        assert(c1 == "434");
        assert(c1.capacity() == 4);
        c1 = nullptr;
        c1.shrink_to_fit();
        assert(c1 == "");
        assert(c1.length() == 0);
        assert(c1.capacity() == 1);
        c1 += (char*)nullptr;
        assert(c1 == "");
        assert(c1.length() == 0);
        assert(c1.capacity() == 1);
        c1 = (char*)nullptr;
        assert(c1 != (char*)nullptr);
        c1 = "";
        c1.shrink_to_fit();
        assert(c1 == "");
        assert(c1.length() == 0);
        assert(c1.capacity() == 1);
        c1.erase(4);
        assert(c1 == "");
        assert(c1.length() == 0);
        assert(c1.capacity() == 1);
        c1 = "abc";
        c1.shrink_to_fit();
        assert(c1 == "abc");
        assert(c1.length() == 3);
        assert(c1.capacity() == 4);
        c1.erase(4);
        assert(c1 == "abc");
        assert(c1.length() == 3);
        assert(c1.capacity() == 4);
        c1.erase(4,1);
        assert(c1 == "abc");
        assert(c1.length() == 3);
        assert(c1.capacity() == 4);
        c1.erase(0,0);
        assert(c1 == "abc");
        assert(c1.length() == 3);
        assert(c1.capacity() == 4);
        c1.erase(0,4);
        assert(c1 == "abc");
        assert(c1.length() == 3);
        assert(c1.capacity() == 4);
        c1.erase(0);
        assert(c1 == "");
        assert(c1.length() == 0);
        assert(c1.capacity() == 4);
        c1 = "";
        c1.shrink_to_fit();
        assert(c1 == "");
        assert(c1.length() == 0);
        assert(c1.capacity() == 1);
        assert(c1.c_str() != nullptr);
        assert(c1.data() != nullptr);
        assert(strlen(c1.data()) == 0);
        char out[16]{};
        c1.copyout(nullptr, 16);
        c1.copyout(out,16);
        assert(strlen(out) == 0);
        c1.copyout(out, 100);
        assert(strlen(out) == 0);
        c1 = "abc123";
        c1.copyout(out, 6);
        assert(strcmp(out,"abc123"));
        c1.copyout(out, 3);
        assert(strcmp(out,"abc"));
        s50 = "abc";
        assert(c1.find(s50, 100) == CString::npos);
        assert(c1.find(nullptr) == CString::npos);
        assert(c1.find(p, 0) == CString::npos);
        assert(c1.find(out, 0, 100) == CString::npos);
        assert(c1.find(s50, 100) == CString::npos);
        assert(c1.find('a', 100) == CString::npos);
        s50 = "abc";
        assert(c1.rfind(s50, 100) == CString::npos);
        assert(c1.rfind(nullptr) == CString::npos);
        assert(c1.rfind(p, 0) == CString::npos);
        assert(c1.rfind(out, 0, 100) == CString::npos);
        assert(c1.rfind(s50, 100) == CString::npos);
        assert(c1.rfind('a', 100) == CString::npos);
        assert(c1.substr(0) == "abc123");
        assert(c1.substr(1,2) == "bc");
        assert(c1.substr(5,1) == "3");
        assert(c1.substr(6,1) == "");
        assert(c1.substr(100) == "");
        assert(c1.substr(100,6) == "");
        assert(c1.substr(0,100) == "abc123");
        assert(c1.compare(CString()) == false);
        assert(c1.compare(nullptr) == false);
        CString s60("abc");
        assert(c1.compare(CString("")) == false);
        assert(c1.compare("") == false);
        assert(c1.compare(CString("a")) == false);
        assert(c1.compare("a") == false);
        c1 = "";
        c1.shrink_to_fit();
        c2 = "";
        c2.shrink_to_fit();
        assert(c1 != nullptr);
        assert((c1 == nullptr) == false);
        assert(c1 == nullptr + c2);
        assert(c1 == c2 + nullptr);
        vec.clear();
        assert(vec.empty());
        vec = c1.split(nullptr);
        assert(vec.empty());

        // From the wiki page:

        const char *ABC = "abc";
        const char *OTT = "123";
        const char *TEXT = "   abc   123   456   ";

        char *s;  // The User c-string to modify

        // 1. Use CString to create and modify a c-string, with no reallocs
        CString cs1(64);     // A new c-string is malloc'd with a capacity of
                             //  64 bytes
        // do many mods which do not cause a realloc,
        //  since the length does not grow past 64 bytes
        cs1 = "123";
        cs1 += "yada";
        cs1 += "yada";
        cs1 += "yada";
        cs1 += TEXT;
        assert(cs1.length() == 36);
        // The cs1 dtor cleans up the malloc

        // 2. Modify an existing c-string
        s = nullptr;
        CString cs2a(&s, 16);         // s is nullptr, so malloc capacity of 16
                                      // cs2a now modifies s
        cs2a = "abc";                 // cs2a and s are both "123", with a null
                                      //  at the end
        assert(cs2a.length() == 3);
        assert(cs2a.capacity() == 16);
        delete s;                     // User is responsible to free the memory
        s = nullptr;

        s = new char[16]{};           // malloc a User c-string
        CString cs2(&s, 16);          // cs2 now modifies s, capacity==16 bytes
        cs2 = "abc";                  // cs2 and s are both "123", with a null
                                      //  at the end
        cs2.insert(3, TEXT, 9, 3);    // insert 123 after abc
        assert(cs2.length() == 6);    // six chars, abc123
        assert(cs2 == "abc123");
        assert(cs2 == s);             // cs2 and s point to the same char array
        cs2.clear();                  // cs2 and s are empty, with a null
        assert(cs2 == "");
        assert(cs2.length() == 0);    // empty
        assert(cs2.capacity() == 16); // capacity has not changed
        delete s;                     // User is responsible to free the memory
        s = nullptr;

        // 3. Use CString to malloc a new c-string
        CString cs3(&s, 16);           // because s is null, malloc a c-string
                                       //  with a capacity of 16 bytes
                                       // cs3 and s point to the new c-string
        assert(cs3 == "");
        assert(cs3.length() == 0);     // empty
        assert(cs3.capacity() == 16);
        cs3 += OTT;                    // cs3 and s are "123"
        cs3 += OTT;                    // cs3 and s are "123123"
        cs3.replace(0, 3, TEXT, 3, 3); // replace the first 123 with abc
        assert(cs3 == "abc123");
        assert(cs3 == s);              // cs3 and s point to the same char array
        delete s;                      // The user is responsible for the
                                       //  c-string cleanup
        s = nullptr;

        // 4. Use CString to modify and resize an existing c-string

        s = new char[16]{};
        CString cs4(&s, 16);          // cs4 can now modify s with a capacity of
                                      //  16 bytes
        cs4 = "123";                  // cs4 and s is "123", with a null at the end
        assert(cs4.length() == 3);
        assert(cs4.capacity() == 16); // capacity has not changed
        cs4.shrink_to_fit();          // cs4 and s is realloc'd to 4 bytes
                                      //  (3 chars plus the null)
        assert(cs4.length() == 3);    // three chars
        assert(cs4.capacity() == 4);  // three chars plus a null
        assert(cs4 == "123");
        assert(cs4 == s);             // cs4 and s point to the same char array
        delete s;                     // The user is responsible for the
                                      //  c-string cleanup
        s = nullptr;

        // 5. Create, modify, and copyout a new c-string
        char arr[16]{};               // char array for the copyout
        CString cs5(16);              // malloc an empty c-string
        assert(cs5.length() == 0);
        assert(cs5.capacity() == 16);
        cs5 = ABC;
        cs5.copyout(arr,16);
        assert(cs5 == arr);

        // 6. Split CString into a vector of CStrings
        CString cs6("/dir1/dir2/filename");
        vector<CString> vec_dirs = cs6.split('/');
        assert(vec_dirs[0] == "dir1");
        assert(vec_dirs[1] == "dir2");
        assert(vec_dirs[2] == "filename");

        TS_INFO("<testCString");
    }
};

#endif
