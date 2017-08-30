#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
// in gcc 7.1 still have to use experimental namespace/headers
#include <experimental/functional>
#include <experimental/algorithm>
#include <chrono>

template <typename TFunc> void RunAndMeasure(TFunc func)
{
    const auto start = std::chrono::steady_clock::now();
    func();
    const auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration <double, std::milli> (end - start).count() << " ms\n";
}
 
int main()
{
    std::string in;
    std::string needle = "Hello Amazing Programming World";
    RunAndMeasure([&]() {
        const int maxIters = 20000000u;
        for (int i = 0; i < maxIters; ++i)
        {
            in += "abcd ";
            if (i % 7)
                in += "xyz, uvw ";
            if (i == maxIters - 100)
                in += " $" + needle + "$ ";
        }
    });
    
    RunAndMeasure([&]() {
    auto it = std::experimental::search(in.begin(), in.end(),
                   std::experimental::default_searcher(
                       needle.begin(), needle.end()));
    if(it == in.end())
        std::cout << "The string " << needle << " not found\n";
    });
    
    RunAndMeasure([&]() {
    auto it = std::experimental::search(in.begin(), in.end(),
                   std::experimental::boyer_moore_searcher(
                       needle.begin(), needle.end()));
    if(it == in.end())
        std::cout << "The string " << needle << " not found\n";
    });
    
    RunAndMeasure([&]() {
    auto it = std::experimental::search(in.begin(), in.end(),
                   std::experimental::boyer_moore_horspool_searcher(
                       needle.begin(), needle.end()));
    if(it == in.end())
        std::cout << "The string " << needle << " not found\n";
    });
}