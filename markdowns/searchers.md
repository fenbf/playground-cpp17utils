# Searchers

When you want to find one object in a ```string```, you can just use find or some other alternative. But the task complicates when there’s a need to search for a pattern (or a sub range) in a string.

The naive approach might be O(n*m) (where n is the length of the whole string, m is the length of the pattern).

But there are much better alternatives. For example Bayer-Moore with the complexity of O(n+m).

C++17 updated ```std::search``` algorithm in two ways:

* you can now use execution policy to run the default version of the algorithm but in a parallel way.
* you can provide a Searcher object that handles the search.

For now we have three searchers:

* ```default_searcher```
* ```boyer_moore_searcher```
* ```boyer_moore_horspool_searcher```

You can play with the example here:

@[searchers sample]({"stubs": ["cpp_searchers.cpp"],"command": "sh ./run.sh cpp_searchers.cpp"})

* Which version is the fastest?
* Is this better than just std::string::find?

More info:

* [N3905 Extending std::search to use Additional Searching Algorithms (Version 4)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3905.html)

MSVC VS 2017.3, GCC: 7.0, Clang: 3.9?

