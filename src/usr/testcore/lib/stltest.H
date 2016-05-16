/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/stltest.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
#ifndef __LIB_STLTEST_H
#define __LIB_STLTEST_H

#include <cxxtest/TestSuite.H>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <iterator>
#include <functional>

class STLTest : public CxxTest::TestSuite
{
    public:
        class V
        {
            public:
                V() : iv_val(0) {}
                V(size_t v) : iv_val(v) {}

                // Should only need operator<
                bool operator<(const V & v) const
                {
                    return (this->iv_val < v.iv_val);
                }
                bool operator>(const V & v) const
                {
                    return (this->iv_val > v.iv_val);
                }

                size_t value() const { return iv_val; }

            private:
                size_t iv_val;

                bool operator==(const V & v) const;
        };

        void testMap()
        {
            std::map<V,V> mymap;  // map::map()
            V v0 = V(0);
            V v1 = V(1);
            V v2 = V(2);
            V v3 = V(3);
            V v4 = V(4);
            V v5 = V(5);
            V v6 = V(6);
            V v7 = V(7);
            V v8 = V(8);
            V v9 = V(9);

            mymap[v1] = v1;     // map::operator[] assign
            mymap[v0] = v0;
            mymap[v9] = v9;
            mymap[v6] = v6;
            mymap[v4] = v4;

            if(mymap.size() != 5)       // map::size()
            {
                TS_FAIL("map::size test failed with %ld\n",mymap.size());
            }

            mymap[v5] = v5;
            mymap[v3] = v3;

            if (v5.value() != mymap[v5].value())   // map::operator[] value
            {
                TS_FAIL("map::operator[] returned wrong value %d",
                        mymap[v5].value());
            }

            // test map::insert(v), map::insert(h,v), lower_bound()
            mymap.insert(std::map<V,V>::value_type(v2,v2));  //map::insert(v);

            std::map<V,V> mymap2;
            std::map<V,V,std::greater<V> > mymap3;

            if(!mymap2.empty()) // map::empty()
            {
                TS_FAIL("map::empty test failed");
            }

            mymap2 = mymap;     // map::operator=
            if (mymap2.size() != mymap.size())
            {
                TS_FAIL("map::operator= test failed");
            }

            mymap3.insert(mymap2.begin(),mymap2.end());
            if (mymap3.size() != mymap2.size())
            {
                TS_FAIL("map::insert(itr,itr) test failed");
            }

            mymap.erase(mymap.begin(),mymap.end());     //map::erase(itr,itr)

            if(!mymap.empty())
            {
                TS_FAIL("map::erase test failed");
            }

            mymap.swap(mymap2);         //map::swap()

            std::map<V,V>::iterator i = mymap.end();    //map::end()
            --i;
            mymap.insert(i,std::map<V,V>::value_type(v8,v8)); //map::insert(h,v)

            i = mymap.find(v1); //map::find()
            if(i == mymap.end() || (i->second).value() != v1.value())
            {
                TS_FAIL("map::find test failed");
            }

            i = mymap.find(v7);
            if(i != mymap.end())
            {
                TS_FAIL("map::find (not found) test failed");
            }

            for(i = mymap.begin(); i != mymap.end(); ++i) //map::begin();
            {
                mymap3[i->first] = i->second;
                if((i->first).value() != (i->second).value())
                {
                    TS_FAIL("map::iterator test failed");
                }
                //printk("MAP %ld:%ld\n",(i->first).value(),(i->second).value());
            }

            // test const iterators, begin(), end()
            for(std::map<V,V>::const_iterator ci = mymap.begin();
                ci != mymap.end(); ++ci)
            {
                if((ci->first).value() != (ci->second).value())
                {
                    TS_FAIL("map::const_iterator test failed");
                }
            }
            std::pair < std::map<V,V>::const_iterator ,
                       std::map<V,V>::const_iterator > p =
                                                    mymap.equal_range(v5);

            if(((p.first)->first).value() != v5.value())
            {
                TS_FAIL("map::equal_range test failed");
            }

            // mymap and mymap3 should be same size, but reverse order
            if(mymap.size() != mymap3.size())
            {
                TS_FAIL("stl::map fail Compare template size test");
            }
            i = mymap.end();
            --i;
            for(std::map<V,V,std::greater<V> >::iterator i3 = mymap3.begin();
                i3 != mymap3.end(); ++i3)
            {
                if((i->first).value() != (i3->first).value())
                {
                    TS_FAIL("std::map fail Compare template value test");
                }
                --i;
            }

            // Test copy constructor.
            std::map<V,V> mymap4(mymap);

            if (mymap.size() != mymap4.size())
            {
                TS_FAIL("stl::map fail Copy constructor size test.");
            }

            // Test range constructor.
            std::map<V,V> mymap5(mymap.begin(), mymap.end());

            if (mymap.size() != mymap5.size())
            {
                TS_FAIL("stl::map fail Range constructor size test.");
            }

            // Test erase by key.
            mymap5.erase(v2);
            if (mymap5.end() != mymap5.find(v2))
            {
                TS_FAIL("std::map fail Erase by iterator test.");
            }
            if (mymap.size() != (mymap5.size() + 1))
            {
                TS_FAIL("std::map fail Erase by iterator size test.");
            }

            // Test erase of root node.  (find will splay to top).
            mymap5.erase(mymap5.find(v6));
            if (mymap5.end() != mymap5.find(v6))
            {
                TS_FAIL("std::map fail Erase by iterator to root test.");
            }
            if (mymap.size() != (mymap5.size() + 2))
            {
                TS_FAIL("std::map fail Erase by iterator to root size test.");
            }


        }


        void testAdvance()
        {
            // Test for a non-random-access iterator, such as list.
            std::list<int> list;

            for(int i = 0; i < 100; i++)
                list.push_back(i);

            for (int i = 0; i < 100; i++)
            {
                std::list<int>::iterator itr = list.begin();
                std::advance(itr, i);
                if (*itr != i)
                {
                    TS_FAIL("List iterator value mismatch %d:%d.", *itr, i);
                }
            }

            // Test for a random-access iterator, such as vector.
            std::vector<int> vector;

            for (int i = 0; i < 100; i++)
                vector.push_back(i);

            for (int i = 0; i < 100; i++)
            {
                std::vector<int>::iterator itr = vector.begin();
                std::advance(itr, i);
                if (*itr != i)
                {
                    TS_FAIL("Vector iterator value mismatch %d:%d.", *itr, i);
                }
            }
        }

        void testDistance()
        {
            // Test for a non-random-access iterator, such as list.
            std::list<int> list;

            for (int i = 0; i < 100; i++)
                list.push_back(i);

            for (int i = 0; i < 100; i++)
                for (int j = 0; j < 100; j++)
                {
                    // distance isn't defined for non-random-access iterator
                    // when "first" is greater than "last".
                    if (i > j) continue;

                    std::list<int>::iterator itr_i = list.begin(),
                                             itr_j = list.begin();

                    std::advance(itr_i, i);
                    std::advance(itr_j, j);

                    ssize_t d = std::distance(itr_i, itr_j);

                    if (d != (j-i))
                    {
                        TS_FAIL("List distance incorrect %d:%d:%d",
                                i, j, d);
                    }
                }

            // Test for a random-access iterator, such as vector.
            std::vector<int> vector;

            for (int i = 0; i < 100; i++)
                vector.push_back(i);

            for (int i = 0; i < 100; i++)
                for (int j = 0; j < 100; j++)
                {
                    std::vector<int>::iterator itr_i = vector.begin(),
                                               itr_j = vector.begin();

                    std::advance(itr_i, i);
                    std::advance(itr_j, j);

                    ssize_t d = std::distance(itr_i, itr_j);

                    if (d != (j-i))
                    {
                        TS_FAIL("Vector distance incorrect %d:%d:%d",
                                i, j, d);
                    }
                }

        }

        void testVector()
        {
            std::vector<int> v;
            v.reserve(100);

            for(int i = 0; i < 100; ++i)
            {
                v.push_back(i);
            }

            std::vector<int>::iterator itr = v.begin();
            std::advance(itr, 50);
            if(*itr != 50)
            {
                TS_FAIL("Vector iterator not pointing at the right value. %d",*itr);
            }

            itr = v.erase(itr);
            if(v.size() != 99)
            {
                TS_FAIL("Vector is not correct size after erase. %d",v.size());
            }
            if(*itr != 51)
            {
                TS_FAIL("Vector::erase did not erase the correct element. %d",*itr);
            }
            itr = v.erase(itr,v.end());
            if(itr != v.end())
            {
                TS_FAIL("Vector erase to end not at end()");
            }
        }

        template<typename T> struct ForEachFunctor
            : public std::unary_function<const T&, void>
        {
            ForEachFunctor() : count(0) {};

            void operator()(const T&) { ++count; };

            size_t count;
        };

        void testForEach()
        {
            std::vector<int> v;
            const size_t COUNT = 10;
            for (size_t i = 0; i < COUNT; i++)
            {
                v.push_back(i);
            }
            ForEachFunctor<int> f;
            f = std::for_each(v.begin(), v.end(), f);

            if (f.count != COUNT)
            {
                TS_FAIL("Functor called incorrect number of times.");
            }
        }

        template<typename T> struct RemoveFunctor
            : public std::unary_function<const T&, bool>
        {
            bool operator()(const T& i) { return (i == 3) || (i == 7); }
        };

        void testRemove()
        {
            std::vector<int> v;
            const size_t COUNT = 10;
            for (size_t i = 0; i < COUNT; i++)
            {
                v.push_back(i);
            }

            if (std::distance(v.begin(), v.end()) != (ssize_t) COUNT)
            {
                TS_FAIL("Incorrect number of elements in the vector.");
            }

            std::vector<int>::iterator new_last =
                    std::remove(v.begin(), v.end(), 4);

            if (std::distance(v.begin(), new_last) != (COUNT - 1))
            {
                TS_FAIL("Remove did not move 1 element.");
            }

            new_last =
                std::remove_if(v.begin(), new_last, RemoveFunctor<int>());

            if (std::distance(v.begin(), new_last) != (COUNT - 3))
            {
                TS_FAIL("Remove_if did not move 2 element.");
            }
        }

        void testUnique()
        {
            std::vector<int> v;
            const size_t COUNT = 10;
            for (size_t i = 0; i < COUNT; i++)
            {
                v.push_back(i);
            }

            std::vector<int>::iterator new_last =
                std::unique(v.begin(), v.end());

            if (new_last != v.end())
            {
                TS_FAIL("Unique removed elements.");
            }

            v.clear();
            v.push_back(1);
            v.push_back(2);
            v.push_back(2); // Remove item 1
            v.push_back(3);
            v.push_back(4);
            v.push_back(4); // Remove item 2
            v.push_back(4); // Remove item 3
            v.push_back(5);
                // Total of 8 items.

            new_last = std::unique(v.begin(), v.end());

            if (std::distance(v.begin(), new_last) != 5)
            {
                TS_FAIL("Incorrect number of items removed by unique.");
            }
        }

        void testSort()
        {
            std::vector<int> v;
            v.push_back(1);
            v.push_back(4);
            v.push_back(2);
            v.push_back(8);
            v.push_back(5);
            v.push_back(7);
            std::sort(v.begin(), v.end());

            for(size_t i = 0; i < (v.size()-1); i++)
            {
                if (v[i] >= v[i+1])
                {
                    TS_FAIL("Element %d is in incorrect position. %d:%d",
                            i, v[i], v[i+1]);
                }
            }

        }

        void testInitListCompile()
        {
            // Code wont compile if this doesn't work
            std::vector< std::vector<int> > v = { {},{1},{1,2,3} };
            std::list< std::list<int> > l = { {},{1},{1,2,3} };
        }

        void testEmplace()
        {
            std::map<int, char> m;

            // uses pair's move constructor
            m.emplace(std::make_pair(1, 'c'));
            if (m.size() != 1)
            {
                TS_FAIL("testEmplace(): Expected map size 1, found size %d", m.size());
            }

            // add another pair
            m.emplace(std::make_pair(2, 'a'));
            if (m.size() != 2)
            {
                TS_FAIL("testEmplace(): Expected map size 2, found size %d", m.size());
            }

            // 3.1 -> 3
            // 65 = ascii 'A'
            m.emplace(std::make_pair(3.1, 65));
            if (m.size() != 3)
            {
                TS_FAIL("testEmplace(): Expected map size 3, found size %d", m.size());
            }

            m.emplace(4, 'W');
            if (m.size() != 4)
            {
                TS_FAIL("testEmplace(): Expected map size 4, found size %d", m.size());
            }

            for (const auto &p : m) {
                if (p.first == 1)
                {
                    if (p.second != 'c')
                    {
                        TS_FAIL("Expected {1 => c} pair");
                    }
                }
                else if (p.first == 2)
                {
                    if (p.second != 'a')
                    {
                        TS_FAIL("Expected {2 => a} pair");
                    }
                }
                else if (p.first == 3)
                {
                    if (p.second != 'A')
                    {
                        TS_FAIL("Unexpected pair {%d => %c}", p.first, p.second);
                    }
                }
                else if (p.first == 4)
                {
                    if (p.second != 'W')
                    {
                        TS_FAIL("Unexpected pair {%d => %c}", p.first, p.second);
                    }
                }
            }

            std::map<int, int> mi;
            for (size_t i = 0; i < 10; ++i)
            if (!mi.emplace(i,i).second)
            {
                TS_FAIL("Emplace did not insert %d", i);
            }
            if (mi.emplace(5,100).second)
            {
                TS_FAIL("Emplace did an insert of an already existing key");
            }
        }

};
#endif
