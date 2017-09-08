Other Changes

shared_ptr with array - [P0414R2: Merging shared_ptr changes from Library Fundamentals to C++17](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0414r2.html). So far unique_ptr was able to handle arrays. Now it’s also possible to use shared_ptr.
Splicing Maps and Sets - [PDF P0083R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0083r2.pdf) - we can now move nodes from one tree based container (maps/sets) into other ones, without additional memory overhead/allocation.
Mathematical special functions - [PDF: P0226R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0226r1.pdf)
Improving std::pair and std::tuple - [N4387](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4387.html)) - pair/tuple obey the same initialization rules as their underlying element types.
Sampling - [n4562: Sampling](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#alg.random.sample) - new algorithm that selects n elements from the sequence
Elementary string conversions - [P0067R5](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0067r5.html), new function [to_chars](http://en.cppreference.com/w/cpp/utility/to_chars) that handles basic conversions, no need to use stringstream, sscanf, itoa or other stuff.
