#include <string>
#include <iostream>
#include <any>
 
int main()
{
    auto a = std::any(12);
 
    std::cout << std::any_cast<int>(a) << '\n'; 
 
    try {
        std::cout << std::any_cast<std::string>(a) << '\n';
    }
    catch(const std::bad_any_cast& e) {
        std::cout << e.what() << '\n';
    }
}