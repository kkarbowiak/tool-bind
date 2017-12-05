/*
    Copyright 2016 Krzysztof Karbowiak
*/

#ifndef TOOL_REF_WRAPPER_H__DDK
#define TOOL_REF_WRAPPER_H__DDK
/**========================================================================== *\
 * Description: Definition of wrapper class that wraps a reference
\*=========================================================================== */


namespace tool
{
    template<class T>
    class wrapper;
}

namespace tool
{
    template<class T>
    wrapper<T> ref(T & t);

    template<class T>
    wrapper<const T> cref(T const & t);
}

namespace tool
{
    template<class T>
    class wrapper
    {
        public:
            explicit wrapper(T & t);
            operator T & () const;

        private:
            T * mPtr;
    };
}


namespace tool
{
////////////////////////////////////////////////////////////////////////////////
template<class T>
inline wrapper<T>::wrapper(T & t)
  : mPtr(&t)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class T>
inline wrapper<T>::operator T & () const
{
    return *mPtr;
}
////////////////////////////////////////////////////////////////////////////////
}

namespace tool
{
////////////////////////////////////////////////////////////////////////////////
template<class T>
inline wrapper<T> ref(T & t)
{
    return wrapper<T>(t);
}
////////////////////////////////////////////////////////////////////////////////
template<class T>
inline wrapper<const T> cref(T const & t)
{
    return wrapper<const T>(t);
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* TOOL_REF_WRAPPER_H__DDK */
