# std::optional

Another and elegant way to return objects from functions that are allowed to be empty.

For example:
```c++
std::optional<std::string> ostr = GetUserResponse();

if (ostr)
    ProcessResponse(*ostr);
else
    Report("please enter a valid value");
```

In the simple sample above ```GetUserResponse``` returns optional with a possible string inside. If a user doesn’t enter a valid value ```ostr``` will be empty. It’s much nicer and expressive than using exceptions, nulls, output params or other ways of handling empty values.

A better example (GCC 7.1):

@[std::optional sample]({"stubs": ["cpp_optional.cpp"],"command": "sh ./run.sh cpp_optional.cpp"})

Notes:

* Implementations are not permitted to use additional storage, such as dynamic memory, to allocate its contained value. The contained value shall be allocated in a region of the optional storage suitably aligned for the type T.

More info:

* [n4562: optional](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#optional)
* [Boost Optional](http://www.boost.org/doc/libs/1_58_0/libs/optional/doc/html/index.html)
* [Efficient optional values | Andrzej’s C++ blog](https://akrzemi1.wordpress.com/2015/07/15/efficient-optional-values/)
* Recipe “Safely signalizing failure with std::optional” from C++17 STL Cookbook.

MSVC VS 2017, GCC: 7.0, Clang: 4.0?



