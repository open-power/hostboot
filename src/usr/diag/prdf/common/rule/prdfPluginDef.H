/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfPluginDef.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef __PRDFPLUGINDEF_H
#define __PRDFPLUGINDEF_H

#include <stdint.h>

#ifdef __HOSTBOOT_MODULE
  #include <stdlib.h>
#else
  #include <cstdlib>
#endif

namespace PRDF
{

namespace PluginDef
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

class ExtensibleFunctionType
{
    public:
        virtual ~ExtensibleFunctionType() {};
};

template <typename _ExtensibleObject>
class ExtensibleFunction : public ExtensibleFunctionType
{
    public:
        virtual ~ExtensibleFunction() { }  // zs01
        virtual int32_t operator()(_ExtensibleObject * A,
                                   PluginDef::ParameterList * B) = 0;
};

class ExtensibleChip;
class ExtensibleDomain;
typedef ExtensibleFunction<ExtensibleChip> ExtensibleChipFunction;
typedef ExtensibleFunction<ExtensibleDomain>
                                        ExtensibleDomainFunction;

template <typename _ExtensibleObject>
class Plugin : public ExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *, PluginDef::ParameterList *);
    public:
        explicit Plugin(int32_t (*func)(_ExtensibleObject *,
                                            PluginDef::ParameterList *))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PluginDef::ParameterList * B)
        {
            int32_t i = 0;
            if (nullptr != _func)
            {
                i = _func(A,B);
            }
            delete B;
            return i;
        };
};

template <typename _ExtensibleObject>
class Plugin_0arg : public ExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *);
    public:
        explicit Plugin_0arg(int32_t (*func)(_ExtensibleObject *))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PluginDef::ParameterList * B)
        {
            int32_t i = _func(A);
            delete B;
            return i;
        };
};

template <typename _ExtensibleObject>
inline Plugin_0arg<_ExtensibleObject>
    bind_plugin(int32_t (*func)(_ExtensibleObject *))
        { return Plugin_0arg<_ExtensibleObject>(func); };

template <typename _ExtensibleObject>
inline Plugin_0arg<_ExtensibleObject> *
    bind_plugin_ptr(int32_t (*func)(_ExtensibleObject *), void * ptr)
        { return new (ptr) Plugin_0arg<_ExtensibleObject>(func); };

template <typename _A, typename _ExtensibleObject>
class Plugin_1arg : public ExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *, _A);
    public:
        explicit Plugin_1arg(int32_t (*func)(_ExtensibleObject *, _A))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PluginDef::ParameterList * B)
        {
            int32_t i = _func(A,
                (_A)static_cast<PluginDef::SingleParameter<_A> &>(*B));
            delete B;
            return i;
        };
};

template <typename _A, typename _ExtensibleObject>
inline Plugin_1arg<_A, _ExtensibleObject>
    bind_plugin(int32_t (*func)(_ExtensibleObject *, _A))
        { return Plugin_1arg<_A, _ExtensibleObject>(func); };

template <typename _A, typename _ExtensibleObject>
inline Plugin_1arg<_A, _ExtensibleObject> *
    bind_plugin_ptr(int32_t (*func)(_ExtensibleObject *, _A), void * ptr)
        { return new (ptr) Plugin_1arg<_A, _ExtensibleObject>(func); };


template <typename _A, typename _B, typename _ExtensibleObject>
class Plugin_2arg : public ExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *, _A, _B);
    public:
        explicit Plugin_2arg(int32_t (*func)(_ExtensibleObject *, _A, _B))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PluginDef::ParameterList * B)
        {
            int32_t i = _func(A,
                static_cast<PluginDef::TwoParameter<_A,_B> *>(B)->getA(),
                static_cast<PluginDef::TwoParameter<_A,_B> *>(B)->getB());
            delete B;
            return i;
        };
};

template <typename _A, typename _B, typename _ExtensibleObject>
inline Plugin_2arg<_A, _B, _ExtensibleObject>
    bind_plugin(int32_t (*func)(_ExtensibleObject *, _A, _B))
        { return Plugin_2arg<_A, _B, _ExtensibleObject>(func); };

template <typename _A, typename _B, typename _ExtensibleObject>
inline Plugin_2arg<_A, _B, _ExtensibleObject> *
    bind_plugin_ptr(int32_t (*func)(_ExtensibleObject *, _A, _B), void * ptr)
        { return new (ptr) Plugin_2arg<_A, _B, _ExtensibleObject>(func); };


template <typename _A, typename _B, typename _C, typename _ExtensibleObject>
class Plugin_3arg : public ExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *, _A, _B, _C);
    public:
        explicit Plugin_3arg(int32_t (*func)
                    (_ExtensibleObject *, _A, _B, _C))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PluginDef::ParameterList * B)
        {
            int32_t i = _func(A,
                static_cast<PluginDef::ThreeParameter<_A,_B,_C> *>
                        (B)->getA(),
                static_cast<PluginDef::ThreeParameter<_A,_B,_C> *>
                        (B)->getB(),
                static_cast<PluginDef::ThreeParameter<_A,_B,_C> *>
                        (B)->getC()
                    );
            delete B;
            return i;
        };
};

template <typename _A, typename _B, typename _C, typename _ExtensibleObject>
inline Plugin_3arg<_A, _B, _C, _ExtensibleObject>
    bind_plugin(int32_t (*func)(_ExtensibleObject *, _A, _B, _C))
        { return Plugin_3arg<_A, _B, _C, _ExtensibleObject>(func); };

template <typename _A, typename _B, typename _C, typename _ExtensibleObject>
inline Plugin_3arg<_A, _B, _C, _ExtensibleObject> *
    bind_plugin_ptr(int32_t (*func)(_ExtensibleObject *, _A, _B, _C),
                    void * ptr)
        { return new (ptr)
                Plugin_3arg<_A, _B, _C, _ExtensibleObject>(func); };

template <typename _A, typename _B, typename _C, typename _D,
          typename _ExtensibleObject>
class Plugin_4arg : public ExtensibleFunction<_ExtensibleObject>
{
    protected:
        int32_t (*_func)(_ExtensibleObject *, _A, _B, _C, _D);
    public:
        explicit Plugin_4arg(int32_t (*func)
                    (_ExtensibleObject *, _A, _B, _C, _D))
            : _func(func) {};

        int32_t operator()(_ExtensibleObject * A,
                           PluginDef::ParameterList * B)
        {
            int32_t i = _func(A,
                static_cast<PluginDef::FourParameter<_A,_B,_C,_D> *>
                        (B)->getA(),
                static_cast<PluginDef::FourParameter<_A,_B,_C,_D> *>
                        (B)->getB(),
                static_cast<PluginDef::FourParameter<_A,_B,_C,_D> *>
                        (B)->getC(),
                static_cast<PluginDef::FourParameter<_A,_B,_C,_D> *>
                        (B)->getD()
                    );
            delete B;
            return i;
        };
};

template <typename _A, typename _B, typename _C, typename _D,
          typename _ExtensibleObject>
inline Plugin_4arg<_A, _B, _C, _D, _ExtensibleObject>
    bind_plugin(int32_t (*func)(_ExtensibleObject *, _A, _B, _C, _D))
        { return Plugin_4arg<_A, _B, _C, _D, _ExtensibleObject>(func); };

template <typename _A, typename _B, typename _C, typename _D,
          typename _ExtensibleObject>
inline Plugin_4arg<_A, _B, _C, _D, _ExtensibleObject> *
    bind_plugin_ptr(int32_t (*func)(_ExtensibleObject *, _A, _B, _C, _D),
                    void * ptr)
        { return new (ptr)
                Plugin_4arg<_A, _B, _C, _D, _ExtensibleObject>(func); };

} // end namespace PRDF

#define __PRDF_PLUGIN_XYZ(X,Y,Z) X##Y##Z
#define __PRDF_PLUGIN_MAKENAME(X,Y,Z) __PRDF_PLUGIN_XYZ(X,Y,Z)

#define PRDF_PLUGIN_DEFINE(CHIP,PLUGIN_NAME) \
    PRDF_PLUGIN_DEFINE_NS(CHIP,CHIP,PLUGIN_NAME)

#define PRDF_PLUGIN_DEFINE_NS(CHIP,NAMESPACE,PLUGIN_NAME) \
    class __PRDF_PLUGIN_MAKENAME(Plugin_Registration_,CHIP,PLUGIN_NAME) \
    { \
      private: \
        ExtensibleFunctionType * cv_plugin; \
        PluginRegisterClass cv_registerClass; \
        char cv_plugin_space[sizeof(Plugin<ExtensibleChip>)]; \
      public: \
        __PRDF_PLUGIN_MAKENAME(Plugin_Registration_,CHIP,PLUGIN_NAME)() : \
            cv_plugin( bind_plugin_ptr(&NAMESPACE::PLUGIN_NAME, \
                                       &cv_plugin_space) ), \
            cv_registerClass(#CHIP,#PLUGIN_NAME,cv_plugin) \
        {} \
    }; \
    __PRDF_PLUGIN_MAKENAME(Plugin_Registration_,CHIP,PLUGIN_NAME) \
        __PRDF_PLUGIN_MAKENAME(g_PluginRegistration_,CHIP,PLUGIN_NAME)
#endif

#include <prdfPluginMap.H>

