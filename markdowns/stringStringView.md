# string_view

Although passing strings got much faster with move semantics from C++11, there’s still a lot of possibilities to end up with many temporary copies.

A much better pattern to solve the problem is to use a string view. As the name suggests instead of using the original string, you’ll only get a non-owning view of it. Most of the time it will be a pointer to the internal buffer and the length. You can pass it around and use most of the common string functions to manipulate.

Views work well with string operations like sub string. In a typical case, each substring operation creates another, smaller copy of some part of the string. With string view, ```substr``` will only map a different portion of the original buffer, without additional memory usage, or dynamic allocation.

Another important reason for using views is the consistency: what if you use other implementations for strings? Not all devs have the luxury to work only with the standard strings. With views, you can just write (or use) existing conversion code, and then string view should handle other strings in the same way.

In theory ```string_view``` is a natural replacement for most of ```const std::string&```.

Still, it’s important to remember that it’s only a non-owning view, so if the original object is gone, the view becomes rubbish.

If you need a real string, there’s a separate constructor for ```std::string``` that accepts a ```string_view```. For instance, the filesystem library was adapted to handle string view (as input when creating a path object).

Ok, but let’s play with the code (GCC 7.1):

@[std::string_view sample]({"stubs": ["cpp_string_view.cpp"],"command": "sh ./run.sh cpp_string_view.cpp"})

More info:

* [n4562: string_view](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#string.view) and also [N3921, string_view: a non-owning reference to a string, revision 7](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3921.html)
* [What is string_view? - Stack Overflow](https://stackoverflow.com/questions/20803826/what-is-string-view)
* [C++17 string_view – Steve Lorimer](https://skebanga.github.io/string-view/)
* [Modernescpp - string_view](http://www.modernescpp.com/index.php/c-17-avoid-copying-with-std-string-view)
* [foonathan::blog() - std::string_view accepting temporaries: good idea or horrible pitfall?](http://foonathan.net/blog/2017/03/22/string_view-temporary.html)

MSVC VS 2017, GCC: 7.0, Clang: 4.0?

