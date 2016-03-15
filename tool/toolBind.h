#ifndef TOOL_BIND_H__DDK
#define TOOL_BIND_H__DDK
/**========================================================================== *\
 * File:        toolBind.h
 *
 * Author:      Krzysztof Karbowiak
 *
 * Description: Definition of a group of bind classes and functions for binding
 *              function calls together with arguments
\*=========================================================================== */

#include "toolFunction.h"
#include "toolMemberFunction.h"
#include "toolRefWrapper.h"


namespace tool
{
    template<class T>
    class traits
    {
        public:
            typedef T value_type;
    };

    template<class T>
    class traits<T const &>
    {
        public:
            typedef T value_type;
    };

    template<class T>
    class traits<T &>
    {
        public:
            typedef T value_type;
    };

    template<class T>
    class traits<wrapper<T const &> >
    {
        public:
            typedef T const & value_type;
    };

    template<class T>
    class traits<wrapper<T &> >
    {
        public:
            typedef T & value_type;
    };
}

namespace tool
{
    template<class R, class F>
    class bind_f0
    {
        public:
            explicit bind_f0(F f);

            R operator()();

        private:
            F mFunction;
    };

    template<class R, class F, class A1>
    class bind_f1
    {
        public:
            bind_f1(
                F f,
                A1 arg1);

            R operator()();

        private:
            F mFunction;
            typename traits<A1>::value_type mArg1;
    };

    template<class R, class F, class A1, class A2>
    class bind_f2
    {
        public:
            bind_f2(
                F f,
                A1 arg1,
                A2 arg2);

            R operator()();

        private:
            F mFunction;
            typename traits<A1>::value_type mArg1;
            typename traits<A2>::value_type mArg2;
    };

    template<class R, class F, class A1, class A2, class A3>
    class bind_f3
    {
        public:
            bind_f3(
                F f,
                A1 arg1,
                A2 arg2,
                A3 arg3);

            R operator()();

        private:
            F mFunction;
            typename traits<A1>::value_type mArg1;
            typename traits<A2>::value_type mArg2;
            typename traits<A3>::value_type mArg3;
    };

    template<class R, class F, class A1, class A2, class A3, class A4>
    class bind_f4
    {
        public:
            bind_f4(
                F f,
                A1 arg1,
                A2 arg2,
                A3 arg3,
                A4 arg4);

            R operator()();

        private:
            F mFunction;
            typename traits<A1>::value_type mArg1;
            typename traits<A2>::value_type mArg2;
            typename traits<A3>::value_type mArg3;
            typename traits<A4>::value_type mArg4;
    };

    template<class R, class F, class A1, class A2, class A3, class A4, class A5>
    class bind_f5
    {
        public:
            bind_f5(
                F f,
                A1 arg1,
                A2 arg2,
                A3 arg3,
                A4 arg4,
                A5 arg5);

            R operator()();

        private:
            F mFunction;
            typename traits<A1>::value_type mArg1;
            typename traits<A2>::value_type mArg2;
            typename traits<A3>::value_type mArg3;
            typename traits<A4>::value_type mArg4;
            typename traits<A5>::value_type mArg5;
    };

    template<class R, class F, class A1>
    class bind_memf0
    {
        public:
            bind_memf0(
                F f,
                A1 arg1);

            R operator()();

        private:
            F mFunction;
            typename traits<A1>::value_type mArg1;
    };

    template<class R, class F, class A1, class A2>
    class bind_memf1
    {
        public:
            bind_memf1(
                F f,
                A1 arg1,
                A2 arg2);

            R operator()();

        private:
            F mFunction;
            typename traits<A1>::value_type mArg1;
            typename traits<A2>::value_type mArg2;
    };

    template<class R, class F, class A1, class A2, class A3>
    class bind_memf2
    {
        public:
            bind_memf2(
                F f,
                A1 arg1,
                A2 arg2,
                A3 arg3);

            R operator()();

        private:
            F mFunction;
            typename traits<A1>::value_type mArg1;
            typename traits<A2>::value_type mArg2;
            typename traits<A3>::value_type mArg3;
    };

    template<class R, class F, class A1, class A2, class A3, class A4>
    class bind_memf3
    {
        public:
            bind_memf3(
                F f,
                A1 arg1,
                A2 arg2,
                A3 arg3,
                A4 arg4);

            R operator()();

        private:
            F mFunction;
            typename traits<A1>::value_type mArg1;
            typename traits<A2>::value_type mArg2;
            typename traits<A3>::value_type mArg3;
            typename traits<A4>::value_type mArg4;
    };

    template<class R, class F, class A1, class A2, class A3, class A4, class A5>
    class bind_memf4
    {
        public:
            bind_memf4(
                F f,
                A1 arg1,
                A2 arg2,
                A3 arg3,
                A4 arg4,
                A5 arg5);

            R operator()();

        private:
            F mFunction;
            typename traits<A1>::value_type mArg1;
            typename traits<A2>::value_type mArg2;
            typename traits<A3>::value_type mArg3;
            typename traits<A4>::value_type mArg4;
            typename traits<A5>::value_type mArg5;
    };

    template<class R, class F, class A1, class A2, class A3, class A4, class A5, class A6>
    class bind_memf5
    {
        public:
            bind_memf5(
                F f,
                A1 arg1,
                A2 arg2,
                A3 arg3,
                A4 arg4,
                A5 arg5,
                A6 arg6);

            R operator()();

        private:
            F mFunction;
            typename traits<A1>::value_type mArg1;
            typename traits<A2>::value_type mArg2;
            typename traits<A3>::value_type mArg3;
            typename traits<A4>::value_type mArg4;
            typename traits<A5>::value_type mArg5;
            typename traits<A6>::value_type mArg6;
    };
}

namespace tool
{
    template<class R>
    bind_f0<R, fn0<R> > bind(
        R (*f)());

    template<class R, class FA1, class A1>
    bind_f1<R, fn1<R, FA1>, A1> bind(
        R (*f)(FA1),
        A1 arg1);

    template<class R, class FA1, class FA2, class A1, class A2>
    bind_f2<R, fn2<R, FA1, FA2>, A1, A2> bind(
        R (*f)(FA1, FA2),
        A1 arg1,
        A2 arg2);

    template<class R, class FA1, class FA2, class FA3, class A1, class A2, class A3>
    bind_f3<R, fn3<R, FA1, FA2, FA3>, A1, A2, A3> bind(
        R (*f)(FA1, FA2, FA3),
        A1 arg1,
        A2 arg2,
        A3 arg3);

    template<class R, class FA1, class FA2, class FA3, class FA4, class A1, class A2, class A3, class A4>
    bind_f4<R, fn4<R, FA1, FA2, FA3, FA4>, A1, A2, A3, A4> bind(
        R (*f)(FA1, FA2, FA3, FA4),
        A1 arg1,
        A2 arg2,
        A3 arg3,
        A4 arg4);

    template<class R, class FA1, class FA2, class FA3, class FA4, class FA5, class A1, class A2, class A3, class A4, class A5>
    bind_f5<R, fn5<R, FA1, FA2, FA3, FA4, FA5>, A1, A2, A3, A4, A5> bind(
        R (*f)(FA1, FA2, FA3, FA4, FA5),
        A1 arg1,
        A2 arg2,
        A3 arg3,
        A4 arg4,
        A5 arg5);

    template<class R, class T, class A1>
    bind_memf0<R, mem_fn0<R, T>, A1> bind(
        R (T::*f)(),
        A1 arg1);

    template<class R, class T, class A1>
    bind_memf0<R, mem_cfn0<R, T>, A1> bind(
        R (T::*f)() const,
        A1 arg1);

    template<class R, class T, class FA1, class A1, class A2>
    bind_memf1<R, mem_fn1<R, T, FA1>, A1, A2> bind(
        R (T::*f)(FA1),
        A1 arg1,
        A2 arg2);

    template<class R, class T, class FA1, class A1, class A2>
    bind_memf1<R, mem_cfn1<R, T, FA1>, A1, A2> bind(
        R (T::*f)(FA1) const,
        A1 arg1,
        A2 arg2);

    template<class R, class T, class FA1, class FA2, class A1, class A2, class A3>
    bind_memf2<R, mem_fn2<R, T, FA1, FA2>, A1, A2, A3> bind(
        R (T::*f)(FA1, FA2),
        A1 arg1,
        A2 arg2,
        A3 arg3);

    template<class R, class T, class FA1, class FA2, class A1, class A2, class A3>
    bind_memf2<R, mem_cfn2<R, T, FA1, FA2>, A1, A2, A3> bind(
        R (T::*f)(FA1, FA2) const,
        A1 arg1,
        A2 arg2,
        A3 arg3);

    template<class R, class T, class FA1, class FA2, class FA3, class A1, class A2, class A3, class A4>
    bind_memf3<R, mem_fn3<R, T, FA1, FA2, FA3>, A1, A2, A3, A4> bind(
        R (T::*f)(FA1, FA2, FA3),
        A1 arg1,
        A2 arg2,
        A3 arg3,
        A4 arg4);

    template<class R, class T, class FA1, class FA2, class FA3, class A1, class A2, class A3, class A4>
    bind_memf3<R, mem_cfn3<R, T, FA1, FA2, FA3>, A1, A2, A3, A4> bind(
        R (T::*f)(FA1, FA2, FA3) const,
        A1 arg1,
        A2 arg2,
        A3 arg3,
        A4 arg4);

    template<class R, class T, class FA1, class FA2, class FA3, class FA4, class A1, class A2, class A3, class A4, class A5>
    bind_memf4<R, mem_fn4<R, T, FA1, FA2, FA3, FA4>, A1, A2, A3, A4, A5> bind(
        R (T::*f)(FA1, FA2, FA3, FA4),
        A1 arg1,
        A2 arg2,
        A3 arg3,
        A4 arg4,
        A5 arg5);

    template<class R, class T, class FA1, class FA2, class FA3, class FA4, class A1, class A2, class A3, class A4, class A5>
    bind_memf4<R, mem_cfn4<R, T, FA1, FA2, FA3, FA4>, A1, A2, A3, A4, A5> bind(
        R (T::*f)(FA1, FA2, FA3, FA4) const,
        A1 arg1,
        A2 arg2,
        A3 arg3,
        A4 arg4,
        A5 arg5);

    template<class R, class T, class FA1, class FA2, class FA3, class FA4, class FA5, class A1, class A2, class A3, class A4, class A5, class A6>
    bind_memf5<R, mem_fn5<R, T, FA1, FA2, FA3, FA4, FA5>, A1, A2, A3, A4, A5, A6> bind(
        R (T::*f)(FA1, FA2, FA3, FA4, FA5),
        A1 arg1,
        A2 arg2,
        A3 arg3,
        A4 arg4,
        A5 arg5,
        A6 arg6);

    template<class R, class T, class FA1, class FA2, class FA3, class FA4, class FA5, class A1, class A2, class A3, class A4, class A5, class A6>
    bind_memf5<R, mem_cfn5<R, T, FA1, FA2, FA3, FA4, FA5>, A1, A2, A3, A4, A5, A6> bind(
        R (T::*f)(FA1, FA2, FA3, FA4, FA5) const,
        A1 arg1,
        A2 arg2,
        A3 arg3,
        A4 arg4,
        A5 arg5,
        A6 arg6);
}


namespace tool
{
////////////////////////////////////////////////////////////////////////////////
template<class R, class F>
inline bind_f0<R, F>::bind_f0(F f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F>
inline R bind_f0<R, F>::operator()()
{
    return mFunction.execute();
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1>
inline bind_f1<R, F, A1>::bind_f1(F f, A1 arg1)
  : mFunction(f)
  , mArg1(arg1)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1>
inline R bind_f1<R, F, A1>::operator()()
{
    return mFunction.execute(mArg1);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2>
inline bind_f2<R, F, A1, A2>::bind_f2(F f, A1 arg1, A2 arg2)
  : mFunction(f)
  , mArg1(arg1)
  , mArg2(arg2)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2>
inline R bind_f2<R, F, A1, A2>::operator()()
{
    return mFunction.execute(mArg1, mArg2);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3>
inline bind_f3<R, F, A1, A2, A3>::bind_f3(F f, A1 arg1, A2 arg2, A3 arg3)
  : mFunction(f)
  , mArg1(arg1)
  , mArg2(arg2)
  , mArg3(arg3)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3>
inline R bind_f3<R, F, A1, A2, A3>::operator()()
{
    return mFunction.execute(mArg1, mArg2, mArg3);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3, class A4>
inline bind_f4<R, F, A1, A2, A3, A4>::bind_f4(F f, A1 arg1, A2 arg2, A3 arg3, A4 arg4)
  : mFunction(f)
  , mArg1(arg1)
  , mArg2(arg2)
  , mArg3(arg3)
  , mArg4(arg4)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3, class A4>
inline R bind_f4<R, F, A1, A2, A3, A4>::operator()()
{
    return mFunction.execute(mArg1, mArg2, mArg3, mArg4);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3, class A4, class A5>
inline bind_f5<R, F, A1, A2, A3, A4, A5>::bind_f5(F f, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5)
  : mFunction(f)
  , mArg1(arg1)
  , mArg2(arg2)
  , mArg3(arg3)
  , mArg4(arg4)
  , mArg5(arg5)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3, class A4, class A5>
inline R bind_f5<R, F, A1, A2, A3, A4, A5>::operator()()
{
    return mFunction.execute(mArg1, mArg2, mArg3, mArg4, mArg5);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1>
inline bind_memf0<R, F, A1>::bind_memf0(F f, A1 arg1)
  : mFunction(f)
  , mArg1(arg1)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1>
inline R bind_memf0<R, F, A1>::operator()()
{
    return mFunction.execute(mArg1);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2>
inline bind_memf1<R, F, A1, A2>::bind_memf1(F f, A1 arg1, A2 arg2)
  : mFunction(f)
  , mArg1(arg1)
  , mArg2(arg2)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2>
inline R bind_memf1<R, F, A1, A2>::operator()()
{
    return mFunction.execute(mArg1, mArg2);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3>
inline bind_memf2<R, F, A1, A2, A3>::bind_memf2(F f, A1 arg1, A2 arg2, A3 arg3)
  : mFunction(f)
  , mArg1(arg1)
  , mArg2(arg2)
  , mArg3(arg3)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3>
inline R bind_memf2<R, F, A1, A2, A3>::operator()()
{
    return mFunction.execute(mArg1, mArg2, mArg3);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3, class A4>
inline bind_memf3<R, F, A1, A2, A3, A4>::bind_memf3(F f, A1 arg1, A2 arg2, A3 arg3, A4 arg4)
  : mFunction(f)
  , mArg1(arg1)
  , mArg2(arg2)
  , mArg3(arg3)
  , mArg4(arg4)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3, class A4>
inline R bind_memf3<R, F, A1, A2, A3, A4>::operator()()
{
    return mFunction.execute(mArg1, mArg2, mArg3, mArg4);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3, class A4, class A5>
inline bind_memf4<R, F, A1, A2, A3, A4, A5>::bind_memf4(F f, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5)
  : mFunction(f)
  , mArg1(arg1)
  , mArg2(arg2)
  , mArg3(arg3)
  , mArg4(arg4)
  , mArg5(arg5)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3, class A4, class A5>
inline R bind_memf4<R, F, A1, A2, A3, A4, A5>::operator()()
{
    return mFunction.execute(mArg1, mArg2, mArg3, mArg4, mArg5);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3, class A4, class A5, class A6>
inline bind_memf5<R, F, A1, A2, A3, A4, A5, A6>::bind_memf5(F f, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6)
  : mFunction(f)
  , mArg1(arg1)
  , mArg2(arg2)
  , mArg3(arg3)
  , mArg4(arg4)
  , mArg5(arg5)
  , mArg6(arg6)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class F, class A1, class A2, class A3, class A4, class A5, class A6>
inline R bind_memf5<R, F, A1, A2, A3, A4, A5, A6>::operator()()
{
    return mFunction.execute(mArg1, mArg2, mArg3, mArg4, mArg5, mArg6);
}
////////////////////////////////////////////////////////////////////////////////
}

namespace tool
{
////////////////////////////////////////////////////////////////////////////////
template<class R>
inline bind_f0<R, fn0<R> > bind(
    R (*f)())
{
    return bind_f0<R, fn0<R> >(fn0<R>(f));
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class A1>
inline bind_f1<R, fn1<R, FA1>, A1> bind(
    R (*f)(FA1),
    A1 arg1)
{
    return bind_f1<R, fn1<R, FA1>, A1>(fn1<R, FA1>(f), arg1);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2, class A1, class A2>
inline bind_f2<R, fn2<R, FA1, FA2>, A1, A2> bind(
    R (*f)(FA1, FA2),
    A1 arg1,
    A2 arg2)
{
    return bind_f2<R, fn2<R, FA1, FA2>, A1, A2>(fn2<R, FA1, FA2>(f), arg1, arg2);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2, class FA3, class A1, class A2, class A3>
inline bind_f3<R, fn3<R, FA1, FA2, FA3>, A1, A2, A3> bind(
    R (*f)(FA1, FA2, FA3),
    A1 arg1,
    A2 arg2,
    A3 arg3)
{
    return bind_f3<R, fn3<R, FA1, FA2, FA3>, A1, A2, A3>(fn3<R, FA1, FA2, FA3>(f), arg1, arg2, arg3);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2, class FA3, class FA4, class A1, class A2, class A3, class A4>
inline bind_f4<R, fn4<R, FA1, FA2, FA3, FA4>, A1, A2, A3, A4> bind(
    R (*f)(FA1, FA2, FA3, FA4),
    A1 arg1,
    A2 arg2,
    A3 arg3,
    A4 arg4)
{
    return bind_f4<R, fn4<R, FA1, FA2, FA3, FA4>, A1, A2, A3, A4>(fn4<R, FA1, FA2, FA3, FA4>(f), arg1, arg2, arg3, arg4);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2, class FA3, class FA4, class FA5, class A1, class A2, class A3, class A4, class A5>
inline bind_f5<R, fn5<R, FA1, FA2, FA3, FA4, FA5>, A1, A2, A3, A4, A5> bind(
    R (*f)(FA1, FA2, FA3, FA4, FA5),
    A1 arg1,
    A2 arg2,
    A3 arg3,
    A4 arg4,
    A5 arg5)
{
    return bind_f5<R, fn5<R, FA1, FA2, FA3, FA4, FA5>, A1, A2, A3, A4, A5>(fn5<R, FA1, FA2, FA3, FA4, FA5>(f), arg1, arg2, arg3, arg4, arg5);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class A1>
inline bind_memf0<R, mem_fn0<R, T>, A1> bind(
    R (T::*f)(),
    A1 arg1)
{
    return bind_memf0<R, mem_fn0<R, T>, A1>(mem_fn0<R, T>(f), arg1);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class A1>
inline bind_memf0<R, mem_cfn0<R, T>, A1> bind(
    R (T::*f)() const,
    A1 arg1)
{
    return bind_memf0<R, mem_cfn0<R, T>, A1>(mem_cfn0<R, T>(f), arg1);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class A1, class A2>
inline bind_memf1<R, mem_fn1<R, T, FA1>, A1, A2> bind(
    R (T::*f)(FA1),
    A1 arg1,
    A2 arg2)
{
    return bind_memf1<R, mem_fn1<R, T, FA1>, A1, A2>(mem_fn1<R, T, FA1>(f), arg1, arg2);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class A1, class A2>
inline bind_memf1<R, mem_cfn1<R, T, FA1>, A1, A2> bind(
    R (T::*f)(FA1) const,
    A1 arg1,
    A2 arg2)
{
    return bind_memf1<R, mem_cfn1<R, T, FA1>, A1, A2>(mem_cfn1<R, T, FA1>(f), arg1, arg2);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class A1, class A2, class A3>
inline bind_memf2<R, mem_fn2<R, T, FA1, FA2>, A1, A2, A3> bind(
    R (T::*f)(FA1, FA2),
    A1 arg1,
    A2 arg2,
    A3 arg3)
{
    return bind_memf2<R, mem_fn2<R, T, FA1, FA2>, A1, A2, A3>(mem_fn2<R, T, FA1, FA2>(f), arg1, arg2, arg3);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class A1, class A2, class A3>
inline bind_memf2<R, mem_cfn2<R, T, FA1, FA2>, A1, A2, A3> bind(
    R (T::*f)(FA1, FA2) const,
    A1 arg1,
    A2 arg2,
    A3 arg3)
{
    return bind_memf2<R, mem_cfn2<R, T, FA1, FA2>, A1, A2, A3>(mem_cfn2<R, T, FA1, FA2>(f), arg1, arg2, arg3);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class A1, class A2, class A3, class A4>
inline bind_memf3<R, mem_fn3<R, T, FA1, FA2, FA3>, A1, A2, A3, A4> bind(
    R (T::*f)(FA1, FA2, FA3),
    A1 arg1,
    A2 arg2,
    A3 arg3,
    A4 arg4)
{
    return bind_memf3<R, mem_fn3<R, T, FA1, FA2, FA3>, A1, A2, A3, A4>(mem_fn3<R, T, FA1, FA2, FA3>(f), arg1, arg2, arg3, arg4);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class A1, class A2, class A3, class A4>
inline bind_memf3<R, mem_cfn3<R, T, FA1, FA2, FA3>, A1, A2, A3, A4> bind(
    R (T::*f)(FA1, FA2, FA3) const,
    A1 arg1,
    A2 arg2,
    A3 arg3,
    A4 arg4)
{
    return bind_memf3<R, mem_cfn3<R, T, FA1, FA2, FA3>, A1, A2, A3, A4>(mem_cfn3<R, T, FA1, FA2, FA3>(f), arg1, arg2, arg3, arg4);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4, class A1, class A2, class A3, class A4, class A5>
inline bind_memf4<R, mem_fn4<R, T, FA1, FA2, FA3, FA4>, A1, A2, A3, A4, A5> bind(
    R (T::*f)(FA1, FA2, FA3, FA4),
    A1 arg1,
    A2 arg2,
    A3 arg3,
    A4 arg4,
    A5 arg5)
{
    return bind_memf4<R, mem_fn4<R, T, FA1, FA2, FA3, FA4>, A1, A2, A3, A4, A5>(mem_fn4<R, T, FA1, FA2, FA3, FA4>(f), arg1, arg2, arg3, arg4, arg5);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4, class A1, class A2, class A3, class A4, class A5>
inline bind_memf4<R, mem_cfn4<R, T, FA1, FA2, FA3, FA4>, A1, A2, A3, A4, A5> bind(
    R (T::*f)(FA1, FA2, FA3, FA4) const,
    A1 arg1,
    A2 arg2,
    A3 arg3,
    A4 arg4,
    A5 arg5)
{
    return bind_memf4<R, mem_cfn4<R, T, FA1, FA2, FA3, FA4>, A1, A2, A3, A4, A5>(mem_cfn4<R, T, FA1, FA2, FA3, FA4>(f), arg1, arg2, arg3, arg4, arg5);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4, class FA5, class A1, class A2, class A3, class A4, class A5, class A6>
inline bind_memf5<R, mem_fn5<R, T, FA1, FA2, FA3, FA4, FA5>, A1, A2, A3, A4, A5, A6> bind(
    R (T::*f)(FA1, FA2, FA3, FA4, FA5),
    A1 arg1,
    A2 arg2,
    A3 arg3,
    A4 arg4,
    A5 arg5,
    A6 arg6)
{
    return bind_memf5<R, mem_fn5<R, T, FA1, FA2, FA3, FA4, FA5>, A1, A2, A3, A4, A5, A6>(mem_fn5<R, T, FA1, FA2, FA3, FA4, FA5>(f), arg1, arg2, arg3, arg4, arg5, arg6);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4, class FA5, class A1, class A2, class A3, class A4, class A5, class A6>
inline bind_memf5<R, mem_cfn5<R, T, FA1, FA2, FA3, FA4, FA5>, A1, A2, A3, A4, A5, A6> bind(
    R (T::*f)(FA1, FA2, FA3, FA4, FA5) const,
    A1 arg1,
    A2 arg2,
    A3 arg3,
    A4 arg4,
    A5 arg5,
    A6 arg6)
{
    return bind_memf5<R, mem_cfn5<R, T, FA1, FA2, FA3, FA4, FA5>, A1, A2, A3, A4, A5, A6>(mem_cfn5<R, T, FA1, FA2, FA3, FA4, FA5>(f), arg1, arg2, arg3, arg4, arg5, arg6);
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* TOOL_BIND_H__DDK */
