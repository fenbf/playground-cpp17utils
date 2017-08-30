#include <string>
#include <iostream>
#include <any>
 
int main()
{
    auto a = std::any(12);
    
    // set any value:
    a = std::string("Hello!");
    a = 16;
    // reading a value:
    
    // we can read it as int
    std::cout << std::any_cast<int>(a) << '\n'; 
 
    // but not as string:
    try 
    {
        std::cout << std::any_cast<std::string>(a) << '\n';
    }
    catch(const std::bad_any_cast& e) 
    {
        std::cout << e.what() << '\n';
    }
    
    // reset and check if it contains any value:
    a.reset();
    if (!a.has_value())
    {
        std::cout << "a is empty!" << "\n";
    }
}