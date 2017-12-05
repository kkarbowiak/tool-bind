/*
    Copyright 2016 Krzysztof Karbowiak
*/

#ifndef TOOL_MEMBER_FUNCTION_H__DDK
#define TOOL_MEMBER_FUNCTION_H__DDK
/**========================================================================== *\
 * Description: Definition of a group of mem_fn classes that wrap member function
 *              pointers into function objects
\*=========================================================================== */


namespace tool
{
    template<class R, class T>
    class mem_fn0
    {
        public:
            typedef R (T::*mf0)();

        public:
            explicit mem_fn0(mf0 f);

            R execute(T * ptr);

        private:
            mf0 mFunction;
    };

    template<class R, class T>
    class mem_cfn0
    {
        public:
            typedef R (T::*mcf0)() const;

        public:
            explicit mem_cfn0(mcf0 f);

            R execute(T const * ptr);

        private:
            mcf0 mFunction;
    };

    template<class R, class T, class FA1>
    class mem_fn1
    {
        public:
            typedef R (T::*mf1)(FA1);

        public:
            explicit mem_fn1(mf1 f);

            R execute(T * ptr, FA1 arg1);

        private:
            mf1 mFunction;
    };
    
    template<class R, class T, class FA1>
    class mem_cfn1
    {
        public:
            typedef R (T::*mcf1)(FA1) const;

        public:
            explicit mem_cfn1(mcf1 f);

            R execute(T const * ptr, FA1 arg1);

        private:
            mcf1 mFunction;
    };

    template<class R, class T, class FA1, class FA2>
    class mem_fn2
    {
        public:
            typedef R (T::*mf2)(FA1, FA2);

        public:
            explicit mem_fn2(mf2 f);

            R execute(T * ptr, FA1 arg1, FA2 arg2);

        private:
            mf2 mFunction;
    };
    
    template<class R, class T, class FA1, class FA2>
    class mem_cfn2
    {
        public:
            typedef R (T::*mcf2)(FA1, FA2) const;

        public:
            explicit mem_cfn2(mcf2 f);

            R execute(T const * ptr, FA1 arg1, FA2 arg2);

        private:
            mcf2 mFunction;
    };

    template<class R, class T, class FA1, class FA2, class FA3>
    class mem_fn3
    {
        public:
            typedef R (T::*mf3)(FA1, FA2, FA3);

        public:
            explicit mem_fn3(mf3 f);

            R execute(T * ptr, FA1 arg1, FA2 arg2, FA3 arg3);

        private:
            mf3 mFunction;
    };
    
    template<class R, class T, class FA1, class FA2, class FA3>
    class mem_cfn3
    {
        public:
            typedef R (T::*mcf3)(FA1, FA2, FA3) const;

        public:
            explicit mem_cfn3(mcf3 f);

            R execute(T const * ptr, FA1 arg1, FA2 arg2, FA3 arg3);

        private:
            mcf3 mFunction;
    };

    template<class R, class T, class FA1, class FA2, class FA3, class FA4>
    class mem_fn4
    {
        public:
            typedef R (T::*mf4)(FA1, FA2, FA3, FA4);

        public:
            explicit mem_fn4(mf4 f);

            R execute(T * ptr, FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4);

        private:
            mf4 mFunction;
    };
    
    template<class R, class T, class FA1, class FA2, class FA3, class FA4>
    class mem_cfn4
    {
        public:
            typedef R (T::*mcf4)(FA1, FA2, FA3, FA4) const;

        public:
            explicit mem_cfn4(mcf4 f);

            R execute(T const * ptr, FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4);

        private:
            mcf4 mFunction;
    };

    template<class R, class T, class FA1, class FA2, class FA3, class FA4, class FA5>
    class mem_fn5
    {
        public:
            typedef R (T::*mf5)(FA1, FA2, FA3, FA4, FA5);

        public:
            explicit mem_fn5(mf5 f);

            R execute(T * ptr, FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4, FA5 arg5);

        private:
            mf5 mFunction;
    };
    
    template<class R, class T, class FA1, class FA2, class FA3, class FA4, class FA5>
    class mem_cfn5
    {
        public:
            typedef R (T::*mcf5)(FA1, FA2, FA3, FA4, FA5) const;

        public:
            explicit mem_cfn5(mcf5 f);

            R execute(T const * ptr, FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4, FA5 arg5);

        private:
            mcf5 mFunction;
    };
}


namespace tool
{
////////////////////////////////////////////////////////////////////////////////
template<class R, class T>
inline mem_fn0<R, T>::mem_fn0(mf0 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T>
inline R mem_fn0<R, T>::execute(T * ptr)
{
    return (ptr->*mFunction)();
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T>
inline mem_cfn0<R, T>::mem_cfn0(mcf0 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T>
inline R mem_cfn0<R, T>::execute(T const * ptr)
{
    return (ptr->*mFunction)();
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1>
inline mem_fn1<R, T, FA1>::mem_fn1(mf1 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1>
inline R mem_fn1<R, T, FA1>::execute(T * ptr, FA1 arg1)
{
    return (ptr->*mFunction)(arg1);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1>
inline mem_cfn1<R, T, FA1>::mem_cfn1(mcf1 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1>
inline R mem_cfn1<R, T, FA1>::execute(T const * ptr, FA1 arg1)
{
    return (ptr->*mFunction)(arg1);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2>
inline mem_fn2<R, T, FA1, FA2>::mem_fn2(mf2 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2>
inline R mem_fn2<R, T, FA1, FA2>::execute(T * ptr, FA1 arg1, FA2 arg2)
{
    return (ptr->*mFunction)(arg1, arg2);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2>
inline mem_cfn2<R, T, FA1, FA2>::mem_cfn2(mcf2 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2>
inline R mem_cfn2<R, T, FA1, FA2>::execute(T const * ptr, FA1 arg1, FA2 arg2)
{
    return (ptr->*mFunction)(arg1, arg2);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3>
inline mem_fn3<R, T, FA1, FA2, FA3>::mem_fn3(mf3 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3>
inline R mem_fn3<R, T, FA1, FA2, FA3>::execute(T * ptr, FA1 arg1, FA2 arg2, FA3 arg3)
{
    return (ptr->*mFunction)(arg1, arg2, arg3);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3>
inline mem_cfn3<R, T, FA1, FA2, FA3>::mem_cfn3(mcf3 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3>
inline R mem_cfn3<R, T, FA1, FA2, FA3>::execute(T const * ptr, FA1 arg1, FA2 arg2, FA3 arg3)
{
    return (ptr->*mFunction)(arg1, arg2, arg3);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4>
inline mem_fn4<R, T, FA1, FA2, FA3, FA4>::mem_fn4(mf4 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4>
inline R mem_fn4<R, T, FA1, FA2, FA3, FA4>::execute(T * ptr, FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4)
{
    return (ptr->*mFunction)(arg1, arg2, arg3, arg4);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4>
inline mem_cfn4<R, T, FA1, FA2, FA3, FA4>::mem_cfn4(mcf4 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4>
inline R mem_cfn4<R, T, FA1, FA2, FA3, FA4>::execute(T const * ptr, FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4)
{
    return (ptr->*mFunction)(arg1, arg2, arg3, arg4);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4, class FA5>
inline mem_fn5<R, T, FA1, FA2, FA3, FA4, FA5>::mem_fn5(mf5 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4, class FA5>
inline R mem_fn5<R, T, FA1, FA2, FA3, FA4, FA5>::execute(T * ptr, FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4, FA5 arg5)
{
    return (ptr->*mFunction)(arg1, arg2, arg3, arg4, arg5);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4, class FA5>
inline mem_cfn5<R, T, FA1, FA2, FA3, FA4, FA5>::mem_cfn5(mcf5 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class T, class FA1, class FA2, class FA3, class FA4, class FA5>
inline R mem_cfn5<R, T, FA1, FA2, FA3, FA4, FA5>::execute(T const * ptr, FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4, FA5 arg5)
{
    return (ptr->*mFunction)(arg1, arg2, arg3, arg4, arg5);
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* TOOL_MEMBER_FUNCTION_H__DDK */
