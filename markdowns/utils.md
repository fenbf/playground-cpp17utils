Library Fundamentals V1 TS and more

Most of the utilities described today (std::optional,std::any, std::string_view, searchers) comes from so called “Library Fundamentals V1”. It was in Technical Specification for some time, and with the paper [“P0220R1 - Adopt Library Fundamentals V1 TS Components for C++17 (R1)"](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0220r1.html) it got merged into the standard.

Support:

* [Libc++ C++1Z Status](http://libcxx.llvm.org/cxx1z_status.html)
* [Visual Studio Support](https://blogs.msdn.microsoft.com/vcblog/2017/05/10/c17-features-in-vs-2017-3/)
* [GCC/libstdc++](https://gcc.gnu.org/onlinedocs/libstdc++/manual/status.html#status.iso.201z), a lot of features are in <experimental/> namespace/headers.
When I describe the features, I write “compiler” support, but when discussing library features, I should mention the library implementation. For the sake of simplification, I’ll just stick to compiler name as each common compiler (GCC, Clang, MSVC) have its separate libs.

And now the features: