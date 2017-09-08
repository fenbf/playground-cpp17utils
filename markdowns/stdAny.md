std::any

A better way to handle any type and replace void*.

Node from [n4562](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#any):

_The discriminated type may contain values of different types but does not attempt conversion between them, i.e. 5 is held strictly as an int and is not implicitly convertible either to “5” or to 5.0. This indifference to interpretation but awareness of type effectively allows safe, generic containers of single values, with no scope for surprises from ambiguous conversions._

In short, you can assign any value to existing any object:

```c++
auto a = std::any(12);
a = std::string("hello world");
a = 10.0f;
```

When you want to read a value you have to perform a proper cast:

```c++
auto a = std::any(12);
std::cout << std::any_cast<int>(a) << '\n'; 

try 
{
    std::cout << std::any_cast<std::string>(a) << '\n';
}
catch(const std::bad_any_cast& e) 
{
    std::cout << e.what() << '\n';
}
```

Here’s a bigger runnable sample (GCC 7.1):

@[std::any sample]({"stubs": ["cpp_any.cpp"],"command": "sh ./run.sh cpp_any.cpp"})

Notes

* any object might be empty.
* any shouldn’t use any dynamically allocated memory, but it’s not guaranteed by the spec.

More info in:

* [n4562: any](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#any)
* [std::any - cppreference.com](http://en.cppreference.com/w/cpp/utility/any)
* [Boost.Any - 1.61.0](http://www.boost.org/doc/libs/1_61_0/doc/html/any.html)
    * [c++ - What is the typical usage of boost any library? - Stack Overflow](https://stackoverflow.com/questions/781001/what-is-the-typical-usage-of-boost-any-library)
* [Conversations: I’d Hold Anything for You [1] | Dr Dobb’s](http://www.drdobbs.com/cpp/conversations-id-hold-anything-for-you-1/184403808)

MSVC VS 2017, GCC: 7.0, Clang: 4.0