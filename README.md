# Bind #

I wrote this code several years ago in an attempt to understand how the excellent [`boost::bind`](http://www.boost.org/doc/libs/1_65_1/libs/bind/doc/html/bind.html) library worked internally and how it could be implemented.

While `boost::bind` is extremely versatile and supports binding any of arguments, routing arguments into arbitrary positions, and placeholders, my version is extremely simple and demands binding all arguments. Due to this constraint, the implementation is much simpler, easier to understand, and also easier to step-through with a debugger to see what is going on.

This implementation is not intended for production code, though it is pretty well tested. For production, use `boost`, or better yet, switch to C++11 or above and use `std::bind`. Or forget about `bind` and use capturing lambdas, also known as continuations.

## License ##

This project is released under **MIT/X11** license, so feel free to do anything you like with it.
