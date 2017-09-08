Summary

Did I miss something? Yes!

There are many other changes in STL that would fill another post (or I could expand the “Other Changes” section). But let’s stop for now. Note that each of those ‘small’ utils are worth a separate post, with more example, so I’ll definitely plan to do that later :)

If you want to dig deeper try to read the spec/draft or look at the official paper with changes: [P0636r0: Changes between C++14 and C++17 DIS](https://isocpp.org/files/papers/p0636r0.html).

As I mentioned, I like that C++17 merged many useful well-known patterns into STL. There’s a high chance you’ve come across many of the features and using them in a project shouldn’t be that hard.

What do I like the most?

I think:

* Filesystem - a significant portion of the library, that will make code much easier and common across many platforms.
* type safe helpers: std::any, std::optional, std::variant - we can now replace void* or C style unions. The code should be safer.
* string features: like string_view, string conversions, searchers.
* parallelism - very powerful abstraction for threading.
Still, there’s a lot of stuff to learn/teach! I’ve just described the features, but the another part of the equation is to use them effectively. And that needs experience.

* What are your favourite features from C++17 STL?
* What have I missed? What else should be in my C++17 posts?
* Have you already used any/optional/variant, for example from boost?
* Interested in new blog posts and bonus content? [Sign up for my newsletter](http://eepurl.com/caCAun).

You might also like to read:

* [C++17 in details: Parallel Algorithms](http://www.bfilipek.com/2017/08/cpp17-details-parallel.html)
* [C++17 STL Cookbook Book Review](http://www.bfilipek.com/2017/08/cpp17stl-review.html)
* [C++17 in details: Filesystem]((http://www.bfilipek.com/2017/08/cpp17-details-filesystem.html)
* [C++17 in details: Code Simplification](http://www.bfilipek.com/2017/07/cpp17-details-simplifications.html)
* [Boost Test Library](http://www.bfilipek.com/2012/12/boost-test-library.html)
