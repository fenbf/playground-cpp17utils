[![C++17 features, stl utils](https://4.bp.blogspot.com/-UQbatL9MY-o/WHIoAlhYl6I/AAAAAAAACz4/GKYFLeObkm4E2my_lswjcb5mKv7ZppppQCPcB/s1600/cpp17.png)](http://www.bfilipek.com/2017/09/cpp17-details-utils.html)

Table Of Contents:

* [Documents And Links](#doc)
* [Library Fundamentals V1 TS and more](#libfun)
* [`std::any`](#any)
* [`std::variant`](#var)
* [`std::optional`](#opt)
* [`std::string_view`](#str)
* [Searchers](#search)
* [Other changes](#other)
* [Summary](#sum)

What I like about C++17 is that it finally brings a lot of features and patterns that are well known but come from other libraries. For example, for years programmers have been using boost libraries. Now, many of boost sub -libraries are merged into the standard. That merging process makes the transition to the modern C++ much easier, as most of the time the code will just compile and work as expected. Not to mention is the fact that soon you won't need any third party libraries.

Let's have a look at the following features:

* `std::any` - adapted from [boost any](http://www.boost.org/doc/libs/1_61_0/doc/html/any.html)
* `std::variant` - and the corresponding  [boost variant](http://www.boost.org/doc/libs/1_64_0/doc/html/variant.html)
* `std::optional` - [boost optional](http://www.boost.org/doc/libs/1_58_0/libs/optional/doc/html/index.html) library
* `std::string_view`
* Searchers for `std::search`
* Plus a few other mentions

This playground is adapted from my blog: [Bartek's coding blog: C++17 in details: Standard Library Utilities](http://www.bfilipek.com/2017/09/cpp17-details-utils.html).

Visit the blog if you're looking for more good stuff about C++ :)

<a name="doc" />

# Documents & Links

First of all, if you want to dig into the standard on your own, you can read the latest draft here: 

[N4659, 2017-03-21, **Draft, Standard for Programming Language C++**](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/n4659.pdf) - from [isocpp.org](https://isocpp.org/).

Also, you can grab **my list of concise descriptions of all of the C++17** - It's a one-page reference card, pdf language features: 

[Grab it here: **C++17 Reference Card**](http://eepurl.com/cyycFz)

Links:

* Compiler support: [C++ compiler support](http://en.cppreference.com/w/cpp/compiler_support)
* The official paper with changes: [P0636r0: Changes between C++14 and C++17 DIS](https://isocpp.org/files/papers/p0636r0.html)
* There's also a talk from Bryce Lelbach: [C++Now 2017:  C++17 Features](https://www.youtube.com/watch?v=LvwXJjRQfHk)
* My master C++17 features post: [C++17 Features](http://www.bfilipek.com/2017/01/cpp17features.html)
* Jason Turner: [C++ Weekly channel](https://www.youtube.com/playlist?list=PLs3KjaCtOwSZ2tbuV1hx8Xz-rFZTan2J1), where he covered most (or even all!) of C++17 features.

And the books:

* [**C++17 STL Cookbook** by Jacek Galowicz](http://amzn.to/2f8wnLp)
* [**Modern C++ Programming Cookbook** by Marius Bancila](http://amzn.to/2eRaiUu)

OK, let's discuss the utils!

<a name="libfun" />

# Library Fundamentals V1 TS and more

Most of the utilities described today (`std::optional`,`std::any`, `std::string_view`, searchers) comes from so called "Library Fundamentals V1". It was in Technical Specification for some time, and with the paper ["P0220R1 - Adopt Library Fundamentals V1 TS Components for C++17 (R1")](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0220r1.html) it got merged into the standard.

Support:

* [Libc++ C++1Z Status](http://libcxx.llvm.org/cxx1z_status.html)
* [Visual Studio Support](https://blogs.msdn.microsoft.com/vcblog/2017/05/10/c17-features-in-vs-2017-3/)
* [GCC/libstdc++](https://gcc.gnu.org/onlinedocs/libstdc++/manual/status.html#status.iso.201z), a lot of features are in `<experimental/>` namespace/headers.

When I describe the features, I write "compiler" support, but when discussing library features, I should mention the library implementation. For the sake of simplification, I'll just stick to compiler name as each common compiler (GCC, Clang, MSVC) have its separate libs.

And now the features:

<a name="any" />

# `std::any`

A better way to handle any type and replace `void*`.

Node from [n4562](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#any):

> The discriminated type may contain values of different types but does not attempt conversion between them, i.e. 5 is held strictly as an int and is not implicitly convertible either to "5" or to 5.0. This indifference to interpretation but awareness of type effectively allows safe, generic containers of single values, with no scope for surprises from ambiguous conversions.

In short, you can assign any value to existing `any` object:

```cpp
auto a = std::any(12);
a = std::string("hello world");
a = 10.0f;
```

When you want to read a value you have to perform a proper cast:

```cpp
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

Here's a bigger runnable sample (GCC 7.1):

@[std::any sample]({"stubs": ["cpp_any.cpp"],"command": "sh ./run.sh cpp_any.cpp"})

Notes

* `any` object might be empty.
* `any` shouldn't use any dynamically allocated memory, but it's not guaranteed by the spec.

More info in:

* [n4562:  any](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#any)
* [std::any - cppreference.com](http://en.cppreference.com/w/cpp/utility/any)
* [Boost.Any - 1.61.0](http://www.boost.org/doc/libs/1_61_0/doc/html/any.html)
 * [c++ - What is the typical usage of boost any library? - Stack Overflow](https://stackoverflow.com/questions/781001/what-is-the-typical-usage-of-boost-any-library)
* [Conversations: I'd Hold Anything for You [1] | Dr Dobb's](http://www.drdobbs.com/cpp/conversations-id-hold-anything-for-you-1/184403808)

MSVC VS 2017, GCC: 7.0, Clang: 4.0

<a name="var" />

# `std::variant`

Type safe unions!

With a regular `union` you can ~~only use POD types~~ (correction: since C++11 it's possible, assuming you provide required operation like a copy constructor, move... see [union declaration](http://en.cppreference.com/w/cpp/language/union))), and it's not safe - for instance, it won't tell you which variant is currently used. With `std::variant` it's only possible to access types that are declared.

For example:

```cpp
std::variant<int, float, std::string> abc;
```

`abc` can only be initialized with `int`, `float` or `string` and nothing else. You'll get a compile time error when you try to assign something else.

To access the data, you can use:

* [`std::get`](http://en.cppreference.com/w/cpp/utility/variant/get) with index or type of the alternative. It throws `std::bad_variant_access` on errors.
* [`std::get_if`](http://en.cppreference.com/w/cpp/utility/variant/get_if) - returns a pointer to the element or `nullptr`;
* or use [`std::visit`](http://en.cppreference.com/w/cpp/utility/variant/visit) method that has usage especially for containers with variants.

A bigger playground (GCC 7.1):

@[std::variant sample]({"stubs": ["cpp_variant.cpp"],"command": "sh ./run.sh cpp_variant.cpp"})

Notes:

* Variant is not allowed to allocate additional (dynamic) memory.
* A variant is not permitted to hold references, arrays, or the type void.
* The first alternative must always be default constructible
* A variant is default initialized with the value of its first alternative.
* If the first alternative type is not default constructible, then the variant must use [`std::monostate`](http://en.cppreference.com/w/cpp/utility/variant/monostate) as the first alternative

More info:

* [P0088R3: Variant: a type-safe union for C++17 (v8).](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0088r3.html) - note that Variant wasn't in the Library Fundamentals, it was a separate proposal.

MSVC VS 2017, GCC: 7.0, Clang: 4.0?

<a name="opt" />

# `std::optional`

Another and elegant way to return objects from functions that are allowed to be empty.

For example:

```cpp
std::optional<std::string> ostr = GetUserResponse();

if (ostr)
    ProcessResponse(*ostr);
else
    Report("please enter a valid value");
```

In the simple sample above `GetUserResponse` returns optional with a possible string inside. If a user doesn't enter a valid value `ostr` will be empty. It's much nicer and expressive than using exceptions, nulls, output params or other ways of handling empty values.

A better example (GCC 7.1):

@[std::optional sample]({"stubs": ["cpp_optional.cpp"],"command": "sh ./run.sh cpp_optional.cpp"})

Notes:

* Implementations are not permitted to use additional storage, such as dynamic memory, to allocate its contained value. The contained value shall be allocated in a region of the optional<T> storage suitably aligned for the type T.

More info:

* [n4562: optional](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#optional)
* [Boost Optional](http://www.boost.org/doc/libs/1_58_0/libs/optional/doc/html/index.html)
* [Efficient optional values | Andrzej's C++ blog](https://akrzemi1.wordpress.com/2015/07/15/efficient-optional-values/)
* Recipe "Safely signalizing failure with std::optional" from C++17 STL Cookbook. 

MSVC VS 2017, GCC: 7.0, Clang: 4.0?

<a name="str" />

# `string_view`

Although passing strings got much faster with move semantics from C++11, there's still a lot of possibilities to end up with many temporary copies.

A much better pattern to solve the problem is to use a string view. As the name suggests instead of using the original string, you'll only get a non-owning view of it. Most of the time it will be a pointer to the internal buffer and the length. You can pass it around and use most of the common string functions to manipulate.

Views work well with string operations like sub string. In a typical case, each substring operation creates another, smaller copy of some part of the string. With string view, `substr` will only map a different portion of the original buffer, without additional memory usage, or dynamic allocation.

Another important reason for using views is the consistency: what if you use other implementations for strings? Not all devs have the luxury to work only with the standard strings. With views, you can just write (or use) existing conversion code, and then string view should handle other strings in the same way.

In theory `string_view` is a natural replacement for most of `const std::string&`.

Still, it's important to remember that it's only a non-owning view, so if the original object is gone, the view becomes rubbish.

If you need a real string, there's a separate constructor for `std::string` that accepts a `string_view`. For instance, the filesystem library was adapted to handle string view (as input when creating a path object).

Ok, but let's play with the code (GCC 7.1):

@[std::string_view sample]({"stubs": ["cpp_string_view.cpp"],"command": "sh ./run.sh cpp_string_view.cpp"})

More info:

* [n4562:  `string_view`](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#string.view) and also [N3921, string_view: a non-owning reference to a string, revision 7](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3921.html)
* [What is string_view? - Stack Overflow](https://stackoverflow.com/questions/20803826/what-is-string-view)
* [C++17 string_view – Steve Lorimer](https://skebanga.github.io/string-view/)
* [Modernescpp - string_view](http://www.modernescpp.com/index.php/c-17-avoid-copying-with-std-string-view)
* [foonathan::blog() - std::string_view accepting temporaries: good idea or horrible pitfall?](http://foonathan.net/blog/2017/03/22/string_view-temporary.html)

MSVC VS 2017, GCC: 7.0, Clang: 4.0?

<a name="search" />

# Searchers

When you want to find one object in a `string`, you can just use find or some other alternative. But the task complicates when there's a need to search for a pattern (or a sub range) in a string. 

The naive approach might be `O(n*m)` (where `n` is the length of the whole string, `m` is the length of the pattern).

But there are much better alternatives. For example Boyer-Moore with the complexity of `O(n+m)`.

C++17 updated `std::search` algorithm in two ways:

* you can now use execution policy to run the default version of the algorithm but in a parallel way.
* you can provide a Searcher object that handles the search.

For now we have three searchers:

* `default_searcher`
* `boyer_moore_searcher`
* `boyer_moore_horspool_searcher`

You can play with the example here (GCC 7.1):

@[searchers sample]({"stubs": ["cpp_searchers.cpp"],"command": "sh ./run.sh cpp_searchers.cpp"})

* Which version is the fastest?
* Is this better than just `std::string::find`?

More info:

* [N3905 Extending std::search to use Additional Searching Algorithms (Version 4)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3905.html)

MSVC VS 2017.3, GCC: 7.0, Clang: 3.9?

<a name="other" />

# Other Changes

* `shared_ptr` with array - [P0414R2: Merging shared_ptr changes from Library Fundamentals to C++17](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0414r2.html). So far `unique_ptr` was able to handle arrays. Now it's also possible to use `shared_ptr`.
* Splicing Maps and Sets - [PDF P0083R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0083r2.pdf) - we can now move nodes from one tree based container (maps/sets) into other ones, without additional memory overhead/allocation.
* Mathematical special functions - [PDF: P0226R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0226r1.pdf)
* Improving `std::pair` and `std::tuple` - [N4387)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4387.html) - pair/tuple obey the same initialization rules as their underlying element types.
* Sampling - [n4562: Sampling](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#alg.random.sample) - new algorithm that selects `n` elements from the sequence
* Elementary string conversions - [P0067R5](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0067r5.html), new function [`to_chars`](http://en.cppreference.com/w/cpp/utility/to_chars) that handles basic conversions, no need to use stringstream, sscanf, itoa or other stuff.

<a name="sum" />

# Summary

Did I miss something? Yes!

There are many other changes in STL that would fill another post (or I could expand the "Other Changes" section). But let's stop for now. Note that each of those 'small' utils are worth a separate post, with more example, so I'll definitely plan to do that later :)

If you want to dig deeper try to read the spec/draft or look at the official paper with changes: [P0636r0: Changes between C++14 and C++17 DIS](https://isocpp.org/files/papers/p0636r0.html).

As I mentioned, I like that C++17 merged many useful well-known patterns into STL. There's a high chance you've come across many of the features and using them in a project shouldn't be that hard.

What do I like the most?

I think:

* Filesystem - a significant portion of the library, that will make code much easier and common across many platforms.
* type safe helpers: `std::any`, `std::optional`, `std::variant` - we can now replace `void*` or C style unions. The code should be safer.
* string features: like `string_view`, string conversions, searchers.
* parallelism - very powerful abstraction for threading.

Still, there's a lot of stuff to learn/teach! I've just described the features, but the another part of the equation is to use them effectively. And that needs experience.

* What are your favourite features from C++17 STL?
* What have I missed? What else should be in my C++17 posts?
* Have you already used any/optional/variant, for example from boost?