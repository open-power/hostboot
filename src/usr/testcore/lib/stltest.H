//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/testcore/lib/stltest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __LIB_STLTEST_H
#define __LIB_STLTEST_H

#include <cxxtest/TestSuite.H>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <iterator>

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

            // test map::insert(v), map::insert(h,v), lower_bound()
            mymap.insert(std::map<V,V>::value_type(v2,v2));  //map::insert(v);

            std::map<V,V> mymap2;
            std::map<V,V,std::greater<V> > mymap3;

            if(!mymap2.empty()) // map::empty()
            {
                TS_FAIL("map::empty test failed");
            }

            mymap2 = mymap;     // map::operator=
            mymap3.insert(mymap2.begin(),mymap2.end());

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
};
#endif
