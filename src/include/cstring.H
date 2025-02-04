/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/cstring.H $                                       */
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
#include <cstring>
#include <vector>

using namespace std;

class CString
{
    /*
     * This class attempts to simplify char array usage, and to reduce the
     * allocations required.
     *
     * A null char is always properly maintained in the char array.
     * The char array can automatically grow by using a realloc as required.
     *
     * Use this class to:
     *  1. Create a new c-string and modify it
     *      Specify a sufficient capacity and do unlimited mods with no realloc.
     *  2. Modify an existing c-string
     *      Pass a pointer to a c-string into the ctor and the c-string is
     *      then modified by calling the CString methods.
     *
     * More details for 1:
     *  An empty CString may be instantiated at a specified capacity.
     *  Unlimited operations may be done without causing a realloc, as long as
     *  the number of chars in the array is less than the capacity.
     *
     *   CString cstr1(16);   < allocate 16 bytes, length is 0
     *   cstr1 = "12345";     < no realloc, length is 5
     *   cstr1 += "6789";     < no realloc, length is 9
     *   cstr1 = "123456789"; < no realloc, length is 9
     *
     *   char *s = new char[16]{}; < we want to use Class CString to modify s
     *   CString cstr2(s,16);      < new CString, copy of s, capacity is 16, length is 0
     *   cstr2 = "12345";          < no realloc, length is 5
     *   cstr2.copyout(s);         < copy cstr2 to s
     *
     * More details for 2:
     *  We can modify an existing c-string, by calling the CString ctor
     *  with a char**.
     *
     *   char *s1{nullptr};        < we want to use Class CString to modify s1
     *   CString cstr1(&s1,16);    < The ctor did a malloc for s1 of 16 bytes.
     *                             < The cstr1 methods now modify s1
     *   cstr1 += "abc123";        < cstr and s1 are each "abc123"
     *   printf("%s", s1)          < "abc123"
     *   delete s1;                < The user is responsible to free s1
     *
     *   char *s2 = new char[16];  < we want to use Class CString to modify s2
     *   CString cstr2(&s2,16);    < The cstr2 methods now modify s2
     *   cstr2 += "abc123";        < cstr2 and s2 are each "abc123"
     *   printf("%s", s2)          < "abc123"
     *   delete s2;                < The user is responsible to free s2
     */

    char** m_buf_ptr{};  // used to modify the users buf addr for a realloc
    char*  m_buf{};      // memory used for the char array operations
    size_t m_capacity{}; // number of bytes allocated for m_buf
    size_t m_len{};      // number of characters in m_buf, not including the null
    bool   m_free{true}; // true if m_buf is to be freed in the dtor

  public:

    /* View the online documentation of class std::string for the CString methods.
     * The usage is nearly identical, even though the implementations differ.
     */

    static constexpr size_t npos = -1;

    /**
     * @brief Create a CString with length of 0 and capacity of 1 for the null
     */
    CString();

    /**
     * @brief Create a CString with length of 0 and with the specified capacity
     * @param[in]  number of bytes to allocate
     * @note The capacity specified includes a byte for the null
     */
    CString(size_t capacity);
    CString(int    capacity) : CString((size_t)capacity) {};

    /**
     * @brief Create a CString and allocate memory according to the input parms
     */
    CString(const CString& str, size_t pos = 0, size_t len = npos); // copy ctor
    CString(const char *s, size_t pos = 0, size_t len = npos);      // copy ctor
    CString(const char c);                                          // copy ctor
    CString(size_t n, const char c);                                // fill ctor

    /**
     * @brief Construct a CString using an existing char pointer.
     * @param[in] p_buf    : Pointer to the char pointer
     * @param[in] capacity : Size of the char array in bytes
     * @note  Any mods, including reallocs, change the Users char array.
     *        The User is responsible to free the char pointer. (m_free is false)
     *        If p_buf or *p_buf is null, then a char array is malloc'd to capacity
     *        It is assumed that if *p_buf is not a nullptr, then *p_buf is a
     *        valid null terminated c-string.
     */
    CString(char **p_buf, size_t capacity);

    /**
     * @brief Free the char array only if appropriate (if m_free is true)
     */
    ~CString();

    // Capacity
    size_t size() const {return m_len;}
    size_t length() const {return m_len;}
    int    capacity() const {return m_capacity;}
    void   resize(size_t n);         // capacity can grow but not shrink
    void   resize(size_t n, char c); // capacity can grow but not shrink
    void   reserve(size_t new_len);  // ensure capacity for new_len plus a null
    void   clear();                  // set length to 0, capacity is unchanged
    void   shrink_to_fit();          // capacity may change if length is less
    bool   empty() const {return m_len == 0;}

    // Element Access
    char& operator[] (const size_t pos) const;
    char& at(size_t pos) const;
    char& back() const;
    char& front() const;

    // Modifiers
    CString& operator=  (const CString& rhs);
    CString& operator=  (const char *rhs);
    CString& operator=  (const char c);
    CString& operator+= (const CString& rhs);
    CString& operator+= (const char *rhs);
    CString& operator+= (const char rhs);
    CString& insert(size_t pos, const CString& str);
    CString& insert(size_t pos, const CString& str, size_t subpos, size_t sublen=npos);
    CString& insert(size_t pos, const char *s);
    CString& insert(size_t pos, const char *s, size_t subpos, size_t sublen=npos);
    CString& insert(size_t pos, size_t n, char c);
    CString& replace(size_t pos, size_t len, const CString& str);
    CString& replace(size_t pos, size_t len, const CString& str, size_t subpos, size_t sublen=npos);
    CString& replace(size_t pos, size_t len, const char *s, size_t subpos, size_t sublen=npos);
    CString& replace(size_t pos, size_t len, const char *s);
    CString& replace(size_t pos, size_t len, char c);
    CString& erase(size_t pos, size_t len = npos);
    CString& uppercase();
    CString& lowercase();

    // CString Operations
    const char* c_str() const {return m_buf;}
    const char* data()  const {return m_buf;}
    size_t find(const CString& str) const;
    size_t find(const CString& str, size_t pos) const;
    size_t find(const char *cstr) const;
    size_t find(const char *cstr, size_t pos) const;
    size_t find(const char *cstr, size_t pos, size_t n) const;
    size_t find(char c) const;
    size_t find(char c, size_t pos) const;
    size_t rfind(const CString& str) const;
    size_t rfind(const CString& str, size_t pos) const;
    size_t rfind(const char *cstr) const;
    size_t rfind(const char *cstr, size_t pos) const;
    size_t rfind(const char *cstr, size_t pos, size_t n) const;
    size_t rfind(char c) const;
    size_t rfind(char c, size_t pos) const;
    CString substr(size_t pos, size_t len = npos) const;
    int compare(const CString& str) const;
    int compare(const char *s) const;

    /**
     * @brief  Copy all the chars to s that will fit
     *         Place a null at the end of s
     * @param[in]  capacity is the size of s in bytes
     */
    void copyout(char *s, size_t capacity);

    // Non-member function overloads
    friend CString  operator+  (const CString& lhs, const CString& rhs);
    friend CString  operator+  (const CString& lhs, const char    *rhs);
    friend CString  operator+  (const char    *lhs, const CString& rhs);
    friend bool     operator== (const CString& lhs, const CString& rhs);
    friend bool     operator== (const CString& lhs, const char    *rhs);
    friend bool     operator!= (const CString& lhs, const CString& rhs);
    friend bool     operator!= (const CString& lhs, const char    *rhs);

    /**
     * @brief  Split the CString into a vector of CStrings by the delimiter
     * @param[in]  char(s) used as the delimiter
     */
    vector<CString> split(const CString& delimiter);
    vector<CString> split(const char    *delimiter);
    vector<CString> split(const char     delimiter);
};
