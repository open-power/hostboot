/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/cstring.C $                                           */
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

/**
 * @file cstring.C
 *
 * @brief Implementations of CString class and functions
 */

#include <cstdlib>
#include <ctype.h>
#include <cstring.H>

using namespace std;

#define MEMCPY(d,s,l) __builtin_memcpy(d,s,l)
#define MEMCMP(a,b,l) __builtin_memcmp(a,b,l)
#define STRSTR(h,n)   __builtin_strstr(h,n)
#define STRCHR(s,c)   __builtin_strchr(s,c)
#define MEMSET(a,c,n) __builtin_memset(a,c,n)
#define REALLOC(s) \
    m_buf      = static_cast<char*>(realloc(m_buf, s)); \
    m_capacity = s;                                     \
    m_buf_ptr  = &m_buf;

void SHIFT_MEM(char* buf, size_t a, size_t b, size_t len)
{
    // move len chars from pos a to pos b
    // move chars in reverse order so we dont clobber as we move
    // ie, shift chars to the right in buf, start with the last char
    while (len--)
    {
        buf[b+len]   = buf[a+len];
    }
}

CString::CString()
{
    m_len        = 0;
    m_capacity   = m_len + 1;
    m_buf        = new char[m_capacity]{};
    m_buf[m_len] = NULL;
    m_buf_ptr    = &m_buf;
}

CString::CString(size_t capacity)
{
    m_len        = 0;
    m_capacity   = capacity;
    m_buf        = new char[m_capacity]{};
    m_buf[m_len] = NULL;
    m_buf_ptr    = &m_buf;
}

CString::CString(const char c)
{
    m_len        = 1;
    m_capacity   = m_len + 1;
    m_buf        = new char[m_capacity]{};
    m_buf[0]     = c;
    m_buf[m_len] = NULL;
    m_buf_ptr    = &m_buf;
}

CString::CString(size_t n, const char c)
{
    m_len        = n;
    m_capacity   = m_len + 1;
    m_buf        = new char[m_capacity]{};
    m_buf[m_len] = NULL;
    m_buf_ptr    = &m_buf;
    MEMSET(m_buf, c, n);
}

CString::CString(char** p_buf, size_t capacity)
{
    m_free = false; // do not free m_buf in the dtor, it is the user's ptr

    if (p_buf == nullptr || *p_buf == nullptr)
    {
        m_len        = 0;
        m_capacity   = capacity == 0 ? 1 : capacity;
        m_buf        = new char[m_capacity]{};
        m_buf[m_len] = NULL;
        m_buf_ptr    = &m_buf;
        if (p_buf) {*p_buf = m_buf;}
        return;
    }
    m_len      = strlen(*p_buf);
    m_capacity = capacity;
    m_buf      = *p_buf;
    m_buf_ptr  = p_buf;
}

CString::CString(const CString& s, size_t pos, size_t len)
{
    size_t s_len = s.length();
    if (len == npos)
    {
        len = s_len - pos;
    }
    if ( (s_len == 0)  ||
         (pos > s_len) ||
         (len <= 0)    ||
         (len > s_len-pos) )
    {
        m_len      = 0;
        m_capacity = m_len + 1;
        m_buf      = new char[m_capacity]{};
        m_buf[0]   = NULL;
        m_buf_ptr  = &m_buf;
        return;
    }
    reserve(len);
    MEMCPY(m_buf, s.c_str()+pos, len);
    m_len        = len;
    m_buf[m_len] = NULL;
    m_buf_ptr    = &m_buf;
}

CString::CString(const char *s, size_t pos, size_t len)
{
    size_t s_len{};
    if (s == nullptr)
    {
        s_len = 0;
    }
    else
    {
        s_len = strlen(s);
    }
    if (len == npos)
    {
        len = s_len - pos;
    }
    if ( (s_len == 0)  ||
         (pos > s_len) ||
         (len <= 0)    ||
         (len > s_len-pos) )
    {
        m_len      = 0;
        m_capacity = m_len + 1;
        m_buf      = new char[m_capacity]{};
        m_buf_ptr  = &m_buf;
        return;
    }
    m_len        = len;
    reserve(m_len);
    MEMCPY(m_buf, s+pos, m_len);
    m_buf[m_len] = NULL;
    m_buf_ptr    = &m_buf;
}

CString::~CString()
{
    if (m_free)
    {
        delete m_buf;
    }
}

const char* rstrstr(const char *haystack, size_t pos, const char *needle)
{
    if (!haystack || !needle)
    {
        return nullptr;
    }
    size_t needle_len   = strlen(needle);
    size_t haystack_len = strlen(haystack);
    char *rhaystack = const_cast<char*>(haystack);

    if (haystack_len < pos)
    {
        return nullptr;
    }
    if (pos)
    {
        rhaystack += pos;
    }
    else
    {
        rhaystack += haystack_len-1;
    }

    while (rhaystack >= haystack)
    {
        if (*rhaystack != *needle)
        {
            --rhaystack;
            continue;
        }
        if (strncmp(needle, rhaystack, needle_len) == 0)
        {
            return rhaystack;
        }

        --rhaystack;
    }

    return nullptr;
}

CString& CString::uppercase()
{
    for (size_t i=0; i<m_len; i++)
    {
        if (m_buf[i] >= 'a' && m_buf[i] <= 'z')
        {
            m_buf[i] &= ~0x20;
        }
    }
    return *this;
}

CString& CString::lowercase()
{
    for (size_t i=0; i<m_len; i++)
    {
        if (m_buf[i] >= 'A' && m_buf[i] <= 'Z')
        {
            m_buf[i] |= 0x20;
        }
    }
    return *this;
}

void CString::copyout(char* s, size_t capacity)
{
    size_t len{m_len};
    if (capacity == 0) {return;}
    if (m_len > capacity-1)
    {
        len = capacity-1;
    }
    if (s)
    {
        strncpy(s, m_buf, len);
        s[len] = NULL;
    }
}

int CString::compare(const CString& str) const
{
    if (m_len != str.length()) {return false;}
    return (MEMCMP(m_buf, str.c_str(), m_len) == 0);
}

int CString::compare(const char* s) const
{
    if (s == nullptr)       {return false;}
    if (m_len != strlen(s)) {return false;}
    return (MEMCMP(m_buf, s, m_len) == 0);
}

size_t CString::rfind(const CString& s, size_t pos) const
{
    if (pos > m_len)
    {
        return npos;
    }
    const char *p = rstrstr(m_buf, pos, s.c_str());
    if (p == nullptr)
    {
        return npos;
    }
    return (p-m_buf);
}

size_t CString::rfind(const CString& s) const
{
    return rfind(s, m_len-1);
}

size_t CString::rfind(const char* cstr, size_t pos) const
{
    if (pos > m_len)
    {
        return npos;
    }
    if (cstr == nullptr)
    {
        return npos;
    }
    const char *p = rstrstr(m_buf, pos, cstr);
    if (p == nullptr)
    {
        return npos;
    }
    return (p-m_buf);
}

size_t CString::rfind(const char* cstr) const
{
    return rfind(cstr, m_len-1);
}

size_t CString::rfind(const char* cstr, size_t pos, size_t n) const
{
    if (cstr == nullptr)
    {
        return npos;
    }
    if (n == 0 || strlen(cstr) < n)
    {
        return npos;
    }
    CString s(cstr,0,n);
    return rfind(s,pos);
}

size_t CString::rfind(char c, size_t pos) const
{
    char s[2]{};
    s[0]=c;
    return rfind(s,pos);
}

size_t CString::rfind(char c) const
{
    return rfind(c, m_len-1);
}

size_t CString::find(const char* cstr) const
{
    return find(cstr, 0);
}

size_t CString::find(const char* cstr, size_t pos) const
{
    if (cstr == nullptr)
    {
        return npos;
    }
    char *start = m_buf+pos;
    char *p = STRSTR(start, cstr);
    if (p == nullptr)
    {
        return npos;
    }
    return (p-m_buf);
}

size_t CString::find(const char* cstr, size_t pos, size_t n) const
{
    if (cstr == nullptr)
    {
        return npos;
    }
    if (n == 0 || strlen(cstr) < n)
    {
        return npos;
    }
    CString s(cstr,0,n);
    return find(s,pos);
}

size_t CString::find(char c, size_t pos) const
{
    char *start = m_buf+pos;
    char *p = STRCHR(start, c);
    if (p == nullptr)
    {
        return npos;
    }
    return (p-m_buf);
}

size_t CString::find(char c) const
{
    return find(c,0);
}

size_t CString::find(const CString& s) const
{
    return find(s,0);
}

size_t CString::find(const CString& s, size_t pos) const
{
    char *start = m_buf+pos;
    char *p = STRSTR(start, s.c_str());
    if (p == nullptr)
    {
        return npos;
    }
    return (p-m_buf);
}

CString& CString::replace(size_t pos,
                          size_t len,
                          const char* s,
                          size_t subpos,
                          size_t sublen)
{
    if (s == nullptr)
    {
        return *this;
    }
    size_t s_len = strlen(s);
    if (sublen == npos)
    {
        sublen = s_len - subpos;
    }
    if (pos > m_len || subpos > s_len || subpos+sublen > s_len)
    {
        return *this;
    }
    if (len > sublen)
    {
        len = sublen;
    }
    if (pos+len > m_capacity-1)
    {
        len = m_capacity - pos -1; // allow it to fill the existing capacity
    }
    MEMCPY(m_buf+pos, s+subpos, len);
    return *this;
}

CString& CString::replace(size_t pos,
                          size_t len,
                          const CString& str,
                          size_t subpos,
                          size_t sublen)
{
    return replace(pos, len, str.c_str(), subpos, sublen);
}

CString& CString::replace(size_t pos, size_t len, const CString& s)
{
    return replace(pos, len, s.c_str(), 0, s.length());
}

CString& CString::replace(size_t pos, size_t len, const char* s)
{
    if (s == nullptr)
    {
        return *this;
    }
    replace(pos, len, s, 0, strlen(s));
    return *this;
}

CString& CString::replace(size_t pos, size_t len, char c)
{
    if (pos > m_len)
    {
        return *this;
    }
    if (len == npos || len > m_capacity-pos)
    {
        len = m_capacity-pos-1; // set all available bytes except the null
    }
    MEMSET(m_buf+pos, c, len);
    m_len = strlen(m_buf);
    return *this;
}

CString& CString::insert(size_t pos, const CString& str, size_t subpos, size_t sublen)
{
    insert(pos, str.c_str(), subpos, sublen);
    return *this;
}

CString& CString::insert(size_t pos, const char* s, size_t subpos, size_t sublen)
{
    if (pos > m_len || s == nullptr)
    {
        return *this;
    }
    size_t s_len = strlen(s);
    if (s_len == 0 || subpos > s_len)
    {
        return *this;
    }
    size_t len = s_len;
    if (sublen < len)
    {
        len = sublen;
    }
    if (len > s_len-subpos)
    {
        len = s_len-subpos;
    }
    reserve(m_len + len);
    // move chars in m_buf to make room for s
    SHIFT_MEM(m_buf, pos, pos+len, m_len-pos);
    // copy in s
    MEMCPY(m_buf+pos, s+subpos, len);
    m_len += len;
    m_buf[m_len] = NULL;
    return *this;
}

CString& CString::insert(size_t pos, const char* s)
{
    if (s == nullptr)
    {
        return *this;
    }
    size_t s_len = strlen(s);
    return insert(pos, s, 0, s_len);
}

CString& CString::insert(size_t pos, const CString& s)
{
    return insert(pos, s.c_str(), 0, s.length());
}

CString& CString::insert(size_t pos, size_t n, char c)
{
    if (pos > m_len || n == 0)
    {
        return *this;
    }
    reserve(m_len + n);
    SHIFT_MEM(m_buf, pos, pos+n, m_len-pos);
    MEMSET(m_buf+pos, c, n);
    m_len += n;
    m_buf[m_len] = NULL;
    return *this;
}

CString& CString::erase(size_t pos, size_t len)
{
    size_t n = len;
    if (n == npos)
    {
        n = m_len-pos;
    }
    if (pos > m_len || n > m_len)
    {
        return *this;
    }

    MEMCPY(m_buf+pos, m_buf+pos+n, m_len-n);
    m_len -= n;
    m_buf[m_len] = NULL;
    return *this;
}

void CString::shrink_to_fit()
{
    size_t new_capacity = m_len + 1;
    if (new_capacity == m_capacity)
    {
        return;
    }
    REALLOC(new_capacity);
    m_capacity = new_capacity;
}

// ensure new_capacity, but do not shrink
void CString::reserve(size_t new_len)
{
    size_t new_capacity = new_len+1; // add a null
    if (new_capacity <= m_capacity)
    {
        return;
    }
    REALLOC(new_capacity);
    m_capacity = new_capacity;
}

// ensure new_len, do not shrink capacity
void CString::resize(size_t new_len)
{
    reserve(new_len);
    m_buf[new_len] = NULL;
    m_len = new_len;
}

// ensure new_len and fill new space with c, do not shrink capacity
void CString::resize(size_t new_len, char c)
{
    size_t old_len  = m_len;
    int    mset_len = new_len-m_len;
    reserve(new_len);
    m_len = new_len;
    if (mset_len > 0)
    {
        MEMSET(m_buf+old_len, c, mset_len);
    }
}

CString CString::substr(size_t pos, size_t len) const
{
    if (pos > m_len)
    {
        return CString();
    }
    if (len == npos)
    {
        len = m_len - pos;
    }
    if (pos+len > m_len)
    {
        len = m_len - pos;
    }
    char s[len+1]{};
    MEMCPY(s, m_buf+pos, len);
    return CString(s);
}

bool operator==(const CString& lhs, const CString& rhs)
{
    size_t len = lhs.length();
    if (len != rhs.length())
    {
        return false;
    }
    return (MEMCMP(lhs.c_str(), rhs.c_str(), len) == 0);
}

bool operator==(const CString& lhs, const char *rhs)
{
    if (rhs == nullptr) {return false;}
    size_t l_len = lhs.length();
    size_t r_len = strlen(rhs);
    if (l_len != r_len)
    {
        return false;
    }
    return (MEMCMP(lhs.c_str(), rhs, l_len) == 0);
}

bool operator==(const char *lhs, const CString& rhs)
{
    if (rhs == nullptr) {return false;}
    size_t r_len = rhs.length();
    size_t l_len = strlen(lhs);
    if (l_len != r_len)
    {
        return false;
    }
    return (MEMCMP(lhs, rhs.c_str(), r_len) == 0);
}

bool operator!=(const CString& lhs, const CString& rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const CString& lhs, const char* rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const char *lhs, const CString& rhs)
{
    return !(lhs == rhs);
}

CString operator+ (const CString& lhs, const CString& rhs)
{
    CString s(lhs);
    s += rhs;
    return s;
}

CString operator+ (const CString& lhs, const char* rhs)
{
    CString s(lhs);
    s += rhs;
    return s;
}

CString operator+ (const char* lhs, const CString& rhs)
{
    CString s(lhs);
    s += rhs;
    return s;
}

char& CString::front() const
{
    return (*this)[0];
}

char& CString::back() const
{
    return (*this)[m_len-1];
}

void CString::clear()
{
    MEMSET(m_buf,0,m_capacity);
    m_len = 0;
}

char& CString::operator[] (const size_t pos) const
{
    if (pos < 0 || pos > m_len)
    {
        return *(m_buf+m_len); // out-of-range returns the null char
    }
    return *(m_buf+pos);
}

char& CString::at(size_t pos) const
{
    if (pos < 0 || pos > m_len)
    {
        return *(m_buf+m_len); // out-of-range returns the null char
    }
    return (*this)[pos];
}

CString& CString::operator= (const CString& rhs)
{
    size_t rhs_len = rhs.length();
    reserve(rhs_len);
    MEMCPY(m_buf, rhs.c_str(), rhs_len);
    m_len = rhs_len;
    m_buf[m_len] = NULL;
    return *this;
}

CString& CString::operator+= (const CString& rhs)
{
    size_t s_len = rhs.length();
    reserve(m_len + s_len);
    MEMCPY(m_buf+m_len, rhs.c_str(), s_len);
    m_len += s_len;
    m_buf[m_len] = NULL;
    return *this;
}

CString& CString::operator= (const char* rhs)
{
    if (rhs == nullptr)
    {
        m_len        = 0;
        m_buf[m_len] = NULL;
        return *this;
    }
    size_t rhs_len = strlen(rhs);
    reserve(rhs_len);
    MEMCPY(m_buf, rhs, rhs_len);
    m_len = rhs_len;
    m_buf[m_len] = NULL;
    return *this;
}

CString& CString::operator= (const char c)
{
    m_len = 1;
    reserve(m_len);
    m_buf[0]     = c;
    m_buf[m_len] = NULL;
    return *this;
}

CString& CString::operator+= (const char *rhs)
{
    if (rhs == nullptr)
    {
        return *this;
    }
    size_t s_len = strlen(rhs);
    if (s_len == 0)
    {
        return *this;
    }
    reserve(m_len + s_len);
    MEMCPY(m_buf+m_len, rhs, s_len);
    m_len += s_len;
    m_buf[m_len] = NULL;
    return *this;
}

CString& CString::operator+= (const char rhs)
{
    reserve(m_len + 1);
    m_buf[m_len] = rhs;
    m_len++;
    m_buf[m_len] = NULL;
    return *this;
}

vector<CString> CString::split(const char* delimiter)
{
    vector<CString> vec;
    if (!delimiter)
    {
        return vec;
    }
    CString         part;
    size_t          start = 0;
    size_t          end   = this->find(delimiter);
    size_t          d_len = strlen(delimiter);

    while (end != CString::npos)
    {
        part = this->substr(start, end-start);
        if (part != "")
        {
            vec.push_back(part);
        }
        start = end + d_len;
        end = this->find(delimiter, start);
    }
    // check for a last part
    part = end + d_len;
    part = this->substr(start);
    if (part != "")
    {
        vec.push_back(part);
    }
    return vec;
}

vector<CString> CString::split(const CString& delimiter)
{
    return this->split(delimiter.c_str());
}

vector<CString> CString::split(const char delimiter)
{
    char d[2] = {delimiter,NULL};
    return this->split(d);
}
