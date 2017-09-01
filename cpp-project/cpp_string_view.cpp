#include <string>
#include <iostream>
#include <string_view>

// we need to overload 'new' to see what's
// hapenning under the hood...
void* operator new(std::size_t n)
{
    std::cout << "new " << n << " bytes\n";
    return malloc(n);
}
 
int main()
{
    // the original string, one allocation:
    std::string str {"Hello Amazing Programming World" };
    
    // another allocation for the substring, separate 'copy'
    auto subStr = str.substr(str.find("Programming"));
    std::cout << subStr << "\n";
    
    // no allocation for the sub range:
    std::string_view strView { str };
    auto subView = strView.substr(str.find("Programming"));
    std::cout << subView << "\n";
}