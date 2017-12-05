/*
    Copyright 2016 Krzysztof Karbowiak
*/

#ifndef TOOL_FUNCTION_H__DDK
#define TOOL_FUNCTION_H__DDK
/**========================================================================== *\
 * Description: Definition of a group of fn classes that wrap function pointers
 *              into function objects
\*=========================================================================== */


namespace tool
{
    template<class R>
    class fn0
    {
        public:
            typedef R (*f0)();

        public:
            explicit fn0(f0 f);

            R execute();

        private:
            f0 mFunction;
    };

    template<class R, class FA1>
    class fn1
    {
        public:
            typedef R (*f1)(FA1);

        public:
            explicit fn1(f1 f);

            R execute(FA1 arg1);

        private:
            f1 mFunction;
    };

    template<class R, class FA1, class FA2>
    class fn2
    {
        public:
            typedef R (*f2)(FA1, FA2);

        public:
            explicit fn2(f2 f);

            R execute(FA1 arg1, FA2 arg2);

        private:
            f2 mFunction;
    };

    template<class R, class FA1, class FA2, class FA3>
    class fn3
    {
        public:
            typedef R (*f3)(FA1, FA2, FA3);

        public:
            explicit fn3(f3 f);

            R execute(FA1 arg1, FA2 arg2, FA3 arg3);

        private:
            f3 mFunction;
    };

    template<class R, class FA1, class FA2, class FA3, class FA4>
    class fn4
    {
        public:
            typedef R (*f4)(FA1, FA2, FA3, FA4);

        public:
            explicit fn4(f4 f);

            R execute(FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4);

        private:
            f4 mFunction;
    };

    template<class R, class FA1, class FA2, class FA3, class FA4, class FA5>
    class fn5
    {
        public:
            typedef R (*f5)(FA1, FA2, FA3, FA4, FA5);

        public:
            explicit fn5(f5 f);

            R execute(FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4, FA5 arg5);

        private:
            f5 mFunction;
    };
}


namespace tool
{
////////////////////////////////////////////////////////////////////////////////
template<class R>
inline fn0<R>::fn0(f0 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R>
inline R fn0<R>::execute()
{
    return mFunction();
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1>
inline fn1<R, FA1>::fn1(f1 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1>
inline R fn1<R, FA1>::execute(FA1 arg1)
{
    return mFunction(arg1);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2>
inline fn2<R, FA1, FA2>::fn2(f2 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2>
inline R fn2<R, FA1, FA2>::execute(FA1 arg1, FA2 arg2)
{
    return mFunction(arg1, arg2);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2, class FA3>
inline fn3<R, FA1, FA2, FA3>::fn3(f3 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2, class FA3>
inline R fn3<R, FA1, FA2, FA3>::execute(FA1 arg1, FA2 arg2, FA3 arg3)
{
    return mFunction(arg1, arg2, arg3);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2, class FA3, class FA4>
inline fn4<R, FA1, FA2, FA3, FA4>::fn4(f4 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2, class FA3, class FA4>
inline R fn4<R, FA1, FA2, FA3, FA4>::execute(FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4)
{
    return mFunction(arg1, arg2, arg3, arg4);
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2, class FA3, class FA4, class FA5>
inline fn5<R, FA1, FA2, FA3, FA4, FA5>::fn5(f5 f)
  : mFunction(f)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class R, class FA1, class FA2, class FA3, class FA4, class FA5>
inline R fn5<R, FA1, FA2, FA3, FA4, FA5>::execute(FA1 arg1, FA2 arg2, FA3 arg3, FA4 arg4, FA5 arg5)
{
    return mFunction(arg1, arg2, arg3, arg4, arg5);
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* TOOL_FUNCTION_H__DDK */
