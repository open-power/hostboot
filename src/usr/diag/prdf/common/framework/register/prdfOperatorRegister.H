/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfOperatorRegister.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#ifndef __PRDFOPERATORREGISTER_H
#define __PRDFOPERATORREGISTER_H

#include <algorithm>

#include <iipscr.h>
#include <prdrCommon.H>

namespace PRDF
{

class NotRegister : public SCAN_COMM_REGISTER_CLASS
{
  public:
    NotRegister() :
        SCAN_COMM_REGISTER_CLASS( ), iv_child(nullptr), iv_iBS(0)
    {
        iv_bs = &iv_iBS;
    }

    NotRegister(SCAN_COMM_REGISTER_CLASS & i_arg) :
        SCAN_COMM_REGISTER_CLASS( ), iv_child(&i_arg),
        iv_iBS(i_arg.GetBitLength())
    {
        iv_bs = &iv_iBS;
    }

    NotRegister & operator=(const NotRegister & r)
    {
        iv_child = r.iv_child;
        iv_iBS = r.iv_iBS;
        //iv_bs = r.iv_bs; <-- don't do this!
        return *this;
    }

    virtual uint32_t Read() const { return iv_child->Read();  }
    virtual uint32_t Write()      { return iv_child->Write(); }

    const BitString * GetBitString(
                    ATTENTION_TYPE i_type = INVALID_ATTENTION_TYPE) const
    {
        (*iv_bs) = ~(*iv_child->GetBitString(i_type));
        return iv_bs;
    }

    virtual uint16_t GetId() const { return iv_child->GetId(); }
    virtual void SetId(uint16_t i_id) {}

    bool operator==(const NotRegister & r) const
    { return r.iv_child == iv_child; }

    bool operator<(const NotRegister & r) const
    { return iv_child < r.iv_child; }

    bool operator>=(const NotRegister & r) const
    { return iv_child >= r.iv_child; }

  protected:
    BitString & AccessBitString(void) { return iv_iBS; }
    void SetBitString(const BitString *) {}

  private:
    SCAN_COMM_REGISTER_CLASS * iv_child;

    BitStringBuffer * iv_bs;
    BitStringBuffer iv_iBS;
};

class SummaryRegister : public SCAN_COMM_REGISTER_CLASS
{
  public:
    SummaryRegister() :
        SCAN_COMM_REGISTER_CLASS( ), iv_child(nullptr), iv_amount(0), iv_iBS(0)
    {
        iv_bs = &iv_iBS;
    }

    SummaryRegister(SCAN_COMM_REGISTER_CLASS & i_arg, uint16_t i_amount) :
        SCAN_COMM_REGISTER_CLASS( ), iv_child(&i_arg), iv_amount(i_amount),
        iv_iBS(i_arg.GetBitLength())
    {
        iv_bs = &iv_iBS;
    }

    SummaryRegister & operator=(const SummaryRegister & r)
    {
        iv_child = r.iv_child;
        iv_amount = r.iv_amount;
        iv_iBS = r.iv_iBS;
        //iv_bs = r.iv_bs; <-- don't do this!
        return *this;
    }

    virtual uint32_t Read() const
    {
        uint32_t rc = iv_child->Read();
        if ( PRD_SCANCOM_FAILURE == rc )
        {
            // This is a bit unusual, but we are going to ignore SCOM failures.
            // This takes care of a corner case where one of the summary
            // registers in the list returns an error, but there is another
            // summary register with an active attention, which would be ignored
            // if we return a bad rc.
            PRDF_INF( "[SummaryRegister::read] SCOM failure on register ID "
                      "0x%04x, ignoring error", iv_child->GetId() );
            rc = SUCCESS;
            iv_child->clearAllBits(); // just in case
        }
        return rc;
    }

    virtual uint32_t Write()      { return iv_child->Write(); }

    const BitString * GetBitString(
                    ATTENTION_TYPE i_type = INVALID_ATTENTION_TYPE) const
    {
        iv_bs->clearAll();

        PRDF::BitString tmp = *iv_child->GetBitString(i_type);

        //if any bits are set in iv_child, then set the iv_amount bit
        if (0 != tmp.getSetCount())
        {
            iv_bs->setBit(0);
            *iv_bs = *iv_bs >> iv_amount;
        }
        return iv_bs;
    }

    virtual uint16_t GetId() const { return iv_child->GetId(); }
    virtual void SetId(uint16_t i_id) {}

    bool operator==(const SummaryRegister & r) const
    { return (r.iv_child == iv_child) && (r.iv_amount == iv_amount); }

    bool operator<(const SummaryRegister & r) const
    {
        if (iv_child == r.iv_child)
            return iv_amount < r.iv_amount;
        return iv_child < r.iv_child;
    }

    bool operator>=(const SummaryRegister & r) const
    {
        if (iv_child == r.iv_child)
            return iv_amount >= r.iv_amount;
        return iv_child >= r.iv_child;
    }

  protected:
    BitString & AccessBitString(void) { return iv_iBS; }
    void SetBitString(const BitString *) {}

  private:
    SCAN_COMM_REGISTER_CLASS * iv_child;
    uint16_t iv_amount;

    BitStringBuffer * iv_bs;
    BitStringBuffer iv_iBS;
};

class LeftShiftRegister : public SCAN_COMM_REGISTER_CLASS
{
  public:
    LeftShiftRegister() :
        SCAN_COMM_REGISTER_CLASS( ), iv_child(nullptr), iv_amount(0), iv_iBS(0)
    {
        iv_bs = &iv_iBS;
    }

    LeftShiftRegister(SCAN_COMM_REGISTER_CLASS & i_arg, uint16_t i_amount) :
        SCAN_COMM_REGISTER_CLASS( ), iv_child(&i_arg), iv_amount(i_amount),
        iv_iBS(i_arg.GetBitLength())
    {
        iv_bs = &iv_iBS;
    }

    LeftShiftRegister & operator=(const LeftShiftRegister & r)
    {
        iv_child = r.iv_child;
        iv_amount = r.iv_amount;
        iv_iBS = r.iv_iBS;
        //iv_bs = r.iv_bs; <-- don't do this!
        return *this;
    }

    virtual uint32_t Read() const { return iv_child->Read();  }
    virtual uint32_t Write()      { return iv_child->Write(); }

    const BitString * GetBitString(
                    ATTENTION_TYPE i_type = INVALID_ATTENTION_TYPE) const
    {
        (*iv_bs) = (*iv_child->GetBitString(i_type)) << iv_amount;
        return iv_bs;
    }

    virtual uint16_t GetId() const { return iv_child->GetId(); }
    virtual void SetId(uint16_t i_id) {}

    bool operator==(const LeftShiftRegister & r) const
    { return (r.iv_child == iv_child) && (r.iv_amount == iv_amount); }

    bool operator<(const LeftShiftRegister & r) const
    {
        if (iv_child == r.iv_child)
            return iv_amount < r.iv_amount;
        return iv_child < r.iv_child;
    }

    bool operator>=(const LeftShiftRegister & r) const
    {
        if (iv_child == r.iv_child)
            return iv_amount >= r.iv_amount;
        return iv_child >= r.iv_child;
    }

  protected:
    BitString & AccessBitString(void) { return iv_iBS; }
    void SetBitString(const BitString *) {}

  private:
    SCAN_COMM_REGISTER_CLASS * iv_child;
    uint16_t iv_amount;

    BitStringBuffer * iv_bs;
    BitStringBuffer iv_iBS;
};

class RightShiftRegister : public SCAN_COMM_REGISTER_CLASS
{
  public:
    RightShiftRegister() :
        SCAN_COMM_REGISTER_CLASS( ), iv_child(nullptr), iv_amount(0), iv_iBS(0)
    {
        iv_bs = &iv_iBS;
    }

    RightShiftRegister(SCAN_COMM_REGISTER_CLASS & i_arg, uint16_t i_amount) :
        SCAN_COMM_REGISTER_CLASS( ), iv_child(&i_arg), iv_amount(i_amount),
        iv_iBS(i_arg.GetBitLength())
    {
        iv_bs = &iv_iBS;
    }

    RightShiftRegister & operator=(const RightShiftRegister & r)
    {
        iv_child = r.iv_child;
        iv_amount = r.iv_amount;
        iv_iBS = r.iv_iBS;
        //iv_bs = r.iv_bs; <-- don't do this!
        return *this;
    }

    virtual uint32_t Read() const { return iv_child->Read();  }
    virtual uint32_t Write()      { return iv_child->Write(); }

    const BitString * GetBitString(
                    ATTENTION_TYPE i_type = INVALID_ATTENTION_TYPE) const
    {
        (*iv_bs) = (*iv_child->GetBitString(i_type)) >> iv_amount;
        return iv_bs;
    }

    virtual uint16_t GetId() const { return iv_child->GetId(); }
    virtual void SetId(uint16_t i_id) {}

    bool operator==(const RightShiftRegister & r) const
    { return (r.iv_child == iv_child) && (r.iv_amount == iv_amount); }

    bool operator<(const RightShiftRegister & r) const
    {
        if (iv_child == r.iv_child)
            return iv_amount < r.iv_amount;
        return iv_child < r.iv_child;
    }

    bool operator>=(const RightShiftRegister & r) const
    {
        if (iv_child == r.iv_child)
            return iv_amount >= r.iv_amount;
        return iv_child >= r.iv_child;
    }

  protected:
    BitString & AccessBitString(void) { return iv_iBS; }
    void SetBitString(const BitString *) {}

  private:
    SCAN_COMM_REGISTER_CLASS * iv_child;
    uint16_t iv_amount;

    BitStringBuffer * iv_bs;
    BitStringBuffer iv_iBS;
};


class AndRegister : public SCAN_COMM_REGISTER_CLASS
{
  public:
    AndRegister() :
        SCAN_COMM_REGISTER_CLASS( ), iv_left(nullptr), iv_right(nullptr), iv_iBS(0)
    {
        iv_bs = &iv_iBS;
    }

    AndRegister( SCAN_COMM_REGISTER_CLASS & i_left,
                 SCAN_COMM_REGISTER_CLASS & i_right ) :
        SCAN_COMM_REGISTER_CLASS( ), iv_left(&i_left), iv_right(&i_right),
        iv_iBS(std::min(i_left.GetBitLength(),
                        i_right.GetBitLength()))
    {
        iv_bs = &iv_iBS;
    }

    AndRegister & operator=(const AndRegister & r)
    {
        iv_left = r.iv_left;
        iv_right = r.iv_right;
        iv_iBS = r.iv_iBS;
        //iv_bs = r.iv_bs; <-- don't do this!
        return *this;
    }

    virtual uint32_t Read() const
    {
        return iv_left->Read() | iv_right->Read();
    }
    virtual uint32_t Write()
    {
        return iv_left->Write() | iv_right->Write();
    }

    const BitString * GetBitString(
                    ATTENTION_TYPE i_type = INVALID_ATTENTION_TYPE) const
    {
        (*iv_bs) = *iv_left->GetBitString(i_type);
        (*iv_bs) = (*iv_bs) & (*iv_right->GetBitString(i_type));
        return iv_bs;
    }

    virtual uint16_t GetId() const
    {
        return Prdr::SignatureOp::combineSig(iv_left->GetId(),
                                             iv_right->GetId());
    }

    virtual void SetId(uint16_t i_id) {}

    bool operator==(const AndRegister & r) const
    { return (r.iv_left == iv_left) && (r.iv_right == iv_right); }

    bool operator<(const AndRegister & r) const
    {
        if (iv_left == r.iv_left)
            return iv_right < r.iv_right;
        return iv_left < r.iv_left;
    }

    bool operator>=(const AndRegister & r) const
    {
        if (iv_left == r.iv_left)
            return iv_right >= r.iv_right;
        return iv_left >= r.iv_left;
    }

  protected:
    BitString & AccessBitString(void) { return iv_iBS; }
    void SetBitString(const BitString *) {}

  private:
    SCAN_COMM_REGISTER_CLASS * iv_left;
    SCAN_COMM_REGISTER_CLASS * iv_right;

    BitStringBuffer * iv_bs;
    BitStringBuffer iv_iBS;
};

class OrRegister : public SCAN_COMM_REGISTER_CLASS
{
  public:

    OrRegister() :
        SCAN_COMM_REGISTER_CLASS( ), iv_left(nullptr), iv_right(nullptr), iv_iBS(0)
    {
        iv_bs = &iv_iBS;
    }

    OrRegister( SCAN_COMM_REGISTER_CLASS & i_left,
                SCAN_COMM_REGISTER_CLASS & i_right ) :
        SCAN_COMM_REGISTER_CLASS( ), iv_left(&i_left), iv_right(&i_right),
        iv_iBS(std::min(i_left.GetBitLength(),
                        i_right.GetBitLength()))
    {
        iv_bs = &iv_iBS;
    }

    OrRegister & operator=(const OrRegister & r)
    {
        iv_left = r.iv_left;
        iv_right = r.iv_right;
        iv_iBS = r.iv_iBS;
        //iv_bs = r.iv_bs; <-- don't do this!
        return *this;
    }

    virtual uint32_t Read() const
    {
        return iv_left->Read() | iv_right->Read();
    }

    virtual uint32_t Write()
    {
        return iv_left->Write() | iv_right->Write();
    }

    const BitString * GetBitString(
                    ATTENTION_TYPE i_type = INVALID_ATTENTION_TYPE ) const
    {
        (*iv_bs) = *iv_left->GetBitString(i_type);
        (*iv_bs) = (*iv_bs) | (*iv_right->GetBitString(i_type));
        return iv_bs;
    }

    virtual uint16_t GetId() const
    {
        return Prdr::SignatureOp::combineSig( iv_left->GetId(),
                                              iv_right->GetId() );
    }

    virtual void SetId(uint16_t i_id) {}

    bool operator==(const OrRegister & r) const
    { return (r.iv_left == iv_left) && (r.iv_right == iv_right); }

    bool operator<(const OrRegister & r) const
    {
        if (iv_left == r.iv_left)
            return iv_right < r.iv_right;
        return iv_left < r.iv_left;
    }

    bool operator>=(const OrRegister & r) const
    {
        if (iv_left == r.iv_left)
            return iv_right >= r.iv_right;
        return iv_left >= r.iv_left;
    }

  protected:
    BitString & AccessBitString(void) { return iv_iBS; }
    void SetBitString(const BitString *) {}

  private:
    SCAN_COMM_REGISTER_CLASS * iv_left;
    SCAN_COMM_REGISTER_CLASS * iv_right;

    BitStringBuffer * iv_bs;
    BitStringBuffer iv_iBS;
};

class NullRegister : public SCAN_COMM_REGISTER_CLASS
{
  public:
    NullRegister(int size) :
        SCAN_COMM_REGISTER_CLASS( ), iv_iBS(size)
    {}

    NullRegister & operator=(const NullRegister & r)
    {
        iv_iBS = r.iv_iBS;
        return *this;
    }

    virtual uint32_t Read() const { return 0; }
    virtual uint32_t Write()      { return 0; }

    const BitString * GetBitString(
                    ATTENTION_TYPE i_type = INVALID_ATTENTION_TYPE) const
    {
        return &iv_iBS;
    }

  protected:
    BitString & AccessBitString(void) { return iv_iBS; }
    void SetBitString(const BitString *) {}

  private:
    BitStringBuffer iv_iBS;

    virtual uint16_t GetId() const
    { return Prdr::SignatureOp::DEFAULT_SIGNATURE; }

    virtual void SetId(uint16_t i_id) {}

};

class AttnTypeRegister : public SCAN_COMM_REGISTER_CLASS
{
  public:
    AttnTypeRegister() :
        SCAN_COMM_REGISTER_CLASS( ), iv_check(&cv_null), iv_recov(&cv_null),
        iv_special(&cv_null), iv_proccs(&cv_null), iv_hostattn(&cv_null),
        iv_iBS(0)
    {
        iv_bs = &iv_iBS;
    }

    AttnTypeRegister( SCAN_COMM_REGISTER_CLASS *i_check,
                      SCAN_COMM_REGISTER_CLASS *i_recov,
                      SCAN_COMM_REGISTER_CLASS *i_special,
                      SCAN_COMM_REGISTER_CLASS *i_proccs,
                      SCAN_COMM_REGISTER_CLASS *i_hostattn ) :
        SCAN_COMM_REGISTER_CLASS( ),
        iv_check(    nullptr == i_check    ? &cv_null : i_check),
        iv_recov(    nullptr == i_recov    ? &cv_null : i_recov),
        iv_special(  nullptr == i_special  ? &cv_null : i_special),
        iv_proccs(   nullptr == i_proccs   ? &cv_null : i_proccs),
        iv_hostattn( nullptr == i_hostattn ? &cv_null : i_hostattn),
        iv_iBS(0)         // will fully initialize this inside ctor.
    {
        uint32_t l_length = 1024;
        l_length = std::min(l_length, iv_check->GetBitLength());
        l_length = std::min(l_length, iv_recov->GetBitLength());
        l_length = std::min(l_length, iv_special->GetBitLength());
        l_length = std::min(l_length, iv_proccs->GetBitLength());
        l_length = std::min(l_length, iv_hostattn->GetBitLength());
        iv_iBS = BitStringBuffer(l_length);
        iv_bs = &iv_iBS;
    }

    AttnTypeRegister & operator=(const AttnTypeRegister & r)
    {
        //iv_null = r.iv_null; <-- don't do this!
        iv_check    = (r.iv_check    == &r.cv_null ? &cv_null : r.iv_check);
        iv_recov    = (r.iv_recov    == &r.cv_null ? &cv_null : r.iv_recov);
        iv_special  = (r.iv_special  == &r.cv_null ? &cv_null : r.iv_special);
        iv_proccs   = (r.iv_proccs   == &r.cv_null ? &cv_null : r.iv_proccs);
        iv_hostattn = (r.iv_hostattn == &r.cv_null ? &cv_null : r.iv_hostattn);
        iv_iBS = r.iv_iBS;
        //iv_bs = r.iv_bs; <-- don't do this!
        return *this;
    }

    virtual uint32_t Read() const
    {
        return iv_check->Read()   | iv_recov->Read() |
               iv_special->Read() | iv_proccs->Read() |
               iv_hostattn->Read();
    }

    virtual uint32_t Write()
    {
        return iv_check->Write()   | iv_recov->Write() |
               iv_special->Write() | iv_proccs->Write() |
               iv_hostattn->Write();
    }

    const BitString * GetBitString(
                    ATTENTION_TYPE i_type = INVALID_ATTENTION_TYPE) const
    {
        switch (i_type)
        {
            case CHECK_STOP:
                (*iv_bs) = BitStringBuffer(
                                            *iv_check->GetBitString(i_type));
                break;

            case RECOVERABLE:
                (*iv_bs) = BitStringBuffer(
                                            *iv_recov->GetBitString(i_type));
                break;

            case SPECIAL:
                (*iv_bs) = BitStringBuffer(
                                            *iv_special->GetBitString(i_type));
                break;

            case PROC_CS:
                (*iv_bs) = BitStringBuffer(
                                            *iv_proccs->GetBitString(i_type));
                break;

            case HOST_ATTN:
                (*iv_bs) = BitStringBuffer(
                                            *iv_hostattn->GetBitString(i_type));
                break;
        }

        return iv_bs;
    }

    virtual uint16_t GetId() const
    {
        uint16_t l_rc = Prdr::SignatureOp::DEFAULT_SIGNATURE;
        l_rc = Prdr::SignatureOp::combineSig(l_rc, iv_check->GetId());
        l_rc = Prdr::SignatureOp::combineSig(l_rc, iv_recov->GetId());
        l_rc = Prdr::SignatureOp::combineSig(l_rc, iv_special->GetId());
        l_rc = Prdr::SignatureOp::combineSig(l_rc, iv_proccs->GetId());
        l_rc = Prdr::SignatureOp::combineSig(l_rc, iv_hostattn->GetId());
        return l_rc;
    }

    virtual void SetId(uint16_t i_id) {}

    bool operator==(const AttnTypeRegister & r) const
    {
        return (r.iv_check   == iv_check)   && (r.iv_recov  == iv_recov) &&
               (r.iv_special == iv_special) && (r.iv_proccs == iv_proccs) &&
               (r.iv_special == iv_hostattn);
    }

  protected:
    BitString & AccessBitString(void) { return iv_iBS; }
    void SetBitString(const BitString *) {}

  private:
    static NullRegister cv_null;

    SCAN_COMM_REGISTER_CLASS * iv_check;
    SCAN_COMM_REGISTER_CLASS * iv_recov;
    SCAN_COMM_REGISTER_CLASS * iv_special;
    SCAN_COMM_REGISTER_CLASS * iv_proccs;
    SCAN_COMM_REGISTER_CLASS * iv_hostattn;

    BitStringBuffer * iv_bs;
    BitStringBuffer iv_iBS;
};

class ConstantRegister : public SCAN_COMM_REGISTER_CLASS
{
  public:
    ConstantRegister() :
        SCAN_COMM_REGISTER_CLASS( ), iv_iBS(0)
    {}

    ConstantRegister( const BitStringBuffer & i_arg ) :
        SCAN_COMM_REGISTER_CLASS( ), iv_iBS(i_arg)
    {}

    ConstantRegister & operator=(const ConstantRegister & r)
    {
        iv_iBS = r.iv_iBS;
        return *this;
    }

    virtual uint32_t Read() const { return SUCCESS; }
    virtual uint32_t Write()      { return SUCCESS; }

    const BitString * GetBitString(
                    ATTENTION_TYPE i_type = INVALID_ATTENTION_TYPE) const
    {
        return &iv_iBS;
    }

    virtual uint16_t GetId() const
    { return Prdr::SignatureOp::DEFAULT_SIGNATURE; }

    virtual void SetId(uint16_t i_id) {}

    bool operator==(const ConstantRegister & r) const
    { return r.iv_iBS == iv_iBS; }

  protected:
    BitString & AccessBitString(void) { return iv_iBS; }
    void SetBitString(const BitString *) {}

  private:
    BitStringBuffer iv_iBS;
};

} // end namespace PRDF

#endif
