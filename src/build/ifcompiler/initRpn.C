// IBM_PROLOG_BEGIN_TAG
// This is an automatically generated prolog.
//
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/ifcompiler/initRpn.C,v $
//
// IBM CONFIDENTIAL
//
// COPYRIGHT International Business Machines Corp. 2010,2010
//
//UNDEFINED
//
// Origin: UNDEFINED
//
// IBM_PROLOG_END_TAG
// Change Log *************************************************************************************
//
//  Flag   Reason  Userid   Date     Description
//  ----- -------- -------- -------- -------------------------------------------------------------
//         D754106 dgilbert 06/14/10 Create
//  dg002 SW039868 dgilbert 10/15/10 Add support to filter unneeded inits by EC
//  dg003 SW047506 dgilbert 12/09/10 SERIES filtering
//                 andrewg  05/24/11 Port over for VPL/PgP
//                 andrewg  09/19/11 Updates based on review
// End Change Log *********************************************************************************

/**
 * @file initRpn.C
 * @brief Definition of the initRpn class. Handles Reverse Polish Notation equations for initfiles
 */
#include <initRpn.H>
#include <initSymbols.H>
//#include <initSpy.H>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace init;

const char * OP_TXT[] =
{
    "PUSH",
    "AND",
    "OR",
    "NOT",
    "EQ",
    "NE",
    "GT",
    "GE",
    "LT",
    "LE",
    "PLUS",
    "MINUS",
    "MULT",
    "DIVIDE",
    "MOD",
    "LIST",
    "SHIFTLEFT",
    "SHIFTRIGHT",
    "FALSE",             //dg003a
    "TRUE",              //dg003a
};

std::string Rpn::cv_empty_str;

//-------------------------------------------------------------------------------------------------

Rpn::Rpn(uint32_t i_uint,Symbols * symbols) : iv_symbols(symbols)
{ push_int(i_uint);}

//-------------------------------------------------------------------------------------------------

Rpn::Rpn(std::string  i_id, Symbols * symbols, TYPE i_type) : iv_symbols(symbols)
{ push_id(i_id, i_type); }

//-------------------------------------------------------------------------------------------------

Rpn::Rpn(uint64_t i_uint, Symbols * symbols) : iv_symbols(symbols)
{
    push_int64(i_uint);
}

//-------------------------------------------------------------------------------------------------

bool Rpn::operator==(const Rpn & r)
{
    bool result = false;
    if (iv_rpnstack.size() == r.iv_rpnstack.size())
    {
        if (iv_symbols == r.iv_symbols)
        {
            result = true;
            RPNSTACK::const_iterator c1 = iv_rpnstack.begin();
            RPNSTACK::const_iterator c2 = r.iv_rpnstack.begin();
            for (; c1 != iv_rpnstack.end(); ++c1, ++c2)
            {
                if (*c1 != *c2)
                {
                    result = false;
                    break;
                }
            }
        }
        else // they have different symbol tables
        {
            result = true;
            RPNSTACK::const_iterator c1 = iv_rpnstack.begin();
            RPNSTACK::const_iterator c2 = r.iv_rpnstack.begin();
            for (; c1 != iv_rpnstack.end(); ++c1, ++c2)
            {
                uint32_t t1 = (*c1) & TYPE_MASK;
                uint32_t t2 = (*c2) & TYPE_MASK;
                if(t1 != t2)
                {
                    result = false;
                    break;
                }
                switch (t1)
                {
                    case DEFINE:
                        {
                            Rpn r1 = iv_symbols->get_define_rpn(*c1);
                            Rpn r2 = r.iv_symbols->get_define_rpn(*c2);
                            if (r1 != r2) result = false;
                        }
                        break;
                    case SYMBOL:
                        {
                            string s1 = iv_symbols->find_name(*c1);
                            string s2 = (r.iv_symbols)->find_name(*c2);
                            if(s1 != s2) result = false;
                        }
                        break;
                    case NUMBER:
                        {
                            uint32_t size = 0;
                            uint64_t data1 = iv_symbols->get_numeric_data(*c1,size);
                            uint64_t data2 = (r.iv_symbols)->get_numeric_data(*c2,size);
                            // do we care if the size is different only the value?
                            if(data1 != data2) result = false;
                        }
                        break;
                    case OPERATION:   // independent of symbol table - just compare
                    default:          // just compare
                        if(*c1 != *c2) result = false;
                        break;
                }
                if(result == false) break;
            }
        }
    }
    return result;
}

//-------------------------------------------------------------------------------------------------

void Rpn::push_int(uint32_t i_uint)
{
    uint32_t rpn_id = iv_symbols->find_numeric_lit(i_uint,4);
    iv_rpnstack.push_back(rpn_id);
}

//-------------------------------------------------------------------------------------------------

void Rpn::push_int64(uint64_t i_uint)
{
    uint32_t rpn_id = iv_symbols->find_numeric_lit(i_uint,8);
    iv_rpnstack.push_back(rpn_id);
}

//-------------------------------------------------------------------------------------------------

void Rpn::push_id(std::string & i_id, TYPE i_type)
{
    uint32_t rpn_id = 0;
    std::string s(i_id);

    for (std::string::iterator c = s.begin(); c != s.end(); ++c)
    {
        *c = toupper(*c);
    }

    rpn_id = iv_symbols->use_symbol(s);

    if (rpn_id & DEFINE)
    {
        Rpn r = iv_symbols->get_define_rpn(rpn_id);
        append(r);
    }
    else
    {
        iv_rpnstack.push_back(rpn_id);
    }
}

//-------------------------------------------------------------------------------------------------

void Rpn::push_array_index(std::string &i_array_idx)
{
    string l_idx = i_array_idx;
    // strip of leading "[" and last "]"
    l_idx = l_idx.substr(1,(l_idx.length() - 2));
    uint32_t l_array_val = atoi(l_idx.c_str());

    uint32_t rpn_id = iv_symbols->find_numeric_array_lit(l_array_val,4);
    iv_rpnstack.push_back(rpn_id);

    //printf("Array Index: %s  decimal:%u  rpn_id:0x%8X\n",l_idx.c_str(),l_array_val,rpn_id);

}

//-------------------------------------------------------------------------------------------------

bool Rpn::isTrue() const  //dg003a
{
    if((iv_rpnstack.size() == 1) && (iv_rpnstack[0] == (TRUE_OP | OPERATION))) return true;
    return false;
}

//-------------------------------------------------------------------------------------------------

bool Rpn::isFalse() const //dg003a
{
    if((iv_rpnstack.size() == 1) && (iv_rpnstack[0] == (FALSE_OP | OPERATION))) return true;
    return false;
}

//-------------------------------------------------------------------------------------------------

Rpn * Rpn::push_op(RPN_OP op)
{
    uint32_t v = op;
    if(op == Rpn::LIST)  // calculate list size
    {
        uint32_t count = 0;
        for(RPNSTACK::const_reverse_iterator r = iv_rpnstack.rbegin(); r != iv_rpnstack.rend(); ++r)
        {
            if(((*r) & TYPE_MASK) == OPERATION) break;
            ++count;
        }
        v |= (count << 8);
    }
    iv_rpnstack.push_back(v | OPERATION);

    return this;
}

//-------------------------------------------------------------------------------------------------
// @post i_rpn is deleted

Rpn *  Rpn::push_merge(Rpn * i_rpn, RPN_OP op)
{
    //dg003a begin
    Rpn * result = this;

    // oportunity for Rpn optimization
    //   rpn && true, -> rpn
    //   rpn && false, -> false
    //   rpn || false, -> rpn
    //   rpn || true, -> true
    if(op == AND)
    {
        if(i_rpn->isTrue())
        {
            delete i_rpn;
            return result; // leave this RPN alone
        }
        if(this->isTrue())
        {
            iv_rpnstack.clear();
            return merge(i_rpn); // merge deletes i_rpn
        }
        if(i_rpn->isFalse() || this->isFalse())
        {
            iv_rpnstack.clear();
            delete i_rpn;
            push_op(FALSE_OP);
            return result;
        }
    }
    else if(op == OR)
    {
        if(i_rpn->isFalse())
        {
            delete i_rpn;
            return result;
        }
        if(this->isFalse())
        {
            iv_rpnstack.clear();
            return merge(i_rpn);  // merge deletes i_rpn
        }
        if(i_rpn->isTrue() || this->isTrue())
        {
            iv_rpnstack.clear();
            delete i_rpn;
            push_op(TRUE_OP);
            return result;
        }
    }

    // Filter out SERIES calculations since this is for SERIES_IP only
    // There might be a better place/way to do this??
    // TODO - No idea what this is really
#if 0
    Rpn r1("SERIES",iv_symbols);
    Rpn r2("SERIES_IP",iv_symbols);
    Rpn r3("SERIES_Z",iv_symbols);
    if( *this == r1)
    {
        if((op == EQ && *i_rpn == r2) || (op == NE && *i_rpn == r3))
        {
            iv_rpnstack.clear();
            push_op(TRUE_OP);
            delete i_rpn;
            return result;
        }
        if((op == EQ && *i_rpn == r3) || (op == NE && *i_rpn == r2))
        {
            iv_rpnstack.clear();
            push_op(FALSE_OP);
            delete i_rpn;
            return result;
        }
    }
#endif
    // These two expressions are seen as a result of macro expansion
    // Reduce (expr1 == expr2) == 0 ->  expr1 != expr2
    // Reduce (expr1 == expr2) == 1 ->  expr1 == expr2
    //      Reduce for any logic operation
    if(op == EQ)
    {
        Rpn r_zero((uint32_t)0,iv_symbols);
        Rpn r_one((uint32_t)1, iv_symbols);

        if ((*i_rpn) == r_zero)
        {
            if((*this) == r_zero)
            {
                delete i_rpn;
                iv_rpnstack.pop_back();
                push_op(TRUE_OP);
                return result;
            }
            if((*this) == r_one)
            {
                delete i_rpn;
                iv_rpnstack.pop_back();
                push_op(FALSE_OP);
                return result;
            }
            // else check for logical op
            switch (iv_rpnstack.back())
            {
                case (AND | OPERATION):
                case (OR  | OPERATION):
                    push_op(NOT);
                    delete i_rpn;
                    return result;

                case (NOT | OPERATION):  // untie the NOT
                    iv_rpnstack.pop_back();
                    delete i_rpn;
                    return result;

                case (EQ | OPERATION):
                    iv_rpnstack.back() = (NE | OPERATION);
                    delete i_rpn;
                    return result;

                case (NE | OPERATION):
                    iv_rpnstack.back() = (EQ | OPERATION);
                    delete i_rpn;
                    return result;

                case (GT | OPERATION):
                    iv_rpnstack.back() = (LE | OPERATION);
                    delete i_rpn;
                    return result;

                case (GE | OPERATION):
                    iv_rpnstack.back() = (LT | OPERATION);
                    delete i_rpn;
                    return result;

                case (LT | OPERATION):
                    iv_rpnstack.back() = (GE | OPERATION);
                    delete i_rpn;
                    return result;

                case (LE | OPERATION):
                    iv_rpnstack.back() = (GT | OPERATION);
                    delete i_rpn;
                    return result;

                case (TRUE_OP | OPERATION):
                    iv_rpnstack.back() = (FALSE_OP | OPERATION);
                    delete i_rpn;
                    return result;

                case (FALSE_OP | OPERATION):
                    iv_rpnstack.back() = (TRUE_OP | OPERATION);
                    delete i_rpn;
                    return result;

                default: // Not a logic operation - leave it alone
                    break;
            }
        }
        else if((*i_rpn) == r_one)
        {
            if((*this) == r_one)
            {
                delete i_rpn;
                iv_rpnstack.pop_back();
                push_op(TRUE_OP);
                return result;
            }
            if((*this) == r_zero)
            {
                delete i_rpn;
                iv_rpnstack.pop_back();
                push_op(FALSE_OP);
                return result;
            }
            // else check for logical op - leave it as is
            uint32_t l_op = iv_rpnstack.back();
            if((l_op == (AND | OPERATION)) ||
               (l_op == (OR  | OPERATION)) ||
               (l_op == (NOT | OPERATION)) ||
               (l_op == (EQ  | OPERATION)) ||
               (l_op == (NE  | OPERATION)) ||
               (l_op == (GT  | OPERATION)) ||
               (l_op == (GE  | OPERATION)) ||
               (l_op == (LT  | OPERATION)) ||
               (l_op == (LE  | OPERATION)) ||
               (l_op == (TRUE_OP | OPERATION)) ||
               (l_op == (FALSE_OP | OPERATION)))
            {
                delete i_rpn;
                return result;
            }
        }
    }

    // other stuff i've seen  TODO
    //     (0 == 1) == 1 , reduced already to (0 == 1)  used to turn off a row - Could eliminate the row?
    //


    //dg003a end

    iv_rpnstack.insert(iv_rpnstack.end(), i_rpn->iv_rpnstack.begin(), i_rpn->iv_rpnstack.end());
    result = push_op(op);

    delete i_rpn;
    return result;
}

//-------------------------------------------------------------------------------------------------
// @post i_rpn is deleted

Rpn * Rpn::merge(Rpn * i_rpn)
{
    iv_rpnstack.insert(iv_rpnstack.end(), i_rpn->iv_rpnstack.begin(), i_rpn->iv_rpnstack.end());
    delete i_rpn;
    return this;
}

//-------------------------------------------------------------------------------------------------
// See header file for contract
void Rpn::bin_read(BINSEQ::const_iterator & bli, Symbols * symbols)
{

    uint32_t size = 2;  // Size is always 2 for symbols

    if(symbols) iv_symbols = symbols;
    iv_rpnstack.clear();

    while(size)
    {
        uint32_t v = *bli++;
        if(v < LAST_OP) // operator
        {
            if(v == LIST)
            {
                --size;
                v |= (*bli++) << 8;
            }
           iv_rpnstack.push_back(v | OPERATION);
           --size;
        }
        else    // tag
        {
            v = (v << 8) + (*bli++);
             --size;
            if(size == 0)
            {
                std::ostringstream errss;
                errss << "Rpn::bin_read Invalid RPN binary sequence\n";
                throw std::invalid_argument(errss.str());
            }
            --size;
           iv_rpnstack.push_back(iv_symbols->get_rpn_id(v));
        }
    }
}

//-------------------------------------------------------------------------------------------------
BINSEQ::const_iterator Rpn::bin_read_one_op(BINSEQ::const_iterator & bli, Symbols * symbols)
{
    if(symbols) iv_symbols = symbols;
    while(true)
    {
        uint32_t v = *bli++;
        if(v < LAST_OP) // operator
        {
            if(v == LIST)  // list has a size and another OP associated with it.
            {
                v |= (*bli++) << 8;   // merge size into LIST op
                iv_rpnstack.push_back(v | OPERATION);
                v = *bli++;  // get the list operation (EQ or NE)
            }
            iv_rpnstack.push_back(v | OPERATION);
            // we are done
            break;
        }
        // not op - always two bytes
        v = (v << 8) + (*bli++);
        iv_rpnstack.push_back(iv_symbols->get_rpn_id(v));
    }
    return bli;
}

//-------------------------------------------------------------------------------------------------

void Rpn::append(const Rpn & i_rpn)
{
    iv_rpnstack.insert(iv_rpnstack.end(), i_rpn.iv_rpnstack.begin(), i_rpn.iv_rpnstack.end());
}

//-------------------------------------------------------------------------------------------------

std::string Rpn::symbol_names() const
{
    std::string result;
    for(RPNSTACK::const_iterator i = iv_rpnstack.begin(); i != iv_rpnstack.end(); ++i)
    {
        if((*i) & SYMBOL)
        {
            if(result.size()) result.append(" ");  // space or lf??
            result.append(iv_symbols->find_name(*i));
        }
    }
    return result;
}

//-------------------------------------------------------------------------------------------------

std::string  Rpn::listing(const char * i_desc, const std::string & spyname, bool i_final)
{
    std::ostringstream odesc;
    std::ostringstream oss;
    uint32_t rpn_byte_size = 0;


    oss << std::hex << std::setfill('0');

    //oss << "0x" << std::setw(2) << iv_rpnstack.size() << '\t' << i_desc << std::endl;
    for(RPNSTACK::iterator i = iv_rpnstack.begin(); i != iv_rpnstack.end(); ++i)
    {
        if( (*i) & OPERATION ) // operator
        {
            ++rpn_byte_size;
            uint32_t op_id = (*i) - OPERATION;
            uint32_t count = op_id >> 8;   // NOTE: only the LIST operator has a count
            op_id &= OP_MASK;

            if(op_id < LAST_OP)
            {
                oss << "0x" << std::setw(2) << op_id << "\t\t" << OP_TXT[op_id] << std::endl;
                if(op_id == LIST)
                {
                    ++rpn_byte_size;
                    oss << "0x" << std::setw(2) << count << "\t\t"
                        << std::dec << count << std::hex << std::endl;
                }
            }
            else
            {
                oss << "0x" << op_id << "\t\t" << "INVALID OPERATION" << std::endl;
            }
        }
        else if((*i) & NUMBER)
        {
            uint32_t size = 0;
            uint64_t data = iv_symbols->get_numeric_data(*i,size);
            if(i_final)
            {
                uint32_t tag = iv_symbols->get_numeric_tag(*i);
                rpn_byte_size += 2;
                oss << "0x" << std::setw(4) << tag << "\t\t" << "PUSH 0x"
                    << std::setw(size*2) << data << std::endl;
            }
            else
            {
                rpn_byte_size += size;
                oss << "0x" << std::setw(size * 2) << data << '\t' << "Numerica Literal" << std::endl;
            }
        }
        else if((*i) & SYMBOL)
        {
            std::string name = iv_symbols->find_name(*i);

            if(i_final)
            {
                uint32_t val = iv_symbols->get_tag(*i);
                uint32_t type = val & Symbols::TYPE_MASK;

                if (type == Symbols::LIT_TYPE ||
                    type == Symbols::VAR_TYPE)
                {
                    rpn_byte_size += 2;
                    oss << "0x" << std::setw(4) << val << "\t\t" << "PUSH " << name << std::endl;
                }
                else
                {
                    rpn_byte_size +=4;
                    oss << "0x" << std::setw(8) << val  << '\t' << name << "\tUnresolved!" << std::endl;
                }
            }
            else  // debug listing
            {
                rpn_byte_size +=2;
                //oss << "0x" << std::setw(8) << *i << '\t'
                oss << "\t\t" << "PUSH " << name << std::endl;

            }
        }
        else
        {
            oss << "0x" << std::setw(8) << *i << '\t' << "Unknown RPN id" << std::endl;
        }
    }

    if((iv_rpnstack.size() == 1) && (iv_rpnstack.front() & SYMBOL)) // skip size and desc
    {
        odesc << oss.str();
    }
    else
    {
        odesc << std::hex << std::setfill('0')
            << "0x" << std::setw(4) << rpn_byte_size << "\t\t";
        if(i_desc) odesc << i_desc;
        else odesc << std::dec << rpn_byte_size << " BYTES";
        odesc << std::endl;
        odesc << oss.str();
    }

    return odesc.str();
}

//-------------------------------------------------------------------------------------------------

void Rpn::bin_str(BINSEQ & o_blist, bool i_prepend_count)  // binary version to write to file
{
    BINSEQ blist;
    uint32_t count = 0;


    for(RPNSTACK::iterator i = iv_rpnstack.begin(); i != iv_rpnstack.end(); ++i)
    {
        uint32_t v = *i;
        uint32_t type = v & TYPE_MASK;
        uint16_t tag;

        switch (type)
        {
            case OPERATION:     blist.push_back((uint8_t)v);
                                ++count;
                                if((v & OP_MASK) == LIST)
                                {
                                    ++count;
                                    blist.push_back((uint8_t)(v >> 8));
                                }
                                break;

            case SYMBOL:        tag = iv_symbols->get_tag(v);
                                blist.push_back((uint8_t)(tag >> 8));
                                blist.push_back((uint8_t) tag);
                                count += 2;
                                break;

            case NUMBER:        tag = iv_symbols->get_numeric_tag(v);
                                blist.push_back((uint8_t)(tag >> 8));
                                blist.push_back((uint8_t) tag);
                                count += 2;
                                break;
            case ARRAY_INDEX:
                                tag = iv_symbols->get_numeric_array_tag(v);
                                blist.push_back((uint8_t)(tag >> 8));
                                blist.push_back((uint8_t) tag);
                                count += 2;
                                break;

            default:
                    std::cerr << "ERROR! Rpn::bit_str() Invalid Rpn type: " << v << std::endl;
                    break;
        }
    }

    if (i_prepend_count)
    {
        o_blist.push_back((uint8_t) count);
    }

    o_blist.insert(o_blist.end(), blist.begin(), blist.end());
}

//-------------------------------------------------------------------------------------------------
// Used for RPN filtering (resolve())
void Rpn::pop_bool(EVAL_STACK & i_stack, RPN_VALUE & o_value) //dg002a
{
    // convert numbers or any to bool
    if(i_stack.size())
    {
        o_value = i_stack.back();
        i_stack.pop_back();
        if(o_value.type == RPN_NUMBER)
        {
            if(o_value.data == 0) o_value.type = RPN_FALSE;
            else
            {
                o_value.type = RPN_TRUE;
                if(o_value.data != 1)
                {
                    cerr << "Was expecting a bool, got a number - assume true" << endl;
                }
            }
        }
        else if(o_value.type == RPN_ANY) o_value.type = RPN_TRUE;
        // else already a bool
    }
    else
    {
        o_value.type = RPN_TRUE;
        cerr << "Empty stack!" << endl;
    }
}
//-------------------------------------------------------------------------------------------------

void Rpn::pop_number(EVAL_STACK & i_stack, RPN_VALUE & o_value) //dg002a
{
    // Convert bools to ANY if a number is expected (eg true == 1)
    if(i_stack.size())
    {
        o_value = i_stack.back();
        i_stack.pop_back();
        //if(o_value.type != RPN_NUMBER && o_value.type != RPN_ANY)
        //{
        //    if(o_value.type == RPN_FALSE) o_value.data = 0;
        //    else if(o_value.type == RPN_TRUE) o_value.data = 1;
        //    //o_value.type = RPN_NUMBER; // not safe when just checking EC
        //    o_value.type = RPN_ANY;
        //}
        // else leave as is
    }
    else
    {
        o_value.type = RPN_ANY;
        cerr << "Empty stack!" << endl;
    }
}

//-------------------------------------------------------------------------------------------------

bool Rpn::resolve_ec(uint32_t i_ec)  //dg002a
{
    SYMBOL_VAL_LIST v;
    SYMBOL_VAL_PAIR p(string("EC"),i_ec);
    v.push_back(p);

    //SYMBOL_VAL_PAIR p1(string("SERIES"),0xA000006C);
    //SYMBOL_VAL_PAIR p2(string("SERIES_IP"),0xA000006C);
    //SYMBOL_VAL_PAIR p3(string("SERIES_Z"),0xA000006D);
    //v.push_back(p1);
    //v.push_back(p2);
    //v.push_back(p3);

    return resolve(v);
}

//-------------------------------------------------------------------------------------------------
// Tries to resolve as much of the RPN as  possible
// @return false means that based on the given varlist, the RPN will never evaluate to true.
//               eg. unconditionally false
//         true means RPN either evaluated to true or there is not enough information to evaluate the RPN
// @note SPY RPNs are not supported
//
bool Rpn::resolve(SYMBOL_VAL_LIST & i_varlist)
{

    bool result = true;

    EVAL_STACK stack;
    RPN_VALUE rpn_true(RPN_TRUE);
    RPN_VALUE rpn_false(RPN_FALSE);
    RPN_VALUE r1;
    RPN_VALUE r2;

    for(RPNSTACK::const_iterator i = iv_rpnstack.begin(); i != iv_rpnstack.end(); ++i)
    {
        if( (*i) & OPERATION )
        {
            uint32_t op = (*i) - OPERATION;
            uint32_t count = op >> 8;
            op &= OP_MASK;

            switch(op)
            {
                case AND:
                    pop_bool(stack,r1);
                    pop_bool(stack,r2);
                    if(r1.type == RPN_TRUE && r2.type == RPN_TRUE) stack.push_back(rpn_true);
                    else stack.push_back(rpn_false);
                    break;

                case OR:
                    pop_bool(stack,r1);
                    pop_bool(stack,r2);
                    if(r1.type == RPN_TRUE || r2.type == RPN_TRUE) stack.push_back(rpn_true);
                    else stack.push_back(rpn_false);
                    break;

                case NOT:
                    pop_bool(stack,r1);
                    if(r1.type == RPN_TRUE) stack.push_back(rpn_false);
                    else if(r1.type == RPN_FALSE) stack.push_back(rpn_true);
                    break;

                case EQ:
                    pop_number(stack,r1);
                    pop_number(stack,r2);
                    if(r1.type == RPN_ANY || r2.type == RPN_ANY) stack.push_back(rpn_true);
                    else if(r1.type == RPN_NUMBER && r2.type == RPN_NUMBER)
                    {
                        if(r1.data == r2.data) stack.push_back(rpn_true);
                        else stack.push_back(rpn_false);
                    }
                    else if(r1.type == RPN_TRUE && r2.type == RPN_NUMBER)
                    {
                        if(r2.data == 0) stack.push_back(rpn_false);
                        else stack.push_back(rpn_true);
                    }
                    else if(r2.type == RPN_TRUE && r1.type == RPN_NUMBER)
                    {
                        if(r1.data == 0) stack.push_back(rpn_false);
                        else stack.push_back(rpn_true);
                    }
                    else if(r1.type == RPN_FALSE && r2.type == RPN_NUMBER)
                    {
                        if(r2.data == 0) stack.push_back(rpn_true);
                        else stack.push_back(rpn_false);
                    }
                    else if(r2.type == RPN_FALSE && r1.type == RPN_NUMBER)
                    {
                        if(r1.data == 0) stack.push_back(rpn_true);
                        else stack.push_back(rpn_false);
                    }
                    else if((r1.type == RPN_TRUE && r2.type == RPN_FALSE) ||
                            (r1.type == RPN_FALSE && r2.type == RPN_TRUE)) stack.push_back(rpn_false);
                    else stack.push_back(rpn_true);
                    break;

                case NE:
                    pop_number(stack,r1);
                    pop_number(stack,r2);
                    if(r1.type == RPN_ANY || r2.type == RPN_ANY) stack.push_back(rpn_true);
                    else
                    {
                        if(r1.data != r2.data) stack.push_back(rpn_true);
                        else stack.push_back(rpn_false);
                    }
                    break;

                case GT:
                    pop_number(stack,r1);
                    pop_number(stack,r2);
                    if(r1.type == RPN_ANY || r2.type == RPN_ANY) stack.push_back(rpn_true);
                    else
                    {
                        if(r2.data > r1.data) stack.push_back(rpn_true);
                        else stack.push_back(rpn_false);
                    }
                    break;

                case GE:
                    pop_number(stack,r1);
                    pop_number(stack,r2);
                    if(r1.type == RPN_ANY || r2.type == RPN_ANY) stack.push_back(rpn_true);
                    else
                    {
                        if(r2.data >= r1.data) stack.push_back(rpn_true);
                        else stack.push_back(rpn_false);
                    }
                    break;

                case LT:
                    pop_number(stack,r1);
                    pop_number(stack,r2);
                    if(r1.type == RPN_ANY || r2.type == RPN_ANY) stack.push_back(rpn_true);
                    else
                    {
                        if(r2.data < r1.data) stack.push_back(rpn_true);
                        else stack.push_back(rpn_false);
                    }
                    break;

                case LE:
                    pop_number(stack,r1);
                    pop_number(stack,r2);
                    if(r1.type == RPN_ANY || r2.type == RPN_ANY) stack.push_back(rpn_true);
                    else
                    {
                        if(r2.data <= r1.data) stack.push_back(rpn_true);
                        else stack.push_back(rpn_false);
                    }
                    break;

                case PLUS:
                    r1 = stack.back(); stack.pop_back();
                    r2 = stack.back(); stack.pop_back();
                    if(r1.type == RPN_NUMBER && r2.type == RPN_NUMBER)
                        stack.push_back(RPN_VALUE(r1.data + r2.data,RPN_NUMBER));
                    else cerr << "Was not expecting a non-numeric value for operator +" << endl;
                    break;

                case MINUS:
                    r1 = stack.back(); stack.pop_back();
                    r2 = stack.back(); stack.pop_back();
                    if(r1.type == RPN_NUMBER && r2.type == RPN_NUMBER)
                        stack.push_back(RPN_VALUE(r2.data - r1.data,RPN_NUMBER));
                    else cerr << "Was not expecting a non-numeric value for operator -" << endl;
                    break;

                case MULT:
                    r1 = stack.back(); stack.pop_back();
                    r2 = stack.back(); stack.pop_back();
                    if(r1.type == RPN_NUMBER && r2.type == RPN_NUMBER)
                        stack.push_back(RPN_VALUE(r2.data * r1.data,RPN_NUMBER));
                    else cerr << "Was not expecting a non-numeric value for operator *" << endl;
                    break;

                case DIVIDE:
                    r1 = stack.back(); stack.pop_back();
                    r2 = stack.back(); stack.pop_back();
                    if(r1.type == RPN_NUMBER && r2.type == RPN_NUMBER)
                        stack.push_back(RPN_VALUE(r2.data / r1.data,RPN_NUMBER));
                    else cerr << "Was not expecting a non-numeric value for operator /" << endl;
                    break;

                case MOD:
                    r1 = stack.back(); stack.pop_back();
                    r2 = stack.back(); stack.pop_back();
                    if(r1.type == RPN_NUMBER && r2.type == RPN_NUMBER)
                        stack.push_back(RPN_VALUE(r2.data % r1.data,RPN_NUMBER));
                    else cerr << "Was not expecting a non-numeric value for operator %" << endl;
                    break;

                case LIST: // lists are always true - TODO look for EC list ??
                    ++i;
                    while(count--) stack.pop_back();
                    stack.push_back(rpn_true);
                    break;

                case SHIFTLEFT:
                    r1 = stack.back(); stack.pop_back();
                    r2 = stack.back(); stack.pop_back();
                    if(r1.type == RPN_NUMBER && r2.type == RPN_NUMBER)
                        stack.push_back(RPN_VALUE(r2.data << r1.data,RPN_NUMBER));
                    else cerr << "Was not expecting a non-numeric value for operator <<" << endl;
                    break;

                case SHIFTRIGHT:
                    r1 = stack.back(); stack.pop_back();
                    r2 = stack.back(); stack.pop_back();
                    if(r1.type == RPN_NUMBER && r2.type == RPN_NUMBER)
                        stack.push_back(RPN_VALUE(r2.data >> r1.data,RPN_NUMBER));
                    else cerr << "Was not expecting a non-numeric value for operator >>" << endl;
                    break;

                case TRUE_OP:  //dg003a
                    stack.push_back(rpn_true);
                    break;

                case FALSE_OP:  //dg003a
                    stack.push_back(rpn_false);
                    break;

                default:
                    cerr << "Invalid operator " << op << endl;
                    break;
            }
        }
        else if((*i) & NUMBER)
        {
            uint32_t size = 0;
            uint64_t data = iv_symbols->get_numeric_data(*i,size);
            stack.push_back(RPN_VALUE(data,RPN_NUMBER));
        }
        else if((*i) & SYMBOL)  // variables and cini enums
        {
            std::string name = iv_symbols->find_name(*i);
            SYMBOL_VAL_LIST::iterator vvi = i_varlist.begin();
            for(; vvi != i_varlist.end(); ++vvi)
            {
                if(name == vvi->first)
                {
                    // cerr << name << " = " << vvi->second << endl;
                    stack.push_back(RPN_VALUE((uint64_t)vvi->second,RPN_NUMBER));
                    break;
                }
            }
            if(vvi == i_varlist.end())
            {
                // cerr << name << " = ANY" << endl;
                stack.push_back(RPN_VALUE(RPN_ANY));
            }
        }
    }
    // an empty RPN is true, if it's not empty then check for false
    if(stack.size())
    {
        RPN_VALUE r = stack.back();
        if(r.type == RPN_FALSE) result = false;
    }
    return result;
}

//-------------------------------------------------------------------------------------------------

uint8_t Rpn::extract8(BINSEQ::const_iterator & bli)
{
    uint8_t val;
    val += (uint8_t)(*bli++);
    return val;
}


//-------------------------------------------------------------------------------------------------

uint16_t Rpn::extract16(BINSEQ::const_iterator & bli)
{
    uint16_t val;
    val = ((uint16_t)(*bli++)) << 8;
    val += (uint16_t)(*bli++);
    return val;
}

//-------------------------------------------------------------------------------------------------

uint32_t Rpn::extract32(BINSEQ::const_iterator & bli)
{
    uint32_t val = extract16(bli);
    val <<= 16;
    val += extract16(bli);
    return val;
}


//-------------------------------------------------------------------------------------------------

uint64_t Rpn::extract64(BINSEQ::const_iterator & bli)
{
    uint64_t val = extract32(bli);
    val <<= 32;
    val += extract32(bli);
    return val;
}

//-------------------------------------------------------------------------------------------------

void Rpn::set8(BINSEQ & bl, uint8_t v)
{
    bl.push_back((uint8_t)(v));
}

//-------------------------------------------------------------------------------------------------

void Rpn::set16(BINSEQ & bl, uint16_t v)
{
    bl.push_back((uint8_t)(v >> 8));
    bl.push_back((uint8_t)(v));
}

//-------------------------------------------------------------------------------------------------

void Rpn::set32(BINSEQ & bl, uint32_t v)
{
    bl.push_back((uint8_t)(v >> 24));
    bl.push_back((uint8_t)(v >> 16));
    bl.push_back((uint8_t)(v >> 8));
    bl.push_back((uint8_t)(v));
}

//-------------------------------------------------------------------------------------------------

void Rpn::set64(BINSEQ & bl, uint64_t v)
{
    bl.push_back((uint8_t)(v >> 56));
    bl.push_back((uint8_t)(v >> 48));
    bl.push_back((uint8_t)(v >> 40));
    bl.push_back((uint8_t)(v >> 32));
    bl.push_back((uint8_t)(v >> 24));
    bl.push_back((uint8_t)(v >> 16));
    bl.push_back((uint8_t)(v >> 8));
    bl.push_back((uint8_t)(v));
}


//-------------------------------------------------------------------------------------------------


