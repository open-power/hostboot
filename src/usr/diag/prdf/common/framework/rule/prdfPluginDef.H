/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdfPluginDef.H $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef __PRDFPLUGINDEF_H
#define __PRDFPLUGINDEF_H

#include <stdint.h>

#ifdef __HOSTBOOT_MODULE
  #include <stdlib.h>
#else
  #include <cstdlib>
#endif

namespace PrdfPluginDef
{
    class ParameterList
    {
    };

    template <typename _A>
        class SingleParameter : public ParameterList
        {
            private:
                _A cv_value;

            public:
                SingleParameter(_A v) : cv_value(v) {};
                operator _A() { return cv_value; };
        };

    template <typename _A>
    inline SingleParameter<_A> *
        bindParm(_A v) { return new SingleParameter<_A>(v); };

    template <typename _A, typename _B>
        class TwoParameter : public ParameterList
        {
            private:
                _A cv_valueA;
                _B cv_valueB;

            public:
                TwoParameter(_A vA, _B vB) : cv_valueA(vA), cv_valueB(vB) {};
                _A getA() { return cv_valueA; };
                _B getB() { return cv_valueB; };
        };

    template <typename _A, typename _B>
    inline TwoParameter<_A, _B> *
        bindParm(_A vA, _B vB) { return new TwoParameter<_A,_B>(vA,vB); };

    template <typename _A, typename _B, typename _C>
        class ThreeParameter : public ParameterList
        {
            private:
                _A cv_valueA;
                _B cv_valueB;
                _C cv_valueC;

            public:
                ThreeParameter(_A vA, _B vB, _C vC)
                    : cv_valueA(vA), cv_valueB(vB), cv_valueC(vC) {};
                _A getA() { return cv_valueA; };
                _B getB() { return cv_valueB; };
                _C getC() { return cv_valueC; };
        };

    template <typename _A, typename _B, typename _C>
    inline ThreeParameter<_A, _B, _C> *
        bindParm(_A vA, _B vB, _C vC)
            { return new ThreeParameter<_A,_B,_C>(vA,vB,vC); };

    template <typename _A, typename _B, typename _C, typename _D>
        class FourParameter : public ParameterList
        {
            private:
                _A cv_valueA;
                _B cv_valueB;
                _C cv_valueC;
                _D cv_valueD;

            public:
                FourParameter(_A vA, _B vB, _C vC, _D vD)
                    : cv_valueA(vA), cv_valueB(vB), cv_valueC(vC),
                      cv_valueD(vD)
                    {};
                _A getA() { return cv_valueA; };
                _B getB() { return cv_valueB; };
                _C getC() { return cv_valueC; };
                _D getD() { return cv_valueD; };
        };

    template <typename _A, typename _B, typename _C, typename _D>
    inline FourParameter<_A, _B, _C, _D> *
        bindParm(_A vA, _B vB, _C vC, _D vD)
            { return new FourParameter<_A,_B,_C,_D>(vA,vB,vC,vD); };


};

class PrdfExtensibleFunctionType
{
    public:
        virtual ~PrdfExtensibleFunctionType() {};
};

template <typename _ExtensibleObject>
class PrdfExtensibleFunction : public PrdfExtensibleFunctionType
{
    public:
        virtual ~PrdfExtensibleFunction() { }  // zs01
        virtual int32_t operator()(_ExtensibleObject * A,
                                   PrdfPluginDef::ParameterList * B) = 0;
};

class PrdfExtensibleChip;
class PrdfExtensibleDomain;
typedef PrdfExtensibleFunction<PrdfExtensibleChip> PrdfExtensibleChipFunction;
typedef PrdfExtensibleFunction<PrdfExtensibleDomain>
                                        PrdfExtensibleDomainFunction;


template <typename _ExtensibleObject>
class PrdfPlugin : public PrdfExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *, PrdfPluginDef::ParameterList *);
    public:
        explicit PrdfPlugin(int32_t (*func)(_ExtensibleObject *,
                                            PrdfPluginDef::ParameterList *))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PrdfPluginDef::ParameterList * B)
        {
            int32_t i = 0;
            if (NULL != _func)
            {
                i = _func(A,B);
            }
            delete B;
            return i;
        };
};

template <typename _ExtensibleObject>
class PrdfPlugin_0arg : public PrdfExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *);
    public:
        explicit PrdfPlugin_0arg(int32_t (*func)(_ExtensibleObject *))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PrdfPluginDef::ParameterList * B)
        {
            int32_t i = _func(A);
            delete B;
            return i;
        };
};

template <typename _ExtensibleObject>
inline PrdfPlugin_0arg<_ExtensibleObject>
    bind_plugin(int32_t (*func)(_ExtensibleObject *))
        { return PrdfPlugin_0arg<_ExtensibleObject>(func); };

template <typename _ExtensibleObject>
inline PrdfPlugin_0arg<_ExtensibleObject> *
    bind_plugin_ptr(int32_t (*func)(_ExtensibleObject *), void * ptr)
        { return new (ptr) PrdfPlugin_0arg<_ExtensibleObject>(func); };

template <typename _A, typename _ExtensibleObject>
class PrdfPlugin_1arg : public PrdfExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *, _A);
    public:
        explicit PrdfPlugin_1arg(int32_t (*func)(_ExtensibleObject *, _A))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PrdfPluginDef::ParameterList * B)
        {
            int32_t i = _func(A,
                (_A)static_cast<PrdfPluginDef::SingleParameter<_A> &>(*B));
            delete B;
            return i;
        };
};

template <typename _A, typename _ExtensibleObject>
inline PrdfPlugin_1arg<_A, _ExtensibleObject>
    bind_plugin(int32_t (*func)(_ExtensibleObject *, _A))
        { return PrdfPlugin_1arg<_A, _ExtensibleObject>(func); };

template <typename _A, typename _ExtensibleObject>
inline PrdfPlugin_1arg<_A, _ExtensibleObject> *
    bind_plugin_ptr(int32_t (*func)(_ExtensibleObject *, _A), void * ptr)
        { return new (ptr) PrdfPlugin_1arg<_A, _ExtensibleObject>(func); };


template <typename _A, typename _B, typename _ExtensibleObject>
class PrdfPlugin_2arg : public PrdfExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *, _A, _B);
    public:
        explicit PrdfPlugin_2arg(int32_t (*func)(_ExtensibleObject *, _A, _B))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PrdfPluginDef::ParameterList * B)
        {
            int32_t i = _func(A,
                static_cast<PrdfPluginDef::TwoParameter<_A,_B> *>(B)->getA(),
                static_cast<PrdfPluginDef::TwoParameter<_A,_B> *>(B)->getB());
            delete B;
            return i;
        };
};

template <typename _A, typename _B, typename _ExtensibleObject>
inline PrdfPlugin_2arg<_A, _B, _ExtensibleObject>
    bind_plugin(int32_t (*func)(_ExtensibleObject *, _A, _B))
        { return PrdfPlugin_2arg<_A, _B, _ExtensibleObject>(func); };

template <typename _A, typename _B, typename _ExtensibleObject>
inline PrdfPlugin_2arg<_A, _B, _ExtensibleObject> *
    bind_plugin_ptr(int32_t (*func)(_ExtensibleObject *, _A, _B), void * ptr)
        { return new (ptr) PrdfPlugin_2arg<_A, _B, _ExtensibleObject>(func); };


template <typename _A, typename _B, typename _C, typename _ExtensibleObject>
class PrdfPlugin_3arg : public PrdfExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *, _A, _B, _C);
    public:
        explicit PrdfPlugin_3arg(int32_t (*func)
                    (_ExtensibleObject *, _A, _B, _C))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PrdfPluginDef::ParameterList * B)
        {
            int32_t i = _func(A,
                static_cast<PrdfPluginDef::ThreeParameter<_A,_B,_C> *>
                        (B)->getA(),
                static_cast<PrdfPluginDef::ThreeParameter<_A,_B,_C> *>
                        (B)->getB(),
                static_cast<PrdfPluginDef::ThreeParameter<_A,_B,_C> *>
                        (B)->getC()
                    );
            delete B;
            return i;
        };
};

template <typename _A, typename _B, typename _C, typename _ExtensibleObject>
inline PrdfPlugin_3arg<_A, _B, _C, _ExtensibleObject>
    bind_plugin(int32_t (*func)(_ExtensibleObject *, _A, _B, _C))
        { return PrdfPlugin_3arg<_A, _B, _C, _ExtensibleObject>(func); };

template <typename _A, typename _B, typename _C, typename _ExtensibleObject>
inline PrdfPlugin_3arg<_A, _B, _C, _ExtensibleObject> *
    bind_plugin_ptr(int32_t (*func)(_ExtensibleObject *, _A, _B, _C),
                    void * ptr)
        { return new (ptr)
                PrdfPlugin_3arg<_A, _B, _C, _ExtensibleObject>(func); };

template <typename _A, typename _B, typename _C, typename _D,
          typename _ExtensibleObject>
class PrdfPlugin_4arg : public PrdfExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *, _A, _B, _C, _D);
    public:
        explicit PrdfPlugin_4arg(int32_t (*func)
                    (_ExtensibleObject *, _A, _B, _C, _D))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PrdfPluginDef::ParameterList * B)
        {
            int32_t i = _func(A,
                static_cast<PrdfPluginDef::FourParameter<_A,_B,_C,_D> *>
                        (B)->getA(),
                static_cast<PrdfPluginDef::FourParameter<_A,_B,_C,_D> *>
                        (B)->getB(),
                static_cast<PrdfPluginDef::FourParameter<_A,_B,_C,_D> *>
                        (B)->getC(),
                static_cast<PrdfPluginDef::FourParameter<_A,_B,_C,_D> *>
                        (B)->getD()
                    );
            delete B;
            return i;
        };
};

template <typename _A, typename _B, typename _C, typename _D,
          typename _ExtensibleObject>
inline PrdfPlugin_4arg<_A, _B, _C, _D, _ExtensibleObject>
    bind_plugin(int32_t (*func)(_ExtensibleObject *, _A, _B, _C, _D))
        { return PrdfPlugin_4arg<_A, _B, _C, _D, _ExtensibleObject>(func); };

template <typename _A, typename _B, typename _C, typename _D,
          typename _ExtensibleObject>
inline PrdfPlugin_4arg<_A, _B, _C, _D, _ExtensibleObject> *
    bind_plugin_ptr(int32_t (*func)(_ExtensibleObject *, _A, _B, _C, _D),
                    void * ptr)
        { return new (ptr)
                PrdfPlugin_4arg<_A, _B, _C, _D, _ExtensibleObject>(func); };


#define __PRDF_PLUGIN_XYZ(X,Y,Z) X##Y##Z
#define __PRDF_PLUGIN_MAKENAME(X,Y,Z) __PRDF_PLUGIN_XYZ(X,Y,Z)

#define PRDF_PLUGIN_DEFINE(CHIP,PLUGIN_NAME) \
    class __PRDF_PLUGIN_MAKENAME(PrdfPlugin_Registration_,CHIP,PLUGIN_NAME) \
    { \
      private: \
        PrdfExtensibleFunctionType * cv_plugin; \
        PrdfPluginRegisterClass cv_registerClass; \
        char cv_plugin_space[sizeof(PrdfPlugin<PrdfExtensibleChip>)]; \
      public: \
        __PRDF_PLUGIN_MAKENAME(PrdfPlugin_Registration_,CHIP,PLUGIN_NAME)() : \
            cv_plugin( bind_plugin_ptr(&PRDF::CHIP::PLUGIN_NAME, \
                                       &cv_plugin_space) ), \
            cv_registerClass(#CHIP,#PLUGIN_NAME,cv_plugin) \
        {} \
    }; \
    __PRDF_PLUGIN_MAKENAME(PrdfPlugin_Registration_,CHIP,PLUGIN_NAME) \
        __PRDF_PLUGIN_MAKENAME(g_PluginRegistration_,CHIP,PLUGIN_NAME)
#endif

#include <prdfPluginMap.H>

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- -------------------------------
//       F494911  f310 03/04/05 iawillia Initial File Creation
//         F522638  f300 09/27/05 iawillia Add 4 parm, fix possible obj strip.
//  zs01 D620028  f330 07/25/07 zshelle  Support for mcp5 compiler
// End Change Log *****************************************************
