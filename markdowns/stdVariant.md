# std::variant

Type safe unions!

With a regular union you ~~can only use POD types~~ (correction: since C++11 it's possible, assuming you provide required operation like a copy constructor, move... [see union declaration](http://en.cppreference.com/w/cpp/language/union)), and it’s not safe - for instance, it won’t tell you which variant is currently used. With std::variant it’s only possible to access types that are declared.

For example:

```c++
std::variant<int, float, std::string> abc;
```

abc can only be initialized with int, float or string and nothing else. You’ll get a compile time error when you try to assign something else.

To access the data, you can use:

* std::get with index or type of the alternative. It throws std::bad_variant_access on errors.
* std::get_if - returns a pointer to the element or nullptr;
* or use std::visit method that has usage especially for containers with variants.

A bigger playground (GCC 7.1):

@[std::variant sample]({"stubs": ["cpp_variant.cpp"],"command": "sh ./run.sh cpp_variant.cpp"})

Notes:

Variant is not allowed to allocate additional (dynamic) memory.
A variant is not permitted to hold references, arrays, or the type void.
A variant is default initialized with the value of its first alternative.
If the first alternative type is not default constructible, then the variant must use [std::monostate](http://en.cppreference.com/w/cpp/utility/variant/monostate) as the first alternative

More info:

[P0088R3: Variant: a type-safe union for C++17 (v8).](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0088r3.html) - note that Variant wasn’t in the Library Fundamentals, it was a separate proposal.

MSVC VS 2017, GCC: 7.0, Clang: 4.0?